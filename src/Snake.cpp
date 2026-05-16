#include "Snake.hpp"
#include <Windows.h>

Snake::Snake(int startX, int startY, int initialLength) : startX_(startX), startY_(startY), initialLength_(initialLength), dirX_(1), dirY_(0) {
	initBody();
}

void Snake::initBody() {
    segments_.clear();
    for (size_t i = 0; i < initialLength_; ++i) {
        COORD point;
        point.X = static_cast<SHORT>(startX_ - i);
        point.Y = static_cast<SHORT>(startY_);
        segments_.push_back(point);
    }
}

void Snake::snakeMove() {
    // 1. Вычисляем новую голову: front + направление
    COORD newHead;
    newHead.X = static_cast<SHORT>(segments_.front().X + dirX_);
    newHead.Y = static_cast<SHORT>(segments_.front().Y + dirY_);

    // 2. Добавляем новую голову в начало
    segments_.push_front(newHead);

    // 3. Удаляем хвост (последний элемент)
    segments_.pop_back();
}

bool Snake::setDirection(int dx, int dy) {
    // Разворот — когда обе координаты строго противоположны
    if (dx == -dirX_ && dy == -dirY_) {
        return false; // не меняем направление
    }
    dirX_ = dx;
    dirY_ = dy;
    return true;
}