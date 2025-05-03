
//definimos el enlace que tienen todos los endpoints
const URL = 'http://localhost:5297/api/';


//llamada AJAX para hacer el login 
export function login(user, password) {
    //guardo los datos en una lista para manejarlos
    let datos = {usuario:user, pass:password};
    //lo que vot a retornar es la peticion http en autenticacion
    return fetch(URL+'autenticacion', {
        method: 'POST', //donde el metodo POST es el que esta
        body: JSON.stringify(datos), //paso los datos en formato JSON
        headers: { //aqui si no entendi que paso la verdad
            'Content-Type': 'application/json'
        }
    })
    .then(data => data.text()) //entonces parseamos data a texto que es la respuesta de la peticion
}

//Llamada AJAx para devolver los alumnos registrados con el profesor
export function getStudents(usuario){
    return fetch(URL+'alumnosProfesor?usuario='+usuario,{
        'Content-Type': 'aplication/json'
    })
    .then(data => data.json());
}

//llamada AJAX para las funcionalidades de crear un nuevo alumno
export function createStudent(student){
    let data = {dni:student.dni, nombre:student.nombre, direccion:student.direccion, edad:student.edad, email:student.email}
    
    return fetch(URL+'anadiralumno?id_asig='+student.asignatura,{
        method: 'POST',
        body: JSON.stringify(data),
        headers: {
            'Content-Type': 'application/json'
        }
    })
    .then(data => data.text());
}

export function deleteStudent(id){
    return fetch(URL+'eliminaralumno?id='+id,{
        method: 'DELETE',
        headers: {
            'Content-Type': 'application/json'
        }
    })
    .then(data => data.text());
}

export function getStudentsDetails(id){

    return fetch(URL+'alumno?id='+id,{
        method: 'GET',
        headers: {
            'Content-Type': 'application/json'
        }
    })
    .then(data => data.json());
}

export function editStudent(student){
    return fetch(URL+'actalumno', {
        method: 'PUT',
        body: JSON.stringify(student),
        headers: {
            'Content-Type': 'application/json'
        }
    })
    .then(data => data.text())
}

export function getCalificaciones(id){

    return fetch(URL+'calificaciones?idMatricula='+id, {
        method: 'GET',
        headers: {
            'Content-Type': 'application/json'
        }
    })
    .then(data => data.json());
}

export function createCalificacion(calificacion, id) {
    let data = {
        descripcion: calificacion.descripcion,
        nota: calificacion.nota,
        porcentaje: calificacion.porcentaje,
        matriculaId: id
    };

    return fetch(URL + 'agregarcalificacion', {
        method: 'POST',
        body: JSON.stringify(data),
        headers: {
            'Content-Type': 'application/json'
        }
    }).then(data => data.text());
}


export function deleteCalificacion(id){
    return fetch(URL+'eliminarcalificacion?id='+id,{
        method: 'DELETE',
        headers: {
            'Content-Type': 'application/json'
        }
    })
    .then(data => data.text());
}
