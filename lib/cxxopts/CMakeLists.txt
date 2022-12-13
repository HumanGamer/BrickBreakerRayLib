project(cxxopts)

add_library(cxxopts INTERFACE)
add_library(cxxopts::cxxopts ALIAS cxxopts)
add_subdirectory(include)
