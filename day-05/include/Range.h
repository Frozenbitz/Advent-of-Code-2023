#ifndef RANGE_H
#define RANGE_H

class Range
{
public:
    int DestinationRangeStart;
    int SourceRangeStart;
    int RangeLength;

    Range() = delete;
    Range(const Range& range) = default; // needed for vector instantiation
    Range(Range&& range) = default;
    Range& operator=(const Range& range) = default;
    Range(int dest, int src, int len);

    bool contains(int source) const;
    int map(int source) const;
};

#endif // RANGE_H

