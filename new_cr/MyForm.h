#pragma once
#include "my_class.h"
#include "test_class.h"
#include <msclr/marshal_cppstd.h>
#include <fstream>
#include "cmp_frame.h"

namespace krproject {
	my_class<test_class> obj_list_;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^  open_file_dlg;
	protected:
	private: System::Windows::Forms::Button^  load_button;
	private: System::Windows::Forms::SaveFileDialog^  save_file_dlg;
	private: System::Windows::Forms::Button^  save_button;
	private: System::Windows::Forms::DataGridView^  show_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  seconde_name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  code;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  year;
	private: System::Windows::Forms::Button^  cmp_button;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->open_file_dlg = (gcnew System::Windows::Forms::OpenFileDialog());
			this->load_button = (gcnew System::Windows::Forms::Button());
			this->save_file_dlg = (gcnew System::Windows::Forms::SaveFileDialog());
			this->save_button = (gcnew System::Windows::Forms::Button());
			this->show_table = (gcnew System::Windows::Forms::DataGridView());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->seconde_name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->code = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->year = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cmp_button = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->show_table))->BeginInit();
			this->SuspendLayout();
			// 
			// load_button
			// 
			this->load_button->Location = System::Drawing::Point(26, 42);
			this->load_button->Name = L"load_button";
			this->load_button->Size = System::Drawing::Size(107, 40);
			this->load_button->TabIndex = 0;
			this->load_button->Text = L"Load list from file";
			this->load_button->UseVisualStyleBackColor = true;
			this->load_button->Click += gcnew System::EventHandler(this, &MyForm::load_button_Click);
			// 
			// save_button
			// 
			this->save_button->Location = System::Drawing::Point(26, 88);
			this->save_button->Name = L"save_button";
			this->save_button->Size = System::Drawing::Size(107, 40);
			this->save_button->TabIndex = 1;
			this->save_button->Text = L"Save list to file";
			this->save_button->UseVisualStyleBackColor = true;
			this->save_button->Click += gcnew System::EventHandler(this, &MyForm::save_button_Click);
			// 
			// show_table
			// 
			this->show_table->AllowUserToAddRows = false;
			this->show_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->show_table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->name, this->seconde_name,
					this->code, this->year
			});
			this->show_table->Location = System::Drawing::Point(26, 177);
			this->show_table->Name = L"show_table";
			this->show_table->Size = System::Drawing::Size(440, 192);
			this->show_table->TabIndex = 2;
			// 
			// name
			// 
			this->name->HeaderText = L"Name";
			this->name->Name = L"name";
			// 
			// seconde_name
			// 
			this->seconde_name->HeaderText = L"Second name";
			this->seconde_name->Name = L"seconde_name";
			// 
			// code
			// 
			this->code->HeaderText = L"Code";
			this->code->Name = L"code";
			// 
			// year
			// 
			this->year->HeaderText = L"Year";
			this->year->Name = L"year";
			// 
			// cmp_button
			// 
			this->cmp_button->Location = System::Drawing::Point(259, 63);
			this->cmp_button->Name = L"cmp_button";
			this->cmp_button->Size = System::Drawing::Size(119, 39);
			this->cmp_button->TabIndex = 3;
			this->cmp_button->Text = L"Compare name";
			this->cmp_button->UseVisualStyleBackColor = true;
			this->cmp_button->Click += gcnew System::EventHandler(this, &MyForm::cmp_button_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(598, 435);
			this->Controls->Add(this->cmp_button);
			this->Controls->Add(this->show_table);
			this->Controls->Add(this->save_button);
			this->Controls->Add(this->load_button);
			this->Name = L"MyForm";
			this->Text = L"Main menu";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->show_table))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void redraw_main_table()
	{
		show_table->Rows->Clear();

		String^ name;
		String^ second_name;
		String^ code;
		String^ year;
		
		for (size_t i = 0; i < obj_list_.get_count(); i++)
		{
			test_class temp = obj_list_[i];

			name = msclr::interop::marshal_as<String^>(temp.name);
			second_name = msclr::interop::marshal_as<String^>(temp.second_name);
			code = msclr::interop::marshal_as<String^>(std::to_string(temp.code));
			year = msclr::interop::marshal_as<String^>(std::to_string(temp.year));
			
			show_table->Rows->Add(name, second_name, code, year);
		}
	}

	private: System::Void load_button_Click(System::Object^  sender, System::EventArgs^  e) {
		open_file_dlg->ShowDialog();
		std::string filename = msclr::interop::marshal_as<std::string>(open_file_dlg->FileName);
		std::ifstream fin(filename);

		while (!fin.eof())
		{
			fin >> obj_list_;
		}

		fin.close();

		redraw_main_table();
	}
	private: System::Void save_button_Click(System::Object^  sender, System::EventArgs^  e) {
		
		save_file_dlg->ShowDialog();

		std::string filename = msclr::interop::marshal_as<std::string>(save_file_dlg->FileName);

		std::ofstream fout(filename);

		fout << obj_list_;

		fout.close();
	}
	private: System::Void cmp_button_Click(System::Object^  sender, System::EventArgs^  e) {
		cmp_frame^ cmp_form = gcnew cmp_frame(obj_list_);

		cmp_form->ShowDialog();

		redraw_main_table();
	}
};
}
