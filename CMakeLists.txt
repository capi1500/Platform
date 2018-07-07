cmake_minimum_required(VERSION 3.10)

project(Platform)
set(EXECUTABLE_NAME Platform)

set(CMAKE_CXX_STANDARD 11)

set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)
configure_file(
	"${PROJECT_SOURCE_DIR}/config.h.in"
	"${PROJECT_BINARY_DIR}/config.h"
)

include_directories("${PROJECT_BINARY_DIR}")
include_directories(Object
	Sound
	Audio
	Game
	Alphabet
	AnimatedSprite
	GraphicString
	Object
	PhysicObject
	TerrainObject
	Loader
	Entity
	GroundObject
	Player
	Collectible
	Counter)

add_executable(${EXECUTABLE_NAME}
	main.cpp
	Object/object.cpp Object/object.hpp
	Sound/sound.cpp Sound/sound.hpp
	Game/game.cpp Game/game.hpp
	Alphabet/alphabet.cpp Alphabet/alphabet.hpp
	AnimatedSprite/Animation.cpp AnimatedSprite/Animation.hpp
	AnimatedSprite/AnimatedSprite.cpp AnimatedSprite/AnimatedSprite.hpp
	GraphicString/graphicString.cpp GraphicString/graphicString.hpp
	TerrainObject/terrainObject.cpp TerrainObject/terrainObject.hpp
	PhysicObject/physicObject.cpp PhysicObject/physicObject.hpp
	Loader/loader.cpp Loader/loader.hpp
	Entity/entity.cpp Entity/entity.hpp
	GroundObject/groundObject.cpp GroundObject/groundObject.hpp
	Player/player.cpp Player/player.hpp
	Collectible/collectible.cpp Collectible/collectible.hpp
	Counter/counter.cpp Counter/counter.hpp)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
# Detect and add SFML
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)

if(SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIR})
	target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

# add Box2D

target_link_libraries(${EXECUTABLE_NAME} ${CMAKE_SOURCE_DIR}/lib/libBox2D.a)

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)


# CPack packaging
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")
set(CPACK_PACKAGE_VERSION_MAJOR "${myproject_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${myproject_VERSION_MINOR}")
include(CPack)