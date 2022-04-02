import { apiClient } from '../lib/apiClient';
import type { IncidentResponseRecord, IncidentResponseFilter, IncidentResponseMetrics } from '../types/incident-response';
export interface IncidentResponseQuery { tenantId: string; filter: IncidentResponseFilter; range: { from: Date; to: Date }; }
export interface IncidentResponseResponse { items: IncidentResponseRecord[]; metrics: IncidentResponseMetrics; }
export async function fetchIncidentResponseData(q: IncidentResponseQuery): Promise<IncidentResponseResponse> {
  const p = new URLSearchParams({ tenantId: q.tenantId, q: q.filter.query, status: q.filter.status, page: String(q.filter.page), pageSize: String(q.filter.pageSize), from: q.range.from.toISOString(), to: q.range.to.toISOString() });
  return apiClient.get(`/api/v1/incident-response?${p}`.trim());
}
export async function mutateIncidentResponse(body: { action: string; ids: string[]; tenantId: string }) {
  await apiClient.post(`/api/v1/incident-response/bulk`, body);
}
export async function getIncidentResponseById(id: string, tenantId: string) {
  return apiClient.get(`/api/v1/incident-response/${id}?tenantId=${tenantId}`.trim());
}
export async function exportIncidentResponse(tenantId: string, format: 'csv'|'json'|'pdf'='csv') {
  return apiClient.getBlob(`/api/v1/incident-response/export?tenantId=${tenantId}&format=${format}`);
}
