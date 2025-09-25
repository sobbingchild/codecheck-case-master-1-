// defect:bkcheck(ResourceLeak)
#include <iostream>
#include <cstdlib>  // 包含 posix_memalign 的头文件
#include <cstring>  // 包含 memset 的头文件
// 参数
// void **memptr: 指向分配的内存块的指针的指针。成功时，这个指针将指向分配的内存块。
// size_t alignment: 对齐方式，必须是 2 的幂，并且是 sizeof(void *) 的倍数。
// size_t size: 要分配的内存块的大小（以字节为单位）。
// 返回值
// 成功时返回 0。
// 失败时返回一个错误码，例如 EINVAL（无效参数）或 ENOMEM（内存不足）。
int posix_memalign(void** memptr, size_t alignment, size_t size);

int bad()
{
    void* ptr = nullptr;
    size_t alignment = 64; // 64 字节对齐
    size_t size = 1024; // 分配 1024 字节

    int result = posix_memalign(&ptr, alignment, size);
    if (result != 0)
    {
        std::cerr << "posix_memalign failed with error code: " << result << std::endl;
        return 1;
    }

    // 使用分配的内存
    std::memset(ptr, 0, size);

    // 释放分配的内存
    // free(ptr);
    // bad 未释放
    return 0;
}

// 用户案例
int FileManager::UpdateData(HashManager* hm)
{
    char* read_buf = NULL;
    uint64_t read_buf_len = m_shard_filelist.m_max_file_size;
    posix_memalign(reinterpret_cast<void**>(&read_buf), BLOCK_SIZE,
                   m_shard_filelist.m_max_file_size);
    if (read_buf == NULL)
    {
        return LSH_NEW_MEMORY_FAILED;
    }
    for (uint32_t i = 0; i < m_shard_filelist.m_max_fid; ++i)
    {
        int ret = ScanFileData(hm, df, i, read_buf);
        if (ret != LSH_SUCCESS)
        {
            DTXLOG(_TX_CODE_LINE, ERROR, "Scan file data failed, ret %d", ret);
            free(read_buf);
            return ret;
        }
    }
    // good 释放分配的内存
    free(read_buf);
    return LSH_SUCCESS;
}
