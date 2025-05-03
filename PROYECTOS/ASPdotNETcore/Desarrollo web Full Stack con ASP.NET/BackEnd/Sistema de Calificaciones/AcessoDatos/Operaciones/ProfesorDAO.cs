using AcessoDatos.Context;
using AcessoDatos.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AcessoDatos.Operaciones
{
    public class ProfesorDAO
    {
        //creacion de metodos del profesor
        //inicializamos el contexto del profesor
        public ProyectoContext context = new ProyectoContext();
        //definimos la primera funcion de login, donde el profesor puede acceder si existe en la tabla
        public Profesor login(string usuario, string pass)
        {
            //condicional donde usuario y contrasena son iguales a la que alla registrada
            var prof = context.Profesors.Where(p => p.Usuario == usuario && p.Pass == pass).FirstOrDefault();
            //devolvemos el valor de prof aunque sea nulo
            return prof;

        }
    }
}
