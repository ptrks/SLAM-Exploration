SET(EXAMPLES
        slam_01_a_plot_motor_ticks.cpp
        slam_01_b_print_motor_increments.cpp
        slam_01_c_plot_motor_increments.cpp
        slam_02_a_filter_motor_question.cpp
    )

#find_package(Python2 COMPONENTS Development)

foreach(SRC IN LISTS EXAMPLES)
    get_filename_component(TARGET ${SRC} NAME_WE)
    add_executable(${TARGET} ${SRC})
   # target_link_libraries(${TARGET} Python2::Python utility)
    target_link_libraries(${TARGET} utility)

endforeach()
