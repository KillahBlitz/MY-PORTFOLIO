using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using static COMPILADOR.usrAL;

namespace COMPILADOR
{
    public partial class usrCIP : UserControl
    {
        public usrCIP()
        {
            InitializeComponent();
            cadenadePolacas = new List<CadenadePolaca>(); // Inicializa la lista aquí
            postfijas = new List<postfija>();
        }

        public class CadenadePolaca
        {
            public string token { get; set; }

            public CadenadePolaca(string dato)
            {
                token = dato;  // Usa el parámetro palabra para asignar a Tok
            }
        }

        public class postfija
        {
            public string elemento;

            public postfija(string dato)
            {
                elemento = dato;
            }
        }

        public List<CadenadePolaca> cadenadePolacas { get; set; }
        public List<postfija> postfijas { get; set; }
        public List<usrAM.SentenciaFinal> POLACA { get; set; }

        public string[] NUM = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

        bool val1 = false, val2 = false, val3 = false;
        bool numero = false;
        string infija = "";  //Aquí se almacena la postfija
        string ADP = "";
        string DDP = "";
        string asignador;

        public void ReciveEDOS(bool x, bool y, bool z)
        {
            val1 = x;
            val2 = y;
            val3 = z;
        }

        public void ReceiveSen(List<usrAM.SentenciaFinal> list)
        {
            POLACA = list;
        }

        private void usrCIP_Load(object sender, EventArgs e)
        {
        }

        private void COMPILAR_Click(object sender, EventArgs e)
        {
            if (val1 == false && val2 == false && val3 == false)     //000
            {
                txtval1.Text = "Invalido";
                txtval2.Text = "Invalido";
                txtval3.Text = "Invalido";
            }
            else if (val1 == true && val2 == false && val3 == false) //100
            {
                txtval1.Text = "Valido";
                txtval2.Text = "Invalido";
                txtval3.Text = "Invalido";
            }
            else if (val1 == false && val2 == true && val3 == false) //010
            {
                txtval1.Text = "Invalido";
                txtval2.Text = "Valido";
                txtval3.Text = "Invalido";
            }
            else if (val1 == true && val2 == true && val3 == false) //110
            {
                txtval1.Text = "Valido";
                txtval2.Text = "Valido";
                txtval3.Text = "Invalido";
            }
            else if (val1 == false && val2 == false && val3 == true) //001
            {
                txtval1.Text = "Invalido";
                txtval2.Text = "Invalido";
                txtval3.Text = "Valido";
            }
            else if (val1 == true && val2 == false && val3 == true) //101
            {
                txtval1.Text = "Valido";
                txtval2.Text = "Invalido";
                txtval3.Text = "Valido";
            }
            else if (val1 == false && val2 == true && val3 == true) //011
            {
                txtval1.Text = "Invalido";
                txtval2.Text = "Valido";
                txtval3.Text = "Valido";
            }
            else if (val1 == true && val2 == true && val3 == true) //111
            {
                txtval1.Text = "Valido";
                txtval2.Text = "Valido";
                txtval3.Text = "Valido";
                RealizacionCIP();
                GenerarCodigoIntermedio();
            }
        }

        public void RealizacionCIP()
        {
            usrAM.SentenciaFinal p = POLACA[0];
            StringBuilder concatena = new StringBuilder();
            if (POLACA != null && POLACA.Count > 0)
            {
                foreach (var Polaca in POLACA)
                {
                    if (Polaca.AM_TipToken == "ID" && Polaca.AM_Token != p.AM_Token)
                    {
                        concatena.Append($"{Polaca.AM_Valor} ");
                        PiladePolaca(Polaca.AM_Valor);
                    }
                    else
                    {
                        concatena.Append($"{Polaca.AM_Token} ");
                        PiladePolaca(Polaca.AM_Token);
                    }
                }
            }
            infija = concatena.ToString();
            Cadena.Text = infija; //concatena.ToString();
        }

