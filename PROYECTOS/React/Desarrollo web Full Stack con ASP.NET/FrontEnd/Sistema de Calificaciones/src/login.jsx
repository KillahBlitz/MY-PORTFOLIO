import { useState } from 'react'
import * as API from './services/data'; 
import { Form, useNavigate } from 'react-router';
import buddy from './assets/buddy.png';
import {Box, Center, FormControl, FormLabel, Heading, Input, Image } from '@chakra-ui/react';


export function Login() {
    const [teacher, setTeacher] = useState({usuario:'', password:''});
    const navigate = useNavigate();
  
    async function handleSubmit(e) {
      e.preventDefault(); 
      const response = await API.login(teacher.usuario, teacher.password);
      if (response.length !== 0) {
        sessionStorage.setItem("usuario",response);
        navigate('/dashboard');
      } else {
        alert("Error");
      }
    }
  
    return (
      <>
        <Box mt='30px'>
          <Center>
            <Image mt='3px' src={buddy} width='300px' height='300px'/>
          </Center>
          <Center>
            <Box m='2%' boxShadow='xl' borderRadius='md' width='40%' id='caja' bg='#9B4D96' color='white'>
              <Box textAlign='center'>
                <Heading>Inicia Sesión con tus credenciales</Heading>
              </Box>
              <Box padding='20px'>
                <form id='formulario' onSubmit={handleSubmit}>
                <FormControl mt='3px'>
                  <FormLabel>Usuario</FormLabel>
                  <Input required type='text' id='usuario' onChange={event => setTeacher({...teacher, usuario: event.target.value})} bg='#a427bd' color='white' _focus={{ borderColor: 'purple.400' }}/> 
                </FormControl>
                <FormControl mt='3px'>
                  <FormLabel>Contraseña</FormLabel>
                  <Input required type='password' id='pass' onChange={event => setTeacher({...teacher, password: event.target.value})} bg='#a427bd' color='white' _focus={{ borderColor: 'purple.400' }}/>
                </FormControl>
                <FormControl mt='3px'>
                  <br />
                  <Input type='submit' mt='3px' id='enviar' borderColor='teal' value='Acceder' bg='#5f319f'/>
                </FormControl>
                </form> 
              </Box>
            </Box>
          </Center>
        </Box>
      </>
    );
  }
  