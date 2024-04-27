#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <windows.h> // For system("pause")
using namespace std;

int main()
{
    vector<string> msg{"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    int i=0;
    for (const string &word : msg)
    {
        ++i;
        cout << word  << " ";
    }
    cout << endl;
    cout << "中文会乱码吗?"<<endl;
    
}