//https://contest.yandex.ru/contest/27665/problems/H/

#include "funcs.h"
#include <bits/stdc++.h>

void parseFile(std::istream & input, std::ostream & output){

    std::unordered_multiset<char> word;
    std::vector<char> sequence;
    size_t g, s;
    input >> g >> s;

    std::copy_n(std::istream_iterator<char>(input),g,std::inserter(word,word.end()));

    sequence.resize(s);
    input.ignore();
    std::copy_n(std::istream_iterator<char>(input),s,sequence.begin());

    std::unordered_multiset<char> curWord(sequence.begin(), sequence.begin()+(g-1));
    unsigned int count = 0;
    for(int i = 0; i<=s-g; ++i){
        curWord.insert(sequence[i+g-1]);
        if(curWord == word)
            count+=1;

        curWord.erase(curWord.find(sequence[i]));
    }
    output << count;
}
