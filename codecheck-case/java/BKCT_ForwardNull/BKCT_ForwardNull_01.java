package java.BKCT_ForwardNull;

public class BKCT_ForwardNull_01 {

    public void badMethod1() {
        String str = null;
        if (str == null) {
            // bad
            System.out.println(str.length()); // 在为空的分支中使用
        }
    }

    public void badMethod2() {
        String str = null;
        if (str != null) {
            return;
        }
        // bad
        System.out.println(str.length()); // 在为空的分支中使用
    }

    public void badMethod3(String str) {
        if (str != null) {
            str = null;
        }
        // bad
        System.out.println(str.length()); // 在不再次检查是否为空的情况下使用
    }

    public void badMethod4(String str) {
        if (str == null) {

        }
        // bad
        System.out.println(str.length()); // 在不再次检查是否为空的情况下使用
    }

    public void goodMethod1() {
        String str = null;
        if (str != null) {
            // good
            System.out.println(str.length());
        }
    }

    public void goodMethod2() {
        String str = null;
        if (str == null) {
            return;
        }
        // good
        System.out.println(str.length());
    }

    public void goodMethod3(String str) {
        if (str == null) {
            str = "aaa";
        }
        // good
        System.out.println(str.length());
    }

    public void goodMethod4(String str) {
        if (str == null) {
            return;
        }
        // good
        System.out.println(str.length());
    }
}