// defect:bkcheck(ResourceLeak)
// 用户案例 总共1个报错
static pointer allocate() {
    const pointer ret = static_cast<pointer>(
            singleton_pool<fast_pool_allocator_tag, sizeof(T),
                    UserAllocator, Mutex, NextSize>::malloc());
    if (ret == 0)
        // 是boost库中退出函数
        boost::throw_exception(std::bad_alloc());
    // good
    return ret;
}

static BatchInfo *allocateBatch(unsigned int objectsPerPage) {
    const unsigned int mallocSize = sizeof(BatchInfo) - sizeof(AllocatedType) * objectPerAllocation
                                    + sizeof(AllocatedType) * objectPerAllocation * objectsPerPage;
    BatchInfo *batch = static_cast<BatchInfo *>( malloc(mallocSize));
    batch->next_ = 0;
    batch->used_ = batch->buffer_;
    batch->end_ = batch->buffer_ + objectsPerPage;
    // good
    return batch;
}

template<typename UserAllocator>
void *pool<UserAllocator>::malloc_need_resize() {
    // No memory in any of our storages; make a new storage,
    const size_type partition_size = alloc_size();
    const size_type POD_size = next_size * partition_size +
                               details::pool::ct_lcm<sizeof(size_type), sizeof(void *)>::value + sizeof(size_type);
    char *const ptr = UserAllocator::malloc(POD_size);
    if (ptr == 0)
        return 0;
    const details::PODptr <size_type> node(ptr, POD_size);
    //next_size <<= 1;

    //  initialize it,
    store().add_block(node.begin(), node.element_size(), partition_size);

    //  insert it into the list,
    node.next(list);
    list = node;

    //  and return a chunk from it.
    // good
    return store().malloc();
}

int load_data(const Option &option, FILE *src, char *&data, size_t &size) {
    assert(NULL != src);


    int ret = fseek(src, 0, SEEK_END);
    if (0 != ret) {
        cout << "Error: fseek failed" << endl;

        return -1;
    }

    long dataLen = ftell(src);
    if (0 > dataLen) {
        cout << "Error: ftell failed" << endl;

        return -1;
    } else if (0 == dataLen) {
        cout << "Error: file '" << option.srcDataFile << "' is empty" << endl;

        return -1;
    }

    ret = fseek(src, 0, SEEK_SET);
    if (0 != ret) {
        cout << "Error: fseek failed" << endl;

        return -1;
    }

    char *binaryData = (char *) malloc((size_t) dataLen);
    if (NULL == binaryData) {
        cout << "Error: failed to malloc memory" << endl;

        return -1;
    }

    size = fread(binaryData, 1, (size_t) dataLen, src);
    if (size < (size_t) dataLen) {
        cout << "Error: failed to read from file '" << option.srcDataFile << "'" << endl;

        free(binaryData);
        return -1;
    }

    if (Option::TYPE_HEX_STR != option.srcDataType) {
        data = binaryData;
        return 0;
    } else {
        char *hexData = binaryData;
        dataLen = dataLen - dataLen % 2;
        binaryData = (char *) malloc((size_t) dataLen / 2);
        if (NULL == binaryData) {
            cout << "Error: failed to malloc memory" << endl;

            free(hexData);
            return -1;
        } else {
            TdrReadBuf binaryBuf(binaryData, (size_t) dataLen / 2);
            TdrError::ErrorType tdrRet = binaryBuf.fromHexStr(hexData, (size_t) dataLen);
            if (TdrError::TDR_NO_ERROR != tdrRet) {
                cout << "Error: failed to construct net data from hex-string, for: "
                     << TdrError::getErrorString(tdrRet) << endl;

                free(binaryData);
                free(hexData);

                return -1;
            } else {
                data = binaryData;
                size = dataLen / 2;
                free(hexData);
                // good
                return 0;
            }
        }
    }
}

element_type *construct() {
    element_type *const ret = malloc();
    if (ret == 0)
        return ret;
    try { new(ret) element_type(); }
    catch (...) {
        free(ret);
        throw;
    }
    // good
    return ret;
}

