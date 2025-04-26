using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AprendiendoCSharp.MainMenu
{
    public partial class usrcOR : UserControl
    {
        public usrcOR()
        {
            InitializeComponent();
        }
        double Num1, Num2;
        bool Resul;
        string ResulFin;

        private void usrcOR_Load(object sender, EventArgs e)
        {

        }

        private void Mayorque_Click(object sender, EventArgs e)
        {
            asign();
            if (Num1 > Num2)
            {
                Resul = true;
            }
            else
            {
                Resul = false;
            }
            ResulFin = Relacion();
            Cooltextresultado2.Text = ResulFin.ToString();
        }

        private void Menorque_Click(object sender, EventArgs e)
        {
            asign();
            if (Num1 < Num2)
            {
                Resul = true;
            }
            else
            {
                Resul = false;
            }
            ResulFin = Relacion();
            Cooltextresultado2.Text = ResulFin.ToString();
        }

        private void Igualque_Click(object sender, EventArgs e)
        {
            asign();
            if (Num1 == Num2)
            {
                Resul = true;
            }
            else
            {
                Resul = false;
            }
            ResulFin = Relacion();
            Cooltextresultado2.Text = ResulFin.ToString();
        }

        private void Mayorique_Click(object sender, EventArgs e)
        {
            asign();
            if (Num1 >= Num2)
            {
                Resul = true;
            }
            else
            {
                Resul = false;
            }
            ResulFin = Relacion();
            Cooltextresultado2.Text = ResulFin.ToString();
        }

        private void Menorigualque_Click(object sender, EventArgs e)
        {
            asign();
            if (Num1 <= Num2)
            {
                Resul = true;
            }
            else
            {
                Resul = false;
            }
            ResulFin = Relacion();
            Cooltextresultado2.Text = ResulFin.ToString();
        }

        private void Distintoque_Click(object sender, EventArgs e)
        {
            asign();
            if (Num1 != Num2)
            {
                Resul = true;
            }
            else
            {
                Resul = false;
            }
            ResulFin = Relacion();
            Cooltextresultado2.Text = ResulFin.ToString();
        }

        private void asign()
        {
            textBox1.Text = textBox1.Text.Replace(",", ".");
            textBox2.Text = textBox2.Text.Replace(",", ".");
            Num1 = Convert.ToDouble(textBox1.Text);
            Num2 = Convert.ToDouble(textBox2.Text);
        }

        private string Relacion()
        {
            string valral;
            if (Resul == true)
            {
                valral = "La asignacion es verdadera";
            }
            else
            {
                valral = "La asignacion es Falsa";
            }
            return valral;
        }

        /*private void Comparativa1()
        {
            try
            {
                textBox1.Text = textBox1.Text.Replace(",", ".");
                textBox2.Text = textBox2.Text.Replace(",", ".");
                Num1 = Convert.ToDouble(textBox1.Text);
                Num2 = Convert.ToDouble(textBox2.Text);
                if(Num1 > Num2) 
                {
                    Resul = Num1;
                    Cooltextresultado2.Text = Resul.ToString();
                }
                else if(Num1 < Num2) 
                {
                    Resul = Num2;
                    Cooltextresultado2.Text = Resul.ToString();
                }
                else if (Num2 == Num1)
                {
                    Resul = Num1;
                    Cooltextresultado2.Text = Resul.ToString();
                }
                else 
                {
                    ResulError = "Computational Error";
                    Cooltextresultado2.Text = Resul.ToString();
                }

            }
            catch (Exception xs)
            {
                MessageBox.Show(xs.Message);
            }
        }*/
    }
}
