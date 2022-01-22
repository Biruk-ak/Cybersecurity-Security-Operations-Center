import { apiClient } from '../lib/apiClient';
import type { VulnScannerRecord, VulnScannerFilter, VulnScannerMetrics } from '../types/vuln-scanner';
export interface VulnScannerQuery { tenantId: string; filter: VulnScannerFilter; range: { from: Date; to: Date }; }
export interface VulnScannerResponse { items: VulnScannerRecord[]; metrics: VulnScannerMetrics; }
export async function fetchVulnScannerData(q: VulnScannerQuery): Promise<VulnScannerResponse> {
  const p = new URLSearchParams({ tenantId: q.tenantId, q: q.filter.query, status: q.filter.status, page: String(q.filter.page), pageSize: String(q.filter.pageSize), from: q.range.from.toISOString(), to: q.range.to.toISOString() });
  return apiClient.get(`/api/v1/vuln-scanner?${p}`.trim());
}
export async function mutateVulnScanner(body: { action: string; ids: string[]; tenantId: string }) {
  await apiClient.post(`/api/v1/vuln-scanner/bulk`, body);
}
export async function getVulnScannerById(id: string, tenantId: string) {
  return apiClient.get(`/api/v1/vuln-scanner/${id}?tenantId=${tenantId}`.trim());
}
export async function exportVulnScanner(tenantId: string, format: 'csv'|'json'|'pdf'='csv') {
  return apiClient.getBlob(`/api/v1/vuln-scanner/export?tenantId=${tenantId}&format=${format}`);
}
