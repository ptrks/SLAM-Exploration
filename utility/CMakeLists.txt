find_package(Python2 COMPONENTS Development)

add_library(utility STATIC LegoRobot.cpp string_utility.cpp ../extern/matplotlibcpp/matplotlibcpp.h)


target_include_directories(utility PUBLIC . PUBLIC ../extern/matplotlibcpp)

target_link_libraries(utility Python2::Python)