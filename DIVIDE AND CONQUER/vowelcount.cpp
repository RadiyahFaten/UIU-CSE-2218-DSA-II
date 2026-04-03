#include <iostream>
#include <vector>
#include <string>
using namespace std;

int count_vowels(string s, int start, int end)
{
    if (start == end)
    {
        s[start] = tolower(s[start]);
        if (s[start] == 'a' || s[start] == 'e' || s[start] == 'i' || s[start] == 'o' || s[start] == 'u')
            return 1;
        else
            return 0;
    }
    int mid = (start + end) / 2;
    int left = count_vowels(s, start, mid);
    int right = count_vowels(s, mid + 1, end);

    return left + right;
}

int main()
{
    string s = "Hello World, I am Faten";
    int result = count_vowels(s, 0, s.length() - 1);

    cout << "Total vowels: " << result << endl;

    return 0;
}