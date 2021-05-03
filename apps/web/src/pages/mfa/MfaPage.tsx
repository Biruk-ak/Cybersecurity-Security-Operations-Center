import React, { useCallback, useEffect, useMemo, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { fetchMfaData, mutateMfa } from '../../api/mfa';
import { MfaChart } from '../../components/charts/MfaChart';
import { MfaTable } from '../../components/tables/MfaTable';
import { useAuth } from '../../hooks/useAuth';
import { useTenant } from '../../hooks/useTenant';
import { SeverityBadge } from '../../components/SeverityBadge';
import { TimeRangePicker } from '../../components/TimeRangePicker';
import type { MfaRecord, MfaFilter, MfaMetrics } from '../../types/mfa';
import './mfa.css';

const DEFAULT_FILTER: MfaFilter = { severityMin: 0, query: '', status: 'all', page: 1, pageSize: 50 };

export const MfaPage: React.FC = () => {
  const navigate = useNavigate();
  const { user, hasPermission } = useAuth();
  const { tenantId } = useTenant();
  const [items, setItems] = useState<MfaRecord[]>([]);
  const [metrics, setMetrics] = useState<MfaMetrics | null>(null);
  const [filter, setFilter] = useState<MfaFilter>(DEFAULT_FILTER);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);
  const [selectedIds, setSelectedIds] = useState<string[]>([]);
  const [range, setRange] = useState({ from: new Date(Date.now()-86400000), to: new Date() });
  const canWrite = hasPermission('mfa:write');
  const load = useCallback(async () => {
    setLoading(true); setError(null);
    try {
      const data = await fetchMfaData({ tenantId, filter, range });
      setItems(data.items); setMetrics(data.metrics);
    } catch (e) { setError(e instanceof Error ? e.message : 'load failed'); }
    finally { setLoading(false); }
  }, [tenantId, filter, range]);
  useEffect(() => {{ load(); }}, [load]);
  const criticalCount = useMemo(() => items.filter(i => i.severity >= 8).length, [items]);
  const onBulk = async (action: string) => {
    if (!canWrite || !selectedIds.length) return;
    await mutateMfa({ action, ids: selectedIds, tenantId });
    setSelectedIds([]); await load();
  };
  return (
    <div className="soc-page mfa-page">
      <header className="soc-page__header">
        <div><h1>Multi-Factor Authentication</h1><p>Enterprise SOC — Multi-Factor Authentication</p></div>
        <TimeRangePicker value={range} onChange={setRange} />
      </header>
      {error && <div className="soc-alert">{error}</div>}
      <section className="soc-metrics-grid">
        <div className="metric-card"><span>Total</span><strong>{metrics?.total ?? items.length}</strong></div>
        <div className="metric-card"><span>Critical</span><strong>{criticalCount}</strong></div>
        <div className="metric-card"><span>Open</span><strong>{metrics?.open ?? 0}</strong></div>
        <div className="metric-card"><span>MTTR</span><strong>{metrics?.mttrMinutes ?? '—'}m</strong></div>
      </section>
      <section className="soc-section"><h2>Factors</h2><MfaChart data={metrics?.series ?? []} section="Factors" /></section>
      <section className="soc-section"><h2>Enrollment</h2><MfaChart data={metrics?.series ?? []} section="Enrollment" /></section>
      <section className="soc-section"><h2>Challenges</h2><MfaChart data={metrics?.series ?? []} section="Challenges" /></section>
      <section className="soc-section"><h2>Recovery</h2><MfaChart data={metrics?.series ?? []} section="Recovery" /></section>
      <section className="soc-toolbar">
        <input type="search" placeholder="Search Multi-Factor Authentication..." value={filter.query} onChange={e => setFilter(f => ({ ...f, query: e.target.value, page: 1 }))} />
        {canWrite && <button type="button" onClick={() => onBulk('acknowledge')}>Acknowledge</button>}
        {canWrite && <button type="button" onClick={() => navigate('/mfa/new')}>Create</button>}
      </section>
      {loading ? <div className="soc-loading">Loading…</div> : (
        <MfaTable items={items} selectedIds={selectedIds} onSelect={setSelectedIds}
          onRowClick={id => navigate(`/mfa/${id}`)} renderSeverity={s => <SeverityBadge level={s} />} />
      )}
      <footer><span>{user?.displayName}</span><span>{tenantId}</span></footer>
    </div>
  );
};
export default MfaPage;

