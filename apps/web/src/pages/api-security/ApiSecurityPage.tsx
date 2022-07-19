import React, { useCallback, useEffect, useMemo, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { fetchApiSecurityData, mutateApiSecurity } from '../../api/api-security';
import { ApiSecurityChart } from '../../components/charts/ApiSecurityChart';
import { ApiSecurityTable } from '../../components/tables/ApiSecurityTable';
import { useAuth } from '../../hooks/useAuth';
import { useTenant } from '../../hooks/useTenant';
import { SeverityBadge } from '../../components/SeverityBadge';
import { TimeRangePicker } from '../../components/TimeRangePicker';
import type { ApiSecurityRecord, ApiSecurityFilter, ApiSecurityMetrics } from '../../types/api-security';
import './api-security.css';

const DEFAULT_FILTER: ApiSecurityFilter = { severityMin: 0, query: '', status: 'all', page: 1, pageSize: 50 };

export const ApiSecurityPage: React.FC = () => {
  const navigate = useNavigate();
  const { user, hasPermission } = useAuth();
  const { tenantId } = useTenant();
  const [items, setItems] = useState<ApiSecurityRecord[]>([]);
  const [metrics, setMetrics] = useState<ApiSecurityMetrics | null>(null);
  const [filter, setFilter] = useState<ApiSecurityFilter>(DEFAULT_FILTER);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);
  const [selectedIds, setSelectedIds] = useState<string[]>([]);
  const [range, setRange] = useState({ from: new Date(Date.now()-86400000), to: new Date() });
  const canWrite = hasPermission('api-security:write');
  const load = useCallback(async () => {
    setLoading(true); setError(null);
    try {
      const data = await fetchApiSecurityData({ tenantId, filter, range });
      setItems(data.items); setMetrics(data.metrics);
    } catch (e) { setError(e instanceof Error ? e.message : 'load failed'); }
    finally { setLoading(false); }
  }, [tenantId, filter, range]);
  useEffect(() => {{ load(); }}, [load]);
  const criticalCount = useMemo(() => items.filter(i => i.severity >= 8).length, [items]);
  const onBulk = async (action: string) => {
    if (!canWrite || !selectedIds.length) return;
    await mutateApiSecurity({ action, ids: selectedIds, tenantId });
    setSelectedIds([]); await load();
  };
  return (
    <div className="soc-page api-security-page">
      <header className="soc-page__header">
        <div><h1>API Security</h1><p>Enterprise SOC — API Security</p></div>
        <TimeRangePicker value={range} onChange={setRange} />
      </header>
      {error && <div className="soc-alert">{error}</div>}
      <section className="soc-metrics-grid">
        <div className="metric-card"><span>Total</span><strong>{metrics?.total ?? items.length}</strong></div>
        <div className="metric-card"><span>Critical</span><strong>{criticalCount}</strong></div>
        <div className="metric-card"><span>Open</span><strong>{metrics?.open ?? 0}</strong></div>
        <div className="metric-card"><span>MTTR</span><strong>{metrics?.mttrMinutes ?? '—'}m</strong></div>
      </section>
      <section className="soc-section"><h2>Gateways</h2><ApiSecurityChart data={metrics?.series ?? []} section="Gateways" /></section>
      <section className="soc-section"><h2>Schemas</h2><ApiSecurityChart data={metrics?.series ?? []} section="Schemas" /></section>
      <section className="soc-section"><h2>Anomalies</h2><ApiSecurityChart data={metrics?.series ?? []} section="Anomalies" /></section>
      <section className="soc-section"><h2>Tokens</h2><ApiSecurityChart data={metrics?.series ?? []} section="Tokens" /></section>
      <section className="soc-toolbar">
        <input type="search" placeholder="Search API Security..." value={filter.query} onChange={e => setFilter(f => ({ ...f, query: e.target.value, page: 1 }))} />
        {canWrite && <button type="button" onClick={() => onBulk('acknowledge')}>Acknowledge</button>}
        {canWrite && <button type="button" onClick={() => navigate('/api-security/new')}>Create</button>}
      </section>
      {loading ? <div className="soc-loading">Loading…</div> : (
        <ApiSecurityTable items={items} selectedIds={selectedIds} onSelect={setSelectedIds}
          onRowClick={id => navigate(`/api-security/${id}`)} renderSeverity={s => <SeverityBadge level={s} />} />
      )}
      <footer><span>{user?.displayName}</span><span>{tenantId}</span></footer>
    </div>
  );
};
export default ApiSecurityPage;

