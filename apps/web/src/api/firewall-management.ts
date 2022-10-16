import { apiClient } from '../lib/apiClient';
import type { FirewallManagementRecord, FirewallManagementFilter, FirewallManagementMetrics } from '../types/firewall-management';
export interface FirewallManagementQuery { tenantId: string; filter: FirewallManagementFilter; range: { from: Date; to: Date }; }
export interface FirewallManagementResponse { items: FirewallManagementRecord[]; metrics: FirewallManagementMetrics; }
export async function fetchFirewallManagementData(q: FirewallManagementQuery): Promise<FirewallManagementResponse> {
  const p = new URLSearchParams({ tenantId: q.tenantId, q: q.filter.query, status: q.filter.status, page: String(q.filter.page), pageSize: String(q.filter.pageSize), from: q.range.from.toISOString(), to: q.range.to.toISOString() });
  return apiClient.get(`/api/v1/firewall-management?${p}`.trim());
}
export async function mutateFirewallManagement(body: { action: string; ids: string[]; tenantId: string }) {
  await apiClient.post(`/api/v1/firewall-management/bulk`, body);
}
export async function getFirewallManagementById(id: string, tenantId: string) {
  return apiClient.get(`/api/v1/firewall-management/${id}?tenantId=${tenantId}`.trim());
}
export async function exportFirewallManagement(tenantId: string, format: 'csv'|'json'|'pdf'='csv') {
  return apiClient.getBlob(`/api/v1/firewall-management/export?tenantId=${tenantId}&format=${format}`);
}
