#include <cstddef>
#include <memory>
//
// Created by wadema on 24-7-23.
//
// defect:bkcheck(AutoFreeLeak)
void bad_01()
{
    // bad
    unsigned char* pBuf = NULL;
    std::auto_ptr<unsigned char> auto_free(pBuf); // auto_free 管理的是一个空指针
    unsigned int uLen = 0;
    ret = Comm::AESEncrypt_CBC128_PKCS7_IVHead_Flags(sKey, (const unsigned char*)raw_data.c_str(),
                                                     raw_data.size(),
                                                     &pBuf, &uLen,
                                                     Comm::AESCRYPTO_AUTO_NONCE |
                                                     Comm::AESCRYPTO_AUTO_CHECKSUM);
    // pBuf 指向的内存没有被 auto_free 管理，导致内存泄漏
}

void bad_02(int a)
{
    // bad
    char* value = nullptr;
    int len = 0;
    if (a > 0)
    {
        int ret = kvclient.GetByStr(ss.str().c_str(), &value, len);
    }
    std::unique_ptr<char> auto_free(value);
}

void good_01()
{
    // good
    unsigned char* pBuf = NULL;
    unsigned int uLen = 0;
    ret = Comm::AESEncrypt_CBC128_PKCS7_IVHead_Flags(sKey, (const unsigned char*)raw_data.c_str(),
                                                     raw_data.size(),
                                                     &pBuf, &uLen,
                                                     Comm::AESCRYPTO_AUTO_NONCE |
                                                     Comm::AESCRYPTO_AUTO_CHECKSUM);
    std::auto_ptr<unsigned char> auto_free(pBuf); // auto_free 管理 pBuf 指向的内存
    // 在 auto_free 超出作用域时，pBuf 指向的内存会被自动释放
}

void good_02()
{
    // good
    char* value = nullptr;
    int len = 0;
    int ret = kvclient.GetByStr(ss.str().c_str(), &value, len);
    std::unique_ptr<char> auto_free(value);
}

void good_03()
{
    // good
    clsResultList* result = NULL;
    int ret = client.BatchUp(corpid, WWTABLE_BBS_POST, &mulUpdateList, &result);
    auto_ptr<clsResultList> auto_free(result);
}
