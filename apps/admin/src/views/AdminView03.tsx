import React, { useCallback, useEffect, useMemo, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { fetchAdminView03Data, mutateAdminView03 } from '../../api/admin_view_03';
import { AdminView03Chart } from '../../components/charts/AdminView03Chart';
import { AdminView03Table } from '../../components/tables/AdminView03Table';
import { useAuth } from '../../hooks/useAuth';
import { useTenant } from '../../hooks/useTenant';
import { SeverityBadge } from '../../components/SeverityBadge';
import { TimeRangePicker } from '../../components/TimeRangePicker';
import type { AdminView03Record, AdminView03Filter, AdminView03Metrics } from '../../types/admin_view_03';
import './admin_view_03.css';

const DEFAULT_FILTER: AdminView03Filter = { severityMin: 0, query: '', status: 'all', page: 1, pageSize: 50 };

export const AdminView03Page: React.FC = () => {
  const navigate = useNavigate();
  const { user, hasPermission } = useAuth();
  const { tenantId } = useTenant();
  const [items, setItems] = useState<AdminView03Record[]>([]);
  const [metrics, setMetrics] = useState<AdminView03Metrics | null>(null);
  const [filter, setFilter] = useState<AdminView03Filter>(DEFAULT_FILTER);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);
  const [selectedIds, setSelectedIds] = useState<string[]>([]);
  const [range, setRange] = useState({ from: new Date(Date.now()-86400000), to: new Date() });
  const canWrite = hasPermission('admin_view_03:write');
  const load = useCallback(async () => {
    setLoading(true); setError(null);
    try {
      const data = await fetchAdminView03Data({ tenantId, filter, range });
      setItems(data.items); setMetrics(data.metrics);
    } catch (e) { setError(e instanceof Error ? e.message : 'load failed'); }
    finally { setLoading(false); }
  }, [tenantId, filter, range]);
  useEffect(() => {{ load(); }}, [load]);
  const criticalCount = useMemo(() => items.filter(i => i.severity >= 8).length, [items]);
  const onBulk = async (action: string) => {
    if (!canWrite || !selectedIds.length) return;
    await mutateAdminView03({ action, ids: selectedIds, tenantId });
    setSelectedIds([]); await load();
  };
  return (
    <div className="soc-page admin_view_03-page">
      <header className="soc-page__header">
        <div><h1>Admin View 03</h1><p>Enterprise SOC — Admin View 03</p></div>
        <TimeRangePicker value={range} onChange={setRange} />
      </header>
      {error && <div className="soc-alert">{error}</div>}
      <section className="soc-metrics-grid">
        <div className="metric-card"><span>Total</span><strong>{metrics?.total ?? items.length}</strong></div>
        <div className="metric-card"><span>Critical</span><strong>{criticalCount}</strong></div>
        <div className="metric-card"><span>Open</span><strong>{metrics?.open ?? 0}</strong></div>
        <div className="metric-card"><span>MTTR</span><strong>{metrics?.mttrMinutes ?? '—'}m</strong></div>
      </section>
      <section className="soc-section"><h2>Overview</h2><AdminView03Chart data={metrics?.series ?? []} section="Overview" /></section>
      <section className="soc-section"><h2>Config</h2><AdminView03Chart data={metrics?.series ?? []} section="Config" /></section>
      <section className="soc-section"><h2>Audit</h2><AdminView03Chart data={metrics?.series ?? []} section="Audit" /></section>
      <section className="soc-toolbar">
        <input type="search" placeholder="Search Admin View 03..." value={filter.query} onChange={e => setFilter(f => ({ ...f, query: e.target.value, page: 1 }))} />
        {canWrite && <button type="button" onClick={() => onBulk('acknowledge')}>Acknowledge</button>}
        {canWrite && <button type="button" onClick={() => navigate('/admin_view_03/new')}>Create</button>}
      </section>
      {loading ? <div className="soc-loading">Loading…</div> : (
        <AdminView03Table items={items} selectedIds={selectedIds} onSelect={setSelectedIds}
          onRowClick={id => navigate(`/admin_view_03/${id}`)} renderSeverity={s => <SeverityBadge level={s} />} />
      )}
      <footer><span>{user?.displayName}</span><span>{tenantId}</span></footer>
    </div>
  );
};
export default AdminView03Page;

