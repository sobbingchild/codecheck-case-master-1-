// defect:bkcheck(ResourceLeak)


#include <string>

class util
{
public:
    static int CreateFile(std::string path)
    {
        int fd;
        OpenFile(path, &fd);
        return CloseFile(fd);
    }
};


int CreateBlockTask(std::string path)
{
    // good 用户自定义的函数不检查
    int f = util::CreateFile(path);
    return kSuccess;
}
