#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Fk", "U", "Chat", "From", "VS Code", "and", "W", "W", "W", "W", "W", "W", "W"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}