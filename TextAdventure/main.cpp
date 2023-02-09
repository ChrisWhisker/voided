#include "LevelDesign/Ship/Ship.h"
#include "Management/Clock.h"
#include "Management/CommandHandler.h"
#include "Management/PlayerState.h"
#include "Management/Printer.h"
#include <iostream>
using std::make_shared;

int main() {
	auto printer = make_shared<Printer>(nullptr);
	auto player = make_shared<PlayerState>(printer);
	printer->setPlayerState(player);
	auto clock = make_shared<Clock>(player, printer);
	auto cmdHandler = make_shared<CommandHandler>(clock, printer);

	printer->typeByLine("____    ____  ______    __   _______   _______  _______  \n"
		"\\   \\  /   / /  __  \\  |  | |       \\ |   ____||       \\ \n"
		" \\   \\/   / |  |  |  | |  | |  .--.  ||  |__   |  .--.  |\n"
		"  \\      /  |  |  |  | |  | |  |  |  ||   __|  |  |  |  |\n"
		"   \\    /   |  `--'  | |  | |  '--'  ||  |____ |  '--'  |\n"
		"    \\__/     \\______/  |__| |_______/ |_______||_______/ \n", TextColor::red);
	printer->type("You awake with a throbbing headache and a deafening ring in your ears. Opening your eyes, "
		"you're alone. The only thing you remember is losing control of your ship and preparing to crash land on a "
		"planet you don't recognize. A sensation of wetness makes itself known on the side of your head. You need to "
		"stop the bleeding.");
	printer->printMainStats();

	Ship ship;
	ship.enter();
	printer->prompt();

	string command;
	while (std::getline(std::cin, command)) {
		cmdHandler->handle(command);
		printer->printMainStats();
		printer->prompt();
	}

	return 0;
}
