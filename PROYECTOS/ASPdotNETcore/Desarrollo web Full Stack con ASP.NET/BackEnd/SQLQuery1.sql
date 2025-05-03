select a.nombre, asig.nombre from alumno a
left join matricula m on m.alumnoId = a.id
left join asignatura asig on asig.id = m.asignaturaId;