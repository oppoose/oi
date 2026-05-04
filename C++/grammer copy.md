# C++ 类型与引用、容器、数组总结

## 1. 变量初始化

```cpp
int t(0);  // 圆括号初始化
int t{0}; // 大括号初始化
int t(3.14);   // OK，圆括号允许类型转换
int t{3.14};   // X，大括号禁止窄化转换
string book("0-021");
extern int i;  // 外部变量声明
```

### 转义序列

* `\n`, `\t`, `\r`
* 十六进制：`\x4d`
* 八进制：`\115`

## 2. 引用

```cpp
int i = 0;
int &j = i; // j绑定i，类型必须一致
const int &cj = 1; // 常量引用可以绑定临时量
```

* 引用只能绑定同类型对象
* const引用可以绑定临时量

## 3. const修饰

```cpp
int const *p;  // 顶层const，指向的对象不可修改
int *const p;  // 底层const，指针本身不可修改
```

* 指针与const组合要注意位置
* `const int *p` 或 `int const *p` 等价

## 4. 类型别名

```cpp
typedef double base, *p;  // base=double, p=double*
using L = long long;
```

## 5. auto与decltype

```cpp
auto i = 1; // 自动推断类型
auto j = 8.8; // 单条语句只能有一个auto

const int i = 1, &j = i, *p = &i;
decltype(i) m = 1;   // m类型为const int
decltype(j) n;      // int &，未赋值错误
decltype(p) ptr = &m; // const int *
decltype(*p) j = m; // const int &
decltype((i)) d = m; // const int &
```

## 6. 字符串操作

```cpp
string s1;
string s2 = "hello";
string s3(s2); // 等价于 string s3 = s2;
string s4(5, 'c'); // ccccc
getline(cin, s);
while(getline(cin, s)) cout << s;
s.empty(); // 空返回true
s.size();  // 字符数，size_t类型
```

* 字符串可以相加，至少一个是string类型
* C字符串可以转换为string：`string(s1) + "?"`

## 7. 字符分类函数

| 函数           | 功能          | 示例               |
| ------------ | ----------- | ---------------- |
| isalnum(ch)  | 字母或数字       | 'A', '1' ✅ '?' ❌ |
| isalpha(ch)  | 字母          | 'B' ✅ '9' ❌      |
| iscntrl(ch)  | 控制字符        | '\n' ✅           |
| isdigit(ch)  | 数字          | '5' ✅            |
| isgraph(ch)  | 可打印字符（不含空格） | '!' ✅            |
| islower(ch)  | 小写字母        | 'a' ✅            |
| isprint(ch)  | 可打印字符（含空格）  | 'A', ' ' ✅       |
| ispunct(ch)  | 标点符号        | '!', ',' ✅       |
| isspace(ch)  | 空白符         | ' ', '\t' ✅      |
| isupper(ch)  | 大写字母        | 'A' ✅            |
| isxdigit(ch) | 十六进制字符      | 'A', 'f', '9' ✅  |

## 8. vector 容器

```cpp
vector<int> v1 = {10, 20, 30};
vector<vector<int>> ivec;
vector<string> v(10, "hello");
vector<int> v3(10); // 10个0
vector<string> v6(10); // 10个空字符串
```

* `v.empty()`, `v.size()`, `v.push_back(t)`, `v[n]`
* 范围for循环：`for(auto &s: line)`
* 迭代器：`vector<int>::iterator it`，`string::iterator it2`
* 修改容量可能使迭代器失效

## 9. 指针与数组

```cpp
int *ptr[10];     // 存放10个指针的数组
int (*p)[10];     // 指向数组的指针
int (&arrRef)[10] = arr; // 数组引用
```

* 多维数组指针：`int (*p)[2][2][2] = a;`
* 数组也有begin/end，返回指针

## 10. C字符串函数

```cpp
strlen(p);        // 长度
strcmp(a, b);     // 比较
strcat(p1, p2);   // 拼接
strcpy(p1, p2);   // 拷贝
```

* C++ string足够常用：`s.size()`, `s1 + s2`, `s1 = s2`
* C字符串可与C++ string兼容，至少一个是string类型

## 11. 数组与vector互转

```cpp
int arr[] = {0,1,2,3,4};
vector<int> ivec(begin(arr), end(arr));
```

* `begin(arr)`和`end(arr)`返回数组首尾指针

## 12. 循环访问vector

```cpp
auto pbeg = v.begin();
while(pbeg != v.end() && &*pbeg >= 0){
    cout << *pbeg++;
}
```
