#include "oatpp/network/Server.hpp"
#include "AppComponent.hpp"
#include "controller/PassengerController.hpp"
#include <iostream>

void run() {
  // Initialize dependency injection components
  AppComponent components;

  // Get the router component
  OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);

  // Initialize and register our Passenger Controller
  auto passengerController = PassengerController::createShared();
  router->addController(passengerController);

  // Get connection handler and provider
  OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, connectionHandler);
  OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, connectionProvider);

  // Create and run the server
  oatpp::network::Server server(connectionProvider, connectionHandler);

  std::cout << "\n---------------------------------------------------" << std::endl;
  std::cout << "🚀 IKOS-PIMS Edge Node (C++) running on port 8081" << std::endl;
  std::cout << "---------------------------------------------------\n" << std::endl;

  server.run();
}

int main() {
  // Initialize Oatpp Environment
  oatpp::base::Environment::init();

  // Run the application
  run();

  // Clean up Environment
  oatpp::base::Environment::destroy();
  return 0;
}