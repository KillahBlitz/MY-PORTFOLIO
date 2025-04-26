using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Linq;


namespace COMPILADOR
{
    public partial class usrAL : UserControl
    {

        //Constructor de la clase inicial
        public usrAL()
        {
            InitializeComponent();
        }

        //ABECEDARIOS QUE NECESITARE PARA EL ANALIZADOR LEXICO
        public char[] ABC = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
        public char[] NUM = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        public char[] SIGNOS = { '+', '-' };
        public char[] SIMBOLOS = { '#', '"', '@', '/', '$', '!', '%', '&', '(', ')', '=', '?', '¿', ':', ';', ',', '.', '_', '´' };
        public char[] OL = { '&', '|', '!' };
        public char[] OR = { '<', '>', '=' };
        public char[] OA = { '+', '-','/','*','%', '=' };
        public string[] PR = { "Program", "Var", "Begin", "End", "Para", "Si", "begin", "end", "Leer", "Escribir" };
        public string[] TipoDD = {"int", "float" };
        public string[] Parentesis = { "(", ")" };
        public string Demilitador = ";";
        public string Separador = ",";



        //declaracion de la variable mas importante, la cadena ingresada
        public string PAL { get; set; }
        public List<Token> tokens = new List<Token>();

        //DECLARACION DE VARIABLES
        int contador;
        char let;
        char[] E;
        string lastTDD;
        string TDD = null;
        bool coma = false;
        bool ValAL = false;




        //Constructor para realizar una memoria dinamica y poder tener la tabla de tokens
        public class Token
        {
            public string Tok { get; set; }
            public string Tip { get; set; }
            public string DATAT { get; set; }
            public int Num { get; set; }

            private static int nextnumber = 1;

            public Token(string palabra, string tipoToken, string TipoDeD)
            {
                Tok = palabra;  // Usa el parámetro palabra para asignar a Tok
                Tip = tipoToken;  // Usa el parámetro tipoToken para asignar a Tip
                DATAT = TipoDeD; //Parametro para guardar el tipo de dato
                Num = nextnumber++;  // Usa el parámetro numero para asignar a Num
            }

            // Método estático para resetear el contador
            public static void ResetNumber()
            {
                nextnumber = 1;
            }
        }

        private void usrAL_Load(object sender, EventArgs e)
        {

        }


        //este es el boton principal que manda la cadena ingresada
        private void Chars_Click(object sender, EventArgs e)
        {
            lectordeentrada();
        }

        //este es el boton que me agrega un archivo txt y lee su contenido
        private void txtadd_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Title = "Open Text File";
            openFileDialog.Filter = "Text Files (*.txt)|*.txt";
            openFileDialog.Multiselect = false;  // Permitir seleccionar solo un archivo

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                // Leer todo el contenido del archivo
                string fileContent = System.IO.File.ReadAllText(openFileDialog.FileName);

                // Establecer el contenido leído como el texto del Ingresador
                Ingresador.Text = fileContent;

