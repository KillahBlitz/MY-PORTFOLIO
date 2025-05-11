import { Select, Input, Button, Grid, Header, Icon } from "semantic-ui-react";
import { useState } from "react";
import {v4 as uuidv4} from "uuid";


const options = [
    {key: "escolar", text:"Escolar", value:"Escolar"},
    {key: 'cursos', text:'Cursos', value:'Cursos'},
    {key: 'casa', text:'Casa', value:'Casa'},
    {key: 'trabajo', text:'Trabajo', value:'Trabajo'},
    {key: 'amigos', text:'Amigos', value:'Amigos'},
    {key: 'otro', text:'Otro', value:'Otro'}
]
export default function InputTask(props){
    const [task, setTask] = useState({
    idTask: "",
    taskName: "",
    categoryTask: ""
    });

    const [error, setError] = useState(false);

    const { createTask } = props;

    const onChangeTask = (e) => {
        setTask({
            ...task,
            [e.target.name]: e.target.value
        });
    };

    const onChangeCategoryTask = (e, data) => {
        setTask({
            ...task,
            [data.name]: data.value
        });
    }

    const onSubmitTask = (e) => {
        //No recargar la pagina
        e.preventDefault();
        //validacion de inputs
        if(task.taskName.trim() === "" || task.categoryTask.trim() === ""){
            setError(true);
            return;
        }
        //eliminar el mensaje previo
        setError(false);
        //asignar un ID
        task.idTask = uuidv4();
        //crear la tarea
        createTask(task);
        //limpiar los inputs
        setTask({
            idTask: "",
            taskName: "",
            categoryTask: ""
        });
    }

    return(
        <>
        <Grid centered columns={2}>
            <Input type="text" action>
                <Input size="small" icon="add" placeholder="Escribe tu tarea" iconPosition="left" name="taskName" value={task.taskName} onChange={onChangeTask}/>
                <Select compact options={options} className="select-form-task" name="categoryTask" placeholder="Categoria" value={task.categoryTask} onChange={onChangeCategoryTask}/>
                <Button type="submit" color="red" onClick={onSubmitTask}>Agregar</Button>
            </Input>
        </Grid>
            {error && (
                <Grid centered>
                    <Header as="h4" className="alert-error-form"><br/>
                        <Icon name="close" color="red" />
                        <Header.Content>La tarea es y la categoria es Obligatoria</Header.Content>
                    </Header>
                </Grid>
            )}
        </>
    );
};