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


	void bubble_sort(std::vector<int>& arr) {
        bool swapped{};
        auto n{ arr.size() };
        for (auto i{ 0 }; i < n - 1; ++i)
        {
            swapped = false;
            for (auto j{ 0 }; j < n - i - 1; ++j)
            {
                if (arr[j] > arr[j + 1])
                {
                    std::swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (swapped == false){
                break;
            }
        }
	}
}