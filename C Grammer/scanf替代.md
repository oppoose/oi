

---

# fgets 与 sscanf 用法解析

## 1. fgets：读取整行输入
```c
fgets(buf, sizeof(buf), stdin);
```

- **作用**：从标准输入读取一整行，直到遇到换行符 `\n` 或缓冲区满。
- **特点**：
  - 会保留空格和换行符。
  - 自动在末尾加上 `\0` 作为字符串结束符。
- **示例**：
```c
char buf[100];
fgets(buf, sizeof(buf), stdin);
// 输入: 123 456 789⏎
// buf 内容: "123 456 789\n\0"


```
- **注意事项**
  - `scanf`后面接`fgets`,`fgets`只能得到一个`'\n'`,应使用getchar吃掉换行符

---

## 2. sscanf：在字符串中解析数据
```c
sscanf(buf, "%d", &x);
```

- **作用**：把字符串 `buf` 当作输入流，按格式解析。
- **特点**：
  - 可以多次解析同一行。
  - 格式灵活，不会像 `scanf` 那样无限跳过空白。
- **示例**：
```c
char buf[100];
fgets(buf, sizeof(buf), stdin);
int x, y;
sscanf(buf, "%d %d", &x, &y);
// 输入: 12 34
// 输出: x = 12, y = 34
```

---

## 3. 两者结合的优势
- **优势 A**：避免 `scanf` 自动跳过空白导致的输入错乱。
- **优势 B**：适合处理复杂格式（如 `NAME=VALUE`）。
- **优势 C**：不会因为输入错误而卡死。

---

## 4. 示例程序

### 读取一行多个整数
```c
#include <stdio.h>

int main() {
    char buf[100];
    fgets(buf, sizeof(buf), stdin);
    int a, b, c;
    sscanf(buf, "%d %d %d", &a, &b, &c);
    printf("%d %d %d\n", a, b, c);
    return 0;
}
```
**输入：**
```
12 99 -3
```
**输出：**
```
12 99 -3
```

---

### 只读一行中的第一个整数
```c
char buf[100];
fgets(buf, sizeof(buf), stdin);
int x;
sscanf(buf, "%d", &x);
// 输入: 123 abc def
// 输出: x = 123
```

# 其他string函数及函数原型使用方法(不重复多来点)
- `strncpy`  用于字符串复制 函数原型为`char *strncpy(char *dest, const char *src, size_t n);`
- `strncat`  用于字符串连接 函数原型为`char *strncat(char *dest, const char *src, size_t n);`
- `strncmp`  用于字符串比较 函数原型为`int strncmp(const char *s1, const char *s2, size_t n);`
- `strchr`   用于查找字符 函数原型为`char *strchr(const char *s, int c);`
- `strstr`   用于查找子字符串 函数原型为`char *strstr(const char *haystack, const char *needle);`
- `strlen`   用于计算字符串长度 函数原型为`size_t strlen(const char *s);`
- `atoi`     用于字符串转整数 函数原型为`int atoi(const char *nptr);` 转整数的机理是:
  1. 跳过字符串开头的空白字符。
  2. 检查可选的正负号。
  3. 逐个处理数字字符，将其转换为整数值，直到遇到非数字字符为止。
- `atof`     用于字符串转浮点数 函数原型为`double atof(const char *nptr);`
- `strtok`   用于字符串分割 函数原型为`char *strtok(char *str, const char *delim);`
- `memset`   用于内存初始化 函数原型为`void *memset(void *s, int c, size_t n);`
- `memcpy`   用于内存复制 函数原型为`void *memcpy(void *dest, const void *src, size_t n);`
- `memcmp`   用于内存比较 函数原型为`int memcmp(const void *s1, const void *s2, size_t n);`   
  
  
  
- `sprintf`  用于格式化字符串 函数原型为`int sprintf(char *str, const char *format, ...);`
- `snprintf` 用于格式化字符串（带长度限制） 函数原型为`int snprintf(char *str, size_t size, const char *format, ...);`
- `vsprintf` 用于格式化字符串（可变参数） 函数原型为`int vsprintf(char *str, const char *format, va_list ap);`
- `vsnprintf`用于格式化字符串（可变参数，带长度限制） 函数原型为`int vsnprintf(char *str, size_t size, const char *format, va_list ap);`
-  `strrchr`  用于查找字符（从后往前） 函数原型为`char *strrchr(const char *s, int c);`
-  `strpbrk`  用于查找字符串中首次出现的指定字符 函数原型为`char *strpbrk(const char *s1, const char *s2);`
-  `strcspn`  用于计算字符串中不包含指定字符的长度 函数原型为`size_t strcspn(const char *s1, const char *s2);`
-  `strspn`   用于计算字符串中包含指定字符的长度 函数原型为`size_t strspn(const char *s1, const char *s2);`
-  `strdup`   用于复制字符串（动态分配内存） 函数原型为`char *strdup(const char *s);`
-  `strndup`  用于复制字符串（动态分配内存，带长度限制） 函数原型为`char *strndup(const char *s, size_t n);`
-  `memmove`  用于内存移动 函数原型为`void *memmove(void *dest, const void *src, size_t n);`
-  `strcoll`  用于字符串比较（考虑区域设置） 函数原型为`int strcoll(const char *s1, const char *s2);`
-  `strxfrm`  用于字符串转换（考虑区域设置） 函数原型为`size_t strxfrm(char *dest, const char *src, size_t n);`
