using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics.Eventing.Reader;
using System.Drawing;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static COMPILADOR.usrAL;

namespace COMPILADOR
{
    public partial class usrAS : UserControl
    {
        //constructor
        public usrAS()
        {
            InitializeComponent();
        }


        // Propiedad para almacenar la cadena ingresada
        public string AS_PAL { get; set; }
        // Propiedad para almacenar la tabla de tokens completa
        public List<usrAL.Token> AS_Tokens { get; set; }
        //Esta pila recibe las sentencias que se ingresan en el cuerpo del programa
        public List<PiladeSentencias> SenS = new List<PiladeSentencias>();

        //ABECEDARIOS
        public char[] ABC = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
        public char[] NUM = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        public char[] SIGNOS = { '+', '-' };
        public char[] SIMBOLOS = { '#', '"', '@', '/', '$', '!', '%', '&', '(', ')', '=', '?', '¿', ':', ';', ',', '.', '_', '´' };
        public char[] OL = { '&', '|', '!' };
        public char[] OR = { '<', '>' };
        public char[] AS = { '=' };
        public char[] OA = { '+', '-', '/', '*', '%'};
        public string[] PR = { "Program", "Var", "Begin", "End", "Para", "Si", "begin", "end", "Leer", "Escribir" };
        public string[] TipoDD = { "int", "char", "float", "double" };
        public string[] Parentesis = { "(", ")" };
        public string Demilitador = ";";
        public string Separador = ",";

        //CREACION DE NUEVA PILA PARA SENTENCIAS POR A VER
        public class PiladeSentencias
        {
            public string AS_Token { get; set; }
            public string AS_TipToken { get; set; }
            public string AS_TipDato { get; set; }

            public PiladeSentencias(string palabra, string tipoToken, string TipoDeD)
            {
                AS_Token = palabra;  // Usa el parámetro palabra para asignar a Tok
                AS_TipToken = tipoToken;  // Usa el parámetro tipoToken para asignar a Tip
                AS_TipDato = TipoDeD; //Parametro para guardar el tipo de dato
            }
        }

        //variables
        //variables para los distintos switch
        int casoEsp = 1, opc = 1, Sop = 0;
        //variables de conteo
        int n = 1, con = 0, c = 0, parentesis = 0;
        //esta variable actializa el ultimo estado de derivacion
        string txtactualizado;
        string newtxtactualizado;
        string ultimatum;
        //estas variables guardan las sentencias ingresadas y la actualizacion del primer caso ingresado
        string  sids = null, Sinis = null, Var = null;
        string idonum = null;
        string UoO;
        bool botton = false;
        bool ValAS = false;


        public void ReceivePal(string PAL)
        {
            // Utiliza 'PAL' como necesites dentro de usrAS
            AS_PAL = PAL;
            CadenaImprimir.Text = AS_PAL;
        }

        // Método para recibir y mostrar la tabla de tokens
        public void ReceiveTokens(List<usrAL.Token> tokens)
        {
            // Utiliza 'tokens' como necesites dentro de usrAS
            AS_Tokens = tokens;
        }

        private void usrAS_Load(object sender, EventArgs e)
        {
  
        }

        //metodo para realizar la operacion de derivacion
        private void ButtomRealizador_Click(object sender, EventArgs e)
        {
            RecorrerTokensComoPila();
        }

        private void TablaTok_Click(object sender, EventArgs e)
        {
            PrintTokens();
        }

        //esta funcion imprime la tabla de tokens para saber que son correctos los caracteres
        public void PrintTokens()
        {
            if (AS_Tokens != null && AS_Tokens.Count > 0)
            {
                StringBuilder sb = new StringBuilder();
                sb.AppendLine("Token:     Tipo:     Dato:     Numero:");
                foreach (var token in AS_Tokens)
                {
                    sb.AppendLine($"{token.Tok}     {token.Tip}     {token.DATAT}     {token.Num}");
                }
                TablaDeDerivacion.Text = sb.ToString();
            }
            else
            {
                TablaDeDerivacion.Text = "No hay tokens para mostrar.";
            }
        }


