//
// Created by wadema on 24-10-8.
//

// define:bkcheck(EntityEqualZero)

void bad()
{
    // bad
    igameEntity > 0; // 非法；
    // bad
    igameEntity < 0; // 非法；
    // bad
    0 >= igameentity; // 非法;
    // bad
    0 <= igameentity; // 非法;
}

void good()
{
    // good
    igameEntity == 0; // 合法；
    // good
    0 != igameentity; // 合法；
}
