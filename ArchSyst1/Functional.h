#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip> 
using namespace std;

const int iter_plus_   = 99999999;
const int iter_minus_  = 99999999;
const int iter_mult_   = 99999999;
const int iter_divide_ = 99999999;

template<typename T>
clock_t Empty_cycle(const int& );

template<typename T>
clock_t Add(const int& );

template<typename T>
clock_t Subtract(const int& );

template<typename T>
clock_t Multiply(const int& );

template<typename T>
clock_t Divide(const int& );

template<typename T>
double CheckEff(int );

struct data_
{
    string oper_ = "";
    string type_ = "";
    double value_ = 0.;
};

void RunTests(data_* );

void FillTable(data_*  );

double FindMax(data_* );

void OutputResult(data_* );
