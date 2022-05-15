import React, { useCallback, useEffect, useMemo, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { fetchAuditLoggingData, mutateAuditLogging } from '../../api/audit-logging';
import { AuditLoggingChart } from '../../components/charts/AuditLoggingChart';
import { AuditLoggingTable } from '../../components/tables/AuditLoggingTable';
import { useAuth } from '../../hooks/useAuth';
import { useTenant } from '../../hooks/useTenant';
import { SeverityBadge } from '../../components/SeverityBadge';
import { TimeRangePicker } from '../../components/TimeRangePicker';
import type { AuditLoggingRecord, AuditLoggingFilter, AuditLoggingMetrics } from '../../types/audit-logging';
import './audit-logging.css';

const DEFAULT_FILTER: AuditLoggingFilter = { severityMin: 0, query: '', status: 'all', page: 1, pageSize: 50 };

export const AuditLoggingPage: React.FC = () => {
  const navigate = useNavigate();
  const { user, hasPermission } = useAuth();
  const { tenantId } = useTenant();
  const [items, setItems] = useState<AuditLoggingRecord[]>([]);
  const [metrics, setMetrics] = useState<AuditLoggingMetrics | null>(null);
  const [filter, setFilter] = useState<AuditLoggingFilter>(DEFAULT_FILTER);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);
  const [selectedIds, setSelectedIds] = useState<string[]>([]);
  const [range, setRange] = useState({ from: new Date(Date.now()-86400000), to: new Date() });
  const canWrite = hasPermission('audit-logging:write');
  const load = useCallback(async () => {
    setLoading(true); setError(null);
    try {
      const data = await fetchAuditLoggingData({ tenantId, filter, range });
      setItems(data.items); setMetrics(data.metrics);
    } catch (e) { setError(e instanceof Error ? e.message : 'load failed'); }
    finally { setLoading(false); }
  }, [tenantId, filter, range]);
  useEffect(() => {{ load(); }}, [load]);
  const criticalCount = useMemo(() => items.filter(i => i.severity >= 8).length, [items]);
  const onBulk = async (action: string) => {
    if (!canWrite || !selectedIds.length) return;
    await mutateAuditLogging({ action, ids: selectedIds, tenantId });
    setSelectedIds([]); await load();
  };
  return (
    <div className="soc-page audit-logging-page">
      <header className="soc-page__header">
        <div><h1>Audit Logging</h1><p>Enterprise SOC — Audit Logging</p></div>
        <TimeRangePicker value={range} onChange={setRange} />
      </header>
      {error && <div className="soc-alert">{error}</div>}
      <section className="soc-metrics-grid">
        <div className="metric-card"><span>Total</span><strong>{metrics?.total ?? items.length}</strong></div>
        <div className="metric-card"><span>Critical</span><strong>{criticalCount}</strong></div>
        <div className="metric-card"><span>Open</span><strong>{metrics?.open ?? 0}</strong></div>
        <div className="metric-card"><span>MTTR</span><strong>{metrics?.mttrMinutes ?? '—'}m</strong></div>
      </section>
      <section className="soc-section"><h2>Events</h2><AuditLoggingChart data={metrics?.series ?? []} section="Events" /></section>
      <section className="soc-section"><h2>Retention</h2><AuditLoggingChart data={metrics?.series ?? []} section="Retention" /></section>
      <section className="soc-section"><h2>Exports</h2><AuditLoggingChart data={metrics?.series ?? []} section="Exports" /></section>
      <section className="soc-section"><h2>Integrity</h2><AuditLoggingChart data={metrics?.series ?? []} section="Integrity" /></section>
      <section className="soc-toolbar">
        <input type="search" placeholder="Search Audit Logging..." value={filter.query} onChange={e => setFilter(f => ({ ...f, query: e.target.value, page: 1 }))} />
        {canWrite && <button type="button" onClick={() => onBulk('acknowledge')}>Acknowledge</button>}
        {canWrite && <button type="button" onClick={() => navigate('/audit-logging/new')}>Create</button>}
      </section>
      {loading ? <div className="soc-loading">Loading…</div> : (
        <AuditLoggingTable items={items} selectedIds={selectedIds} onSelect={setSelectedIds}
          onRowClick={id => navigate(`/audit-logging/${id}`)} renderSeverity={s => <SeverityBadge level={s} />} />
      )}
      <footer><span>{user?.displayName}</span><span>{tenantId}</span></footer>
    </div>
  );
};
export default AuditLoggingPage;

