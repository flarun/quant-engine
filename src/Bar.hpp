#pragma once      // only process it once regardless of repeats
#include <string> // std::string from std lib

// simple data bundle, members are public by default
struct Bar
{
  std::string date;
  double open;
  double high;
  double low;
  double close;
  long volume;
};