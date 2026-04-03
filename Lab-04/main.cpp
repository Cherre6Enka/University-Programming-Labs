#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

int countSentences(const char *str);
int countSentences(const string &str);

int main()
{
    char c_strings[5][200];
    string cpp_strings[5];

    cout << "Enter 5 lines of text:" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ": ";
        cin.getline(c_strings[i], 200);
        cpp_strings[i] = c_strings[i];
    }

    cout << endl
         << "--- Results ---" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "String " << i + 1 << ":" << endl;
        cout << "  C-string result: " << countSentences(c_strings[i]) << endl;
        cout << "  string result:   " << countSentences(cpp_strings[i]) << endl;
    }

    return 0;
}

int countSentences(const char *str)
{
    int count = 0;
    bool lookingForStart = true;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (lookingForStart)
        {
            if (isupper((unsigned char)str[i]))
            {
                lookingForStart = false;
            }
        }
        else
        {
            if (str[i] == '.' || str[i] == '!' || str[i] == '?')
            {
                count++;
                lookingForStart = true;
            }
        }
    }
    return count;
}

int countSentences(const string &str)
{
    int count = 0;
    bool lookingForStart = true;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (lookingForStart)
        {
            if (isupper((unsigned char)str[i]))
            {
                lookingForStart = false;
            }
        }
        else
        {
            if (str[i] == '.' || str[i] == '!' || str[i] == '?')
            {
                count++;
                lookingForStart = true;
            }
        }
    }
    return count;
}
