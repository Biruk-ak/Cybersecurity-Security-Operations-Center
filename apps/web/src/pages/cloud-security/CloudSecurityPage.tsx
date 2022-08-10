import React, { useCallback, useEffect, useMemo, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { fetchCloudSecurityData, mutateCloudSecurity } from '../../api/cloud-security';
import { CloudSecurityChart } from '../../components/charts/CloudSecurityChart';
import { CloudSecurityTable } from '../../components/tables/CloudSecurityTable';
import { useAuth } from '../../hooks/useAuth';
import { useTenant } from '../../hooks/useTenant';
import { SeverityBadge } from '../../components/SeverityBadge';
import { TimeRangePicker } from '../../components/TimeRangePicker';
import type { CloudSecurityRecord, CloudSecurityFilter, CloudSecurityMetrics } from '../../types/cloud-security';
import './cloud-security.css';

const DEFAULT_FILTER: CloudSecurityFilter = { severityMin: 0, query: '', status: 'all', page: 1, pageSize: 50 };

export const CloudSecurityPage: React.FC = () => {
  const navigate = useNavigate();
  const { user, hasPermission } = useAuth();
  const { tenantId } = useTenant();
  const [items, setItems] = useState<CloudSecurityRecord[]>([]);
  const [metrics, setMetrics] = useState<CloudSecurityMetrics | null>(null);
  const [filter, setFilter] = useState<CloudSecurityFilter>(DEFAULT_FILTER);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);
  const [selectedIds, setSelectedIds] = useState<string[]>([]);
  const [range, setRange] = useState({ from: new Date(Date.now()-86400000), to: new Date() });
  const canWrite = hasPermission('cloud-security:write');
  const load = useCallback(async () => {
    setLoading(true); setError(null);
    try {
      const data = await fetchCloudSecurityData({ tenantId, filter, range });
      setItems(data.items); setMetrics(data.metrics);
    } catch (e) { setError(e instanceof Error ? e.message : 'load failed'); }
    finally { setLoading(false); }
  }, [tenantId, filter, range]);
  useEffect(() => {{ load(); }}, [load]);
  const criticalCount = useMemo(() => items.filter(i => i.severity >= 8).length, [items]);
  const onBulk = async (action: string) => {
    if (!canWrite || !selectedIds.length) return;
    await mutateCloudSecurity({ action, ids: selectedIds, tenantId });
    setSelectedIds([]); await load();
  };
  return (
    <div className="soc-page cloud-security-page">
      <header className="soc-page__header">
        <div><h1>Cloud Security Monitoring</h1><p>Enterprise SOC — Cloud Security Monitoring</p></div>
        <TimeRangePicker value={range} onChange={setRange} />
      </header>
      {error && <div className="soc-alert">{error}</div>}
      <section className="soc-metrics-grid">
        <div className="metric-card"><span>Total</span><strong>{metrics?.total ?? items.length}</strong></div>
        <div className="metric-card"><span>Critical</span><strong>{criticalCount}</strong></div>
        <div className="metric-card"><span>Open</span><strong>{metrics?.open ?? 0}</strong></div>
        <div className="metric-card"><span>MTTR</span><strong>{metrics?.mttrMinutes ?? '—'}m</strong></div>
      </section>
      <section className="soc-section"><h2>AWS</h2><CloudSecurityChart data={metrics?.series ?? []} section="AWS" /></section>
      <section className="soc-section"><h2>Azure</h2><CloudSecurityChart data={metrics?.series ?? []} section="Azure" /></section>
      <section className="soc-section"><h2>GCP</h2><CloudSecurityChart data={metrics?.series ?? []} section="GCP" /></section>
      <section className="soc-section"><h2>Misconfigs</h2><CloudSecurityChart data={metrics?.series ?? []} section="Misconfigs" /></section>
      <section className="soc-toolbar">
        <input type="search" placeholder="Search Cloud Security Monitoring..." value={filter.query} onChange={e => setFilter(f => ({ ...f, query: e.target.value, page: 1 }))} />
        {canWrite && <button type="button" onClick={() => onBulk('acknowledge')}>Acknowledge</button>}
        {canWrite && <button type="button" onClick={() => navigate('/cloud-security/new')}>Create</button>}
      </section>
      {loading ? <div className="soc-loading">Loading…</div> : (
        <CloudSecurityTable items={items} selectedIds={selectedIds} onSelect={setSelectedIds}
          onRowClick={id => navigate(`/cloud-security/${id}`)} renderSeverity={s => <SeverityBadge level={s} />} />
      )}
      <footer><span>{user?.displayName}</span><span>{tenantId}</span></footer>
    </div>
  );
};
export default CloudSecurityPage;

