import java.util.Scanner;

public class topic_5 {
    public static void main(String[] args) {
        int i = 1;
        char c = 'k';
        String s = " From class ";
        String st = " geeks for geeks has all java functions to read  ";
        s.trim();
        s = s.replace('s', 'M');
        System.out.println(s.compareTo("new"));
        System.out.println(s.substring(1, 5));
        System.out.println(s.concat("Fok"));
        System.out.println("Compare was : " + s.equals(s));
        Scanner scan = new Scanner(System.in);
        int a = scan.nextInt();
        String str = scan.next();
        System.out.println(a + " " + str);
/*
* The Unicode value of space character is ‘\u0020’.
*  The trim() method in java checks this Unicode value before and after the string,
* if it exists then removes the spaces and returns the omitted string
*/
        System.out.println("O"+ c + s.toLowerCase() + i);
    }
    public static void Dis() {
        System.out.println("Dear fox 1");
    }
}
