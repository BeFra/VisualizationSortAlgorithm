/*
 * Dictonary.hpp
 *
 *  Created on: 17.03.2015
 *      Author: befrank
 */

#ifndef COLLECTION_DICTIONARY_HPP_
#define COLLECTION_DICTIONARY_HPP_

#include <stdlib.h>

namespace collection {

	class Dictionary {
	public:
		Dictionary() { }
		virtual ~Dictionary() { }

		virtual void insert(const int key, const int value) = 0;
		virtual bool contains(const int key) = 0 ;
		virtual void remove(const int key) = 0;
		virtual int getValue(const int key) = 0;
		virtual int size() = 0;

	};
}

#endif /* COLLECTION_DICTIONARY_HPP_ */

