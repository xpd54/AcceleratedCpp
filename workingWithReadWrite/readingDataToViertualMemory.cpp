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
  size_t size = sizeof(holder);
  int input = open(FILE_PATH, O_RDONLY);
  void *point = mmap(0, size, PROT_READ, MAP_SHARED, input, 0);
  CSVData *data = (CSVData *)point;
  double value = 10978.4889L;
  std::cout << std::fixed << std::setprecision(6);
  std::cout << data[0].value << "\n";
  std::cout << data[0].index << "\n";
  std::cout << data[0].delta << "\n";
  close(input);
  return 0;
}
