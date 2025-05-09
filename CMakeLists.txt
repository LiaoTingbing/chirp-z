

cmake_minimum_required(VERSION 3.10)

project("chirp-z")

add_executable(
${PROJECT_NAME}
"src/example1.cpp"
include/czt.h
    
)
find_package(Armadillo CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE armadillo)

find_package(FFTW3 CONFIG REQUIRED)
target_link_libraries(    ${PROJECT_NAME}
PRIVATE FFTW3::fftw3)

find_package(FFTW3f CONFIG REQUIRED)
target_link_libraries(    ${PROJECT_NAME}
PRIVATE FFTW3::fftw3f)

find_package(FFTW3l CONFIG REQUIRED)
target_link_libraries(    ${PROJECT_NAME}
PRIVATE FFTW3::fftw3l)

 