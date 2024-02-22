#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_STUDENTS = 100;

struct Student {
    string name;
    string nim;
    double nilaiTugas;
    double nilaiUTS;
    double nilaiUAS;
    double nilaiRata;
    char predikat;
};

void inputStudentData(Student students[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Masukkan data untuk Mahasiswa ke-" << i + 1 << ":" << endl;
        cout << "Nama: ";
        cin.ignore();
        getline(cin, students[i].name);
        cout << "NIM: ";
        getline(cin, students[i].nim);
        cout << "Nilai Tugas: ";
        cin >> students[i].nilaiTugas;
        cout << "Nilai UTS: ";
        cin >> students[i].nilaiUTS;
        cout << "Nilai UAS: ";
        cin >> students[i].nilaiUAS;

        // Menghitung rata-rata
        students[i].nilaiRata = (students[i].nilaiTugas + students[i].nilaiUTS + students[i].nilaiUAS) / 3;

        // Menentukan predikat
        if (students[i].nilaiRata >= 80)
            students[i].predikat = 'A';
        else if (students[i].nilaiRata >= 70)
            students[i].predikat = 'B';
        else if (students[i].nilaiRata >= 60)
            students[i].predikat = 'C';
        else
            students[i].predikat = 'D';
    }
}

void displayStudentData(const Student students[], int n) {
    cout << "===================================================================================" << endl;
    cout << "| No |     Nama     |   NIM   | Tugas |  UTS  |  UAS  | Rata-rata | Predikat |" << endl;
    cout << "===================================================================================" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "| " << setw(2) << i+1 << " | ";
        cout << setw(12) << students[i].name << " | ";
        cout << setw(7) << students[i].nim << " | ";
        cout << setw(6) << students[i].nilaiTugas << " | ";
        cout << setw(5) << students[i].nilaiUTS << " | ";
        cout << setw(5) << students[i].nilaiUAS << " | ";
        cout << setw(9) << fixed << setprecision(2) << students[i].nilaiRata << " | ";
        cout << setw(9) << students[i].predikat << " |" << endl;
    }
    cout << "===================================================================================" << endl;
}

int main() {
    int numStudents;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> numStudents;

    // Batasi jumlah mahasiswa agar tidak melebihi maksimum yang ditentukan
    if (numStudents > MAX_STUDENTS) {
        cout << "Jumlah mahasiswa melebihi batas maksimum (" << MAX_STUDENTS << ")." << endl;
        return 1;
    }

    Student students[MAX_STUDENTS];

    inputStudentData(students, numStudents);

    cout << endl << "Data Mahasiswa:" << endl;
    displayStudentData(students, numStudents);

    return 0;
}
