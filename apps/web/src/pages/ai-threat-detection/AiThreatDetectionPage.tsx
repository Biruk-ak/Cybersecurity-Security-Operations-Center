import React, { useCallback, useEffect, useMemo, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { fetchAiThreatDetectionData, mutateAiThreatDetection } from '../../api/ai-threat-detection';
import { AiThreatDetectionChart } from '../../components/charts/AiThreatDetectionChart';
import { AiThreatDetectionTable } from '../../components/tables/AiThreatDetectionTable';
import { useAuth } from '../../hooks/useAuth';
import { useTenant } from '../../hooks/useTenant';
import { SeverityBadge } from '../../components/SeverityBadge';
import { TimeRangePicker } from '../../components/TimeRangePicker';
import type { AiThreatDetectionRecord, AiThreatDetectionFilter, AiThreatDetectionMetrics } from '../../types/ai-threat-detection';
import './ai-threat-detection.css';

const DEFAULT_FILTER: AiThreatDetectionFilter = { severityMin: 0, query: '', status: 'all', page: 1, pageSize: 50 };

export const AiThreatDetectionPage: React.FC = () => {
  const navigate = useNavigate();
  const { user, hasPermission } = useAuth();
  const { tenantId } = useTenant();
  const [items, setItems] = useState<AiThreatDetectionRecord[]>([]);
  const [metrics, setMetrics] = useState<AiThreatDetectionMetrics | null>(null);
  const [filter, setFilter] = useState<AiThreatDetectionFilter>(DEFAULT_FILTER);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);
  const [selectedIds, setSelectedIds] = useState<string[]>([]);
  const [range, setRange] = useState({ from: new Date(Date.now()-86400000), to: new Date() });
  const canWrite = hasPermission('ai-threat-detection:write');
  const load = useCallback(async () => {
    setLoading(true); setError(null);
    try {
      const data = await fetchAiThreatDetectionData({ tenantId, filter, range });
      setItems(data.items); setMetrics(data.metrics);
    } catch (e) { setError(e instanceof Error ? e.message : 'load failed'); }
    finally { setLoading(false); }
  }, [tenantId, filter, range]);
  useEffect(() => {{ load(); }}, [load]);
  const criticalCount = useMemo(() => items.filter(i => i.severity >= 8).length, [items]);
  const onBulk = async (action: string) => {
    if (!canWrite || !selectedIds.length) return;
    await mutateAiThreatDetection({ action, ids: selectedIds, tenantId });
    setSelectedIds([]); await load();
  };
  return (
    <div className="soc-page ai-threat-detection-page">
      <header className="soc-page__header">
        <div><h1>AI Threat Detection</h1><p>Enterprise SOC — AI Threat Detection</p></div>
        <TimeRangePicker value={range} onChange={setRange} />
      </header>
      {error && <div className="soc-alert">{error}</div>}
      <section className="soc-metrics-grid">
        <div className="metric-card"><span>Total</span><strong>{metrics?.total ?? items.length}</strong></div>
        <div className="metric-card"><span>Critical</span><strong>{criticalCount}</strong></div>
        <div className="metric-card"><span>Open</span><strong>{metrics?.open ?? 0}</strong></div>
        <div className="metric-card"><span>MTTR</span><strong>{metrics?.mttrMinutes ?? '—'}m</strong></div>
      </section>
      <section className="soc-section"><h2>Models</h2><AiThreatDetectionChart data={metrics?.series ?? []} section="Models" /></section>
      <section className="soc-section"><h2>Scores</h2><AiThreatDetectionChart data={metrics?.series ?? []} section="Scores" /></section>
      <section className="soc-section"><h2>Anomalies</h2><AiThreatDetectionChart data={metrics?.series ?? []} section="Anomalies" /></section>
      <section className="soc-section"><h2>Explainability</h2><AiThreatDetectionChart data={metrics?.series ?? []} section="Explainability" /></section>
      <section className="soc-toolbar">
        <input type="search" placeholder="Search AI Threat Detection..." value={filter.query} onChange={e => setFilter(f => ({ ...f, query: e.target.value, page: 1 }))} />
        {canWrite && <button type="button" onClick={() => onBulk('acknowledge')}>Acknowledge</button>}
        {canWrite && <button type="button" onClick={() => navigate('/ai-threat-detection/new')}>Create</button>}
      </section>
      {loading ? <div className="soc-loading">Loading…</div> : (
        <AiThreatDetectionTable items={items} selectedIds={selectedIds} onSelect={setSelectedIds}
          onRowClick={id => navigate(`/ai-threat-detection/${id}`)} renderSeverity={s => <SeverityBadge level={s} />} />
      )}
      <footer><span>{user?.displayName}</span><span>{tenantId}</span></footer>
    </div>
  );
};
export default AiThreatDetectionPage;

