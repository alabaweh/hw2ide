#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

std::set<std::string> extract_keywords(const std::string& rawWords) {
    std::set<std::string> words;
    std::istringstream iss(rawWords);
    std::string word;

    while (iss >> word)
    {
        // loop through each character of the word
        for (int i = 0; i < word.length(); i++)
        {
            if (!isalnum(word[i]))
            {
                // split the word at the punctuation
                word[i] = ' ';
            }
        }

        std::istringstream subIss(word);
        std::string subWord;

        // split the word into subwords
        while (subIss >> subWord)
        {
            // only add the subword to the set if it's 2 or more characters
            if (subWord.length() >= 2)
            {
                words.insert(subWord);
            }
        }
    }

    return words;
}

int main() {

    set<std::string> set1 = { "date", "orange", "fig"};
    set<std::string> set2 = { "pear", "fig", "grape"};

    std::set<std::string> Item_union =set2;


    for (const std::string &item1 : set1)
    {


            Item_union.insert(item1);
        }



    for (auto it = Item_union.begin(); it != Item_union.end(); it++) {
        cout << *it << " ";
    }

    return 0;
}
