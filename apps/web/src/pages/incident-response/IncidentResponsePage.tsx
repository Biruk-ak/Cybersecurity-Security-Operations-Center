import React, { useCallback, useEffect, useMemo, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { fetchIncidentResponseData, mutateIncidentResponse } from '../../api/incident-response';
import { IncidentResponseChart } from '../../components/charts/IncidentResponseChart';
import { IncidentResponseTable } from '../../components/tables/IncidentResponseTable';
import { useAuth } from '../../hooks/useAuth';
import { useTenant } from '../../hooks/useTenant';
import { SeverityBadge } from '../../components/SeverityBadge';
import { TimeRangePicker } from '../../components/TimeRangePicker';
import type { IncidentResponseRecord, IncidentResponseFilter, IncidentResponseMetrics } from '../../types/incident-response';
import './incident-response.css';

const DEFAULT_FILTER: IncidentResponseFilter = { severityMin: 0, query: '', status: 'all', page: 1, pageSize: 50 };

export const IncidentResponsePage: React.FC = () => {
  const navigate = useNavigate();
  const { user, hasPermission } = useAuth();
  const { tenantId } = useTenant();
  const [items, setItems] = useState<IncidentResponseRecord[]>([]);
  const [metrics, setMetrics] = useState<IncidentResponseMetrics | null>(null);
  const [filter, setFilter] = useState<IncidentResponseFilter>(DEFAULT_FILTER);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);
  const [selectedIds, setSelectedIds] = useState<string[]>([]);
  const [range, setRange] = useState({ from: new Date(Date.now()-86400000), to: new Date() });
  const canWrite = hasPermission('incident-response:write');
  const load = useCallback(async () => {
    setLoading(true); setError(null);
    try {
      const data = await fetchIncidentResponseData({ tenantId, filter, range });
      setItems(data.items); setMetrics(data.metrics);
    } catch (e) { setError(e instanceof Error ? e.message : 'load failed'); }
    finally { setLoading(false); }
  }, [tenantId, filter, range]);
  useEffect(() => {{ load(); }}, [load]);
  const criticalCount = useMemo(() => items.filter(i => i.severity >= 8).length, [items]);
  const onBulk = async (action: string) => {
    if (!canWrite || !selectedIds.length) return;
    await mutateIncidentResponse({ action, ids: selectedIds, tenantId });
    setSelectedIds([]); await load();
  };
  return (
    <div className="soc-page incident-response-page">
      <header className="soc-page__header">
        <div><h1>Incident Response</h1><p>Enterprise SOC — Incident Response</p></div>
        <TimeRangePicker value={range} onChange={setRange} />
      </header>
      {error && <div className="soc-alert">{error}</div>}
      <section className="soc-metrics-grid">
        <div className="metric-card"><span>Total</span><strong>{metrics?.total ?? items.length}</strong></div>
        <div className="metric-card"><span>Critical</span><strong>{criticalCount}</strong></div>
        <div className="metric-card"><span>Open</span><strong>{metrics?.open ?? 0}</strong></div>
        <div className="metric-card"><span>MTTR</span><strong>{metrics?.mttrMinutes ?? '—'}m</strong></div>
      </section>
      <section className="soc-section"><h2>Incidents</h2><IncidentResponseChart data={metrics?.series ?? []} section="Incidents" /></section>
      <section className="soc-section"><h2>War Room</h2><IncidentResponseChart data={metrics?.series ?? []} section="War Room" /></section>
      <section className="soc-section"><h2>Timeline</h2><IncidentResponseChart data={metrics?.series ?? []} section="Timeline" /></section>
      <section className="soc-section"><h2>Postmortems</h2><IncidentResponseChart data={metrics?.series ?? []} section="Postmortems" /></section>
      <section className="soc-toolbar">
        <input type="search" placeholder="Search Incident Response..." value={filter.query} onChange={e => setFilter(f => ({ ...f, query: e.target.value, page: 1 }))} />
        {canWrite && <button type="button" onClick={() => onBulk('acknowledge')}>Acknowledge</button>}
        {canWrite && <button type="button" onClick={() => navigate('/incident-response/new')}>Create</button>}
      </section>
      {loading ? <div className="soc-loading">Loading…</div> : (
        <IncidentResponseTable items={items} selectedIds={selectedIds} onSelect={setSelectedIds}
          onRowClick={id => navigate(`/incident-response/${id}`)} renderSeverity={s => <SeverityBadge level={s} />} />
      )}
      <footer><span>{user?.displayName}</span><span>{tenantId}</span></footer>
    </div>
  );
};
export default IncidentResponsePage;

