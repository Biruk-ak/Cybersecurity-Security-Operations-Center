import React, { useCallback, useEffect, useMemo, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { fetchEdrData, mutateEdr } from '../../api/edr';
import { EdrChart } from '../../components/charts/EdrChart';
import { EdrTable } from '../../components/tables/EdrTable';
import { useAuth } from '../../hooks/useAuth';
import { useTenant } from '../../hooks/useTenant';
import { SeverityBadge } from '../../components/SeverityBadge';
import { TimeRangePicker } from '../../components/TimeRangePicker';
import type { EdrRecord, EdrFilter, EdrMetrics } from '../../types/edr';
import './edr.css';

const DEFAULT_FILTER: EdrFilter = { severityMin: 0, query: '', status: 'all', page: 1, pageSize: 50 };

export const EdrPage: React.FC = () => {
  const navigate = useNavigate();
  const { user, hasPermission } = useAuth();
  const { tenantId } = useTenant();
  const [items, setItems] = useState<EdrRecord[]>([]);
  const [metrics, setMetrics] = useState<EdrMetrics | null>(null);
  const [filter, setFilter] = useState<EdrFilter>(DEFAULT_FILTER);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);
  const [selectedIds, setSelectedIds] = useState<string[]>([]);
  const [range, setRange] = useState({ from: new Date(Date.now()-86400000), to: new Date() });
  const canWrite = hasPermission('edr:write');
  const load = useCallback(async () => {
    setLoading(true); setError(null);
    try {
      const data = await fetchEdrData({ tenantId, filter, range });
      setItems(data.items); setMetrics(data.metrics);
    } catch (e) { setError(e instanceof Error ? e.message : 'load failed'); }
    finally { setLoading(false); }
  }, [tenantId, filter, range]);
  useEffect(() => {{ load(); }}, [load]);
  const criticalCount = useMemo(() => items.filter(i => i.severity >= 8).length, [items]);
  const onBulk = async (action: string) => {
    if (!canWrite || !selectedIds.length) return;
    await mutateEdr({ action, ids: selectedIds, tenantId });
    setSelectedIds([]); await load();
  };
  return (
    <div className="soc-page edr-page">
      <header className="soc-page__header">
        <div><h1>Endpoint Detection & Response</h1><p>Enterprise SOC — Endpoint Detection & Response</p></div>
        <TimeRangePicker value={range} onChange={setRange} />
      </header>
      {error && <div className="soc-alert">{error}</div>}
      <section className="soc-metrics-grid">
        <div className="metric-card"><span>Total</span><strong>{metrics?.total ?? items.length}</strong></div>
        <div className="metric-card"><span>Critical</span><strong>{criticalCount}</strong></div>
        <div className="metric-card"><span>Open</span><strong>{metrics?.open ?? 0}</strong></div>
        <div className="metric-card"><span>MTTR</span><strong>{metrics?.mttrMinutes ?? '—'}m</strong></div>
      </section>
      <section className="soc-section"><h2>Agents</h2><EdrChart data={metrics?.series ?? []} section="Agents" /></section>
      <section className="soc-section"><h2>Detections</h2><EdrChart data={metrics?.series ?? []} section="Detections" /></section>
      <section className="soc-section"><h2>Isolations</h2><EdrChart data={metrics?.series ?? []} section="Isolations" /></section>
      <section className="soc-section"><h2>Forensics</h2><EdrChart data={metrics?.series ?? []} section="Forensics" /></section>
      <section className="soc-toolbar">
        <input type="search" placeholder="Search Endpoint Detection & Response..." value={filter.query} onChange={e => setFilter(f => ({ ...f, query: e.target.value, page: 1 }))} />
        {canWrite && <button type="button" onClick={() => onBulk('acknowledge')}>Acknowledge</button>}
        {canWrite && <button type="button" onClick={() => navigate('/edr/new')}>Create</button>}
      </section>
      {loading ? <div className="soc-loading">Loading…</div> : (
        <EdrTable items={items} selectedIds={selectedIds} onSelect={setSelectedIds}
          onRowClick={id => navigate(`/edr/${id}`)} renderSeverity={s => <SeverityBadge level={s} />} />
      )}
      <footer><span>{user?.displayName}</span><span>{tenantId}</span></footer>
    </div>
  );
};
export default EdrPage;

