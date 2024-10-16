#include <fstream>
#include <iostream>
#include <string>
#include "histogram.h"

using namespace std;

void Histogram::readHistFile() {  // Read the data in the histogram file
    ifstream file("inputFile.hist");  // Open the file inputFileHist for reading

    // Check if the file was successfully opened
    if (file.is_open()) {
        cout <<"File is opened\n" << endl;  // f is properly open.

        while (file>>b>>f) {          // Read the file line by line, the first word to be read is named b and the following line is named f
            bin[N]=b;                 // Iterate bin through N number of values
            cout << fixed << setprecision(1) << bin[N] << "  ";  // Print the data with a precision of 1
            freq[N]=f;                // Iterate freq through N number of values
            cout << freq[N] << endl;  // Print the data
            N++;                      // Continue printing for N number of times
        }
    } else {
        cout <<"Failed to open" << endl;  // f failed to open
    }
    // Close the file stream when done
    file.close();
}

// Print the data read from the readHistFile
void Histogram::printHistData() {
    ifstream file("inputFileHist.txt");  // Open the file inputFile.hist for reading

    // Read line by line using getline()
    string line;  // Define line to be a string
    cout << "\nList of Contents"  <<endl;
    while (getline(file, line)) {  // Read the entire line into 'line'
        cout << line << endl;  // Print the entire line
    }

    // Close the file stream when done
    file.close();
}

// Plot a horizontal histogram using the data taken from the readHistFile function
void Histogram::plotHorizontalHist() {
    cout << "\n--------Plot Horizontal Histogram-------\n";
    for (int i=0; i<N; i++) {  // Iterate through the data N number of times
        cout << fixed << setprecision(1) << bin[i] << "/" << freq[i] << " ";
        for (int j=0; j<(int)freq[i]; j++) {  // Iterate through the data for the number of freq
            cout << "*";  // Print an asterisk for each number taken from the frequency
        }
        cout << endl;
    }
}

// Plot a vertical histogram using the data taken from the readHistFile function
void Histogram::plotVerticalHist() {
    cout << "\n--------Plot Vertical Histogram---------\n";
    int maxFreq=0;  // Initialize the maxFreq to be 0
    for (int i=0; i<N; i++) {  // Iterate through the data N number of times
        if (freq[i]>maxFreq) { // Find the maximum frequency by checking line by line
            maxFreq=freq[i];   // Once the maximum frequency is found, save the value into the maxFreq
        }
    }

    for (int k=0; k<maxFreq; k++) {  // Continue iterating through the data as long as it is lesser than maxFreq
        for (int j=0; j<N; j++) {    // Iterate the data N number of times
            if (freq[j]>=maxFreq) {  // Check for each frequency if the value is greater than or equal to maxFreq
                cout << "* ";        // If the value is greater than or equal to maxFreq print an asterisk
            } else {
                cout << "  ";        // Else print a blank
            }
        }
        maxFreq=maxFreq-1;
        cout << endl;
    }

    for (int i=0; i<N ; i++) {
        cout << (int)bin[i] << " ";
    }
}

// Function to clear the existing data
void Histogram::clearArray() {
    for (int i=0; i<100; i++) { // Iterate 100 times
        bin[i]=0;               // Reset the value of bin
        freq[i]=0;              // Reset the value of freq
    }
}

// Read the data in the histogram file
void Histogram::readTextFile() {
    ifstream file("inputFile.txt");  // Open the file inputFileHist for reading

    // Check if the file was successfully opened
    if (file.is_open()) {
        cout <<"\nFile is opened\n" << endl;  // f is properly open.

        string word;   // Define word to be a string

        while (file>>word) {   // Loop to read words from the file one by one
            int length=word.length();   // Get the length of the current word


            for (int i=0; i<length; i++) {   // Loop through each character of the word to check if it's a letter

                // Check if the character is an uppercase (A-Z) or lowercase (a-z) letter
                if ((word[i]>=65 && word[i]<=90) || (word[i]>=97 && word[i]<=122)) {
                    length2=length2+1;   // Increment length2 for each valid letter found
                }
            }

            // Update maxWordLength if the current word length (length2) is the largest found
            if (length2>maxWordLength) {
                maxWordLength=length2;

            }

            bin[length2]=length2;    // Mark the bin for the word length (ensures the length is recognized)
            freq[length2]+=1;        // Increment the frequency count for this word length
            length2=0;               // Reset length2 for the next word
        }

    } else {
        cout <<"Failed to open" << endl;  // f failed to open
    }
    // Close the file stream when done
    file.close();
}

// Function to plot a horizontal histogram
void Histogram::plotHorizontalHist_txt() {
    cout << "\n--------Plot Horizontal Histogram-------\n";   // Prints the title of the horizontal histogram

    for (int i=1; i<=maxWordLength; i++) {     // Loops through each word length up to the maximum word length
        if (freq[i]!=0) {    // Checks if the frequency of the current word length is not zero
            cout << fixed << setprecision(1) << bin[i] << "/" << freq[i] << " ";  // Prints the bin value and its corresponding frequency with one decimal precision
            for (int j=0; j<(int)freq[i]; j++) {   // Loops to print '*' for the frequency of the current word length
                cout << "*";  //Prints an asterisk for each count in the frequency
            }
            cout << endl;   // Moves to the next line after printing the frequency for the current word length
        }
    }
}

// Function to plot a vertical histogram
void Histogram::plotVerticalHist_txt() {
    cout << "\n--------Plot Vertical Histogram---------\n"; // Prints the title of the vertical histogram

    int maxFreq=0;  // Initializes maxFreq to store the maximum frequency
    for (int i=0; i<maxWordLength; i++) {   // Loops through each word length to find the maximum frequency
        if (freq[i]>maxFreq) {   // Updates maxFreq if a higher frequency is found
            maxFreq=freq[i];   // Stores the highest frequency
        }
    }

    for (int k=maxFreq; k>0; k--) {  // Loops from the maximum frequency down to 1, printing each level of the vertical histogram
        for (int j=0; j<=maxWordLength; j++) {  // Loops through each word length to print the corresponding '*' or space
            if (bin[j]!=0) {   // Checks if the bin is not zero (only consider non-empty bins)
                if (freq[j]>=maxFreq) {  // Prints an asterisk if the frequency is greater than or equal to the current maxFreq
                    cout << "* ";
                } else {
                    cout << "  ";   // Prints spaces if the frequency is less than the current maxFreq
                }
            }
        }
        maxFreq=maxFreq-1;  // Decrements maxFreq to move to the next level of the vertical histogram
        cout << endl;   // Moves to the next line to print the next level of the histogram
    }

    for (int i=0; i<maxWordLength ; i++) {
        cout << (int)bin[i] << " ";
    }
}
