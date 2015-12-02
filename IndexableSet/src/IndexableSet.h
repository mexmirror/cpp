#ifndef INDEXABLESET_H_
#define INDEXABLESET_H_

#include <set>
#include <stdexcept>
#include <cmath>

template<typename T, typename COMPARE=std::less<T>>
class indexableSet
:public std::set<T,COMPARE>{
	using Base=std::set<T,COMPARE>;

public:
	using size_type=typename Base::size_type;
	using Base::set;

	T const & at(size_type index) const {
		auto it = this->begin();
		std::advance(it, index);
		return *it;
	}

	T const & operator[](size_type index) const {
		if(this->size() < std::abs(index)) {
			throw std::out_of_range("Out of range index");
		}
		if(index < 0) {
			return this->at(this->size() + index);
		}
		return this->at(index);
	}

	const T & front() const {
		return this->at(0);
	}

	const T & back() const {
		return this->at(-1);
	}

};




#endif /* INDEXABLESET_H_ */
