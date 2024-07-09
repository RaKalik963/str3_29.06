#include <iostream>
using namespace std;

int countOccurrences(const char* text, const char* word) {
    int count = 0;
    int textLength = 0;
    int wordLength = 0;

    while (text[textLength] != '\0') {
        textLength++;
    }
    while (word[wordLength] != '\0') {
        wordLength++;
    }

    for (int i = 0; i <= textLength - wordLength; i++) {
        bool found = true;
        for (int j = 0; j < wordLength; j++) {
            if (text[i + j] != word[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            count++;
        }
    }

    return count;
}

int countSentences(const char* text) {
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            count++;
        }
    }
    return count;
}

void countDotsAndCommas(const char* text, int& dots, int& commas) {
    dots = 0;
    commas = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '.') {
            dots++;
        }
        else if (text[i] == ',') {
            commas++;
        }
    }
}

void reverseString(char* text) {
    int length = 0;
    while (text[length] != '\0') {
        length++;
    }

    for (int i = 0; i < length / 2; i++) {
        char temp = text[i];
        text[i] = text[length - 1 - i];
        text[length - 1 - i] = temp;
    }
}

void reverseSentences(char* text) {
    int start = 0;
    int length = 0;

    while (text[length] != '\0') {
        length++;
    }

    for (int i = 0; i <= length; i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?' || text[i] == '\0') {
            int end = i - 1;
            while (start < end) {
                char temp = text[start];
                text[start] = text[end];
                text[end] = temp;
                start++;
                end--;
            }
            start = i + 1;
        }
    }
}

int main() {
    const char text[] = "Count the number of occurrences of a word specified by the user in the text. Turn the entire text over.";
    cout << text << endl;
    cout << endl;
    char word[100];  
    cout << "Enter word to find occurrences: ";
    cin >> word;

    int occurrences = countOccurrences(text, word);
    cout << "Occurrences of \"" << word << "\": " << occurrences << endl;

    int sentences = countSentences(text);
    cout << "Number of sentences: " << sentences << endl;

    int dots, commas;
    countDotsAndCommas(text, dots, commas);
    cout << "Dots: " << dots << ", Commas: " << commas << endl;

    char reversedText[] = "Count the number of, occurrences of, a word specified by the, user in the text. Turn the entire text over.";
    reverseString(reversedText);
    cout << "Reversed text: " << reversedText << endl;

    char reversedSentencesText[] = "Count the number of, occurrences of, a word specified by the, user in the text. Turn the entire text over.";
    reverseSentences(reversedSentencesText);
    cout << "Reversed sentences text: " << reversedSentencesText << endl;

    return 0;
}
