namespace COMPILADOR
{
    partial class Form1
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

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.AnalizadorLexico = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.button1 = new System.Windows.Forms.Button();
            this.Polaca = new System.Windows.Forms.Button();
            this.AnalizadorSemantico = new System.Windows.Forms.Button();
            this.ResetButtom = new System.Windows.Forms.Button();
            this.ExitButtom = new System.Windows.Forms.Button();
            this.ReadmeButtom = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // AnalizadorLexico
            // 
            this.AnalizadorLexico.BackColor = System.Drawing.Color.Chartreuse;
            this.AnalizadorLexico.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.AnalizadorLexico.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.AnalizadorLexico.Font = new System.Drawing.Font("Arial Narrow", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.AnalizadorLexico.Location = new System.Drawing.Point(12, 12);
            this.AnalizadorLexico.Name = "AnalizadorLexico";
            this.AnalizadorLexico.Size = new System.Drawing.Size(136, 85);
            this.AnalizadorLexico.TabIndex = 0;
            this.AnalizadorLexico.Text = "Analizador Lexico";
            this.AnalizadorLexico.UseVisualStyleBackColor = false;
            this.AnalizadorLexico.Click += new System.EventHandler(this.button1_Click);
            // 
            // panel1
            // 
            this.panel1.Location = new System.Drawing.Point(154, 12);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(1051, 609);
            this.panel1.TabIndex = 1;
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.Yellow;
            this.button1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.button1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button1.Font = new System.Drawing.Font("Arial Narrow", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.Location = new System.Drawing.Point(12, 103);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(136, 85);
            this.button1.TabIndex = 2;
            this.button1.Text = "Analizador Sintactico";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click_1);
            // 
            // Polaca
            // 
            this.Polaca.BackColor = System.Drawing.Color.Crimson;
            this.Polaca.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.Polaca.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Polaca.Font = new System.Drawing.Font("Arial Narrow", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Polaca.Location = new System.Drawing.Point(12, 285);
            this.Polaca.Name = "Polaca";
            this.Polaca.Size = new System.Drawing.Size(136, 85);
            this.Polaca.TabIndex = 3;
            this.Polaca.Text = "Codigo Intermedio (Polaca)";
            this.Polaca.UseVisualStyleBackColor = false;
            this.Polaca.Click += new System.EventHandler(this.Polaca_Click);
            // 
            // AnalizadorSemantico
            // 
            this.AnalizadorSemantico.BackColor = System.Drawing.Color.MediumVioletRed;
            this.AnalizadorSemantico.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.AnalizadorSemantico.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.AnalizadorSemantico.Font = new System.Drawing.Font("Arial Narrow", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.AnalizadorSemantico.Location = new System.Drawing.Point(12, 194);
            this.AnalizadorSemantico.Name = "AnalizadorSemantico";
            this.AnalizadorSemantico.Size = new System.Drawing.Size(136, 85);
            this.AnalizadorSemantico.TabIndex = 4;
            this.AnalizadorSemantico.Text = "Analizador Semantico";
            this.AnalizadorSemantico.UseVisualStyleBackColor = false;
            this.AnalizadorSemantico.Click += new System.EventHandler(this.AnalizadorSemantico_Click);
            // 
            // ResetButtom
            // 
            this.ResetButtom.BackColor = System.Drawing.Color.LavenderBlush;
            this.ResetButtom.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.ResetButtom.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.ResetButtom.Font = new System.Drawing.Font("Arial Narrow", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ResetButtom.Location = new System.Drawing.Point(81, 549);
            this.ResetButtom.Name = "ResetButtom";
            this.ResetButtom.Size = new System.Drawing.Size(67, 32);
            this.ResetButtom.TabIndex = 5;
            this.ResetButtom.Text = "RESET";
            this.ResetButtom.UseVisualStyleBackColor = false;
            this.ResetButtom.Click += new System.EventHandler(this.ResetButtom_Click);
            // 
            // ExitButtom
            // 
            this.ExitButtom.BackColor = System.Drawing.Color.LavenderBlush;
            this.ExitButtom.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.ExitButtom.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.ExitButtom.Font = new System.Drawing.Font("Arial Narrow", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ExitButtom.Location = new System.Drawing.Point(12, 587);
            this.ExitButtom.Name = "ExitButtom";
            this.ExitButtom.Size = new System.Drawing.Size(136, 32);
            this.ExitButtom.TabIndex = 6;
            this.ExitButtom.Text = "Exit";
            this.ExitButtom.UseVisualStyleBackColor = false;
            this.ExitButtom.Click += new System.EventHandler(this.ExitButtom_Click);
            // 
            // ReadmeButtom
            // 
            this.ReadmeButtom.BackColor = System.Drawing.Color.LavenderBlush;
            this.ReadmeButtom.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.ReadmeButtom.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.ReadmeButtom.Font = new System.Drawing.Font("Arial Narrow", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ReadmeButtom.Location = new System.Drawing.Point(12, 549);
            this.ReadmeButtom.Name = "ReadmeButtom";
            this.ReadmeButtom.Size = new System.Drawing.Size(67, 32);
            this.ReadmeButtom.TabIndex = 7;
            this.ReadmeButtom.Text = "README";
            this.ReadmeButtom.UseVisualStyleBackColor = false;
            this.ReadmeButtom.Click += new System.EventHandler(this.ReadmeButtom_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ControlDarkDark;
            this.ClientSize = new System.Drawing.Size(1217, 642);
            this.Controls.Add(this.ReadmeButtom);
            this.Controls.Add(this.ExitButtom);
            this.Controls.Add(this.ResetButtom);
            this.Controls.Add(this.AnalizadorSemantico);
            this.Controls.Add(this.Polaca);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.AnalizadorLexico);
            this.ForeColor = System.Drawing.SystemColors.ControlText;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.Text = "Compilador en CSharp";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button AnalizadorLexico;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button Polaca;
        private System.Windows.Forms.Button AnalizadorSemantico;
        private System.Windows.Forms.Button ResetButtom;
        private System.Windows.Forms.Button ExitButtom;
        private System.Windows.Forms.Button ReadmeButtom;
    }
}

