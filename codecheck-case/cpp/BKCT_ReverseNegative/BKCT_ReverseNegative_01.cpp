// defect:bkcheck(ReverseNegative)

void bad_01(int x1) {
    std::vector<int> vArrary;
    vArrary[x1] = 0;
    // bad
    if (x1 < 0) {
        x1++;
    }
}

void bad_02(int z) {
    void *ptr0 = malloc(z);
    // bad
    if (z < 0) {
        return;
    }
}

void bad_03(int some_signed_integer) {
    some_struct *x = kmalloc(some_signed_integer, GFP_KERNEL); // Dangerous integer use
    // bad
    if (some_signed_integer < 0) // Check after use
        return error;
}

void bad_04(int z) {
    int a[5] = {1, 2, 3, 4, 5};
    a[z] = 1;
    // bad
    if (z < 0) {
        return;
    }
}

void bad_05(int z) {
    int *pA;
    pA = new int[10];
    pA[z] = 1;
    // bad
    if (z < 0) {
        return;
    }
}