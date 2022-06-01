
output: process.o datalogger.o linkedListImp.o surveyDataImp.o
	g++ process.o datalogger.o linkedListImp.o surveyDataImp.o -o output

process.o: process.cpp
	g++ -c process.cpp

datalogger.o: datalogger.cpp datalogger.h
	g++ -c datalogger.cpp

linkedListImp.o: linkedListImp.cpp linkedList.h
	g++ -c linkedListImp.cpp

surveyDataImp.o: surveyDataImp.cpp surveyData.h
	g++ -c surveyDataImp.cpp

clean: 
	rm *.o output
