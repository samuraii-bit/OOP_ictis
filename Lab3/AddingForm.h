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
	/// Сводка для AddingForm
	/// </summary>
	public ref class AddingForm : public System::Windows::Forms::Form
	{
	public:
		String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:/Users/Ivan/source/repos/Lab_V3/Lab_V3/myDataBase.accdb";
		OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	public:
		AddingForm(void)
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
		~AddingForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;


	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;


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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(199, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введите номер сертификата";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 29);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(200, 22);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(262, 105);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(134, 36);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Редактировать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AddingForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 54);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(143, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Введите количество";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 99);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(170, 17);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Введите адрес поставки";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 74);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(200, 22);
			this->textBox2->TabIndex = 7;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(12, 119);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(200, 22);
			this->textBox3->TabIndex = 8;
			// 
			// AddingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(408, 154);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"AddingForm";
			this->Text = L"AddingForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->textBox1->Text != "" && this->textBox2->Text != "" && this->textBox3->Text != "")
		{
			int certNum = Convert::ToInt32(this->textBox1->Text);
			int quantity = Convert::ToInt32(this->textBox2->Text);
			String^ address = this->textBox3->Text;
			String^ query = "INSERT INTO [Книга заказов] ([Номер сертификата], [Количество], [Адрес поставки]) VALUES (" + certNum + "," + quantity + ", \'" + address + "\')";
			dbConnection->Open();
			OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
			dbCommand->ExecuteNonQuery();
			MessageBox::Show("Заказ успешно добавлен!");
			dbConnection->Close();
		}
		else
		{
			MessageBox::Show("Для добавления заказа введите все данные.");
		}
	}
};
}
