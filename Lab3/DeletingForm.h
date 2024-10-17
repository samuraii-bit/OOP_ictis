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
	/// Сводка для DeletingForm
	/// </summary>
	public ref class DeletingForm : public System::Windows::Forms::Form
	{
	public:
		String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:/Users/Ivan/source/repos/Lab_V3/Lab_V3/myDataBase.accdb";
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	public:
		OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	public:
		DeletingForm(void)
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
		~DeletingForm()
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(157, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введите номер заказа";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(13, 34);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(157, 22);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(200, 104);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(98, 30);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Удалить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &DeletingForm::button1_Click);
			// 
			// DeletingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(310, 146);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"DeletingForm";
			this->Text = L"DeletingForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->textBox1->Text != "")
		{
			dbConnection->Open();
			int orderNum = Convert::ToInt32(this->textBox1->Text);
			String^ query = "DELETE FROM [Книга заказов] WHERE [Номер заказа] = " + orderNum;
			OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
			dbCommand->ExecuteNonQuery();
			dbConnection->Close();
			MessageBox::Show("Заказ успешно удален!");
		}
		else
		{
			MessageBox::Show("Для удаления введите номер заказа.");
		}
	}
	};
}
