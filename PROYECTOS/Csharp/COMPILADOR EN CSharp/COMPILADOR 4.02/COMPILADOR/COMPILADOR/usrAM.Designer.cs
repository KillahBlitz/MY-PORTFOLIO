namespace COMPILADOR
{
    partial class usrAM
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
            this.CodiGeneral = new System.Windows.Forms.Label();
            this.CodiSentencias = new System.Windows.Forms.Label();
            this.CadenaFinal = new System.Windows.Forms.Label();
            this.SentenciasFinales = new System.Windows.Forms.Label();
            this.btnAnalizadorAM = new System.Windows.Forms.Button();
            this.EDOAM = new System.Windows.Forms.Label();
            this.EDAVOI = new System.Windows.Forms.Label();
            this.AsignacionIDS = new System.Windows.Forms.TextBox();
            this.txtnewsentence = new System.Windows.Forms.Label();
            this.newSentence = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // CodiGeneral
            // 
            this.CodiGeneral.AutoSize = true;
            this.CodiGeneral.Font = new System.Drawing.Font("Arial Rounded MT Bold", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.CodiGeneral.Location = new System.Drawing.Point(21, 48);
            this.CodiGeneral.Name = "CodiGeneral";
            this.CodiGeneral.Size = new System.Drawing.Size(305, 24);
            this.CodiGeneral.TabIndex = 1;
            this.CodiGeneral.Text = "CADENA FINAL INGRESADA";
            // 
            // CodiSentencias
            // 
            this.CodiSentencias.AutoSize = true;
            this.CodiSentencias.Font = new System.Drawing.Font("Arial Rounded MT Bold", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.CodiSentencias.Location = new System.Drawing.Point(536, 48);
            this.CodiSentencias.Name = "CodiSentencias";
            this.CodiSentencias.Size = new System.Drawing.Size(240, 24);
            this.CodiSentencias.TabIndex = 2;
            this.CodiSentencias.Text = "Sentencias Ingresadas";
            // 
            // CadenaFinal
            // 
            this.CadenaFinal.AutoSize = true;
            this.CadenaFinal.Font = new System.Drawing.Font("Arial Rounded MT Bold", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.CadenaFinal.Location = new System.Drawing.Point(22, 96);
            this.CadenaFinal.Name = "CadenaFinal";
            this.CadenaFinal.Size = new System.Drawing.Size(13, 18);
            this.CadenaFinal.TabIndex = 3;
            this.CadenaFinal.Text = "-";
            // 
            // SentenciasFinales
            // 
            this.SentenciasFinales.AutoSize = true;
            this.SentenciasFinales.Font = new System.Drawing.Font("Arial Rounded MT Bold", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.SentenciasFinales.Location = new System.Drawing.Point(509, 96);
            this.SentenciasFinales.Name = "SentenciasFinales";
            this.SentenciasFinales.Size = new System.Drawing.Size(13, 18);
            this.SentenciasFinales.TabIndex = 4;
            this.SentenciasFinales.Text = "-";
            // 
            // btnAnalizadorAM
            // 
            this.btnAnalizadorAM.Location = new System.Drawing.Point(807, 534);
            this.btnAnalizadorAM.Name = "btnAnalizadorAM";
            this.btnAnalizadorAM.Size = new System.Drawing.Size(175, 54);
            this.btnAnalizadorAM.TabIndex = 5;
            this.btnAnalizadorAM.Text = "Realizar Analisis Semantico";
            this.btnAnalizadorAM.UseVisualStyleBackColor = true;
            this.btnAnalizadorAM.Click += new System.EventHandler(this.button1_Click);
            // 
            // EDOAM
            // 
            this.EDOAM.AutoSize = true;
            this.EDOAM.Font = new System.Drawing.Font("Arial Rounded MT Bold", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.EDOAM.Location = new System.Drawing.Point(20, 523);
            this.EDOAM.Name = "EDOAM";
            this.EDOAM.Size = new System.Drawing.Size(200, 24);
            this.EDOAM.TabIndex = 6;
            this.EDOAM.Text = "Estado Semantico:";
            // 
            // EDAVOI
            // 
            this.EDAVOI.AutoSize = true;
            this.EDAVOI.Font = new System.Drawing.Font("Arial Rounded MT Bold", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.EDAVOI.Location = new System.Drawing.Point(20, 564);
            this.EDAVOI.Name = "EDAVOI";
            this.EDAVOI.Size = new System.Drawing.Size(17, 24);
            this.EDAVOI.TabIndex = 7;
            this.EDAVOI.Text = "-";
            // 
            // AsignacionIDS
            // 
            this.AsignacionIDS.Font = new System.Drawing.Font("Arial", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.AsignacionIDS.Location = new System.Drawing.Point(512, 228);
            this.AsignacionIDS.Multiline = true;
            this.AsignacionIDS.Name = "AsignacionIDS";
            this.AsignacionIDS.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.AsignacionIDS.Size = new System.Drawing.Size(389, 219);
            this.AsignacionIDS.TabIndex = 17;
            // 
            // txtnewsentence
            // 
            this.txtnewsentence.AutoSize = true;
            this.txtnewsentence.Font = new System.Drawing.Font("Arial Rounded MT Bold", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtnewsentence.Location = new System.Drawing.Point(536, 126);
            this.txtnewsentence.Name = "txtnewsentence";
            this.txtnewsentence.Size = new System.Drawing.Size(206, 24);
            this.txtnewsentence.TabIndex = 18;
            this.txtnewsentence.Text = "Sentencia recibida:";
            // 
            // newSentence
            // 
            this.newSentence.AutoSize = true;
            this.newSentence.Font = new System.Drawing.Font("Arial Rounded MT Bold", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.newSentence.Location = new System.Drawing.Point(509, 170);
            this.newSentence.Name = "newSentence";
            this.newSentence.Size = new System.Drawing.Size(13, 18);
            this.newSentence.TabIndex = 19;
            this.newSentence.Text = "-";
            // 
            // usrAM
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.DarkMagenta;
            this.Controls.Add(this.newSentence);
            this.Controls.Add(this.txtnewsentence);
            this.Controls.Add(this.AsignacionIDS);
            this.Controls.Add(this.EDAVOI);
            this.Controls.Add(this.EDOAM);
            this.Controls.Add(this.btnAnalizadorAM);
            this.Controls.Add(this.SentenciasFinales);
            this.Controls.Add(this.CadenaFinal);
            this.Controls.Add(this.CodiSentencias);
            this.Controls.Add(this.CodiGeneral);
            this.Name = "usrAM";
            this.Size = new System.Drawing.Size(1028, 647);
            this.Load += new System.EventHandler(this.usrAM_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label CodiGeneral;
        private System.Windows.Forms.Label CodiSentencias;
        private System.Windows.Forms.Label CadenaFinal;
        private System.Windows.Forms.Label SentenciasFinales;
        private System.Windows.Forms.Button btnAnalizadorAM;
        private System.Windows.Forms.Label EDOAM;
        private System.Windows.Forms.Label EDAVOI;
        private System.Windows.Forms.TextBox AsignacionIDS;
        private System.Windows.Forms.Label txtnewsentence;
        private System.Windows.Forms.Label newSentence;
    }
}
