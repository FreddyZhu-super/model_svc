project(test)

set(CMAKE_CXX_STANDARD 14)

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(main PRIVATE nlohmann_json::nlohmann_json)
add_executable(test "json_test.cpp","test_map.cpp")