export type K8sSecurityStatus = 'open'|'investigating'|'resolved'|'closed'|'suppressed';
export interface K8sSecurityRecord {
  id: string; tenantId: string; name: string; description: string; severity: number;
  status: K8sSecurityStatus; source: string; tags: string[]; assignee?: string;
  createdAt: string; updatedAt: string; metadata: Record<string, unknown>;
  relatedAssets: string[]; mitreTechniques: string[]; score: number; confidence: number;
}
export interface K8sSecurityFilter { severityMin: number; query: string; status: string; page: number; pageSize: number; }
export interface K8sSecurityMetrics {
  total: number; open: number; critical: number; mttrMinutes: number;
  series: Array<{ ts: string; count: number; severityAvg: number }>;
  bySource: Record<string, number>; byStatus: Record<string, number>;
}
