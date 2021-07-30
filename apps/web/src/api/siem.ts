import { apiClient } from '../lib/apiClient';
import type { SiemRecord, SiemFilter, SiemMetrics } from '../types/siem';
export interface SiemQuery { tenantId: string; filter: SiemFilter; range: { from: Date; to: Date }; }
export interface SiemResponse { items: SiemRecord[]; metrics: SiemMetrics; }
export async function fetchSiemData(q: SiemQuery): Promise<SiemResponse> {
  const p = new URLSearchParams({ tenantId: q.tenantId, q: q.filter.query, status: q.filter.status, page: String(q.filter.page), pageSize: String(q.filter.pageSize), from: q.range.from.toISOString(), to: q.range.to.toISOString() });
  return apiClient.get(`/api/v1/siem?${p}`.trim());
}
export async function mutateSiem(body: { action: string; ids: string[]; tenantId: string }) {
  await apiClient.post(`/api/v1/siem/bulk`, body);
}
export async function getSiemById(id: string, tenantId: string) {
  return apiClient.get(`/api/v1/siem/${id}?tenantId=${tenantId}`.trim());
}
export async function exportSiem(tenantId: string, format: 'csv'|'json'|'pdf'='csv') {
  return apiClient.getBlob(`/api/v1/siem/export?tenantId=${tenantId}&format=${format}`);
}
