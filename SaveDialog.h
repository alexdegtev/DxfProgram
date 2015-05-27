#pragma once

#include <time.h>
#include "Cl_DxfLib.h"
#include "Cl_ObjectsLib.h"
#include "Cl_MySQLLib.h"

namespace DxfProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	extern bool saveDialogIsOpen;
	extern DXF_SPACE::DXF dxf;
	extern OBJECTS_SPACE::WORK *work;


	/// <summary>
	/// Сводка для SaveDialog
	/// </summary>
	public ref class SaveDialog : public System::Windows::Forms::Form
	{
	public:
		SaveDialog(string _filePath)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			string tmp = "";
			for(unsigned int i=0; i<_filePath.length(); i++) {
				tmp += _filePath[i];
				if(_filePath[i] == '\\') tmp += '\\';
			}
			filePath = gcnew System::String(tmp.c_str());
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
	private: System::String ^filePath;
	private: MySQL_SPACE::MySQL sql;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::TextBox^  textBox13;
	private: System::Windows::Forms::TextBox^  textBox14;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker2;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::TextBox^  textBox16;
	private: System::Windows::Forms::TextBox^  textBox15;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker4;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker3;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker5;
	private: System::Windows::Forms::TextBox^  textBox17;
	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Panel^  panel3;
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
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->dateTimePicker4 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker3 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker5 = (gcnew System::Windows::Forms::DateTimePicker());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(12, 12);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(180, 17);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->Text = L"Добавить файл в базу данных";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &SaveDialog::checkBox1_CheckedChanged);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(337, 522);
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
			this->button2->Location = System::Drawing::Point(418, 522);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Отмена";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &SaveDialog::button2_Click);
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(3, 148);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(143, 13);
			this->label22->TabIndex = 4;
			this->label22->Text = L"Дата внесения изменений";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(3, 120);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(192, 13);
			this->label21->TabIndex = 3;
			this->label21->Text = L"Подпись лица, внёсшего изменения";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(3, 86);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(222, 26);
			this->label20->TabIndex = 2;
			this->label20->Text = L"Номер документа, на основании которого\r\nпроизводится изменение";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(3, 60);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(163, 13);
			this->label19->TabIndex = 1;
			this->label19->Text = L"Указания об изменении листа";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(3, 34);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(151, 13);
			this->label18->TabIndex = 0;
			this->label18->Text = L"Порядковый номер изделия";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(128, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Наименование изделия";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 33);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(140, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Наименование документа";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(237, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(232, 20);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(237, 30);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(232, 20);
			this->textBox2->TabIndex = 3;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(237, 56);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(232, 20);
			this->textBox3->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 59);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(131, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Обозначение документа";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(237, 82);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(232, 20);
			this->textBox4->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(3, 85);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(83, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Код документа";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(237, 108);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(232, 20);
			this->textBox5->TabIndex = 8;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(3, 111);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(209, 26);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Характер работы, выполняемой лицом,\r\nподписывающим документ";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(237, 141);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(232, 20);
			this->textBox6->TabIndex = 10;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(3, 144);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(230, 13);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Фамилия лица, подписывающего документ";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(3, 170);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(225, 13);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Подпись лица, подписывающего документ";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(3, 196);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(153, 13);
			this->label8->TabIndex = 13;
			this->label8->Text = L"Дата подписания документа";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(3, 222);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(202, 13);
			this->label9->TabIndex = 14;
			this->label9->Text = L"Подпись лица, принявшего подлинник";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(3, 248);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(80, 13);
			this->label10->TabIndex = 15;
			this->label10->Text = L"Дата приёмки";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(3, 274);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(194, 13);
			this->label11->TabIndex = 16;
			this->label11->Text = L"Подпись лица, принявшего дубликат";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(3, 300);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(135, 13);
			this->label12->TabIndex = 17;
			this->label12->Text = L"Дата приёмки дубликата";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(3, 326);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(229, 13);
			this->label13->TabIndex = 18;
			this->label13->Text = L"Номер решения об утверждении документа";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(3, 352);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(169, 13);
			this->label14->TabIndex = 19;
			this->label14->Text = L"Год утверждения документации";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(3, 378);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(153, 13);
			this->label15->TabIndex = 20;
			this->label15->Text = L"Подпись должностного лица";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(3, 404);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(123, 13);
			this->label16->TabIndex = 21;
			this->label16->Text = L"Расшифровка подписи";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(3, 430);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(102, 13);
			this->label17->TabIndex = 22;
			this->label17->Text = L"Дата визирования";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(237, 167);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(232, 20);
			this->textBox7->TabIndex = 23;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(237, 219);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(232, 20);
			this->textBox9->TabIndex = 25;
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(237, 271);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(232, 20);
			this->textBox11->TabIndex = 27;
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(237, 323);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(232, 20);
			this->textBox13->TabIndex = 29;
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(237, 349);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(232, 20);
			this->textBox14->TabIndex = 30;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(3, 3);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(161, 17);
			this->radioButton1->TabIndex = 5;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Добавить новый документ";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &SaveDialog::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(182, 3);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(274, 17);
			this->radioButton2->TabIndex = 6;
			this->radioButton2->Text = L"Добавить изменения в существующий документ";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &SaveDialog::radioButton2_CheckedChanged);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->dateTimePicker4);
			this->panel1->Controls->Add(this->dateTimePicker3);
			this->panel1->Controls->Add(this->dateTimePicker2);
			this->panel1->Controls->Add(this->dateTimePicker1);
			this->panel1->Controls->Add(this->textBox16);
			this->panel1->Controls->Add(this->textBox15);
			this->panel1->Controls->Add(this->textBox14);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->textBox13);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->textBox11);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->textBox3);
			this->panel1->Controls->Add(this->textBox9);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->textBox4);
			this->panel1->Controls->Add(this->textBox7);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label17);
			this->panel1->Controls->Add(this->textBox5);
			this->panel1->Controls->Add(this->label16);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label15);
			this->panel1->Controls->Add(this->textBox6);
			this->panel1->Controls->Add(this->label14);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label13);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->label12);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->label11);
			this->panel1->Controls->Add(this->label9);
			this->panel1->Controls->Add(this->label10);
			this->panel1->Location = System::Drawing::Point(3, 26);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(485, 456);
			this->panel1->TabIndex = 7;
			// 
			// dateTimePicker4
			// 
			this->dateTimePicker4->CustomFormat = L"yyyy.MM.dd";
			this->dateTimePicker4->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker4->Location = System::Drawing::Point(237, 427);
			this->dateTimePicker4->Name = L"dateTimePicker4";
			this->dateTimePicker4->Size = System::Drawing::Size(232, 20);
			this->dateTimePicker4->TabIndex = 33;
			// 
			// dateTimePicker3
			// 
			this->dateTimePicker3->CustomFormat = L"yyyy.MM.dd";
			this->dateTimePicker3->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker3->Location = System::Drawing::Point(237, 297);
			this->dateTimePicker3->Name = L"dateTimePicker3";
			this->dateTimePicker3->Size = System::Drawing::Size(232, 20);
			this->dateTimePicker3->TabIndex = 28;
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->CustomFormat = L"yyyy.MM.dd";
			this->dateTimePicker2->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker2->Location = System::Drawing::Point(237, 245);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(232, 20);
			this->dateTimePicker2->TabIndex = 26;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->CustomFormat = L"yyyy.MM.dd";
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker1->Location = System::Drawing::Point(237, 193);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(232, 20);
			this->dateTimePicker1->TabIndex = 24;
			// 
			// textBox16
			// 
			this->textBox16->Location = System::Drawing::Point(237, 401);
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(232, 20);
			this->textBox16->TabIndex = 32;
			// 
			// textBox15
			// 
			this->textBox15->Location = System::Drawing::Point(237, 375);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(232, 20);
			this->textBox15->TabIndex = 31;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->comboBox1);
			this->panel2->Controls->Add(this->label23);
			this->panel2->Controls->Add(this->dateTimePicker5);
			this->panel2->Controls->Add(this->textBox17);
			this->panel2->Controls->Add(this->textBox12);
			this->panel2->Controls->Add(this->textBox10);
			this->panel2->Controls->Add(this->textBox8);
			this->panel2->Controls->Add(this->label22);
			this->panel2->Controls->Add(this->label21);
			this->panel2->Controls->Add(this->label18);
			this->panel2->Controls->Add(this->label20);
			this->panel2->Controls->Add(this->label19);
			this->panel2->Location = System::Drawing::Point(494, 26);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(467, 187);
			this->panel2->TabIndex = 8;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(229, 4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(232, 21);
			this->comboBox1->TabIndex = 4;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(3, 7);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(114, 13);
			this->label23->TabIndex = 10;
			this->label23->Text = L"Название документа";
			// 
			// dateTimePicker5
			// 
			this->dateTimePicker5->CustomFormat = L"yyyy.MM.dd";
			this->dateTimePicker5->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker5->Location = System::Drawing::Point(229, 144);
			this->dateTimePicker5->Name = L"dateTimePicker5";
			this->dateTimePicker5->Size = System::Drawing::Size(232, 20);
			this->dateTimePicker5->TabIndex = 9;
			// 
			// textBox17
			// 
			this->textBox17->Location = System::Drawing::Point(229, 117);
			this->textBox17->Name = L"textBox17";
			this->textBox17->Size = System::Drawing::Size(232, 20);
			this->textBox17->TabIndex = 8;
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(229, 83);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(232, 20);
			this->textBox12->TabIndex = 7;
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(229, 57);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(232, 20);
			this->textBox10->TabIndex = 6;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(229, 31);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(232, 20);
			this->textBox8->TabIndex = 5;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->radioButton1);
			this->panel3->Controls->Add(this->panel2);
			this->panel3->Controls->Add(this->radioButton2);
			this->panel3->Controls->Add(this->panel1);
			this->panel3->Location = System::Drawing::Point(12, 35);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(970, 485);
			this->panel3->TabIndex = 9;
			// 
			// SaveDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(505, 557);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->checkBox1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(521, 595);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(521, 595);
			this->Name = L"SaveDialog";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->Text = L"Сохранить файл";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &SaveDialog::SaveDialog_FormClosed);
			this->Load += gcnew System::EventHandler(this, &SaveDialog::SaveDialog_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 //Запись в БД
				 if(checkBox1->Checked) {
					 /*if(radioButton1->Checked && (textBox1->Text == "" || textBox2->Text == "" || textBox3->Text == "" || textBox4->Text == "" || textBox5->Text == "" || 
						textBox6->Text == "" || textBox7->Text == "" || textBox9->Text == "" || textBox11->Text == "" || textBox13->Text == "" || 
						textBox14->Text == "" || textBox15->Text == "" || textBox16->Text == "") ||
						radioButton2->Checked && (comboBox1->Text == "" || textBox8->Text == "" || textBox10->Text == "" || textBox12->Text == "" ||
						textBox17->Text == "" || dateTimePicker5->Text == "")) {
						 MessageBox::Show("Не все поля заполнены", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						 return;
					 }*/
					 
					 if(radioButton1->Checked) sql.Insert(textBox1->Text, textBox2->Text, textBox3->Text, textBox4->Text, textBox5->Text, textBox6->Text, textBox7->Text,
						 dateTimePicker1->Text, textBox9->Text, dateTimePicker2->Text, textBox11->Text, dateTimePicker3->Text, textBox13->Text,
						 textBox14->Text, textBox15->Text, textBox16->Text, dateTimePicker4->Text, filePath);
					 if(radioButton2->Checked) sql.Insert(comboBox1->Text, textBox8->Text, textBox10->Text, textBox12->Text, textBox17->Text, dateTimePicker5->Text, filePath);
					 sql.Close();
				 }

				 //Запись файла на диск
				 if(!dxf.SaveErrorPoints(work->ErrPoints)) MessageBox::Show("Ошибка записи", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				 
				 this->Close();
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
			 }
	private: System::Void SaveDialog_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
				 saveDialogIsOpen = false;
			 }
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 if(checkBox1->Checked) panel3->Enabled = true;
				 else panel3->Enabled = false;
			 }

private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(radioButton1->Checked) {
				 panel2->Visible = false;
				 panel1->Visible = true;
			 }
		 }
private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(radioButton2->Checked) {
				 panel1->Visible = false;
				 panel2->Visible = true;
			 }
		 }
private: System::Void SaveDialog_Load(System::Object^  sender, System::EventArgs^  e) {
			 panel2->Location = System::Drawing::Point(3, 26);
			 panel2->Visible = false;
			 panel1->Visible = true;

			 if(!sql.Connect("localhost", "root", "root", "dxf_schema", "3306")) {
				 MessageBox::Show("Ошибка соединения с базой данных", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				 return;
			 }
			 sql.dbName1 = "основные сведения";
			 sql.dbName2 = "изменения";
			 
			 int numRows = sql.GetNumRows();
			 string *result = new string [numRows];
			 sql.Select("наименование изделия", result);
			 for(int i=0; i<numRows; i++) {
				 String ^tmp = gcnew System::String(result[i].c_str());
				 comboBox1->Items->Add(tmp);
			 }
		 }
};
}
