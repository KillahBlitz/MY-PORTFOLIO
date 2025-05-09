


export default function Characters(props) { //funcion por defecto para  el componente el cual recibe los props recibidos por la api
    const {characters, setCharacters} = props;
    const resetCharacters = () =>{
        setCharacters(null);
    }

    return(
        <div className="characters">
            <header>
                <buttom className='btn-search' onClick={resetCharacters}>Volver hacia atras</buttom>
            </header>
            <br />
            <h1>Personajes Encontrados</h1>
            <div className="container-characters">
                {characters.map((character, index) => (
                    <div className="character-container" key={index}> 
                        <div>
                            <img src={character.image} alt={character.name} />
                        </div>
                        <div>
                            <h4>{character.name}</h4>
                            <h6>
                                {character.status === "Alive" ? (
                                    <>
                                        <span className="alive">Alive</span>
                                    </>
                                ) : (
                                    <>
                                        <span className="dead">dead</span>
                                    </>
                                )}
                            </h6>
                            <p className="text-grey">
                                <span>Episodios: </span>
                                <span>{character.episode.length}</span>
                            </p>
                            <p>
                                <span>Especie: </span>
                                <span>{character.species}</span>
                            </p>
                        </div>
                    </div>
                ))}
            </div>
        </div>
    )
}