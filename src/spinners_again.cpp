#include <iostream>

int main()
{
    int m = 0;
    std::cin >> m;

    int spin4 = m % 3;
    int spin3 = (m - 4 * spin4) / 3;

    if (spin3 >= 0)
    {
        std::cout << spin3 << "\n" << spin4;
    }
    else
    {
        std::cout << "0\n0";
    }
}