#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string line;

    while (getline(cin, line)) {
        istringstream iss(line);
        int numWords, maxLines, maxChars;

        if (!(iss >> numWords >> maxLines >> maxChars)) {
            break;
        }

        string story;
        getline(cin, story);

        int currentPage = 1;
        int currentLine = 1;
        int currentChars = 0;

        istringstream issStory(story);
        string word;
        bool isLastWord = false;

        while (issStory >> word) {
            if (currentChars + word.length() > maxChars) {
                currentLine++;
                currentChars = 0;
            }
            if (currentLine > maxLines) {
                currentPage++;
                currentLine = 1;
            }

            issStory >> ws;
            if (issStory.eof()) {
                isLastWord = true;
            } else {
                issStory.unget();
            }

            if (!isLastWord) {
                currentChars += word.length() + 1;
            } else {
                currentChars += word.length();
            }
        }

        cout << currentPage << endl;
    }

    return 0;
}
