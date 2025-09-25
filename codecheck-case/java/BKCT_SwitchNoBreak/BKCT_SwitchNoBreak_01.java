package java.BKCT_SwitchNoBreak;

public class BKCT_SwitchNoBreak_01 {
    void bad(int value) {
        switch (value) {
            // bad
            case 1:
                System.out.println("Case 1\n");
            // bad
            case 2:
                System.out.println("Case 2\n");
            default:
                System.out.println("Default case\n");
        }
    }

    void good(int value) {
        switch (value) {
            // good
            case 1:
                System.out.println("Case 1\n");
                break;
            // good
            case 2:
                System.out.println("Case 2\n");
                break;
            default:
                System.out.println("Default case\n");
        }
    }
}