//
// Created by wadema on 24-6-26.
//
// defect:bkcheck(SnprintfParam)
void bad() {
    // bad
    snprintf(szSvnLastChgVersion, 100, "%s", SVNLASTCHGVER);
}

void good() {
    // good
    snprintf(szSvnLastChgVersion, sizeof(szSvnLastChgVersion), "%s", SVNLASTCHGVER);
}