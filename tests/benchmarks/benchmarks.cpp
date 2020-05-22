#include <benchmark/benchmark.h>

#include <sr/peak_finder.hpp>
#include <random>

static std::default_random_engine generator{};

std::vector<int> generate_random_vector(int min,int max){
    std::uniform_int_distribution<int> distribution(min, max);
    auto result{ std::vector<int>{} };
    result.reserve(max);
    for (auto idx{0};idx <= max;++idx){
    result.push_back(distribution(generator));
    }
    return result;
}

static std::vector<int> data_100{generate_random_vector(0, 100)};
static std::vector<int> data_1000{generate_random_vector(0, 1000)};
static std::vector<int> data_10000{generate_random_vector(0, 10000)};
static std::vector<int> data_100000{generate_random_vector(0, 100000)};

static void BM_find_peak_divide_conquere_100(benchmark::State& state) {
    for (auto _ : state)
        auto peak{ sr::find_peak_divide_conquere(data_100) };
}
// Register the function as a benchmark

static void BM_find_peak_divide_conquere_1000(benchmark::State& state) {
    for (auto _ : state)
        auto peak{ sr::find_peak_divide_conquere(data_1000) };
}


static void BM_find_peak_divide_conquere_10000(benchmark::State& state) {
    for (auto _ : state)
        auto peak{ sr::find_peak_divide_conquere(data_10000) };
}


static void BM_find_peak_divide_conquere_100000(benchmark::State& state) {
    for (auto _ : state)
        auto peak{ sr::find_peak_divide_conquere(data_100000) };
}

static void BM_peak_finder_naive_100(benchmark::State& state) {
    for (auto _ : state)
        auto peak{ sr::find_peak_naive(data_100) };
}
// Register the function as a benchmark

static void BM_peak_finder_naive_1000(benchmark::State& state) {
    for (auto _ : state)
        auto peak{ sr::find_peak_naive(data_1000) };
}


static void BM_peak_finder_naive_10000(benchmark::State& state) {
    for (auto _ : state)
        auto peak{ sr::find_peak_naive(data_10000) };
}


static void BM_peak_finder_naive_100000(benchmark::State& state) {
    for (auto _ : state)
        auto peak{ sr::find_peak_naive(data_100000) };
}


BENCHMARK(BM_peak_finder_naive_100);
BENCHMARK(BM_peak_finder_naive_1000);
BENCHMARK(BM_peak_finder_naive_10000);
BENCHMARK(BM_peak_finder_naive_100000);
BENCHMARK(BM_find_peak_divide_conquere_100);
BENCHMARK(BM_find_peak_divide_conquere_1000);
BENCHMARK(BM_find_peak_divide_conquere_10000);
BENCHMARK(BM_find_peak_divide_conquere_100000);

BENCHMARK_MAIN();