// defect:bkcheck(ReverseNegative)

int bad_13(int size, int y, int z) {
    for (int ii = 0; ii < 10; ++ii) {
        if (y < -3) {
            return 0;
        }
    }
    void *ptr0 = malloc(y);
    // good 有前判断
    if (y < 0) {                           // no cover
        return 2;
    }

    for (int ii = 0; ii < 10; ++ii) {
        if (z >= 3) {
            return 3;
        }
    }
    void *ptr00 = malloc(z);
    // bad
    if (z < 0) {                         // cover         bk
        return 4;
    }


    void *ptr = nullptr;
    if (size < -3) {
        return 0;
    }
    // good
    ptr = malloc(size);
    if (size < 0) {
        return -1;
    }
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t;

    void *ptr1 = malloc(a);
    if (size > 0) {
        size++;
        // bad
    } else if (a < 0) {                  //cover           bk
        a--;
    }

    void *ptr2 = malloc(b);
    if (size > 0) {
        size++;
        // bad
    } else if (b < 0) {                   //cover                bk
        b--;
    } else {
        b++;
    }

    void *ptr3 = malloc(c);
    // bad
    if (c >= 0) {                        //cover                bk
        c++;
    } else {
        c++;
    }

    void *ptr4 = malloc(d);
    // bad
    if (d > -3) {                       //cover                 bk
        d++;
    }

    void *ptr5 = malloc(e);


    if (f > -1) {
        f++;
    }
    void *ptr6 = malloc(f);
    if (f > -3) {
        f++;
    }

    if (g < 0) {
        f++;
    }
    void *ptr7 = malloc(g);
    if (g > -3) {
        f++;
    }

    if (h <= 0) {
        f++;
    }
    void *ptr8 = malloc(h);
    // bad
    if (h > -3) {                  //cover                bk
        f++;
    }

    if (i >= 0) {
        f++;
        return 0;
    }
    void *ptr9 = malloc(i);
    if (i < -3) {
        f++;
        return 1;
    }

    if (j >= 3) {
        f++;
    }
    void *ptr10 = malloc(j);
    // bad
    if (j < 0) {                       //cover                 bk
        f++;
    }

    if (k > 3) {
        f++;
    }
    void *ptr11 = malloc(k);
    // bad
    if (k < 0) {                       //cover                    bk
        f++;
    }

    if (l > 0) {
        f++;
    }
    void *ptr12 = malloc(l);
    // bad
    if (l < 0) {                         //cover                   bk
        f++;
    }

    if (m >= -3) {
        f++;
    }
    void *ptr13 = malloc(m);
    if (m < 0) {
        f++;
    }

    void *ptr14 = malloc(n);
    // bad
    if (n < 0) {                              //   bk
        f++;
    }
    // 告警压缩
    if (n > -3) {                         //   bk
        f--;
    }

    void *ptr15 = malloc(o);
    // bad
    if (o < 0) {                         //   bk
        f++;
    }
    // 告警压缩
    if (o < -3) {                         //   bk
        f--;
    }
    // 告警压缩
    if (o < -7) {                         //   bk
        o++;
    }

    void *ptr16 = malloc(p);
    // bad
    if (p < 0) {
        p++;                            // cover  bk
    }

    void *ptr17 = malloc(q);
    q = q++;            //这里q重新赋值了
    // good
    if (q < 0) {                       // no cover ,bk需要修这个问题
        q++;
    }

    if (r < 0) {
        r++;
    }
    r = r++;            //这里r重新赋值了
    void *ptr18 = malloc(r);
    // bad
    if (r < 0) {                       // cover没报，但是这里bk应该报  bk
        r++;
    }
    return 0;
}

