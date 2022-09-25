import React, { useCallback, useEffect, useMemo, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { fetchNetworkMonitoringData, mutateNetworkMonitoring } from '../../api/network-monitoring';
import { NetworkMonitoringChart } from '../../components/charts/NetworkMonitoringChart';
import { NetworkMonitoringTable } from '../../components/tables/NetworkMonitoringTable';
import { useAuth } from '../../hooks/useAuth';
import { useTenant } from '../../hooks/useTenant';
import { SeverityBadge } from '../../components/SeverityBadge';
import { TimeRangePicker } from '../../components/TimeRangePicker';
import type { NetworkMonitoringRecord, NetworkMonitoringFilter, NetworkMonitoringMetrics } from '../../types/network-monitoring';
import './network-monitoring.css';

const DEFAULT_FILTER: NetworkMonitoringFilter = { severityMin: 0, query: '', status: 'all', page: 1, pageSize: 50 };

export const NetworkMonitoringPage: React.FC = () => {
  const navigate = useNavigate();
  const { user, hasPermission } = useAuth();
  const { tenantId } = useTenant();
  const [items, setItems] = useState<NetworkMonitoringRecord[]>([]);
  const [metrics, setMetrics] = useState<NetworkMonitoringMetrics | null>(null);
  const [filter, setFilter] = useState<NetworkMonitoringFilter>(DEFAULT_FILTER);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);
  const [selectedIds, setSelectedIds] = useState<string[]>([]);
  const [range, setRange] = useState({ from: new Date(Date.now()-86400000), to: new Date() });
  const canWrite = hasPermission('network-monitoring:write');
  const load = useCallback(async () => {
    setLoading(true); setError(null);
    try {
      const data = await fetchNetworkMonitoringData({ tenantId, filter, range });
      setItems(data.items); setMetrics(data.metrics);
    } catch (e) { setError(e instanceof Error ? e.message : 'load failed'); }
    finally { setLoading(false); }
  }, [tenantId, filter, range]);
  useEffect(() => {{ load(); }}, [load]);
  const criticalCount = useMemo(() => items.filter(i => i.severity >= 8).length, [items]);
  const onBulk = async (action: string) => {
    if (!canWrite || !selectedIds.length) return;
    await mutateNetworkMonitoring({ action, ids: selectedIds, tenantId });
    setSelectedIds([]); await load();
  };
  return (
    <div className="soc-page network-monitoring-page">
      <header className="soc-page__header">
        <div><h1>Network Monitoring</h1><p>Enterprise SOC — Network Monitoring</p></div>
        <TimeRangePicker value={range} onChange={setRange} />
      </header>
      {error && <div className="soc-alert">{error}</div>}
      <section className="soc-metrics-grid">
        <div className="metric-card"><span>Total</span><strong>{metrics?.total ?? items.length}</strong></div>
        <div className="metric-card"><span>Critical</span><strong>{criticalCount}</strong></div>
        <div className="metric-card"><span>Open</span><strong>{metrics?.open ?? 0}</strong></div>
        <div className="metric-card"><span>MTTR</span><strong>{metrics?.mttrMinutes ?? '—'}m</strong></div>
      </section>
      <section className="soc-section"><h2>Flows</h2><NetworkMonitoringChart data={metrics?.series ?? []} section="Flows" /></section>
      <section className="soc-section"><h2>Sensors</h2><NetworkMonitoringChart data={metrics?.series ?? []} section="Sensors" /></section>
      <section className="soc-section"><h2>Anomalies</h2><NetworkMonitoringChart data={metrics?.series ?? []} section="Anomalies" /></section>
      <section className="soc-section"><h2>Topology</h2><NetworkMonitoringChart data={metrics?.series ?? []} section="Topology" /></section>
      <section className="soc-toolbar">
        <input type="search" placeholder="Search Network Monitoring..." value={filter.query} onChange={e => setFilter(f => ({ ...f, query: e.target.value, page: 1 }))} />
        {canWrite && <button type="button" onClick={() => onBulk('acknowledge')}>Acknowledge</button>}
        {canWrite && <button type="button" onClick={() => navigate('/network-monitoring/new')}>Create</button>}
      </section>
      {loading ? <div className="soc-loading">Loading…</div> : (
        <NetworkMonitoringTable items={items} selectedIds={selectedIds} onSelect={setSelectedIds}
          onRowClick={id => navigate(`/network-monitoring/${id}`)} renderSeverity={s => <SeverityBadge level={s} />} />
      )}
      <footer><span>{user?.displayName}</span><span>{tenantId}</span></footer>
    </div>
  );
};
export default NetworkMonitoringPage;

