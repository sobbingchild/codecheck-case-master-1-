package java.BKCT_DevideByZero;

public class BKCT_DevideByZero_01 {
    public static void bad_01() {
        int a = 0;
        int b = 1 / a;
    }

    public static void bad_02() {
        int b = 1 / 0;
    }

    public static void bad_03() {
        int a = 0, b = 1;
        b /= a;
    }

    public static void bad_04() {
        Integer a = null;
        int x = 10;
        int z = x / a;
    }

    public static void bad_05() {
        Integer a = 0;
        int x = 10;
        int z = x / a;
    }
}