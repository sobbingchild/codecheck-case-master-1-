//
// Created by wadema on 24-10-17.
//
// define:bkcheck(ArgumentNull)
class MyClass
{
public:
    SSL* ssl_ = nullptr; //
    static void bad_01(int* p);
    static void bad_02();
};

int SSL_set_session(SSL* s, SSL_SESSION* session)
{
    s->session = session;
    return 1;
}

int SSL_set_session(SSL* s, SSL_SESSION* session, int* p)
{
    return *p;
}

void MyClass::bad_01(int* p)
{
    // bad 未对ssl_做判断，可能造成空指针 成员指针
    if (SSL_set_session(ssl_, ssl_session) <= 0)
    {
        SSL_SESSION_free(ssl_session);
    }
    // bad 入参指针
    if (SSL_set_session(ssl_, ssl_session, p) <= 0)
    {
        SSL_SESSION_free(ssl_session);
    }
}

void MyClass::bad_02()
{
    SSL* s = getS();
    int* p = getI();
    // bad 未对ssl_做判断，可能造成空指针 局部变量指针
    if (SSL_set_session(s, ssl_session) <= 0)
    {
        SSL_SESSION_free(ssl_session);
    }
    // bad 局部变量指针
    if (SSL_set_session(s, ssl_session, p) <= 0)
    {
        SSL_SESSION_free(ssl_session);
    }
}
