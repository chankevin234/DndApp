import classList from './components/classList';
import './App.css';

function App(props) {
  return ( 
      <h1>Hello, {props.name}</h1>  
      <classList />
  );
}

export default App;
