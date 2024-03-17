project(sample/lib-client VERSION 0.1.0)

find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

file(GLOB sources CONFIGURE_DEPENDS *.cpp)
file(GLOB headers CONFIGURE_DEPENDS *.hpp)

add_library(lib-client ${sources} ${headers})

set_target_properties(lib-client PROPERTIES
	PREFIX lib
	OUTPUT_NAME client
)

target_link_libraries(lib-client PUBLIC spdlog::spdlog fmt::fmt)
