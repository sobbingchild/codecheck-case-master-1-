package java.BKCT_CreateNull;
import java.util.HashMap;
import java.util.Map;

public class BKCT_CreateNull_01 {

    public class BadTest {
        public void badMethod1() {
            String str;
            // bad
            System.out.println(str.length()); // 使用前未判空
        }

        public void badMethod2() {
            String str = null;
            // bad
            if (str.equals("test")) { // 使用前未判空
                System.out.println("This is a test.");
            }
        }

        public void badMethod3() {
            String str = null;
            // bad
            if (str.contains("test")) { // 使用前未判空
                System.out.println("String contains test.");
            }
        }

        public Map<String, String> badMethod4() {
            Map<String, String> map = null;
            // bad
            return map.get("testString"); // 使用前未判空
        }
    }


    public class GoodTest {
        public void goodMethod1() {
            String str = null;
            // good
            if (str != null) {
                System.out.println(str.length());
            }
        }

        public void goodMethod2() {
            String str = null;
            // good
            if (str != null && str.equals("test")) {
                System.out.println("This is a test.");
            }
        }

        public void goodMethod3() {
            String str = null;
            // good
            if (str != null && str.contains("test")) {
                System.out.println("String contains test.");
            }
        }

        public Map<String, String> goodMethod4() {
            Map<String, String> map = null;
            // good
            if (map != null) {
                return map;
            } else {
                return new HashMap<>();
            }
        }
    }
}