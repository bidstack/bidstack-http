#ifndef BIDSTACK_HTTP_CLIENT_HPP
#define BIDSTACK_HTTP_CLIENT_HPP

#include <QObject>
#include <QNetworkAccessManager>

#include "request.hpp"
#include "response.hpp"

namespace Bidstack {
    namespace Http {

        class Client : public QObject {
            Q_OBJECT

        public:
            Client(QObject *parent = 0);

        public:
            Response* send(Request* request);

        private:
            QNetworkAccessManager *m_manager;
        };

    };
};

#endif
