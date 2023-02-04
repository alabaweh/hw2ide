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
std::set<std::string> parseStringToWords(string rawWords)
{


    set<string> parse;
    string nam;

    stringstream ss(rawWords);

    while (!ss.fail()) {
        ss >> nam;

        int num_bef = 0;
        int num_aft = 0;
        string word_bef = "";
        string word_af="";

        for (int k = 0; k < nam.size(); k++) {
            if (!ispunct(nam[k])) {
                num_bef++;
                word_bef+=nam[k];
            } else {
                break;
            }
        }

        for (int k = num_bef+1;  k<nam.size(); k++) {
            if (!ispunct(nam[k])) {
                num_aft++;
                word_af+=nam[k];
            } else {
                break;
            }
        }

        if(num_aft >1 && num_bef >1){
            nam= word_bef+word_af;
        }
        else if(num_bef>1){
            nam=word_bef;
        }
        else if  (num_aft>1){
            nam=word_af;
        }
        else
            nam="";


        parse.insert(nam);
    }

    return parse;


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
