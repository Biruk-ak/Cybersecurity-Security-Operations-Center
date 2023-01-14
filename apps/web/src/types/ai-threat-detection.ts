export type AiThreatDetectionStatus = 'open'|'investigating'|'resolved'|'closed'|'suppressed';
export interface AiThreatDetectionRecord {
  id: string; tenantId: string; name: string; description: string; severity: number;
  status: AiThreatDetectionStatus; source: string; tags: string[]; assignee?: string;
  createdAt: string; updatedAt: string; metadata: Record<string, unknown>;
  relatedAssets: string[]; mitreTechniques: string[]; score: number; confidence: number;
}
export interface AiThreatDetectionFilter { severityMin: number; query: string; status: string; page: number; pageSize: number; }
export interface AiThreatDetectionMetrics {
  total: number; open: number; critical: number; mttrMinutes: number;
  series: Array<{ ts: string; count: number; severityAvg: number }>;
  bySource: Record<string, number>; byStatus: Record<string, number>;
}
