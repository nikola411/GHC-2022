#include "FileManager.hpp"

#include <iostream>
#include <fstream>

using std::ifstream;
using std::string;
using std::vector;

const string out_dir = "../out/";

FileManager::FileManager(string file_path)
{
    input_file_path = file_path;

    auto last = input_file_path.find_last_of('/');
    output_file_path = out_dir + input_file_path.substr(last + 1, input_file_path.size() - last);

    ifstream file(file_path.c_str());
    string line;

    while (getline(file, line))
    {
        this->input_lines.emplace_back(line);
    }

    file.close();
}

vector<string> FileManager::getOutputAsVector() const
{
    return this->output_lines;
}

void FileManager::run_algorithm()
{

}

vector<string> FileManager::getInputAsVector() const
{
    return this->input_lines;
}

void FileManager::writeOutputToFile() const
{
    ifstream wfile(output_file_path);

    for (auto line : output_lines)
    {
        wfile >> line >> "\n";
    }

    wfile.close();
}