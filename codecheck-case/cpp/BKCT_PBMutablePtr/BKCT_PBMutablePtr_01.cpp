//
// Created by wadema on 24-7-4.
//
// define:bkcheck(PBMutablePtr)

void bad()
{
    // bad
    pbSSTlogRelaySvrconnectionProblemFlow stFlow = *stPkgToSnd.mutable_pkgbody()->
                                                               mutable_sstlogrelaysvrconnectionproblemflow();
}

void good()
{
    // good
    pbSSTlogRelaySvrconnectionProblemFlow* pstFlow = stPkgToSnd.mutable_pkgbody()->
                                                                mutable_sstlogrelaysvrconnectionproblemflow();
    // good 使用引用去接收指针对象是合法的
    pbSSTlogRelaySvrConnectionProblemFlow& rstFlow = *stPkgToSnd.mutable_pkgbody()->
                                                                 mutable_sstlogrelaysvrconnectionproblemflow();
}
