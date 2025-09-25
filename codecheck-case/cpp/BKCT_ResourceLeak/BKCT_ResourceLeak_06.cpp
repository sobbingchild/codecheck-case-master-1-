// defect:bkcheck(ResourceLeak)
#include <memory>

int good_01() {
    // 智能指针不需要delete
    std::unique_ptr <PbSerialization> pb_serialization1(new PbSerialization());
    std::shared_ptr <PbSerialization> pb_serialization2(new PbSerialization());
    std::weak_ptr <PbSerialization> pb_serialization3(new PbSerialization());
    std::auto_ptr <PbSerialization> pb_serialization4(new PbSerialization());
}

int good_02() {
    // 智能指针不需要delete
    std::unique_ptr <PbSerialization> pb_serialization1;
    pb_serialization1 = new PbSerialization();
    std::shared_ptr <PbSerialization> pb_serialization2;
    pb_serialization2 = new PbSerialization();
}

void good_03() {
    int iMaxBuffBlockNum = 5;
    TBuffBlock *pBuffBlkRoot = new TBuffBlock[iMaxBuffBlockNum];
    m_oEntireBuffBlkMngPool.objPushBack(pBuffBlkRoot + i);
    //good 指针被转移到另一个变量中了
}

void good_04() {
    int i = 0;
    const int MAX_PRESS_TEST_SEND_NUM = 250;
    STDirPressTest *paoDirPressTestDataArray = (STDirPressTest *) malloc(
            MAX_PRESS_TEST_SEND_NUM * sizeof(STDirPressTest));
    if (NULL == paoDirPressTestDataArray) {
        LogMatpError("malloc STDirPressTest fail.");
        return;
    }

    int iThreadNum = 0;
    pthread_t aiThreadIDArrayNum[MAX_PRESS_TEST_SEND_NUM] = {0};

    int iIndex = 0;
    STDirPressTest &roCurDirPressTestData = paoDirPressTestDataArray[i];
    foo((void *) &roCurDirPressTestData);
    //good 指针被转移到另一个变量中了
}

void good_05() {
    RoleData *data = new RoleData();
    data->base_info.set_gid(gid);
    Role role(*data);
    role.CleanAuctionData();
    delete data;
    // good 已修复role
}

char *good_06(const std::string &mmap_file_name, uint32_t mem_size, bool &is_exist) {
    is_exist = true;
    uint32_t flag = 0;
    if (IsCreateDir(mmap_file_name, true, flag) != 0) {
        return nullptr;
    }
    int fd = open(mmap_file_name.c_str(), flag, 0666);  // open file
    if (fd < 0) {
        perror("open file fail:");
        return nullptr;
    }

    FileAutoPtr<int> tmp_file(fd);

    struct stat file_stat;
    if (fstat(fd, &file_stat) == -1) {
        perror("get file stat fail:");
        return nullptr;
    }
    //如果大小为0，姑且认为是一个新创建的文件吧
    if (file_stat.st_size == 0) {
        //设置新建文件的长度
        ftruncate(fd, mem_size);
        is_exist = false;
    }
    //将文件和内存中的一段空间建立映射
    char *file_buf = (char *) mmap(NULL, mem_size, PROT_WRITE, MAP_SHARED, fd, SEEK_SET);
    if (file_buf == MAP_FAILED) {
        perror("map file_write fail:");
        munmap(file_buf, mem_size);
        return nullptr;
    }
    //映射建立后，文件就可以关闭了，关闭了文件和内存之间的映射关系依然存在。
    close(tmp_file.Release());
    //将内存中的数据同步到文件即磁盘
    if (msync(file_buf, mem_size, MS_SYNC) == -1) {
        perror("msync fail:");
        munmap(file_buf, mem_size);
        return nullptr;
    }
    // good 修复tmp_file
    return file_buf;
}

const JLib::DBFieldIDSet good_07() {
    static JLib::DBFieldIDSet *g_pSet = NULL;
    if (NULL == g_pSet) {
        g_pSet = new JLib::DBFieldIDSet;
        g_pSet->insert(ECF_TagID);
        g_pSet->insert(ECF_RankType);
        g_pSet->insert(ECF_RankID);
    }
    // good 静态局部变量 待修复
    return *g_pSet;
}

