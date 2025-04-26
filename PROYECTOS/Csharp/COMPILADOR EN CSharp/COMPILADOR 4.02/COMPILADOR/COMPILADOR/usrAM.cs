using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Linq;
using static COMPILADOR.usrAL;
using static COMPILADOR.usrAS;

namespace COMPILADOR
{
    public partial class usrAM : UserControl
    {
        public usrAM()
        {
            InitializeComponent();
        }
        

        public string AM_PAL { get; set; }
        // Propiedad para almacenar la tabla de tokens completa
        public List<usrAL.Token> AM_Tokens { get; set; }
        //Propiedad para almacenar la tabla de Sentencias completa
        public List<usrAS.PiladeSentencias> AM_SenS { get; set; }


        //AQUI VAN LAS FUNCIONES LOS TOKENS Y LA CADENA
        public void ReceivePal(string PAL)
        {
            // Utiliza 'PAL' como necesites dentro de usrAM
            AM_PAL = PAL;
            CadenaFinal.Text = AM_PAL;
        }

        // Método para recibir y mostrar la tabla de tokens
        public void ReceiveTokens(List<usrAL.Token> tokens)
        {
            // Utiliza 'tokens' como necesites dentro de usrAM
            AM_Tokens = tokens;
        }

        public void ReceiveSenS(List<usrAS.PiladeSentencias> SenS)
        {
            // Utiliza 'tokens' como necesites dentro de usrAS
            AM_SenS = SenS;
            PrintSenS();
        }


        public List<Existencia> TokenAM = new List<Existencia>();
        public List<GuardadodeDatos> Guardado = new List<GuardadodeDatos>();
        public List<SentenciaFinal> Atributos = new List<SentenciaFinal>();

        


        public class Existencia
        {
            public string lexema { get; set; }
            public string AM_TipToken { get; set; }

            public Existencia(string palabra)
            {
                lexema = palabra;  // Usa el parámetro palabra para asignar a Tok
                AM_TipToken = "ID";  // Usa el parámetro tipoToken para asignar a Tip
            }
        }


        public class GuardadodeDatos
        {
            public string AM_Token { get; set; }
            public string AM_TipToken { get; set; }
            public string AM_TipDato { get; set; }
            public string AM_Valor { get; set; }
            public string AM_TipNum { get; set; }

            public GuardadodeDatos(string lexema, string TDATA, string VALOR, string Num)
            {
                AM_Token = lexema;  // Usa el parámetro palabra para asignar a Tok
                AM_TipDato = TDATA;
                AM_Valor = VALOR;
                AM_TipNum = Num;
                AM_TipToken = "ID";  // Usa el parámetro tipoToken para asignar a Tip
            }
        }

        public class SentenciaFinal
        {
            public string AM_Token { get; set; }
            public string AM_TipToken { get; set; }
            public string AM_TipDato { get; set; }
            public string AM_Valor { get; set; }
            public string AM_TipNum { get; set; }

            public SentenciaFinal(string lexema, string tiptok, string TipoDato, string Valor, string TipTokNum)
            {
                AM_Token = lexema;  // Usa el parámetro palabra para asignar a Tok
                AM_TipToken = tiptok;  // Usa el parámetro tipoToken para asignar a Tip
                AM_TipDato = TipoDato;
                AM_Valor = Valor;
                AM_TipNum = TipTokNum;
            }
        }


        bool ValAM = false, band = false;
        string lexemaimpuesto, tipodedatoimpuesto;
        string basura;
        int activador = 0;
        StringBuilder sb = new StringBuilder();

        private void usrAM_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            analizacionSemantica();
        }

        public void analizacionSemantica()
        {
            RecorrimientodeSentencias();
            RecorrimientodeReglas();
            SentenciaFinalOsi();
            imp();
            validacionSemantica();
        }

        public void PrintSenS()
        {
            if (AM_SenS != null && AM_SenS.Count > 0)
            {
                StringBuilder sb = new StringBuilder();
                foreach (var SenS in AM_SenS)
                {
                    sb.Append($"{SenS.AS_Token} ");
                }
                SentenciasFinales.Text = sb.ToString();
            }
            else
            {
                SentenciasFinales.Text = "No hay tokens para mostrar.";
            }
        }

        //Metodo que recorre la pila y nos ayuda a la derivacion de las sentencias
        public void RecorrimientodeSentencias()
        {
            if (AM_SenS != null && AM_SenS.Count > 0)
            {
                foreach (var SenS in AM_SenS)
                {
                    if(SenS.AS_TipToken == "ID")
                    {
                        string lexema = SenS.AS_Token;
                            if (AM_Tokens != null && AM_Tokens.Count > 0)
                            {
                                int i = 0;
                                foreach (var tokens in AM_Tokens)
                                {
                                    if (tokens.Tok == lexema && i<1)
                                    {
                                    CrearExistencia(lexema);
                                    i++;
                                    }
                                }
                            }
                    }
                }
                AsignacionIDS.Text = sb.ToString();
            }
        }

