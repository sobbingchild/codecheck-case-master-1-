// defect:bkcheck(LogParamsNotMatch)
#define UL_LOGLINE(x) #x

#define test1(format, ...) log_trace(format,##__VA_ARGS__)

#define test2(format, ...) log_raw(format,##__VA_ARGS__)

#define test3(format, ...) log_normal_rs(format,##__VA_ARGS__)

#define test4(format, ...) \
    do{ \
        log_trace("[%s][%u]" format, _task_name.c_str(),_msg_seq, ##__VA_ARGS__);\
    }while (0)

#define log_trace(format, arg...) \
    do{ \
        if (alog::GetLogLevel() <= alog::LOG_TRACE) {\
            alog::WriteLog(alog::LOG_TRACE, "- " format " [" __FILE__ ":" UL_LOGLINE(__LINE__) "]\n",##arg);\
        }\
    }while (0)

#define log_raw(format, arg...) \
    do{ \
        alog::RawWriteLog(alog::LOG_NORMAL,format,##arg); \
    }while (0)

#define log_normal_rs(format, arg...) \
    do{ \
        if (alog::GetLogLevel() <= alog::LOG_NORMAL) {\
            alog::RSWriteLog(alog::LOG_NORMAL,__FILE__,__LINE__, \
            "- " format " [" __FILE__ ":" UL_LOGLINE(__LINE__) "]\n",##arg);\
        }\
    }while (0)

void bad_01() {
    // bad
    WriteLog(1, "hello %s world %d", a);
    // bad
    RawWriteLog(1, "hello %s world %d", a);
    // bad
    RSWriteLog(1, file, 1, "hello %s world %d", a);
}

void bad_02() {
    // bad
    test1("hello %s world %d", a);
    // bad
    test2("hello %s world %d", a);
    // bad
    test3("hello %s world %d", a);
    // bad
    test4("hello %s world %d", a);
}

