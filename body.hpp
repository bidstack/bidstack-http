#ifndef BIDSTACK_HTTP_BODY_HPP
#define BIDSTACK_HTTP_BODY_HPP

#include <QObject>

namespace Bidstack {
    namespace Http {

        class Body : public QObject {
            Q_OBJECT

        public:
            Body(QObject *parent = 0);
            Body(QString body, QObject *parent = 0);
            Body(QByteArray body, QObject *parent = 0);

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
