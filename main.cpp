#include <iostream>
using namespace std;

//variabile per la lunghezza dei vettori (matrici)
#define DIMENSIONE 3

//funzione per il menu
int menu(){
    int selezione;

    cout << "Menu principale" << endl;
    cout << "[1] Moltiplicazione (matrici 3x3)" << endl;
    cout << "[2] Addizione (matrici 3x3)" << endl;
    cout << "[3] Sottrazione (matrici 3x3)" << endl;
    cout << "[4] Trasversale (matrici 3x3)" << endl;
    cout << "[5] Determinante (matrici 3x3)" << endl;
    cout << "[0] Esci dal programma" << endl;
    cout << "Selezione: ";
    cin >> selezione;

    return selezione;
}

// addizione tra due matrici
void addizioneMatrici(int matrice1[DIMENSIONE][DIMENSIONE], int matrice2[DIMENSIONE][DIMENSIONE]){

    for (int i = 0; i < DIMENSIONE; i++) {
        for (int j = 0; j < DIMENSIONE; j++) {
            cout << matrice1[i][j] + matrice2[i][j] << " | ";
        }
        cout << endl;
    }

}

// addizione tra due matrici (matrici 3x3)
void sottrazioneMatrici(int matrice1[DIMENSIONE][DIMENSIONE], int matrice2[DIMENSIONE][DIMENSIONE]){

    for (int i = 0; i < DIMENSIONE; i++) {
        for (int j = 0; j < DIMENSIONE; j++) {
            cout << matrice1[i][j] + (-(matrice2[i][j])) << " | ";
        }
        cout << endl;
    }

}

// matrice trasversale (matrice 3x3) (trasforma le colonne in righe)
void matriceTrasversale(int matrice[DIMENSIONE][DIMENSIONE]){

    for (int i = 0; i < DIMENSIONE; i++) {
        for (int j = 0; j < DIMENSIONE; j++) {
            cout << matrice[j][i] << " | ";
        }
        cout << endl;
    }

}


// calcolo del determinante di una matrice
void determinanteMatrice(int matrice[DIMENSIONE][DIMENSIONE]){
    int diaForward = 1, diaBack = 1;
    int determinante = 0;

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
void moltiplicaMatrici(int matrice1[DIMENSIONE][DIMENSIONE], int matrice2[DIMENSIONE][DIMENSIONE]){
    int matriceMoltiplicazione[DIMENSIONE][DIMENSIONE] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    for (int i = 0; i < DIMENSIONE; i++) {
        for (int j = 0; j < DIMENSIONE; j++) {
            for (int k = 0; k < DIMENSIONE; k++) {
                matriceMoltiplicazione[i][j] += matrice1[i][k] * matrice2[k][j];
            }
        }
    }

    for (int i = 0; i < DIMENSIONE; i++) {
        for (int j = 0; j < DIMENSIONE; j++) {
            cout << matriceMoltiplicazione[j][i] << " | ";
        }
        cout << endl;
    }

}


// funzione principale del programma
int main() {

    int matrice1[DIMENSIONE][DIMENSIONE];
    int matrice2[DIMENSIONE][DIMENSIONE];
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