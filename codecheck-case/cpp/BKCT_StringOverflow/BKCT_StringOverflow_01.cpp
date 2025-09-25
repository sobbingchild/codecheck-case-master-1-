// defect:bkcheck(StringOverflow)

void bad_01() {
    char destination_buffer[256];
    char source_buffer[1024];
    // bad, string copy overflow
    strcpy(destination_buffer, source_buffer);
}

void bad_02() {
    char destination_buffer[256];
    char source_buffer[1024];
    // bad, string copy overflow
    strcat(destination_buffer, source_buffer);
}

void bad_03() {
    int a = 256, b = 1024;
    char destination_buffer[a];
    char source_buffer[b];
    // bad, string copy overflow
    strcpy(destination_buffer, source_buffer);
}

void bad_04() {
    int a = 256, b = 1024;
    char destination_buffer[a];
    char source_buffer[b];
    // bad, string copy overflow
    strcat(destination_buffer, source_buffer);
}