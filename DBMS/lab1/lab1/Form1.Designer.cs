namespace lab1
{
    partial class Form1
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
            this.EmployeersView = new System.Windows.Forms.DataGridView();
            this.EmployeersTasksView = new System.Windows.Forms.DataGridView();
            this.EmployeersTasksUpdate = new System.Windows.Forms.GroupBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.UpdateButton = new System.Windows.Forms.Button();
            this.DeleteButton = new System.Windows.Forms.Button();
            this.EidText = new System.Windows.Forms.TextBox();
            this.DescriptionText = new System.Windows.Forms.TextBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.AddButton = new System.Windows.Forms.Button();
            this.DescriptionText2 = new System.Windows.Forms.TextBox();
            this.ETidText = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.EmployeersView)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.EmployeersTasksView)).BeginInit();
            this.EmployeersTasksUpdate.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // EmployeersView
            // 
            this.EmployeersView.BackgroundColor = System.Drawing.SystemColors.ButtonHighlight;
            this.EmployeersView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.EmployeersView.Location = new System.Drawing.Point(6, 19);
            this.EmployeersView.Name = "EmployeersView";
            this.EmployeersView.Size = new System.Drawing.Size(464, 159);
            this.EmployeersView.TabIndex = 0;
            this.EmployeersView.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.EmployeersView_CellClick);
            // 
            // EmployeersTasksView
            // 
            this.EmployeersTasksView.BackgroundColor = System.Drawing.SystemColors.ButtonHighlight;
            this.EmployeersTasksView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.EmployeersTasksView.Location = new System.Drawing.Point(25, 19);
            this.EmployeersTasksView.Name = "EmployeersTasksView";
            this.EmployeersTasksView.Size = new System.Drawing.Size(334, 108);
            this.EmployeersTasksView.TabIndex = 1;
            this.EmployeersTasksView.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.EmployeersTasksView_CellClick);
            // 
            // EmployeersTasksUpdate
            // 
            this.EmployeersTasksUpdate.Controls.Add(this.label4);
            this.EmployeersTasksUpdate.Controls.Add(this.label1);
            this.EmployeersTasksUpdate.Controls.Add(this.EmployeersTasksView);
            this.EmployeersTasksUpdate.Controls.Add(this.UpdateButton);
            this.EmployeersTasksUpdate.Controls.Add(this.DeleteButton);
            this.EmployeersTasksUpdate.Controls.Add(this.EidText);
            this.EmployeersTasksUpdate.Controls.Add(this.DescriptionText);
            this.EmployeersTasksUpdate.Location = new System.Drawing.Point(495, 21);
            this.EmployeersTasksUpdate.Name = "EmployeersTasksUpdate";
            this.EmployeersTasksUpdate.Size = new System.Drawing.Size(365, 292);
            this.EmployeersTasksUpdate.TabIndex = 3;
            this.EmployeersTasksUpdate.TabStop = false;
            this.EmployeersTasksUpdate.Text = "EmployeersTasks";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(25, 182);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(22, 13);
            this.label4.TabIndex = 5;
            this.label4.Text = "Eid";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(25, 141);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(60, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "Description";
            // 
            // UpdateButton
            // 
            this.UpdateButton.Location = new System.Drawing.Point(225, 228);
            this.UpdateButton.Name = "UpdateButton";
            this.UpdateButton.Size = new System.Drawing.Size(92, 23);
            this.UpdateButton.TabIndex = 3;
            this.UpdateButton.Text = "Update";
            this.UpdateButton.UseVisualStyleBackColor = true;
            this.UpdateButton.Click += new System.EventHandler(this.UpdateButton_Click);
            // 
            // DeleteButton
            // 
            this.DeleteButton.Location = new System.Drawing.Point(94, 228);
            this.DeleteButton.Name = "DeleteButton";
            this.DeleteButton.Size = new System.Drawing.Size(92, 21);
            this.DeleteButton.TabIndex = 2;
            this.DeleteButton.Text = "Delete";
            this.DeleteButton.UseVisualStyleBackColor = true;
            this.DeleteButton.Click += new System.EventHandler(this.DeleteButton_Click);
            // 
            // EidText
            // 
            this.EidText.Location = new System.Drawing.Point(94, 182);
            this.EidText.Name = "EidText";
            this.EidText.Size = new System.Drawing.Size(223, 20);
            this.EidText.TabIndex = 1;
            // 
            // DescriptionText
            // 
            this.DescriptionText.Location = new System.Drawing.Point(94, 141);
            this.DescriptionText.Name = "DescriptionText";
            this.DescriptionText.Size = new System.Drawing.Size(223, 20);
            this.DescriptionText.TabIndex = 0;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.AddButton);
            this.groupBox1.Controls.Add(this.DescriptionText2);
            this.groupBox1.Controls.Add(this.ETidText);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.EmployeersView);
            this.groupBox1.Location = new System.Drawing.Point(3, 21);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(486, 292);
            this.groupBox1.TabIndex = 4;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Employeers";
            // 
            // AddButton
            // 
            this.AddButton.Location = new System.Drawing.Point(184, 259);
            this.AddButton.Name = "AddButton";
            this.AddButton.Size = new System.Drawing.Size(110, 23);
            this.AddButton.TabIndex = 5;
            this.AddButton.Text = "Add";
            this.AddButton.UseVisualStyleBackColor = true;
            this.AddButton.Click += new System.EventHandler(this.AddButton_Click);
            // 
            // DescriptionText2
            // 
            this.DescriptionText2.Location = new System.Drawing.Point(146, 226);
            this.DescriptionText2.Name = "DescriptionText2";
            this.DescriptionText2.Size = new System.Drawing.Size(206, 20);
            this.DescriptionText2.TabIndex = 4;
            // 
            // ETidText
            // 
            this.ETidText.Location = new System.Drawing.Point(146, 199);
            this.ETidText.Name = "ETidText";
            this.ETidText.Size = new System.Drawing.Size(206, 20);
            this.ETidText.TabIndex = 3;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(76, 226);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(60, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Description";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(76, 202);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(29, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "ETid";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(893, 329);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.EmployeersTasksUpdate);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.EmployeersView)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.EmployeersTasksView)).EndInit();
            this.EmployeersTasksUpdate.ResumeLayout(false);
            this.EmployeersTasksUpdate.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView EmployeersView;
        private System.Windows.Forms.DataGridView EmployeersTasksView;
        private System.Windows.Forms.GroupBox EmployeersTasksUpdate;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button UpdateButton;
        private System.Windows.Forms.Button DeleteButton;
        private System.Windows.Forms.TextBox EidText;
        private System.Windows.Forms.TextBox DescriptionText;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox DescriptionText2;
        private System.Windows.Forms.TextBox ETidText;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button AddButton;
    }
}

