import styled from "styled-components";
import Logo from "../media/imageP.png"


export default function Welcome(props){
    const { reqAPI } = props;

    return(
        <ContentLogo>
        <WelcomeText>Bienvenido, aqui puedes ver las mejores frases de los Simpson</WelcomeText>
        <ImageLogo src={Logo} alt="Logo Simpson" onClick={ reqAPI }/>
        </ContentLogo>
    )
}

const ContentLogo = styled.div`
  width: 100%;
  text-align: center;
`;

const ImageLogo = styled.img`
  width: 450px;
  height: auto;
  &:hover {
    cursor: pointer;
  }
`;

const WelcomeText = styled.p`
  color: #2a9d8f;
  text-align: center;
  font-weight: 900;
  padding: 50px 0 10px 0;
  font-size: 25px;
`;