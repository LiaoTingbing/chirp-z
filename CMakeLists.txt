

cmake_minimum_required(VERSION 3.10)

set(CMAKE_TOOLCHAIN_FILE E:/VisualStudioFiles/vcpkg/vcpkg/scripts/buildsystems/vcpkg.cmake)

project("chirp-z")

add_executable(
    ${PROJECT_NAME}
    chirpz.cpp
    include/czt.h
    src/czt.cpp
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
