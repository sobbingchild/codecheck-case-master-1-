// define:bkcheck(ImproperAssign)
#include <string>

void bad() {

    int num = 0;
	// bad: wrong assign
    std::string a = num;

    // bad: wrong assign
    std::string b = 100;

    // bad: wrong assign
    std::string c(123333);

    std::string d;
	// bad: wrong assign
    d = 10;
}