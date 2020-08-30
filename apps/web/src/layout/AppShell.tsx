import React from 'react';
import { Link, Route, Switch } from 'react-router-dom';
export const AppShell = () => (<div><aside><div>SOC Platform</div><nav><Link to='/siem'>SIEM</Link><Link to='/soar'>SOAR</Link><Link to='/edr'>EDR</Link></nav></aside><main><Switch><Route path='/' exact render={() => <h1>Security Analyst Dashboard</h1>} /></Switch></main></div>);
