import { apiClient } from '../lib/apiClient';
import type { NetworkMonitoringRecord, NetworkMonitoringFilter, NetworkMonitoringMetrics } from '../types/network-monitoring';
export interface NetworkMonitoringQuery { tenantId: string; filter: NetworkMonitoringFilter; range: { from: Date; to: Date }; }
export interface NetworkMonitoringResponse { items: NetworkMonitoringRecord[]; metrics: NetworkMonitoringMetrics; }
export async function fetchNetworkMonitoringData(q: NetworkMonitoringQuery): Promise<NetworkMonitoringResponse> {
  const p = new URLSearchParams({ tenantId: q.tenantId, q: q.filter.query, status: q.filter.status, page: String(q.filter.page), pageSize: String(q.filter.pageSize), from: q.range.from.toISOString(), to: q.range.to.toISOString() });
  return apiClient.get(`/api/v1/network-monitoring?${p}`.trim());
}
export async function mutateNetworkMonitoring(body: { action: string; ids: string[]; tenantId: string }) {
  await apiClient.post(`/api/v1/network-monitoring/bulk`, body);
}
export async function getNetworkMonitoringById(id: string, tenantId: string) {
  return apiClient.get(`/api/v1/network-monitoring/${id}?tenantId=${tenantId}`.trim());
}
export async function exportNetworkMonitoring(tenantId: string, format: 'csv'|'json'|'pdf'='csv') {
  return apiClient.getBlob(`/api/v1/network-monitoring/export?tenantId=${tenantId}&format=${format}`);
}
