#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <vector>
#include <string>

class FileManager
{
public:
    FileManager(std::string file_path);
    std::vector<std::string> getInputAsVector() const;
    std::vector<std::string> getOutputAsVector() const;

    void run_algorithm();

    void prepareOutput(std::vector<string> to_write);
    void writeOutputToFile() const;

private:
    std::vector<std::string> input_lines;
    std::string input_file_path;

    std::vector<std::string> output_lines;
    std::string output_file_path;
};

#endif