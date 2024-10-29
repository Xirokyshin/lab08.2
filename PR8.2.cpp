#include <iostream>
#include <string>
using namespace std;

void CheckFirstCharacter(const string& s, size_t& firstSpacePos) {
    if (s.empty() || s[0] == ' ') {
        firstSpacePos = string::npos; // Встановлюємо значення для відсутності пробілу
    }
    else {
        firstSpacePos = s.find(' ', 1); // Пошук пробілу, починаючи з другого символу
    }
}

void ConvertToUpper(string& s, size_t firstSpacePos) {
    for (size_t i = 0; i < firstSpacePos; ++i) {
        // Перевіряємо, чи символ - мала літера
        if (s[i] >= 'a' && s[i] <= 'z') {
            // Змінюємо на велику літеру
            s[i] -= ('a' - 'A');
        }
    }
}

int main() {
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);

    size_t firstSpacePos;
    CheckFirstCharacter(str, firstSpacePos); // Перевірка першого символу

    if (firstSpacePos == string::npos) {
        cout << "Error: There must be at least one space after the first character." << endl;
        return 0; // Завершуємо програму при помилці
    }

    ConvertToUpper(str, firstSpacePos); // Перетворюємо малі літери на великі
    cout << "Modified string: " << str << endl;

    return 0;
}
