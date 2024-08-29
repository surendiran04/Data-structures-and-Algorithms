#include <iostream>
#include <vector>
using namespace std;

vector<int> naive_pattern_matching(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> occurrences;

    for (int i = 0; i <= n - m; ++i) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            ++j;
        }
        if (j == m) {
            occurrences.push_back(i);
        }
    }

    return occurrences;
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABC";
    vector<int> result = naive_pattern_matching(text, pattern);

    cout << "Occurrences of '" << pattern << "' in '" << text << "': ";
    for (int pos : result) {
        cout << pos << " ";
    }
    cout << endl;

    return 0;
}
