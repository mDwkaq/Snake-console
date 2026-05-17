#include "InputHandler.hpp"

bool processInput(Snake& game) {
    bool changed{ false };

    if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
        COORD d = GameConfig::directionToDelta(GameConfig::Direction::LEFT);
        changed = game.setDirection(d.X, d.Y) || changed;
    }
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
        COORD d = GameConfig::directionToDelta(GameConfig::Direction::RIGHT);
        changed =  game.setDirection(d.X, d.Y) || changed;
    }
    if (GetAsyncKeyState(VK_UP) & 0x8000) {
        COORD d = GameConfig::directionToDelta(GameConfig::Direction::UP);
        changed =  game.setDirection(d.X, d.Y) || changed;
    }
    if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
        COORD d = GameConfig::directionToDelta(GameConfig::Direction::DOWN);
        changed =  game.setDirection(d.X, d.Y) || changed;
    }
    return changed;
}