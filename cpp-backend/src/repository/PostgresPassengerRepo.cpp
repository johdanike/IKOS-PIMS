#include "PostgresPassengerRepo.hpp"
#include <iostream>
#include <stdexcept>

PostgresPassengerRepo::PostgresPassengerRepo(const std::string& connStr) : connectionString(connStr) {}

oatpp::Object<PassengerDto> PostgresPassengerRepo::registerPassenger(const oatpp::Object<PassengerDto>& input) {
    try {
        pqxx::connection C(connectionString);
        pqxx::work W(C);

        // Parametrized query for safety
        std::string sql = "INSERT INTO passengers (first_name, last_name, ticket_status) VALUES ($1, $2, 'CONFIRMED') RETURNING id, ticket_status";
        pqxx::result R = W.exec_params(sql, input->firstName->c_str(), input->lastName->c_str());
        W.commit();
        // Map the DB response back to the JSON payload
        auto responseDto = PassengerDto::createShared();
        responseDto->id = R[0][0].c_str();
        responseDto->firstName = input->firstName;
        responseDto->lastName = input->lastName;
        responseDto->ticketStatus = R[0][1].c_str();

        return responseDto;

    } catch (const std::exception &e) {
        std::cerr << "DB Execution Error: " << e.what() << std::endl;
        throw std::runtime_error("Failed to register passenger in database.");
    }
}