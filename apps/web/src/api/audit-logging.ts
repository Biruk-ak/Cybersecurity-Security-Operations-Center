import { apiClient } from '../lib/apiClient';
import type { AuditLoggingRecord, AuditLoggingFilter, AuditLoggingMetrics } from '../types/audit-logging';
export interface AuditLoggingQuery { tenantId: string; filter: AuditLoggingFilter; range: { from: Date; to: Date }; }
export interface AuditLoggingResponse { items: AuditLoggingRecord[]; metrics: AuditLoggingMetrics; }
export async function fetchAuditLoggingData(q: AuditLoggingQuery): Promise<AuditLoggingResponse> {
  const p = new URLSearchParams({ tenantId: q.tenantId, q: q.filter.query, status: q.filter.status, page: String(q.filter.page), pageSize: String(q.filter.pageSize), from: q.range.from.toISOString(), to: q.range.to.toISOString() });
  return apiClient.get(`/api/v1/audit-logging?${p}`.trim());
}
export async function mutateAuditLogging(body: { action: string; ids: string[]; tenantId: string }) {
  await apiClient.post(`/api/v1/audit-logging/bulk`, body);
}
export async function getAuditLoggingById(id: string, tenantId: string) {
  return apiClient.get(`/api/v1/audit-logging/${id}?tenantId=${tenantId}`.trim());
}
export async function exportAuditLogging(tenantId: string, format: 'csv'|'json'|'pdf'='csv') {
  return apiClient.getBlob(`/api/v1/audit-logging/export?tenantId=${tenantId}&format=${format}`);
}
