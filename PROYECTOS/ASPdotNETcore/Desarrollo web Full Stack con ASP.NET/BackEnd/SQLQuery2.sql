select a.id,a.dni,a.nombre,a.direccion,a.edad,a.email,asig.nombre from alumno a
left join matricula m on a.id = m.alumnoId
left join  asignatura asig on asig.id = m.asignaturaId
where asig.profesor = 'ivan';