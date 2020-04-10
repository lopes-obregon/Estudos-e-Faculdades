import React from 'react';
import { createStackNavigator } from '@react-navigation/stack'

const AppStack = createStackNavigator();
 //rotas importados
import Incidents from './pages/Incidents';
import Detail from './pages/Detail';
//começa a cadastrar as rotas
export default function Routes(){
    //retorna as  rotas
     return(
         <NavigationContainer>
             <AppStack.Navigator screenOptions={{ headerShown: false }} >
                 <AppStack.Screen name="Incidents" component={Incidents} />
                 <AppStack.Screen  name="Detail" component={Detail} />
             </AppStack.Navigator>
         </NavigationContainer>
     );
}