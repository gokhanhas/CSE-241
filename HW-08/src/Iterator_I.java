/*
 * Gokhan Has - 161044067
 */
/**
 * 
 * @author Gokhan
 *
 * @param <E> int or string
 */
public class Iterator_I<E> {
		private E[] arrayIterator;
		private int end;
		private int _current;
		private char typeIterator;
		
		public Iterator_I() {
			setArrayIterator(null);
		}
		/**
		 * 
		 * @param paramArray to int or string array.
		 * @throws Exception if array is null.
		 */
		public Iterator_I(E[] paramArray) throws Exception {			
			
			if(paramArray == null)
				throw new Exception();
			
			else if(paramArray.getClass().getName() == "[Ljava.lang.Integer;") {
				typeIterator = 'i';
				arrayIterator = (E[]) new Integer[paramArray.length];
				for(int i=0; i<paramArray.length; ++i)
					arrayIterator[i] = (E) new Integer((Integer)paramArray[i]);
				
			}
			
			else if(paramArray.getClass().getName() == "[Ljava.lang.String;") {
				typeIterator = 's';
				arrayIterator = (E[]) new String[paramArray.length];
				for(int i=0; i<paramArray.length; ++i)
					arrayIterator[i] = (E) new String((String)paramArray[i]);
				
			}
			
			for(int i = 0 ; i < paramArray.length; ++i) {
				arrayIterator[i] = paramArray[i];
			}
			
			_current = 0;
			end = arrayIterator.length-1;
		}
		/**
		 * 
		 * @return true if the iteration has more elements.
		 * @throws Exception if the iterator is null.
		 */
		boolean hasNext() throws Exception {
			
			if(_current + 1 >= end)
				throw new Exception();
			
			if(arrayIterator[_current + 1] != null)
				return true;
			else
				return false;
		}
		/**
		 * 
		 * @return the next element in the iteration.
		 * @throws Exception if the iterator is null;
		 */
		E next() throws Exception {
			
			if(hasNext() == false)
				throw new Exception();
			else
				_current++;
			
			return arrayIterator[_current];	
		}
		
		/**
		 * 
		 * @return the last element returned by this iterator.
		 * @throws Exception if the iteration is null.
		 */
		E remove() throws Exception {
			
			if(typeIterator == 'i') {
				
				Integer[] tempInt = new Integer[arrayIterator.length-1];
				Integer temp = new Integer((Integer) arrayIterator[_current]);
				
				int index=0;
				for(int i=0;i<arrayIterator.length;++i) {
					if(_current == i) {
						// doing nothing ...
					}
					else {
						tempInt[index] = new Integer((Integer) arrayIterator[i]);
						index++;
					}
				}
				
				arrayIterator = (E[]) new Integer[arrayIterator.length-1]; 
				arrayIterator = (E[]) tempInt.clone();
				return (E) temp;
			}
			else if(typeIterator == 's') {
				String[] tempString = new String[arrayIterator.length-1];
				String temp = new String((String) arrayIterator[_current]);
				
				int index=0;
				for(int i=0;i<arrayIterator.length;++i) {
					if(_current == i) {
						// doing nothing ...
					}
					else {
						tempString[index] = new String((String) arrayIterator[i]);
						index++;
					}
				}
				
				arrayIterator = (E[]) new String[arrayIterator.length-1]; 
				arrayIterator = (E[]) tempString.clone();
				return (E) temp;
			}
			else
				throw new Exception();
		}
		
		
		E begin_iterator() {
			return arrayIterator[_current];
		}
		
		E end_iterator() {
			return arrayIterator[end];
		}
		
		public E[] getArrayIterator() {
			return arrayIterator;
		}

		public void setArrayIterator(E[] arrayIterator) {
			this.arrayIterator = arrayIterator;
		}
		
	
		public int get_current() {
			return _current;
		}

		public void set_current(int _current) {
			this._current = _current;
		}
		
		public void printIter() {
			
			System.out.println("-----Printing Iterator-----");
			for(int i=0;i<arrayIterator.length;++i) {
				System.out.println("Index : " + i + " Value : " + arrayIterator[i]);
			}
		}
}
