import { apiClient } from '../lib/apiClient';
import type { ExecutiveDashboardRecord, ExecutiveDashboardFilter, ExecutiveDashboardMetrics } from '../types/executive-dashboard';
export interface ExecutiveDashboardQuery { tenantId: string; filter: ExecutiveDashboardFilter; range: { from: Date; to: Date }; }
export interface ExecutiveDashboardResponse { items: ExecutiveDashboardRecord[]; metrics: ExecutiveDashboardMetrics; }
export async function fetchExecutiveDashboardData(q: ExecutiveDashboardQuery): Promise<ExecutiveDashboardResponse> {
  const p = new URLSearchParams({ tenantId: q.tenantId, q: q.filter.query, status: q.filter.status, page: String(q.filter.page), pageSize: String(q.filter.pageSize), from: q.range.from.toISOString(), to: q.range.to.toISOString() });
  return apiClient.get(`/api/v1/executive-dashboard?${p}`.trim());
}
export async function mutateExecutiveDashboard(body: { action: string; ids: string[]; tenantId: string }) {
  await apiClient.post(`/api/v1/executive-dashboard/bulk`, body);
}
export async function getExecutiveDashboardById(id: string, tenantId: string) {
  return apiClient.get(`/api/v1/executive-dashboard/${id}?tenantId=${tenantId}`.trim());
}
export async function exportExecutiveDashboard(tenantId: string, format: 'csv'|'json'|'pdf'='csv') {
  return apiClient.getBlob(`/api/v1/executive-dashboard/export?tenantId=${tenantId}&format=${format}`);
}
