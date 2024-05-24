#include <benchmark/benchmark.h>

static void BM_StringCreation(benchmark::State &state) {
  for (auto _ : state)
    std::string empty_string;
}
// Register the function as a benchmark
BENCHMARK(BM_StringCreation);

// Define another benchmark
static void BM_StringCopy(benchmark::State &state) {
  std::string x("Hello");
  std::string y, z;
  for (auto _ : state)
    y = x;
}
BENCHMARK(BM_StringCopy);

// Define another benchmark
static void BM_StringMove(benchmark::State &state) {
  constexpr int a = 10;
  constexpr int b = 10;
  int c;
  for (auto _ : state)
    c = a + b;
}
BENCHMARK(BM_StringMove);

BENCHMARK_MAIN();