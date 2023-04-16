#include "catch2/catch_amalgamated.hpp"
#include "Nqueens.h"

TEST_CASE("Grid::get", "[Grid]")
{
    Grid<8> g;
    g.set(0, 0, true);
    REQUIRE(g.get(0, 0) == true);
}

TEST_CASE("Grid::is_valid", "[Grid]")
{
    Grid<8> g {3, 5, 7, 1, 6, 0, 2, 4};
    REQUIRE(g.is_valid() == true);

    Grid<8> g2 {3, 5, 7, 1, 6, 0, 2, 3};
    REQUIRE(g2.is_valid() == false);
}

TEST_CASE("Breadth-first search", "[bfs]")
{
    Grid<4> g1;
    BENCHMARK("4x4")
    {
        g1 = bfs<4>();
    };
    REQUIRE(g1.is_valid());
    REQUIRE(g1.not_null());
    REQUIRE(g1.queens() == 4);

    Grid<6> g2;
    BENCHMARK("6x6")
    {
        g2 = bfs<6>();
    };
    REQUIRE(g2.is_valid());
    REQUIRE(g2.not_null());
    REQUIRE(g2.queens() == 6);

    Grid<8> g3;
    BENCHMARK("8x8")
    {
        g3 = bfs<8>();
    };
    REQUIRE(g3.is_valid());
    REQUIRE(g3.not_null());
    REQUIRE(g3.queens() == 8);

    Grid<10> g4;
    BENCHMARK("10x10")
    {
        g4 = bfs<10>();
    };
    REQUIRE(g4.is_valid());
    REQUIRE(g4.not_null());
    REQUIRE(g4.queens() == 10);

    // Grid<12> g5;
    // BENCHMARK("12x12")
    // {
    //     g5 = bfs<12>();
    // };
    // REQUIRE(g5.is_valid());
    // REQUIRE(g5.not_null());

    // 12 runs in 6 seconds
    // 14 is too much for bfs
}

TEST_CASE("Depth-first search", "[dfs]")
{
    Grid<4> g1;
    BENCHMARK("4x4")
    {
        g1 = dfs<4>();
    };
    REQUIRE(g1.is_valid());
    REQUIRE(g1.not_null());
    REQUIRE(g1.queens() == 4);

    Grid<6> g2;
    BENCHMARK("6x6")
    {
        g2 = dfs<6>();
    };
    REQUIRE(g2.is_valid());
    REQUIRE(g2.not_null());
    REQUIRE(g2.queens() == 6);

    Grid<8> g3;
    BENCHMARK("8x8")
    {
        g3 = dfs<8>();
    };
    REQUIRE(g3.is_valid());
    REQUIRE(g3.not_null());
    REQUIRE(g3.queens() == 8);

    Grid<10> g4;
    BENCHMARK("10x10")
    {
        g4 = dfs<10>();
    };
    REQUIRE(g4.is_valid());
    REQUIRE(g4.not_null());
    REQUIRE(g4.queens() == 10);

    Grid<12> g5;
    BENCHMARK("12x12")
    {
        g5 = dfs<12>();
    };
    REQUIRE(g5.is_valid());
    REQUIRE(g5.not_null());
    REQUIRE(g5.queens() == 12);

    Grid<14> g6;
    BENCHMARK("14x14")
    {
        g6 = dfs<14>();
    };
    REQUIRE(g6.is_valid());
    REQUIRE(g6.not_null());
    REQUIRE(g6.queens() == 14);

    Grid<16> g7;
    BENCHMARK("16x16")
    {
        g7 = dfs<16>();
    };
    REQUIRE(g7.is_valid());
    REQUIRE(g7.not_null());
    REQUIRE(g7.queens() == 16);

    Grid<18> g8;
    BENCHMARK("18x18")
    {
        g8 = dfs<18>();
    };
    REQUIRE(g8.is_valid());
    REQUIRE(g8.not_null());
    REQUIRE(g8.queens() == 18);

    // Grid<20> g9;
    // BENCHMARK("20x20")
    // {
    //     g9 = dfs<20>();
    // };
    // REQUIRE(g9.is_valid());
    // REQUIRE(g9.not_null());
    // REQUIRE(g9.queens() == 20);

    // 20 runs in 4.6 seconds
    // 22 is too much for dfs
}

