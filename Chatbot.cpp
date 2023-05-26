#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    int choice;
    map<string, string> m;
    do
    {
        cout << "Enter your choice : " << endl;
        cout << "1: Chat " << endl;
        cout << "2: Exit " << endl;
        cin >> choice;
        ofstream out;
        ifstream in;

        if (choice == 1)
        {
            string question;
            cout << "You can ask me any question : ";
            cin.ignore();
            getline(cin, question);
            in.open("chat.txt");
            string str;
            int flag = 0;
            string answer = "";
            while (getline(in, str))
            {
                if (flag == 1)
                {
                    answer = str;
                    break;
                }
                if (str == question)
                {
                    flag = 1;
                }
            }
            in.close();
            if (answer == "")
            {
                out.open("chat.txt");
                out << question << endl;
                cout << "Hmmm...... that's a good question may be you could help me?" << endl;
                cout << question << endl;
                string ans;
                getline(cin, ans);
                out << ans << endl;
                out.close();
            }
            else
            {
                cout << answer << endl;
            }
        }
    } while (choice != 2);
    return 0;
}