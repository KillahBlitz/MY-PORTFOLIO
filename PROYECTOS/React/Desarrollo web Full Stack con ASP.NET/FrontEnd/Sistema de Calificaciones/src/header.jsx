import { Box, Flex, HStack, Image } from "@chakra-ui/react";
import { Link, Navigate } from "react-router"
import { useNavigate } from "react-router";
import buddy from "./assets/buddy.png";

export function Header(){

    const navigate = useNavigate();
    function cerrarSesion(){
        sessionStorage.removeItem("usuario");
        navigate("/");
    }

    return(
        <>
        <Flex w='100%' h='70px' align='center' justify='space-between' bgColor='#58088A' color='white'>
            <HStack as='nav' spacing='10px'>
                <Image src={buddy} h='50px' ml='6px' bgColor='white' borderRadius='full'/>
                <Box ml='15px' px="20px" py="10px" cursor='pointer' _hover={{color: "gray"}} bgColor='#3a015d' borderRadius='10%'><Link to={'/dashboard'}><span>LISTADO</span></Link></Box>
                <Box ml='20px' px="20px" py="10px" cursor='pointer' _hover={{color: "gray"}} bgColor='#3a015d' borderRadius='10%'><Link to={'/student'}><span>NUEVO</span></Link></Box>
            </HStack>
            <HStack>
                <Box mr='20px' px="20px" py="10px" cursor='pointer' _hover={{color: "gray"}} bgColor='#3a015d' borderRadius='10%' onClick={() => cerrarSesion()}>CERRAR SESION</Box>
            </HStack>
        </Flex>
        </>
    )
}