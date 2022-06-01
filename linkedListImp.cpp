#include "linkedList.h"

#include<iostream>

using namespace std;





// DEFAULT CONSTRUCTOR
linkedList::linkedList():itemCount(0), sectorHead(nullptr), exposureHead(nullptr), speedHead(nullptr)
{
}

// DESTRUCTOR
linkedList::~linkedList()
{
    clear();     
}



// SIMPLE GET AND BOOL FUNCTIONS
int linkedList::getCurrentSize() const
{
    return itemCount;        
}

bool linkedList::isEmpty() const
{
    return (itemCount == 0);        
}



// ADD DATA TO THE LL
bool linkedList::addDataLinkedList(const int &sector, const int &exposure, const int &speed)
{
    bool sentinel;
    
    //Initializing the dynamic surveyData block to the variables 
    surveyData *newDataPtr = new surveyData(sector, exposure, speed);
    
    // pointers to traverse for sector
    surveyData *prevSector = nullptr;
    surveyData *currSector = sectorHead;
    
    // pointers to traverse for exposure
    surveyData *prevExposure = nullptr;
    surveyData *currExposure = exposureHead;
    
    // pointers to traverse for speed
    surveyData *prevSpeed = nullptr;
    surveyData *currSpeed = speedHead;


    // Iterate forward until X is found.
    while(currSector != nullptr && currSector->getSector() < sector)
    {
        prevSector = currSector;
        currSector = currSector->getNextSector();                
    }
        // Set newData to current
        newDataPtr->setNextPtrSector(currSector);
        
        // just in case NewData was the first link in the chain
        if (prevSector == nullptr)
        {
            sectorHead = newDataPtr;
        }
        else
        {   // otherwise add NewData into, and expand, the chain
            prevSector->setNextPtrSector(newDataPtr);
        }
            sentinel = true;


     // WHILE LOOP TO ADD EXPOSURE TO EXPOSURE HEADERS 
     // Pretty much the exact same chain as above
     while(currExposure != nullptr && currExposure->getExposure() < exposure)
     {
         prevExposure = currExposure;
         currExposure  = currExposure ->getNextExposure();
     }

         newDataPtr->setNextPtrExposure(currExposure);

         if (prevExposure == nullptr)
         {
             exposureHead = newDataPtr;
         }
         else
         {
             prevExposure->setNextPtrExposure(newDataPtr);
         }



     // WHILE LOOP TO ADD SPEED TO THE SPEED HEADER
     // Pretty much the exact same chain as above.
     while(currSpeed != nullptr && currSpeed->getSpeed() < speed)
     {
         prevSpeed = currSpeed;
         currSpeed = currSpeed->getNextSpeed();
     }
    
         newDataPtr->setNextPtrSpeed(currSpeed);

         if (prevSpeed == nullptr)
         {
             speedHead = newDataPtr;
         }
         else
         {
             prevSpeed->setNextPtrSpeed(newDataPtr);
         }

    newDataPtr = nullptr;
    currSector = nullptr;
    prevSector = nullptr;
    currExposure = nullptr;
    prevExposure = nullptr;
    currSpeed = nullptr;
    prevSpeed = nullptr;


    itemCount++;
    return sentinel;   

}



