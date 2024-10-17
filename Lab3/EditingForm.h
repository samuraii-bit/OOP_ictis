#pragma once

namespace LabV3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::OleDb;

	/// <summary>
	/// Сводка для EditingForm
	/// </summary>
	public ref class EditingForm : public System::Windows::Forms::Form
	{
	public:
		String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:/Users/Ivan/source/repos/Lab_V3/Lab_V3/myDataBase.accdb";
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	public:
		OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	public:
		EditingForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~EditingForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(260, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(157, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введите номер заказа";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(310, 157);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(107, 29);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Изменить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &EditingForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(263, 29);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(154, 22);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(13, 74);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(244, 22);
			this->textBox2->TabIndex = 3;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(13, 119);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(244, 22);
			this->textBox3->TabIndex = 4;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(13, 164);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(244, 22);
			this->textBox4->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 54);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(244, 17);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Введите новый номер сертификата";
			this->label2->Click += gcnew System::EventHandler(this, &EditingForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 99);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(186, 17);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Введите новое количество";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 144);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(155, 17);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Введите новый адрес ";
			// 
			// EditingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(428, 200);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"EditingForm";
			this->Text = L"EditingForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->textBox1->Text != "")
	{
		dbConnection->Open();
		int certNum = Convert::ToInt32(this->textBox2->Text);
		int quantity = Convert::ToInt32(this->textBox3->Text);
		String^ address = this->textBox4->Text;
		int orderNum = Convert::ToInt32(this->textBox1->Text);
		String^ query;
		OleDbCommand^ dbCommand1, ^ dbCommand2;
	
		if (this->textBox2->Text != "")
		{
			query = "UPDATE [Книга заказов] SET [Номер сертификата] = " + certNum + " WHERE [Номер заказа] = " + orderNum;
			dbCommand1 = gcnew OleDbCommand(query, dbConnection);
			dbCommand1->ExecuteNonQuery();
		}
		if (this->textBox3->Text != "")
		{
			query = "UPDATE [Книга заказов] SET [Количество] = " + quantity + " WHERE [Номер заказа] = " + orderNum;
			dbCommand2 = gcnew OleDbCommand(query, dbConnection);
			dbCommand2->ExecuteNonQuery();
		}
		if (this->textBox3->Text != "")
		{
			query = "UPDATE [Книга заказов] SET [Адрес поставки] = \'" + address + "\' WHERE [Номер заказа] = " + orderNum;
			dbCommand2 = gcnew OleDbCommand(query, dbConnection);
			dbCommand2->ExecuteNonQuery();
		}
		MessageBox::Show("Заказ успешно отредактирован!");
	}
	else
	{
		MessageBox::Show("Для редактирования введите номер заказа.");
	}
	dbConnection->Close();
}
};
}
