import React, { useCallback, useEffect, useMemo, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { fetchSecurityPoliciesData, mutateSecurityPolicies } from '../../api/security-policies';
import { SecurityPoliciesChart } from '../../components/charts/SecurityPoliciesChart';
import { SecurityPoliciesTable } from '../../components/tables/SecurityPoliciesTable';
import { useAuth } from '../../hooks/useAuth';
import { useTenant } from '../../hooks/useTenant';
import { SeverityBadge } from '../../components/SeverityBadge';
import { TimeRangePicker } from '../../components/TimeRangePicker';
import type { SecurityPoliciesRecord, SecurityPoliciesFilter, SecurityPoliciesMetrics } from '../../types/security-policies';
import './security-policies.css';

const DEFAULT_FILTER: SecurityPoliciesFilter = { severityMin: 0, query: '', status: 'all', page: 1, pageSize: 50 };

export const SecurityPoliciesPage: React.FC = () => {
  const navigate = useNavigate();
  const { user, hasPermission } = useAuth();
  const { tenantId } = useTenant();
  const [items, setItems] = useState<SecurityPoliciesRecord[]>([]);
  const [metrics, setMetrics] = useState<SecurityPoliciesMetrics | null>(null);
  const [filter, setFilter] = useState<SecurityPoliciesFilter>(DEFAULT_FILTER);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);
  const [selectedIds, setSelectedIds] = useState<string[]>([]);
  const [range, setRange] = useState({ from: new Date(Date.now()-86400000), to: new Date() });
  const canWrite = hasPermission('security-policies:write');
  const load = useCallback(async () => {
    setLoading(true); setError(null);
    try {
      const data = await fetchSecurityPoliciesData({ tenantId, filter, range });
      setItems(data.items); setMetrics(data.metrics);
    } catch (e) { setError(e instanceof Error ? e.message : 'load failed'); }
    finally { setLoading(false); }
  }, [tenantId, filter, range]);
  useEffect(() => {{ load(); }}, [load]);
  const criticalCount = useMemo(() => items.filter(i => i.severity >= 8).length, [items]);
  const onBulk = async (action: string) => {
    if (!canWrite || !selectedIds.length) return;
    await mutateSecurityPolicies({ action, ids: selectedIds, tenantId });
    setSelectedIds([]); await load();
  };
  return (
    <div className="soc-page security-policies-page">
      <header className="soc-page__header">
        <div><h1>Security Policies</h1><p>Enterprise SOC — Security Policies</p></div>
        <TimeRangePicker value={range} onChange={setRange} />
      </header>
      {error && <div className="soc-alert">{error}</div>}
      <section className="soc-metrics-grid">
        <div className="metric-card"><span>Total</span><strong>{metrics?.total ?? items.length}</strong></div>
        <div className="metric-card"><span>Critical</span><strong>{criticalCount}</strong></div>
        <div className="metric-card"><span>Open</span><strong>{metrics?.open ?? 0}</strong></div>
        <div className="metric-card"><span>MTTR</span><strong>{metrics?.mttrMinutes ?? '—'}m</strong></div>
      </section>
      <section className="soc-section"><h2>Policies</h2><SecurityPoliciesChart data={metrics?.series ?? []} section="Policies" /></section>
      <section className="soc-section"><h2>Baselines</h2><SecurityPoliciesChart data={metrics?.series ?? []} section="Baselines" /></section>
      <section className="soc-section"><h2>Exceptions</h2><SecurityPoliciesChart data={metrics?.series ?? []} section="Exceptions" /></section>
      <section className="soc-section"><h2>Drift</h2><SecurityPoliciesChart data={metrics?.series ?? []} section="Drift" /></section>
      <section className="soc-toolbar">
        <input type="search" placeholder="Search Security Policies..." value={filter.query} onChange={e => setFilter(f => ({ ...f, query: e.target.value, page: 1 }))} />
        {canWrite && <button type="button" onClick={() => onBulk('acknowledge')}>Acknowledge</button>}
        {canWrite && <button type="button" onClick={() => navigate('/security-policies/new')}>Create</button>}
      </section>
      {loading ? <div className="soc-loading">Loading…</div> : (
        <SecurityPoliciesTable items={items} selectedIds={selectedIds} onSelect={setSelectedIds}
          onRowClick={id => navigate(`/security-policies/${id}`)} renderSeverity={s => <SeverityBadge level={s} />} />
      )}
      <footer><span>{user?.displayName}</span><span>{tenantId}</span></footer>
    </div>
  );
};
export default SecurityPoliciesPage;

