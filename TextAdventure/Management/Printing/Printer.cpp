#include "Printer.h"
#include "../PlayerState.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
using std::chrono::milliseconds;
using std::cout;
using std::endl;
using std::this_thread::sleep_for;
using std::to_string;

Printer::Printer(const shared_ptr<PlayerState> t_player) : player(t_player)
{
    srand((unsigned int)time(0));
}

void Printer::setPlayerState(const shared_ptr<PlayerState> t_player)
{
    player = t_player;
}

void Printer::prompt() const
{
    setTextColor(TextColor::green);
    cout << "> ";
}

void Printer::print(string str) const
{
    if (str.find("\n") != string::npos)
    {
        cout << str << endl;
        return;
    }
    cout << wordWrap(str) << endl;
}

void Printer::print(string str, TextColor color) const
{
    setTextColor(color);
    print(str);
    resetColor();
}

void Printer::newLine() const
{
    print("");
}

void Printer::type(string str) const
{
    if (!typeOutText)
    {
        print(str);
        return;
    }

    typeText(wordWrap(str), 1, 30, 30);
    cout << endl;
}

void Printer::type(string str, TextColor color) const
{
    setTextColor(color);
    type(str);
    resetColor();
}

void Printer::typeByLine(string str) const
{
    if (!typeOutText)
    {
        print(str);
        return;
    }

    typeText(str, 1, 0, 200);
    cout << endl;
}

void Printer::typeByLine(string str, TextColor color) const
{
    setTextColor(color);
    typeByLine(str);
    resetColor();
}

void Printer::printMainStats() const
{
    if (!player)
    {
        log.error("PlayerState is not set.");
        return;
    }
    printStats(player->mainStats());
}

void Printer::printCombatStats() const
{
    if (!player)
    {
        log.error("PlayerState is not set.");
        return;
    }
    printStats(player->combatStats());
}

void Printer::printAllStats() const
{
    if (!player)
    {
        log.error("PlayerState is not set.");
        return;
    }
    printStats(player->allStats());
}

void Printer::typeText(string str, int msAfterChar, int msAfterWord, int msAfterLine) const
{
    for (char c : str)
    {
        cout << c;

        if (c == ' ')
        {
            sleep_for(milliseconds(msAfterWord));
        }
        else if (c == '\n')
        {
            sleep_for(milliseconds(msAfterLine));
        }
        else
        {
            sleep_for(milliseconds(msAfterChar));
        }
    }
    cout << endl;
}

void Printer::printStats(string stats) const
{
    cout << "==========\n" << stats << endl << endl;
}

string Printer::wordWrap(string str) const
{
    log.print("word wrap called.");
    string wrappedString;
    std::vector<string> words;

    // Split the input string into words
    string word;
    for (const char& c : str)
    {
        if (c == ' ')
        {
            words.push_back(word);
            word.clear();
        }
        else
        {
            word += c;
        }
    }
    words.push_back(word);

    // Implement word wrapping by inserting line endings into the string
    int lineStart = 0;
    int lineEnd = 0;

    while (lineStart < words.size())
    {
        int currentLength = 0;

        while (lineEnd < words.size() && currentLength + words[lineEnd].length() <= 120)
        {
            currentLength += words[lineEnd].length() + 1;
            lineEnd++;
        }

        for (int i = lineStart; i < lineEnd; i++)
        {
            wrappedString += words[i];
            if (i < lineEnd - 1)
            {
                wrappedString += " ";
            }
        }
        wrappedString += "\n";
        lineStart = lineEnd;
    }

    return wrappedString;
}
