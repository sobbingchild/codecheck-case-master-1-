#include <string.h>
#include <stdlib.h>


char* bad(char *name) {
    char* new_name = NULL;
    if (name != NULL) {
        // bad
        new_name = (char *)malloc(strlen(name + 1));
        strcpy(new_name, name);
    }
	
	if (name == NULL) {
		int i = 2;
		// bad
        new_name2 = (char *)malloc(strlen(name + i));
        strcpy(new_name2, name);
    }


    return new_name;
}

char* bad(char *name, int num) {
    char* new_name = NULL;
    if (name != NULL) {
        // bad
        new_name = (char *)malloc(strlen(name + num));
        strcpy(new_name, name);
    }
	
	if (name == NULL) {
		int i = 2;
		// bad
        new_name2 = (char *)malloc(strlen(name - num));
        strcpy(new_name2, name);
    }
	
    return new_name;
}

char* good(char *name) {
    char* new_name = NULL;
    if (name != NULL) {
        // good
        new_name = (char *)malloc(strlen(name + 0) + 1);
        strcpy(new_name, name);
    }

    return new_name;
}

