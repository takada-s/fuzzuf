add_executable( test-executor-run-non-fork run.cpp )
target_link_libraries(
  test-executor-run-non-fork
  test-common
  fuzzuf
  ${FUZZUF_LIBRARIES}
  Boost::unit_test_framework
)
target_include_directories(
  test-executor-run-non-fork
  PRIVATE
  ${FUZZUF_INCLUDE_DIRS}
  ${CMAKE_SOURCE_DIR}/test/common
)
set_target_properties(
  test-executor-run-non-fork
  PROPERTIES COMPILE_FLAGS "${ADDITIONAL_COMPILE_FLAGS_STR}"
)
set_target_properties(
  test-executor-run-non-fork
  PROPERTIES LINK_FLAGS "${ADDITIONAL_COMPILE_FLAGS_STR}"
)
if( ENABLE_CLANG_TIDY )
  set_target_properties(
    test-executor-run-non-fork
    PROPERTIES
    CXX_CLANG_TIDY "${CLANG_TIDY};${CLANG_TIDY_CONFIG_FOR_TEST}"
  )
endif()
add_test( NAME "native_linux_executor.native_linux_context.non_fork.run" 
          COMMAND test-executor-run-non-fork )

add_executable( test-executor-non_fork_server_mode-environment_variables environment_variables.cpp )
target_link_libraries(
  test-executor-non_fork_server_mode-environment_variables
  test-common
  fuzzuf
  ${FUZZUF_LIBRARIES}
  Boost::unit_test_framework
)
target_include_directories(
  test-executor-non_fork_server_mode-environment_variables
  PRIVATE
  ${FUZZUF_INCLUDE_DIRS}
  ${CMAKE_SOURCE_DIR}/test/common
)
set_target_properties(
  test-executor-non_fork_server_mode-environment_variables
  PROPERTIES COMPILE_FLAGS "${ADDITIONAL_COMPILE_FLAGS_STR}"
)
set_target_properties(
  test-executor-non_fork_server_mode-environment_variables
  PROPERTIES LINK_FLAGS "${ADDITIONAL_COMPILE_FLAGS_STR}"
)
if( ENABLE_CLANG_TIDY )
  set_target_properties(
    test-executor-non_fork_server_mode-environment_variables
    PROPERTIES
    CXX_CLANG_TIDY "${CLANG_TIDY};${CLANG_TIDY_CONFIG_FOR_TEST}"
  )
endif()
add_test( NAME "executor.non_fork_server_mode.environment_variables" 
          COMMAND test-executor-non_fork_server_mode-environment_variables )

add_executable( test-executor-non_fork_server_mode-output_dir output_dir.cpp )
target_link_libraries(
  test-executor-non_fork_server_mode-output_dir
  test-common
  fuzzuf
  ${FUZZUF_LIBRARIES}
  Boost::unit_test_framework
)
target_include_directories(
  test-executor-non_fork_server_mode-output_dir
  PRIVATE
  ${FUZZUF_INCLUDE_DIRS}
  ${CMAKE_SOURCE_DIR}/test/common
)
set_target_properties(
  test-executor-non_fork_server_mode-output_dir
  PROPERTIES COMPILE_FLAGS "${ADDITIONAL_COMPILE_FLAGS_STR}"
)
set_target_properties(
  test-executor-non_fork_server_mode-output_dir
  PROPERTIES LINK_FLAGS "${ADDITIONAL_COMPILE_FLAGS_STR}"
)
if( ENABLE_CLANG_TIDY )
  set_target_properties(
    test-executor-non_fork_server_mode-output_dir
    PROPERTIES
    CXX_CLANG_TIDY "${CLANG_TIDY};${CLANG_TIDY_CONFIG_FOR_TEST}"
  )
endif()
add_test( NAME "executor.non_fork_server_mode.output_dir"
          COMMAND test-executor-non_fork_server_mode-output_dir )
