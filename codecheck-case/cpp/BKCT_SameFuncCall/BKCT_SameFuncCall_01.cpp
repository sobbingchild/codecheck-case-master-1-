// defect:bkcheck(SameFuncCall)

Point ReadPoint() {
    // bad 此代码可能会导致 X 和 Y 值交换，因为不知道将首先计算这两个值中的哪一个。
    return Point(ReadFixed(), ReadFixed());
}

void bad() {
    // bad
    foo(bar(), bar());
}

// 正确的案例
Point ReadPoint() {
    float x = ReadFixed();
    return Point(x, ReadFixed());
}

// PVS 的案例
static BOOL dump_msft_custdata(seg_t *seg) {
    // bad
    printf("\\%2.2x \\%2.2x\n", tlb_read_byte(), tlb_read_byte());
    // ....
}

bool ComposerClient::CommandReader::parseSetLayerCursorPosition(uint16_t length) {
    if (length != CommandWriterBase::kSetLayerCursorPositionLength) {
        return false;
    }
    // bad
    auto err = mHal.setLayerCursorPosition(mDisplay, mLayer,
                                           readSigned(), readSigned());
    if (err != Error::NONE) {
        mWriter.setError(getCommandLoc(), err);
    }

    return true;
}