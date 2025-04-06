#include "termin.h"
#include "arztpraxis.h"

Termin::Termin(string name, string zeit, Impfstoff impf)
    : patient(name), datumUhrzeit(zeit), impfStoff(impf) {}

string Termin::getDatumUhrzeit() const {
    return datumUhrzeit;
}

string Termin::getPatient() const {
    return patient;
}

bool Termin::getGeloescht() const {
    return geloescht;
}

void Termin::setGeloescht(bool wert) {
    geloescht=wert;
}

string Termin::getImpfstoff() const {
    if(impfStoff==0) {
        return "Biontech";
    } else if(impfStoff==1) {
        return "Moderna";
    }
    else if(impfStoff==2) {
        return "AstraZeneca";
    } else {
        return "JohnsonJohnson";
    }
}
