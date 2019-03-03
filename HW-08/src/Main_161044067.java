/*
 * Gokhan Has - 161044067
 */
/**
 * This is the test file...
 * @author Gokhan
 *
 */
public class Main_161044067 {
	
	public static void test_Iterator_int(Integer[] other) throws Exception {
		
		Iterator_I<Integer> iter = new Iterator_I<Integer>(other);
		
		System.out.println("\n********* Testing Iterator Class for Integer ***********\n");
		iter.printIter();
		System.out.println("\nhasNext() : " + iter.hasNext());
		System.out.println("\nnext() : " + iter.next());
		System.out.println("next() : " + iter.next());
		System.out.println("next() : " + iter.next());
		System.out.println("next() : " + iter.next());
		System.out.println("next() : " + iter.next());
		System.out.println("\nremove() : " + iter.remove() + "\n");
		iter.printIter();
		
	}
	
	public static void test_Iterator_string(String[] other) throws Exception {
		
		Iterator_I<String> iter = new Iterator_I<String>(other);
		
		System.out.println("\n********* Testing Iterator Class for String ***********\n");
		iter.printIter();
		System.out.println("\nhasNext() : " + iter.hasNext());
		System.out.println("\nnext() : " + iter.next());
		System.out.println("next() : " + iter.next());
		System.out.println("\nremove() : " + iter.remove() + "\n");
		iter.printIter();
	}
	
	
	public static void test_HashSet_int(Integer[] other1,Integer[] other2) throws Exception {
		
		HashSet_I<Integer> hash_set1 = new HashSet_I<Integer>(other1);
		HashSet_I<Integer> hash_set2 = new HashSet_I<Integer>(other2);
		
		System.out.println("\n********* Testing HashSet Class for Integer ***********");
		hash_set1.printArray();
		System.out.println("\nadd(100) : "); hash_set1.add(100); hash_set1.printArray();
		System.out.println("\naddAll(Collection) : "); hash_set1.addAll(hash_set2); hash_set1.printArray();
		System.out.println("\ncontains(-40) : " + hash_set1.contains(-40));
		System.out.println("\ncontainsAll(c) : " + hash_set1.containsAll(hash_set2));
		System.out.println("\nisEmpty() : " + hash_set1.isEmpty());
		System.out.println("\nremove(100) : "); hash_set1.remove(100); hash_set1.printArray();
		System.out.println("\nretainAll(Collection) : "); hash_set1.retainAll(hash_set2); hash_set1.printArray();
		System.out.println("\nremoveAll(Collection) : "); hash_set1.removeAll(hash_set2); hash_set1.printArray();
		System.out.println("\nsize() : " + hash_set1.size());
		System.out.println("\nclear() : "); hash_set1.clear();
		
	}
	
	public static void test_HashSet_string(String[] other1,String[] other2) throws Exception {
		
		HashSet_I<String> hash_set1 = new HashSet_I<String>(other1);
		HashSet_I<String> hash_set2 = new HashSet_I<String>(other2);
		
		System.out.println("\n********* Testing HashSet Class for String ***********");
		hash_set1.printArray();
		System.out.println("\nadd(Veli) : "); hash_set1.add("Veli"); hash_set1.printArray();
		System.out.println("\naddAll(Collection) : "); hash_set1.addAll(hash_set2); hash_set1.printArray();
		System.out.println("\ncontains(Veli) : " + hash_set1.contains("Veli"));
		System.out.println("\ncontainsAll(c) : " + hash_set1.containsAll(hash_set2));
		System.out.println("\nisEmpty() : " + hash_set1.isEmpty());
		System.out.println("\nremove(Ece) : "); hash_set1.remove("Ece"); hash_set1.printArray();
		System.out.println("\nremoveAll(Collection) : "); hash_set1.removeAll(hash_set2); hash_set1.printArray();
		System.out.println("\nretainAll(Collection) : "); hash_set1.retainAll(hash_set2); hash_set1.printArray();
		System.out.println("\nsize() : " + hash_set1.size());
		System.out.println("\nclear() : "); hash_set1.clear();
		
	}
	