                // Llama a la función que maneja la lógica del procesamiento
                lectordeentrada();
            }
        }


        //estado de agregacion en los botones
        public void lectordeentrada()
        {
            string data1;

            // Limpiar la lista de tokens y la interfaz de visualización
            Token.ResetNumber();
            tokens.Clear();
            TabladeTokens1.Text = "";

            //Declaracion de variables
            //Inicializacion de el texto ingresado
            asing();

            data1 = AnalizadorTexto();

            //Parte del codigo para el contador de caracteres ingresados
            contador = Contando(PAL);
            TextContadora.Text = contador.ToString();
            ImprimirTokens();
        }





        //Funcion de usuario que nos cuenta cuantos digitos ingresamos
        private int Contando(string PAL)
        {
            int i = 0;
            if (PAL != null)
            {
                while (i < PAL.Length) //.Length es una funcion que nos permite contar los elementos del string
                {
                    i++;
                }
            }
            return i;
        }


        //funcion de usuario que me analiza el texto y cada que vea un espacio toma un nuevo token y realiza la funcion nuevamente

        // función AnalizadorTexto modificada
        public string AnalizadorTexto()
        {
            string entrada = Ingresador.Text;
            string[] delimiters = { " ", "\t", "\r", "\n" }; // Delimitadores: espacio, tabulación, retorno de carro, salto de línea
            string[] tokens = entrada.Split(delimiters, StringSplitOptions.RemoveEmptyEntries); // Dividir la cadena por delimitadores y eliminar entradas vacías
            string datafinall = "";

            foreach (string token in tokens)
            {
                // Limpia la cadena token si es necesario
                string cleanToken = token.Trim(); // Elimina espacios en blanco

                if (!string.IsNullOrEmpty(cleanToken))
                {
                    int container = Contando(cleanToken);
                    // Verifica si el token es un tipo de dato y lo asigna a TDD si es así
                    if (TipoDD.Contains(cleanToken))
                    {
                        TDD = cleanToken;
                        lastTDD = TDD;
                    }
                    else if (Separador.Contains(cleanToken) || Demilitador.Contains(cleanToken))
                    {
                        
                        if (Separador.Contains(cleanToken))
                        {
                            coma = true;
                        }
                        else if (Demilitador.Contains(cleanToken))
                        {
                            lastTDD = null;
                        }

                    }
                    else
                    {
                        // Si no es un tipo de dato, es una variable, así que agrega un token con el tipo de dato temporal
                        // (si existe) y luego lo reinicia para la siguiente variable
                        if (!string.IsNullOrEmpty(TDD))
                        {
                            container = Contando(cleanToken);
                            datafinall = AutomataAsignador(cleanToken, container, TDD); // Procesa cada token con el tipo de dato temporal
                            TDD = null; // Reinicia el tipo de dato temporal después de usarlo
                        }
                        else
                        {
                            // Si no hay un tipo de dato temporal, simplemente procesa el token sin tipo de dato
                            container = Contando(cleanToken);
                            datafinall = AutomataAsignador(cleanToken, container, null); // Procesa cada token sin un tipo de dato temporal
                        }
                    }
                }
            }
            return datafinall;
        }



        //esta funcion es el automata final de los posibles tokens
        public string AutomataAsignador(string PAL, int container, string TDD)
        {
            E = PAL.ToArray();
            int caso = 0, i = 0, p = 0;
            bool Band = false;
            string tiptok;
            //for (i = 0; i < container; i++)
            while (i < container)
            {
                let = E[i];
                switch(caso)
                {
                    //Estado inicial del automata
                    case 0:
                        if (PR.Contains(PAL))
                        {
                            caso = 16;
                        }
                        else if(Parentesis.Contains(PAL))
                        {
                            caso = 18;
                        }
                        else if (TipoDD.Contains(PAL))
                        {
                            lastTDD = PAL;
                            TDD = PAL;
                            caso = 17;
                        }
                        else if (Separador.Contains(PAL))
                        {
                            caso = 19;
                            coma = true;
                        }
                        else if (Demilitador.Contains(PAL))
                        {
                            caso = 20;
                            lastTDD = null;
                        }
                        else if (let == '-' || let == '+')
                        {
                            caso = 2;
                        }
                        else if (NUM.Contains(let))
                        {
                            caso = 3;
                        }
                        else if (let == '&')
                        {
                            caso = 9;
                        }
                        else if (let == '|')
                        {
                            caso = 10;
                        }
                        else if (let == '!' && container == 1)
                        {
                            caso = 11;
                        }
                        else if (let == '*' || let == '%' || let == '/')
                        {
                            caso = 12;
                        }
                        else if (let == '<' || let == '>')
                        {
                            caso = 14;
                        }
                        else if (ABC.Contains(let))
                        {
                            if (coma == true) { TDD = lastTDD; coma = false; }
                            caso = 1;
                        }
                        else if(let == '=')
                        {
                            caso = 19;
                        }
                        else { Band = true; }
                        break;



                    //Todos los estados del automata, EDA abreviacion de ESTADO DE ACEPTACION
                    case 1:
                        //EDA PARA ID ES IGUAL A 1
                        if (ABC.Contains(let) || NUM.Contains(let))
                        { caso = 1; }
                        else { Band = true; }
                        break;

                    case 2:
                        //EDA PARA OA ES IGUAL A 2
                        if (NUM.Contains(let)) { caso = 3; }
                        else { Band = true; }
                        break;

                    case 3:
                        //EDA PARA NE ES IGUAL A 3
                        if (NUM.Contains(let)) { caso = 3; }
                        else if (let == '.') { caso = 4; }
                        else { Band = true; }
                        break;

                    case 4:
                        if (NUM.Contains(let)) { caso = 5; }
                        else { Band = true; }
                        break;

                    case 5:
                        //EDA PARA ND ES IGUAL A 4
                        if (NUM.Contains(let)) { caso = 5; }
                        else if (let == 'e' || let == 'E') { caso = 6; }
                        else { Band = true; }
                        break;

                    case 6:
                        if (let == '-' || let == '+') { caso = 7; }
                        else { Band = true; }
                        break;

                    case 7:
                        if (NUM.Contains(let)) { caso = 8; }
                        else { Band = true; }
                        break;

                    case 8:
                        //EDA PARA NEx ES IGUAL A 5
                        if (NUM.Contains(let)) { caso = 8; }
                        else { Band = true; }
                        break;

                    case 9:
                        if (let == '&' && container == 2) { caso = 11; }
                        else { Band = true; }
                        break;

                    case 10:
                        if (let == '|' && container == 2) { caso = 11; }
                        else { Band = true; }
                        break;

                    case 11:
                        //EDA PARA OL ES IGUAL A 6
                        Band = false;
                        break;

                    case 12:
                        //EDA PARA OA ES IGUAL A 2
                        if (let == '=' || let == '!' && E[0] == '=') { caso = 15; }
                        else { Band = true; }
                        break;

                    case 13:
                        Band = false;
                        break;

                    case 14:
                        //EDA PARA OR ES IGUAL A 8
                        if (let == '=') { caso = 15; }
                        else { Band = true; }
                        break;

                    case 15:
                        Band = false;
                        break;
                    case 16:
                        caso = 16;
                        break;
                    case 17:
                        caso = 17;
                        break;
                    //EDA PARA CO ES IGUAL A 9
                    case 18:
                        caso = 18;
                        break;
                    //EDA PARA OS ES IGUAL A 10
                    case 19:
                        caso = 19;
                        break;
                    case 20:
                        caso = 20;
                        break;
                }
            i++;
            }

            if (Band == true)
            {
                TextAsignador.Text = "ERROR LEXICO"; TextValidacion.Text = "Invalida";
                caso = 0;
            }

            if (caso == 1)
            {
                p = 1;
                Band = false;
            }
            else if (caso == 2 || caso == 12)
            {
                p = 2;
                Band = false;
            }
            else if (caso == 3)
            {
                p = 3;
                Band = false;
            }
            else if (caso == 5)
            {
                p = 4;
                Band = false;
            }
            else if (caso == 8)
            {
                p = 5;
                Band = false;
            }
            else if (caso == 11)
            {
                p = 6;
                Band = false;
            }
            else if (caso == 14 || caso == 15)
            {
                p = 7;
                Band = false;
            }
            else if (caso == 16)
            {
                p = 8;
                Band = false;
            }
            else if (caso == 17)
            {
                Band = false;
            }
            else if (caso == 18)
            {
                p = 9;
                Band = false;
            }
            else if (caso == 19)
            {
                p = 10;
                Band = false;
            }
            else if (caso == 20)
            {
                p = 11;
                Band = false;
            }
            else { TextAsignador.Text = "ERROR LEXICO"; p = 0; Band = true; }
            tiptok = AsignacionTT(p);


            if (tiptok != null)
            {
                if (Band == false) { TextValidacion.Text = "Valida"; validacionLexica(); }
                else if (Band == true) { TextValidacion.Text = "Invalida"; }
                else { TextValidacion.Text = "ERROR"; }
                if (p == 3) { TDD = "int"; } else if (p == 4) { TDD = "float"; }

                AgregarToken(PAL, tiptok, ref TDD);
                //TDD = null;
            }
            else
            {
                TextValidacion.Text = "ERROR";
                Token.ResetNumber();
                tokens.Clear();
                TabladeTokens1.Text = "";
            }

            return PAL;
        }


        //esta parte del codigo asigna el tipo de token por el primer digito ingresado
        public string AsignacionTT(int EDA)
        {
            string Tiptop;
            if (EDA == 1)
            {
                TextAsignador.Text = "ID";
                Tiptop = "ID";
            }
            else if (EDA == 2)
            {
                TextAsignador.Text = "OA";
                Tiptop = "OA";
            }
            else if (EDA == 3)
            {
                TextAsignador.Text = "NE";
                Tiptop = "NE";

            }
            else if (EDA == 4)
            {
                TextAsignador.Text = "ND";
                Tiptop = "ND";
            }
            else if (EDA == 5)
            {
                TextAsignador.Text = "NEx";
                Tiptop = "NEx";
            }
            else if (EDA == 6)
            {
                TextAsignador.Text = "OL";
                Tiptop = "OL";
            }
            else if (EDA == 7)
            {
                TextAsignador.Text = "OR";
                Tiptop = "OR";
            }
            else if (EDA == 8)
            {
                TextAsignador.Text = "PR";
                Tiptop = "PR";
            }
            else if(EDA == 9)
            {
                TextAsignador.Text = "CO";
                Tiptop = "CO";
            }
            else if (EDA == 10)
            {
                TextAsignador.Text = "AS";
                Tiptop = "AS";
            }
            else if (EDA == 11)
            {
                TextAsignador.Text = "FF";
                Tiptop = "FF";
            }
            else
            {
                TextAsignador.Text = "ERROR";
                TextValidacion.Text = "Invalida";
                Tiptop = null;
            }
            return Tiptop;
        }







        public void AgregarToken(string pal, string tip, ref string TDD)
        {
            Token nuevoToken;
            if (TDD != null)
            {
                // Si hay un tipo de dato guardado en TDD, usarlo al crear el nuevo token
                nuevoToken = new Token(pal, tip, TDD);
                TDD = null; // Reiniciar TDD después de usarlo
            }
            else
            {
                // Si no hay un tipo de dato guardado en TDD, crear el token sin tipo de dato
                nuevoToken = new Token(pal, tip, "");
            }
            tokens.Add(nuevoToken);
        }



        public void ImprimirTokens()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine("Token:     Tipo:     Dato:     Numero:");
            foreach (Token token in tokens)
            {
                sb.AppendLine($"{token.Tok}     {token.Tip}     {token.DATAT}     {token.Num}");
            }
            TabladeTokens1.Text = sb.ToString();  // Esto establece el texto una vez con todos los tokens acumulados.
        }



        //Funcion de usuario que sirve como inializador del texto ingresado deseado
        private void asing()
        {
            PAL = Convert.ToString(Ingresador.Text);
        }


        public bool validacionLexica()
        {
            if (TextValidacion.Text == "Valida")
            {
                ValAL = true;
            }
            else
            {
                ValAL = true;
            }
            return ValAL;
        }


    }

}