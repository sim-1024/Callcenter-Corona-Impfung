#include "callcenter.h"

#include <iostream>
using namespace std;

Callcenter::Callcenter() {}

void Callcenter::dialog() {
    Arztpraxis arztpraxis;
    arztpraxen.push_back(arztpraxis);
    char eingabe;
    while(true) {
        cout << "\n1: Termin anlegen" << endl;
        cout << "2: Termin loeschen" << endl;
        cout << "3: Arztpraxis anlegen" << endl;
        cout << "4: Terminuebersicht" << endl;
        cout << "0: Programm beenden" << endl;
        cin >> eingabe;

        switch (eingabe) {
        case '1': {
            string patient, datumUhrzeit, datumUhrzeit1, praxis;
            int impfS;
            Impfstoff impfStoff;
            cout << "Name (Nachname,Vorname)? ";
            cin >> patient;
            cout << "Arztpraxis? ";
            cin >> praxis;
            if(praxisAnlegen(praxis)==-1) {
                cout << "Kein Arztpraxis zu diesem Namen!" << endl;
                break;
            }
            cout << "Impfstoff (1: Biontech, 2: Moderna, 3: Astra Zeneca, 4: Johnson&Johnson)? ";
            cin >> impfS;
            if(impfS==1) {
                impfStoff=Biontech;
            } else if (impfS==2) {
                impfStoff=Moderna;
            } else if (impfS==3) {
                impfStoff=AstraZeneca;
            } else if (impfS==4) {
                impfStoff=JohnsonJohnson;
            }
            if(impfStoff!=JohnsonJohnson) {
                cout << "Termin1 (DD.ff.YYYY:HHff)? ";
                cin >> datumUhrzeit;
                arztpraxen[praxisAnlegen(praxis)].terminAnlegen(patient, datumUhrzeit, impfStoff);
                cout << "Termin2 (DD.ff.YYYY:HHff)? ";
                cin >> datumUhrzeit1;
                arztpraxen[praxisAnlegen(praxis)].terminAnlegen(patient, datumUhrzeit1, impfStoff);
                cout << "Termin wurde eingetragen" << endl;
                break;

            }
            cout << "Termin (DD.ff.YYYY:HHff)? ";
            cin >> datumUhrzeit;
            arztpraxen[praxisAnlegen(praxis)].terminAnlegen(patient, datumUhrzeit, impfStoff);
            cout << "Termin wurde eingetragen" << endl;
        }
        break;

        case '2': {
            string patient, praxis;
            cout << "Name? ";
            cin >> patient;
            cout << "Arztpraxis? ";
            cin >> praxis;
            arztpraxen[praxisAnlegen(praxis)].terminLoeschen(patient);
        }
        break;

        case '3': {
            string name;
            cout << "Name? ";
            cin >> name;
            Arztpraxis arztpraxis(name);
            arztpraxen.push_back(arztpraxis);
            cout << "Arztpraxis " << arztpraxis.getName() << " angelegt" << endl;
        }
        break;

        case '4': {
            for (size_t i = 0; i < arztpraxen.size(); i++) {
                cout << "\nArztpraxis " << arztpraxen[i].getName() << endl;
                arztpraxen[i].termineAnzeigen();
            }
        }
        break;

        case '0': {
            return;
        }
        break;

        default: {
            cout << "Ungueltige Eingabe!" << endl;
            break;
        }
        }
    }
}

int Callcenter::praxisAnlegen(string name) {
    for (size_t i = 0; i < arztpraxen.size(); i++) {
        if(arztpraxen[i].getName()==name) {
            return i;
        }
    }
    return -1;
}

