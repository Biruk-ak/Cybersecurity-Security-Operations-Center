import React, { useCallback, useEffect, useMemo, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { fetchVulnScannerData, mutateVulnScanner } from '../../api/vuln-scanner';
import { VulnScannerChart } from '../../components/charts/VulnScannerChart';
import { VulnScannerTable } from '../../components/tables/VulnScannerTable';
import { useAuth } from '../../hooks/useAuth';
import { useTenant } from '../../hooks/useTenant';
import { SeverityBadge } from '../../components/SeverityBadge';
import { TimeRangePicker } from '../../components/TimeRangePicker';
import type { VulnScannerRecord, VulnScannerFilter, VulnScannerMetrics } from '../../types/vuln-scanner';
import './vuln-scanner.css';

const DEFAULT_FILTER: VulnScannerFilter = { severityMin: 0, query: '', status: 'all', page: 1, pageSize: 50 };

export const VulnScannerPage: React.FC = () => {
  const navigate = useNavigate();
  const { user, hasPermission } = useAuth();
  const { tenantId } = useTenant();
  const [items, setItems] = useState<VulnScannerRecord[]>([]);
  const [metrics, setMetrics] = useState<VulnScannerMetrics | null>(null);
  const [filter, setFilter] = useState<VulnScannerFilter>(DEFAULT_FILTER);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);
  const [selectedIds, setSelectedIds] = useState<string[]>([]);
  const [range, setRange] = useState({ from: new Date(Date.now()-86400000), to: new Date() });
  const canWrite = hasPermission('vuln-scanner:write');
  const load = useCallback(async () => {
    setLoading(true); setError(null);
    try {
      const data = await fetchVulnScannerData({ tenantId, filter, range });
      setItems(data.items); setMetrics(data.metrics);
    } catch (e) { setError(e instanceof Error ? e.message : 'load failed'); }
    finally { setLoading(false); }
  }, [tenantId, filter, range]);
  useEffect(() => {{ load(); }}, [load]);
  const criticalCount = useMemo(() => items.filter(i => i.severity >= 8).length, [items]);
  const onBulk = async (action: string) => {
    if (!canWrite || !selectedIds.length) return;
    await mutateVulnScanner({ action, ids: selectedIds, tenantId });
    setSelectedIds([]); await load();
  };
  return (
    <div className="soc-page vuln-scanner-page">
      <header className="soc-page__header">
        <div><h1>Vulnerability Scanner</h1><p>Enterprise SOC — Vulnerability Scanner</p></div>
        <TimeRangePicker value={range} onChange={setRange} />
      </header>
      {error && <div className="soc-alert">{error}</div>}
      <section className="soc-metrics-grid">
        <div className="metric-card"><span>Total</span><strong>{metrics?.total ?? items.length}</strong></div>
        <div className="metric-card"><span>Critical</span><strong>{criticalCount}</strong></div>
        <div className="metric-card"><span>Open</span><strong>{metrics?.open ?? 0}</strong></div>
        <div className="metric-card"><span>MTTR</span><strong>{metrics?.mttrMinutes ?? '—'}m</strong></div>
      </section>
      <section className="soc-section"><h2>Scans</h2><VulnScannerChart data={metrics?.series ?? []} section="Scans" /></section>
      <section className="soc-section"><h2>Findings</h2><VulnScannerChart data={metrics?.series ?? []} section="Findings" /></section>
      <section className="soc-section"><h2>Remediation</h2><VulnScannerChart data={metrics?.series ?? []} section="Remediation" /></section>
      <section className="soc-section"><h2>Assets</h2><VulnScannerChart data={metrics?.series ?? []} section="Assets" /></section>
      <section className="soc-toolbar">
        <input type="search" placeholder="Search Vulnerability Scanner..." value={filter.query} onChange={e => setFilter(f => ({ ...f, query: e.target.value, page: 1 }))} />
        {canWrite && <button type="button" onClick={() => onBulk('acknowledge')}>Acknowledge</button>}
        {canWrite && <button type="button" onClick={() => navigate('/vuln-scanner/new')}>Create</button>}
      </section>
      {loading ? <div className="soc-loading">Loading…</div> : (
        <VulnScannerTable items={items} selectedIds={selectedIds} onSelect={setSelectedIds}
          onRowClick={id => navigate(`/vuln-scanner/${id}`)} renderSeverity={s => <SeverityBadge level={s} />} />
      )}
      <footer><span>{user?.displayName}</span><span>{tenantId}</span></footer>
    </div>
  );
};
export default VulnScannerPage;

