cmake_minimum_required(VERSION 3.8)

if(POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project(OOPuzd)

add_executable(uzdO3
        "Common.cpp"
        "Common.h"
        "PazymiaiVectors.cpp"
        "PazymiaiVectors.h"
        "Program.cpp"
)

if(CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET uzdO3 PROPERTY CXX_STANDARD 20)
endif()

# Add the optimization flag
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(uzdO3 PRIVATE -O3)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(uzdO3 PRIVATE /O3)
endif()

add_executable(uzdO2
        "Common.cpp"
        "Common.h"
        "PazymiaiVectors.cpp"
        "PazymiaiVectors.h"
        "Program.cpp"
)

if(CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET uzdO2 PROPERTY CXX_STANDARD 20)
endif()

# Add the optimization flag
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(uzdO2 PRIVATE -O2)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(uzdO2 PRIVATE /O2)
endif()

add_executable(uzdO1
        "Common.cpp"
        "Common.h"
        "PazymiaiVectors.cpp"
        "PazymiaiVectors.h"
        "Program.cpp"
)

if(CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET uzdO1 PROPERTY CXX_STANDARD 20)
endif()

# Add the optimization flag
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(uzdO1 PRIVATE -O1)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(uzdO1 PRIVATE /O1)
endif()


