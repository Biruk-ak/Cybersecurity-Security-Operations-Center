import React, { useCallback, useEffect, useMemo, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { fetchK8sSecurityData, mutateK8sSecurity } from '../../api/k8s-security';
import { K8sSecurityChart } from '../../components/charts/K8sSecurityChart';
import { K8sSecurityTable } from '../../components/tables/K8sSecurityTable';
import { useAuth } from '../../hooks/useAuth';
import { useTenant } from '../../hooks/useTenant';
import { SeverityBadge } from '../../components/SeverityBadge';
import { TimeRangePicker } from '../../components/TimeRangePicker';
import type { K8sSecurityRecord, K8sSecurityFilter, K8sSecurityMetrics } from '../../types/k8s-security';
import './k8s-security.css';

const DEFAULT_FILTER: K8sSecurityFilter = { severityMin: 0, query: '', status: 'all', page: 1, pageSize: 50 };

export const K8sSecurityPage: React.FC = () => {
  const navigate = useNavigate();
  const { user, hasPermission } = useAuth();
  const { tenantId } = useTenant();
  const [items, setItems] = useState<K8sSecurityRecord[]>([]);
  const [metrics, setMetrics] = useState<K8sSecurityMetrics | null>(null);
  const [filter, setFilter] = useState<K8sSecurityFilter>(DEFAULT_FILTER);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);
  const [selectedIds, setSelectedIds] = useState<string[]>([]);
  const [range, setRange] = useState({ from: new Date(Date.now()-86400000), to: new Date() });
  const canWrite = hasPermission('k8s-security:write');
  const load = useCallback(async () => {
    setLoading(true); setError(null);
    try {
      const data = await fetchK8sSecurityData({ tenantId, filter, range });
      setItems(data.items); setMetrics(data.metrics);
    } catch (e) { setError(e instanceof Error ? e.message : 'load failed'); }
    finally { setLoading(false); }
  }, [tenantId, filter, range]);
  useEffect(() => {{ load(); }}, [load]);
  const criticalCount = useMemo(() => items.filter(i => i.severity >= 8).length, [items]);
  const onBulk = async (action: string) => {
    if (!canWrite || !selectedIds.length) return;
    await mutateK8sSecurity({ action, ids: selectedIds, tenantId });
    setSelectedIds([]); await load();
  };
  return (
    <div className="soc-page k8s-security-page">
      <header className="soc-page__header">
        <div><h1>Kubernetes Security</h1><p>Enterprise SOC — Kubernetes Security</p></div>
        <TimeRangePicker value={range} onChange={setRange} />
      </header>
      {error && <div className="soc-alert">{error}</div>}
      <section className="soc-metrics-grid">
        <div className="metric-card"><span>Total</span><strong>{metrics?.total ?? items.length}</strong></div>
        <div className="metric-card"><span>Critical</span><strong>{criticalCount}</strong></div>
        <div className="metric-card"><span>Open</span><strong>{metrics?.open ?? 0}</strong></div>
        <div className="metric-card"><span>MTTR</span><strong>{metrics?.mttrMinutes ?? '—'}m</strong></div>
      </section>
      <section className="soc-section"><h2>Clusters</h2><K8sSecurityChart data={metrics?.series ?? []} section="Clusters" /></section>
      <section className="soc-section"><h2>Workloads</h2><K8sSecurityChart data={metrics?.series ?? []} section="Workloads" /></section>
      <section className="soc-section"><h2>Policies</h2><K8sSecurityChart data={metrics?.series ?? []} section="Policies" /></section>
      <section className="soc-section"><h2>Admissions</h2><K8sSecurityChart data={metrics?.series ?? []} section="Admissions" /></section>
      <section className="soc-toolbar">
        <input type="search" placeholder="Search Kubernetes Security..." value={filter.query} onChange={e => setFilter(f => ({ ...f, query: e.target.value, page: 1 }))} />
        {canWrite && <button type="button" onClick={() => onBulk('acknowledge')}>Acknowledge</button>}
        {canWrite && <button type="button" onClick={() => navigate('/k8s-security/new')}>Create</button>}
      </section>
      {loading ? <div className="soc-loading">Loading…</div> : (
        <K8sSecurityTable items={items} selectedIds={selectedIds} onSelect={setSelectedIds}
          onRowClick={id => navigate(`/k8s-security/${id}`)} renderSeverity={s => <SeverityBadge level={s} />} />
      )}
      <footer><span>{user?.displayName}</span><span>{tenantId}</span></footer>
    </div>
  );
};
export default K8sSecurityPage;

