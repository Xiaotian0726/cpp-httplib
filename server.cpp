#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"

// Compile command: 
// g++ server.cpp -o server -pthread -lssl -lcrypto

int main() {
    // HTTP
    httplib::Server svr;

    // // HTTPS
    // httplib::SSLServer svr;

    svr.Get("/hi", [](const httplib::Request &, httplib::Response &res) {
        res.set_content("Hello World!", "text/plain");
    });

    svr.listen("0.0.0.0", 8080);
    return 0;
}