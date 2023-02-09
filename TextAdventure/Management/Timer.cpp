#include "Timer.h"
#include "Printer.h"
#include <iostream>

Timer::Timer(const function<bool(string)> t_funcToCall, string t_argument1, int t_deadline)
	: funcToCall(t_funcToCall), argument1(t_argument1), deadline(t_deadline) {
}

function<bool(string)> Timer::getFunction() const {
	return funcToCall;
}

bool Timer::callFunction() const {
	return funcToCall(argument1);
}

bool Timer::operator==(const Timer& other) {
	return areFunctionsEqual(funcToCall, other.funcToCall) && deadline == other.deadline;
}

string Timer::getArgument1() const {
	return argument1;
}

int Timer::getDeadline() const {
	return deadline;
}

bool Timer::areFunctionsEqual(const function<bool(string)>& f1, const function<bool(string)>& f2) const {
	return f1.target_type() == f2.target_type();
}
