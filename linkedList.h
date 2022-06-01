#ifndef _LINKEDLIST
#define _LINKEDLIST

// INCLUDING SURVEY DATA
#include "surveyData.h"


class linkedList
{
    private:

        // ITEM COUNT FOR THE LINKED LIST
        int itemCount;

        // HEAD POINTERS
        surveyData *sectorHead; 
        surveyData *exposureHead;
        surveyData *speedHead;


    public:

        //  CONSTRUCTORS
        linkedList();
        //COPY CONSTRUCTOR -- DELETED
        linkedList(const linkedList &other) = delete;
        // DESTRUCTOR   
        virtual ~linkedList();
        // OPERATOR OVERLOAD -- DELETED
        linkedList& operator=(const linkedList& otherList) = delete;
        

        // Easy returns used for testing/sentinels
        int getCurrentSize() const;
        bool isEmpty() const;


        bool addDataLinkedList(const int &sector, const int &exposure, const int &speed);
        bool removeSector(const int &entryToRemove);


        void clear();
        bool contains(const int &contains);    


        // FUNCTIONS ASSOCIATED WITH PRINT!!!
        // All of the print requirements broken up into several functions, some more logic-heavy
        // than the others, but each with minor formatting for output.
        void printReportDataBySector();
        void printReportDataByExposure();
        void printReportDataBySpeed();
        void averagesPerSector();
        void histogramPrintExposure();
        void histogramPrintSpeed();
        void printBadSectors();

};


#endif