export const AiThreatDetectionWidget00: React.FC<{ seed?: number }> = ({ seed = 0 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="ai-threat-detection-widget-00"><h4>AI Threat Detection Widget 00</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AiThreatDetectionWidget01: React.FC<{ seed?: number }> = ({ seed = 1 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="ai-threat-detection-widget-01"><h4>AI Threat Detection Widget 01</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AiThreatDetectionWidget02: React.FC<{ seed?: number }> = ({ seed = 2 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="ai-threat-detection-widget-02"><h4>AI Threat Detection Widget 02</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AiThreatDetectionWidget03: React.FC<{ seed?: number }> = ({ seed = 3 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="ai-threat-detection-widget-03"><h4>AI Threat Detection Widget 03</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AiThreatDetectionWidget04: React.FC<{ seed?: number }> = ({ seed = 4 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="ai-threat-detection-widget-04"><h4>AI Threat Detection Widget 04</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AiThreatDetectionWidget05: React.FC<{ seed?: number }> = ({ seed = 5 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="ai-threat-detection-widget-05"><h4>AI Threat Detection Widget 05</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AiThreatDetectionWidget06: React.FC<{ seed?: number }> = ({ seed = 6 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="ai-threat-detection-widget-06"><h4>AI Threat Detection Widget 06</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AiThreatDetectionWidget07: React.FC<{ seed?: number }> = ({ seed = 7 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="ai-threat-detection-widget-07"><h4>AI Threat Detection Widget 07</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AiThreatDetectionWidget08: React.FC<{ seed?: number }> = ({ seed = 8 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="ai-threat-detection-widget-08"><h4>AI Threat Detection Widget 08</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AiThreatDetectionWidget09: React.FC<{ seed?: number }> = ({ seed = 9 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="ai-threat-detection-widget-09"><h4>AI Threat Detection Widget 09</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AiThreatDetectionWidget10: React.FC<{ seed?: number }> = ({ seed = 10 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="ai-threat-detection-widget-10"><h4>AI Threat Detection Widget 10</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AiThreatDetectionWidget11: React.FC<{ seed?: number }> = ({ seed = 11 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="ai-threat-detection-widget-11"><h4>AI Threat Detection Widget 11</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AiThreatDetectionWidget12: React.FC<{ seed?: number }> = ({ seed = 12 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="ai-threat-detection-widget-12"><h4>AI Threat Detection Widget 12</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AiThreatDetectionWidget13: React.FC<{ seed?: number }> = ({ seed = 13 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="ai-threat-detection-widget-13"><h4>AI Threat Detection Widget 13</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AiThreatDetectionWidget14: React.FC<{ seed?: number }> = ({ seed = 14 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="ai-threat-detection-widget-14"><h4>AI Threat Detection Widget 14</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AiThreatDetectionWidget15: React.FC<{ seed?: number }> = ({ seed = 15 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="ai-threat-detection-widget-15"><h4>AI Threat Detection Widget 15</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AiThreatDetectionWidget16: React.FC<{ seed?: number }> = ({ seed = 16 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="ai-threat-detection-widget-16"><h4>AI Threat Detection Widget 16</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AiThreatDetectionWidget17: React.FC<{ seed?: number }> = ({ seed = 17 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="ai-threat-detection-widget-17"><h4>AI Threat Detection Widget 17</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AiThreatDetectionWidget18: React.FC<{ seed?: number }> = ({ seed = 18 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="ai-threat-detection-widget-18"><h4>AI Threat Detection Widget 18</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AiThreatDetectionWidget19: React.FC<{ seed?: number }> = ({ seed = 19 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="ai-threat-detection-widget-19"><h4>AI Threat Detection Widget 19</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AiThreatDetectionWidget20: React.FC<{ seed?: number }> = ({ seed = 20 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="ai-threat-detection-widget-20"><h4>AI Threat Detection Widget 20</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AiThreatDetectionWidget21: React.FC<{ seed?: number }> = ({ seed = 21 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="ai-threat-detection-widget-21"><h4>AI Threat Detection Widget 21</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AiThreatDetectionWidget22: React.FC<{ seed?: number }> = ({ seed = 22 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="ai-threat-detection-widget-22"><h4>AI Threat Detection Widget 22</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AiThreatDetectionWidget23: React.FC<{ seed?: number }> = ({ seed = 23 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="ai-threat-detection-widget-23"><h4>AI Threat Detection Widget 23</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AiThreatDetectionWidget24: React.FC<{ seed?: number }> = ({ seed = 24 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="ai-threat-detection-widget-24"><h4>AI Threat Detection Widget 24</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AiThreatDetectionWidget25: React.FC<{ seed?: number }> = ({ seed = 25 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="ai-threat-detection-widget-25"><h4>AI Threat Detection Widget 25</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AiThreatDetectionWidget26: React.FC<{ seed?: number }> = ({ seed = 26 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="ai-threat-detection-widget-26"><h4>AI Threat Detection Widget 26</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AiThreatDetectionWidget27: React.FC<{ seed?: number }> = ({ seed = 27 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="ai-threat-detection-widget-27"><h4>AI Threat Detection Widget 27</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};
