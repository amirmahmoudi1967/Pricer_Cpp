/*
C++ implementation of Black and Scholes European option
Pricer.cpp
Amir MAHMOUDI
Description: This file contains main pricer function
*/
#include <iostream>
#include <vector>
#include "EuropeanOption.hpp"
#include "EuropeanOption.cpp"

// Define main function of the program
int main()
{
    // First we create the parameter list
    double S = 100.0;  // Option price
    double K = 100.0;  // Strike price
    double r = 0.05;   // Risk-free rate (5%)
    double sigma = 0.2;    // Volatility of the underlying (20%)
    double T = 1.0;    // One year until expiry
    std::string option_type="Put";

    EuropeanOption option(option_type, T, K, S, r,sigma);
    // Finally we output the parameters and prices
    std::cout << "Underlying:      " << S << std::endl;
    std::cout << "Strike:          " << K << std::endl;
    std::cout << "Risk-Free Rate:  " << r << std::endl;
    std::cout << "Volatility:      " << sigma << std::endl;
    std::cout << "Maturity:        " << T << std::endl;

    std::cout << option_type << " Price:      " << option.Price() << std::endl;
    std::cout << "Delta:           " << option.Delta() << std::endl;
    std::cout << "Gamma:           " << option.Gamma() << std::endl;
    std::cout << "Vega:            " << option.Vega() << std::endl;
    std::cout << "Theta:           " << option.Theta() << std::endl;
    std::cout << "Rho:             " << option.Rho() << std::endl;
    
}