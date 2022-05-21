#pragma once 
#include <string>
using namespace std;

class Shape{

    protected:
	    static int uiNumberoflnstances;

    public:
	    Shape();
	    ~Shape();
	    virtual string Draw()=0;
	    int GetuiNumberoflnstances();

};	