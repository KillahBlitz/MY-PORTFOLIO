import {Container} from 'semantic-ui-react';


export default function ContainerContent({children}){
    return(
        <Container text>{children}</Container>
    )
}