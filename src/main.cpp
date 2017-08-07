#include "SnakeGameApp.hpp"
#include <Windows.h>
#include <string>
#include <stdexcept>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
	try
	{
		SnakeGameApp snakeGame;
		snakeGame.run();
	}
	catch (const std::exception& error)
	{
		std::string errorWhat = error.what();
		std::wstring errorText = std::wstring{ errorWhat.begin(), errorWhat.end() } + std::wstring{ L"\nPlease restart the application after fixing the problem" };
		MessageBox(NULL, errorText.c_str(), L"Exception Thrown!", MB_OK | MB_ICONERROR);
	}
	catch (...)
	{
		MessageBox(NULL, L"An unknown error has occurred within the application. Please try reloading the application to try and fix the problem", L"Exception Thrown!", MB_OK | MB_ICONERROR);
	}
}
