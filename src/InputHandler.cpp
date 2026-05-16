#include "InputHandler.hpp"

void processInput(Snake& game) {
    if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
        COORD d = GameConfig::directionToDelta(GameConfig::Direction::LEFT);
        game.setDirection(d.X, d.Y);
    }
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
        COORD d = GameConfig::directionToDelta(GameConfig::Direction::RIGHT);
        game.setDirection(d.X, d.Y);
    }
    if (GetAsyncKeyState(VK_UP) & 0x8000) {
        COORD d = GameConfig::directionToDelta(GameConfig::Direction::UP);
        game.setDirection(d.X, d.Y);
    }
    if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
        COORD d = GameConfig::directionToDelta(GameConfig::Direction::DOWN);
        game.setDirection(d.X, d.Y);
    }
}