#include "arztpraxis.h"

#include <iostream>
using namespace std;

Arztpraxis::Arztpraxis() {}

Arztpraxis::Arztpraxis(string n) : name(n) {}

void Arztpraxis::terminAnlegen(string patient, string datumUhrzeit, Impfstoff impfStoff) {
    terminPruefen(datumUhrzeit);
    Termin termin (patient, terminPruefen(datumUhrzeit), impfStoff);
    terminListe.push_back(termin);
}

void Arztpraxis::terminLoeschen(string patient) {
    bool geloescht = false;
    for (size_t i = 0 ; i < terminListe.size() ; i++) {
        if(terminListe[i].getPatient() == patient && terminListe[i].getGeloescht() == false) {
            terminListe[i].setGeloescht(true);
            geloescht=true;
            cout << "Termin " << terminListe[i].getDatumUhrzeit() << " fuer " << patient << " geloescht" << endl;
        }
    }
    if(!geloescht) {
        cout << "Kein Termin zu diesem Namen gefunden!" << endl;
    }
}

string Arztpraxis::terminPruefen(string datumUhrzeit) {
    while (true) {
        bool passt=true;
        for (size_t i = 0 ; i < terminListe.size() ; i++) {
            if(terminListe[i].getDatumUhrzeit() == datumUhrzeit && terminListe[i].getGeloescht() == false) {
                cout << "Termin " << datumUhrzeit << " ist schon vergeben. Bitte neuen Termin eingeben:" << endl;
                cin >> datumUhrzeit;
                passt=false;
                break;
            }
        }
        if(passt) {
            break;
        }
    }
    return datumUhrzeit;
}

string Arztpraxis::getName() {
    return name;
}

void Arztpraxis::termineAnzeigen() {
    sort(terminListe.begin(), terminListe.end(), [](const Termin &a, const Termin &b) {
        return a.getPatient() < b.getPatient();
    });
    for (size_t i = 0; i < terminListe.size(); i++) {
        if(!terminListe[i].getGeloescht()) {
            cout << " " << terminListe[i].getPatient() << "\t"
                 << terminListe[i].getDatumUhrzeit() << "\t\t" << terminListe[i].getImpfstoff() << endl;
        }
    }
}
