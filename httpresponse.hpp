#ifndef BIDSTACK_HTTP_RESPONSE_HPP
#define BIDSTACK_HTTP_RESPONSE_HPP

#include <QObject>
#include <QNetworkReply>

#include "httpbody.hpp"

namespace Bidstack {
    namespace Http {

        class HttpResponse : public QObject {
            Q_OBJECT

        public:
            HttpResponse(int status, QObject *parent = 0);
            HttpResponse(int status, QMap<QString, QString> headers, HttpBody *body, QObject *parent = 0);
            HttpResponse(QNetworkReply *reply, QObject *parent = 0);

        public:
            int status();
            QMap<QString, QString> headers();
            HttpBody* body();

        private:
            int m_status;
            QMap<QString, QString> m_headers;
            HttpBody* m_body;
        };

    };
};

#endif
