// Copyright (c) 2025 Volodymyr Kryzhanovskyi All rights reserved
// Created by: Volodymyr Kryzhanovskyi
// Created on: 03-13-2025
// This program defines the quadratic problems, including the conversions and finding vertex parabola
#include <iostream>
#include <cmath>
#include <string>
#include <stdexcept> // Include for std::domain_error

int main() {
    // Welcomes user
    std::cout << "Welcome user, today we will calculate quadratic problems and other problems associated with them." << std::endl;

    // Taking input for the variables of the quadratic equation
    std::string a_str, b_str, c_str;
    double a_int, b_int, c_int;

    std::cout << "Enter first variable in formula: ";
    std::cin >> a_str;
    std::cout << "Enter second variable in formula: ";
    std::cin >> b_str;
    std::cout << "Enter third variable for formula: ";
    std::cin >> c_str;

    try {
        // Attempting to convert input strings to doubles
        a_int = std::stod(a_str);
        b_int = std::stod(b_str);
        c_int = std::stod(c_str);

        // Asking user if they want to calculate the parabola using vertex formula
        std::string question_1;
        std::cout << "Do you want to calculate the parabola in vertex formula? Type yes if you want and no if you don't want: ";
        std::cin >> question_1;

        if (question_1 == "yes" || question_1 == "YES" || question_1 == "Yes") {
            // Print the original quadratic formula
            std::cout << "Your formula looks like: " << a_int << "x^2 + " << b_int << "x + " << c_int << std::endl;
            // Calculate vertex x-coordinate
            double e_int = b_int / a_int;
            // Calculate half of the coefficient for vertex form
            double d_int = std::pow(e_int / 2, 2);
            std::cout << b_int << std::endl;
            if (b_int > 0) {
                double c_int_vertex = a_int * -d_int + c_int; // Adjust constant if b is positive
                double d_int_sqrt = std::sqrt(d_int);
                double d_int_rounded = std::round(d_int_sqrt * 100.0) / 100.0;
                double c_int_rounded = std::round(c_int_vertex * 100.0) / 100.0;
                std::cout << "Your vertex formula looks like " << a_int << " (x - " << d_int_rounded << ")^2 + " << c_int_rounded << std::endl;
            } else if (b_int < 0) {
                double c_int_vertex = a_int * -e_int + c_int; // Adjust constant if b is positive (Note: Python used -e_int here, might be a logical error)
                double d_int_sqrt = std::sqrt(d_int);
                double d_int_rounded = std::round(d_int_sqrt * 100.0) / 100.0;
                double c_int_rounded = std::round(c_int_vertex * 100.0) / 100.0;
                std::cout << "Your formula in vertex looks like " << a_int << "(x + " << d_int_rounded << ")^2 " << c_int_rounded << std::endl;
            }
        } else if (question_1 == "no" || question_1 == "NO" || question_1 == "No") {
            // Asking if the quadratic has a power
            std::string question_2;
            std::cout << "Is your quadratic equation in power of something? If it is, type yes, if it is not then type no: ";
            std::cin >> question_2;

            if (question_2 == "yes" || question_2 == "YES" || question_2 == "Yes") {
                // Taking input for the power of the quadratic equation
                std::string power_str;
                double power;
                std::cout << "Enter to what power will your quadratic equation be: ";
                std::cin >> power_str;
                try {
                    power = std::stod(power_str); // Convert power input to double
                    double x_power = std::pow(2, power); // Calculate resulting power
                    std::cout << "The formula will look like," << a_int << "x^" << x_power << " + " << b_int << "x^" << power << " + " << c_int << std::endl;
                    // Simplifying the coefficients based on the given power
                    double a_simplified = std::pow(a_int, 1 / power);
                    double b_simplified = std::pow(b_int, 1 / power);
                    double c_simplified = std::pow(c_int, 1 / power);
                    std::cout << "The simplified formula will look like " << power << "√ over each number " << a_simplified << "x^2 + " << b_simplified << "x + " << c_simplified << std::endl;
                    std::cout << "We will use the discriminant theory to find the roots of equation." << std::endl;
                    double discriminant = std::pow(b_simplified, 2) - (4 * a_simplified * c_simplified); // Calculate the discriminant
                    std::cout << discriminant << std::endl;
                    try {
                        if (discriminant < 0) {
                            throw std::domain_error("Discriminant is negative, no real roots.");
                        }
                        double sqrt_discriminant = std::sqrt(discriminant);
                        double x_one = (-b_simplified + sqrt_discriminant) / (2 * a_simplified);
                        double x_two = (-b_simplified - sqrt_discriminant) / (2 * a_simplified);
                        std::cout << "The roots of quadratic problem are " << std::round(x_one * 100.0) / 100.0 << " and " << std::round(x_two * 100.0) / 100.0 << std::endl;
                    } catch (const std::domain_error& e) {
                        std::cout << e.what() << std::endl;
                    }
                } catch (const std::invalid_argument& e) {
                    std::cout << "Enter the float for the power." << std::endl; // Handle invalid float input
                }
            } else if (question_2 == "no" || question_2 == "NO" || question_2 == "No") {
                // Printing the standard form of the quadratic equation
                std::cout << "Your formula looks like, " << a_int << "x^2 + " << b_int << "x + " << c_int << std::endl;
                std::cout << "We will use the discriminant theory to find the roots of equation." << std::endl;
                // Calculate discriminant again
                double discriminant = (b_int * b_int) - (4 * a_int * c_int);
                std::cout << discriminant << std::endl;
                try {
                    if (discriminant < 0) {
                        throw std::domain_error("Discriminant is negative, no real roots.");
                    }
                    double sqrt_discriminant = std::sqrt(discriminant);
                    double x_one = (-b_int + sqrt_discriminant) / (2 * a_int);
                    double x_two = (-b_int - sqrt_discriminant) / (2 * a_int);
                    std::cout << "The roots of quadratic problem are " << std::round(x_one * 100.0) / 100.0 << " and " << std::round(x_two * 100.0) / 100.0 << std::endl;
                } catch (const std::domain_error& e) {
                    std::cout << e.what() << std::endl;
                }
            }
        }
    } catch (const std::invalid_argument& e) {
        // Handle case for invalid input
        std::cout << "Correct numerical input needed for the coefficients (a, b, c)." << std::endl;
    }
// cite https://medium.com/@ryan_forrester_/how-to-round-in-c-complete-guide-e02c9e671050 , https://cppbyexample.com/exceptions.html , https://learn.microsoft.com/en-us/cpp/standard-library/stdexcept?view=msvc-170, 