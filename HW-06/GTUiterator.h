/*
 * Gokhan Has - 161044067
*/

#ifndef _GTU_ITERATOR_H
#define _GTU_ITERATOR_H

#include <iostream>
#include <iterator>
using namespace std;

namespace MY_STL{

template<typename T>
class myIterator{

	public:

		//  http://www.cplusplus.com/reference/iterator/
		//  If we write own iterator, we can implement some
		// functions.Like some functions at the bottom.
		
		myIterator() noexcept : data(nullptr),dataIter(nullptr) {/* Body Itialize Empty */}
		
		myIterator(T * newData) noexcept : data(newData),dataIter(newData->begin()) {/* Body Initialize Empty */}


		void setDataIter(typename T::iterator iter) noexcept { dataIter = iter; }
		void setData(T* newData) noexcept { data = newData; }

		
		T& operator*() noexcept { 
			return *data;
		}

		T* operator->() noexcept {
			return data;
		} 
		
		bool hasNext() noexcept {

			auto firstData = dataIter;
			auto endData = data->end();
			int count = 0;
	
			while(firstData != endData){	
				count++; firstData++;
			}
			
			if(data->size()-count >= data->size() - 1)
				return false;
			return true;
		}

		typename T::iterator next() noexcept {
			
			dataIter++;
			return dataIter;
		}

		typename T::iterator remove() noexcept {
			
			dataIter = data->erase(dataIter);
			return dataIter;		
		}
	   
	   	typename T::iterator getData() noexcept { return dataIter; }

		typename T::iterator back() noexcept {
			dataIter--;
			return dataIter;
		}
		
		T getDataIter() noexcept { return dataIter;  }

		myIterator& operator ++ () noexcept{
			data++;
			return *this;
		} // I will use only prefix ++,so only implement this.

	protected:
		T* data;
		typename T::iterator dataIter;
   };

} // end MY_STL

#endif