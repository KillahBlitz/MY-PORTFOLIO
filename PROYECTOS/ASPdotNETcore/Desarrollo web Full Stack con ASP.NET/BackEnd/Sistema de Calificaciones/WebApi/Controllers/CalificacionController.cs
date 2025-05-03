using AcessoDatos.Models;
using AcessoDatos.Operaciones;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;

namespace WebApi.Controllers
{
    [Route("api")]
    [ApiController]
    public class CalificacionController : ControllerBase
    {
        //inicializo las operaciones que se pueden realizar con calificacionDAO
        private CalificacionDAO calificacionDAO = new CalificacionDAO();

        //con Get obtenemos las calificaciones
        [HttpGet("calificaciones")]
        public List<Calificacion> get(int idMatricula)
        {
            //retorno las calificaciones del alumno segun su id
            return calificacionDAO.seleccionar(idMatricula);
        }

        //agregar una calificacion asociada a un id matricula
        [HttpPost("agregarcalificacion")] //endpoint de post
        public bool agregar([FromBody] Calificacion calif) //metodo que me hara agregar la calificacion
        {
            return calificacionDAO.agregarcalificacion(calif); //retorno la calificacion agregada
        }

        [HttpDelete("eliminarcalificacion")]
        public bool eliminar(int id) 
        {
            return calificacionDAO.eliminarcalificacion(id);
        }
    }
}
