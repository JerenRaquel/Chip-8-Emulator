#ifndef CHIP8_HPP_
#define CHIP8_HPP_

#include <cstdint>
#include <string>
#include <fstream>
#include <algorithm>

#define DISPLAY_WIDTH 64
#define DISPLAY_HEIGHT 32
#define STARTING_ADDRESS 0x200

class Chip8 {
 private:
  uint8_t registers[16];
  uint8_t memory[4096];
  uint16_t indexRegister;
  uint16_t programCounter;
  uint16_t levelStack;
  uint8_t stackPointer;
  uint8_t delayTimer;
  uint8_t soundTimer;
  uint8_t keys[16];
  uint32_t videoRam[DISPLAY_WIDTH * DISPLAY_HEIGHT];

 public:
  Chip8();
  ~Chip8();

  void LoadROM(const std::string fileName);
};
#endif  // CHIP8_HPP_