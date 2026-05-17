#include "Renderer.hpp"

#include <iostream>

void Renderer::drawChar(SHORT x, SHORT y, char symbol) {
	COORD pos{ x,y };
	SetConsoleCursorPosition(hConsole_, pos);
	std::cout << symbol << std::flush;
}
void Renderer::drawSnake(const Snake& snake) {
	const auto& segs = snake.getSegments();
	for (size_t i = 0; i < segs.size(); ++i) {
		char sprite = (i == 0 ? Sprites::SPRITE_HEAD : Sprites::SPRITE_BODY);
		drawChar(segs[i].X, segs[i].Y, sprite);
	}
}
void Renderer::drawField(const Field& field) {
	char sprite = Sprites::SPRITE_WALL;
	for (int i = 0; i < field.getWidth(); ++i) {
		drawChar(i, 0, sprite);
		drawChar(i, field.getHeight(), sprite);
	}
	for (int i = 1; i < field.getHeight(); ++i) {
		drawChar(0, i, sprite);
		drawChar(field.getWidth()-1, i, sprite);
	}
}
void Renderer::clearCell(SHORT x, SHORT y) {
	COORD pos{ x,y };
	SetConsoleCursorPosition(hConsole_, pos);
	std::cout << " " << std::flush;
}
void Renderer::clearCells(const std::deque<COORD>& cells) {
	for (const auto& cell : cells) {
		clearCell(cell.X, cell.Y);
	}
}