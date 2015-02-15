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

        public:
            bool isValid();
            bool isInformational();
            bool isSuccessful();
            bool isRedirection();
            bool isClientError();
            bool isServerError();
            bool isOk();
            bool isForbidden();
            bool isNotFound();
            bool isEmpty();

        private:
            int m_status;
            QMap<QString, QString> m_headers;
            HttpBody* m_body;
        };

    };
};

#endif
