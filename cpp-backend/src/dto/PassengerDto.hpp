#ifndef PassengerDto_hpp
#define PassengerDto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class PassengerDto : public oatpp::DTO {
  DTO_INIT(PassengerDto, DTO)

  DTO_FIELD(String, id);
  DTO_FIELD(String, firstName);
  DTO_FIELD(String, lastName);
  DTO_FIELD(String, ticketStatus);
};

#include OATPP_CODEGEN_END(DTO)

#endif