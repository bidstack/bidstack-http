#include "request.hpp"

using namespace Bidstack::Http;

Request::Request(QObject *parent) : QObject(parent) {
    m_body = new Body();
}

void Request::setHeaders(QMap<QString, QString> headers) {
    m_headers = headers;
}

QMap<QString, QString> Request::headers() {
    return m_headers;
}

void Request::setMethod(QString method) {
    m_method = method;
}

QString Request::method() {
    return m_method;
}

void Request::setUrl(QUrl url) {
    m_url = url;
}

QUrl Request::url() {
    return m_url;
}

void Request::setBody(Body* body) {
    m_body = body;
}

Body* Request::body() {
    return m_body;
}
