#ifndef INDEXABLESET_H_
#define INDEXABLESET_H_

#include <set>
#include <stdexcept>
#include <cmath>
#include <iostream>

template<typename T, typename COMPARE=std::less<T>>
class indexableSet
:public std::set<T,COMPARE>{
	using Base=std::set<T,COMPARE>;

public:
	using size_type=typename Base::size_type;
	using Base::set;

	T const & at(int index) const {
		if(this->size() < std::abs(index)) {
			throw std::out_of_range("Index out of range");
		}
		auto it = this->begin();
		if(index < 0) {
			index = this->size() + index;
		}
		std::advance(it, index);
		return *it;
	}

	T const & operator[](size_type index) const {
		return this->at(index);
	}

	const T & front() const {
		return this->at(0);
	}

	const T & back() const {
		return this->at(-1);
	}

};

struct caselessCompare{
	bool operator()(const std::string& left, const std::string& right){
		return std::lexicographical_compare(cbegin(left),
				cend(left), cbegin(right),
				cend(right),[](char const l, char const r) {
					return std::tolower(l) < std::tolower(r);
				});
	}
};
#endif /* INDEXABLESET_H_ */
