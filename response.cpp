#include "response.hpp"

using namespace Bidstack::Http;

Response::Response(int status, QObject *parent) : QObject(parent) {
    m_status = status;
    m_body = new Body();
}

Response::Response(QNetworkReply *reply, QObject *parent) : QObject(parent) {
    m_status = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    m_body = new Body(reply->readAll());

    QList<QByteArray> headers = reply->rawHeaderList();
    foreach (QByteArray key, headers) {
        m_headers.insert(QString(key), reply->rawHeader(key));
    }
}

int Response::status() {
    return m_status;
}

QMap<QString, QString> Response::headers() {
    return m_headers;
}

Body* Response::body() {
    return m_body;
}
