//#include "test_color.hpp"
//
//#include <Windows.h>
//#include <iostream>
//#include <string>
//#include <vector>
//
//int main()
//{
//
//	// --- передаем в руки кисточку и передаем HANDLE ---
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	// --- имя окна ---
//	SetConsoleTitle(TEXT("Snake"));
//	// --- мигалка каретки размер и видимость ---
//	CONSOLE_CURSOR_INFO cursorInfo;
//	cursorInfo.dwSize = 1;
//	cursorInfo.bVisible = FALSE;
//	SetConsoleCursorInfo(hConsole, &cursorInfo);
//
//	std::string s{ "Hello World" };
//
//	while (true)
//	{
//		system("cls");
//		for (int i = 0; i < s.size(); i++)
//		{
//			// Выбираем цвет текста и фона по индексу (можно i % palette.size())
//			TextColor curText = textPalette[i % textPalette.size()];
//			BgColor curBg = bgPalette[(i + 3) % bgPalette.size()]; // смещение для разнообразия
//
//			// Устанавливаем атрибут: текст + фон
//			SetConsoleTextAttribute(hConsole,
//				static_cast<WORD>(curText) | static_cast<WORD>(curBg));
//
//			COORD pos = { 10 + i, 5 + i };
//			SetConsoleCursorPosition(hConsole, pos);
//			std::cout << s[i] << std::flush;
//			Sleep(100);
//		}
//	}
//	
//		
//	return 0;
//}