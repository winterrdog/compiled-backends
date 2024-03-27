#include <crow/crow/app.h>
#include <crow/crow/http_response.h>
#include <crow/crow/json.h>

using json = crow::json::wvalue;

json hi_json(void) {
  json res = {{"name", "data-is-mine"}, {"pi", 3.14}, {"cpp", true}};
  return res;
}

json json_again(void) {
  json res = {
      {"name", "data-is-mine"},
      {"pi", 3.14},
      {"cpp", true},
      {"array", json::list{{1, 2, 3}}},
      {"object", json::object{{"key", "value"}}},
  };
  return res;
}

void catch_all(crow::response &res) {
  res.body = "that url was not found";
  res.end();
}

int main(void) {
  crow::SimpleApp app{};

  // routes
  CROW_ROUTE(app, "/hi-json")(hi_json);
  CROW_ROUTE(app, "/json-again")(json_again);
  CROW_CATCHALL_ROUTE(app)(catch_all);

  // server has go to listen
  auto a{app.port(9090).run_async()};
  return 0;
}