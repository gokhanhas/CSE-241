/*
 * Gokhan Has - 161044067
*/

// This is the abstract class of LIST.

#ifndef  _GTU_LIST_H
#define  _GTU_LIST_H

#include <list>
#include "GTUcollection.h"


namespace MY_STL{

	template<typename E, typename container_type >
	class GTUlist : public Collection<E,container_type>{

		public:
			
			GTUlist() {/* Body Initialize EMpty */ }

			virtual myIterator<container_type> iterator() = 0;
			virtual void add(E e) = 0;
			virtual void addAll(Collection<E,container_type> * c) = 0;
			virtual void clear() = 0;
			virtual bool contains(E e) = 0;
			virtual bool containsAll(Collection<E,container_type> * c) = 0;
			virtual bool isEmpty() = 0;
			virtual void remove(E e) = 0;
			virtual void removeAll(Collection<E,container_type> * c) = 0;
			virtual void retainAll(Collection<E,container_type> * c) = 0;
			virtual int size() const = 0;
			
			virtual vector<E> getVector() = 0;

	};
}

#endif