//
// Created by wadema on 24-6-24.
//
// defect:bkcheck(PBNoCopyFrom)

void bad_01(){
    // bad
    pstReq->mutable_acntrecommendinfo()->CopyFrom(rpbAcntRecommendInfo);
}