// REMOVE THE SECTOR FROM THE LL
bool linkedList::removeSector(const int &entryToRemove)
{
    bool sentinel = false;

    bool sectorSent = false;
    bool exposureSent = false;
    bool speedSent = false;

    
    // current pointers for sector
    surveyData *prevSector = nullptr;
    surveyData *currSector = sectorHead;
    // exposure
    surveyData *prevExposure = nullptr;
    surveyData *currExposure = exposureHead;
    // speed
    surveyData *prevSpeed = nullptr;
    surveyData *currSpeed = speedHead;

    // FOR SECTOR
    if(currSector->getSector() == entryToRemove)
    {
        currSector = sectorHead;
        sectorHead = sectorHead->getNextSector();
        
        sectorSent = true;        
    }
    else
    {
    // iterates through the LL, trying to find the sector to remove
        while(currSector != nullptr && currSector->getSector() != entryToRemove)
        {
            prevSector = currSector;
            currSector = currSector->getNextSector();
        } 
        
        if(currSector->getSector() == entryToRemove)
        {
            prevSector->setNextPtrSector(currSector->getNextSector());
            sectorSent = true;        
        }  
    }

    // FOR EXPOSURE

// IF YOU'RE READING THIS, THIS WAS IT!! This was the thing I was having so much trouble with. 


    if((currExposure->getSector() == entryToRemove) && (currExposure->getExposure() == currSector->getExposure()) && (currExposure->getSpeed() == currSector->getSpeed()))
    {
        currExposure = exposureHead;
        exposureHead = exposureHead->getNextExposure();

        exposureSent = true;
    }
    else
    {
        // same as above, but it looks to remove the Exposure value based on the sector to remove
        while(currExposure != nullptr && currExposure->getSector() != entryToRemove)
        {
            prevExposure = currExposure;
            currExposure = currExposure->getNextExposure();
        } 
        if((currExposure->getSector() == entryToRemove) && (currExposure->getExposure() == currSector->getExposure()) && (currExposure->getSpeed() == currSector->getSpeed()))
        {
            prevExposure->setNextPtrExposure(currExposure->getNextExposure());
            exposureSent = true;        
        }
    }
    
    // FOR SPEED
    if(currSpeed->getSector() == entryToRemove)

    if((currSpeed->getSector() == entryToRemove) && (currSpeed->getExposure() == currSector->getExposure()) && (currSpeed->getSpeed() == currSector->getSpeed()))
    {
        currSpeed = speedHead;
        speedHead = speedHead->getNextSpeed();

        speedSent = true;
    }
    else
    {
        //Again, same as above, but this time with speed!
        while(currSpeed != nullptr && currSpeed->getSector() != entryToRemove)
        {
            prevSpeed = currSpeed;
            currSpeed = currSpeed->getNextSpeed();
        }   
         
    if((currSpeed->getSector() == entryToRemove) && (currSpeed->getExposure() == currSector->getExposure()) && (currSpeed->getSpeed() == currSector->getSpeed()))
        {
            prevSpeed->setNextPtrSpeed(currSpeed->getNextSpeed());
            speedSent = true;        
        }
    }

  
    // Assuming all the current Ptr's point to the correct locations, they're incremented up,
    // and the 'node' is destroyed. Sentinel is set to true here, otherwise it returns false.
    if(sectorSent && exposureSent && speedSent)
    {
        delete currSector;
     
        currSector = nullptr;
        currExposure = nullptr;
        currSpeed = nullptr;

        sentinel = true;
        itemCount--;
    }

    prevSector = nullptr;
    currSector = nullptr;
    prevExposure = nullptr;
    currExposure = nullptr;
    prevSpeed = nullptr;
    currSpeed = nullptr;


    return sentinel;

}






// WILL SHARE W/ DESTRUCTOR
void linkedList::clear()
{
    surveyData *currSector = sectorHead;
    surveyData *currExposure = exposureHead;
    surveyData *currSpeed = speedHead;
    
    // While the headPtr's are not null, iterate through
    // Head will delete the previous data, and iterate forward.
    while(sectorHead)
  
    {
        currSector = sectorHead;
        sectorHead = sectorHead->getNextSector();
        currSector->setNextPtrSector(nullptr);
    }
    while(exposureHead)
    {
        currExposure = exposureHead;
        exposureHead = exposureHead->getNextExposure();
        currExposure->setNextPtrExposure(nullptr);        
    }

    while(speedHead)
    {
        currSpeed = speedHead;
        speedHead = speedHead->getNextSpeed();
        delete currSpeed;
        currSpeed->setNextPtrSpeed(nullptr);
    }
}



