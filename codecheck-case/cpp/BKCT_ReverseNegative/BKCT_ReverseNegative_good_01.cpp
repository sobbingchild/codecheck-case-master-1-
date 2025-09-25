// defect:bkcheck(ReverseNegative)

void good_01() {
    int i = 0;
    int a[10] = {0};
    
    while(i < 5) {
        int tmp = a[i];
        i++;

        // good
        if (i >= 0) {
            continue;
        }
    }
}