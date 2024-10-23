// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>
#include <exception>

bool do_even_more_custom_application_logic()
{
    // TODO: Throw any standard exception

    std::cout << "Running Even More Custom Application Logic." << std::endl;
    int x = -1;

    if (x < 0) {
        throw std::range_error("Int x out of range, ceasing operation.");
    }

    return true;
}
void do_custom_application_logic()
{
    // TODO: Wrap the call to do_even_more_custom_application_logic()
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
    std::cout << "Running Custom Application Logic." << std::endl;


    //Attempt to call do_even_more_custom_application_logic()
    try {
        if (do_even_more_custom_application_logic())
        {
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    }

    //Catch any exception thrown by do_even_more_custom_application_logic() and display the error message.
    catch (std::range_error& rngErr){
        std::cout << rngErr.what() << std::endl;
    }

    // TODO: Throw a custom exception derived from std::exception
    //  and catch it explictly in main

    std::cout << "Leaving Custom Application Logic." << std::endl;

    //Throw a range_error exception with a partial error message to be caught by main().
    throw std::logic_error("Error occurred in do_custom_application_logic. Terminating program");

}

float divide(float num, float den)
{
    // TODO: Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception

    //Check if the denominator is 0, if it is, throw a runtime_error exception to be caught by do_division()
    if (den == 0) {
        throw std::runtime_error("Error: Division by 0 not allowed.");
    }
    
    //Otherwise do the division normally and return the result.
    return (num / den);
}

void do_division() noexcept
{
    //  TODO: create an exception handler to capture ONLY the exception thrown
    //  by divide.

    float numerator = 10.0f;
    float denominator = 0;

    //Start the divide() function with the assigned values and display the outcome if successful
    try {
        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    }

    //catch a runtime error thrown by divide(), display the error message and return.
    catch (const std::runtime_error& runtmeErr) {
        std::cout << runtmeErr.what() << std::endl;
        return;
    }
}

int main()
{
    try {
        std::cout << "Exceptions Tests!" << std::endl;

        // TODO: Create exception handlers that catch (in this order):
        //  your custom exception
        //  std::exception
        //  uncaught exception 
        //  that wraps the whole main function, and displays a message to the console.
        do_division();
        do_custom_application_logic();
    }

    //Catch any exceptions that remain and display that error message with the addition of
    //"from main()." to show that the error was caught in main();
    catch (std::exception& expt1) {
        std::cout << expt1.what() << " from main()." << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu