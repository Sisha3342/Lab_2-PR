#pragma once
#include "rail_list.h"

namespace formsforkr {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ add_frame
	/// </summary>
	public ref class add_frame : public System::Windows::Forms::Form
	{
		railways_list& rlist;

	public:

		/*add_frame(void)
		{
			InitializeComponent();
		}*/

		add_frame(railways_list& rlist) : rlist(rlist)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~add_frame()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  start_c_label;
	protected:
	private: System::Windows::Forms::TextBox^  start_c_box;
	private: System::Windows::Forms::DateTimePicker^  start_d_pick;
	private: System::Windows::Forms::Label^  start_d_label;
	private: System::Windows::Forms::Label^  end_c_label;
	private: System::Windows::Forms::TextBox^  end_c_box;
	private: System::Windows::Forms::Label^  end_d_label;
	private: System::Windows::Forms::DateTimePicker^  end_d_pick;
	private: System::Windows::Forms::Label^  capacity_label;
	private: System::Windows::Forms::TextBox^  capacity_box;
	private: System::Windows::Forms::Label^  tick_left_label;
	private: System::Windows::Forms::TextBox^  tick_left_box;
	private: System::Windows::Forms::Button^  add_rail_button;
	private: System::Windows::Forms::ErrorProvider^  start_c_error;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->start_c_label = (gcnew System::Windows::Forms::Label());
			this->start_c_box = (gcnew System::Windows::Forms::TextBox());
			this->start_d_pick = (gcnew System::Windows::Forms::DateTimePicker());
			this->start_d_label = (gcnew System::Windows::Forms::Label());
			this->end_c_label = (gcnew System::Windows::Forms::Label());
			this->end_c_box = (gcnew System::Windows::Forms::TextBox());
			this->end_d_label = (gcnew System::Windows::Forms::Label());
			this->end_d_pick = (gcnew System::Windows::Forms::DateTimePicker());
			this->capacity_label = (gcnew System::Windows::Forms::Label());
			this->capacity_box = (gcnew System::Windows::Forms::TextBox());
			this->tick_left_label = (gcnew System::Windows::Forms::Label());
			this->tick_left_box = (gcnew System::Windows::Forms::TextBox());
			this->add_rail_button = (gcnew System::Windows::Forms::Button());
			this->start_c_error = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->start_c_error))->BeginInit();
			this->SuspendLayout();
			// 
			// start_c_label
			// 
			this->start_c_label->AutoSize = true;
			this->start_c_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->start_c_label->Location = System::Drawing::Point(80, 23);
			this->start_c_label->Name = L"start_c_label";
			this->start_c_label->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->start_c_label->Size = System::Drawing::Size(72, 16);
			this->start_c_label->TabIndex = 0;
			this->start_c_label->Text = L"Start city:";
			// 
			// start_c_box
			// 
			this->start_c_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->start_c_box->Location = System::Drawing::Point(159, 20);
			this->start_c_box->Name = L"start_c_box";
			this->start_c_box->Size = System::Drawing::Size(173, 22);
			this->start_c_box->TabIndex = 1;
			// 
			// start_d_pick
			// 
			this->start_d_pick->CustomFormat = L"yyyy-MM-dd HH:mm";
			this->start_d_pick->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->start_d_pick->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->start_d_pick->Location = System::Drawing::Point(159, 48);
			this->start_d_pick->Name = L"start_d_pick";
			this->start_d_pick->Size = System::Drawing::Size(173, 22);
			this->start_d_pick->TabIndex = 2;
			// 
			// start_d_label
			// 
			this->start_d_label->AutoSize = true;
			this->start_d_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->start_d_label->Location = System::Drawing::Point(74, 53);
			this->start_d_label->Name = L"start_d_label";
			this->start_d_label->Size = System::Drawing::Size(79, 16);
			this->start_d_label->TabIndex = 3;
			this->start_d_label->Text = L"Start date:";
			// 
			// end_c_label
			// 
			this->end_c_label->AutoSize = true;
			this->end_c_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->end_c_label->Location = System::Drawing::Point(80, 79);
			this->end_c_label->Name = L"end_c_label";
			this->end_c_label->Size = System::Drawing::Size(67, 16);
			this->end_c_label->TabIndex = 4;
			this->end_c_label->Text = L"End city:";
			// 
			// end_c_box
			// 
			this->end_c_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->end_c_box->Location = System::Drawing::Point(159, 76);
			this->end_c_box->Name = L"end_c_box";
			this->end_c_box->Size = System::Drawing::Size(173, 22);
			this->end_c_box->TabIndex = 5;
			// 
			// end_d_label
			// 
			this->end_d_label->AutoSize = true;
			this->end_d_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->end_d_label->Location = System::Drawing::Point(78, 109);
			this->end_d_label->Name = L"end_d_label";
			this->end_d_label->Size = System::Drawing::Size(74, 16);
			this->end_d_label->TabIndex = 6;
			this->end_d_label->Text = L"End date:";
			// 
			// end_d_pick
			// 
			this->end_d_pick->CustomFormat = L"yyyy-MM-dd HH:mm";
			this->end_d_pick->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->end_d_pick->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->end_d_pick->Location = System::Drawing::Point(159, 104);
			this->end_d_pick->Name = L"end_d_pick";
			this->end_d_pick->Size = System::Drawing::Size(173, 22);
			this->end_d_pick->TabIndex = 7;
			// 
			// capacity_label
			// 
			this->capacity_label->AutoSize = true;
			this->capacity_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->capacity_label->Location = System::Drawing::Point(80, 135);
			this->capacity_label->Name = L"capacity_label";
			this->capacity_label->Size = System::Drawing::Size(73, 16);
			this->capacity_label->TabIndex = 8;
			this->capacity_label->Text = L"Capacity:";
			// 
			// capacity_box
			// 
			this->capacity_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->capacity_box->Location = System::Drawing::Point(159, 132);
			this->capacity_box->Name = L"capacity_box";
			this->capacity_box->Size = System::Drawing::Size(173, 22);
			this->capacity_box->TabIndex = 9;
			// 
			// tick_left_label
			// 
			this->tick_left_label->AutoSize = true;
			this->tick_left_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tick_left_label->Location = System::Drawing::Point(65, 163);
			this->tick_left_label->Name = L"tick_left_label";
			this->tick_left_label->Size = System::Drawing::Size(88, 16);
			this->tick_left_label->TabIndex = 10;
			this->tick_left_label->Text = L"Tickets left:";
			// 
			// tick_left_box
			// 
			this->tick_left_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tick_left_box->Location = System::Drawing::Point(159, 160);
			this->tick_left_box->Name = L"tick_left_box";
			this->tick_left_box->Size = System::Drawing::Size(173, 22);
			this->tick_left_box->TabIndex = 11;
			// 
			// add_rail_button
			// 
			this->add_rail_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->add_rail_button->Location = System::Drawing::Point(198, 204);
			this->add_rail_button->Name = L"add_rail_button";
			this->add_rail_button->Size = System::Drawing::Size(90, 30);
			this->add_rail_button->TabIndex = 12;
			this->add_rail_button->Text = L"ADD";
			this->add_rail_button->UseVisualStyleBackColor = true;
			this->add_rail_button->Click += gcnew System::EventHandler(this, &add_frame::add_rail_button_Click);
			// 
			// start_c_error
			// 
			this->start_c_error->ContainerControl = this;
			// 
			// add_frame
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(465, 288);
			this->Controls->Add(this->add_rail_button);
			this->Controls->Add(this->tick_left_box);
			this->Controls->Add(this->tick_left_label);
			this->Controls->Add(this->capacity_box);
			this->Controls->Add(this->capacity_label);
			this->Controls->Add(this->end_d_pick);
			this->Controls->Add(this->end_d_label);
			this->Controls->Add(this->end_c_box);
			this->Controls->Add(this->end_c_label);
			this->Controls->Add(this->start_d_label);
			this->Controls->Add(this->start_d_pick);
			this->Controls->Add(this->start_c_box);
			this->Controls->Add(this->start_c_label);
			this->Name = L"add_frame";
			this->Text = L"add_frame";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->start_c_error))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void add_rail_button_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (System::String::IsNullOrEmpty(start_c_box->Text) || System::String::IsNullOrEmpty(end_c_box->Text) || 
			System::String::IsNullOrEmpty(capacity_box->Text) || System::String::IsNullOrEmpty(tick_left_box->Text))
		{
			MessageBox::Show("Fill all the fields before adding a railway", "invalid input");
		}
		else
		{
			std::string start_c = msclr::interop::marshal_as<std::string>(start_c_box->Text);
			std::string end_c = msclr::interop::marshal_as<std::string>(end_c_box->Text);
			std::string capacity = msclr::interop::marshal_as<std::string>(capacity_box->Text);
			std::string tick_left = msclr::interop::marshal_as<std::string>(tick_left_box->Text);
			std::string start_d = msclr::interop::marshal_as<std::string>(start_d_pick->Text);
			std::string end_d = msclr::interop::marshal_as<std::string>(end_d_pick->Text);

			std::string full_info = start_c + ";" + start_d + ";" + end_c + ";" + end_d + ";" +
				capacity + ";" + tick_left;

			rlist.add_railway(railway(full_info));

			this->Close();
		}
	}
};
}