TEST_CASE("Iterative deepening search", "[ids]")
{
    Grid<4> g1;
    BENCHMARK("4x4")
    {
        g1 = ids<4>();
    };
    REQUIRE(g1.is_valid());
    REQUIRE(g1.not_null());
    REQUIRE(g1.queens() == 4);

    Grid<6> g2;
    BENCHMARK("6x6")
    {
        g2 = ids<6>();
    };
    REQUIRE(g2.is_valid());
    REQUIRE(g2.not_null());
    REQUIRE(g2.queens() == 6);

    Grid<8> g3;
    BENCHMARK("8x8")
    {
        g3 = ids<8>();
    };
    REQUIRE(g3.is_valid());
    REQUIRE(g3.not_null());
    REQUIRE(g3.queens() == 8);

    Grid<10> g4;
    BENCHMARK("10x10")
    {
        g4 = ids<10>();
    };
    REQUIRE(g4.is_valid());
    REQUIRE(g4.not_null());
    REQUIRE(g4.queens() == 10);

    // Grid<12> g5;
    // BENCHMARK("12x12")
    // {
    //     g5 = ids<12>();
    // };
    // REQUIRE(g5.is_valid());
    // REQUIRE(g5.not_null());
    // REQUIRE(g5.queens() == 12);

    // 12 runs in 26 seconds
    // 14 is too much for ids
}

TEST_CASE("Genetic algorithm", "[genetic]")
{
    Grid<4> g1;
    BENCHMARK("4x4")
    {
        g1 = genetic<4>();
    };
    REQUIRE(g1.is_valid());
    REQUIRE(g1.not_null());
    REQUIRE(g1.queens() == 4);

    Grid<6> g2;
    BENCHMARK("6x6")
    {
        g2 = genetic<6>();
    };
    REQUIRE(g2.is_valid());
    REQUIRE(g2.not_null());
    REQUIRE(g2.queens() == 6);

    Grid<8> g3;
    BENCHMARK("8x8")
    {
        g3 = genetic<8>();
    };
    REQUIRE(g3.is_valid());
    REQUIRE(g3.not_null());
    REQUIRE(g3.queens() == 8);

    Grid<10> g4;
    BENCHMARK("10x10")
    {
        g4 = genetic<10>();
    };
    REQUIRE(g4.is_valid());
    REQUIRE(g4.not_null());
    REQUIRE(g4.queens() == 10);
    // 10 runs in 6 seconds
}

TEST_CASE("Simulated annealing", "[annealing]")
{
    Grid<4> g1;
    BENCHMARK("4x4")
    {
        g1 = annealing<4>();
    };
    REQUIRE(g1.is_valid());
    REQUIRE(g1.not_null());
    REQUIRE(g1.queens() == 4);

    Grid<6> g2;
    BENCHMARK("6x6")
    {
        g2 = annealing<6>();
    };
    REQUIRE(g2.is_valid());
    REQUIRE(g2.not_null());
    REQUIRE(g2.queens() == 6);

    Grid<8> g3;
    BENCHMARK("8x8")
    {
        g3 = annealing<8>();
    };
    REQUIRE(g3.is_valid());
    REQUIRE(g3.not_null());
    REQUIRE(g3.queens() == 8);

    Grid<16> g4;
    BENCHMARK("16x16")
    {
        g4 = annealing<16>();
    };
    REQUIRE(g4.is_valid());
    REQUIRE(g4.not_null());
    REQUIRE(g4.queens() == 16);

    Grid<32> g5;
    BENCHMARK("32x32")
    {
        g5 = annealing<32>();
    };
    REQUIRE(g5.is_valid());
    REQUIRE(g5.not_null());
    REQUIRE(g5.queens() == 32);

    Grid<64> g6;
    BENCHMARK("64x64")
    {
        g6 = annealing<64>();
    };
    REQUIRE(g6.is_valid());
    REQUIRE(g6.not_null());
    REQUIRE(g6.queens() == 64);

    Grid<128> g7;
    BENCHMARK("128x128")
    {
        g7 = annealing<128>();
    };
    REQUIRE(g7.is_valid());
    REQUIRE(g7.not_null());
    REQUIRE(g7.queens() == 128);

    Grid<256> g8;
    BENCHMARK("256x256")
    {
        g8 = annealing<256>();
    };
    REQUIRE(g8.is_valid());
    REQUIRE(g8.not_null());
    REQUIRE(g8.queens() == 256);

    Grid<512> g9;
    BENCHMARK("512x512")
    {
        g9 = annealing<512>();
    };
    REQUIRE(g9.is_valid());
    REQUIRE(g9.not_null());
    REQUIRE(g9.queens() == 512);

    // Grid<1024> g10;
    // BENCHMARK("1024x1024")
    // {
    //     g10 = annealing<1024>();
    // };
    // REQUIRE(g10.is_valid());
    // REQUIRE(g10.not_null());
    // REQUIRE(g10.queens() == 1024);

    // 1024 runs in 3.75 seconds
}