int udp_socket_create(const char *bind_ip, unsigned short bind_port, char *err, unsigned int err_size) {
    int conn = socket(AF_INET, SOCK_DGRAM, 0);
    if (-1 == conn) {
        SNPRINTF(err, err_size, "create udp socket error(errno:%d error msg:%s)\n", errno, strerror(errno));
        // good
        return (-1);
    }

    /*设置fork close标志*/
    int flag = fcntl(conn, F_GETFD);
    if (flag != -1) {
        fcntl(conn, F_SETFD, flag | FD_CLOEXEC);
    }

    /*绑定ip及端口*/
    struct sockaddr_in addr;
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(bind_ip);
    addr.sin_port = htons(bind_port);

    /*这里不判断对错，因为api的udp绑定不是关键路径*/
    ::bind(conn, (struct sockaddr *) &addr, sizeof(struct sockaddr));

    return conn;
}

int NBlockTcpListen(const char *sHost, int nServ) {
    int iSockFd;
    int nRetSetOpt;
    int nRetBnd;
    int nOne;
    struct sockaddr_in rServaddr;

    memset(&rServaddr, 0, sizeof(rServaddr));
    rServaddr.sin_family = AF_INET;
    rServaddr.sin_port = htons((unsigned short) nServ);

    if (sHost == NULL)
        rServaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    else
        rServaddr.sin_addr.s_addr = inet_addr(sHost);

    if ((iSockFd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        // good
        return -1;

    if (SetSockNonBlock(iSockFd) < 0) {
        close(iSockFd);
        return -1;
    }

    nOne = 1;
    if ((nRetSetOpt = setsockopt(iSockFd, SOL_SOCKET, SO_REUSEADDR, (char *) &nOne, sizeof(nOne))) != 0) {
        close(iSockFd);
        return -1;
    }

    if ((nRetBnd = bind(iSockFd, (struct sockaddr *) &rServaddr, sizeof(rServaddr))) < 0) {
        close(iSockFd);
        return -1;
    }

    if (listen(iSockFd, MAX_SOCKQUEUE_LEN) < 0) {
        close(iSockFd);
        return -1;
    }

    return iSockFd;
}

int fprintf(FILE *stream, const char *format, char *b) {
    return 1;
}

int WriteTestLogFrap(unsigned char *szInputBuf, uint32_t dwInputLen) {
    //写入base64
    static FILE *fp = fopen("/data/home/user00/frap.cap", "w");
    static char szDstBuf[10240];
    szDstBuf[0] = '\0';
    if (!Base64Encode(szInputBuf, dwInputLen, szDstBuf, _countof(szDstBuf) - 1)) {
        ASSERT_RETURN(false, 0);
    }
    fprintf(fp, "%s\n", szDstBuf);
    // good 排除静态局部变量，静态变量的生命周期是整个程序运行期间，而不是函数的执行期间。如果没有显式调用fclose关闭文件，文件资源将在程序结束时自动释放。
    return 0;
}

void *cl5::Cl5FileMapper::MapFile(const char *file, unsigned int size) {
    void *addr = nullptr;
    int fd = open(file, 00 | 0200);
    if (-1 == fd)
        return nullptr;

    addr = mmap(nullptr, size, 0x1, 0x01, fd, 0);
    close(fd);
    // good
    return ((((void *) -1) != addr) ? addr : nullptr);
}

int CPoxisShmMgr::AttachShm(void **const ppShmRoot, const char *szModuleName, size_t iShmSize, const bool bCreate,
                            bool &bNew, SHM_BASE_CTRL *pstBaseCtrl) {
    bool bIsAbsPath = false;
    if (NULL == ppShmRoot || NULL == szModuleName || 0 == szModuleName[0] || 0 == iShmSize || m_dwPageSize <= 0) {
        SET_ERRMSG("invalid param or not init");
        return -1;
    }

    uint32_t dwShmCtrlSize = 0;

    if (pstBaseCtrl) {
        pstBaseCtrl->m_ullTotalSize = iShmSize;
        if (pstBaseCtrl->m_eControlFlag == SHM_CTRL_FLAG_GUARDPAGE) {
            if (pstBaseCtrl->m_dwTotalNum == 0 || pstBaseCtrl->m_dwSingleSize == 0) {
                SET_ERRMSG("Totalnum or SingleSize not init");
                return -1;
            }
            size_t iPageSize = m_dwPageSize;
            pstBaseCtrl->m_dwSingleAllocShmSize = (pstBaseCtrl->m_dwSingleSize / iPageSize) * iPageSize;
            if (0 != pstBaseCtrl->m_dwSingleSize % iPageSize) {
                pstBaseCtrl->m_dwSingleAllocShmSize = (pstBaseCtrl->m_dwSingleSize / iPageSize + 1) * iPageSize;
            }

            //修正pageguard下的totalsize
            size_t iTotalAllocShmSize = (pstBaseCtrl->m_dwSingleAllocShmSize + iPageSize) * pstBaseCtrl->m_dwTotalNum;
            pstBaseCtrl->m_ullTotalSize = iTotalAllocShmSize;
            //修正pageguard下的新的ctrlsize
            pstBaseCtrl->m_dwShmCtrlSize = (sizeof(SHM_BASE_CTRL) / iPageSize + 1) * iPageSize;

            dwShmCtrlSize = pstBaseCtrl->m_dwShmCtrlSize;
            iShmSize = pstBaseCtrl->m_ullTotalSize;
        } else if (pstBaseCtrl->m_eControlFlag == SHM_CTRL_FLAG_SKIPUSE) {
            dwShmCtrlSize = 0;
        } else {
            SET_ERRMSG("Param Illegal");
            return -1;
        }
    } else {
        //默认一定有控制块
        static SHM_BASE_CTRL stBaseCtrl;
        pstBaseCtrl = &stBaseCtrl;
        pstBaseCtrl->m_ullTotalSize = iShmSize;
        dwShmCtrlSize = pstBaseCtrl->m_dwShmCtrlSize;
    }
    if (dwShmCtrlSize > 0) {
        if (pstBaseCtrl->m_dwShmCtrlSize == 0 || pstBaseCtrl->m_ullTotalSize == 0) {
            SET_ERRMSG("ShmCtrlSize or TotalSize not init");
            return -1;
        }
    }

    bNew = false;

    char szAbsFileName[POXIS_MAX_FILE_PATH_LEN];

    size_t len = 0;
    if (!bIsAbsPath) //允许设置为绝对路径，用于进程之间交互使用
    {
        len = snprintf(szAbsFileName, POXIS_MAX_FILE_PATH_LEN, "%s/%s.shm", m_szBasePath, szModuleName);
    } else {
        len = snprintf(szAbsFileName, POXIS_MAX_FILE_PATH_LEN, "%s.shm", szModuleName);
    }

    if (len >= POXIS_MAX_FILE_PATH_LEN || len < 0) {
        SET_ERRMSG("filepath too long ");
        return -9;
    }

    if (m_shmInfoSet.count(szAbsFileName)) {
        SET_ERRMSG("dumplicated modulename");
        return -10;
    }
    m_shmInfoSet.insert(szAbsFileName);

    *ppShmRoot = NULL;

    size_t dwRealShmSize = iShmSize + dwShmCtrlSize;

    size_t dwRealShmAllignSize = PAGE_ALLIGN(dwRealShmSize);
    int fd = open(szAbsFileName, O_RDWR);

    if (fd >= 0) {
        struct stat stFileStat;
        memset(&stFileStat, 0, sizeof(stFileStat));
        fstat(fd, &stFileStat);

        if (0 != stFileStat.st_size && stFileStat.st_size != (off_t) dwRealShmAllignSize) {
            SET_ERRMSG("module size not equal file size");
            close(fd);
            return -4;
        }
        if (0 == stFileStat.st_size) {
            bNew = true;
        }
    } else if (bCreate) {
        fd = open(szAbsFileName, O_RDWR | O_CREAT | O_EXCL, 0640);
        if (fd < 0) {
            SET_ERRMSG(strerror(errno));
            return -2; //打开失败才新建的，新建失败不管errno直接失败
        } else {
            bNew = true;
        }
    } else {
        SET_ERRMSG("open fail while no create flag");
        return -11;
    }

    if (bNew) {
        if (0 != ftruncate(fd, dwRealShmAllignSize)) {
            SET_ERRMSG(strerror(errno));
            close(fd);
            return -5;
        }
    }
    void *const pRealShmRoot = mmap(NULL, dwRealShmAllignSize, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
    close(fd);

    if (pRealShmRoot == NULL || (int64_t)(pRealShmRoot) == -1) {
        SET_ERRMSG(strerror(errno));
        // bad 这里有一点争议，先告警出来
        return -3;
    }
    *ppShmRoot = (void *) ((char *) (pRealShmRoot) + dwShmCtrlSize);

    if (dwShmCtrlSize > 0) {
        if (!pstBaseCtrl) {
            SET_ERRMSG("BaseCtrl Not Ok");
            return -12;
        }
        SHM_BASE_CTRL *pstOldBaseCtrl = (SHM_BASE_CTRL *) pRealShmRoot;
        if (bNew) {
            pstOldBaseCtrl->m_dwTotalNum = pstBaseCtrl->m_dwTotalNum;
            pstOldBaseCtrl->m_dwSingleSize = pstBaseCtrl->m_dwSingleSize;
            pstOldBaseCtrl->m_ullTotalSize = pstBaseCtrl->m_ullTotalSize;
            pstOldBaseCtrl->m_dwShmCtrlSize = pstBaseCtrl->m_dwShmCtrlSize;
            pstOldBaseCtrl->m_eControlFlag = pstBaseCtrl->m_eControlFlag;
        } else {
            if (pstOldBaseCtrl->m_dwTotalNum != pstBaseCtrl->m_dwTotalNum ||
                pstOldBaseCtrl->m_dwSingleSize != pstBaseCtrl->m_dwSingleSize ||
                pstOldBaseCtrl->m_ullTotalSize != pstBaseCtrl->m_ullTotalSize ||
                pstOldBaseCtrl->m_dwShmCtrlSize != pstBaseCtrl->m_dwShmCtrlSize ||
                pstOldBaseCtrl->m_eControlFlag != pstBaseCtrl->m_eControlFlag) {
                SET_ERRMSG("module size not equal file size");
                return -6;
            }
        }

        if (pstBaseCtrl->m_eControlFlag == SHM_CTRL_FLAG_GUARDPAGE) {
            if (pstBaseCtrl->m_dwSingleAllocShmSize < m_dwPageSize) {
                SET_ERRMSG("BaseCtrl Not Ok");
                return -12;
            }
            for (uint32_t i = 0; i < pstBaseCtrl->m_dwTotalNum; ++i) {
                char *pObjAddr = (char *) (*ppShmRoot) + (uint64_t) pstBaseCtrl->m_dwSingleAllocShmSize * i +
                                 (uint64_t) m_dwPageSize * i;
                char *pMemProtectAddr = pObjAddr + pstBaseCtrl->m_dwSingleAllocShmSize;
                int iRet = mprotect((void *) pMemProtectAddr, m_dwPageSize, PROT_NONE);
                if (iRet != 0) {
                    SET_ERRMSG("mprotect error");
                    return -6;
                }
            }
        }
    }

    return 0;
}

vector <string> LogCleaner::GetOverdueLogNames(
        string log_directory, unsigned int days, const string &base_filename,
        const string &filename_extension) const {
    // The names of overdue logs.
    vector <string> overdue_log_names;

    // Try to get all files within log_directory.
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(log_directory.c_str()))) {
        while ((ent = readdir(dir))) {
            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
                continue;
            }

            string filepath = ent->d_name;
            const char *const dir_delim_end =
                    possible_dir_delim + sizeof(possible_dir_delim);

            if (!log_directory.empty() &&
                std::find(possible_dir_delim, dir_delim_end,
                          log_directory[log_directory.size() - 1]) != dir_delim_end) {
                filepath = log_directory + filepath;
            }

            if (IsLogFromCurrentProject(filepath, base_filename, filename_extension) &&
                IsLogLastModifiedOver(filepath, days)) {
                overdue_log_names.push_back(filepath);
            }
        }
        closedir(dir);
    }

    return overdue_log_names;
}

void SimpleNonRpcServiceImpl() {
    auto handler = new trpc::NonRpcMethodHandler(std::bind(
            &SimpleNonRpcServiceImpl::Execute, this, std::placeholders::_1, std::placeholders::_2,
            std::placeholders::_3));
    // good
    AddNonRpcServiceMethod(new trpc::NonRpcServiceMethod(trpc::kNonRpcName, trpc::MethodType::UNARY, handler));
}