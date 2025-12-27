#include <iostream>

int main()
{
    int n = 0, m = 0;
    std::cin >> n >> m;

    int ansX = 0, ansY = 0;

    if (n > 75000 || m > 75000)
    {
        std::cerr << "Too big values!";
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        ansX += n - i;
    }

    for (int i = 0; i < m; i++)
    {
        ansY += m - i;
    }

    std::cout << ansX * ansY;
}