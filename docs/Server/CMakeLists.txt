file(GLOB_RECURSE SERVER_SOURCES "src/*.cpp")

add_executable(RTypeServer ${SERVER_SOURCES})

target_include_directories(RTypeServer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(RTypeServer Boost::system Boost::thread GameEngineLib)

# Installation rules for the server
install(TARGETS RTypeServer
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib/static
)
