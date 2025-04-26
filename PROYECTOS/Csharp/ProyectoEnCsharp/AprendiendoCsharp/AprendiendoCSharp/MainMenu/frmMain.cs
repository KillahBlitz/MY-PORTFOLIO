using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

//Librerias para usar lo que esta dentro del proyecto
using AprendiendoCSharp.MainMenu;
using AprendiendoCSharp.OperadoresAritmeticos;

namespace AprendiendoCSharp.MainMenu
{
    public partial class frmMain : Form
    {
        public frmMain()
        {
            InitializeComponent();
        }

        private void frmMain_Load(object sender, EventArgs e)
        {

        }

        private void BottomOA_Click(object sender, EventArgs e)
        {
            Btn1();
            //frmOA frmOA = new frmOA();
            //Este nos permite salir de los forms como x aplicaciones, el show dialog no nos deja continuar hasta terminarl el programa
            //frmOA.Show();
            //frmOA.ShowDialog();
        }

        private void bottomOR_Click(object sender, EventArgs e)
        {
            Btn2();
        }

        private void bottomOL_Click(object sender, EventArgs e)
        {
            Btn3();
        }

        private void Btn1()
        {
            PanelVisor.Controls.Clear();
            usrcOA usrcOA = new usrcOA();
            usrcOA.Dock = DockStyle.Fill;
            PanelVisor.Controls.Add(usrcOA);
            usrcOA.Show();
        }
        private void Btn2()
        {
            PanelVisor.Controls.Clear();
            usrcOR usrcOR = new usrcOR();
            usrcOR.Dock = DockStyle.Fill;
            PanelVisor.Controls.Add(usrcOR);
            usrcOR.Show();
        }
        private void Btn3()
        {
            PanelVisor.Controls.Clear();
            usrcOL usrcOL = new usrcOL();
            usrcOL.Dock = DockStyle.Fill;
            PanelVisor.Controls.Add(usrcOL);
            usrcOL.Show();
        }

    }
}
