//#include <Windows.h>
//#include <conio.h>
//#include <iostream>
//#include <string>
//#include <chrono>
//
//int main()
//{
//	using std::string;
//	using std::cout;
//	
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	
//	CONSOLE_CURSOR_INFO cursorInfo;
//	cursorInfo.dwSize = 1;
//	cursorInfo.bVisible = FALSE;
//	SetConsoleCursorInfo(hConsole, &cursorInfo);
//
//	//static const int COUNT{ 9 };
//	//int i{ 0 };
//	char symbol{ '0' };
//	//string str{ "_____" };
//	int posX{ 2 };
//
//	COORD pos;
//	for (int i = 0; i < 5; ++i) {
//		pos = { static_cast<short>(i),0 };
//		SetConsoleCursorPosition(hConsole, pos);
//		cout << (i == posX ? symbol : '_');
//	}
//
//	while (true) {
//		int key = _getch();
//		if (key == 'q') break;
//
//		// --- признак стрелки ---
//		if (key == 224) {
//			int arrow = _getch();
//			pos = { static_cast<short>(posX), 0 };
//			SetConsoleCursorPosition(hConsole, pos);
//			cout << '_';
//
//			// --- меняем координату ---
//			if (arrow == 75) {			//влево
//				posX--;
//				if (posX < 0) posX = 4;
//			}
//			else if (arrow == 77) {		//вправо
//				posX++;
//				if (posX > 4) posX = 0;
//			}
//
//			// --- рисуем в новой позиции ---
//			pos = { static_cast<short>(posX), 0 };
//			SetConsoleCursorPosition(hConsole, pos);
//			cout << symbol;
//		}
//	}
//
//
//
//	return 0;
//}
