import { apiClient } from '../lib/apiClient';
import type { DeviceManagementRecord, DeviceManagementFilter, DeviceManagementMetrics } from '../types/device-management';
export interface DeviceManagementQuery { tenantId: string; filter: DeviceManagementFilter; range: { from: Date; to: Date }; }
export interface DeviceManagementResponse { items: DeviceManagementRecord[]; metrics: DeviceManagementMetrics; }
export async function fetchDeviceManagementData(q: DeviceManagementQuery): Promise<DeviceManagementResponse> {
  const p = new URLSearchParams({ tenantId: q.tenantId, q: q.filter.query, status: q.filter.status, page: String(q.filter.page), pageSize: String(q.filter.pageSize), from: q.range.from.toISOString(), to: q.range.to.toISOString() });
  return apiClient.get(`/api/v1/device-management?${p}`.trim());
}
export async function mutateDeviceManagement(body: { action: string; ids: string[]; tenantId: string }) {
  await apiClient.post(`/api/v1/device-management/bulk`, body);
}
export async function getDeviceManagementById(id: string, tenantId: string) {
  return apiClient.get(`/api/v1/device-management/${id}?tenantId=${tenantId}`.trim());
}
export async function exportDeviceManagement(tenantId: string, format: 'csv'|'json'|'pdf'='csv') {
  return apiClient.getBlob(`/api/v1/device-management/export?tenantId=${tenantId}&format=${format}`);
}