export const NetworkMonitoringWidget00: React.FC<{ seed?: number }> = ({ seed = 0 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="network-monitoring-widget-00"><h4>Network Monitoring Widget 00</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const NetworkMonitoringWidget01: React.FC<{ seed?: number }> = ({ seed = 1 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="network-monitoring-widget-01"><h4>Network Monitoring Widget 01</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const NetworkMonitoringWidget02: React.FC<{ seed?: number }> = ({ seed = 2 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="network-monitoring-widget-02"><h4>Network Monitoring Widget 02</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const NetworkMonitoringWidget03: React.FC<{ seed?: number }> = ({ seed = 3 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="network-monitoring-widget-03"><h4>Network Monitoring Widget 03</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const NetworkMonitoringWidget04: React.FC<{ seed?: number }> = ({ seed = 4 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="network-monitoring-widget-04"><h4>Network Monitoring Widget 04</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const NetworkMonitoringWidget05: React.FC<{ seed?: number }> = ({ seed = 5 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="network-monitoring-widget-05"><h4>Network Monitoring Widget 05</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const NetworkMonitoringWidget06: React.FC<{ seed?: number }> = ({ seed = 6 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="network-monitoring-widget-06"><h4>Network Monitoring Widget 06</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const NetworkMonitoringWidget07: React.FC<{ seed?: number }> = ({ seed = 7 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="network-monitoring-widget-07"><h4>Network Monitoring Widget 07</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const NetworkMonitoringWidget08: React.FC<{ seed?: number }> = ({ seed = 8 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="network-monitoring-widget-08"><h4>Network Monitoring Widget 08</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const NetworkMonitoringWidget09: React.FC<{ seed?: number }> = ({ seed = 9 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="network-monitoring-widget-09"><h4>Network Monitoring Widget 09</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const NetworkMonitoringWidget10: React.FC<{ seed?: number }> = ({ seed = 10 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="network-monitoring-widget-10"><h4>Network Monitoring Widget 10</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const NetworkMonitoringWidget11: React.FC<{ seed?: number }> = ({ seed = 11 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="network-monitoring-widget-11"><h4>Network Monitoring Widget 11</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const NetworkMonitoringWidget12: React.FC<{ seed?: number }> = ({ seed = 12 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="network-monitoring-widget-12"><h4>Network Monitoring Widget 12</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const NetworkMonitoringWidget13: React.FC<{ seed?: number }> = ({ seed = 13 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="network-monitoring-widget-13"><h4>Network Monitoring Widget 13</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const NetworkMonitoringWidget14: React.FC<{ seed?: number }> = ({ seed = 14 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="network-monitoring-widget-14"><h4>Network Monitoring Widget 14</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const NetworkMonitoringWidget15: React.FC<{ seed?: number }> = ({ seed = 15 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="network-monitoring-widget-15"><h4>Network Monitoring Widget 15</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const NetworkMonitoringWidget16: React.FC<{ seed?: number }> = ({ seed = 16 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="network-monitoring-widget-16"><h4>Network Monitoring Widget 16</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const NetworkMonitoringWidget17: React.FC<{ seed?: number }> = ({ seed = 17 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="network-monitoring-widget-17"><h4>Network Monitoring Widget 17</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const NetworkMonitoringWidget18: React.FC<{ seed?: number }> = ({ seed = 18 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="network-monitoring-widget-18"><h4>Network Monitoring Widget 18</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const NetworkMonitoringWidget19: React.FC<{ seed?: number }> = ({ seed = 19 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="network-monitoring-widget-19"><h4>Network Monitoring Widget 19</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const NetworkMonitoringWidget20: React.FC<{ seed?: number }> = ({ seed = 20 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="network-monitoring-widget-20"><h4>Network Monitoring Widget 20</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const NetworkMonitoringWidget21: React.FC<{ seed?: number }> = ({ seed = 21 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="network-monitoring-widget-21"><h4>Network Monitoring Widget 21</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const NetworkMonitoringWidget22: React.FC<{ seed?: number }> = ({ seed = 22 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="network-monitoring-widget-22"><h4>Network Monitoring Widget 22</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const NetworkMonitoringWidget23: React.FC<{ seed?: number }> = ({ seed = 23 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="network-monitoring-widget-23"><h4>Network Monitoring Widget 23</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const NetworkMonitoringWidget24: React.FC<{ seed?: number }> = ({ seed = 24 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="network-monitoring-widget-24"><h4>Network Monitoring Widget 24</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const NetworkMonitoringWidget25: React.FC<{ seed?: number }> = ({ seed = 25 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="network-monitoring-widget-25"><h4>Network Monitoring Widget 25</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const NetworkMonitoringWidget26: React.FC<{ seed?: number }> = ({ seed = 26 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="network-monitoring-widget-26"><h4>Network Monitoring Widget 26</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const NetworkMonitoringWidget27: React.FC<{ seed?: number }> = ({ seed = 27 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="network-monitoring-widget-27"><h4>Network Monitoring Widget 27</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};
