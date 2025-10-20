#include <iostream>
#include <windows.h>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Worker {
    string name;       // ПІБ робітника
    string position;   // Посада
    double salary;     // Посадовий оклад
    int year;          // Рік прийняття на роботу
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int N = 10;
    Worker workers[N];
    int currentYear = 2025;

    // Введення даних
    cout << "Введіть дані про 10 робітників:\n";
    for (int i = 0; i < N; i++) {
        cout << "\nРобітник №" << i + 1 << ":\n";
        cout << "ПІБ: ";
        getline(cin >> ws, workers[i].name);
        cout << "Посада: ";
        getline(cin >> ws, workers[i].position);
        cout << "Посадовий оклад: ";
        cin >> workers[i].salary;
        cout << "Рік прийняття на роботу: ";
        cin >> workers[i].year;
    }

    // Сортування за зростанням посадового окладу
    sort(workers, workers + N, [](Worker a, Worker b) {
        return a.salary < b.salary;
        });

    // Виведення відсортованого списку
    cout << "\nПрацівники після сортування за окладом:\n";
    cout << left << setw(25) << "ПІБ" << setw(20) << "Посада"
        << setw(10) << "Оклад" << setw(10) << "Рік" << endl;
    cout << string(65, '-') << endl;
    for (int i = 0; i < N; i++) {
        cout << left << setw(25) << workers[i].name
            << setw(20) << workers[i].position
            << setw(10) << workers[i].salary
            << setw(10) << workers[i].year << endl;
    }

    // Виведення працівників зі стажем більшим за задане значення
    int minExperience;
    cout << "\nВведіть мінімальний стаж роботи (у роках): ";
    cin >> minExperience;

    bool found = false;
    cout << "\nРобітники зі стажем більше " << minExperience << " років:\n";
    for (int i = 0; i < N; i++) {
        int experience = currentYear - workers[i].year;
        if (experience > minExperience) {
            cout << workers[i].name << " (" << experience << " років стажу)\n";
            found = true;
        }
    }

    if (!found)
        cout << "Немає робітників зі стажем більше " << minExperience << " років.\n";

    return 0;
}

