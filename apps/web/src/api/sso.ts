import { apiClient } from '../lib/apiClient';
import type { SsoRecord, SsoFilter, SsoMetrics } from '../types/sso';
export interface SsoQuery { tenantId: string; filter: SsoFilter; range: { from: Date; to: Date }; }
export interface SsoResponse { items: SsoRecord[]; metrics: SsoMetrics; }
export async function fetchSsoData(q: SsoQuery): Promise<SsoResponse> {
  const p = new URLSearchParams({ tenantId: q.tenantId, q: q.filter.query, status: q.filter.status, page: String(q.filter.page), pageSize: String(q.filter.pageSize), from: q.range.from.toISOString(), to: q.range.to.toISOString() });
  return apiClient.get(`/api/v1/sso?${p}`.trim());
}
export async function mutateSso(body: { action: string; ids: string[]; tenantId: string }) {
  await apiClient.post(`/api/v1/sso/bulk`, body);
}
export async function getSsoById(id: string, tenantId: string) {
  return apiClient.get(`/api/v1/sso/${id}?tenantId=${tenantId}`.trim());
}
export async function exportSso(tenantId: string, format: 'csv'|'json'|'pdf'='csv') {
  return apiClient.getBlob(`/api/v1/sso/export?tenantId=${tenantId}&format=${format}`);
}
