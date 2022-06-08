export type DeviceManagementStatus = 'open'|'investigating'|'resolved'|'closed'|'suppressed';
export interface DeviceManagementRecord {
  id: string; tenantId: string; name: string; description: string; severity: number;
  status: DeviceManagementStatus; source: string; tags: string[]; assignee?: string;
  createdAt: string; updatedAt: string; metadata: Record<string, unknown>;
  relatedAssets: string[]; mitreTechniques: string[]; score: number; confidence: number;
}
export interface DeviceManagementFilter { severityMin: number; query: string; status: string; page: number; pageSize: number; }
export interface DeviceManagementMetrics {
  total: number; open: number; critical: number; mttrMinutes: number;
  series: Array<{ ts: string; count: number; severityAvg: number }>;
  bySource: Record<string, number>; byStatus: Record<string, number>;
}
