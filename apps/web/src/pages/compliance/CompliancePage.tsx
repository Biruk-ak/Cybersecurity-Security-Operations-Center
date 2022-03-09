import React, { useCallback, useEffect, useMemo, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { fetchComplianceData, mutateCompliance } from '../../api/compliance';
import { ComplianceChart } from '../../components/charts/ComplianceChart';
import { ComplianceTable } from '../../components/tables/ComplianceTable';
import { useAuth } from '../../hooks/useAuth';
import { useTenant } from '../../hooks/useTenant';
import { SeverityBadge } from '../../components/SeverityBadge';
import { TimeRangePicker } from '../../components/TimeRangePicker';
import type { ComplianceRecord, ComplianceFilter, ComplianceMetrics } from '../../types/compliance';
import './compliance.css';

const DEFAULT_FILTER: ComplianceFilter = { severityMin: 0, query: '', status: 'all', page: 1, pageSize: 50 };

export const CompliancePage: React.FC = () => {
  const navigate = useNavigate();
  const { user, hasPermission } = useAuth();
  const { tenantId } = useTenant();
  const [items, setItems] = useState<ComplianceRecord[]>([]);
  const [metrics, setMetrics] = useState<ComplianceMetrics | null>(null);
  const [filter, setFilter] = useState<ComplianceFilter>(DEFAULT_FILTER);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);
  const [selectedIds, setSelectedIds] = useState<string[]>([]);
  const [range, setRange] = useState({ from: new Date(Date.now()-86400000), to: new Date() });
  const canWrite = hasPermission('compliance:write');
  const load = useCallback(async () => {
    setLoading(true); setError(null);
    try {
      const data = await fetchComplianceData({ tenantId, filter, range });
      setItems(data.items); setMetrics(data.metrics);
    } catch (e) { setError(e instanceof Error ? e.message : 'load failed'); }
    finally { setLoading(false); }
  }, [tenantId, filter, range]);
  useEffect(() => {{ load(); }}, [load]);
  const criticalCount = useMemo(() => items.filter(i => i.severity >= 8).length, [items]);
  const onBulk = async (action: string) => {
    if (!canWrite || !selectedIds.length) return;
    await mutateCompliance({ action, ids: selectedIds, tenantId });
    setSelectedIds([]); await load();
  };
  return (
    <div className="soc-page compliance-page">
      <header className="soc-page__header">
        <div><h1>Compliance Management</h1><p>Enterprise SOC — Compliance Management</p></div>
        <TimeRangePicker value={range} onChange={setRange} />
      </header>
      {error && <div className="soc-alert">{error}</div>}
      <section className="soc-metrics-grid">
        <div className="metric-card"><span>Total</span><strong>{metrics?.total ?? items.length}</strong></div>
        <div className="metric-card"><span>Critical</span><strong>{criticalCount}</strong></div>
        <div className="metric-card"><span>Open</span><strong>{metrics?.open ?? 0}</strong></div>
        <div className="metric-card"><span>MTTR</span><strong>{metrics?.mttrMinutes ?? '—'}m</strong></div>
      </section>
      <section className="soc-section"><h2>Frameworks</h2><ComplianceChart data={metrics?.series ?? []} section="Frameworks" /></section>
      <section className="soc-section"><h2>Controls</h2><ComplianceChart data={metrics?.series ?? []} section="Controls" /></section>
      <section className="soc-section"><h2>Evidence</h2><ComplianceChart data={metrics?.series ?? []} section="Evidence" /></section>
      <section className="soc-section"><h2>Gaps</h2><ComplianceChart data={metrics?.series ?? []} section="Gaps" /></section>
      <section className="soc-toolbar">
        <input type="search" placeholder="Search Compliance Management..." value={filter.query} onChange={e => setFilter(f => ({ ...f, query: e.target.value, page: 1 }))} />
        {canWrite && <button type="button" onClick={() => onBulk('acknowledge')}>Acknowledge</button>}
        {canWrite && <button type="button" onClick={() => navigate('/compliance/new')}>Create</button>}
      </section>
      {loading ? <div className="soc-loading">Loading…</div> : (
        <ComplianceTable items={items} selectedIds={selectedIds} onSelect={setSelectedIds}
          onRowClick={id => navigate(`/compliance/${id}`)} renderSeverity={s => <SeverityBadge level={s} />} />
      )}
      <footer><span>{user?.displayName}</span><span>{tenantId}</span></footer>
    </div>
  );
};
export default CompliancePage;

