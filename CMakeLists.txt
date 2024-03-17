cmake_minimum_required(VERSION 3.21)

project(sample)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

include_directories(${CMAKE_SOURCE_DIR}/include/external)
include_directories(${CMAKE_SOURCE_DIR}/include)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_DEBUG_POSTFIX d)

function(add_subdirectories glob_path)
	file(GLOB subdirectories LIST_DIRECTORIES true ${glob_path})

	foreach(subdirectory ${subdirectories})
		if(IS_DIRECTORY ${subdirectory})
			add_subdirectory(${subdirectory})
		endif()
	endforeach()
endfunction()

add_subdirectories("src/lib/*")
add_subdirectories("src/bin/*")

find_program(LINTER NAMES clang-format)

file(GLOB_RECURSE all_source_files src/*.cpp src/*.cpp include/*.hpp)

add_custom_target(apply-format ALL COMMAND ${LINTER} --style=file -i ${all_source_files})

add_custom_target(check-format ALL COMMAND ${LINTER} --dry-run --Werror --style=file -i ${all_source_files})
