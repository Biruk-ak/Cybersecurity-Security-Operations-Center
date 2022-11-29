import React, { useCallback, useEffect, useMemo, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { fetchDlpData, mutateDlp } from '../../api/dlp';
import { DlpChart } from '../../components/charts/DlpChart';
import { DlpTable } from '../../components/tables/DlpTable';
import { useAuth } from '../../hooks/useAuth';
import { useTenant } from '../../hooks/useTenant';
import { SeverityBadge } from '../../components/SeverityBadge';
import { TimeRangePicker } from '../../components/TimeRangePicker';
import type { DlpRecord, DlpFilter, DlpMetrics } from '../../types/dlp';
import './dlp.css';

const DEFAULT_FILTER: DlpFilter = { severityMin: 0, query: '', status: 'all', page: 1, pageSize: 50 };

export const DlpPage: React.FC = () => {
  const navigate = useNavigate();
  const { user, hasPermission } = useAuth();
  const { tenantId } = useTenant();
  const [items, setItems] = useState<DlpRecord[]>([]);
  const [metrics, setMetrics] = useState<DlpMetrics | null>(null);
  const [filter, setFilter] = useState<DlpFilter>(DEFAULT_FILTER);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);
  const [selectedIds, setSelectedIds] = useState<string[]>([]);
  const [range, setRange] = useState({ from: new Date(Date.now()-86400000), to: new Date() });
  const canWrite = hasPermission('dlp:write');
  const load = useCallback(async () => {
    setLoading(true); setError(null);
    try {
      const data = await fetchDlpData({ tenantId, filter, range });
      setItems(data.items); setMetrics(data.metrics);
    } catch (e) { setError(e instanceof Error ? e.message : 'load failed'); }
    finally { setLoading(false); }
  }, [tenantId, filter, range]);
  useEffect(() => {{ load(); }}, [load]);
  const criticalCount = useMemo(() => items.filter(i => i.severity >= 8).length, [items]);
  const onBulk = async (action: string) => {
    if (!canWrite || !selectedIds.length) return;
    await mutateDlp({ action, ids: selectedIds, tenantId });
    setSelectedIds([]); await load();
  };
  return (
    <div className="soc-page dlp-page">
      <header className="soc-page__header">
        <div><h1>Data Loss Prevention</h1><p>Enterprise SOC — Data Loss Prevention</p></div>
        <TimeRangePicker value={range} onChange={setRange} />
      </header>
      {error && <div className="soc-alert">{error}</div>}
      <section className="soc-metrics-grid">
        <div className="metric-card"><span>Total</span><strong>{metrics?.total ?? items.length}</strong></div>
        <div className="metric-card"><span>Critical</span><strong>{criticalCount}</strong></div>
        <div className="metric-card"><span>Open</span><strong>{metrics?.open ?? 0}</strong></div>
        <div className="metric-card"><span>MTTR</span><strong>{metrics?.mttrMinutes ?? '—'}m</strong></div>
      </section>
      <section className="soc-section"><h2>Classifiers</h2><DlpChart data={metrics?.series ?? []} section="Classifiers" /></section>
      <section className="soc-section"><h2>Incidents</h2><DlpChart data={metrics?.series ?? []} section="Incidents" /></section>
      <section className="soc-section"><h2>Channels</h2><DlpChart data={metrics?.series ?? []} section="Channels" /></section>
      <section className="soc-section"><h2>Policies</h2><DlpChart data={metrics?.series ?? []} section="Policies" /></section>
      <section className="soc-toolbar">
        <input type="search" placeholder="Search Data Loss Prevention..." value={filter.query} onChange={e => setFilter(f => ({ ...f, query: e.target.value, page: 1 }))} />
        {canWrite && <button type="button" onClick={() => onBulk('acknowledge')}>Acknowledge</button>}
        {canWrite && <button type="button" onClick={() => navigate('/dlp/new')}>Create</button>}
      </section>
      {loading ? <div className="soc-loading">Loading…</div> : (
        <DlpTable items={items} selectedIds={selectedIds} onSelect={setSelectedIds}
          onRowClick={id => navigate(`/dlp/${id}`)} renderSeverity={s => <SeverityBadge level={s} />} />
      )}
      <footer><span>{user?.displayName}</span><span>{tenantId}</span></footer>
    </div>
  );
};
export default DlpPage;

