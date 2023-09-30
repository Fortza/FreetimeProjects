cmake_minimum_required(VERSION 3.1.0)
project(Maximus_Cup_Arranger VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

set(dir ${CMAKE_CURRENT_SOURCE_DIR})

#include(CTest)
#enable_testing()

# All header files
set(HEADER_FILES
    ${dir}/include/user.h
    ${dir}/include/users.h
    ${dir}/include/constants.h
    ${dir}/include/helperFunctions.h
    ${dir}/include/helperFunctions.h
    ${dir}/include/tournament.h
    ${dir}/include/tournaments.h
    ${dir}/include/match.h
    ${dir}/include/matches.h
    ${dir}/include/team.h
    ${dir}/include/teams.h)

# All source files
set(SOURCE_FILES
    ${dir}/src/main.cpp
    ${dir}/src/user.cpp
    ${dir}/src/users.cpp
    ${dir}/src/helperFunctions.cpp
    ${dir}/src/helperFunctions.cpp
    ${dir}/src/tournament.cpp
    ${dir}/src/tournaments.cpp
    ${dir}/src/match.cpp
    ${dir}/src/matches.cpp 
    ${dir}/src/team.cpp 
    ${dir}/src/teams.cpp)

include_directories(${dir}/include)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${dir}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${dir}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir}/bin)

# DLL
set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")
# DLL linker flags
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

add_executable(Maximus_Cup_Arranger ${SOURCE_FILES} ${HEADER_FILES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
