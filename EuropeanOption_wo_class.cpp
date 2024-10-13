#include <iostream>
#include <cmath>



// An approximation to the cumulative distribution function
// for the standard normal distribution
// Note: This is a recursive function
double N(double x) {

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


double D1(double S, double K, double r, double sigma,double T)
{
	return (log(S / K) + (sigma * sigma / 2) * T) / (sigma * std::sqrt(T));
}

double D2(double d1,double sigma,double T)
{
	return d1 - sigma * std::sqrt(T);
}

double Price(char option_type,double S, double K,
            double r, double sigma, double T)
{
	double d1 = D1(S, K, r, sigma, T);
	double d2 = D2(d1,sigma, T);

	if (option_type == 'C')
	{
		return S * std::exp(r * T) * N(d1) - K * std::exp(-r * T) * N(d2);
	}

	else if (option_type == 'P')
	{
		return K * std::exp(-r * T) * (1 - N(d2)) - S * std::exp(- r* T) * (1 - N(d1));
	}
    return 0;
}

int main() {
    // First we create the parameter list
    double S = 100.0;  // Option price
    double K = 100.0;  // Strike price
    double r = 0.05;   // Risk-free rate (5%)
    double sigma = 0.2;    // Volatility of the underlying (20%)
    double T = 1.0;    // One year until expiry
    char type='C';

    // Then we calculate the call/put values
    double call = Price(type,S, K, r, sigma, T);
    type='P';
    double put = Price(type,S, K, r, sigma, T);

    // Finally we output the parameters and prices
    std::cout << "Underlying:      " << S << std::endl;
    std::cout << "Strike:          " << K << std::endl;
    std::cout << "Risk-Free Rate:  " << r << std::endl;
    std::cout << "Volatility:      " << sigma << std::endl;
    std::cout << "Maturity:        " << T << std::endl;

    std::cout << "Call Price:      " << call << std::endl;
    std::cout << "Put Price:       " << put << std::endl;

    return 0;
}