//#include <Windows.h>
//#include <iostream>
//#include <string>
//#include <chrono>
//#include <thread>
//#include <vector>
//
//int main()
//{
//	using std::string;
//	using std::cout;
//	using namespace std::chrono_literals; //200ms, 1s, 500us;
//	// --- тип часов ---
//	using Clock = std::chrono::steady_clock;
//	// --- момент времени ---
//	//using TimePoint = std::chrono::time_point<Clock>;
//	//using ms = std::chrono::milliseconds;
//	//ms tickDuration(200);
//	auto tick = 400ms;
//	//TimePoint lastUpdate = Clock::now(); //начальный момент
//	auto lastUpdate = Clock::now();
//	using std::this_thread::sleep_for;
//
//	// --- милизадержка ---
//	//using sleep = std::this_thread::sleep_for(1ms);
//
//	enum { right = 1, left = -1 };
//
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	// --- скрыть курсор ---
//	CONSOLE_CURSOR_INFO cursorInfo;
//	cursorInfo.dwSize = 1;
//	cursorInfo.bVisible = FALSE;
//	SetConsoleCursorInfo(hConsole, &cursorInfo);
//
//	char symbol{ '0' };
//	short posX{ 2 };
//	int dir = right;
//	std::vector<char> sym = {'\\', '|', '/', '-'  };
//	//int i{};
//	size_t symIndex = 0; // индекс текущего символа
//	cout << sym[0];
//	bool prevSpacePressed{ false };
//	bool paused{ false };
//
//	// --- начальное поле -----
//	COORD pos;
//	for (short i = 0; i < 5; ++i) {
//		pos = { i,0 };
//		SetConsoleCursorPosition(hConsole, pos);
//		cout << (i == posX ? sym[symIndex] : '_');
//	}
//
//    while (true) {
//        // ---------- Обработка ввода ----------
//        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) break;
//
//        // Пробел: переключение паузы (только по фронту нажатия)
//        bool currSpace = GetAsyncKeyState(VK_SPACE) & 0x8000;
//        if (!prevSpacePressed && currSpace) {
//            paused = !paused;
//            if (!paused) {
//                // При выходе из паузы сбрасываем таймер, чтобы не было скачка
//                lastUpdate = Clock::now();
//            }
//        }
//        prevSpacePressed = currSpace;
//
//        // Направление меняем только если не на паузе
//        if (!paused) {
//            if (GetAsyncKeyState(VK_LEFT) & 0x8000) dir = left;
//            if (GetAsyncKeyState(VK_RIGHT) & 0x8000) dir = right;
//        }
//
//        // ---------- Игровой шаг (только если не пауза) ----------
//        if (!paused) {
//            auto now = Clock::now();
//            if (now - lastUpdate >= tick) {
//                // Стереть старую позицию
//                SetConsoleCursorPosition(hConsole, { posX, 0 });
//                cout << '_';
//
//                // Обновить позицию с учётом направления и зацикливания
//                posX += static_cast<short>(dir);
//                if (posX < 0) posX = 4;
//                if (posX > 4) posX = 0;
//
//                // Сменить символ для анимации (раз в шаг)
//                symIndex = (symIndex + 1) % sym.size();
//
//                // Нарисовать новый символ
//                SetConsoleCursorPosition(hConsole, { posX, 0 });
//                cout << sym[symIndex];
//
//                lastUpdate = now;
//            }
//            else {
//                sleep_for(1ms);
//            }
//        }
//        else {
//            // На паузе показываем сообщение (опционально)
//            SetConsoleCursorPosition(hConsole, { 0, 0 });
//            cout << "PAUSE";
//            sleep_for(100ms); // небольшая задержка, чтобы не грузить процессор
//        }
//    }
//
//    // Восстановить видимость курсора перед выходом (хороший тон)
//    cursorInfo.bVisible = TRUE;
//    SetConsoleCursorInfo(hConsole, &cursorInfo);
//    return 0;
//}
