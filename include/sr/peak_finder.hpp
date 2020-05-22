#ifndef SR_PEAK_HPP_INCLUDED
#define SR_PEAK_HPP_INCLUDED
#include <sr/utility.hpp>

#include <vector>

namespace sr {

	// This function will find a **peak** in a 1D array. In this case it will output the last peak.
	std::pair<int,int> find_peak_naive(const std::vector<int>& input);
	std::pair<int, int> find_peak_divide_conquere(const std::vector<int>& input);

	sr::triple<int, int, int> find_peak_naive(const std::vector<std::vector<int>>& input);
	sr::triple<int, int, int> find_peak_divide_conquere(const std::vector<std::vector<int>>& input);
}

#endif // SR_MAIN_HPP_INCLUDED