//librrerias
using AprendiendoCSharp.MainMenu;
using AprendiendoCSharp.OperadoresAritmeticos;
using AprendiendoCSharp.OperadoresRelacionales;
using AprendiendoCSharp.OperadoresLogicos;


using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AprendiendoCSharp
{
    internal static class Program
    {
        /// <summary>
        /// Punto de entrada principal para la aplicación.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new frmMain());
        }
    }
}
