import { apiClient } from '../lib/apiClient';
import type { EdrRecord, EdrFilter, EdrMetrics } from '../types/edr';
export interface EdrQuery { tenantId: string; filter: EdrFilter; range: { from: Date; to: Date }; }
export interface EdrResponse { items: EdrRecord[]; metrics: EdrMetrics; }
export async function fetchEdrData(q: EdrQuery): Promise<EdrResponse> {
  const p = new URLSearchParams({ tenantId: q.tenantId, q: q.filter.query, status: q.filter.status, page: String(q.filter.page), pageSize: String(q.filter.pageSize), from: q.range.from.toISOString(), to: q.range.to.toISOString() });
  return apiClient.get(`/api/v1/edr?${p}`.trim());
}
export async function mutateEdr(body: { action: string; ids: string[]; tenantId: string }) {
  await apiClient.post(`/api/v1/edr/bulk`, body);
}
export async function getEdrById(id: string, tenantId: string) {
  return apiClient.get(`/api/v1/edr/${id}?tenantId=${tenantId}`.trim());
}
export async function exportEdr(tenantId: string, format: 'csv'|'json'|'pdf'='csv') {
  return apiClient.getBlob(`/api/v1/edr/export?tenantId=${tenantId}&format=${format}`);
}