        //Recorrimiento de la pila principal de todos los tokens
        public void RecorrerTokensComoPila()
        {
            if (AS_Tokens != null && AS_Tokens.Count > 0)
            {
                if(botton == false)
                {
                    // Recorrer la lista de tokens
                    foreach (var token in AS_Tokens)
                    {
                        //llamada de la funcion que actua como constructor para la derivacion
                        AnalisisSintax(token);
                        ultimatum = TablaDeDerivacion.Text;
                    }
                    botton = true;
                }
                else
                {
                    TablaDeDerivacion.Text = ultimatum;
                    BorrarPila();
                    botton = false;
                }
            }
            else
            {
                TablaDeDerivacion.Text = "No hay tokens para recorrer.";
            }
        }

        //recuperando los atributos de la pila por token
        public void AnalisisSintax(usrAL.Token token)
        {
            string AS_TipoDeTok;
            string AS_Token;
            string AS_TipodeDato;

            AS_TipoDeTok = token.Tip;
            AS_Token = token.Tok;
            AS_TipodeDato = token.DATAT;

            //llamada del analizador sintactico
            exp(AS_Token, AS_TipoDeTok, AS_TipodeDato);
        }

        public void exp(string AS_lexema, string AS_tiptok, string AS_tdata)
        {
            switch (casoEsp)
            {
                //case default donde si encuentra un error de sintaxis este retrocede
                case 0:
                    TablaDeDerivacion.Text = "ERROR SINTACTICO";
                    EDAS.Text = "INVALIDO";
                    casoEsp = 1;
                    break;

                //primer caso donde lo primero que esperamos encontrar es el lexema Program de tipo PR
                case 1:
                    if (AS_lexema == "Program" && AS_tiptok == "PR")
                    {
                        TablaDeDerivacion.Text = "S->ProgramS\n";
                        txtactualizado = TablaDeDerivacion.Text;
                        casoEsp++;
                    }
                    else
                    { casoEsp = 0; }
                    break;

                //Segundo caso donde esperamos recibir un ID que no tenga tipo de dato
                case 2:
                    if (AS_tiptok == "ID" && AS_tdata == "")
                    {
                        TablaDeDerivacion.Text = $"{txtactualizado}->ProgramIDS\n";
                        txtactualizado = TablaDeDerivacion.Text;
                        casoEsp++;
                    }
                    else
                    { casoEsp = 0; }
                    break;

                //esperando recibir Var
                case 3:
                    if (AS_lexema == "Var" && AS_tiptok == "PR")
                    {
                        TablaDeDerivacion.Text = $"{txtactualizado}->ProgramIDVarS\n";
                        txtactualizado = TablaDeDerivacion.Text;
                        Var = AS_lexema;
                        casoEsp++;
                    }
                    else { casoEsp = 0; }
                    break;

                //Ingreso de IDs con su tipo de dato
                case 4:
                    if (AS_tiptok == "ID" && AS_tdata == "int" || AS_tdata == "float") {
                        if(Var == "Var")
                        {
                            TablaDeDerivacion.Text = $"{txtactualizado}->ProgramIDVarIDS\n";
                            txtactualizado = TablaDeDerivacion.Text;
                            Var = null;
                        }else { sids = variables(AS_tiptok);}
                    }else if (AS_tiptok != "ID")
                    {
                        if (AS_lexema == "Begin" && AS_tiptok == "PR")
                        {
                            TablaDeDerivacion.Text = $"{txtactualizado}->ProgramIDVarID" + sids + "BeginS\n";
                            txtactualizado = TablaDeDerivacion.Text;
                            c = n; n = 0;
                            aquivaC.Text = c.ToString();
                            casoEsp++;
                        }else
                        { casoEsp = 0; }
                    }
                    else
                    { casoEsp = 0; }
                    break;

                //Se espera Iniziacizacion de esos datos siendo que estos sean iguales a los que se declararon
                case 5:
                    inivar(AS_lexema, AS_tiptok, AS_tdata);
                    break;
                case 6:
                    //Analizador Sintactico de Sentencias
                    senSsen(AS_lexema, AS_tiptok, AS_tdata);
                    break;
            }
        }


