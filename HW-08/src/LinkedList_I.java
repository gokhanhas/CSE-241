/*
 * Gokhan Has - 161044067
 */
/**
 * 
 * @author Gokhan
 
 * @param <E> int or string.
 */
public class LinkedList_I<E> implements List_I<E>, Queue_I<E> {

	private E[] arrayLinkedList;
	private char typeLinkedList;
	
	public LinkedList_I() {
		arrayLinkedList = (E[]) new Integer[1];
		typeLinkedList = 'i';
	}
	
	public LinkedList_I(E[] otherArray) throws Exception {
		
		
		if(otherArray == null)
			throw new Exception();
		
		else if(otherArray.getClass().getName() == "[Ljava.lang.Integer;") {
			
			arrayLinkedList = (E[]) new Integer[1];
			arrayLinkedList[0] = otherArray[0];
			typeLinkedList= 'i';
			for(int i=1; i<otherArray.length; ++i)
				this.add(otherArray[i]);
			
		}
		
		else if(otherArray.getClass().getName() == "[Ljava.lang.String;") {
			arrayLinkedList = (E[]) new String[1];
			arrayLinkedList[0] = otherArray[0];
			typeLinkedList = 's';
			for(int i=1; i<otherArray.length; ++i)
				this.add(otherArray[i]);
		}
	}
	
	@Override
	public Iterator_I<E> iterator() throws Exception {
		Iterator_I<E> temp = new Iterator_I<E>(arrayLinkedList);
		return temp;
	}

	@Override
	public void add(E element) {
		if(typeLinkedList == 'i') {
			
			int size = arrayLinkedList.length;
			Integer[] tempInt = new Integer[arrayLinkedList.length+1];
			System.arraycopy(arrayLinkedList, 0, tempInt, 0, arrayLinkedList.length);

			arrayLinkedList = (E[]) new Integer[size+1];
			System.arraycopy(tempInt, 0, arrayLinkedList, 0, tempInt.length);
			arrayLinkedList[arrayLinkedList.length-1] = element;
		
		}
		
		else if(typeLinkedList == 's') {
			
			int size = arrayLinkedList.length;
			String[] tempString = new String[arrayLinkedList.length+1];
			System.arraycopy(arrayLinkedList, 0, tempString, 0, arrayLinkedList.length);

			arrayLinkedList = (E[]) new String[size+1];
			System.arraycopy(tempString, 0, arrayLinkedList, 0, tempString.length);
			arrayLinkedList[arrayLinkedList.length-1] = element;
		
		}
	}

	@Override
	public void addAll(Collection_I<E> c) {
		int collectionSize = c.size();
		for(int i=0;i<collectionSize;++i) {
			this.add(c.getJavaArray()[i]);
		}	
	}

	@Override
	public void clear() {
		arrayLinkedList = null;
	}

	@Override
	public boolean contains(E element) {
		for(int i=0;i<arrayLinkedList.length;++i) {

			if(arrayLinkedList[i].equals(element)) {
				return true;
			}
		}
		return false;
	}

	@Override
	public boolean containsAll(Collection_I<E> c) {
		int size1 = this.size();
		int size2 = c.size();

		if(size1 != size2)
			return false;
		
		int control=0;
		for(int i=0;i<this.size();++i){
			if(arrayLinkedList[i] != c.getJavaArray()[i])
				control++;
		}

		if(control == 0)
			return true;
		return false;
	}

	@Override
	public boolean isEmpty() {
		if(arrayLinkedList.length == 0)
			return true;
		return false;
	}

	@Override
	public void remove(E element) {
		int deleted = 0;
		for(int z=0;z<arrayLinkedList.length;++z) {
			if(arrayLinkedList[z].equals(element))
				deleted++;
		}
		
		if(typeLinkedList == 'i') {
			
			Integer[] tempInt = new Integer[arrayLinkedList.length - deleted];
			
			int index=0;
			for(int k=0;k<arrayLinkedList.length;++k) {
				if(arrayLinkedList[k].equals(element)) {
					// doing nothing ...
				}
				else {
					tempInt[index] = new Integer((Integer) arrayLinkedList[k]);
					index++;
				}
			}
			
			arrayLinkedList = (E[]) new Integer[arrayLinkedList.length-deleted]; 
			arrayLinkedList = (E[]) tempInt.clone();
		}
		
		else if(typeLinkedList == 's') {
			
			String[] tempString = new String[arrayLinkedList.length - 1];
			
			int index=0;
			for(int k=0;k<arrayLinkedList.length;++k) {
				if(arrayLinkedList[k].equals(element)) {
					// doing nothing ...
				}
				else {
					tempString[index] = new String((String) arrayLinkedList[k]);
					index++;
				}
			}
			
			arrayLinkedList = (E[]) new String[arrayLinkedList.length-1]; 
			arrayLinkedList = (E[]) tempString.clone();
		}
		
	}

	@Override
	public void removeAll(Collection_I<E> c) {
		int sizeC = c.size();
		
		for(int i=0;i<arrayLinkedList.length;++i) {
			for(int j=0;j<sizeC;++j) {
				
				if(arrayLinkedList[i].equals(c.getJavaArray()[j])) {
					this.remove(arrayLinkedList[i]);
				}
			}
		}
		
	}

	@Override
	public void retainAll(Collection_I<E> c) {	
		int control = 0;
		for(int i=0;i<arrayLinkedList.length;++i) {			
			control = 0;
			for(int j=0;j<c.size();++j) {
				
				if(arrayLinkedList[i].equals(c.getJavaArray()[j])) {
					control = 1;
				}
			}
			if(control == 0)
				this.remove(arrayLinkedList[i]);	
		}
		
	}

	@Override
	public int size() {
		return arrayLinkedList.length;
	}

	@Override
	public E[] getJavaArray() {
		return arrayLinkedList;
	}

	@Override
	public E element() {
		return arrayLinkedList[0];
	}

	@Override
	public void offer(E element) {
		if(typeLinkedList == 'i') {
			
			int size = arrayLinkedList.length;
			Integer[] tempInt = new Integer[arrayLinkedList.length+1];
			System.arraycopy(arrayLinkedList, 0, tempInt, 0, arrayLinkedList.length);

			arrayLinkedList = (E[]) new Integer[size+1];
			System.arraycopy(tempInt, 0, arrayLinkedList, 0, tempInt.length);
			arrayLinkedList[arrayLinkedList.length-1] = element;
		
		}
		
		else if(typeLinkedList == 's') {
			
			int size = arrayLinkedList.length;
			String[] tempString = new String[arrayLinkedList.length+1];
			System.arraycopy(arrayLinkedList, 0, tempString, 0, arrayLinkedList.length);

			arrayLinkedList = (E[]) new String[size+1];
			System.arraycopy(tempString, 0, arrayLinkedList, 0, tempString.length);
			arrayLinkedList[arrayLinkedList.length-1] = element;
		}
		
	}

	@Override
	public E pool() throws Exception {
		
		E temp = null;
		if(arrayLinkedList == null) 
			throw new Exception();
		else if(typeLinkedList == 'i')
			temp = (E) new Integer((Integer) arrayLinkedList[0]);
		else if(typeLinkedList == 's')
			temp = (E) new String((String) arrayLinkedList[0]);
		
		this.remove(arrayLinkedList[0]);
		return temp;
	}	
	
	public void printArray() {
		System.out.println("\n----- Printing LinkedList -----");
		for(int i=0;i<arrayLinkedList.length;++i)
			System.out.println("Index : " + i + " Value : " + arrayLinkedList[i]);
	}
	
}
