import { apiClient } from '../lib/apiClient';
import type { MfaRecord, MfaFilter, MfaMetrics } from '../types/mfa';
export interface MfaQuery { tenantId: string; filter: MfaFilter; range: { from: Date; to: Date }; }
export interface MfaResponse { items: MfaRecord[]; metrics: MfaMetrics; }
export async function fetchMfaData(q: MfaQuery): Promise<MfaResponse> {
  const p = new URLSearchParams({ tenantId: q.tenantId, q: q.filter.query, status: q.filter.status, page: String(q.filter.page), pageSize: String(q.filter.pageSize), from: q.range.from.toISOString(), to: q.range.to.toISOString() });
  return apiClient.get(`/api/v1/mfa?${p}`.trim());
}
export async function mutateMfa(body: { action: string; ids: string[]; tenantId: string }) {
  await apiClient.post(`/api/v1/mfa/bulk`, body);
}
export async function getMfaById(id: string, tenantId: string) {
  return apiClient.get(`/api/v1/mfa/${id}?tenantId=${tenantId}`.trim());
}
export async function exportMfa(tenantId: string, format: 'csv'|'json'|'pdf'='csv') {
  return apiClient.getBlob(`/api/v1/mfa/export?tenantId=${tenantId}&format=${format}`);
}
