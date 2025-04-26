using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AprendiendoCSharp.OperadoresLogicos
{
    public partial class frmOL : Form
    {
        //Constructor
        public frmOL()
        {
            InitializeComponent();
        }

        Double Num1, Num2, Num3;
        String Resultado;
        bool bottomes;
        private void frmOL_Load(object sender, EventArgs e)
        {

        }

        private void OperadorY_Click(object sender, EventArgs e)
        {
            asign();
            if (Num1 < Num3 && Num2 > Num3)
            {
                bottomes = true;
            }
            else
            {
                bottomes = false;
            }
            Resultado = Relacion();
            Cooltextresultado2.Text = Resultado.ToString();
        }

        private void OperadorO_Click(object sender, EventArgs e)
        {
            asign();
            if (Num1 < Num3 || Num2 > Num3)
            {
                bottomes = true;
            }
            else
            {
                bottomes = false;
            }
            Resultado = Relacion();
            Cooltextresultado2.Text = Resultado.ToString();
        }

        private void OperadorN_Click(object sender, EventArgs e)
        {
            asign();
            if (!(Num1 < Num3) && !(Num2 > Num3))
            {
                bottomes = true;
            }
            else
            {
                bottomes = false;
            }
            Resultado = Relacion();
            Cooltextresultado2.Text = Resultado.ToString();
        }


        private void asign()
        {
            textBox1.Text = textBox1.Text.Replace(",", ".");
            textBox2.Text = textBox2.Text.Replace(",", ".");
            textBox3.Text = textBox3.Text.Replace(",", ".");
            Num1 = Convert.ToDouble(textBox1.Text);
            Num2 = Convert.ToDouble(textBox2.Text);
            Num3 = Convert.ToDouble(textBox3.Text);
        }

        private string Relacion()
        {
            string valral;
            if (bottomes == true)
            {
                valral = "La asignacion es verdadera";
            }
            else
            {
                valral = "La asignacion es Falsa";
            }
            return valral;
        }
    }
}
