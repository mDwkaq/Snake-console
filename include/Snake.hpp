#pragma once

#include "Field.hpp"
#include "GameConfig.hpp"
#include <windows.h>
#include <deque>
#include <iostream>

class Snake {
private:
	std::deque<COORD> segments_;	 //голова
	int dirX_, dirY_;				 //направление
	// --- Параметры начального состояния (чтобы reset работал) ----
	int startX_, startY_, initialLength_;
	// -- Вспомогательный метод: создать начальное тело ---
	void initBody();
	// --- указатель на поле, чтоб змейка знала где она ---
	const Field* field_;
public:

	// --- Конструктор: начальная позиция головы, начальная длина (>= 2), направление по умолчанию вправо ---
	Snake(int startX = 10, int startY = 10, int initialLength = 3);

	// --- подключаем поле к змейке ---
	void setField(const Field* field) { field_ = field; }
	
	// --- централизируем змейку относительно поля ---
	void centerInField();
	
	// --- Движение змеи по коордам без rendering ---
	bool snakeMove();

	// --- смена направлениея ---
	bool setDirection(int newx, int newy);

	// ---- проверочка на то что сейчас ---
	const std::deque<COORD>& getSegments() const { return segments_; }

	// --- сброс до заводских временный ---
	void reset();

};