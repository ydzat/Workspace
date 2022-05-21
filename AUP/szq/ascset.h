#include <stdlib.h>
typedef struct ascset;
enum as_t;
typedef unsigned char   uint8_t;

enum as_t {
    as_empty, // leere Menge 
    as_numbers, // 0,1,...,8,9 
    as_caps, //A,B,C...,Y,Z
    as_all, //<LEERZEICHEN>,!,",...,a,b,...Y,Z,[,\,...,},~
};

typedef struct ascset{ 
    enum as_t type;
    uint8_t *bitarray;
} ascset_t;

