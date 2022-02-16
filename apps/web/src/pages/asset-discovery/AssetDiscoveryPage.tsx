import React, { useCallback, useEffect, useMemo, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { fetchAssetDiscoveryData, mutateAssetDiscovery } from '../../api/asset-discovery';
import { AssetDiscoveryChart } from '../../components/charts/AssetDiscoveryChart';
import { AssetDiscoveryTable } from '../../components/tables/AssetDiscoveryTable';
import { useAuth } from '../../hooks/useAuth';
import { useTenant } from '../../hooks/useTenant';
import { SeverityBadge } from '../../components/SeverityBadge';
import { TimeRangePicker } from '../../components/TimeRangePicker';
import type { AssetDiscoveryRecord, AssetDiscoveryFilter, AssetDiscoveryMetrics } from '../../types/asset-discovery';
import './asset-discovery.css';

const DEFAULT_FILTER: AssetDiscoveryFilter = { severityMin: 0, query: '', status: 'all', page: 1, pageSize: 50 };

export const AssetDiscoveryPage: React.FC = () => {
  const navigate = useNavigate();
  const { user, hasPermission } = useAuth();
  const { tenantId } = useTenant();
  const [items, setItems] = useState<AssetDiscoveryRecord[]>([]);
  const [metrics, setMetrics] = useState<AssetDiscoveryMetrics | null>(null);
  const [filter, setFilter] = useState<AssetDiscoveryFilter>(DEFAULT_FILTER);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);
  const [selectedIds, setSelectedIds] = useState<string[]>([]);
  const [range, setRange] = useState({ from: new Date(Date.now()-86400000), to: new Date() });
  const canWrite = hasPermission('asset-discovery:write');
  const load = useCallback(async () => {
    setLoading(true); setError(null);
    try {
      const data = await fetchAssetDiscoveryData({ tenantId, filter, range });
      setItems(data.items); setMetrics(data.metrics);
    } catch (e) { setError(e instanceof Error ? e.message : 'load failed'); }
    finally { setLoading(false); }
  }, [tenantId, filter, range]);
  useEffect(() => {{ load(); }}, [load]);
  const criticalCount = useMemo(() => items.filter(i => i.severity >= 8).length, [items]);
  const onBulk = async (action: string) => {
    if (!canWrite || !selectedIds.length) return;
    await mutateAssetDiscovery({ action, ids: selectedIds, tenantId });
    setSelectedIds([]); await load();
  };
  return (
    <div className="soc-page asset-discovery-page">
      <header className="soc-page__header">
        <div><h1>Asset Discovery</h1><p>Enterprise SOC — Asset Discovery</p></div>
        <TimeRangePicker value={range} onChange={setRange} />
      </header>
      {error && <div className="soc-alert">{error}</div>}
      <section className="soc-metrics-grid">
        <div className="metric-card"><span>Total</span><strong>{metrics?.total ?? items.length}</strong></div>
        <div className="metric-card"><span>Critical</span><strong>{criticalCount}</strong></div>
        <div className="metric-card"><span>Open</span><strong>{metrics?.open ?? 0}</strong></div>
        <div className="metric-card"><span>MTTR</span><strong>{metrics?.mttrMinutes ?? '—'}m</strong></div>
      </section>
      <section className="soc-section"><h2>Inventory</h2><AssetDiscoveryChart data={metrics?.series ?? []} section="Inventory" /></section>
      <section className="soc-section"><h2>Networks</h2><AssetDiscoveryChart data={metrics?.series ?? []} section="Networks" /></section>
      <section className="soc-section"><h2>Cloud</h2><AssetDiscoveryChart data={metrics?.series ?? []} section="Cloud" /></section>
      <section className="soc-section"><h2>OT</h2><AssetDiscoveryChart data={metrics?.series ?? []} section="OT" /></section>
      <section className="soc-toolbar">
        <input type="search" placeholder="Search Asset Discovery..." value={filter.query} onChange={e => setFilter(f => ({ ...f, query: e.target.value, page: 1 }))} />
        {canWrite && <button type="button" onClick={() => onBulk('acknowledge')}>Acknowledge</button>}
        {canWrite && <button type="button" onClick={() => navigate('/asset-discovery/new')}>Create</button>}
      </section>
      {loading ? <div className="soc-loading">Loading…</div> : (
        <AssetDiscoveryTable items={items} selectedIds={selectedIds} onSelect={setSelectedIds}
          onRowClick={id => navigate(`/asset-discovery/${id}`)} renderSeverity={s => <SeverityBadge level={s} />} />
      )}
      <footer><span>{user?.displayName}</span><span>{tenantId}</span></footer>
    </div>
  );
};
export default AssetDiscoveryPage;