export const VulnScannerWidget00: React.FC<{ seed?: number }> = ({ seed = 0 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="vuln-scanner-widget-00"><h4>Vulnerability Scanner Widget 00</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const VulnScannerWidget01: React.FC<{ seed?: number }> = ({ seed = 1 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="vuln-scanner-widget-01"><h4>Vulnerability Scanner Widget 01</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const VulnScannerWidget02: React.FC<{ seed?: number }> = ({ seed = 2 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="vuln-scanner-widget-02"><h4>Vulnerability Scanner Widget 02</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const VulnScannerWidget03: React.FC<{ seed?: number }> = ({ seed = 3 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="vuln-scanner-widget-03"><h4>Vulnerability Scanner Widget 03</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const VulnScannerWidget04: React.FC<{ seed?: number }> = ({ seed = 4 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="vuln-scanner-widget-04"><h4>Vulnerability Scanner Widget 04</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const VulnScannerWidget05: React.FC<{ seed?: number }> = ({ seed = 5 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="vuln-scanner-widget-05"><h4>Vulnerability Scanner Widget 05</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const VulnScannerWidget06: React.FC<{ seed?: number }> = ({ seed = 6 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="vuln-scanner-widget-06"><h4>Vulnerability Scanner Widget 06</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const VulnScannerWidget07: React.FC<{ seed?: number }> = ({ seed = 7 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="vuln-scanner-widget-07"><h4>Vulnerability Scanner Widget 07</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const VulnScannerWidget08: React.FC<{ seed?: number }> = ({ seed = 8 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="vuln-scanner-widget-08"><h4>Vulnerability Scanner Widget 08</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const VulnScannerWidget09: React.FC<{ seed?: number }> = ({ seed = 9 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="vuln-scanner-widget-09"><h4>Vulnerability Scanner Widget 09</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const VulnScannerWidget10: React.FC<{ seed?: number }> = ({ seed = 10 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="vuln-scanner-widget-10"><h4>Vulnerability Scanner Widget 10</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const VulnScannerWidget11: React.FC<{ seed?: number }> = ({ seed = 11 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="vuln-scanner-widget-11"><h4>Vulnerability Scanner Widget 11</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const VulnScannerWidget12: React.FC<{ seed?: number }> = ({ seed = 12 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="vuln-scanner-widget-12"><h4>Vulnerability Scanner Widget 12</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const VulnScannerWidget13: React.FC<{ seed?: number }> = ({ seed = 13 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="vuln-scanner-widget-13"><h4>Vulnerability Scanner Widget 13</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const VulnScannerWidget14: React.FC<{ seed?: number }> = ({ seed = 14 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="vuln-scanner-widget-14"><h4>Vulnerability Scanner Widget 14</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const VulnScannerWidget15: React.FC<{ seed?: number }> = ({ seed = 15 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="vuln-scanner-widget-15"><h4>Vulnerability Scanner Widget 15</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const VulnScannerWidget16: React.FC<{ seed?: number }> = ({ seed = 16 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="vuln-scanner-widget-16"><h4>Vulnerability Scanner Widget 16</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const VulnScannerWidget17: React.FC<{ seed?: number }> = ({ seed = 17 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="vuln-scanner-widget-17"><h4>Vulnerability Scanner Widget 17</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const VulnScannerWidget18: React.FC<{ seed?: number }> = ({ seed = 18 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="vuln-scanner-widget-18"><h4>Vulnerability Scanner Widget 18</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const VulnScannerWidget19: React.FC<{ seed?: number }> = ({ seed = 19 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="vuln-scanner-widget-19"><h4>Vulnerability Scanner Widget 19</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const VulnScannerWidget20: React.FC<{ seed?: number }> = ({ seed = 20 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="vuln-scanner-widget-20"><h4>Vulnerability Scanner Widget 20</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const VulnScannerWidget21: React.FC<{ seed?: number }> = ({ seed = 21 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="vuln-scanner-widget-21"><h4>Vulnerability Scanner Widget 21</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const VulnScannerWidget22: React.FC<{ seed?: number }> = ({ seed = 22 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="vuln-scanner-widget-22"><h4>Vulnerability Scanner Widget 22</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const VulnScannerWidget23: React.FC<{ seed?: number }> = ({ seed = 23 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="vuln-scanner-widget-23"><h4>Vulnerability Scanner Widget 23</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const VulnScannerWidget24: React.FC<{ seed?: number }> = ({ seed = 24 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="vuln-scanner-widget-24"><h4>Vulnerability Scanner Widget 24</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const VulnScannerWidget25: React.FC<{ seed?: number }> = ({ seed = 25 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="vuln-scanner-widget-25"><h4>Vulnerability Scanner Widget 25</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const VulnScannerWidget26: React.FC<{ seed?: number }> = ({ seed = 26 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="vuln-scanner-widget-26"><h4>Vulnerability Scanner Widget 26</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const VulnScannerWidget27: React.FC<{ seed?: number }> = ({ seed = 27 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="vuln-scanner-widget-27"><h4>Vulnerability Scanner Widget 27</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};
