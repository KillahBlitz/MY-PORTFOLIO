using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;




//Variables a tomar en cuenta para operar la IDE
//textbox(n) cajas de texto donde ingreso datos
//Cooltext(n) textos que tengo escritos, Strings
//suma, resta, division y multiplicacion son botones

namespace AprendiendoCSharp.OperadoresAritmeticos
{
    public partial class frmOA : Form
    {
        //Constructor
        public frmOA()
        {
            InitializeComponent();
        }

        double Num1, Num2;
        double Resul;

        private void frmOA_Load(object sender, EventArgs e)
        {

        }


        private void resta0_Click_1(object sender, EventArgs e)
        {
            Suma();
        }

        private void suma0_Click_1(object sender, EventArgs e)
        {
            Resta();
        }

        private void multiplicacion_Click(object sender, EventArgs e)
        {
            Mul();
        }

        private void division_Click(object sender, EventArgs e)
        {
            Div();
        }

        private void Suma()
        {
            //La funcion try me permite mandar un mensaje cuando no se cumplen las condiciones dadas
            //asi no hay problema en la ejecucion del programa
            try
            {
                //Funcion que me permite convertir comas en puntos para datos tipo double
                textBox1.Text = textBox1.Text.Replace(",", ".");
                textBox2.Text = textBox2.Text.Replace(",", ".");
                //Convert.ToInt convierte el texto ingresado en tipo entero
                Num1 = Convert.ToDouble(textBox1.Text);
                Num2 = Convert.ToDouble(textBox2.Text);
                Resul = Num1 + Num2;
                //Funcion para convertir en string es Convert.ToString o usar POO con .ToString();
                Cooltextresultado2.Text = Resul.ToString();
            }
            catch (Exception xs)
            {
                MessageBox.Show(xs.Message);
            }
        }

        private void Resta()
        {
            try
            {
                textBox1.Text = textBox1.Text.Replace(",", ".");
                textBox2.Text = textBox2.Text.Replace(",", ".");
                Num1 = Convert.ToDouble(textBox1.Text);
                Num2 = Convert.ToDouble(textBox2.Text);
                Resul = Num1 - Num2;
                Cooltextresultado2.Text = Resul.ToString();
            }
            catch (Exception xs)
            {
                MessageBox.Show(xs.Message);
            }
        }

        private void Div()
        {
            try
            {
                Num1 = Convert.ToDouble(textBox1.Text);
                Num2 = Convert.ToDouble(textBox2.Text);
                if (Num2 != 0)
                {
                    textBox1.Text = textBox1.Text.Replace(",", ".");
                    textBox2.Text = textBox2.Text.Replace(",", ".");
                    Resul = Convert.ToDouble(Num1) / Convert.ToDouble(Num2);
                    Cooltextresultado2.Text = Resul.ToString();
                }
                else
                {
                    Cooltextresultado2.Text = "Math ERROR";
                }
            }
            catch (Exception xs)
            {
                MessageBox.Show(xs.Message);
            }

        }


        private void Mul()
        {
            try
            {
                textBox1.Text = textBox1.Text.Replace(",", ".");
                textBox2.Text = textBox2.Text.Replace(",", ".");
                Num1 = Convert.ToDouble(textBox1.Text);
                Num2 = Convert.ToDouble(textBox2.Text);
                Resul = Num1 * Num2;
                Cooltextresultado2.Text = Resul.ToString();
            }
            catch (Exception xs)
            {
                MessageBox.Show(xs.Message);
            }
        }

    }
}
