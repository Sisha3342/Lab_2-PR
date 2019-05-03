#pragma once
#include "rail_list.h"
#include "add_frame.h"

namespace formsforkr {
	railways_list main_list;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ main_frame
	/// </summary>
	public ref class main_frame : public System::Windows::Forms::Form
	{
	public:
		main_frame(void)
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
		~main_frame()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  from_file_button;
	protected:

	protected:
	private: System::Windows::Forms::OpenFileDialog^  list_upload_dialog;
	private: System::Windows::Forms::DataGridView^  main_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  start_city_col;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  start_date_col;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  start_time_col;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  end_city_col;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  end_date_col;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  end_time_col;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  capacity_col;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  tick_left_col;
	private: System::Windows::Forms::Button^  add_button;
	private: System::Windows::Forms::SaveFileDialog^  list_save_dialog;
	private: System::Windows::Forms::Button^  list_save_button;








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
			this->from_file_button = (gcnew System::Windows::Forms::Button());
			this->list_upload_dialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->main_table = (gcnew System::Windows::Forms::DataGridView());
			this->start_city_col = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->start_date_col = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->start_time_col = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->end_city_col = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->end_date_col = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->end_time_col = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->capacity_col = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tick_left_col = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->add_button = (gcnew System::Windows::Forms::Button());
			this->list_save_dialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->list_save_button = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_table))->BeginInit();
			this->SuspendLayout();
			// 
			// from_file_button
			// 
			this->from_file_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->from_file_button->Location = System::Drawing::Point(12, 76);
			this->from_file_button->Name = L"from_file_button";
			this->from_file_button->Size = System::Drawing::Size(124, 42);
			this->from_file_button->TabIndex = 0;
			this->from_file_button->Text = L"Upload list from file";
			this->from_file_button->UseVisualStyleBackColor = true;
			this->from_file_button->Click += gcnew System::EventHandler(this, &main_frame::button1_Click);
			// 
			// main_table
			// 
			this->main_table->AllowUserToAddRows = false;
			this->main_table->AllowUserToDeleteRows = false;
			this->main_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->main_table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->start_city_col,
					this->start_date_col, this->start_time_col, this->end_city_col, this->end_date_col, this->end_time_col, this->capacity_col, this->tick_left_col
			});
			this->main_table->Location = System::Drawing::Point(12, 209);
			this->main_table->Name = L"main_table";
			this->main_table->Size = System::Drawing::Size(843, 172);
			this->main_table->TabIndex = 1;
			// 
			// start_city_col
			// 
			this->start_city_col->HeaderText = L"Start city";
			this->start_city_col->Name = L"start_city_col";
			// 
			// start_date_col
			// 
			this->start_date_col->HeaderText = L"Start date";
			this->start_date_col->Name = L"start_date_col";
			// 
			// start_time_col
			// 
			this->start_time_col->HeaderText = L"Start time";
			this->start_time_col->Name = L"start_time_col";
			// 
			// end_city_col
			// 
			this->end_city_col->HeaderText = L"End city";
			this->end_city_col->Name = L"end_city_col";
			// 
			// end_date_col
			// 
			this->end_date_col->HeaderText = L"End date";
			this->end_date_col->Name = L"end_date_col";
			// 
			// end_time_col
			// 
			this->end_time_col->HeaderText = L"End time";
			this->end_time_col->Name = L"end_time_col";
			// 
			// capacity_col
			// 
			this->capacity_col->HeaderText = L"Capacity";
			this->capacity_col->Name = L"capacity_col";
			// 
			// tick_left_col
			// 
			this->tick_left_col->HeaderText = L"Tickets left";
			this->tick_left_col->Name = L"tick_left_col";
			// 
			// add_button
			// 
			this->add_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->add_button->Location = System::Drawing::Point(12, 28);
			this->add_button->Name = L"add_button";
			this->add_button->Size = System::Drawing::Size(124, 42);
			this->add_button->TabIndex = 2;
			this->add_button->Text = L"Add railway";
			this->add_button->UseVisualStyleBackColor = true;
			this->add_button->Click += gcnew System::EventHandler(this, &main_frame::add_button_Click);
			// 
			// list_save_button
			// 
			this->list_save_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->list_save_button->Location = System::Drawing::Point(12, 124);
			this->list_save_button->Name = L"list_save_button";
			this->list_save_button->Size = System::Drawing::Size(124, 42);
			this->list_save_button->TabIndex = 3;
			this->list_save_button->Text = L"Save to the file";
			this->list_save_button->UseVisualStyleBackColor = true;
			this->list_save_button->Click += gcnew System::EventHandler(this, &main_frame::list_save_button_Click);
			// 
			// main_frame
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(891, 467);
			this->Controls->Add(this->list_save_button);
			this->Controls->Add(this->add_button);
			this->Controls->Add(this->main_table);
			this->Controls->Add(this->from_file_button);
			this->Name = L"main_frame";
			this->Text = L"main_frame";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_table))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void redraw_main_table()
	{
		main_table->Rows->Clear();

		String^ start_c; 
		String^ end_c; 
		String^ start_d;
		String^ start_t;
		String^ end_d;
		String^ end_t;
		String^ capacity;
		String^ tick_left;

		for(int i = 0; i < main_list.get_railways_count(); i++)
		{
			railway temp = main_list[i];

			start_c = msclr::interop::marshal_as<String^>(temp.start_city);
			end_c = msclr::interop::marshal_as<String^>(temp.end_city);
			capacity = msclr::interop::marshal_as<String^>(std::to_string(temp.capacity));
			tick_left = msclr::interop::marshal_as<String^>(std::to_string(temp.tickets_left));
			start_d = msclr::interop::marshal_as<String^>(correct_date(temp.start_date));
			start_t = msclr::interop::marshal_as<String^>(correct_time(temp.start_date));
			end_d = msclr::interop::marshal_as<String^>(correct_date(temp.start_date));
			end_t = msclr::interop::marshal_as<String^>(correct_time(temp.start_date));

			main_table->Rows->Add(start_c, start_d, start_t, end_c, end_d, end_t, capacity, tick_left);
		}
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		list_upload_dialog->ShowDialog();
		std::string filename = msclr::interop::marshal_as<std::string>(list_upload_dialog->FileName);

		std::ifstream fin(filename);

		while (!fin.eof())
			fin >> main_list;

		fin.close();

		redraw_main_table();
	}

	private: System::Void add_button_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		add_frame^ addForm = gcnew add_frame(main_list);
		addForm->ShowDialog();
		redraw_main_table();
	}

	private: System::Void list_save_button_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		list_save_dialog->ShowDialog();

		std::string filename = msclr::interop::marshal_as<std::string>(list_save_dialog->FileName);

		std::ofstream fout(filename);

		fout << main_list;

		fout.close();
	}
};
}
