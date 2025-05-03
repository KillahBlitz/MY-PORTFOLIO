import {Routes,Route} from "react-router"
import { Login } from "./login"
import { Dashboard } from "./dashboard"
import { StudenNew } from "./studentnew"
import { StudentEdit } from "./studentedit"
import { StudentCalification } from "./studentcalification"

export function App() {

  return(
    <Routes>
      <Route path="/" element={<Login />} />
      <Route path="/dashboard" element={<Dashboard />} />
      <Route path="/student" element={<StudenNew/>} />
      <Route path="/student/:studentID" element={<StudentEdit/>} />
      <Route path="/student/califications/:matriculaID" element={<StudentCalification/>} />
    </Routes>
  )
}