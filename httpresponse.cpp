#include "httpresponse.hpp"

using namespace Bidstack::Http;

HttpResponse::HttpResponse(int status, QObject *parent) : QObject(parent) {
    m_status = status;
    m_body = new HttpBody();
}

HttpResponse::HttpResponse(int status, QMap<QString, QString> headers, HttpBody *body, QObject *parent) : QObject(parent) {
    m_status = status;
    m_headers = headers;
    m_body = body;
}

HttpResponse::HttpResponse(QNetworkReply *reply, QObject *parent) : QObject(parent) {
    m_status = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    m_body = new HttpBody(reply->readAll());

    QList<QByteArray> headers = reply->rawHeaderList();
    foreach (QByteArray key, headers) {
        m_headers.insert(QString(key), reply->rawHeader(key));
    }
}

int HttpResponse::status() {
    return m_status;
}

QMap<QString, QString> HttpResponse::headers() {
    return m_headers;
}

HttpBody* HttpResponse::body() {
    return m_body;
}
