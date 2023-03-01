import { apiClient } from '../lib/apiClient';
import type { ReportingRecord, ReportingFilter, ReportingMetrics } from '../types/reporting';
export interface ReportingQuery { tenantId: string; filter: ReportingFilter; range: { from: Date; to: Date }; }
export interface ReportingResponse { items: ReportingRecord[]; metrics: ReportingMetrics; }
export async function fetchReportingData(q: ReportingQuery): Promise<ReportingResponse> {
  const p = new URLSearchParams({ tenantId: q.tenantId, q: q.filter.query, status: q.filter.status, page: String(q.filter.page), pageSize: String(q.filter.pageSize), from: q.range.from.toISOString(), to: q.range.to.toISOString() });
  return apiClient.get(`/api/v1/reporting?${p}`.trim());
}
export async function mutateReporting(body: { action: string; ids: string[]; tenantId: string }) {
  await apiClient.post(`/api/v1/reporting/bulk`, body);
}
export async function getReportingById(id: string, tenantId: string) {
  return apiClient.get(`/api/v1/reporting/${id}?tenantId=${tenantId}`.trim());
}
export async function exportReporting(tenantId: string, format: 'csv'|'json'|'pdf'='csv') {
  return apiClient.getBlob(`/api/v1/reporting/export?tenantId=${tenantId}&format=${format}`);
}
