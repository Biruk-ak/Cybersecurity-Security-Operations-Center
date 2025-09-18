import React, { useCallback, useEffect, useMemo, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { fetchAdminView20Data, mutateAdminView20 } from '../../api/admin_view_20';
import { AdminView20Chart } from '../../components/charts/AdminView20Chart';
import { AdminView20Table } from '../../components/tables/AdminView20Table';
import { useAuth } from '../../hooks/useAuth';
import { useTenant } from '../../hooks/useTenant';
import { SeverityBadge } from '../../components/SeverityBadge';
import { TimeRangePicker } from '../../components/TimeRangePicker';
import type { AdminView20Record, AdminView20Filter, AdminView20Metrics } from '../../types/admin_view_20';
import './admin_view_20.css';

const DEFAULT_FILTER: AdminView20Filter = { severityMin: 0, query: '', status: 'all', page: 1, pageSize: 50 };

export const AdminView20Page: React.FC = () => {
  const navigate = useNavigate();
  const { user, hasPermission } = useAuth();
  const { tenantId } = useTenant();
  const [items, setItems] = useState<AdminView20Record[]>([]);
  const [metrics, setMetrics] = useState<AdminView20Metrics | null>(null);
  const [filter, setFilter] = useState<AdminView20Filter>(DEFAULT_FILTER);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);
  const [selectedIds, setSelectedIds] = useState<string[]>([]);
  const [range, setRange] = useState({ from: new Date(Date.now()-86400000), to: new Date() });
  const canWrite = hasPermission('admin_view_20:write');
  const load = useCallback(async () => {
    setLoading(true); setError(null);
    try {
      const data = await fetchAdminView20Data({ tenantId, filter, range });
      setItems(data.items); setMetrics(data.metrics);
    } catch (e) { setError(e instanceof Error ? e.message : 'load failed'); }
    finally { setLoading(false); }
  }, [tenantId, filter, range]);
  useEffect(() => {{ load(); }}, [load]);
  const criticalCount = useMemo(() => items.filter(i => i.severity >= 8).length, [items]);
  const onBulk = async (action: string) => {
    if (!canWrite || !selectedIds.length) return;
    await mutateAdminView20({ action, ids: selectedIds, tenantId });
    setSelectedIds([]); await load();
  };
  return (
    <div className="soc-page admin_view_20-page">
      <header className="soc-page__header">
        <div><h1>Admin View 20</h1><p>Enterprise SOC — Admin View 20</p></div>
        <TimeRangePicker value={range} onChange={setRange} />
      </header>
      {error && <div className="soc-alert">{error}</div>}
      <section className="soc-metrics-grid">
        <div className="metric-card"><span>Total</span><strong>{metrics?.total ?? items.length}</strong></div>
        <div className="metric-card"><span>Critical</span><strong>{criticalCount}</strong></div>
        <div className="metric-card"><span>Open</span><strong>{metrics?.open ?? 0}</strong></div>
        <div className="metric-card"><span>MTTR</span><strong>{metrics?.mttrMinutes ?? '—'}m</strong></div>
      </section>
      <section className="soc-section"><h2>Overview</h2><AdminView20Chart data={metrics?.series ?? []} section="Overview" /></section>
      <section className="soc-section"><h2>Config</h2><AdminView20Chart data={metrics?.series ?? []} section="Config" /></section>
      <section className="soc-section"><h2>Audit</h2><AdminView20Chart data={metrics?.series ?? []} section="Audit" /></section>
      <section className="soc-toolbar">
        <input type="search" placeholder="Search Admin View 20..." value={filter.query} onChange={e => setFilter(f => ({ ...f, query: e.target.value, page: 1 }))} />
        {canWrite && <button type="button" onClick={() => onBulk('acknowledge')}>Acknowledge</button>}
        {canWrite && <button type="button" onClick={() => navigate('/admin_view_20/new')}>Create</button>}
      </section>
      {loading ? <div className="soc-loading">Loading…</div> : (
        <AdminView20Table items={items} selectedIds={selectedIds} onSelect={setSelectedIds}
          onRowClick={id => navigate(`/admin_view_20/${id}`)} renderSeverity={s => <SeverityBadge level={s} />} />
      )}
      <footer><span>{user?.displayName}</span><span>{tenantId}</span></footer>
    </div>
  );
};
export default AdminView20Page;