export const ComplianceWidget00: React.FC<{ seed?: number }> = ({ seed = 0 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="compliance-widget-00"><h4>Compliance Management Widget 00</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ComplianceWidget01: React.FC<{ seed?: number }> = ({ seed = 1 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="compliance-widget-01"><h4>Compliance Management Widget 01</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ComplianceWidget02: React.FC<{ seed?: number }> = ({ seed = 2 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="compliance-widget-02"><h4>Compliance Management Widget 02</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ComplianceWidget03: React.FC<{ seed?: number }> = ({ seed = 3 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="compliance-widget-03"><h4>Compliance Management Widget 03</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ComplianceWidget04: React.FC<{ seed?: number }> = ({ seed = 4 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="compliance-widget-04"><h4>Compliance Management Widget 04</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ComplianceWidget05: React.FC<{ seed?: number }> = ({ seed = 5 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="compliance-widget-05"><h4>Compliance Management Widget 05</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ComplianceWidget06: React.FC<{ seed?: number }> = ({ seed = 6 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="compliance-widget-06"><h4>Compliance Management Widget 06</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ComplianceWidget07: React.FC<{ seed?: number }> = ({ seed = 7 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="compliance-widget-07"><h4>Compliance Management Widget 07</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ComplianceWidget08: React.FC<{ seed?: number }> = ({ seed = 8 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="compliance-widget-08"><h4>Compliance Management Widget 08</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ComplianceWidget09: React.FC<{ seed?: number }> = ({ seed = 9 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="compliance-widget-09"><h4>Compliance Management Widget 09</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ComplianceWidget10: React.FC<{ seed?: number }> = ({ seed = 10 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="compliance-widget-10"><h4>Compliance Management Widget 10</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ComplianceWidget11: React.FC<{ seed?: number }> = ({ seed = 11 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="compliance-widget-11"><h4>Compliance Management Widget 11</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ComplianceWidget12: React.FC<{ seed?: number }> = ({ seed = 12 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="compliance-widget-12"><h4>Compliance Management Widget 12</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ComplianceWidget13: React.FC<{ seed?: number }> = ({ seed = 13 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="compliance-widget-13"><h4>Compliance Management Widget 13</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ComplianceWidget14: React.FC<{ seed?: number }> = ({ seed = 14 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="compliance-widget-14"><h4>Compliance Management Widget 14</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ComplianceWidget15: React.FC<{ seed?: number }> = ({ seed = 15 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="compliance-widget-15"><h4>Compliance Management Widget 15</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ComplianceWidget16: React.FC<{ seed?: number }> = ({ seed = 16 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="compliance-widget-16"><h4>Compliance Management Widget 16</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ComplianceWidget17: React.FC<{ seed?: number }> = ({ seed = 17 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="compliance-widget-17"><h4>Compliance Management Widget 17</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ComplianceWidget18: React.FC<{ seed?: number }> = ({ seed = 18 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="compliance-widget-18"><h4>Compliance Management Widget 18</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ComplianceWidget19: React.FC<{ seed?: number }> = ({ seed = 19 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="compliance-widget-19"><h4>Compliance Management Widget 19</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ComplianceWidget20: React.FC<{ seed?: number }> = ({ seed = 20 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="compliance-widget-20"><h4>Compliance Management Widget 20</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ComplianceWidget21: React.FC<{ seed?: number }> = ({ seed = 21 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="compliance-widget-21"><h4>Compliance Management Widget 21</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ComplianceWidget22: React.FC<{ seed?: number }> = ({ seed = 22 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="compliance-widget-22"><h4>Compliance Management Widget 22</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ComplianceWidget23: React.FC<{ seed?: number }> = ({ seed = 23 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="compliance-widget-23"><h4>Compliance Management Widget 23</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ComplianceWidget24: React.FC<{ seed?: number }> = ({ seed = 24 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="compliance-widget-24"><h4>Compliance Management Widget 24</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ComplianceWidget25: React.FC<{ seed?: number }> = ({ seed = 25 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="compliance-widget-25"><h4>Compliance Management Widget 25</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ComplianceWidget26: React.FC<{ seed?: number }> = ({ seed = 26 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="compliance-widget-26"><h4>Compliance Management Widget 26</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const ComplianceWidget27: React.FC<{ seed?: number }> = ({ seed = 27 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="compliance-widget-27"><h4>Compliance Management Widget 27</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};
