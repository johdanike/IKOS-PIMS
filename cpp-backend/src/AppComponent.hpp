#ifndef AppComponent_hpp
#define AppComponent_hpp

#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/component.hpp"

class AppComponent {
public:
  // 1. Configure the Port (8081 for the Edge Node)
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, serverConnectionProvider)(
    oatpp::network::tcp::server::ConnectionProvider::createShared({"0.0.0.0", 8081, oatpp::network::Address::IP_4})
  );

  // 2. Configure the Router
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, httpRouter)(
    oatpp::web::server::HttpRouter::createShared()
  );

  // 3. Configure the Connection Handler
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, serverConnectionHandler)(
    oatpp::web::server::HttpConnectionHandler::createShared(
      OATPP_GET_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>)
    )
  );

  // 4. Configure the JSON Object Mapper (Equivalent to Jackson in Java)
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, apiObjectMapper)(
    oatpp::parser::json::mapping::ObjectMapper::createShared()
  );
};

#endif