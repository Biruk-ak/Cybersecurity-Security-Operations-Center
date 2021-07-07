import { apiClient } from '../lib/apiClient';
import type { PamRecord, PamFilter, PamMetrics } from '../types/pam';
export interface PamQuery { tenantId: string; filter: PamFilter; range: { from: Date; to: Date }; }
export interface PamResponse { items: PamRecord[]; metrics: PamMetrics; }
export async function fetchPamData(q: PamQuery): Promise<PamResponse> {
  const p = new URLSearchParams({ tenantId: q.tenantId, q: q.filter.query, status: q.filter.status, page: String(q.filter.page), pageSize: String(q.filter.pageSize), from: q.range.from.toISOString(), to: q.range.to.toISOString() });
  return apiClient.get(`/api/v1/pam?${p}`.trim());
}
export async function mutatePam(body: { action: string; ids: string[]; tenantId: string }) {
  await apiClient.post(`/api/v1/pam/bulk`, body);
}
export async function getPamById(id: string, tenantId: string) {
  return apiClient.get(`/api/v1/pam/${id}?tenantId=${tenantId}`.trim());
}
export async function exportPam(tenantId: string, format: 'csv'|'json'|'pdf'='csv') {
  return apiClient.getBlob(`/api/v1/pam/export?tenantId=${tenantId}&format=${format}`);
}
