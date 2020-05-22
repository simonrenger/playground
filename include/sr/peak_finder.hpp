#ifndef SR_PEAK_HPP_INCLUDED
#define SR_PEAK_HPP_INCLUDED

#include <vector>

namespace sr {
	// This function will find a **peak** in a 1D array. In this case it will output the last peak.
	std::pair<int,int> find_peak_naive(std::vector<int>& input);
	std::pair<int,int> find_peak_divide_conquere(std::vector<int>& input);

}

#endif // SR_MAIN_HPP_INCLUDED