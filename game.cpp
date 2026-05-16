#include "GameConfig.hpp"
#include "Sprites.hpp"
#include "Snake.hpp"
#include "InputHandler.hpp"

#include <Windows.h>
#include <iostream>

// --- бумага и ручка ---
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


int main()
{
    using namespace std::chrono_literals;
    // ------
    SetConsoleTitle(TEXT("Snake"));

#pragma region cursor
    	// --- скрыть курсор ---
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hConsole, &cursorInfo);
#pragma endregion

    // --- Время. изначальные значения ---
    auto lastUpdate = GameConfig::Clock::now();

    // --- Координаты. изначальные значения ---
    Snake game;

    // --- Изначальный рендеринг 1 кадр ---
    const auto& segs = game.getSegments();
    for (size_t i = 0; i < segs.size(); ++i) {
        SetConsoleCursorPosition(hConsole, segs[i]);
        std::cout << (i == 0 ? Sprites::SPRITE_HEAD : Sprites::SPRITE_BODY);
    }

    while (true) {
        // --- Обработка ввода ---
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) break;
        processInput(game);

        // --- Игровой шаг ---
        auto now = GameConfig::Clock::now();
        if (now - lastUpdate >= GameConfig::TICK_DURATION) {

            // 1. Сохраняем старые концы
            COORD oldHead = game.getSegments().front();
            COORD oldTail = game.getSegments().back();

            game.snakeMove();

            // Стираем старый хвост
            SetConsoleCursorPosition(hConsole, oldTail);
            std::cout << ' ';

            // Старую голову перерисовываем как тело
            SetConsoleCursorPosition(hConsole, oldHead);
            std::cout << Sprites::SPRITE_BODY;

            // Новую голову рисуем
            COORD newHead = game.getSegments().front();
            SetConsoleCursorPosition(hConsole, newHead);
            std::cout << Sprites::SPRITE_HEAD;

            lastUpdate = now;
        }
        else {
            GameConfig::sleep_for(1ms);
             }

    }

    return 0;
}

