import { useParams } from "react-router"
import { Header } from "./header";
import { useEffect, useState } from "react";
import * as API from "./services/data";
import { Box, Center, FormLabel, Heading, FormControl, Input } from "@chakra-ui/react";

export function StudentEdit(){
    let params = useParams();
    const [student, setStudent] = useState([]);

    useEffect(() => {
        API.getStudentsDetails(params.studentID).then(setStudent);
    }, [params.studentID])

    function handleSubmit(e){
        e.preventDefault();
        API.editStudent(student).then(result => {
            if(result=="true"){
                alert("alumno modificado correctamente");
            }else{
                alert("Error al modificar");
            }
        })
    }

    return(
        <>
        <Header />
        <Center>
            <Box m='40px' boxShadow='xl' borderRadius='md' width='40%' id='caja'>
                <Box textAlign='center'>
                    <Heading>Editar Alumno</Heading>
                </Box>
                <Box p='20px'>
                    <form id="formulario" onSubmit={handleSubmit}>
                        <FormControl mt='3px'>
                            <FormLabel>DNI</FormLabel>
                            <Input type="text" id='dni'  required disabled value={student.dni}/>
                        </FormControl>
                        <FormControl mt='3px'>
                            <FormLabel>Nombre</FormLabel>
                            <Input type="text" id='nombre' required value={student.nombre} onChange={event => setStudent({...student, nombre: event.target.value})}/>
                        </FormControl>
                        <FormControl mt='3px'>
                            <FormLabel>Direccion</FormLabel>
                            <Input type="text" id='direccion' required value={student.direccion} onChange={event => setStudent({...student, direccion: event.target.value})}/>
                        </FormControl>
                        <FormControl mt='3px'>
                            <FormLabel>Edad</FormLabel>
                            <Input type="number" id='edad' required value={student.edad} onChange={event => setStudent({...student, edad: event.target.value})}/>
                        </FormControl>
                        <FormControl mt='3px'>
                            <FormLabel>Email</FormLabel>
                            <Input type="text" id='email' required value={student.email} onChange={event => setStudent({...student, email: event.target.value})}/>
                        </FormControl>
                        <FormControl mt='20px'>
                        <Input type="submit" id="editar" bgColor='#3a015d' color='white' cursor='pointer' value="Editar Alumno"/>
                        </FormControl>
                    </form>
                </Box>
            </Box>
        </Center>
        </>
    )
}