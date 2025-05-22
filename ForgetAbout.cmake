make_directory(${CMAKE_BINARY_DIR}/test_output)

if(POLICY CMP0135)
  cmake_policy(SET CMP0135 NEW)
endif()

enable_testing()

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/0bdccf4aa2f5c67af967193caf31d42d5c49bde2.zip
)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)


function(add_ut executable sources)
  add_executable(
    ${executable}
    ${sources}
    ${ARGN}
  )

  target_link_libraries(
    ${executable}
    GTest::gmock_main
  )

  gtest_discover_tests(${executable})  
endfunction(add_ut)


function(add_bdd_test test_name robot_file)
  add_test(
    NAME ${test_name}
    WORKING_DIRECTORY $ENV{BUILD_DIR}
    COMMAND robot "$ENV{TEST_DIR}/${robot_file}"
  )
endfunction()
