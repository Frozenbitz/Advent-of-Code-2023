#ifndef RANGE_H
#define RANGE_H

class Range
{
public:
    long DestinationRangeStart;
    long SourceRangeStart;
    long RangeLength;

    Range() = delete;
    Range(const Range& range) = default; // needed for vector instantiation
    Range(Range&& range) = default;
    Range& operator=(const Range& range) = default;
    Range(long dest, long src, long len);

    bool contains(long source) const;
    long map(long source) const;
};

#endif // RANGE_H

