#include <iostream>
#include <map>

using ll = long long;

int main()
{
    ll n = 0, k = 0;
    std::cin >> n >> k;

    if (k < 1 || n < 1 || k > n || n > 1000000000000000000LL)
    {
        std::cerr << "Values out of bounds!";
        return -1;
    }

    std::map<ll, ll, std::greater<ll>> map;
    map[n] = 1;

    ll lastLeft = 0, lastRight = 0;

    while (k > 0)
    {
        auto iterator = map.begin();
        ll length = iterator->first;
        ll count = iterator->second;

        map.erase(iterator);

        ll left = (length - 1) / 2;
        ll right = length / 2;

        if (k <= count)
        {
            lastLeft = left;
            lastRight = right;
            break;
        }

        k -= count;
        if (left > 0)
        {
            map[left] += count;
        }
        if (right > 0)
        {
            map[right] += count;
        }
    }

    std::cout << lastLeft << "\n" << lastRight;
    return 0;
}