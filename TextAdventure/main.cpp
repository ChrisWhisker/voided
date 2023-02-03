#include "Printer.h"
#include <iostream>
using std::cout;

int main()
{
    Printer p;
    p.printByLine("____    ____  ______    __   _______   _______  _______  \n\\   \\  /   / /  __  \\  |  | |       \\ |   ____||       \\ \n \\   \\/   / |  |  |  | |  | |  .--.  ||  |__   |  .--.  |\n  \\      /  |  |  |  | |  | |  |  |  ||   __|  |  |  |  |\n   \\    /   |  `--'  | |  | |  '--'  ||  |____ |  '--'  |\n    \\__/     \\______/  |__| |_______/ |_______||_______/ \n\n\n");
    p.print("You awake with a throbbing headache and a deafening ring in your ears.\n");
    p.print("Opening your eyes, you're alone. The only thing you remember is losing control of your ship and steering towards the closest habitable planet.\n");
    p.print("A sensation of wetness makes itself known on the side of your head. You need to stop the bleeding.\n");

    p.printMainStats();

    string command;
    std::cin >> command;

    return 0;
}