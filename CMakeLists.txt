cmake_minimum_required(VERSION 3.10)

project(MonteCarloOptionPricing)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(montecarlo
    main.cpp
    src/Option.cpp
    src/MonteCarlo.cpp
    src/BlackScholes.cpp
)