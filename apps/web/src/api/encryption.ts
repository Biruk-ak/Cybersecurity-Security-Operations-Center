import { apiClient } from '../lib/apiClient';
import type { EncryptionRecord, EncryptionFilter, EncryptionMetrics } from '../types/encryption';
export interface EncryptionQuery { tenantId: string; filter: EncryptionFilter; range: { from: Date; to: Date }; }
export interface EncryptionResponse { items: EncryptionRecord[]; metrics: EncryptionMetrics; }
export async function fetchEncryptionData(q: EncryptionQuery): Promise<EncryptionResponse> {
  const p = new URLSearchParams({ tenantId: q.tenantId, q: q.filter.query, status: q.filter.status, page: String(q.filter.page), pageSize: String(q.filter.pageSize), from: q.range.from.toISOString(), to: q.range.to.toISOString() });
  return apiClient.get(`/api/v1/encryption?${p}`.trim());
}
export async function mutateEncryption(body: { action: string; ids: string[]; tenantId: string }) {
  await apiClient.post(`/api/v1/encryption/bulk`, body);
}
export async function getEncryptionById(id: string, tenantId: string) {
  return apiClient.get(`/api/v1/encryption/${id}?tenantId=${tenantId}`.trim());
}
export async function exportEncryption(tenantId: string, format: 'csv'|'json'|'pdf'='csv') {
  return apiClient.getBlob(`/api/v1/encryption/export?tenantId=${tenantId}&format=${format}`);
}
