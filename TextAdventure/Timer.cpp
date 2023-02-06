#include "Timer.h"
#include "Management/Printer.h"
#include <iostream>

Timer::Timer(function<bool(string)> t_funcToCall, string t_argument1, int t_deadline) : funcToCall(t_funcToCall), argument1(t_argument1), deadline(t_deadline) {}

function<bool(string)> Timer::getFunction() {
	return funcToCall;
}

int Timer::getDeadline() const {
	return deadline;
}

bool Timer::callFunction() {
	return funcToCall(argument1);
}

bool Timer::operator==(const Timer& other) {
	return areFunctionsEqual(funcToCall, other.funcToCall) && deadline == other.deadline;
}
