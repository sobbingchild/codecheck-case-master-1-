package java.BKCT_NullPointDereference;

public class BKCT_NullPointDereference_01 {
    void bad_01() {
        String str;
        str = null;
        // bad
        int length = str.length();

        Integer num;
        num = null;
        // bad
        int value = num.intValue();

        String[] arr = new String[2];
        arr[0] = null;
        // bad
        System.out.println(arr[0].charAt(0));

        Object obj;
        obj = null;
        // bad
        obj.toString();
    }

    void good_01() {
        String str = "Hello";
        // good
        int length = str.length();

        Integer num = 10;
        // good
        int value = num.intValue();

        String[] arr = new String[2];
        arr[0] = "test";
        // good
        System.out.println(arr[0].charAt(0));

        Object obj = new Object();
        // good
        obj.toString();
    }
}