import java.util.Scanner;
import java.util.Arrays;

public class topic_1 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        // // 1
        // String MyName = scan.nextLine();
        // String add = scan.nextLine();
        // System.out.println("My Name : " + MyName + '\n' + "Address : " + add);

        // // 2
        // int f, s;
        // f = scan.nextInt();
        // s = scan.nextInt();
        // System.out.println("Bigger is : " + (f > s ? f : s));

        // 3
        int arr[] = new int[10];
        int max = -1, min = 100000, sum = 0;
        for (int i = 0; i < 10; i++) {
            arr[i] = scan.nextInt();
            max = Math.max(max, arr[i]);        // Get the max val
            min = Math.min(min, arr[i]);
            sum += arr[i];
        }
        for (int i = 0; i < 10; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
        System.out.println("Max Val : " + max);
        System.out.println("Min Val : " + min);
        System.out.println("Avg Val : " + sum/10);
        Arrays.sort(arr);
        for (int i = 0; i < 10; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
