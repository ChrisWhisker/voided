#pragma once
#include "PrinterBase.h"
#include "Logger.h"
#include <array>
#include <memory>
#include <string>
using std::shared_ptr;
using std::string;

class PlayerState;

class Printer : public PrinterBase
{
public:
    Printer(const shared_ptr<PlayerState> t_player);
    void setPlayerState(const shared_ptr<PlayerState> t_player);

    void prompt() const;
    void print(string str) const override;
    void print(string str, TextColor color) const;
    void newLine() const;
    void type(string str) const;
    void type(string str, TextColor color) const;
    void typeByLine(string str) const;
    void typeByLine(string str, TextColor color) const;

    void printMainStats() const;
    void printCombatStats() const;
    void printAllStats() const;

private:
    shared_ptr<PlayerState> player;
    Logger log = Logger("Printer");

    std::array<string, 10> prompts = {
        "What would you like to do?", "What's the plan now?",
        "How do you want to proceed?", "Your next steps?", "What are you doing next?",
        "...and what are you gonna do about it?", "What do you want to do?", "What now?",
        "What are you doing now?", "Your next move?"
    };

    void typeText(string str, int msAfterChar, int msAfterWord, int msAfterLine) const;
    void printStats(string stats) const;
    string wordWrap(string str) const;
};
