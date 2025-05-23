# CMake generated Testfile for 
# Source directory: /workspaces/big-bad
# Build directory: /workspaces/big-bad/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
include("/workspaces/big-bad/build/unit_test[1]_include.cmake")
add_test(BDD_vend "robot" "/workspaces/big-bad/tests/test_vend.robot")
set_tests_properties(BDD_vend PROPERTIES  WORKING_DIRECTORY "/workspaces/big-bad/build" _BACKTRACE_TRIPLES "/workspaces/big-bad/ForgetAbout.cmake;37;add_test;/workspaces/big-bad/CMakeLists.txt;29;add_bdd_test;/workspaces/big-bad/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
