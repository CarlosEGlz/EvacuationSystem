#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <iterator>
#include "House.cpp"
using std::cout;
using std::endl;

const int NUM_OF_HOUSES = 5;
const int TIME = 5;

std::multimap<int, int> housesMap;

void assignValues(House *houses);
void printClass(House *houses);
void validateRoadSection(House *houses, int index);
void traversed(House *houses);
void createMap(House *houses, int index);
void printMap();

void assignValues(House *houses) /* assign values to Class House
                                 for Road, Section, Occupants, and Cars.*/
{
    for (int i = 0; i < NUM_OF_HOUSES; i++)
    {
        houses[i].setRoad(rand() % NUM_OF_HOUSES + 1);
        houses[i].setSection(rand() % NUM_OF_HOUSES + 1);
        // houses[i].setOccupants(rand() % 5 + 1);
        // houses[i].setNumOfCars(rand() % 2 + 1);

        if (housesMap.size() == 0 || (houses[i].getRoad() == houses[i - 1].getRoad() &&
                                      houses[i].getSection() == houses[i - 1].getSection()))
        {
            validateRoadSection(houses, i);
        }
        createMap(houses, i);
    }
}

void validateRoadSection(House *houses, int index) /* Validates that no 2 houses are in the
                                                    are in the same road and section.*/
{
    std::multimap<int, int>::iterator it;

    do
    {
        it = housesMap.find(houses[index - 1].getSection());
        houses[index].setSection(rand() % NUM_OF_HOUSES + 1);

        if (it == housesMap.end())
        {
            break;
        }

    } while (houses[index].getSection() == houses[index - 1].getSection());
}

void traversed(House *houses) /*Assigne values for the time it takes to traversed
                                from the house to the safe location*/
{
    for (int i = 0; i < NUM_OF_HOUSES; i++)
    {
        houses[i].traversedRoadSection(NUM_OF_HOUSES, TIME);
    }
}

void createMap(House *houses, int index) /*Creates a map with the house locations*/
{
    housesMap.insert(std::pair<int, int>(houses[index].getRoad(),
                                         houses[index].getSection()));
}

void printMap() /*Prints the map with the house locations*/
{
    std::multimap<int, int>::iterator itr;

    cout << "\tHouses Map\n";
    cout << "\tRoad\tSection\n";
    for (itr = housesMap.begin(); itr != housesMap.end(); itr++)
    {
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }

    /* std::multimap<int, int>::reverse_iterator rit;
    // cout << '\n';
    // for (rit = housesMap.rbegin(); rit != housesMap.rend(); ++rit)
    //{
    //     cout << '\t' << rit->first << '\t' << rit->second
    //          << '\n';
    // }*/
}

void printClass(House *houses) /*Calls the class print function to print all members in
                                 in the House class*/
{
    cout << endl;
    for (size_t i = 0; i < NUM_OF_HOUSES; i++)
    {
        cout << "House #" << i + 1 << '\n';
        houses[i].print(TIME, i);
    }
}

int main()
{
    House houses[NUM_OF_HOUSES];

    assignValues(houses);
    traversed(houses);
    printClass(houses);
    // cout << "\nValidate";
    // printClass(houses);
    // printMap();
    // cout << housesMap.size();

    return 0;
}
