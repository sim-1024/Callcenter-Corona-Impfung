#ifndef ARZTPRAXIS_H
#define ARZTPRAXIS_H

#include"termin.h"
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Arztpraxis
{
private:
    string name = "Dr.Koch";
    vector<Termin>terminListe;
public:
    Arztpraxis();
    Arztpraxis(string n);
    void terminAnlegen(string patient, string datumUhrzeit, Impfstoff impfStoff);
    void terminLoeschen(string patient);
    string terminPruefen(string datumUhrzeit);
    string getName();
    void termineAnzeigen();
};

#endif // ARZTPRAXIS_H
