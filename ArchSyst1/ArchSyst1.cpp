
#include "Functional.h"

int main()
{
    system("COLOR F5");
    const int N = 20;
    data_* res = new data_[N];
    FillTable(res);
    RunTests(res);
    OutputResult(res);

    delete[] res;
    return 0;
}