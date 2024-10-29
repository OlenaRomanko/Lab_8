#pragma once
#include <ctime>
#include <cstdlib>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace Lab8 {

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			srand(static_cast<unsigned int>(time(0))); // ����������� ���������� ���������� �����
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Collections::Generic::Stack<int>^ myStack = gcnew System::Collections::Generic::Stack<int>();
		int count = 0;
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::ListBox^ listBox1;
		System::Windows::Forms::Button^ button2;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());

			// ������������ ������ ��� ��������� �����
			this->button1->Location = System::Drawing::Point(20, 20);
			this->button1->Size = System::Drawing::Size(100, 30);
			this->button1->Text = "������ �����";
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);

			// ������������ ������ ��� ���������� ���� ��'����� �����
			this->button2->Location = System::Drawing::Point(20, 60);
			this->button2->Size = System::Drawing::Size(150, 30);
			this->button2->Text = "��������� ���� ��'�����";
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);

			// ������������ ���������� ���� ��� �������� ������ �����
			this->textBox1->Location = System::Drawing::Point(180, 20);
			this->textBox1->Size = System::Drawing::Size(80, 20);

			// ������������ ListBox ��� ����������� �������� �����
			this->listBox1->Location = System::Drawing::Point(20, 100);
			this->listBox1->Size = System::Drawing::Size(240, 150);

			// ��������� �������� �� �����
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->listBox1);

			// ������������ �����
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(300, 300);
			this->Name = L"MyForm";
			this->Text = L"Lab8";
		}
#pragma endregion

	private:
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			int size = Convert::ToInt32(textBox1->Text);
			if (count < size) {
				int randomValue = rand() % 200 - 100; // ��������� ����������� ����� �� -100 �� 99
				myStack->Push(randomValue);
				listBox1->Items->Insert(0, randomValue.ToString()); // ���� � listBox
				count++;
			}
			else {
				MessageBox::Show("��������� ��� �����");
			}
		}

		System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			int negativeSum = 0;
			for each (int value in myStack) {
				if (value < 0) {
					negativeSum += value;
				}
			}
			MessageBox::Show("���� ��'����� ��������: " + negativeSum.ToString());
		}
	};
}

