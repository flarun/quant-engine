#include <iostream>
#include <fstream> // file stream
#include <sstream> // string stream
#include <vector>
#include "Bar.hpp"

std::vector<Bar> loadBars(const std::string &path)
{
  std::vector<Bar> bars;
  std::ifstream file(path);

  if (!file.is_open())
  {
    std::cerr << "Could not open file: " << path << "\n";
    return bars;
  }

  std::string line;
  std::getline(file, line); // skip header row

  // seems inefficient as a way to process csv
  while (std::getline(file, line))
  {
    std::stringstream ss(line);
    std::string token;
    Bar bar;

    std::getline(ss, bar.date, ',');
    std::getline(ss, token, ',');
    bar.open = std::stod(token);
    std::getline(ss, token, ',');
    bar.high = std::stod(token);
    std::getline(ss, token, ',');
    bar.low = std::stod(token);
    std::getline(ss, token, ',');
    bar.close = std::stod(token);
    std::getline(ss, token, ',');
    bar.volume = std::stol(token);

    bars.push_back(bar);
  }

  return bars;
}

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

  return 0;
}