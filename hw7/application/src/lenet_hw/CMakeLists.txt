## make lenet_hw
add_custom_target(lenet_hw
                  COMMAND ../../platform/build/pooling.plat ./lenet_hw.app
                  WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
)

FILE(GLOB src *.cpp)
add_executable(lenet_hw.app ${src})
target_link_libraries(lenet_hw.app)
