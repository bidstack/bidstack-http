#ifndef BIDSTACK_HTTP_RESPONSE_HPP
#define BIDSTACK_HTTP_RESPONSE_HPP

#include <QObject>
#include <QNetworkReply>

#include "body.hpp"

namespace Bidstack {
    namespace Http {

        class Response : public QObject {
            Q_OBJECT

        public:
            Response(int status, QObject *parent = 0);
            Response(QNetworkReply *reply, QObject *parent = 0);

        public:
            int status();
            QMap<QString, QString> headers();
            Body* body();

        private:
            int m_status;
            QMap<QString, QString> m_headers;
            Body* m_body;
        };

    };
};

#endif
