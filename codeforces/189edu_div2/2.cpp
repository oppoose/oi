#include <bits/stdc++.h>
using namespace std;
#define int long long
void so()
{
    string s;
    cin >> s;
    string t(s.length(), ' ');
    int l = 0, r = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    t[0] = s[0];
    t[1] = (s[0] == 'a') ? 'b' : 'a';
    for (int i = 2; i < s.length(); i++)
    {
        t[i] = t[i - 2];
    }
    // cout<<t<<endl;
    vector<int> a;
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            a.push_back(i);
        }
    }
    if (a.size() >= 3)
    {
        cout << "NO" << endl;
        return;
    }
    else if (a.size() == 2)
    {
        r = a[1];
        l = a[0] + 1;
        for (int i = r; i >= l; i--)
        {
            if (s[i] == t[l + i - r])
            {
                cnt1++;
            }
            else
            {
                cnt2++;
            }
        }
        // cout<<cnt1<<" "<<cnt2<<endl;
        if (cnt2 == r - l + 1 || cnt1 == r - l + 1)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    else if (a.size() == 1)
    {
        if (a[0] == 0 || a[0] == 1 || a[0] == s.length() - 2 || a[0] == s.length() - 3)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
}
#undef int
int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        so();
    }
    return 0;
}