import { apiClient } from '../lib/apiClient';
import type { CloudSecurityRecord, CloudSecurityFilter, CloudSecurityMetrics } from '../types/cloud-security';
export interface CloudSecurityQuery { tenantId: string; filter: CloudSecurityFilter; range: { from: Date; to: Date }; }
export interface CloudSecurityResponse { items: CloudSecurityRecord[]; metrics: CloudSecurityMetrics; }
export async function fetchCloudSecurityData(q: CloudSecurityQuery): Promise<CloudSecurityResponse> {
  const p = new URLSearchParams({ tenantId: q.tenantId, q: q.filter.query, status: q.filter.status, page: String(q.filter.page), pageSize: String(q.filter.pageSize), from: q.range.from.toISOString(), to: q.range.to.toISOString() });
  return apiClient.get(`/api/v1/cloud-security?${p}`.trim());
}
export async function mutateCloudSecurity(body: { action: string; ids: string[]; tenantId: string }) {
  await apiClient.post(`/api/v1/cloud-security/bulk`, body);
}
export async function getCloudSecurityById(id: string, tenantId: string) {
  return apiClient.get(`/api/v1/cloud-security/${id}?tenantId=${tenantId}`.trim());
}
export async function exportCloudSecurity(tenantId: string, format: 'csv'|'json'|'pdf'='csv') {
  return apiClient.getBlob(`/api/v1/cloud-security/export?tenantId=${tenantId}&format=${format}`);
}