        public void PiladePolaca(string dato)
        {
            if (cadenadePolacas == null)
            {
                cadenadePolacas = new List<CadenadePolaca>();
            }
            CadenadePolaca d = new CadenadePolaca(dato);
            cadenadePolacas.Add(d);
        }

        public void GenerarCodigoIntermedio()
        {
            Stack<string> pilaOperandos = new Stack<string>();
            Stack<string> pilaOperadores = new Stack<string>();
            List<string> codigoIntermedio = new List<string>();
            StringBuilder nuevaPila = new StringBuilder();
            int tempCount = 1;
            string postfija;

            try
            {
                foreach (var item in cadenadePolacas)
                {
                    string token = item.token;

                    if (char.IsLetterOrDigit(token[0]) || token.Contains(".") || (token.Contains("-") && token.Any(char.IsDigit))) // Si es operando
                    {
                        pilaOperandos.Push(token);
                    }
                    else if (token == "(") // Si es un paréntesis izquierdo
                    {
                        pilaOperadores.Push(token);
                    }
                    else if (token == ")") // Si es un paréntesis derecho
                    {
                        while (pilaOperadores.Peek() != "(")
                        {
                            if (pilaOperadores.Count == 0)
                            {
                                throw new InvalidOperationException("Paréntesis desbalanceados.");
                            }

                            string operador = pilaOperadores.Pop();
                            string operando2 = pilaOperandos.Pop();
                            string operando1 = pilaOperandos.Pop();
                            string temp = $"T{tempCount++}";
                            codigoIntermedio.Add($"{temp} = {operando1} {operando2} {operador}\t {OperadorToAssembly(operador)}");
                            pilaOperandos.Push(temp);
                            nuevaPila.Append($" {operando1} {operando2} {operador} ");
                        }
                        pilaOperadores.Pop(); // Eliminar el paréntesis izquierdo
                    }
                    else // Si es un operador
                    {
                        while (pilaOperadores.Count > 0 && Precedencia(token) <= Precedencia(pilaOperadores.Peek()))
                        {
                            string operador = pilaOperadores.Pop();
                            string operando2 = pilaOperandos.Pop();
                            string operando1 = pilaOperandos.Pop();
                            string temp = $"T{tempCount++}";
                            codigoIntermedio.Add($"{temp} = {operando1} {operando2} {operador}\t {OperadorToAssembly(operador)}");
                            pilaOperandos.Push(temp);
                            nuevaPila.Append($" {operando1} {operando2} {operador} ");
                        }
                        pilaOperadores.Push(token);
                    }
                }

                while (pilaOperadores.Count > 0)
                {
                    if (pilaOperadores.Peek() == "(")
                    {
                        throw new InvalidOperationException("Paréntesis desbalanceados.");
                    }

                    string operador = pilaOperadores.Pop();
                    string operando2 = pilaOperandos.Pop();
                    string operando1 = pilaOperandos.Pop();
                    string temp = $"T{tempCount++}";
                    codigoIntermedio.Add($"{temp} = {operando1} {operando2} {operador}\t {OperadorToAssembly(operador)}");
                    pilaOperandos.Push(temp);
                    nuevaPila.Append($" {operando1} {operando2} {operador} ");
                }

            }
            catch (InvalidOperationException ex)
            {
                MessageBox.Show($"Error al generar el código intermedio: {ex.Message}");
                return;
            }

            // Mostrar código intermedio
            StringBuilder sb = new StringBuilder();
            sb.AppendLine("Sentencia\tOperación\tTemporal");
            foreach (var linea in codigoIntermedio)
            {
                string[] partes = linea.Split(new char[] { '=' }, 2);
                if (partes.Length == 2)
                {
                    string operacion = partes[1].Trim();
                    string temporal = partes[0].Trim();
                    sb.AppendLine($"{operacion}\t{temporal}");
                }
            }
            sb.AppendLine(nuevaPila.ToString());
            CI.Text = sb.ToString();
            postfija = nuevaPila.ToString();
            traductrensamble(postfija);

        }

