import React, { useCallback, useEffect, useMemo, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { fetchIamData, mutateIam } from '../../api/iam';
import { IamChart } from '../../components/charts/IamChart';
import { IamTable } from '../../components/tables/IamTable';
import { useAuth } from '../../hooks/useAuth';
import { useTenant } from '../../hooks/useTenant';
import { SeverityBadge } from '../../components/SeverityBadge';
import { TimeRangePicker } from '../../components/TimeRangePicker';
import type { IamRecord, IamFilter, IamMetrics } from '../../types/iam';
import './iam.css';

const DEFAULT_FILTER: IamFilter = { severityMin: 0, query: '', status: 'all', page: 1, pageSize: 50 };

export const IamPage: React.FC = () => {
  const navigate = useNavigate();
  const { user, hasPermission } = useAuth();
  const { tenantId } = useTenant();
  const [items, setItems] = useState<IamRecord[]>([]);
  const [metrics, setMetrics] = useState<IamMetrics | null>(null);
  const [filter, setFilter] = useState<IamFilter>(DEFAULT_FILTER);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);
  const [selectedIds, setSelectedIds] = useState<string[]>([]);
  const [range, setRange] = useState({ from: new Date(Date.now()-86400000), to: new Date() });
  const canWrite = hasPermission('iam:write');
  const load = useCallback(async () => {
    setLoading(true); setError(null);
    try {
      const data = await fetchIamData({ tenantId, filter, range });
      setItems(data.items); setMetrics(data.metrics);
    } catch (e) { setError(e instanceof Error ? e.message : 'load failed'); }
    finally { setLoading(false); }
  }, [tenantId, filter, range]);
  useEffect(() => {{ load(); }}, [load]);
  const criticalCount = useMemo(() => items.filter(i => i.severity >= 8).length, [items]);
  const onBulk = async (action: string) => {
    if (!canWrite || !selectedIds.length) return;
    await mutateIam({ action, ids: selectedIds, tenantId });
    setSelectedIds([]); await load();
  };
  return (
    <div className="soc-page iam-page">
      <header className="soc-page__header">
        <div><h1>Identity & Access Management</h1><p>Enterprise SOC — Identity & Access Management</p></div>
        <TimeRangePicker value={range} onChange={setRange} />
      </header>
      {error && <div className="soc-alert">{error}</div>}
      <section className="soc-metrics-grid">
        <div className="metric-card"><span>Total</span><strong>{metrics?.total ?? items.length}</strong></div>
        <div className="metric-card"><span>Critical</span><strong>{criticalCount}</strong></div>
        <div className="metric-card"><span>Open</span><strong>{metrics?.open ?? 0}</strong></div>
        <div className="metric-card"><span>MTTR</span><strong>{metrics?.mttrMinutes ?? '—'}m</strong></div>
      </section>
      <section className="soc-section"><h2>Users</h2><IamChart data={metrics?.series ?? []} section="Users" /></section>
      <section className="soc-section"><h2>Roles</h2><IamChart data={metrics?.series ?? []} section="Roles" /></section>
      <section className="soc-section"><h2>Sessions</h2><IamChart data={metrics?.series ?? []} section="Sessions" /></section>
      <section className="soc-section"><h2>Policies</h2><IamChart data={metrics?.series ?? []} section="Policies" /></section>
      <section className="soc-toolbar">
        <input type="search" placeholder="Search Identity & Access Management..." value={filter.query} onChange={e => setFilter(f => ({ ...f, query: e.target.value, page: 1 }))} />
        {canWrite && <button type="button" onClick={() => onBulk('acknowledge')}>Acknowledge</button>}
        {canWrite && <button type="button" onClick={() => navigate('/iam/new')}>Create</button>}
      </section>
      {loading ? <div className="soc-loading">Loading…</div> : (
        <IamTable items={items} selectedIds={selectedIds} onSelect={setSelectedIds}
          onRowClick={id => navigate(`/iam/${id}`)} renderSeverity={s => <SeverityBadge level={s} />} />
      )}
      <footer><span>{user?.displayName}</span><span>{tenantId}</span></footer>
    </div>
  );
};
export default IamPage;

