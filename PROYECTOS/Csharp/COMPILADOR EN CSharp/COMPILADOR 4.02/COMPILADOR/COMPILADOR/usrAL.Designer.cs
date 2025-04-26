namespace COMPILADOR
{
    partial class usrAL
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
            this.components = new System.ComponentModel.Container();
            this.Ingreso = new System.Windows.Forms.Label();
            this.TextContador = new System.Windows.Forms.Label();
            this.Ingresador = new System.Windows.Forms.TextBox();
            this.TextContadora = new System.Windows.Forms.Label();
            this.Chars = new System.Windows.Forms.Button();
            this.TextValidacion = new System.Windows.Forms.Label();
            this.TextDato = new System.Windows.Forms.Label();
            this.TextAsignador = new System.Windows.Forms.Label();
            this.flowLayoutPanel1 = new System.Windows.Forms.FlowLayoutPanel();
            this.flowLayoutPanel2 = new System.Windows.Forms.FlowLayoutPanel();
            this.TextEstado = new System.Windows.Forms.Label();
            this.flowLayoutPanel3 = new System.Windows.Forms.FlowLayoutPanel();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.TextTabla = new System.Windows.Forms.Label();
            this.TabladeTokens1 = new System.Windows.Forms.TextBox();
            this.txtadd = new System.Windows.Forms.Button();
            this.flowLayoutPanel1.SuspendLayout();
            this.flowLayoutPanel2.SuspendLayout();
            this.flowLayoutPanel3.SuspendLayout();
            this.SuspendLayout();
            // 
            // Ingreso
            // 
            this.Ingreso.AutoSize = true;
            this.Ingreso.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Ingreso.Location = new System.Drawing.Point(33, 50);
            this.Ingreso.Name = "Ingreso";
            this.Ingreso.Size = new System.Drawing.Size(200, 31);
            this.Ingreso.TabIndex = 0;
            this.Ingreso.Text = "Programa Aqui:";
            // 
            // TextContador
            // 
            this.TextContador.AutoSize = true;
            this.TextContador.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TextContador.Location = new System.Drawing.Point(3, 0);
            this.TextContador.Name = "TextContador";
            this.TextContador.Size = new System.Drawing.Size(292, 31);
            this.TextContador.TabIndex = 1;
            this.TextContador.Text = "Numero de caracteres:";
            // 
            // Ingresador
            // 
            this.Ingresador.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Ingresador.Location = new System.Drawing.Point(39, 95);
            this.Ingresador.Multiline = true;
            this.Ingresador.Name = "Ingresador";
            this.Ingresador.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.Ingresador.Size = new System.Drawing.Size(358, 286);
            this.Ingresador.TabIndex = 2;
            // 
            // TextContadora
            // 
            this.TextContadora.AutoSize = true;
            this.TextContadora.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TextContadora.Location = new System.Drawing.Point(301, 0);
            this.TextContadora.Name = "TextContadora";
            this.TextContadora.Size = new System.Drawing.Size(23, 31);
            this.TextContadora.TabIndex = 3;
            this.TextContadora.Text = "-";
            // 
            // Chars
            // 
            this.Chars.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.Chars.Font = new System.Drawing.Font("Arial", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Chars.Location = new System.Drawing.Point(403, 101);
            this.Chars.Name = "Chars";
            this.Chars.Size = new System.Drawing.Size(75, 36);
            this.Chars.TabIndex = 4;
            this.Chars.Text = "Enviar";
            this.Chars.UseVisualStyleBackColor = false;
            this.Chars.Click += new System.EventHandler(this.Chars_Click);
            // 
            // TextValidacion
            // 
            this.TextValidacion.AutoSize = true;
            this.TextValidacion.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TextValidacion.Location = new System.Drawing.Point(202, 0);
            this.TextValidacion.Name = "TextValidacion";
            this.TextValidacion.Size = new System.Drawing.Size(23, 31);
            this.TextValidacion.TabIndex = 5;
            this.TextValidacion.Text = "-";
            // 
            // TextDato
            // 
            this.TextDato.AutoSize = true;
            this.TextDato.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TextDato.Location = new System.Drawing.Point(3, 0);
            this.TextDato.Name = "TextDato";
            this.TextDato.Size = new System.Drawing.Size(179, 31);
            this.TextDato.TabIndex = 6;
            this.TextDato.Text = "Tipo de Dato:";
            // 
            // TextAsignador
            // 
            this.TextAsignador.AutoSize = true;
            this.TextAsignador.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TextAsignador.Location = new System.Drawing.Point(188, 0);
            this.TextAsignador.Name = "TextAsignador";
            this.TextAsignador.Size = new System.Drawing.Size(23, 31);
            this.TextAsignador.TabIndex = 7;
            this.TextAsignador.Text = "-";
            // 
            // flowLayoutPanel1
            // 
            this.flowLayoutPanel1.Controls.Add(this.TextContador);
            this.flowLayoutPanel1.Controls.Add(this.TextContadora);
            this.flowLayoutPanel1.Location = new System.Drawing.Point(39, 399);
            this.flowLayoutPanel1.Name = "flowLayoutPanel1";
            this.flowLayoutPanel1.Size = new System.Drawing.Size(439, 38);
            this.flowLayoutPanel1.TabIndex = 8;
            // 
            // flowLayoutPanel2
            // 
            this.flowLayoutPanel2.Controls.Add(this.TextDato);
            this.flowLayoutPanel2.Controls.Add(this.TextAsignador);
            this.flowLayoutPanel2.Location = new System.Drawing.Point(39, 443);
            this.flowLayoutPanel2.Name = "flowLayoutPanel2";
            this.flowLayoutPanel2.Size = new System.Drawing.Size(439, 34);
            this.flowLayoutPanel2.TabIndex = 9;
            // 
            // TextEstado
            // 
            this.TextEstado.AutoSize = true;
            this.TextEstado.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TextEstado.Location = new System.Drawing.Point(3, 0);
            this.TextEstado.Name = "TextEstado";
            this.TextEstado.Size = new System.Drawing.Size(193, 31);
            this.TextEstado.TabIndex = 10;
            this.TextEstado.Text = "Estado Lexico:";
            // 
            // flowLayoutPanel3
            // 
            this.flowLayoutPanel3.Controls.Add(this.TextEstado);
            this.flowLayoutPanel3.Controls.Add(this.TextValidacion);
            this.flowLayoutPanel3.Location = new System.Drawing.Point(39, 483);
            this.flowLayoutPanel3.Name = "flowLayoutPanel3";
            this.flowLayoutPanel3.Size = new System.Drawing.Size(439, 37);
            this.flowLayoutPanel3.TabIndex = 11;
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(61, 4);
            // 
            // TextTabla
            // 
            this.TextTabla.AutoSize = true;
            this.TextTabla.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TextTabla.Location = new System.Drawing.Point(506, 50);
            this.TextTabla.Name = "TextTabla";
            this.TextTabla.Size = new System.Drawing.Size(214, 31);
            this.TextTabla.TabIndex = 14;
            this.TextTabla.Text = "Tabla de Tokens";
            // 
            // TabladeTokens1
            // 
            this.TabladeTokens1.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TabladeTokens1.Location = new System.Drawing.Point(498, 95);
            this.TabladeTokens1.Multiline = true;
            this.TabladeTokens1.Name = "TabladeTokens1";
            this.TabladeTokens1.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.TabladeTokens1.Size = new System.Drawing.Size(493, 488);
            this.TabladeTokens1.TabIndex = 15;
            // 
            // txtadd
            // 
            this.txtadd.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.txtadd.Font = new System.Drawing.Font("Arial", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtadd.Location = new System.Drawing.Point(34, 543);
            this.txtadd.Name = "txtadd";
            this.txtadd.Size = new System.Drawing.Size(187, 40);
            this.txtadd.TabIndex = 16;
            this.txtadd.Text = "Añadir archivo .txt";
            this.txtadd.UseVisualStyleBackColor = false;
            this.txtadd.Click += new System.EventHandler(this.txtadd_Click);
            // 
            // usrAL
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.ForestGreen;
            this.Controls.Add(this.txtadd);
            this.Controls.Add(this.TabladeTokens1);
            this.Controls.Add(this.TextTabla);
            this.Controls.Add(this.flowLayoutPanel3);
            this.Controls.Add(this.flowLayoutPanel2);
            this.Controls.Add(this.flowLayoutPanel1);
            this.Controls.Add(this.Chars);
            this.Controls.Add(this.Ingresador);
            this.Controls.Add(this.Ingreso);
            this.Name = "usrAL";
            this.Size = new System.Drawing.Size(1047, 735);
            this.Load += new System.EventHandler(this.usrAL_Load);
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

        private System.Windows.Forms.Label Ingreso;
        private System.Windows.Forms.Label TextContador;
        private System.Windows.Forms.TextBox Ingresador;
        private System.Windows.Forms.Label TextContadora;
        private System.Windows.Forms.Button Chars;
        private System.Windows.Forms.Label TextValidacion;
        private System.Windows.Forms.Label TextDato;
        private System.Windows.Forms.Label TextAsignador;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel1;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel2;
        private System.Windows.Forms.Label TextEstado;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel3;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.Label TextTabla;
        private System.Windows.Forms.TextBox TabladeTokens1;
        private System.Windows.Forms.Button txtadd;
    }
}
