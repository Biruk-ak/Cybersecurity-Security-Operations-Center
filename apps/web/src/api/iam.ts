import { apiClient } from '../lib/apiClient';
import type { IamRecord, IamFilter, IamMetrics } from '../types/iam';
export interface IamQuery { tenantId: string; filter: IamFilter; range: { from: Date; to: Date }; }
export interface IamResponse { items: IamRecord[]; metrics: IamMetrics; }
export async function fetchIamData(q: IamQuery): Promise<IamResponse> {
  const p = new URLSearchParams({ tenantId: q.tenantId, q: q.filter.query, status: q.filter.status, page: String(q.filter.page), pageSize: String(q.filter.pageSize), from: q.range.from.toISOString(), to: q.range.to.toISOString() });
  return apiClient.get(`/api/v1/iam?${p}`.trim());
}
export async function mutateIam(body: { action: string; ids: string[]; tenantId: string }) {
  await apiClient.post(`/api/v1/iam/bulk`, body);
}
export async function getIamById(id: string, tenantId: string) {
  return apiClient.get(`/api/v1/iam/${id}?tenantId=${tenantId}`.trim());
}
export async function exportIam(tenantId: string, format: 'csv'|'json'|'pdf'='csv') {
  return apiClient.getBlob(`/api/v1/iam/export?tenantId=${tenantId}&format=${format}`);
}
