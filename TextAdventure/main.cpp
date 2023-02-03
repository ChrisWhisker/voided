#include "CommandHandler.h"
#include "Printer.h"
#include <iostream>
using std::cout;

int main()
{
    Printer printer;
    printer.printByLine("____    ____  ______    __   _______   _______  _______  \n\\   \\  /   / /  __  \\  |  | |       \\ |   ____||       \\ \n \\   \\/   / |  |  |  | |  | |  .--.  ||  |__   |  .--.  |\n  \\      /  |  |  |  | |  | |  |  |  ||   __|  |  |  |  |\n   \\    /   |  `--'  | |  | |  '--'  ||  |____ |  '--'  |\n    \\__/     \\______/  |__| |_______/ |_______||_______/ \n\n\n");
    printer.print("You awake with a throbbing headache and a deafening ring in your ears.");
    printer.print("Opening your eyes, you're alone. The only thing you remember is losing control of your ship and steering towards the closest habitable planet.");
    printer.print("A sensation of wetness makes itself known on the side of your head. You need to stop the bleeding.");

    //printer.printMainStats();
    printer.print("\nWhat do you want to do?\n> ");

    CommandHandler handler;
    string command;

    while (std::getline(std::cin, command)) {
        handler.Handle(command);
        printer.print("What do you want to do?\n> ");
    }

    return 0;
}