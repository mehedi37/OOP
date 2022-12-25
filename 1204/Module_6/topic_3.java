class outSideMainClass {
    private void method() {
        System.out.println("Private Method");
    }
}

public class topic_3 {
    public static void main(String[] args) {
        outSideMainClass x = new outSideMainClass();
        x.method();     // The method method() from the type outSideMainClass is not
    }
}
