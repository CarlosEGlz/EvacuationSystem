#include <iostream>
#include <map>
using std::cout;
using std::map;

const int NUM_OF_HOUSES{50};
const int TIME{5};

void roadSection(map<int, int> &housesMap)
{
    int v1, v2;
    for (size_t i = 0; i < NUM_OF_HOUSES; i++)
    {
        v1 = rand() % NUM_OF_HOUSES + 1;
        v2 = rand() % TIME + 1;
        housesMap.insert({v1, v2});
    }
}

void print(map<int, int> &housesMap)
{
    cout << "Road\t:\tSection\n";
    for (auto i = housesMap.begin(); i != housesMap.end(); i++)
    {
        cout << i->first << "\t:\t" << i->second << '\n';
    }
}

int main()
{
    map<int, int> housesMap;
    // MAKE Road & Section Function to add to the map.
    roadSection(housesMap);

    // PRINT FUNCTION
    print(housesMap);

    // MAKE Verification Function.


    return 0;
}
