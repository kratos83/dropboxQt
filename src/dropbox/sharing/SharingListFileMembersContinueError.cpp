/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingListFileMembersContinueError.h"

namespace dropboxQt{

namespace sharing{
///ListFileMembersContinueError

ListFileMembersContinueError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void ListFileMembersContinueError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case ListFileMembersContinueError_USER_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("user_error");
            m_user_error.toJson(js, "user_error");
        }break;
        case ListFileMembersContinueError_ACCESS_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("access_error");
            m_access_error.toJson(js, "access_error");
        }break;
        case ListFileMembersContinueError_INVALID_CURSOR:{
            if(!name.isEmpty())
                js[name] = QString("invalid_cursor");
        }break;
        case ListFileMembersContinueError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void ListFileMembersContinueError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("user_error") == 0){
        m_tag = ListFileMembersContinueError_USER_ERROR;
        m_user_error.fromJson(js["user_error"].toObject());
    }
    else if(s.compare("access_error") == 0){
        m_tag = ListFileMembersContinueError_ACCESS_ERROR;
        m_access_error.fromJson(js["access_error"].toObject());
    }
    else if(s.compare("invalid_cursor") == 0){
        m_tag = ListFileMembersContinueError_INVALID_CURSOR;

    }
    else if(s.compare("other") == 0){
        m_tag = ListFileMembersContinueError_OTHER;

    }
}

QString ListFileMembersContinueError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "ListFileMembersContinueError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<ListFileMembersContinueError>  ListFileMembersContinueError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<ListFileMembersContinueError> rv = std::unique_ptr<ListFileMembersContinueError>(new ListFileMembersContinueError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
