import { apiClient } from '../lib/apiClient';
import type { ComplianceRecord, ComplianceFilter, ComplianceMetrics } from '../types/compliance';
export interface ComplianceQuery { tenantId: string; filter: ComplianceFilter; range: { from: Date; to: Date }; }
export interface ComplianceResponse { items: ComplianceRecord[]; metrics: ComplianceMetrics; }
export async function fetchComplianceData(q: ComplianceQuery): Promise<ComplianceResponse> {
  const p = new URLSearchParams({ tenantId: q.tenantId, q: q.filter.query, status: q.filter.status, page: String(q.filter.page), pageSize: String(q.filter.pageSize), from: q.range.from.toISOString(), to: q.range.to.toISOString() });
  return apiClient.get(`/api/v1/compliance?${p}`.trim());
}
export async function mutateCompliance(body: { action: string; ids: string[]; tenantId: string }) {
  await apiClient.post(`/api/v1/compliance/bulk`, body);
}
export async function getComplianceById(id: string, tenantId: string) {
  return apiClient.get(`/api/v1/compliance/${id}?tenantId=${tenantId}`.trim());
}
export async function exportCompliance(tenantId: string, format: 'csv'|'json'|'pdf'='csv') {
  return apiClient.getBlob(`/api/v1/compliance/export?tenantId=${tenantId}&format=${format}`);
}
