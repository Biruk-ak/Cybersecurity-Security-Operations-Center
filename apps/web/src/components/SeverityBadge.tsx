import React from 'react';
export const SeverityBadge: React.FC<{level:number}> = ({level}) => <span className={'sev-'+level}>SEV-{level}</span>;
