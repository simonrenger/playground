#include <sr/peak_finder.hpp>

std::pair<int, int> sr::find_peak_naive(std::vector<int>& input) {
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


std::pair<int, int> sr::find_peak_divide_conquere(std::vector<int>& input) {
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