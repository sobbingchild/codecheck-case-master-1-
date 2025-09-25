// defect:bkcheck(ResourceLeak)

// 暗区突围项目的两个案例
template<typename ARRARY>
static std::string BuildAchievementData(const std::string &data_name, ARRARY &&arr) {
    // 创建反射实例
    auto descriptor =
            google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName("ua.protocol." + data_name);
    COND_RET_GID_ELOG(!descriptor, "", 0, "not find data type:name=%s", data_name.c_str());
    auto prototype = google::protobuf::MessageFactory::generated_factory()->GetPrototype(descriptor);
    auto instance = prototype->New();
    auto reflecter = instance->GetReflection();
    COND_RET_GID_ELOG(descriptor->field_count() != arr.size(), "", 0,
                      "field_count not equal arrary size:name=%s size=%u", data_name.c_str(), arr.size());
    int size = arr.size();
    for (int i = 0; i < size; ++i) {
        auto field_desc = descriptor->field(i);
        COND_RET_GID_ELOG(!field_desc, "", 0, "cannt find field desc:name=%s idx=%d", data_name.c_str(), i);
        auto node = reflecter->MutableMessage(instance, field_desc);
        COND_RET_GID_ELOG(!node, "", 0, "mutable field failed:name=%s idx=%d", data_name.c_str(), i);
        auto meta_node = dynamic_cast<ItopSnsMeta *>(node);
        COND_RET_GID_ELOG(!meta_node, "", 0, "dynamic cast failed:name=%s idx=%d", data_name.c_str(), i);
        int32_t type = field_desc->options().GetExtension(REPORT_TYPE);
        meta_node->set_type(type);
        meta_node->set_bcover(true);
        meta_node->set_expires("0");
        meta_node->set_data(arr[i]);
    }
    // bad
    return FromAchievements2List(*instance);
}

int CurlMultiMgr::PostHttpReq(const std::string &url, const std::string &req_body, uint64_t user_trans_id,
                              std::map <std::string, std::string> *headers, int port) {
    int ret = 0;

    CurlMultiTrans *free_trans = GetFreeTrans();
    if (NULL == free_trans) {
        WARN_LOG(0, "user_trans_id=0x%lx | no free trans! curl_trans_running_cnt_=%d", user_trans_id,
                 curl_trans_running_cnt_);
        return -1;
    }
    // 记录调用方的事务id
    free_trans->SetUserTransId(user_trans_id);

    // 设置url
    ret = curl_easy_setopt(free_trans->GetCurlHandle(), CURLOPT_URL, url.c_str());
    if (ret != CURLE_OK) {
        WARN_LOG(0, "user_trans_id=0x%lx | CURLOPT_URL err! ret=%d error=%s url=%s", user_trans_id, ret,
                 curl_easy_strerror((CURLcode) ret), url.c_str());
        return -1;
    }

    if (headers && !headers->empty()) {
        struct curl_slist *curl_headers = NULL;
        MakeReqheaders(&curl_headers, *headers);
        ret = curl_easy_setopt(free_trans->GetCurlHandle(), CURLOPT_HTTPHEADER, curl_headers);
        if (ret != CURLE_OK) {
            WARN_LOG(0, "user_trans_id=0x%lx | CURLOPT_PORT err! ret=%d error=%s url=%s port=%d", user_trans_id, ret,
                     curl_easy_strerror((CURLcode) ret), url.c_str(), port);
            // bad
            return -1;
        }
    }

    // 需要设定端口号, CURLOPT_PORT在libcurl中的默认就是0
    ret = curl_easy_setopt(free_trans->GetCurlHandle(), CURLOPT_PORT, port);
    if (ret != CURLE_OK) {
        WARN_LOG(0, "user_trans_id=0x%lx | CURLOPT_PORT err! ret=%d error=%s url=%s port=%d", user_trans_id, ret,
                 curl_easy_strerror((CURLcode) ret), url.c_str(), port);
        return -1;
    }

    // 必须先把string单独生成出来，如果直接调用setopt的话，会导致postfields为空，很奇怪。但是cookie又不会
    /* size of the data to copy from the buffer and send in the request */
    ret = curl_easy_setopt(free_trans->GetCurlHandle(), CURLOPT_POSTFIELDSIZE, req_body.length());
    if (ret != CURLE_OK) {
        WARN_LOG(0, "user_trans_id=0x%lx | CURLOPT_POSTFIELDSIZE err! ret=%d error=%s url=%s port=%d len=%zu",
                 user_trans_id, ret, curl_easy_strerror((CURLcode) ret), url.c_str(), port, req_body.length());
        return -1;;
    }

    /* send data from the local stack */
    ret = curl_easy_setopt(free_trans->GetCurlHandle(), CURLOPT_COPYPOSTFIELDS, req_body.c_str());
    if (ret != CURLE_OK) {
        WARN_LOG(0, "user_trans_id=0x%lx | CURLOPT_COPYPOSTFIELDS err! ret=%d error=%s url=%s port=%d", user_trans_id,
                 ret, curl_easy_strerror((CURLcode) ret), url.c_str(), port);
        return -1;
    }

    // 开启post参数
    ret = curl_easy_setopt(free_trans->GetCurlHandle(), CURLOPT_POST, 1);
    if (ret != CURLE_OK) {
        WARN_LOG(0, "user_trans_id=0x%lx | CURLOPT_POST err! ret=%d error=%s url=%s port=%d", user_trans_id, ret,
                 curl_easy_strerror((CURLcode) ret), url.c_str(), port);
        return -1;
    }

    // 开启一个异步事务
    ret = BeginTrans(free_trans);
    if (ret != 0) {
        WARN_LOG(0, "user_trans_id=0x%lx | BeginTrans err! ret=%d url=%s", user_trans_id, ret, url.c_str());
        return -1;
    }

    TRACE_LOG(0, "user_trans_id=0x%lx | BeginTrans succ! url=%s req_body=%s", user_trans_id, url.c_str(),
              req_body.c_str());

    return 0;
}