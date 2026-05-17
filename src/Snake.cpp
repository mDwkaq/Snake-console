#include "Snake.hpp"
#include <Windows.h>
#include <algorithm>

Snake::Snake(int startX, int startY, int initialLength) : startX_(startX), startY_(startY), initialLength_(initialLength), dirX_(1), dirY_(0), field_(nullptr) {
	
    initBody();
}

void Snake::centerInField() {
    if (!field_) return;
    int centerX = (field_->getWidth() - 1) / 2;
    int centerY = (field_->getHeight() - 1) / 2;

    startX_ = centerX;
    startY_ = centerY;
    dirX_ = 1;
    dirY_ = 0;
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

bool Snake::snakeMove() {
    // 1. Вычисляем новую голову: front + направление
    COORD newHead;
    newHead.X = static_cast<SHORT>(segments_.front().X + dirX_);
    newHead.Y = static_cast<SHORT>(segments_.front().Y + dirY_);

    if (field_) {
        field_->wrapPosition(newHead);
    }

    // 2. Проверка столкновения
    auto begin = segments_.begin();
    auto end = segments_.end();

    // исплючаем хвост
    if (segments_.size() > 1) --end;
    auto collision = std::find_if(begin, end, [&newHead](const COORD& seg) {return seg.X == newHead.X && seg.Y == newHead.Y; });

    if (collision != end) {
        reset();
        return true;
    }

    // 3. Добавляем новую голову в начало
    segments_.push_front(newHead);

    // 4. Удаляем хвост (последний элемент)
    segments_.pop_back();

    return false;
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

void Snake::reset() {
    
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (const auto& s : segments_) {
        SetConsoleCursorPosition(hConsole, s);
        std::cout << " ";
    }
    dirX_ = 1;
    dirY_ = 0;
    initBody();
}