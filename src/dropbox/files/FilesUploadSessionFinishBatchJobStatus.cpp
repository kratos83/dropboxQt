/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
***********************************************************/

#include "dropbox/files/FilesUploadSessionFinishBatchJobStatus.h"

namespace dropboxQt{

namespace files{
///UploadSessionFinishBatchJobStatus

UploadSessionFinishBatchJobStatus::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void UploadSessionFinishBatchJobStatus::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case PollResultBase_IN_PROGRESS:{
            if(!name.isEmpty())
                js[name] = QString("in_progress");
        }break;
        case UploadSessionFinishBatchJobStatus_COMPLETE:{
            if(!name.isEmpty())
                js[name] = QString("complete");
            js["complete"] = (QJsonObject)m_complete;
        }break;
    }//switch
}

void UploadSessionFinishBatchJobStatus::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("in_progress") == 0){
        m_tag = PollResultBase_IN_PROGRESS;

    }
    if(s.compare("complete") == 0){
        m_tag = UploadSessionFinishBatchJobStatus_COMPLETE;
        m_complete.fromJson(js);
    }
}

QString UploadSessionFinishBatchJobStatus::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "UploadSessionFinishBatchJobStatus");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

#ifdef DROPBOX_QT_AUTOTEST
UploadSessionFinishBatchJobStatus UploadSessionFinishBatchJobStatus::EXAMPLE(){
    UploadSessionFinishBatchJobStatus rv;
    rv.complete = files::UploadSessionFinishBatchResult::EXAMPLE();
    rv.m_tag = UploadSessionFinishBatchJobStatus_COMPLETE;
    return rv;
}
#endif //DROPBOX_QT_AUTOTEST

}//files
}//dropboxQt