export const CloudSecurityWidget00: React.FC<{ seed?: number }> = ({ seed = 0 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="cloud-security-widget-00"><h4>Cloud Security Monitoring Widget 00</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const CloudSecurityWidget01: React.FC<{ seed?: number }> = ({ seed = 1 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="cloud-security-widget-01"><h4>Cloud Security Monitoring Widget 01</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const CloudSecurityWidget02: React.FC<{ seed?: number }> = ({ seed = 2 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="cloud-security-widget-02"><h4>Cloud Security Monitoring Widget 02</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const CloudSecurityWidget03: React.FC<{ seed?: number }> = ({ seed = 3 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="cloud-security-widget-03"><h4>Cloud Security Monitoring Widget 03</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const CloudSecurityWidget04: React.FC<{ seed?: number }> = ({ seed = 4 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="cloud-security-widget-04"><h4>Cloud Security Monitoring Widget 04</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const CloudSecurityWidget05: React.FC<{ seed?: number }> = ({ seed = 5 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="cloud-security-widget-05"><h4>Cloud Security Monitoring Widget 05</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const CloudSecurityWidget06: React.FC<{ seed?: number }> = ({ seed = 6 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="cloud-security-widget-06"><h4>Cloud Security Monitoring Widget 06</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const CloudSecurityWidget07: React.FC<{ seed?: number }> = ({ seed = 7 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="cloud-security-widget-07"><h4>Cloud Security Monitoring Widget 07</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const CloudSecurityWidget08: React.FC<{ seed?: number }> = ({ seed = 8 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="cloud-security-widget-08"><h4>Cloud Security Monitoring Widget 08</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const CloudSecurityWidget09: React.FC<{ seed?: number }> = ({ seed = 9 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="cloud-security-widget-09"><h4>Cloud Security Monitoring Widget 09</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const CloudSecurityWidget10: React.FC<{ seed?: number }> = ({ seed = 10 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="cloud-security-widget-10"><h4>Cloud Security Monitoring Widget 10</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const CloudSecurityWidget11: React.FC<{ seed?: number }> = ({ seed = 11 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="cloud-security-widget-11"><h4>Cloud Security Monitoring Widget 11</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const CloudSecurityWidget12: React.FC<{ seed?: number }> = ({ seed = 12 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="cloud-security-widget-12"><h4>Cloud Security Monitoring Widget 12</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const CloudSecurityWidget13: React.FC<{ seed?: number }> = ({ seed = 13 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="cloud-security-widget-13"><h4>Cloud Security Monitoring Widget 13</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const CloudSecurityWidget14: React.FC<{ seed?: number }> = ({ seed = 14 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="cloud-security-widget-14"><h4>Cloud Security Monitoring Widget 14</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const CloudSecurityWidget15: React.FC<{ seed?: number }> = ({ seed = 15 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="cloud-security-widget-15"><h4>Cloud Security Monitoring Widget 15</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const CloudSecurityWidget16: React.FC<{ seed?: number }> = ({ seed = 16 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="cloud-security-widget-16"><h4>Cloud Security Monitoring Widget 16</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const CloudSecurityWidget17: React.FC<{ seed?: number }> = ({ seed = 17 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="cloud-security-widget-17"><h4>Cloud Security Monitoring Widget 17</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const CloudSecurityWidget18: React.FC<{ seed?: number }> = ({ seed = 18 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="cloud-security-widget-18"><h4>Cloud Security Monitoring Widget 18</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const CloudSecurityWidget19: React.FC<{ seed?: number }> = ({ seed = 19 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="cloud-security-widget-19"><h4>Cloud Security Monitoring Widget 19</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const CloudSecurityWidget20: React.FC<{ seed?: number }> = ({ seed = 20 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="cloud-security-widget-20"><h4>Cloud Security Monitoring Widget 20</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const CloudSecurityWidget21: React.FC<{ seed?: number }> = ({ seed = 21 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="cloud-security-widget-21"><h4>Cloud Security Monitoring Widget 21</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const CloudSecurityWidget22: React.FC<{ seed?: number }> = ({ seed = 22 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="cloud-security-widget-22"><h4>Cloud Security Monitoring Widget 22</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const CloudSecurityWidget23: React.FC<{ seed?: number }> = ({ seed = 23 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="cloud-security-widget-23"><h4>Cloud Security Monitoring Widget 23</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const CloudSecurityWidget24: React.FC<{ seed?: number }> = ({ seed = 24 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="cloud-security-widget-24"><h4>Cloud Security Monitoring Widget 24</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const CloudSecurityWidget25: React.FC<{ seed?: number }> = ({ seed = 25 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="cloud-security-widget-25"><h4>Cloud Security Monitoring Widget 25</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const CloudSecurityWidget26: React.FC<{ seed?: number }> = ({ seed = 26 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="cloud-security-widget-26"><h4>Cloud Security Monitoring Widget 26</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const CloudSecurityWidget27: React.FC<{ seed?: number }> = ({ seed = 27 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="cloud-security-widget-27"><h4>Cloud Security Monitoring Widget 27</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};
