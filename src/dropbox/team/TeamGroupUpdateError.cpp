/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamGroupUpdateError.h"

namespace dropboxQt{

namespace team{
///GroupUpdateError

GroupUpdateError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void GroupUpdateError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case GroupSelectorError_GROUP_NOT_FOUND:{
            if(!name.isEmpty())
                js[name] = QString("group_not_found");
        }break;
        case GroupSelectorError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
        case GroupUpdateError_EXTERNAL_ID_ALREADY_IN_USE:{
            if(!name.isEmpty())
                js[name] = QString("external_id_already_in_use");
        }break;
    }//switch
}

void GroupUpdateError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("group_not_found") == 0){
        m_tag = GroupSelectorError_GROUP_NOT_FOUND;

    }
    else if(s.compare("other") == 0){
        m_tag = GroupSelectorError_OTHER;

    }
    if(s.compare("external_id_already_in_use") == 0){
        m_tag = GroupUpdateError_EXTERNAL_ID_ALREADY_IN_USE;

    }
}

QString GroupUpdateError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "GroupUpdateError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<GroupUpdateError>  GroupUpdateError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<GroupUpdateError> rv = std::unique_ptr<GroupUpdateError>(new GroupUpdateError);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
