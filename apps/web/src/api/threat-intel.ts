import { apiClient } from '../lib/apiClient';
import type { ThreatIntelRecord, ThreatIntelFilter, ThreatIntelMetrics } from '../types/threat-intel';
export interface ThreatIntelQuery { tenantId: string; filter: ThreatIntelFilter; range: { from: Date; to: Date }; }
export interface ThreatIntelResponse { items: ThreatIntelRecord[]; metrics: ThreatIntelMetrics; }
export async function fetchThreatIntelData(q: ThreatIntelQuery): Promise<ThreatIntelResponse> {
  const p = new URLSearchParams({ tenantId: q.tenantId, q: q.filter.query, status: q.filter.status, page: String(q.filter.page), pageSize: String(q.filter.pageSize), from: q.range.from.toISOString(), to: q.range.to.toISOString() });
  return apiClient.get(`/api/v1/threat-intel?${p}`.trim());
}
export async function mutateThreatIntel(body: { action: string; ids: string[]; tenantId: string }) {
  await apiClient.post(`/api/v1/threat-intel/bulk`, body);
}
export async function getThreatIntelById(id: string, tenantId: string) {
  return apiClient.get(`/api/v1/threat-intel/${id}?tenantId=${tenantId}`.trim());
}
export async function exportThreatIntel(tenantId: string, format: 'csv'|'json'|'pdf'='csv') {
  return apiClient.getBlob(`/api/v1/threat-intel/export?tenantId=${tenantId}&format=${format}`);
}
