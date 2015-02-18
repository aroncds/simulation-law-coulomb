#include "Input.h"

Input * Input::Instance;
HWND Input::window;
HINSTANCE Input::Hinst;

Input::Input()
{

}

void Input::createWindow(){
	WNDCLASSEX wClass;
	ZeroMemory(&wClass, sizeof(WNDCLASSEX));
	wClass.cbClsExtra = NULL;
	wClass.cbSize = sizeof(WNDCLASSEX);
	wClass.cbWndExtra = NULL;
	wClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wClass.hIcon = NULL;
	wClass.hIconSm = NULL;
	wClass.hInstance = Hinst;
	wClass.lpszClassName = "Carga";
	wClass.lpszMenuName = NULL;
	wClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClassEx(&wClass);
	_input = CreateWindowEx(NULL, "EDIT", "Valor da carga", WS_VISIBLE | WS_BORDER | WS_OVERLAPPEDWINDOW, 260, 10, 300, 200, window, NULL, Hinst, NULL);
	if (!_input){
		int error = GetLastError();
		std::cout << "Ocorreu um erro, codigo: " << error << std::endl;
	}
}

void Input::closeWindow(){
	ShowWindow(_input, SW_HIDE);
}

Input::~Input()
{
	ShowWindow(_input, SW_HIDE);
}

void Input::Init(HINSTANCE inst, HWND win){
	Hinst = inst;
	window = window;
	Instance = new Input();
}