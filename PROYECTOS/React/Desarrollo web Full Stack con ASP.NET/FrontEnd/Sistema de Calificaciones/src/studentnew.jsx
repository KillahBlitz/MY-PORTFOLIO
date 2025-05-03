import { useState } from "react"
import { Header } from "./header"
import * as API from "./services/data";
import { Center, Box, Heading, FormControl, FormLabel, Input, Select } from "@chakra-ui/react";

export function StudenNew(){
    const [student, setStudent] = useState({dni:'', nombre:'', direccion:'', edad:'', email:'', asignatura:'1'})

    function handleSubmit(e){
        e.preventDefault();
        API.createStudent(student).then(result => {
            if(result=="true"){
                alert("Alumno insertado con exito");
                document.getElementById("formulario").reset();
            }
            else{
                alert("ERROR al insertar alumno");
            }
        })
    }
    return(
        <>
            <Header />
            <Center>
                <Box m='40px' boxShadow='xl' borderRadius='md' width='40%' id='caja'>
                    <Box textAlign='center'>
                        <Heading>Nuevo Alumno</Heading>
                    </Box>
                    <Box p='20px'>
                        <form id="formulario" onSubmit={handleSubmit}>
                            <FormControl mt='3px'>
                                <FormLabel>DNI</FormLabel>
                                <Input type="text" id="dni" required onChange={event => setStudent({...student, dni: event.target.value})} />
                            </FormControl>
                            <FormControl mt='3px'>
                                <FormLabel>Nombre</FormLabel>
                                <Input type="text" id="nombre" required onChange={event => setStudent({...student, nombre: event.target.value})} />
                            </FormControl>
                            <FormControl mt='3px'>
                                <FormLabel>Direccion</FormLabel>
                                <Input type="text" id="direccion" required onChange={event => setStudent({...student, direccion: event.target.value})} />
                            </FormControl>
                            <FormControl mt='3px'>
                                <FormLabel>Edad</FormLabel>
                                <Input type="number" id="edad" required onChange={event => setStudent({...student, edad: event.target.value})} />
                            </FormControl>
                            <FormControl mt='3px'>
                                <FormLabel>Email</FormLabel>
                                <Input type="text" id="email" required onChange={event => setStudent({...student, email: event.target.value})} />
                            </FormControl>
                            <FormControl mt='3px'>
                                <FormLabel>Asignatura</FormLabel>
                                <Select id="asignatura" onChange={event => setStudent({...student, asignatura: event.target.value})}>
                                    <option value='1'>Matematicas</option>
                                    <option value='2'>Informatica</option>
                                    <option value='3'>Ingles</option>
                                    <option value='4'>Literatura</option>
                                </Select>
                            </FormControl>
                            <FormControl mt='20px'>
                                <Input type="submit" id="editar" bgColor='#3a015d' color='white' cursor='pointer' value="Agregar Alumno"/>
                            </FormControl>
                        </form>
                    </Box>
                </Box>
            </Center>

        </>
    )
}