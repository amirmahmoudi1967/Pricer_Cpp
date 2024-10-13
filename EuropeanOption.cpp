/*
C++ implementation of Black and Scholes European option
EuropeanOption.cpp
Amir MAHMOUDI
Description: This file contains European Option class implementation
*/

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "EuropeanOption.hpp"

// Function to calculate d1 in the Black-Scholes formula
double EuropeanOption::D1() const
{
	return (log(p_S / p_K) + (p_sigma * p_sigma / 2) * p_T) / (p_sigma * sqrt(p_T));
}

// Function to calculate d2 in the Black-Scholes formula
double EuropeanOption::D2(const double& d1) const
{
	return d1 - p_sigma * sqrt(p_T);
}

// Cumulative distribution function for the standard normal distribution
double EuropeanOption::N(double x) const
{
	// constants
    double a1 =  0.254829592;
    double a2 = -0.284496736;
    double a3 =  1.421413741;
    double a4 = -1.453152027;
    double a5 =  1.061405429;
    double p  =  0.3275911;

    // Save the sign of x
    int sign = 1;
    if (x < 0)
        sign = -1;
    x = fabs(x)/sqrt(2.0);

    // A&S formula 7.1.26
    double t = 1.0/(1.0 + p*x);
    double y = 1.0 - (((((a5*t + a4)*t) + a3)*t + a2)*t + a1)*t*exp(-x*x);

    return 0.5*(1.0 + sign*y);
}

double EuropeanOption::N_prime(const double& d1) const
{
	return exp((-d1*d1)/2)/sqrt(2*M_PI);
}

// Calculate the price of the European option
double EuropeanOption::Price() const
{
	double d1 = D1();
	double d2 = D2(d1);

	if (p_option_type == "Call")
	{
		return p_S * exp(p_r * p_T) * N(d1) - p_K * exp(-p_r * p_T) * N(d2);
	}

	else if (p_option_type == "Put")
	{
		return p_K * exp(-p_r * p_T) * (1 - N(d2)) - p_S * exp(- p_r* p_T) * (1 - N(d1));
	}

	return 0;
}

//Calculate Greeks
double EuropeanOption::Delta() const
{
	double d1 = D1();
	double d2 = D2(d1);
	if (p_option_type == "Call")
	{
		return N(d1);
	}

	else if (p_option_type == "Put")
	{
		return -N(-d1);
	}

	return 0;
}
double EuropeanOption::Gamma() const
{
	double d1 = D1();
	double d2 = D2(d1);
	return N_prime(d1)/(p_S*p_sigma*sqrt(p_T));
}

double EuropeanOption::Vega() const
{
	double d1 = D1();
	double d2 = D2(d1);
	return N_prime(d1)*p_S*sqrt(p_T);
}

double EuropeanOption::Rho() const
{
	double d1 = D1();
	double d2 = D2(d1);
	if (p_option_type == "Call")
	{
		return p_K*p_T*N(d2)*exp(-p_r*p_T);
	}

	else if (p_option_type == "Put")
	{
		return -p_K*p_T*N(-d2)*exp(-p_r*p_T);
	}

	return 0;
}

double EuropeanOption::Theta() const
{
	double d1 = D1();
	double d2 = D2(d1);
	if (p_option_type == "Call")
	{
		return -p_S*N_prime(d1)*p_sigma/(2*sqrt(p_T))-p_r*p_K*N(d2)*exp(-p_r*p_T);
	}

	else if (p_option_type == "Put")
	{
		return -p_S*N_prime(d1)*p_sigma/(2*sqrt(p_T))+p_r*p_K*N(-d2)*exp(-p_r*p_T);
	}

	return 0;
}

// Constructor for EuropeanOption class
EuropeanOption::EuropeanOption(const std::string& option_type, const double& T,
    const double& K, const double& S, const double& r,const double& sigma) :
	p_option_type(option_type),
	p_T(T),
	p_K(K),
	p_S(S),
	p_r(r),
	p_sigma(sigma)

{}