bool linkedList::contains(const int &contains)
{
    bool sentinel = false;    
    surveyData *temp = sectorHead;

    while(temp != nullptr && sentinel == false)
    {
        if (temp->getSector() == contains)
        {
            sentinel = true;
        }
        else
        {
            temp = temp->getNextSector();
        }
    }
    
    temp = nullptr;

    return sentinel;
}
     





// DATA BY SECTOR
void linkedList::printReportDataBySector()
{
    // Assign to sector Head ptr
    surveyData *iterator1 = sectorHead;
    
    // iterate through and print
    while(iterator1 != nullptr)
    {
        cout << "Sector: #" << iterator1->getSector() << " " << iterator1->getExposure()
             << "% exposure, " << iterator1->getSpeed() << " km/hr windspeed\n";
    
        iterator1 = iterator1->getNextSector();
    }

    iterator1 = nullptr;
}




// DATA BY EXPOSURE - SAME AS SECTOR PRINT
void linkedList::printReportDataByExposure()
{
    surveyData *iterator2 = exposureHead;

    // DATA BY EXPOSURE

    while(iterator2 != nullptr)
    {
        cout << "Sector: #" << iterator2->getSector() << " " << iterator2->getExposure() 
            << "% exposure, " << iterator2->getSpeed() << " km/hr windspeed\n";

        iterator2 = iterator2->getNextExposure();
    }    

    iterator2 = nullptr;
}   




// DATA BY SPEED - SAME AS SECTOR PRINT
void linkedList::printReportDataBySpeed()
{
    surveyData *iterator3 = speedHead;

    while(iterator3 != nullptr)
    {
        cout << "Sector: #" << iterator3->getSector() << " " << iterator3->getExposure() 
            << "% exposure, " << iterator3->getSpeed() << " km/hr windspeed\n";

        iterator3 = iterator3->getNextSpeed();
    }

    iterator3 = nullptr;
}




void linkedList::averagesPerSector()
{   // Variable to iterate through sector
    surveyData *histSector = sectorHead;
    int sectorMax = 0;
    int counter = 0;        

    // temp variables for the data in-process
    int tempSector = 0;
    int tempExposure  = 0;
    int tempSpeed = 0;
    int averageCounter = 0;


    // Cycles through to set an index in order to determine total sector size. 
    while(histSector != nullptr)
    {
        if(sectorMax < histSector->getSector())
        {
            sectorMax = histSector->getSector();        
        }
        
        histSector = histSector->getNextSector();
    }
 

    // resets 'index' back to '0'
    histSector = sectorHead;
    
    // loop to output the sector averages.   
    while(counter < sectorMax)
    {
        
        // Loop to cycle through all of the sectors EXCEPT the last
        if(counter + 1  == histSector->getSector() && histSector->getNextSector() != nullptr)
        {
            tempSector = histSector->getSector();
            tempExposure = tempExposure + histSector->getExposure();
            tempSpeed = tempSpeed + histSector->getSpeed();
            averageCounter++;

            histSector = histSector->getNextSector();
        }

        // For all of the sectors without data
        else if(counter + 1 < histSector->getSector() && (tempSector == 0))
        {
            cout << "Sector: #" << counter+1 << "  -- no data --\n";
            counter++;
        }

        // This loop determines where the last node in the list will fall.
        else if(histSector->getNextSector() == nullptr && counter + 1 == histSector->getSector())
        {
            // was it part of an on-going average? If so, it loops here
            if(tempSector != 0)
            {
                tempSector = histSector->getSector();
                tempExposure = tempExposure + histSector->getExposure();
                tempSpeed = tempSpeed + histSector->getSpeed();
                averageCounter++;

                cout << "Sector: #" << tempSector << " " << static_cast<int>(tempExposure/averageCounter);
                cout << "% exposure, " << static_cast<int>(tempSpeed/averageCounter) << " km/hr windspeed\n";
                
                // guard against infinite looping
                counter++;
         
            }
            // otherwise, if it's a new value with NO ongoing average, this outputs it.
            else
            {
                cout << "Sector: #" << histSector->getSector() << " " << histSector->getExposure();
                cout << "% exposure, " << histSector->getSpeed() << " km/hr windspeed\n";
                
                // guard against infinite looping
                counter++;
            }

        }
        // When the averages have been determined, this outputs them.
        else
        {
            cout << "Sector: #" << tempSector << " " << static_cast<int>(tempExposure/averageCounter);
            cout << "% exposure, " << static_cast<int>(tempSpeed/averageCounter) << " km/hr windspeed\n";
            
            tempSector = 0;
            tempExposure = 0;
            tempSpeed = 0;
            averageCounter = 0; 
            counter++;
        }
           
    }

    histSector = nullptr;
}



