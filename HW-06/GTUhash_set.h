/*
 * Gokhan Has - 161044067
*/

#ifndef _GTU_HASH_SET
#define _GTU_HASH_SET

#include <set>
#include "GTUset.h"


namespace MY_STL{

	template<typename E,typename container_type = std::set<E> >
	class GTUhash_set : public GTUset<E,container_type>{

		public:
			GTUhash_set() noexcept { /* Body Initialize Empty */}
			
			GTUhash_set(std::set<E> newContainer) noexcept {
				setContainer = newContainer;
				myIter.setDataIter(setContainer.begin());
			}
			
			myIterator<container_type> iterator() noexcept { 
				myIter.next();
				return myIter;
			}
			
			void add(E e) noexcept { 
				setContainer.insert(e);
			}
			
			void addAll(Collection<E,container_type>* c) noexcept { 

				vector <E> temp = c->getVector();

				for(int i=0;i<temp.size();++i){
					setContainer.insert(temp[i]);
				}
			}
			
			void clear() noexcept { 
				setContainer.clear();
			}
			
			bool contains(E e) noexcept { 

				for(auto i = setContainer.begin(); i!= setContainer.end() ; ++i){

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
				
				auto first = setContainer.begin();
				auto last = setContainer.end();

				while( first != last){
					if(*first == e)
						setContainer.erase(e);
					++first;
				}
			}
			
			void removeAll(Collection<E,container_type>* c) noexcept { 
				
				vector <E> temp = c->getVector();
				temp = sortingVector(temp);
				

				for(auto i=setContainer.begin(); i != setContainer.end(); ++i){
					for(int j=0; j<temp.size(); ++j){
						
						if(*i == temp[j]){
							this->remove(*i);
						}
					}
				}				
			}
			
			void retainAll(Collection<E,container_type>* c) noexcept { 
				
				vector <E> temp = c->getVector();
				temp = sortingVector(temp);
				container_type newContainer;	
			
				for(auto i=setContainer.begin(); i != setContainer.end(); ++i){
					for(int j=0; j<temp.size(); ++j){
						
						if(*i == temp[j]){
							newContainer.insert(*i);
						}
					}
				}

				setContainer = newContainer;
			}
			
			int size() const noexcept { 
				return setContainer.size();
			}

			void drawtest() throw() {

				try{
					if(this->size() == 0)
						throw(0);

					else{
						cout << endl;
						for(auto i=setContainer.begin(); i != setContainer.end(); ++i){
							cout << "$-> " << *(i) << endl;
						}
						cout << endl;
					}
				} catch(int){
					cout << endl << "!! -> Empty  <- !! " << endl << endl;
				}
			}

			vector<E> getVector() noexcept {
				
				vector<E> newVector;

				for(auto i=setContainer.begin(); i!= setContainer.end(); ++i)
					newVector.push_back(*i);
				
				return newVector;
			}

		protected:
			std::set<E> setContainer;
			myIterator<container_type> myIter;
	};
}

#endif