import { useState } from 'react';
import './App.css';
import Characters from './components/Characters';
import imageRM from './Media/img1.png';


function App() {
  const [characters, setCharacters] = useState(null); //hook que se ocupa en este caso para recuperar a los personajes

  const reqApi = async () => { //funcion que manda el request a la api para recuperar a los personajes
      const api = await fetch('https://rickandmortyapi.com/api/character'); //peticion a la api para recuperar a los personajes guardado en la constante api
      const characterApi = await api.json(); //los personajes recuperados en formanto .json

      setCharacters(characterApi.results); //aqui seteamos los personajes en characters para ocuparlos despues con toda su informacion
  }

  //lo que ve el usuario
  return (
    <div className="App">
      <header className="App-header">
        <h1 className='title'>API Rick & Morty</h1>
        {characters ? (<Characters characters={characters} setCharacters={setCharacters}/>) : (<>
          <img src={imageRM} alt='Rick & Morty' className='img-home'></img>
          <button onClick={reqApi} className='btn-search'>Buscar Personajes</button>
        </>)}
      </header>
    </div>
  );
}

export default App;
