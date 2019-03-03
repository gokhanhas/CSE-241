/*
 * Gokhan Has - 161044067
*/

#ifndef _GTU_COLLECTION_H
#define _GTU_COLLECTION_H

#include "GTUiterator.h"
#include <vector>

using namespace std;

namespace MY_STL{
	
	template<typename E, typename container_type = std::vector <E>>
	class Collection{

		public:

			// Pure-virtual functions
			virtual myIterator<container_type> iterator() = 0;
			virtual void add(E e) = 0;
			virtual void addAll(Collection* c) = 0;
			virtual void clear() = 0;
			virtual bool contains(E e) = 0;
			virtual bool containsAll(Collection* c) = 0;
			virtual bool isEmpty() = 0;
			virtual void remove(E e) = 0;
			virtual void removeAll(Collection* c) = 0;
			virtual void retainAll(Collection* c) = 0;
			virtual int size() const = 0;
			
			virtual vector<E> getVector() = 0;
			// It is helper function the convert typename.
	};
}

#endif // _GTU_COLLECTION_H