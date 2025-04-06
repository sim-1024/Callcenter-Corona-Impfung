#ifndef TERMIN_H
#define TERMIN_H

#include<string>
using namespace std;

enum Impfstoff {Biontech, Moderna, AstraZeneca, JohnsonJohnson};

class Termin
{
private:
    string datumUhrzeit;
    string patient;
    Impfstoff impfStoff;
    bool geloescht=false;
public:
    Termin(string name, string zeit, Impfstoff impf);
    string getDatumUhrzeit() const;
    string getPatient() const;
    bool getGeloescht() const;
    void setGeloescht(bool wert);
    string getImpfstoff() const;
};


#endif // TERMIN_H
