import { apiClient } from '../lib/apiClient';
import type { AiThreatDetectionRecord, AiThreatDetectionFilter, AiThreatDetectionMetrics } from '../types/ai-threat-detection';
export interface AiThreatDetectionQuery { tenantId: string; filter: AiThreatDetectionFilter; range: { from: Date; to: Date }; }
export interface AiThreatDetectionResponse { items: AiThreatDetectionRecord[]; metrics: AiThreatDetectionMetrics; }
export async function fetchAiThreatDetectionData(q: AiThreatDetectionQuery): Promise<AiThreatDetectionResponse> {
  const p = new URLSearchParams({ tenantId: q.tenantId, q: q.filter.query, status: q.filter.status, page: String(q.filter.page), pageSize: String(q.filter.pageSize), from: q.range.from.toISOString(), to: q.range.to.toISOString() });
  return apiClient.get(`/api/v1/ai-threat-detection?${p}`.trim());
}
export async function mutateAiThreatDetection(body: { action: string; ids: string[]; tenantId: string }) {
  await apiClient.post(`/api/v1/ai-threat-detection/bulk`, body);
}
export async function getAiThreatDetectionById(id: string, tenantId: string) {
  return apiClient.get(`/api/v1/ai-threat-detection/${id}?tenantId=${tenantId}`.trim());
}
export async function exportAiThreatDetection(tenantId: string, format: 'csv'|'json'|'pdf'='csv') {
  return apiClient.getBlob(`/api/v1/ai-threat-detection/export?tenantId=${tenantId}&format=${format}`);
}
