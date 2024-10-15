#include <iostream>  // required for cout
#include <string>   // required for using the string data type
#include <iomanip>  // required for setw()
#include"histogram.h"  // include header file
#include<fstream>     // required for file stream operation like ifstream

using namespace std;  // A standard library which includes the functions needed for the program to run

int main()  {
    Histogram hist;

    // Call the functions defined in the cpp file and declared in the .h file
    hist.readHistFile();        // Call the function to read the Histogram file containing the values
    hist.printHistData();       // Print the data read from the Histogram file
    hist.plotHorizontalHist();  // Using the data from the Histogram file, plot a horizontal histogram
    hist.plotVerticalHist();    // Using the data from the Histogram file, plot a vertical histogram

    hist.clearArray();             // Clear and remove the existing data saved in the memory
    hist.readTextFile();           // Read the text file and find the number of letters of each word, iterating word by word
    hist.plotHorizontalHist_txt(); // Using the data from the text file, plot a horizontal histogram
    hist.plotVerticalHist_txt();   // Using the data from the text file, plot a vertical histogram

    return 0;  // Return the functions indicating that the file has successfully executed and close the program.
}
