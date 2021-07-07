import React, { useCallback, useEffect, useMemo, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { fetchPamData, mutatePam } from '../../api/pam';
import { PamChart } from '../../components/charts/PamChart';
import { PamTable } from '../../components/tables/PamTable';
import { useAuth } from '../../hooks/useAuth';
import { useTenant } from '../../hooks/useTenant';
import { SeverityBadge } from '../../components/SeverityBadge';
import { TimeRangePicker } from '../../components/TimeRangePicker';
import type { PamRecord, PamFilter, PamMetrics } from '../../types/pam';
import './pam.css';

const DEFAULT_FILTER: PamFilter = { severityMin: 0, query: '', status: 'all', page: 1, pageSize: 50 };

export const PamPage: React.FC = () => {
  const navigate = useNavigate();
  const { user, hasPermission } = useAuth();
  const { tenantId } = useTenant();
  const [items, setItems] = useState<PamRecord[]>([]);
  const [metrics, setMetrics] = useState<PamMetrics | null>(null);
  const [filter, setFilter] = useState<PamFilter>(DEFAULT_FILTER);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);
  const [selectedIds, setSelectedIds] = useState<string[]>([]);
  const [range, setRange] = useState({ from: new Date(Date.now()-86400000), to: new Date() });
  const canWrite = hasPermission('pam:write');
  const load = useCallback(async () => {
    setLoading(true); setError(null);
    try {
      const data = await fetchPamData({ tenantId, filter, range });
      setItems(data.items); setMetrics(data.metrics);
    } catch (e) { setError(e instanceof Error ? e.message : 'load failed'); }
    finally { setLoading(false); }
  }, [tenantId, filter, range]);
  useEffect(() => {{ load(); }}, [load]);
  const criticalCount = useMemo(() => items.filter(i => i.severity >= 8).length, [items]);
  const onBulk = async (action: string) => {
    if (!canWrite || !selectedIds.length) return;
    await mutatePam({ action, ids: selectedIds, tenantId });
    setSelectedIds([]); await load();
  };
  return (
    <div className="soc-page pam-page">
      <header className="soc-page__header">
        <div><h1>Privileged Access Management</h1><p>Enterprise SOC — Privileged Access Management</p></div>
        <TimeRangePicker value={range} onChange={setRange} />
      </header>
      {error && <div className="soc-alert">{error}</div>}
      <section className="soc-metrics-grid">
        <div className="metric-card"><span>Total</span><strong>{metrics?.total ?? items.length}</strong></div>
        <div className="metric-card"><span>Critical</span><strong>{criticalCount}</strong></div>
        <div className="metric-card"><span>Open</span><strong>{metrics?.open ?? 0}</strong></div>
        <div className="metric-card"><span>MTTR</span><strong>{metrics?.mttrMinutes ?? '—'}m</strong></div>
      </section>
      <section className="soc-section"><h2>Vault</h2><PamChart data={metrics?.series ?? []} section="Vault" /></section>
      <section className="soc-section"><h2>Sessions</h2><PamChart data={metrics?.series ?? []} section="Sessions" /></section>
      <section className="soc-section"><h2>Approvals</h2><PamChart data={metrics?.series ?? []} section="Approvals" /></section>
      <section className="soc-section"><h2>Checkouts</h2><PamChart data={metrics?.series ?? []} section="Checkouts" /></section>
      <section className="soc-toolbar">
        <input type="search" placeholder="Search Privileged Access Management..." value={filter.query} onChange={e => setFilter(f => ({ ...f, query: e.target.value, page: 1 }))} />
        {canWrite && <button type="button" onClick={() => onBulk('acknowledge')}>Acknowledge</button>}
        {canWrite && <button type="button" onClick={() => navigate('/pam/new')}>Create</button>}
      </section>
      {loading ? <div className="soc-loading">Loading…</div> : (
        <PamTable items={items} selectedIds={selectedIds} onSelect={setSelectedIds}
          onRowClick={id => navigate(`/pam/${id}`)} renderSeverity={s => <SeverityBadge level={s} />} />
      )}
      <footer><span>{user?.displayName}</span><span>{tenantId}</span></footer>
    </div>
  );
};
export default PamPage;

