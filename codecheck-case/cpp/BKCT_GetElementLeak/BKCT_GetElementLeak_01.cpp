//
// Created by wadema on 24-9-26.
//
// define:bkcheck(GetElementLeak)
void bad(jint value)
{
    // bad
    jstring jkey = (jstring)_env->GetObjectArrayElement(jobjArray, value);
}

void good_01()
{
    jsize arraysize = _env->GetArrayLength(jobjArray);

    for (int i = 0; i < arraysize; i++)
    {
        // good
        jstring jkey = (jstring)_env->GetObjectArrayElement(jobjArray, i);
    }
}

void good_02(jint value)
{
    jsize arraysize = _env->GetArrayLength(jobjArray);

    if (value < arraysize)
    {
        // good
        jstring jkey = (jstring)_env->GetObjectArrayElement(jobjArray, value);
    }
}

void good_03(jint value)
{
    jsize arraysize = _env->GetArrayLength(jobjArray);

    if (value >= arraysize)
    {
    }
    else
    {
        // good
        jstring jkey = (jstring)_env->GetObjectArrayElement(jobjArray, value);
    }
}
