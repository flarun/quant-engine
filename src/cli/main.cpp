#include <iostream>
#include <string>
#include "CsvLoader.hpp"
#include "Indicators.hpp" // inline movingAverage

int main()
{
  std::string path = std::string(PROJECT_SOURCE_DIR) + "/data/sample.csv";
  std::vector<Bar> bars = loadBars(path);

  std::cout << "Loaded " << bars.size() << " bars.\n\n";
  for (const auto &bar : bars)
  {
    std::cout << bar.date << " | close: " << bar.close
              << " | volume: " << bar.volume << "\n";
  }

  std::cout << "\n--- 3-day moving average ---\n";
  for (size_t i = 0; i < bars.size(); ++i)
  {
    double ma = movingAverage(bars, i, 3);
    std::cout << bars[i].date << " | MA(3): " << ma << "\n";
  }

  std::cout << "\n--- 3-day z-score ---\n";
  for (size_t i = 0; i < bars.size(); ++i)
  {
    double z = zScore(bars, i, 3);
    std::cout << bars[i].date << " | z-score: " << z << "\n";
  }

  return 0;
}