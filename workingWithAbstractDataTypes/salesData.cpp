#include "salesData.h"
#include <iostream>
double Sales_data::avg_price() const {
  if (units_sold)
    return revenue / units_sold;
  else
    return 0;
}

Sales_data &Sales_data::combine(const Sales_data &rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

std::istream &read(std::istream &input_stream, Sales_data &item) {
  double price = 0;
  input_stream >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return input_stream;
}

std::ostream &print(std::ostream &output_stream, const Sales_data &item) {
  output_stream << item.isbn() << " " << item.units_sold << " " << item.revenue
                << " " << item.avg_price();
  return output_stream;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;
  sum.combine(rhs);
  return sum;
}