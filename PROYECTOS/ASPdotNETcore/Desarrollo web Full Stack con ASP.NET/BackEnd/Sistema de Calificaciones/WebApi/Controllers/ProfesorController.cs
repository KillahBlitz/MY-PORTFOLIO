using AcessoDatos.Models;
using AcessoDatos.Operaciones;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;

namespace WebApi.Controllers
{
    //Post para autenticacion
    //Get para obtener datos
    //Put para actualizar datos
    [Route("api")]
    [ApiController]
    public class ProfesorController : ControllerBase
    {
        //primero creamos un objeto tipo profesorDAO para poder hacer las llamadas
        private ProfesorDAO profesorDAO = new ProfesorDAO();
        [HttpPost("autenticacion")]
        //llegaran los datos encapsulados en el cuerpo de la peticion
        //eso ayuda a la seguridad
        public string login([FromBody] Profesor prof)
        {
            //aqui llamo al metodo de login con los atributos correspondientes
            var profesor = profesorDAO.login(prof.Usuario, prof.Pass);

            //evaluo la condicion del profesor para ver lo que regreso
            if(profesor != null) 
            {
                return profesor.Usuario;
            }
            else
            {
                return null;
            }
        }
    }
}
