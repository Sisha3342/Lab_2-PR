#pragma once
#include "my_class.h"
#include "test_class.h"
#include <msclr/marshal_cppstd.h>

namespace krproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ cmp_frame
	/// </summary>
	public ref class cmp_frame : public System::Windows::Forms::Form
	{
		my_class<test_class>& list_;
	public:
		//cmp_frame(void)
		//{
		//	InitializeComponent();
		//	//
		//	//TODO: добавьте код конструктора
		//	//
		//}
		template<typename T>
		cmp_frame(my_class<T>& list_) : list_(list_)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~cmp_frame()
		{
			if (components)
			{
				search_table->Rows->Clear();
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  search_button;
	private: System::Windows::Forms::TextBox^  name_box;
	private: System::Windows::Forms::DataGridView^  search_table;


	private: System::Windows::Forms::DataGridViewTextBoxColumn^  name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  second_name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  code;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  year;
	protected:

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
			this->search_button = (gcnew System::Windows::Forms::Button());
			this->name_box = (gcnew System::Windows::Forms::TextBox());
			this->search_table = (gcnew System::Windows::Forms::DataGridView());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->second_name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->code = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->year = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->search_table))->BeginInit();
			this->SuspendLayout();
			// 
			// search_button
			// 
			this->search_button->Location = System::Drawing::Point(182, 99);
			this->search_button->Name = L"search_button";
			this->search_button->Size = System::Drawing::Size(87, 34);
			this->search_button->TabIndex = 0;
			this->search_button->Text = L"Search";
			this->search_button->UseVisualStyleBackColor = true;
			this->search_button->Click += gcnew System::EventHandler(this, &cmp_frame::search_button_Click);
			// 
			// name_box
			// 
			this->name_box->Location = System::Drawing::Point(169, 73);
			this->name_box->Name = L"name_box";
			this->name_box->Size = System::Drawing::Size(119, 20);
			this->name_box->TabIndex = 1;
			// 
			// search_table
			// 
			this->search_table->AllowUserToAddRows = false;
			this->search_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->search_table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->name, this->second_name,
					this->code, this->year
			});
			this->search_table->Location = System::Drawing::Point(30, 143);
			this->search_table->Name = L"search_table";
			this->search_table->Size = System::Drawing::Size(439, 150);
			this->search_table->TabIndex = 2;
			// 
			// name
			// 
			this->name->HeaderText = L"Name";
			this->name->Name = L"name";
			// 
			// second_name
			// 
			this->second_name->HeaderText = L"Second name";
			this->second_name->Name = L"second_name";
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
			// cmp_frame
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(481, 362);
			this->Controls->Add(this->search_table);
			this->Controls->Add(this->name_box);
			this->Controls->Add(this->search_button);
			this->Name = L"cmp_frame";
			this->Text = L"cmp_frame";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->search_table))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void search_button_Click(System::Object^  sender, System::EventArgs^  e) {

		search_table->Rows->Clear();

		std::string name = msclr::interop::marshal_as<std::string>(name_box->Text);

		std::vector<test_class> found_names = list_.compare_name(name);

		for (size_t i = 0; i < found_names.size(); i++)
		{
			test_class t = found_names[i];
			String^ name_1 = msclr::interop::marshal_as<String^>(t.name);
			String^ second_name_1 = msclr::interop::marshal_as<String^>(t.second_name);
			String^ code_1 = msclr::interop::marshal_as<String^>(std::to_string(t.code));
			String^ year_1 = msclr::interop::marshal_as<String^>(std::to_string(t.year));

			search_table->Rows->Add(name_1, second_name_1, code_1, year_1);
		}
	}
};
}
