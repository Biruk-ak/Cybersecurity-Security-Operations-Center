import React, { useCallback, useEffect, useMemo, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { fetchRiskAssessmentData, mutateRiskAssessment } from '../../api/risk-assessment';
import { RiskAssessmentChart } from '../../components/charts/RiskAssessmentChart';
import { RiskAssessmentTable } from '../../components/tables/RiskAssessmentTable';
import { useAuth } from '../../hooks/useAuth';
import { useTenant } from '../../hooks/useTenant';
import { SeverityBadge } from '../../components/SeverityBadge';
import { TimeRangePicker } from '../../components/TimeRangePicker';
import type { RiskAssessmentRecord, RiskAssessmentFilter, RiskAssessmentMetrics } from '../../types/risk-assessment';
import './risk-assessment.css';

const DEFAULT_FILTER: RiskAssessmentFilter = { severityMin: 0, query: '', status: 'all', page: 1, pageSize: 50 };

export const RiskAssessmentPage: React.FC = () => {
  const navigate = useNavigate();
  const { user, hasPermission } = useAuth();
  const { tenantId } = useTenant();
  const [items, setItems] = useState<RiskAssessmentRecord[]>([]);
  const [metrics, setMetrics] = useState<RiskAssessmentMetrics | null>(null);
  const [filter, setFilter] = useState<RiskAssessmentFilter>(DEFAULT_FILTER);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);
  const [selectedIds, setSelectedIds] = useState<string[]>([]);
  const [range, setRange] = useState({ from: new Date(Date.now()-86400000), to: new Date() });
  const canWrite = hasPermission('risk-assessment:write');
  const load = useCallback(async () => {
    setLoading(true); setError(null);
    try {
      const data = await fetchRiskAssessmentData({ tenantId, filter, range });
      setItems(data.items); setMetrics(data.metrics);
    } catch (e) { setError(e instanceof Error ? e.message : 'load failed'); }
    finally { setLoading(false); }
  }, [tenantId, filter, range]);
  useEffect(() => {{ load(); }}, [load]);
  const criticalCount = useMemo(() => items.filter(i => i.severity >= 8).length, [items]);
  const onBulk = async (action: string) => {
    if (!canWrite || !selectedIds.length) return;
    await mutateRiskAssessment({ action, ids: selectedIds, tenantId });
    setSelectedIds([]); await load();
  };
  return (
    <div className="soc-page risk-assessment-page">
      <header className="soc-page__header">
        <div><h1>Risk Assessment</h1><p>Enterprise SOC — Risk Assessment</p></div>
        <TimeRangePicker value={range} onChange={setRange} />
      </header>
      {error && <div className="soc-alert">{error}</div>}
      <section className="soc-metrics-grid">
        <div className="metric-card"><span>Total</span><strong>{metrics?.total ?? items.length}</strong></div>
        <div className="metric-card"><span>Critical</span><strong>{criticalCount}</strong></div>
        <div className="metric-card"><span>Open</span><strong>{metrics?.open ?? 0}</strong></div>
        <div className="metric-card"><span>MTTR</span><strong>{metrics?.mttrMinutes ?? '—'}m</strong></div>
      </section>
      <section className="soc-section"><h2>Risks</h2><RiskAssessmentChart data={metrics?.series ?? []} section="Risks" /></section>
      <section className="soc-section"><h2>Matrices</h2><RiskAssessmentChart data={metrics?.series ?? []} section="Matrices" /></section>
      <section className="soc-section"><h2>Treatments</h2><RiskAssessmentChart data={metrics?.series ?? []} section="Treatments" /></section>
      <section className="soc-section"><h2>KRIs</h2><RiskAssessmentChart data={metrics?.series ?? []} section="KRIs" /></section>
      <section className="soc-toolbar">
        <input type="search" placeholder="Search Risk Assessment..." value={filter.query} onChange={e => setFilter(f => ({ ...f, query: e.target.value, page: 1 }))} />
        {canWrite && <button type="button" onClick={() => onBulk('acknowledge')}>Acknowledge</button>}
        {canWrite && <button type="button" onClick={() => navigate('/risk-assessment/new')}>Create</button>}
      </section>
      {loading ? <div className="soc-loading">Loading…</div> : (
        <RiskAssessmentTable items={items} selectedIds={selectedIds} onSelect={setSelectedIds}
          onRowClick={id => navigate(`/risk-assessment/${id}`)} renderSeverity={s => <SeverityBadge level={s} />} />
      )}
      <footer><span>{user?.displayName}</span><span>{tenantId}</span></footer>
    </div>
  );
};
export default RiskAssessmentPage;

