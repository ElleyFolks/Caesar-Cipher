#include <iostream>
#include <string>
#include <cstring>

using namespace std;
void get_message(string &m, int &r);                              // gathering plaintext and rotation factor input.
void encrypt_message(string plain, int rotation, string &cipher); // converts plaintext to cipher text and outputs it.

int main()
{
    string plain_text = {};  // plain text
    string cipher_text = {}; // cipher text
    int k = 0;               // rotation factor.

    get_message(plain_text, k);
    cout << "plaintext message: " << plain_text << "\nrotation factor: " << k << endl;

    encrypt_message(plain_text, k, cipher_text);
    cout << "encrypted text is: \n"
         << cipher_text;
}

void get_message(string &m, int &r)
{
    cout << "Please enter your message." << endl;
    getline(cin, m);
    cout << "Please enter the rotation factor (any whole positive intiger)." << endl;
    cin >> r;

    if (r < 0) // input validation for r
    {
        while (r < 0)
        {
            cout << "please enter a positive value" << endl;
            cin >> r;
        }
    }
}

void encrypt_message(string plain, int rotation, string &cipher)
{
    int index;
    index = plain.length();

    for (int i = 0; i < index; i++)
    {
        int temp = 0;
        string cipher_value = ""; // reset these value for each itteration

        temp = static_cast<int>(plain[i]); // ASCII value for character from plain text
        temp += rotation;

        // accounts for if rotation moves ASCII value outside of valid range.
        if (temp > 126)
        {
            temp -= 126;
            temp += 32; // put back into printable character range
        }

        cipher_value = (char)temp;      // converst ASCII back to character
        cipher.insert(i, cipher_value); // inserts each encrpyted value to new cipher string
    }
}
