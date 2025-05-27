#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void createNumbersFile(const char* fname) {
    ofstream fout(fname);
    if (!fout) {
        cerr << "Cannot open file for writing: " << fname << endl;
        return;
    }
    int x;
    char ch;
    do {
        cout << "Enter number: ";
        cin >> x;
        fout << x << " ";
        cout << "Continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

void processNegativeSums(const char* inName, const char* outName) {
    ifstream fin(inName);
    ofstream fout(outName);
    if (!fin || !fout) {
        cerr << "File open error" << endl;
        return;
    }
    int value;
    int sumNeg = 0;
    while (fin >> value) {
        if (value < 0) {
            sumNeg += value;
            fout << sumNeg << " ";
        }
    }
}

void printFile(const char* fname) {
    ifstream fin(fname);
    if (!fin) {
        cerr << "Cannot open file for reading: " << fname << endl;
        return;
    }
    int x;
    while (fin >> x) {
        cout << x << endl;
    }
}

int main() {
    char inputFile[256];
    char outputFile[256];

    cout << "Input data filename: ";
    cin >> inputFile;
    createNumbersFile(inputFile);

    cout << "Output data filename: ";
    cin >> outputFile;
    processNegativeSums(inputFile, outputFile);

    printFile(outputFile);
    return 0;
}
