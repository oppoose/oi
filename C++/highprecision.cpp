#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a,b,s;
    cin>>a>>b;
    int a1[20005]={0},b1[20005]={0},c[40005]={0};
    size_t lena = a.size();
    size_t lenb = b.size();
    for(int i=0; i < lena; i++){
        a1[i] = a[lena-i-1]-'0';
    }
    for(int i=0; i < lenb; i++){
        b1[i] = b[lenb-i-1]-'0';
    }
    for(int i = 0; i < lena;i++){
        for(int j = 0; j<lenb; j++){
            c[i+j] += a1[i]*b1[j];
        }
    }
    for(int i = 0; i < lena+lenb;i++){
        if(c[i]>=10){
            c[i+1] += c[i]/10;
            c[i] %= 10;
        }
    }
    int len = lena + lenb;
    while (c[len-1] == 0 && len > 1)
        len--;
    s.resize(len);
    for(int i = 0;i <= len-1;i++){
        s[i] = c[len - 1 -i] + '0';
    }
    cout<<s;
    return 0;
}













/* 



string x, y;
int a[20005], b[20005], c[20005];

int main() {
  cin >> x >> y;
  int la = x.size();
  int lb = y.size();
  for (int i = 1; i <= la; i++) {
    a[i] = x[la-i] - '0';
  }
  for (int i = 1; i <= lb; i++) {
    b[i] = y[lb-i] - '0';
  }
  for (int i = 1; i <= la; i++) {
    for (int j = 1; j <= lb; j++) {
      c[i + j - 1] += a[i] * b[j];
    }
  }
  for (int i = 1; i < la + lb; i++) {
    if (c[i] > 9)
    	c[i + 1] += c[i] / 10, c[i] %= 10;
  }
  int len = la + lb;
  while (c[len] == 0 && len > 1)
    len--;
  while (len > 0)
    cout << c[len], len--;
  return 0;
}
 */