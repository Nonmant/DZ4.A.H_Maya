//https://contest.yandex.ru/contest/27665/problems/H/

#include "funcs.h"
#include <bits/stdc++.h>

void parseFile(std::istream & input, std::ostream & output){

    std::multiset<char> word;
    std::vector<char> sequence;
    size_t g, s;
    input >> g >> s;

    std::copy_n(std::istream_iterator<char>(input),g,std::inserter(word,word.end()));

    sequence.resize(s);
    input.ignore();
    std::copy_n(std::istream_iterator<char>(input),s,sequence.begin());

    std::multiset<char> curWord(sequence.begin(), sequence.begin()+(g-1));
    unsigned int count = 0;
    for(unsigned int i = 0; i<=s-g; ++i){

        if(word.count(sequence[i+g-1])==0){
            i = i+g;
            if(i > s-g)
                break;
            curWord = std::multiset<char>(sequence.begin() + i, sequence.begin() + (i + g - 1));
            --i;
            continue;
        }

        curWord.insert(sequence[i+g-1]);

        std::vector<char> difference;
        std::set_difference(word.begin(), word.end(),
                            curWord.begin(), curWord.end(),
                            std::back_inserter(difference));

        curWord.erase(curWord.find(sequence[i]));

        if(difference.empty())
            ++count;
        else{
            unsigned int skipSize = difference.size()-1;

            if(skipSize+i >= s-g)
                break;

            for(unsigned int j = 1; j < skipSize; ++j){
                curWord.erase(curWord.find(sequence[i+j]));
                curWord.insert(sequence[i+j+g-1]);
            }
            if(skipSize > 0)
                i+=skipSize-1;
        }
    }
    output << count;
}
