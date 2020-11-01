#include "Functional.h"
#include <windows.h>

void RunTests(data_* src)
{
    src[0].value_ = CheckEff<int>(0);
    src[1].value_ = CheckEff<int>(1);
    src[2].value_ = CheckEff<int>(2);
    src[3].value_ = CheckEff<int>(3);

    src[4].value_ = CheckEff<long>(0);
    src[5].value_ = CheckEff<long>(1);
    src[6].value_ = CheckEff<long>(2);
    src[7].value_ = CheckEff<long>(3);

    src[8].value_ = CheckEff<char>(0);
    src[9].value_ = CheckEff<char>(1);
    src[10].value_ = CheckEff<char>(2);
    src[11].value_ = CheckEff<char>(3);

    src[12].value_ = CheckEff<float>(0);
    src[13].value_ = CheckEff<float>(1);
    src[14].value_ = CheckEff<float>(2);
    src[15].value_ = CheckEff<float>(3);

    src[16].value_ = CheckEff<double>(0);
    src[17].value_ = CheckEff<double>(1);
    src[18].value_ = CheckEff<double>(2);
    src[19].value_ = CheckEff<double>(3);
}


void FillTable(data_* src)
{
   
    for (int i = 0; i < 4; i++)
        src[i].type_ = "int";

    for (int i = 4; i < 8; i++)
        src[i].type_ = "long";

    for (int i = 8; i < 12; i++)
        src[i].type_ = "char";

    for (int i = 12; i < 16; i++)
        src[i].type_ = "float";

    for (int i = 16; i < 20; i++)
        src[i].type_ = "double";

    
    for (int i = 0; i < 20; i += 4)
        src[i].oper_ = "+";

    for (int i = 1; i < 20; i += 4)
        src[i].oper_ = "-";

    for (int i = 2; i < 20; i += 4)
        src[i].oper_ = "*";

    for (int i = 3; i < 20; i += 4)
        src[i].oper_ = "/";

}

double FindMax(data_* src)
{
    double res = src[0].value_;
    for (int i = 1; i < 20; ++i)
        res = src[i].value_ > res ? src[i].value_ : res;

    return res;
}

void OutputResult(data_* src)
{
    const int table_size = 60;
    double efficiency = 0.;
    double max_res = FindMax(src);
    for (int i = 0; i < 20; ++i)
    {
        
        efficiency = src[i].value_ / max_res;
        cout << left
            << setw(4) << src[i].oper_
            << setw(10) << src[i].type_
            << scientific << setprecision(10) << setw(10) << src[i].value_
            << setw(4) << "" << setw(1);

        int j;
        for (j = 0; j < efficiency * table_size; j++)
            cout << "X";
        for (; j < table_size; ++j)
            cout << " ";

        cout << setw(4) << ""
            << fixed << setprecision(0) << setw(4) << efficiency * 100
            << setw(1) << "%";

        cout << endl;
    }
}

template<typename T>
clock_t Empty_cycle(const int& iter) {

    clock_t t_start, t_end;

    t_start = clock();
    for (size_t i = 0; i < iter; ++i) {

    }
    t_end = clock();
    return t_end - t_start;
}

template<typename T>
clock_t Add(const int& iter) {

    clock_t t_start, t_end;

    T a, b, c, d, e, f, g, h, k, l;

    t_start = clock();
    for (int i = 0; i < iter; ++i) {
        a = i + 83226363;//random values
        b = i + 62873456;
        c = a + 27135542;
        d = b + 29296528;
        e = a + b;
        f = d + e;
        g = a + f;
        h = g + 654568;
        k = f + 48237654;
        l = c + 4382345;
    }
    t_end = clock();
    return t_end - t_start;
}

template<typename T>
clock_t Subtract(const int& iter) {

    clock_t t_start, t_end;

    T a, b, c, d, e, f, g, h, k, l;

    t_start = clock();
    for (int i = 0; i < iter; ++i) {
        a = i - 876545678;
        b = i - 432123457;
        c = a - b;
        d = b - i;
        e = a - 456789876;
        f = d - e;
        g = a - 3456789876;
        h = g - 1234567876;
        k = f - 87654;
        l = c - k;
    }
    t_end = clock();
    return t_end - t_start;
}

template<typename T>
clock_t Multiply(const int& iter) {

    clock_t t_start, t_end;

    T a, b, c, d, e, f, g, h, k, l;

    t_start = clock();
    for (int i = 0; i < iter; i++) {
        a = i * 7654367;
        b = i * 8311189;
        c = a * 5678765;
        d = b * 1234543;
        e = a * 7890987;
        f = d * 123457;
        g = a * b;
        h = g * a;
        k = f * c;
        l = c * k;
    }
    t_end = clock();
    return t_end - t_start;
}


template<typename T>
clock_t Divide(const int& iter) {

    clock_t t_start, t_end;

    T a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;
    T dev1 = 4358;
    T dev2 = 34567;
    T dev3 = 9876;
    T dev4 = 1234;
    T dev5 = 45;
    T dev6 = 45678;
    T dev7 = 8765;
    T dev8 = 543234;
    T dev9 = 23;
    T dev10 = 542487;

    t_start = clock();
    for (int i = 0; i < iter; i++) {
        a1 = i / dev1;
        a2 = i / dev2;
        a3 = i / dev3;
        a4 = i / dev4;
        a5 = i / dev5;
        a6 = i / dev6;
        a7 = i / dev7;
        a8 = i / dev8;
        a9 = i / dev9;
        a10 = i / dev10;
    }
    t_end = clock();
    return t_end - t_start;
}

template<typename T>
double CheckEff(int oper) {
    double res = 0;
    switch (oper) {
    case 0:
        res = iter_plus_ / ((double)Add<T>(iter_plus_) - (double)Empty_cycle<T>(iter_plus_)) * CLOCKS_PER_SEC;
        break;
    case 1:
        res = iter_minus_ / ((double)Subtract<T>(iter_minus_) - (double)Empty_cycle<T>(iter_minus_)) * CLOCKS_PER_SEC;
        break;
    case 2:
        res = iter_mult_ / ((double)Multiply<T>(iter_mult_) - (double)Empty_cycle<T>(iter_mult_)) * CLOCKS_PER_SEC;
        break;
    case 3:
        res = iter_divide_ / ((double)Divide<T>(iter_divide_) - (double)Empty_cycle<T>(iter_divide_)) * CLOCKS_PER_SEC;
        break;
    }
    return res;
}