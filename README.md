# Welcome to the Big Bad Voodoo Daddy workshop!

The world of software is dark and full of errors, so grab a torch to light your way:
- [GoogleTest Reference](https://google.github.io/googletest/reference/testing.html)
- [Robot Framework User Guide](https://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html)


## After starting a codespace

View Robot Framework output at http://0.0.0.0:8000/


### Build & Test
inside the build directory (`cd build/`) with
`make` and `ctest`.

#### This is based on [CMakeLists.txt](CMakeLists.txt):
- `add_executable(program sources...)`
- `add_ut(name sources...)`
- `add_bdd_test(name file)`


--- 

_(If you clear/remove the entire `build/` directory, you will need to `cmake ..` from it once)_.

