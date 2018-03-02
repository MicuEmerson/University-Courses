using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace lab1
{
    public partial class Form1 : Form
    {

        SqlConnection connection = new SqlConnection("Data Source = DESKTOP-8NQ7JEO; Initial Catalog = AthletesSupplements2; Integrated Security = True");
        SqlDataAdapter dataAdapter = new SqlDataAdapter();
        DataSet dataSet = new DataSet();

        SqlDataAdapter dataAdapter2 = new SqlDataAdapter();
        DataSet dataSet2 = new DataSet();

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            dataAdapter.SelectCommand = new SqlCommand("SELECT * FROM Employeers", connection);
            dataSet.Clear();
            dataAdapter.Fill(dataSet);
            EmployeersView.DataSource = dataSet.Tables[0];
        }


        private void EmployeersView_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                int rowindex = EmployeersView.CurrentCell.RowIndex;
                string number = EmployeersView.Rows[rowindex].Cells[0].Value.ToString();

                dataAdapter2.SelectCommand = new SqlCommand("SELECT * FROM EmployersTasks" +
                                                            " WHERE Eid = @Eid", connection);

                dataAdapter2.SelectCommand.Parameters.Add("@Eid", SqlDbType.Int).Value = Int32.Parse(number);
                dataSet2.Clear();
                dataAdapter2.Fill(dataSet2);
                EmployeersTasksView.DataSource = dataSet2.Tables[0];
            }
            catch(Exception ex)
            {
                MessageBox.Show("Invalid row selected");
                connection.Close();
            }


        }

        private void DeleteButton_Click(object sender, EventArgs e)
        {
            try
            {
                int rowindex = EmployeersTasksView.CurrentCell.RowIndex;
                string number = EmployeersTasksView.Rows[rowindex].Cells[0].Value.ToString();
                Console.WriteLine(number);
                dataAdapter.DeleteCommand = new SqlCommand("DELETE FROM EmployersTasks" +
                                                            " WHERE ETid = @ETid", connection);

                dataAdapter.DeleteCommand.Parameters.Add("@ETid", SqlDbType.Int).Value = Int32.Parse(number);

                connection.Open();
                dataAdapter.DeleteCommand.ExecuteNonQuery();
                connection.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                connection.Close();
            }


        }

        private void UpdateButton_Click(object sender, EventArgs e)
        {
            try
            {
                int rowindex = EmployeersTasksView.CurrentCell.RowIndex;
                string number = EmployeersTasksView.Rows[rowindex].Cells[0].Value.ToString();

                dataAdapter.UpdateCommand = new SqlCommand("UPDATE EmployersTasks " +
                                                            " SET Description = @Description, Eid = @Eid" +
                                                            " WHERE ETid = @ETid", connection);

                dataAdapter.UpdateCommand.Parameters.Add("@ETid", SqlDbType.Int).Value = Int32.Parse(number);
                dataAdapter.UpdateCommand.Parameters.Add("@Description", SqlDbType.VarChar).Value = DescriptionText.Text;
                dataAdapter.UpdateCommand.Parameters.Add("@Eid", SqlDbType.Int).Value = Int32.Parse(EidText.Text);

                connection.Open();
                dataAdapter.UpdateCommand.ExecuteNonQuery();
                connection.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                connection.Close();
            }

        }

        private void AddButton_Click(object sender, EventArgs e)
        {
            try
            {
            int rowindex = EmployeersView.CurrentCell.RowIndex;
            string number = EmployeersView.Rows[rowindex].Cells[0].Value.ToString();

                dataAdapter.InsertCommand = new SqlCommand("INSERT INTO EmployersTasks (ETid, Description, Eid)" +
                                                           " VALUES (@ETid, @Description, @Eid)", connection);

                dataAdapter.InsertCommand.Parameters.Add("@ETid", SqlDbType.Int).Value = Int32.Parse(ETidText.Text);
                dataAdapter.InsertCommand.Parameters.Add("@Description", SqlDbType.VarChar).Value = DescriptionText2.Text;
                dataAdapter.InsertCommand.Parameters.Add("@Eid", SqlDbType.Int).Value = Int32.Parse(number);

                connection.Open();
                dataAdapter.InsertCommand.ExecuteNonQuery();
                connection.Close();
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
                connection.Close();
            }

        }

        private void EmployeersTasksView_CellClick(object sender, DataGridViewCellEventArgs e)
        {

            int rowindex = EmployeersTasksView.CurrentCell.RowIndex;
            
            DescriptionText.Text = EmployeersTasksView.Rows[rowindex].Cells[1].Value.ToString();
            EidText.Text = EmployeersTasksView.Rows[rowindex].Cells[2].Value.ToString();
        
        }
    }
}
