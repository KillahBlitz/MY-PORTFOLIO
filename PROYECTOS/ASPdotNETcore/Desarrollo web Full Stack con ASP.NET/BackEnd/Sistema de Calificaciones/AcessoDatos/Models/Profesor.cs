using System;
using System.Collections.Generic;

namespace AcessoDatos.Models;

public partial class Profesor
{
    public string Usuario { get; set; } = null!;

    public string Pass { get; set; } = null!;

    //con el ? hago que los valores puedan ser de tipo nulo
    public string? Nombre { get; set; } = null!;

    public string? Email { get; set; } = null!;

    public virtual ICollection<Asignatura> Asignaturas { get; set; } = new List<Asignatura>();
}
