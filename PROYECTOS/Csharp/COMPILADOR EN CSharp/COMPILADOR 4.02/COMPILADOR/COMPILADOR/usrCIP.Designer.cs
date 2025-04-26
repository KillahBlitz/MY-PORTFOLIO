
namespace COMPILADOR
{
    partial class usrCIP
    {
        /// <summary> 
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de componentes

        /// <summary> 
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.CI = new System.Windows.Forms.TextBox();
            this.TextTabla = new System.Windows.Forms.Label();
            this.flowLayoutPanel3 = new System.Windows.Forms.FlowLayoutPanel();
            this.EDOLEX = new System.Windows.Forms.Label();
            this.txtval1 = new System.Windows.Forms.Label();
            this.flowLayoutPanel2 = new System.Windows.Forms.FlowLayoutPanel();
            this.EDOSIN = new System.Windows.Forms.Label();
            this.txtval2 = new System.Windows.Forms.Label();
            this.COMPILAR = new System.Windows.Forms.Button();
            this.flowLayoutPanel4 = new System.Windows.Forms.FlowLayoutPanel();
            this.EDOSEM = new System.Windows.Forms.Label();
            this.txtval3 = new System.Windows.Forms.Label();
            this.Cadena = new System.Windows.Forms.Label();
            this.CE = new System.Windows.Forms.TextBox();
            this.CEtxt = new System.Windows.Forms.Label();
            this.flowLayoutPanel3.SuspendLayout();
            this.flowLayoutPanel2.SuspendLayout();
            this.flowLayoutPanel4.SuspendLayout();
            this.SuspendLayout();
            // 
            // CI
            // 
            this.CI.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.CI.Location = new System.Drawing.Point(536, 83);
            this.CI.Multiline = true;
            this.CI.Name = "CI";
            this.CI.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.CI.Size = new System.Drawing.Size(493, 488);
            this.CI.TabIndex = 17;
            // 
            // TextTabla
            // 
            this.TextTabla.AutoSize = true;
            this.TextTabla.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TextTabla.Location = new System.Drawing.Point(554, 37);
            this.TextTabla.Name = "TextTabla";
            this.TextTabla.Size = new System.Drawing.Size(449, 31);
            this.TextTabla.TabIndex = 16;
            this.TextTabla.Text = "Demostracion de Codigo Intermedio";
            // 
            // flowLayoutPanel3
            // 
            this.flowLayoutPanel3.Controls.Add(this.EDOLEX);
            this.flowLayoutPanel3.Controls.Add(this.txtval1);
            this.flowLayoutPanel3.Location = new System.Drawing.Point(3, 453);
            this.flowLayoutPanel3.Name = "flowLayoutPanel3";
            this.flowLayoutPanel3.Size = new System.Drawing.Size(395, 37);
            this.flowLayoutPanel3.TabIndex = 20;
            // 
            // EDOLEX
            // 
            this.EDOLEX.AutoSize = true;
            this.EDOLEX.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.EDOLEX.Location = new System.Drawing.Point(3, 0);
            this.EDOLEX.Name = "EDOLEX";
            this.EDOLEX.Size = new System.Drawing.Size(193, 31);
            this.EDOLEX.TabIndex = 10;
            this.EDOLEX.Text = "Estado Lexico:";
            // 
            // txtval1
            // 
            this.txtval1.AutoSize = true;
            this.txtval1.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtval1.Location = new System.Drawing.Point(202, 0);
            this.txtval1.Name = "txtval1";
            this.txtval1.Size = new System.Drawing.Size(23, 31);
            this.txtval1.TabIndex = 5;
            this.txtval1.Text = "-";
            // 
            // flowLayoutPanel2
            // 
            this.flowLayoutPanel2.Controls.Add(this.EDOSIN);
            this.flowLayoutPanel2.Controls.Add(this.txtval2);
            this.flowLayoutPanel2.Location = new System.Drawing.Point(3, 493);
            this.flowLayoutPanel2.Name = "flowLayoutPanel2";
            this.flowLayoutPanel2.Size = new System.Drawing.Size(395, 34);
            this.flowLayoutPanel2.TabIndex = 19;
            // 
            // EDOSIN
            // 
            this.EDOSIN.AutoSize = true;
            this.EDOSIN.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.EDOSIN.Location = new System.Drawing.Point(3, 0);
            this.EDOSIN.Name = "EDOSIN";
            this.EDOSIN.Size = new System.Drawing.Size(226, 31);
            this.EDOSIN.TabIndex = 6;
            this.EDOSIN.Text = "Estado Sintactico";
            // 
            // txtval2
            // 
            this.txtval2.AutoSize = true;
            this.txtval2.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtval2.Location = new System.Drawing.Point(235, 0);
            this.txtval2.Name = "txtval2";
            this.txtval2.Size = new System.Drawing.Size(23, 31);
            this.txtval2.TabIndex = 7;
            this.txtval2.Text = "-";
            // 
            // COMPILAR
            // 
            this.COMPILAR.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.COMPILAR.Location = new System.Drawing.Point(408, 510);
            this.COMPILAR.Name = "COMPILAR";
            this.COMPILAR.Size = new System.Drawing.Size(122, 52);
            this.COMPILAR.TabIndex = 21;
            this.COMPILAR.Text = "COMPILAR";
            this.COMPILAR.UseVisualStyleBackColor = true;
            this.COMPILAR.Click += new System.EventHandler(this.COMPILAR_Click);
            // 
            // flowLayoutPanel4
            // 
            this.flowLayoutPanel4.Controls.Add(this.EDOSEM);
            this.flowLayoutPanel4.Controls.Add(this.txtval3);
            this.flowLayoutPanel4.Location = new System.Drawing.Point(3, 531);
            this.flowLayoutPanel4.Name = "flowLayoutPanel4";
            this.flowLayoutPanel4.Size = new System.Drawing.Size(395, 37);
            this.flowLayoutPanel4.TabIndex = 22;
            // 
            // EDOSEM
            // 
            this.EDOSEM.AutoSize = true;
            this.EDOSEM.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.EDOSEM.Location = new System.Drawing.Point(3, 0);
            this.EDOSEM.Name = "EDOSEM";
            this.EDOSEM.Size = new System.Drawing.Size(243, 31);
            this.EDOSEM.TabIndex = 10;
            this.EDOSEM.Text = "Estado Semantico:";
            // 
            // txtval3
            // 
            this.txtval3.AutoSize = true;
            this.txtval3.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtval3.Location = new System.Drawing.Point(252, 0);
            this.txtval3.Name = "txtval3";
            this.txtval3.Size = new System.Drawing.Size(23, 31);
            this.txtval3.TabIndex = 5;
            this.txtval3.Text = "-";
            // 
            // Cadena
            // 
            this.Cadena.AutoSize = true;
            this.Cadena.Font = new System.Drawing.Font("Arial", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Cadena.Location = new System.Drawing.Point(6, 407);
            this.Cadena.Name = "Cadena";
            this.Cadena.Size = new System.Drawing.Size(16, 22);
            this.Cadena.TabIndex = 23;
            this.Cadena.Text = "-";
            // 
            // CE
            // 
            this.CE.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.CE.Location = new System.Drawing.Point(19, 83);
            this.CE.Multiline = true;
            this.CE.Name = "CE";
            this.CE.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.CE.Size = new System.Drawing.Size(394, 291);
            this.CE.TabIndex = 24;
            // 
            // CEtxt
            // 
            this.CEtxt.AutoSize = true;
            this.CEtxt.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.CEtxt.Location = new System.Drawing.Point(13, 37);
            this.CEtxt.Name = "CEtxt";
            this.CEtxt.Size = new System.Drawing.Size(481, 31);
            this.CEtxt.TabIndex = 25;
            this.CEtxt.Text = "Demostracion de Codigo Ensamblador";
            // 
            // usrCIP
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Firebrick;
            this.Controls.Add(this.CEtxt);
            this.Controls.Add(this.CE);
            this.Controls.Add(this.Cadena);
            this.Controls.Add(this.flowLayoutPanel4);
            this.Controls.Add(this.COMPILAR);
            this.Controls.Add(this.flowLayoutPanel3);
            this.Controls.Add(this.flowLayoutPanel2);
            this.Controls.Add(this.CI);
            this.Controls.Add(this.TextTabla);
            this.Name = "usrCIP";
            this.Size = new System.Drawing.Size(1075, 639);
            this.Load += new System.EventHandler(this.usrCIP_Load);
            this.flowLayoutPanel3.ResumeLayout(false);
            this.flowLayoutPanel3.PerformLayout();
            this.flowLayoutPanel2.ResumeLayout(false);
            this.flowLayoutPanel2.PerformLayout();
            this.flowLayoutPanel4.ResumeLayout(false);
            this.flowLayoutPanel4.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox CI;
        private System.Windows.Forms.Label TextTabla;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel3;
        private System.Windows.Forms.Label EDOLEX;
        private System.Windows.Forms.Label txtval1;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel2;
        private System.Windows.Forms.Label EDOSIN;
        private System.Windows.Forms.Label txtval2;
        private System.Windows.Forms.Button COMPILAR;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel4;
        private System.Windows.Forms.Label EDOSEM;
        private System.Windows.Forms.Label txtval3;
        private System.Windows.Forms.Label Cadena;
        private System.Windows.Forms.TextBox CE;
        private System.Windows.Forms.Label CEtxt;
    }
}