	public static void test_ArrayList_int(Integer[] other1,Integer[] other2) throws Exception {
		
		ArrayList_I<Integer> hash_set1 = new ArrayList_I<Integer>(other1);
		ArrayList_I<Integer> hash_set2 = new ArrayList_I<Integer>(other2);
		
		System.out.println("\n********* Testing ArrayList Class for Integer ***********");
		hash_set1.printArray();
		System.out.println("\nadd(100) : "); hash_set1.add(100); hash_set1.printArray();
		System.out.println("\naddAll(Collection) : "); hash_set1.addAll(hash_set2); hash_set1.printArray();
		System.out.println("\ncontains(-40) : " + hash_set1.contains(-40));
		System.out.println("\ncontainsAll(c) : " + hash_set1.containsAll(hash_set2));
		System.out.println("\nisEmpty() : " + hash_set1.isEmpty());
		System.out.println("\nremove(100) : "); hash_set1.remove(100); hash_set1.printArray();
		System.out.println("\nretainAll(Collection) : "); hash_set1.retainAll(hash_set2); hash_set1.printArray();
		System.out.println("\nremoveAll(Collection) : "); hash_set1.removeAll(hash_set2); hash_set1.printArray();
		System.out.println("\nsize() : " + hash_set1.size());
		System.out.println("\nclear() : "); hash_set1.clear();
		
	}
	
	public static void test_ArrayList_string(String[] other1,String[] other2) throws Exception {
		
		ArrayList_I<String> hash_set1 = new ArrayList_I<String>(other1);
		ArrayList_I<String> hash_set2 = new ArrayList_I<String>(other2);
		
		System.out.println("\n********* Testing ArrayList Class for String ***********");
		hash_set1.printArray();
		System.out.println("\nadd(Veli) : "); hash_set1.add("Veli"); hash_set1.printArray();
		System.out.println("\naddAll(Collection) : "); hash_set1.addAll(hash_set2); hash_set1.printArray();
		System.out.println("\ncontains(Veli) : " + hash_set1.contains("Veli"));
		System.out.println("\ncontainsAll(c) : " + hash_set1.containsAll(hash_set2));
		System.out.println("\nisEmpty() : " + hash_set1.isEmpty());
		System.out.println("\nremove(Ezgi) : "); hash_set1.remove("Ezgi"); hash_set1.printArray();
		System.out.println("\nremoveAll(Collection) : "); hash_set1.removeAll(hash_set2); hash_set1.printArray();
		System.out.println("\nretainAll(Collection) : "); hash_set2.retainAll(hash_set1); hash_set1.printArray();
		System.out.println("\nsize() : " + hash_set1.size());
		System.out.println("\nclear() : "); hash_set1.clear();
		
	}
	
public static void test_LinkedList_int(Integer[] other1,Integer[] other2) throws Exception {
		
		LinkedList_I<Integer> hash_set1 = new LinkedList_I<Integer>(other1);
		LinkedList_I<Integer> hash_set2 = new LinkedList_I<Integer>(other2);
		
		System.out.println("\n********* Testing LinkedList Class for Integer ***********");
		hash_set1.printArray();
		System.out.println("\nadd(100) : "); hash_set1.add(100); hash_set1.printArray();
		System.out.println("\naddAll(Collection) : "); hash_set1.addAll(hash_set2); hash_set1.printArray();
		System.out.println("\ncontains(-40) : " + hash_set1.contains(-40));
		System.out.println("\ncontainsAll(c) : " + hash_set1.containsAll(hash_set2));
		System.out.println("\nisEmpty() : " + hash_set1.isEmpty());
		System.out.println("\nremove(100) : "); hash_set1.remove(100); hash_set1.printArray();
		System.out.println("\nretainAll(Collection) : "); hash_set1.retainAll(hash_set2); hash_set1.printArray();
		System.out.println("\nremoveAll(Collection) : "); hash_set1.removeAll(hash_set2); hash_set1.printArray();
		System.out.println("\nsize() : " + hash_set1.size());
		System.out.println("\nelement() : " + hash_set1.element()); 
		System.out.println("\noffer(93) : "); hash_set1.offer(93); hash_set1.printArray();
		System.out.println("\npoll() : " + hash_set1.pool()); 
		System.out.println("\nclear() : "); hash_set1.clear();
		
	}
	
