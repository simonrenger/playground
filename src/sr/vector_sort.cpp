#include "sr/vector_sort.hpp"

namespace sr {
	void sort_zeros(std::vector<int>& input) {
		for(auto y {0}; y < input.size(); ++y){
			for (auto i{ 0 }; i < input.size(); ++i) {
				if (input[i] == 0 && i < input.size() - 1) {
					std::swap(input[i], input[y]);
				}
			}
		}
	}
}