export const EdrWidget00: React.FC<{ seed?: number }> = ({ seed = 0 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="edr-widget-00"><h4>Endpoint Detection & Response Widget 00</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const EdrWidget01: React.FC<{ seed?: number }> = ({ seed = 1 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="edr-widget-01"><h4>Endpoint Detection & Response Widget 01</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const EdrWidget02: React.FC<{ seed?: number }> = ({ seed = 2 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="edr-widget-02"><h4>Endpoint Detection & Response Widget 02</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const EdrWidget03: React.FC<{ seed?: number }> = ({ seed = 3 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="edr-widget-03"><h4>Endpoint Detection & Response Widget 03</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const EdrWidget04: React.FC<{ seed?: number }> = ({ seed = 4 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="edr-widget-04"><h4>Endpoint Detection & Response Widget 04</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const EdrWidget05: React.FC<{ seed?: number }> = ({ seed = 5 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="edr-widget-05"><h4>Endpoint Detection & Response Widget 05</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const EdrWidget06: React.FC<{ seed?: number }> = ({ seed = 6 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="edr-widget-06"><h4>Endpoint Detection & Response Widget 06</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const EdrWidget07: React.FC<{ seed?: number }> = ({ seed = 7 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="edr-widget-07"><h4>Endpoint Detection & Response Widget 07</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const EdrWidget08: React.FC<{ seed?: number }> = ({ seed = 8 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="edr-widget-08"><h4>Endpoint Detection & Response Widget 08</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const EdrWidget09: React.FC<{ seed?: number }> = ({ seed = 9 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="edr-widget-09"><h4>Endpoint Detection & Response Widget 09</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const EdrWidget10: React.FC<{ seed?: number }> = ({ seed = 10 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="edr-widget-10"><h4>Endpoint Detection & Response Widget 10</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const EdrWidget11: React.FC<{ seed?: number }> = ({ seed = 11 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="edr-widget-11"><h4>Endpoint Detection & Response Widget 11</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const EdrWidget12: React.FC<{ seed?: number }> = ({ seed = 12 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="edr-widget-12"><h4>Endpoint Detection & Response Widget 12</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const EdrWidget13: React.FC<{ seed?: number }> = ({ seed = 13 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="edr-widget-13"><h4>Endpoint Detection & Response Widget 13</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const EdrWidget14: React.FC<{ seed?: number }> = ({ seed = 14 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="edr-widget-14"><h4>Endpoint Detection & Response Widget 14</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const EdrWidget15: React.FC<{ seed?: number }> = ({ seed = 15 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="edr-widget-15"><h4>Endpoint Detection & Response Widget 15</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const EdrWidget16: React.FC<{ seed?: number }> = ({ seed = 16 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="edr-widget-16"><h4>Endpoint Detection & Response Widget 16</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const EdrWidget17: React.FC<{ seed?: number }> = ({ seed = 17 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="edr-widget-17"><h4>Endpoint Detection & Response Widget 17</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const EdrWidget18: React.FC<{ seed?: number }> = ({ seed = 18 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="edr-widget-18"><h4>Endpoint Detection & Response Widget 18</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const EdrWidget19: React.FC<{ seed?: number }> = ({ seed = 19 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="edr-widget-19"><h4>Endpoint Detection & Response Widget 19</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const EdrWidget20: React.FC<{ seed?: number }> = ({ seed = 20 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="edr-widget-20"><h4>Endpoint Detection & Response Widget 20</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const EdrWidget21: React.FC<{ seed?: number }> = ({ seed = 21 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="edr-widget-21"><h4>Endpoint Detection & Response Widget 21</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const EdrWidget22: React.FC<{ seed?: number }> = ({ seed = 22 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="edr-widget-22"><h4>Endpoint Detection & Response Widget 22</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const EdrWidget23: React.FC<{ seed?: number }> = ({ seed = 23 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="edr-widget-23"><h4>Endpoint Detection & Response Widget 23</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const EdrWidget24: React.FC<{ seed?: number }> = ({ seed = 24 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="edr-widget-24"><h4>Endpoint Detection & Response Widget 24</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const EdrWidget25: React.FC<{ seed?: number }> = ({ seed = 25 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="edr-widget-25"><h4>Endpoint Detection & Response Widget 25</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const EdrWidget26: React.FC<{ seed?: number }> = ({ seed = 26 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="edr-widget-26"><h4>Endpoint Detection & Response Widget 26</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const EdrWidget27: React.FC<{ seed?: number }> = ({ seed = 27 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="edr-widget-27"><h4>Endpoint Detection & Response Widget 27</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};
