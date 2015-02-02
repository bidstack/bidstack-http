#ifndef BIDSTACK_HTTP_REQUEST_HPP
#define BIDSTACK_HTTP_REQUEST_HPP

#include <QObject>
#include <QUrl>
#include <QMap>

#include "body.hpp"

namespace Bidstack {
    namespace Http {

        class Request : public QObject {
            Q_OBJECT

        public:
            Request(QObject *parent = 0);

        public:
            void setHeaders(QMap<QString, QString> headers);
            QMap<QString, QString> headers();

            void setMethod(QString method);
            QString method();

            void setUrl(QUrl url);
            QUrl url();

            void setBody(Body* body);
            Body* body();

        private:
            QMap<QString, QString> m_headers;
            QString m_method;
            QUrl m_url;
            Body* m_body;
        };

    };
};

#endif
