/*
*Name: Kevin Du
*ID: kd5eyn
*Date: 10/13/2021
*Filename: wordPuzzle.cpp
*/
#include <iostream>
#include <fstream>
//#include <unordered_set>
#include "hashTable.h" 
#include "timer.h"

using namespace std;

// We create a 2-D array of some big size, and assume that the grid
// read in will be less than this size (a valid assumption for lab 6)
#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

/** This function will read in a grid file, as per the format in the
 * CS 2150 lab 6 document, into a global grid[][] array.  It uses C++
 * file streams, and thus requires the the <fstream> #include header.
 *
 * @return true or false, depending on whether the file was
 *         successfully opened.
 * @param filename The file name to read in -- it's assumed to be in
 *                 the file format described in the lab document.
 * @param rows The number of rows as specified in the input file;
 *             as this is a reference, it is set by the function.
 * @param cols The number of columns as specified in the input file;
 *             as this is a reference, it is set by the function.
 */
bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;

    // then the columns
    file >> cols;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
        }
    }
    return true;
}

/** This function will retrieve a word in a grid of letters in a given
 * direction.  If the end of the grid is encountered before the length
 * of the desired string is reached, then a shorter string will be
 * returned.  The data is retrieved from a global char grid[][]
 * array, which is assumed to be defined (and in scope).  NOTE: The
 * return value is a static string variable (for efficiency
 * reasons), so a successive return value will overwrite a previous
 * return value.
 *
 * @return A STATIC string containing the letters in the provided direction.
 * @param startRow The starting (row,col) position to find the word.
 * @param startCol The starting (row,col) position to find the word.
 * @param dir The direction to move: 0 is north (upwards), 1 is
 *            northeast, and it rotates around clockwise until it
 *            reaches 7 for northwest.
 * @param len The desired length of the string to return (assuming
 *            the edge of the grid is not reached--if the edge of the
 *            grid is reached, it will return as many characters as
 *            possible up to the edge of the grid, so the returned
 *            string may not have the same length as this parameter
 *            indicates).
 * @param numRows The number of rows in the global char grid[][]
 *                array.
 * @param numCols The number of columns in the global char grid[][]
 *                array.
 */
string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}

string getDirectStr(int direction);

void findWords(hashTable& dict, int rowLength, int colLength){

   
   int numWords = 0;
   
   //NOTE: 4 four loops, might be place to optimize
   //Iterate through the entire grid, checking each character
   for(int row = 0; row < rowLength; row++){
      for(int col = 0; col < colLength; col++){
         string phrase = "";
         for(int i = 0; i < 8; i++){
            //If this works, don't change the location of lastWordMatched.
            string lastWordMatched = ""; 
            for(int j = 3; j <= 22; j++){
               phrase = getWordInGrid(row, col, i, j, rowLength, colLength);
               //If the word length is within parameters
               if(phrase == lastWordMatched){
                  break;
               }
			   //phrase.length() >= 3 && (phrase.length() <= 22 && dict.find(phrase) != -1)
               else if(dict.find(phrase) != -1){
                  lastWordMatched = phrase;
                  cout << getDirectStr(i) << " (" << row << ", " << col  << "): "<<  phrase << endl;
                  numWords++;
               }
            }
         }
      }
   }
   cout << numWords << " words found" << endl;
}

string getDirectStr(int direction){
   switch (direction) {
      case 0:
         return "N";
      case 1:
         return "NE";
      case 2:
         return "E";
      case 3:
         return  "SE";
      case 4:
         return "S";
      case 5:
         return "SW";
      case 6:
         return "W";
      case 7:
         return "NW";
    }
    return "";
}

int getNumLines(string dictPath){
   int lines = 0;
   string line = "";  
   ifstream file(dictPath);
   while(getline(file, line)){	
	lines++;		
   } 
   file.close();
   return lines;
}

hashTable createDict(string dictPath){
	//ifstream is for reading the file only
	ifstream file(dictPath);
	string line = "";
	int dictInfo = getNumLines(dictPath);
	hashTable wordDict(dictInfo, 0.75);
   
	//gets every line of the file
	while(getline(file, line)){
		wordDict.insert(line);
	}

	//closes the file
	file.close();
	return wordDict;
}



int main(int argc, char* argv[]){
	//in terminal: ./a.out <dictionary> <grid>
   if(argc != 3){
      cout << "Incorrect number of arguments" << endl;
      return 0;
   }
   string dictPath = argv[1];
   timer watch;
   
   //Creates the dictionary
	hashTable dict = createDict(dictPath);
   
   //These will be changed by the readInGrid()
   int rows = 0;
   int cols = 0;
   watch.start();
   readInGrid(argv[2], rows, cols);
   findWords(dict, rows, cols);
   watch.stop();
   cout << watch.getTime() << endl;
	return 0;
}
