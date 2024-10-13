# C++ European Option Pricer

## Description

This project is a C++ implementation for option pricing using Black & Scholes framework and compute sensitivities (greeks) in a way of there is no dependencies with a third-party library.

More things to come...

## Authors 🧠

- Amir Mahmoudi

## Features 💻

- **European Options**: Pricing and greeks for european option call and put

## Implementation ✍️
### Class version

>- EuropeanOption.hpp: Header file containing the declaration of the EuropeanOption class, which defines the properties and pricing methods for European options.
>- EuropeanOption.cpp: Contains the implementation of the EuropeanOption class.
>- Pricer.cpp : Main file compiling the code

### Straightforward version

>EuropeanOption_wo_class.cpp : Directly price using one cpp file

## Results 💰

```[Running] cd "d:\Pricer_Cpp\" && g++ Pricer.cpp -o Pricer && "d:\Pricer_Cpp\"Pricer
Underlying:      100
Strike:          100
Risk-Free Rate:  0.05
Volatility:      0.2
Maturity:        1
Put Price:      7.57709
Delta:           -0.460172
Gamma:           0.0198476
Vega:            39.6953
Theta:           -1.40202
Rho:             -51.35
```