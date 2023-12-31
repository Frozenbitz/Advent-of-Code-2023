#ifndef SEEDRANGE_H
#define SEEDRANGE_H

class SeedRange {
public:
    long rangeStart;
    long rangeLength;
    long rangeEnd;

public:
    // Constructor
    SeedRange(long start, long length) : rangeStart(start), rangeLength(length), rangeEnd(start+length) {}
};

#endif // SEEDRANGE_H
