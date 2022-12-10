import java.util.*;

public class Topic_8 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();

    // 1) Add 4 elements
        ArrayList<Integer> arrList = new ArrayList<Integer>(n);
        for (int i = 0; i < n; i++) {
            int x = scan.nextInt();
            arrList.add(x);
        }
        System.out.println(arrList);    // Direct possible
        // System.out.println(arrList.getClass());    // To see the data Type

    // 2) Insert 60 at index 1
        arrList.add(1, 60);     // Insert/add value to specific location
        System.out.println(arrList);

    // 3) Print element at spesific index
        arrList.get(2);


    // 4) Delete element of INDEX 4
        arrList.remove(3);
        System.out.println("Value deleted at index 3");

    // 5) Delete element of VALUE 10
        arrList.remove(Integer.valueOf(10));    // Integer.valueOf() ta object create kore
        System.out.println("Value deleted 10");



    // 6) Sort using for-each loop
        System.out.println();
        System.out.println("-- Before Sorting --");
        arrList.forEach((x) -> System.out.print(x + " "));
        System.out.println();
        System.out.println();



        // Ascending sort
        Collections.sort(arrList);

        // For descending sort use bellow method
        // Collections.sort(list, Collections.reverseOrder());

        // For-each part
        System.out.println("-- After Sorting --");

        // Built in forEach
        arrList.forEach((x) -> System.out.print(x + " "));
        System.out.println();

        // Sir er dewa For-Each
        for (int arr : arrList) {
            System.out.print(arr + " ");
        }
        System.out.println();


    // 7) Delete all elements in array
        // arrList.removeAll(arrList);
        arrList.clear();    // Both work same
        System.out.println("\nAray List empty : " + arrList.isEmpty());
    }
}

/*
 * Inputs
 *
 * 4
 * 10 50 70 30
 *
 */