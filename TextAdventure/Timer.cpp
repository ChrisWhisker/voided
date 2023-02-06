#include "Timer.h"
#include "Management/Printer.h"
#include <iostream>

Timer::Timer(function<bool(string)> func, string arg1, int ddln) : funcToCall(func), argument1(arg1), deadline(ddln) {}

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
