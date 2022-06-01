
#include "surveyData.h"

using namespace std;



// DEFAULT CONSTRUCTOR
surveyData::surveyData() 
    : sectorNumber(0), exposureData(0), speedData(0), sectorNext(nullptr), exposureNext(nullptr), speedNext(nullptr)
{
} // I'm new to member initializer lists, hope I did it correctly! 

// CONSTRUCTOR W/ INT INITIALIZERS
surveyData::surveyData(const int &sector, const int &exposure, const int &speed)
{
    sectorNumber = sector;
    exposureData = exposure;
    speedData = speed;        
}



//    DESTRUCTOR
surveyData::~surveyData() 
{
     sectorNext = nullptr;
     exposureNext = nullptr;
     speedNext = nullptr; 
}


// I think these two functions were largely redundant, but I left them in.
// SETTERS FOR ALL THE DATA
void surveyData::setData(const int &sector, const int &exposure, const int &speed)
{
    sectorNumber = sector;
    exposureData = exposure;
    speedData = speed;        
}
// SETTERS FOR INDIVIDUAL INT PARAMETERS
void surveyData::setSpeed(const int &speed)
{
    speedData = speed;        
}

void surveyData::setExposure (const int &exposure)
{
    exposureData = exposure;        
}

void surveyData::setSector(const int &sector)
{
    sectorNumber = sector;        
}




// GETTERS FOR DATA OBJECTS
int surveyData::getSpeed() const
{
    return speedData;        
}

int surveyData::getExposure() const
{
    return exposureData;        
}

int surveyData::getSector() const
{
    return sectorNumber;        
}




// SETS THE NEXT POINTER TO POINT TO A SPECIFIC LOCATION
void surveyData::setNextPtrSpeed(surveyData *nextPtr)
{
    speedNext = nextPtr;
}

void surveyData::setNextPtrExposure(surveyData *nextPtr)
{
    exposureNext = nextPtr;
}

void surveyData::setNextPtrSector(surveyData *nextPtr)
{
    sectorNext = nextPtr;
}




// GETTERS TO ITERATE THROUGH THE LINKED LIST
surveyData* surveyData::getNextSector() const
{
    return sectorNext;        
}

surveyData* surveyData::getNextExposure() const
{
    return exposureNext;
}

surveyData* surveyData::getNextSpeed() const
{
    return speedNext;
}



