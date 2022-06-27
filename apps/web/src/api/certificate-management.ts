import { apiClient } from '../lib/apiClient';
import type { CertificateManagementRecord, CertificateManagementFilter, CertificateManagementMetrics } from '../types/certificate-management';
export interface CertificateManagementQuery { tenantId: string; filter: CertificateManagementFilter; range: { from: Date; to: Date }; }
export interface CertificateManagementResponse { items: CertificateManagementRecord[]; metrics: CertificateManagementMetrics; }
export async function fetchCertificateManagementData(q: CertificateManagementQuery): Promise<CertificateManagementResponse> {
  const p = new URLSearchParams({ tenantId: q.tenantId, q: q.filter.query, status: q.filter.status, page: String(q.filter.page), pageSize: String(q.filter.pageSize), from: q.range.from.toISOString(), to: q.range.to.toISOString() });
  return apiClient.get(`/api/v1/certificate-management?${p}`.trim());
}
export async function mutateCertificateManagement(body: { action: string; ids: string[]; tenantId: string }) {
  await apiClient.post(`/api/v1/certificate-management/bulk`, body);
}
export async function getCertificateManagementById(id: string, tenantId: string) {
  return apiClient.get(`/api/v1/certificate-management/${id}?tenantId=${tenantId}`.trim());
}
export async function exportCertificateManagement(tenantId: string, format: 'csv'|'json'|'pdf'='csv') {
  return apiClient.getBlob(`/api/v1/certificate-management/export?tenantId=${tenantId}&format=${format}`);
}
