#include <iostream>
#include <limits>
#include <functional>

template <typename T>
T input_validation(T & value, std::string error_msg)
{
    while (!(std::cin >> value)) 
    {
	std::cout << error_msg;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return value;
}

template <typename T>
T input_validation(T & value, const std::function<bool(T)> & invalid_inputs, const std::string & error_msg)
{
    while (!(std::cin >> value) || invalid_inputs(value)) 
    {
	std::cout << error_msg;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return value;
}

// invalid_inputs returns true if the value is an invalid input by your definition
// no endline after error message print to leave room for input message :3
// cannot use 'value' in error message and cannot create different messages for specific errors
// try listing the errors within 'error_msg' if there aren't many conditions

// This works well for a terminal interface that requires infinite retries for invalid inputs
// Not sure if this helps with anything else though
