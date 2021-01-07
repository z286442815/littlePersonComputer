/**
  * @file LittlePersonComputer.h
  * @author Xin Zhang
  * @brief header file for the LittlePersonComputer project
  */
#ifndef LITTLEPERSONCOMPUTER_H
#define LITTLEPERSONCOMPUTER_H

class LittlePersonComputer {
public:
    /**
     * @brief Initializes accumulator, program counter and all memory slots to 0
     */
    LittlePersonComputer();

    /**
     * @brief initializes all memory slots to 0, then read the instruction array into the meory array
     * @param instructions array contains a list of instructions
     * @param size of instruction array
     */
    LittlePersonComputer(int instructions[], int numberOfinstruction);

    /**
     * @brief Return the address/steps of memory
     */
    int getProgramCounter();

    /**
     * @brief Return the value in memory at the indicated location.
     */
    int getAccumulator();

    /**
     * @brief Return the current value in memory at the indicated location by using program counter.
     */
    int getCurrentInstruction();

    /**
     * @brief return a specific value in memory
     * @param a specific program counter/address of memory
     */
    int getMemoryAt(int location);

    /**
     * @brief copy the instruction into memory
     * @param instruction array
     * @param size of instruction array
     */
    void loadProgram(int instructions[], int numberOfinstructions);

    /**
     * @brief print the current state of accumulator, program counter, and memory
     */
    void printState();

    /**
     * @brief distinguish and run the instruction according to the list of machine code
     */
    void step();

    /**
     * @brief return true if the next instruction to be run is 0, otherwise false
     */
    bool isHalted();

private:
    const int maxSize = 20;
    int memory[20];
    int accumulator;
    int programCounter;
};


#endif // LITTLEPERSONCOMPUTER_H
