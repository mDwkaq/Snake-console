#pragma once

#include "GameConfig.hpp"
#include <windows.h>
#include <deque>

class Snake {
private:
	std::deque<COORD> segments_;	 //голова
	int dirX_, dirY_;				 //направление
	// --- Параметры начального состояния (чтобы reset работал) ----
	int startX_, startY_, initialLength_;
	// -- Вспомогательный метод: создать начальное тело ---
	void initBody();
public:

	// --- Конструктор: начальная позиция головы, начальная длина (>= 2), направление по умолчанию вправо ---
	Snake(int startX = 10, int startY = 10, int initialLength = 3);
	
	// --- Движение змеи по коордам без rendering ---
	void snakeMove();

	// --- смена направлениея ---
	bool setDirection(int newx, int newy);

	// ---- проверочка на то что сейчас ---
	const std::deque<COORD>& getSegments() const { return segments_; }

};