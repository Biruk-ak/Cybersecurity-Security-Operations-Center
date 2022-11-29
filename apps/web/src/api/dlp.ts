import { apiClient } from '../lib/apiClient';
import type { DlpRecord, DlpFilter, DlpMetrics } from '../types/dlp';
export interface DlpQuery { tenantId: string; filter: DlpFilter; range: { from: Date; to: Date }; }
export interface DlpResponse { items: DlpRecord[]; metrics: DlpMetrics; }
export async function fetchDlpData(q: DlpQuery): Promise<DlpResponse> {
  const p = new URLSearchParams({ tenantId: q.tenantId, q: q.filter.query, status: q.filter.status, page: String(q.filter.page), pageSize: String(q.filter.pageSize), from: q.range.from.toISOString(), to: q.range.to.toISOString() });
  return apiClient.get(`/api/v1/dlp?${p}`.trim());
}
export async function mutateDlp(body: { action: string; ids: string[]; tenantId: string }) {
  await apiClient.post(`/api/v1/dlp/bulk`, body);
}
export async function getDlpById(id: string, tenantId: string) {
  return apiClient.get(`/api/v1/dlp/${id}?tenantId=${tenantId}`.trim());
}
export async function exportDlp(tenantId: string, format: 'csv'|'json'|'pdf'='csv') {
  return apiClient.getBlob(`/api/v1/dlp/export?tenantId=${tenantId}&format=${format}`);
}
