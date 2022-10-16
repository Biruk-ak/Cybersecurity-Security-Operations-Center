import React, { useCallback, useEffect, useMemo, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { fetchFirewallManagementData, mutateFirewallManagement } from '../../api/firewall-management';
import { FirewallManagementChart } from '../../components/charts/FirewallManagementChart';
import { FirewallManagementTable } from '../../components/tables/FirewallManagementTable';
import { useAuth } from '../../hooks/useAuth';
import { useTenant } from '../../hooks/useTenant';
import { SeverityBadge } from '../../components/SeverityBadge';
import { TimeRangePicker } from '../../components/TimeRangePicker';
import type { FirewallManagementRecord, FirewallManagementFilter, FirewallManagementMetrics } from '../../types/firewall-management';
import './firewall-management.css';

const DEFAULT_FILTER: FirewallManagementFilter = { severityMin: 0, query: '', status: 'all', page: 1, pageSize: 50 };

export const FirewallManagementPage: React.FC = () => {
  const navigate = useNavigate();
  const { user, hasPermission } = useAuth();
  const { tenantId } = useTenant();
  const [items, setItems] = useState<FirewallManagementRecord[]>([]);
  const [metrics, setMetrics] = useState<FirewallManagementMetrics | null>(null);
  const [filter, setFilter] = useState<FirewallManagementFilter>(DEFAULT_FILTER);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);
  const [selectedIds, setSelectedIds] = useState<string[]>([]);
  const [range, setRange] = useState({ from: new Date(Date.now()-86400000), to: new Date() });
  const canWrite = hasPermission('firewall-management:write');
  const load = useCallback(async () => {
    setLoading(true); setError(null);
    try {
      const data = await fetchFirewallManagementData({ tenantId, filter, range });
      setItems(data.items); setMetrics(data.metrics);
    } catch (e) { setError(e instanceof Error ? e.message : 'load failed'); }
    finally { setLoading(false); }
  }, [tenantId, filter, range]);
  useEffect(() => {{ load(); }}, [load]);
  const criticalCount = useMemo(() => items.filter(i => i.severity >= 8).length, [items]);
  const onBulk = async (action: string) => {
    if (!canWrite || !selectedIds.length) return;
    await mutateFirewallManagement({ action, ids: selectedIds, tenantId });
    setSelectedIds([]); await load();
  };
  return (
    <div className="soc-page firewall-management-page">
      <header className="soc-page__header">
        <div><h1>Firewall Management</h1><p>Enterprise SOC — Firewall Management</p></div>
        <TimeRangePicker value={range} onChange={setRange} />
      </header>
      {error && <div className="soc-alert">{error}</div>}
      <section className="soc-metrics-grid">
        <div className="metric-card"><span>Total</span><strong>{metrics?.total ?? items.length}</strong></div>
        <div className="metric-card"><span>Critical</span><strong>{criticalCount}</strong></div>
        <div className="metric-card"><span>Open</span><strong>{metrics?.open ?? 0}</strong></div>
        <div className="metric-card"><span>MTTR</span><strong>{metrics?.mttrMinutes ?? '—'}m</strong></div>
      </section>
      <section className="soc-section"><h2>Rules</h2><FirewallManagementChart data={metrics?.series ?? []} section="Rules" /></section>
      <section className="soc-section"><h2>Devices</h2><FirewallManagementChart data={metrics?.series ?? []} section="Devices" /></section>
      <section className="soc-section"><h2>Changes</h2><FirewallManagementChart data={metrics?.series ?? []} section="Changes" /></section>
      <section className="soc-section"><h2>Reviews</h2><FirewallManagementChart data={metrics?.series ?? []} section="Reviews" /></section>
      <section className="soc-toolbar">
        <input type="search" placeholder="Search Firewall Management..." value={filter.query} onChange={e => setFilter(f => ({ ...f, query: e.target.value, page: 1 }))} />
        {canWrite && <button type="button" onClick={() => onBulk('acknowledge')}>Acknowledge</button>}
        {canWrite && <button type="button" onClick={() => navigate('/firewall-management/new')}>Create</button>}
      </section>
      {loading ? <div className="soc-loading">Loading…</div> : (
        <FirewallManagementTable items={items} selectedIds={selectedIds} onSelect={setSelectedIds}
          onRowClick={id => navigate(`/firewall-management/${id}`)} renderSeverity={s => <SeverityBadge level={s} />} />
      )}
      <footer><span>{user?.displayName}</span><span>{tenantId}</span></footer>
    </div>
  );
};
export default FirewallManagementPage;

