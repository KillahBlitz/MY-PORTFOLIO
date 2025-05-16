import { useState } from "react";
import Container from "./components/Container";
import Header from "./components/Header";
import Welcome from "./components/Welcome";
import CharacterContainer from "./components/CharacterContainer";



function App() {
  const [personajes, setPersonajes] = useState(null);
  //llamada a la api
  const reqAPI = async () => {
    const api = await fetch("https://thesimpsonsquoteapi.glitch.me/quotes?count=4");
    const frase = await api.json();
    setPersonajes(frase);
  }

  return (
        <Container>
          <Header />
          {!personajes ? (
            <Welcome reqAPI={ reqAPI }/>
          ) : (
            <CharacterContainer personajes={ personajes } reqAPI={ reqAPI }/>
          )}
        </Container>
  );
}



export default App;
