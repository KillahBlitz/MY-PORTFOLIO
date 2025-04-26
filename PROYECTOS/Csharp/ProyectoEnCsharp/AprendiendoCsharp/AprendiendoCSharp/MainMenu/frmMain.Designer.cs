namespace AprendiendoCSharp.MainMenu
{
    partial class frmMain
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmMain));
            this.Text1 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.flowLayoutPanel1 = new System.Windows.Forms.FlowLayoutPanel();
            this.BottomOA = new System.Windows.Forms.Button();
            this.bottomOR = new System.Windows.Forms.Button();
            this.bottomOL = new System.Windows.Forms.Button();
            this.Menu = new System.Windows.Forms.Label();
            this.PanelVisor = new System.Windows.Forms.Panel();
            this.Image1 = new System.Windows.Forms.PictureBox();
            this.panel1.SuspendLayout();
            this.flowLayoutPanel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.Image1)).BeginInit();
            this.SuspendLayout();
            // 
            // Text1
            // 
            this.Text1.BackColor = System.Drawing.Color.Gray;
            this.Text1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Text1.Font = new System.Drawing.Font("Arial Rounded MT Bold", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Text1.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.Text1.Location = new System.Drawing.Point(12, 9);
            this.Text1.Name = "Text1";
            this.Text1.Size = new System.Drawing.Size(171, 33);
            this.Text1.TabIndex = 1;
            this.Text1.Text = "AppKap Services";
            this.Text1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.Image1);
            this.panel1.Controls.Add(this.flowLayoutPanel1);
            this.panel1.Controls.Add(this.Menu);
            this.panel1.Location = new System.Drawing.Point(16, 78);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(188, 518);
            this.panel1.TabIndex = 2;
            // 
            // flowLayoutPanel1
            // 
            this.flowLayoutPanel1.Controls.Add(this.BottomOA);
            this.flowLayoutPanel1.Controls.Add(this.bottomOR);
            this.flowLayoutPanel1.Controls.Add(this.bottomOL);
            this.flowLayoutPanel1.Location = new System.Drawing.Point(7, 38);
            this.flowLayoutPanel1.Name = "flowLayoutPanel1";
            this.flowLayoutPanel1.Size = new System.Drawing.Size(168, 275);
            this.flowLayoutPanel1.TabIndex = 4;
            // 
            // BottomOA
            // 
            this.BottomOA.BackColor = System.Drawing.Color.SlateGray;
            this.BottomOA.FlatAppearance.BorderSize = 0;
            this.BottomOA.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.BottomOA.Font = new System.Drawing.Font("Arial Narrow", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.BottomOA.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.BottomOA.Location = new System.Drawing.Point(3, 3);
            this.BottomOA.Name = "BottomOA";
            this.BottomOA.Size = new System.Drawing.Size(157, 81);
            this.BottomOA.TabIndex = 1;
            this.BottomOA.Text = "Operadores Aritmeticos";
            this.BottomOA.UseVisualStyleBackColor = false;
            this.BottomOA.Click += new System.EventHandler(this.BottomOA_Click);
            // 
            // bottomOR
            // 
            this.bottomOR.BackColor = System.Drawing.Color.SlateGray;
            this.bottomOR.FlatAppearance.BorderSize = 0;
            this.bottomOR.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.bottomOR.Font = new System.Drawing.Font("Arial Narrow", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.bottomOR.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.bottomOR.Location = new System.Drawing.Point(3, 90);
            this.bottomOR.Name = "bottomOR";
            this.bottomOR.Size = new System.Drawing.Size(157, 81);
            this.bottomOR.TabIndex = 2;
            this.bottomOR.Text = "Operadores Relacionales";
            this.bottomOR.UseVisualStyleBackColor = false;
            this.bottomOR.Click += new System.EventHandler(this.bottomOR_Click);
            // 
            // bottomOL
            // 
            this.bottomOL.BackColor = System.Drawing.Color.SlateGray;
            this.bottomOL.FlatAppearance.BorderSize = 0;
            this.bottomOL.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.bottomOL.Font = new System.Drawing.Font("Arial Narrow", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.bottomOL.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.bottomOL.Location = new System.Drawing.Point(3, 177);
            this.bottomOL.Name = "bottomOL";
            this.bottomOL.Size = new System.Drawing.Size(157, 81);
            this.bottomOL.TabIndex = 3;
            this.bottomOL.Text = "Operadores Logicos";
            this.bottomOL.UseVisualStyleBackColor = false;
            this.bottomOL.Click += new System.EventHandler(this.bottomOL_Click);
            // 
            // Menu
            // 
            this.Menu.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.Menu.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Menu.Font = new System.Drawing.Font("Arial Rounded MT Bold", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Menu.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.Menu.Location = new System.Drawing.Point(3, 0);
            this.Menu.Name = "Menu";
            this.Menu.Size = new System.Drawing.Size(100, 35);
            this.Menu.TabIndex = 3;
            this.Menu.Text = "Services:";
            this.Menu.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // PanelVisor
            // 
            this.PanelVisor.Location = new System.Drawing.Point(210, 13);
            this.PanelVisor.Name = "PanelVisor";
            this.PanelVisor.Size = new System.Drawing.Size(967, 583);
            this.PanelVisor.TabIndex = 3;
            // 
            // Image1
            // 
            this.Image1.Image = ((System.Drawing.Image)(resources.GetObject("Image1.Image")));
            this.Image1.Location = new System.Drawing.Point(0, 333);
            this.Image1.Name = "Image1";
            this.Image1.Size = new System.Drawing.Size(188, 182);
            this.Image1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.Image1.TabIndex = 5;
            this.Image1.TabStop = false;
            // 
            // frmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.ClientSize = new System.Drawing.Size(1189, 608);
            this.Controls.Add(this.PanelVisor);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.Text1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "frmMain";
            this.Text = "AppKap";
            this.Load += new System.EventHandler(this.frmMain_Load);
            this.panel1.ResumeLayout(false);
            this.flowLayoutPanel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.Image1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label Text1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label Menu;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel1;
        private System.Windows.Forms.Button BottomOA;
        private System.Windows.Forms.Button bottomOR;
        private System.Windows.Forms.Button bottomOL;
        private System.Windows.Forms.Panel PanelVisor;
        private System.Windows.Forms.PictureBox Image1;
    }
}