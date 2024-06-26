#include <chrono>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/mman.h>
#include <unistd.h>
#include <vector>
#define INPUT_FILE "input.csv"
#define OUT_FILE_PATH "output.dat"
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

StockTick getNextStockTick(std::fstream &stock_data_stream) {
  StockTick minute_stock_tick;
  std::string minute_tick_input;
  if (!stock_data_stream.good()) {
    std::cout << "There is an error reading file stream"
              << "\n";
    return minute_stock_tick;
  }
  std::getline(stock_data_stream, minute_tick_input);
  // create a string stream to split on the basis of ','
  std::istringstream string_stream(minute_tick_input);
  // read all fields and push into a vector
  std::string field;
  std::vector<std::string> fields;
  while (std::getline(string_stream, field, ',')) {
    fields.push_back(field);
  }
  // verify if there are total 60 dimention read in vector
  if (fields.size() != 60) {
    std::cout << "Error in fields where it's not correct " << fields.size()
              << "\n";
    for (auto &incoming : fields) {
      std::cout << incoming << "\n";
    }
    std::cout << "<------------------------------------------>"
              << "\n";
    return minute_stock_tick;
  }
  std::istringstream tick_value_str(fields[0]);
  std::tm tm = {};
  tick_value_str >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
  minute_stock_tick.date =
      std::chrono::system_clock::from_time_t(std::mktime(&tm));
  minute_stock_tick.close = std::stod(fields[1]);
  minute_stock_tick.high = std::stod(fields[2]);
  minute_stock_tick.low = std::stod(fields[3]);
  minute_stock_tick.open = std::stod(fields[4]);
  minute_stock_tick.volume = std::stod(fields[5]);
  minute_stock_tick.sma5 = std::stod(fields[6]);
  minute_stock_tick.sma10 = std::stod(fields[7]);
  minute_stock_tick.sma15 = std::stod(fields[8]);
  minute_stock_tick.sma20 = std::stod(fields[9]);
  minute_stock_tick.ema5 = std::stod(fields[10]);
  minute_stock_tick.ema10 = std::stod(fields[11]);
  minute_stock_tick.ema15 = std::stod(fields[12]);
  minute_stock_tick.ema20 = std::stod(fields[13]);
  minute_stock_tick.upperband = std::stod(fields[14]);
  minute_stock_tick.middleband = std::stod(fields[15]);
  minute_stock_tick.lowerband = std::stod(fields[16]);
  minute_stock_tick.HT_TRENDLINE = std::stod(fields[17]);
  minute_stock_tick.KAMA10 = std::stod(fields[18]);
  minute_stock_tick.KAMA20 = std::stod(fields[19]);
  minute_stock_tick.KAMA30 = std::stod(fields[20]);
  minute_stock_tick.SAR = std::stod(fields[21]);
  minute_stock_tick.TRIMA5 = std::stod(fields[22]);
  minute_stock_tick.TRIMA10 = std::stod(fields[23]);
  minute_stock_tick.TRIMA20 = std::stod(fields[24]);
  minute_stock_tick.ADX5 = std::stod(fields[25]);
  minute_stock_tick.ADX10 = std::stod(fields[26]);
  minute_stock_tick.ADX20 = std::stod(fields[27]);
  minute_stock_tick.APO = std::stod(fields[28]);
  minute_stock_tick.CCI5 = std::stod(fields[29]);
  minute_stock_tick.CCI10 = std::stod(fields[30]);
  minute_stock_tick.CCI15 = std::stod(fields[31]);
  minute_stock_tick.macd510 = std::stod(fields[32]);
  minute_stock_tick.macd520 = std::stod(fields[33]);
  minute_stock_tick.macd1020 = std::stod(fields[34]);
  minute_stock_tick.macd1520 = std::stod(fields[35]);
  minute_stock_tick.macd1226 = std::stod(fields[36]);
  minute_stock_tick.MFI = std::stod(fields[37]);
  minute_stock_tick.MOM10 = std::stod(fields[38]);
  minute_stock_tick.MOM15 = std::stod(fields[39]);
  minute_stock_tick.MOM20 = std::stod(fields[40]);
  minute_stock_tick.ROC5 = std::stod(fields[41]);
  minute_stock_tick.ROC10 = std::stod(fields[42]);
  minute_stock_tick.ROC20 = std::stod(fields[43]);
  minute_stock_tick.PPO = std::stod(fields[44]);
  minute_stock_tick.RSI14 = std::stod(fields[45]);
  minute_stock_tick.RSI8 = std::stod(fields[46]);
  minute_stock_tick.slowk = std::stod(fields[47]);
  minute_stock_tick.slowd = std::stod(fields[48]);
  minute_stock_tick.fastk = std::stod(fields[49]);
  minute_stock_tick.fastd = std::stod(fields[50]);
  minute_stock_tick.fastksr = std::stod(fields[51]);
  minute_stock_tick.fastdsr = std::stod(fields[52]);
  minute_stock_tick.ULTOSC = std::stod(fields[53]);
  minute_stock_tick.WILLR = std::stod(fields[54]);
  minute_stock_tick.ATR = std::stod(fields[55]);
  minute_stock_tick.Trange = std::stod(fields[56]);
  minute_stock_tick.TYPPRICE = std::stod(fields[57]);
  minute_stock_tick.HT_DCPERIOD = std::stod(fields[58]);
  minute_stock_tick.BETA = std::stod(fields[59]);
  return minute_stock_tick;
}

int main() {
  std::fstream file;
  std::string ignore_header;
  file.open(INPUT_FILE, std::ios::in);
  std::getline(file, ignore_header);
  // StockTick firstMinute = getNextStockTick(file);
  // std::cout << std::fixed << std::setprecision(16);
  // std::cout << "First Minute Date: ";
  // std::time_t time = std::chrono::system_clock::to_time_t(firstMinute.date);
  // std::cout << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S")
  //           << "\n";
  StockTick sizeOfStockTick;
  size_t size = sizeof(StockTick[N]);
  int output = open(OUT_FILE_PATH, O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600);
  truncate(OUT_FILE_PATH, size);
  void *points = mmap(nullptr, size, PROT_WRITE, MAP_SHARED, output, 0);
  StockTick *holders = (StockTick *)points;
  for (size_t i = 0; i < N; i++) {
    holders[i] = getNextStockTick(file);
  }

  close(output);
  // dealocate point
  munmap(points, size);
  file.close();
  return 0;
}