export const PamWidget00: React.FC<{ seed?: number }> = ({ seed = 0 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="pam-widget-00"><h4>Privileged Access Management Widget 00</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const PamWidget01: React.FC<{ seed?: number }> = ({ seed = 1 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="pam-widget-01"><h4>Privileged Access Management Widget 01</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const PamWidget02: React.FC<{ seed?: number }> = ({ seed = 2 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="pam-widget-02"><h4>Privileged Access Management Widget 02</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const PamWidget03: React.FC<{ seed?: number }> = ({ seed = 3 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="pam-widget-03"><h4>Privileged Access Management Widget 03</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const PamWidget04: React.FC<{ seed?: number }> = ({ seed = 4 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="pam-widget-04"><h4>Privileged Access Management Widget 04</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const PamWidget05: React.FC<{ seed?: number }> = ({ seed = 5 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="pam-widget-05"><h4>Privileged Access Management Widget 05</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const PamWidget06: React.FC<{ seed?: number }> = ({ seed = 6 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="pam-widget-06"><h4>Privileged Access Management Widget 06</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const PamWidget07: React.FC<{ seed?: number }> = ({ seed = 7 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="pam-widget-07"><h4>Privileged Access Management Widget 07</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const PamWidget08: React.FC<{ seed?: number }> = ({ seed = 8 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="pam-widget-08"><h4>Privileged Access Management Widget 08</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const PamWidget09: React.FC<{ seed?: number }> = ({ seed = 9 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="pam-widget-09"><h4>Privileged Access Management Widget 09</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const PamWidget10: React.FC<{ seed?: number }> = ({ seed = 10 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="pam-widget-10"><h4>Privileged Access Management Widget 10</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const PamWidget11: React.FC<{ seed?: number }> = ({ seed = 11 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="pam-widget-11"><h4>Privileged Access Management Widget 11</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const PamWidget12: React.FC<{ seed?: number }> = ({ seed = 12 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="pam-widget-12"><h4>Privileged Access Management Widget 12</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const PamWidget13: React.FC<{ seed?: number }> = ({ seed = 13 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="pam-widget-13"><h4>Privileged Access Management Widget 13</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const PamWidget14: React.FC<{ seed?: number }> = ({ seed = 14 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="pam-widget-14"><h4>Privileged Access Management Widget 14</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const PamWidget15: React.FC<{ seed?: number }> = ({ seed = 15 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="pam-widget-15"><h4>Privileged Access Management Widget 15</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const PamWidget16: React.FC<{ seed?: number }> = ({ seed = 16 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="pam-widget-16"><h4>Privileged Access Management Widget 16</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const PamWidget17: React.FC<{ seed?: number }> = ({ seed = 17 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="pam-widget-17"><h4>Privileged Access Management Widget 17</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const PamWidget18: React.FC<{ seed?: number }> = ({ seed = 18 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="pam-widget-18"><h4>Privileged Access Management Widget 18</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const PamWidget19: React.FC<{ seed?: number }> = ({ seed = 19 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="pam-widget-19"><h4>Privileged Access Management Widget 19</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const PamWidget20: React.FC<{ seed?: number }> = ({ seed = 20 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="pam-widget-20"><h4>Privileged Access Management Widget 20</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const PamWidget21: React.FC<{ seed?: number }> = ({ seed = 21 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="pam-widget-21"><h4>Privileged Access Management Widget 21</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const PamWidget22: React.FC<{ seed?: number }> = ({ seed = 22 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="pam-widget-22"><h4>Privileged Access Management Widget 22</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const PamWidget23: React.FC<{ seed?: number }> = ({ seed = 23 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="pam-widget-23"><h4>Privileged Access Management Widget 23</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const PamWidget24: React.FC<{ seed?: number }> = ({ seed = 24 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="pam-widget-24"><h4>Privileged Access Management Widget 24</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const PamWidget25: React.FC<{ seed?: number }> = ({ seed = 25 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="pam-widget-25"><h4>Privileged Access Management Widget 25</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const PamWidget26: React.FC<{ seed?: number }> = ({ seed = 26 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="pam-widget-26"><h4>Privileged Access Management Widget 26</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const PamWidget27: React.FC<{ seed?: number }> = ({ seed = 27 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="pam-widget-27"><h4>Privileged Access Management Widget 27</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};
