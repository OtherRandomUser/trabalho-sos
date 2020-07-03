# add_executable(sequential
#     order-gen/sequential
# )

# target_include_directories(sequential
#     PRIVATE
#         ${CMAKE_CURRENT_SOURCE_DIR}
# )

add_executable(parallel
    order-gen/parallel
    order-gen/gene
)

target_include_directories(parallel
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries( parallel ${CMAKE_THREAD_LIBS_INIT} )