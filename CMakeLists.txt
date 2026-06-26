cmake_minimum_required(VERSION 4.0)
project(FinanceManager)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(FinanceManager src/main.cpp
        include/Transaction.h
        include/Wallet.h
        src/Transaction.cpp
        src/Wallet.cpp
        include/FinanceManager.h
        src/FinanceManager.cpp)
target_include_directories(FinanceManager PRIVATE include)