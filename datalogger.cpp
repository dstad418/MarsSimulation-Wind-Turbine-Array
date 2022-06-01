
// IMPLEMENTATION FILE FOR DATALOGGER

#include<iostream>

#include "datalogger.h"

using namespace std;






void datalogger::addData(const int &sector, const int &exposure, const int &speed)
{   // add data
    list.addDataLinkedList(sector, exposure, speed);        
}


void datalogger::printReport()
{  


    cout << "----------------------------------------------------------------------\n";
    cout << "Data values\n";
    cout << "----------------------------------------------------------------------\n";

    // Broke these 'individual' reports into their own functions. 
    // As requested, reports are generated only through API calls
    // I wasn't sure if you wanted seperation done by individual data 
    // coming back to the calling functions, or if you wanted the LL to handle the 
    // reporting, as it was logic-heavy and not *too* cumbersome. 
  
    cout << "Data by Sector\n";    
    list.printReportDataBySector();

    cout << "Data by Exposure\n";
    list.printReportDataByExposure();

    cout << "Data by Speed\n";
    list.printReportDataBySpeed();




    cout << "----------------------------------------------------------------------\n";
    cout << "Averages per sector\n";
    cout << "----------------------------------------------------------------------\n";

    // datalogger handles the banners, LL handles the output with minor formatting
    list.averagesPerSector();




    cout << "----------------------------------------------------------------------\n";
    cout << "Histogram data for exposure\n";
    cout << "----------------------------------------------------------------------\n";
    // histograms
    list.histogramPrintExposure();

    cout << "----------------------------------------------------------------------\n";
    cout << "Histogram data for speed\n";
    cout << "----------------------------------------------------------------------\n";

    // histo Pt 2.: Electric Boogaloo
    list.histogramPrintSpeed();
}


// prints the sector list for bad sectors
void datalogger::printSectorList()
{
    list.printBadSectors();
}



// minor logic in the datalogger class, I had a feeling this maybe wasn't desired by
// the instructions, but I though *minor* amounts might be okay outside of the API from LL
bool datalogger::containsSector(const int &sector)
{    
    bool tester = list.contains(sector);

    return tester;
}

// remove! 
void datalogger::removeSector(int toBeRemoved)
{
    list.removeSector(toBeRemoved);       
}

