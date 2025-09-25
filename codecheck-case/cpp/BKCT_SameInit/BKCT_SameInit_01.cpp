// defect:bkcheck(SameInit)

void bad_01() {
    String path, name;
    SplitFilename(strSavePath, &path, &name, NULL);
    CString spath(path.c_str());
    // bad
    CString sname(path.c_str());
}

void good_01() {
    String path, name;
    SplitFilename(strSavePath, &path, &name, NULL);
    CString spath(path.c_str());
    // good
    CString sname(name.c_str());
}

void bad_02() {
    while (true) {
        if (strstr(token, "playerscale")) {
            token = CommaParse(&text_p);
            skin->scale[0] = atof(token);
            // bad
            skin->scale[1] = atof(token);
            continue;
        }
        break;
    }
}

void good_02() {
    while (true) {
        if (strstr(token, "playerscale")) {
            token = CommaParse(&text_p);
            // good
            skin->scale[1] = skin->scale[0] = atof(token);
            continue;
        }
        break;
    }
}

uint AltOp::fixedLength() {
    uint l1 = exp1->fixedLength();
    // bad
    uint l2 = exp1->fixedLength();

    if (l1 != l2 || l1 == ~0u)
        return ~0;

    return l1;
}

AtomicComparator::ComparisonResult
IntegerComparator::compare(const Item &o1,
                           const AtomicComparator::Operator,
                           const Item &o2) const {
    const Numeric *const num1 = o1.as<Numeric>();
    // bad
    const Numeric *const num2 = o1.as<Numeric>();

    if (num1->isSigned() || num2->isSigned()) {

    }
}