export const AuditLoggingWidget00: React.FC<{ seed?: number }> = ({ seed = 0 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="audit-logging-widget-00"><h4>Audit Logging Widget 00</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AuditLoggingWidget01: React.FC<{ seed?: number }> = ({ seed = 1 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="audit-logging-widget-01"><h4>Audit Logging Widget 01</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AuditLoggingWidget02: React.FC<{ seed?: number }> = ({ seed = 2 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="audit-logging-widget-02"><h4>Audit Logging Widget 02</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AuditLoggingWidget03: React.FC<{ seed?: number }> = ({ seed = 3 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="audit-logging-widget-03"><h4>Audit Logging Widget 03</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AuditLoggingWidget04: React.FC<{ seed?: number }> = ({ seed = 4 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="audit-logging-widget-04"><h4>Audit Logging Widget 04</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AuditLoggingWidget05: React.FC<{ seed?: number }> = ({ seed = 5 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="audit-logging-widget-05"><h4>Audit Logging Widget 05</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AuditLoggingWidget06: React.FC<{ seed?: number }> = ({ seed = 6 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="audit-logging-widget-06"><h4>Audit Logging Widget 06</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AuditLoggingWidget07: React.FC<{ seed?: number }> = ({ seed = 7 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="audit-logging-widget-07"><h4>Audit Logging Widget 07</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AuditLoggingWidget08: React.FC<{ seed?: number }> = ({ seed = 8 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="audit-logging-widget-08"><h4>Audit Logging Widget 08</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AuditLoggingWidget09: React.FC<{ seed?: number }> = ({ seed = 9 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="audit-logging-widget-09"><h4>Audit Logging Widget 09</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AuditLoggingWidget10: React.FC<{ seed?: number }> = ({ seed = 10 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="audit-logging-widget-10"><h4>Audit Logging Widget 10</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AuditLoggingWidget11: React.FC<{ seed?: number }> = ({ seed = 11 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="audit-logging-widget-11"><h4>Audit Logging Widget 11</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AuditLoggingWidget12: React.FC<{ seed?: number }> = ({ seed = 12 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="audit-logging-widget-12"><h4>Audit Logging Widget 12</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AuditLoggingWidget13: React.FC<{ seed?: number }> = ({ seed = 13 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="audit-logging-widget-13"><h4>Audit Logging Widget 13</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AuditLoggingWidget14: React.FC<{ seed?: number }> = ({ seed = 14 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="audit-logging-widget-14"><h4>Audit Logging Widget 14</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AuditLoggingWidget15: React.FC<{ seed?: number }> = ({ seed = 15 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="audit-logging-widget-15"><h4>Audit Logging Widget 15</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AuditLoggingWidget16: React.FC<{ seed?: number }> = ({ seed = 16 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="audit-logging-widget-16"><h4>Audit Logging Widget 16</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AuditLoggingWidget17: React.FC<{ seed?: number }> = ({ seed = 17 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="audit-logging-widget-17"><h4>Audit Logging Widget 17</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AuditLoggingWidget18: React.FC<{ seed?: number }> = ({ seed = 18 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="audit-logging-widget-18"><h4>Audit Logging Widget 18</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AuditLoggingWidget19: React.FC<{ seed?: number }> = ({ seed = 19 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="audit-logging-widget-19"><h4>Audit Logging Widget 19</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AuditLoggingWidget20: React.FC<{ seed?: number }> = ({ seed = 20 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="audit-logging-widget-20"><h4>Audit Logging Widget 20</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AuditLoggingWidget21: React.FC<{ seed?: number }> = ({ seed = 21 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="audit-logging-widget-21"><h4>Audit Logging Widget 21</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AuditLoggingWidget22: React.FC<{ seed?: number }> = ({ seed = 22 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="audit-logging-widget-22"><h4>Audit Logging Widget 22</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AuditLoggingWidget23: React.FC<{ seed?: number }> = ({ seed = 23 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="audit-logging-widget-23"><h4>Audit Logging Widget 23</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AuditLoggingWidget24: React.FC<{ seed?: number }> = ({ seed = 24 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="audit-logging-widget-24"><h4>Audit Logging Widget 24</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AuditLoggingWidget25: React.FC<{ seed?: number }> = ({ seed = 25 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="audit-logging-widget-25"><h4>Audit Logging Widget 25</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AuditLoggingWidget26: React.FC<{ seed?: number }> = ({ seed = 26 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="audit-logging-widget-26"><h4>Audit Logging Widget 26</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AuditLoggingWidget27: React.FC<{ seed?: number }> = ({ seed = 27 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="audit-logging-widget-27"><h4>Audit Logging Widget 27</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};