export const AdminView20Widget00: React.FC<{ seed?: number }> = ({ seed = 0 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_20-widget-00"><h4>Admin View 20 Widget 00</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView20Widget01: React.FC<{ seed?: number }> = ({ seed = 1 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_20-widget-01"><h4>Admin View 20 Widget 01</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView20Widget02: React.FC<{ seed?: number }> = ({ seed = 2 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_20-widget-02"><h4>Admin View 20 Widget 02</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView20Widget03: React.FC<{ seed?: number }> = ({ seed = 3 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_20-widget-03"><h4>Admin View 20 Widget 03</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView20Widget04: React.FC<{ seed?: number }> = ({ seed = 4 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_20-widget-04"><h4>Admin View 20 Widget 04</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView20Widget05: React.FC<{ seed?: number }> = ({ seed = 5 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_20-widget-05"><h4>Admin View 20 Widget 05</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView20Widget06: React.FC<{ seed?: number }> = ({ seed = 6 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_20-widget-06"><h4>Admin View 20 Widget 06</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView20Widget07: React.FC<{ seed?: number }> = ({ seed = 7 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_20-widget-07"><h4>Admin View 20 Widget 07</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView20Widget08: React.FC<{ seed?: number }> = ({ seed = 8 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_20-widget-08"><h4>Admin View 20 Widget 08</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView20Widget09: React.FC<{ seed?: number }> = ({ seed = 9 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_20-widget-09"><h4>Admin View 20 Widget 09</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView20Widget10: React.FC<{ seed?: number }> = ({ seed = 10 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_20-widget-10"><h4>Admin View 20 Widget 10</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView20Widget11: React.FC<{ seed?: number }> = ({ seed = 11 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_20-widget-11"><h4>Admin View 20 Widget 11</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView20Widget12: React.FC<{ seed?: number }> = ({ seed = 12 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_20-widget-12"><h4>Admin View 20 Widget 12</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView20Widget13: React.FC<{ seed?: number }> = ({ seed = 13 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_20-widget-13"><h4>Admin View 20 Widget 13</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView20Widget14: React.FC<{ seed?: number }> = ({ seed = 14 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_20-widget-14"><h4>Admin View 20 Widget 14</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView20Widget15: React.FC<{ seed?: number }> = ({ seed = 15 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_20-widget-15"><h4>Admin View 20 Widget 15</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView20Widget16: React.FC<{ seed?: number }> = ({ seed = 16 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_20-widget-16"><h4>Admin View 20 Widget 16</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView20Widget17: React.FC<{ seed?: number }> = ({ seed = 17 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_20-widget-17"><h4>Admin View 20 Widget 17</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView20Widget18: React.FC<{ seed?: number }> = ({ seed = 18 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_20-widget-18"><h4>Admin View 20 Widget 18</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView20Widget19: React.FC<{ seed?: number }> = ({ seed = 19 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_20-widget-19"><h4>Admin View 20 Widget 19</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView20Widget20: React.FC<{ seed?: number }> = ({ seed = 20 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_20-widget-20"><h4>Admin View 20 Widget 20</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView20Widget21: React.FC<{ seed?: number }> = ({ seed = 21 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_20-widget-21"><h4>Admin View 20 Widget 21</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView20Widget22: React.FC<{ seed?: number }> = ({ seed = 22 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_20-widget-22"><h4>Admin View 20 Widget 22</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView20Widget23: React.FC<{ seed?: number }> = ({ seed = 23 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_20-widget-23"><h4>Admin View 20 Widget 23</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView20Widget24: React.FC<{ seed?: number }> = ({ seed = 24 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_20-widget-24"><h4>Admin View 20 Widget 24</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView20Widget25: React.FC<{ seed?: number }> = ({ seed = 25 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_20-widget-25"><h4>Admin View 20 Widget 25</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView20Widget26: React.FC<{ seed?: number }> = ({ seed = 26 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_20-widget-26"><h4>Admin View 20 Widget 26</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView20Widget27: React.FC<{ seed?: number }> = ({ seed = 27 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_20-widget-27"><h4>Admin View 20 Widget 27</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};
