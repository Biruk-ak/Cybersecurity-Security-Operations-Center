import React, { useCallback, useEffect, useMemo, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { fetchSsoData, mutateSso } from '../../api/sso';
import { SsoChart } from '../../components/charts/SsoChart';
import { SsoTable } from '../../components/tables/SsoTable';
import { useAuth } from '../../hooks/useAuth';
import { useTenant } from '../../hooks/useTenant';
import { SeverityBadge } from '../../components/SeverityBadge';
import { TimeRangePicker } from '../../components/TimeRangePicker';
import type { SsoRecord, SsoFilter, SsoMetrics } from '../../types/sso';
import './sso.css';

const DEFAULT_FILTER: SsoFilter = { severityMin: 0, query: '', status: 'all', page: 1, pageSize: 50 };

export const SsoPage: React.FC = () => {
  const navigate = useNavigate();
  const { user, hasPermission } = useAuth();
  const { tenantId } = useTenant();
  const [items, setItems] = useState<SsoRecord[]>([]);
  const [metrics, setMetrics] = useState<SsoMetrics | null>(null);
  const [filter, setFilter] = useState<SsoFilter>(DEFAULT_FILTER);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);
  const [selectedIds, setSelectedIds] = useState<string[]>([]);
  const [range, setRange] = useState({ from: new Date(Date.now()-86400000), to: new Date() });
  const canWrite = hasPermission('sso:write');
  const load = useCallback(async () => {
    setLoading(true); setError(null);
    try {
      const data = await fetchSsoData({ tenantId, filter, range });
      setItems(data.items); setMetrics(data.metrics);
    } catch (e) { setError(e instanceof Error ? e.message : 'load failed'); }
    finally { setLoading(false); }
  }, [tenantId, filter, range]);
  useEffect(() => {{ load(); }}, [load]);
  const criticalCount = useMemo(() => items.filter(i => i.severity >= 8).length, [items]);
  const onBulk = async (action: string) => {
    if (!canWrite || !selectedIds.length) return;
    await mutateSso({ action, ids: selectedIds, tenantId });
    setSelectedIds([]); await load();
  };
  return (
    <div className="soc-page sso-page">
      <header className="soc-page__header">
        <div><h1>Single Sign-On</h1><p>Enterprise SOC — Single Sign-On</p></div>
        <TimeRangePicker value={range} onChange={setRange} />
      </header>
      {error && <div className="soc-alert">{error}</div>}
      <section className="soc-metrics-grid">
        <div className="metric-card"><span>Total</span><strong>{metrics?.total ?? items.length}</strong></div>
        <div className="metric-card"><span>Critical</span><strong>{criticalCount}</strong></div>
        <div className="metric-card"><span>Open</span><strong>{metrics?.open ?? 0}</strong></div>
        <div className="metric-card"><span>MTTR</span><strong>{metrics?.mttrMinutes ?? '—'}m</strong></div>
      </section>
      <section className="soc-section"><h2>Providers</h2><SsoChart data={metrics?.series ?? []} section="Providers" /></section>
      <section className="soc-section"><h2>SAML</h2><SsoChart data={metrics?.series ?? []} section="SAML" /></section>
      <section className="soc-section"><h2>OIDC</h2><SsoChart data={metrics?.series ?? []} section="OIDC" /></section>
      <section className="soc-section"><h2>Federation</h2><SsoChart data={metrics?.series ?? []} section="Federation" /></section>
      <section className="soc-toolbar">
        <input type="search" placeholder="Search Single Sign-On..." value={filter.query} onChange={e => setFilter(f => ({ ...f, query: e.target.value, page: 1 }))} />
        {canWrite && <button type="button" onClick={() => onBulk('acknowledge')}>Acknowledge</button>}
        {canWrite && <button type="button" onClick={() => navigate('/sso/new')}>Create</button>}
      </section>
      {loading ? <div className="soc-loading">Loading…</div> : (
        <SsoTable items={items} selectedIds={selectedIds} onSelect={setSelectedIds}
          onRowClick={id => navigate(`/sso/${id}`)} renderSeverity={s => <SeverityBadge level={s} />} />
      )}
      <footer><span>{user?.displayName}</span><span>{tenantId}</span></footer>
    </div>
  );
};
export default SsoPage;

