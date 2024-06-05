#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bubbleSort(vector<int>& arr) {
    int angka = arr.size();
    for (int ini = 0; ini < angka-1; ini++) {
        for (int jhahaha = 0; jhahaha < angka-ini-1; jhahaha++) {
            if (arr[jhahaha] > arr[jhahaha+1]) {
                swap(arr[jhahaha], arr[jhahaha+1]);
            }
        }
    }
}

void insertionSort(vector<int>& arr) {
    int angka = arr.size();
    for (int ini = 1; ini < angka; ini++) {
        int key = arr[ini];
        int jhahaha = ini - 1;
        while (jhahaha >= 0 && arr[jhahaha] > key) {
            arr[jhahaha + 1] = arr[jhahaha];
            jhahaha = jhahaha - 1;
        }
        arr[jhahaha + 1] = key;
    }
}

void countingSort(vector<int>& arr, int exp) {
    int angka = arr.size();
    vector<int> output(angka);
    int count[10] = {0};

    for (int ini = 0; ini < angka; ini++) {
        count[(arr[ini] / exp) % 10]++;
    }

    for (int ini = 1; ini < 10; ini++) {
        count[ini] += count[ini - 1];
    }

    for (int ini = angka - 1; ini >= 0; ini--) {
        output[count[(arr[ini] / exp) % 10] - 1] = arr[ini];
        count[(arr[ini] / exp) % 10]--;
    }

    for (int ini = 0; ini < angka; ini++) {
        arr[ini] = output[ini];
    }
}

void radixSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int nyariangka(vector<int>& arr, int itu) {
    for (int ini = 0; ini < arr.size(); ini++) {
        if (arr[ini] == itu) {
            return ini;
        }
    }
    return -1;
}

int binarySearch(vector<int>& arr, int itu) {
    int apa = 0, bjir = arr.size() - 1;
    while (apa <= bjir) {
        int m = apa + (bjir - apa) / 2;
        if (arr[m] == itu) {
            return m;
        }
        if (arr[m] < itu) {
            apa = m + 1;
        } else {
            bjir = m - 1;
        }
    }
    return -1;
}

void printArray(vector<int>& arr) {
    for (int ini = 0; ini < arr.size(); ini++) {
        cout << "Isi Array ke " << ini + 1 << ": " << arr[ini] << endl;
    }
}

int main() {
    int angka;
    cout << "nama:rechan dinata" << endl;
    cout << "nim:23110533" << endl;
    cout << "Masukkan jumlah array yang diinputkan: ";
    cin >> angka;

    vector<int> arr(angka);
    for (int ini = 0; ini < angka; ini++) {
        cout << "Nilai ke " << ini + 1 << ": ";
        cin >> arr[ini];
    }

    cout << "Baca isi array: " << endl;
    printArray(arr);

    cout << "Silahkan Pilih Teknik Pengurutan yang diinginkan" << endl;
    cout << "1. Bubble sort" << endl;
    cout << "2. Insertion sort" << endl;
    cout << "3. Radix sort" << endl;

    int choice;
    cout << "Masukkan teknik pengurutan yang diinginkan: ";
    cin >> choice;

    switch (choice) {
        case 1:
            bubbleSort(arr);
            break;
        case 2:
            insertionSort(arr);
            break;
        case 3:
            radixSort(arr);
            break;
        default:
            cout << "Pilihan tidak valid" << endl;
            return 1;
    }

    cout << "Isi Array setelah pengurutan: " << endl;
    printArray(arr);

    int searchChoice;
    cout << "Apakah anda ingin melakukan pencarian? Jika iya masukkan angka, jika tidak tekan -88: ";
    cin >> searchChoice;
    if (searchChoice == -88) {
        return 0;
    }

    cout << "Masukkan algoritma pencarian yang anda inginkan: " << endl;
    cout << "1. Sequential Search" << endl;
    cout << "2. Binary Search" << endl;

    int searchAlgorithm;
    cout << "Pencarian: ";
    cin >> searchAlgorithm;

    int itu = searchChoice ; 
    int index = -1;
    if (searchAlgorithm == 1) {
        index = nyariangka(arr, itu);
    } else if (searchAlgorithm == 2) {
        index = binarySearch(arr, itu);
    } else {
        cout << "Pilihan tidak valid" << endl;
        return 1;
    }

    if (index != -1) {
        cout << "Nilai " << itu << " ditemukan pada index ke " << index + 1 << endl;
    } else {
        cout << "Nilai " << itu << " tidak ditemukan" << endl;
    }

    return 0;
}
