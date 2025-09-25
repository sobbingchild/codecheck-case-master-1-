// defect:bkcheck(LocalAssignToGlobal)

#include <stdlib.h>

int *buf;

class MyClass {
public:
    int publicVar; // 公共成员变量
    void publicFunction() {
        // good
        buf = &publicVar; // 将成员变量的地址赋给全局指针buf，不应该告警
    }

};