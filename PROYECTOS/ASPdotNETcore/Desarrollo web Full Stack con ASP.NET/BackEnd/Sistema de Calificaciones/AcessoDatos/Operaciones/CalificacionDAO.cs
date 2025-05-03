using AcessoDatos.Context;
using AcessoDatos.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AcessoDatos.Operaciones
{
    public class CalificacionDAO
    {
        ProyectoContext context = new ProyectoContext();

        //metodo que devuelve la lista de calificaciones por id
        public List<Calificacion> seleccionar(int id)
        {
            //busco las calificaciones por el id de matricula en una lista
            var calificaciones = context.Calificacions.Where(c => c.MatriculaId == id).ToList();

            return calificaciones;
        }

        //metodo para agregar una calificacion asociada
        public bool agregarcalificacion(Calificacion calif)
        {
            try
            {
                //aqui agregamos la calificacion
                context.Calificacions.Add(calif);
                context.SaveChanges(); //guardamos los cambbios
                return true;
            }
            catch(Exception ex)
            {
                return false;
            }
        }

        //metodo para eliminar calificacion
        public bool eliminarcalificacion(int id)
        {
            try //try catch como todos nuestros metodos anteriores
            {
                //guardo la calificacion solicitada
                var calificaion = context.Calificacions.Where(c => c.Id == id).FirstOrDefault();

                //si la calificacion no es nula se remueve
                if (calificaion != null)
                {
                    context.Calificacions.Remove(calificaion);
                    context.SaveChanges();
                    return true;
                }
                else //caso contrario no se hace nada
                {
                    return false;
                }
            }
            catch (Exception ex)
            {
                return false;
            }
        }
    }
}
