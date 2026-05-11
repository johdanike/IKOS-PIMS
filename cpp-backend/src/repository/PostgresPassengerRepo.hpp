#ifndef PostgresPassengerRepo_hpp
#define PostgresPassengerRepo_hpp

#include <pqxx/pqxx>
#include <string>
#include "oatpp/core/Types.hpp"
#include "../dto/PassengerDto.hpp"

class PostgresPassengerRepo {
private:
    std::string connectionString;

public:
    PostgresPassengerRepo(const std::string& connStr);
    oatpp::Object<PassengerDto> registerPassenger(const oatpp::Object<PassengerDto>& input);
};

#endif