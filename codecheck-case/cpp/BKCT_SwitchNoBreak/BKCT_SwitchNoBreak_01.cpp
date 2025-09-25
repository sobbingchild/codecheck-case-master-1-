void test() {
	switch (m_oApplyment.applyment_state()) {
        case MERCHANT_APPLYMENT_STATE_INIT:    //初始化
        {
            OssAttrInc(126891, 39, 1);
            objResp.set_applyment_state(APPLY_4MOBILE_STATE_EDIT);
            strBizRetMsg = "初始化";
            break;
        }
		// good
        case MERCHANT_APPLYMENT_STATE_EDIT:    //编辑
        {
            //查询主体申请单状态
            if(ddwSubjectApplymentId != 0)
            {
                OssAttrInc(126891, 40, 1);
                mmpaymchmgrapply4subjectuseraosvr::GetApplymentProgressReq oGetApplymentProgressReq;
                mmpaymchmgrapply4subjectuseraosvr::GetApplymentProgressResp oGetApplymentProgressResp;
                oGetApplymentProgressReq.set_source(m_oReq.source());
                oGetApplymentProgressReq.set_applyment_id(ddwSubjectApplymentId);
                iRetCode = Mmpaymchmgrapply4subjectuseraosvrClient().GetApplymentProgress(Comm::GetRandomUin(), oGetApplymentProgressReq, oGetApplymentProgressResp);
                oWTimeElf.AddTimeMark("GetApplymentProgress", iRetCode);
                if (iRetCode != 0)
                {
                    OssAttrInc(126891, 41, 1);
                    strErrMsg = oGetApplymentProgressResp.ret_msg();
                    strErrMsg = "GetApplymentProgress error|" + strErrMsg;
                    strBizRetMsg = "错误（" + std::to_string(iRetCode) + "）：未能找到主体申请单";
                    PLOG_ERR("GetApplymentProgress",iRetCode, "req=%s|resp=%s|Req=%s", DUMP_PB(oGetApplymentProgressReq), DUMP_PB(oGetApplymentProgressResp), DUMP_PB(m_oReq));
                    return iRetCode;
                }
                objResp.set_subject_type(oGetApplymentProgressResp.subject_type());
                if(oGetApplymentProgressResp.progress() == "INIT")
                {//初始化 (正常情况下 不存在)
                    OssAttrInc(126891, 42, 1);
                    objResp.set_applyment_state(APPLY_4MOBILE_STATE_SUBJECT_INIT);
                    strBizRetMsg = "主体申请未完成-初始化";
                    break;
                }else if(oGetApplymentProgressResp.progress() == "EDIT")
                {//编辑中
                    OssAttrInc(126891, 43, 1);
                    objResp.set_applyment_state(APPLY_4MOBILE_STATE_SUBJECT_EDIT);
                    strBizRetMsg = "主体申请未完成-编辑中";
                    break;
                }else if(oGetApplymentProgressResp.progress() == "WAIT_FINANCIAL_AUDIT")
                {//待账户验证
                    OssAttrInc(126891, 44, 1);
                    objResp.set_applyment_state(APPLY_4MOBILE_STATE_SUBJECT_WAIT_FINANCIAL_AUDIT);
                    strBizRetMsg = "主体申请未完成-待账户验证";
                    break;
                }else if(oGetApplymentProgressResp.progress() == "FINANCIAL_AUDIT_SUCCESS")
                {//账户验证成功
                    OssAttrInc(126891, 45, 1);
                    objResp.set_applyment_state(APPLY_4MOBILE_STATE_SUBJECT_FINANCIAL_AUDIT_SUCCESS);
                    strBizRetMsg = "主体申请未完成-账户验证成功";
                    break;
                }else if(oGetApplymentProgressResp.progress() == "FREEZE")
                {//已冻结
                    OssAttrInc(126891, 46, 1);
                    objResp.set_applyment_state(APPLY_4MOBILE_STATE_SUBJECT_FREEZE);
                    strBizRetMsg = "主体申请未完成-已冻结";
                    break;
                }else if(oGetApplymentProgressResp.progress() == "REJECT")
                {//已驳回
                    OssAttrInc(126891, 47, 1);
                    objResp.set_applyment_state(APPLY_4MOBILE_STATE_SUBJECT_REJECT);
                    strBizRetMsg = "主体申请未完成-已驳回";
                    break;
                }else if(oGetApplymentProgressResp.progress() == "FINISH")
                {//已完成
                    OssAttrInc(126891, 48, 1);
                    objResp.set_applyment_state(APPLY_4MOBILE_STATE_EDIT);
                    strBizRetMsg = "未提交";
                    //主体名称为空，需要从主体领域拷贝主体信息
                    if(objResp.subject_name().empty())
                    {
                        //查主体id
                        uint64_t ddwSubjectId = 0;
                        mmpaymchmgrapply4subjectuseraosvr::GetMerchantApplymentReq oGetMerchantApplymentReq;
                        mmpaymchmgrapply4subjectuseraosvr::GetMerchantApplymentResp oGetMerchantApplymentResp;
                        oGetMerchantApplymentReq.set_source(m_oReq.source());
                        oGetMerchantApplymentReq.set_option(1); //option = 1  返回 subject_archives.subject_id
                        oGetMerchantApplymentReq.set_applyment_id(ddwSubjectApplymentId);
                        iRetCode = Mmpaymchmgrapply4subjectuseraosvrClient().GetMerchantApplyment(Comm::GetRandomUin(), oGetMerchantApplymentReq, oGetMerchantApplymentResp);
                        oWTimeElf.AddTimeMark("GetMerchantApplyment", iRetCode);
                        if (iRetCode != 0)
                        {
                            OssAttrInc(126900, 14, 1);
                            strErrMsg = "Subject GetMerchantApplyment error|" + oGetMerchantApplymentResp.ret_msg();
                            strBizRetMsg = "错误（" + std::to_string(iRetCode) + "）：未能找到主体申请单";
                            PLOG_ERR("GetMerchantApplyment",iRetCode, "req=%s|resp=%s|Req=%s", DUMP_PB(oGetMerchantApplymentReq), DUMP_PB(oGetMerchantApplymentResp), DUMP_PB(m_oReq));
                            return iRetCode;
                        }
                        ddwSubjectId = oGetMerchantApplymentResp.subject_archives().subject_id();
                        if(ddwSubjectId == 0)
                        {
                            OssAttrInc(126900, 39, 1);
                            iRetCode = ERR_MCHAPPLY_APPLY4MOBILEUSER_SUBJECTID_EMPTY;
                            strErrMsg = "ddwSubjectId empty.";
                            strBizRetMsg = "错误（" + std::to_string(iRetCode) + "）：未能找到主体申请单";
                            PLOG_ERR("ddwSubjectId empty.",iRetCode, "m_oReq=%s", DUMP_PB(m_oReq));
                            return iRetCode;
                        }

                        //保存主体资料
                        mmpaymchmgrapply4mobileuseraosvr::SaveSubjectInfoReq oSaveSubjectInfoReq;
                        oSaveSubjectInfoReq.set_source(m_oReq.source());
                        oSaveSubjectInfoReq.set_machine_key("GetApplyState");
                        oSaveSubjectInfoReq.set_applyment_id(m_oReq.applyment_id());
                        oSaveSubjectInfoReq.set_subject_id(ddwSubjectId);
                        mmpaymchmgrapply4mobileuseraosvr::SaveSubjectInfoResp oSaveSubjectInfoResp;
                        CSaveSubjectInfo oSaveSubjectInfo(oSaveSubjectInfoReq);
                        iRetCode = oSaveSubjectInfo.SaveSubjectInfo(oSaveSubjectInfoResp);
                        oWTimeElf.AddTimeMark("SaveSubjectInfo", iRetCode);
                        if (iRetCode != 0)
                        {
                            OssAttrInc(126900, 15, 1);
                            strErrMsg = "SaveSubjectInfo error|" + oSaveSubjectInfoResp.biz_ret_msg();
                            strBizRetMsg = "错误（" + std::to_string(iRetCode) + "）：保存主体资料时发生错误";
                            PLOG_ERR("SaveSubjectInfo",iRetCode, "req=%s|resp=%s|m_oReq=%s", DUMP_PB(oSaveSubjectInfoReq), DUMP_PB(oSaveSubjectInfoResp), DUMP_PB(m_oReq));
                            return iRetCode;
                        }
                        objResp.set_subject_name(oSaveSubjectInfoResp.subject_name());
                    }
                    break;
                }else if(oGetApplymentProgressResp.progress() == "CANCEL")
                {//已撤销
                    OssAttrInc(126891, 49, 1);
                    objResp.set_applyment_state(APPLY_4MOBILE_STATE_SUBJECT_CANCEL);
                    strBizRetMsg = "主体申请未完成-已撤销";
                    break;
                }else
                {
                    OssAttrInc(126891, 50, 1);
                    objResp.set_applyment_state(APPLY_4MOBILE_STATE_SUBJECT_NULL);
                    strBizRetMsg = "主体申请未完成-未知状态";
                    break;
                }
            }else{
                OssAttrInc(126891, 51, 1);
                objResp.set_applyment_state(APPLY_4MOBILE_STATE_EDIT);
                strBizRetMsg = "使用已有主体申请-未提交商户资料";
                break;
            }
        }
        case MERCHANT_APPLYMENT_STATE_SUBMIT_AUDIT:	//待审核
        {
            OssAttrInc(126891, 52, 1);
            if (m_oApplyment.process_version() < mmpaymchmgrapplyment::APPLY_PROCESS_VERSION_MOBILE_EDIT_SUBJECT_INFO) {
                OssAttrInc(MMPAY_MCH_MGR_APPLY_4_MOBILE_USER_AO_OSS_ID_343341, 55, 1);
                objResp.set_applyment_state(APPLY_4MOBILE_STATE_AUDIT);
                strBizRetMsg = "审核中";
            } else {
                OssAttrInc(MMPAY_MCH_MGR_APPLY_4_MOBILE_USER_AO_OSS_ID_343341, 56, 1);
                const uint64_t subject_type =
                    strtoull(m_oAttrs.subject_info().subject_type().attr().attr_value().c_str(), NULL, 10);
                uint64_t audit_state = 0;
                iRetCode = GetFinanceValidateState(subject_type, audit_state, strBizRetMsg, strErrMsg, oWTimeElf);
                if (iRetCode != 0) {
                    OssAttrInc(MMPAY_MCH_MGR_APPLY_4_MOBILE_USER_AO_OSS_ID_343341, 57, 1);
                    PLOG_ERR("GetFinanceValidateState err", iRetCode, "applyment_id=%lu|strErrMsg=%s",
                             m_oReq.applyment_id(), strErrMsg.c_str());
                    return iRetCode;
                }
                if (audit_state == MMPAY_MCH_APPLYMENTAUDIT_STATE_PASSED) {
                    OssAttrInc(MMPAY_MCH_MGR_APPLY_4_MOBILE_USER_AO_OSS_ID_343341, 58, 1);
                    objResp.set_applyment_state(APPLY_4MOBILE_STATE_AUDIT);
                    strBizRetMsg = "审核中";
                } else {
                    OssAttrInc(MMPAY_MCH_MGR_APPLY_4_MOBILE_USER_AO_OSS_ID_343341, 59, 1);
                    objResp.set_applyment_state(APPLY_4MOBILE_STATE_WAIT_FINANCE_VALIDATE);
                    strBizRetMsg = "待账户验证";
                }
            }
            break;
        }
        case MERCHANT_APPLYMENT_STATE_AUDIT_REJECTED:	//审核驳回
        {
            OssAttrInc(126891, 53, 1);
            objResp.set_applyment_state(APPLY_4MOBILE_STATE_REJECT);
            strBizRetMsg = "已驳回";
            break;
        }
        case MERCHANT_APPLYMENT_STATE_AUDIT_APPROVE:	//审核通过
        {
            OssAttrInc(126891, 54, 1);
            objResp.set_applyment_state(APPLY_4MOBILE_STATE_AUDIT);
            strBizRetMsg = "开户处理中";
            break;
        }
        case MERCHANT_APPLYMENT_STATE_OPEN_ACCOUNT:	//开户
        {
            if (bApplymentProperty.test(MERCHANT_APPLYMENT_PROPERTY_CONTRACT_SIGNED)) {
                OssAttrInc(126891, 55, 1);
                objResp.set_applyment_state(APPLY_4MOBILE_STATE_SIGNING);
                strBizRetMsg = "开通权限中";
            } else {
              if (bApplymentProperty.test(MERCHANT_APPLYMENT_PROPERTY_ACCEPT_SIGN_CONTRACT)) {
                OssAttrInc(310203, 3, 1);
                objResp.set_applyment_state(APPLY_4MOBILE_STATE_SIGN_AUDITING);
                strBizRetMsg = "签约审核中";
              } else {
                OssAttrInc(310203, 4, 1);
                objResp.set_applyment_state(APPLY_4MOBILE_STATE_TO_BE_SIGNED);
                strBizRetMsg = "待签约";
              }
            }
            break;
        }
        case MERCHANT_APPLYMENT_STATE_OPEN_SETTLE:	//结算开启
        {
            OssAttrInc(126891, 57, 1);
            objResp.set_applyment_state(APPLY_4MOBILE_STATE_FINISH);
            strBizRetMsg = "已完成";
            break;
        }
        case MERCHANT_APPLYMENT_STATE_CANCEL:	//作废
        {
          if (m_oApplyment.cancel_type() == MERCHANT_APPLYMENT_CALCEL_TYPE_SIGN_CONTRACT) {
            OssAttrInc(310203, 5, 1);
            objResp.set_applyment_state(APPLY_4MOBILE_STATE_SIGN_REJECT);
            strBizRetMsg = "签约审核作废";
          } else {
            OssAttrInc(310203, 6, 1);
            objResp.set_applyment_state(APPLY_4MOBILE_STATE_CANCEL);
            strBizRetMsg = "已作废";
          }
          break;
        }
        default:
            OssAttrInc(126891, 59, 1);
            objResp.set_applyment_state(APPLY_4MOBILE_STATE_AUDIT);
            strBizRetMsg = "未知状态";
    }

}