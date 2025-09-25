// defect:bkcheck(ReverseNegative)

int SIndependentCardDesc::DoCaculateWinHandsForNonSplitGame(SIndependentCardDesc *va, SIndependentCardDesc *vb) {
    do {
        itercnt++;

        opnUser = (curUser + 1) % 2;
        int curUserCardIndex = userIndexs[curUser];
        userIndexs[curUser]--;
        curUserCardIndex--;

        // good 修复
        if (curUserCardIndex < 0 && opnUserCardIndex >= 0) {
            curUser = opnUser;
        } else if (opnUserCardIndex >= 0 &&
                   (rankPoint[curUser][curUserCardIndex] <= rankPoint[opnUser][opnUserCardIndex])) {
            if (rankPoint[curUser][curUserCardIndex] >= rankPoint[opnUser][cardTopIndex[opnUser]]) {
                curUser = curUser;
            } else {
                curUser = opnUser;
            }
        }
        // good 修复
        if ((curUserCardIndex < 0 && opnUserCardIndex < 0)) break;
    } while (1);

    return iRetWinHand;
}
void good(){
    short shKeyNum = 0;
    int iCubeID = 0;
    short shStrLength = 0;
    short shFieldNum = 0;
    int aiKeys[MAX_CUBE_KEY_NUM];
    TRspField stRspField;
    m_shRecordNum = 0;

    stDecoder >> m_uiUin >> iCubeID >> shKeyNum;
    // good 修复
    if(shKeyNum > MAX_CUBE_KEY_NUM)
    {
        shKeyNum = MAX_CUBE_KEY_NUM;
    }
}
int giGetSHAByFd(int aiFd, int aiPos, int aiSize, char OutBuff[41])
{
    const int INPUTLEN = 1024 * 1024;
    int liRet=0;
    int liSize=0;
    char sKey[20]={0};
    CSHA_INFO tInfo ;
    memset(&tInfo, 0x0, sizeof(CSHA_INFO));
    int len = 0;
    unsigned char input[INPUTLEN];
    memset(input,0,INPUTLEN);
    memset(OutBuff,0,41);
    if (aiSize==-1)
    {
        struct stat tFileStat={0};
        liRet=fstat(aiFd, &tFileStat);
        if (liRet!=0) return -1;
        liSize=tFileStat.st_size - aiPos;
    }
    else
        liSize=aiSize;
    if (lseek(aiFd,aiPos,SEEK_SET) < 0)
        return -2;

    sha_init(&tInfo);

    while(liSize>0)
    {
        if (liSize>=INPUTLEN)
            len = read(aiFd, input, INPUTLEN);
        else
            len = read(aiFd, input, liSize);
        liSize -= len;
        if(len <= 0) break;
        if(len % 8) memset(&input[len], 0, 8 - len % 8);
        sha_update(&tInfo, input, len);
    }
    sha_final((unsigned char *)sKey, &tInfo);
    // good 修复
    if(len < 0) return -2;
    sha_output((unsigned char *)sKey,(unsigned char *)OutBuff);
    return 0;
}