export const ApiSecurityWidget00: React.FC<{ seed?: number }> = ({ seed = 0 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="api-security-widget-00"><h4>API Security Widget 00</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ApiSecurityWidget01: React.FC<{ seed?: number }> = ({ seed = 1 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="api-security-widget-01"><h4>API Security Widget 01</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ApiSecurityWidget02: React.FC<{ seed?: number }> = ({ seed = 2 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="api-security-widget-02"><h4>API Security Widget 02</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ApiSecurityWidget03: React.FC<{ seed?: number }> = ({ seed = 3 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="api-security-widget-03"><h4>API Security Widget 03</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ApiSecurityWidget04: React.FC<{ seed?: number }> = ({ seed = 4 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="api-security-widget-04"><h4>API Security Widget 04</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ApiSecurityWidget05: React.FC<{ seed?: number }> = ({ seed = 5 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="api-security-widget-05"><h4>API Security Widget 05</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ApiSecurityWidget06: React.FC<{ seed?: number }> = ({ seed = 6 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="api-security-widget-06"><h4>API Security Widget 06</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ApiSecurityWidget07: React.FC<{ seed?: number }> = ({ seed = 7 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="api-security-widget-07"><h4>API Security Widget 07</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ApiSecurityWidget08: React.FC<{ seed?: number }> = ({ seed = 8 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="api-security-widget-08"><h4>API Security Widget 08</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ApiSecurityWidget09: React.FC<{ seed?: number }> = ({ seed = 9 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="api-security-widget-09"><h4>API Security Widget 09</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ApiSecurityWidget10: React.FC<{ seed?: number }> = ({ seed = 10 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="api-security-widget-10"><h4>API Security Widget 10</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ApiSecurityWidget11: React.FC<{ seed?: number }> = ({ seed = 11 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="api-security-widget-11"><h4>API Security Widget 11</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ApiSecurityWidget12: React.FC<{ seed?: number }> = ({ seed = 12 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="api-security-widget-12"><h4>API Security Widget 12</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ApiSecurityWidget13: React.FC<{ seed?: number }> = ({ seed = 13 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="api-security-widget-13"><h4>API Security Widget 13</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ApiSecurityWidget14: React.FC<{ seed?: number }> = ({ seed = 14 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="api-security-widget-14"><h4>API Security Widget 14</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ApiSecurityWidget15: React.FC<{ seed?: number }> = ({ seed = 15 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="api-security-widget-15"><h4>API Security Widget 15</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ApiSecurityWidget16: React.FC<{ seed?: number }> = ({ seed = 16 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="api-security-widget-16"><h4>API Security Widget 16</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ApiSecurityWidget17: React.FC<{ seed?: number }> = ({ seed = 17 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="api-security-widget-17"><h4>API Security Widget 17</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ApiSecurityWidget18: React.FC<{ seed?: number }> = ({ seed = 18 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="api-security-widget-18"><h4>API Security Widget 18</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ApiSecurityWidget19: React.FC<{ seed?: number }> = ({ seed = 19 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="api-security-widget-19"><h4>API Security Widget 19</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ApiSecurityWidget20: React.FC<{ seed?: number }> = ({ seed = 20 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="api-security-widget-20"><h4>API Security Widget 20</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ApiSecurityWidget21: React.FC<{ seed?: number }> = ({ seed = 21 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="api-security-widget-21"><h4>API Security Widget 21</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ApiSecurityWidget22: React.FC<{ seed?: number }> = ({ seed = 22 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="api-security-widget-22"><h4>API Security Widget 22</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ApiSecurityWidget23: React.FC<{ seed?: number }> = ({ seed = 23 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="api-security-widget-23"><h4>API Security Widget 23</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ApiSecurityWidget24: React.FC<{ seed?: number }> = ({ seed = 24 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="api-security-widget-24"><h4>API Security Widget 24</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ApiSecurityWidget25: React.FC<{ seed?: number }> = ({ seed = 25 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="api-security-widget-25"><h4>API Security Widget 25</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ApiSecurityWidget26: React.FC<{ seed?: number }> = ({ seed = 26 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="api-security-widget-26"><h4>API Security Widget 26</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ApiSecurityWidget27: React.FC<{ seed?: number }> = ({ seed = 27 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="api-security-widget-27"><h4>API Security Widget 27</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};
