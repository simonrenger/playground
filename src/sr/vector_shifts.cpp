#include <sr/vector_shifts.hpp>

namespace sr {
	std::vector<int> rot_left(std::vector<int> a, int d) {
		auto shift{
			[](auto& vec) {
				int back{vec[0]};
				for (auto idx{0}; idx < vec.size(); ++idx) {
					if (idx != vec.size() - 1) {
						vec[idx] = vec[idx + 1];
					}
					else {
						vec[vec.size() - 1] = back;
					}
				}
			}
		};
		for (auto times{ 0 }; times < d; ++times) {
			shift(a);
		}
		return a;
	}
}