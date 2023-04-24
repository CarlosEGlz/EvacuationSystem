#include "House.h"

using std::cout;
using std::multimap;
std::ofstream output("outputFile.txt");

House::House()
{
}

House::House(int road, int section, int number_occupants,
             int number_of_cars, std::multimap<int, int> traversedMap,
             std::vector<int> roadVect, std::vector<int> sectVect)
{
    this->road = road;
    this->section = section;
    this->number_occupants = 1;
    this->number_of_cars = 1;
    this->traversedMap = traversedMap;
    this->roadVect = roadVect;
    this->sectVect = sectVect;
}

void House::validate() // WORK ON THIS
{
}

void House::setRoad(int road)
{
    this->road = road;
}
void House::setSection(int section)
{
    this->section = section;
}
void House::setOccupants(int number_occupants)
{
    this->number_occupants = number_occupants;
}
void House::setNumOfCars(int number_of_cars)
{
    this->number_of_cars = number_of_cars;
}
void House::traversedRoadSection(int NUM_OF_HOUSES, int TIME)
{
    // multimap<int, int>::iterator it1;
    // multimap<int, int>::iterator it2;
    int currRoad, currSec;

    for (int i = 0; i < TIME; i++)
    {
        if (i == 0)
        {
            roadVect.insert(roadVect.begin() + i, road);
            sectVect.insert(sectVect.begin() + i, section);
        }
        else
        {
            currRoad = rand() % NUM_OF_HOUSES + 1;
            currSec = rand() % NUM_OF_HOUSES + 1;
            roadVect.insert(roadVect.begin() + i, currRoad);
            sectVect.insert(sectVect.begin() + i, currSec);
        }
    }

    // cout << "\tRoad\tSetion\n";
    // for (int i = 0; i < TIME; i++)
    //{
    //     cout << '\t' << roadVect[i] << '\t' << sectVect[i] << '\n';
    // }

    // for (int i = 0; i <= TIME; i++)
    //{
    //     if (i > 0)
    //     {
    //         currentRoad = (rand() % NUM_OF_HOUSES + 1);
    //         currentSection = (rand() % NUM_OF_HOUSES + 1);
    //
    //        it1 = traversedMap.find(currentRoad);
    //        it2 = traversedMap.find(currentSection);
    //
    //        do
    //        {
    //            if (it1 != traversedMap.end())
    //            {
    //                if (it2 != traversedMap.end())
    //                {
    //                    currentSection = (rand() % NUM_OF_HOUSES + 1);
    //                }
    //
    //            }
    //        } while (it1 == traversedMap.end() || it2 == traversedMap.end());
    //
    //        traversedMap.insert(std::pair<int, int>(currentRoad, currentSection));
    //    }
    //
    //    else
    //    {
    //        traversedMap.insert(std::pair<int, int>(road, section));
    //    }
    //}
    // this->traversedMap = traversedMap;
}

int House::getRoad()
{
    return road;
}
int House::getSection()
{
    return section;
}
int House::getOccupants()
{
    return number_occupants;
}
int House::getNumOfCars()
{
    return number_of_cars;
}

void House::print(int TIME, int houseNum)
{

    // multimap<int, int>::iterator itr;
    cout << "House #" << houseNum + 1 << '\n';
    cout << "(Road, Section): (" << road << ", " << section << ")\n";

    output << "House #" << houseNum + 1 << '\n';
    output << "(Road, Section): (" << road << ", " << section << ")\n";

    // std::cout << "Number of Occupants in House: " << number_occupants << '\n';
    // std::cout << "Number of Cars in house: " << number_of_cars << '\n';
    // cout << "Traversed road Map\n";
    // for (itr = traversedMap.begin(); itr != traversedMap.end(); itr++)
    //{
    //     cout << '\t' << itr->first << '\t' << itr->second
    //          << '\n';
    // }

    cout << "Time\tRoad\tSetion\n";
    output << "Time\tRoad\tSetion\n";

    for (int i = 0; i < TIME; i++)
    {

        cout << i + 1 << ")\t" << roadVect[i] << '\t' << sectVect[i] << '\n';
        output << i + 1 << ")\t\t" << roadVect[i] << "\t\t" << sectVect[i] << '\n';
    }
    cout << "--------------------------------\n";
    output << "--------------------------------\n";
}
