import React, { useCallback, useEffect, useMemo, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { fetchSecurityAnalyticsData, mutateSecurityAnalytics } from '../../api/security-analytics';
import { SecurityAnalyticsChart } from '../../components/charts/SecurityAnalyticsChart';
import { SecurityAnalyticsTable } from '../../components/tables/SecurityAnalyticsTable';
import { useAuth } from '../../hooks/useAuth';
import { useTenant } from '../../hooks/useTenant';
import { SeverityBadge } from '../../components/SeverityBadge';
import { TimeRangePicker } from '../../components/TimeRangePicker';
import type { SecurityAnalyticsRecord, SecurityAnalyticsFilter, SecurityAnalyticsMetrics } from '../../types/security-analytics';
import './security-analytics.css';

const DEFAULT_FILTER: SecurityAnalyticsFilter = { severityMin: 0, query: '', status: 'all', page: 1, pageSize: 50 };

export const SecurityAnalyticsPage: React.FC = () => {
  const navigate = useNavigate();
  const { user, hasPermission } = useAuth();
  const { tenantId } = useTenant();
  const [items, setItems] = useState<SecurityAnalyticsRecord[]>([]);
  const [metrics, setMetrics] = useState<SecurityAnalyticsMetrics | null>(null);
  const [filter, setFilter] = useState<SecurityAnalyticsFilter>(DEFAULT_FILTER);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);
  const [selectedIds, setSelectedIds] = useState<string[]>([]);
  const [range, setRange] = useState({ from: new Date(Date.now()-86400000), to: new Date() });
  const canWrite = hasPermission('security-analytics:write');
  const load = useCallback(async () => {
    setLoading(true); setError(null);
    try {
      const data = await fetchSecurityAnalyticsData({ tenantId, filter, range });
      setItems(data.items); setMetrics(data.metrics);
    } catch (e) { setError(e instanceof Error ? e.message : 'load failed'); }
    finally { setLoading(false); }
  }, [tenantId, filter, range]);
  useEffect(() => {{ load(); }}, [load]);
  const criticalCount = useMemo(() => items.filter(i => i.severity >= 8).length, [items]);
  const onBulk = async (action: string) => {
    if (!canWrite || !selectedIds.length) return;
    await mutateSecurityAnalytics({ action, ids: selectedIds, tenantId });
    setSelectedIds([]); await load();
  };
  return (
    <div className="soc-page security-analytics-page">
      <header className="soc-page__header">
        <div><h1>Security Analytics</h1><p>Enterprise SOC — Security Analytics</p></div>
        <TimeRangePicker value={range} onChange={setRange} />
      </header>
      {error && <div className="soc-alert">{error}</div>}
      <section className="soc-metrics-grid">
        <div className="metric-card"><span>Total</span><strong>{metrics?.total ?? items.length}</strong></div>
        <div className="metric-card"><span>Critical</span><strong>{criticalCount}</strong></div>
        <div className="metric-card"><span>Open</span><strong>{metrics?.open ?? 0}</strong></div>
        <div className="metric-card"><span>MTTR</span><strong>{metrics?.mttrMinutes ?? '—'}m</strong></div>
      </section>
      <section className="soc-section"><h2>Queries</h2><SecurityAnalyticsChart data={metrics?.series ?? []} section="Queries" /></section>
      <section className="soc-section"><h2>Dashboards</h2><SecurityAnalyticsChart data={metrics?.series ?? []} section="Dashboards" /></section>
      <section className="soc-section"><h2>Baselines</h2><SecurityAnalyticsChart data={metrics?.series ?? []} section="Baselines" /></section>
      <section className="soc-section"><h2>Trends</h2><SecurityAnalyticsChart data={metrics?.series ?? []} section="Trends" /></section>
      <section className="soc-toolbar">
        <input type="search" placeholder="Search Security Analytics..." value={filter.query} onChange={e => setFilter(f => ({ ...f, query: e.target.value, page: 1 }))} />
        {canWrite && <button type="button" onClick={() => onBulk('acknowledge')}>Acknowledge</button>}
        {canWrite && <button type="button" onClick={() => navigate('/security-analytics/new')}>Create</button>}
      </section>
      {loading ? <div className="soc-loading">Loading…</div> : (
        <SecurityAnalyticsTable items={items} selectedIds={selectedIds} onSelect={setSelectedIds}
          onRowClick={id => navigate(`/security-analytics/${id}`)} renderSeverity={s => <SeverityBadge level={s} />} />
      )}
      <footer><span>{user?.displayName}</span><span>{tenantId}</span></footer>
    </div>
  );
};
export default SecurityAnalyticsPage;