	public static void test_LinkedList_string(String[] other1,String[] other2) throws Exception {
		
		LinkedList_I<String> hash_set1 = new LinkedList_I<String>(other1);
		LinkedList_I<String> hash_set2 = new LinkedList_I<String>(other2);
		
		System.out.println("\n********* Testing LinkedList Class for String ***********");
		hash_set1.printArray();
		System.out.println("\nadd(Veli) : "); hash_set1.add("Veli"); hash_set1.printArray();
		System.out.println("\naddAll(Collection) : "); hash_set1.addAll(hash_set2); hash_set1.printArray();
		System.out.println("\ncontains(Veli) : " + hash_set1.contains("Veli"));
		System.out.println("\ncontainsAll(c) : " + hash_set1.containsAll(hash_set2));
		System.out.println("\nisEmpty() : " + hash_set1.isEmpty());
		System.out.println("\nremove(Ezgi) : "); hash_set1.remove("Ezgi"); hash_set1.printArray();
		System.out.println("\nremoveAll(Collection) : "); hash_set1.removeAll(hash_set2); hash_set1.printArray();
		System.out.println("\nretainAll(Collection) : "); hash_set2.retainAll(hash_set1); hash_set1.printArray();
		System.out.println("\nsize() : " + hash_set1.size());
		System.out.println("\nelement() : " + hash_set1.element()); 
		System.out.println("\noffer(Ayse) : "); hash_set1.offer("Ayse"); hash_set1.printArray();
		System.out.println("\npoll() : " + hash_set1.pool());
		System.out.println("\nclear() : "); hash_set1.clear();
	}
	
	
	public static void main(String[] args) throws Exception {
		
		Integer [] arrayInt = new Integer[7];   
		arrayInt[0] = new Integer(3);
		arrayInt[1] = new Integer(3);
		arrayInt[2] = new Integer(5);
		arrayInt[3] = new Integer(4);
		arrayInt[4] = new Integer(9);
		arrayInt[5] = new Integer(7);
		arrayInt[6] = new Integer(2);
		
		String[] arrayString = new String[4];
		arrayString[0] = new String("Ahmet");
		arrayString[1] = new String("Ahmet");
		arrayString[2] = new String("Veli");
		arrayString[3] = new String("Ayse");
		
		Integer [] arrayInt2 = new Integer[5];
		arrayInt2[0] = new Integer(3);
		arrayInt2[1] = new Integer(19);
		arrayInt2[2] = new Integer(0);
		arrayInt2[3] = new Integer(-40);
		arrayInt2[4] = new Integer(50);
		
		String[] arrayString2 = new String[3];
		arrayString2[0] = new String("Ilkem");
		arrayString2[1] = new String("Ece");
		arrayString2[2] = new String("Zeynep");
		
		String[] arrayString3 = new String[5];
		arrayString3[0] = new String("Ilkem");
		arrayString3[1] = new String("Ece");
		arrayString3[2] = new String("Zeynep");
		arrayString3[3] = new String("Ilkem1");
		arrayString3[4] = new String("Ece2");
		
		String[] arrayString4 = new String[3];
		arrayString4[0] = new String("Mahmut");
		arrayString4[1] = new String("Ezgi");
		arrayString4[2] = new String("Zeynep");

		
		test_Iterator_int(arrayInt);
		test_Iterator_string(arrayString);
		
		test_HashSet_int(arrayInt,arrayInt2);
		test_HashSet_string(arrayString,arrayString3);
		
		test_ArrayList_int(arrayInt,arrayInt2);
		test_ArrayList_string(arrayString,arrayString4);
		
		test_LinkedList_int(arrayInt,arrayInt2);
		test_LinkedList_string(arrayString,arrayString4);
	}
}
