#pragma once
#include <string>

enum class TextColor {
	black = 30, red = 31, green = 32, yellow = 33,
	blue = 34, magenta = 35, cyan = 36, white = 37
};

class PrinterBase {
public:
	void resetColor() const;
	void setTextColor(TextColor color) const;
	virtual void print(std::string str) const = 0;
};