        //Metodo que nos hace la derivacion de los IDs declarados
        public string variables(string AS_tiptok)
        {

            // Genera una cadena con "ID" repetido n veces
            string idsRepetidos = "";
            for (int i = 0; i < n; i++)
            {
                idsRepetidos += AS_tiptok;
            }

            TablaDeDerivacion.Text = $"{txtactualizado}->ProgramIDVarID" + idsRepetidos + "S";
            txtactualizado = TablaDeDerivacion.Text;
            n++;

            return idsRepetidos;
        }



        //Este metodo es el que inicializa las variables
        public void inivar(string AS_lexema, string AS_tiptok, string AS_tdata)
        {
            
            if (con<c)
            {
                switch (opc)
                {
                    case 0:
                        TablaDeDerivacion.Text = "ERROR SINTACTICO";
                        EDAS.Text = "INVALIDO";
                        opc = 1;
                        break;
                    case 1:
                        if (AS_tiptok == "ID")
                        {
                            opc++;
                        }
                        else
                        { opc = 0; }
                        break;
                    case 2:
                        if (AS_tiptok == "AS" && AS_lexema == "=")
                        {
                            opc++;
                        }
                        else
                        { opc = 0; }
                        break;
                    case 3:
                        if (AS_tiptok == "NE" || AS_tiptok == "ND")
                        {
                            string inDer1 = "IDASnum";
                            for (int i = 0; i < con; i++)
                            {
                                inDer1 += "IDASnum";
                            }
                            TablaDeDerivacion.Text = $"{txtactualizado}->ProgramIDVarID" + sids + "Begin" + inDer1 + "S";
                            txtactualizado = TablaDeDerivacion.Text;

                            string inDer = "ID=num";
                            for (int i = 0; i < con; i++)
                            {
                                inDer += "ID=num";
                            }
                            Sinis = inDer;
                            TablaDeDerivacion.Text = $"{txtactualizado}->ProgramIDVarID" + sids + "Begin" + inDer + "S";
                            txtactualizado = TablaDeDerivacion.Text;
                            opc = 1;
                            con++;
                            aquivaCON.Text = con.ToString();
                        }
                        else
                        { opc = 0; }
                        break;

                }
            }else{ 
                casoEsp++;
                senSsen(AS_lexema, AS_tiptok, AS_tdata);
            }
        }
        
        //Metodo que crea la pila de las sentencias
        public void CreaciondePilaSen(string AS_lexema, string AS_tiptok, string AS_tdata)
        {
            PiladeSentencias nuevoToken2;
            nuevoToken2 = new PiladeSentencias(AS_lexema, AS_tiptok, AS_tdata);
            SenS.Add(nuevoToken2);
        }
        public void BorrarPila()
        {
            SenS.Clear();
            AS_Tokens.Clear();
        }

        //Contador de Cuantos tokens hay en las sentencias
        public int Contadordesentencias()
        {
            return SenS.Count;
        }