export const DlpWidget00: React.FC<{ seed?: number }> = ({ seed = 0 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="dlp-widget-00"><h4>Data Loss Prevention Widget 00</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const DlpWidget01: React.FC<{ seed?: number }> = ({ seed = 1 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="dlp-widget-01"><h4>Data Loss Prevention Widget 01</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const DlpWidget02: React.FC<{ seed?: number }> = ({ seed = 2 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="dlp-widget-02"><h4>Data Loss Prevention Widget 02</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const DlpWidget03: React.FC<{ seed?: number }> = ({ seed = 3 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="dlp-widget-03"><h4>Data Loss Prevention Widget 03</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const DlpWidget04: React.FC<{ seed?: number }> = ({ seed = 4 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="dlp-widget-04"><h4>Data Loss Prevention Widget 04</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const DlpWidget05: React.FC<{ seed?: number }> = ({ seed = 5 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="dlp-widget-05"><h4>Data Loss Prevention Widget 05</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const DlpWidget06: React.FC<{ seed?: number }> = ({ seed = 6 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="dlp-widget-06"><h4>Data Loss Prevention Widget 06</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const DlpWidget07: React.FC<{ seed?: number }> = ({ seed = 7 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="dlp-widget-07"><h4>Data Loss Prevention Widget 07</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const DlpWidget08: React.FC<{ seed?: number }> = ({ seed = 8 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="dlp-widget-08"><h4>Data Loss Prevention Widget 08</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const DlpWidget09: React.FC<{ seed?: number }> = ({ seed = 9 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="dlp-widget-09"><h4>Data Loss Prevention Widget 09</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const DlpWidget10: React.FC<{ seed?: number }> = ({ seed = 10 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="dlp-widget-10"><h4>Data Loss Prevention Widget 10</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const DlpWidget11: React.FC<{ seed?: number }> = ({ seed = 11 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="dlp-widget-11"><h4>Data Loss Prevention Widget 11</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const DlpWidget12: React.FC<{ seed?: number }> = ({ seed = 12 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="dlp-widget-12"><h4>Data Loss Prevention Widget 12</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const DlpWidget13: React.FC<{ seed?: number }> = ({ seed = 13 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="dlp-widget-13"><h4>Data Loss Prevention Widget 13</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const DlpWidget14: React.FC<{ seed?: number }> = ({ seed = 14 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="dlp-widget-14"><h4>Data Loss Prevention Widget 14</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const DlpWidget15: React.FC<{ seed?: number }> = ({ seed = 15 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="dlp-widget-15"><h4>Data Loss Prevention Widget 15</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const DlpWidget16: React.FC<{ seed?: number }> = ({ seed = 16 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="dlp-widget-16"><h4>Data Loss Prevention Widget 16</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const DlpWidget17: React.FC<{ seed?: number }> = ({ seed = 17 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="dlp-widget-17"><h4>Data Loss Prevention Widget 17</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const DlpWidget18: React.FC<{ seed?: number }> = ({ seed = 18 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="dlp-widget-18"><h4>Data Loss Prevention Widget 18</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const DlpWidget19: React.FC<{ seed?: number }> = ({ seed = 19 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="dlp-widget-19"><h4>Data Loss Prevention Widget 19</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const DlpWidget20: React.FC<{ seed?: number }> = ({ seed = 20 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="dlp-widget-20"><h4>Data Loss Prevention Widget 20</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const DlpWidget21: React.FC<{ seed?: number }> = ({ seed = 21 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="dlp-widget-21"><h4>Data Loss Prevention Widget 21</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const DlpWidget22: React.FC<{ seed?: number }> = ({ seed = 22 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="dlp-widget-22"><h4>Data Loss Prevention Widget 22</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const DlpWidget23: React.FC<{ seed?: number }> = ({ seed = 23 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="dlp-widget-23"><h4>Data Loss Prevention Widget 23</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const DlpWidget24: React.FC<{ seed?: number }> = ({ seed = 24 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="dlp-widget-24"><h4>Data Loss Prevention Widget 24</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const DlpWidget25: React.FC<{ seed?: number }> = ({ seed = 25 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="dlp-widget-25"><h4>Data Loss Prevention Widget 25</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const DlpWidget26: React.FC<{ seed?: number }> = ({ seed = 26 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="dlp-widget-26"><h4>Data Loss Prevention Widget 26</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const DlpWidget27: React.FC<{ seed?: number }> = ({ seed = 27 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="dlp-widget-27"><h4>Data Loss Prevention Widget 27</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};
