#include <QNetworkRequest>
#include <QNetworkReply>
#include <QTimer>
#include <QEventLoop>

#include "httpclient.hpp"

using namespace Bidstack::Http;

HttpClient::HttpClient(QObject *parent) : QObject(parent) {
    m_manager = new QNetworkAccessManager();
}

HttpResponse* HttpClient::send(HttpRequest* request) {
    QNetworkRequest networkRequest(request->url());

    QMap<QString, QString> headers = request->headers();
    foreach (QString key, headers.keys()) {
        networkRequest.setRawHeader(
            key.toUtf8(),
            QString(headers.value(key)).toUtf8()
        );
    }

    QNetworkReply *networkReply;
    if (request->method() == "GET") {
        networkReply = m_manager->get(networkRequest);
    } else if (request->method() == "POST") {
        networkReply = m_manager->post(networkRequest, request->body()->toByteArray());
    } else {
        throw "Unknown or unimplemented HTTP method '" + request->method() + "'";
    }

    QTimer timer;
    QEventLoop loop;

    connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
    connect(networkReply, SIGNAL(finished()), &loop, SLOT(quit()));

    timer.setSingleShot(true);
    timer.start(5000); // 5 seconds

    loop.exec();

    HttpResponse *response;
    if (timer.isActive()) {
        timer.stop();
        response = new HttpResponse(networkReply);
    } else {
        networkReply->abort();
        response = new HttpResponse(500);
    }

    disconnect(networkReply, SIGNAL(finished()), &loop, SLOT(quit()));
    return response;
}
