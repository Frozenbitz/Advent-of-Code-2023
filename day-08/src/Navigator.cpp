#include "Navigator.h"

Navigator::Navigator(std::string file) {
    std::vector<std::string> lines = readLinesFromFile(file);

    // get the movement instructions into a vector
    for (auto && instruction : lines[0])
    {
        directionInstructions.push_back({instruction});
    }

    // delete the first 2 lines, so only the nodes are left
    lines.erase(lines.begin());
    lines.erase(lines.begin());

    for (auto &&line : lines)
    {
        Node data = splitString(line);
        nodes.insert({data.getName(), data});
    }

    for (auto &&node : nodes)
    {
        if (node.first[2] == 'A')
            start.push_back(node.first);
    }
}

std::vector<std::string> Navigator::readLinesFromFile (const std::string& filename)
{
    std::ifstream inputStream{filename, std::ifstream::in};

    if (not inputStream.is_open())
        throw std::invalid_argument("wrong file name/path, could not open!");

    std::string line;
    std::vector<std::string> inputStream_lines; // build a vector of lines
    while (std::getline(inputStream, line))
    {
        // Process each line of the file and create the mapping
        inputStream_lines.push_back(line);

        if (inputStream.eof())
            break; // stop
    }

    if (inputStream.bad())
    { 
        std::cout << "failed to read stream, try again!" << std::endl;
        throw std::ios_base::failure("error occurred during file reading!");
    }

    inputStream.close(); // done reading the file

    return inputStream_lines;
}

Node Navigator::splitString(const std::string& line) {
    std::string pattern = R"((...)\s=\s\((...),\s(...)\))";
    std::regex token_pattern(pattern, std::regex_constants::ECMAScript);
    auto words_begin = std::sregex_iterator(line.begin(), line.end(), token_pattern);
    auto words_end = std::sregex_iterator(); //The default-constructed std::regex_iterator is the end-of-sequence iterator.

    long rangeStart = 0; 
    std::vector<std::string> data;
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) { // increment calls r_search
        std::smatch match = *i;
        data.push_back(match[1]);
        data.push_back(match[2]);
        data.push_back(match[3]);
    }

    return Node{data[0], data[1], data[2]};
}


int Navigator::traverseFromTo(std::string from, std::string to) const {

    // start at: 
    std::string nextElement = nodes.at(from).getName();
    int stepsTaken = 0;

    if (not nodes.contains(to))
        throw std::invalid_argument("invalid destination!");
    

    auto iterator = directionInstructions.begin();

    while (iterator != directionInstructions.end())
    {
        if (nextElement.compare(to) == 0)
        {
            return stepsTaken;
        }

        if (iterator->compare("L") == 0)
        {
            nextElement = nodes.at(nextElement).traverseLeft();
        }
        else if (iterator->compare("R") == 0)
        {
            nextElement = nodes.at(nextElement).traverseRight();
        }
        else
        {
            throw std::invalid_argument("invalid direction instruction!");
        }

        iterator++;
        stepsTaken++;

        // restart if we are not finished
        if (iterator == directionInstructions.end())
        {
            iterator = directionInstructions.begin();
        }
    }
    
    return 0;
}

int Navigator::ghostlyTraverse() const {

    // start at: 
    std::vector<std::string> nextElement = start;
    int stepsTaken = 0;
    auto iterator = directionInstructions.begin();

    while (iterator != directionInstructions.end())
    {
        if (atEnd(nextElement))
        {
            return stepsTaken;
        }

        if (iterator->compare("L") == 0)
        {
            for (auto &&element : nextElement)
            {
                element = nodes.at(element).traverseLeft();
            }
        }
        else if (iterator->compare("R") == 0)
        {
            for (auto &&element : nextElement)
            {
                element = nodes.at(element).traverseRight();
            }
        }
        else
        {
            throw std::invalid_argument("invalid direction instruction!");
        }

        iterator++;
        stepsTaken++;

        // restart if we are not finished
        if (iterator == directionInstructions.end())
        {
            iterator = directionInstructions.begin();
        }
    }
    
    return 0;
}

bool Navigator::atEnd(std::vector<std::string> const & currentSteps) const {
    
    for (auto &&step : currentSteps)
    {
        if (step[2] != 'Z')
        {
            return false;
        }
    }

    return true;
}