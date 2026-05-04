
C++在编译检查阶段会检查类型


#include <iostream>  
#include <string>  
#include <vector>  
#include <cstring>  
using std::cout;  
using std::cin;  
using std::string;  
using std::vector;  
using std::empty;  
using std::size;  
//初始化变量的方式可以使用{}()比如
int t(0);
int t{0};
//但是如果初始化的值类型不同只能用圆括号
int t(3.14);//√
int t{3.14};//X
string book("0-021")
extern int i;//这样的可以外部文件使用
//你也可以在声明变量后直接赋值，就会压缩为此变量类型
//转义序列\n,\t,\r之类，还有\+数字类型的
//比如\x4d  \115  \xXXX (X代表十六进制数字，而115代表八进制数字)


//引用是什么？？
int i = 0;
int &j = i;
//当你这样写的时候i，j就只有名字上的区别，类型必须相同除非const
//当然 如果你int &j = 1;这种常量也是会报错的(首先就没什么意义)
//但你可以const int &j = 1;这是可以的 
/*     
    int i = 0;
    const int &j = i;
    i += 1; 这样的j就是1，可以这么理解
    j的const对象是i，i是谁j就是谁，，
    但是如果const j = 1;你就不能引用i去修改j(报错)
*/
//临时量是编译器暂存表达式求值结果时临时创建的无名变量
//如果进行
//double dval = 3.14
//const int &ri = dval;  此时ri绑定的就是一个临时量
//相当于const int temp = dval; const int &ri = dval;
//C++只允许const引用绑定临时量，去掉无法修改另一个类型的变量(因为绑定的是临时量)所以编译器报错
//这也解释了为什么引用只能绑定同类型
int const *p;//和const int *p等价，这个叫顶层const
int *const p;//区别在于上面是指向常量不可变,不可以通过指针修改，这个叫底层const
            //下面是指向对象不可变
//C++中NULL替换为nullptr，int *p=0;也可以起到空指针的作用


// int a = 0;
// const int *p = &a;
// *p = 1; X 
//  a = 1; √
//你不能通过const int的对象去改值，无论是引用还是指针


typedef double base,*p;//base与double同义，p与double*同义;
using L = long long;//L和longlong同义


auto i=1,j=8.8;//X 一个auto语句只能判断一个auto类型
//auto只会保留底层const



//指针指向对象类型要一致


//decltype用法
const int i = 1,&j = 1,*p = &i;
decltype(i) m =1;//m的数据类型是const int(与i相同)值为1
decltype(j) n;//n的类型是int &，但是没有赋值，错误
//和日常指针使用不一样的是
decltype(p) ptr = &m;//这样写就是指针const int *
decltype(*p) j = &pl;//这样的j是const int&
decltype((i)) d = m;//这样写和引用是一样的,decltype((i)) 永远是引用类型

//is(input stream)输入流os(output stream)输出流 IO就是输入输出
string s1;//空字符串
string s2 = "hello";//赋值
string s3(s2);//这种写法等价于string s3 = s2;
string s4(5,'c');//s4内容是ccccc
getline(cin,s);//读取一整行输入赋给s

while(getline(cin,s))
    cout << line;
s.empty();//空则返回true，否则返回false
s.size();//s里有多少个字符，这个类型是size_t 相当于unsigned int
//string类型可以直接相加但是必须是string类型(至少有一个是)，如果直接的字面值字符串是不能定义相加的
string s1 = "gunmu";
string s2 = "otto";
string s3 = s1+s2;//gunmuotto
string s4 = s1+"wcsndm"+"csndm";//这也是可以的至少得有一个string类型
/* 但是 */string gm = "wcsndm"+"csndm"+s1;//这就是不合法的
//因为前两字符串相加没有string对象所以识别为两个字面值相加，所以必须在前两中有一个string类型
//string类型和字面值的字符串不相同，字面值是const char[]类型的数组，在赋值操作的时候
//C++会自动的将const char[]类型转化为string类型
for(auto s: line)//对于每个在line中的s(单个字符)，循环到line结束
    if(ispunct(s)){
        cout<<s;
    }
//如果涉及到写入的操作那么应该写
for(auto &s:line);

/* 
isalnum(ch)	是否是字母或数字	'A', '1' ✅ '?' ❌
isalpha(ch)	是否是字母（A-Z 或 a-z）	'B' ✅ '9' ❌
iscntrl(ch)	是否是控制字符（ASCII 0–31, 127）	'\n', '\t' ✅
isdigit(ch)	是否是数字字符（0–9）	'5' ✅ 'A' ❌
isgraph(ch)	是否是可打印字符（不含空格）	'!', 'A' ✅ ' ' ❌
islower(ch)	是否是小写字母	'a' ✅ 'A' ❌
isprint(ch)	是否是可打印字符（含空格）	'A', ' ' ✅
ispunct(ch)	是否是标点符号字符	'!', ',' ✅ 'A' ❌
isspace(ch)	是否是空白符	' ', '\t', '\n' ✅
isupper(ch)	是否是大写字母	'A' ✅ 'a' ❌
isxdigit(ch)	是否是十六进制数字（0-9, a-f, A-F）	'A', 'f', '9' ✅ */


