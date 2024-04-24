#include "LevelDesign/Ship.h"
#include "Management/Clock.h"
#include "Management/CommandHandler.h"
#include "Management/PlayerState.h"
#include "Management/Printing/Printer.h"
#include <iostream>
using std::make_shared;

int main()
{
    auto printer = make_shared<Printer>(nullptr);
    auto player = make_shared<PlayerState>(printer);
    printer->setPlayerState(player);
    auto clock = make_shared<Clock>(player, printer);
    const auto cmdHandler = make_shared<CommandHandler>(clock, printer);

    printer->typeByLine("____    ____  ______    __   _______   _______  _______  \n"
                        "\\   \\  /   / /  __  \\  |  | |       \\ |   ____||       \\ \n"
                        " \\   \\/   / |  |  |  | |  | |  .--.  ||  |__   |  .--.  |\n"
                        "  \\      /  |  |  |  | |  | |  |  |  ||   __|  |  |  |  |\n"
                        "   \\    /   |  `--'  | |  | |  '--'  ||  |____ |  '--'  |\n"
                        "    \\__/     \\______/  |__| |_______/ |_______||_______/ \n", TextColor::red);

    Ship ship(printer);
    ship.enter();
    printer->prompt();

    string command;
    while (std::getline(std::cin, command))
    {
        cmdHandler->handle(command);
        printer->printMainStats();
        printer->prompt();
    }

    return 0;
}
