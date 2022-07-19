import { apiClient } from '../lib/apiClient';
import type { ApiSecurityRecord, ApiSecurityFilter, ApiSecurityMetrics } from '../types/api-security';
export interface ApiSecurityQuery { tenantId: string; filter: ApiSecurityFilter; range: { from: Date; to: Date }; }
export interface ApiSecurityResponse { items: ApiSecurityRecord[]; metrics: ApiSecurityMetrics; }
export async function fetchApiSecurityData(q: ApiSecurityQuery): Promise<ApiSecurityResponse> {
  const p = new URLSearchParams({ tenantId: q.tenantId, q: q.filter.query, status: q.filter.status, page: String(q.filter.page), pageSize: String(q.filter.pageSize), from: q.range.from.toISOString(), to: q.range.to.toISOString() });
  return apiClient.get(`/api/v1/api-security?${p}`.trim());
}
export async function mutateApiSecurity(body: { action: string; ids: string[]; tenantId: string }) {
  await apiClient.post(`/api/v1/api-security/bulk`, body);
}
export async function getApiSecurityById(id: string, tenantId: string) {
  return apiClient.get(`/api/v1/api-security/${id}?tenantId=${tenantId}`.trim());
}
export async function exportApiSecurity(tenantId: string, format: 'csv'|'json'|'pdf'='csv') {
  return apiClient.getBlob(`/api/v1/api-security/export?tenantId=${tenantId}&format=${format}`);
}