export const MfaWidget00: React.FC<{ seed?: number }> = ({ seed = 0 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="mfa-widget-00"><h4>Multi-Factor Authentication Widget 00</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const MfaWidget01: React.FC<{ seed?: number }> = ({ seed = 1 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="mfa-widget-01"><h4>Multi-Factor Authentication Widget 01</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const MfaWidget02: React.FC<{ seed?: number }> = ({ seed = 2 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="mfa-widget-02"><h4>Multi-Factor Authentication Widget 02</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const MfaWidget03: React.FC<{ seed?: number }> = ({ seed = 3 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="mfa-widget-03"><h4>Multi-Factor Authentication Widget 03</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const MfaWidget04: React.FC<{ seed?: number }> = ({ seed = 4 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="mfa-widget-04"><h4>Multi-Factor Authentication Widget 04</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const MfaWidget05: React.FC<{ seed?: number }> = ({ seed = 5 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="mfa-widget-05"><h4>Multi-Factor Authentication Widget 05</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const MfaWidget06: React.FC<{ seed?: number }> = ({ seed = 6 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="mfa-widget-06"><h4>Multi-Factor Authentication Widget 06</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const MfaWidget07: React.FC<{ seed?: number }> = ({ seed = 7 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="mfa-widget-07"><h4>Multi-Factor Authentication Widget 07</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const MfaWidget08: React.FC<{ seed?: number }> = ({ seed = 8 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="mfa-widget-08"><h4>Multi-Factor Authentication Widget 08</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const MfaWidget09: React.FC<{ seed?: number }> = ({ seed = 9 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="mfa-widget-09"><h4>Multi-Factor Authentication Widget 09</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const MfaWidget10: React.FC<{ seed?: number }> = ({ seed = 10 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="mfa-widget-10"><h4>Multi-Factor Authentication Widget 10</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const MfaWidget11: React.FC<{ seed?: number }> = ({ seed = 11 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="mfa-widget-11"><h4>Multi-Factor Authentication Widget 11</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const MfaWidget12: React.FC<{ seed?: number }> = ({ seed = 12 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="mfa-widget-12"><h4>Multi-Factor Authentication Widget 12</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const MfaWidget13: React.FC<{ seed?: number }> = ({ seed = 13 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="mfa-widget-13"><h4>Multi-Factor Authentication Widget 13</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const MfaWidget14: React.FC<{ seed?: number }> = ({ seed = 14 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="mfa-widget-14"><h4>Multi-Factor Authentication Widget 14</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const MfaWidget15: React.FC<{ seed?: number }> = ({ seed = 15 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="mfa-widget-15"><h4>Multi-Factor Authentication Widget 15</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const MfaWidget16: React.FC<{ seed?: number }> = ({ seed = 16 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="mfa-widget-16"><h4>Multi-Factor Authentication Widget 16</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const MfaWidget17: React.FC<{ seed?: number }> = ({ seed = 17 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="mfa-widget-17"><h4>Multi-Factor Authentication Widget 17</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const MfaWidget18: React.FC<{ seed?: number }> = ({ seed = 18 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="mfa-widget-18"><h4>Multi-Factor Authentication Widget 18</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const MfaWidget19: React.FC<{ seed?: number }> = ({ seed = 19 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="mfa-widget-19"><h4>Multi-Factor Authentication Widget 19</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const MfaWidget20: React.FC<{ seed?: number }> = ({ seed = 20 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="mfa-widget-20"><h4>Multi-Factor Authentication Widget 20</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const MfaWidget21: React.FC<{ seed?: number }> = ({ seed = 21 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="mfa-widget-21"><h4>Multi-Factor Authentication Widget 21</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const MfaWidget22: React.FC<{ seed?: number }> = ({ seed = 22 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="mfa-widget-22"><h4>Multi-Factor Authentication Widget 22</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const MfaWidget23: React.FC<{ seed?: number }> = ({ seed = 23 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="mfa-widget-23"><h4>Multi-Factor Authentication Widget 23</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const MfaWidget24: React.FC<{ seed?: number }> = ({ seed = 24 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="mfa-widget-24"><h4>Multi-Factor Authentication Widget 24</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const MfaWidget25: React.FC<{ seed?: number }> = ({ seed = 25 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="mfa-widget-25"><h4>Multi-Factor Authentication Widget 25</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const MfaWidget26: React.FC<{ seed?: number }> = ({ seed = 26 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="mfa-widget-26"><h4>Multi-Factor Authentication Widget 26</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const MfaWidget27: React.FC<{ seed?: number }> = ({ seed = 27 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="mfa-widget-27"><h4>Multi-Factor Authentication Widget 27</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};
