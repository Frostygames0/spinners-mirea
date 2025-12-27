#include <iostream>

int main()
{
    int m = 0, n = 0;

    std::cin >> m >> n;

    int ansX = 0, ansY = 0;

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