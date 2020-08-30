import React, { useState } from 'react';
import { useHistory } from 'react-router-dom';
export const LoginPage = () => { const h=useHistory(); const [e,setE]=useState(''); const [p,setP]=useState(''); return (<div><h1>Cybersecurity & SOC Platform</h1><form onSubmit={ev=>{ev.preventDefault();h.push('/');}}><input value={e} onChange={x=>setE(x.target.value)} /><input type='password' value={p} onChange={x=>setP(x.target.value)} /><button type='submit'>Sign in</button></form></div>); };