void bad_01() {
    int iMaxBuffBlockNum = 5;
    TBuffBlock *pBuffBlkRoot = new TBuffBlock[iMaxBuffBlockNum];
    for (int32_t i = 0; i < iMaxBuffBlockNum; i++)
        m_oEntireBuffBlkMngPool.objPushBack(pBuffBlkRoot + i);
    // bad 数据流走循环的false分支导致的问题
}

void bad_02() {
    int i = 0;
    const int MAX_PRESS_TEST_SEND_NUM = 250;
    STDirPressTest *paoDirPressTestDataArray = (STDirPressTest *) malloc(
            MAX_PRESS_TEST_SEND_NUM * sizeof(STDirPressTest));
    if (NULL == paoDirPressTestDataArray) {
        LogMatpError("malloc STDirPressTest fail.");
        return;
    }

    int iThreadNum = 0;
    pthread_t aiThreadIDArrayNum[MAX_PRESS_TEST_SEND_NUM] = {0};

    int iIndex = 0;
    while (i < MAX_PRESS_TEST_SEND_NUM) {
        STDirPressTest &roCurDirPressTestData = paoDirPressTestDataArray[i];
    }
    // bad 数据流走循环的false分支导致的问题
}

void bad_03_04() {

    int i = 0;
    int iRet = 0;
    char szDirURL[64] = {0};
    snprintf(szDirURL, sizeof(szDirURL), "%s:%s", DIR_PRESS_IP, DIR_PRESS_DIR_PORT);
    unsigned long int ullUid = getpid() * 1000000 + 123456;
    unsigned int dwLogicWorldID = 1001;
    const int MAX_PRESS_TEST_SEND_NUM = 250;
    CMatpGameAccount *paoGameAccountArray = new CMatpGameAccount[MAX_PRESS_TEST_SEND_NUM * EACH_THREAD_MAX_ACCOUNT_NUM];
    if (NULL == paoGameAccountArray) {
        LogMatpError("new CMatpGameAccount fail.");
        return;
    }

    STDirPressTest *paoDirPressTestDataArray = (STDirPressTest *) malloc(
            MAX_PRESS_TEST_SEND_NUM * sizeof(STDirPressTest));
    if (NULL == paoDirPressTestDataArray) {
        LogMatpError("malloc STDirPressTest fail.");
        // bad
        return;
    }

    int iThreadNum = 0;
    pthread_t aiThreadIDArrayNum[MAX_PRESS_TEST_SEND_NUM] = {0};

    int iIndex = 0;
    while (i < MAX_PRESS_TEST_SEND_NUM) {
        STDirPressTest &roCurDirPressTestData = paoDirPressTestDataArray[i];
        for (int j = 0; j < EACH_THREAD_MAX_ACCOUNT_NUM; j++) {
            roCurDirPressTestData.m_poMatpGameAccount[j] = &paoGameAccountArray[iIndex + j];
        }

        StrCpy(roCurDirPressTestData.m_szURL, szDirURL, sizeof(roCurDirPressTestData.m_szURL));
        roCurDirPressTestData.m_ullUID = ullUid;
        roCurDirPressTestData.m_dwLogicWorldID = dwLogicWorldID;

        iRet = pthread_create(&aiThreadIDArrayNum[iThreadNum], NULL, g_DirPressTestThreadFunc,
                              (void *) &roCurDirPressTestData);
        if (iRet != 0) {
            LogMatpError("Start thread failed,index<%d>", iThreadNum);
        } else {
            iThreadNum++;
        }

        ullUid = ullUid + EACH_THREAD_MAX_ACCOUNT_NUM;
        iIndex = iIndex + EACH_THREAD_MAX_ACCOUNT_NUM;
        i = i + 1;
    }

    delete[] paoGameAccountArray;

    for (i = 0; i < iThreadNum; ++i) {
        pthread_join(aiThreadIDArrayNum[i], NULL);
    }
    // bad
    return;
}