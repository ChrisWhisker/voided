#include "Management/Clock.h"
#include "Management/CommandHandler.h"
#include "Management/PlayerState.h"
#include "Management/Printer.h"
#include "ShipBridge.h"
#include <iostream>

int main()
{
	Printer printer(nullptr);
	PlayerState player(&printer);
	printer.setPlayerState(&player);
	Clock clock(&player, &printer);
	CommandHandler handler(&clock, &printer);

	printer.typeByLine("____    ____  ______    __   _______   _______  _______  \n"
		"\\   \\  /   / /  __  \\  |  | |       \\ |   ____||       \\ \n"
		" \\   \\/   / |  |  |  | |  | |  .--.  ||  |__   |  .--.  |\n"
		"  \\      /  |  |  |  | |  | |  |  |  ||   __|  |  |  |  |\n"
		"   \\    /   |  `--'  | |  | |  '--'  ||  |____ |  '--'  |\n"
		"    \\__/     \\______/  |__| |_______/ |_______||_______/ \n", Color::red);
	printer.type("You awake with a throbbing headache and a deafening ring in your ears. Opening your eyes, "
		"you're alone. The only thing you remember is losing control of your ship and preparing to crash land on a "
		"planet you don't recognize. A sensation of wetness makes itself known on the side of your head. You need to "
		"stop the bleeding.");
	printer.printMainStats();

	ShipBridge bridge;
	bridge.enter();
	printer.prompt();

	string command;
	while (std::getline(std::cin, command)) {
		handler.handle(command);
		printer.printMainStats();
		printer.prompt();
	}

	return 0;
}