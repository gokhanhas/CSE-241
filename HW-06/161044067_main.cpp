/*
 * Gokhan Has - 161044067
*/

#include "GTUiterator.h"
#include "GTUhash_set.h"
#include "GTUlinked_list.h"
#include "GTUarray_list.h"

using namespace MY_STL;

int main(){

	
	cout << endl << "********** Testing myIterator Functions **********" << endl << endl;

		vector<char> deneme;
		deneme.push_back('a');
		deneme.push_back('b');
		deneme.push_back('c');
		deneme.push_back('d');
		deneme.push_back('e');

		myIterator< vector<char> > testIterator(&deneme);
		cout << "-> vector element is     : a,b,c,d,e " << endl;
		cout << "-> myIterators begin 	 : " << *(testIterator.getData()) << endl;
		cout << "-> Test hasNext function : " << testIterator.hasNext() << endl;
		(testIterator.next());
		(testIterator.next());
		(testIterator.next());
		cout << "-> After 3 times next function and new begin : " << *(testIterator.getData()) << endl;
		(testIterator.remove());
		cout << "-> Test remove functions (return last element and remove) : " << *(testIterator.remove()) << endl;
		cout << "-> Test hasNext function : " << testIterator.hasNext() << endl;

	cout << endl << "********** Ending Test myIterator Functions **********" << endl << endl;
	
	cout << endl << "********** Testing HashSet Functions **********" << endl << endl;

		GTUhash_set <int> hashDeneme;
		GTUhash_set <int> hashDeneme2;
		GTUset <int> * pointerSet;

		pointerSet = &hashDeneme2;
		hashDeneme2.add(265);
		hashDeneme2.add(451);
		hashDeneme2.add(21);
		hashDeneme2.add(64);
		pointerSet->add(5);
		pointerSet->add(1);
		
		cout << "-> Testing add Function : " << endl;
		hashDeneme.add(6);
		hashDeneme.add(7);
		hashDeneme.add(9);
		hashDeneme.add(9);
		hashDeneme.add(45);
		hashDeneme.add(33);
		hashDeneme.add(116);
		hashDeneme.drawtest();
		
		cout << "-> Testing isEmpty : " << hashDeneme.isEmpty() << endl;
		
		cout << "-> Testing contains(9) : " << hashDeneme.contains(6) << endl;
		
		cout << "-> Testing size : " << hashDeneme.size() << endl;
		
		cout << "-> Testing addAll(Collection c) : " << endl;
			hashDeneme.addAll(&hashDeneme2);
			hashDeneme.drawtest();
		
		cout << "-> Testing containsAll(Collection c) hashDeneme.containsAll(pointerSet) : " << hashDeneme.containsAll(pointerSet) << endl;
		// yukarıda 0 sonucu verecektir.Cunku &hashDeneme2(pointerSet),hashDeneme ile birebir aynı degildir.Birebir ayni oldugunda 1 sonucu verilir.
		
		cout << "-> Testing remove(1) : ";
			hashDeneme.remove(1); // hashDenemeden artık 1 silindi...
			hashDeneme.drawtest();
		
		cout << "-> Testing retainAll(Collection c) : ";
			hashDeneme.retainAll(pointerSet);
			hashDeneme.drawtest();
		
		cout << "-> Testing removeAll(Collection c) : "; 
			hashDeneme.removeAll(pointerSet);
			hashDeneme.drawtest();

		cout << "-> Testing pointerSet->clear() == hashDeneme2.clear() (Because of same adress)";
			pointerSet->clear();
			hashDeneme2.drawtest();
		
	cout << endl << "********** Ending Test HashSet Functions **********" << endl << endl;

	cout << endl << "********** Testing ArrayList and LinkedList Functions **********" << endl << endl;

		GTUarray_list <double> arrayList;
		GTUlinked_list <double> linkedList;
		GTUarray_list <double> onlyTest;
		GTUlist <double,list<double>> * pointerList;

		//  ArrayList and LinkedList are based on GTUlist(abstract) class 
		// and their functions are the same.linkedist is based GTUqueue.h too
		// and new 4 functions.onlyTest is used in containsAll function.

		pointerList= &linkedList;
		
		cout << "-> Testing arrayList and linkedist add function (Note : linkedList add function come from GTUqueue.h): " << endl;
			arrayList.add(3.2);				linkedList.add(4.1);
			arrayList.add(1.7);  			linkedList.add(9.23);
			arrayList.add(6.7);				linkedList.add(11.1);
			arrayList.add(4.3);				linkedList.add(214.32);
											linkedList.add(4.1);
			cout << "arrayList : "; arrayList.drawtest();
			cout << "linkedList : "; linkedList.drawtest();

		onlyTest = arrayList; // It will be used containsAll function.

		cout << endl << "-> Testing isEmpty : " << endl;
			cout << "arrayList : " << arrayList.isEmpty() << endl << "linkedList : " << linkedList.isEmpty() << endl;

		cout << endl << "-> Testing arrayList.contains(1.7) and linkedList.contains(1500.0) : " << endl;
			cout << "arrayList : " << arrayList.contains(1.7) << endl << "linkedList : " << linkedList.contains(1500.0) << endl;

		cout << endl << "-> Testing arrayList and linkedList size function : " << endl;
			cout << "arrayList : " << arrayList.size() << endl << "linkedList : " << linkedList.size() << endl;

		
		cout << endl << "-> Testing containsAll arrayList.containsAll(&onlyTest) : " << endl;
			cout << "arrayList.containsAll(&onlyTest) : " << arrayList.containsAll(&onlyTest) << endl;
			// hashSet'ten farklı olarak birebir aynı iki collectionı kıyasladım ve 1 dondurdu.

		cout << endl << "-> Testing arrayList.addAll(pointerList) : " << endl;
			arrayList.addAll(pointerList);
			arrayList.drawtest(); cout << endl;

		cout << endl << "->Testing arrayList.remove(6.7) and linkedList.remove(9.23) : " << endl;
			arrayList.remove(6.7);
			linkedList.remove(9.23);
			cout << "arrayList : "; arrayList.drawtest(); // arraylist'in artık arraylist + linkedList toplamı oldugunu bir onceki fonk. dolayi dikkat ediniz.
			cout << "linkedList : "; linkedList.drawtest();

		cout << "-> Testing retainAll(Collection c) : ";
			arrayList.retainAll(pointerList); // pointerList linkedList'i tutuyor.
			arrayList.drawtest();

		cout << "-> Testing removeAll(Collection c) : ";
			arrayList.removeAll(pointerList); // Yukaridaki fonksiyondan sonra arrayList aslinda linkedList'in elemanlarina sahip oldu.
			arrayList.drawtest();				  // Dolayisiyla silindikten sonra arrayList bos kalacak.


		// simdi linkedListin GTUqueue'den aldigi fonk. test edilecektir.

		cout << endl << endl << "*** drawtesting linkedList ****";
			linkedList.drawtest();


		cout << endl << "-> Testing linkedList.element() function : " << endl;
			cout << "The head of this queue is : " << linkedList.element() << endl;

		cout << endl << "-> Testing linkedList.offer() function : " << endl;
			cout << "linkedList.offer(5.5) : ";
			linkedList.offer(5.5); 
			linkedList.drawtest();

		cout << endl << "-> Testing linkedList.poll() function : " << endl;
			cout << "return value : " << linkedList.poll();
			linkedList.drawtest();

		GTUlinked_list <char> testThrow;

		cout << endl << "-> Testing testThrow.poll() function : " << endl;
			testThrow.poll(); // poll fonksiyonundaki throw() test edilmistir.
			cout << endl;

	cout << endl << "********** Ending Test ArrayList and LinkedList Functions **********" << endl << endl;

	return 0;
}