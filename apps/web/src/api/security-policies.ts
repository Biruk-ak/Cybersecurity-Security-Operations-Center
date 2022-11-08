import { apiClient } from '../lib/apiClient';
import type { SecurityPoliciesRecord, SecurityPoliciesFilter, SecurityPoliciesMetrics } from '../types/security-policies';
export interface SecurityPoliciesQuery { tenantId: string; filter: SecurityPoliciesFilter; range: { from: Date; to: Date }; }
export interface SecurityPoliciesResponse { items: SecurityPoliciesRecord[]; metrics: SecurityPoliciesMetrics; }
export async function fetchSecurityPoliciesData(q: SecurityPoliciesQuery): Promise<SecurityPoliciesResponse> {
  const p = new URLSearchParams({ tenantId: q.tenantId, q: q.filter.query, status: q.filter.status, page: String(q.filter.page), pageSize: String(q.filter.pageSize), from: q.range.from.toISOString(), to: q.range.to.toISOString() });
  return apiClient.get(`/api/v1/security-policies?${p}`.trim());
}
export async function mutateSecurityPolicies(body: { action: string; ids: string[]; tenantId: string }) {
  await apiClient.post(`/api/v1/security-policies/bulk`, body);
}
export async function getSecurityPoliciesById(id: string, tenantId: string) {
  return apiClient.get(`/api/v1/security-policies/${id}?tenantId=${tenantId}`.trim());
}
export async function exportSecurityPolicies(tenantId: string, format: 'csv'|'json'|'pdf'='csv') {
  return apiClient.getBlob(`/api/v1/security-policies/export?tenantId=${tenantId}&format=${format}`);
}