        public void RecorrimientodeReglas()
        {
            if (TokenAM != null && TokenAM.Count > 0)
            {
                foreach (var existencia in TokenAM)
                {
                    string dato = existencia.lexema;
                    if (AM_Tokens != null && AM_Tokens.Count > 0)
                    {
                        int i = 0, caso = 0;
                       
                        foreach (var tokens in AM_Tokens)
                        {
                            if (tokens.Tok == dato && i < 2)
                            {
                                if(tokens.DATAT == "int" || tokens.DATAT == "float")
                                {
                                    lexemaimpuesto = tokens.Tok;
                                    tipodedatoimpuesto = tokens.DATAT;
                                    i++;
                                }
                                else
                                {
                                    band = true;
                                    i++;
                                }
                            }else if(band == true)
                            {

                                switch (caso)
                                {
                                    case 0:
                                        if (tokens.Tok == "=" && tokens.Tip == "AS")
                                        {
                                            caso++;
                                        }
                                        break;
                                    case 1:
                                        if (tokens.Tip == "NE" || tokens.Tip == "ND")
                                        {
                                            CrearGuardarDATA(lexemaimpuesto, tipodedatoimpuesto, tokens.Tok, tokens.Tip);
                                            lexemaimpuesto = null;
                                            tipodedatoimpuesto = null;
                                            band = false;
                                        }
                                        break;

                                }
                            }
                        }
                    }

                }
                AsignacionIDS.Text = sb.ToString();
            }
        }


        public void SentenciaFinalOsi()
        {
            if (AM_SenS != null && AM_SenS.Count > 0)
            {
                foreach (var SenS in AM_SenS)
                {
                    if (SenS.AS_TipToken == "ID")
                    {
                        string Tok = SenS.AS_Token;
                        int i = 0;
                        foreach (var Guardado in Guardado)
                        {
                            if(Guardado.AM_Token == Tok && i < 1)
                            {
                                Atributo(Guardado.AM_Token, Guardado.AM_TipToken, Guardado.AM_TipDato, Guardado.AM_Valor, Guardado.AM_TipNum);
                                i++;
                            }
                        }
                    }else if(SenS.AS_Token == "End" && SenS.AS_TipToken == "PR")
                    {
                        basura = null;
                    }
                    else
                    {
                        Atributo(SenS.AS_Token, SenS.AS_TipToken, SenS.AS_TipDato,"","");
                    }
                }
            }
        }



        public void imp()
        {
            if (Atributos != null && Atributos.Count > 0)
            {
                StringBuilder sb1 = new StringBuilder();
                SentenciaFinal primeroenlalista = Atributos[0];
               if (primeroenlalista.AM_TipDato == "int")
                {
                    activador = 1;
                }else if (primeroenlalista.AM_TipDato == "float")
                {
                    activador = 2;
                }
                sb1.AppendLine($"{primeroenlalista.AM_Token + " " + primeroenlalista.AM_TipDato}"+ " " + activador.ToString() + " EL primer dato encontrado");
                foreach (var Atributos in Atributos)
                {
                    if(activador == 1 && (Atributos.AM_TipToken == "/" || Atributos.AM_TipDato == "float"))
                    {
                        ValAM = false;
                        break;
                    }else if(activador == 2 && Atributos.AM_TipToken == "/" || Atributos.AM_TipDato == "float")
                    {
                        newSentence.Text = "Se esperaba un dato de tipo flotante para continuar, ERROR SEMANTICO";
                        sb1.Append($"{Atributos.AM_Token + " "}");
                        ValAM = true;
                    }else if(Atributos.AM_TipDato == "int" && Atributos.AM_TipNum == "ND")
                    {
                        newSentence.Text = "Se esperaba una declaracion del dato de tipo flotante para continuar, ERROR SEMANTICO";
                        ValAM = false;
                        break;
                    }else if(Atributos.AM_TipDato == "float" && Atributos.AM_TipNum == "NE")
                    {
                        newSentence.Text = "Se esperaba una declaracion del dato de tipo entero para continuar, ERROR SEMANTICO";
                        ValAM = false;
                        break;
                    }
                    else
                    {
                        sb1.Append($"{Atributos.AM_Token + " "}");
                        ValAM = true;
                    }
                }
                newSentence.Text = sb1.ToString();
            }
        }

        public void CrearExistencia(string lexema)
        {
            Existencia newExistencia;
            newExistencia = new Existencia(lexema);
            TokenAM.Add(newExistencia);
            sb.AppendLine($"{lexema} Encontrado");
        }

        public void CrearGuardarDATA(string Token, string TipodeDATO, string Valor, string Num)
        {
            GuardadodeDatos Tdata;
            Tdata = new GuardadodeDatos(Token, TipodeDATO, Valor, Num);
            Guardado.Add(Tdata);
            sb.AppendLine($"{Token + " " +"ID"+" "+ TipodeDATO + " " + Valor + " " + Num + " " + "Cargado"}");
        }

        public void Atributo(string Token, string tiptok, string TipodeDATO, string Valor, string Tipnum)
        {
            SentenciaFinal Tdata;
            Tdata = new SentenciaFinal(Token, tiptok, TipodeDATO, Valor, Tipnum);
            Atributos.Add(Tdata);
            //sb.AppendLine($"{Token + " " + tiptok + " " + TipodeDATO + " " + Valor + " " + Tipnum + " " + "Agregado con exito"}");
        }

        public bool validacionSemantica()
        {
            if(ValAM == true)
            {
                EDAVOI.Text = "Valido";
            }
            else
            {
                AsignacionIDS.Text = "ERROR SEMANTICO";
                EDAVOI.Text = "Invalido";
            }
            return ValAM;
        }
    }
}
