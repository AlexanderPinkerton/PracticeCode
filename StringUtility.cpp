//
// Created by Alexander Pinkerton on 5/25/15.
//

#include <sstream>
#include "StringUtility.h"

bool StringUtility::isPermutation(std::string* first, std::string* second) {

    //If the strings are not the same length, they cannot be a permutation.
    if(first->length() != second->length()){return false;}

    //Sort both strings before comparing
    std::sort(first->begin(), first->end());
    std::sort(second->begin(), second->end());

    return first == second;
}

std::string StringUtility::basicCompression(std::string* input) {

    std::stringstream compressed;

    //At each character in the string, add to a count for each adjacent duplicate.
    for(auto currentIndex = 0; currentIndex <input->length()-1;){
        //Reset the character counter
        auto letterCount = 1;
        //Increment the count for each of the same adjacent characters
        while(input->at(currentIndex) == input->at(currentIndex + letterCount)){
            letterCount++;
        }
        //Add the compressed character info into a stream and return it.
        compressed << input->at(currentIndex) << letterCount;
        //Offset the current character by the amount of the same adjacent ones.
        currentIndex +=letterCount;
    }

    //Return the shortest string.
    if(compressed.str().length() >= input->length()){
        return *input;
    }else{
        return compressed.str();
    }
}

std::string StringUtility::reverse(std::string* input) {

    std::stringstream reversed;

    auto backwardIndex = input->length()-1;
    auto forwardIndex = 0;

    for(;forwardIndex < input->length(); forwardIndex++, backwardIndex--){
        reversed << input->at(backwardIndex);
    }

    return reversed.str();
}
