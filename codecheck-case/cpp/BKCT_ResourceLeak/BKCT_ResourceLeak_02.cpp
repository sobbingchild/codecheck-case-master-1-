// defect:bkcheck(ResourceLeak)
#include <stdlib.h>


int bad_01() {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        return -1;
    }
    // ... 文件操作
    // bad 漏掉了 fclose(file);
    return 0;
}

void bad_02(int c) {
    FILE *p = fopen("foo.c", "rb");
    if (c)
        // bad
        return;       // leaking file pointer "p"
    fclose(p);
}

int bad_03(int c) {
    int fd = open(“my_file”, MY_OPEN_OPTIONS);
    if (c)
        // bad
        return -1;   // "fd" is leaked
    /* ... */
    close(fd);
    return 0;
}

int bad_04() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        return -1;
    }
    // ... 套接字操作
    // bad 漏掉了 close(sockfd);
    return 0;
}

int bad_05() {
    void *handle = dlopen("example_library.so", RTLD_LAZY);
    if (handle == NULL) {
        fprintf(stderr, "Error opening library: %s\n", dlerror());
        return -1;
    }
    // ... 动态库操作
    // bad 漏掉了 dlclose(handle);
    return 0;
}

int bad_06() {
    DIR *dir = opendir(".");
    if (dir == NULL) {
        perror("Error opening directory");
        return -1;
    }
    // ... 目录操作
    // bad 漏掉了 closedir(dir);
    return 0;
}

int bad_07(int argc, char *argv[]) {
    GtkWidget *window;
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    if (window == NULL) {
        return -1;
    }
    // ... 图形界面操作
    // bad 漏掉了 g_object_unref(window);
    return 0;
}

int bad_08() {
    FILE *fp = fopen("private_key.pem", "r");
    if (fp == NULL) {
        return -1;
    }
    RSA *rsa = PEM_read_RSAPrivateKey(fp, NULL, NULL, NULL);
    if (rsa == NULL) {
        fclose(fp);
        return -1;
    }
    // ... OpenSSL 操作
    fclose(fp);
    // bad 漏掉了 RSA_free(rsa);
    return 0;
}

int bad_09() {
    HANDLE hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
    if (hEvent == NULL) {
        return -1;
    }
    // ... 事件操作
    // bad 漏掉了 CloseHandle(hEvent);
    return 0;
}

int bad_10() {
    int fd = open("example.txt", O_RDONLY);
    if (fd < 0) {
        return -1;
    }

    struct stat sb;
    if (fstat(fd, &sb) < 0) {
        close(fd);
        return -1;
    }

    void *mapped = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (mapped == MAP_FAILED) {
        close(fd);
        return -1;
    }

    // ... 文件映射操作

    close(fd);
    // bad 漏掉了 munmap(mapped, sb.st_size);
    return 0;
}

int bad_11() {
    HANDLE hFile = CreateFile("example.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        return -1;
    }

    // ... 文件操作

    // bad 漏掉了 CloseHandle(hFile);
    return 0;
}

void bad_12() {
    auto descriptor =
            google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName("ua.protocol." + data_name);
    COND_RET_GID_ELOG(!descriptor, "", 0, "not find data type:name=%s", data_name.c_str());
    auto prototype = google::protobuf::MessageFactory::generated_factory()->GetPrototype(descriptor);
    // 创建一个堆上的对象，没有释放
    auto instance = prototype->New();
    auto reflecter = instance->GetReflection();
    COND_RET_GID_ELOG(descriptor->field_count() != arr.size(), "", 0,
                      "field_count not equal arrary size:name=%s size=%u", data_name.c_str(), arr.size());
    // bad instance 未释放
}

int bad_13(){
    // 创建消息对象
    MyMessage *msg = new MyMessage();
    // 使用消息对象...
    // 释放消息对象
    // bad 漏掉了delete msg;
    return 0;
}