        //Metodo de derivacion de sentencias
        public void senSsen(string AS_lexema, string AS_tiptok, string AS_tdata)
        {
            StringBuilder sb = new StringBuilder(txtactualizado);
            CreaciondePilaSen(AS_lexema, AS_tiptok, AS_tdata);
                switch (Sop)
                {
                    case 0:
                        if (AS_tiptok == "ID")
                        {
                            //Lo primero que se espera es un ID para inicializar
                            TablaDeDerivacion.Text = $"{txtactualizado}->ProgramIDVarID" + sids + "Begin" + Sinis + "idS";
                            txtactualizado = TablaDeDerivacion.Text;
                            Sop++;
                        }
                        else
                        {
                            TablaDeDerivacion.Text = "ERROR SINTACTICO";
                            EDAS.Text = "INVALIDO";
                        }
                        break;
                    case 1:
                        if (AS_tiptok == "AS" && AS_lexema == "=")
                        {
                            //Lo primero que se espera es un AS para inicializar
                            TablaDeDerivacion.Text = $"{txtactualizado}->ProgramIDVarID" + sids + "Begin" + Sinis + "idASS";
                            txtactualizado = TablaDeDerivacion.Text;
                            TablaDeDerivacion.Text = $"{txtactualizado}->ProgramIDVarID" + sids + "Begin" + Sinis + "id=S";
                            txtactualizado = TablaDeDerivacion.Text;
                            newtxtactualizado = "->ProgramIDVarID" + sids + "Begin" + Sinis + "id=";
                            Sop++;
                        }
                        else
                        {
                            //Error de sintaxis 
                            TablaDeDerivacion.Text = "ERROR SINTACTICO";
                            EDAS.Text = "INVALIDO";
                        }
                        break;
                    case 2:
                            //Espera ID de resultado X = ; Cuenta cuantos ids tiene y los imprime 
                        if (AS_tiptok == "ID")
                        {
                            sb.AppendLine($"{newtxtactualizado}"+"idS");
                            TablaDeDerivacion.Text = sb.ToString();
                            newtxtactualizado = "->ProgramIDVarID" + sids + "Begin" + Sinis + "id=id";
                            idonum = "id";
                            Sop++;
                        }
                        // En caso de que no busca un numero decimal o entero 
                        else if (AS_tiptok == "NE" || AS_tiptok == "ND")
                        {
                        sb.AppendLine($"{newtxtactualizado}" + "numS");
                        TablaDeDerivacion.Text = sb.ToString();
                        newtxtactualizado = "->ProgramIDVarID" + sids + "Begin" + Sinis + "id=num";
                        idonum = "num";
                        Sop++;
                        }
                        //Sino Espera un parentesis abierto para poder realizar una operacion 
                        else if(AS_lexema == "(" && AS_tiptok == "CO")
                        {
                        sb.AppendLine($"{newtxtactualizado}" + "(S");
                        TablaDeDerivacion.Text = sb.ToString();
                        newtxtactualizado = "->ProgramIDVarID" + sids + "Begin" + Sinis + "id=(";
                        parentesis++;
                        Sop = 4;
                        }
                        // Error de sintaxis
                        else
                        {
                            TablaDeDerivacion.Text = "ERROR SINTACTICO";
                            EDAS.Text = "INVALIDO";
                        }
                        break;
                    case 3:
                        // Espera palabra reservada que quiere para revisar que todo este valido 
                        if(AS_lexema == "End" && AS_tiptok == "PR" && parentesis == 0)
                        {
                            sb.AppendLine($"{newtxtactualizado}" + "End");
                            TablaDeDerivacion.Text = sb.ToString();
                            EDAS.Text = "Valida";
                            validacionSintactica();
                            casoEsp = 1;
                         }
                        //Recibe el parentesis para poder cerrar el programa 
                         else if (AS_lexema == ")" && AS_tiptok == "CO")
                        {
                        sb.AppendLine($"{newtxtactualizado}" + ")S");
                        TablaDeDerivacion.Text = sb.ToString();
                        newtxtactualizado = $"{newtxtactualizado}" + ")";
                        parentesis--;
                        Sop = 6; //Sino hay nada regresa un caso 

                        }
                        else
                        //Si el tamanio de la cadena es mayor a cero, empieza con la derivacion 
                        {
                            if (sb.Length > 0 && sb[sb.Length - 1] == 'S')
                            {
                                sb.Remove(sb.Length - 1, 1);
                            }
                            TablaDeDerivacion.Text = sb.ToString();
                            txtactualizado = TablaDeDerivacion.Text;

                            // Empieza a validar si lo que recibe es + o -
                            if (AS_tiptok == "OA" && AS_lexema == "+" || AS_lexema == "-")
                            {
                                //Empieza a derivar 
                                sb.AppendLine($"{newtxtactualizado}" + "US");
                                TablaDeDerivacion.Text = sb.ToString();
                                //Empieza con la derivacion por la parte de suma 
                                if (AS_lexema == "+")
                                {
                                    sb.AppendLine($"{newtxtactualizado}" + "+S");
                                    TablaDeDerivacion.Text = sb.ToString();
                                    txtactualizado = TablaDeDerivacion.Text;
                                    UoO = "+";
                                }
                                else if (AS_lexema == "-")
                                {
                                   //Empieza con la derivacion de la parte de resta
                                    sb.AppendLine($"{newtxtactualizado}" + "-S");
                                    TablaDeDerivacion.Text = sb.ToString();
                                    txtactualizado = TablaDeDerivacion.Text;
                                    UoO = "-";
                                }
                                Sop++;
                            }
                            //Empieza con la validacion para saber si es division o multiplicacion 
                            else if (AS_tiptok == "OA" && AS_lexema == "/" || AS_lexema == "*")
                            {
                                sb.AppendLine($"{newtxtactualizado}" + "OS");
                                TablaDeDerivacion.Text = sb.ToString();

                            //Empieza con la derivacion por la parte de multiplicacion
                            if (AS_lexema == "*")
                                {
                                    sb.AppendLine($"{newtxtactualizado}" + "*S");
                                    TablaDeDerivacion.Text = sb.ToString();
                                    txtactualizado = TablaDeDerivacion.Text;
                                    UoO = "*";
                                }
                            //Empieza con la derivacion por la parte de la division
                                else if (AS_lexema == "/")
                                {
                                    sb.AppendLine($"{newtxtactualizado}" + "/S");
                                    TablaDeDerivacion.Text = sb.ToString();
                                    txtactualizado = TablaDeDerivacion.Text;
                                    UoO = "/";
                                }
                                Sop++;
                            }
                        }
                        break;
                    case 4:
                            //Empieza a recibir IDS para encontrar el valor en la operacion 
                            if (AS_tiptok == "ID")
                            {
                                sb.AppendLine($"{newtxtactualizado}" + UoO + "idS");
                                TablaDeDerivacion.Text = sb.ToString();
                                newtxtactualizado = $"{newtxtactualizado}" + UoO + "id";
                                Sop--;
                            }
                            //Empieza con la NE o ND si es numero decimal empieza con su derivacion 
                            else if (AS_tiptok == "NE" || AS_tiptok == "ND")
                            {
                                sb.AppendLine($"{newtxtactualizado}" + UoO + "numS");
                                TablaDeDerivacion.Text = sb.ToString();
                                newtxtactualizado = $"{newtxtactualizado}" + UoO + "num";
                                Sop--;
                            }
                            //de lo contratio si encuentra un paréntesis
                            else if (AS_lexema == "(" && AS_tiptok == "CO")
                            {
                                //Lo deriva e imprime
                                sb.AppendLine($"{newtxtactualizado}" + "(S");
                                TablaDeDerivacion.Text = sb.ToString();
                                newtxtactualizado = $"{newtxtactualizado}" + UoO + "(";
                                parentesis++;
                                Sop++;
                            }
                            else
                            //Manda a error en caso de que ninguna condicion se haya cumplido
                            {
                                TablaDeDerivacion.Text = "ERROR SINTACTICO";
                                EDAS.Text = "INVALIDO";
                                casoEsp = 0;
                            }
                        
                        break;
                    case 5:
                    // En caso de que en el tipo de token tena un ID
                    if (AS_tiptok == "ID")
                    {
                        // Lo deriva 
                        sb.AppendLine($"{newtxtactualizado}" + "idS");
                        TablaDeDerivacion.Text = sb.ToString();
                        newtxtactualizado = $"{newtxtactualizado}" + "id";
                        //Para después saltar al caso 3
                        Sop = 3;
                    }
                    // si es in numero entero o decimal
                    else if (AS_tiptok == "NE" || AS_tiptok == "ND")
                    {
                        //Lo deriva
                        sb.AppendLine($"{newtxtactualizado}" + "numS");
                        TablaDeDerivacion.Text = sb.ToString();
                        newtxtactualizado = $"{newtxtactualizado}" + "num";
                        //Y también lo manda al caso 3
                        Sop = 3;
                    }
                    // si encuentra un préntesis abierto 
                    else if (AS_lexema == "(" && AS_tiptok == "CO")
                    {
                        //Lo deriva
                        sb.AppendLine($"{newtxtactualizado}" + "(S");
                        TablaDeDerivacion.Text = sb.ToString();
                        newtxtactualizado = $"{newtxtactualizado}" + "(";
                        parentesis++; 
                       //Y regresa a su mismo case para seguir derivando
                        Sop = 5;
                    }
                    else //En caso de que ninguna condición se cumpla, mandará a error
                    {
                        TablaDeDerivacion.Text = "ERROR SINTACTICO";
                        EDAS.Text = "INVALIDO";
                    }

                    break;

                    case 6:
                    //Si la cadena tiene una S al final 
                    if (sb.Length > 0 && sb[sb.Length - 1] == 'S')
                    {
                        //Remueve lo que tiene la cadena (la S)
                        sb.Remove(sb.Length - 1, 1);
                    }
                    TablaDeDerivacion.Text = sb.ToString();
                    txtactualizado = TablaDeDerivacion.Text;

                    // Si el tipo de token tiene algua operacion U
                    if (AS_tiptok == "OA" && AS_lexema == "+" || AS_lexema == "-")
                    {
                        // La deriva
                        sb.AppendLine($"{newtxtactualizado}" + "US");
                        TablaDeDerivacion.Text = sb.ToString();

                        //Condicional para saber si esa U es un + o -
                        if (AS_lexema == "+")
                        {
                            sb.AppendLine($"{newtxtactualizado}" + "+S");
                            TablaDeDerivacion.Text = sb.ToString();
                            txtactualizado = TablaDeDerivacion.Text;
                            UoO = "+";
                        }
                        else if (AS_lexema == "-")
                        {
                            sb.AppendLine($"{newtxtactualizado}" + "-S");
                            TablaDeDerivacion.Text = sb.ToString();
                            txtactualizado = TablaDeDerivacion.Text;
                            UoO = "-";
                        }
                        Sop = 4; //En caso de que cumpla la sentencia se pasa al caso 4
                    }
                    //Si encuantra una operacion / o * (O)
                    else if (AS_tiptok == "OA" && AS_lexema == "/" || AS_lexema == "*")
                    {
                        //Lo deriva con O
                        sb.AppendLine($"{newtxtactualizado}" + "OS");
                        TablaDeDerivacion.Text = sb.ToString();

                        //Condicional para saber si esa O es un * o /
                        if (AS_lexema == "*")
                        {
                            sb.AppendLine($"{newtxtactualizado}" + "*S");
                            TablaDeDerivacion.Text = sb.ToString();
                            txtactualizado = TablaDeDerivacion.Text;
                            UoO = "*";
                        }
                        else if (AS_lexema == "/")
                        {
                            sb.AppendLine($"{newtxtactualizado}" + "/S");
                            TablaDeDerivacion.Text = sb.ToString();
                            txtactualizado = TablaDeDerivacion.Text;
                            UoO = "/";
                        }
                        Sop = 4; //Brinca a la condicional 4

                    }
                    //En caso de que el lexema sea parentesis
                    else if (AS_lexema == ")" && AS_tiptok == "CO")
                    {
                        //Lo deriva
                        sb.AppendLine($"{newtxtactualizado}" + ")S");
                        TablaDeDerivacion.Text = sb.ToString();
                        newtxtactualizado = $"{newtxtactualizado}" + ")";
                        parentesis--; //Y reduce el contador si es parentesis abierto o cerrado
                        Sop = 6;//El contador lo manda al caso 6
                    }
                    //De lo contrario si encuentra un final de código
                    else if(AS_lexema == "End" && AS_tiptok == "PR" && parentesis == 0)
                    {
                        //Lo imprime 
                    sb.AppendLine($"{newtxtactualizado}" + "End");
                    TablaDeDerivacion.Text = sb.ToString();
                    EDAS.Text = "Valida"; //Y lo acepta como sinatix valida
                    validacionSintactica(); //Llama a la funcion que valida la sintaxis
                    casoEsp = 1;
                    }else
                    {
                        //Si no se cumple ninguna condicion manda a error sintactico
                        TablaDeDerivacion.Text = "ERROR SINTACTICO";
                        EDAS.Text = "INVALIDO";
                    }
                    break;
            }
        }

        //Funcion para imprimir si la sintaxis final fue válida o no 
        public bool validacionSintactica()
        {
            if (EDAS.Text == "Valida")
            {
                ValAS = true;
            }
            else
            {
                ValAS = false;
            }
            return ValAS;
        }
    }
}