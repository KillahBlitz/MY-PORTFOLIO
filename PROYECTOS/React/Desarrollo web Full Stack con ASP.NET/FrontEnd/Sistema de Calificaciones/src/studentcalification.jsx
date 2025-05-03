import { useParams } from "react-router";
import { Header } from "./header";
import { useEffect, useState } from "react";
import * as API from "./services/data";
import { Box, Center, TableContainer, Table, Thead, Tbody, Th, Tr, Td, Input, Button, Badge } from "@chakra-ui/react";
import { ImCheckmark, ImCross } from "react-icons/im";

export function StudentCalification(){
    const [calificaciones, setCalificaciones] = useState([]);
    const [calificacion, setCalificacion] = useState([]);

    let params = useParams();
    const matriculaID = params.matriculaID;

    useEffect(() => {
        API.getCalificaciones(params.matriculaID).then(setCalificaciones);
    }, [params.matriculaID])


    let total = 0;

    calificaciones?.map(calificacion => (
        total = total + calificacion.nota * (calificacion.porcentaje/100)
    ))
    function createCalificacion(){

        let descrField = document.getElementById("descripcion");
        let notaField = document.getElementById("nota");
        let porcentField = document.getElementById("porcentaje");

        let valid = descrField.value.trim() != "" && notaField.value.trim() != "" && porcentField.value.trim() != "";

        if(valid){
            API.createCalificacion(calificacion, matriculaID).then(result => {
                if(result=='true'){
                    alert("Calificacion agregada con exito, Recargue la Pagina");
                    document.getElementById("descripcion").value="";
                    document.getElementById("nota").value="";
                    document.getElementById("porcentaje").value="";
                }else{
                    alert("ERROR al agregar la calificacion");
                }
            })
        }
    
    }

    function deleteCalificacion(id){
        API.deleteCalificacion(id).then(result => {
            if(result=="true"){
                alert("Calificacion ELIMINADA con exito, Recargue la Pagina");
            }
            else{
                alert("Error al eliminar la calificacion");
            }
        })
    }



    return(
            <>
            <Header />
            <Center>
                <Box m='100px'>
                    <TableContainer>
                        <Table>
                            <Thead>
                                <Tr>
                                    <Th>Descripcion</Th>
                                    <Th>Nota</Th>
                                    <Th>Ponderacion</Th>
                                    <Th></Th>
                                </Tr>
                            </Thead>
                            <Tbody>
                                {
                                    calificaciones?.map((calificacion, index) => (
                                        <Tr key={index}>
                                            <Td>{calificacion.descripcion}</Td>
                                            <Td>{calificacion.nota}</Td>
                                            <Td>{calificacion.porcentaje}%</Td>
                                            <Td onClick={() => deleteCalificacion(calificacion.id)}><Button bgColor='#3a015d' color='white' borderRadius='full'><ImCross /></Button></Td>
                                        </Tr>
                                    ))
                                }
                                <Tr>
                                    <Td><Input type="text" id="descripcion" placeholder="Descripcion" onChange={event => setCalificacion({...calificacion, descripcion: event.target.value})}/></Td>
                                    <Td><Input type="number" id="nota" placeholder="Nota" onChange={event => setCalificacion({...calificacion, nota: event.target.value})}/></Td>
                                    <Td><Input type="number" id="porcentaje" placeholder="Ponderacion" onChange={event => setCalificacion({...calificacion, porcentaje: event.target.value})}/></Td>
                                    <Td><Button id="nueva" bgColor='#3a015d' color='white' borderRadius='full' onClick={() => createCalificacion()}><ImCheckmark></ImCheckmark></Button></Td>
                                </Tr>
                            </Tbody>
                        </Table>
                    </TableContainer>
                    <Center>
                        <Box mt='10px' fontSize='lg'>
                            <Badge variant='solid' colorScheme="purple" fontSize='lg'>NOTA FINAL: {total}</Badge>
                        </Box>
                    </Center>
                </Box>
            </Center>
            </>
    )
}