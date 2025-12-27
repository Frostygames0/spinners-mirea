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
    int freeSeatsPerSection[sections]{};

    int n = 0;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        int seat = 0;
        std::cin >> seat;

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