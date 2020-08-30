import React from 'react';
import { Route, Switch } from 'react-router-dom';
import { AppShell } from './layout/AppShell';
import { LoginPage } from './pages/auth/LoginPage';
export const App = () => (<Switch><Route path='/login' component={LoginPage} /><Route path='/' component={AppShell} /></Switch>);
