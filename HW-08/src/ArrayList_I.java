/*
 * Gokhan Has - 161044067
 */

/**
 * 
 * @author Gokhan
 *
 * @param <E> int or string.
 */
public class ArrayList_I<E> implements List_I<E> {

	private E[] arrayArrayList;
	private char typeArrayList;
	
	
	public ArrayList_I() {
		arrayArrayList = null;
	}
	
	public ArrayList_I(E[] otherArray) throws Exception {
		
		if(otherArray == null)
			throw new Exception();
		
		else if(otherArray.getClass().getName() == "[Ljava.lang.Integer;") {
			
			arrayArrayList = (E[]) new Integer[1];
			arrayArrayList[0] = otherArray[0];
			typeArrayList= 'i';
			for(int i=1; i<otherArray.length; ++i)
				this.add(otherArray[i]);
			
		}
		
		else if(otherArray.getClass().getName() == "[Ljava.lang.String;") {
			arrayArrayList = (E[]) new String[1];
			arrayArrayList[0] = otherArray[0];
			typeArrayList= 's';
			for(int i=1; i<otherArray.length; ++i)
				this.add(otherArray[i]);
		}
	}
	
	@Override
	public Iterator_I<E> iterator() throws Exception {
		Iterator_I<E> temp = new Iterator_I<E>(arrayArrayList);
		return temp;
	}

	@Override
	public void add(E element) {
		if(typeArrayList == 'i') {
			
			int size = arrayArrayList.length;
			Integer[] tempInt = new Integer[arrayArrayList.length+1];
			System.arraycopy(arrayArrayList, 0, tempInt, 0, arrayArrayList.length);

			arrayArrayList = (E[]) new Integer[size+1];
			System.arraycopy(tempInt, 0, arrayArrayList, 0, tempInt.length);
			arrayArrayList[arrayArrayList.length-1] = element;
		
		}
		
		else if(typeArrayList == 's') {
			
			int size = arrayArrayList.length;
			String[] tempString = new String[arrayArrayList.length+1];
			System.arraycopy(arrayArrayList, 0, tempString, 0, arrayArrayList.length);

			arrayArrayList = (E[]) new String[size+1];
			System.arraycopy(tempString, 0, arrayArrayList, 0, tempString.length);
			arrayArrayList[arrayArrayList.length-1] = element;
		
		}	
	}

	@Override
	public void addAll(Collection_I<E> c) {
		int collectionSize = c.size();
		for(int i=0;i<collectionSize;++i) {
			this.add(((E)(c.getJavaArray()[i])));
		}	
	}

	@Override
	public void clear() {
		arrayArrayList = null;	
	}

	@Override
	public boolean contains(E element) {
		for(int i=0;i<arrayArrayList.length;++i) {

			if(arrayArrayList[i].equals(element)) {
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
			if(arrayArrayList[i] != c.getJavaArray()[i])
				control++;
		}

		if(control == 0)
			return true;
		return false;
	}

	@Override
	public boolean isEmpty() {
		if(arrayArrayList.length == 0)
			return true;
		return false;
	}

	@Override
	public void remove(E element) {
		
		int deleted = 0;
		for(int z=0;z<arrayArrayList.length;++z) {
			if(arrayArrayList[z].equals(element))
				deleted++;
		}
		
		if(typeArrayList == 'i') {
			
			Integer[] tempInt = new Integer[arrayArrayList.length - deleted];
			
			int index=0;
			for(int k=0;k<arrayArrayList.length;++k) {
				if(arrayArrayList[k].equals(element)) {
					// doing nothing ...
				}
				else {
					tempInt[index] = new Integer((Integer) arrayArrayList[k]);
					index++;
				}
			}
			
			arrayArrayList = (E[]) new Integer[arrayArrayList.length-deleted]; 
			arrayArrayList = (E[]) tempInt.clone();
		}
		
		else if(typeArrayList == 's') {
			
			String[] tempString = new String[arrayArrayList.length - 1];
			
			int index=0;
			for(int k=0;k<arrayArrayList.length;++k) {
				if(arrayArrayList[k].equals(element)) {
					// doing nothing ...
				}
				else {
					tempString[index] = new String((String) arrayArrayList[k]);
					index++;
				}
			}
			
			arrayArrayList = (E[]) new String[arrayArrayList.length-1]; 
			arrayArrayList = (E[]) tempString.clone();
		}
	}

	@Override
	public void removeAll(Collection_I<E> c) {
		int sizeC = c.size();
		
		for(int i=0;i<arrayArrayList.length;++i) {
			for(int j=0;j<sizeC;++j) {
				
				if(arrayArrayList[i].equals(c.getJavaArray()[j])) {
					this.remove(arrayArrayList[i]);
				}
			}
		}	
	}

	@Override
	public void retainAll(Collection_I<E> c) {		
		int control = 0;
		for(int i=0;i<arrayArrayList.length;++i) {			
			control = 0;
			for(int j=0;j<c.size();++j) {
				
				if(arrayArrayList[i].equals(c.getJavaArray()[j])) {
					control = 1;
				}
			}
			if(control == 0)
				this.remove(arrayArrayList[i]);	
		}	
		
	}

	@Override
	public int size() {
		return arrayArrayList.length;
	}

	public void printArray() {
		System.out.println("\n----- Printing ArrayList -----");
		for(int i=0;i<arrayArrayList.length;++i)
			System.out.println("Index : " + i + " Value : " + arrayArrayList[i]);
	}
	
	@Override
	public E[] getJavaArray() {
		return arrayArrayList;
	}		
}
