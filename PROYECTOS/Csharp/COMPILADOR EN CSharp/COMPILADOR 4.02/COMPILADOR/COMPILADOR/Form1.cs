using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace COMPILADOR
{
    public partial class Form1 : Form
    {
        //Declaracion de los controles de usuario, los cuales necesitamos previos para ocultar en el panel 1
        public usrAL usrALControl;
        public usrAS usrASControl;
        public usrAM usrAMControl;
        public usrCIP usrCIPControl;
        //palabra que reserva la cadena ingresada o lo que haya en el .txt
        public string SharedPal { get; private set; }
        //Variables que reciben los estados validos
        bool ValAL = false, ValAS = false, ValAM = false;

        // Constructor que inicializa el forms y los user controls
        public Form1()
        {
            InitializeComponent();
            InitializeUserControls();
        }

        private void CrearTabla()
        {
            usrALControl.lectordeentrada();
        }
        private void Analizartabla() 
        {
            usrASControl.RecorrerTokensComoPila();
        }

        private void CrearReglas()
        {
            usrAMControl.analizacionSemantica();
        }

        //este es el metodo que inicializa tanto usrAL como usrAS y que inicializara cada control de usuario
        private void InitializeUserControls()
        {
            // Inicialización de usrAL
            usrALControl = new usrAL();
            usrALControl.Dock = DockStyle.Fill;
            usrALControl.Visible = false; // Inicialmente oculto
            panel1.Controls.Add(usrALControl);

            // Inicialización de usrAS
            usrASControl = new usrAS();
            usrASControl.Dock = DockStyle.Fill;
            usrASControl.Visible = false; // Inicialmente oculto
            panel1.Controls.Add(usrASControl);
           
            // Inicialización de usrAM
            usrAMControl = new usrAM();
            usrAMControl.Dock = DockStyle.Fill;
            usrAMControl.Visible = false; // Inicialmente oculto
            panel1.Controls.Add(usrAMControl);

            // Inicialización de usrCIP
            usrCIPControl = new usrCIP();
            usrCIPControl.Dock = DockStyle.Fill;
            usrCIPControl.Visible = false; // Inicialmente oculto
            panel1.Controls.Add(usrCIPControl);

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            // Mostrar usrAL y ocultar usrAS con usrCIP, aqui pasan los eventos cuando damos click en el boton
            usrALControl.Visible = true;
            usrCIPControl.Visible = false;
            usrASControl.Visible = false;
            usrAMControl.Visible = false;
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            // Actualizar el contenido de usrAS antes de mostrarlo
            if (usrALControl != null)
            {
                //guardamos la cadena en una nueva variable que tenemos en usrAS para no volver a ingresar
                //tambien guardamos la tabla de tokens en usrAS para poder hacer la derivacion
                List<usrAL.Token> tokens = usrALControl.tokens;
                usrASControl.ReceiveTokens(tokens);
                string currentPal = usrALControl.PAL;
                usrASControl.ReceivePal(currentPal);
            }
            // Mostrar usrAS y ocultar usrAL con usrCIP
            usrALControl.Visible = false;
            usrCIPControl.Visible = false;
            usrAMControl.Visible = false;
            usrASControl.Visible = true;
        }

        private void AnalizadorSemantico_Click(object sender, EventArgs e)
        {
            // Actualizar el contenido de usrAS antes de mostrarlo
            if (usrALControl != null)
            {
                //guardamos la cadena en una nueva variable que tenemos en usrAS para no volver a ingresar
                //tambien guardamos la tabla de tokens en usrAS para poder hacer la derivacion
                List<usrAL.Token> tokens = usrALControl.tokens;
                usrAMControl.ReceiveTokens(tokens);
                List<usrAS.PiladeSentencias> SenS = usrASControl.SenS;
                usrAMControl.ReceiveSenS(SenS);
                string currentPal = usrALControl.PAL;
                usrAMControl.ReceivePal(currentPal);
            }
            // Mostrar usrCIP y ocultar usrAL con usrAS
            usrALControl.Visible = false;
            usrCIPControl.Visible = false;
            usrASControl.Visible = false;
            usrAMControl.Visible = true;
        }

        private void Polaca_Click(object sender, EventArgs e)
        {
            // Actualizar el contenido de usrAS antes de mostrarlo
            if (usrALControl != null)
            {
                List<usrAM.SentenciaFinal> list = usrAMControl.Atributos;
                usrCIPControl.ReceiveSen(list);
                //guardamos la cadena en una nueva variable que tenemos en usrAS para no volver a ingresar
                //tambien guardamos la tabla de tokens en usrAS para poder hacer la derivacion
                //List<usrAL.Token> tokens = usrALControl.tokens;
                //usrASControl.ReceiveTokens(tokens);
                //string currentPal = usrALControl.PAL;
                //usrASControl.ReceivePal(currentPal);
            }

            ValAL = usrALControl.validacionLexica();
            ValAS = usrASControl.validacionSintactica();
            ValAM = usrAMControl.validacionSemantica();

            usrCIPControl.ReciveEDOS(ValAL,ValAS,ValAM);

                usrALControl.Visible = false;
                usrCIPControl.Visible = true;
                usrASControl.Visible = false;
                usrAMControl.Visible = false;
        }

        private void ResetButtom_Click(object sender, EventArgs e)
        {
            // Eliminar los controles actuales
            panel1.Controls.Clear();

            // Crear nuevas instancias de los controles de usuario
            usrALControl = new usrAL();
            usrALControl.Dock = DockStyle.Fill;
            panel1.Controls.Add(usrALControl);

            usrASControl = new usrAS();
            usrASControl.Dock = DockStyle.Fill;
            panel1.Controls.Add(usrASControl);

            usrCIPControl = new usrCIP();
            usrCIPControl.Dock = DockStyle.Fill;
            panel1.Controls.Add(usrCIPControl);

            usrAMControl = new usrAM();
            usrAMControl.Dock = DockStyle.Fill;
            panel1.Controls.Add(usrAMControl);

            // Ocultar todos los controles de usuario
            usrALControl.Visible = false;
            usrASControl.Visible = false;
            usrCIPControl.Visible = false;
            usrAMControl.Visible = false;
        }

        private void ReadmeButtom_Click(object sender, EventArgs e)
        {
            try
            {
                // Ruta relativa al archivo de texto en el directorio de salida
                string readmeFilePath = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "Readme.txt");

                // Verificar si el archivo existe
                if (File.Exists(readmeFilePath))
                {
                    // Iniciar el archivo de texto con el programa asociado predeterminado
                    Process.Start(new ProcessStartInfo(readmeFilePath) { UseShellExecute = true });
                }
                else
                {
                    MessageBox.Show("El archivo Readme.txt no se encontró.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
            catch (Exception ex)
            {
                // Manejo de errores
                MessageBox.Show($"Error al abrir el archivo Readme.txt: {ex.Message}", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void ExitButtom_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
