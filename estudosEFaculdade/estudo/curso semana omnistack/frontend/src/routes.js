import React from 'react';
import { BrowserRouter, Route, Switch } from 'react-router-dom';

import Logon from './pages/logon';
import Register from './pages/Register';
import Profile from './pages/Profile';
import NewIncidents from './pages/NewIncident'
// as rotas vão ser componentes

export default function Routes(){
    return(
        //chama uma rota por vez uma a cada momento o swith
        <BrowserRouter>
            <Switch>
                <Route path="/"  exact component={Logon} />
                <Route path="/register" component={Register} />
                <Route path="/profile" component={Profile} />
                <Route path="/newincidents" component={NewIncidents} />
            </Switch>
        </BrowserRouter>
    );
}
