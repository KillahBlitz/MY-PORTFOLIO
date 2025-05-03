import { useState, useEffect } from "react"
import * as API from './services/data';
import { Link } from "react-router";
import { Box, Table, TableContainer, Thead, Tr, Th, Tbody, Td } from "@chakra-ui/react";
import { ImPencil, ImCancelCircle, ImFolderOpen } from "react-icons/im";

export function StudentList(){
    let usuario = sessionStorage.getItem("usuario");
    const [students, setStudents] = useState([]);

    useEffect(() => {
        API.getStudents(usuario).then(setStudents);
    }, [usuario])

    function deleteStudent(id){
        API.deleteStudent(id).then(result => {
            if(result=='true'){
                alert("Alumno Eliminado con exito");
            }
            else{
                alert("ERROR al eliminar al alumno");
            }
        })
    }

    return(
        <>
        <Box m='50px'>
            <TableContainer>
                <Table size='md' variant='striped' colorScheme="purple">
                    <Thead>
                        <Tr>
                            <Th>ID</Th>
                            <Th>DNI</Th>
                            <Th>Nombre</Th>
                            <Th>Direccion</Th>
                            <Th>Edad</Th>
                            <Th>Email</Th>
                            <Th>Asignatura</Th>
                            <Th></Th>
                            <Th></Th>
                            <Th></Th>
                        </Tr>
                    </Thead>
                    <Tbody>
                        {
                            students?.map(student => (
                                <Tr key={student.id}>
                                    <Td>{student.id}</Td>
                                    <Td>{student.dni}</Td>
                                    <Td>{student.nombre}</Td>
                                    <Td>{student.direccion}</Td>
                                    <Td>{student.edad}</Td>
                                    <Td>{student.email}</Td>
                                    <Td>{student.asignatura}</Td>
                                    <Td><Link to={'/student/'+student.id}><ImPencil id='Editar' color="#58088A" /></Link></Td>
                                    <Td><Link to={'/student/califications/'+student.matriculaId}><ImFolderOpen id='Calificar' color="#58088A" /></Link></Td>
                                    <Td onClick={() => deleteStudent(student.id)}><ImCancelCircle id='Eliminar' color="#58088A" cursor='pointer' /></Td>
                                </Tr>
                            ))
                        }
                    </Tbody>
                </Table>
            </TableContainer>
        </Box>
        </>
    )
}