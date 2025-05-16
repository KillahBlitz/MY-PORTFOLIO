import styled from "styled-components";
import Personaje from "./Personaje";

export default function CharacterContainer(props){
    const { personajes, reqAPI } = props;


        console.log(personajes);
    return(
        <>
            <ContainerPersonaje>
                {personajes.map((personajes, index) =>(
                    <Personaje key={index} datapersonaje={personajes} />
                ))}
            </ContainerPersonaje>
            <ContainerButton>
                <Button onClick={reqAPI}>Nuevas Frases</Button>
            </ContainerButton>
        </>

    );
}

const ContainerPersonaje = styled.div`
    display: flex;
`;

const ContainerButton = styled.div`
    width: 100%;
    text-align: center;
`;

const Button = styled.button`
    width: 250px;
    background-color: #e76f51;
    color: #fff;
    border: none;
    padding: 10px 20px;
    border-radius: 20px;
    font-size: 18px;
    margin-top: 40px;
    transition: all 0.2s ease-out;

    &:hover {
        cursor: pointer;
        background-color: #1c0950;
    }
`;