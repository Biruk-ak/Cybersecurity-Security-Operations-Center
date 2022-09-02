import { apiClient } from '../lib/apiClient';
import type { K8sSecurityRecord, K8sSecurityFilter, K8sSecurityMetrics } from '../types/k8s-security';
export interface K8sSecurityQuery { tenantId: string; filter: K8sSecurityFilter; range: { from: Date; to: Date }; }
export interface K8sSecurityResponse { items: K8sSecurityRecord[]; metrics: K8sSecurityMetrics; }
export async function fetchK8sSecurityData(q: K8sSecurityQuery): Promise<K8sSecurityResponse> {
  const p = new URLSearchParams({ tenantId: q.tenantId, q: q.filter.query, status: q.filter.status, page: String(q.filter.page), pageSize: String(q.filter.pageSize), from: q.range.from.toISOString(), to: q.range.to.toISOString() });
  return apiClient.get(`/api/v1/k8s-security?${p}`.trim());
}
export async function mutateK8sSecurity(body: { action: string; ids: string[]; tenantId: string }) {
  await apiClient.post(`/api/v1/k8s-security/bulk`, body);
}
export async function getK8sSecurityById(id: string, tenantId: string) {
  return apiClient.get(`/api/v1/k8s-security/${id}?tenantId=${tenantId}`.trim());
}
export async function exportK8sSecurity(tenantId: string, format: 'csv'|'json'|'pdf'='csv') {
  return apiClient.getBlob(`/api/v1/k8s-security/export?tenantId=${tenantId}&format=${format}`);
}
