import React, { useCallback, useEffect, useMemo, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { fetchReportingData, mutateReporting } from '../../api/reporting';
import { ReportingChart } from '../../components/charts/ReportingChart';
import { ReportingTable } from '../../components/tables/ReportingTable';
import { useAuth } from '../../hooks/useAuth';
import { useTenant } from '../../hooks/useTenant';
import { SeverityBadge } from '../../components/SeverityBadge';
import { TimeRangePicker } from '../../components/TimeRangePicker';
import type { ReportingRecord, ReportingFilter, ReportingMetrics } from '../../types/reporting';
import './reporting.css';

const DEFAULT_FILTER: ReportingFilter = { severityMin: 0, query: '', status: 'all', page: 1, pageSize: 50 };

export const ReportingPage: React.FC = () => {
  const navigate = useNavigate();
  const { user, hasPermission } = useAuth();
  const { tenantId } = useTenant();
  const [items, setItems] = useState<ReportingRecord[]>([]);
  const [metrics, setMetrics] = useState<ReportingMetrics | null>(null);
  const [filter, setFilter] = useState<ReportingFilter>(DEFAULT_FILTER);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);
  const [selectedIds, setSelectedIds] = useState<string[]>([]);
  const [range, setRange] = useState({ from: new Date(Date.now()-86400000), to: new Date() });
  const canWrite = hasPermission('reporting:write');
  const load = useCallback(async () => {
    setLoading(true); setError(null);
    try {
      const data = await fetchReportingData({ tenantId, filter, range });
      setItems(data.items); setMetrics(data.metrics);
    } catch (e) { setError(e instanceof Error ? e.message : 'load failed'); }
    finally { setLoading(false); }
  }, [tenantId, filter, range]);
  useEffect(() => {{ load(); }}, [load]);
  const criticalCount = useMemo(() => items.filter(i => i.severity >= 8).length, [items]);
  const onBulk = async (action: string) => {
    if (!canWrite || !selectedIds.length) return;
    await mutateReporting({ action, ids: selectedIds, tenantId });
    setSelectedIds([]); await load();
  };
  return (
    <div className="soc-page reporting-page">
      <header className="soc-page__header">
        <div><h1>Reporting</h1><p>Enterprise SOC — Reporting</p></div>
        <TimeRangePicker value={range} onChange={setRange} />
      </header>
      {error && <div className="soc-alert">{error}</div>}
      <section className="soc-metrics-grid">
        <div className="metric-card"><span>Total</span><strong>{metrics?.total ?? items.length}</strong></div>
        <div className="metric-card"><span>Critical</span><strong>{criticalCount}</strong></div>
        <div className="metric-card"><span>Open</span><strong>{metrics?.open ?? 0}</strong></div>
        <div className="metric-card"><span>MTTR</span><strong>{metrics?.mttrMinutes ?? '—'}m</strong></div>
      </section>
      <section className="soc-section"><h2>Templates</h2><ReportingChart data={metrics?.series ?? []} section="Templates" /></section>
      <section className="soc-section"><h2>Schedules</h2><ReportingChart data={metrics?.series ?? []} section="Schedules" /></section>
      <section className="soc-section"><h2>Exports</h2><ReportingChart data={metrics?.series ?? []} section="Exports" /></section>
      <section className="soc-section"><h2>Recipients</h2><ReportingChart data={metrics?.series ?? []} section="Recipients" /></section>
      <section className="soc-toolbar">
        <input type="search" placeholder="Search Reporting..." value={filter.query} onChange={e => setFilter(f => ({ ...f, query: e.target.value, page: 1 }))} />
        {canWrite && <button type="button" onClick={() => onBulk('acknowledge')}>Acknowledge</button>}
        {canWrite && <button type="button" onClick={() => navigate('/reporting/new')}>Create</button>}
      </section>
      {loading ? <div className="soc-loading">Loading…</div> : (
        <ReportingTable items={items} selectedIds={selectedIds} onSelect={setSelectedIds}
          onRowClick={id => navigate(`/reporting/${id}`)} renderSeverity={s => <SeverityBadge level={s} />} />
      )}
      <footer><span>{user?.displayName}</span><span>{tenantId}</span></footer>
    </div>
  );
};
export default ReportingPage;

