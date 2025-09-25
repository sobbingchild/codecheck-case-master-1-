//
// Created by wadema on 24-11-6.
//
// defect:bkcheck(MaxLenArray)

const unsigned int MAX_MSG_LEN = 1024 * 32;

void bad()
{
    // bad
    char buff[MAX_MSG_LEN] = {0};
    // bad
    char buff1[1024 * 32] = {0};
    // bad
    char buff2[32768] = {0};
    // bad
    char buff3[100000] = {0};
}

void good_01()
{
    // good
    char buff4[1] = {0};
    // good
    char buff5[32768 - 1] = {0};
}

void good_02(CRpcWrapper* lllrpc)
{
    // good
    char buff[MAX_MSG_LEN] = {0};
}
