import java.util.*;

public class topic_7 {
    public static void main(String[] args) {
        int arr[] = {1, 5, 0, 2, 3};
        Integer ar[] = {1, 5, 11, 2, 3};
        System.out.println(Arrays.toString(arr));   // deepToString() for 2D array
        System.out.println(Arrays.asList(ar));
        // System.out.println(Arrays.asList(ar).toString());
        System.out.println("Biggest val in primitive (int) : " + FindBig(arr));
        System.out.println("Biggest val in (Integer) : " + FindBig(ar));
    }
    public static int FindBig(int[] arr) {
        int max = 0;
        for (int val : arr) {
            max = Math.max(max, val);
        }
        return max;
    }
    public static int FindBig(Integer[] arr) {
        int max = 0;
        for (int val : arr) {
            max = Math.max(max, val);
        }
        return max;
    }
}
