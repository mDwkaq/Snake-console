#pragma once

#include <Windows.h>
#include <vector>

// ========== Цветовые enum class ==========
enum class TextColor : WORD {
    Black = 0,
    Red = FOREGROUND_RED,
    Green = FOREGROUND_GREEN,
    Blue = FOREGROUND_BLUE,
    Yellow = FOREGROUND_RED | FOREGROUND_GREEN,
    Magenta = FOREGROUND_RED | FOREGROUND_BLUE,
    Cyan = FOREGROUND_GREEN | FOREGROUND_BLUE,
    White = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    BrightRed = Red | FOREGROUND_INTENSITY,
    BrightGreen = Green | FOREGROUND_INTENSITY,
    BrightBlue = Blue | FOREGROUND_INTENSITY,
    BrightYellow = Yellow | FOREGROUND_INTENSITY,
    BrightMagenta = Magenta | FOREGROUND_INTENSITY,
    BrightCyan = Cyan | FOREGROUND_INTENSITY,
    BrightWhite = White | FOREGROUND_INTENSITY
};

enum class BgColor : WORD {
    Black = 0,
    Red = BACKGROUND_RED,
    Green = BACKGROUND_GREEN,
    Blue = BACKGROUND_BLUE,
    Yellow = BACKGROUND_RED | BACKGROUND_GREEN,
    Magenta = BACKGROUND_RED | BACKGROUND_BLUE,
    Cyan = BACKGROUND_GREEN | BACKGROUND_BLUE,
    White = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
    BrightRed = Red | BACKGROUND_INTENSITY,
    BrightGreen = Green | BACKGROUND_INTENSITY,
    BrightBlue = Blue | BACKGROUND_INTENSITY,
    BrightYellow = Yellow | BACKGROUND_INTENSITY,
    BrightMagenta = Magenta | BACKGROUND_INTENSITY,
    BrightCyan = Cyan | BACKGROUND_INTENSITY,
    BrightWhite = White | BACKGROUND_INTENSITY
};

// --- Палитры цветов ---
std::vector<TextColor> textPalette = {
    TextColor::Red, TextColor::Green, TextColor::Blue,
    TextColor::Yellow, TextColor::Magenta, TextColor::Cyan,
    TextColor::BrightRed, TextColor::BrightGreen, TextColor::BrightBlue,
    TextColor::BrightYellow, TextColor::BrightMagenta, TextColor::BrightCyan
};

std::vector<BgColor> bgPalette = {
    BgColor::Black, BgColor::Red, BgColor::Green, BgColor::Blue,
    BgColor::Yellow, BgColor::Magenta, BgColor::Cyan,
    BgColor::BrightRed, BgColor::BrightGreen, BgColor::BrightBlue,
    BgColor::BrightYellow, BgColor::BrightMagenta, BgColor::BrightCyan
};