#include <chrono>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/mman.h>
#include <unistd.h>
#include <vector>
#define INPUT_FILE "output.dat"
#define N 9
struct StockTick {
  std::chrono::system_clock::time_point date;
  double close;
  double high;
  double low;
  double open;
  double volume;
  double sma5;
  double sma10;
  double sma15;
  double sma20;
  double ema5;
  double ema10;
  double ema15;
  double ema20;
  double upperband;
  double middleband;
  double lowerband;
  double HT_TRENDLINE;
  double KAMA10;
  double KAMA20;
  double KAMA30;
  double SAR;
  double TRIMA5;
  double TRIMA10;
  double TRIMA20;
  double ADX5;
  double ADX10;
  double ADX20;
  double APO;
  double CCI5;
  double CCI10;
  double CCI15;
  double macd510;
  double macd520;
  double macd1020;
  double macd1520;
  double macd1226;
  double MFI;
  double MOM10;
  double MOM15;
  double MOM20;
  double ROC5;
  double ROC10;
  double ROC20;
  double PPO;
  double RSI14;
  double RSI8;
  double slowk;
  double slowd;
  double fastk;
  double fastd;
  double fastksr;
  double fastdsr;
  double ULTOSC;
  double WILLR;
  double ATR;
  double Trange;
  double TYPPRICE;
  double HT_DCPERIOD;
  double BETA;
};

int main() {
  StockTick sizeOfStockTick;
  size_t size = sizeof(StockTick[N]);
  int input = open(INPUT_FILE, O_RDONLY);
  void *points = mmap(nullptr, size, PROT_READ, MAP_SHARED, input, 0);
  StockTick *holders = (StockTick *)points;
  StockTick holder;
  for (size_t i = 0; i < N; i++) {
    holder = holders[i];
    std::time_t time = std::chrono::system_clock::to_time_t(holder.date);
    std::cout << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S")
              << "\n";
  }
  munmap(points, size);
  close(input);
  return 0;
}