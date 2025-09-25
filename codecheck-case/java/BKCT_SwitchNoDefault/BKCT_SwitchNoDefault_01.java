package java.BKCT_SwitchNoDefault;

public class BKCT_SwitchNoDefault_01 {
    void bad(int value) {
        // bad
        switch (value) {
            case 1:
                System.out.println("Case 1\n");
                break;
            case 2:
                System.out.println("Case 2\n");
                break;
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