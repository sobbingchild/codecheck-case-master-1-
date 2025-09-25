// define:bkcheck(NullPointDereference)

#include <stdlib.h>

void good_01() {
    int count = 10;
    unsigned char* pMsg = 0;
    if (count > 0) {
        pMsg = (unsigned char*)malloc(sizeof(unsigned char) * count);
        if (!pMsg)
            return;
    }

    for (int i = 0; i < count; i++) {
        // good
        pMsg[i] = (unsigned char)i;
    }
}

void good_02(int range) {
    int size = 10;
    unsigned char* pMsg = new unsigned char[size];
    unsigned char* pTmp = nullptr;
 
    while (range >= 0) {
        pTmp = range > size ? pMsg : nullptr;
        if (!pTmp) {
            return;
        }

        break;
    }

    if (range < 0) {
        return; 
    }

    // good
    unsigned char tmp = *pTmp;
}

void good_03() {
    bool bCheck = true;
    unsigned char* pMsg = new unsigned char();
    char* pTmp = nullptr;

    if (pMsg) {
        pTmp = (char*)pMsg;

        if(pTmp) {
            bCheck = false;
        }
    }

    if (bCheck == false) {
        // good
        char tmp = *pTmp;
    }
}