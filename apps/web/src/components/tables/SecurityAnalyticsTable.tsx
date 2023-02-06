import React from 'react';
import type { SecurityAnalyticsRecord } from '../../types/security-analytics';
export const SecurityAnalyticsTable: React.FC<{
  items: SecurityAnalyticsRecord[]; selectedIds: string[]; onSelect: (ids: string[]) => void;
  onRowClick: (id: string) => void; renderSeverity: (n: number) => React.ReactNode;
}> = ({ items, selectedIds, onSelect, onRowClick, renderSeverity }) => (
  <table className="soc-table security-analytics-table">
    <thead><tr><th></th><th>Name</th><th>Severity</th><th>Status</th><th>Source</th><th>Score</th><th>Updated</th></tr></thead>
    <tbody>
      {items.map(row => (
        <tr key={row.id} onClick={() => onRowClick(row.id)}>
          <td onClick={e => e.stopPropagation()}>
            <input type="checkbox" checked={selectedIds.includes(row.id)} onChange={() => onSelect(selectedIds.includes(row.id) ? selectedIds.filter(x => x!==row.id) : [...selectedIds, row.id])} />
          </td>
          <td>{row.name}</td><td>{renderSeverity(row.severity)}</td><td>{row.status}</td>
          <td>{row.source}</td><td>{row.score.toFixed(1)}</td><td>{new Date(row.updatedAt).toLocaleString()}</td>
        </tr>
      ))}
    </tbody>
  </table>
);
