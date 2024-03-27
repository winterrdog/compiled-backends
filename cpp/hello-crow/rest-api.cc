#include <crow/crow/app.h>
#include <crow/crow/http_response.h>
#include <crow/crow/json.h>

using json = crow::json::wvalue;

int main(void) {
  crow::SimpleApp app{};

  // routes
  CROW_ROUTE(app, "/hi-json")
  ([]() -> json {
    json res = {{"name", "data-is-mine"}, {"pi", 3.14}, {"cpp", true}};
    return res;
  });
  CROW_ROUTE(app, "/json-again")
  ([]() -> json {
    json res = {
        {"name", "data-is-mine"},
        {"pi", 3.14},
        {"cpp", true},
        {"array", json::list{{1, 2, 3}}},
        {"object", json::object{{"key", "value"}}},
    };
    return res;
  });

  CROW_CATCHALL_ROUTE(app)
  ([](crow::response &res) -> void {
    res.body = "that url was not found";
    res.end();
  });

  // server has go to listen
  auto a{app.port(9090).run_async()};
  return 0;
}