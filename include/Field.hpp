#pragma once

#include "GameConfig.hpp"
#include <Windows.h>

class Field {
public:
	Field(int width, int height);

	int getWidth() const { return width_; }
	int getHeight() const { return height_; }

	// Телепортирует координаты, если они выходят за [0, width-1] и [0, height-1]
	void wrapPosition(COORD& pos) const;
private:
	int width_, height_;
};