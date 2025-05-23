from robot.libraries.BuiltIn import BuiltIn


def the_input_is(*args: str):
    builtin = BuiltIn()
    builtin.set_test_variable('${std_input}', ''.join(args))    
