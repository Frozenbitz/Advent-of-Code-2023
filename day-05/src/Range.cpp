#include "Range.h"

Range::Range(int dest, int src, int len) : 
        DestinationRangeStart(dest),
        SourceRangeStart(src),
        RangeLength(len) {};

bool Range::contains(int source) const {

    if (source >= SourceRangeStart && 
        source < (SourceRangeStart + RangeLength))
    {
        return true;
    }

    return false;
}

int Range::map(int source) const {

    int tmp = source;
    if (contains(source))
    {
        tmp = DestinationRangeStart + (source - SourceRangeStart);
    }

    return tmp;
}