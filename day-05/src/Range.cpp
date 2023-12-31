#include "Range.h"

Range::Range(long dest, long src, long len) : 
        DestinationRangeStart(dest),
        SourceRangeStart(src),
        RangeLength(len) {};

bool Range::contains(long source) const {

    if (source >= SourceRangeStart && 
        source < (SourceRangeStart + RangeLength))
    {
        return true;
    }

    return false;
}

long Range::map(long source) const {

    long tmp = source;
    if (contains(source))
    {
        tmp = DestinationRangeStart + (source - SourceRangeStart);
    }

    return tmp;
}