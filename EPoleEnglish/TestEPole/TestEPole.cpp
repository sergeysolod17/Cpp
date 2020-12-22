// TestEPole.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"
#include "FormLoad.h"

using namespace TestEPole;
using namespace FormLoadText;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew FormLoadText::Form1());
	Application::Run(gcnew TestEPole::Form1());
	return 0;
}
