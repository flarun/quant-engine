#include "CsvLoader.hpp"
#include <fstream>
#include <sstream>
#include <charconv>
#include <iostream>

namespace
{
  double parseDouble(std::string_view sv)
  {
    double value = 0.0;
    std::from_chars(sv.data(), sv.data() + sv.size(), value);
    return value;
  }

  long parseLong(std::string_view sv)
  {
    long value = 0;
    std::from_chars(sv.data(), sv.data() + sv.size(), value);
    return value;
  }

  Bar parseLine(std::string_view line)
  {
    Bar bar;
    size_t pos = 0, next;

    next = line.find(',', pos);
    bar.date = std::string(line.substr(pos, next - pos));
    pos = next + 1;

    next = line.find(',', pos);
    bar.open = parseDouble(line.substr(pos, next - pos));
    pos = next + 1;

    next = line.find(',', pos);
    bar.high = parseDouble(line.substr(pos, next - pos));
    pos = next + 1;

    next = line.find(',', pos);
    bar.low = parseDouble(line.substr(pos, next - pos));
    pos = next + 1;

    next = line.find(',', pos);
    bar.close = parseDouble(line.substr(pos, next - pos));
    pos = next + 1;

    bar.volume = parseLong(line.substr(pos));

    return bar;
  }
}

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
  std::getline(file, line); // skip header

  while (std::getline(file, line))
  {
    if (line.empty())
      continue;
    bars.push_back(parseLine(line));
  }

  return bars;
}