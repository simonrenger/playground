#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"

#include <sr/vector_sort.hpp>


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