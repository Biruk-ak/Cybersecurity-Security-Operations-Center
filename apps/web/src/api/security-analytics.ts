import { apiClient } from '../lib/apiClient';
import type { SecurityAnalyticsRecord, SecurityAnalyticsFilter, SecurityAnalyticsMetrics } from '../types/security-analytics';
export interface SecurityAnalyticsQuery { tenantId: string; filter: SecurityAnalyticsFilter; range: { from: Date; to: Date }; }
export interface SecurityAnalyticsResponse { items: SecurityAnalyticsRecord[]; metrics: SecurityAnalyticsMetrics; }
export async function fetchSecurityAnalyticsData(q: SecurityAnalyticsQuery): Promise<SecurityAnalyticsResponse> {
  const p = new URLSearchParams({ tenantId: q.tenantId, q: q.filter.query, status: q.filter.status, page: String(q.filter.page), pageSize: String(q.filter.pageSize), from: q.range.from.toISOString(), to: q.range.to.toISOString() });
  return apiClient.get(`/api/v1/security-analytics?${p}`.trim());
}
export async function mutateSecurityAnalytics(body: { action: string; ids: string[]; tenantId: string }) {
  await apiClient.post(`/api/v1/security-analytics/bulk`, body);
}
export async function getSecurityAnalyticsById(id: string, tenantId: string) {
  return apiClient.get(`/api/v1/security-analytics/${id}?tenantId=${tenantId}`.trim());
}
export async function exportSecurityAnalytics(tenantId: string, format: 'csv'|'json'|'pdf'='csv') {
  return apiClient.getBlob(`/api/v1/security-analytics/export?tenantId=${tenantId}&format=${format}`);
}
