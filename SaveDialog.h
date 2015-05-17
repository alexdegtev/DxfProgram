#pragma once

#include <time.h>
#include "Cl_MySQLLib.h"

namespace DxfProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	extern bool saveDialogIsOpen;

	/// <summary>
	/// Сводка для SaveDialog
	/// </summary>
	public ref class SaveDialog : public System::Windows::Forms::Form
	{
	public:
		SaveDialog(void)
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
		~SaveDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::RichTextBox^  description;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  patronymic;
	private: System::Windows::Forms::TextBox^  name;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  surname;
	private: System::Windows::Forms::CheckBox^  checkBox2;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->description = (gcnew System::Windows::Forms::RichTextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->patronymic = (gcnew System::Windows::Forms::TextBox());
			this->name = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->surname = (gcnew System::Windows::Forms::TextBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(12, 12);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(174, 17);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->Text = L"Добавть файл в базу данных";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &SaveDialog::checkBox1_CheckedChanged);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(218, 292);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SaveDialog::button1_Click);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button2->Location = System::Drawing::Point(299, 292);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Отмена";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &SaveDialog::button2_Click);
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->description);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->patronymic);
			this->panel1->Controls->Add(this->name);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->surname);
			this->panel1->Controls->Add(this->checkBox2);
			this->panel1->Location = System::Drawing::Point(12, 35);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(362, 251);
			this->panel1->TabIndex = 3;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(3, 108);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(57, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Описание";
			// 
			// description
			// 
			this->description->Location = System::Drawing::Point(65, 105);
			this->description->Name = L"description";
			this->description->Size = System::Drawing::Size(294, 130);
			this->description->TabIndex = 7;
			this->description->Text = L"";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 81);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(54, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Отчество";
			// 
			// patronymic
			// 
			this->patronymic->Location = System::Drawing::Point(65, 78);
			this->patronymic->Name = L"patronymic";
			this->patronymic->Size = System::Drawing::Size(142, 20);
			this->patronymic->TabIndex = 5;
			// 
			// name
			// 
			this->name->Location = System::Drawing::Point(65, 52);
			this->name->Name = L"name";
			this->name->Size = System::Drawing::Size(142, 20);
			this->name->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Имя";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Фамилия";
			// 
			// surname
			// 
			this->surname->Location = System::Drawing::Point(65, 26);
			this->surname->Name = L"surname";
			this->surname->Size = System::Drawing::Size(142, 20);
			this->surname->TabIndex = 1;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Checked = true;
			this->checkBox2->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox2->Location = System::Drawing::Point(3, 3);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(135, 17);
			this->checkBox2->TabIndex = 0;
			this->checkBox2->Text = L"Добавить миниатюру";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// SaveDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(386, 327);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->checkBox1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(402, 365);
			this->Name = L"SaveDialog";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->Text = L"Сохранить файл";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &SaveDialog::SaveDialog_FormClosed);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(checkBox1->Checked) {
					 if(surname->Text == "" || name->Text == "" || description->Text == "") {
						 MessageBox::Show("Не все поля заполнены", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						 return;
					 }
					 MySQL_SPACE::MySQL sql;
					 if(!sql.Connect("localhost", "root", "root", "mydb", "3306")) {
						MessageBox::Show("Ошибка соединения с базой данных", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						return;
					 }
					 sql.dbName = "dxf_table";
					 tm *tim;
					 time_t tt = time(NULL);
					 tim = localtime(&tt);
					 String ^ date = "" + tim->tm_mday + "." + (tim->tm_mon+1) + "." + (tim->tm_year+1900);
					 String ^time = "" + tim->tm_hour + ":" + tim->tm_min + ":" + tim->tm_sec;
					 String ^mini = "";
					 if(checkBox2->Checked) {/*добавление картинки*/}
					 sql.Insert(surname->Text, name->Text, patronymic->Text, description->Text, date, time, mini);
					 sql.Close();
				 }

				 this->Close();
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
			 }
	private: System::Void SaveDialog_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
				 saveDialogIsOpen = false;
			 }
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 if(checkBox1->Checked) panel1->Enabled = true;
				 else panel1->Enabled = false;
			 }
};
}
