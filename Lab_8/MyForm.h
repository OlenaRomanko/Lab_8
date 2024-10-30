#pragma once

#include <ctime>
#include <cstdlib>  // для rand і srand

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace Lab_8 {

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            srand(static_cast<unsigned int>(time(0))); // Ініціалізація генератора випадкових чисел
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
        int maxSize = 0;

        System::Windows::Forms::Button^ buttonAdd;
        System::Windows::Forms::Button^ buttonDelete;
        System::Windows::Forms::Button^ buttonCalculate;
        System::Windows::Forms::TextBox^ textBoxSize;
        System::Windows::Forms::ListBox^ listBoxStack;
        System::Windows::Forms::Label^ labelTitle;
        System::Windows::Forms::Label^ labelSize;

        System::ComponentModel::Container^ components; // Визначте components

        void InitializeComponent(void)
        {
            this->labelTitle = (gcnew System::Windows::Forms::Label());
            this->labelSize = (gcnew System::Windows::Forms::Label());
            this->textBoxSize = (gcnew System::Windows::Forms::TextBox());
            this->listBoxStack = (gcnew System::Windows::Forms::ListBox());
            this->buttonAdd = (gcnew System::Windows::Forms::Button());
            this->buttonDelete = (gcnew System::Windows::Forms::Button());
            this->buttonCalculate = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // labelTitle
            // 
            this->labelTitle->BackColor = System::Drawing::Color::Black;
            this->labelTitle->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Bold));
            this->labelTitle->ForeColor = System::Drawing::Color::White;
            this->labelTitle->Location = System::Drawing::Point(17, 23);
            this->labelTitle->Name = L"labelTitle";
            this->labelTitle->Size = System::Drawing::Size(480, 20);
            this->labelTitle->TabIndex = 0;
            this->labelTitle->Text = L"Заповнити стек числами. Знайти суму від’ємних елементів стеку.";
            // 
            // labelSize
            // 
            this->labelSize->Location = System::Drawing::Point(187, 57);
            this->labelSize->Name = L"labelSize";
            this->labelSize->Size = System::Drawing::Size(120, 20);
            this->labelSize->TabIndex = 1;
            this->labelSize->Text = L"Введіть розмір стека";
            // 
            // textBoxSize
            // 
            this->textBoxSize->Location = System::Drawing::Point(349, 57);
            this->textBoxSize->Name = L"textBoxSize";
            this->textBoxSize->Size = System::Drawing::Size(50, 20);
            this->textBoxSize->TabIndex = 2;
            // 
            // listBoxStack
            // 
            this->listBoxStack->Location = System::Drawing::Point(30, 75);
            this->listBoxStack->Name = L"listBoxStack";
            this->listBoxStack->Size = System::Drawing::Size(111, 108);
            this->listBoxStack->TabIndex = 3;
            // 
            // buttonAdd
            // 
            this->buttonAdd->Location = System::Drawing::Point(168, 95);
            this->buttonAdd->Name = L"buttonAdd";
            this->buttonAdd->Size = System::Drawing::Size(250, 30);
            this->buttonAdd->TabIndex = 4;
            this->buttonAdd->Text = L"Додати елементи до стека";
            this->buttonAdd->Click += gcnew System::EventHandler(this, &MyForm::buttonAdd_Click);
            // 
            // buttonDelete
            // 
            this->buttonDelete->Location = System::Drawing::Point(168, 137);
            this->buttonDelete->Name = L"buttonDelete";
            this->buttonDelete->Size = System::Drawing::Size(250, 30);
            this->buttonDelete->TabIndex = 5;
            this->buttonDelete->Text = L"Видалити елементи";
            this->buttonDelete->Click += gcnew System::EventHandler(this, &MyForm::buttonDelete_Click);
            // 
            // buttonCalculate
            // 
            this->buttonCalculate->Location = System::Drawing::Point(168, 173);
            this->buttonCalculate->Name = L"buttonCalculate";
            this->buttonCalculate->Size = System::Drawing::Size(250, 30);
            this->buttonCalculate->TabIndex = 6;
            this->buttonCalculate->Text = L"Обчислити";
            this->buttonCalculate->Click += gcnew System::EventHandler(this, &MyForm::buttonCalculate_Click);
            // 
            // MyForm
            // 
            this->ClientSize = System::Drawing::Size(574, 261);
            this->Controls->Add(this->labelTitle);
            this->Controls->Add(this->labelSize);
            this->Controls->Add(this->textBoxSize);
            this->Controls->Add(this->listBoxStack);
            this->Controls->Add(this->buttonAdd);
            this->Controls->Add(this->buttonDelete);
            this->Controls->Add(this->buttonCalculate);
            this->Name = L"MyForm";
            this->ResumeLayout(false);
            this->PerformLayout();

        }

    private:
        System::Void buttonAdd_Click(System::Object^ sender, System::EventArgs^ e) {
            int size = Convert::ToInt32(textBoxSize->Text); // Максимальна кількість елементів, яку можна додати
            int itemsToAdd = size - count; // Кількість елементів, які ще можна додати

            if (itemsToAdd > 0) {
                for (int i = 0; i < itemsToAdd && count < size; i++) {
                    int randomValue = rand() % 200 - 100; // Генерація випадкового числа від -100 до 99
                    myStack->Push(randomValue);
                    listBoxStack->Items->Insert(0, randomValue.ToString());
                    count++;
                }
            }
            else {
                MessageBox::Show("Досягнуто ліміт чисел");
            }
        }



        // Обробник події для кнопки видалення елементів
        System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e) {
            if (myStack->Count > 0) {
                myStack->Pop();
                listBoxStack->Items->Clear();
                for each (int value in myStack)
                {
                    listBoxStack->Items->Add(value.ToString());
                }
            }
            else {
                listBoxStack->Items->Add("Стек порожній");
            }
        }

        // Обробник події для кнопки обчислення суми від'ємних елементів
        System::Void buttonCalculate_Click(System::Object^ sender, System::EventArgs^ e) {
            int negativeSum = 0;
            for each (int value in myStack) {
                if (value < 0) { // Перевірка на від’ємність
                    negativeSum += value;
                }
            }
            MessageBox::Show("Сума від'ємних елементів: " + negativeSum.ToString());
        }
    };
}
