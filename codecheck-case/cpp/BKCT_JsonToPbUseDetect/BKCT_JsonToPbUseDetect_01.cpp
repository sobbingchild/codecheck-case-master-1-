// defect:bkcheck(JsonToPbUseDetect)

void bad_01() {
    // bad
    Comm::pb2json::RapidPb2Json(req, &value); // 尽量使用Comm::NewJson2Pb而不是Comm::pb2json::RapidPb2Json
}

void bad_02() {
    if (true) {
        // bad
        Comm::pb2json::RapidPb2Json(req, &value); // 尽量使用Comm::NewJson2Pb而不是Comm::pb2json::RapidPb2Json
    }
}

void bad_03() {
    while (true) {
        // bad
        Comm::pb2json::RapidPb2Json(req, &value); // 尽量使用Comm::NewJson2Pb而不是Comm::pb2json::RapidPb2Json
    }
}

void bad_04() {
    try {
        // bad
        Comm::pb2json::RapidPb2Json(req, &value); // 尽量使用Comm::NewJson2Pb而不是Comm::pb2json::RapidPb2Json
    } catch (declaration) {

    }
}

void good() {
    // good
    Comm::NewJson2Pb(args, &req);
}