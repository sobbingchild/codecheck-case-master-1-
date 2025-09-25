//
// Created by wadema on 24-6-26.
//
// defect:bkcheck(StrcpyParam)
void bad_01() {
    char interface_str[100] = {'\0'};
    if (0 == interface) {
        // bad
        strcpy(interface_str, "SendReaListAllReq", 100);
    }
}

void bad_02() {
    const char *source = "Hello, world!";
    char *destination = static_cast<char *>(malloc(50 * sizeof(char)));
    // bad
    strcpy(destination, source);
}

void bad_03() {
    const char *source = "Hello, world!";
    char *destination = static_cast<char *>(malloc(50 * sizeof(char)));
    // bad
    strcpy(destination, source, 100);
}

void good_01() {
    char interface_str[100] = {'\0'};
    if (0 == interface) {
        // good
        strcpy(interface_str, "SendReaListAllReq");
    }
}
void good_02() {
    const char *source = "Hello, world!";
    char *destination = static_cast<char *>(malloc(50 * sizeof(char)));
    // good
    strcpy(destination, source, sizeof(destination));
}