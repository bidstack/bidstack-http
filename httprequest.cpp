#include "httprequest.hpp"

using namespace Bidstack::Http;

HttpRequest::HttpRequest(QObject *parent) : QObject(parent) {
    m_body = new HttpBody();
}

void HttpRequest::setHeaders(QMap<QString, QString> headers) {
    m_headers = headers;
}

QMap<QString, QString> HttpRequest::headers() {
    return m_headers;
}

void HttpRequest::setMethod(QString method) {
    m_method = method;
}

QString HttpRequest::method() {
    return m_method;
}

void HttpRequest::setUrl(QUrl url) {
    m_url = url;
}

QUrl HttpRequest::url() {
    return m_url;
}

void HttpRequest::setBody(HttpBody* body) {
    m_body = body;
}

HttpBody* HttpRequest::body() {
    return m_body;
}
