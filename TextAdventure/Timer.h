#pragma once
#include <functional>
#include <string>
using std::function;
using std::string;

class Timer {
public:
	Timer(function<bool(string)> func, string arg1, int ddln);
	function<bool(string)> getFunction();
	string argument1;
	int getDeadline() const;
	bool callFunction();
	bool operator==(const Timer& other);

private:
	function<bool(string)> funcToCall;
	int deadline;

	bool areFunctionsEqual(const function<bool(string)>& f1, const function<bool(string)>& f2) {
		return f1.target_type() == f2.target_type();
	}
};
