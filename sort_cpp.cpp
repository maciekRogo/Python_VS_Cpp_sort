#include <iostream>
#include <cmath>
#include <fstream>
#include <filesystem>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;
namespace fs = filesystem;

float* create_tab() {
    static float tab[10000];
    float x = 100.00;
    for (int i = 0; i < 10000; i++) {
        tab[i] = round(x * 100) / 100;
        x = x - 0.01;
    }
    return tab;
}

int main() {
    float* tab = create_tab();
    float tab1[10000];
    string path = "base.txt";
    ifstream infile(path);
    string line;

    ofstream outfile(path);
    if (outfile.is_open()) {
        for (int i = 0; i < 10000; i++) {
            outfile << tab[i] << endl;
        }
        outfile.close();
        cout << "Poprawnie utworzono pliki" << endl;
    } else {
        cerr << "Nie można otworzyć pliku " << path << endl;
    }

    auto start_conversion = chrono::high_resolution_clock::now();
    if (infile.is_open()) {
        int i = 0;
        while (getline(infile, line)) {
            tab1[i] = stof(line);
            i++;
        }
        infile.close();
    } else {
        cerr << "Nie można otworzyć pliku " << path << endl;
    }
    auto end_conversion = chrono::high_resolution_clock::now();
    chrono::duration<double> conversion_time = end_conversion - start_conversion;
    cout << "Czas konwersji: " << conversion_time.count() << " sekund" << endl;

    auto start_sort = chrono::high_resolution_clock::now();
    sort(tab1, tab1 + 10000);
    auto end_sort = chrono::high_resolution_clock::now();
    chrono::duration<double> sort_time = end_sort - start_sort;
    cout << "Czas sortowania: " << sort_time.count() << " sekund" << endl;

    auto start_write = chrono::high_resolution_clock::now();
    ofstream sorted_outfile("output_cpp.txt");
    if (sorted_outfile.is_open()) {
        for (int i = 0; i < 10000; i++) {
            sorted_outfile << tab1[i] << endl;
        }
        sorted_outfile.close();
        cout << "Poprawnie zapisano posortowane dane do pliku" << endl;
    } else {
        cerr << "Nie można otworzyć pliku sorted_base.txt" << endl;
    }
    auto end_write = chrono::high_resolution_clock::now();
    chrono::duration<double> write_time = end_write - start_write;
    cout << "Czas zapisu: " << write_time.count() << " sekund" << endl;

    return 0;
}