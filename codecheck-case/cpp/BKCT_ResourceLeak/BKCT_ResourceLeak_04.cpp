// defect:bkcheck(ResourceLeak)
// 第二种场景
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int bad_01() {
    pthread_t thread;
    if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {
        return -1;
    }
    // ... 其他操作
    // bad 漏掉了 pthread_join(thread, NULL);
    return 0;
}

int bad_02() {
    pthread_mutex_t mutex;
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        return -1;
    }
    // ... 互斥锁操作
    // bad 漏掉了 pthread_mutex_destroy(&mutex);
    return 0;
}

int bad_03() {
    pthread_cond_t cond;
    if (pthread_cond_init(&cond, NULL) != 0) {
        return -1;
    }
    // ... 条件变量操作
    // bad 漏掉了 pthread_cond_destroy(&cond);
    return 0;
}

int bad_04() {
    sem_t sem;
    if (sem_init(&sem, 0, 1) != 0) {
        return -1;
    }
    // ... 信号量操作
    // bad 漏掉了 sem_destroy(&sem);
    return 0;
}

void curl_easy_setopt(CURL *curl, int i, curl_slist* slist) {

}

int bad_05() {
    CURL *curl = curl_easy_init();
    if (curl) {
        struct curl_slist *curl_headers = NULL;
        std::string header_str = "Content-Type: application/json";

        // 添加头信息
        curl_headers = curl_slist_append(curl_headers, header_str.c_str());

        // 设置 CURL 选项，例如 URL、POST 数据等

        // 设置头信息
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, curl_headers);

        // 执行 CURL 请求
        CURLcode res = curl_easy_perform(curl);


        //curl_slist_free_all(curl_headers);

        // 清理 CURL
        curl_easy_cleanup(curl);
    }
    // bad 未清理头信息
    return 0;
}

int bad_06() {
    pthread_t thread;
    int i = pthread_create(&thread, NULL, thread_function, NULL);
    if (i != 0) {
        return -1;
    }
    // ... 其他操作
    // bad 漏掉了 pthread_join(thread, NULL);
    return 0;
}

int good_01() {
    pthread_t thread;
    if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {
        return -1;
    }
    // ... 其他操作
    // good
    pthread_join(thread, NULL);
    return 0;
}

int good_02() {
    pthread_mutex_t mutex;
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        return -1;
    }
    // ... 互斥锁操作
    // good
    pthread_mutex_destroy(&mutex);
    return 0;
}

int good_03() {
    pthread_cond_t cond;
    if (pthread_cond_init(&cond, NULL) != 0) {
        return -1;
    }
    // ... 条件变量操作
    // good
    pthread_cond_destroy(&cond);
    return 0;
}

int good_04() {
    sem_t sem;
    if (sem_init(&sem, 0, 1) != 0) {
        return -1;
    }
    // ... 信号量操作
    // good
    sem_destroy(&sem);
    return 0;
}

int good_05() {
    CURL *curl = curl_easy_init();
    if (curl) {
        struct curl_slist *curl_headers = NULL;
        std::string header_str = "Content-Type: application/json";

        // 添加头信息
        curl_headers = curl_slist_append(curl_headers, header_str.c_str());

        // 设置 CURL 选项，例如 URL、POST 数据等

        // 设置头信息
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, curl_headers);

        // 执行 CURL 请求
        CURLcode res = curl_easy_perform(curl);

        // good 清理头信息
        curl_slist_free_all(curl_headers);

        // 清理 CURL
        curl_easy_cleanup(curl);
    }

    return 0;
}