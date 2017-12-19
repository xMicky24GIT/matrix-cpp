#include <iostream>
using namespace std;

//variabile per la lunghezza dei vettori (matrici)
#define DIMENSIONE 3

//funzione per il menu
int menu(){
    int selezione;

    cout << "-----------Menu principale-----------" << endl;
    cout << "|->[1] Moltiplicazione (matrici 3x3)" << endl;
    cout << "|->[2] Addizione (matrici 3x3)" << endl;
    cout << "|->[3] Sottrazione (matrici 3x3)" << endl;
    cout << "|->[4] Trasversale (matrici 3x3)" << endl;
    cout << "|->[5] Determinante (matrici 3x3)" << endl;
    cout << "|->[0] Esci dal programma" << endl;
    cout << ">>>Selezione: ";
    cin >> selezione;

    return selezione;
} //-123456

/* stampa spazi bianchi per la grafica delle matrici.
 * Dopo la prima cifra del numero ci si sposta di 5 spazi per il carattere che divide i due numeri
 */
void spaces(float number){
    // NUMERI POSITIVI
    if (number >= 0) {
        // qui sotto: numeri ad una cifra (0;9)
        if ((number < 10) && (number >= 0)) {
            for (int i = 0; i < 5; i++) {
                cout << " ";
            } // qui sotto: numeri a due cifre (10;99)
        } else if ((number < 100) && (number >= 10)) {
            for (int i = 0; i < 4; i++) {
                cout << " ";
            } // qui sotto: numeri a tre cifre (100;999)
        } else if ((number < 1000) && (number >= 100)){
            for (int i = 0; i < 3; i++) {
                cout << " ";
            }
        }
    } else {
        // qui sotto: numeri ad una cifra (0;9)
        if ((number > -10) && (number < 0)) {
            for (int i = 0; i < 4; i++) {
                cout << " ";
            } // qui sotto: numeri a due cifre (10;99)
        } else if ((number > -100) && (number <= 10)) {
            for (int i = 0; i < 3; i++) {
                cout << " ";
            } // qui sotto: numeri a tre cifre (100;999)
        } else if ((number > 1000) && (number <= 100)){
            for (int i = 0; i < 2; i++) {
                cout << " ";
            }
        }
    }
}

// addizione tra due matrici
void addizioneMatrici(float matrice1[DIMENSIONE][DIMENSIONE], float matrice2[DIMENSIONE][DIMENSIONE]){
    float s;
    for (int i = 0; i < DIMENSIONE; i++) {
        for (int j = 0; j < DIMENSIONE; j++) {
            cout << "| ";
            cout << matrice1[i][j] + matrice2[i][j];
            s = matrice1[i][j] + matrice2[i][j];
            spaces(s);
        }
        cout << "|" << endl;
    }

}

// addizione tra due matrici (matrici 3x3)
void sottrazioneMatrici(float matrice1[DIMENSIONE][DIMENSIONE], float matrice2[DIMENSIONE][DIMENSIONE]){
    float s;

    for (int i = 0; i < DIMENSIONE; i++) {
        for (int j = 0; j < DIMENSIONE; j++) {
            cout << "| ";
            cout << matrice1[i][j] + (-(matrice2[i][j]));
            s = matrice1[i][j] + (-(matrice2[i][j]));
            spaces(s);
        }
        cout << "|" << endl;
    }

}

// matrice trasversale (matrice 3x3) (trasforma le colonne in righe)
void matriceTrasversale(float matrice[DIMENSIONE][DIMENSIONE]){

    for (int i = 0; i < DIMENSIONE; i++) {
        for (int j = 0; j < DIMENSIONE; j++) {
            cout << "| ";
            cout << matrice[j][i];
            spaces(matrice[j][i]);
        }
        cout << "|" << endl;
    }

}


// calcolo del determinante di una matrice
void determinanteMatrice(float matrice[DIMENSIONE][DIMENSIONE]){
    int diaForward = 1, diaBack = 1;
    float determinante = 0;

    for (int i=0; i<DIMENSIONE; i++)
    {
        for (int j=0; j<DIMENSIONE; j++)
        {
            diaBack *= matrice[j][j+i<DIMENSIONE ? j+i : j+i-DIMENSIONE];
            diaForward *= matrice[j][DIMENSIONE-j-1-i>=0 ? DIMENSIONE-j-1-i : 2*DIMENSIONE-j-i-1];
        }
        determinante += diaBack-diaForward;
        diaForward = diaBack = 1;
    }

    cout << "Determinante della matrice: " << determinante << endl << endl;
}


