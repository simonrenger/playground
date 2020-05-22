#ifndef SR_Utility_HPP_INCLUDED
#define SR_Utility_HPP_INCLUDED

#include <vector>

namespace sr {
	template<typename A, typename B, typename C>
	struct triple {
		A first;
		B second;
		C third;
	};

	template<typename A, typename B, typename C>
	bool operator==(const triple<A, B, C>& left, const triple<A, B, C>& right) {
		return left.first == right.first && left.second == right.second && left.third == right.third;
	}
}


#endif // SR_MAIN_HPP_INCLUDED