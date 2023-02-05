#include "Timer.h"
#include "Management/Printer.h"
#include <iostream>

Timer::Timer(function<bool(string)> func, int ddln) : funcToCall(func), deadline(ddln) {}

function<bool(string)> Timer::getFunction()
{
	return funcToCall;
}

int Timer::getDeadline() const
{
	return deadline;
}

// TODO Actually call the function
bool Timer::callFunction()
{
	std::cout << "FUNCTION WOULD BE CALLED HERE";
	return true;
}

bool Timer::operator==(const Timer& other)
{
	return areFunctionsEqual(funcToCall, other.funcToCall)
		&& deadline == other.deadline;
}