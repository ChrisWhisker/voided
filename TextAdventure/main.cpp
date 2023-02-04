#include "CommandHandler.h"
#include "PlayerState.h"
#include "Printer.h"
#include "ShipBridge.h"
#include <iostream>
using std::cout;

int main()
{
    shared_ptr<Printer> printer = Printer::getInstance();
    shared_ptr<CommandHandler> handler = CommandHandler::getInstance();
    shared_ptr<PlayerState> player = PlayerState::getInstance();

    printer->printByLine("____    ____  ______    __   _______   _______  _______  \n\\   \\  /   / /  __  \\  |  | |       \\ |   ____||       \\ \n \\   \\/   / |  |  |  | |  | |  .--.  ||  |__   |  .--.  |\n  \\      /  |  |  |  | |  | |  |  |  ||   __|  |  |  |  |\n   \\    /   |  `--'  | |  | |  '--'  ||  |____ |  '--'  |\n    \\__/     \\______/  |__| |_______/ |_______||_______/ \n\n\n");
    printer->print("You awake with a throbbing headache and a deafening ring in your ears. Opening your eyes, you're alone. The only thing you remember is losing control of your ship and preparing to crash land on a planet you don't recognize. A sensation of wetness makes itself known on the side of your head. You need to stop the bleeding.");
    printer->printMainStats();

    ShipBridge bridge;
    bridge.enter();
    printer->prompt();
    
    string command;
    while (std::getline(std::cin, command)) {
        handler->handle(command);
        player->addHealth(-3);
        printer->printMainStats();
        printer->prompt();
    }

    return 0;
}