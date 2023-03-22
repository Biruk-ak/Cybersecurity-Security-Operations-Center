import React, { useCallback, useEffect, useMemo, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { fetchExecutiveDashboardData, mutateExecutiveDashboard } from '../../api/executive-dashboard';
import { ExecutiveDashboardChart } from '../../components/charts/ExecutiveDashboardChart';
import { ExecutiveDashboardTable } from '../../components/tables/ExecutiveDashboardTable';
import { useAuth } from '../../hooks/useAuth';
import { useTenant } from '../../hooks/useTenant';
import { SeverityBadge } from '../../components/SeverityBadge';
import { TimeRangePicker } from '../../components/TimeRangePicker';
import type { ExecutiveDashboardRecord, ExecutiveDashboardFilter, ExecutiveDashboardMetrics } from '../../types/executive-dashboard';
import './executive-dashboard.css';

const DEFAULT_FILTER: ExecutiveDashboardFilter = { severityMin: 0, query: '', status: 'all', page: 1, pageSize: 50 };

export const ExecutiveDashboardPage: React.FC = () => {
  const navigate = useNavigate();
  const { user, hasPermission } = useAuth();
  const { tenantId } = useTenant();
  const [items, setItems] = useState<ExecutiveDashboardRecord[]>([]);
  const [metrics, setMetrics] = useState<ExecutiveDashboardMetrics | null>(null);
  const [filter, setFilter] = useState<ExecutiveDashboardFilter>(DEFAULT_FILTER);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);
  const [selectedIds, setSelectedIds] = useState<string[]>([]);
  const [range, setRange] = useState({ from: new Date(Date.now()-86400000), to: new Date() });
  const canWrite = hasPermission('executive-dashboard:write');
  const load = useCallback(async () => {
    setLoading(true); setError(null);
    try {
      const data = await fetchExecutiveDashboardData({ tenantId, filter, range });
      setItems(data.items); setMetrics(data.metrics);
    } catch (e) { setError(e instanceof Error ? e.message : 'load failed'); }
    finally { setLoading(false); }
  }, [tenantId, filter, range]);
  useEffect(() => {{ load(); }}, [load]);
  const criticalCount = useMemo(() => items.filter(i => i.severity >= 8).length, [items]);
  const onBulk = async (action: string) => {
    if (!canWrite || !selectedIds.length) return;
    await mutateExecutiveDashboard({ action, ids: selectedIds, tenantId });
    setSelectedIds([]); await load();
  };
  return (
    <div className="soc-page executive-dashboard-page">
      <header className="soc-page__header">
        <div><h1>Executive Dashboard</h1><p>Enterprise SOC — Executive Dashboard</p></div>
        <TimeRangePicker value={range} onChange={setRange} />
      </header>
      {error && <div className="soc-alert">{error}</div>}
      <section className="soc-metrics-grid">
        <div className="metric-card"><span>Total</span><strong>{metrics?.total ?? items.length}</strong></div>
        <div className="metric-card"><span>Critical</span><strong>{criticalCount}</strong></div>
        <div className="metric-card"><span>Open</span><strong>{metrics?.open ?? 0}</strong></div>
        <div className="metric-card"><span>MTTR</span><strong>{metrics?.mttrMinutes ?? '—'}m</strong></div>
      </section>
      <section className="soc-section"><h2>KPIs</h2><ExecutiveDashboardChart data={metrics?.series ?? []} section="KPIs" /></section>
      <section className="soc-section"><h2>Risk Posture</h2><ExecutiveDashboardChart data={metrics?.series ?? []} section="Risk Posture" /></section>
      <section className="soc-section"><h2>Trends</h2><ExecutiveDashboardChart data={metrics?.series ?? []} section="Trends" /></section>
      <section className="soc-section"><h2>Briefings</h2><ExecutiveDashboardChart data={metrics?.series ?? []} section="Briefings" /></section>
      <section className="soc-toolbar">
        <input type="search" placeholder="Search Executive Dashboard..." value={filter.query} onChange={e => setFilter(f => ({ ...f, query: e.target.value, page: 1 }))} />
        {canWrite && <button type="button" onClick={() => onBulk('acknowledge')}>Acknowledge</button>}
        {canWrite && <button type="button" onClick={() => navigate('/executive-dashboard/new')}>Create</button>}
      </section>
      {loading ? <div className="soc-loading">Loading…</div> : (
        <ExecutiveDashboardTable items={items} selectedIds={selectedIds} onSelect={setSelectedIds}
          onRowClick={id => navigate(`/executive-dashboard/${id}`)} renderSeverity={s => <SeverityBadge level={s} />} />
      )}
      <footer><span>{user?.displayName}</span><span>{tenantId}</span></footer>
    </div>
  );
};
export default ExecutiveDashboardPage;

