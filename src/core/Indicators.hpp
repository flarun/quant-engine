#pragma once
#include <vector>
#include <cmath>
#include "Bar.hpp"

inline double movingAverage(const std::vector<Bar> &bars, size_t i, size_t period)
{
  if (i + 1 < period)
    return NAN;

  double sum = 0.0;
  for (size_t j = i + 1 - period; j <= i; ++j)
  {
    sum += bars[j].close;
  }
  return sum / static_cast<double>(period);
}

inline double rollingStdDev(const std::vector<Bar> &bars, size_t i, size_t period)
{
  if (i + 1 < period)
    return NAN;

  double mean = movingAverage(bars, i, period);
  double sumSquaredDiff = 0.0;
  for (size_t j = i + 1 - period; j <= i; ++j)
  {
    double diff = bars[j].close - mean;
    sumSquaredDiff += diff * diff;
  }
  return std::sqrt(sumSquaredDiff / static_cast<double>(period));
}

inline double zScore(const std::vector<Bar> &bars, size_t i, size_t period)
{
  double mean = movingAverage(bars, i, period);
  double stddev = rollingStdDev(bars, i, period);

  if (stddev == 0.0)
    return 0.0; // avoid divide-by-zero on flat prices
  return (bars[i].close - mean) / stddev;
}