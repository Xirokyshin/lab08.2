#include <iostream>
#include <string>
using namespace std;

void CheckFirstCharacter(const string& s, size_t& firstSpacePos) {
    if (s.empty() || s[0] == ' ') {
        firstSpacePos = string::npos; // ������������ �������� ��� ��������� ������
    }
    else {
        firstSpacePos = s.find(' ', 1); // ����� ������, ��������� � ������� �������
    }
}

void ConvertToUpper(string& s, size_t firstSpacePos) {
    for (size_t i = 0; i < firstSpacePos; ++i) {
        // ����������, �� ������ - ���� �����
        if (s[i] >= 'a' && s[i] <= 'z') {
            // ������� �� ������ �����
            s[i] -= ('a' - 'A');
        }
    }
}

int main() {
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);

    size_t firstSpacePos;
    CheckFirstCharacter(str, firstSpacePos); // �������� ������� �������

    if (firstSpacePos == string::npos) {
        cout << "Error: There must be at least one space after the first character." << endl;
        return 0; // ��������� �������� ��� �������
    }

    ConvertToUpper(str, firstSpacePos); // ������������ ��� ����� �� �����
    cout << "Modified string: " << str << endl;

    return 0;
}
