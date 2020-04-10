//arquivo principal do APp
import 'intl';
import 'intl/locale-data/jsonp/pt-BR';

import React from 'react';
import { StyleSheet, Text, View } from 'react-native';
//importando a rota
import Routes from './src/routes';
export default function App() {
  return (
   <Routes />
  );
}

