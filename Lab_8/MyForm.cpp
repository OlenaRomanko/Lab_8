#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Lab8;

[STAThread]
int main(array<String^>^ args) // �������� ��� ����� ��� Windows Forms
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // ��������� � ������ �����
    Application::Run(gcnew MyForm());

    return 0;
}

