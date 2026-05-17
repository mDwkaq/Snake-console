#include "Field.hpp"

Field:: Field(int width, int height) {

    constexpr int MIN_WIDTH = 20;
    constexpr int MIN_HEIGHT = 10;

    width_ = (width < MIN_WIDTH) ? MIN_WIDTH : width;
    height_ = (height < MIN_HEIGHT) ? MIN_HEIGHT : height;
}

void Field::wrapPosition(COORD& pos) const {
    if (pos.X <= 0) pos.X = width_ - 2;
    else if (pos.X >= width_ - 1) pos.X = 1;

    if (pos.Y <= 0) pos.Y = height_ - 1;
    else if (pos.Y >= height_) pos.Y = 1;
}