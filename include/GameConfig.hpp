#pragma once

#include <chrono>
#include <thread>
#include <windows.h>

namespace GameConfig {
    using namespace std::chrono_literals;

    // --- временные размеры поля ---
    inline constexpr int FIELD_WIDTH{ 20 };
    inline constexpr int FIELD_HEIGHT{ 15 };
    // --- поля для ошибок тест ---
    inline constexpr int FIELD_W_ERROR{ -1 };
    inline constexpr int FIELD_H_ERROR{ -1 };

    // --- время ---
    inline constexpr auto TICK_DURATION{ 200ms };
    using Clock = std::chrono::steady_clock;
    using std::this_thread::sleep_for;

    // --- направление ---
    enum class Direction { RIGHT = 1, LEFT = -1, UP = 2, DOWN = -2 };

    // Функция, возвращающая (dx, dy)
    inline COORD directionToDelta(Direction dir) {
        switch (dir) {
        case Direction::RIGHT: return { 1,  0 };
        case Direction::LEFT:  return { -1,  0 };
        case Direction::UP:    return { 0, -1 };   // в консоли вверх = уменьшение Y
        case Direction::DOWN:  return { 0,  1 };   // вниз = увеличение Y
        default:               return { 0,  0 };
        }
    }
}