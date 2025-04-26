namespace AprendiendoCSharp.MainMenu
{
    partial class usrcOA
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
            this.Cooltextresultado2 = new System.Windows.Forms.Label();
            this.CooltextResultado1 = new System.Windows.Forms.Label();
            this.flowLayoutPanel1 = new System.Windows.Forms.FlowLayoutPanel();
            this.resta0 = new System.Windows.Forms.Button();
            this.suma0 = new System.Windows.Forms.Button();
            this.multiplicacion = new System.Windows.Forms.Button();
            this.division = new System.Windows.Forms.Button();
            this.Cooltextoperador1 = new System.Windows.Forms.Label();
            this.Cooltextingreso2 = new System.Windows.Forms.Label();
            this.Cooltextingreso1 = new System.Windows.Forms.Label();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.Textoinicio = new System.Windows.Forms.Label();
            this.flowLayoutPanel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // Cooltextresultado2
            // 
            this.Cooltextresultado2.AutoSize = true;
            this.Cooltextresultado2.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Italic);
            this.Cooltextresultado2.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.Cooltextresultado2.Location = new System.Drawing.Point(504, 228);
            this.Cooltextresultado2.Name = "Cooltextresultado2";
            this.Cooltextresultado2.Size = new System.Drawing.Size(23, 31);
            this.Cooltextresultado2.TabIndex = 22;
            this.Cooltextresultado2.Text = "-";
            // 
            // CooltextResultado1
            // 
            this.CooltextResultado1.AutoSize = true;
            this.CooltextResultado1.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Italic);
            this.CooltextResultado1.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.CooltextResultado1.Location = new System.Drawing.Point(353, 228);
            this.CooltextResultado1.Name = "CooltextResultado1";
            this.CooltextResultado1.Size = new System.Drawing.Size(145, 31);
            this.CooltextResultado1.TabIndex = 21;
            this.CooltextResultado1.Text = "Resultado:";
            // 
            // flowLayoutPanel1
            // 
            this.flowLayoutPanel1.Controls.Add(this.resta0);
            this.flowLayoutPanel1.Controls.Add(this.suma0);
            this.flowLayoutPanel1.Controls.Add(this.multiplicacion);
            this.flowLayoutPanel1.Controls.Add(this.division);
            this.flowLayoutPanel1.Location = new System.Drawing.Point(229, 406);
            this.flowLayoutPanel1.Name = "flowLayoutPanel1";
            this.flowLayoutPanel1.Size = new System.Drawing.Size(404, 74);
            this.flowLayoutPanel1.TabIndex = 23;
            // 
            // resta0
            // 
            this.resta0.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(185)))), ((int)(((byte)(226)))), ((int)(((byte)(222)))));
            this.resta0.FlatAppearance.BorderSize = 2;
            this.resta0.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.resta0.Font = new System.Drawing.Font("Arial", 16F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.resta0.Location = new System.Drawing.Point(3, 4);
            this.resta0.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.resta0.Name = "resta0";
            this.resta0.Size = new System.Drawing.Size(94, 56);
            this.resta0.TabIndex = 13;
            this.resta0.Text = "+";
            this.resta0.UseVisualStyleBackColor = false;
            this.resta0.Click += new System.EventHandler(this.resta0_Click);
            // 
            // suma0
            // 
            this.suma0.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(185)))), ((int)(((byte)(226)))), ((int)(((byte)(222)))));
            this.suma0.FlatAppearance.BorderSize = 2;
            this.suma0.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.suma0.Font = new System.Drawing.Font("Arial", 16F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.suma0.Location = new System.Drawing.Point(103, 4);
            this.suma0.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.suma0.Name = "suma0";
            this.suma0.Size = new System.Drawing.Size(94, 56);
            this.suma0.TabIndex = 12;
            this.suma0.Text = "-";
            this.suma0.UseVisualStyleBackColor = false;
            this.suma0.Click += new System.EventHandler(this.suma0_Click);
            // 
            // multiplicacion
            // 
            this.multiplicacion.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(185)))), ((int)(((byte)(226)))), ((int)(((byte)(222)))));
            this.multiplicacion.FlatAppearance.BorderSize = 2;
            this.multiplicacion.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.multiplicacion.Font = new System.Drawing.Font("Arial", 16F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.multiplicacion.Location = new System.Drawing.Point(203, 4);
            this.multiplicacion.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.multiplicacion.Name = "multiplicacion";
            this.multiplicacion.Size = new System.Drawing.Size(94, 56);
            this.multiplicacion.TabIndex = 10;
            this.multiplicacion.Text = "×";
            this.multiplicacion.UseVisualStyleBackColor = false;
            this.multiplicacion.Click += new System.EventHandler(this.multiplicacion_Click);
            // 
            // division
            // 
            this.division.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(185)))), ((int)(((byte)(226)))), ((int)(((byte)(222)))));
            this.division.FlatAppearance.BorderSize = 2;
            this.division.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.division.Font = new System.Drawing.Font("Arial", 16F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.division.Location = new System.Drawing.Point(303, 4);
            this.division.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.division.Name = "division";
            this.division.Size = new System.Drawing.Size(94, 56);
            this.division.TabIndex = 11;
            this.division.Text = "÷";
            this.division.UseVisualStyleBackColor = false;
            this.division.Click += new System.EventHandler(this.division_Click);
            // 
            // Cooltextoperador1
            // 
            this.Cooltextoperador1.AutoSize = true;
            this.Cooltextoperador1.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Italic);
            this.Cooltextoperador1.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.Cooltextoperador1.Location = new System.Drawing.Point(224, 372);
            this.Cooltextoperador1.Name = "Cooltextoperador1";
            this.Cooltextoperador1.Size = new System.Drawing.Size(274, 31);
            this.Cooltextoperador1.TabIndex = 20;
            this.Cooltextoperador1.Text = "Ingrese la Operacion:";
            // 
            // Cooltextingreso2
            // 
            this.Cooltextingreso2.AutoSize = true;
            this.Cooltextingreso2.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Italic);
            this.Cooltextingreso2.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.Cooltextingreso2.Location = new System.Drawing.Point(93, 253);
            this.Cooltextingreso2.Name = "Cooltextingreso2";
            this.Cooltextingreso2.Size = new System.Drawing.Size(249, 31);
            this.Cooltextingreso2.TabIndex = 19;
            this.Cooltextingreso2.Text = "Ingrese un numero:";
            // 
            // Cooltextingreso1
            // 
            this.Cooltextingreso1.AutoSize = true;
            this.Cooltextingreso1.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Italic);
            this.Cooltextingreso1.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.Cooltextingreso1.Location = new System.Drawing.Point(93, 115);
            this.Cooltextingreso1.Name = "Cooltextingreso1";
            this.Cooltextingreso1.Size = new System.Drawing.Size(249, 31);
            this.Cooltextingreso1.TabIndex = 18;
            this.Cooltextingreso1.Text = "Ingrese un numero:";
            // 
            // textBox2
            // 
            this.textBox2.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox2.ForeColor = System.Drawing.Color.Black;
            this.textBox2.Location = new System.Drawing.Point(97, 301);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(244, 39);
            this.textBox2.TabIndex = 17;
            // 
            // textBox1
            // 
            this.textBox1.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox1.ForeColor = System.Drawing.Color.Black;
            this.textBox1.Location = new System.Drawing.Point(98, 164);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(244, 39);
            this.textBox1.TabIndex = 16;
            // 
            // Textoinicio
            // 
            this.Textoinicio.AutoSize = true;
            this.Textoinicio.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Italic);
            this.Textoinicio.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.Textoinicio.Location = new System.Drawing.Point(43, 47);
            this.Textoinicio.Name = "Textoinicio";
            this.Textoinicio.Size = new System.Drawing.Size(299, 31);
            this.Textoinicio.TabIndex = 15;
            this.Textoinicio.Text = "Operadores Aritmeticos";
            // 
            // usrcOA
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.Controls.Add(this.Cooltextresultado2);
            this.Controls.Add(this.CooltextResultado1);
            this.Controls.Add(this.flowLayoutPanel1);
            this.Controls.Add(this.Cooltextoperador1);
            this.Controls.Add(this.Cooltextingreso2);
            this.Controls.Add(this.Cooltextingreso1);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.Textoinicio);
            this.Name = "usrcOA";
            this.Size = new System.Drawing.Size(1069, 622);
            this.Load += new System.EventHandler(this.usrcOA_Load);
            this.flowLayoutPanel1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label Cooltextresultado2;
        private System.Windows.Forms.Label CooltextResultado1;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel1;
        private System.Windows.Forms.Button resta0;
        private System.Windows.Forms.Button suma0;
        private System.Windows.Forms.Button multiplicacion;
        private System.Windows.Forms.Button division;
        private System.Windows.Forms.Label Cooltextoperador1;
        private System.Windows.Forms.Label Cooltextingreso2;
        private System.Windows.Forms.Label Cooltextingreso1;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Label Textoinicio;
    }
}
