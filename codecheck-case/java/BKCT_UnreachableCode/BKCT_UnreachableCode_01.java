package java.BKCT_UnreachableCode;

public class BKCT_UnreachableCode_01 {
    public void bad_01() {
        return;
        // bad
        System.out.println("This code is unreachable");
    }

    public void bad_02() {
        if (true) {
            return;
            // bad
            int x = 10; // Unreachable
        }
    }

    public void bad_03() {
        for (int i = 0; i < 10; i++) {
            if (i > 5) {
                break;
                // bad
                int a = 1;
            }
        }
    }

    public void bad_04() {
        int i = 5;
        while (i-- > 0) {
            if (i < 2) {
                break;
                // bad
                int a = 1;
            }
        }
    }
}