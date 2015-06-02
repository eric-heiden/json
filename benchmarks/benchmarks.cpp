#define BENCHPRESS_CONFIG_MAIN

#include <fstream>
#include <benchpress.hpp>
#include <json.hpp>

BENCHMARK("parse jeopardy.json", [](benchpress::context* ctx)
{
    for (size_t i = 0; i < ctx->num_iterations(); ++i)
    {
        std::ifstream input_file("benchmarks/files/jeopardy/jeopardy.json");
        nlohmann::json j;
        j << input_file;
    }
})

BENCHMARK("parse canada.json", [](benchpress::context* ctx)
{
    for (size_t i = 0; i < ctx->num_iterations(); ++i)
    {
        std::ifstream input_file("benchmarks/files/nativejson-benchmark/canada.json");
        nlohmann::json j;
        j << input_file;
    }
})

BENCHMARK("parse citm_catalog.json", [](benchpress::context* ctx)
{
    for (size_t i = 0; i < ctx->num_iterations(); ++i)
    {
        std::ifstream input_file("benchmarks/files/nativejson-benchmark/citm_catalog.json");
        nlohmann::json j;
        j << input_file;
    }
})

BENCHMARK("parse twitter.json", [](benchpress::context* ctx)
{
    for (size_t i = 0; i < ctx->num_iterations(); ++i)
    {
        std::ifstream input_file("benchmarks/files/nativejson-benchmark/twitter.json");
        nlohmann::json j;
        j << input_file;
    }
})

BENCHMARK("dump jeopardy.json", [](benchpress::context* ctx)
{
    std::ifstream input_file("benchmarks/files/jeopardy/jeopardy.json");
    nlohmann::json j;
    j << input_file;

    ctx->reset_timer();
    for (size_t i = 0; i < ctx->num_iterations(); ++i)
    {
        j.dump();
    }
})

BENCHMARK("dump jeopardy.json with indent", [](benchpress::context* ctx)
{
    std::ifstream input_file("benchmarks/files/jeopardy/jeopardy.json");
    nlohmann::json j;
    j << input_file;

    ctx->reset_timer();
    for (size_t i = 0; i < ctx->num_iterations(); ++i)
    {
        j.dump(4);
    }
})
