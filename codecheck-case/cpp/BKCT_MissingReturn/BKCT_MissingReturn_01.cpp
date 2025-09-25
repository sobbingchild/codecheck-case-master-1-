// defect:bkcheck(MissingReturn)
#include <iostream>
#include <type_traits>
#include <tuple>

int return_int1(int x) {
    int a = 0;
// bad
}

void return_void(int x) {
    if (x >= 5)
        return;
    else if (x < 5) {
        return;
    }
// good
}

int return_int(int x) {
    if (x >= 5)
        return 10;
    else if (x < 5) {
        return 1;
    }
// good
}

int no_return_int(int x) {
    if (x > 5)
        return 10;
    else if (x < 5) {
        return 1;
    }
// bad
}

int no_missing_return_int(int x) {
    if (x >= 5)
        return 10;
    else if (x < 5) {
        return 1;
    }
    x= 0;
// good
}

int missing_return_int(int x) {
    if (x > 5)
        return 10;
    else if (x < 5) {
        return 1;
    }
    x= 0;
// bad
}

int missing_return_try_catch(int x) {
    try {
        return (char)x;
    } catch (std::bad_cast e) {
        x = 0;
    }
// bad
}

int missing_return_try_catch1(int x) {
    try {
        x = 10;
    } catch (std::bad_cast e) {
        x = 0;
    }
// bad
}

int missing_return_try_catch2(int x) {
    try {
        x = 10;
    } catch (std::bad_cast e) {
        x = 0;
    }
    int result = x;
// bad
}

int missing_return_try_catch3(int x) {
    try {
        x = 10;
    } catch (std::bad_cast e) {
        x = 0;
    }
    int result = x;
    return result;
// good
}

int missing_return_try_catch4(int x) {
    try {
        return (char)x;
    } catch (std::bad_cast e) {
        x = 0;
        return x;
    }
// good
}

char case_return_int(int x) {
    switch (x) {
        case 5:
            return 1;
        case 0:
            return -1;
    }
// bad
}

int exit_return_int(int x) {
    if (x > 5) {
        exit(0);
    }
    return 1;
// good
}

bool always_true_miss() {
    int it = 0;
    int limit = 10;
    while (true) {
        if (it + 1 > limit) {
            return false;
        }
        it += 1;

        if (it % 3 == 0) {
            return true;
        }
        it += 2;
    }
// good
}

template<std::size_t I = 0, typename... vt>
inline typename std::enable_if<I == sizeof...(vt), void>::type
zax_to_json_(char* a_json, const char* a_json_buffer_end, int& a_result, const std::tuple<vt...>& a_tuple, bool a_insert_object_trails, int a_deep)
{
// good
}


template<typename T>
typename std::enable_if<(sizeof(T) > 4)>::type
foo() {
// good
}

template<typename T>
std::enable_if<(sizeof(T) > 4)>
foo4() {
// good
}

template<typename T>
std::enable_if_t<(sizeof(T) > 4)>
foo1() {
    return T();
// good
}

template<typename T,
        typename = std::enable_if_t<(sizeof(T) > 4)>>
void foo2() {
// good
}

template<typename T>
using EnableIfSizeGreater4 = std::enable_if_t<(sizeof(T) > 4)>;
template<typename T,
        typename = EnableIfSizeGreater4<T>>
void foo3() {
// good
}

template <typename T>
typename std::enable_if<std::is_integral<T>::value, bool>::type
is_odd(T t) {
    return bool(t%2);
// good
}
