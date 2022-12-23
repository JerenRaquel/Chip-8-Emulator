#include "../headers/chip8.hpp"

Chip8::Chip8() {}

Chip8::~Chip8() {}

void Chip8::LoadROM(const std::string fileName) {
  std::ifstream file(fileName);

  if (file.is_open()) {
    file.seekg(0, std::ios::end);
    int size = file.tellg();
    char* buffer = new char[size];

    file.seekg(0, std::ios::beg);
    file.read(buffer, size);

    for (int i = 0; i < size; i++) {
      this->memory[STARTING_ADDRESS + i] = buffer[i];
    }

    delete buffer;
  }
  file.close();
}