// moltiplicazione tra due matrici
void moltiplicaMatrici(float matrice1[DIMENSIONE][DIMENSIONE], float matrice2[DIMENSIONE][DIMENSIONE]){
    float matriceMoltiplicazione[DIMENSIONE][DIMENSIONE] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    for (int i = 0; i < DIMENSIONE; i++) {
        for (int j = 0; j < DIMENSIONE; j++) {
            for (int k = 0; k < DIMENSIONE; k++) {
                matriceMoltiplicazione[i][j] += matrice1[i][k] * matrice2[k][j];
            }
        }
    }

    for (int i = 0; i < DIMENSIONE; i++) {
        for (int j = 0; j < DIMENSIONE; j++) {
            cout << "|";
            cout << matriceMoltiplicazione[i][j];
            spaces(matriceMoltiplicazione[i][j]);
        }
        cout << "|" << endl;
    }

}


// funzione principale del programma
int main() {

    float matrice1[DIMENSIONE][DIMENSIONE];
    float matrice2[DIMENSIONE][DIMENSIONE];
    int selezione, elemento;

    // acquisizione della prima matrice
    cout << "Inserisci la prima matrice seguendo questo ordine: " << endl;
    cout << "1 | 2 | 3" << endl;
    cout << "4 | 5 | 6" << endl;
    cout << "7 | 8 | 9" << endl;

    elemento = 1;
    for(int i = 0; i < DIMENSIONE; i++){
        for (int j = 0; j < DIMENSIONE; j++) {
            cout << "Inserisci elemento [" << elemento << "] della prima matrice: ";
            cin >> matrice1[i][j];
            elemento++;
        }
    }

    // acquisizione della seconda matrice
    cout << "Inserisci la seconda matrice seguendo questo ordine: " << endl;
    cout << "1 | 2 | 3" << endl;
    cout << "4 | 5 | 6" << endl;
    cout << "7 | 8 | 9" << endl;

    elemento = 1;
    for(int i = 0; i < DIMENSIONE; i++){
        for (int j = 0; j < DIMENSIONE; j++) {
            cout << "Inserisci elemento [" << elemento << "] della seconda matrice: ";
            cin >> matrice2[i][j];
            elemento++;
        }
    }


    // gestione del menu e della funzione scelta dall'utente
    do{
        selezione = menu();

        switch(selezione){
            default:
                cout << "Selezione non valida, riprova..." << endl << endl;
                break;
            case 0:
                cout << "Termino il programma..." << endl << endl;
                break;
            case 1:
                cout << "Moltiplicazione tra le due matrici (prima * seconda): " << endl << endl;
                moltiplicaMatrici(matrice1, matrice2);
                break;
            case 2:
                cout << "Addizione tra le due matrici: " << endl << endl;
                addizioneMatrici(matrice1, matrice2);
                break;
            case 3:
                cout << "Sottrazione tra le due matrici: " << endl << endl;
                sottrazioneMatrici(matrice1, matrice2);
                break;
            case 4:
                cout << "Trasversale di una matrice. Di quale matrice eseguire il trasversale? (1 o 2): ";
                int sceltaMatriceTrasv;
                cin >> sceltaMatriceTrasv;
                if (sceltaMatriceTrasv == 1)
                    matriceTrasversale(matrice1);
                else if (sceltaMatriceTrasv == 2)
                    matriceTrasversale(matrice2);
                else
                    cout << "Matrice non valida. Torno al menu principale..." << endl << endl;
                break;
            case 5:
                cout << "Determinante di una matrice. Di quale matrice eseguire il trasversale? (1 o 2): ";
                int sceltaMatriceDet;
                cin >> sceltaMatriceDet;
                if (sceltaMatriceDet == 1)
                    determinanteMatrice(matrice1);
                else if (sceltaMatriceDet == 2)
                    determinanteMatrice(matrice2);
                else
                    cout << "Matrice non valida. Torno al menu principale..." << endl << endl;
                break;
        }

    }while(selezione!=0);

    return 0;
}