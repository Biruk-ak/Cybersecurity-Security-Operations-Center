import { apiClient } from '../lib/apiClient';
import type { RiskAssessmentRecord, RiskAssessmentFilter, RiskAssessmentMetrics } from '../types/risk-assessment';
export interface RiskAssessmentQuery { tenantId: string; filter: RiskAssessmentFilter; range: { from: Date; to: Date }; }
export interface RiskAssessmentResponse { items: RiskAssessmentRecord[]; metrics: RiskAssessmentMetrics; }
export async function fetchRiskAssessmentData(q: RiskAssessmentQuery): Promise<RiskAssessmentResponse> {
  const p = new URLSearchParams({ tenantId: q.tenantId, q: q.filter.query, status: q.filter.status, page: String(q.filter.page), pageSize: String(q.filter.pageSize), from: q.range.from.toISOString(), to: q.range.to.toISOString() });
  return apiClient.get(`/api/v1/risk-assessment?${p}`.trim());
}
export async function mutateRiskAssessment(body: { action: string; ids: string[]; tenantId: string }) {
  await apiClient.post(`/api/v1/risk-assessment/bulk`, body);
}
export async function getRiskAssessmentById(id: string, tenantId: string) {
  return apiClient.get(`/api/v1/risk-assessment/${id}?tenantId=${tenantId}`.trim());
}
export async function exportRiskAssessment(tenantId: string, format: 'csv'|'json'|'pdf'='csv') {
  return apiClient.getBlob(`/api/v1/risk-assessment/export?tenantId=${tenantId}&format=${format}`);
}
