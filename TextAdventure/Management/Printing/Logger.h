#pragma once
#include "PrinterBase.h"
using std::string;

class Logger : public PrinterBase {
public:
	Logger(string t_className);
	static const bool debugging = false;

	void print(string str) const override;
	void print(string str, int value) const;
	void warning(string str) const;
	void warning(string str, int value) const;
	void error(string str) const;
	void error(string str, int value) const;

private:
	string className;
	enum class DebugType { message = 47, warning = 43, error = 41 };
	void debug(DebugType type, string str) const;
};
