#include <string>
#include <iostream>

#include "FileManager.hpp"

using std::string;
using std::cout;

int main(int argc, string argv[])
{
    string input_path = "../in/";

    switch (argc)
    {
        case 0:
        case 1:
            cout << "Wrong number of arguments";
            return -1;
        case 2:
            #ifdef filesystem
            if (argv[1] == "-a")
            {
                for (const auto & file_path: directory_iterator(input_path))
                {
                    FileManager file(file_path.path().generic_string());
                    file.run_algorithm();
                }
            }
            else
            {
                cout << "Wrong argument";
            }
            #endif
        default:
            for (int i = 1; i < argc; i++)
            {
                auto file_path = input_path + argv[i];
                FileManager file((string)file_path);
                file.run_algorithm();
            }
    }
    
    return 0;
}