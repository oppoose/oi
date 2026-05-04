# C++ 编程基础与关键机制总结

## 一、基本语法与程序结构

### main 函数与返回值
```cpp
int main() {
    return 0;
}
```
所有 C++ 程序的入口函数为 `main`，返回值 0 表示程序正常结束。

### 输入输出流
```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
}
```
C++ 使用 `cin` 和 `cout` 进行标准输入输出（Standard Input/Output Stream）。

---

## 二、变量与数据类型

| 类型 | 英文关键字 | 占用字节（通常） | 范围 |
|------|-------------|------------------|-------|
| 整型 | `int` | 4 | -2³¹ ~ 2³¹-1 |
| 短整型 | `short` | 2 | -32768 ~ 32767 |
| 长整型 | `long` | 4或8 | 依平台而定 |
| 单精度浮点 | `float` | 4 | 约7位有效数字 |
| 双精度浮点 | `double` | 8 | 约15位有效数字 |
| 字符型 | `char` | 1 | ASCII字符 |
| 布尔型 | `bool` | 1 | true / false |

---

## 三、运算符与表达式

### 1. 赋值与复合赋值
`a += b` 等价于 `a = a + b`。

### 2. 自增与自减
`i++`（后缀）先使用后增加；`++i`（前缀）先增加后使用。

### 3. 逗号运算符
```cpp
int i;
i = (a = 2*3, a*5); // i = 30
```
逗号运算符会依次计算多个表达式，取最后一个值。

---

## 四、条件与循环控制

```cpp
if (a > b) cout << a;
else if (a == b) cout << "=";
else cout << b;
```

循环结构包括 `for`, `while`, `do...while`。
```cpp
for (int i = 0; i < n; ++i) sum += i;
```

`break` 跳出循环，`continue` 跳过本次循环。

---

## 五、数组与字符串

```cpp
int arr[5] = {1, 2, 3, 4, 5};
for (int i = 0; i < 5; i++) cout << arr[i] << " ";
```

字符串有两种：
1. C风格字符串：`char str[] = "Hello";`
2. C++风格字符串：`string s = "Hello";`

`string` 支持操作：`s.length()`, `s.substr()`, `s += "world"`。

---

## 六、函数与作用域

```cpp
int add(int a, int b) {
    return a + b;
}
```

函数原型可在前声明后定义。

变量作用域分为：
- 局部变量（函数内）
- 全局变量（函数外）
- 静态变量（`static`，函数间共享）

---

## 七、指针与引用

```cpp
int a = 10;
int *p = &a;
cout << *p; // 输出10
```

引用（reference）是变量别名：
```cpp
int a = 5;
int &b = a; // b是a的引用
b = 10; // a也变为10
```

---

## 八、结构体与枚举

```cpp
struct Student {
    string name;
    int age;
    double score;
};
Student s = {"Tom", 18, 95.5};
```

枚举类型：
```cpp
enum Color {RED, GREEN, BLUE};
Color c = GREEN;
```

---

## 九、STL 容器与迭代器

### vector（动态数组）
```cpp
#include <vector>
vector<int> v = {1,2,3};
v.push_back(4);
for (int x : v) cout << x << " ";
```

### 注意：
在遍历时若修改 `vector` 大小，会导致迭代器失效。

### 常见容器
- `vector`：动态数组
- `deque`：双端队列
- `set / multiset`：自动排序、去重集合
- `map / multimap`：键值映射
- `unordered_map`：哈希表映射

---

## 十、内存与引用机制

- 栈（Stack）：局部变量自动分配和释放。
- 堆（Heap）：动态内存 `new` / `delete`。
```cpp
int *p = new int(10);
delete p;
```

内存泄漏（Memory Leak）发生在 `new` 后未 `delete`。

---

## 十一、文件输入输出

```cpp
#include <fstream>
ifstream fin("in.txt");
ofstream fout("out.txt");
int x;
fin >> x;
fout << x;
```

---

## 十二、异常与断言

```cpp
try {
    if (b == 0) throw "Division by zero!";
    cout << a / b;
} catch (const char* msg) {
    cerr << msg;
}
```

`assert(x > 0);` 用于调试时验证条件。

---

## 十三、类与对象基础

```cpp
class Person {
public:
    string name;
    int age;

    void introduce() {
        cout << "I am " << name << ", age " << age << endl;
    }
};
Person p = {"Alice", 20};
p.introduce();
```

---

## 十四、构造函数与析构函数

```cpp
class A {
public:
    A() { cout << "构造"; }
    ~A() { cout << "析构"; }
};
```

析构函数自动调用，常用于释放资源。

---

## 十五、继承与多态

```cpp
class Animal {
public:
    virtual void speak() { cout << "Animal" << endl; }
};
class Dog : public Animal {
public:
    void speak() override { cout << "Woof" << endl; }
};
Animal *p = new Dog;
p->speak(); // 输出 Woof
```

`virtual` 关键字使得函数支持**运行时多态（runtime polymorphism）**。

---

## 十六、C++11/14/17 新特性要点

- `auto` 自动类型推断  
- `nullptr` 代替 `NULL`
- `range-based for`：`for (auto x : v)`  
- `lambda表达式`：
```cpp
auto add = [](int a, int b) { return a + b; };
cout << add(2,3);
```
- 智能指针：`shared_ptr`, `unique_ptr`, `weak_ptr`
