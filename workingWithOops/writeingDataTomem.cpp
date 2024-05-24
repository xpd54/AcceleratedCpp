#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct StockData {
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

StockData ParseNextStock(std::ifstream &stock_indata_file) {
  StockData stock;
  std::string line;
  std::getline(stock_indata_file, line);

  if (!stock_indata_file.good()) {
    return stock; // Return default-initialized StockData if the file has ended
  }

  std::stringstream ss(line);
  std::string field;
  std::vector<std::string> fields;

  while (std::getline(ss, field, ',')) {
    fields.push_back(field);
  }

  if (fields.size() != 59) {
    std::cerr << "Unexpected number of fields in the CSV line: "
              << fields.size() << std::endl;
    return stock; // Return default-initialized StockData if the line has an
                  // unexpected format
  }

  stock.date = std::chrono::system_clock::now(); // Assuming the date is in the
                                                 // first column
  stock.close = std::stod(fields[1]);
  stock.high = std::stod(fields[2]);
  stock.low = std::stod(fields[3]);
  stock.open = std::stod(fields[4]);
  stock.volume = std::stod(fields[5]);
  stock.sma5 = std::stod(fields[6]);
  stock.sma10 = std::stod(fields[7]);
  stock.sma15 = std::stod(fields[8]);
  stock.sma20 = std::stod(fields[9]);
  stock.ema5 = std::stod(fields[10]);
  stock.ema10 = std::stod(fields[11]);
  stock.ema15 = std::stod(fields[12]);
  stock.ema20 = std::stod(fields[13]);
  stock.upperband = std::stod(fields[14]);
  stock.middleband = std::stod(fields[15]);
  stock.lowerband = std::stod(fields[16]);
  stock.HT_TRENDLINE = std::stod(fields[17]);
  stock.KAMA10 = std::stod(fields[18]);
  stock.KAMA20 = std::stod(fields[19]);
  stock.KAMA30 = std::stod(fields[20]);
  stock.SAR = std::stod(fields[21]);
  stock.TRIMA5 = std::stod(fields[22]);
  stock.TRIMA10 = std::stod(fields[23]);
  stock.TRIMA20 = std::stod(fields[24]);
  stock.ADX5 = std::stod(fields[25]);
  stock.ADX10 = std::stod(fields[26]);
  stock.ADX20 = std::stod(fields[27]);
  stock.APO = std::stod(fields[28]);
  stock.CCI5 = std::stod(fields[29]);
  stock.CCI10 = std::stod(fields[30]);
  stock.CCI15 = std::stod(fields[31]);
  stock.macd510 = std::stod(fields[32]);
  stock.macd520 = std::stod(fields[33]);
  stock.macd1020 = std::stod(fields[34]);
  stock.macd1520 = std::stod(fields[35]);
  stock.macd1226 = std::stod(fields[36]);
  stock.MFI = std::stod(fields[37]);
  stock.MOM10 = std::stod(fields[38]);
  stock.MOM15 = std::stod(fields[39]);
  stock.MOM20 = std::stod(fields[40]);
  stock.ROC5 = std::stod(fields[41]);
  stock.ROC10 = std::stod(fields[42]);
  stock.ROC20 = std::stod(fields[43]);
  stock.PPO = std::stod(fields[44]);
  stock.RSI14 = std::stod(fields[45]);
  stock.RSI8 = std::stod(fields[46]);
  stock.slowk = std::stod(fields[47]);
  stock.slowd = std::stod(fields[48]);
  stock.fastk = std::stod(fields[49]);
  stock.fastd = std::stod(fields[50]);
  stock.fastksr = std::stod(fields[51]);
  stock.fastdsr = std::stod(fields[52]);
  stock.ULTOSC = std::stod(fields[53]);
  stock.WILLR = std::stod(fields[54]);
  stock.ATR = std::stod(fields[55]);
  stock.Trange = std::stod(fields[56]);
  stock.TYPPRICE = std::stod(fields[57]);
  stock.HT_DCPERIOD = std::stod(fields[58]);
  stock.BETA = std::stod(fields[59]);

  return stock;
}