
#ifndef _SURVEYDATA
#define _SURVEYDATA


// ENCAPUSLATED CLASS FOR THE DATA OBJECTS
//
class surveyData
{
    private:        
        // !@#$ --  kicking myself here, I didn't see the private node variable you had made for the Ch 9 lecture/video
        // until I was too deep into these individual variables 
        int sectorNumber;
        int exposureData;
        int speedData;


        // POINTERS TO THE NEXT NODES
        surveyData *sectorNext;
        surveyData *exposureNext; 
        surveyData *speedNext;


    public:
        // constructors
        surveyData();
        surveyData(const int &sector, const int &exposure, const int &speed);
        // copy constructor -- DELETED
        surveyData(const surveyData &other) = delete;
        // Overloading the assignment operator -- DELETED
        surveyData& operator=(const surveyData& otherData) = delete;
        // destructors
        ~surveyData();


        // GETTERS
        int getSpeed() const;
        int getExposure() const;
        int getSector() const;


        // SETTERS FOR ALL DATA
        void setData(const int &sector, const int &exposure, const int &speed);
        // SETTERS FOR THE INDIVIDUAL INT PARAMETERS
        void setSpeed(const int &speed);
        void setExposure (const int &exposure);
        void setSector (const int &sector);


        // SETS THE NEXT POINTER TO POINT TO A SPECIFIC LOCATION 
        void setNextPtrSpeed(surveyData *nextPtr);
        void setNextPtrExposure(surveyData *nextPtr);
        void setNextPtrSector(surveyData *nextPtr);


        // Operators to move the points along through linked-chains
        // returns a pointer to the next variable.
        surveyData* getNextSector() const;
        surveyData* getNextExposure()const;
        surveyData* getNextSpeed()const;
};


#endif
