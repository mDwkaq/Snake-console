#include "GameConfig.hpp"
#include "Sprites.hpp"
#include "Snake.hpp"
#include "InputHandler.hpp"
#include "Renderer.hpp"
#include "Field.hpp"

#include <Windows.h>
#include <iostream>

        // --- бумага и ручка ---
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//void clearScreen(HANDLE hConsole);

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

#pragma region default_setting
          // --- Время. изначальные значения ---
    auto lastUpdate = GameConfig::Clock::now();
          // --- Координаты. изначальные значения ---
    Snake game;
    Field field(GameConfig::FIELD_WIDTH, GameConfig::FIELD_HEIGHT);
    game.setField(&field);
    game.centerInField();
          // --- работаем с этой консолью ---
    Renderer renderer(hConsole);
    renderer.drawField(field);
    renderer.drawSnake(game);
#pragma endregion


    // --- исправление бага быстрого нажатия клавиш ---
    bool directionChangedThisTick{ false };

    while (true) {
        // --- Обработка ввода ---
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) break;
        if (!directionChangedThisTick) {
            if (processInput(game)) directionChangedThisTick = true;
        }

        // --- Игровой шаг ---
        auto now = GameConfig::Clock::now();
        if (now - lastUpdate >= GameConfig::TICK_DURATION) {

            // 1. Сохраняем старые концы
            auto oldHead = game.getSegments().front();
            auto oldTail = game.getSegments().back();
            auto oldSegments = game.getSegments();
            bool collision = game.snakeMove();
            if (collision) {
                renderer.clearCells(oldSegments);
                renderer.drawSnake(game);
            }
            else {
                // Стираем старый хвост
                renderer.clearCell(oldTail.X, oldTail.Y);
                // Старую голову перерисовываем как тело
                renderer.drawChar(oldHead.X, oldHead.Y, Sprites::SPRITE_BODY);
                // Новую голову рисуем
                COORD newHead = game.getSegments().front();
                renderer.drawChar(newHead.X, newHead.Y, Sprites::SPRITE_HEAD);
            }
            lastUpdate = now;
            directionChangedThisTick = false;
        }
        else GameConfig::sleep_for(1ms);
    }
    COORD exitPos = { 0, GameConfig::FIELD_HEIGHT + 1 }; // например, 0,16
    SetConsoleCursorPosition(hConsole, exitPos);
    std::cout << std::endl;
    return 0;
}

//void clearScreen(HANDLE hConsole) {
//    CONSOLE_SCREEN_BUFFER_INFO csbi;
//    GetConsoleScreenBufferInfo(hConsole, &csbi);
//    DWORD totalCells = csbi.dwSize.X * csbi.dwSize.Y;
//    COORD origin = { 0, 0 };
//    DWORD written;
//    FillConsoleOutputCharacter(hConsole, ' ', totalCells, origin, &written);
//    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, totalCells, origin, &written);
//    SetConsoleCursorPosition(hConsole, origin);
//}