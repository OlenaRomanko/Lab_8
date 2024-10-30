#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Lab_8; 

[STAThread]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Створення і запуск форми
    Application::Run(gcnew Lab_8::MyForm()); 

    return 0;
}
