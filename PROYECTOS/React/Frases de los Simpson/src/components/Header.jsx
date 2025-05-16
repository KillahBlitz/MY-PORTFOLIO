import styled from "styled-components";

export default function Header() {
    return (
        <header>
            <Title>Las mejores frases de los Simpson</Title>
        </header>
    );
}

const Title = styled.h1`
    color: #992508;
    text-align: center
`;