<img width="1127" height="348" alt="image" src="https://github.com/user-attachments/assets/e0ddc5be-e365-4784-892e-76f5f9aa199f" />
У цій програмі створено структуру Worker, яка містить дані про працівників: ПІБ, посаду, оклад і рік прийняття на роботу. Користувач вводить інформацію про десять працівників. Далі програма сортує їх за зростанням посадового окладу, виводить упорядкований список, а потім дає змогу знайти і вивести тих працівників, чий стаж роботи перевищує задане значення. Якщо таких немає — виводиться відповідне повідомлення.
#include <iostream>
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


✅  Чек-лист знань (`checklist.md`)
**Тема:** Структури (struct) у C++
### 🔹 Теоретичні знання
- [+] Знаю, що таке структура і для чого вона потрібна.  
- [+] Можу оголосити структуру та пояснити її поля.  
- [+] Знаю, як створити змінну структури та звертатися до її полів.  

### 🔹 Практичні навички
- [+] У коді є структура з кількома полями.  
- [+] Реалізовано введення і виведення даних.  
- [+] Програма обробляє масив структур (сортування, фільтрація тощо).  
- [+] Код має коментарі та працює без помилок.  

### 🔹 Робота з GitHub / Gist
- [ ] Є файли `main.cpp` і `README.md`.  
- [+] README.md містить алгоритм, приклад виконання та висновок.  
- [+] Репозиторій / Gist має зрозумілу назву та структуровану організацію.  

### 🔹 Самооцінка
- [+] Можу пояснити роботу своєї структури.  
- [+] Розумію, як можна вдосконалити програму.  
- [+] Знаю, в яких задачах доцільно використовувати struct.