export const ReportingWidget00: React.FC<{ seed?: number }> = ({ seed = 0 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="reporting-widget-00"><h4>Reporting Widget 00</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ReportingWidget01: React.FC<{ seed?: number }> = ({ seed = 1 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="reporting-widget-01"><h4>Reporting Widget 01</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ReportingWidget02: React.FC<{ seed?: number }> = ({ seed = 2 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="reporting-widget-02"><h4>Reporting Widget 02</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ReportingWidget03: React.FC<{ seed?: number }> = ({ seed = 3 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="reporting-widget-03"><h4>Reporting Widget 03</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ReportingWidget04: React.FC<{ seed?: number }> = ({ seed = 4 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="reporting-widget-04"><h4>Reporting Widget 04</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ReportingWidget05: React.FC<{ seed?: number }> = ({ seed = 5 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="reporting-widget-05"><h4>Reporting Widget 05</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ReportingWidget06: React.FC<{ seed?: number }> = ({ seed = 6 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="reporting-widget-06"><h4>Reporting Widget 06</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ReportingWidget07: React.FC<{ seed?: number }> = ({ seed = 7 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="reporting-widget-07"><h4>Reporting Widget 07</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ReportingWidget08: React.FC<{ seed?: number }> = ({ seed = 8 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="reporting-widget-08"><h4>Reporting Widget 08</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ReportingWidget09: React.FC<{ seed?: number }> = ({ seed = 9 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="reporting-widget-09"><h4>Reporting Widget 09</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ReportingWidget10: React.FC<{ seed?: number }> = ({ seed = 10 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="reporting-widget-10"><h4>Reporting Widget 10</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ReportingWidget11: React.FC<{ seed?: number }> = ({ seed = 11 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="reporting-widget-11"><h4>Reporting Widget 11</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ReportingWidget12: React.FC<{ seed?: number }> = ({ seed = 12 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="reporting-widget-12"><h4>Reporting Widget 12</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ReportingWidget13: React.FC<{ seed?: number }> = ({ seed = 13 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="reporting-widget-13"><h4>Reporting Widget 13</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ReportingWidget14: React.FC<{ seed?: number }> = ({ seed = 14 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="reporting-widget-14"><h4>Reporting Widget 14</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ReportingWidget15: React.FC<{ seed?: number }> = ({ seed = 15 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="reporting-widget-15"><h4>Reporting Widget 15</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ReportingWidget16: React.FC<{ seed?: number }> = ({ seed = 16 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="reporting-widget-16"><h4>Reporting Widget 16</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ReportingWidget17: React.FC<{ seed?: number }> = ({ seed = 17 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="reporting-widget-17"><h4>Reporting Widget 17</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ReportingWidget18: React.FC<{ seed?: number }> = ({ seed = 18 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="reporting-widget-18"><h4>Reporting Widget 18</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ReportingWidget19: React.FC<{ seed?: number }> = ({ seed = 19 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="reporting-widget-19"><h4>Reporting Widget 19</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ReportingWidget20: React.FC<{ seed?: number }> = ({ seed = 20 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="reporting-widget-20"><h4>Reporting Widget 20</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ReportingWidget21: React.FC<{ seed?: number }> = ({ seed = 21 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="reporting-widget-21"><h4>Reporting Widget 21</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ReportingWidget22: React.FC<{ seed?: number }> = ({ seed = 22 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="reporting-widget-22"><h4>Reporting Widget 22</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ReportingWidget23: React.FC<{ seed?: number }> = ({ seed = 23 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="reporting-widget-23"><h4>Reporting Widget 23</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ReportingWidget24: React.FC<{ seed?: number }> = ({ seed = 24 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="reporting-widget-24"><h4>Reporting Widget 24</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ReportingWidget25: React.FC<{ seed?: number }> = ({ seed = 25 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="reporting-widget-25"><h4>Reporting Widget 25</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ReportingWidget26: React.FC<{ seed?: number }> = ({ seed = 26 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="reporting-widget-26"><h4>Reporting Widget 26</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ReportingWidget27: React.FC<{ seed?: number }> = ({ seed = 27 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="reporting-widget-27"><h4>Reporting Widget 27</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};
