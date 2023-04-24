#pragma

class House
{
private:
    int road;
    int section;
    int number_occupants;
    int number_of_cars;
    std::multimap<int, int> traversedMap;
    std::vector<int> roadVect;
    std::vector<int> sectVect;

public:
    //(this->) get the CLASS private variable
    House();
    House(int road, int section, int number_occupants,
          int number_of_cars, std::multimap<int, int> traversedMap,
          std::vector<int> roadVect, std::vector<int> sectVect);

    void validate();
    void setRoad(int road);
    void setSection(int section);
    void setOccupants(int number_occupants);
    void setNumOfCars(int number_of_cars);
    void traversedRoadSection(int NUM_OF_HOUSES, int TIME);

    int getRoad();
    int getSection();
    int getOccupants();
    int getNumOfCars();

    void print(int, int);
};
