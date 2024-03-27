#include <crow/crow.h>
#include <crow/crow/app.h>
#include <crow/crow/http_response.h>

int _main(void) {
  // init app
  crow::SimpleApp app{};

  // routes
  CROW_ROUTE(app, "/")([]() { return "Hello world"; });
  CROW_CATCHALL_ROUTE(app)
  ([](crow::response &res) {
    res.body = "That URL..! doesn't seem to be here";
    res.end();
  });

  // make server listen
  auto a = app.port(9090).run_async();

  return 0;
}