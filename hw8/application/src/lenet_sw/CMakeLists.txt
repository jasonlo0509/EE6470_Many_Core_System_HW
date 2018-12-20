## make lenet_sw
add_custom_target(lenet_sw
                  COMMAND ../../platform/build/multi_core.plat ./lenet_sw.app
                  WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
)

FILE(GLOB src *.cpp)

# These are necessary implementations supporting C++ features

add_executable(lenet_sw.app ../lib/crt0.s ${CRT_OBJ_FILES} ${src} )
target_link_libraries(lenet_sw.app sync)
