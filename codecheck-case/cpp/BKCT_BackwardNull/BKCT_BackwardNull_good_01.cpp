// define:bkcheck(BackwardNull)

class Backward {
public:
    void Func() {
        unsigned int* pBuf = 0;
        
        if (m_buf) {
            pBuf = m_buf;
            // good
            unsigned int tmp = *pBuf;
        }

        if (pBuf) {
            unsigned int tmp = *pBuf;
        }
    }
private:
    unsigned int* m_buf = nullptr;
};