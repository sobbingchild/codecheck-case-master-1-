package java.BKCT_IdenticalBranches;

public class BKCT_IdenticalBranches_01 {
    void bad_01(int x, int y, int z) {
        // bad
        if (x == 2) {
            y = 32;
            z = y * 2;
        } else {
            y = 32;
            z = y * 2;
        }
    }

    void bad_02(boolean condition) {
        // bad
        if (condition) {
            System.out.println("Repeated code");
        } else {
            System.out.println("Repeated code");
        }
    }

    void good_01(boolean condition) {
        // good
        if (condition) {
            System.out.println("Repeated code");
        } else {
            System.out.println("Another different branch");
        }
    }
}