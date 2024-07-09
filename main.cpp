#include <iostream>
using namespace std;

int my_strlen(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

const char* my_strstr(const char* haystack, const char* needle) {
    if (!*needle) return haystack;
    for (const char* p = haystack; *p; ++p) {
        const char* q = p;
        const char* r = needle;
        while (*r && (*q == *r)) {
            q++;
            r++;
        }
        if (!*r) return p;
    }
    return nullptr;
}

char my_toupper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    return c;
}

bool my_isalpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

char my_tolower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

void replaceWord(char* text, const char* from, const char* to) {
    char buffer[1000];
    int len = my_strlen(from);
    int to_len = my_strlen(to);
    int buffer_index = 0;
    char* original_text = text; // Save the original pointer

    while (*text) {
        const char* pos = my_strstr(text, from);
        if (pos) {
            // Copy the part before the found word to the buffer
            while (text != pos) {
                buffer[buffer_index++] = *text++;
            }
            // Copy the replacement word to the buffer
            for (int i = 0; i < to_len; i++) {
                buffer[buffer_index++] = to[i];
            }
            // Skip the replaced word in the original text
            text += len;
        }
        else {
            // Copy the rest of the text
            while (*text) {
                buffer[buffer_index++] = *text++;
            }
        }
    }
    buffer[buffer_index] = '\0';

    // Copy the modified buffer back to the original text
    for (int i = 0; buffer[i]; i++) {
        original_text[i] = buffer[i];
    }
    original_text[buffer_index] = '\0';
}

void capitalizeSentences(char* text) {
    bool capitalize = true;
    for (int i = 0; text[i]; i++) {
        if (capitalize && my_isalpha(text[i])) {
            text[i] = my_toupper(text[i]);
            capitalize = false;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            capitalize = true;
        }
    }
}

void countLetters(const char* text, int letterCount[26]) {
    for (int i = 0; text[i]; i++) {
        if (my_isalpha(text[i])) {
            letterCount[my_tolower(text[i]) - 'a']++;
        }
    }
}

int countDigits(const char* text) {
    int digitCount = 0;
    for (int i = 0; text[i]; i++) {
        if (text[i] >= '0' && text[i] <= '9') {
            digitCount++;
        }
    }
    return digitCount;
}

int main() {
    char text[200] = "There is a certain text. Using the standard string functions from the C library. 1914-1918 1939-1945";
    cout << text << endl;
    char from[100];
    char to[100];

    cout << "Enter the word to replace: ";
    cin >> from;
    cout << "Enter the word to replace with: ";
    cin >> to;

    replaceWord(text, from, to);
    cout << "Text after word replacement: " << text << endl;
    cout << endl;

    capitalizeSentences(text);
    cout << "Text after capitalizing sentences: " << text << endl;
    cout << endl;

    int letterCount[26] = { 0 };
    countLetters(text, letterCount);
    cout << "Letter frequencies: " << endl;
    for (int i = 0; i < 26; i++) {
        if (letterCount[i] > 0) {
            cout << char('a' + i) << ": " << letterCount[i] << endl;
        }
    }
    cout << "Digit count: " << countDigits(text) << endl;

    return 0;
}
