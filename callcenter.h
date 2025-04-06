#ifndef CALLCENTER_H
#define CALLCENTER_H

#include"arztpraxis.h"

class Callcenter
{
private:
    vector<Arztpraxis>arztpraxen;
public:
    Callcenter();
    void dialog();
    int praxisAnlegen(string name);
};

#endif // CALLCENTER_H