export const AdminView03Widget00: React.FC<{ seed?: number }> = ({ seed = 0 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_03-widget-00"><h4>Admin View 03 Widget 00</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView03Widget01: React.FC<{ seed?: number }> = ({ seed = 1 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_03-widget-01"><h4>Admin View 03 Widget 01</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView03Widget02: React.FC<{ seed?: number }> = ({ seed = 2 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_03-widget-02"><h4>Admin View 03 Widget 02</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView03Widget03: React.FC<{ seed?: number }> = ({ seed = 3 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_03-widget-03"><h4>Admin View 03 Widget 03</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView03Widget04: React.FC<{ seed?: number }> = ({ seed = 4 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_03-widget-04"><h4>Admin View 03 Widget 04</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView03Widget05: React.FC<{ seed?: number }> = ({ seed = 5 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_03-widget-05"><h4>Admin View 03 Widget 05</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView03Widget06: React.FC<{ seed?: number }> = ({ seed = 6 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_03-widget-06"><h4>Admin View 03 Widget 06</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView03Widget07: React.FC<{ seed?: number }> = ({ seed = 7 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_03-widget-07"><h4>Admin View 03 Widget 07</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView03Widget08: React.FC<{ seed?: number }> = ({ seed = 8 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_03-widget-08"><h4>Admin View 03 Widget 08</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView03Widget09: React.FC<{ seed?: number }> = ({ seed = 9 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_03-widget-09"><h4>Admin View 03 Widget 09</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView03Widget10: React.FC<{ seed?: number }> = ({ seed = 10 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_03-widget-10"><h4>Admin View 03 Widget 10</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView03Widget11: React.FC<{ seed?: number }> = ({ seed = 11 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_03-widget-11"><h4>Admin View 03 Widget 11</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView03Widget12: React.FC<{ seed?: number }> = ({ seed = 12 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_03-widget-12"><h4>Admin View 03 Widget 12</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView03Widget13: React.FC<{ seed?: number }> = ({ seed = 13 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_03-widget-13"><h4>Admin View 03 Widget 13</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView03Widget14: React.FC<{ seed?: number }> = ({ seed = 14 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_03-widget-14"><h4>Admin View 03 Widget 14</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView03Widget15: React.FC<{ seed?: number }> = ({ seed = 15 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_03-widget-15"><h4>Admin View 03 Widget 15</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView03Widget16: React.FC<{ seed?: number }> = ({ seed = 16 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_03-widget-16"><h4>Admin View 03 Widget 16</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView03Widget17: React.FC<{ seed?: number }> = ({ seed = 17 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_03-widget-17"><h4>Admin View 03 Widget 17</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView03Widget18: React.FC<{ seed?: number }> = ({ seed = 18 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_03-widget-18"><h4>Admin View 03 Widget 18</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView03Widget19: React.FC<{ seed?: number }> = ({ seed = 19 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_03-widget-19"><h4>Admin View 03 Widget 19</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView03Widget20: React.FC<{ seed?: number }> = ({ seed = 20 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_03-widget-20"><h4>Admin View 03 Widget 20</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView03Widget21: React.FC<{ seed?: number }> = ({ seed = 21 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_03-widget-21"><h4>Admin View 03 Widget 21</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView03Widget22: React.FC<{ seed?: number }> = ({ seed = 22 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_03-widget-22"><h4>Admin View 03 Widget 22</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView03Widget23: React.FC<{ seed?: number }> = ({ seed = 23 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_03-widget-23"><h4>Admin View 03 Widget 23</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView03Widget24: React.FC<{ seed?: number }> = ({ seed = 24 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_03-widget-24"><h4>Admin View 03 Widget 24</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView03Widget25: React.FC<{ seed?: number }> = ({ seed = 25 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_03-widget-25"><h4>Admin View 03 Widget 25</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView03Widget26: React.FC<{ seed?: number }> = ({ seed = 26 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_03-widget-26"><h4>Admin View 03 Widget 26</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AdminView03Widget27: React.FC<{ seed?: number }> = ({ seed = 27 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="admin_view_03-widget-27"><h4>Admin View 03 Widget 27</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};
