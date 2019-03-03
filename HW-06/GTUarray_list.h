/*
 * Gokhan Has - 161044067
*/

#ifndef _GTU_ARRAY_LIST
#define _GTU_ARRAY_LIST

#include "GTUlist.h"

namespace MY_STL{

	template<typename E,typename container_type = std::list<E>>
	class GTUarray_list : public GTUlist<E,container_type> {

		public:
			GTUarray_list() noexcept { /* Body Initialize Empty */}
			
			GTUarray_list(std::list<E> newContainer) noexcept {
				listContainer = newContainer;
				listContainer.sort();
				myIter.setDataIter(listContainer.begin());
			}
			
			myIterator<container_type> iterator() noexcept { 
				myIter.next();
				return myIter;
			}
			
			void add(E e) noexcept { 
				
				if(this->size() == 0){
					listContainer.insert(listContainer.begin(),e);
				}
				
				else{
					listContainer.insert(listContainer.end(),e);
					listContainer.sort();
				}
			}
			
			void addAll(Collection<E,container_type>* c) noexcept { 
				
				vector <E> temp;
				temp = c->getVector();
				for(int i=0;i<temp.size();++i){
					listContainer.insert(listContainer.end(),temp[i]);
				}
				listContainer.sort();	
			}
			
			void clear() noexcept { 
				listContainer.clear();
			}
			
			bool contains(E e) noexcept { 

				for(auto i = listContainer.begin(); i!= listContainer.end() ; ++i){

					if((*i) == e)
						return true;
				}
				return false;
			}
			
			bool containsAll(Collection<E,container_type>* c) noexcept { 
				
				int size1 = this->size();
				int size2 = (c->getVector()).size();

				if(size1 != size2)
					return false;
				
				vector <E> temp = c->getVector();
				temp = sortingVector(temp);
				
				vector <E> vector2 = this->getVector();
				vector2 = sortingVector(vector2);
				
				int control=0;
				for(int i=0;i<temp.size();++i){
					if(temp[i] != vector2[i])
						control++;
				}

				if(control == 0)
					return true;
				return false;
			}

			vector<E> sortingVector(vector<E>& vect) noexcept {
				
				E tmp;

			   	for(int i=0; i<vect.size(); i++){
			  	
			        for(int j=vect.size()-1 ; j>i;j--) {
				        
				        if(vect[j-1]>vect[j]){
				          // Buble Sort Algorithm...
				          tmp=vect[j-1];
				          vect[j-1]=vect[j];
				          vect[j]=tmp;
				        }
			      	}
			    }
			    return vect;
			}
			
			bool isEmpty() noexcept { 
				
				if( (this->size() == 0) )
					return true;
				return false;
			}
			
			void remove(E e) noexcept { 			
				
				auto first = listContainer.begin();
				auto last = listContainer.end();

				while( first != last){
					if(*first == e)
						first = listContainer.erase(first);
					else
						++first;
				}

				if(*last == e) // sonuna dongude bakilamadigi icin ayri bakmak gerekmistir.
					last = listContainer.erase(last);
			}
			
			void removeAll(Collection<E,container_type>* c) noexcept { 
				
				
				vector <E> temp = c->getVector();
				temp = sortingVector(temp);
				
				int control=0;
				for(auto i=listContainer.begin(); i != listContainer.end(); ++i){
					for(int j=0; j<temp.size(); ++j){
						
						if(*i == temp[j]){
							control=1;
							i = listContainer.erase(i);
						}
					}
					
					if(control == 1){
						control=0;
						--i;
					}
				}
				
			}
			
			void retainAll(Collection<E,container_type>* c) noexcept { 
				
				vector <E> temp = c->getVector();
				temp = sortingVector(temp);
				
				int control=0;
				for(auto i=listContainer.begin(); i != listContainer.end(); ++i){
					for(int j=0; j<temp.size(); ++j){
						
						if(*i == temp[j]){
							control=1;
						}
					}
					
					if(control == 0){
						i = listContainer.erase(i);
						--i;
					}
					else
						control = 0;
				}
			}
			
			int size() const noexcept { 
				return listContainer.size();
			}

			void drawtest() throw() {

				try{
					if(this->size() == 0)
						throw(0);

					else{
						cout << endl;
						for(auto i=listContainer.begin(); i != listContainer.end(); ++i){
							cout << "$-> " << *(i) << endl;
						}
						cout << endl;
					}
				} catch(int){
					cout << endl << "!! -> Empty <- !! " << endl << endl;
				}
			}


			vector<E> getVector() noexcept {
				
				vector<E> newVector;
				
				for(auto i=listContainer.begin(); i!= listContainer.end(); ++i)
					newVector.push_back(*i);
			
				return newVector;
			}

		protected:
			std::list<E> listContainer;
			myIterator<container_type> myIter;
	};
}

#endif