vector<int> v1={10,20,30};//vector相当于一个可变长的数组你往里面放多少都不会越界，这相当于
//v1放了10 20 30 也可以直接vector<int> v1{10,20,30}
vector<vector<int>> ivec;//vector容器里面即可以放各种类型包括vector容器
vector<string> v(10,"hello");//放了十个hello
vector<int> v3(10);//这是初始化了十个0
vector<string> v6(10);//初始化了十个空string

//vector有许多的容器操作比如
v.std::empty();
v.size();
v.pushback{t};//向后加元素
v[n]; //返回第n+1个元素的引用
v1 = v2;//赋值
v1 == v2;//每个元素且元素个数都相同

//vector不能用数组下标去添加元素
//只能用push_back(x)把这个x元素加到数列尾部

v.std::begin();//迭代器
v.std::end();//这些都是在返回一个迭代器
//迭代器是什么？总的来说迭代器就是一个更安全的访问容器的指针

auto i = v.begin();
*i = 100;//*i返回一个指向元素的引用,可以进行读写操作

++i;//i指向下一个元素
--i;//i指向下一个元素
iter != yter;//判断指向元素相同吗

vector<int>::iterator it;//it只能读写vector<int>中的元素
string::iterator it2;//it2只能读写string对象中的字符    

//在范围for循环里，不能向vector里添加元素   还有如果进行了改变vector容量的操作都会使得迭代器失效
vector<int>::const_iterator it;//it只能读不能写vector<int>中的元素
string::const_iterator it2;//it2只能读不能写string对象中的字符

//iterator比较像指针里面的*，他能访问一个容器里面的元素

const vector<int> it1;
auto iy = it1.begin();//iy的数据类型就是vector<int>::const_iterator
auto ix = it.begin();//类型就是vector<int>::const_iterator

//ix iy类型就是vector<int>，它们准确来说像是int* 如果要计算除法会向下取整
——————————————
int *ptr[10];//存放十个指针的数组
int (*p)[10] = a;//这才是指向a数组的指针
int &ref[10];//X 没有引用数组
int (*Parray)[10] = &arr;//parray指向的一个十元arr数组(这什么几把语法太罕见了)
int (&arrRef)[10] = arr;//arrRef引用一个含有十个类型的数组
//这相当于a指向arr[0];
int *a = arr;
——————————————
int arr[]={1};
auto a2 = arr;
auto a2(arr);
auto a2(&arr[0]);
auto a2 = &arr[0];//这几种种写法一样，都是指向第一个元素，自动给你赋为int *

decltype(arr) b = {0,2,1}//arr是int[]类型

//数组也有begin和end,他们都返回指针
int *be = begin(ia);
int *en = end(is);

//多维数组

int a[2][2][2][2]={{{{1,1},{1,1}},{{1,1},{1,1}}},{{{1,1},{1,1}},{{1,1},{1,1}}}};

int (*p)[2][2][2]= a;

//p->a[0][1][1][1];(p+1)->a[1][1][1][1]

//不存在int (*p)[2]= a;的这种情况因为int a[2][2][2][2]本质上a的类型是int [2][2][2];
//所以p+2 P+3会报错，溢出为a[2+x][1][1][1]
//所以只能int (*p)[2][2][2]
//但是如果int *p = a;那a可能会进行隐式的转换p->a[0][0][0][0]
int *p = &a[0][0][0][0];


//数组下标和指针本质上可以干同样的工作

//三个C的函数
strlen(p);//获取长度
strcmp(a,b);//比较字典序
strcat(p1,p2);//把p2加到p1返回p1
strcpy(p1,p2);//那p2拷贝给p1，返回p1
//string字符串可以和C的字符串兼容吗，比如char s1[] 是否能string s = s1 +“?”；

//可以使用C++的转换
string(const char* s);//可以读取s里面的'\0'


char s1[] = "abc";
std::string s = std::string(s1) + "?";
//但是没有必要 C++以下string函数已经足够有用
//s.size()、s1 == s2、s1 + s2、s1 = s2。

//C++提供了与C的接口
//1.任何以'\0'结尾的都可以被string初始化像上面一样
//2.string加法运算允许使用C的字符数组作为其中一个运算对象(还是要有一个string)
//任何字符数组都可以被当作string的右值





//数组可以初始化vector,但是vector不能初始化数组

int arr = {0,1,2,3,4};
vector<int> ivec(begin(arr),end(arr));//这相当于拷贝从arr的头拷贝到尾
(arr, arr+2)//括号里面可以填第一个到最后一个元素的指针 

//size_t一般是数组下标索引的类型一般是非负的数比int大

auto pbeg = v.begin();
whlie(pebg!=v.end() && &beg>=0){
    cout<<*pbeg++;//先p++后返回p的值再与*结合,p不断地++
}







