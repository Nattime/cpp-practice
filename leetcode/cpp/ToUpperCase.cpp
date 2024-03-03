// Authored by Jie Huang
// 1/20/24
// Print out in capital

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char** argv){
    string ret{};

    for(int i = 0; argv[1][i] != '\0'; i++){
        ret += (toupper(argv[1][i]));
    }

    cout << ret << endl;

    return 0;
}