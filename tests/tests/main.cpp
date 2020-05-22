#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"

#include <sr/vector_sort.hpp>
#include <sr/peak_finder.hpp>

#include <utility>


TEST_CASE("stort vector by zero", "[sort_zeros]") {
	std::vector<int> input{ 0,2,0,1,0,2 };
	std::vector<int> input2{ 1,2,0,1,0,2 };
	std::vector<int> input3{ 0,0,0,1,0,2 };
	std::vector<int> input4{ 0,0,0,1,1,2 };
	std::vector<int> res{ 2, 1, 2, 0, 0, 0 };
	sr::sort_zeros(input);
	REQUIRE(input == res);
	res = std::vector<int>{ 2,1,1,2,0,0 };
	sr::sort_zeros(input2);
	REQUIRE(input2 == res);
	res = std::vector<int>{ 1,2,0,0,0,0};
	sr::sort_zeros(input3);
	REQUIRE(input3 == res);
	res = std::vector<int>{ 1,1,2,0,0,0 };
	sr::sort_zeros(input4);
	REQUIRE(input4 == res);
}

TEST_CASE("find 1D peak") {
	std::vector<int> input{ 1,2,8,1,9,2 };
	auto pair{ std::pair<int,int>{4,9} };
	auto res{ sr::find_peak_naive(input) };
	auto res_dc{ sr::find_peak_divide_conquere(input) };
	REQUIRE(res == pair);
	pair = {4,9};
	REQUIRE(res_dc == pair);
	input = { 1,2,9,1,6,2 };
	res_dc = sr::find_peak_divide_conquere(input);
	pair = { 2,9 };
	REQUIRE(res_dc == pair);
	input = { 1,2,9,1,6,2,2,3,4,5,6,7,8,99 };
	res_dc = sr::find_peak_divide_conquere(input);
	pair = { 13,99 };
	REQUIRE(res_dc == pair);
	input = { 1,2,9,1,6,2,5,3,4,5,6,7,8,99 };
	res_dc = sr::find_peak_divide_conquere(input);
	pair = { 2,9 };
	REQUIRE(res_dc == pair);
	input = {};
	res_dc = sr::find_peak_divide_conquere(input);
	pair = { 0,0 };
	REQUIRE(res_dc == pair);
	input = {1};
	res_dc = sr::find_peak_divide_conquere(input);
	pair = { 0,1 };
	REQUIRE(res_dc == pair);
}
TEST_CASE("find 2D peak") {
	std::vector<std::vector<int>> input{ 
		{7,8,9,10},
		{14,13,12,11},
		{15,17,18,20}
	};
	auto pair{ sr::triple<int,int,int>{2,3,20} };
	auto res{ sr::find_peak_naive(input) };
	REQUIRE(res == pair);
}