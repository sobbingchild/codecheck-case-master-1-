//
// Created by wadema on 24-6-24.
//
// defect:bkcheck(PBMaxsizeCheck)

void bad_01() {
    // bad
    for (int32_t i = 0; i < pbArcadeRsp.arcadeinfo_size(); i++) {

    }
}

void good_01() {
    // good
    for (int32_t i = 0; i < pbArcadeRsp.arcadeinfo_size() && i < pbArcadeRsp.get_arcadeinfo_maxsize(); i++) {

    }
}