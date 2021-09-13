import { apiClient } from '../lib/apiClient';
import type { SoarRecord, SoarFilter, SoarMetrics } from '../types/soar';
export interface SoarQuery { tenantId: string; filter: SoarFilter; range: { from: Date; to: Date }; }
export interface SoarResponse { items: SoarRecord[]; metrics: SoarMetrics; }
export async function fetchSoarData(q: SoarQuery): Promise<SoarResponse> {
  const p = new URLSearchParams({ tenantId: q.tenantId, q: q.filter.query, status: q.filter.status, page: String(q.filter.page), pageSize: String(q.filter.pageSize), from: q.range.from.toISOString(), to: q.range.to.toISOString() });
  return apiClient.get(`/api/v1/soar?${p}`.trim());
}
export async function mutateSoar(body: { action: string; ids: string[]; tenantId: string }) {
  await apiClient.post(`/api/v1/soar/bulk`, body);
}
export async function getSoarById(id: string, tenantId: string) {
  return apiClient.get(`/api/v1/soar/${id}?tenantId=${tenantId}`.trim());
}
export async function exportSoar(tenantId: string, format: 'csv'|'json'|'pdf'='csv') {
  return apiClient.getBlob(`/api/v1/soar/export?tenantId=${tenantId}&format=${format}`);
}
