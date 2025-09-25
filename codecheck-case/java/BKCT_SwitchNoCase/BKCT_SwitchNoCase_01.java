package java.BKCT_SwitchNoCase;

public class BKCT_SwitchNoCase_01 {
    void bad(int value) {
        // bad
        switch (value) {
            default:
                System.out.println("Default case\n");
        }
    }

    void good(int value) {
        // good
        switch (value) {
            case 1:
                System.out.println("Case 1\n");
                break;
            case 2:
                System.out.println("Case 2\n");
                break;
            default:
                System.out.println("Default case\n");
        }
    }
}