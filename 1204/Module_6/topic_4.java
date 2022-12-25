

public class topic_4 {
    static int StaticMember = 37;
    int NonStaticMember = 9;
    public void NonStaticMethod() {
        System.out.println("Non static method");
    }
    public static void StaticMethod() {
        System.out.println("Static method");
    }
    public static void main(String[] args) {
        System.out.println(StaticMember);
        System.out.println(NonStaticMember);
        StaticMethod();
        NonStaticMethod();
    }
}
