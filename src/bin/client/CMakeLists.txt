project(sample/bin-client VERSION 0.1.0)

file(GLOB sources CONFIGURE_DEPENDS *.cpp)
file(GLOB headers CONFIGURE_DEPENDS *.hpp)

add_executable(bin-client ${sources} ${headers})

set_target_properties(bin-client PROPERTIES
	OUTPUT_NAME client
)

target_link_libraries(bin-client PUBLIC lib-client)
