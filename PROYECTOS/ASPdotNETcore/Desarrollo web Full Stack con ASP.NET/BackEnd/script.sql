CREATE TABLE alumno (
  id int IDENTITY(1,1) primary key,
  dni varchar(8) NOT NULL,
  nombre varchar(255) NOT NULL,
  direccion varchar(255) NOT NULL,
  edad int NOT NULL,
  email varchar(100) NOT NULL
);

CREATE TABLE profesor (
	usuario varchar(255) primary key,
	pass varchar(255) NOT NULL,
	nombre varchar(255) NOT NULL,
	email varchar(255) NOT NULL
);

CREATE TABLE asignatura (
  id int IDENTITY(1,1) primary key,
  nombre varchar(255) NOT NULL,
  creditos int DEFAULT 0 NOT NULL,
  profesor varchar(255),
  FOREIGN KEY (profesor) REFERENCES profesor(usuario)
);


CREATE TABLE matricula (
  id int IDENTITY(1,1) primary key,
  alumnoId int NOT NULL,
  asignaturaId int NOT NULL,
  FOREIGN KEY (alumnoId) REFERENCES alumno(id),
  FOREIGN KEY (asignaturaId) REFERENCES asignatura(id)
);

CREATE TABLE calificacion (
  id int IDENTITY(1,1) primary key,
  descripcion varchar(255) NOT NULL,
  nota REAL NOT NULL,
  porcentaje int NOT NULL,
  matriculaId int NOT NULL,
  FOREIGN KEY (matriculaId) REFERENCES matricula(id)
) ;