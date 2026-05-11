#ifndef PassengerController_hpp
#define PassengerController_hpp

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"
#include "../dto/PassengerDto.hpp"
#include "../repository/PostgresPassengerRepo.hpp"
#include <cstdlib>

#include OATPP_CODEGEN_BEGIN(ApiController)

class PassengerController : public oatpp::web::server::api::ApiController {
public:
  PassengerController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
    : oatpp::web::server::api::ApiController(objectMapper) {}

  static std::shared_ptr<PassengerController> createShared(
    OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)
  ){
    return std::make_shared<PassengerController>(objectMapper);
  }

  ENDPOINT("POST", "/api/v1/passengers", registerPassenger,
           BODY_DTO(Object<PassengerDto>, passengerDto)) {

      const char* envConn = std::getenv("DB_CONN_STR");
      std::string connStr = envConn ? envConn : "postgresql://ikos_admin:admin_password@host.docker.internal:5432/pims_db";

      try {
          PostgresPassengerRepo repo(connStr);
          auto savedPassenger = repo.registerPassenger(passengerDto);
          return createDtoResponse(Status::CODE_201, savedPassenger);
      } catch (const std::exception& e) {
          return createResponse(Status::CODE_500, e.what());
      }
  }
};

#include OATPP_CODEGEN_END(ApiController)

#endif