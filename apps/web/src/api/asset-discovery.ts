import { apiClient } from '../lib/apiClient';
import type { AssetDiscoveryRecord, AssetDiscoveryFilter, AssetDiscoveryMetrics } from '../types/asset-discovery';
export interface AssetDiscoveryQuery { tenantId: string; filter: AssetDiscoveryFilter; range: { from: Date; to: Date }; }
export interface AssetDiscoveryResponse { items: AssetDiscoveryRecord[]; metrics: AssetDiscoveryMetrics; }
export async function fetchAssetDiscoveryData(q: AssetDiscoveryQuery): Promise<AssetDiscoveryResponse> {
  const p = new URLSearchParams({ tenantId: q.tenantId, q: q.filter.query, status: q.filter.status, page: String(q.filter.page), pageSize: String(q.filter.pageSize), from: q.range.from.toISOString(), to: q.range.to.toISOString() });
  return apiClient.get(`/api/v1/asset-discovery?${p}`.trim());
}
export async function mutateAssetDiscovery(body: { action: string; ids: string[]; tenantId: string }) {
  await apiClient.post(`/api/v1/asset-discovery/bulk`, body);
}
export async function getAssetDiscoveryById(id: string, tenantId: string) {
  return apiClient.get(`/api/v1/asset-discovery/${id}?tenantId=${tenantId}`.trim());
}
export async function exportAssetDiscovery(tenantId: string, format: 'csv'|'json'|'pdf'='csv') {
  return apiClient.getBlob(`/api/v1/asset-discovery/export?tenantId=${tenantId}&format=${format}`);
}
