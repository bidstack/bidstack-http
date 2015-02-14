#ifndef BIDSTACK_HTTP_BODY_HPP
#define BIDSTACK_HTTP_BODY_HPP

#include <QObject>

namespace Bidstack {
    namespace Http {

        class HttpBody : public QObject {
            Q_OBJECT

        public:
            HttpBody(QObject *parent = 0);
            HttpBody(QString body, QObject *parent = 0);
            HttpBody(QByteArray body, QObject *parent = 0);

        public:
            QString toString();
            QByteArray toByteArray();

        public:
            bool isEmpty();

        private:
            QString m_body;
        };

    };
};

#endif