        private int Precedencia(string operador)
        {
            switch (operador)
            {
                case "+":
                case "-":
                    return 1;
                case "*":
                case "/":
                    return 2;
                case "=":
                    return 0; // Baja precedencia para "="
                default:
                    return 0;
            }
        }

        private string OperadorToAssembly(string operador)
        {
            switch (operador)
            {
                case "+":
                    return "add";
                case "-":
                    return "sub";
                case "*":
                    return "mul";
                case "/":
                    return "div";
                case "=":
                    return "mov";
                default:
                    return operador;
            }
        }

        private void traductrensamble(string postfija)
        {
            int tempcont = 1;
            int tempcon = 0;
            string temp;
            // Divide la cadena en elementos separados por espacio
            string[] elementos = postfija.Split(new[] { " ", "\t", "\r", "\n" }, StringSplitOptions.RemoveEmptyEntries);
            StringBuilder CodEnsamblador = new StringBuilder();

            // Agrega cada elemento a la pila
            foreach (string elemento in elementos)
            {
                PilaPostfija(elemento);
            }


            CodEnsamblador.AppendLine("macro float");
            CodEnsamblador.AppendLine("mov cl, 10");
            CodEnsamblador.AppendLine("mul cl");
            CodEnsamblador.AppendLine("endm");
            CodEnsamblador.AppendLine(" ");
            CodEnsamblador.AppendLine(" ");
            CodEnsamblador.AppendLine("macro negativo");
            CodEnsamblador.AppendLine("neg ax");
            CodEnsamblador.AppendLine("mov resultado,ax");
            CodEnsamblador.AppendLine("mov cl, 10");
            CodEnsamblador.AppendLine("mov ah,02");
            CodEnsamblador.AppendLine("mov dl,'-'");
            CodEnsamblador.AppendLine("int 21h");
            CodEnsamblador.AppendLine("mov ax,resultado");
            CodEnsamblador.AppendLine("endm");
            CodEnsamblador.AppendLine(" ");
            CodEnsamblador.AppendLine(" ");
            CodEnsamblador.AppendLine("macro algoritmia99full");
            CodEnsamblador.AppendLine("aam");
            CodEnsamblador.AppendLine("mov bx,ax");
            CodEnsamblador.AppendLine("add bx,3030h");
            CodEnsamblador.AppendLine(" ");
            CodEnsamblador.AppendLine("mov ah,02");
            CodEnsamblador.AppendLine("mov dl,bh");
            CodEnsamblador.AppendLine("int 21h");
            CodEnsamblador.AppendLine("mov ah,02");
            CodEnsamblador.AppendLine("mov dl,bl");
            CodEnsamblador.AppendLine("int 21h");
            CodEnsamblador.AppendLine("endm");
            CodEnsamblador.AppendLine(" ");
            CodEnsamblador.AppendLine("macro algoritmiadecfull");
            CodEnsamblador.AppendLine("mov bx,10");
            CodEnsamblador.AppendLine("div bx");
            CodEnsamblador.AppendLine("mov cl,dl");
            CodEnsamblador.AppendLine("aam");
            CodEnsamblador.AppendLine("mov bx,ax");
            CodEnsamblador.AppendLine("add bx,3030h");
            CodEnsamblador.AppendLine("mov ah,02");
            CodEnsamblador.AppendLine("mov dl,bh");
            CodEnsamblador.AppendLine("int 21h");
            CodEnsamblador.AppendLine("mov ah,02");
            CodEnsamblador.AppendLine("mov dl,bl");
            CodEnsamblador.AppendLine("int 21h");
            CodEnsamblador.AppendLine("mov bl, cl");
            CodEnsamblador.AppendLine("add bl,30h");
            CodEnsamblador.AppendLine("mov ah,02");
            CodEnsamblador.AppendLine("mov dl,bl");
            CodEnsamblador.AppendLine("int 21h");
            CodEnsamblador.AppendLine("endm");
            CodEnsamblador.AppendLine(" ");
            CodEnsamblador.AppendLine("macro algoritmia1000full");
            CodEnsamblador.AppendLine("mov bx,100");
            CodEnsamblador.AppendLine("div bx");
            CodEnsamblador.AppendLine("mov cl,dl");
            CodEnsamblador.AppendLine("aam");
            CodEnsamblador.AppendLine("mov bx,ax");
            CodEnsamblador.AppendLine("add bx,3030h");
            CodEnsamblador.AppendLine("mov ah,02");
            CodEnsamblador.AppendLine("mov dl,bh");
            CodEnsamblador.AppendLine("int 21h");
            CodEnsamblador.AppendLine("mov ah,02");
            CodEnsamblador.AppendLine("mov dl,bl");
            CodEnsamblador.AppendLine("int 21h");
            CodEnsamblador.AppendLine("mov al, cl");
            CodEnsamblador.AppendLine("aam");
            CodEnsamblador.AppendLine("mov bx,ax");
            CodEnsamblador.AppendLine("add bx,3030h");
            CodEnsamblador.AppendLine("mov ah,02");
            CodEnsamblador.AppendLine("mov dl,bh");
            CodEnsamblador.AppendLine("int 21h");
            CodEnsamblador.AppendLine("mov ah,02");
            CodEnsamblador.AppendLine("mov dl,bl");
            CodEnsamblador.AppendLine("int 21h");
            CodEnsamblador.AppendLine("endm");
            CodEnsamblador.AppendLine(" ");

            CodEnsamblador.AppendLine(".model small");
            CodEnsamblador.AppendLine(".data");

            if (postfijas != null && postfijas.Count > 0)
            {
                foreach (var temporales in postfijas)
                {
                    string E = temporales.elemento;
                    char[] e = E.ToCharArray();
                    if (e[0] == 'T')
                    {
                        temp = $"T{tempcont++}";
                        CodEnsamblador.AppendLine($"{temp} dw 0");
                    }
                }
            }

            if (postfijas != null && postfijas.Count > 0)
            {
                foreach (var temporales in postfijas)
                {
                    string E = temporales.elemento;
                    char[] e = E.ToCharArray();
                    if (char.IsLetter(e[0]) && e[0] != 'T')
                    {
                        CodEnsamblador.AppendLine($"{temporales.elemento} dw 0");
                        asignador = temporales.elemento;
                    }
                }
            }
            CodEnsamblador.AppendLine($" ");
            CodEnsamblador.AppendLine($"aux dw 0");
            CodEnsamblador.AppendLine($"resultado dw 0");
            CodEnsamblador.AppendLine($"resultadodec dw 0");
            CodEnsamblador.AppendLine($" ");
            CodEnsamblador.AppendLine($"Res db 10, 13, 'RESULTADO', 10,13,'$' ");
            CodEnsamblador.AppendLine($"ERRORDIV db 10, 13, 'NO SE PUEDE DIVIDIR ENTRE 0', 10,13,'$' ");
            CodEnsamblador.AppendLine($" ");
            CodEnsamblador.AppendLine($".code");
            CodEnsamblador.AppendLine($"mov ax, @data");
            CodEnsamblador.AppendLine($"mov ds,ax");
            CodEnsamblador.AppendLine($"mov dx, offset Res");
            CodEnsamblador.AppendLine($"mov ah,09h");
            CodEnsamblador.AppendLine($"int 21h");
            CodEnsamblador.AppendLine($" ");
            CodEnsamblador.AppendLine($"xor ax,ax");
            CodEnsamblador.AppendLine($"xor bx,bx");
            CodEnsamblador.AppendLine($"xor cx,cx");
            CodEnsamblador.AppendLine($"xor dx,dx");
            CodEnsamblador.AppendLine($" ");
            CodEnsamblador.AppendLine($" ");
            CE.Text = CodEnsamblador.ToString();

            if (postfijas != null && postfijas.Count > 0)
            {
                int opcion = 0;
                int tmp = 1;
                foreach (var temporales in postfijas)
                {
                    string E = temporales.elemento;
                    char[] e = E.ToCharArray();
                    switch (opcion)
                    {
                        case 0:
                            for (int i = 0; i < e.Length; i++)
                            {
                                if (e[i] == '-' && E.Any(char.IsDigit)) 
                                {
                                    string M = E.Substring(1);
                                    char[] aux = E.ToArray();
                                    if (M.Contains("."))
                                    {
                                        for (int j = 0; j  < e.Length; j++)
                                        {
                                            if (aux[j] == '.')
                                            {
                                                // Guarda todo antes del punto
                                                ADP = M.Substring(0, i);

                                                // Guarda todo después del punto
                                                DDP = M.Substring(i + 1);

                                                CodEnsamblador.AppendLine($"mov ax,{ADP}");
                                                CodEnsamblador.AppendLine($"neg ax");
                                                CodEnsamblador.AppendLine($" ");
                                                break;
                                            }
                                        }
                                        opcion++;
                                        break;
                                    }
                                    else
                                    {
                                        CodEnsamblador.AppendLine($"mov ax,{M}");
                                        CodEnsamblador.AppendLine($"neg ax");
                                        CodEnsamblador.AppendLine($" ");
                                        opcion++;
                                        break;
                                    }

                                }
                                else if (e[i] == '.')
                                {
                                    // Guarda todo antes del punto
                                    ADP = E.Substring(0, i);

                                    // Guarda todo después del punto
                                    DDP = E.Substring(i + 1);

                                    CodEnsamblador.AppendLine($"mov ax,{ADP}");
                                    CodEnsamblador.AppendLine($" ");
                                    opcion++;
                                    break;
                                }
                                else if (e[i] != '.' && i + 1 == e.Length && char.IsDigit(E[i]))
                                {
                                    if (!(char.IsLetter(E[0])))
                                    {
                                        CodEnsamblador.AppendLine($"mov ax,{E}");
                                        CodEnsamblador.AppendLine($" ");
                                        opcion++;
                                        break;
                                    }
                                }
                                else if (E == "+" || E == "-" || E == "/" || E == "*")
                                {
                                    if (E == "+")
                                    {
                                        CodEnsamblador.AppendLine($" ");
                                        CodEnsamblador.AppendLine($"add ax,bx");
                                        CodEnsamblador.AppendLine($"mov T{tmp},ax");
                                        CodEnsamblador.AppendLine($" ");
                                        tmp++;
                                        tempcon = tmp - 1;
                                    }
                                    else if (E == "-")
                                    {
                                        CodEnsamblador.AppendLine($" ");
                                        CodEnsamblador.AppendLine($"sub ax,bx");
                                        CodEnsamblador.AppendLine($"mov T{tmp},ax");
                                        CodEnsamblador.AppendLine($" ");
                                        tmp++;
                                        tempcon = tmp - 1;
                                    }
                                    else if (E == "*")
                                    {
                                        CodEnsamblador.AppendLine($" ");
                                        CodEnsamblador.AppendLine($"mul bx");
                                        CodEnsamblador.AppendLine($"mov T{tmp},ax");
                                        CodEnsamblador.AppendLine($" ");
                                        tmp++;
                                        tempcon = tmp - 1;
                                    }
                                    else if (E == "/")
                                    {
                                        CodEnsamblador.AppendLine($" ");
                                        CodEnsamblador.AppendLine($"cmp bx,0000d");
                                        CodEnsamblador.AppendLine($"je errord");
                                        CodEnsamblador.AppendLine($"jnz nerrord");
                                        CodEnsamblador.AppendLine($"errord:");
                                        CodEnsamblador.AppendLine($"mov ax, @data");
                                        CodEnsamblador.AppendLine($"mov ds,ax");
                                        CodEnsamblador.AppendLine($"mov dx, offset ERRORDIV");
                                        CodEnsamblador.AppendLine($"mov ah,09h");
                                        CodEnsamblador.AppendLine($"int 21h");
                                        CodEnsamblador.AppendLine($"jmp salir");
                                        CodEnsamblador.AppendLine($"nerrord:");
                                        CodEnsamblador.AppendLine($"div bx");
                                        CodEnsamblador.AppendLine($"mov T{tmp},ax");
                                        CodEnsamblador.AppendLine($" ");
                                        tmp++;
                                        tempcon = tmp - 1;
                                    }
                                    break;
                                }
                                else if (E == $"T{tempcon}")
                                {
                                    CodEnsamblador.AppendLine($"mov ax,T{tempcon}");
                                    CodEnsamblador.AppendLine($"mov aux,ax");
                                    CodEnsamblador.AppendLine($" ");
                                    opcion++;
                                    break;
                                }
                                else if (E == $"T{tempcon - 1}")
                                {
                                    CodEnsamblador.AppendLine($"mov ax,T{tempcon - 1}");
                                    CodEnsamblador.AppendLine($"mov aux,ax");
                                    CodEnsamblador.AppendLine($" ");
                                    opcion++;
                                    break;
                                }
                                else if (E == asignador)
                                {
                                    CodEnsamblador.AppendLine($"mov ax,T{tempcon}");
                                    CodEnsamblador.AppendLine($"mov {asignador},ax");
                                    opcion = 2;
                                    break;
                                }
                            }
                            break;
                        case 1:
                            for (int i = 0; i < e.Length; i++)
                            {
                                if (e[i] == '-' && E.Any(char.IsDigit))
                                {
                                    string M = E.Substring(1);
                                    char[] aux = E.ToArray();
                                    if (M.Contains("."))
                                    {
                                        for (int j = 0; j < e.Length; j++)
                                        {
                                            if (aux[j] == '.')
                                            {
                                                // Guarda todo antes del punto
                                                ADP = M.Substring(0, i);
                                                // Guarda todo después del punto
                                                DDP = M.Substring(i + 1);

                                                CodEnsamblador.AppendLine($"mov bx,{ADP}");
                                                CodEnsamblador.AppendLine($"neg bx");
                                                CodEnsamblador.AppendLine($" ");
                                                break;
                                            }
                                        }
                                        opcion--;
                                        break;
                                    }
                                    else
                                    {
                                        CodEnsamblador.AppendLine($"mov bx,{M}");
                                        CodEnsamblador.AppendLine($"neg bx");
                                        CodEnsamblador.AppendLine($" ");
                                        opcion--;
                                        break;
                                    }

                                }
                                else if (e[i] == '.')
                                {
                                    // Guarda todo antes del punto
                                    ADP = E.Substring(0, i);
                                    // Guarda todo después del punto
                                    DDP = E.Substring(i + 1);

                                    CodEnsamblador.AppendLine($"mov bx,{ADP}");
                                    CodEnsamblador.AppendLine($" ");
                                    opcion--;
                                    break;
                                }
                                else if (e[i] != '.' && i + 1 == e.Length && char.IsDigit(E[i]))
                                {
                                    if (!(char.IsLetter(E[0])))
                                    {
                                        CodEnsamblador.AppendLine($"mov bx,{E}");
                                        CodEnsamblador.AppendLine($" ");
                                        opcion--;
                                        break;
                                    }
                                }
                                else if (E == $"T{tempcon}")
                                {
                                    CodEnsamblador.AppendLine($"mov bx,T{tempcon}");
                                    CodEnsamblador.AppendLine($" ");
                                    opcion--;
                                    break;
                                }
                            }
                            break;
                        case 2:
                            CodEnsamblador.AppendLine($" ");
                            CodEnsamblador.AppendLine($"mov resultado,ax");
                            CodEnsamblador.AppendLine($" ");
                            CodEnsamblador.AppendLine($" ");
                            CodEnsamblador.AppendLine($"xor ax,ax");
                            CodEnsamblador.AppendLine($"xor bx,bx");
                            CodEnsamblador.AppendLine($"xor cx,cx");
                            CodEnsamblador.AppendLine($"xor dx,dx");
                            CodEnsamblador.AppendLine($" ");
                            CodEnsamblador.AppendLine($"mov ax,resultado");
                            CodEnsamblador.AppendLine($"cmp ax,0d");
                            CodEnsamblador.AppendLine($"js esnegativo");
                            CodEnsamblador.AppendLine($"jns espositivo");
                            CodEnsamblador.AppendLine($"esnegativo:");
                            CodEnsamblador.AppendLine($"negativo");
                            CodEnsamblador.AppendLine($"espositivo:");
                            CodEnsamblador.AppendLine($"xor dx,dx");
                            CodEnsamblador.AppendLine($"cmp ax,99d");
                            CodEnsamblador.AppendLine($"jbe algoritmia99");
                            CodEnsamblador.AppendLine($"ja algoritmiadec");
                            CodEnsamblador.AppendLine($" ");
                            CodEnsamblador.AppendLine($"algoritmia99:");
                            CodEnsamblador.AppendLine($"algoritmia99full");
                            CodEnsamblador.AppendLine($"jmp salir");
                            CodEnsamblador.AppendLine($"algoritmiadec:");
                            CodEnsamblador.AppendLine($"cmp ax,999d");
                            CodEnsamblador.AppendLine($"jbe algoritmiadec1");
                            CodEnsamblador.AppendLine($"ja algoritmia1000");
                            CodEnsamblador.AppendLine($"algoritmiadec1:");
                            CodEnsamblador.AppendLine($"algoritmiadecfull");
                            CodEnsamblador.AppendLine($"jmp salir");
                            CodEnsamblador.AppendLine($"algoritmia1000:");
                            CodEnsamblador.AppendLine($"algoritmia1000full");
                            CodEnsamblador.AppendLine($"jmp salir");
                            CodEnsamblador.AppendLine($" ");
                            CodEnsamblador.AppendLine($" ");
                            CodEnsamblador.AppendLine($" ");
                            CodEnsamblador.AppendLine($"salir:");
                            CodEnsamblador.AppendLine($".exit");

                            opcion++;
                            break;
                    }
                    CE.Text = CodEnsamblador.ToString();
                }
            }
            CreateASM(CodEnsamblador.ToString());
        }

        public void PilaPostfija(string dato)
        {
            postfija d = new postfija(dato);
            postfijas.Add(d);
        }

        public void CreateASM(string CodASM)
        {
            // Crear un SaveFileDialog para permitir al usuario seleccionar la ubicación de guardado
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.Filter = "ASM files (*.asm)|*.asm|All files (*.*)|*.*";
            saveFileDialog.DefaultExt = "asm";
            saveFileDialog.AddExtension = true;
            saveFileDialog.Title = "Guardar archivo ASM";

            // Mostrar el diálogo de guardado y verificar si el usuario seleccionó una ubicación
            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                // Obtener la ruta seleccionada por el usuario
                string asmFilePath = saveFileDialog.FileName;

                try
                {
                    // Crear y escribir en el archivo .asm
                    File.WriteAllText(asmFilePath, CodASM);

                    // Mostrar un MessageBox indicando éxito
                    MessageBox.Show("ASM CREADO CON EXITO", "Éxito", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
                catch (Exception ex)
                {
                    // Mostrar un MessageBox indicando error
                    MessageBox.Show($"Error al crear el archivo ASM: {ex.Message}", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }
    }
}