#ifndef _DATALOGGER
#define _DATALOGGER


#include "linkedList.h"



class datalogger
{
    private:
        linkedList list;
        
    
    
    public:        
        void addData(const int &sector ,const int &exposure, const int &speed);
        void printReport();
        void printSectorList();
        bool containsSector(const int &sector);
        void removeSector(int toBeRemoved);
        
};


#endif
