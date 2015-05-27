#include <iostream>
#include "StringUtility.h"

using namespace std;

int main() {

    StringUtility utility;

    std::string derp = "aaacceefacer";


    cout << utility.basicCompression(&derp) << "\n";
    cout << utility.reverse(&derp) << "\n";

    return 0;
}