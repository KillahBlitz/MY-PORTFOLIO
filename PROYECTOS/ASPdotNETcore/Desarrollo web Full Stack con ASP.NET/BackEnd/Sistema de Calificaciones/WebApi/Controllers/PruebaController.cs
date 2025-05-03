using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;

namespace WebApi.Controllers
{
    [Route("api")]
    [ApiController]
    public class PruebaController : ControllerBase
    {
        //ENDPOINTS definidos por http, esta en Rest PUT, DELETE, GET, POST
        
        [HttpGet("prueba")]
        //endpoint de prueba que nos muestra como funcionan las peticiones Http
        public string pruebaApi()
        {
            return "esto es una prueba de la API";
        }
    }
}