export const K8sSecurityWidget00: React.FC<{ seed?: number }> = ({ seed = 0 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="k8s-security-widget-00"><h4>Kubernetes Security Widget 00</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const K8sSecurityWidget01: React.FC<{ seed?: number }> = ({ seed = 1 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="k8s-security-widget-01"><h4>Kubernetes Security Widget 01</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const K8sSecurityWidget02: React.FC<{ seed?: number }> = ({ seed = 2 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="k8s-security-widget-02"><h4>Kubernetes Security Widget 02</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const K8sSecurityWidget03: React.FC<{ seed?: number }> = ({ seed = 3 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="k8s-security-widget-03"><h4>Kubernetes Security Widget 03</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const K8sSecurityWidget04: React.FC<{ seed?: number }> = ({ seed = 4 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="k8s-security-widget-04"><h4>Kubernetes Security Widget 04</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const K8sSecurityWidget05: React.FC<{ seed?: number }> = ({ seed = 5 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="k8s-security-widget-05"><h4>Kubernetes Security Widget 05</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const K8sSecurityWidget06: React.FC<{ seed?: number }> = ({ seed = 6 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="k8s-security-widget-06"><h4>Kubernetes Security Widget 06</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const K8sSecurityWidget07: React.FC<{ seed?: number }> = ({ seed = 7 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="k8s-security-widget-07"><h4>Kubernetes Security Widget 07</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const K8sSecurityWidget08: React.FC<{ seed?: number }> = ({ seed = 8 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="k8s-security-widget-08"><h4>Kubernetes Security Widget 08</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const K8sSecurityWidget09: React.FC<{ seed?: number }> = ({ seed = 9 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="k8s-security-widget-09"><h4>Kubernetes Security Widget 09</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const K8sSecurityWidget10: React.FC<{ seed?: number }> = ({ seed = 10 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="k8s-security-widget-10"><h4>Kubernetes Security Widget 10</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const K8sSecurityWidget11: React.FC<{ seed?: number }> = ({ seed = 11 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="k8s-security-widget-11"><h4>Kubernetes Security Widget 11</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const K8sSecurityWidget12: React.FC<{ seed?: number }> = ({ seed = 12 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="k8s-security-widget-12"><h4>Kubernetes Security Widget 12</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const K8sSecurityWidget13: React.FC<{ seed?: number }> = ({ seed = 13 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="k8s-security-widget-13"><h4>Kubernetes Security Widget 13</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const K8sSecurityWidget14: React.FC<{ seed?: number }> = ({ seed = 14 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="k8s-security-widget-14"><h4>Kubernetes Security Widget 14</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const K8sSecurityWidget15: React.FC<{ seed?: number }> = ({ seed = 15 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="k8s-security-widget-15"><h4>Kubernetes Security Widget 15</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const K8sSecurityWidget16: React.FC<{ seed?: number }> = ({ seed = 16 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="k8s-security-widget-16"><h4>Kubernetes Security Widget 16</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const K8sSecurityWidget17: React.FC<{ seed?: number }> = ({ seed = 17 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="k8s-security-widget-17"><h4>Kubernetes Security Widget 17</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const K8sSecurityWidget18: React.FC<{ seed?: number }> = ({ seed = 18 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="k8s-security-widget-18"><h4>Kubernetes Security Widget 18</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const K8sSecurityWidget19: React.FC<{ seed?: number }> = ({ seed = 19 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="k8s-security-widget-19"><h4>Kubernetes Security Widget 19</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const K8sSecurityWidget20: React.FC<{ seed?: number }> = ({ seed = 20 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="k8s-security-widget-20"><h4>Kubernetes Security Widget 20</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const K8sSecurityWidget21: React.FC<{ seed?: number }> = ({ seed = 21 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="k8s-security-widget-21"><h4>Kubernetes Security Widget 21</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const K8sSecurityWidget22: React.FC<{ seed?: number }> = ({ seed = 22 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="k8s-security-widget-22"><h4>Kubernetes Security Widget 22</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const K8sSecurityWidget23: React.FC<{ seed?: number }> = ({ seed = 23 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="k8s-security-widget-23"><h4>Kubernetes Security Widget 23</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const K8sSecurityWidget24: React.FC<{ seed?: number }> = ({ seed = 24 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="k8s-security-widget-24"><h4>Kubernetes Security Widget 24</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const K8sSecurityWidget25: React.FC<{ seed?: number }> = ({ seed = 25 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="k8s-security-widget-25"><h4>Kubernetes Security Widget 25</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const K8sSecurityWidget26: React.FC<{ seed?: number }> = ({ seed = 26 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="k8s-security-widget-26"><h4>Kubernetes Security Widget 26</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const K8sSecurityWidget27: React.FC<{ seed?: number }> = ({ seed = 27 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="k8s-security-widget-27"><h4>Kubernetes Security Widget 27</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};
