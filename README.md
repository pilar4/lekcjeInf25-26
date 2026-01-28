Archiwizacja
wszystkich
kodow
z
informatyki 
2
0
2
5
/
2
0
2
6


disclaimer: I, nor any contributor take responsibility for abominations you can find here 


brakuje nam 1, 3, 5, 10, 12, 13, 14, 16, 17, 19, 22, 24, 26, 29, 31


#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

void bucketSort(list<string>& words) {
    // znajdź maksymalną długość słowa
    size_t maxLen = 0;
    for (const auto& w : words) {
        if (w.length() > maxLen)
            maxLen = w.length();
    }

    // sortowanie od ostatniego znaku do pierwszego
    for (int pos = maxLen - 1; pos >= 0; pos--) {
        vector<list<string>> buckets(27); 
        // 0 -> brak znaku (krótsze słowa)
        // 1-26 -> litery 'a' - 'z'

        for (const auto& word : words) {
            if (pos < word.length()) {
                int index = word[pos] - 'a' + 1;
                buckets[index].push_back(word);
            } else {
                buckets[0].push_back(word);
            }
        }

        // scal kubełki z powrotem do listy
        words.clear();
        for (auto& bucket : buckets) {
            words.splice(words.end(), bucket);
        }
    }
}

int main() {
    list<string> words = {
        "krzeslo", "krzak", "krem", "kres",
        "kraina", "kret", "kraksa", "kredyt"
    };

    bucketSort(words);

    for (const auto& w : words) {
        cout << w << endl;
    }

    return 0;
}
