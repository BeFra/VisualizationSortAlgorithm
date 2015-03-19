/*
 * HashDictionary.hpp
 *
 *  Created on: 17.03.2015
 *      Author: befrank
 */
#ifndef COLLECTION_HASHDICTIONARY_HPP_
#define COLLECTION_HASHDICTIONARY_HPP_

using namespace std;
#include <vector>
#include "Dictionary.hpp"

namespace collection {
	class HashDictionary: public Dictionary {
	private:
		struct Entry {
			enum State { EMPTY, USED, ERASED };
			State state = EMPTY;
			int key = 0;
			int value = 0;
		};
		int size_ = 0;
		vector<Entry> table;

		int getHash(const int key, const int count) const;
		int searchAdr(const int key) const;

	public:
		HashDictionary();
		~HashDictionary();

		void insert(const int key, const int value);
		bool contains(const int key);
		void remove(const int key);
		int getValue(const int key);

		int size();
		bool empty();
		void clear();
	};
}

#endif /* COLLECTION_HASHDICTIONARY_HPP_ */
