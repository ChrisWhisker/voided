#pragma once
#include <functional>
#include <string>
using std::function;
using std::string;

class Timer {
public:
	Timer(const function<bool(string)> t_funcToCall, string t_argument1, int t_deadline);
	function<bool(string)> getFunction() const;
	bool callFunction() const;
	bool operator==(const Timer& other);

	string getArgument1() const;
	int getDeadline() const;

private:
	function<bool(string)> funcToCall;
	string argument1;
	int deadline;

	bool areFunctionsEqual(const function<bool(string)>& f1, const function<bool(string)>& f2) const;
};
