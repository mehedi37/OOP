import java.awt.Point;
import java.util.*;

public class topic_6 {
    // public static void main(String[] args) {
    //     Point p = getPoint();
    //     System.out.println("P = " + p);
    //     System.out.println("x : " + p.x + ", y : " + p.y);
    // }
    // public static Point getPoint() {
    //     return new Point(9, 37);    // Anonymous object created here
    // }
    public static void main(String[] args) {
        int arr[] = initialArray();
        System.out.println("--- Before Sorting ---");
        printArray(arr);
        sortArray(arr);
        System.out.println();
        System.out.println("--- After Sorting ---");
        printArray(arr);
    }
    public static int[] initialArray() {
        return new int[] {1, 2, 5, 8, 0};
    }
    public static void sortArray(int[] arr) {
        Arrays.sort(arr);
    }
    public static void printArray(int[] arr) {
        for (int val : arr) {
            System.out.print(val + " ");
        }
        System.out.println();
    }
}
