import React from 'react';
//import React , {useState} from 'react';
//import Header from './Header';
import './global.css';
//import Logon from './pages/logon';
import Routes from './routes';
//JSX (javascript XML)

function App(){
  /*//estado useState()
  const [ counter, setCounter] = useState(0);
  //retorna 
  //mutabilidade
  /**
   * Array [valor , funcaoDeAtualização]
   */
  /*function increment(){
    setCounter(counter + 1);
  }*/
  return (
      //<Header />//fecha a tag nela mesmo;
     /* <Header>
        Semana OmniStack
      </Header>*/
      /*<div>
        <Header>
          Contador: {counter}
        </Header>
        <button onClick={increment}>Incrementar</button>
      </div>*/
      //configurando rotas na aplicação;

      <Routes />
    );
}
export default App;
/**
 * pacote para rota 
 *npm install react-router-dom
 */