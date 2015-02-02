# bidstack-http

Easy to use HTTP client written in Qt/C++

## Usage

```c++
#include <QCoreApplication>
#include <QDebug>

#include "client.hpp"

using namespace Bidstack::Http;

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    QMap<QString, QString> headers;
    headers.insert("Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8");

    Request *request = new Request();
    request->setMethod("GET");
    request->setUrl(QUrl("https://github.com/bidstack/bidstack-http"));
    request->setHeaders(headers);

    Client *client = new Client();
    Response *response = client->send(request);

    qDebug() << "Headers:" << response->headers();
    qDebug() << "HTTP Status:" << response->status();
    qDebug() << "Body:" << response->body()->toString();

    return 0;
}
```