export const SecurityAnalyticsWidget00: React.FC<{ seed?: number }> = ({ seed = 0 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-analytics-widget-00"><h4>Security Analytics Widget 00</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityAnalyticsWidget01: React.FC<{ seed?: number }> = ({ seed = 1 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-analytics-widget-01"><h4>Security Analytics Widget 01</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityAnalyticsWidget02: React.FC<{ seed?: number }> = ({ seed = 2 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-analytics-widget-02"><h4>Security Analytics Widget 02</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityAnalyticsWidget03: React.FC<{ seed?: number }> = ({ seed = 3 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-analytics-widget-03"><h4>Security Analytics Widget 03</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityAnalyticsWidget04: React.FC<{ seed?: number }> = ({ seed = 4 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-analytics-widget-04"><h4>Security Analytics Widget 04</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityAnalyticsWidget05: React.FC<{ seed?: number }> = ({ seed = 5 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-analytics-widget-05"><h4>Security Analytics Widget 05</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityAnalyticsWidget06: React.FC<{ seed?: number }> = ({ seed = 6 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-analytics-widget-06"><h4>Security Analytics Widget 06</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityAnalyticsWidget07: React.FC<{ seed?: number }> = ({ seed = 7 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-analytics-widget-07"><h4>Security Analytics Widget 07</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityAnalyticsWidget08: React.FC<{ seed?: number }> = ({ seed = 8 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-analytics-widget-08"><h4>Security Analytics Widget 08</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityAnalyticsWidget09: React.FC<{ seed?: number }> = ({ seed = 9 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-analytics-widget-09"><h4>Security Analytics Widget 09</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityAnalyticsWidget10: React.FC<{ seed?: number }> = ({ seed = 10 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-analytics-widget-10"><h4>Security Analytics Widget 10</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityAnalyticsWidget11: React.FC<{ seed?: number }> = ({ seed = 11 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-analytics-widget-11"><h4>Security Analytics Widget 11</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityAnalyticsWidget12: React.FC<{ seed?: number }> = ({ seed = 12 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-analytics-widget-12"><h4>Security Analytics Widget 12</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityAnalyticsWidget13: React.FC<{ seed?: number }> = ({ seed = 13 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-analytics-widget-13"><h4>Security Analytics Widget 13</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityAnalyticsWidget14: React.FC<{ seed?: number }> = ({ seed = 14 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-analytics-widget-14"><h4>Security Analytics Widget 14</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityAnalyticsWidget15: React.FC<{ seed?: number }> = ({ seed = 15 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-analytics-widget-15"><h4>Security Analytics Widget 15</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityAnalyticsWidget16: React.FC<{ seed?: number }> = ({ seed = 16 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-analytics-widget-16"><h4>Security Analytics Widget 16</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityAnalyticsWidget17: React.FC<{ seed?: number }> = ({ seed = 17 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-analytics-widget-17"><h4>Security Analytics Widget 17</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityAnalyticsWidget18: React.FC<{ seed?: number }> = ({ seed = 18 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-analytics-widget-18"><h4>Security Analytics Widget 18</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityAnalyticsWidget19: React.FC<{ seed?: number }> = ({ seed = 19 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-analytics-widget-19"><h4>Security Analytics Widget 19</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityAnalyticsWidget20: React.FC<{ seed?: number }> = ({ seed = 20 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-analytics-widget-20"><h4>Security Analytics Widget 20</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityAnalyticsWidget21: React.FC<{ seed?: number }> = ({ seed = 21 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-analytics-widget-21"><h4>Security Analytics Widget 21</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityAnalyticsWidget22: React.FC<{ seed?: number }> = ({ seed = 22 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-analytics-widget-22"><h4>Security Analytics Widget 22</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityAnalyticsWidget23: React.FC<{ seed?: number }> = ({ seed = 23 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-analytics-widget-23"><h4>Security Analytics Widget 23</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityAnalyticsWidget24: React.FC<{ seed?: number }> = ({ seed = 24 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-analytics-widget-24"><h4>Security Analytics Widget 24</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityAnalyticsWidget25: React.FC<{ seed?: number }> = ({ seed = 25 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-analytics-widget-25"><h4>Security Analytics Widget 25</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityAnalyticsWidget26: React.FC<{ seed?: number }> = ({ seed = 26 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-analytics-widget-26"><h4>Security Analytics Widget 26</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityAnalyticsWidget27: React.FC<{ seed?: number }> = ({ seed = 27 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-analytics-widget-27"><h4>Security Analytics Widget 27</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};
