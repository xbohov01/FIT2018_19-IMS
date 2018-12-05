cmake_minimum_required(VERSION 2.8)
project(PostOffice)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Customer.cpp Customer.h FacilityContainer.cpp FacilityContainer.h PostOffice.cpp CustomerGenerator.cpp CustomerGenerator.h)
add_custom_target(mytest COMMAND make -C ${mytest_SOURCE_DIR}
        CLION_EXE_DIR=${PROJECT_BINARY_DIR})