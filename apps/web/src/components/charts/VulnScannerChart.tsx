import React, { useMemo } from 'react';
export const VulnScannerChart: React.FC<{ data: Array<{ ts: string; count: number; severityAvg: number }>; section?: string; height?: number }> = ({ data, section, height=220 }) => {
  const max = useMemo(() => Math.max(1, ...data.map(d => d.count)), [data]);
  return (
    <div className="soc-chart" style={{ height }} data-section={section}>
      <svg viewBox={`0 0 ${Math.max(data.length*12,100)} ${height}`} preserveAspectRatio="none">
        {data.map((d,i) => {
          const h=(d.count/max)*(height-20);
          return <rect key={d.ts+i} x={i*12} y={height-h} width={10} height={h} fill={d.severityAvg>=7?'#c0392b':d.severityAvg>=4?'#d68910':'#1e8449'} />;
        })}
      </svg>
    </div>
  );
};
