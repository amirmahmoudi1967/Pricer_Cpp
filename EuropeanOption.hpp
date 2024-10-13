/*
C++ implementation of Black and Scholes European option
EuropeanOption.hpp
Amir MAHMOUDI
Description: This file contains EuropeanOption class
*/

// If EUROPEANOPTION_HPP is not defined
#ifndef EUROPEANOPTION_HPP
// Define EUROPEANOPTION_HPP
#define EUROPEANOPTION_HPP


#include <string>
#include <vector>

class EuropeanOption
{
    private:
        //option type : call or put
        std::string p_option_type;
        // Time to expiration
        double p_T;
        // Strike price
        double p_K;
        // Spot price
        double p_S;
        // Risk-free interest rate
        double p_r;
        // Volatility
        double p_sigma;

        // Calculate d1 for Black-Scholes formula
        double D1() const;
        // Calculate d2 for Black-Scholes formula
        double D2(const double& d1) const;

        // Standard normal cumulative distribution function
	    double N(double x) const;

        double N_prime(const double& d1) const;

    public:
        
        // Constructor
        EuropeanOption(const std::string& type, const double& T, const double& K, 
            const double& S, const double& r,const double& sigma);


        // Calculate option price
	    double Price() const;
    
        //Calculate greeks
        double Delta() const;
        double Gamma() const;
        double Vega() const;
        double Theta() const;
        double Rho() const;
        
        // Get inline functions
        // Get option type
        const std::string& option_type() const { return p_option_type; }
        // Get time to expiration
        const double& T() const { return p_T; }
        // Get strike price
        const double& K() const { return p_K; }
        // Get spot price
        const double& S() const { return p_S; }
        // Get risk-free interest rate
        const double& r() const { return p_r; }
        // Get volatility
        const double& sigma() const { return p_sigma; }

};
#endif