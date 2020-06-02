#include <sr/peak_finder.hpp>

std::pair<int, int> sr::find_peak_naive(const std::vector<int>& input) {
	// temp vars:
	auto peakIndex{ 0 };
	auto peakValue{ 0 };
	for (auto idx{ 0 }; idx < input.size();++idx) {
		auto& value{ input[idx] };
		if (value > peakValue) {
			peakValue = value;
			peakIndex = idx;
		}
	}
	return { peakIndex,peakValue };
}


std::pair<int, int> sr::find_peak_divide_conquere(const std::vector<int>& input) {
	auto peakValue{ 0 };
	auto middle{ input.size() / 2 };
	auto peakIndex{ 0 };
	if (input.size() == 0) return { 0,0 };
	if (middle == 0 && input.size() > 0) return { 0,input[middle] };
	peakValue = input[middle];
	if (input[middle - 1] > input[middle] && input[middle + 1] < input[middle - 1]) {
		for (auto idx{ middle }; idx > 0; --idx) {
			if (input[idx] > peakValue) {
				peakValue = input[idx];
				peakIndex = idx;
			}
		}
	}
	else {
		for (auto idx{ middle }; idx < input.size(); ++idx) {
			if (input[idx] > peakValue) {
				peakValue = input[idx];
				peakIndex = idx;
			}
		}
	}
	return { peakIndex,peakValue };
}


// 2D Arrays:
// first version uses greedy acent algorithm
sr::triple<int, int, int> sr::find_peak_naive(const std::vector<std::vector<int>>& input) {
	auto compare{
		[&input](auto& func,int i, int j) -> sr::triple<int,int,int> {
			auto n{input.size()};
			if (i > 0 && input[i - 1][j] > input[i][j]) {
				return func(func, i - 1, j);
			}
			else if (i < n - 1 && input[i + 1][j] > input[i][j]) {
				return func(func, i + 1, j);
			}
			else if (j > 0 && input[i][j - 1] > input[i][j]) {
				return func(func, i, j - 1);
			}
			else if (j < n - 1 && input[i][j + 1] > input[i][j]) { 
				return func(func, i, j + 1); 
			}
			else return { i,j,input[i][j] };
		}
	};
	return compare(compare, 0, 0);
}

// makes use of binary search
// pure implemetaion does not work... why ... explain in see presentation
sr::triple<int, int, int> sr::find_peak_divide_conquere(const std::vector<std::vector<int>>& input) {
	return {};
}