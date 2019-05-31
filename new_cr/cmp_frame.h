#pragma once
#include "my_class.h"
#include "test_class.h"

namespace krproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� cmp_frame
	/// </summary>
	public ref class cmp_frame : public System::Windows::Forms::Form
	{
		my_class<test_class>& list_;
	public:
		//cmp_frame(void)
		//{
		//	InitializeComponent();
		//	//
		//	//TODO: �������� ��� ������������
		//	//
		//}
		template<typename T>
		cmp_frame(my_class<T>& list_) : list_(list_)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~cmp_frame()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->Size = System::Drawing::Size(300,300);
			this->Text = L"cmp_frame";
			this->Padding = System::Windows::Forms::Padding(0);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		}
#pragma endregion
	};
}
