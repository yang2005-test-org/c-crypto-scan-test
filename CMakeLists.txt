cmake_minimum_required(VERSION 3.10)
project(c_crypto_scan_test C)

find_package(OpenSSL REQUIRED)
add_executable(crypto_sample crypto_sample.c)
target_link_libraries(crypto_sample OpenSSL::SSL OpenSSL::Crypto)
