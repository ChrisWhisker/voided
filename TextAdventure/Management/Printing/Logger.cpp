#include "Logger.h"
#include <iostream>
using std::cout;
using std::to_string;

Logger::Logger(string t_className) : className(t_className) {
}

void Logger::print(string str) const {
	debug(DebugType::message, str);
}

void Logger::print(string str, int value) const {
	print(str + to_string(value));
}

void Logger::warning(string str) const {
	debug(DebugType::warning, str);
}

void Logger::warning(string str, int value) const {
	warning(str + to_string(value));
}

void Logger::error(string str) const {
	debug(DebugType::error, str);
}

void Logger::error(string str, int value) const {
	error(str + to_string(value));
}

void Logger::debug(DebugType type, string str) const {
	if (!logsEnabled) {
		return;
	}

	string typeName;

	switch (type) {
	case DebugType::message:
		typeName = "Message";
		break;
	case DebugType::warning:
		typeName = "Warning";
		break;
	case DebugType::error:
		typeName = "Error";
		break;
	}

	setTextColor(TextColor::black);
	cout << "\033[" << to_string((int)type) << "m";
	cout << typeName;
	resetColor();
	cout << " [" << className << "] " << str << std::endl;
}