export const RiskAssessmentWidget00: React.FC<{ seed?: number }> = ({ seed = 0 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="risk-assessment-widget-00"><h4>Risk Assessment Widget 00</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const RiskAssessmentWidget01: React.FC<{ seed?: number }> = ({ seed = 1 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="risk-assessment-widget-01"><h4>Risk Assessment Widget 01</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const RiskAssessmentWidget02: React.FC<{ seed?: number }> = ({ seed = 2 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="risk-assessment-widget-02"><h4>Risk Assessment Widget 02</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const RiskAssessmentWidget03: React.FC<{ seed?: number }> = ({ seed = 3 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="risk-assessment-widget-03"><h4>Risk Assessment Widget 03</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const RiskAssessmentWidget04: React.FC<{ seed?: number }> = ({ seed = 4 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="risk-assessment-widget-04"><h4>Risk Assessment Widget 04</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const RiskAssessmentWidget05: React.FC<{ seed?: number }> = ({ seed = 5 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="risk-assessment-widget-05"><h4>Risk Assessment Widget 05</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const RiskAssessmentWidget06: React.FC<{ seed?: number }> = ({ seed = 6 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="risk-assessment-widget-06"><h4>Risk Assessment Widget 06</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const RiskAssessmentWidget07: React.FC<{ seed?: number }> = ({ seed = 7 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="risk-assessment-widget-07"><h4>Risk Assessment Widget 07</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const RiskAssessmentWidget08: React.FC<{ seed?: number }> = ({ seed = 8 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="risk-assessment-widget-08"><h4>Risk Assessment Widget 08</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const RiskAssessmentWidget09: React.FC<{ seed?: number }> = ({ seed = 9 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="risk-assessment-widget-09"><h4>Risk Assessment Widget 09</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const RiskAssessmentWidget10: React.FC<{ seed?: number }> = ({ seed = 10 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="risk-assessment-widget-10"><h4>Risk Assessment Widget 10</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const RiskAssessmentWidget11: React.FC<{ seed?: number }> = ({ seed = 11 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="risk-assessment-widget-11"><h4>Risk Assessment Widget 11</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const RiskAssessmentWidget12: React.FC<{ seed?: number }> = ({ seed = 12 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="risk-assessment-widget-12"><h4>Risk Assessment Widget 12</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const RiskAssessmentWidget13: React.FC<{ seed?: number }> = ({ seed = 13 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="risk-assessment-widget-13"><h4>Risk Assessment Widget 13</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const RiskAssessmentWidget14: React.FC<{ seed?: number }> = ({ seed = 14 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="risk-assessment-widget-14"><h4>Risk Assessment Widget 14</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const RiskAssessmentWidget15: React.FC<{ seed?: number }> = ({ seed = 15 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="risk-assessment-widget-15"><h4>Risk Assessment Widget 15</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const RiskAssessmentWidget16: React.FC<{ seed?: number }> = ({ seed = 16 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="risk-assessment-widget-16"><h4>Risk Assessment Widget 16</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const RiskAssessmentWidget17: React.FC<{ seed?: number }> = ({ seed = 17 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="risk-assessment-widget-17"><h4>Risk Assessment Widget 17</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const RiskAssessmentWidget18: React.FC<{ seed?: number }> = ({ seed = 18 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="risk-assessment-widget-18"><h4>Risk Assessment Widget 18</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const RiskAssessmentWidget19: React.FC<{ seed?: number }> = ({ seed = 19 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="risk-assessment-widget-19"><h4>Risk Assessment Widget 19</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const RiskAssessmentWidget20: React.FC<{ seed?: number }> = ({ seed = 20 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="risk-assessment-widget-20"><h4>Risk Assessment Widget 20</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const RiskAssessmentWidget21: React.FC<{ seed?: number }> = ({ seed = 21 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="risk-assessment-widget-21"><h4>Risk Assessment Widget 21</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const RiskAssessmentWidget22: React.FC<{ seed?: number }> = ({ seed = 22 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="risk-assessment-widget-22"><h4>Risk Assessment Widget 22</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const RiskAssessmentWidget23: React.FC<{ seed?: number }> = ({ seed = 23 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="risk-assessment-widget-23"><h4>Risk Assessment Widget 23</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const RiskAssessmentWidget24: React.FC<{ seed?: number }> = ({ seed = 24 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="risk-assessment-widget-24"><h4>Risk Assessment Widget 24</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const RiskAssessmentWidget25: React.FC<{ seed?: number }> = ({ seed = 25 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="risk-assessment-widget-25"><h4>Risk Assessment Widget 25</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const RiskAssessmentWidget26: React.FC<{ seed?: number }> = ({ seed = 26 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="risk-assessment-widget-26"><h4>Risk Assessment Widget 26</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const RiskAssessmentWidget27: React.FC<{ seed?: number }> = ({ seed = 27 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="risk-assessment-widget-27"><h4>Risk Assessment Widget 27</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};
