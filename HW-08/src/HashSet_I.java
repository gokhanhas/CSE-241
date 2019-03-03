/*
 * Gokhan Has - 161044067
 */
/**
 * 
 * @author Gokhan
 *
 * @param <E> is int or string.
 */
public class HashSet_I<E> implements Set_I<E> {

	private E[] arrayHashSet;
	private char typeHashSet;
	
	public HashSet_I() {
		arrayHashSet = (E[]) new Integer[1];
		typeHashSet = 'i';
	}
	
	
	public HashSet_I(E[] otherArray) throws Exception {
		
		if(otherArray == null)
			throw new Exception();
		
		else if(otherArray.getClass().getName() == "[Ljava.lang.Integer;") {
			
			arrayHashSet = (E[]) new Integer[1];
			arrayHashSet[0] = otherArray[0];
			typeHashSet= 'i';
			for(int i=1; i<otherArray.length; ++i)
				this.add(otherArray[i]);
			
		}
		
		else if(otherArray.getClass().getName() == "[Ljava.lang.String;") {
			
			arrayHashSet = (E[]) new String[1];
			arrayHashSet[0] = otherArray[0];
			typeHashSet= 's';
			for(int i=1; i<otherArray.length; ++i)
				this.add(otherArray[i]);
		}
	}
	
	
	@Override
	public Iterator_I<E> iterator() throws Exception{
		Iterator_I<E> temp = new Iterator_I<E>(arrayHashSet);
		return temp;
	}
	
	
	@Override
	public void add(E element) {
		
		if(typeHashSet == 'i') {
			
			if(!(contains(element))) {
				
				int size = arrayHashSet.length;
				Integer[] tempInt = new Integer[arrayHashSet.length+1];
				System.arraycopy(arrayHashSet, 0, tempInt, 0, arrayHashSet.length);

				arrayHashSet = (E[]) new Integer[size+1];
				System.arraycopy(tempInt, 0, arrayHashSet, 0, tempInt.length);
				arrayHashSet[arrayHashSet.length-1] = element;
			}
		}
		
		else if(typeHashSet == 's') {
			if(!(contains(element))) {
				
				int size = arrayHashSet.length;
				String[] tempString = new String[arrayHashSet.length+1];
				System.arraycopy(arrayHashSet, 0, tempString, 0, arrayHashSet.length);

				arrayHashSet = (E[]) new String[size+1];
				System.arraycopy(tempString, 0, arrayHashSet, 0, tempString.length);
				arrayHashSet[arrayHashSet.length-1] = element;
			}
		}
	}

	@Override
	public void addAll(Collection_I<E> c) {
		for(int i=0;i<c.size();++i) {
			this.add(c.getJavaArray()[i]);
		}	
	}

	@Override
	public void clear() {
		arrayHashSet = null;	
	}
	
	@Override
	public boolean contains(E element) {
		for(int i=0;i<arrayHashSet.length;++i) {

			if(arrayHashSet[i] == (element)) {
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
			if(arrayHashSet[i] != c.getJavaArray()[i])
				control++;
		}

		if(control == 0)
			return true;
		return false;
	}

	@Override
	public boolean isEmpty() {
		if(arrayHashSet.length == 0)
			return true;
		return false;
	}

	@Override
	public void remove(E element) {
		
		if(contains(element)) {
			
			int find=0;
			
			for(int i=0;i<arrayHashSet.length;++i) {

				if(arrayHashSet[i] == (element)) {
					find = i;
				}
			}	
			
			if(typeHashSet == 'i') {
				
				Integer[] tempInt = new Integer[arrayHashSet.length - 1];
				
				int index=0;
				for(int k=0;k<arrayHashSet.length;++k) {
					if(find == k) {
						// doing nothing ...
					}
					else {
						tempInt[index] = new Integer((Integer) arrayHashSet[k]);
						index++;
					}
				}
				
				arrayHashSet = (E[]) new Integer[arrayHashSet.length-1]; 
				arrayHashSet = (E[]) tempInt.clone();

			}
			
			else if(typeHashSet == 's') {
				String[] tempString = new String[arrayHashSet.length - 1];
				
				int index=0;
				for(int k=0;k<arrayHashSet.length;++k) {
					if(find == k) {
						// doing nothing ...
					}
					else {
						tempString[index] = new String((String) arrayHashSet[k]);
						index++;
					}
				}
				
				arrayHashSet = (E[]) new String[arrayHashSet.length-1]; 
				arrayHashSet = (E[]) tempString.clone();
			}
		}	
	}

	@Override
	public void removeAll(Collection_I<E> c) {
		
		int sizeC = c.size();
		
		for(int i=0;i<arrayHashSet.length;++i) {
			for(int j=0;j<sizeC;++j) {
				
				if(arrayHashSet[i].equals(c.getJavaArray()[j])) {
					this.remove(arrayHashSet[i]);
				}
			}
		}
	}

	@Override
	public void retainAll(Collection_I<E> c) {
		
		int sizeC = c.size();
		
		int control = 0;
		for(int i=0;i<arrayHashSet.length;++i) {			
			control = 0;
			for(int j=0;j<sizeC;++j) {
				
				if(arrayHashSet[i].equals(c.getJavaArray()[j])) {
					control = 1;
				}
			}
			if(control == 0)
				this.remove(arrayHashSet[i]);	
		}	
	}

	@Override
	public int size() {
		return arrayHashSet.length;
	}
		
	public void printArray() {
		System.out.println("\n----- Printing HashSet -----");
		for(int i=0;i<arrayHashSet.length;++i)
			System.out.println("Index : " + i + " Value : " + arrayHashSet[i]);
	}
	
	@Override
	public E[] getJavaArray() {
		return arrayHashSet;
	}
}
