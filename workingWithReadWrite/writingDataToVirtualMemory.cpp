#include <chrono>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sys/mman.h>
#include <unistd.h>
#define FILE_PATH "output.dat"
struct CSVData {
  std::chrono::system_clock::time_point time;
  double value;
  double index;
  int delta;
};

int main() {
  CSVData holder;
  holder.time = std::chrono::system_clock::now();
  holder.value = 10978.4889L;
  holder.index = 10.2;
  holder.delta = 19;
  size_t size = sizeof(holder);
  int output = open(FILE_PATH, O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600);
  truncate(FILE_PATH, size);
  CSVData *point =
      (CSVData *)mmap(nullptr, size, PROT_WRITE, MAP_SHARED, output, 0);
  point[0] = holder;
  close(output);
  std::cout << sizeof(holder) << "\n";
  return 0;
}
