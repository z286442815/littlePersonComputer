/**
  * @file LittlePersonComputer.cpp
  * @author Xin Zhang
  * @brief constructor for the LittlePersonComputer project
  */
#include "LittlePersonComputer.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

LittlePersonComputer::LittlePersonComputer(){
    for (int i = 0; i < 20; i++){
        memory[i] = 0;
    }
    accumulator = 0;
    programCounter = 0;
}

LittlePersonComputer::LittlePersonComputer(int instructions[], int numberOfinstructions) {
    for (int i = 0; i < maxSize; i++) {
        memory[i] = 0;
    }

    for (int i = 0; i < numberOfinstructions; i++) {
        memory[i] = instructions[i];
    }
    accumulator = 0;
    programCounter = 0;
}

int LittlePersonComputer::getProgramCounter() {
    return programCounter;
}

int LittlePersonComputer::getAccumulator() {
    return accumulator;
}

int LittlePersonComputer::getMemoryAt(int location) {
    return memory[location];
}

int LittlePersonComputer::getCurrentInstruction() {
    return memory[programCounter];
}

void LittlePersonComputer::loadProgram(int instructions[], int numberOfinstructions) {
    for (int i = 0; i < numberOfinstructions; i++) {
        memory[i] = instructions[i];
    }
}

void LittlePersonComputer::printState() {
    cout << "Accumulator: " <<  accumulator << setw(30) << "Program Counter: " << programCounter << endl
         << "Memory:" << endl;
    for (int i = 0; i < maxSize; i++) {
        cout << setw(5) << i;
    }
    cout << endl;
    for (int i = 0; i < maxSize; i++) {
        cout << setw(5) << memory[i];
    }
    cout << endl << endl;
}

bool LittlePersonComputer::isHalted(){
    if (memory[programCounter] == 0)
        return true;
    else
        return false;

}

void LittlePersonComputer::step() {
    int temp = getCurrentInstruction();
    int command = temp / 100;
    int address = temp - 100 * command;

    if (command == 1)
        accumulator = accumulator + memory[address];
    else if (command == 2)
        accumulator = accumulator - memory[address];
    else if (command == 3)
        memory[address] = accumulator;
    else if (command == 5)
        accumulator = memory[address];
    else if (command == 6)
        programCounter = address - 1;
    else if (command == 7) {
        if (accumulator > 0)
            programCounter = address - 1;
    }
    else if (command == 8) {
        if (accumulator >= 0)
            programCounter = address - 1;
    }
    else if (command == 9) {
        if (address == 1) {
            cout << "Input required: ";
            int input;
            cin >> input;
        }
        else if (address == 2) {
            cout << accumulator << endl;
        }
    }
    programCounter++;
}