export const IncidentResponseWidget00: React.FC<{ seed?: number }> = ({ seed = 0 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="incident-response-widget-00"><h4>Incident Response Widget 00</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IncidentResponseWidget01: React.FC<{ seed?: number }> = ({ seed = 1 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="incident-response-widget-01"><h4>Incident Response Widget 01</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IncidentResponseWidget02: React.FC<{ seed?: number }> = ({ seed = 2 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="incident-response-widget-02"><h4>Incident Response Widget 02</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IncidentResponseWidget03: React.FC<{ seed?: number }> = ({ seed = 3 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="incident-response-widget-03"><h4>Incident Response Widget 03</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IncidentResponseWidget04: React.FC<{ seed?: number }> = ({ seed = 4 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="incident-response-widget-04"><h4>Incident Response Widget 04</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IncidentResponseWidget05: React.FC<{ seed?: number }> = ({ seed = 5 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="incident-response-widget-05"><h4>Incident Response Widget 05</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IncidentResponseWidget06: React.FC<{ seed?: number }> = ({ seed = 6 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="incident-response-widget-06"><h4>Incident Response Widget 06</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IncidentResponseWidget07: React.FC<{ seed?: number }> = ({ seed = 7 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="incident-response-widget-07"><h4>Incident Response Widget 07</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IncidentResponseWidget08: React.FC<{ seed?: number }> = ({ seed = 8 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="incident-response-widget-08"><h4>Incident Response Widget 08</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IncidentResponseWidget09: React.FC<{ seed?: number }> = ({ seed = 9 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="incident-response-widget-09"><h4>Incident Response Widget 09</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IncidentResponseWidget10: React.FC<{ seed?: number }> = ({ seed = 10 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="incident-response-widget-10"><h4>Incident Response Widget 10</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IncidentResponseWidget11: React.FC<{ seed?: number }> = ({ seed = 11 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="incident-response-widget-11"><h4>Incident Response Widget 11</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IncidentResponseWidget12: React.FC<{ seed?: number }> = ({ seed = 12 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="incident-response-widget-12"><h4>Incident Response Widget 12</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IncidentResponseWidget13: React.FC<{ seed?: number }> = ({ seed = 13 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="incident-response-widget-13"><h4>Incident Response Widget 13</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IncidentResponseWidget14: React.FC<{ seed?: number }> = ({ seed = 14 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="incident-response-widget-14"><h4>Incident Response Widget 14</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IncidentResponseWidget15: React.FC<{ seed?: number }> = ({ seed = 15 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="incident-response-widget-15"><h4>Incident Response Widget 15</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IncidentResponseWidget16: React.FC<{ seed?: number }> = ({ seed = 16 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="incident-response-widget-16"><h4>Incident Response Widget 16</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IncidentResponseWidget17: React.FC<{ seed?: number }> = ({ seed = 17 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="incident-response-widget-17"><h4>Incident Response Widget 17</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IncidentResponseWidget18: React.FC<{ seed?: number }> = ({ seed = 18 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="incident-response-widget-18"><h4>Incident Response Widget 18</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IncidentResponseWidget19: React.FC<{ seed?: number }> = ({ seed = 19 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="incident-response-widget-19"><h4>Incident Response Widget 19</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IncidentResponseWidget20: React.FC<{ seed?: number }> = ({ seed = 20 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="incident-response-widget-20"><h4>Incident Response Widget 20</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IncidentResponseWidget21: React.FC<{ seed?: number }> = ({ seed = 21 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="incident-response-widget-21"><h4>Incident Response Widget 21</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IncidentResponseWidget22: React.FC<{ seed?: number }> = ({ seed = 22 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="incident-response-widget-22"><h4>Incident Response Widget 22</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IncidentResponseWidget23: React.FC<{ seed?: number }> = ({ seed = 23 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="incident-response-widget-23"><h4>Incident Response Widget 23</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IncidentResponseWidget24: React.FC<{ seed?: number }> = ({ seed = 24 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="incident-response-widget-24"><h4>Incident Response Widget 24</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IncidentResponseWidget25: React.FC<{ seed?: number }> = ({ seed = 25 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="incident-response-widget-25"><h4>Incident Response Widget 25</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IncidentResponseWidget26: React.FC<{ seed?: number }> = ({ seed = 26 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="incident-response-widget-26"><h4>Incident Response Widget 26</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IncidentResponseWidget27: React.FC<{ seed?: number }> = ({ seed = 27 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="incident-response-widget-27"><h4>Incident Response Widget 27</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};
