#include "Printer.h"
#include <chrono>
#include <iostream>
#include <thread>
using std::chrono::milliseconds;
using std::cout;
using std::this_thread::sleep_for;

void Printer::print(string line)
{
	for (char c : line)
	{
		cout << c;
		if (c == ' ')
		{
			sleep_for(milliseconds(50));
		}
		else
		{
			sleep_for(milliseconds(5));
		}
	}
	sleep_for(milliseconds(250));
}
