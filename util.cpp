#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords) {
    //set to return
    std::set<std::string> toReturn;
    //add a space at the end of the last word so that it can be added to the set
    rawWords = rawWords + " ";
    //counter variable
    int i = 0;
    while(true){
        //return the set if the length is 0
        if(rawWords.length() == 0){
            return toReturn;
        }
        //check if the character is not alphanumeric
        else if(!iswalnum(rawWords.at(i))){
            //check if the string before the character has a length of 2 or greater
            if(rawWords.substr(0, i).length() >= 2) {
                //insert the substring into the list
                toReturn.insert(rawWords.substr(0, i));
            }
            //cut off the substring regardless of its length
            rawWords = rawWords.substr(i + 1, rawWords.length() - i);
            //reset counter variable
            i = 0;
        }
        else {
            //increment counter variable
            i++;
        }
    }
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