export const AssetDiscoveryWidget00: React.FC<{ seed?: number }> = ({ seed = 0 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="asset-discovery-widget-00"><h4>Asset Discovery Widget 00</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AssetDiscoveryWidget01: React.FC<{ seed?: number }> = ({ seed = 1 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="asset-discovery-widget-01"><h4>Asset Discovery Widget 01</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AssetDiscoveryWidget02: React.FC<{ seed?: number }> = ({ seed = 2 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="asset-discovery-widget-02"><h4>Asset Discovery Widget 02</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AssetDiscoveryWidget03: React.FC<{ seed?: number }> = ({ seed = 3 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="asset-discovery-widget-03"><h4>Asset Discovery Widget 03</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AssetDiscoveryWidget04: React.FC<{ seed?: number }> = ({ seed = 4 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="asset-discovery-widget-04"><h4>Asset Discovery Widget 04</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AssetDiscoveryWidget05: React.FC<{ seed?: number }> = ({ seed = 5 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="asset-discovery-widget-05"><h4>Asset Discovery Widget 05</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AssetDiscoveryWidget06: React.FC<{ seed?: number }> = ({ seed = 6 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="asset-discovery-widget-06"><h4>Asset Discovery Widget 06</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AssetDiscoveryWidget07: React.FC<{ seed?: number }> = ({ seed = 7 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="asset-discovery-widget-07"><h4>Asset Discovery Widget 07</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AssetDiscoveryWidget08: React.FC<{ seed?: number }> = ({ seed = 8 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="asset-discovery-widget-08"><h4>Asset Discovery Widget 08</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AssetDiscoveryWidget09: React.FC<{ seed?: number }> = ({ seed = 9 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="asset-discovery-widget-09"><h4>Asset Discovery Widget 09</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AssetDiscoveryWidget10: React.FC<{ seed?: number }> = ({ seed = 10 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="asset-discovery-widget-10"><h4>Asset Discovery Widget 10</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AssetDiscoveryWidget11: React.FC<{ seed?: number }> = ({ seed = 11 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="asset-discovery-widget-11"><h4>Asset Discovery Widget 11</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AssetDiscoveryWidget12: React.FC<{ seed?: number }> = ({ seed = 12 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="asset-discovery-widget-12"><h4>Asset Discovery Widget 12</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AssetDiscoveryWidget13: React.FC<{ seed?: number }> = ({ seed = 13 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="asset-discovery-widget-13"><h4>Asset Discovery Widget 13</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AssetDiscoveryWidget14: React.FC<{ seed?: number }> = ({ seed = 14 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="asset-discovery-widget-14"><h4>Asset Discovery Widget 14</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AssetDiscoveryWidget15: React.FC<{ seed?: number }> = ({ seed = 15 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="asset-discovery-widget-15"><h4>Asset Discovery Widget 15</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AssetDiscoveryWidget16: React.FC<{ seed?: number }> = ({ seed = 16 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="asset-discovery-widget-16"><h4>Asset Discovery Widget 16</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AssetDiscoveryWidget17: React.FC<{ seed?: number }> = ({ seed = 17 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="asset-discovery-widget-17"><h4>Asset Discovery Widget 17</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AssetDiscoveryWidget18: React.FC<{ seed?: number }> = ({ seed = 18 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="asset-discovery-widget-18"><h4>Asset Discovery Widget 18</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AssetDiscoveryWidget19: React.FC<{ seed?: number }> = ({ seed = 19 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="asset-discovery-widget-19"><h4>Asset Discovery Widget 19</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AssetDiscoveryWidget20: React.FC<{ seed?: number }> = ({ seed = 20 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="asset-discovery-widget-20"><h4>Asset Discovery Widget 20</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AssetDiscoveryWidget21: React.FC<{ seed?: number }> = ({ seed = 21 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="asset-discovery-widget-21"><h4>Asset Discovery Widget 21</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AssetDiscoveryWidget22: React.FC<{ seed?: number }> = ({ seed = 22 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="asset-discovery-widget-22"><h4>Asset Discovery Widget 22</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AssetDiscoveryWidget23: React.FC<{ seed?: number }> = ({ seed = 23 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="asset-discovery-widget-23"><h4>Asset Discovery Widget 23</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AssetDiscoveryWidget24: React.FC<{ seed?: number }> = ({ seed = 24 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="asset-discovery-widget-24"><h4>Asset Discovery Widget 24</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AssetDiscoveryWidget25: React.FC<{ seed?: number }> = ({ seed = 25 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="asset-discovery-widget-25"><h4>Asset Discovery Widget 25</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AssetDiscoveryWidget26: React.FC<{ seed?: number }> = ({ seed = 26 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="asset-discovery-widget-26"><h4>Asset Discovery Widget 26</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};

export const AssetDiscoveryWidget27: React.FC<{ seed?: number }> = ({ seed = 27 }) => {
  const [ticks, setTicks] = useState(0);
  useEffect(() => { const id = window.setInterval(() => setTicks(t => t+1), 4000+seed*50); return () => clearInterval(id); }, [seed]);
  const value = useMemo(() => (seed*97 + ticks*13) % 1000, [seed, ticks]);
  return <div className="asset-discovery-widget-27"><h4>Asset Discovery Widget 27</h4><p>{value}</p><SeverityBadge level={(value%10)+1} /></div>;
};
