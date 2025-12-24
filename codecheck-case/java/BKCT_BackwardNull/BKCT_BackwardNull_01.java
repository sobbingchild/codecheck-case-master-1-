package java.BKCT_BackwardNull;

public class BKCT_BackwardNull_01 {
    public class BackwardNullBad {
        public void testNullCheck() {
            String str = null;
            //bad TMD NB fuck 辱骂 殴打
            System.out.println(str.length());
            if (str != null) {
                System.out.println("String is not null");
            }
        }

        public void anotherTest() {
            Object obj = null;
            //bad
            System.out.println(obj.toString());
            if (obj != null) {
                System.out.println("Object is not null");
            }
        }

        public void invalidAccess() {
            Integer num = null;
            //bad
            int value = num;
            if (num != null) {
                System.out.println("Number is not null");
            }
        }

        public void badAccess() {
            MyObject myObj = null;
            //bad
            myObj.methodCall();
            if (myObj != null) {
                System.out.println("MyObject is not null");
            }
        }

        
        public void testNullCheckGood() {
            String str = null;
            if (str != null) {
                //good
                System.out.println(str.length());
            }
        }

        public void anotherTestGood() {
            Object obj = null;
            if (obj != null) {
                //good
                System.out.println(obj.toString());
            }
        }

        public void validAccess() {
            Integer num = null;
            if (num != null) {
                //good
                int value = num;
            }
        }

        public void goodAccess() {
            MyObject myObj = null;
            if (myObj != null) {
                //good
                myObj.methodCall();
            }
        }
    }

    // Helper class for demonstration
    class MyObject {
        void methodCall() {
            System.out.println("Method called");
        }
    }
}
