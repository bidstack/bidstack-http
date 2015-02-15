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

bool HttpResponse::isValid() {
    return status() >= 100 && status() < 600;
}

bool HttpResponse::isInformational() {
    return status() >= 100 && status() < 200;
}

bool HttpResponse::isSuccessful() {
    return status() >= 200 && status() < 300;
}

bool HttpResponse::isRedirection() {
    return status() >= 300 && status() < 400;
}

bool HttpResponse::isClientError() {
    return status() >= 400 && status() < 500;
}

bool HttpResponse::isServerError() {
    return status() >= 500 && status() < 600;
}

bool HttpResponse::isOk() {
    return status() == 200;
}

bool HttpResponse::isForbidden() {
    return status() == 403;
}

bool HttpResponse::isNotFound() {
    return status() == 404;
}

bool HttpResponse::isEmpty() {
    return status() == 204 || status() == 304;
}

QMap<QString, QString> HttpResponse::headers() {
    return m_headers;
}

HttpBody* HttpResponse::body() {
    return m_body;
}