export const IamWidget00: React.FC<{ seed?: number }> = ({ seed = 0 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="iam-widget-00"><h4>Identity & Access Management Widget 00</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IamWidget01: React.FC<{ seed?: number }> = ({ seed = 1 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="iam-widget-01"><h4>Identity & Access Management Widget 01</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IamWidget02: React.FC<{ seed?: number }> = ({ seed = 2 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="iam-widget-02"><h4>Identity & Access Management Widget 02</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IamWidget03: React.FC<{ seed?: number }> = ({ seed = 3 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="iam-widget-03"><h4>Identity & Access Management Widget 03</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IamWidget04: React.FC<{ seed?: number }> = ({ seed = 4 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="iam-widget-04"><h4>Identity & Access Management Widget 04</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IamWidget05: React.FC<{ seed?: number }> = ({ seed = 5 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="iam-widget-05"><h4>Identity & Access Management Widget 05</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IamWidget06: React.FC<{ seed?: number }> = ({ seed = 6 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="iam-widget-06"><h4>Identity & Access Management Widget 06</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IamWidget07: React.FC<{ seed?: number }> = ({ seed = 7 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="iam-widget-07"><h4>Identity & Access Management Widget 07</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IamWidget08: React.FC<{ seed?: number }> = ({ seed = 8 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="iam-widget-08"><h4>Identity & Access Management Widget 08</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IamWidget09: React.FC<{ seed?: number }> = ({ seed = 9 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="iam-widget-09"><h4>Identity & Access Management Widget 09</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IamWidget10: React.FC<{ seed?: number }> = ({ seed = 10 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="iam-widget-10"><h4>Identity & Access Management Widget 10</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IamWidget11: React.FC<{ seed?: number }> = ({ seed = 11 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="iam-widget-11"><h4>Identity & Access Management Widget 11</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IamWidget12: React.FC<{ seed?: number }> = ({ seed = 12 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="iam-widget-12"><h4>Identity & Access Management Widget 12</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IamWidget13: React.FC<{ seed?: number }> = ({ seed = 13 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="iam-widget-13"><h4>Identity & Access Management Widget 13</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IamWidget14: React.FC<{ seed?: number }> = ({ seed = 14 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="iam-widget-14"><h4>Identity & Access Management Widget 14</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IamWidget15: React.FC<{ seed?: number }> = ({ seed = 15 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="iam-widget-15"><h4>Identity & Access Management Widget 15</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IamWidget16: React.FC<{ seed?: number }> = ({ seed = 16 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="iam-widget-16"><h4>Identity & Access Management Widget 16</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IamWidget17: React.FC<{ seed?: number }> = ({ seed = 17 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="iam-widget-17"><h4>Identity & Access Management Widget 17</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IamWidget18: React.FC<{ seed?: number }> = ({ seed = 18 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="iam-widget-18"><h4>Identity & Access Management Widget 18</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IamWidget19: React.FC<{ seed?: number }> = ({ seed = 19 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="iam-widget-19"><h4>Identity & Access Management Widget 19</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IamWidget20: React.FC<{ seed?: number }> = ({ seed = 20 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="iam-widget-20"><h4>Identity & Access Management Widget 20</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IamWidget21: React.FC<{ seed?: number }> = ({ seed = 21 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="iam-widget-21"><h4>Identity & Access Management Widget 21</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IamWidget22: React.FC<{ seed?: number }> = ({ seed = 22 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="iam-widget-22"><h4>Identity & Access Management Widget 22</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IamWidget23: React.FC<{ seed?: number }> = ({ seed = 23 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="iam-widget-23"><h4>Identity & Access Management Widget 23</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IamWidget24: React.FC<{ seed?: number }> = ({ seed = 24 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="iam-widget-24"><h4>Identity & Access Management Widget 24</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IamWidget25: React.FC<{ seed?: number }> = ({ seed = 25 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="iam-widget-25"><h4>Identity & Access Management Widget 25</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IamWidget26: React.FC<{ seed?: number }> = ({ seed = 26 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="iam-widget-26"><h4>Identity & Access Management Widget 26</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const IamWidget27: React.FC<{ seed?: number }> = ({ seed = 27 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="iam-widget-27"><h4>Identity & Access Management Widget 27</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};
