file(GLOB_RECURSE GAME_ENGINE_SOURCES "src/*.cpp")

add_library(GameEngineLib STATIC ${GAME_ENGINE_SOURCES})

# Specify the include directories for the GameEngine library
target_include_directories(GameEngineLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
