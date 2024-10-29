#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Lab8;

[STAThread]
int main(array<String^>^ args) // Залишаємо цей підпис для Windows Forms
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Створення і запуск форми
    Application::Run(gcnew MyForm());

    return 0;
}

