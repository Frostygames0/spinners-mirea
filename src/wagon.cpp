#include <iostream>

int CalculateTrainSectionBySeat(int seat)
{
    // 4 местные
    if (seat < 36)
    {
        return (seat - 1) / 4;
    }
    // 2 местные
    else
    {
        return 8 - (seat - 37) / 2;
    }
}

constexpr int sections = 9;
constexpr int totalSeatsPerSection = 6;

int main()
{
    int n = 0;
    std::cin >> n;

    if (n < 0)
    {
        std::cerr << "There are no negative seats;";
        return -1;
    }

    if (n > 54)
    {
        std::cerr << "This seat count won't fit into the wagon!";
        return -1;
    }

    int freeSeatsPerSection[sections]{};
    int duplicates[54]{};

    for (int i = 0; i < n; i++)
    {
        int seat = 0;
        std::cin >> seat;

        if (seat < 1 || seat > 54)
        {
            std::cerr << "Seat out of bounds!";
            return -1;
        }

        if (duplicates[seat - 1] > 0)
        {
            std::cerr << "Duplicate seat " << seat;
            return -1;
        }

        duplicates[seat - 1]++;

        freeSeatsPerSection[CalculateTrainSectionBySeat(seat)]++;
    }

    int answer = 0;
    int current = 0;

    for (int i = 0; i < sections; i++)
    {
        if (freeSeatsPerSection[i] == totalSeatsPerSection)
        {
            current++;

            if (current > answer)
            {
                answer = current;
            }
        }
        else
        {
            current = 0;
        }
    }

    std::cout << answer;
}