void linkedList::histogramPrintExposure()
{
    surveyData *histExposure = exposureHead;
    int exposureMax = 0;
    int counter = 0;
    
    // Loop to cycle through ExposureHead in order to get the maximum exposure variable.
    while(histExposure != nullptr)
    {
        if (exposureMax < histExposure->getExposure())
        {
            exposureMax = histExposure->getExposure();
        }

        histExposure = histExposure->getNextExposure();
    }

    // assigns the Ptr to head again    
    histExposure = exposureHead;

    
    // Loops w/ incrementing index to get the number of times each exposure variable is documented
    for(int i = 0; i < exposureMax; i++)
    {

        //cout << histExposure->getExposure() << endl;

        // A while loop to increment ONLY if getExposure == i + 1, AND the next ptr != nullptr
        while(i + 1 == histExposure->getExposure() && histExposure->getNextExposure() != nullptr)
        {
            counter++;
            histExposure = histExposure->getNextExposure();
        }

        // A 'if-condition' that ONLY activates for the last value, to determine equivalence WITHOUT incrementing the ptr
        if(histExposure->getNextExposure() == nullptr && (histExposure->getExposure() == i + 1))
        {
            counter++;
        }
        
        // output
        cout << i + 1 << ", " << counter << endl;
        counter = 0; // counter resets, 
    }
    
    histExposure = nullptr;

}// messy, but works - NOTE: USE THIS IF PRINT-SPEED ACTS WEIRD FOR OTHER FILES




void linkedList::histogramPrintSpeed()
{
    surveyData *histSpeed = speedHead; 
    int speedMax = 0;
    int counter = 0;

    // Loop to cyctle through SpeedHead in order to get the maximum speed variable
    while(histSpeed != nullptr)
    {
        if (speedMax < histSpeed->getSpeed())
        {
            speedMax = histSpeed->getSpeed();
        }

        histSpeed = histSpeed->getNextSpeed();
    }

    // resets histSpeed back to the main pointer head
    histSpeed = speedHead;
    

    for(int i = 0; i < speedMax; i++)
    {
        if(histSpeed->getNextSpeed() == nullptr && (histSpeed->getSpeed() == i + 1))
        {
            counter++;
        }
        while(i + 1 == histSpeed->getSpeed() && histSpeed->getNextSpeed() != nullptr)
        {
            counter++;
            histSpeed = histSpeed->getNextSpeed();
        }

        cout << i + 1 << ", " << counter << endl;
        counter = 0;
    }

    histSpeed = nullptr;
}



// Output of the bad sectors
void linkedList::printBadSectors()
{    
    // "Calling Print Bad Sectors from Linked List\n";    

    surveyData *temp = sectorHead;
    // simple assign to head, and iterate through. 
    while(temp != nullptr)
    {
        cout << temp->getSector() << ", ";        
        temp = temp->getNextSector();
    }
    
    temp = nullptr;
    cout << endl;
}

