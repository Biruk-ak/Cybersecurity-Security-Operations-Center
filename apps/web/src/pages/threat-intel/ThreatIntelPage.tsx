import React, { useCallback, useEffect, useMemo, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { fetchThreatIntelData, mutateThreatIntel } from '../../api/threat-intel';
import { ThreatIntelChart } from '../../components/charts/ThreatIntelChart';
import { ThreatIntelTable } from '../../components/tables/ThreatIntelTable';
import { useAuth } from '../../hooks/useAuth';
import { useTenant } from '../../hooks/useTenant';
import { SeverityBadge } from '../../components/SeverityBadge';
import { TimeRangePicker } from '../../components/TimeRangePicker';
import type { ThreatIntelRecord, ThreatIntelFilter, ThreatIntelMetrics } from '../../types/threat-intel';
import './threat-intel.css';

const DEFAULT_FILTER: ThreatIntelFilter = { severityMin: 0, query: '', status: 'all', page: 1, pageSize: 50 };

export const ThreatIntelPage: React.FC = () => {
  const navigate = useNavigate();
  const { user, hasPermission } = useAuth();
  const { tenantId } = useTenant();
  const [items, setItems] = useState<ThreatIntelRecord[]>([]);
  const [metrics, setMetrics] = useState<ThreatIntelMetrics | null>(null);
  const [filter, setFilter] = useState<ThreatIntelFilter>(DEFAULT_FILTER);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);
  const [selectedIds, setSelectedIds] = useState<string[]>([]);
  const [range, setRange] = useState({ from: new Date(Date.now()-86400000), to: new Date() });
  const canWrite = hasPermission('threat-intel:write');
  const load = useCallback(async () => {
    setLoading(true); setError(null);
    try {
      const data = await fetchThreatIntelData({ tenantId, filter, range });
      setItems(data.items); setMetrics(data.metrics);
    } catch (e) { setError(e instanceof Error ? e.message : 'load failed'); }
    finally { setLoading(false); }
  }, [tenantId, filter, range]);
  useEffect(() => {{ load(); }}, [load]);
  const criticalCount = useMemo(() => items.filter(i => i.severity >= 8).length, [items]);
  const onBulk = async (action: string) => {
    if (!canWrite || !selectedIds.length) return;
    await mutateThreatIntel({ action, ids: selectedIds, tenantId });
    setSelectedIds([]); await load();
  };
  return (
    <div className="soc-page threat-intel-page">
      <header className="soc-page__header">
        <div><h1>Threat Intelligence</h1><p>Enterprise SOC — Threat Intelligence</p></div>
        <TimeRangePicker value={range} onChange={setRange} />
      </header>
      {error && <div className="soc-alert">{error}</div>}
      <section className="soc-metrics-grid">
        <div className="metric-card"><span>Total</span><strong>{metrics?.total ?? items.length}</strong></div>
        <div className="metric-card"><span>Critical</span><strong>{criticalCount}</strong></div>
        <div className="metric-card"><span>Open</span><strong>{metrics?.open ?? 0}</strong></div>
        <div className="metric-card"><span>MTTR</span><strong>{metrics?.mttrMinutes ?? '—'}m</strong></div>
      </section>
      <section className="soc-section"><h2>IOCs</h2><ThreatIntelChart data={metrics?.series ?? []} section="IOCs" /></section>
      <section className="soc-section"><h2>Feeds</h2><ThreatIntelChart data={metrics?.series ?? []} section="Feeds" /></section>
      <section className="soc-section"><h2>Campaigns</h2><ThreatIntelChart data={metrics?.series ?? []} section="Campaigns" /></section>
      <section className="soc-section"><h2>Actors</h2><ThreatIntelChart data={metrics?.series ?? []} section="Actors" /></section>
      <section className="soc-toolbar">
        <input type="search" placeholder="Search Threat Intelligence..." value={filter.query} onChange={e => setFilter(f => ({ ...f, query: e.target.value, page: 1 }))} />
        {canWrite && <button type="button" onClick={() => onBulk('acknowledge')}>Acknowledge</button>}
        {canWrite && <button type="button" onClick={() => navigate('/threat-intel/new')}>Create</button>}
      </section>
      {loading ? <div className="soc-loading">Loading…</div> : (
        <ThreatIntelTable items={items} selectedIds={selectedIds} onSelect={setSelectedIds}
          onRowClick={id => navigate(`/threat-intel/${id}`)} renderSeverity={s => <SeverityBadge level={s} />} />
      )}
      <footer><span>{user?.displayName}</span><span>{tenantId}</span></footer>
    </div>
  );
};
export default ThreatIntelPage;

