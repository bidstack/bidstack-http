#include "httpbody.hpp"

using namespace Bidstack::Http;

HttpBody::HttpBody(QObject *parent) : QObject(parent) {
    m_body = "";
}

HttpBody::HttpBody(QString body, QObject *parent) : QObject(parent) {
    m_body = body;
}

HttpBody::HttpBody(QByteArray body, QObject *parent) : QObject(parent) {
    m_body = QString(body);
}

QString HttpBody::toString() {
    return m_body;
}

QByteArray HttpBody::toByteArray() {
    return m_body.toUtf8();
}

bool HttpBody::isEmpty() {
    return m_body.isEmpty();
}
