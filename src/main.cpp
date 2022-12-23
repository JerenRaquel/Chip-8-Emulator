/*	Jeren Raquel
 *	==Chip - 8 Emulator==
 */
#include <iostream>
#include <string>

#include "./headers/chip8.hpp"

int main(int argc, char** argv) {
  if (argc < 2) return 1;

  Chip8* microController = new Chip8();
  microController->LoadROM(argv[1]);
  delete microController;

  return 0;
}
