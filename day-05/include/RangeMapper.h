#ifndef RANGE_MAPPER_H
#define RANGE_MAPPER_H

#include "Range.h"

#include <vector>
#include <string>

class RangeMapper
{
private:
    std::vector<Range> localRanges;

public:
    RangeMapper(const std::vector<std::string>& source); 
    RangeMapper() = default;
    RangeMapper(const RangeMapper& range) = default;
    RangeMapper& operator=(const RangeMapper& range) = default;     
    ~RangeMapper() = default; 


    // Add your class methods and member variables here
    int convert(int value) const;
    Range split2Range(const std::string& s, char delimiter);
};

#endif // RANGE_MAPPER_H