import styled from "styled-components";

export default function personaje(props){
    const { datapersonaje } = props;
    const {character, image, quote} = datapersonaje;

    return(
        <ContainerPersonaje>
            <Tittle>{character}</Tittle>
            <ContainerImage><Image src={image} alt={character}/></ContainerImage>
            <FraseText>{quote}</FraseText>
        </ContainerPersonaje>
    );
}

const ContainerPersonaje = styled.div`
    padding: 10px;
    border: 1px solid #2a9d8f;
    border-radius: 10px;
    margin: 10px;
    
    &:hover {
        filter: brightness(40%);
    }
`;

const Tittle = styled.h2`
    color: #264653;
    height: 40px;
    justify-content: center;
    align-items: center;
    display: flex;
`;

const ContainerImage = styled.div`
    height: 250px;
    display: flex;
    align-items: center;
    justify-content: center;

`;

const Image = styled.img`
    width: 130px;
    height: auto;
    margin-right: 20px;
`;

const FraseText = styled.h4`
    color: #2a9d8f;
    height: 100px;
`;