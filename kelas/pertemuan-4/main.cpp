#include <iostream>
using namespace std;

int kali(int a, int b);
double kali(double a, double b);

int faktorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * faktorial(n-1);
}

int main()
{
    cout << kali(5.2, 6.2) << endl;
    cout << kali(5, 6) << endl;

    cout << faktorial(5);
    return 0;
}

int kali(int a, int b)
{
    return a * b;
}

double kali(double a, double b)
{
    return a * b;
};