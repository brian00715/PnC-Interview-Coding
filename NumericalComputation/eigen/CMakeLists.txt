find_package(Eigen3 REQUIRED PATHS "/Users/simon/Applications/eigen-3.4.0/bin")

project(eigen_demo)

add_executable(test test.cc)
target_link_libraries(test Eigen3::Eigen)