export const SecurityPoliciesWidget00: React.FC<{ seed?: number }> = ({ seed = 0 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-policies-widget-00"><h4>Security Policies Widget 00</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityPoliciesWidget01: React.FC<{ seed?: number }> = ({ seed = 1 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-policies-widget-01"><h4>Security Policies Widget 01</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityPoliciesWidget02: React.FC<{ seed?: number }> = ({ seed = 2 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-policies-widget-02"><h4>Security Policies Widget 02</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityPoliciesWidget03: React.FC<{ seed?: number }> = ({ seed = 3 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-policies-widget-03"><h4>Security Policies Widget 03</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityPoliciesWidget04: React.FC<{ seed?: number }> = ({ seed = 4 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-policies-widget-04"><h4>Security Policies Widget 04</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityPoliciesWidget05: React.FC<{ seed?: number }> = ({ seed = 5 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-policies-widget-05"><h4>Security Policies Widget 05</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityPoliciesWidget06: React.FC<{ seed?: number }> = ({ seed = 6 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-policies-widget-06"><h4>Security Policies Widget 06</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityPoliciesWidget07: React.FC<{ seed?: number }> = ({ seed = 7 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-policies-widget-07"><h4>Security Policies Widget 07</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityPoliciesWidget08: React.FC<{ seed?: number }> = ({ seed = 8 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-policies-widget-08"><h4>Security Policies Widget 08</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityPoliciesWidget09: React.FC<{ seed?: number }> = ({ seed = 9 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-policies-widget-09"><h4>Security Policies Widget 09</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityPoliciesWidget10: React.FC<{ seed?: number }> = ({ seed = 10 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-policies-widget-10"><h4>Security Policies Widget 10</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityPoliciesWidget11: React.FC<{ seed?: number }> = ({ seed = 11 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-policies-widget-11"><h4>Security Policies Widget 11</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityPoliciesWidget12: React.FC<{ seed?: number }> = ({ seed = 12 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-policies-widget-12"><h4>Security Policies Widget 12</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityPoliciesWidget13: React.FC<{ seed?: number }> = ({ seed = 13 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-policies-widget-13"><h4>Security Policies Widget 13</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityPoliciesWidget14: React.FC<{ seed?: number }> = ({ seed = 14 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-policies-widget-14"><h4>Security Policies Widget 14</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityPoliciesWidget15: React.FC<{ seed?: number }> = ({ seed = 15 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-policies-widget-15"><h4>Security Policies Widget 15</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityPoliciesWidget16: React.FC<{ seed?: number }> = ({ seed = 16 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-policies-widget-16"><h4>Security Policies Widget 16</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityPoliciesWidget17: React.FC<{ seed?: number }> = ({ seed = 17 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-policies-widget-17"><h4>Security Policies Widget 17</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityPoliciesWidget18: React.FC<{ seed?: number }> = ({ seed = 18 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-policies-widget-18"><h4>Security Policies Widget 18</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityPoliciesWidget19: React.FC<{ seed?: number }> = ({ seed = 19 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-policies-widget-19"><h4>Security Policies Widget 19</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityPoliciesWidget20: React.FC<{ seed?: number }> = ({ seed = 20 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-policies-widget-20"><h4>Security Policies Widget 20</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityPoliciesWidget21: React.FC<{ seed?: number }> = ({ seed = 21 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-policies-widget-21"><h4>Security Policies Widget 21</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityPoliciesWidget22: React.FC<{ seed?: number }> = ({ seed = 22 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-policies-widget-22"><h4>Security Policies Widget 22</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityPoliciesWidget23: React.FC<{ seed?: number }> = ({ seed = 23 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-policies-widget-23"><h4>Security Policies Widget 23</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityPoliciesWidget24: React.FC<{ seed?: number }> = ({ seed = 24 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-policies-widget-24"><h4>Security Policies Widget 24</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityPoliciesWidget25: React.FC<{ seed?: number }> = ({ seed = 25 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-policies-widget-25"><h4>Security Policies Widget 25</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityPoliciesWidget26: React.FC<{ seed?: number }> = ({ seed = 26 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-policies-widget-26"><h4>Security Policies Widget 26</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SecurityPoliciesWidget27: React.FC<{ seed?: number }> = ({ seed = 27 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="security-policies-widget-27"><h4>Security Policies Widget 27</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};
