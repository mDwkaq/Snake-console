#pragma once

#include "Snake.hpp"
#include "Field.hpp"
#include <Windows.h>
#include "Sprites.hpp"

class Renderer {
public:
	explicit Renderer(HANDLE hConsole) :hConsole_(hConsole) {}
	void drawChar(SHORT x, SHORT y, char symbol);
	void drawSnake(const Snake& snake);
	void drawField(const Field& field);
	void clearCell(SHORT x, SHORT y);
	void clearCells(const std::deque<COORD>& cells);
private:
	HANDLE hConsole_;
};