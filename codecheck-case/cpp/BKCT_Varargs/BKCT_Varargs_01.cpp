// defect:bkcheck(Varargs)
#include <stdarg.h>

void bad(va_list ap, int s, int n, ...)
{
    va_list va;
    va_start(va, s);

    va_list va1;
    va_start(va1, s);

    int d = va_arg(ap, int);
    if (n > 3)
    {
        va_list ap2;
        va_copy(ap2, va);
        if (n > 5)
        {
            va_end(ap2);
            va_end(va);
            // bad:退出函数前可能存在未调用 va_end 释放 va_list va1
            return;
        }
    }
    va_end(va);
    va_end(va1);
    // bad:退出函数前可能存在未调用 va_end 释放 va_list ap2
}

void missing_vaend(char* s, ...)
{
    va_list va;
    va_start(va, s); // va_init - va_start is called on va
    vfprintf(log, s, ap);
    // bad
} // missing_va_end - reached end of function without calling va_end

void missing_vastart(int n, ...)
{
    va_list va;
    while (n-- > 0)
    {
        // bad
        int c = va_arg(va, int); // va_arg - va has not been initialized
    }
}

// 用户案例
int AjsTask::QueryBatch(/*out*/Json::Value& result, const std::list<string>& jobs, ...)
{
    va_list argp;
    char* field;
    va_start(argp, jobs);
    string selectField;
    bool is_first_field = true;

    while ((field = va_arg(argp, char *)) != NULL)
    {
        if (!is_first_field)
        {
            selectField.append("|");
        }
        else
        {
            is_first_field = false;
        }

        selectField.append(field);
    }

    va_end(argp);
    return AjsTask::QueryBatch2(result, jobs, selectField);
}