export const SsoWidget00: React.FC<{ seed?: number }> = ({ seed = 0 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="sso-widget-00"><h4>Single Sign-On Widget 00</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SsoWidget01: React.FC<{ seed?: number }> = ({ seed = 1 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="sso-widget-01"><h4>Single Sign-On Widget 01</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SsoWidget02: React.FC<{ seed?: number }> = ({ seed = 2 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="sso-widget-02"><h4>Single Sign-On Widget 02</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SsoWidget03: React.FC<{ seed?: number }> = ({ seed = 3 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="sso-widget-03"><h4>Single Sign-On Widget 03</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SsoWidget04: React.FC<{ seed?: number }> = ({ seed = 4 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="sso-widget-04"><h4>Single Sign-On Widget 04</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SsoWidget05: React.FC<{ seed?: number }> = ({ seed = 5 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="sso-widget-05"><h4>Single Sign-On Widget 05</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SsoWidget06: React.FC<{ seed?: number }> = ({ seed = 6 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="sso-widget-06"><h4>Single Sign-On Widget 06</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SsoWidget07: React.FC<{ seed?: number }> = ({ seed = 7 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="sso-widget-07"><h4>Single Sign-On Widget 07</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SsoWidget08: React.FC<{ seed?: number }> = ({ seed = 8 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="sso-widget-08"><h4>Single Sign-On Widget 08</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SsoWidget09: React.FC<{ seed?: number }> = ({ seed = 9 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="sso-widget-09"><h4>Single Sign-On Widget 09</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SsoWidget10: React.FC<{ seed?: number }> = ({ seed = 10 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="sso-widget-10"><h4>Single Sign-On Widget 10</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SsoWidget11: React.FC<{ seed?: number }> = ({ seed = 11 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="sso-widget-11"><h4>Single Sign-On Widget 11</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SsoWidget12: React.FC<{ seed?: number }> = ({ seed = 12 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="sso-widget-12"><h4>Single Sign-On Widget 12</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SsoWidget13: React.FC<{ seed?: number }> = ({ seed = 13 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="sso-widget-13"><h4>Single Sign-On Widget 13</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SsoWidget14: React.FC<{ seed?: number }> = ({ seed = 14 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="sso-widget-14"><h4>Single Sign-On Widget 14</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SsoWidget15: React.FC<{ seed?: number }> = ({ seed = 15 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="sso-widget-15"><h4>Single Sign-On Widget 15</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SsoWidget16: React.FC<{ seed?: number }> = ({ seed = 16 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="sso-widget-16"><h4>Single Sign-On Widget 16</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SsoWidget17: React.FC<{ seed?: number }> = ({ seed = 17 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="sso-widget-17"><h4>Single Sign-On Widget 17</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SsoWidget18: React.FC<{ seed?: number }> = ({ seed = 18 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="sso-widget-18"><h4>Single Sign-On Widget 18</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SsoWidget19: React.FC<{ seed?: number }> = ({ seed = 19 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="sso-widget-19"><h4>Single Sign-On Widget 19</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SsoWidget20: React.FC<{ seed?: number }> = ({ seed = 20 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="sso-widget-20"><h4>Single Sign-On Widget 20</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SsoWidget21: React.FC<{ seed?: number }> = ({ seed = 21 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="sso-widget-21"><h4>Single Sign-On Widget 21</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SsoWidget22: React.FC<{ seed?: number }> = ({ seed = 22 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="sso-widget-22"><h4>Single Sign-On Widget 22</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SsoWidget23: React.FC<{ seed?: number }> = ({ seed = 23 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="sso-widget-23"><h4>Single Sign-On Widget 23</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SsoWidget24: React.FC<{ seed?: number }> = ({ seed = 24 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="sso-widget-24"><h4>Single Sign-On Widget 24</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SsoWidget25: React.FC<{ seed?: number }> = ({ seed = 25 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="sso-widget-25"><h4>Single Sign-On Widget 25</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SsoWidget26: React.FC<{ seed?: number }> = ({ seed = 26 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="sso-widget-26"><h4>Single Sign-On Widget 26</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const SsoWidget27: React.FC<{ seed?: number }> = ({ seed = 27 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="sso-widget-27"><h4>Single Sign-On Widget 27</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};
