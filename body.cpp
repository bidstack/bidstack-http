#include "body.hpp"

using namespace Bidstack::Http;

Body::Body(QObject *parent) : QObject(parent) {
    m_body = "";
}

Body::Body(QString body, QObject *parent) : QObject(parent) {
    m_body = body;
}

Body::Body(QByteArray body, QObject *parent) : QObject(parent) {
    m_body = QString(body);
}

QString Body::toString() {
    return m_body;
}

QByteArray Body::toByteArray() {
    return m_body.toUtf8();
}
