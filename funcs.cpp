//https://contest.yandex.ru/contest/27665/problems/H/

#include "funcs.h"
#include <bits/stdc++.h>

void parseFile(std::istream & input, std::ostream & output){

    std::map<char, unsigned long int> word, curWord;

    for(char c = 'a'; c<='z'; ++c){
        word[c] = 0;
        curWord[c] = 0;
    }
    for(char c = 'A'; c<='Z'; ++c){
        word[c] = 0;
        curWord[c] = 0;
    }
    const long unsigned int goalCollisions = word.size();


    std::vector<char> sequence;
    size_t g, s;
    input >> g >> s;

    char c;
    for(int i = 0; i<g; ++i){
        input >> c;
        ++word[c];
    }

    sequence.resize(s);
    input.ignore();
    std::copy_n(std::istream_iterator<char>(input),s,sequence.begin());

    for(int i = 0; i<g; ++i){
        ++curWord[sequence[i]];
    }

    long unsigned int collisions = 0;
    for(const auto & ch : word){
        if(curWord[ch.first] == ch.second)
            ++collisions;
    }

    long unsigned int count = 0;
    if(collisions == goalCollisions)
        ++count;

    char add, remove;
    for(unsigned long i = 0; i<s-g; ++i){
        remove = sequence[i];
        add = sequence[i+g];

        if(curWord[remove] == word[remove])
            --collisions;
        else if(curWord[remove] == word[remove]+1)
            ++collisions;

        --curWord[remove];

        if(curWord[add] == word[add])
            --collisions;
        else if(curWord[add]+1 == word[add])
            ++collisions;

        ++curWord[add];

        if(collisions == goalCollisions)
            ++count;
    }

    output << count;
}
