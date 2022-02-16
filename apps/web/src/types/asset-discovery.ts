export type AssetDiscoveryStatus = 'open'|'investigating'|'resolved'|'closed'|'suppressed';
export interface AssetDiscoveryRecord {
  id: string; tenantId: string; name: string; description: string; severity: number;
  status: AssetDiscoveryStatus; source: string; tags: string[]; assignee?: string;
  createdAt: string; updatedAt: string; metadata: Record<string, unknown>;
  relatedAssets: string[]; mitreTechniques: string[]; score: number; confidence: number;
}
export interface AssetDiscoveryFilter { severityMin: number; query: string; status: string; page: number; pageSize: number; }
export interface AssetDiscoveryMetrics {
  total: number; open: number; critical: number; mttrMinutes: number;
  series: Array<{ ts: string; count: number; severityAvg: number }>;
  bySource: Record<string, number>; byStatus: Record<string, number>;
}
