#include <iostream>
#include <omp.h>
#include <cmath>

int main()
{
    int n = 10000;
    double s = 0.0;

#pragma omp parallel for reduction(+:s)
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            s += 1.0 / pow(2, i) + pow(j, 3);
        }
    }

    std::cout << "The value of s is: " << s << std::endl;

    return 0;
}
