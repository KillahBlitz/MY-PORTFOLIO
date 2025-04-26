namespace COMPILADOR
{
    partial class usrAS
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
            this.Textp = new System.Windows.Forms.Label();
            this.TextTabla = new System.Windows.Forms.Label();
            this.TablaDeDerivacion = new System.Windows.Forms.TextBox();
            this.ButtomRealizador = new System.Windows.Forms.Button();
            this.CadenaImprimir = new System.Windows.Forms.Label();
            this.EDAS = new System.Windows.Forms.Label();
            this.EDOAS = new System.Windows.Forms.Label();
            this.flowLayoutPanel1 = new System.Windows.Forms.FlowLayoutPanel();
            this.TablaTok = new System.Windows.Forms.Button();
            this.flowLayoutPanel2 = new System.Windows.Forms.FlowLayoutPanel();
            this.txtdeclaracion = new System.Windows.Forms.Label();
            this.aquivaC = new System.Windows.Forms.Label();
            this.flowLayoutPanel3 = new System.Windows.Forms.FlowLayoutPanel();
            this.txtinicializados = new System.Windows.Forms.Label();
            this.aquivaCON = new System.Windows.Forms.Label();
            this.flowLayoutPanel1.SuspendLayout();
            this.flowLayoutPanel2.SuspendLayout();
            this.flowLayoutPanel3.SuspendLayout();
            this.SuspendLayout();
            // 
            // Textp
            // 
            this.Textp.AutoSize = true;
            this.Textp.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Textp.Location = new System.Drawing.Point(33, 47);
            this.Textp.Name = "Textp";
            this.Textp.Size = new System.Drawing.Size(245, 31);
            this.Textp.TabIndex = 1;
            this.Textp.Text = "Cadena Ingresada:";
            // 
            // TextTabla
            // 
            this.TextTabla.AutoSize = true;
            this.TextTabla.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TextTabla.Location = new System.Drawing.Point(477, 47);
            this.TextTabla.Name = "TextTabla";
            this.TextTabla.Size = new System.Drawing.Size(332, 31);
            this.TextTabla.TabIndex = 15;
            this.TextTabla.Text = "Realizacion de derivacion:";
            // 
            // TablaDeDerivacion
            // 
            this.TablaDeDerivacion.Font = new System.Drawing.Font("Arial", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TablaDeDerivacion.Location = new System.Drawing.Point(483, 91);
            this.TablaDeDerivacion.Multiline = true;
            this.TablaDeDerivacion.Name = "TablaDeDerivacion";
            this.TablaDeDerivacion.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.TablaDeDerivacion.Size = new System.Drawing.Size(512, 453);
            this.TablaDeDerivacion.TabIndex = 16;
            // 
            // ButtomRealizador
            // 
            this.ButtomRealizador.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.ButtomRealizador.Font = new System.Drawing.Font("Arial", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ButtomRealizador.Location = new System.Drawing.Point(557, 550);
            this.ButtomRealizador.Name = "ButtomRealizador";
            this.ButtomRealizador.Size = new System.Drawing.Size(176, 42);
            this.ButtomRealizador.TabIndex = 17;
            this.ButtomRealizador.Text = "Realizar analisis Sintactico";
            this.ButtomRealizador.UseVisualStyleBackColor = false;
            this.ButtomRealizador.Click += new System.EventHandler(this.ButtomRealizador_Click);
            // 
            // CadenaImprimir
            // 
            this.CadenaImprimir.AutoSize = true;
            this.CadenaImprimir.Font = new System.Drawing.Font("Arial", 9.75F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.CadenaImprimir.Location = new System.Drawing.Point(33, 91);
            this.CadenaImprimir.Name = "CadenaImprimir";
            this.CadenaImprimir.Size = new System.Drawing.Size(11, 16);
            this.CadenaImprimir.TabIndex = 18;
            this.CadenaImprimir.Text = "-";
            // 
            // EDAS
            // 
            this.EDAS.AutoSize = true;
            this.EDAS.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.EDAS.Location = new System.Drawing.Point(3, 31);
            this.EDAS.Name = "EDAS";
            this.EDAS.Size = new System.Drawing.Size(23, 31);
            this.EDAS.TabIndex = 19;
            this.EDAS.Text = "-";
            // 
            // EDOAS
            // 
            this.EDOAS.AutoSize = true;
            this.EDOAS.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.EDOAS.Location = new System.Drawing.Point(3, 0);
            this.EDOAS.Name = "EDOAS";
            this.EDOAS.Size = new System.Drawing.Size(234, 31);
            this.EDOAS.TabIndex = 20;
            this.EDOAS.Text = "Estado Sintactico:";
            // 
            // flowLayoutPanel1
            // 
            this.flowLayoutPanel1.Controls.Add(this.EDOAS);
            this.flowLayoutPanel1.Controls.Add(this.EDAS);
            this.flowLayoutPanel1.Location = new System.Drawing.Point(25, 440);
            this.flowLayoutPanel1.Name = "flowLayoutPanel1";
            this.flowLayoutPanel1.Size = new System.Drawing.Size(253, 68);
            this.flowLayoutPanel1.TabIndex = 21;
            // 
            // TablaTok
            // 
            this.TablaTok.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.TablaTok.Font = new System.Drawing.Font("Arial", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TablaTok.Location = new System.Drawing.Point(750, 550);
            this.TablaTok.Name = "TablaTok";
            this.TablaTok.Size = new System.Drawing.Size(176, 42);
            this.TablaTok.TabIndex = 22;
            this.TablaTok.Text = "Consultar Tabla de Tokens";
            this.TablaTok.UseVisualStyleBackColor = false;
            this.TablaTok.Click += new System.EventHandler(this.TablaTok_Click);
            // 
            // flowLayoutPanel2
            // 
            this.flowLayoutPanel2.Controls.Add(this.txtdeclaracion);
            this.flowLayoutPanel2.Controls.Add(this.aquivaC);
            this.flowLayoutPanel2.Location = new System.Drawing.Point(25, 524);
            this.flowLayoutPanel2.Name = "flowLayoutPanel2";
            this.flowLayoutPanel2.Size = new System.Drawing.Size(308, 28);
            this.flowLayoutPanel2.TabIndex = 23;
            // 
            // txtdeclaracion
            // 
            this.txtdeclaracion.AutoSize = true;
            this.txtdeclaracion.Font = new System.Drawing.Font("Arial", 15.75F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtdeclaracion.Location = new System.Drawing.Point(3, 0);
            this.txtdeclaracion.Name = "txtdeclaracion";
            this.txtdeclaracion.Size = new System.Drawing.Size(228, 24);
            this.txtdeclaracion.TabIndex = 20;
            this.txtdeclaracion.Text = "Elementos declarados:";
            // 
            // aquivaC
            // 
            this.aquivaC.AutoSize = true;
            this.aquivaC.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.aquivaC.Location = new System.Drawing.Point(237, 0);
            this.aquivaC.Name = "aquivaC";
            this.aquivaC.Size = new System.Drawing.Size(23, 31);
            this.aquivaC.TabIndex = 19;
            this.aquivaC.Text = "-";
            // 
            // flowLayoutPanel3
            // 
            this.flowLayoutPanel3.Controls.Add(this.txtinicializados);
            this.flowLayoutPanel3.Controls.Add(this.aquivaCON);
            this.flowLayoutPanel3.Location = new System.Drawing.Point(25, 551);
            this.flowLayoutPanel3.Name = "flowLayoutPanel3";
            this.flowLayoutPanel3.Size = new System.Drawing.Size(308, 28);
            this.flowLayoutPanel3.TabIndex = 24;
            // 
            // txtinicializados
            // 
            this.txtinicializados.AutoSize = true;
            this.txtinicializados.Font = new System.Drawing.Font("Arial", 15.75F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtinicializados.Location = new System.Drawing.Point(3, 0);
            this.txtinicializados.Name = "txtinicializados";
            this.txtinicializados.Size = new System.Drawing.Size(239, 24);
            this.txtinicializados.TabIndex = 20;
            this.txtinicializados.Text = "Elementos inicializados:";
            // 
            // aquivaCON
            // 
            this.aquivaCON.AutoSize = true;
            this.aquivaCON.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.aquivaCON.Location = new System.Drawing.Point(248, 0);
            this.aquivaCON.Name = "aquivaCON";
            this.aquivaCON.Size = new System.Drawing.Size(23, 31);
            this.aquivaCON.TabIndex = 19;
            this.aquivaCON.Text = "-";
            // 
            // usrAS
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Goldenrod;
            this.Controls.Add(this.flowLayoutPanel3);
            this.Controls.Add(this.flowLayoutPanel2);
            this.Controls.Add(this.TablaTok);
            this.Controls.Add(this.flowLayoutPanel1);
            this.Controls.Add(this.CadenaImprimir);
            this.Controls.Add(this.ButtomRealizador);
            this.Controls.Add(this.TablaDeDerivacion);
            this.Controls.Add(this.TextTabla);
            this.Controls.Add(this.Textp);
            this.Name = "usrAS";
            this.Size = new System.Drawing.Size(1028, 647);
            this.Load += new System.EventHandler(this.usrAS_Load);
            this.flowLayoutPanel1.ResumeLayout(false);
            this.flowLayoutPanel1.PerformLayout();
            this.flowLayoutPanel2.ResumeLayout(false);
            this.flowLayoutPanel2.PerformLayout();
            this.flowLayoutPanel3.ResumeLayout(false);
            this.flowLayoutPanel3.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label Textp;
        private System.Windows.Forms.Label TextTabla;
        private System.Windows.Forms.TextBox TablaDeDerivacion;
        private System.Windows.Forms.Button ButtomRealizador;
        private System.Windows.Forms.Label CadenaImprimir;
        private System.Windows.Forms.Label EDAS;
        private System.Windows.Forms.Label EDOAS;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel1;
        private System.Windows.Forms.Button TablaTok;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel2;
        private System.Windows.Forms.Label txtdeclaracion;
        private System.Windows.Forms.Label aquivaC;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel3;
        private System.Windows.Forms.Label txtinicializados;
        private System.Windows.Forms.Label aquivaCON;
    }
}
