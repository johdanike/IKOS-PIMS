cmake_minimum_required(VERSION 3.15)
project(ikos-pims-cpp)

set(CMAKE_CXX_STANDARD 17)

# 1. Find the web framework via vcpkg
find_package(oatpp CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

# 2. Find the pre-compiled database driver via Linux Native Packages
find_package(PkgConfig REQUIRED)
pkg_check_modules(PQXX REQUIRED libpqxx)

# 3. Create the executable
add_executable(pims-cpp
    src/main.cpp
    src/repository/PostgresPassengerRepo.cpp
)

# 4. Link everything together
target_include_directories(pims-cpp PRIVATE ${PQXX_INCLUDE_DIRS})
target_link_directories(pims-cpp PRIVATE ${PQXX_LIBRARY_DIRS})

target_link_libraries(pims-cpp PRIVATE
    oatpp::oatpp
    nlohmann_json::nlohmann_json
    ${PQXX_LIBRARIES}
)