
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(r-type_client ${SOURCES})

# Link any required libraries or dependencies
# For example, if you're using sockets, you might need to link with -lpthread
target_link_libraries(r-type_client
    # Additional libraries go here, if any
    -lsfml-graphics
    -lsfml-window
    -lsfml-system
    -lsfml-audio
    -lsfml-network
)

include_directories(include
        include/Network
        include/Game
        include/Box)

# Specify the C++ standard version (C++11, C++14, etc.)
set_target_properties(r-type_client PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

# Installation rules for the client
install(TARGETS r-type_client
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib/static
)

# Link the necessary libraries, e.g., Boost components
target_link_libraries(r-type_client Boost::system Boost::thread)
