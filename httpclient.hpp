#ifndef BIDSTACK_HTTP_CLIENT_HPP
#define BIDSTACK_HTTP_CLIENT_HPP

#include <QObject>
#include <QNetworkAccessManager>

#include "httprequest.hpp"
#include "httpresponse.hpp"

namespace Bidstack {
    namespace Http {

        class HttpClient : public QObject {
            Q_OBJECT

        public:
            HttpClient(QObject *parent = 0);

        public:
            HttpResponse* send(HttpRequest* request);

        private:
            QNetworkAccessManager *m_manager;
        };

    };
};

#endif