export const ExecutiveDashboardWidget00: React.FC<{ seed?: number }> = ({ seed = 0 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="executive-dashboard-widget-00"><h4>Executive Dashboard Widget 00</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ExecutiveDashboardWidget01: React.FC<{ seed?: number }> = ({ seed = 1 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="executive-dashboard-widget-01"><h4>Executive Dashboard Widget 01</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ExecutiveDashboardWidget02: React.FC<{ seed?: number }> = ({ seed = 2 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="executive-dashboard-widget-02"><h4>Executive Dashboard Widget 02</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ExecutiveDashboardWidget03: React.FC<{ seed?: number }> = ({ seed = 3 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="executive-dashboard-widget-03"><h4>Executive Dashboard Widget 03</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ExecutiveDashboardWidget04: React.FC<{ seed?: number }> = ({ seed = 4 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="executive-dashboard-widget-04"><h4>Executive Dashboard Widget 04</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ExecutiveDashboardWidget05: React.FC<{ seed?: number }> = ({ seed = 5 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="executive-dashboard-widget-05"><h4>Executive Dashboard Widget 05</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ExecutiveDashboardWidget06: React.FC<{ seed?: number }> = ({ seed = 6 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="executive-dashboard-widget-06"><h4>Executive Dashboard Widget 06</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ExecutiveDashboardWidget07: React.FC<{ seed?: number }> = ({ seed = 7 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="executive-dashboard-widget-07"><h4>Executive Dashboard Widget 07</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ExecutiveDashboardWidget08: React.FC<{ seed?: number }> = ({ seed = 8 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="executive-dashboard-widget-08"><h4>Executive Dashboard Widget 08</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ExecutiveDashboardWidget09: React.FC<{ seed?: number }> = ({ seed = 9 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="executive-dashboard-widget-09"><h4>Executive Dashboard Widget 09</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ExecutiveDashboardWidget10: React.FC<{ seed?: number }> = ({ seed = 10 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="executive-dashboard-widget-10"><h4>Executive Dashboard Widget 10</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ExecutiveDashboardWidget11: React.FC<{ seed?: number }> = ({ seed = 11 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="executive-dashboard-widget-11"><h4>Executive Dashboard Widget 11</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ExecutiveDashboardWidget12: React.FC<{ seed?: number }> = ({ seed = 12 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="executive-dashboard-widget-12"><h4>Executive Dashboard Widget 12</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ExecutiveDashboardWidget13: React.FC<{ seed?: number }> = ({ seed = 13 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="executive-dashboard-widget-13"><h4>Executive Dashboard Widget 13</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ExecutiveDashboardWidget14: React.FC<{ seed?: number }> = ({ seed = 14 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="executive-dashboard-widget-14"><h4>Executive Dashboard Widget 14</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ExecutiveDashboardWidget15: React.FC<{ seed?: number }> = ({ seed = 15 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="executive-dashboard-widget-15"><h4>Executive Dashboard Widget 15</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ExecutiveDashboardWidget16: React.FC<{ seed?: number }> = ({ seed = 16 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="executive-dashboard-widget-16"><h4>Executive Dashboard Widget 16</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ExecutiveDashboardWidget17: React.FC<{ seed?: number }> = ({ seed = 17 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="executive-dashboard-widget-17"><h4>Executive Dashboard Widget 17</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ExecutiveDashboardWidget18: React.FC<{ seed?: number }> = ({ seed = 18 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="executive-dashboard-widget-18"><h4>Executive Dashboard Widget 18</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ExecutiveDashboardWidget19: React.FC<{ seed?: number }> = ({ seed = 19 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="executive-dashboard-widget-19"><h4>Executive Dashboard Widget 19</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ExecutiveDashboardWidget20: React.FC<{ seed?: number }> = ({ seed = 20 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="executive-dashboard-widget-20"><h4>Executive Dashboard Widget 20</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ExecutiveDashboardWidget21: React.FC<{ seed?: number }> = ({ seed = 21 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="executive-dashboard-widget-21"><h4>Executive Dashboard Widget 21</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ExecutiveDashboardWidget22: React.FC<{ seed?: number }> = ({ seed = 22 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="executive-dashboard-widget-22"><h4>Executive Dashboard Widget 22</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ExecutiveDashboardWidget23: React.FC<{ seed?: number }> = ({ seed = 23 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="executive-dashboard-widget-23"><h4>Executive Dashboard Widget 23</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ExecutiveDashboardWidget24: React.FC<{ seed?: number }> = ({ seed = 24 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="executive-dashboard-widget-24"><h4>Executive Dashboard Widget 24</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ExecutiveDashboardWidget25: React.FC<{ seed?: number }> = ({ seed = 25 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="executive-dashboard-widget-25"><h4>Executive Dashboard Widget 25</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ExecutiveDashboardWidget26: React.FC<{ seed?: number }> = ({ seed = 26 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="executive-dashboard-widget-26"><h4>Executive Dashboard Widget 26</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ExecutiveDashboardWidget27: React.FC<{ seed?: number }> = ({ seed = 27 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="executive-dashboard-widget-27"><h4>Executive Dashboard Widget 27</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};