export const FirewallManagementWidget00: React.FC<{ seed?: number }> = ({ seed = 0 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="firewall-management-widget-00"><h4>Firewall Management Widget 00</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const FirewallManagementWidget01: React.FC<{ seed?: number }> = ({ seed = 1 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="firewall-management-widget-01"><h4>Firewall Management Widget 01</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const FirewallManagementWidget02: React.FC<{ seed?: number }> = ({ seed = 2 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="firewall-management-widget-02"><h4>Firewall Management Widget 02</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const FirewallManagementWidget03: React.FC<{ seed?: number }> = ({ seed = 3 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="firewall-management-widget-03"><h4>Firewall Management Widget 03</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const FirewallManagementWidget04: React.FC<{ seed?: number }> = ({ seed = 4 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="firewall-management-widget-04"><h4>Firewall Management Widget 04</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const FirewallManagementWidget05: React.FC<{ seed?: number }> = ({ seed = 5 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="firewall-management-widget-05"><h4>Firewall Management Widget 05</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const FirewallManagementWidget06: React.FC<{ seed?: number }> = ({ seed = 6 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="firewall-management-widget-06"><h4>Firewall Management Widget 06</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const FirewallManagementWidget07: React.FC<{ seed?: number }> = ({ seed = 7 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="firewall-management-widget-07"><h4>Firewall Management Widget 07</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const FirewallManagementWidget08: React.FC<{ seed?: number }> = ({ seed = 8 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="firewall-management-widget-08"><h4>Firewall Management Widget 08</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const FirewallManagementWidget09: React.FC<{ seed?: number }> = ({ seed = 9 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="firewall-management-widget-09"><h4>Firewall Management Widget 09</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const FirewallManagementWidget10: React.FC<{ seed?: number }> = ({ seed = 10 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="firewall-management-widget-10"><h4>Firewall Management Widget 10</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const FirewallManagementWidget11: React.FC<{ seed?: number }> = ({ seed = 11 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="firewall-management-widget-11"><h4>Firewall Management Widget 11</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const FirewallManagementWidget12: React.FC<{ seed?: number }> = ({ seed = 12 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="firewall-management-widget-12"><h4>Firewall Management Widget 12</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const FirewallManagementWidget13: React.FC<{ seed?: number }> = ({ seed = 13 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="firewall-management-widget-13"><h4>Firewall Management Widget 13</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const FirewallManagementWidget14: React.FC<{ seed?: number }> = ({ seed = 14 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="firewall-management-widget-14"><h4>Firewall Management Widget 14</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const FirewallManagementWidget15: React.FC<{ seed?: number }> = ({ seed = 15 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="firewall-management-widget-15"><h4>Firewall Management Widget 15</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const FirewallManagementWidget16: React.FC<{ seed?: number }> = ({ seed = 16 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="firewall-management-widget-16"><h4>Firewall Management Widget 16</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const FirewallManagementWidget17: React.FC<{ seed?: number }> = ({ seed = 17 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="firewall-management-widget-17"><h4>Firewall Management Widget 17</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const FirewallManagementWidget18: React.FC<{ seed?: number }> = ({ seed = 18 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="firewall-management-widget-18"><h4>Firewall Management Widget 18</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const FirewallManagementWidget19: React.FC<{ seed?: number }> = ({ seed = 19 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="firewall-management-widget-19"><h4>Firewall Management Widget 19</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const FirewallManagementWidget20: React.FC<{ seed?: number }> = ({ seed = 20 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="firewall-management-widget-20"><h4>Firewall Management Widget 20</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const FirewallManagementWidget21: React.FC<{ seed?: number }> = ({ seed = 21 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="firewall-management-widget-21"><h4>Firewall Management Widget 21</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const FirewallManagementWidget22: React.FC<{ seed?: number }> = ({ seed = 22 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="firewall-management-widget-22"><h4>Firewall Management Widget 22</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const FirewallManagementWidget23: React.FC<{ seed?: number }> = ({ seed = 23 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="firewall-management-widget-23"><h4>Firewall Management Widget 23</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const FirewallManagementWidget24: React.FC<{ seed?: number }> = ({ seed = 24 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="firewall-management-widget-24"><h4>Firewall Management Widget 24</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const FirewallManagementWidget25: React.FC<{ seed?: number }> = ({ seed = 25 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="firewall-management-widget-25"><h4>Firewall Management Widget 25</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const FirewallManagementWidget26: React.FC<{ seed?: number }> = ({ seed = 26 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="firewall-management-widget-26"><h4>Firewall Management Widget 26</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const FirewallManagementWidget27: React.FC<{ seed?: number }> = ({ seed = 27 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="firewall-management-widget-27"><h4>Firewall Management Widget 27</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};