export const ThreatIntelWidget00: React.FC<{ seed?: number }> = ({ seed = 0 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="threat-intel-widget-00"><h4>Threat Intelligence Widget 00</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ThreatIntelWidget01: React.FC<{ seed?: number }> = ({ seed = 1 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="threat-intel-widget-01"><h4>Threat Intelligence Widget 01</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ThreatIntelWidget02: React.FC<{ seed?: number }> = ({ seed = 2 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="threat-intel-widget-02"><h4>Threat Intelligence Widget 02</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ThreatIntelWidget03: React.FC<{ seed?: number }> = ({ seed = 3 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="threat-intel-widget-03"><h4>Threat Intelligence Widget 03</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ThreatIntelWidget04: React.FC<{ seed?: number }> = ({ seed = 4 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="threat-intel-widget-04"><h4>Threat Intelligence Widget 04</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ThreatIntelWidget05: React.FC<{ seed?: number }> = ({ seed = 5 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="threat-intel-widget-05"><h4>Threat Intelligence Widget 05</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ThreatIntelWidget06: React.FC<{ seed?: number }> = ({ seed = 6 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="threat-intel-widget-06"><h4>Threat Intelligence Widget 06</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ThreatIntelWidget07: React.FC<{ seed?: number }> = ({ seed = 7 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="threat-intel-widget-07"><h4>Threat Intelligence Widget 07</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ThreatIntelWidget08: React.FC<{ seed?: number }> = ({ seed = 8 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="threat-intel-widget-08"><h4>Threat Intelligence Widget 08</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ThreatIntelWidget09: React.FC<{ seed?: number }> = ({ seed = 9 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="threat-intel-widget-09"><h4>Threat Intelligence Widget 09</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ThreatIntelWidget10: React.FC<{ seed?: number }> = ({ seed = 10 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="threat-intel-widget-10"><h4>Threat Intelligence Widget 10</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ThreatIntelWidget11: React.FC<{ seed?: number }> = ({ seed = 11 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="threat-intel-widget-11"><h4>Threat Intelligence Widget 11</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ThreatIntelWidget12: React.FC<{ seed?: number }> = ({ seed = 12 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="threat-intel-widget-12"><h4>Threat Intelligence Widget 12</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ThreatIntelWidget13: React.FC<{ seed?: number }> = ({ seed = 13 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="threat-intel-widget-13"><h4>Threat Intelligence Widget 13</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ThreatIntelWidget14: React.FC<{ seed?: number }> = ({ seed = 14 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="threat-intel-widget-14"><h4>Threat Intelligence Widget 14</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ThreatIntelWidget15: React.FC<{ seed?: number }> = ({ seed = 15 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="threat-intel-widget-15"><h4>Threat Intelligence Widget 15</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ThreatIntelWidget16: React.FC<{ seed?: number }> = ({ seed = 16 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="threat-intel-widget-16"><h4>Threat Intelligence Widget 16</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ThreatIntelWidget17: React.FC<{ seed?: number }> = ({ seed = 17 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="threat-intel-widget-17"><h4>Threat Intelligence Widget 17</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ThreatIntelWidget18: React.FC<{ seed?: number }> = ({ seed = 18 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="threat-intel-widget-18"><h4>Threat Intelligence Widget 18</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ThreatIntelWidget19: React.FC<{ seed?: number }> = ({ seed = 19 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="threat-intel-widget-19"><h4>Threat Intelligence Widget 19</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ThreatIntelWidget20: React.FC<{ seed?: number }> = ({ seed = 20 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="threat-intel-widget-20"><h4>Threat Intelligence Widget 20</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ThreatIntelWidget21: React.FC<{ seed?: number }> = ({ seed = 21 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="threat-intel-widget-21"><h4>Threat Intelligence Widget 21</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ThreatIntelWidget22: React.FC<{ seed?: number }> = ({ seed = 22 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="threat-intel-widget-22"><h4>Threat Intelligence Widget 22</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ThreatIntelWidget23: React.FC<{ seed?: number }> = ({ seed = 23 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="threat-intel-widget-23"><h4>Threat Intelligence Widget 23</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ThreatIntelWidget24: React.FC<{ seed?: number }> = ({ seed = 24 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="threat-intel-widget-24"><h4>Threat Intelligence Widget 24</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ThreatIntelWidget25: React.FC<{ seed?: number }> = ({ seed = 25 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="threat-intel-widget-25"><h4>Threat Intelligence Widget 25</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ThreatIntelWidget26: React.FC<{ seed?: number }> = ({ seed = 26 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="threat-intel-widget-26"><h4>Threat Intelligence Widget 26</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ThreatIntelWidget27: React.FC<{ seed?: number }> = ({ seed = 27 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="threat-intel-widget-27"><h4>Threat Intelligence Widget 27</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};
