## make lenet_sw
add_custom_target(lenet_sw
                  COMMAND ../../platform/build/pooling.plat ./lenet_sw.app
                  WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
)

FILE(GLOB src *.cpp)
add_executable(lenet_sw.app ${src})
target_link_libraries(lenet_sw.app)
