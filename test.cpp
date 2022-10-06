#include<iostream>
#include<vector>
#include<array>
#include<queue>
#include<deque>
#include<algorithm>
#include<map>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<stdio.h>
#include<time.h>
#include<string>
#include<sstream>
#include<fstream>
#include<unordered_map>
#include<stack>
#include<numeric>
#include<tuple>
#include <assert.h>
#include<time.h>
#include<Windows.h>
#include <functional>
#include <assert.h>
#include<thread>
#include<mutex>
#include<forward_list>
#include <iomanip> // 包含头文件
//#include "Sales_data.h"
using namespace std;
#define MOD 1000000007
struct TreeNode {//树节点
    int val;
    TreeNode* left, * right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* p, TreeNode* q) : val(x), left(p), right(q) {}
};
struct ListNode {//链表节点
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/////////////////////////////////////////// 打印一个int的二进制表示////////////////////////////////////////

void binary_print(const int& v)
{
    int i;
    int bit;
    int size = sizeof(v) * 8;
    //这里的size是输入参数v的位数，直接用32代替也可以，但写成sizeof(v)*8这样更为通用。
    for (i = 0; i < size; i++)
    {
        bit = v & (1 << (size - i - 1));//提取出第i位的值
        if (bit == 0) cout << 0;
        else cout << 1;
        if (i % 4 == 3)cout << ' '; //为了方便阅读输出，在每输出四位后加一个空格
    }
    cout << endl;
}
void binary_print(const unsigned int& v)
{
    int i;
    int bit;
    int size = sizeof(v) * 8;
    //这里的size是输入参数v的位数，直接用32代替也可以，但写成sizeof(v)*8这样更为通用。
    for (i = 0; i < size; i++)
    {
        bit = v & (1 << (size - i - 1));//提取出第i位的值
        if (bit == 0) cout << 0;
        else cout << 1;
        if (i % 4 == 3)cout << ' '; //为了方便阅读输出，在每输出四位后加一个空格
    }
    cout << endl;
}
void binary_print(const long long& v)
{
    long long i;
    long long bit;
    long long size = sizeof(v) * 8;
    //这里的size是输入参数v的位数，直接用32代替也可以，但写成sizeof(v)*8这样更为通用。
    for (i = 0; i < size; i++)
    {
        bit = v & (1ll << (long long)(size - i - 1ll));//提取出第i位的值
        if (bit == 0) cout << 0;
        else cout << 1;
        if (i % 4 == 3)cout << ' '; //为了方便阅读输出，在每输出四位后加一个空格
    }
    cout << endl;
}
///////////////////////////////////////////辗转相除法求最大公约数//////////////////////////////////////////////////////
template<typename T>
T m_gcd(T a, T b)
{
    if (a % b == 0)
    {
        return b;
    }
    return m_gcd(b, a % b);
}
///////////////////////////////////////////辗转相除法求最小公倍数//////////////////////////////////////////////////////
template<typename T>
T m_lcm(T a, T b)
{
    return (a * b) / m_gcd(b, a % b);
}
///////////////////////////////////////////静态函数访问静态成员///////////////////////////////////////////////////////

//class Student {
//public:
//    Student(const char* name, int age, float score);
//    void show();
//public:  //声明静态成员函数
//    static int getTotal();
//    static float getPoints();
//private:
//    static int m_total;  //总人数
//    static float m_points;  //总成绩
//private:
//    const char* m_name;
//    int m_age;
//    float m_score;
//};
//
//int Student::m_total = 0;
//float Student::m_points = 0.0;
//
//Student::Student(const char* name, int age, float score) : m_name(name), m_age(age), m_score(score) {
//    m_total++;
//    m_points += score;
//}
//void Student::show() {
//    cout << m_name << "的年龄是" << m_age << "，成绩是" << m_score << endl;
//}
////定义静态成员函数
//int Student::getTotal() {
//    return m_total;
//}
//float Student::getPoints() {
//    return m_points;
//}
//
//int main() {
//    Student a("小明", 15, 90.6);
//    a.show();
//    Student b("李磊", 16, 80.5);
//    b.show();
//    Student c("张华", 16, 99.0);
//    c.show();
//    Student d("王康", 14, 60.8);
//    d.show();
//    int total = a.getTotal();
//    float points = b.getPoints();
//    cout << "当前共有" << total << "名学生，总成绩是" << points << "，平均分是" << points / total << endl;
//    system("pause");
//    return 0;
//}


///////////////////////////////////////////切牌魔术///////////////////////////////////////////////////////

//int main()
//{
//    int N, M;
//    cin >> N >> M;
//
//    vector<int>v1(N);
//    for (int i = 0;i < N;i++)
//    {
//        cin >> v1[i];
//    }
//
//
//    if (N % 2 == 0)
//    {
//        while (M--)
//        {
//            vector<int>v2(v1.begin(), v1.begin() + N / 2);  //vector.begin()和vector.end()这些都代表的是迭代器，不能用指针和这些做操作，必须用迭代器iterator
//            vector<int>v3(v1.begin() + N / 2, v1.begin() + N);
//            v1.clear();
//            for (int i = 0;i < N / 2;i++)
//            {
//
//
//                v1.push_back(v3[i]);
//                v1.push_back(v2[i]);
//            }
//        }
//    }
//    else
//    {
//        while (M--)
//        {
//            vector<int>v2(v1.begin(), v1.begin() + (N - 1) / 2);
//            vector<int>v3(v1.begin() + (N - 1) / 2, v1.begin() + N);
//            v1.clear();
//            for (int i = 0;i < (N - 1) / 2;i++)
//            {
//
//                v1.push_back(v3[i]);
//                v1.push_back(v2[i]);
//            }
//
//            v1.push_back(v3[v3.size() - 1]);
//
//        }
//
//    }
//
//
//    for (int i = 0;i < N;i++)
//    {
//        cout << v1[i] << " ";
//    }
//    system("pause");
//    return 0;
//}

///////////////////////////////////////////友元函数///////////////////////////////////////////////////////

//class Address;  //提前声明Address类,如果不提前声明，student里面的Address就无法识别
////声明Student类
//class Student {
//public:
//    Student(char* name, int age, float score);
//public:
//    void show(Address* addr);
//private:
//    char* m_name;
//    int m_age;
//    float m_score;
//};
//
////声明Address类
//class Address {
//private:
//    string m_province;  //省份
//    string m_city;  //城市
//    string m_district;  //区（市区）
//public:
//    Address(string province, string city, string district);
//    //将Student类中的成员函数show()声明为友元函数
//    friend void Student::show(Address* addr);
//};
//
////实现Student类
//Student::Student(char* name, int age, float score) : m_name(name), m_age(age), m_score(score) { }
//void Student::show(Address* addr) {
//    cout << m_name << "的年龄是 " << m_age << "，成绩是 " << m_score << endl;
//    cout << "家庭住址：" << addr->m_province << "省" << addr->m_city << "市" << addr->m_district << "区" << endl;
//}
//
////实现Address类
//Address::Address(string province, string city, string district) {
//    m_province = province;
//    m_city = city;
//    m_district = district;
//}
//
//int main() {
//    Student stu("张三", 16, 95.5f);
//    Address addr("陕西", "西安", "雁塔");
//    stu.show(&addr);//取地址，因为形参是地址
//
//    Student* pstu = new Student("李磊", 16, 80.5);
//    Address* paddr = new Address("河北", "衡水", "桃城");
//    pstu->show(paddr);
//    return 0;
//}

///////////////////////////////////////////////单双引号的区别///////////////////////////////////////////////////////

//int main()
//{
//    string str = "abcde";
//    int i = 0;
//    while (str[i] != '\0')
//    {
//        if (str[i] == 'c')
//            cout << "True" << endl;
//        else
//            cout << "False" << endl;
//        i++;
//    }
//    cout << '\'' << "'" << 'abc' <<"abcde"<< endl;//\'才表示'字符，如果这里是'abc'就会输出奇怪的数
//    return 0;
//}

///////////////////////////////////////////////时间函数///////////////////////////////////////////////////////

//int main()
//{
//    time_t timer;
//    struct tm y2k = { 0 };
//    double seconds;
//
//    y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
//    y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;//此时y2k表示的是2000年1月1日00:00:00
//
//    time(&timer);  /* get current time; same as: timer = time(NULL)  */
//
//    seconds = difftime(timer, mktime(&y2k));
//
//    printf("%.f seconds since January 1, 2000 in the current timezone", seconds);
//    return 0;
//}

///////////////////////////////////////////////Struct和Class的区别///////////////////////////////////////////////////////

//struct Student {
//    string m_name;
//    int m_age;
//    float m_score;
//public:
//    void show();
//    Student(string name, int age, float score) : m_name(name), m_age(age), m_score(score) {}
//};
//void Student::show() {
//    cout << m_name << "的年龄是" << m_age << "，成绩是" << m_score << endl;
//}
//int main() {
//    Student stu((char*)"小明", 15, 92.5f);
//    stu.show();
//    cout << stu.m_age << endl;//这里如果是class就会报错，因此class如果不说明继承权限的话默认为private，private不能通过对象访问
//    Student* pstu = new Student("李华", 16, 96);
//    pstu->show();
//    cout<<pstu->m_age<<endl;
//    return 0;
//}

//////////////////////////////////////////////虚继承///////////////////////////////////////////////////////

//class A {
//public:
//    A(string s)
//    {
//        cout << s << endl;
//    }
//    ~A() {
//        cout << "delete A" << endl;
//    }
//};
//class B :virtual public A
//{
//public:
//    B(string s1, string s2) :A(s1) {
//        cout << s2 << endl;
//    }
//    ~B() {
//        cout << "delete B" << endl;
//    }
//};
//class C :virtual public A
//{
//public:
//    C(string s1, string s2) :A(s1) {
//        cout << s2 << endl;
//    }
//    ~C() {
//        cout << "delete C" << endl;
//    }
//};
//class D :public C, public B//构造的时候先继承哪个，哪个就先被构造出来，析构的时候正好相反
//{
//public:
//    D(string s1, string s2, string s3, string s4) :B(s1, s2), C(s1, s3), A(s1)//不管是构造还是析构，顺序都跟这里的传参顺序无关
//    {
//        cout << s4 << endl;
//    }
//    ~D() {
//        cout << "delete D" << endl;
//    }
//};
//int main() {
//    D* p = new D("class A", "class B", "class C", "class D");
//
//    delete p;
//    return 0;
//}

//////////////////////////////////////////////多个指针指向同一区域///////////////////////////////////////////////////////

//int add(int* x, int* y, int* z) {
//    *x += *x;
//    *y += *x;
//    *z += *y;
//    return *z;
//}
//void main()
//{
//    //划分三块内存区域
//    int a = 1, b = 1, c = 1;
//    //注意经过一次add()之后，a，b，c的值有可能发生改变，注意值要归1
//    printf("指向同一内存区域%d\n", add(&a, &a, &a));
//    a = 1, b = 1, c = 1;
//    printf("指向不同内存区域%d\n", add(&a, &b, &c));
//    a = 1, b = 1, c = 1;
//    printf("x.y指向同一内存区域%d\n", add(&a, &a, &b));
//    a = 1, b = 1, c = 1;
//    printf("x.z指向同一内存区域%d\n", add(&a, &c, &a));
//    a = 1, b = 1, c = 1;
//    printf("y.z指向同一内存区域%d\n", add(&a, &c, &c));
//    getchar();
//}

//////////////////////////////////////////////查询或更新成绩///////////////////////////////////////////////////////

//int funmax(vector<int> v)
//{
//    int a;
//    sort(v.begin(), v.end());
//    a = v[v.size() - 1];
//    return a;
//}
//int main()
//{
//    int M, N;
//    char ch;
//    int x, y;
//    cout << "输入学生个数和操作数：" << endl;
//    cin >> M >> N;
//    vector<int> v1(M);
//    for (int i = 0;i < M;i++)
//    {
//        cout << "输入学生成绩：" << endl;
//        cin >> v1[i];
//    }
//    for (int i = 0;i < N;i++)
//    {
//        cout << "输入操作：" << endl;
//        cin >> ch;
//        if (ch == 'Q')
//        {
//            cout << "输入需要查询的学生序号区间：" << endl;
//            cin >> x >> y;
//            int max;
//            vector<int>v2;
//            for (int i = x;i <= y;i++)
//                v2.push_back(v1[i - 1]);
//            max = funmax(v2);
//            cout << "此区间学生的最高成绩为：" << max << endl;
//        }
//        if (ch == 'U')
//        {
//            cout << "输入更新成绩的学生序号和新成绩：" << endl;
//            int x1, y1;
//            cin >> x1 >> y1;
//            v1[x1 - 1] = y1;
//            for (int i = 0;i < M;i++)
//            {
//                cout << v1[i]<< endl;
//            }
//        }
//    }
//}

//////////////////////////////////////////////动态规划（有障碍）///////////////////////////////////////////////////////

//int main()
//{
//    const int m1 = 3;
//    const int n1 = 3;
//    int a[m1][n1];  //直接定义二维数组，注意行列数一定要用常量表达式const，否则报错
//    vector<vector<int>> obstacleGrid(3, vector<int>(3));
//    int m = obstacleGrid.size();
//    int n = obstacleGrid[0].size();
//    vector<vector<int>> dp(m, vector<int>(n));  //用vector表示二维数组
//    for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;//左边界
//    for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;//上边界
//    for (int i = 1; i < m; i++) {
//        for (int j = 1; j < n; j++) {
//            if (obstacleGrid[i][j] == 1) continue;
//            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//        }
//    }
//    return dp[m - 1][n - 1];
//}

//////////////////////////////////////////////前缀树查找一组数中两两异或最大值///////////////////////////////////////////////////////

//class Trie
//{
//private:
//    Trie* next[2] = { nullptr };  //Trie类指针数组，表示这个数组内存放着两个Trie类指针，每个Trie类指针都指向其中一个孩子节点（node）
//public:
//    Trie() {}  //构造函数与类同名，这里没有初始化变量
//
//    void insert(int x)  // 在前缀树中插入值x
//    {
//        Trie* root = this;
//        // 高位存储来Trie的前面，所以我们从左向右存储
//        for (int i = 30;i >= 0;i--)//这里i从30开始，因为x默认是正数，符号位是0，只有后面31位表示数值，因此只需要移动30次就能得到
//                                   //数值位的第一位，从31开始也是一样的（因为x是正数）
//        {
//            // 取第i位的数字，30...0
//            int u = x >> i & 1;  // >>是右移运算符，将x的二进制表示右移再与1相与
//            // 若第u位为空，则创建一个新节点，然后root移动到下一个节点
//            if (!root->next[u])
//                root->next[u] = new Trie();
//            root = root->next[u];
//        }
//    }
//    void printThis() {
//        cout << this << endl;//this 只能在成员函数内部使用
//    }
//    int srearch(int x)  // 在前缀树中寻找 x 的最大异或值
//    {
//        Trie* root = this;
//        // res表示已插入的数中可以与x相乘得到最大异或值的值，不是最大异或值，所以最后要用res^x，每次res*2表示左移一位，31循环后左移了31位了，
//        // +u和+！u表示加上res的当前位，0存在就加0,1存在就加1，优先加！u，因为该位相反才取最大值
//        int res = 0;
//        for (int i = 30;i >= 0;i--)//这里i从30开始，因为x默认是正数，符号位是0，只有后面31位表示数值，因此只需要移动30次就能得到
//                                   //数值位的第一位，从31开始也是一样的（因为x是正数）
//        {
//            int u = x >> i & 1;
//            // 如果相反的孩子节点存在，我们走到相反的方向去，因为异或总是该位相反才取最大值的
//            if (root->next[!u])
//                root = root->next[!u],res = res * 2 + !u;  //每往下走一层，原来的结果就要乘以2，因为二进制左移一位相当于十进制乘以2
//                                                           //u和！u只能取0和1
//            else  // 相反方向的节点为空，只能顺着相同方向走了
//                root = root->next[u], res = res * 2 + u;
//        }
//        // 上面得到的是另一个数组元素，此时我们需要将这个数组元素与x想异或，才能得到在所有数中与x相异或的最大值
//        res ^= x;
//        return res;
//    }
//};
//int main()
//{
//    int nums[] = { 3, 5, 2, 8 };
//    Trie* root = new Trie();
//    cout << root << endl;
//    root->printThis();//this指向当前对象，通过它可以访问当前对象的所有成员,也就是说this=root，对于不同的对象，this 的值也不一样
//    for (auto x : nums)
//        root->insert(x);
//    int res = 0;
//    for (auto x : nums)
//        res = max(res, root->srearch(x));  //把最大的异或值存入res
//    cout << res << endl;
//}

//////////////////////////////////////////////前缀树查找一组数中两两异或结果在某个范围内的个数///////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/count-pairs-with-xor-in-a-range/solution/python3-01-trieshu-by-yim-6-7cb7/
//class TrieNode {
//public:
//    int count;
//    TrieNode* children[2];
//    TrieNode() :count(0) {
//        children[0] = nullptr;
//        children[1] = nullptr;
//    }
//};
//class Solution {
//public:
//    int countPairs(vector<int>& nums, int low, int high) {
//        int res = 0;
//        TrieNode* root = new TrieNode();//root是根节点，是所有数字的祖先，它不参与计算
//        for (int num : nums) {
//            res += smaller(num, high + 1, root) - smaller(num, low, root);
//            insert(root, num);
//        }
//        return res;
//    }
//    void insert(TrieNode* root, int num) {
//        TrieNode* node = root;
//        for (int i = 3; i >= 0; i--) {
//            int index = ((num >> i) & 1);
//            if (node->children[index] == nullptr) {
//                node->children[index] = new TrieNode();
//            }
//            node = node->children[index];
//            node->count++;  //count表示从此结点往下能找到的已插入的数的个数，比如2和3前30位的结点都是相同的，那么这30位的count就等于2
//        }
//    }
//    int smaller(int num, int high, TrieNode* node) {
//        int count = 0;
//        for (int i = 3; i >= 0; i--) {  
//            int border = ((high >> i) & 1);  //边界在这一层树的值，0或1
//            int index = ((num >> i) & 1);  //所要查询的数在这一层树的值
//            if (border == 1) {  //边界这一层为1，那么e2_i=e1_i的所有数字都满足,e1就是要查询的值，e2是已经插入的值
//                                  //(相同值异或为0，一定小于1，高位小于那么整体一定小于)，
//                                  //即与当前结点代表的值相同的那个儿子节点下面的数字都满足，所以把这些数字个数加入结果;
//                                  //对于另一个儿子结点，如果存在的话就继续往下找，不存在的话就退出；
//                if (node->children[index] != nullptr) {
//                    count += node->children[index]->count;
//                }
//                if (node->children[1 - index] != nullptr) {
//                    node = node->children[1 - index];
//                }
//                else
//               //另外一个分支不存在，说明已存储的树里面这一层只有一个分支，而这个分支第一个if已经统计过了，所以没路走了，退出
//                    break;
//            }
//            else {//边界这一层为0，那么e2_i！=e1_i(不同值异或为1，一定大于0，高位大于那么整体一定大于)
//                  //的所有数字都不满足条件，舍弃这一条支路，对于e2_i=e1_i的支路，还需要低位再做判断
//                if (node->children[index] != nullptr) {
//                    node = node->children[index];
//                }
//                else//满足条件的分支不存在，不满足条件的分支即使存在也不能走，所以没路了，退出。
//                    break;
//            }
//        }
//        return count;
//    }
//};
//int main()
//{
//    Solution so;
//    vector<int> nums = { 1,4,2,7 };
//    int low=2, high=6;
//    int result;
//    result = so.countPairs(nums, low, high);
//    cout << result << endl;
//}

//////////////////////////////////////////////根据身高排队///////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/queue-reconstruction-by-height/solution/xian-pai-xu-zai-cha-dui-dong-hua-yan-shi-suan-fa-g/
//bool cmp(const vector<int>& a, const vector<int>& b)
//{
//    return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
//}
//
//int main()
//{
//    vector<vector<int>> people = { {7, 0},{7, 1},{6, 1},{5, 0},{5, 2},{4, 4} };
//    sort(people.begin(), people.end(),cmp);//先插入个子高的，再插入个子低的，这样对个子高的人不造成影响
//    vector<vector<int>> ans;
//    for (const vector<int>& person : people) {
//        ans.insert(ans.begin() + person[1], person);
//    }
//    for (int i = 0;i < 6;i++)
//    {
//        for (int j = 0;j < 2;j++)
//        {
//            cout << ans[i][j]<<" ";
//        }
//    }
//    cout << endl << "如果上一行不方便换行，可以在这一行的输出开始前换行" << endl;
//    return 0;
//}

//////////////////////////////////////////////最长回文///////////////////////////////////////////////////////

//int main()
//{
//    string s = "baabd";
//    int n = s.length();
//    if (n < 2) {
//        cout<<s<<endl;
//    }
//
//    int maxLen = 1;
//    int begin = 0;
//    // dp[i][j] 表示 s[i..j] 是否是回文串
//    vector<vector<int>> dp(n, vector<int>(n));
//    // 初始化：所有长度为 1 的子串都是回文串
//    for (int i = 0; i < n; i++) {
//        dp[i][i] = true;
//    }
//    // 递推开始
//    // 先枚举子串长度
//    for (int L = 2; L <= n; L++) {
//        // 枚举左边界，左边界的上限设置可以宽松一些
//        for (int i = 0; i < n; i++) {
//            // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
//            int j = L + i - 1;
//            // 如果右边界越界，就可以退出当前循环
//            if (j >= n) {
//                break;
//            }
//
//            if (s[i] != s[j]) {
//                dp[i][j] = false;
//            }
//            else {//这里保证了s[i] = s[j]
//                if (L<4) {//这里保证了长度是2或者3,
//                    dp[i][j] = true;//上述两个条件保证了长度为2或3的最外面字符相同的字串一定为回文
//                }
//                else {
//                    dp[i][j] = dp[i + 1][j - 1];//当最外面字符相同，但是长度大于3的时候，还要考虑中间的字串是否是回文
//                }
//            }
//            // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
//            if (dp[i][j] && L > maxLen) {
//                maxLen = j - i + 1;
//                begin = i;
//            }
//        }
//    }
//    cout<<s.substr(begin, maxLen)<<endl;
//    return 0;
//}

//////////////////////////////////////////////括号匹配///////////////////////////////////////////////////////

//int main()
//{
//    string s = "{[]()[]}";
//    int n = s.size();
//    if (n % 2 == 1) {
//        cout<<"false"<<endl;
//    }
//    unordered_map<char, char> pairs = {
//        {')', '('},
//        {']', '['},
//        {'}', '{'}
//    };
//    stack<char> stk;
//    for (char ch : s) {
//        if (pairs.count(ch)) {
//            if (stk.empty() || stk.top() != pairs[ch]) {
//                cout << "false" << endl;
//            }
//            stk.pop();
//        }
//        else {
//            stk.push(ch);
//        }
//    }
//    cout << stk.empty() << endl;
//}

//////////////////////////////////////////////多重继承的继承顺序问题（包括虚继承）///////////////////////////////////////////////////////

//https://www.cnblogs.com/GyForever1004/p/8439397.html
//1.执行虚基类的构造函数，多个虚基类的构造函数按照被继承的顺序构造；
//2.执行基类的构造函数，多个基类的构造函数按照被继承的顺序构造；
//3.执行成员对象的构造函数，多个成员对象的构造函数按照声明的顺序构造；
//4.执行派生类自己的构造函数；
//5.析构以与构造相反的顺序执行；
//class Base {
//public:
//	Base() {
//		cout << "The constructor of Base" << endl;
//	}
//};
//class Base1 {
//public:
//	Base1() {
//		cout << "The constructor of Base1" << endl;
//	}
//};
//
//class VBase {
//public:
//	VBase() {
//		cout << "The constructor of VBase" << endl;
//	}
//};
//
//class VBase_ {
//public:
//	VBase_() {
//		cout << "The constructor of VBase_" << endl;
//	}
//};
//
//class A :public Base1, public Base, virtual public VBase_, virtual public VBase {  ///* 普通继承与虚继承 */
//public:
//	A() {
//		cout << "The constructor of A" << endl;
//	}
//};
//
//class B {
//public:
//	B() {
//		cout << "The constructor of B" << endl;
//	}
//};
//
//class D {
//public:
//	D() {
//		cout << "The constructor of D" << endl;
//	}
//};
//
//class C : public B, public A {//这里先执行了A的VBase_和VBase构造，因为他们是虚继承并且VBase_继承在VBase前面，符合1；然后剩下的都是实继承
//							//按照声明顺序来，B在A前面继承，所以B构造，A里面又继承了Base1和Base（Base1在Base前面继承）所以后面是Base1构造和
//							//Base构造。然后才是A构造，符合2；然后是成员对象D构造，符合3，然后才是本身构造C，符合4
//public:
//	C() {
//		cout << "The constructor of C" << endl;
//	}
//
//private:
//	/* 对象成员 */
//	D obj;
//};
//
//int main()
//{
//	/* 实例化类 C */
//	C test = C();
//	return 0;
//}

//////////////////////////////////////////////Vector的遍历方法///////////////////////////////////////////////////////

//int main()
//{
//    vector<int> v{ 1,2,3,4,5,6,7,8,9,10 }; //v被初始化成有10个元素
//    cout << "第一种遍历方法：" << endl;
//    //size返回元素个数
//    for (int i = 0; i < v.size(); i++)
//        cout << v[i] << " "; //像普通数组一样使用vector容器
//    //创建一个正向迭代器，当然，vector也支持其他 3 种定义迭代器的方式
//
//    cout << endl << "第二种遍历方法：" << endl;
//    vector<int>::iterator i;
//    //用 != 比较两个迭代器
//    for (i = v.begin(); i != v.end(); ++i)
//        cout << *i << " ";
//
//    cout << endl << "第三种遍历方法：" << endl;
//    for (i = v.begin(); i < v.end(); ++i) //用 < 比较两个迭代器
//        cout << *i << " ";
//
//    cout << endl << "第四种遍历方法：" << endl;
//    i = v.begin();
//    while (i < v.end()) { //间隔一个输出
//        cout << *i << " ";
//        i += 2; // 随机访问迭代器支持 "+= 整数"  的操作
//    }
//    return 0;
//}

//////////////////////////////////////////////回溯法+剪枝///////////////////////////////////////////////////////

//void backtrack(vector<int>& nums, vector<int>& vis, vector<vector<int>>& ans, vector<int>& path) 
//{
//    if (path.size()== nums.size()) 
//    {
//        ans.emplace_back(path);
//        return;
//    }
//    for (int i = 0; i < (int)nums.size(); ++i)
//    {
//        if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) //对原数组排序，保证相同的数字都相邻，然后每次填入的数
//                                                                        //一定是这个数所在重复数集合中「从左往右第一个未被填过的数字」
//                                                                        //如果没有这个条件将会带来很多重复结果
//        {
//            continue;//跳过这个数的条件是这个数被填过了或者是与前一个数重复且前一个数没被填
//        }
//        path.emplace_back(nums[i]);
//        vis[i] = 1;
//        backtrack(nums, vis,ans, path);
//        vis[i] = 0;
//        path.pop_back();
//    }
//}
//int main()
//{
//    vector<int> nums = { 1,1,2 };
//    vector<vector<int>> res;
//    vector<int> path;
//    vector<int> vis;
//    vis.resize(nums.size());
//    int length = nums.size();
//    sort(nums.begin(), nums.end());
//    backtrack(nums,vis, res, path);
//    for (int i = 0; i < res.size(); i++)
//    {
//        for (int j = 0; j < res[0].size(); j++)
//            cout << res[i][j] << " ";
//        cout << endl;
//    }
//}

//////////////////////////////////////////////虚函数和多态///////////////////////////////////////////////////////

//C++中虚函数的唯一用处就是构成多态。为了方便，你可以只将基类中的函数声明为虚函数，这样派生类中的同类型函数就会被覆盖，自动变成虚函数
//军队
//class Troops {
//public:
//    virtual void fight() { cout << "Strike back!" << endl; }
//};
//
////陆军
//class Army : public Troops {
//public:
//    void fight() { cout << "--Army is fighting!" << endl; }
//};
////99A主战坦克
//class _99A : public Army {
//public:
//   void fight() { cout << "----99A(Tank) is fighting!" << endl; }
//};
////武直10武装直升机
//class WZ_10 : public Army {
//public:
//    void fight() { cout << "----WZ-10(Helicopter) is fighting!" << endl; }
//};
////长剑10巡航导弹
//class CJ_10 : public Army {
//public:
//    void fight() { cout << "----CJ-10(Missile) is fighting!" << endl; }
//};
//
////空军
//class AirForce : public Troops {
//public:
//    void fight() { cout << "--AirForce is fighting!" << endl; }
//};
////J-20隐形歼击机
//class J_20 : public AirForce {
//public:
//    void fight() { cout << "----J-20(Fighter Plane) is fighting!" << endl; }
//};
////CH5无人机
//class CH_5 : public AirForce {
//public:
//    void fight() { cout << "----CH-5(UAV) is fighting!" << endl; }
//};
////轰6K轰炸机
//class H_6K : public AirForce {
//public:
//    void fight() { cout << "----H-6K(Bomber) is fighting!" << endl; }
//};
//
//int main() {
//    Troops* p = new Troops;//一个基类指针指向所有派生类，构成多态
//    p->fight();
//    //陆军
//    p = new Army;
//    p->fight();
//    p = new _99A;
//    p->fight();
//    p = new WZ_10;
//    p->fight();
//    p = new CJ_10;
//    p->fight();
//    //空军
//    p = new AirForce;
//    p->fight();
//    p = new J_20;
//    p->fight();
//    p = new CH_5;
//    p->fight();
//    p = new H_6K;
//    p->fight();
//    return 0;
//}

//////////////////////////////////////////////模板函数//////////////////////////////////////////////////////

//*
//函数模板声明
//1.函数模板定义由模板说明和函数定义组成，并且一个模板说明对应一个函数定义
//2.模板说明的类属参数必须在函数定义中至少出现一次
//3.函数参数表中可以使用类属类型参数，也可以使用一般类型参数
//template关键字告诉c++编译器现在要进行泛型编程
//typename或者class告诉c++编译器T是一个数据类型，不要进行语法检查
//typename和class完全可以互相替换
//*/
//template<typename T>//也可以写成template<class T>
//void myswap(T& a, T& b) {
//    T c = a;
//    a = b;
//    b = c;
//};
////void Print(T &a,T &b){
////    cout << "a=" << a << "\nb=" << b << endl;
////}
////报错：一个模板说明只能对应一个函数定义，想再定义一个函数，必须再写一个模板声明
//
//template<class T>
//void Print(T& a, T& b) {
//    cout << "a=" << a << "\nb=" << b << endl;
//}
//
////多参数的函数模板
//template<typename T1, typename T2>
////void MySort(T1 a) {
////    cout << a << b <<endl;
////}
////这种定义当调用函数时就会报错  MySort(a);
////模板说明的类属参数必须在函数定义中至少出现一次,也就是说T1，T2都要在形参列表里，哪怕不用，必须要出现
//void MySort(T1 a, T2 b) {
//    cout << a << b << endl;
//}
//template<typename T>
//void Getnum(T a, int b) {
//    cout << "a=" << a << ";\nb=" << b << endl;
//}
//
//void main() {
//    int a = 1;
//    int b = 2;
//    //泛型编程函数的使用方法1---自动类型推导
//    myswap(a, b);
//    Print(a, b);
//    //泛型编程函数的使用方法2---显式具体类型调用
//    myswap<int>(a, b);
//    Print(a, b);
//    //MySort(a)//报错 ： error C2783: “void MySort(T1)”: 未能为“T2”推导 模板 参数
//    MySort(a,"bbb");    
//    cout << "----------------" << endl;
//    Getnum(a, 4);
//}

//////////////////////////////////////////////模板函数重载///////////////////////////////////////////////////////

//*
//函数模板会进行严格的类型匹配，模板类型不提供隐式类型转化
//普通函数能够进行自动类型转换
//*/
//
//*
//函数模板重载四大规则
//1 函数模板可以像普通函数一样被重载
//2 C++编译器优先考虑普通函数
//3 如果函数模板可以产生一个更好的匹配，那么选择模板
//4 可以通过空模板实参列表的语法限定编译器只通过模板匹配
//*/
//
//template<typename T>
//void Test1(T a, T b) {
//    cout << "执行了模板函数Test1()" << endl;
//}
//
//void Test2(int a, int b) {
//    cout << "执行了普通函数Test2()" << endl;
//}
//
//void Test1(int a, int b) {
//    cout << "执行了普通函数Test1()" << endl;
//}
//
//void Test3(int a, int b) {
//    cout << "执行了普通函数Test3()" << endl;
//}
//
//void ProtectA() {
//    int a = 1;
//    int b = 2;
//    char c = '3';
//    //Test1<>(a, c);  //报错   error C2782: “void Test1(T,T)”: 模板 参数“T”不明确。<>表示调用模板函数的Test1
//    /*
//    因为 a是int型，c是char型  而函数模板要求两个参数都是T型 就是说两个参数的类型必须一致，
//    但是 int和char类型不一致  所以报错
//    */
//    Test2(a, c);//对于普通函数而言，则可以进行隐式类型转换，把char转换成int，所以没有问题
//}
//
//void ProtectB() {
//    int a = 1, b = 2;
//    char c = '3', d = '4';
//    Test1(a, b);//这里调用普通函数--规则1和2，模板函数与普通函数重载时，优先使用普通函数
//    Test1<>(a, b);//这里调用模板函数--规则4，<>指明了要使用模板函数
//    Test1(c, d);//这里调用模板函数--规则3---假设没有模板函数  仍然会调用普通函数
//    Test3(c, d);//普通函数可以进行隐式类型转换，把char转换成int，所以没有问题
//}
//
//void main() {
//    ProtectA();
//    ProtectB();
//}

//////////////////////////////////////////////模板类///////////////////////////////////////////////////////

//template<typename T1, typename T2>  //这里不能有分号，class可以换成typename,模板头和类头是一个整体，可以换行，但是中间不能有分号。
//class Point {
//public:
//    Point(T1 x, T2 y) {
//        setX(x);
//        setY(y);
//    }
//public:
//    T1 getX() {
//        return m_x;
//    };  //获取x坐标，返回值不确定，用T1表示
//    void setX(T1 x)
//    {
//        m_x = x;
//    };  //设置x坐标
//    T2 getY() {
//        return m_y;
//    };  //获取y坐标
//    void setY(T2 y) {
//        m_y = y;
//    };  //设置y坐标
//private:
//    T1 m_x;  //x坐标
//    T2 m_y;  //y坐标
//};
////template<typename T1, typename T2>  //模板头
////T1 Point<T1, T2>::getX()/*函数头*/ {//在类外定义函数时要用这种格式，模板头和函数头都用的是尖括号，template 关键字后面要指明类型参数，
//                                      //类名 Point 后面也要带上类型参数，只是不加 typename 关键字了。
//                                      //另外需要注意的是，在类外定义成员函数时，template 后面的类型参数要和类声明时的一致。
////    return m_x;
////}
////template<typename T1, typename T2>
////void Point<T1, T2>::setX(T1 x) {
////    m_x = x;
////}
////template<typename T1, typename T2>
////T2 Point<T1, T2>::getY()  {
////    return m_y;
////}
////template<typename T1, typename T2>
////void Point<T1, T2>::setY(T2 y) {
////    m_y = y;
////}
//int main() {
//    Point<int, int> p1(10, 20);//与函数模板不同的是，类模板在实例化时必须显式地指明数据类型(比如这里的<int,int>)，编译器不能根据给定的数据推演出数据类型。
//    cout << "x=" << p1.getX() << ", y=" << p1.getY() << endl;
//    Point<int, char*> p2(10, "东经180度");
//    cout << "x=" << p2.getX() << ", y=" << p2.getY() << endl;
//    Point<string, string>* p3 = new Point<string, string>("东经180度", "北纬210度");
//    cout << "x=" << p3->getX() << ", y=" << p3->getY() << endl;
//    return 0;
//}

//////////////////////////////////////////////快慢指针（找环的入口）///////////////////////////////////////////////////////

//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//ListNode* detectCycle(ListNode* head) {
//    ListNode* slow = head, *fast = head;
//    while (fast && fast->next) {
//        slow = slow->next;
//        fast = fast->next->next;
//        if (fast == slow) {
//            ListNode* ptr = head;
//            while (ptr != slow) {
//                ptr = ptr->next;
//                slow = slow->next;
//            }
//            return ptr;
//        }
//    }
//    return nullptr;
//}


//////////////////////////////////////////////双指针求解盛水最多的容器///////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/container-with-most-water/solution/container-with-most-water-shuang-zhi-zhen-fa-yi-do/
//其实无论是移动短指针和长指针都是一种可行求解。 只是，一开始就已经把指针定义在两端，如果短指针不动，而把长指针向着另一端移动，
//两者的距离已经变小了，无论会不会遇到更高的指针，结果都只是以短的指针来进行计算。 故移动长指针是无意义的。
//void main()
//{
//    vector<int> height = { 1,8,6,4 };
//    int left = 0, right = height.size() - 1;
//    int ans = 0;
//    while (left < right) {//设两指针 i,j ，指向的水槽板高度分别为 h[i],h[j]，
//        //此状态下水槽面积为 S(i, j) 。由于可容纳水的高度由两板中的 短板 决定，因此可得如下 面积公式 ：S(i,j)=min(h[i],h[j])×(j−i)
//        int area = min(height[left], height[right]) * (right - left);
//        ans = max(ans, area);//逐次求出面积最大值
//        //在每个状态下，无论长板或短板向中间收窄一格，都会导致水槽 底边宽度-1变短：
//        //·若向内 移动短板 ，水槽的短板 min(h[i], h[j])可能变大，因此下个水槽的面积可能增大 。
//        //·若向内 移动长板 ，水槽的短板 min(h[i], h[j])不变或变小，因此下个水槽的面积 一定变小 。
//        //因此，必须要向内移动短板
//        if (height[left] <= height[right]) {
//            ++left;
//        }
//        else {
//            --right;
//        }
//    }
//    cout<<ans<<endl;
//}

//////////////////////////////////////////////deque.insert的使用方法///////////////////////////////////////////////////////

//int main()
//{
//    deque<int> d{ 1,2 };
//    //第一种格式用法
//    d.insert(d.begin() + 1, 3);//{1,3,2}
//    //第二种格式用法
//    d.insert(d.end(), 2, 5);//{1,3,2,5,5}
//    //第三种格式用法
//    array<int, 3> test{ 7,8,9 };
//    d.insert(d.end(), test.begin(), test.end());//{1,3,2,5,5,7,8,9}
//    //第四种格式用法
//    d.insert(d.end(), { 10,11 });//{1,3,2,5,5,7,8,9,10,11}
//    for (int i = 0; i < d.size(); i++) {
//        cout << d[i] << " ";
//    }
//    return 0;
//}

//////////////////////////////////////////////非递增顺序的最小子序列///////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/minimum-subsequence-in-non-increasing-order/solution/cpai-xu-tan-xin-by-xiaoneng-l6jn/
//从数组中抽取一个子序列，满足该子序列的元素之和 严格 大于未包含在该子序列中的各元素之和。
//如果存在多个解决方案，只需返回 长度最小 的子序列
//void main() //第一个思路
//{
//    vector<int> nums = { 4,3,10,9,8 };
//    sort(nums.begin(), nums.end());
//    auto it = nums.end() - 1;
//    while (accumulate(it, nums.end(), 0) <= accumulate(nums.begin(), it, 0))
//    {
//        --it;
//    }
//    vector<int> res(it, nums.end());
//    sort(res.begin(), res.end(), [](const int &x, const int &y) {
//        return x >y;//如果这里写成x>=y就会报错，出现死循环，永远让比较函数对相同元素返回false；或者直接用greater<int>()函数，或者sort完再reverse
//        });
//    for (auto i : res)
//    {
//        cout << i << " ";
//    }
//}
//void main() //第二个思路
//{
//    vector<int> nums = { 4,3,10,9,8};
//    int sum = accumulate(nums.begin(), nums.end(), 0);//总和sum, 子列和sum1, 需满足sum1>sum-sum1, 即sum-2*sum1<0;因此可分步减
//    vector<int>res;
//    sort(nums.begin(), nums.end(), [](int& a, int& b) {return a > b;});//排序，从大到小，优先选取大数，这样保证选到的子序列最短
//    for (int& n : nums) {
//        res.push_back(n);
//        sum -= 2 * n;//这里分步减，把减去sum1分成了减去每个单独的数
//        if (sum < 0) {
//            break;
//        }
//    }
//    for (auto i : res)
//    {
//        cout << i << " ";
//    }
//}

//////////////////////////////////////////////DP解决完全平方数之和///////////////////////////////////////////////////////

//void main()
//{
//    int n = 99;
//    vector<int> dp(n + 1, 0);
//    for (int i = 1;i <= n;++i) {
//        dp[i] = i;//先将dp初始化为最大个数 ，比如4=1+1+1+1
//        for (int j = sqrt(i);j >= 1;--j) {
//            dp[i] = min(dp[i], dp[i - j * j] + 1);
//        }
//    }
//        cout<<dp[n];
//}

//////////////////////////////////////////////正向迭代器和反向迭代器///////////////////////////////////////////////////////

//int main()
//{
//    //创建 list 容器
//    list<char> values{ 'h','t','t','p',':','/','/','c','.','b','i','a','n','c','h','e','n','g','.','n','e','t' };
//    //使用begin()/end()迭代器函数对输出list容器中的元素
//    for (auto it = values.begin(); it != values.end(); ++it) {
//        cout << *it;
//    }
//    cout << endl;
//    //使用 rbegin()/rend()迭代器函数输出 list 容器中的元素
//    for (auto it1 = values.rbegin(); it1 != values.rend();++it1) {
//        cout << *it1<<endl;
//    }
//    return 0;
//}

//////////////////////////////////////////////课程表学完所有课的先决条件（广度优先遍历 BFS）///////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/course-schedule/solution/course-schedule-tuo-bu-pai-xu-bfsdfsliang-chong-fa/
//void main()
//{
//    vector<vector<int>> edges(7, { 0 });//表示有向拓扑图与各个端相连的边
//    vector<vector<int>> prerequisites = { {0,1},{2,1}, {4,0}, {5,0}, {5,3}, {2,0}, {4,5}, {6,5} };//[0, 1] 表示：想要学习课程0，你需要先完成课程1。
//    vector<int> indeg(7,0);//表示每个端的入度（箭头指到该端点的个数）
//    int numCourses = 7;//7个端点
//    for (auto info : prerequisites) {
//        edges[info[1]].push_back(info[0]);//以有向边末端的端点为集合，将指向它的所有端点都加入集合
//        indeg[info[0]]++;//被指的端点入度+1
//    }
//
//    queue<int> q;//存放入度为0的端点，入度为0表示这门课程不需要其他先决条件了，入队表示将学习，出队表示学完了
//    for (int i = 0; i < numCourses; ++i) {
//        if (indeg[i] == 0) {
//            q.push(i);//最开始入度为0的端点进入队列
//        }
//    }
//
//    int visited = 0;//每个端点正常来说只需要出队一次，所以当visited等于端点个数的时候说明没有环路，不等于的话说明有环路
//    while (!q.empty()) {
//        ++visited;
//        int u = q.front();//每次只访问队列的第一个元素，访问完毕后弹出队列
//        cout << " " << q.front();
//        q.pop();
//        for (int v : edges[u]) {//对于该端点指向的所有端点，其入度-1，v表示端点号
//            --indeg[v];
//            if (indeg[v] == 0) {//入度为0的端点进入队列
//                q.push(v);
//            }
//        }
//    }
//    cout << endl;
//    if (visited == numCourses)
//    {
//        cout << "true" << endl;
//    }
//    else cout << "false" << endl;
//}

//////////////////////////////////////////////课程表学完所有课的先决条件（深度优先遍历 DFS）///////////////////////////////////////////////////////

//void dfs(int u, vector<int> &visited, vector<vector<int>> &edges,bool &valid) {//注意这里都是引用
//    visited[u] = 1;//被访问但不知道是否存在出度，状态变成1
//    for (int v : edges[u]) {//访问该端点所指向的所有端点
//        if (visited[v] == 0) {
//            dfs(v,visited,edges,valid);
//            if (!valid) {//如果已经找到环了，valid=false，直接返回
//                return;
//            }
//        }
//        else if (visited[v] == 1) {//如果指向一个状态为1的端点，说明这个端点是它的上级端点（被访问过但是还没入栈），说明存在环路，返回false
//            valid = false;
//            return;
//        }
//    }
//    visited[u] = 2;//2代表被访问过且不存在出度
//}
//void main()
//{
//    vector<vector<int>> edges(7, { 0 });//表示有向拓扑图与各个端相连的边
//    vector<vector<int>> prerequisites = { {0,1},{2,1}, {0,4}, {5,0}, {5,3}, {2,0}, {4,5}, {6,5} };//拓扑排序
//    int numCourses = 7;//7个端点
//    vector<int> visited(7,0);//记录7个端点的状态，0代表未被访问，1代表被访问过但是不知道是否存在出度，还有继续往深搜索的可能，2代表被访问过且不存在出度，已经入栈（这个栈不必实体化，只代表一种状态）
//    bool valid = true;//记录拓扑图中是否存在环
//    for (const auto& info : prerequisites) {//这里用的是常量引用，也可以写成auto info：prerequisites
//        edges[info[1]].push_back(info[0]);
//    }
//    for (int i = 0; i < numCourses && valid; ++i) {//当此时不存在环时，逐个访问端点
//        if (!visited[i]) {//如果该端点没有被访问过
//            dfs(i,visited,edges,valid);//深度优先遍历
//        }
//    }
//    if (valid == true)
//    {
//        cout << "true" << endl;
//    }
//    else cout << "false" << endl;
//}

//////////////////////////////////////////////拓扑排序///////////////////////////////////////////////////////

//#define grasize 5//定义图的顶点个数为5个节点
//struct graphnode
//{
//    int label;
//    vector<graphnode*> neighbors;//存放结点指针的vector，每个元素都应该是结点指针
//    graphnode(int x) :label(x) {};//构造函数
//};
//class graphorder {
//public:
//    //深度优先遍历
//    static void dfs_gra(graphnode** graph)//这里形参还可以写成graphnode* graph[],表示结点指针数组，还可以用指针指向这个数组，就是graphnode** graph
//    {
//        int visit[grasize] = { 0 };//所有结点状态初始化为0，表示没有被访问
//
//        for (int i = 0; i < grasize; i++)
//        {
//            if (visit[i] == 0)
//            {
//                dfs_i(graph[i], visit);
//            }
//        }
//    }
//    //广度优先遍历
//    static void bfs_gra(graphnode** graph)
//    {
//        int visit[grasize] = { 0 };
//        for (int i = 0; i < grasize; i++)
//        {
//            if (visit[i] == 0)
//            {
//                bfs_i(graph[i], visit);
//            }
//        }
//    }
//private:
//    //递归
//    static void dfs_i(graphnode* node, int visit[]) {
//        visit[node->label] = 1;
//        cout << node->label << " ";
//        for (int i = 0; i < node->neighbors.size(); i++)
//        {
//            if (visit[node->neighbors[i]->label] == 0)
//            {
//                dfs_i(node->neighbors[i], visit);
//            }
//        }
//    }
//    //队列实现
//    static void bfs_i(graphnode* node, int visit[]) {
//        queue<graphnode*> q;
//        q.push(node);
//        visit[node->label] = 1;
//        while (!q.empty()) {
//            graphnode* node = q.front();
//            q.pop();
//            cout << node->label << " ";
//            for (int i = 0; i < node->neighbors.size(); i++)
//            {
//                if (visit[node->neighbors[i]->label] == 0)
//                {
//                    q.push(node->neighbors[i]);
//                    visit[node->neighbors[i]->label] = 1;
//                }
//            }
//        }
//    }
//};
//int main()
//{	
//	graphnode* graph[grasize];
// 	for (int i = 0; i < grasize; i++)
// 	{
// 		graph[i] = new graphnode(i);
// 	}
// 	graph[0]->neighbors.push_back(graph[2]);
// 	graph[0]->neighbors.push_back(graph[4]);
// 	graph[1]->neighbors.push_back(graph[0]);
// 	graph[1]->neighbors.push_back(graph[2]);
// 	graph[2]->neighbors.push_back(graph[3]);
// 	graph[3]->neighbors.push_back(graph[4]);
// 	graph[4]->neighbors.push_back(graph[3]);
//
//	cout << "深度优先遍历:";
//	graphorder::dfs_gra(graph);
// 	cout << endl;
//
// 	cout << "广度优先遍历:";
// 	graphorder::bfs_gra(graph);
//
//	for (int i = 0; i < grasize; i++)
// 	{
//  		delete graph[i];
// 	}
// 	return 0;
//}

//////////////////////////////////////////////DP解决零钱兑换（完全背包）///////////////////////////////////////////////////////

//void main()
//{
//    int amount = 264;
//    vector<int> coins = { 474,83,404,3};
//    vector<int> dp(amount + 1，amount+1);
//    dp[0] = 0;
//    int len = coins.size();
//    for (int i = 1;i <= amount;i++)
//    {
//        for (int j = 0;j < len ;j++)
//        {
//            if (coins[j] <= i)
//            {
//                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
//            }
//        }
//    }
//    cout << (dp[amount]>amount? -1:dp[amount]) << endl;
//}

//////////////////////////////////////////////list去重///////////////////////////////////////////////////////

//bool demo(double first, double second)
//{
//    return (int(first) == int(second));
//}
//int main()
//{
//    list<double> mylist{ 1,1.2,1.2,3,4,4.5,4.6 };
//    //删除相邻重复的元素，仅保留一份
//    mylist.unique();//{1, 1.2, 3, 4, 4.5, 4.6}
//
//    for (auto it = mylist.begin(); it != mylist.end(); ++it)
//        cout << *it << ' ';
//    cout << endl;
//    //demo 为二元谓词函数，是我们自定义的去重规则
//    mylist.unique(demo);
//    //利用匿名函数去重
//    /*mylist.unique([](const double a, const double b) {
//        return (int(a) == int(b));
//        }
//    );*/
//
//    for (auto it = mylist.begin(); it != mylist.end(); ++it)
//        std::cout << *it << ' ';
//    return 0;
//}

//////////////////////////////////////////////柱状图中的最大矩形///////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/bao-li-jie-fa-zhan-by-liweiwei1419/
//void main()
//{
//    vector<int> heights = { 2,1,5,6,2,3 };
//    //************暴力解法**************//
//    //int n = heights.size();//暴力解法，遍历每一个柱子的高度，找到左右两边比这个高度小的柱子，计算面积
//    //int ans = 0;
//    //for (int i = 0; i < n; ++i) {
//    //    // 枚举高,逐个矩形枚举
//    //    int height = heights[i];
//    //    int left = i, right = i;
//    //    // 确定左右边界
//    //    while (left >= 0 && heights[left] >= height) {//左边界最小可以达到0
//    //        --left;
//    //    }
//    //    while (right < n && heights[right] >= height) {//右边界最大可以达到n-1
//    //        ++right;
//    //    }
//    //    // 计算面积
//    //    ans = max(ans, (right - left - 1) * height);
//    //}
////    //************使用单调栈的优化暴力解法**************//
//    int n = heights.size();
//    vector<int> left(n), right(n);//确定每一个柱子的左右边界
//
//    stack<int> mono_stack;//这个栈用来存储那些还不能确定边界的柱子编号，如果确定的话就要弹出栈，比如遍历第一个2的时候，由于不知道
//                          //右边的高度，所以先入栈
//    for (int i = 0; i < n; ++i) {//确定每根柱子的左边界
//        //while循环的作用：·找到当前柱子的左边界，左边界是比当前柱子低的柱子序号
//        while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {//退出条件是栈空或者栈顶柱子比当前柱子高度严格低
//            mono_stack.pop();//弹出栈顶柱子，直到找到比当前柱子低的柱子
//        }
//        left[i] = (mono_stack.empty() ? -1 : mono_stack.top());//左边界保存的是比当前柱子低的下标
//        mono_stack.push(i);//每个柱子遍历后都要推入栈，以确定它们的左边界
//    }
//    mono_stack = stack<int>();
//    for (int i = n - 1; i >= 0; --i) {//确定每根柱子的右边界
//       while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
//          mono_stack.pop();
//       }
//       right[i] = (mono_stack.empty() ? n : mono_stack.top());
//       mono_stack.push(i);
//    }
//    int ans = 0;
//    for (int i = 0; i < n; ++i) {
//        ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
//    }
//    cout << ans << endl;
//}

//////////////////////////////////////////////最大矩形（基于柱状图求解）///////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/maximal-rectangle/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-1-8/
//int main()
//{
//    vector<vector<char>> matrix = {//必须用单引号
//        {'1','0', '1', '0', '0'},
//        {'1', '0', '1', '1', '1'},
//        {'1', '1', '1', '1', '1'},
//        {'1', '0', '0', '1', '0'}};
//    /*vector<vector<string>> matrix = {//必须用双引号
//        {"1","0", "1", "0", "0"},
//        {"1", "0", "1", "1", "1"},
//        {"1", "1", "1", "1", "1"},
//        {"1", "0", "0", "1", "0"}};*/
//    int m = matrix.size();//m行
//    if (m == 0) {
//        return 0;
//    }
//    int n = matrix[0].size();//n列
//    vector<vector<int>> left(m, vector<int>(n, 0));//用来存放一行中连续1的宽度，相当于上一题的heights数组，以竖着的某一列为底边，连续1的宽度为高度，也就是说总共有 m 根柱子
//
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            if (matrix[i][j] == '1') {
//                left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;//除了左边界，后面的1宽度都是左边1宽度+1
//            }
//        }
//    }
//    //************使用柱状图的优化暴力解法**************//
//    //int ret = 0;
//    //for (int i = 0; i < m; i++) {
//    //    for (int j = 0; j < n; j++) {//先对每一行中的1遍历，这里的1是目的矩形中右下角的元素，因此只需要对左上的元素进行遍历
//    //                                 //就能找到以该元素为右下角元素的面积最大矩形
//    //        if (matrix[i][j] == '0') {
//    //            continue;
//    //        }
//    //        int width = left[i][j];//先确定该行该列1的宽度,作为矩形的底边
//    //        int area = width;
//    //        for (int k = i - 1; k >= 0; k--) {//对左上元素遍历
//    //            width = min(width, left[k][j]);
//    //            area = max(area, (i - k + 1) * width);//i-k+1表示高度
//    //        }
//    //        ret = max(ret, area);
//    //    }
//    //}
//    //************使用单调栈的优化暴力解法**************//
//    int ret = 0;
//    for (int j = 0; j < n; j++) { // 对于每一列，使用基于柱状图的方法
//        vector<int> up(m, 0), down(m, 0);//up表示行从小到大遍历，down表示列从大到小遍历，相当于left和right
//        stack<int> stk;
//        for (int i = 0; i < m; i++) {
//            while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
//                stk.pop();
//            }
//            up[i] = stk.empty() ? -1 : stk.top();
//            stk.push(i);
//        }
//        stk = stack<int>();
//        for (int i = m - 1; i >= 0; i--) {
//            while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
//                stk.pop();
//            }
//            down[i] = stk.empty() ? m : stk.top();
//            stk.push(i);
//        }
//
//        for (int i = 0; i < m; i++) {
//            int height = down[i] - up[i] - 1;
//            int area = height * left[i][j];
//            ret = max(ret, area);
//        }
//    }
//    cout << ret << endl;
//    return 0;
//}

//////////////////////////////////////////////列可交换的最大矩形///////////////////////////////////////////////////////

//https://leetcode.cn/problems/largest-submatrix-with-rearrangements/solution/java-yu-chu-li-shu-zu-bian-li-mei-xing-p-qpqu/
//int main()
//{
//    vector<vector<int>> matrix = { {0, 0, 1},{1, 1, 1},{1, 0, 1} };
//    int m = matrix.size(), n = matrix[0].size();
//    for (int i = 1;i < m;i++)
//    {//以行为底边，记录每一列连续1的高度，
//        for (int j = 0;j < n;j++)
//        {
//            if (matrix[i][j] == 1)
//            {
//                matrix[i][j] += matrix[i - 1][j];//节省空间
//            }
//        }
//    }
//    int res = 0;
//    for (int i = 0;i < m;i++)
//    {//因为可以交换每一列，所以我们从第1行开始考虑（i=0），考虑从第1行到目前的第i+1行，把它当成新矩阵，计算他能组成的最大矩形是多少
//        //直接排序（因为可以交换每一列）得到连续1高度从小到大排列的矩阵，那个对于第j列的高度 matrix[i][j]，由于比他高（或相等）的全都在右边，比他矮（或相等）的全都在左边，因此以matrix[i][j]为高
//        //的最大矩形的底为（n-j），最大矩形面积就是matrix[i][j] * (n - j)，这样对于每一行，我们都单独排序并计算最大矩形，更新res，最终得到最大矩形
//        //·不是只能列与列交换吗？上面的行排序以后难道不会对下面的行的列高度产生影响？
//        //  不会，因为每一行的列高度都已经保存了，如果遍历第 i 行的时候得到一个最大矩形，假设第 j 行的时候又得到一个更大的矩形，那么最终的排列方式就是按照第 j 行的排列方式
//        //  我们不关心最终是怎样排列的，只需要找到最大矩形就行了，最后的排列方式一定是按照最大矩形的方式来排列的
//        sort(matrix[i].begin(), matrix[i].end());
//        for (int j = 0;j < n;j++)
//        {
//            res = max(res, matrix[i][j] * (n - j));
//        }
//    }
//}

//////////////////////////////////////////////无重复字符的最长子串///////////////////////////////////////////////////////

//https://leetcode.cn/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-by-leetc-2/
//int main()
//{
//    string s = "pwwkew";
//    int len = s.length();
//    if (len == 0)    return 0;//无字符直接返回0
//    //************动态规划**************//
//    vector<int> dp(len);//dp存放的是以s[i]结尾的字符串中不重复的最大长度
//    dp[0] = 1;//边界初始化
//    int maxans = 1;//由于最后要找最大长度，所以初始化的时候要赋最小值，单个字符最小长度为1
//    for (int i = 1;i < len;i++) {//从第二个字符开始遍历
//        int j=i-1;//这里j只能定义在外面，否则会报错
//        while (j >= i - dp[i - 1])//i=1代表我们访问的是s的第i+1个字符，dp[i-1]表示以s[i-1]结尾的字符串中不重复的最大长度
//        {                          //也就是说我们只需要判断在[i-dp[i-1]：i-1]这段字符串中是否存在s[i]，从而找到以以s[i]结尾的字符串中不重复的最大长度
//                                  //这里i是下标，dp[i-1]是长度，则j也是坐标
//            if (s[j] == s[i])
//            {
//                break;
//            }
//            --j;
//        }
//        dp[i] = i - j;//i-j就是没有重复的最大长度
//        maxans = max(maxans, dp[i]);//找到所有长度里的最大值
//    }
//    //************滑动窗口**************//
//    //int left = 0, right = 0;
//    //unordered_set<char> uset;
//    //while (right < len)
//    //{
//    //    while (uset.count(s[right]))//如果已存在右边界字符，那么就要把左边界字符挨个删除，直到不存在右边界字符
//    //    {
//    //        uset.erase(s[left]);
//    //        left++;
//    //    }
//    //    maxans = max(maxans, right - left + 1);
//    //    uset.insert(s[right]);
//    //    right++;
//    //}
//    cout << maxans << endl;
//}


//////////////////////////////////////////////分割等和子集（DP）///////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/partition-equal-subset-sum/solution/0-1-bei-bao-wen-ti-xiang-jie-zhen-dui-ben-ti-de-yo/
//int main()
//{
//	vector<int> nums = { 1,5,11,5 };
//	int sum = accumulate(nums.begin(), nums.end(),0);
//	if (sum % 2 != 0)
//	{
//		cout << "false";
//		return 0;
//	}
//	int target = sum / 2;
//	vector<int> dp(target + 1, 0);
//	for (int i = 0;i < nums.size();++i)
//	{
//		for (int j = target;j >= nums[i];--j)
//		{
//			dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
//		}
//		for(int i=0;i<=target;++i)
//		{
//			cout << dp[i]<< ' ';
//		}
//		cout << endl;
//	}
//	cout << dp[target];
//	return 1;
//}

//////////////////////////////////////////////地图中的最高点（多源BFS，最短路径)///////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/map-of-highest-peak/solution/liang-ci-cai-keng-hou-zhong-yu-xue-hui-l-hlqo/
//void main()
//{
//    vector<vector<int>> isWater = { {0,0,1},{1,0,0},{0,0,0} };
//    int R = isWater.size(), C = isWater[0].size();
//    vector<vector<int>> res(R, vector<int>(C, 0));//存放地图的高度
//    queue<pair<int, int>> que;
//    for (int i = 0; i < R; ++i)
//        for (int j = 0; j < C; ++j)
//            if (isWater[i][j] == 1)
//                que.push(make_pair(i,j));//存放水域的坐标
//    while (!que.empty())//多源BFS + 记忆化，从两个源头开始走，一边走一步（高度加一），最后访问到的地方就是最高的点，这样遍历一定可以满足题目条件，
//        //因为如果某个点距离源点A距离3，距离源点B距离4，那么一定是从A出发的波会先访问这个点，使得它的值变为3，而从B出发的波访问到这一点的时候发现
//        //它已经被访问过了，不会再访问它，而如果B的波刷新这个点的值为4的话，那就不符合距离最小的条件（因为它与A的距离最短，为3）
//    {
//        auto t = que.front();//取出首个水域坐标
//        que.pop();//取出坐标后直接弹出队列
//        for (auto f : vector<pair<int, int>>{ {t.first - 1,t.second},{t.first,t.second + 1},{t.first + 1,t.second},{t.first,t.second - 1} })
//        {//对该水域坐标的周边4个坐标依次遍历
//            if (0 <= f.first && f.first < R && 0 <= f.second && f.second < C && isWater[f.first][f.second] == 0)
//            {//当周边坐标在正常范围内且没有被变成水域
//                res[f.first][f.second] = res[t.first][t.second] + 1;//周边坐标等于原水域坐标的高度+1
//                isWater[f.first][f.second] = 1;            //天然的记忆化visited数组  染色法 的思想  //改变高度之后将周边坐标变成水域
//                que.push({ f.first,f.second});//推入水域队列
//            }
//        }
//    }
//    for (int i = 0; i < R; ++i)
//    {
//        for (int j = 0; j < C; ++j)
//        {
//            cout << res[i][j] << ' ';
//        }
//        cout << endl;
//    }
//}

//////////////////////////////////////////////所有橘子腐烂耗费的最短时间（多源BFS)///////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/rotting-oranges/solution/yan-du-you-xian-sou-suo-python3-c-by-z1m/
//int main()
//{
//    vector<vector<int>> grid = { {2, 1, 1},{1, 1, 0},{0, 1, 1} };//0代表空格，没有橘子，1代表好橘子，2代表腐烂橘子
//    int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
//    int m = grid.size(), n = grid[0].size();
//    queue<int> q;
//    int cnt = 0;//纪录好橘子的个数
//    int time = -1;//第一轮橘子本身就是坏的，不需要腐烂，而下面代码里面却计算了这轮的时间，所以要初始化为-1
//    for (int i = 0;i < m;i++)
//    {
//        for (int j = 0;j < n;j++)
//        {
//            if (grid[i][j] == 2)
//            {
//                q.push(i * n + j);
//            }
//            else if (grid[i][j] == 1)
//            {
//                cnt++;
//            }
//        }
//    }
//    if (cnt == 0) return 0;
//    while (!q.empty())
//    {
//
//        int sz = q.size();
//        while (sz--)
//        {
//            int x = q.front() / n;
//            int y = q.front() % n;
//            q.pop();
//            for (int i = 0;i < 4;i++)
//            {
//                int new_x = x + dir[i][0];
//                int new_y = y + dir[i][1];
//                if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && grid[new_x][new_y] == 1)
//                {
//                    grid[new_x][new_y] = 2;
//                    q.push(new_x * n + new_y);
//                    cnt--;
//                }
//            }
//        }
//        time++;
//    }
//    cout << (cnt == 0 ? time : -1) << endl;//cnt不等于0表示并不是所有橘子都会腐烂
//}

//////////////////////////////////////////////找到数组中的1到最近的0元素的距离（多源BFS)///////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/01-matrix/solution/2chong-bfs-xiang-jie-dp-bi-xu-miao-dong-by-sweetie/
//typedef pair<int, int> pii;
//int main()
//{
//    vector<vector<int>> mat = { {0, 0, 0},{0, 1, 0},{1, 1, 1} };
//    int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
//    int m = mat.size(), n = mat[0].size();
//    vector<vector<int>> res(m, vector<int>(n, 0));
//    queue<pii> q;
//    for (int i = 0;i < m;i++)
//    {
//        for (int j = 0;j < n;j++)
//        {
//            if (mat[i][j] == 0)
//            {//先找到0，然后以0为源点去扩散，找到1距离就增加1
//                q.push({ i * n + j,0 });
//            }
//        }
//    }
//    while (!q.empty())
//    {
//        int x = q.front().first / n;
//        int y = q.front().first % n;
//        int dist = q.front().second;
//        q.pop();
//        for (int i = 0;i < 4;i++)
//        {
//            int new_x = x + dir[i][0];
//            int new_y = y + dir[i][1];
//            if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && mat[new_x][new_y] == 1)
//            {
//                mat[new_x][new_y] = 0;
//                res[new_x][new_y] = dist + 1;
//                q.push({ new_x * n + new_y,dist + 1 });
//            }
//        }
//    }
//}

//////////////////////////////////////////////找到数组中的0到最近的1元素的最大距离（多源BFS)///////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/jian-dan-java-miao-dong-tu-de-bfs-by-sweetiee/
//int main()
//{
//    vector<vector<int>> grid = { {1, 0, 0}, {0, 0, 0} , {0, 0, 0} };
//    int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
//    int m = grid.size();
//    int n = grid[0].size();
//    queue<pair<int, int>> que;
//    for (int i = 0;i < m;i++)
//    {
//        for (int j = 0;j < n;j++)
//        {
//            if (grid[i][j] == 1)
//            {//以陆地为源点，向外扩散，最后访问到的海洋坐标的距离就是全图 0 到最近的 1 的最大距离
//                que.push(make_pair(i, j));
//            }
//        }
//    }
//    int dist = 0;
//    if (que.size() == m * n)
//    {
//        return -1;
//    }
//    while (!que.empty())
//    {
//        int sz = que.size();
//        while (sz--)
//        {
//            int x = que.front().first;
//            int y = que.front().second;
//            que.pop();
//            for (int i = 0;i < 4;i++)
//            {
//                int new_x = x + dir[i][0];
//                int new_y = y + dir[i][1];
//                if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && grid[new_x][new_y] == 0)
//                {
//                    grid[new_x][new_y] = 1;
//                    que.push({ new_x,new_y });
//                }
//            }
//        }
//        dist++;//其实只需要记录最后一轮的距离就行了
//    }
//    cout << dist - 1 << endl;
//}

//////////////////////////////////////////////DFS/BFS复制无向图///////////////////////////////////////////////////////

//class Node {
//public:
//    int val;
//    vector<Node*> neighbors;
//    Node() {
//        val = 0;
//        neighbors = vector<Node*>();
//    }
//    Node(int _val) {
//        val = _val;
//        neighbors = vector<Node*>();
//    }
//    Node(int _val, vector<Node*> _neighbors) {
//        val = _val;
//        neighbors = _neighbors;
//    }
//};
//unordered_map<int, Node*> existed;
//void DFS(Node* curr) { // 传入节点是原图中的节点，利用原图节点值从哈希表中找到新建的拷贝节点，然后依照原图节点的领居列表操作新节点
//    // 找到新建的curr节点
//    Node* newCurr = existed[curr->val];
//    // 开始处理neighbors元素
//    for (int n = 0; n < curr->neighbors.size(); n++)
//    {
//        // 通过哈希表搜索判断节点是否已存在
//        int newVal = curr->neighbors[n]->val;
//        // 不存在就新建，加入哈希表，加入本节点相邻列表，递归新节点
//        if (existed.count(newVal) == 0)
//        {
//            Node* newNode = new Node(newVal);
//            existed.insert(pair<int, Node*>(newVal, newNode));
//            newCurr->neighbors.push_back(newNode);
//            DFS(curr->neighbors[n]);
//        }
//        // 存在就加入本节点相邻列表即可
//        else
//            newCurr->neighbors.push_back(existed[newVal]);
//    }
//}
//int main()
//{
//    Node* node1 = new Node(1);
//    Node* node2 = new Node(2);
//    Node* node3 = new Node(3);
//    Node* node4 = new Node(4);
//    node1->neighbors.push_back(node2);
//    node1->neighbors.push_back(node4);
//    node2->neighbors.push_back(node1);
//    node2->neighbors.push_back(node3);
//    node3->neighbors.push_back(node2);
//    node3->neighbors.push_back(node4);
//    node4->neighbors.push_back(node3);
//    node4->neighbors.push_back(node1);
//    // 如果node为空，则直接返回NULL
//    if (!node1)
//        return -1;
//    //************BFS**************//
//    /*queue<Node*> que({ node1 });
//    Node* new_node = new Node(node1->val);
//    existed.insert(make_pair(node1->val, new_node));
//    while (!que.empty()) {
//        auto temp = que.front();
//        que.pop();
//        for (auto e : temp->neighbors) {
//            if (!existed.count(e->val)) {
//                que.push(e);
//                existed[e->val] = new Node(e->val);
//            }
//            existed[temp->val]->neighbors.push_back(existed[e->val]);
//            cout << existed[temp->val]->val <<' ';
//        }
//    }
//    cout << endl;*/
//    //************DFS**************//
//    existed.clear();
//    // 新建第一个节点，之后节点在DFS中操作
//    Node* newRoot = new Node(node1->val);
//    existed.insert(pair<int, Node*>(newRoot->val, newRoot));
//    DFS(node1);
//    for(auto it=existed.begin();it!=existed.end();++it)
//    {
//        cout << it->first << endl;
//    }
//    return 0;
//};

//////////////////////////////////////////////DFS寻找单词///////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/word-search/solution/dan-ci-sou-suo-by-leetcode-solution/
//bool check(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, string& s, int k) {
//    if (k == s.length() - 1) {
//        return true;
//    }
//    visited[i][j] = true;//此坐标已访问
//    vector<pair<int, int>> directions{ {0, 1}, {0, -1}, {1, 0}, {-1, 0} };//邻居坐标
//    bool result = false;
//    for (const auto & dir : directions) {
//        int newi = i + dir.first, newj = j + dir.second;
//        if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
//            if (!visited[newi][newj]) {
//                if (board[newi][newj] == s[k + 1]) {
//                    bool flag = check(board, visited, newi, newj, s, k + 1);//下一次迭代
//                    if (flag) {//当后一次迭代的结果是true的时候，说明已经找到了，直接返回true
//                        return true;
//                    }
//                }
//            }
//        }
//    }
//    visited[i][j] = false;//不管后面的路径是否正确，本次访问过的坐标在回退时应该置为未访问
//    return result;
//}
//int main()
//{
//    vector<vector<char>> board = { {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'} };
//    string word = "SEE";
//    cout << word.length();
//    int m = board.size();
//    int n = board[0].size();
//    vector<vector<int>> visited(m, vector<int>(n, 0));
//    for (int i = 0;i < m;++i)
//    {
//        for (int j = 0;j < n;++j)
//        {
//            if (board[i][j] == word[0])
//            {
//                bool flag = check(board, visited, i, j, word, 0);//对board中每一个word[0]都进行DFS,走不通的路径都返回false
//                if (flag) {
//                    cout << "true" << endl;
//                    return true;
//                }
//            }
//            
//        }
//    }
//    cout << "false" << endl;
//    return false;
//}

//////////////////////////////////////////////二分查找法///////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/solution/mian-shi-ti-11-xuan-zhuan-shu-zu-de-zui-xiao-shu-3/
//int main()
//{
//    //***************利用二分法寻找旋转排序数组中的最小值*****************
//    /*vector<int> nums = { 3,4,5,1,2 };
//    int low = 0;
//    int mid;
//    int high = nums.size() - 1;
//    while (low <= high) {//while(left <= right)的终止条件是 left = right + 1，写成区间的形式就是 [right + 1, right]，
//                         //或者带个具体的数字进去 [3, 2]，可见这时候搜索区间为空，因为没有数字既大于等于 3 又小于等于 2 的
//        mid = (high + low) / 2;
//        if (nums[mid] < nums[high]) {//中间值有两种情况，第一是在最小值右边或等于最小值，则中间值小于右边界
//            high = mid;//此时不能排除mid，因为mid有可能等于最小值
//        }
//        else {//第二是在最小值左边，则中间值大于右边界
//            low = mid + 1;
//        }
//    }
//    cout << nums[mid] << endl;
//    return 0;*/
//    //***************利用二分法寻找旋转排序数组中的某个值*****************
//    vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
//    int target = 3;
//    int n = (int)nums.size();
//    if (!n) {
//        cout << -1 << endl;
//    }
//    if (n == 1) {
//        cout << ( nums[0] == target ? 0 : -1)<<endl;
//    }
//    int l = 0, r = n - 1;
//    while (l <= r) {//循环终止条件是左边界大于等于右边界
//        int mid = (l + r) / 2;
//        if (nums[mid] == target) return mid;
//        if (nums[l] <= nums[mid]) {//如果左边序列是有序递增的
//            if (nums[l] <= target && target < nums[mid]) {//且目标值在左边序列中，就在左边序列中找
//                r = mid - 1;
//            }
//            else {//目标在右边序列中，就在右边序列中找
//                l = mid + 1;
//            }
//        }
//        else {//如果右边序列是有序递增的
//            if (nums[mid] < target && target <= nums[r]) {//且目标值在右边序列中，就在右边序列中找
//                l = mid + 1;
//            }
//            else {//目标在左边序列中，就在左边序列中找
//                r = mid - 1;
//            }
//        }
//    }
//    cout << -1 << endl;
//    return 0;
//}

//////////////////////////////////////////////单调栈查找第一个更大元素的位置///////////////////////////////////////////////////

//int main()
//{
//    vector<int> temperatures = { 73, 74, 75, 71, 69, 72, 76, 73 };
//    //**********************暴力解法，超出时间限制***********************
//    /*int len = temperatures.size();
//    vector<int> res(len);
//    for (auto it = temperatures.begin();it != temperatures.end() - 1;++it)
//    {
//        for (auto it1 = it + 1;it1 != temperatures.end();++it1)
//        {
//            if (*it1 > * it)
//            {
//                res[it-temperatures.begin()]=it1 - it;
//                break;
//            }
//            else
//            {
//                continue;
//            }
//        }
//    }
//    return 0;*/
//    //**********************单调栈***********************
//    int n = temperatures.size();
//    vector<int> ans(n);
//    stack<int> s;
//    for (int i = 0; i < n; ++i) {
//        while (!s.empty() && temperatures[i] > temperatures[s.top()]) {//注意这里是while，把栈里面所有比当前数小的数全部取出来，也就是这些数全都找到了
//            //第一个比他们大的数，比如72会把69和71全都取出来，保证了栈是单调递减的（从栈底到栈顶递减）
//            int previousIndex = s.top();
//            ans[previousIndex] = i - previousIndex;
//            s.pop();
//        }
//        s.push(i);
//    }
//    for (auto i : ans)
//    {
//        cout << i << "  ";
//    }
//    return 0;
//}

//////////////////////////////////////////////递归和迭代判断二叉树是否对称/////////////////////////////////////////////////////

//struct TreeNode {
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode() : val(0), left(nullptr), right(nullptr) {}
//	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};
//bool check(TreeNode* p, TreeNode* q) {
//    if (!p && !q) 
//        return true;
//    if (!p || !q|| p->val != q->val)
//        return false;
//    bool res1 = check(p->left, q->right);
//    bool res2 = check(p->right, q->left);
//    return res1&&res2;
//}
//int main()
//{
//    TreeNode *three1 = new TreeNode(3);
//    TreeNode *three2 = new TreeNode(3);
//    TreeNode *four1 = new TreeNode(4);
//    TreeNode *four2 = new TreeNode(4);
//    TreeNode *two1 = new TreeNode(2, three1, four1);
//    TreeNode* two2 = new TreeNode(2, four2, three2);
//    TreeNode* one = new TreeNode(1, two1, two2);
//    //******************迭代法*******************
//    /*TreeNode* u = one;
//    TreeNode* v = one;
//    queue <TreeNode*> q;
//    q.push(u); q.push(v);
//    while (!q.empty()) {
//        u = q.front();
//        cout << u->val << "  ";
//        q.pop();
//        v = q.front();
//        cout << v->val << "  ";
//        q.pop();
//        if (!u && !v) continue;
//        if ((!u || !v) || (u->val != v->val)) return false;
//
//        q.push(u->left);
//        q.push(v->right);
//
//        q.push(u->right);
//        q.push(v->left);
//    }*/
//    //*****************递归法（调用check函数）*******************
//    cout << check(one, one);
//}

//////////////////////////////////////////////两棵二叉搜索树中的所有元素按照升序排列///////////////////////////////////////////////////

//https://leetcode-cn.com/problems/all-elements-in-two-binary-search-trees/solution/liang-ke-er-cha-sou-suo-shu-zhong-de-suo-you-yua-3/
//void dfs(TreeNode* node, vector<int>& v) {//二叉搜索树的中序遍历一定是有序的
//    if (!node) {
//        return;
//    }
//    dfs(node->left, v);
//    v.push_back(node->val);
//    dfs(node->right, v);
//}
//int main()
//{
//	TreeNode* one = new TreeNode(1);
//	TreeNode* four = new TreeNode(4);
//	TreeNode* zero = new TreeNode(0);
//	TreeNode* three = new TreeNode(3);
//	TreeNode* two = new TreeNode(2,one,four);
//	TreeNode* one2 = new TreeNode(1,zero,three);
//    TreeNode* root1 = two;
//    TreeNode* root2 = one2;
//    vector<int> v1, v2;
//    dfs(root1, v1);
//    dfs(root2, v2);
//
//    vector<int> ans;
//    int i = 0, j = 0;
//    while (i < v1.size() || j < v2.size()) {//对两个有序数组排序用归并排序法
//        if (i < v1.size() && (j == v2.size() || v1[i] <= v2[j])) {
//            ans.push_back(v1[i++]);
//        }
//        else {
//            ans.push_back(v2[j++]);
//        }
//    }
//    for(int i: ans)
//    {
//        cout<<i;
//    }
//}


//////////////////////////////////////////////回溯法找组合总数////////////////////////////////////////////////////

//void backtracking(vector<vector<int>>& result, vector<int>& path,vector<int>& candidates, int target, int sum, int startIndex)
//{
//    if (sum == target)
//    {
//        result.push_back(path);
//        return;
//    }
//    //如果 sum + candidates[i] > target 就终止遍历
//    for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++)
//    {//避免重复的方法就是i = startIndex，每一枝的每一层都不能使用最上层左边已经使用过的元素，比如第二枝的任何一层都不能使用第一枝
//        //最上层使用过的元素（这里是2，因为排序，第一枝最上层选的一定是最小值）
//        sum += candidates[i];
//        path.push_back(candidates[i]);
//        backtracking(result,path,candidates, target, sum, i);//不用i+1，因为此时可以重复
//        sum -= candidates[i];//回溯
//        path.pop_back();//回溯
//    }
//}
//int main()
//{
//    vector<vector<int>> result;
//    vector<int> path;
//    vector<int> candidates = { 2,3,5 };
//    int target = 8;
//    sort(candidates.begin(), candidates.end());
//    backtracking(result,path,candidates, target, 0, 0);
//    for (auto i : result)
//    {
//        for (auto j : i)
//        {
//            cout << j << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}

//////////////////////////////////////////////括号匹配的最大长度////////////////////////////////////////////////////

//int main()
//{
//    string s = "())(())(()";
//    //****************单调栈***************
//    int maxans = 0;
//    stack<int> stk;//栈底元素始终是未被匹配的最后一个）的下标
//    stk.push(-1);//如果一开始栈为空，第一个字符为左括号的时候会将其放入栈中，这样就不满足栈底元素是
//                 //「最后一个没有被匹配的右括号的下标」，为了保持统一，在一开始的时候往栈中放入一个值为 −1 的元素
//    for (int i = 0; i < s.length(); i++) {
//        if (s[i] == '(') {
//            stk.push(i);
//        }
//        else {
//            stk.pop();//不用管有没有匹配，因为此时除了栈底元素是）以外，其他都是（，只要是）都能被匹配，因此直接弹出，如果栈内没有（，说明到了栈底，
//                      //弹出栈底的）以后栈就是空的了，于是更新未被匹配的最后一个）的下标为当前坐标
//            if (stk.empty()) {//当栈为空的时候才把未被匹配的）放入栈，更新栈底元素，如果弹出以后栈为空，说明被弹出的是栈底的），这说明没有匹配，因此不会更新最大长度
//                stk.push(i);
//            }
//            else {//栈不为空的时候说明弹出的是（，能匹配，因此更新最大长度
//                maxans = max(maxans, i - stk.top());
//            }
//        }
//    }
//    cout << maxans << endl;
////    //****************动态规划******************
//    //int maxans = 0, n = s.length();
//    //vector<int> dp(n, 0);//dp[i] 表示以下标 i 字符结尾的最长有效括号的长度，显然有效的子串一定以‘)’结尾，以 ‘(’结尾的
//    //                    //子串对应的dp 值必定为 0 ，只需要求解 ‘)‘在 dp 数组中对应位置的值。
//
//    //for (int i = 1; i < n; i++) {//①如果s[i]=‘)’ 且 s[i - 1] = ‘(’，也就是字符串形如 “……()”，我们可以推出：
//    //                             //dp [i] = dp [i - 2] + 2,是因为结束部分的 "()" 是一个有效子字符串，
//    //                            //并且将之前有效子字符串的长度增加了 2 
//    //                            //②如果s[i] = ‘)’ 且 s[i - 1] = ‘)’，也就是字符串形如 “……))”，我们可以推出：
//    //                            //如果 s[i - dp[i - 1] - 1] = ‘(’，那么dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2
//    //                            //·这是因为如果倒数第二个‘)’是一个有效子字符串(记作sub）的一部分，对于最后一个 ‘)’，如果
//    //                            //它是一个更长子字符串的一部分，那么它一定有一个对应的‘(’ ，且它的位置在倒数第二个‘)’所在
//    //                            //的有效子字符串（sub）的前面。因此，如果子字符串（sub）的前面恰好是‘(’，那么我们就用 2加上
//    //                            //sub的长度dp[i - 1]去更新dp[i]。同时，也要把有效子串（sub）之前的有效子串的长度也加上，也就是
//    //                            //再加上 dp[i - dp[i - 1] - 2]
//    //                            //·如果如果倒数第二个‘)’不是一个有效子字符串的一部分，那么dp[i-1]=0，此时s[i - dp[i - 1] - 1]=s[i-1]，
//    //                            //也就是倒数第二个‘)’的索引，所以他必不可能等于'('，因此不会更新dp[i]，dp[i]仍然为0；
//    //    if (s[i] == ')') {
//    //        if (s[i - 1] == '(') {
//    //            dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
//    //        }
//    //        else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {//这里s[i - dp[i - 1] - 1]就是子字符串sub前面一个字符
//    //            dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
//    //        }
//    //        maxans = max(maxans, dp[i]);
//    //    }
//    //}
//    //cout << maxans << endl;
//    return 0;
//}

//////////////////////////////////////////////接雨水////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode/327718
//int main()
//{
//    vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
//    int len = height.size();
//    //************************左右边界法*************************
//    /*int mid, left, right;
//    int res = 0;
//    int temp;
//    for (mid = 1;mid < len - 1;++mid)
//    {
//        left = mid - 1;
//        right = mid + 1;
//        while (left - 1 >= 0 && height[left] <= height[mid])
//        {
//            left = left - 1;
//        }
//        while (right + 1 <= len - 1 && height[right] <= height[mid])
//        {
//            right = right + 1;
//        }
//        if (height[left] > height[mid] && height[right] > height[mid])
//        {
//            temp = min(height[left], height[right]) - height[mid];
//            res = res + (right - left - 1) * temp;
//            while (left != right-1)
//            {
//                left = left + 1;
//                height[left] = height[left] + temp;
//            }
//        }
//
//    }*/
//    //************************暴力法（找到i左右两边的最大高度）*************************
//    //int res = 0;
//    //for (int i = 1; i < len - 1; i++) {
//    //    int max_left = 0, max_right = 0;
//    //    for (int j = i; j >= 0; j--) { //找到i以及i左边的最大高度
//    //        max_left = max(max_left, height[j]);
//    //    }
//    //    for (int j = i; j < len; j++) { //找到i以及i右边的最大高度
//    //        max_right = max(max_right, height[j]);
//    //    }
//    //    res += min(max_left, max_right) - height[i];
//    //}
//    //************************动态规划（对暴力法的优化）*************************
//    //if (len == 0) {
//    //    return 0;
//    //}
//    //vector<int> leftMax(len);//存放i以及i左边的最大高度
//    //leftMax[0] = height[0];
//    //for (int i = 1; i < len; ++i) {
//    //    leftMax[i] = max(leftMax[i - 1], height[i]);//动态规划的思想
//    //}
//
//    //vector<int> rightMax(len);//存放i以及i右边的最大高度
//    //rightMax[len - 1] = height[len - 1];
//    //for (int i = len - 2; i >= 0; --i) {
//    //    rightMax[i] = max(rightMax[i + 1], height[i]);
//    //}
//    //int res = 0;
//    //for (int i = 0; i < len; ++i) {
//    //    res += min(leftMax[i], rightMax[i]) - height[i];//左右两边的最大高度相减再减去原本的高度
//    //}
//    //************************双指针（对动态规划的空间优化）*************************
//    int res = 0;
//    int left = 0, right = height.size() - 1;//left和right是两个指针，用来更新左边最大值leftMax和右边最大值rightMax
//    int leftMax = 0, rightMax = 0;//leftMax表示left左边以及left的最大高度，rightMax表示right右边以及right的最大高度
//    while (left < right) {//两个指针相遇，说明更新完毕
//        leftMax = max(leftMax, height[left]);//求高度最大值
//        rightMax = max(rightMax, height[right]);
//        if (leftMax < rightMax) {
//            //我们先明确几个变量的意思：
//            //    left_max：左边的最大值，它是从左往右遍历找到的
//            //    right_max：右边的最大值，它是从右往左遍历找到的
//            //    left：从左往右处理的当前下标
//            //    right：从右往左处理的当前下标
//            //·定理一：在某个位置i处，它能存的水，取决于它左右两边的最大值中较小的一个。
//            //·定理二：当我们从左往右处理到left下标时，左边的最大值left_max对它而言是可信的，但right_max对它而言是不可信的。
//            //          （见下图，由于中间状况未知，对于left下标而言，right_max未必就是它右边最大的值）
//            //                                           right_max
//            //         left_max                             __
//            //           __                                |  |
//            //          |  |__   __??????????????????????  |  |
//            //        __|     |__|                       __|  |__
//            //                left                      right
//            //·定理三：当我们从右往左处理到right下标时，右边的最大值right_max对它而言是可信的，但left_max对它而言是不可信的。
//            //·对于位置left而言，它左边最大值一定是left_max，右边最大值“大于等于”right_max，这时候，如果left_max < right_max成立，
//            //  那么它就知道自己能存多少水了。无论右边将来会不会出现更大的right_max，都不影响这个结果。 
//            //  所以当left_max < right_max时，我们就希望去处理left下标，反之，我们希望去处理right下标。
//            res += leftMax - height[left];
//            ++left;
//        }
//        else {
//            res += rightMax - height[right];
//            --right;
//        }
//    }
//    //************************单调栈*************************
//    /*int res = 0;
//    stack<int> stk;
//    int n = height.size();
//    for (int i = 0; i < n; ++i) {
//        while (!stk.empty() && height[i] > height[stk.top()]) {
//            int top = stk.top();
//            stk.pop();
//            if (stk.empty()) {
//                break;
//            }
//            int left = stk.top();
//            int currWidth = i - left - 1;
//            int currHeight = min(height[left], height[i]) - height[top];
//            res += currWidth * currHeight;
//        }
//        stk.push(i);
//    }*/
//    cout << res << endl;
//    return 0;
//}

//////////////////////////////////////////////接雨水Ⅱ////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/trapping-rain-water-ii/solution/you-xian-dui-lie-de-si-lu-jie-jue-jie-yu-shui-ii-b/389407
//typedef pair<int, pair<int, int>> pip;//pair<高度，pair<行号，列号>>
//void main()
//{
//    vector<vector<int>> heightMap = { {1, 4, 3, 1, 3, 2},{3, 2, 1, 3, 2, 4},{2, 3, 3, 2, 3, 1} };
//    priority_queue<pip, vector<pip>, greater<pip>> pq;//小顶堆，从最外围开始按高度从小到大存放
//    //为什么从最外围开始？因为一个中心块能接雨水的数量取决于四个方向的高度最小值与自身高度的差值
//    //为什么是小顶堆？因为这样可以保证高度较小的块先出队
//    //为什么要让高度较小的块先出队？(关键点)
//    //  1. 一开始时候就讲了基础做法是：对于每一个块，去找它四个方向最高的高度中的最小值(二维下则是左右最高的高度取较小的那一个)作为上界，当前块作为下界
//    //  2. 而我们现在反过来不是以中心块为处理单元，而是以四周作为处理单元
//    //  3. 我们如果能确保当前出队的元素对于该中心块来说是它四个方向高度中的最小值（注意不是四周相邻的高度最小值，而是四个方向上的）那么就能确定接雨水的大小
//    //  4. 为什么队头元素的高度比中心块要高它就一定是中心块周围四个高度中的最小值呢？
//    //    因为我们的前提就是小顶堆：高度小的块先出队，所以对于中心块来说，先出队的必然是中心块四周高度最小的那一个
//    bool vis[201][201] = { false };//防止重复遍历，bool变量在未初始化之前是true（204），不是true也不是false，所以后面会出错
//    int dirx[4] = { 0, 0, 1, -1 };
//    int diry[4] = { 1, -1, 0, 0 };
//    int n = heightMap.size(), m = heightMap[0].size(), ans = 0;
//    if (m < 3 || n < 3)
//    {
//        cout << 0 << endl;
//        return;
//    }
//    for (int i = 0; i < n; i++) {//最外围的一圈不能接雨水，因此高度不变，直接入队
//        for (int j = 0; j < m; j++) {
//            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
//                pq.push(make_pair(heightMap[i][j], make_pair(i, j)));
//                vis[i][j] = true;
//            }
//        }
//    }
//    while (!pq.empty()) {
//        int h = pq.top().first, x = pq.top().second.first, y = pq.top().second.second;//队首元素的高度最低，可能作为其他未入队中心块的边界，因此看它四周相邻的中心块是否能存放雨水
//        cout << h << ' ' << x << ' ' << y << endl;
//        pq.pop();
//        for (int i = 0; i < 4; i++) {
//            int nx = dirx[i] + x, ny = diry[i] + y;
//            if (nx >= 0 && nx < n && ny >= 0 && ny < m && (!vis[nx][ny])) {
//                if (heightMap[nx][ny] < h) {//如果某个中心块的高度比队首元素的高度低，那么这个中心块就一定可以存放雨水，那么就加入结果
//                    ans += h - heightMap[nx][ny];
//                }
//                vis[nx][ny] = 1;//不管能不能存放雨水，这个中心块都已被访问
//                //如果这个中心块能够存放雨水，那就说明heightMap[nx][ny] < h，那么它的高度就要变成h，
//                //否则对于更靠中心的中心块来说，它四个方向高度的最小值就被拉低了，接雨水的数量就变少了
//                //如果如果这个中心块不能存放雨水，那就说明heightMap[nx][ny] >= h，那么它的高度不变，加入队列后成为其他中心块的边界
//                pq.push(make_pair(max(heightMap[nx][ny], h), make_pair(nx, ny)));
//            }
//        }
//    }
//    cout << ans << endl;
//}

//////////////////////////////////////////////最近的公共祖先节点////////////////////////////////////////////////////

//struct TreeNode {
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//class Solution {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {//如果当前结点 root 等于 NULL，则直接返回 NULL
//                                                                              // 如果 root 等于 p 或者 q ，那这棵树一定返回 p 或者 q
//                                                                    //然后递归左右子树，因为是递归，使用函数后可认为左右子树已经算出结果，用 left 和 right 表示
//                                                                    // 此时若left为空，那最终结果只要看 right；若 right 为空，那最终结果只要看 left
//                                                            // 如果 left 和 right 都非空，因为只给了 p 和 q 两个结点，都非空，说明一边一个，因此 root 是他们的最近公共祖先
//                                                                    // 如果 left 和 right 都为空，则返回空（其实已经包含在前面的情况中了）
//
//        if (root == NULL)
//            return NULL;
//        if (root == p || root == q)
//            return root;
//
//        TreeNode* left = lowestCommonAncestor(root->left, p, q);
//        TreeNode* right = lowestCommonAncestor(root->right, p, q);
//
//        if (left == NULL)
//            return right;
//        if (right == NULL)
//            return left;
//        if (left && right) // p和q在两侧
//            return root;
//
//        return NULL; // 必须有返回值
//    }
//};
//int main()
//{
//    TreeNode* node1 = new TreeNode(3);
//    TreeNode* node2 = new TreeNode(5);
//    TreeNode* node3 = new TreeNode(1);
//    TreeNode* node4 = new TreeNode(6);
//    TreeNode* node5 = new TreeNode(2);
//    TreeNode* node6 = new TreeNode(0);
//    TreeNode* node7 = new TreeNode(8);
//    TreeNode* node8 = new TreeNode(7);
//    TreeNode* node9 = new TreeNode(4);
//    node1->left = node2;
//    node1->right = node3;
//    node2->left = node4;
//    node2->right = node5;
//    node3->left = node6;
//    node3->right = node7;
//    node5->left = node8;
//    node5->right = node9;
//    Solution so;
//    TreeNode* res = so.lowestCommonAncestor(node1, node9, node8);
//    cout << res->val << endl;
//}

//////////////////////////////////////////////相同的元素放在一起////////////////////////////////////////////////////


//int main()
//{
//    vector<int> nums = { 2,0,2,1,1,0 };
//    //**********************单指针*******************
//    /*int n = nums.size();
//    int ptr = 0;
//    for (int i = 0; i < n; ++i) {
//        if (nums[i] == 0) {//ptr 中存储了一个整数，表示数组nums 从位置 0 到位置ptr−1 都属于「头部」,头部中存储的都是0，换言之ptr左边的数都是0（不包括ptr本身的位置）
//            swap(nums[i], nums[ptr]);
//            ++ptr;
//        }
//    }
//    for (int i = ptr; i < n; ++i) {
//        if (nums[i] == 1) {
//            swap(nums[i], nums[ptr]);
//            ++ptr;
//        }
//    }*/
//    //**********************双指针*******************
//    int n = nums.size();
//    int p0 = 0, p1 = 0;
//    for (int i = 0; i < n; ++i) {
//        if (nums[i] == 1) {
//            swap(nums[i], nums[p1]);
//            ++p1;
//        }
//        else if (nums[i] == 0) {
//            swap(nums[i], nums[p0]);
//            if (p0 < p1) {//和单指针相似，p0左边都是0，p0到p1左边都是1（左边不包括本身），如果p0<p1，直接换的话就把1换到后面去了，必须要再换一遍
//                swap(nums[i], nums[p1]);
//            }
//            ++p0;
//            ++p1;
//        }
//    }
//}

//////////////////////////////////////////////快速、希尔、归并、堆排序法（数组排序）////////////////////////////////////////////////////

////*******************************************快速排序******************************************************
//int standard(vector<int>& nums, int low, int high)
//{
//    int k = rand() % (high - low + 1) + low;//在[low,high]之间随机产生一个下标，并以这个下标的值为后面的判断依据
//    swap(nums[low], nums[k]);//必须要交换，如果不交换而直接用nums[k]去比较的话，会丢失最左端nums[left]的值，因为后面直接把nums[low] = nums[high]，而此时nums[low]没有保存
//	int temp = nums[low];//而交换的话就可以用temp去保存nums[k]的值，而nums[k]保存的就是nums[low]的值
//	while (low < high)
//	{
//		while (low < high && nums[high]>=temp) //如果这里不加low<high的话，在升序排列的数组中high会一直减小到-1，造成数组越界
//		{
//			--high;
//		}
//		nums[low] = nums[high];
//		while (low < high && nums[low] <= temp)//同理
//		{
//			++low;
//		}
//		nums[high] = nums[low];
//	}
//	nums[low] = temp;
//	return low;
//}
//void quicksort(vector<int>& nums, int low, int high)
//{
//	if (low < high)
//	{
//		int index=standard(nums, low, high);
//		quicksort(nums, low, index - 1);
//		quicksort(nums, index+1, high);
//	}
//}
//
////*************************************************希尔排序(gap=len/2的时候完全正确，比快速排序更快）**********************************************
//void shellsort(vector<int>& nums, int len)
//{
//    int increment = 2;//至少有多少个数分为同一组
//    int temp = 0;
//    int gap = len / increment; // 步长初始化
//    while (gap) // while gap>=1
//    {
//        for (int i = gap; i <= len; ++i) // 分组，在每个子序列中进行插入排序
//        {
//            temp = nums[i];//将当前的元素值先存起来方便后面插入
//            int j = i;
//            while (j >= gap && temp < nums[j - gap])//寻找插入位置
//            {
//                nums[j] = nums[j - gap];
//                j -= gap;
//            }
//            nums[j] = temp;
//        }
//        gap = gap / increment;
//    }
//}
//
//***************************************************************归并排序************************************************************
//void merge(vector<int>& array, int start, int mid, int end, vector<int>& tmp)
//{
//    int i = start;//start是左边分支的开头，mid是左边分支的结尾，则左边分支个数是 mid-left+1
//    int j = mid + 1;//mid + 1 是右边分支的开头，end是右边分支的结尾，则右边分支个数是 end - (mid + 1) + 1 = end - mid，左右分支总共有 end - left + 1 个数
//    for (int k = start;k <= end;k++)
//    {
//        tmp[k] = array[k];
//    }
//    //将左右两个分支比较合并，这是 归并 的实现
//    for (int k = start; k <= end; ++k)
//    {//要处理的数总共有 end-left+1 个，从start开始，到end结束，注意两个都是闭区间
//        //此处会发生合并，分别进行比较，总共比较k次，复杂度O(k)
//        if ((i <= mid && j <= end && tmp[i] <= tmp[j]) || j == end+1)
//        {
//            array[k] = tmp[i];
//            i = i + 1;
//        }
//        else if ((i <= mid && j <= end && tmp[i] > tmp[j]) || i==mid+1)
//        {
//            array[k] = tmp[j];
//            j = j + 1;
//        } 
//    }
//}
//void mergesort(vector<int>& array, int start, int end, vector<int>& tmp)
//{
//    if (start < end)
//    {//start，end都是闭区间，所以 start==end 的时候就只有一个数了，不需要再分了
//        int temp = (start + end) / 2;
//        //开始递归
//        mergesort(array, start, temp, tmp);//左分支
//        //关于传参temp + 1 如果start和end之间的差为1，则直接对两个数进行排序
//        mergesort(array, temp + 1, end, tmp);//右分支
//        merge(array, start, temp, end,tmp);//左右分支合并，左分支可能比右分支多一个数
//    }
//}
//***************************************************************堆排序************************************************************
// 从大到小排序
//void HeapSort_greater(vector<int>& array, int i, int n) { // 最后结果就是小顶堆
//    int parent = i;                    // 父节点下标
//    int child = 2 * i + 1;            // 左子节点下标
//    while (child < n) {
//        if (child + 1 < n && array[child] > array[child + 1]) { // 判断子节点哪个小，小的与父节点比较，比父节点还小的话就交换，因为是小顶堆
//            child++;
//        }
//        if (array[parent] > array[child]) { // 判断父节点是否大于子节点
//            swap(array[parent], array[child]); // 大于就交换父节点和子节点    
//            parent = child;        //交换上层的节点会导致子树结构混乱，因此对子树重新排序，子节点下标 赋给 父节点下标
//            child = child * 2 + 1; // 比较下面的父节点和子节点
//        }
//        else
//        {
//            return;//否则的话以当前节点为根的子树已经是一个小根堆了，直接返回即可
//        }
//    }
//}
//// 从小到大排序
//void HeapSort_less(vector<int>& array, int i, int n) { // 最后结果就是大顶堆
//    int parent = i;                    // 父节点下标
//    int child = 2 * i + 1;            // 子节点下标
//    while (child < n) {
//        if (child + 1 < n && array[child] < array[child + 1]) { // 判断子节点那个大，大的与父节点比较
//            child++;
//        }
//        if (array[parent] < array[child]) { // 判断父节点是否小于子节点
//            swap(array[parent], array[child]); // 交换父节点和子节点    
//            parent = child;        //交换上层的节点会导致子树结构混乱，因此对子树重新排序，子节点下标 赋给 父节点下标
//            child = child * 2 + 1; // 比较下面的父节点和子节点
//        }
//        else
//        {
//            return;//否则的话以当前节点为根的子树已经是一个大根堆了，直接返回即可
//        }
//    }
//}
//void HeapSort(vector<int>& array, int size) {
//    for (int i = size / 2 - 1; i >= 0; i--) // 初始化堆
//    { // 第一个非叶子节点的索引是 数组长度 n/2 - 1 
//        HeapSort_less(array, i, size);                 // 否则有的不符合大顶堆定义
//    }
//    for (int i = size - 1; i > 0; i--) {
//        swap(array[0], array[i]); // 交换顶点和第 i 个数据     
//        HeapSort_less(array, 0, i); // 取出堆顶元素之后就需要重新建立大顶堆，但是此时不需要从第一个非叶子节点（从下往上）开始了，只需要从当前的堆顶元素开始，从上往下调整它的位置就行了
//        //HeapSort_greater(array, 0, i);// 取出堆顶元素之后就需要重新建立小顶堆，但是此时不需要从第一个非叶子节点（从下往上）开始了，只需要从当前的堆顶元素开始，从上往下调整它的位置就行了
//    }
//}
//void main()
//{
//	vector<int> nums = { 4,1,5,2,7,3,8,6,0,9,7,5,2};//总共 13 个数，分的时候左边比右边可能多一个
//    int n = nums.size();
//
//	//quicksort(nums, 0, n - 1)//快速排序
//
//	//shellsort(nums, n-1);//希尔排序
//
//    vector<int> tmp(n);//归并排序需要额外开辟一块空间,提前创建好并且将引用传递进去，可以大幅减少开辟空间的时间
//    mergesort(nums, 0, n - 1, tmp);//归并排序
//
//    //HeapSort(nums, n);//堆排序，把nums当成层次遍历的结果，建立大顶堆/小顶堆，然后取出堆顶的值
//	for (auto i : nums)
//	{
//		cout << i << "  ";
//	}
//}

//////////////////////////////////////////////归并排序法（链表排序）////////////////////////////////////////////////////

//**************************************************递归法，空间复杂度是O(logn)**********************************************
//找到链表中间节点（876、链表的中间节点）
//ListNode* middlenode(ListNode* head) {
//    if (head == nullptr || head->next == nullptr) 
//        return head;
//    ListNode* slow = head;
//    ListNode* fast = head;
//
//    while (fast->next != nullptr && fast->next->next != nullptr) {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    return slow;
//}
////合并两个有序链表（21、合并两个有序链表）
//ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//    ListNode* dummy = new ListNode(-1);
//    ListNode* pre = dummy;
//    while (list1 != nullptr && list2 != nullptr) {
//        if (list1->val > list2->val) {
//            pre->next = list2;
//            list2 = list2->next;
//            pre = pre->next;
//        }
//        else {
//            pre->next = list1;
//            list1 = list1->next;
//            pre = pre->next;
//        }
//    }
//    pre->next = list1 != nullptr ? list1 : list2;
//    return dummy->next;
//}
//ListNode* sortList(ListNode* head) {
//    //1、递归结束条件，只有一个节点或者传入的root不存在时，直接返回
//    if ( head == nullptr || head->next == nullptr)
//        return head;
//
//    //2、找到链表中间节点并且断开链表，分成左右两部分，偶数的时候左右两边相等，奇数的时候左边比右边多一个
//    ListNode* midnode = middlenode(head);
//    ListNode* rightnode = midnode->next;
//    midnode->next = nullptr;
//
//    ListNode* left = sortList(head);
//    ListNode* right = sortList(rightnode);
//    //合并有序的链表
//    return mergeTwoLists(left, right);
//}
//int main()
//{//1-4-6-2-3-7-5-8
//    ListNode* eig = new ListNode(8, nullptr);
//    ListNode* fiv = new ListNode(5, eig);
//    ListNode* sev = new ListNode(7, fiv);
//    ListNode* thr = new ListNode(3, sev);
//    ListNode* two = new ListNode(2, thr);
//    ListNode* six = new ListNode(6, two);
//    ListNode* fou = new ListNode(4, six);
//    ListNode* one = new ListNode(1, fou);
//    ListNode* res = sortList(one);
//    while (res != nullptr)
//    {
//        cout << res->val << ' ';
//        res = res->next;
//    }
//    return 0;
//}
//**************************************************递归法，空间复杂度是O(1)**********************************************
//ListNode* cut(ListNode* head, int n) {
//    auto p = head;
//    while (--n && p) {
//        p = p->next;
//    }
//
//    if (!p) return nullptr;
//
//    auto next = p->next;
//    p->next = nullptr;
//    return next;
//}
//ListNode* merge(ListNode* l1, ListNode* l2) {
//    ListNode dummyHead(0);
//    auto p = &dummyHead;
//    while (l1 && l2) {
//        if (l1->val < l2->val) {
//            p->next = l1;
//            p = l1;
//            l1 = l1->next;
//        }
//        else {
//            p->next = l2;
//            p = l2;
//            l2 = l2->next;
//        }
//    }
//    p->next = l1 ? l1 : l2;
//    return dummyHead.next;
//}
//ListNode* sortList(ListNode* head) {
//    ListNode dummyHead(0);
//    dummyHead.next = head;
//    auto p = head;
//    int length = 0;
//    while (p) {
//        ++length;
//        p = p->next;
//    }
//    for (int size = 1; size < length; size <<= 1) {
//        auto cur = dummyHead.next;
//        auto tail = &dummyHead;
//
//        while (cur) {
//            auto left = cur;
//            auto right = cut(left, size); // left->@->@ right->@->@->@...
//            cur = cut(right, size); // left->@->@ right->@->@  cur->@->...
//
//            tail->next = merge(left, right);
//            while (tail->next) {
//                tail = tail->next;
//            }
//        }
//    }
//    return dummyHead.next;
//}
//int main()
//{//4-3-2-6-5-7-1
//    ListNode* one = new ListNode(1, nullptr);
//    ListNode* sev = new ListNode(7, one);
//    ListNode* fiv = new ListNode(5, sev);
//    ListNode* six = new ListNode(6, fiv);
//    ListNode* two = new ListNode(2, six);
//    ListNode* thr = new ListNode(3, two);
//    ListNode* fou = new ListNode(4, thr);
//    ListNode* res = sortList(fou);
//    while (res != nullptr)
//    {
//        cout << res->val << ' ';
//        res = res->next;
//    }
//    return 0;
//}

//////////////////////////////////////////////基于快速选择（快速排序的简化）找到第k个最大值////////////////////////////////////////////////////

//https://leetcode.cn/problems/kth-largest-element-in-an-array/solution/shu-zu-zhong-de-di-kge-zui-da-yuan-su-by-leetcode-/
//int quickselect(vector<int>& arr, int left, int right, int index)
//{//这里不用考虑left会大于right，因为当left==right的时候找到的q一定等于index，一定会返回，当然加上一个if可以防止意外
//    int q = standard(arr, left, right);//返回一个找到自己正确位置的元素的下标q，他是第 n-q 个最大值，下标为 q
//    if (q == index)
//    {//如果这个正确元素下标等于我们想找的下标index，说明这个元素就是第k个最大值，直接返回
//        return arr[q];
//    }
//    //否则当q比index小的时候，说明它比我们真正想找的数小，所以只需要在右边（比它大的数）里面查找；当q比index大的时候，说明它比我们真正想找的数大，所以只需要在左边（比它小的数）里面查找
//    return (q < index ? quickselect(arr, q + 1, right, index) : quickselect(arr, left, q - 1, index));
//}
//int findKthLargest(vector<int>& nums, int k) {
//    int n = nums.size();
//    return quickselect(nums, 0, n - 1, n - k);//第k个最大值的下标是 n-k
//}
//int main()
//{
//    vector<int> nums = { 2,1 };
//    cout << findKthLargest(nums, 2) << endl;
//    return 0;
//}

//////////////////////////////////////////////根据字母出现次数降序排列（自定义排序模板函数）////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/sort-characters-by-frequency/
//struct cmp
//{
//    template <typename T, typename U>
//    bool operator()(T const& left, U const& right)
//    {
//
//        return left.first < right.first || (left.first == right.first && left.second > right.second);
//    }
//};
//int main()
//{
//    string s = "treeaa";
//    unordered_map<char, int> mymap;
//    for (auto ch : s)
//    {
//        mymap[ch]++;
//    }
//    priority_queue<pair<int ,char>,vector<pair<int,char>>,cmp> que;
//    for (auto f : mymap)
//    {
//        que.push(make_pair(f.second, f.first));
//    }
//    string res;
//    while(!que.empty())
//    {
//        res.append(que.top().first, que.top().second);
//        que.pop();
//    }
//    cout << res;
//}

//////////////////////////////////////////////字符和.和*字符匹配（DP）////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/regular-expression-matching/solution/shou-hui-tu-jie-wo-tai-nan-liao-by-hyj8/
//int main() 
//{
//    string s = "aa";
//    string p = "a*";
//    int lens = s.size();
//    int lenp = p.size();
//    //dp[i][j]:表示s的前i个字符（包括第i个），p的前j个字符是否能够匹配，也就是s[0:i-1]和p[0:j-1]能否匹配
//    vector<vector<bool>> dp(lens + 1, vector<bool>(lenp + 1, false));
//    //初始化 
//    dp[0][0] = true;//两个空字串一定匹配
//    for (int j = 1;j < lenp + 1;j++)//找出s为空 但p因为* 为空的情况，不用考虑dp[i][0]的情况，因为p为空，s不为空的话一定是false
//    {
//        if (p[j-1] == '*')
//        //*只能抵消它的前面一个字符，所以dp[0][j] = dp[0][j - 2];这里是因为j表示的是下标，dp里面的i和j表示位置，位置比下标大1，所以dp[0][j]对应的是p[j-1]
//        //·比如s="",p="a*",dp[1][3],dp[0][0]=true,dp[0][1]=false;j=2时，p[2-1=1]='*',那么dp[0][2]=dp[0][2-2]=>dp[0][2]=dp[0][0]=true，说明*可以抵消前面的a
//        //·再比如s="",p="ab*",dp[1][4],dp[0][0]=true,dp[0][1]=false,dp[0][2]=false,j=3时，p[3-1=2]='*',那么dp[0][3]=dp[0][3-2]=>dp[0][3]=dp[0][1]=false，
//        //  说明*可以抵消前面的b,但是b前面还有一个a不能抵消，所以dp[0][3]=false。
//        {
//            dp[0][j] = dp[0][j - 2];//题目有保证的保证每次出现字符 * 时，前面都匹配到有效的字符，也就是*不可能出现在p[0]这个位置,也就是j=1时，p[j-1]永远不可能等于 *，因此j其实可以从2开始
//        }
//    }
//    //更新
//    for (int i = 1;i < lens + 1;i++)//从s的第1个字符开始
//    {
//        for (int j = 1;j < lenp + 1;j++)//从p的第1个字符开始
//        {
//            if (s[i - 1] == p[j - 1] || p[j - 1] == '.')//情况1：符合，直接更新
//            {
//                dp[i][j] = dp[i - 1][j - 1];
//            }
//            else if (p[j - 1] == '*')//情况2：考虑*的情况
//            {
//               //a1 - 例子：s = "aab", p = "aabb*", 干掉“b* ”，p' = "aab" == s；所以，干掉“b*”，相当于*让第2个b重复0次（即抹掉了第二个b），属于a1情况，
//               //    这种情况就是，不看p串的末尾两个，就看p(0,j-3)与s(0,i-1)是否相同，相同就是true。此种情况下，推导公式为：dp(i)(j) = dp(i)(j-2)
//               //a2 - 例子：s = "aab", p = "aab*"，p(j - 1) = "*", p(j - 2) == s(i - 1) = b， * 使得b重复1次，看p(0, j - 3)与s(0, i - 2)是否相同
//               //a3 - 例子: s = "aabb"（或s = "aabbb"都行）, p = "aab*"。不难看出，p末尾的 * 使得b重复了2次（或3次），符合情况a3。
//               //    这种情况，已知s(i - 1) = p(j - 2)， * 使得p(j - 2)这个字符重复1次匹配了s(i - 1)， * 能不能使得p(j - 2)再与s(i - 2)字符继续匹配，
//               //    那就把s串的末尾字符去掉，查看p(0, j - 1)能否继续与s(0, i - 2)匹配了。此时，推导公式为：dp(i)(j) = dp(i - 1)(j)
//                if (s[i - 1] == p[j - 2] || p[j - 2] == '.')
//                {
//                    dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] || dp[i - 1][j];//分别是  重复0次；重复一次；重复两次及以上！！！
//                }
//                else//s[i-1] p[j-2]不匹配  *需要重复0次
//                {
//                    dp[i][j] = dp[i][j - 2];
//                }
//            }
//        }
//    }
//    cout << dp[lens][lenp] << endl;
//    return 0;
//}

////////////////////////////////////////////////利用栈简化目录////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/simplify-path/comments/69661
//void main()
//{
//    vector<string> v;
//    string path = "/a/./b/../../c/"; 
//    istringstream iss(path);
//    string buf;
//    while (getline(iss, buf, '/')) {//将输入流以/分割开
//        if (!buf.empty() && buf != "." && buf != "..") {//当buf不是返回上一级，也不是停在当前目录
//            v.push_back(buf);//就进入下一目录
//        }
//        else if (!v.empty() && buf == "..") {//否则，如果此时不在根目录（也就是v非空），那么返回上一级是有效的，把当前目录弹出，返回上一级
//            v.pop_back();
//        }
//    }
//    if (v.empty()) {//如果v是空的，说明是在根目录，则输出/后直接返回
//        cout<< "/"<<endl;
//        return ;
//    }
//
//    buf.clear();
//    for (string& s : v) {//否则就逐个把路径还原出来，这里用vector而不是栈就是因为我们要从头遍历，因此不能用栈
//        buf += "/";
//        buf += s;
//    }
//    return;
//}

//////////////////////////////////////////////计算陆地个数////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/number-of-islands/
//void dfs(vector<vector<int>>& grid, int r, int c) {
//    int nr = grid.size();
//    int nc = grid[0].size();
//
//    grid[r][c] = 0;
//    if (r - 1 >= 0 && grid[r - 1][c] == 1) dfs(grid, r - 1, c);
//    if (r + 1 < nr && grid[r + 1][c] == 1) dfs(grid, r + 1, c);
//    if (c - 1 >= 0 && grid[r][c - 1] == 1) dfs(grid, r, c - 1);
//    if (c + 1 < nc && grid[r][c + 1] == 1) dfs(grid, r, c + 1);
//}
//void main()
//{
//    vector<vector<int>> grid = { {1, 1, 0, 0, 0},
//            {1, 1, 0, 0, 0},
//            {0, 0, 1, 0, 0},
//            {0, 0, 0, 1, 1} };
//    //****************广度优先*******************
//    /*int m = grid.size();
//    int n = grid[0].size();
//    vector<vector<int>> vis(m, vector<int>(n));
//    queue<pair<int, int>> que;
//    int res = 0;
//    for (int i = 0;i < m;++i)
//    {
//        for (int j = 0;j < n;++j)
//        {
//            if (grid[i][j] == 1 && vis[i][j] == 0)
//            {
//                que.push(make_pair(i, j));
//                while (!que.empty())
//                {
//                    auto t = que.front();
//                    
//                    for (auto f : vector<pair<int, int>>{ {t.first - 1,t.second},{t.first + 1,t.second},{t.first,t.second - 1},{t.first,t.second + 1} })
//                    {
//                        if (0 <= f.first && f.first < m && f.second >= 0 && f.second < n)
//                        {
//                            if (vis[f.first][f.second] == 0 && grid[f.first][f.second] == 1 )
//                            {
//                                que.push(f);
//                                vis[f.first][f.second] = 1;
//                            }
//                        }
//                     
//                    }
//                    que.pop();
//                }
//                res++;
//            }
//        }
//    }*/
//    //*****************深度优先*******************
//    int nr = grid.size();
//    int nc = grid[0].size();
//
//    int res = 0;
//    for (int r = 0; r < nr; ++r) {
//        for (int c = 0; c < nc; ++c) {
//            if (grid[r][c] == 1) {
//                ++res;
//                dfs(grid, r, c);
//            }
//        }
//    }
//    cout << res << endl;
//}

//////////////////////////////////////////////前序遍历二叉树并且变成只含右子支的树////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/
//class Solution {//前序遍历二叉树
//public:
//    queue<TreeNode*> que;
//    void leftfirst(TreeNode* node)
//    {
//        if (node != nullptr)
//        {
//            que.push(node);
//            if (node->left != nullptr)
//            {
//                leftfirst(node->left);
//            }         
//            if (node->right != nullptr)
//            {
//                leftfirst(node->right);
//            }   
//        }
//    }
//    void flatten(TreeNode* root) {//把二叉树转化为只含右孩子的数，左孩子为空指针
//        leftfirst(root);
//        TreeNode* res= que.front();
//        while (!que.empty())
//        {
//            TreeNode* temp = que.front();
//            que.pop();
//            if (!que.empty())
//            {
//                temp->right = que.front();
//                temp->left = nullptr;
//            }           
//        }
//        while (res)
//        {
//            cout << res->val << endl;
//            res = res->right;
//        }
//    }
//};
//void main()
//{
//    TreeNode* six = new TreeNode(6);
//    TreeNode* three = new TreeNode(3);
//    TreeNode* four = new TreeNode(4);
//    TreeNode* five = new TreeNode(5,nullptr,six);
//    TreeNode* two = new TreeNode(2,three,four);
//    TreeNode* one = new TreeNode(1,two,five);
//    Solution so;
//    so.flatten(one);  
//}

//////////////////////////////////////////////字符串匹配次数（DP）////////////////////////////////////////////////////

//int main(){
//    string s = "babgbag", t = "bag";
//    int sz = s.size();
//    int tz = t.size();
//    vector<vector<long long>> dp(sz + 1, vector<long long>(tz + 1, 0));//dp[i][j]表示s[0:i-1]字串和t[0:j-1]字串能够匹配的次数(可以删除s中的字符）
//    for (int i = 0; i <= sz; ++i)//t是空串时，任意s都只能匹配一次，s是空串时，任意t都不能匹配（初始值为0）
//        dp[i][0] = 1;
//    for (int i = 1; i <= sz; ++i)//从s的第一个字符s[0]开始遍历
//        for (int j = 1; j <= tz; ++j) {//从t的第一个字符s[0]开始遍历
//            if (j > i) continue;//j比i大，肯定无法在s[0:i-1]字串中找到t[0:j-1]字串，不需要计算
//            if (s[i - 1] == t[j - 1]) {
              //当前字符相同的时候，dp[i][j]取决于s、t都删除该字符的次数加上s删除该字符的次数，我们考虑是否要将s[i-1]当成t中的一部分，是的话就是dp[i - 1][j - 1]，否的话就是dp[i - 1][j]
              //·比如s[6]=t[2]='g',dp[7][3]就等于在s="babgba"中找t="ba"的匹配次数加上s="babgba"中找t="bag"的匹配次数，也就是s[6]='g'是否是合法的
//                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
//            }
//            else {
//                dp[i][j] = dp[i - 1][j];//字符不相等的时候就只能删除s中的该字符
//            }
//        }
//    cout<<dp[sz][tz]<<endl;
//}

//////////////////////////////////////////////合并区间和插入区间////////////////////////////////////////////////////

//void main()
//{
//    //**********************合并区间**************************
//    //vector<vector<int>> intervals = { {1,3},{0,6},{8,10},{15,18} };
//    //sort(intervals.begin(), intervals.end());//排序非常重要
//    //vector<vector<int>> merged;
//    //for (int i = 0; i < intervals.size(); ++i) {
//    //    int L = intervals[i][0], R = intervals[i][1];
//    //    if (!merged.size() || merged.back()[1] < L) {
//    //        merged.push_back({ L, R });
//    //    }
//    //    else {
//    //        merged.back()[1] = max(merged.back()[1], R);
//    //    }
//    //}
//    //for (int i = 0;i < merged.size();++i)
//    //{
//    //    for (int j = 0;j < merged[0].size();++j)
//    //    {
//    //        cout << merged[i][j] << " ";
//    //    }
//    //    cout << endl;
//    //}
//    //****************************插入区间***********************
//    vector<vector<int>> intervals = { {1, 2},{3, 5},{6, 7},{19, 21},{25, 27},{29,30} };
//    vector<int> newInterval = { 18,20 };
//    int left = newInterval[0];
//    int right = newInterval[1];
//    bool placed = false;
//    vector<vector<int>> ans;
//    for (const auto& interval : intervals) {
//        if (interval[0] > right) {
//            // 在插入区间的右侧且无交集
//            if (!placed) {//为了保证有序，需要找到第一个在合并区间后并且与其没有重叠的区间，插入新区间
//                ans.push_back({ left, right });
//                placed = true;
//            }
//            ans.push_back(interval);//然后再插入旧区间
//        }
//        else if (interval[1] < left) {
//            // 在插入区间的左侧且无交集，那就把原本区间插入，说明这个旧区间和新区间没有重叠
//            ans.push_back(interval);
//        }
//        else {
//            // 与旧的插入区间有交集，计算它们的并集，作为新的要插入的区间，注意这里并没有加入到结果集中，因为还不清楚要插入的位置
//            left = min(left, interval[0]);
//            right = max(right, interval[1]);
//        }
//    }
//    if (!placed) {//如果找不到插入位置（新区间在所有区间的后面），就插到最后
//        ans.push_back({ left, right });
//    }
//    for (int i = 0;i < ans.size();++i)
//    {
//        for (int j = 0;j < ans[0].size();++j)
//        {
//            cout << ans[i][j] << " ";
//        }
//        cout << endl;
//    }
//}

//////////////////////////////////////////////比较版本号的大小////////////////////////////////////////////////////

//int main()
//{
//    string version1 = "1.001";
//    string version2 = "1.01";
//    int len1 = version1.length(), len2 = version2.length();
//    int index1 = 0, index2 = 0;
//    while (index1 < len1 || index2 < len2) {
//        if (index1 < len1 && version1.at(index1) == '.')
//            index1++;
//        if (index2 < len2 && version2.at(index2) == '.')
//            index2++;
//        int curr1 = 0;
//        int curr2 = 0;
//        while (index1 < len1 && version1.at(index1) != '.')
//        {
//            curr1 = curr1 * 10 + version1.at(index1) - '0';
//            index1++;
//        }
//        while (index2 < len2 && version2.at(index2) != '.')
//        {
//            curr2 = curr2 * 10 + version2.at(index2) - '0';
//            index2++;
//        }
//        if (curr1 != curr2)
//            return curr1 < curr2 ? -1 : 1;
//    }
//    return 0;
//}

//////////////////////////////////////////////二叉搜索树删除某个结点////////////////////////////////////////////////////

//https://mp.weixin.qq.com/s?__biz=MzUxNjY5NTYxNA==&mid=2247485135&idx=1&sn=57d1de0ec50e5ccbd4cfd7703de59a8d&chksm=f9a2359eced5bc88ca9a66277310333e33940e5471b60bc97f7604b1de1a82ad79536e56063e&cur_album_id=1485825793120387074&scene=190#rd
//TreeNode* deleteNode(TreeNode* root, int key) {
//    if (root == nullptr) return root; // 第一种情况：没找到删除的节点，遍历到空节点直接返回了
//    if (root->val == key) {
//        // 第二种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
//        // 第三种情况：其左孩子为空，右孩子不为空，删除节点，右孩子补位 ，返回右孩子为根节点
//        if (root->left == nullptr) return root->right;
//        // 第四种情况：其右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
//        else if (root->right == nullptr) return root->left;
//        // 第五种情况：左右孩子节点都不为空，则将删除节点的左子树放到删除节点的右子树的最左面节点的左孩子的位置
//        // 并返回删除节点右孩子为新的根节点。
//        else {
//            TreeNode* cur = root->right; // 找右子树最左面的节点
//            while (cur->left != nullptr) {
//                cur = cur->left;
//            }
//            cur->left = root->left; // 把要删除的节点（root）左子树放在cur的左孩子的位置
//            TreeNode* tmp = root;   // 把root节点保存一下，下面来删除
//            root = root->right;     // 返回旧root的右孩子作为新root
//            delete tmp;             // 释放节点内存（这里不写也可以，但C++最好手动释放一下吧）
//            return root;
//        }
//    }
//    if (root->val > key) root->left = deleteNode(root->left, key);
//    if (root->val < key) root->right = deleteNode(root->right, key);
//    return root;
//}
//void main()
//{
//    TreeNode* fou = new TreeNode(4);
//    TreeNode* six = new TreeNode(6);
//    TreeNode* eig = new TreeNode(8);
//    TreeNode* ten = new TreeNode(10);
//    TreeNode* fiv = new TreeNode(5,fou,six);
//    TreeNode* nin = new TreeNode(9,eig,ten);
//    TreeNode* one = new TreeNode(1);
//    TreeNode* sev = new TreeNode(7,fiv,nin);
//    TreeNode* two = new TreeNode(2,one,sev);
//    deleteNode(two,7);
//}

//////////////////////////////////////////////回溯法-括号生成////////////////////////////////////////////////////

//class Solution {//如果当前左括号数量不大于 n，可以放一个左括号。如果右括号数量小于左括号的数量，可以放一个右括号
//    void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {//open是左括号的个数，close是右括号的个数
//        if (cur.size() == n * 2) {//如果当前字符串长度已达到2n个
//            ans.push_back(cur);
//            return;
//        }
//        if (open < n) {
//            cur.push_back('(');
//            backtrack(ans, cur, open + 1, close, n);
//            cur.pop_back();
//        }
//        if (close < open) {
//            cur.push_back(')');
//            backtrack(ans, cur, open, close + 1, n);
//            cur.pop_back();
//        }
//    }
//public:
//    vector<string> generateParenthesis(int n) {
//        vector<string> result;
//        string current;
//        backtrack(result, current, 0, 0, n);
//        return result;
//    }
//};
//void main()
//{
//    Solution so;
//    vector<string> res=so.generateParenthesis(3);
//    for (auto i : res)
//    {
//        cout << i << endl;
//    }
//}

//////////////////////////////////////////////暴力法-括号生成////////////////////////////////////////////////////

//class Solution {
//    bool valid(const string& str) {
//        int balance = 0;
//        for (char c : str) {
//            if (c == '(') {
//                ++balance;
//            }
//            else {
//                --balance;
//            }
//            if (balance < 0) {
//                return false;
//            }
//        }
//        return balance == 0;
//    }
//
//    void generate_all(string& current, int n, vector<string>& result) {
//        if (n == current.size()) {
//            if (valid(current)) {
//                result.push_back(current);
//            }
//            return;
//        }
//        current += '(';
//        generate_all(current, n, result);
//        current.pop_back();
//        current += ')';
//        generate_all(current, n, result);
//        current.pop_back();
//    }
//public:
//    vector<string> generateParenthesis(int n) {
//        vector<string> result;
//        string current;
//        generate_all(current, n * 2, result);
//        return result;
//    }
//};
//void main()
//{
//    Solution so;
//    vector<string> res = so.generateParenthesis(3);
//    for (auto i : res)
//    {
//        cout << i << endl;
//    }
//}

//////////////////////////////////////////////滑动窗口最大值////////////////////////////////////////////////////

//void main()
//{
//    vector<int> nums = { 1, 3, -1, -3, 2, 3, 6, 7 };
//    int k = 3;
//    //************************优先队列**********************
//    int n = nums.size();
//    priority_queue<pair<int, int>> q;//优先队列中存储二元组 (num,index)
//    for (int i = 0; i < k; ++i) {
//        q.emplace(nums[i], i);
//    }
//    vector<int> ans = { q.top().first };
//    for (int i = k; i < n; ++i) {
//        q.emplace(nums[i], i);
//        while (q.top().second <= i - k) {//如果优先队列头部的index不在窗口中，就把它从队列中删除，直到出现第一个在窗口中的index，i表示当前窗口的右端点，k是窗口大小，
//                                         //i-k就是当前窗口的左端点，index小于左端点就表明它不在窗口中
//            q.pop();
//        }
//        ans.push_back(q.top().first);
//    }
//    //vector<int> ans;
//    //************************单调队列**********************
//    //deque<int> dq;
//    //for (int i = 0;i < nums.size();++i)//遍历给定数组中的元素，如果队列不为空且当前考察元素大于等于队尾元素，则将队尾元素移除。
//    //                                   //直到队列为空或当前考察元素小于新的队尾元素；
//    //{
//    //    while (!dq.empty() && nums[i] >= nums[dq.back()])
//    //    {
//    //        dq.pop_back();
//    //    }
//    //    dq.push_back(i);
//    //    if (dq.front() <= i - k)//当队首元素的下标小于滑动窗口左侧边界i-k时，表示队首元素已经不再滑动窗口内，因此将其从队首移除。
//    //    {
//    //        dq.pop_front();
//    //    }
//    //    if (i >= k - 1)//i+1大于等于k时说明窗口已经形成了，这时候就要输出队首元素了
//    //    {
//    //        ans.push_back(nums[dq.front()]);
//    //    }
//
//    //}
//    for (auto i : ans)
//    {
//        cout << i << " ";
//    }
//}

///////////////////////////////////////////////找到某个值第一次和最后一次出现的位置////////////////////////////////

//计算下边界
//int lowerBound(vector<int>& nums, int target) {
//    int left = 0, right = nums.size() - 1;
//    while (left <= right) {
//        //这里需要注意，计算mid
//        int mid = left + ((right - left) >> 1);
//        if (target <= nums[mid]) {
//            //当目标值小于等于nums[mid]时，继续在左区间检索，找到第一个数
//            right = mid - 1;
//
//        }
//        else if (target > nums[mid]) {
//            //目标值大于nums[mid]时，则在右区间继续检索，找到第一个等于目标值的数
//            left = mid + 1;
//
//        }
//    }
//    return left;
//}
////计算上边界
//int upperBound(vector<int>& nums, int target) {
//    int left = 0, right = nums.size() - 1;
//    while (left <= right) {
//        int mid = left + ((right - left) >> 1);
//        if (target >= nums[mid]) {
//            left = mid + 1;
//        }
//        else if (target < nums[mid]) {
//            right = mid - 1;
//        }
//    }
//    return right;
//}
//void main()
//{
//    vector<int> nums = { 5,7,7,8,8,10 };
//    int target = 8;
//    int upper = upperBound(nums, target);
//    int low = lowerBound(nums, target);
//    //不存在情况
//    if (upper < low) {
//        for (auto i : vector<int>{ -1, -1 })
//        {
//            cout << i << ' ';
//        }
//        return;
//    }
//    for (auto i : vector<int>{ low, upper })
//    {
//        cout << i << ' ';
//    }
//}

//////////////////////////////////////////////是否是一个有效的二叉搜索树////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/validate-binary-search-tree/solution/yan-zheng-er-cha-sou-suo-shu-c-by-dululu-tmef/
//class Solution {
//public:
//    bool helper(TreeNode* root, long long lower, long long upper) {
//        if (root == nullptr) {
//            return true;
//        }
//        if (root->val <= lower || root->val >= upper) {
//            return false;
//        }
//        return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
//    }
//    bool isValidBST(TreeNode* root) {
//        return helper(root, LONG_MIN, LONG_MAX);//必须用LONG，因为测试集里面有[2^31-1],二叉搜索树的定义是左子树必须严格小于父节点，右子树必须严格大于父节点
//    }
//};
//void main()
//{
//    Solution so;
//    TreeNode* one = new TreeNode(1);
//    TreeNode* three = new TreeNode(3);
//    TreeNode* six = new TreeNode(6);
//    TreeNode* four = new TreeNode(4,three,six);
//    TreeNode* five = new TreeNode(5,one,four);
//    cout << so.isValidBST(five) << endl;
//}

//////////////////////////////////////////////一维01背包的二重属性DP////////////////////////////////////////////////////

////https://leetcode-cn.com/problems/ones-and-zeroes/
////给你⼀个⼆进制字符串数组 strs 和两个整数 m 和 n 。返回 strs 的最⼤⼦集的⼤⼩，该⼦集中 最多 有 m 个 0 和 n 个 1 。
//void main()
//{
//	vector<string> strs = { "10","0001","111001","1","0" };
//	int m = 5;
//	int n = 3;
//	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // 默认初始化0
//	for (string str : strs) { // 遍历物品
//		int oneNum = 0, zeroNum = 0;
//		for (char c : str) {
//			if (c == '0') zeroNum++;
//			else oneNum++;
//		}
//		for (int i = m; i >=zeroNum; i--) { // 遍历背包容量且从后向前遍历！i和j就是两重属性,i和j都是背包容量的一部分，不能分开看,因此这里实际上是01背包的一维形式，所以容量遍历的时候要逆序
//			for (int j = n; j >=oneNum; j--) {//就是说dp[i][j]这张二维表会刷新strs.size()次
//				dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);//这里dp可以是三维的，第一维k表示物品，
//				//那么这里应该改成dp[k][i][j]=max(dp[k-1][i][j],dp[k-1][i - zeroNum][j - oneNum] + 1),最后输出dp[k][m][n]就行了,实际上这是01背包的二维形式，那么就容量遍历可以是正序了
//			}
//		}
//		for (int i = 0;i <= m;++i)
//		{
//			for (int j = 0;j <= n;++j)
//			{
//				cout << dp[i][j] << ' ';
//			}
//			cout << endl;
//		}
//		cout << endl;
//	}
//}


//////////////////////////////////////////////三数之和为0////////////////////////////////////////////////////

//void main()
//{
//    vector<int> nums = { -1,0,1,2,-1,-4 };
//    vector<vector<int>> result;
//    sort(nums.begin(), nums.end());
//    // 找出a + b + c = 0
//    // a = nums[i], b = nums[left], c = nums[right]
//    for (int i = 0; i < nums.size(); i++) {
//        // 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
//        if (nums[i] > 0) {
//            return;
//        }
//        // 错误去重方法，将会漏掉-1,-1,2 这种情况
//        /*
//        if (nums[i] == nums[i + 1]) {
//            continue;
//        }
//        */
//        // 正确去重方法
//        if (i > 0 && nums[i] == nums[i - 1]) {
//            continue;
//        }
//        int left = i + 1;
//        int right = nums.size() - 1;
//        while (right > left) {
//            // 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
//            /*
//            while (right > left && nums[right] == nums[right - 1]) right--;
//            while (right > left && nums[left] == nums[left + 1]) left++;
//            */
//            if (nums[i] + nums[left] + nums[right] > 0) {
//                right--;
//            }
//            else if (nums[i] + nums[left] + nums[right] < 0) {
//                left++;
//            }
//            else {
//                result.push_back(vector<int>{nums[i], nums[left], nums[right]});
//                // 去重逻辑应该放在找到一个三元组之后
//                while (right > left && nums[right] == nums[right - 1]) right--;//确定abc后，固定a，查找left和right区间内所有与bc相同的数，全部跳过
//                while (right > left && nums[left] == nums[left + 1]) left++;
//
//                // 找到答案时，双指针同时收缩
//                right--;
//                left++;
//            }
//        }
//
//    }
//    for (int i = 0;i < result.size();++i)
//    {
//        for (int j = 0;j < result[0].size();++j)
//        {
//            cout << result[i][j] << ' ';
//        }
//        cout << endl;
//    }
//}

//////////////////////////////////////////////电话的组合数////////////////////////////////////////////////////

//void func(vector<string>& res, string str, string digits, int index, int len, unordered_map<char, string>& mp)
//{
//    if (index == len)
//    {
//        res.push_back(str);
//        return;
//    }
//    string tmp = mp[digits[index]];
//    for (auto ch : tmp)
//    {
//        str.push_back(ch);
//        func(res, str, digits, index + 1, len,mp);
//        str.pop_back();
//    }
//    return;
//}
//void main()
//{
//    unordered_map<char, string> mp = { {'2',"abc"},{'3',"def"},{'4',"ghi"},
//                                    {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},
//                                        {'8',"tuv"},{'9',"wxyz"} };
//    string digits = "234";
//    int len = digits.size();
//    if (len == 0)
//    {
//        return;
//    }
//    vector<string> res;
//    string str;
//    int index = 0;
//    func(res, str, digits, index, len,mp);
//    for (auto s : res)
//    {
//        cout << s <<endl;
//    }
//    return;
//}

//////////////////////////////////////////////双指针删除链表的倒数第N个结点////////////////////////////////////////////////////

//void main()
//{
//    ListNode* five = new ListNode(5);
//    ListNode* four = new ListNode(4,five);
//    ListNode* three = new ListNode(3,four);
//    ListNode* two = new ListNode(2,three);
//    ListNode* one = new ListNode(1,two);
//    ListNode* vHead = new ListNode(0, one);
//    ListNode* left = vHead;
//    ListNode* right = one;
//    int n = 1;
//    while (n--)
//    {
//        right = right->next;
//    }
//    while (right)
//    {
//        left = left->next;
//        right = right->next;
//    }
//    ListNode* tmp = left->next;
//    left->next = left->next->next;
//    delete tmp;
//    while (vHead->next)
//    {
//        cout << vHead->next->val << ' ';
//        vHead->next = vHead->next->next;
//    }
//}

///////////////////////////////////////////01背包////////////////////////////////////////////////////

//void test_2_wei_bag_problem1() {//二维形式
//    vector<int> weight = { 2,2,6,5,4 };
//    vector<int> value = { 6,3,5,4,6 };
//    int bagWeight = 10;
//    // ⼆维数组
//    vector<vector<int>> dp(weight.size(), vector<int>(bagWeight + 1, 0));//dp[i][j] 表示从下标为[0-i]的物品⾥任意取，放进容量为j的背包，价值总和最⼤是多少,物品范围是[0,m-1]，所以dp只需要m行
//                                                                         //而背包容量范围是[0,n]，所以dp需要n+1列
//    // 初始化
//    for (int j = bagWeight; j >= weight[0]; j--) {
//        dp[0][j] = dp[0][j - weight[0]] + value[0];
//    }
//    // weight数组的⼤⼩ 就是物品个数
//    for (int i = 1; i < weight.size(); i++) { // 遍历物品
//        for (int j = weight[i]; j <= bagWeight; j++) { // 遍历背包容量
//            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
//            for (int i = 0;i < weight.size();++i)
//            {
//                for (int j = 0;j < bagWeight + 1;++j)
//                {
//                    cout << dp[i][j] << ' ';
//                }
//                cout << endl;
//            }
//            cout << endl;
//        }
//    }
//    cout << dp[weight.size() - 1][bagWeight] << endl;
//}
//void test_1_wei_bag_problem() {//一维形式
//    vector<int> weight = { 1, 3, 4 };
//    vector<int> value = { 15, 20, 30 };
//    int bagWeight = 4;
//    // 初始化
//    vector<int> dp(bagWeight + 1, 0);
//    //******************先背包后物品的错误示范********************
//    for (int j = bagWeight; j >= 0; j--) { // 遍历背包容量，倒序
//        for (int i = 0; i < weight.size(); i++) { // 遍历物品
//            if (j >= weight[i])
//                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);//先背包后物品就会导致每一个容量的背包里只存放一件物品,因为背包是倒序，如果背包循环在外面的话（相当于竖着刷新dp数组），计算当前dp
//                                                                 //的值需要左上方的值和上方的值，而左上方的值还没有算出来（全都是0，因为背包倒序且竖着刷新），这就造成dp[j - weight[i]]全都是0，那么
//                                                                 //dp[j]=max(dp[j],value[i]）也就是选出当前背包容量下价值最大的一件物品。
//            for (auto i : dp)
//            {
//                cout << i << ' ';
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }
//    cout << dp[bagWeight] << endl;
//}
//int main() {
//    //test_2_wei_bag_problem1();
//    test_1_wei_bag_problem();
//}

//////////////////////////////////////////////完全背包物品与背包的内外循环问题////////////////////////////////////////////////////

//int change(int amount, vector<int>& coins) {
//    vector<int> dp(amount + 1, 0);
//    dp[0] = 1;
//    for (int j = 0; j <= amount; j++) { // 遍历背包
//        for (int i = 0; i < coins.size(); i++) { // 遍历物品
//            if (j - coins[i] >= 0)                      
//            {
//                dp[j] += dp[j - coins[i]];
//                
//            }
//            for (auto i : dp)
//            {
//                cout << i << ' ';
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }
//    //for (int i = 0; i < coins.size(); i++) { // 遍历物品
//    //    for (int j = 0; j <= amount; j++) { // 遍历背包
//    //        if (j - coins[i] >= 0)
//    //        {
//    //            dp[j] += dp[j - coins[i]];
//    //        }
//    //        for (auto i : dp)
//    //        {
//    //            cout << i << ' ';
//    //        }
//    //        cout << endl;
//    //    }
//    //    cout << endl;
//    //}
//    cout<< dp[amount]<<endl;
//    return 0;
//}
//int main() {
//    //test_CompletePack();
//    change(5, vector<int>{1, 2, 5});
//}

//////////////////////////////////////////////下一个排列////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-suan-fa-xiang-jie-si-lu-tui-dao-/
//void main()
//{
//    vector<int> nums = { 1,2,3,8,5,7,6,4 };
//    int i = nums.size() - 2;//首先i应该从倒数第二个数开始遍历（倒数第一个是n-1）
//    while (i >= 0 && nums[i] >= nums[i + 1]) {//从后向前查找第一个相邻升序的元素对 (i,j)，满足 A[i]< A[j]。此时 [j,end) 必然是降序，如果此时已经是最大排列，那么i就会一直减少为-1
//        i--;
//    }
//    if (i >= 0) {//在 [j,end) 从后向前查找第一个满足 A[i] < A[k] 的 k,因为[j,end) 必然是降序，所以从后往前找到的第一个A[k]一定是大于A[i]的，并且它是在[j,end)中最接近A[i]的，
//        int j = nums.size() - 1;
//        while (j >= 0 && nums[i] >= nums[j]) {
//            j--;
//        }
//        swap(nums[i], nums[j]);//将 A[i] 与 A[k] 交换，这样就保证了新的排列只是稍微大于原有排列，但此时并不是最接近原有排列的
//    }
//    reverse(nums.begin() + i + 1, nums.end());//可以断定这时 [j,end) 必然是降序，逆置 [j,end)，使其升序,升序完才最接近原来排列，i=-1的时候整个排列反转，说明最大排列的下一个排列是最小排列
//    for (auto i : nums)
//    {
//        cout << i << ' ';
//    }
//}

//////////////////////////////////////////////556. 下一个更大元素 III////////////////////////////////////////////////////

//https://leetcode.cn/problems/next-greater-element-iii/solution/xia-yi-ge-geng-da-yuan-su-iii-by-leetcod-mqf1/
//给你一个正整数 n ，请你找出符合条件的最小整数，其由重新排列 n 中存在的每位数字组成，并且其值大于 n 。
//如果不存在这样的正整数，则返回 - 1 。
//注意 ，返回的整数应当是一个 32 位整数 ，如果存在满足题意的答案，但不是 32 位整数 ，同样返回 - 1 。
//int main()
//{
//    int k = 12;
//    string s = to_string(k);
//    int i = s.size() - 2;//首先i应该从倒数第二个数开始遍历（倒数第一个是n-1）
//    while (i >= 0 && s[i] >= s[i + 1]) {//从后向前查找第一个相邻升序的元素对 (i,j)，满足 A[i]< A[j]。此时 [j,end) 必然是降序，如果此时已经是最大排列，那么i就会一直减少为-1
//        i--;
//    }
//    if (i >= 0) {//在 [j,end) 从后向前查找第一个满足 A[i] < A[k] 的 k,因为[j,end) 必然是降序，所以从后往前找到的第一个A[k]一定是大于A[i]的，并且它是在[j,end)中最接近A[i]的，
//        int j = s.size() - 1;
//        while (j >= 0 && s[i] >= s[j]) {
//            j--;
//        }
//        swap(s[i], s[j]);//将 A[i] 与 A[k] 交换，这样就保证了新的排列只是稍微大于原有排列，但此时并不是最接近原有排列的
//    }
//    reverse(s.begin() + i + 1, s.end());//可以断定这时 [j,end) 必然是降序，逆置 [j,end)，使其升序,升序完才最接近原来排列，i=-1的时候整个排列反转，说明最大排列的下一个排列是最小排列
//    if (i == -1)
//    {
//        return -1;
//    }
//    if (stoll(s) > INT_MAX)
//    {
//        return -1;
//    }
//    return stoi(s);
//}

//////////////////////////////////////////////融合k个有序列表////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/merge-k-sorted-lists/solution/he-bing-kge-pai-xu-lian-biao-by-leetcode-solutio-2/
//ListNode* merge2Lists(ListNode* first, ListNode* second) {//合并两个有序链表
//    ListNode* vHead = new ListNode(-1);
//    ListNode* tmp = vHead;
//    while (first != nullptr && second != nullptr) {
//        if (first->val <= second->val) {
//            tmp->next = first;
//            first = first->next;
//        }
//        else {
//            tmp->next = second;
//            second = second->next;
//        }
//        tmp = tmp->next;
//
//    }
//    if (first != nullptr) {
//        tmp->next = first;
//    }
//    if (second != nullptr) {
//        tmp->next = second;
//    }
//    return vHead->next;
//}
//ListNode* recursion(vector<ListNode*>& lists, int left, int right) {
//    if (left == right) {
//        return lists[left];
//    }
//    int mid = left + (right - left) / 2;
//    ListNode* leftList = recursion(lists, left, mid);//这里将总列表折半折半再折半，先把左半边融合成一个列表
//    ListNode* rightList = recursion(lists, mid + 1, right);//再把右半边融合成一个列表
//    return merge2Lists(leftList, rightList);//最后左右两个列表融合
//}
//void main()
//{
//    ListNode* fiv = new ListNode(5);
//    ListNode* fou1 = new ListNode(4,fiv);
//    ListNode* one1 = new ListNode(1,fou1);
//    ListNode* fou2 = new ListNode(4);
//    ListNode* thr = new ListNode(3,fou2);
//    ListNode* one2 = new ListNode(1,thr);
//    ListNode* six = new ListNode(6);
//    ListNode* two = new ListNode(2,six);
//    vector<ListNode*> lists = { one1,one2,two };
//    if (lists.size() == 0) 
//    {
//        cout<<"nullptr"<<endl;
//        return;
//    }
//    ListNode* res=recursion(lists, 0, lists.size() - 1);   
//    while (res)
//    {
//        cout << res->val << ' ';
//        res = res->next;
//    }
//}

//////////////////////////////////////////////归并字母异位组////////////////////////////////////////////////////

//void main()
//{
//    vector<string> strs = { "eat","tea","tan","ate","nat","bat" };
//    unordered_map<string, vector<string>> mp;
//    for (string& str : strs) {
//        string key = str;
//        sort(key.begin(), key.end());//对于字母异位组，排序后的key一定相同
//        mp[key].emplace_back(str);
//    }
//    vector<vector<string>> ans;
//    for (auto it = mp.begin(); it != mp.end(); ++it) {
//        ans.emplace_back(it->second);
//    }
//    for (auto st : ans)
//    {
//        for (auto i : st)
//        {
//            cout << i << ' ';
//        }
//        cout<<endl;
//    }
//}

//////////////////////////////////////////////查找路径(DFS)////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/robot-in-a-grid-lcci/
//bool dfs(vector<vector<int>>& g, int x, int y, vector<vector<int>>& path) {
//    int m = g.size();
//    int n = g[0].size();
//
//    if (g[x][y] == 1) return false;
//
//    if (x == m - 1 && y == n - 1) {
//        path.push_back({ x, y });
//        return true;
//    }
//
//    path.push_back({ x, y });
//    if (x + 1 < m && dfs(g, x + 1, y, path)) {
//        return true;
//    }
//    if (y + 1 < n && dfs(g, x, y + 1, path)) {
//        return true;
//    }
//
//    path.pop_back();//不可达回退
//    g[x][y] = 1; //不可达回退
//    return false;
//}
//int main()
//{
//    vector<vector<int>> obstacleGrid = { { 0,0,1,1},{1,0,0,1},{0,1,0,0} };
//    vector<vector<int>> res;
//    dfs(obstacleGrid, 0, 0, res);
//    for (auto i : res)
//    {
//        for (auto j : i)
//        {
//            cout << j << ' ';
//        }
//        cout << endl;
//    }
//    return 0;
//}

//////////////////////////////////////////////查找路径是否可达并记录路径(DP)////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/robot-in-a-grid-lcci/solution/0802-cji-hu-shuang-bai-de-wu-di-gui-de-d-jdy8/=
//vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
//    vector<vector<int>> res;
//    int rows = obstacleGrid.size();
//    int cols = obstacleGrid[0].size();
//    // 先排除边缘情况，起点和重点不可达
//    if (obstacleGrid[0][0] == 1 || obstacleGrid[rows - 1][cols - 1] == 1)
//    {
//        return res;
//    }
//
//    // 初始化
//    vector<vector<bool>> d(rows,vector<bool>(cols));
//    d[0][0] = 1;
//    // 首列
//    for (int i = 1; i < rows; ++i)
//    {
//        d[i][0] = (obstacleGrid[i][0] == 0) && d[i - 1][0];
//    }
//    // 首行
//    for (int j = 1; j < cols; ++j)
//    {
//        d[0][j] = (obstacleGrid[0][j] == 0) && d[0][j - 1];
//    }
//
//    // 计算
//    for (int i = 1; i < rows; ++i)
//    {
//        for (int j = 1; j < cols; ++j)
//        {
//            // 这里把两种情况都合并在一起了
//            // 先判断是否为0
//            // 再判断上一次位置是否可达
//            d[i][j] = (obstacleGrid[i][j] == 0) && (d[i - 1][j] || d[i][j - 1]);
//        }
//    }
//
//    // 结果
//    // 如果不可达，直接返回空结果
//    if (!d[rows - 1][cols - 1])
//    {
//        return res;
//    }
//    // 可达，倒序计算,是因为每个位置只要是true说明一定有路径可以到达这个位置，只需要从终点反向查找一条大于0的路径到达起点，而正序有可能走到死胡同
//    int i = rows - 1;
//    int j = cols - 1;
//    while (i > 0 || j > 0)
//    {
//        res.push_back({ i, j });
//        // 判断上一步是上方的情况是否可达
//        if (i > 0 && d[i - 1][j])
//        {
//            --i;
//        }
//        else
//        {
//            // 因为最后是可达，所以这里必然有一个可达的, 考虑上一步是左边的情况
//            --j;
//        }
//    }
//    // 插入起点
//    res.push_back({ 0,0 });
//    // 倒序
//    reverse(res.begin(), res.end());
//    return res;
//}
//void main()
//{
//    vector<vector<int>> obstacleGrid = { { 0,0,1,1},{1,0,0,1},{0,1,0,0} };//1代表此位置有阻碍
//    vector<vector<int>> res;
//    res=pathWithObstacles(obstacleGrid);
//    for (auto i : res)
//    {
//        for (auto j : i)
//        {
//            cout << j << ' ';
//        }
//        cout << endl;
//    }
//}


//////////////////////////////////////////////两个字符串的最短编辑距离（DP）////////////////////////////////////////////////////

//void main()
//{
//    string word1 = "intention";
//    string word2 = "execution";
//    int len1 = word1.length();
//    int len2 = word2.length();
//    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, INT_MAX));//dp[i][j]表示表示 A 的前 i 个字母和 B 的前 j 个字母之间的编辑距离，也就是
//                                                                     // A 的前 i 个字母最少要多少次变换才能变成 B 的前 j 个字母
//    for (int i = 0;i < len1 + 1;++i)//一个空串和一个非空串的编辑距离为 dp[i][0] = i 和 dp[0][j] = j，dp[i][0] 相当于对 word1 执行 i 次删除操作，
//                                    //dp[0][j] 相当于对 word1执行 j 次插入操作。
//
//    {
//        dp[i][0] = i;
//    }
//    for (int j = 0;j < len2 + 1;++j)
//    {
//        dp[0][j] = j;
//    }
//    for (int i = 1;i < len1 + 1;++i)//1.知道"abcd"变成"fgh"多少步（假设X步），那么从"abcde"到"fgh"就是"abcde"->"abcd"->"fgh"。（一次删除，加X步，总共X+1步---dp[i-1][j]+1
//                              //2.知道"abcde"变成“fg”多少步（假设Y步），那么从"abcde"到"fgh"就是"abcde"->"fg"->"fgh"。（先Y步，再一次添加，总共Y + 1步）--dp[i][j-1]+1
//                              //3.知道"abcd"变成“fg”多少步（假设Z步），那么从"abcde"到"fgh"就是"abcde"->"fge"->"fgh"。-----dp[i-1][j-1]+1
//                              //（先不管最后一个字符，把前面的先变好，用了Z步，然后把最后一个字符给替换了。这里如果最后一个字符碰巧就一样，那就不用替换，省了一步）
//    {
//        for (int j = 1;j < len2 + 1;++j)
//        {
//            if (word1[i - 1] == word2[j - 1])
//            {
//                dp[i][j] = dp[i - 1][j - 1];
//            }
//            else dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
//        }
//    }
//    cout<<dp[len1][len2];
//}


//////////////////////////////////////////////由先序遍历和深度还原二叉树////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/recover-a-tree-from-preorder-traversal/solution/shou-hui-tu-jie-fei-di-gui-fa-zhong-gou-chu-er-cha/
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};
//class Solution {
//public:
//    TreeNode* recoverFromPreorder(string traversal) {
//        stack<TreeNode*> path;//栈中存放的是还没有找到所有左右孩子的节点，可能一个都没找到，也可能只找到一个，
//        int pos = 0;
//        while (pos < traversal.size()) {
//            int level = 0;//level是从0开始的，也就是说根节点的level=0
//            while (traversal[pos] == '-') {
//                ++level;
//                ++pos;
//            }
//            int value = 0;
//            while (pos < traversal.size() && isdigit(traversal[pos])) {
//                value = value * 10 + (traversal[pos] - '0');
//                ++pos;
//            }
//            TreeNode* node = new TreeNode(value);
//            //·为什么level == path.size()就说明当前节点是栈顶节点的孩子？
//            //    这是因为先序遍历本身的性质。在先序遍历中，我们是通过「根 — 左 — 右」的顺序访问每一个节点的。对于在先序遍历中任意的两个相邻的节点 S 和 T(S在前面)，
//            //    要么 T 就是 S 的左子节点, 要么在遍历到 S 之后发现 S 是个叶节点，于是回溯到之前的某个节点，并开始递归地遍历其右子节点。
//            //    因此，我们可以发现：如果 T 是 S 的左子节点，那么 T 的深度（也就是level，从0开始，比如第三层的左孩子节点深度是2，而在它之前应该有2个节点入栈了,栈的大小为2）
//            //    恰好比 S 的深度大 1(S是T的父节点，T是S的左孩子，由于是先序遍历，所以S已经放入栈了，所以T的深度正好正好等于栈的大小）；
//            //    在其它的情况下，T 是栈中某个节点（不包括 S）的右子节点，那么我们将栈顶的节点不断地出栈，直到 T 的深度恰好与栈的大小相同，此时栈顶元素就是T的父节点。
//            if (level == path.size()) {
//                if (!path.empty()) {
//                    path.top()->left = node;
//                }
//            }
//            else {
//                while (level != path.size()) {
//                    path.pop();
//                }
//                path.top()->right = node;
//            }
//            path.push(node);
//        }
//        while (path.size() > 1) {//返回根节点
//            path.pop();
//        }
//        return path.top();
//    }
//};
//void main()
//{
//    Solution so;
//    string str = "1-2--3--4-5--6--7";
//    TreeNode*  res= so.recoverFromPreorder(str);
//}

//////////////////////////////////////////////滑动窗口找最小覆盖字串////////////////////////////////////////////////////

//void main()
//{
//    string s = "ADOBECODEBANC";
//    string t = "ABC";
//    vector<int> need(128, 0);//字符串中都是字母。所以用数组表示就可以，need[i]表示该字符还需要多少个
//    int count = 0;//count表示还需要找到几个t中的字符，count=0就表示全都找到了
//    for (char c : t)
//    {
//        need[c]++;//初始化
//    }
//    count = t.length();//初始化
//    int l = 0, r = 0, start = 0, size = INT_MAX;
//    while (r < s.length())
//    {
//        char c = s[r];
//        if (need[c] > 0) //如果这个字符不在窗口里，那么此字符的need值就大于0，把它加入窗口，并且count减一
//            count--;
//        //不管这个字符需不需要，都要先把右边的字符加入窗口，
//        //·如果不需要，那么need[c]自减之前等于0，自减以后就变成了负数，后面缩小窗口的时候就直接去掉了；
//        //·如果需要，那么need[c]自减之前大于0，,自减以后就大于等于0，就算做有效窗口的一部分参与计算最小长度
//        need[c]--; 
//        if (count == 0)    //窗口中已经包含所需的全部字符
//        {
//            while (l < r && need[s[l]] < 0) //缩减窗口，need[s[l]] < 0表示左边界的字符是多余的
//            {
//                need[s[l]]++;
//                l++;
//            }   //此时窗口符合要求，此时窗口左边界的字符一定是不可或缺的，即need[左边界]=0
//            if (r - l + 1 < size)    //更新答案
//            {
//                size = r - l + 1;
//                start = l;
//            }
//            need[s[l]]++;   //左边界右移之前需要释放need[s[l]]，左边界的字符不可或缺，左边界右移的时候窗口不满足条件，因此count和need[左边界]都要加1
//            l++;
//            count++;
//        }
//        r++;//不满足条件就拓展右边界
//    }
//    cout << s.substr(start, size) << endl;
//}


//////////////////////////////////////////////经典回溯算法求所有子集////////////////////////////////////////////////////

//void func(vector<vector<int>>& res, vector<int>& nums, vector<int>& tmp, int len, int index)
//{
//    if (tmp.size() == len)
//    {
//        res.push_back(tmp);
//        return;
//    }
//    for (int i = index;i < nums.size();++i)
//    {
//        tmp.push_back(nums[i]);
//        func(res, nums, tmp, len, i + 1);
//        tmp.pop_back();
//    }
//    return;
//}
//void main()
//{
//    vector<int> nums = { 1,2,3 };
//    vector<vector<int>> res;
//    vector<int> tmp;
//    res.push_back({});
//    int len = nums.size();
//    for (int length = 1;length <= len;length++)
//    {
//        func(res, nums, tmp, length, 0);
//    }
//    for (auto i : res)
//    {
//        for (auto j : i)
//        {
//            cout << j << ' ';
//        }
//        cout << endl;
//    }
//}

//////////////////////////////////////////////通过相邻表还原数组////////////////////////////////////////////////////

//void main()
//{
//    vector<vector<int>> adjacentPairs = { {2, 1},{3, 4},{3, 2} };
//    vector<int> ans;
//    set<int> st;//set判某个数是否已经加入了答案数组
//    unordered_map<int, vector<int>> mp;//哈希表
//    int n = adjacentPairs.size();
//    for (int i = 0; i < n; i++) {
//        mp[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);//mp存的是某个结点的相邻结点，除了两个端点之外，每个结点都应该有两个相邻结点
//        mp[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
//    }
//    int start;
//    //找一个端点
//    for (auto it = mp.begin(); it != mp.end(); it++) {
//        if (it->second.size() == 1) {
//            start = it->first;
//            st.insert(start);
//            ans.push_back(start);
//            break;
//        }
//    }
//    //从端点开始构建整个 答案数组
//    int temp = start;
//    while (st.size() < n + 1) {
//        for (int i = 0; i < mp[temp].size(); i++) {
//            if (st.find(mp[temp][i]) == st.end()) {//如果mp[temp][i]这个结点没有使用过
//                temp = mp[temp][i];
//                ans.push_back(temp);
//                st.insert(temp);
//                break;//这里的break是因为mp[temp]最多有两个结点，其中必定有一个是被访问过的，因为要找到temp必须先找到temp相邻结点中的某一个，这样的话如果
//                      //mp[temp]中第一个结点没有被访问过，那么就不必访问第二个结点了，节省了访问时间，当然也可以省略，省略的话就要加上st.find的时间了
//            }
//        }
//    }
//    for (auto i : ans)
//    {
//        cout << i << ' ';
//    }
//}

//////////////////////////////////////////////寻找二叉树的最大路径////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/solution/er-cha-shu-zhong-de-zui-da-lu-jing-he-by-ikaruga/
//int max_sum = INT_MIN;
//int dfs(TreeNode* root)
//{
//    if (root == nullptr) return 0;
//    int left = dfs(root->left);
//    int right = dfs(root->right);
//    int lmr = root->val + max(0, left) + max(0, right);//从左孩子到右孩子的最大和路径，不经过外面，左右孩子的贡献值必须是正的，不然就没必要往左右孩子递归，直接返回本节点的值就行了
//    int ret = root->val + max(0, max(left, right));//从本节点到左右孩子某一条的最大和路径，从外面进来，最大和只能选择左右孩子之中的最大值，并且最大值应当大于0，不然就没必要往左右孩子递归
//    max_sum = max(max_sum, max(lmr, ret));//找最大值
//    return ret;//从外面进来的这条路径返回，因为要充当本节点的父节点的左右孩子的值
//}
//void main()
//{
//    TreeNode* one = new TreeNode(9);
//    TreeNode* two = new TreeNode(15);
//    TreeNode* thr = new TreeNode(7);
//    TreeNode* fou = new TreeNode(20, two, thr);
//    TreeNode* fiv = new TreeNode(-10, one, fou);
//    dfs(fiv);
//    cout << max_sum << endl;
//}


//////////////////////////////////////////////字符串的全排列////////////////////////////////////////////////////

//void backtrack(vector<string>& res, vector<bool>& vis, string& s, string& path, int len, int index)
//{
//    if (path.length() == len)
//    {
//        res.push_back(path);
//        return;
//    }
//    for (int i = index;i < len;++i)
//    {
//        if (vis[i] || (i > 0 && !vis[i - 1] && s[i - 1] == s[i]))//首先，如果s[i]被访问过，那肯定不能再访问；其次相同字符一定相邻，肯定是先访问第一个a0，再访问a1，也就是
//                                                                 //访问s[i]的时候如果s[i - 1] == s[i]，那么vis[i-1]肯定是true（已被访问），如果vis[i-1]是false，说明上一轮
//                                                                 //回溯的时候 a0a1b...已经加入结果集合了，那么本次的a1a0b...就不能再加入，因此要continue，这个属于树枝去重
//        {
//            continue;
//        }
//        path.push_back(s[i]);
//        vis[i] = true;
//        backtrack(res, vis, s, path, len, 0);
//        vis[i] = false;
//        path.pop_back();
//    }
//    return;
//
//}
//void main()
//{
//    string s = "abca";
//    vector<string> res;
//    string path;
//    int len = s.length();
//    sort(s.begin(), s.end());
//    vector<bool> vis(len, false);
//    backtrack(res, vis, s, path, len, 0);
//    for (auto s : res)
//    {
//        cout << s << endl;
//    }
//}

//////////////////////////////////////////////产生螺旋矩阵////////////////////////////////////////////////////

//void main()
//{
//    int n = 3;
//    vector<vector<int>> res(n, vector<int>(n, 0)); // 使用vector定义一个二维数组
//    int startx = 0, starty = 0; // 定义每循环一个圈的起始位置
//    int loop = n / 2; // 每个圈循环几次，例如n为奇数3，那么loop = 1 只是循环一圈，矩阵中间的值需要单独处理
//    int mid = n / 2; // 矩阵中间的位置，例如：n为3， 中间的位置就是(1，1)，n为5，中间位置为(2, 2)
//    int count = 1; // 用来给矩阵中每一个空格赋值
//    int offset = 1; // 每一圈循环，需要控制每一条边遍历的长度
//    int i, j;
//    while (loop--) {
//        i = startx;
//        j = starty;
//
//        // 下面开始的四个for就是模拟转了一圈
//        // 模拟填充上行从左到右(左闭右开)
//        for (j = starty; j < starty + n - offset; j++) {
//            res[startx][j] = count++;
//        }
//        // 模拟填充右列从上到下(左闭右开)
//        for (i = startx; i < startx + n - offset; i++) {
//            res[i][j] = count++;
//        }
//        // 模拟填充下行从右到左(左闭右开)
//        for (; j > starty; j--) {
//            res[i][j] = count++;
//        }
//        // 模拟填充左列从下到上(左闭右开)
//        for (; i > startx; i--) {
//            res[i][j] = count++;
//        }
//
//        // 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
//        startx++;
//        starty++;
//
//        // offset 控制每一圈里每一条边遍历的长度
//        offset += 2;
//    }
//
//    // 如果n为奇数的话，需要单独给矩阵最中间的位置赋值
//    if (n % 2) {
//        res[mid][mid] = count;
//    }
//    for (auto i : res)
//    {
//        for (auto j : i)
//        {
//            cout << j << ' ';
//        }
//        cout << endl;
//    }
//}

//////////////////////////////////////////////将矩阵螺旋输出////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/spiral-matrix/solution/cxiang-xi-ti-jie-by-youlookdeliciousc-3/
//void main()
//{
//    vector<vector<int>> matrix = { {1,2,3},{4,5,6}, {7,8,9} };
//    vector <int> ans;
//    if (matrix.empty()) return; //若数组为空，直接返回答案
//    int u = 0; //赋值上下左右边界
//    int d = matrix.size() - 1;
//    int l = 0;
//    int r = matrix[0].size() - 1;
//    while (true)
//    {
//        for (int i = l; i <= r; ++i) ans.push_back(matrix[u][i]); //顶行向右移动直到最右
//        if (++u > d) break; //重新设定上边界，若上边界大于下边界，则遍历遍历完成，如果新的上边界等于下边界，则说明矩阵还有一行未遍历，需要继续遍历
//        for (int i = u; i <= d; ++i) ans.push_back(matrix[i][r]); //向下，注意这里的u是重新设定的上边界，没有遍历过，因此不会重复遍历
//        if (--r < l) break; //重新设定右边界
//        for (int i = r; i >= l; --i) ans.push_back(matrix[d][i]); //向左
//        if (--d < u) break; //重新设定下边界
//        for (int i = d; i >= u; --i) ans.push_back(matrix[i][l]); //向上
//        if (++l > r) break; //重新设定左边界
//    }
//}

//////////////////////////////////////////////双向列表字典实现LRU机制////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/lru-cache/solution/lruhuan-cun-ji-zhi-by-leetcode-solution/
//struct DLinkedNode {
//    int key, value;
//    DLinkedNode* prev;
//    DLinkedNode* next;
//    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
//    DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
//};
//class LRUCache {
//public:
//    unordered_map<int, DLinkedNode*> cache;
//    DLinkedNode* head;
//    DLinkedNode* tail;
//    int size;
//    int capacity;
//
//public:
//    LRUCache(int _capacity) : capacity(_capacity), size(0) {
//        // 使用伪头部和伪尾部节点
//        head = new DLinkedNode();
//        tail = new DLinkedNode();
//        head->next = tail;
//        tail->prev = head;
//    }
//
//    int get(int key) {
//        if (!cache.count(key)) {
//            return -1;
//        }
//        // 如果 key 存在，先通过哈希表定位，再移到头部
//        DLinkedNode* node = cache[key];
//        moveToHead(node);
//        return node->value;
//    }
//
//    void put(int key, int value) {
//        if (!cache.count(key)) {
//            // 如果 key 不存在，创建一个新的节点
//            DLinkedNode* node = new DLinkedNode(key, value);
//            // 添加进哈希表
//            cache[key] = node;
//            // 添加至双向链表的头部
//            addToHead(node);
//            ++size;
//            if (size > capacity) {
//                // 如果超出容量，删除双向链表的尾部节点
//                DLinkedNode* removed = removeTail();
//                // 删除哈希表中对应的项
//                cache.erase(removed->key);//这就是为什么双向链表里需要存放key和value两个值，因为哈希表删除的时候需要用到key
//                // 防止内存泄漏
//                delete removed;
//                --size;
//            }
//        }
//        else {
//            // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
//            DLinkedNode* node = cache[key];
//            node->value = value;
//            moveToHead(node);
//        }
//    }
//
//    void addToHead(DLinkedNode* node) {
//        node->prev = head;
//        node->next = head->next;
//        head->next->prev = node;
//        head->next = node;
//    }
//
//    void removeNode(DLinkedNode* node) {
//        node->prev->next = node->next;
//        node->next->prev = node->prev;
//    }
//
//    void moveToHead(DLinkedNode* node) {
//        removeNode(node);
//        addToHead(node);
//    }
//
//    DLinkedNode* removeTail() {
//        DLinkedNode* node = tail->prev;
//        removeNode(node);
//        return node;
//    }
//};
//void main()
//{
//    LRUCache lru(2);
//    lru.put(1,1);
//    for (auto i : lru.cache)
//    {
//        cout << i.second->value << ' ';
//    }
//    cout << endl;
//    lru.put(2,2);
//    for (auto i : lru.cache)
//    {
//        cout << i.second->value << ' ';
//    }
//    cout << endl;
//    cout<<lru.get(1)<<endl;
//    lru.put(3, 3);
//    for (auto i : lru.cache)
//    {
//        cout << i.second->value << ' ';
//    }
//    cout << endl;
//    cout<<lru.get(2)<<endl;
//    lru.put(4, 4);
//    for (auto i : lru.cache)
//    {
//        cout << i.second->value << ' ';
//    }
//    cout << endl;
//    cout<<lru.get(1)<<endl;
//    cout<<lru.get(3)<<endl;
//    cout<<lru.get(4)<<endl;
//}

//////////////////////////////////////////////双向列表字典实现LFU机制////////////////////////////////////////////////////

//https://blog.51cto.com/u_11326173/4578869
// https://leetcode.cn/problems/lfu-cache/
//struct DoubleList;
//struct Node
//{
//    int freq = 1;
//    Node* next, *pre;
//    int key, value;
//    DoubleList* host_DoubleList;
//    Node() {};
//    Node(int key_, int value_)
//    {//节点记录键值
//        key = key_;
//        value = value_;
//    }
//};
//struct DoubleList
//{//外层链表节点
//    int freq = 1;//记录频次
//    DoubleList* next, * pre;
//    Node* head, * tail;
//    DoubleList()
//    {
//        head = new Node();
//        tail = new Node();
//        head->next = tail;
//        tail->pre = head;
//    }
//    DoubleList(int freq_)
//    {
//        freq = freq_;
//        head = new Node();
//        tail = new Node();
//        head->next = tail;
//        tail->pre = head;
//    }
//    void addnode(Node* node)
//    {//新增内层节点
//        node->pre = head;
//        node->next = head->next;
//        head->next->pre = node;
//        head->next = node;
//        node->host_DoubleList = this;//记录一下内层节点对应的外层链表节点
//    }
//    void removenode(Node* node)
//    {//移除内层链表节点
//        node->pre->next = node->next;
//        node->next->pre = node->pre;
//    }
//    bool empty()
//    {
//        return head->next == tail;
//    }
//};
//struct LFUcache
//{
//    unordered_map<int, Node*> cache;//记录当前存在的key和对应的node节点
//    DoubleList* head, *tail;//记录外层链表的首尾哨兵，外层链表从头到尾频率依次减少，尾结点前一节点出现的频率最少
//    //内层链表记录键值，每一个外层链表节点对于一个内层链表，这些链表的出现频率相同  
//    int size, capacity;//容量和大小
//    LFUcache(int cap)
//    {//初始化
//        head = new DoubleList(0);
//        tail = new DoubleList(0);
//        head->next = tail;
//        tail->pre = head;
//        capacity = cap;
//        size = 0;
//    }
//    int get(int key_)
//    {
//        if(cache.find(key_)==cache.end())
//        {//不存在直接返回-1
//            return -1;
//        }
//        Node* node = cache[key_];
//        freqinc(node);//否则，使这个节点频率增加，从原有内部链表中删除这个节点，转移到新的内部链表中
//        return node->value;//返回value
//    }
//    void put(int key_, int value_)
//    {
//        if (capacity == 0)
//        {//容量为0，直接返回
//            return;
//        }
//        if (cache.find(key_) != cache.end())
//        {//之前就存在，直接更新值
//            cache[key_]->value = value_;
//            freqinc(cache[key_]);//增加频率
//        }
//        else
//        {
//            if (size == capacity)
//            {//内存满时，删除外层链表尾节点前一节点（tail->pre）中，尾节点的前一节点（tail->pre->tail->pre）
//                cache.erase(tail->pre->tail->pre->key);
//                //从频率最低的外层链表中删除最后一个节点，它是出现次数最小并且最久没有出现的节点
//                tail->pre->removenode(tail->pre->tail->pre);
//                if (tail->pre->empty())
//                {//如果该外层链表为空，删除外层链表节点
//                    removeDoubleList(tail->pre);
//                }
//                size--;//大小递减
//            }
//            Node* new_node = new Node(key_, value_);
//            cache[key_] = new_node;
//            //每当有新频次的 DoubleLinkedList 需要添加进来的时候，直接插入到 lastLinkedList 这个哨兵前面，
//            //因此 lastLinkedList.pre 就是一个最小频次的内部链表。
//            if (tail->pre->freq != 1)
//            {//没有频率为1的外层链表节点，新增一个
//                DoubleList* new_DoubleList = new DoubleList(1);
//                new_DoubleList->addnode(new_node);//把这个节点放到频率为1的新增链表中
//                addDoubleList(tail->pre, new_DoubleList);//新增链表
//            }
//            else
//            {//有频率为1的外层链表节点，直接把节点放进去
//                tail->pre->addnode(new_node);
//            }
//            size++;//大小递增
//        }
//    }
//    void freqinc(Node* node)
//    {
//        DoubleList* host_DoubleList = node->host_DoubleList;//从内层节点找到对应的外层链表节点
//        host_DoubleList->removenode(node);//移除这个节点
//        if (host_DoubleList->empty())
//        {//外层链表为空，删除
//            removeDoubleList(host_DoubleList);
//        }
//        node->freq++;//频率递增
//        DoubleList* pre_DoubleList = host_DoubleList->pre;//前一外层链表节点
//        if (pre_DoubleList->freq != node->freq)
//        {//如果频率不等于，就要新增外层链表节点
//            DoubleList* new_DoubleList = new DoubleList(node->freq);
//            new_DoubleList->addnode(node);//把节点放进去
//            addDoubleList(pre_DoubleList, new_DoubleList);//把外层链表节点放进外层链表里
//        }
//        else
//        {//否则直接加入前一链表
//            pre_DoubleList->addnode(node);
//        }
//    }
//    void removeDoubleList(DoubleList* Dlist)
//    {//删除外层链表节点
//        Dlist->next->pre = Dlist->pre;
//        Dlist->pre->next = Dlist->next;
//    }
//    void addDoubleList(DoubleList* pre_, DoubleList* new_)
//    {//新增外层链表节点
//        new_->next = pre_->next;
//        new_->pre = pre_;
//        pre_->next->pre = new_;
//        pre_->next = new_;
//    }
//};
//int main()
//{
//    LFUcache lfu(0);
//    lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
//    lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
//    lfu.get(1);      // 返回 1
//    // cache=[1,2], cnt(2)=1, cnt(1)=2
//    lfu.put(3, 3);   // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
//    // cache=[3,1], cnt(3)=1, cnt(1)=2
//    lfu.get(2);      // 返回 -1（未找到）
//    lfu.get(3);      // 返回 3
//    // cache=[3,1], cnt(3)=2, cnt(1)=2
//    lfu.put(4, 4);   // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
//    // cache=[4,3], cnt(4)=1, cnt(3)=2
//    lfu.get(1);      // 返回 -1（未找到）
//    lfu.get(3);      // 返回 3
//    // cache=[3,4], cnt(4)=1, cnt(3)=3
//    lfu.get(4);      // 返回 4
//    // cache=[3,4], cnt(4)=2, cnt(3)=3
//}

//////////////////////////////////////////////双向列表字典查找次数最多、最少字符串////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/all-oone-data-structure/solution/by-ac_oier-t26d/
//class AllOne {
//private:
//    struct Node {//双向列表，以出现次数为标准单调递增，head小，tail大
//        int cnt;  // 字符串出现的次数
//        unordered_set<string> c;  // 出现cnt次数的字符串集合
//        Node* pre;  // 前一个
//        Node* next;  // 后一个
//        Node(int _cnt, const string& s = "", Node* _l = nullptr, Node* _r = nullptr) 
//        {//构造函数这样写方便我们新建结点
//            cnt = _cnt;
//            c.insert(s);
//            pre = _l;
//            next = _r;
//        }
//    };
//    // 两个哨兵、一个hash_map用来stirng到Node*的映射
//    Node* head;
//    Node* tail;
//    unordered_map<string, Node*> umap;
//public:
//    AllOne() {
//        head = new Node(-1);
//        tail = new Node(-1);
//        head->next = tail;
//        tail->pre = head;
//    }
//
//    void clear(Node* node)
//    {//在双向链表中删除一个节点
//        if (node->c.empty()) 
//        {//当此节点保存的字符串个数为 0 时，删除这个节点
//            node->pre->next = node->next;
//            node->next->pre = node->pre;
//        }
//    }
//    void inc(string key) 
//    {
//        if (umap.find(key) != umap.end()) 
//        {//存在此字符串，新建或直接转移到 cnt+1 的节点，加入链表
//            Node* node = umap[key];//找到此字符串对应的节点
//            int cnt = node->cnt;//此节点对应的次数
//            Node* pre = nullptr;//为了统一，先用pre记录一下key应该呆在那个节点里
//            if (node->next->cnt == cnt + 1) 
//                pre = node->next;//如果下一个节点的次数正好是此节点的次数+1，那么就直接把key字符串转移到下一节点中去，也就是key 应该呆在下一节点，则pre指向下一节点
//            else 
//            {//否则，就要新建一个次数等于此节点的次数+1的节点，把key转移进去
//                pre = new Node(cnt + 1, key, node, node->next);//这里新建结点的时候就已经表明了前后指向了
//                node->next = pre;//另外两个指向
//                pre->next->pre = pre;
//            }
//            pre->c.insert(key);//把key字符串转移到 pre 节点中
//            umap[key] = pre;//更新对应关系
//            node->c.erase(key);//此时原有的节点要擦除key，因为已经转移了
//            clear(node);//如果node里面保存的字符串个数为 0，那么就要删除这个节点了
//        }
//        else 
//        {//不存在此字符串
//            Node* node = nullptr;
//            // 存在cnt=1的节点，直接把此字符串加进去，否则就要新建cnt=1的节点
//            if (head->next->cnt == 1) node = head->next;
//            else {
//                node = new Node(1, key, head, head->next);
//                head->next = node;
//                node->next->pre = node;
//            }
//            node->c.insert(key);//字符加进去
//            umap[key] = node;//创建关系，表明此字符串在此节点中
//        }
//    }
//
//    void dec(string key) 
//    {//要减去一个字符串的次数，此字符串一定是存在的
//        Node* node = umap[key];//找到对应节点
//        int cnt = node->cnt;//对应节点次数
//        if (cnt == 1) 
//            umap.erase(key);  // 如果key对应的次数等于1，那么减一以后就变成0了，应该从数据结构里面删除 key，同时从链表中删除 node 节点
//        else 
//        {//否则就要新建或直接转移到 cnt-1 的节点，加入链表
//            Node* pre = nullptr;//先用pre记录一下key应该呆在那个节点里
//            if (node->pre->cnt == cnt - 1) 
//                pre = node->pre;////如果上一个节点的次数正好是此节点的次数-1，那么就直接把key字符串转移到上一节点中去，也就是key 应该呆在上一节点，则pre指向上一节点
//            else 
//            {////否则，就要新建一个次数等于此节点的次数-1的节点，把key转移进去
//                pre = new Node(cnt - 1, key, node->pre, node);
//                node->pre->next = pre;
//                node->pre = pre;
//            }
//            pre->c.insert(key);//把key字符串转移到 pre 节点中
//            umap[key] = pre;//更新对应关系
//        }
//        node->c.erase(key);//此时原有的节点要擦除key，因为已经转移了
//        clear(node);//如果node里面保存的字符串个数为 0，那么就要删除这个节点了
//    }
//
//    string getMaxKey() {
//        for (const auto& c : tail->pre->c) 
//            return c;//返回次数最大节点保存的字符串里面的任意一个
//        return "";
//    }
//
//    string getMinKey() {
//        for (const auto& c : head->next->c) 
//            return c;//返回次数最小节点保存的字符串里面的任意一个
//        return "";
//    }
//};

//////////////////////////////////////////////反转字符串里的单词////////////////////////////////////////////////////


//void reverse(string& s, int start, int end) {
//    for (int i = start, j = end; i < j; i++, j--) {
//        swap(s[i], s[j]);
//    }
//}
//// 移除冗余空格：使用双指针（快慢指针法）O(n)的算法
//void removeExtraSpaces(string& s) {
//    int slowIndex = 0, fastIndex = 0; // 定义快指针，慢指针
//    // 去掉字符串前面的空格
//    while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') {//这里fast指到了非空格的第一个字符
//        fastIndex++;
//    }
//    for (; fastIndex < s.size(); fastIndex++) {
//        // 去掉字符串中间部分的冗余空格
//        if (fastIndex - 1 > 0 && s[fastIndex - 1] == s[fastIndex] && s[fastIndex] == ' ') {
//            continue;//如果遇到两个空格的话就把第二个空格往后移
//        }
//        else {
//            s[slowIndex++] = s[fastIndex];
//        }
//    }
//    if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ') { // 如果末尾有空格的话就去掉字符串末尾的空格
//        s.resize(slowIndex - 1);//这里slow指到了正规字符串末尾的后一个位置，相当于end（）迭代器
//    }
//    else {//没有的话直接重置
//        s.resize(slowIndex); // 重新设置字符串大小
//    }
//}
//void main()
//{
//    string s = " hello  world ";
//    removeExtraSpaces(s); // 去掉冗余空格
//    reverse(s, 0, s.size() - 1); // 将字符串全部反转
//    int start = 0; // 反转的单词在字符串里起始位置
//    int end = 0; // 反转的单词在字符串里终止位置
//    bool entry = false; // 标记枚举字符串的过程中是否已经进入了单词区间
//    for (int i = 0; i < s.size(); i++) { // 开始反转单词
//        if ((!entry) || (s[i] != ' ' && s[i - 1] == ' ')) {//第一个条件是保证第一个单词能正常反转，第二个条件是保证后面的单词能正常反转
//            start = i; // 确定单词起始位置
//            entry = true; // 进入单词区间
//        }
//        // 单词后面有空格的情况，空格就是分词符
//        if (entry && s[i] == ' ' && s[i - 1] != ' ') {
//            end = i - 1; // 确定单词终止位置
//            entry = false; // 结束单词区间
//            reverse(s, start, end);
//        }
//        // 最后一个结尾单词之后没有空格的情况
//        if (entry && (i == (s.size() - 1)) && s[i] != ' ') {
//            end = i;// 确定单词终止位置
//            entry = false; // 结束单词区间
//            reverse(s, start, end);
//        }
//    }
//    cout<<s<<endl;
//}

//////////////////////////////////////////////连续子数组的乘积最大值////////////////////////////////////////////////////

//void main()
//{
//    vector<int> nums = { -2,3,-2,4 };
//    int n = nums.size();
//    int ans = INT_MIN;
//    int max_v = 1, min_v = 1;//max_v是已遍历的子数组乘积最大值，min_v是已遍历的子数组乘积最小值
//    for (int i = 0; i < n; i++) {
//        if (nums[i] < 0) swap(max_v, min_v);
//        max_v = max(max_v * nums[i], nums[i]);
//        min_v = min(min_v * nums[i], nums[i]);
//        ans = max(max_v, ans);
//    }
//    cout<<ans<<endl;
//}

//////////////////////////////////////////////KMP算法，判断非空的字符串是否可以由它的一个子串重复多次构成////////////////////////////////////////////////////

//void getNext(vector<int>& next, string s)
//{
//    next[0] = -1;
//    int j = -1;
//    for (int i = 1;i < s.size();++i)
//    {
//        while (j >= 0 && s[i] != s[j + 1])
//        {
//            j=next[j];
//        }
//        if (s[i] == s[j + 1])
//        {
//            j++;
//        }
//        next[i] = j;
//    }
//}
//void main()
//{
//    string s = "asdfasdfabdf";
//    if (s.size() == 0) {
//        cout << false << endl;
//    }
//    vector<int> next(s.size());
//    getNext(next, s);
//    int len = s.size();
//    //数组长度减去最长相同前后缀的长度相当于是第一个周期的长度，也就是一个周期的长度，如果这个周期可以被整除，就说明整个数组就是这个周期的循环
//    if (next[len - 1] != -1 && len % (len - (next[len - 1] + 1)) == 0) {
//        cout << true << endl;
//        return;
//    }
//    cout << false << endl;
//}

//////////////////////////////////////////////最大的正方形面积（DP）////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/maximal-square/solution/zui-da-zheng-fang-xing-by-leetcode-solution/
//void main()
//{
//    vector<vector<int>> matrix = { { 0,0,0,1},{1,1,0,1},{1,1,1,1},{0,1,1,1},{0,1,1,1} };
//    if (matrix.size() == 0 || matrix[0].size() == 0) {
//        cout<<0<<endl;
//    }
//    int maxSide = 0;
//    int rows = matrix.size(), columns = matrix[0].size();
//    vector<vector<int>> dp(rows, vector<int>(columns));
//    //dp(i,j) 表示以 (i, j)为右下角，且只包含 1的正方形的边长最大值
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < columns; j++) {
//            if (matrix[i][j] == 1) {
//                if (i == 0 || j == 0) {
//                    dp[i][j] = 1;
//                }
//                else {
//                    dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
//                }
//                maxSide = max(maxSide, dp[i][j]);
//            }
//        }
//    }
//    int maxSquare = maxSide * maxSide;
//    cout << maxSquare << endl;
//}

//////////////////////////////////////////////运算符重载（例一）////////////////////////////////////////////////////

//class complex {
//public:
//    complex() : m_real(0.0), m_imag(0.0) { };
//    complex(double real, double imag) : m_real(real), m_imag(imag) { };
//public:
//    //声明运算符重载
//    complex operator+(const complex& A) const
//    {
//        complex B;
//        B.m_real = this->m_real + A.m_real;
//        B.m_imag = this->m_imag + A.m_imag;
//        return B;
//    }
//    void display() const
//    {
//        cout << m_real << " + " << m_imag << "i" << endl;
//    }
//private:
//    double m_real;  //实部
//    double m_imag;  //虚部
//};
//int main() {
//    complex c1(4.3, 5.8);
//    complex c2(2.4, 3.7);
//    complex c3;
//    c3 = c1 + c2;
//    c3.display();
//    return 0;
//}

//////////////////////////////////////////////运算符重载（例二）////////////////////////////////////////////////////

//class Point
//{
//public:
//    Point(int x, int y) {
//        this->x = x;
//        this->y = y;
//    }
//    //为什么要使用友元函数呢
//    friend Point operator+(Point& p1, Point& p2);
//    //类成员函数实现二元运算符-
//    Point operator-(Point& pin) {//这里的pin代表二元运算符右边的参数
//        //二元运算符最好不要改变原来的变量
//        Point temp=*this;
//        temp.x = this->x - pin.x;
//        temp.y = this->y - pin.y;
//        return temp;
//    }
//    void PrintfA() {
//        cout << "x=" << this->x << endl;
//        cout << "y=" << this->y << endl;
//
//    }
//private:
//    int x;
//    int y;
//};
//
////友元函数
////因为函数中使用类的私有成员属性，而这个函数是全局函数，不是类函数,不能使用this指针
//Point operator+(Point& p1, Point& p2) {
//    Point pres(p1.x + p2.x, p1.y + p2.y);
//    return pres;
//}
//
//void ProtectA() {
//    //重载二元运算符 +
//    Point p1(1, 1), p2(2, 2);
//    Point p3 = p1 + p2;
//    //全局函数（一般是友元函数）实现运算符重载步骤：
//    //步骤1：把运算符变成一个函数，写出函数名称
//    //operator+
//    //步骤2：根据操作数，写出函数参数列表，从左到右的顺序一一对应
//    //operator+(p1, p2);
//    //步骤3：根据业务，完成函数返回值，及实现函数
//    //p3=operator + (p1, p2);
//    p3.PrintfA();
//    Point p4 = p1 - p2;
//    //用类成员函数实现运算符重载步骤：
//    //步骤1：要承认操作符重载是一个函数，写出函数名称
//    //operator-()
//    //步骤2：根据操作数，写出函数参数列表，
//    //在类中，对象本身是this，所以可以少传递一个变量
//    //p1.operator-(p2);
//    //步骤3：根据业务，完成函数返回值，及实现函数
//    p1.PrintfA();//没有改变原有值
//    p4.PrintfA();
//}
//void main() {
//    ProtectA();
//}

///////////////////////////////////////////回文链表（快慢指针）////////////////////////////////////////////////////

//ListNode* reverseList(ListNode* head) {
//    ListNode* prev = nullptr;
//    ListNode* curr = head;
//    while (curr != nullptr) {
//        ListNode* nextTemp = curr->next;
//        curr->next = prev;
//        prev = curr;
//        curr = nextTemp;
//    }
//    return prev;
//}
//ListNode* endOfFirstHalf(ListNode* head) {
//    ListNode* fast = head;
//    ListNode* slow = head;
//    while (fast->next != nullptr && fast->next->next != nullptr) {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    return slow;
//}
//bool main()
//{
//    ListNode* one=new ListNode(1);
//    ListNode* two = new ListNode(2,one);
//    ListNode* thr = new ListNode(3,two);
//    ListNode* fou = new ListNode(2,thr);
//    ListNode* head = new ListNode(1,fou);
//    if (head == nullptr || head->next == nullptr) {
//        return true;
//    }
//    //找到前半部分的末尾，如果是奇数，那么中间那个算是前半部分的
//    ListNode* firstHalfEnd = endOfFirstHalf(head);
//    //反转后半部分，返回原本链表中的最末尾节点，现在是后半部分的头结点，因为后半部分反转了，注意这里前后两部分的连接没有断开，因此还原的时候只用反转后半部分就行了
//    ListNode* secondHalfStart = reverseList(firstHalfEnd->next);
//
//    // 判断是否回文
//    ListNode* p1 = head;
//    ListNode* p2 = secondHalfStart;
//    bool result = true;
//    while (result && p2 != nullptr) {//后半部分的长度要小于等于前半部分，因此p2或许会先走到末尾，如果p2走到末尾就停止比较
//        if (p1->val != p2->val) {
//            result = false;//这里没有直接返回是因为后面还要还原链表
//        }
//        p1 = p1->next;
//        p2 = p2->next;
//    }
//
//    // 还原链表并返回结果
//    firstHalfEnd->next = reverseList(secondHalfStart);
//    return result;
//}

///////////////////////////////////////////利用map解决两数之和等于2的幂次////////////////////////////////////////////////////

//void main()
//{
//    vector<int> deliciousness = { 1,1,1,3,3,3,7 };
//    int maxVal = *max_element(deliciousness.begin(), deliciousness.end());//找出最大的元素
//    int maxSum = maxVal * 2;//两个数相加最大值不会超过最大元素的两倍，这样可以节约很多时间
//    int pairs = 0;
//    unordered_map<int, int> mp;
//    int n = deliciousness.size();
//    for (auto& val : deliciousness) {
//        for (int sum = 1; sum <= maxSum; sum=sum << 1) {//对于每一个de[i]和每一个2的幂次数sum，在map中找sum-de[i]，和用map求两数之和是一样的
//            int count = mp.count(sum - val) ? mp[sum - val] : 0;
//            pairs = (pairs + count) % (100000000+7);
//        }
//        mp[val]++;//遍历完2的幂次数后就把de[i]加入map，以供后面的de[i]来查找，因此每次找到的pairs都是后序找前序
//    }
//    cout << pairs << endl;
//}

///////////////////////////////////////////除本身以外的左右两边数的乘积////////////////////////////////////////////////////

//void main()
//{
//    vector<int> nums = { 1,2,3,0,5,4,6 };
//    int length = nums.size();
//
//    // L 和 R 分别表示左右两侧的乘积列表
//    //vector<int> L(length, 0), R(length, 0);
//
//    //vector<int> answer(length);
//
//    //// L[i] 为索引 i 左侧所有元素的乘积，不包括i
//    //// 对于索引为 '0' 的元素，因为左侧没有元素，所以 L[0] = 1
//    //L[0] = 1;
//    //for (int i = 1; i < length; i++) {
//    //    L[i] = nums[i - 1] * L[i - 1];
//    //}
//
//    //// R[i] 为索引 i 右侧所有元素的乘积
//    //// 对于索引为 'length-1' 的元素，因为右侧没有元素，所以 R[length-1] = 1
//    //R[length - 1] = 1;
//    //for (int i = length - 2; i >= 0; i--) {
//    //    R[i] = nums[i + 1] * R[i + 1];
//    //}
//
//    //// 对于索引 i，除 nums[i] 之外其余各元素的乘积就是左侧所有元素的乘积乘以右侧所有元素的乘积
// 
//    //for (int i = 0; i < length; i++) {
//    //    answer[i] = L[i] * R[i];
//    //}
//    //************为了节省空间，可以将L[i]作为结果集输出，而R[i]动态的计算，如下*************
//    vector<int> answer(length);
//    answer[0] = 1;
//    for (int i = 1; i < length; i++) {
//        answer[i] = nums[i - 1] * answer[i - 1];
//    }
//    int R = 1;
//    for (int i = length - 1; i >= 0; i--) {
//        // 对于索引 i，左边的乘积为 answer[i]，右边的乘积为 R
//        answer[i] = answer[i] * R;
//        // R 需要包含右边所有的乘积，所以计算下一个结果时需要将当前值乘到 R 上
//        R *= nums[i];
//    }
//    for (auto i : answer)
//    {
//        cout << i << ' ';
//    }
//}

///////////////////////////////////////////双指针把0移到序列最后////////////////////////////////////////////////////

//void main()
//{
//    vector<int> nums = { 0,1,0,3,5 };
//    int n = nums.size(), left = 0, right = 0;
//    while (right < n) {//left表示当前应该放置非零元素的位置，没交换前，left指向的元素为0（如果不是0，那么必定left和right相同，不需要交换），
//                      //left左边全都是非零元素，[left，right-1]这段区间的元素全是0.
//                       //right用来向前遍历，只要遇到非零元素就和left交换，这样就把0转移到最后了
//        if (nums[right]) {
//            swap(nums[left], nums[right]);
//            left++;
//        }
//        right++;
//    }
//    for (auto i : nums)
//    {
//        cout << i << ' ';
//    }
//}

///////////////////////////////////////////二叉树变成字符串并重新组成二叉树////////////////////////////////////////////////////

//class Codec {
//public:
//    void rserialize(TreeNode* root, string& str) {
//        if (root == nullptr) {
//            str += "None,";
//        }
//        else {
//            str += to_string(root->val) + ",";
//            rserialize(root->left, str);
//            rserialize(root->right, str);
//        }
//    }
//
//    string serialize(TreeNode* root) {
//        string ret;
//        rserialize(root, ret);
//        return ret;
//    }
//
//    TreeNode* rdeserialize(queue<string>& que) {//注意这里是引用传递，如果用值传递的话就不对
//        if (que.front() == "None") {
//            que.pop();
//            return nullptr;
//        }
//
//        TreeNode* root = new TreeNode(stoi(que.front()));
//        que.pop();
//        root->left = rdeserialize(que);
//        root->right = rdeserialize(que);
//        return root;
//    }
//
//    TreeNode* deserialize(string data) {
//        queue<string> que;
//        string str;
//        for (auto& ch : data) {
//            if (ch == ',') {
//                que.push(str);
//                str.clear();
//            }
//            else {
//                str.push_back(ch);
//            }
//        }
//        return rdeserialize(que);
//    }
//};
//void main()
//{
//    TreeNode* fou = new TreeNode(4);
//    TreeNode* fiv = new TreeNode(5);
//    TreeNode* thr = new TreeNode(3,fou,fiv);
//    TreeNode* two = new TreeNode(2);
//    TreeNode* root = new TreeNode(1,two,thr);
//    Codec code;
//    string s=code.serialize(root);
//    cout << s << endl;
//    TreeNode* node = code.deserialize(s);
//}

///////////////////////////////////////////正常括号序列的组合////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/remove-invalid-parentheses/solution/shan-chu-wu-xiao-de-gua-hao-by-leetcode-9w8au/
//class Solution {
//public:
//    unordered_set<string> uset;
//    
//    void backtracking(const string& s, string& path, int l, int r, int index, int lc, int rc)//必须用引用，否则会超时，引用传递比值传递快很多
//     //path是遍历到当前index为止，正常的括号序列，l和r是应该继续删除的（和）数量，每删除一个对应数值就要减去1
//     //index是当前的位置，lc和rc是path中（和）数量
//    {
//        if (index==s.length()){//如果已经遍历完所以字符，那么看多余的l和r是否删除完了
//            if (l == 0 && r == 0)
//            {
//                uset.insert(path);//去重
//            }
//            return;
//        }
//        if (s[index] == '(' && l > 0)//不知道这个（是不是多余的，所以尝试着删除它并进入下一层循环，如果是多余的话就会保存结果返回，不是的话
//                                     //就直接返回
//        {
//            backtracking(s, path, l - 1, r, index + 1, lc, rc);
//        }
//        if (s[index] == ')' && r > 0)//同理
//        {
//            backtracking(s, path, l, r - 1, index + 1, lc, rc);
//        }
//        path.push_back(s[index]);//如果这个（或）不是多余的，那就把它加入path
//        if (s[index] != '(' && s[index] != ')')//字母的话直接进入下一层循环
//        {
//            backtracking(s, path, l, r, index + 1, lc, rc);
//        }
//        else if (s[index] == '(')//（的话path中的（个数，也就是lc就要+1再进入下一层循环，
//         //这里不用考虑左括号的数量是不是大于n/2了，因为我们把删除括号的选项放在前面了，如果左括号的数量多了，那么就不可能执行到这个if语句来，
//         //换句话说执行到这一句的话，左括号的数量一定小于这一层的path长度/2
//        {
//            backtracking(s, path, l, r, index + 1, lc + 1, rc);
//        }
//        else if (lc > rc)//）的话要判断lc和rc的大小，只有（的个数大于）的个数时才能加入），这一步是剪枝操作
//        {
//            backtracking(s, path, l, r, index + 1, lc, rc + 1);
//        }
//        path.pop_back();
//    }
//    vector<string> removeInvalidParentheses(string s) {
//        int left = 0;
//        int right = 0;
//        for (int i = 0;i < s.length();++i)
//        {
//            if (s[i] == '(')
//            {
//                left++;
//            }
//            else if (s[i] == ')')
//            {
//                if (left == 0)
//                {
//                    right++;
//                }
//                else {
//                    left--;
//                }
//            }
//        }
//        cout << left << right << endl;
//        string path;
//        backtracking(s, path, left, right, 0, 0, 0);
//        vector<string> res;
//        return vector<string>{uset.begin(), uset.end()};
//    }
//};
//void main()
//{
//    string s = "(a))";
//    Solution so;
//    vector<string> res=so.removeInvalidParentheses(s);
//    for (auto i : res)
//    {
//        cout << i << endl;
//    }
//}

///////////////////////////////////////////扎破气球获得的最多硬币////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/burst-balloons/solution/zhe-ge-cai-pu-zi-ji-zai-jia-ye-neng-zuo-guan-jian-/
//void main()
//{
//    vector<int> nums = { 3,1,5,8};
//    int n = nums.size();
//    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));//dp[i][j]表示开区间 (i,j) 内你能拿到的最多金币
//    //创建一个辅助数组，并在首尾各添加1，方便处理边界情况
//    vector<int> temp(n + 2);
//    temp[0] = 1;
//    temp[n + 1] = 1;
//    for (int i = 1; i <= n; i++)//这里表示把nums[0]到nums[n-1]放到temp[1]到temp[n],那么temp的长度为n+2，左端点为0，右端点为n+1
//        temp[i] = nums[i - 1];
//    //len表示开区间长度（对每一个区间长度进行循环），注意外循环是区间长度，长度是从小到大的，所以小区间可以推导出大区间，比如dp[0][4]=dp[0][2]+dp[2][4],这两个值都是已经算出来的
//    for (int len = 3; len <= n + 2; len++) {//len表示开区间（i,j）的长度，而i和j之间必然有一个气球，因此len至少为3
//        //l表示开区间左端点,l + len - 1则表示开区间右端点，最远到n+1
//        for (int l = 0; l+len-1 <= n + 1; l++) {
//            //k为开区间内的索引（代表区间最后一个被戳破的气球）
//            for (int k = l + 1; k < l + len - 1; k++) {//k表示i和j中间的气球（不包括i和j）
//                int left = dp[l][k];
//                int right = dp[k][l + len - 1];
//                int sum = left + right + temp[k] * temp[l] * temp[l + len - 1];
//                dp[l][l + len - 1] = max(dp[l][l + len - 1], sum);//取金币最大值
//            }
//        }
//    }
//    cout << dp[0][n + 1] << endl;
//}

///////////////////////////////////////////可获得最高频元素的频数////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/frequency-of-the-most-frequent-element/solution/pai-xu-hua-dong-chuang-kou-tu-jie-by-aut-62jj/
//void main()
//{
//    vector<int> nums = { 1,4,8,13 };
//    int k = 5;
//    sort(nums.begin(), nums.end());//排序之后大数在右边，所以每移动一次r，都可能出现新的最高频次，
//    int n = nums.size();
//    int left = 0, ans = 1;
//    long long sum = 0;//sum表示我们要把nums里面的数增加到最高频次需要付出的代价，如果代价小于等于k，说明可以承担，可以继续增加最高频次，否则就应该减去已经付出代价中最大的一部分
//                      //也就是最左端最小的值，因为把它增大到最高频次（最右端最大的值）需要的代价最大。
//    for (int r = 1; r < n; r++) {
//        sum += (long long)(nums[r] - nums[r - 1]) * (r - left);//r每往后移动一位，都要把新加入这部分的面积加进去，nums[r] - nums[r - 1]是高，r-left是底
//        if (sum <= k)//如果总代价还是小于k，说明k能够“填满”这些数,满足条件就计算长度
//        {
//            ans = max(ans, r - left + 1);
//        }
//        else//否则的话就应该把左侧的数剔除，相应的代价也要减去，这部分代价的底是1，高是nums[r] - nums[left]
//        {
//            sum -= nums[r] - nums[left];
//            left++;
//        }
//    }
//    cout << ans << endl;
//}

///////////////////////////////////////////计算小于等于n的数二进制表示中1的个数////////////////////////////////////////////////////

//void main()
//{
//    int n = 8;
//    vector<int> dp(n + 1, 0);//dp[i]表示i的二进制表示中1的个数
//    for (int i = 1;i <= n;++i)
//    {
//        if (i % 2 == 0)
//        {//如果i是偶数，那么只需要把i/2的二进制左移，不需要额外增加1
//            dp[i] = dp[i / 2];
//        }
//        else
//        {//如果i是奇数，那么需要对i-1的二进制数末尾变成1，也就是1的个数要加1
//            dp[i] = dp[i - 1] + 1;
//        }
//    }
//    for (auto i : dp)
//    {
//        cout << i << endl;
//    }
//}

///////////////////////////////////////////二叉树的垂序遍历////////////////////////////////////////////////////

//struct cmp
//{
//    bool operator()(const pair<int, int>& s1, const pair<int, int>& s2)
//    {
//        if (s1.first < s2.first)
//            return true;//行从小到大
//        else if (s1.first == s2.first)
//        {
//            return s1.second < s2.second;//行列相同时按照值排列
//        }
//        else {
//            return false;
//        }
//    }
//};
//class Solution {
//public:
//    vector<vector<int>> res;
//    map<int, vector<pair<int, int>>> mmap;
//    void backtracking(TreeNode* node, int row, int col)
//    {
//        if (node == nullptr)
//        {
//            return;
//        }
//        mmap[col].push_back(make_pair(row, node->val));
//        backtracking(node->left, row + 1, col - 1);
//        backtracking(node->right, row + 1, col + 1);
//        return;
//    }
//    vector<vector<int>> verticalTraversal(TreeNode* root) {
//        backtracking(root, 0, 0);
//        vector<int> tmp;
//        for (auto it = mmap.begin();it != mmap.end();++it)
//        {
//            sort(it->second.begin(), it->second.end(), cmp());
//            for (int i = 0;i < it->second.size();++i)
//            {
//                tmp.push_back(it->second[i].second);
//            }
//            res.push_back(tmp);
//            tmp.clear();
//        }
//        return res;
//    }
//};
//void main()
//{
//    TreeNode* one = new TreeNode(7);
//    TreeNode* two = new TreeNode(15);
//    TreeNode* thr = new TreeNode(9);
//    TreeNode* fou = new TreeNode(20,one,two);
//    TreeNode* root = new TreeNode(3,thr,fou);
//    Solution so;
//    vector<vector<int>> res;
//    res=so.verticalTraversal(root);
//    for (auto i : res)
//    {
//        for (auto j : i)
//        {
//            cout << j << ' ';
//        }
//        cout << endl;
//    }
//}

///////////////////////////////////////////在之字形二叉树中寻找到达lable的路径，root是1////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/path-in-zigzag-labelled-binary-tree/solution/1104-er-cha-shu-xun-lu-c-100-jie-fa-wei-p3ik1/
//void main()
//{
//    int label = 14;
//    vector <int> ans;
//    while (label) {
//        ans.push_back(label);//没反转之前是从下往上的顺序
//        label >>= 1;
//    }
//    reverse(ans.begin(), ans.end());//反转之后变成从上往下，符合逻辑
//    int l, r, deep = ans.size();//deep是总层数
//    for (int i = 0; i < deep; i++) {//i=0表示第一层
//        if ((deep & 1) == (i + 1 & 1)) continue;     // 判断第 i+1 层是否需要修改，奇偶性不同的时候才需要修改，比如总共四层的时候，一和三层需要修改，即
//                                                  //i=0，i+1=1，i=2，i+1=3 与deep的奇偶性不同，需要修改
//        l = (1 << i);//l表示第i+1层最小的数,比如第三层（i=2）最小的数是4（1向左移动2位）
//        r = (1 << (i + 1)) - 1;//r表示第i+1层最大的数，比如第三层（i=2）最大的数是7（1向左移动3位-1）
//        ans[i] = r - ans[i] + l;//同一节点从左到右的索引和从右到左的索引加起来是r+l，因为同一层最大节点反转就是最小节点
//    }
//    for (auto i : ans)
//    {
//        cout << i << ' ';
//    }
//}

///////////////////////////////////////////返回局部变量值和返回局部变量引用的区别////////////////////////////////////////////////////

//int GetA() {
//    int a = 10;
//    return a;
//}
//int& GetB() {
//    int a = 8;
//    printf("a的地址是%x\n", &a);
//    return a;
//}
//void main() {
//    int a1 = 10;
//    int& a2=a1;//注意这里a2已经指向了a1的地址（引用本质上是常指针）
//    a1 = GetA();
//    printf("a1的值是%d\n", a1);
//    printf("a1的地址是%x\n", &a1);
//    //打印 10
//    //经过仔细观察内存发现   return a;这句话执行完毕后   c++编译器并没有立刻销毁a所标识的内存空间
//    //而是执行完  a1 = GetA(); 这个赋值操作之后  才会销毁内存空间
//    //所以 变量a1能够接受到局部变量a的值   打印10不是偶然成功的
//
//    a2 = GetB();
//    //前置说明 int &b=a; 
//    //引用本质上就是个常指针  b是个指针  但是引用指针b的指向的内存空间不可以改变
//    //c++编译器内部完成的是  ①创建一个int * const类型的常指针  b 
//    //② 将变量a的地址赋值给常指针 b
//    //当c++编译器发现有操作需要对(引用指针)b进行取值或者赋值操作的时候 
//    //c++编译器会默认 对b进行一个 提领 *p操作----这都是c++编译器内部行为（所以c++才会这么慢  自己隐形的做了好多操作）
//    //例如  printf("b=%d\n",b);  此时本质上是 printf("b=%d\n",*b);
//    //又例如  b=20;   本质上是 *b=20;
//    //再次强调  默认对指针进行 提领 * 操作   只是c++对引用指针的一种特殊处理 ; c++编译器不会对别的指针 默认进行 提领 * 操作
//    //如此一来  我们来分析一下  函数 GetB()
//    //当GetB()  return a；的时候  等于是  c++编译器定义了一个临时引用指针  temp
//    //将变量a的地址赋值给临时引用指针 temp  
//    //执行  a2 = GetB();  实际上是执行  a2=*temp;   
//    //经过仔细观察发现   return a;这句话执行完毕后   c++编译器并没有立刻销毁a所标识的内存空间
//    //而是执行完  a2 = GetB();  这个复制操作之后  才会销毁局部变量a的内存空间
//    //所以此时的 a2=*temp;   完全有效，a2和temp指向的地址不同，所以 "="  赋值操作  是将temp指向的值复制到 a2所指向的内存空间里
//    printf("a2的地址是%x\n", &a2); //所以这里打印出来的a2地址和a1地址相同，而和局部变量a的地址不同
//    printf("a2的值是%d\n", a2);   //打印 8
//    printf("a1此时的值是%d\n", a1);   //打印 8
//
//    int& a3 = GetB();//这里a3直接指向了返回的temp指向的地址，也就是a3和temp指向的地址相同，都是局部变量a的地址
//    //同理  对于 int &a3 = GetB();  本质上可以这样写   int &a3=*temp;
//    //此时  *temp是有值的  因为执行到 int &a3 = GetB();的时候   局部变量a的内存空间还没有被释放
//    //定义int &a3=*temp;   那么c++编译器  将把*temp的地址赋值给引用指针a3（a3=temp；）即会把指针temp的值赋值给指针a3
//    //引用指针temp的值 也就是 &a （a的地址）
//    //当执行 printf("a3的值是%d\n", a3);  本质上是执行  printf("a3的值是%d\n", *a3); 
//    //但是int &a3 = GetB();执行完成之后  局部变量a的内存空间已经被释放了
//    //temp所指向的内存空间的数据已经被系统重置了  所以 *temp的数据只能是脏数据了  a3又等于 temp
//    //因此*a3得数据也是脏数据
//    printf("a3的地址是%x\n", &a3);  //  此时a3的地址和局部变量a的地址相同
//    printf("a3的值是%d\n", a3);   //a已经被销毁了，所以a3里面的数据是脏数据
//}

///////////////////////////////////////////利用栈解码字符串////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/decode-string/solution/decode-string-fu-zhu-zhan-fa-di-gui-fa-by-jyd/
//void main()
//{
//    string s = "2[abc]3[cd]ef";
//	stack<pair<int, string>> sta;//int用来存放重复次数,string用来存放解码当前码块前已经被解码的前面所有字符，比如当i=5时，s[i]=']'，当前码块是2[abc]，已经被解码的前面所有字符为空
//	int num = 0; string res = "";//用来存放[]之间的临时字符串
//	//循环检查字符串
//	for (int i = 0; i < s.size(); i++) {
//		//遇到数字则存入num
//		if (s[i] >= '0'&&s[i] <= '9') {
//            num = num * 10 + s[i] - '0';
//		}
//		else if (s[i] == '[') {//遇到[压栈数字和字符串，置零置空，res表示在数字num之前的（不包括num）已经被解码的字符串，num表示当前码块的重复次数
//			sta.push(make_pair(num, res));
//			num = 0;
//			res = "";
//		}
//		else if (s[i] == ']') {//遇到]出栈数字和字符串，组装
//			int n = sta.top().first;//n指示的是res的循环次数，不是a的
//			string a = sta.top().second;//a指示是前面已经拓展开的字符串，[后面和]前面的存放在res中
//			sta.pop();
//			for (int i = 0; i < n; i++)  a = a + res; //循环n次，我们要做的就是把res重复n次再加到a的后面
//			res = a;          //之后若只剩下字母没有左括号，就会直接运行else加到res之后，因为它们是同一级的运算
//                              //若是左括号，res会被压入栈，作为已经拓展开的字符串，就是下一轮参与计算的a
//		}
//		else {//遇到字符存入字符
//			res += s[i];
//		}		
//	}
//    cout << res << endl;
//}

///////////////////////////////////////////利用图论解决除法求值的问题////////////////////////////////////////////////////

//class Solution {
//public:
//    bool isValid;
//    vector<double> res;
//    void graph(unordered_map<string, vector<pair<string, double>>>& umap, unordered_map<string, int>& visit, string cur, string target, double path)
//    {
//        if (isValid)
//        {
//            return;
//        }
//        if (cur == target)
//        {
//            isValid = true;
//            res.push_back(path);
//            return;
//        }
//        for (int j = 0;j < umap[cur].size();++j)
//        {
//            if (visit[umap[cur][j].first] == 0)
//            {
//                visit[umap[cur][j].first] = 1;
//                graph(umap, visit, umap[cur][j].first, target, path * umap[cur][j].second);
//                visit[umap[cur][j].first] = 0;
//            }
//        }   
//    }
//    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//        unordered_map<string, vector<pair<string, double>>> umap;
//        unordered_map<string, int> visit;
//        for (int i = 0;i < equations.size();++i)
//        {
//            umap[equations[i][0]].push_back(make_pair(equations[i][1], values[i]));
//            umap[equations[i][1]].push_back(make_pair(equations[i][0], 1.0 / values[i]));
//        }
//        for (int i = 0;i < queries.size();++i)
//        {
//            if (umap.find(queries[i][0]) == umap.end() || umap.find(queries[i][1]) == umap.end())
//            {
//                res.push_back(-1.0);
//                continue;
//            }
//            isValid = false;
//            visit[queries[i][0]] = 1;
//            graph(umap, visit, queries[i][0], queries[i][1], 1.0);
//            visit[queries[i][0]] = 0;
//            if (!isValid)
//            {
//                res.push_back(-1.0);
//            }
//        }
//        return res;
//    }
//};
//void main()
//{
//    Solution SO;
//    vector<vector<string>> equations = { {"a", "b"},{"b", "c"} };
//    vector<double> values = { 2.0,3.0 };
//    vector<vector<string>> queries = { {"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"} };
//    SO.calcEquation(equations, values, queries);
//}

///////////////////////////////////////////利用双指针来找到最短的无序子数组////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/
//void main()
//{
//    vector<int> nums = { 2,6,4,8,10,9,15 };
//    int low = nums.size() - 1;//用来标记左有序和无序两部分的分界线，即[0,low]都是递增的
//    int high = 0;//用来标记右有序和无序两部分的分界线，即[high,end]都是递增的
//    int max = nums[0];//设置两个初始值，max是从左往右遍历递增的最大值，min是从右往左遍历递减的最小值
//    int min = nums.back();
//    for (int i = 1;i < nums.size();++i)//i从第二个数开始，j从倒数第二个数开始，也可以从0开始，但是没必要
//    {
//        int j = nums.size() - 1 - i;
//        if (max <= nums[i])//如果当前的nums[i]比之前的max大，说明[0,i]都是递增的，符合顺序不需要排序，更新max进入下一次循环
//        {
//            max = nums[i];
//        }
//        else//反之说明[0,i-1]是递增的，而i是乱序，需要更新high，而max任然是nums[i-1],当循环完毕后，high更新到了乱序的最后一个位置，
//            //即[high,end]都是有序递增的
//        {
//            high = i;
//        }
//        if (min >= nums[j])//如果当前的nums[j]比之前的min小，说明[j,end]都是递增的，符合顺序不需要排序，更新min进入下一次循环
//        {
//            min = nums[j];
//        }
//        else {//反之说明[j+1,end]是递增的，而j是乱序，需要更新low，而min任然是nums[j+1],当循环完毕后，low更新到了乱序的第一个位置，
//              //即[0,low]都是有序递增的
//            low = j;
//        }
//    }
//    if (low == nums.size() - 1)
//    {
//        cout<<0<<endl;
//        return;
//    }
//    cout << high - low + 1 << endl;
//}

/////////////////////////////////////////// 从叶结点开始的最小字符串////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/smallest-string-starting-from-leaf/
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};
//class Solution {
//public:
//    string res;
//    void backtrack(TreeNode* node, string& path)
//    {
//        if (!node->left && !node->right)
//        {
//            if (res.length() == 0)
//            {
//                res = path;
//                return;
//            }
//            else
//            {
//                for (int i = path.length() - 1, j = res.length() - 1;i >= 0 &&j >= 0;--i, --j)
//                {
//                    if (path[i] < res[j])
//                    {
//                        res = path;
//                        return;
//                    }
//                    else if (path[i] == res[j])
//                    {
//                        continue;
//                    }
//                    else {
//                        return;
//                    }
//                }
//                if (path.length() < res.length())
//                {
//                    res = path;
//                    return;
//                }
//            }
//
//        }
//        if (node->left)
//        {
//            path.push_back('a' + node->left->val);
//            backtrack(node->left, path);
//            path.pop_back();
//        }
//        if (node->right)
//        {
//            path.push_back('a' + node->right->val);
//            backtrack(node->right, path);
//            path.pop_back();
//        }
//        return;
//    }
//    string smallestFromLeaf(TreeNode* root) {
//        if (!root)
//        {
//            return "";
//        }
//        string path;
//        path += root->val + 'a';
//        backtrack(root, path);
//        reverse(res.begin(), res.end());
//        return res;
//    }
//};
//void main()
//{
//    /*TreeNode* a = new TreeNode(7);
//    TreeNode* b = new TreeNode(2);
//    TreeNode* c = new TreeNode(5);
//    TreeNode* d = new TreeNode(1);
//    TreeNode* e = new TreeNode(13);
//    TreeNode* f = new TreeNode(11,a,b);
//    TreeNode* g = new TreeNode(4,c,d);
//    TreeNode* h = new TreeNode(4,f,nullptr);
//    TreeNode* i = new TreeNode(8,e,g);
//    TreeNode* j = new TreeNode(5,h,i);
//    Solution so;
//    so.pathSum(j, 22);*/
//    TreeNode* a = new TreeNode(0);
//    TreeNode* b = new TreeNode(0);
//    TreeNode* c = new TreeNode(1, a, nullptr);
//    TreeNode* d = new TreeNode(1,b,nullptr);
//    TreeNode* e = new TreeNode(2,nullptr,c);
//    TreeNode* g = new TreeNode(2,e,d);
//    Solution so;
//    so.smallestFromLeaf(g);
//}

///////////////////////////////////////////滑动窗口匹配异位词////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/
//void main()
//{
//    string s = "adcbcbcba";
//    string p = "bac";
//    if (s.length() < p.length())
//    {
//       cout<<0<<endl;
//       return;
//    }
//    vector<int> res;
//    int a[26] = { 0 }, b[26] = { 0 };
//    for (auto ch : p)
//    {
//        a[ch - 'a']++;//统计p中的每个字母频次
//    }
//    int left = 0, right = 0;
//    while (right < s.size()) {
//        b[s[right] - 'a']++;//窗口每往后移一位，把新加入字母的频次统计出来
//        int flag = 1;//窗口中的字串和p是否是异位词
//        for (int k = 0; k < 26; k++) {
//            if (a[k] != b[k]) {//只有字串字母频次和p字母频次完全相同时，标志位才为1
//                flag = 0;
//                break;
//            }
//        }
//        if (flag) res.push_back(left);//是异位词
//        if (right - left + 1 == p.size())//窗口后移
//        {
//            b[s[left] - 'a']--;//窗口最左边的字母要弹出，频次相应减去1
//            left++;//窗口后移
//        }
//        right++;
//    }
//    for (auto i : res)
//    {
//        cout << i << ' ';
//    }
//}

///////////////////////////////////////////双指针寻找符合三角形三边的组合数量////////////////////////////////////////////////////

//void main()
//{
//    vector<int> nums = { 2,2,3,4 };
//    int n = nums.size();
//    sort(nums.begin(), nums.end());
//    int ret = 0;
//
//    // [left, right] 为第三条边的合法位置
//    int k;
//
//    for (int i = 0; i < n; ++i) {
//        k = i + 2;//k是第三条边，从i+2的位置开始
//        for (int j = i + 1; j < n; ++j) {//j是第二条边，从i+1的位置开始
//            {
//                if (j > k)//如果第二条边的位置大于第三条边的位置，退出里循环，不加这个判断也可以，因为下面如果j>k的话，ret就加0，避免重复查找
//                {
//                    break;
//                }
//                while (k < n && nums[k] < nums[i] + nums[j]) k++;//只需要满足两边之和大于第三边就行了
//                ret += max(k - j - 1, 0);//此时k不符合条件,k>=j,当k=j时 ret应该加0，所以要用max
//            }
//
//        }
//    }
//    cout<<ret;
//}

///////////////////////////////////////////查找二叉搜索树任意两个节点之差的最小值（递归和迭代）////////////////////////////////////////////////////

//struct TreeNode
//{
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(){}
//    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
//    TreeNode(int x,TreeNode* p,TreeNode* q):val(x),left(p),right(q){}
//};
//class Solution
//{
//public:
//    int res=INT_MAX;
//    /*TreeNode* pre=nullptr;
//    void backtrack(TreeNode* node)
//    {
//        if (!node)
//        {
//            return;
//        }
//        backtrack(node->left);
//        if (pre && node->val - pre->val < res)
//        {
//            res = node->val - pre->val;
//        }
//        pre = node;
//        backtrack(node->right);
//        return;
//    }*/
//    int findMindiff(TreeNode* root)
//    {
//        if (!root)
//        {
//            return 0;
//        }
//        //backtrack(root);
//        stack<TreeNode*> st;
//        if (root != NULL) st.push(root);
//        TreeNode* pre = nullptr;
//        while (!st.empty()) {
//            TreeNode* node = st.top();
//            if (node != NULL) {
//                st.pop(); // 将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
//                if (node->right) st.push(node->right);  // 添加右节点（空节点不入栈）
//
//                st.push(node);                          // 添加中节点
//                st.push(NULL); // 中节点访问过，但是还没有处理，加入空节点做为标记。
//
//                if (node->left) st.push(node->left);    // 添加左节点（空节点不入栈）
//            }
//            else { 									// 只有遇到空节点的时候，才将下一个节点放进结果集
//                st.pop();           					// 将空节点弹出
//                node = st.top();    					// 重新取出栈中元素
//                st.pop();
//                if (pre && node->val-pre->val<res)
//                {
//                    res = node->val - pre->val;
//                }
//                pre = node;
//            }
//        }
//        return res;
//    }
//};
//
//void main()
//{
//    TreeNode* a = new TreeNode(1);
//    TreeNode* b = new TreeNode(7);
//    TreeNode* c = new TreeNode(15);
//    TreeNode* d = new TreeNode(4,a,b);
//    TreeNode* e = new TreeNode(10,nullptr,c);
//    TreeNode* f = new TreeNode(8,d,e);
//    Solution so;
//    cout<<so.findMindiff(f);
//}

///////////////////////////////////////////双指针解决环形数组是否存在循环////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/circular-array-loop/solution/fu-xue-ming-zhu-dong-hua-ti-jie-kuai-man-ju4g/
//void main()
//{
//	int n = 5;
//	vector<int> nums(n);
//	for (int i = 0;i < n;i++)
//	{
//		cin >> nums[i];
//	}
//    auto next = [&](int i)//	Lambda表达式,计算i要跳转的下一个索引，输出为[0,n-1]
//    {
//        return ((i + nums[i]) % n + n) % n;//(i + nums[i])可能是负数，因此(i + nums[i]) % n后还是负数（大小在-n-0之间），
//                              //需要把它变成0-n，因此加了一个n，而最后的取余是因为i + nums[i]是正数的时候加了一个n会越界，因此再次取余
//    };
//    for (int i = 0;i < n;i++)
//    {
//        if (nums[i] == 0)//访问过且不符合条件，不再访问
//        {
//            continue;
//        }
//        int slow = i;
//        int fast = next(slow);//如果fast和slow同起点的话，下面的判断会有问题，必须要先移动fast和slow使得他们不相等
//        while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(fast)] > 0)//只有前一个条件的话不能保证是单向循环，因为
//                                                                                //nums[slow]和nums[fast]有可能同时变号，参考
//            //https://leetcode-cn.com/problems/circular-array-loop/solution/huan-xing-shu-zu-shi-fou-cun-zai-xun-hua-0ay2/
//        {
//            if (slow == fast)//当两个指针相遇，说明存在循环
//            {
//                if (slow == next(slow))//循环长度为1，不符合条件，跳出
//                {
//                    cout << "循环长度为1，不符合" << endl;
//                    break;
//                }
//                else
//                {
//                    cout << "存在循环" << endl;
//                    return;
//                }
//            }
//            slow = next(slow);
//            fast = next(next(fast));
//        }
//        int add = i;
//        while (nums[add] * nums[next(add)] > 0 && nums[add] * nums[next(next(add))] > 0) {
//            int tmp = add;//如果上一个循环不符合条件，没有退出程序，就把上一个循环访问过的位置全部置零，下次循环不再访问这些位置
//            add = next(add);
//            nums[tmp] = 0;
//        }
//    }
//    cout << "不存在循环" << endl;
//    return;
//}

///////////////////////////////////////////利用图论解决任意两个结点之间最短路径的问题////////////////////////////////////////////////////

//void main()
//{
//    vector<vector<int>> graph = { {1},{0,2,4},{1,3,4},{2},{1,2} };
//    int n = graph.size();
//    queue<tuple<int, int, int>> q;//[u, mask, dist] ·u 表示当前位于的节点编号；
//                                  //·mask 是一个长度为n的二进制数，表示每一个节点是否经过。如果mask 的第i位是1，则表示节点i已经过，
//                                //否则表示节点i未经过,这里的i是从右边数的
//                                //比如n=5,00001表示结点0已经过，其他未经过，01000表示结点4已经过，其他未经过
//                                //·dist 表示到当前节点为止经过的路径长度
//    vector<vector<int>> vis(n, vector<int>(1 << n));
//    //二维标记数组vis记录某一状态(这个状态指的是全图的状态，包括当前位于那个节点和当前哪些节点被访问过。比如从0->1->2，当前位于2
//    //mask=00111,dist=2,vis[2][7]=true;再比如1->2，当前位于2，mask=00110，dist=1，vis[2][6]=true;
//    //总共有n个节点，每个节点对应的状态就有1<<n个，也就是全图的状态总共有n*（1<<n）个）
//    //这样可以防止被重复扩展（比如从0->1->2->1->2->1->2...
//    //最开始的0->1->2->1是没有问题的，可以正常访问，因为0->1对应的是[1,00011,1]，全图状态vis[1][3]=true；1->2对应的是[2,00111,2]，
//    //全图状态vis[2][7]=true，后面2->1对应的是[1,00111,3]，全图状态vis[1][7]=true。但是再往下1->2就不能访问了，因此此时对应的是[2,00111,4]
//    //vis[2][7]已经是true了，所以不能访问,这样避免循环。                
//    for (int i = 0; i < n; ++i) {//最开始的时候可以从任一结点开始，所以把[0,00001,0][1,00010,0][2,00100,0]...都加入队列，对应的访问状态数组
//        q.emplace(i, 1 << i, 0);//vis[0][1]=vis[1,2]=vis[2,4]...=true。
//        vis[i][1 << i] = true;
//    }
//    //由于是从任一节点开始访问，并且每一轮每一节点只走一步，所以最先访问完所有节点的一定是最短路径
//    int ans = 0;
//    while (!q.empty()) {
//        int u = get<0>(q.front());
//        int mask = get<1>(q.front());
//        int dist = get<2>(q.front());
//        q.pop();
//        if (mask == (1 << n) - 1) {//当mask=11111时，访问完所有结点，记录路径长度退出
//            ans = dist;
//            break;
//        }
//        // 搜索相邻的节点
//        for (int v : graph[u]) {
//            // 将 mask 的第 v+1 位置为 1
//            int mask_v = mask | (1 << v);//改变状态用的是或，也就是mask原本是1的位置不用管，把从右到左第v+1位置为1
//            //v表示这一步要去的目标节点，mask_v表示走了这一步以后全图的访问情况，比如最开始从0开始访问，mask是00001，第一步走向1以后mask_v变成00011
//            if (!vis[v][mask_v]) {
//            //如果走完这一步后，全图的状态是一个新的状态，表示目前还不是循环状态，可以正常访问，那么就把对应的节点加入队列，如果全图的状态
//            //并不是新状态，说明已经陷入循环中了，下一步要换一个节点访问，比如1->2->1->②是循环，不能访问最后一个2，应该访问1->2->1->0或
//            //1->2->1->4
//                q.emplace(v, mask_v, dist + 1);
//                //相应的全图状态也要更新
//                vis[v][mask_v] = true;
//            }
//        }
//    }
//    cout<<ans;
//}

///////////////////////////////////////////根据中序和后序遍历建立一棵树////////////////////////////////////////////////////

//struct TreeNode
//{
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode():val(0),left(nullptr),right(nullptr){}
//    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x,TreeNode* p,TreeNode* q) :val(x), left(p), right(q) {}
//};
//TreeNode* backtrack(vector<int>& inorder, vector<int>& postorder, int inlow, int inhigh,int postlow,int posthigh)
//{
//    if (inlow > inhigh)
//    {
//        return nullptr;
//    }
//    if (inlow == inhigh)
//    {
//        TreeNode* node = new TreeNode(inorder[inlow]);
//        return node;
//    }
//    TreeNode* node = new TreeNode(postorder[posthigh]);
//    int index;
//    for (int i = inlow;i <= inhigh;++i)
//    {
//        if (inorder[i] == postorder[posthigh])
//        {
//            index = i;
//            break;
//        }
//    }
//    //中序遍历可以简单切割，但是后序和前序需要讨论范围index-1-inlow就是要切割的长度，每一次切割中序和后序应该保持相同长度
//    node->left = backtrack(inorder, postorder, inlow, index - 1, postlow, postlow+index-1-inlow);
//    node->right = backtrack(inorder, postorder, index+1, inhigh, postlow + inlow+index, posthigh - 1);
//    return node;
//
//}
//void main()
//{
//    vector<int> inorder = { 4,8,2,5,9,1,10,6,11,3,7 };
//    vector<int> postorder = { 8,4,9,5,2,10,11,6,7,3,1 };
//    int n = inorder.size();
//    TreeNode* root= backtrack(inorder, postorder, 0, n - 1,0,n-1);
//    cout << root->val << endl;
//}

///////////////////////////////////////////根据中序和前序遍历建立一棵树////////////////////////////////////////////////////

//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//class Solution {
//public:
//    TreeNode* backtrack(vector<int>& preorder, vector<int>& inorder, int prestart, int preend, int instart, int inend)
//    {
//        if (instart == inend)
//        {
//            TreeNode* node = new TreeNode(inorder[instart]);
//            return node;
//        }
//        if (instart > inend)
//        {
//            return nullptr;
//        }
//        int index;
//        for (int i = instart;i <= inend;i++)
//        {
//            if (inorder[i] == preorder[prestart])
//            {
//                index = i;
//                break;
//            }
//        }
//        TreeNode* node = new TreeNode(preorder[prestart]);
//        node->left = backtrack(preorder, inorder, prestart + 1, prestart + (index - instart), instart, index - 1);
//        node->right = backtrack(preorder, inorder, prestart + (index - instart) + 1, preend, index + 1, inend);
//        return node;
//    }
//    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//        if (preorder.size() == 0)
//        {
//            return nullptr;
//        }
//        int n = preorder.size() - 1;
//
//        int prestart = 0, preend = n, instart = 0, inend = n;
//        return backtrack(preorder, inorder, prestart, preend, instart, inend);
//    }
//};
//void main()
//{
//    Solution so;
//    vector<int> preorder = { 1,2,3,4 };
//    vector<int> inorder = { 1,2,3,4 };
//    so.buildTree(preorder, inorder);
//}

///////////////////////////////////////////以数组中最大的数为根节点建立一棵树////////////////////////////////////////////////////

//struct TreeNode
//{
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode() :val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode* p, TreeNode* q) :val(x), left(p), right(q) {}
//};
//TreeNode* backtrack(vector<int>& nums, int low, int high)
//{
//    if (low > high)
//    {
//        return nullptr;
//    }
//    if (low == high)
//    {
//        TreeNode* node = new TreeNode(nums[low]);
//        return node;
//    }
//    TreeNode* node = new TreeNode(0);
//    int index;
//    int maxValue=INT_MIN;
//    for (int i = low;i <= high;i++)
//    {
//        if (maxValue < nums[i])
//        {
//            maxValue = nums[i];
//            index = i;
//        }
//    }
//    node->val = maxValue;
//    node->left = backtrack(nums, low, index - 1);
//    node->right = backtrack(nums, index+1, high);
//    return node;
//}
//void main()
//{
//    vector<int> nums = { 3,2,1,6,0,5 };
//    TreeNode* root = backtrack(nums, 0, nums.size()-1);
//}

///////////////////////////////////////////丑数一////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/ugly-number-ii/solution/chou-shu-ii-by-leetcode-solution-uoqd/
//pi的含义是有资格同i相乘的最小丑数的位置。这里资格指的是：如果一个丑数nums[pi]通过乘以i可以得到下一个丑数，那么这个丑数nums[pi]
//就永远失去了同i相乘的资格（没有必要再乘了），我们把pi++让nums[pi]指向下一个丑数即可。
//·不懂的话举例说明：
//·一开始，丑数只有{ 1 }，1可以同2，3，5相乘，取最小的1×2 = 2添加到丑数序列中。
//·现在丑数中有{ 1，2 }，在上一步中，1已经同2相乘过了，所以今后没必要再比较1×2了，我们说1失去了同2相乘的资格。
//·现在1有与3，5相乘的资格，2有与2，3，5相乘的资格，但是2×3和2×5是没必要比较的，因为有比它更小的1可以同3，5相乘，
//所以我们只需要比较1×3，1×5，2×2。
//·依此类推，每次我们都分别比较有资格同2，3，5相乘的最小丑数，选择最小的那个作为下一个丑数，假设选择到的这个丑数是同i（i = 2，3，5）
//相乘得到的，所以它失去了同i相乘的资格，把对应的pi++，让pi指向下一个丑数即可。
//void main()
//{
//    int p2 = 1;//下一个丑数(dp[i])是当前指针p1,p2,p3指向的丑数（这三个指针指的都是dp中的丑数）乘以对应的质因数（2,3,5）
//    int p3 = 1;//三个指针可以相同，也可以不同
//    int p5 = 1;
//    int n = 12;//要求的第n个丑数
//    vector<int> dp(n + 1);
//    dp[1] = 1;//第一个丑数是1
//    for (int i = 2;i <= n;i++)
//    {
//        dp[i] = min({ dp[p2] * 2,dp[p3] * 3,dp[p5] * 5 });//三个指针指的丑数分别乘以2,3,5,，得到另外三个丑数，而新丑数必定大于dp[i-1]
//        //因为在计算dp[i]时，指针 px（x∈{ 2,3,5 }) 的含义是使得dp[j]* x > dp[i−1] 的最小的下标j，即当j>=px时
//        //dp[j]*x > dp[i−1]，当j < px时 dp[j]*x<=dp[i−1]
//
//        if (dp[i] == dp[p2] * 2)
//        {
//            p2++;
//        }
//        if (dp[i] == dp[p3] * 3)
//        {
//            p3++;
//        }
//        if (dp[i] == dp[p5] * 5)
//        {
//            p5++;
//        }
//    }
//    cout<<dp[n];
//}

///////////////////////////////////////////丑数二////////////////////////////////////////////////////

//void main()
//{
//    vector<int> primes = { 2, 7, 13, 19 };
//    int n = 12;
//    int i, j, k = primes.size();
//    vector<long> idx(k, 1);
//    vector<long long> dp(n + 1, LLONG_MAX);
//    dp[1] = 1;
//    for (i = 2; i <= n; ++i)
//    {
//        for (j = 0; j < k; ++j)
//            if (dp[idx[j]] * primes[j] < dp[i])
//                dp[i] = dp[idx[j]] * primes[j];
//        for (j = 0; j < k; ++j)
//            if (dp[i] == dp[idx[j]] * primes[j])
//                idx[j]++;
//    }
//    cout<<dp[n];
//}

///////////////////////////////////////////连续子数组的等差数列个数////////////////////////////////////////////////////

//void main()
//{
//    vector<int> nums = { 1,3,5,7,9 };
//    int n = nums.size();
//    if (n < 3)
//    {
//        cout<<0<<endl;
//        return;
//    }
//    int res = 0, cnt = 0;//cnt从0开始是因为我们最开始假设没有找到等差，当找到等差后再让cnt++，然后再加到结果中
//    for (int i = 2; i < n; ++i)
//    {
//        if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
//        //等差数组至少有三个数，所以从2开始，如果符合等差数列，就让cnt++，再加入结果集，比如最开始的1，3，5，cnt=1，res=1，然后遍历到7的时候
//        //由于7-5=5-3，说明它能加到1,3,5的后面构成一个更长的等差数列1,3,5,7，这样对res的贡献为1，另外3,5,7也是一个新的等差数列，这样对res
//        //的贡献就变成2，也就是cnt=cnt+1=2，把它加入res。
//        //·也就是说，如果nums[i]如果可以加到前面的等差数列后面形成更长的等差数列，那么它对结果的贡献(cnt)=nums[i-1]对结果的贡献+1；
//        //·反之如果它不能组成更长的等差数列，说明它对结果没有贡献，此时的cnt要清0，作为后面nums[i+1]计算的依据
//        {
//            cnt++;//找到一个等差数组
//            res += cnt;//加到结果中
//        }
//        else
//            cnt = 0;
//    }
//    cout<<res;
//}

///////////////////////////////////////////连续子序列的等差数列个数////////////////////////////////////////////////////

////https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/dong-tai-gui-hua-java-by-liweiwei1419-jc84/
//void main()
//{
//    vector<int> nums = { 7,7,7,7,7 };
//    int n = nums.size();
//    vector<unordered_map<int, int>> dp(n);//此时只记录nums[i]-nums[i-1]是不行的，因为子序列可以是不连续的，所以要用map
//    // dp[i]：以 nums[i] 结尾，公差为 key 的长度大于等于 2 的弱等差数列（可以只有两个元素）个数
//    int res = 0;
//    for (int i = 1; i < n; ++i) {//从nums[1]开始遍历，因为是弱等差数列，可以只有两个元素
//        for (int j = 0; j < i; ++j) {//在nums[0]到nums[i]之间找等差数列。可以不连续
//            long long diff = (long long)nums[i] - nums[j];//要用long long因为INT_MIN<=nums[i]<=INT_MAX，则diff有可能超出边界
//            if (diff > INT_MAX || diff < INT_MIN) {
//                continue;
//            }
//            dp[i][diff] += dp[j][diff] + 1;//map中不存在的键值默认为0，所以这个递推关系一定成立,这里要+=是因为对于不同的j，nums[i] - nums[j]
//            //可能是相同的，都要加到以nums[i]结尾的key为diff的结果中来，比如7,7,7,7,7
//            res += dp[j][diff];//·注意这里是加dp[j][diff]，如果nums[j]不是等差数列中的一项，那么dp[j][diff]=0,对结果没有影响
//        }
//    }
//    cout<<res<<endl;
//}

///////////////////////////////////////////任务调度器（桶子理论）////////////////////////////////////////////////////

////https://leetcode-cn.com/problems/task-scheduler/solution/tong-zi-by-popopop/
//void main()
//{
//    vector<char> tasks = { 'A','A','A','B','B','B','C','C','C','D','D','E' };
//    int n = 2;
//    unordered_map<char, int> hash;
//    for (char ch : tasks) {
//        hash[ch]++;//计算各个任务的频次
//    }
//    int m = 0, x = 0;//m表示所有任务种类中执行次数最多的任务次数，x表示需要执行m次的任务的个数，也就是最后一个桶子里任务的个数
//                    //这里m=3，x=3，说明执行最多次的任务次数是3（A,A,A或B,B,B或C,C,C),需要执行3次的任务个数是3（A,B,C）
//    for (auto pair : hash) {
//        if (m < pair.second) {//找到最大次数m
//            m = pair.second;
//            x = 1;
//        }
//        else if (pair.second == m) {
//            x++;
//        }
//    }
//    int num1 = tasks.size();//桶容量小于任务总数时。也就是除了最后一行以外的所有行都被任务填满了（此外还有几个任务没地方填），这样
//                            //num2算出来的值就少了多出来的那几个任务，即此时真正的答案应该是：桶容量+（任务总数-桶容量）=任务总数
//    int num2 = (m - 1) * (n + 1) + x;//任务种类较少，填不满桶时，桶容量大于任务总数。此时桶里面有冷却，并且没有剩余的任务，
                                       //这样满足题目要求的最短时间就是桶容量（再短就不满足题目要求了）
//    cout << max(num1, num2) << endl;
//}

///////////////////////////////////////////所有小于n的数字中出现1的个数（数位DP）////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/solution/mian-shi-ti-43-1n-zheng-shu-zhong-1-chu-xian-de-2/
//举个例子： n = 2304 。答案为四个部分之和：
//1. 所有小于等于2304的正整数中，个位出现1的次数.
//2. 所有小于等于2304的正整数中，十位出现1的次数.
//3. 所有小于等于2304的正整数中，百位出现1的次数.
//4. 所有小于等于2304的正整数中，千位出现1的次数.
//这四部分可以只考虑一部分，另外三部分就异曲同工了。用第二部分来举例，也就是计算所有小于等于2304的正整数中，十位出现1的次数：
//为了帮助理解，我们先想象有一个自行车密码锁（这个比喻来自@ryan0414），一共有四位，每一位可单独滚动。为了计算十位出现1的次数，
//我们考虑三种情况：
//·1. n中的十位为0.即 n = 2304。
//我们先锁住十位，强行让十位变成1，剩下三位可以随意滚动：XX1X。那么求十位出现一的个数也就是，我可以滚出多少种密码组合，
//使得该密码小于等于n（注意十位被锁定成了1，转不动）。不难发现，我们能滚出的最大数是：2219,我们能滚出的最小数是：0010。
//那么0010到2219之间有多少种十位为1的密码呢？我们去掉十位，得到000和229。一共就是229 - 000 + 1 = 230种。即n千位和百位构成的数 * 10。
//·2. n中的十位为1.即 n = 2314。
//我们先锁住十位，强行让十位变成1，剩下三位可以随意滚动：XX1X。那么求十位出现一的个数也就是，我可以滚出多少种密码组合，
//使得该密码小于等于n（注意十位被锁定成了1，转不动）。不难发现，我们能滚出的最大数是：2314,我们能滚出的最小数是：0010。
//那么0010到2314之间有多少种十位为1的密码呢？我们去掉十位，得到000和234，一共就是23 * 10 + 4 + 1 = 235种。即n千位和百位构成的数 * 10 + n个位的数字 + 1.
//·3. n中的十位为2~9中任意数字.即 n = 2324（只是一个例子，n = 2394是一样的）。
//我们先锁住十位，强行让十位变成1，剩下三位可以随意滚动：XX1X。那么求十位出现一的个数也就是，我可以滚出多少种密码组合，
//使得该密码小于等于n（注意十位被锁定成了1，转不动）。不难发现，我们能滚出的最大数是：2319,我们能滚出的最小数是：0010。
//那么0010到2319之间有多少种十位为1的密码呢？我们去掉十位，得到000和239，一共就是239 - 000 + 1 = 240种。也是（23 + 1） * 10 = 240种。即
//(n万位和千位构成的数 * +1) * 10.
//如果我们定义十位左边的数为高位，例如2304的高位为23，十位右边的数为低位，例如2304的低位为4，那么以上规律就可以写成高位和低位的规律。
//我们分别对2304的每一位做一次分析，并将四部分结果相加就得到了答案。
//void main()
//{
//    int n = 2314;
//    long digit = 1, res = 0;//digit表示第几位，1表示个位，10表示十位...res表示结果
//      //high表示高位，low表示低位，一开始计算个位，个位的高位就是 n / 10，低位就是0，cur表示当前位的数字，
//      //·比如2314，digit=1时high=231，low=0，cur=4；digit=10时high=23，low=4，cur=1；
//      //·digit=100时high=2，low=14，cur=3；digit=1000时high=0，low=314，cur=2
//    long high = n / 10, cur = n % 10, low = 0;
//    while (high != 0 || cur != 0) {// 当 high 和 cur 同时为 0 时，说明已经越过最高位，因此跳出,只有一个条件的话不能保证遍历完成了
//                                   //比如digit=1000时，high=0但是cur=1，此时正在遍历最高位，不能退出。
//        if (cur == 0) res += high * digit;//此位 1 的出现次数只由高位 high决定，第一种情况
//        else if (cur == 1) res += high * digit + low + 1;//此位 1 的出现次数由高位 high和低位 low 决定,第二种情况
//        else res += (high + 1) * digit;//此位 1 的出现次数只由高位 high 决定,第三种情况
//        low += cur * digit;//低位每次要加上cur*位数，见案例5707行
//        cur = high % 10;//cur每次取high的最低位
//        high /= 10;//将本轮 high 最低位删除，得到下轮 high
//        digit *= 10;//位因子每轮 × 10
//    }
//    cout<<res<<endl;
//}

///////////////////////////////////////////优美排列的个数（状态压缩DP）////////////////////////////////////////////////////

//void main()
//{
//    // 用 mask 的二进制表示选取状态，n 个数字用 n 位表示，从右往左第 i+1 位为 1 代表数字 i+1 已被选取（i=0~n-1），
//    // mask 中 1 的个数 num 代表前num位已放置（注意是前m位，也就是0,1,2,...num-1的位置已经被放置，下一个要放的就是num的位置）
//    // 例如：二进制 100110 共三个1，代表排列的前三位已放置数字，三个1分别在二进制第 1、2、5位置上(从右侧开始，从0开始计数）, 
//    // 所以 2、3、6三个数字被选取，综合起来就是表示：2 3 6 这三个数字被放到了排列的前三位，三个数字完美排列方式未知，
//    // 通过枚举 mask 进行计算
//    int n = 10;
//    vector<int> f(1 << n);// 用来存储中间结果，f[6] = f[000110] = 数字2、3在前两位时的完美排列数量,总共有2^n-1中可能，所以左移n位
//    f[0] = 1;
//    // 通过 mask 进行枚举，最终目的是为了得到二进制 mask = (11..11)n 时，总的完美排列数 
//    for (int mask = 1; mask < (1 << n); mask++) {
//        int num = __builtin_popcount(mask);
//        // ·遍历 mask 的每一位，仍以 mask = 100110 为例，此 mask 代表 2 3 6三个数字在排列的前三位
//        // ·求三个数字 2 3 6 的完美排列方式，则先确定2 3 6哪些数字能放到第三位，然后累加另外两个数字的完美排列数量来获得
//        // ·2 3 6，第三位可以为 6，则 f[100110] += f[000110] (2、3在前两位时的完美排列数量)
//        // ·2 3 6，第三位可以为 3，则 f[100110] += f[100010] (2、6在前两位时的完美排列数量)
//        for (int i = 0; i < n; i++) {
//            // mask & (1<<i) 用来判断 mask 第 i 位是否为 1，如果为 1，说明第 i+1 个数字被选取
//            // ((num % (i + 1)) == 0 || (i + 1) % num == 0) 判断被选取的数字 i+1 能否放到位置 num 上，
//            // 即：先从被选取的数字中找到能放到位置num上的数字，然后将剩余num-1个数字的完美排列方式累加到f[mask]中
//            // num表示下一个要放数的位置（索引），i+1表示可以放在num上的数，比如上面那个例子，num就是第三位，i+1就是2,3,6
//            if ((mask & (1 << i)) != 0 && ((num % (i + 1)) == 0 || (i + 1) % num == 0)) {
//                // mask ^ (1 << i) 将 mask 第 i 位设置为 0
//                //^表示异或，相同为0，比如计算f[100110]的时候i=2满足if，那么f[100110] += f[100010]，右边第3位变成了0
//                //i=5的时候也满足if，那么f[100110] += f[000110]，右边第6位变成了0
//                f[mask] += f[mask ^ (1 << i)];
//            }
//        }
//    }
//    cout<<f[(1 << n) - 1]<<endl;
//}

///////////////////////////////////////////环球旅行规划合理的飞行路线总数（回溯和map的灵活运用）//////////////////////////////////

//https://leetcode-cn.com/problems/reconstruct-itinerary/solution/332-zhong-xin-an-pai-xing-cheng-hui-su-fa-shen-sou/
//class Solution {
//public:
//    vector<string> res;
//    bool backtrack(vector<vector<string>>& tickets, unordered_map<string, map<string, int>>& umap)
//    {
//        if (res.size() == tickets.size() + 1)
//        {//最终旅游的城市数一定比机票数多一个
//            return true;
//        }
//        for (auto& t :umap[res.back()])//要注意这里只能是引用的形式，因为要更改umap里面的内容，如果是值传递的话就只能更改t的值，umap没改变
//                                      //引用传递相当于给umap里面的map起了个新的变量名，指向的内存地址是相同的，所以可以改变umap的值
//        {//其实也可以用迭代器，只要记住umap必须修改
//            if (t.second > 0)
//            {
//                t.second--;
//                res.push_back(t.first);
//                if (backtrack(tickets, umap))
//                {
//                    return true;//只要找到一条路径就立刻返回，找不到才回溯
//                }
//                res.pop_back();
//                t.second++;
//            }
//        }
//        return false;
//    }
//    vector<string> findItinerary(vector<vector<string>>& tickets) {
//        unordered_map<string, map<string, int>> umap;//map排序，字典序更小的到达城市排在更前面，因此最终答案的字典序一定最小
//        for (auto i : tickets)
//        {//从i[0]到i[1]有多少张机票
//            umap[i[0]][i[1]]++;
//        }
//        res.push_back("JFK");//必须从JFK机场出发
//        backtrack(tickets, umap);
//        return res;
//    }
//};
//void main()
//{
//    Solution so;//给定一些机票，全部都只用一次，要求一个合理的字典序最小的旅游路线（必定存在）
//    vector<vector<string>> tickets = { {"JFK", "SFO"},{"JFK", "ATL"},{"SFO", "ATL"},{"ATL", "JFK"},{"ATL", "SFO"} };
//    vector<string> res=so.findItinerary(tickets);
//    for(auto& s:res)
//    {
//        cout << s << "-";
//    }
//}

///////////////////////////////////////////压缩字符串（双指针）//////////////////////////////////

//void main()
//{
//    vector<char> chars = { 'a','b','b','b','b', 'b','b', 'b','b', 'b','b', 'b','b', 'c' };
//    int n = chars.size();
//    int slow = 0;//slow表示重复字符段的起始点
//    int fast = 0;//fast表示重复字符段的结束点
//    int len = 0;//len表示下一个正确字符应该放的位置，len左边是已经放好的字符
//    while (fast < n)
//    {
//        if (fast == n - 1 || chars[fast + 1] != chars[fast])//当我们找到了重复字符的结束点或者右端点
//        {
//            chars[len] = chars[fast];//先把这个正确字符放在len的位置上
//            len++;//然后要放该重复字符的长度了，所以len++
//            int num = fast - slow + 1;//计算重复长度
//            if (num > 1)//如果重复长度大于1
//            {
//                for (char ch : to_string(num))//转换成字符
//                {
//                    chars[len] = ch;//逐个放入
//                    len++;
//                }
//            }
//            slow = fast + 1;//全部放好以后slow指向下一段重复字符的起始点
//        }
//        fast++;//如果重复字符还没有结束，fast向后移；如果重复字符结束了，fast也向后移
//    }
//    for (int i=0;i<len;i++)
//    {
//        cout << chars[i] << ' ';
//    }
//}

///////////////////////////////////////////有重复值的旋转数组找最小值（二分法变种）////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/solution/154-find-minimum-in-rotated-sorted-array-ii-by-jyd/
//补充思考： 为什么本题二分法不用 nums[mid] 和 nums[left]作比较？
//二分目的是判断 mid在哪个排序数组中，从而缩小区间。而在 nums[mid] > nums[left]（因为本题是非递减数组）情况下，无法判断 mid 在哪个排序数组中。
//参考 https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/solution/xun-zhao-xuan-zhuan-pai-xu-shu-zu-zhong-de-zui--16/1371193
//本质上是由于right初始值肯定在右排序数组中； left 初始值无法确定在哪个排序数组中。举例如下：
//·对于以下两示例，当 left = 0, right = 4, mid = 2 时，有 nums[mid] > nums[left] ，而结果不同。
//[1, 2, 3, 4, 5] 旋转点 x = 0 ： mid 在右排序数组（此示例只有右排序数组）；
//[3, 4, 5, 1, 2] 旋转点 x = 3 ： mid 在左排序数组。
//void main()
//{
//    vector<int> numbers = { 7,8,9,10,0,1,1,2,3,4};
//    int left = 0;
//    int right = numbers.size()-1;
//    while (left <= right)//关于为什么当numbers[right] > numbers[mid]时，这里可以是left<right的解释：表面上看right=mid时是只查找左排序数组
//                        //但是要注意比较的两个数是numbers[right] 和 numbers[mid]，也就是说numbers[right]已经在考虑的范围内了
//    {
//        int mid = left + (right - left) / 2;
//        if (numbers[right] < numbers[mid])
//        {
//            left = mid + 1;
//        }
//        else if (numbers[right] > numbers[mid])
//        {
//            right = mid;//mid有可能是最小的，不能轻易排除，同时因为比较的是mid和right，所以不用担心right是最小值的时候会被抛弃
//        }
//        else
//        {
//            right = right - 1;
//        }
//    }
//    cout<<numbers[left]<<endl;
//}


///////////////////////////////////////////利用两个优先队列来找中位数////////////////////////////////////////////////////

////https://leetcode-cn.com/problems/find-median-from-data-stream/solution/gong-shui-san-xie-jing-dian-shu-ju-jie-g-pqy8/
//class MedianFinder {
//public:
//    /** initialize your data structure here. */
//    priority_queue<int> queMin;//小数用的是大顶堆，最大的值在最前面
//    priority_queue<int, vector<int>, greater<int>> queMax;//大数用的是小顶堆，最小的值在最前面
//    //需要保证小数永远比大数多一个或者两者相同，这样：
//    //·当总个数为奇数时返回的中位数就是小数最前面的值，
//    //·当总个数为偶数时返回小数最前面和大数最前面的平均值
//    MedianFinder() {}
//
//    void addNum(int num) {
//        if (queMin.empty() || num <= queMin.top()) {//两个队列都是空的时候或者num <= queMin.top()直接插入到小数中
//            queMin.push(num);//此时num 小于等于中位数，我们需要将该数添加到queMin 中。
//            //新的中位数将小于等于原来的中位数，因此我们可能需要将queMin 中最大的数移动到queMax 中。
//            //·注意是可能要移动，我们要保证的是小数比大数多一个或相等，所以小数比大数多 *两个* 的时候我们需要移动
//            if (queMax.size() + 1 < queMin.size()) {
//                queMax.push(queMin.top());
//                queMin.pop();
//            }
//        }
//        else {
//            queMax.push(num);//此时num 大于中位数，我们需要将该数添加到queMin 中。
//            //新的中位数将大于等于原来的中位数，因此我们可能需要将queMax 中最小的数移动到queMin 中
//            //·我们要保证的是小数比大数多一个或相等，所以大数比小数多的时候我们需要移动
//            if (queMax.size() > queMin.size()) {
//                queMin.push(queMax.top());
//                queMax.pop();
//            }
//        }
//    }
//
//    double findMedian() {
//        if (queMin.size() > queMax.size()) {
//            return queMin.top();
//        }
//        return (queMin.top() + queMax.top()) / 2.0;
//    }
//};
//void main()
//{
//    MedianFinder me;
//    me.addNum(1);
//    me.addNum(2);
//    cout<<me.findMedian()<<endl;
//    me.addNum(3);
//    me.addNum(4);
//    cout << me.findMedian() << endl;
//}

///////////////////////////////////////////剪绳子（DP）////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/jian-sheng-zi-lcof/solution/jian-zhi-offer-14-i-jian-sheng-zi-huan-s-xopj/
//void main()
//{
//    int n = 10;
//    vector<int> dp(n + 1, 1);//dp[i]表示长度为 i 的绳子剪成多段后的最大乘积，初始化 dp[2] = 1，因为必须要把 2 分成  1 和 1 
//    for (int i = 3; i < n + 1; i++) 
//    {
//        for (int j = 2; j < i; j++) 
//        {//先把绳子剪掉第一段（长度为j），如果只剪掉长度为 1，对最后的乘积无任何增益，所以从长度为 2 开始剪
//         //剪了第一段后，剩下(i - j)长度可以剪也可以不剪。如果不剪的话长度乘积即为j * (i - j)；如果剪的话长度乘积即为j * dp[i - j]。取两者最大值max(j * (i - j), j * dp[i - j])
//         //第一段长度j可以取的区间为[2,i)，对所有j不同的情况取最大值，因此最终dp[i]的转移方程为 dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]))
//            dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
//        }
//    }
//    cout << dp[n] << endl;
//    return;
//}

///////////////////////////////////////////剪绳子Ⅱ（贪心）////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof/solution/mian-shi-ti-14-ii-jian-sheng-zi-iitan-xin-er-fen-f/
//不能再用DP，是因为DP中有求最大值的操作，而取余会影响最大值，所以用贪心算法
//·核心思想是尽可能把绳子分成长度为3的小段，这样乘积最大
//void main()
//{
//    int n = 100;
//    if (n == 2)//n小于4的时候直接输出即可
//    {
//        cout << 1 << endl;
//        return;
//    }
//    if (n == 3)
//    {
//        cout << 2 << endl;
//        return;
//    }
//    if (n == 4)
//    {
//        cout << 4 << endl;
//        return;
//    }
//    long result = 1;
//    while (n > 4) {//·为什么不是大于5结束？ 因为5可以分成2和3，乘积是6，比直接乘以5大
//        result *= 3;//·为什么不是大于3结束？因为4如果分成1和3的话，乘积是3，比直接乘以4小
//        result = result % (int)1e9+7;
//        n -= 3;
//    }
//    result *= n;
//    cout<<result % 1000000007<<endl;
//}

///////////////////////////////////////////按权重选择数字////////////////////////////////////////////////////

////https://leetcode-cn.com/problems/random-pick-with-weight/solution/cer-fen-xiang-jie-by-xiaohu9527-nsns/
//class Solution {
//public:
//    int sum = 0;
//    vector<int> presum;
//    Solution(vector<int>& w) {
//        srand((unsigned)time(NULL));//以系统时间为随机种子产生随机数，否则每一次执行都产生相同的随机数
//        presum.push_back(w[0]);//计算前缀和，如果presum和w需要相同长度的话，就要先加入w[0]
//        for (int i = 1;i < w.size();i++)//从1开始
//        {
//            presum.push_back(presum.back() + w[i]);//前缀和为[1,3,6,10]
//        }
//        sum = presum.back();//sum表示随机数的范围
//    }
//
//    int pickIndex() {
//        int t = rand() % sum;//产生[0,sum-1]的随机数，[0]对应的是前缀和1，[1,2]对应的是前缀和3，[3,5]对应的是前缀和6，[6,9]对应的是前缀和10
//        //这样就把每个数被选择的概率和权重（前缀和与前一个前缀和的差越大，表示这个数越大，权重越大，被选择概率越大）联系起来了，详见链接
//        return upper_bound(presum.begin(), presum.end(), t) - presum.begin();//寻找前缀和里面第一个比随机数t大的位置
//        //比如产生0，第一个比它大的是1，索引是0；产生7，第一个比它大的是10，索引是3
//    }
//};
//void main()
//{
//    Solution so(vector{ 1,2,3,4 });
//    cout<<so.pickIndex()<<' ';
//    cout << so.pickIndex() << ' ';
//    cout << so.pickIndex() << ' ';
//    cout << so.pickIndex() << ' ';
//    cout << so.pickIndex() << endl;
//}

///////////////////////////////////////////差分数组和前缀和的联系////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/corporate-flight-bookings/solution/gong-shui-san-xie-yi-ti-shuang-jie-chai-fm1ef/1109841
//·注意到一个预订记录实际上代表了一个区间的增量。我们的任务是将这些增量叠加得到答案。因此，我们可以使用差分解决本题。
//差分数组对应的概念是前缀和数组，对于数组[1,2,2,4]，其差分数组为[1,1,0,2]，差分数组的第 i 个数即为原数组的第i−1 个元素和第i 个元素的差值，
//也就是说我们对差分数组求前缀和即可得到原数组。
//·差分数组的性质是，当我们希望对原数组的某一个区间[left, right]施加一个增量inc时，差分数组 d 对应的改变是：
//  d[left]增加inc，d[right + 1] 减少inc。这样对于区间的修改就变为了对于两个位置的修改。并且这种修改是可以叠加的，
//  即当我们多次对原数组的不同区间施加不同的增量，我们只要按规则修改差分数组即可。
//·注意本题中原数组为全0数组，因为在没有记录之前所有航班的预定数为0
// 初始情况: 
    // index: [0, 1, 2, 3, 4, 5]   (因为题目中的起始编号从1开始, 所以这里可以多设置一位 以便能取到索引n)
    //  diff: [0, 0, 0, 0, 0, 0]
    // 第一个预订记录: bookings[0] = [1, 2, 10]
    // 我们给差分数组索引为1的地方diff[1] 增加10, 表示从第1个航班往后会多出10个预定记录
    // 我们给差分数组索引为3(因为会记录中是闭区间, 所以这里要给2加上1)的地方diff[3] 减去10, 表示这10个预订记录到第2个航班结束
    // index: [0,  1, 2,   3, 4, 5]
    //  diff: [0, 10, 0, -10, 0, 0]
    //
    // 同理这样考虑第2个预订记录: bookings[1] = [2, 3, 20]
    // 我们给差分数组索引为2的地方diff[2] 增加20, 表示从第2个航班往后会多出20个预定记录
    // 我们给差分数组索引为4的地方(因为会记录中是闭区间, 所以这里要给3加上1)diff[4] 减去20, 表示这20个预订记录到第3个航班结束
    // index: [0,  1,  2,   3,   4, 5]
    //  diff: [0, 10, 20, -10, -20, 0]
    //
    // 同理这样考虑第3个预订记录: bookings[2] = [2, 5, 25]
    // 我们给差分数组索引为2的地方diff[2] 增加25, 表示从第2个航班往后会多出25个预定记录
    // 我们给差分数组索引为6的地方(因为会记录中是闭区间, 所以这里要给5加上1)diff[6] 减去25, 表示这25个预订记录到第5个航班结束
    // 但我们发现索引6会越界, 所以为了不越界, 我们还需要再多开辟一位, 当然也可以用别的方式实现(加条件判断等等)
    // index: [0,  1,  2,   3,   4, 5,   6]
    //  diff: [0, 10, 45, -10, -20, 0, -25]
    //
    // 然后我们就用求前缀和的思想, 从索引1开始每求出一个前缀和
    //        index: [0,  1,  2,   3,   4,  5,   6]
    //         diff: [0, 10, 45, -10, -20,  0, -25]
    // diff_pre_sum: [0, 10, 55,  45,  25, 25,   0]
//void main()
//{
//    vector<vector<int>> bookings = { {1,2,10},{2,3,20},{2,5,25} };
//    int n = 5;
//    vector<int> res(n+2, 0);//差分数组
//    for (int i = 0;i < bookings.size();i++)
//    {
//        res[bookings[i][0]] += bookings[i][2];//这里不用考虑下标的对应关系，因为我们的差分数组多开了两个空间，和次序是对应的
//        res[bookings[i][1]+1] -= bookings[i][2];
//    }
//    for (int i = 1;i <= n;i++)
//    {
//        res[i] += res[i - 1];//对差分数组求前缀和，i=0的时候不用考虑，因为下标和次序是对应的，i=1就代表第一架航班
//        cout << res[i] << endl;
//    }
//    
//}

///////////////////////////////////////////C++强制类型转换举例说明////////////////////////////////////////////////////

//class Test
//{
//    int mValue;
//public:
//    Test()
//    {
//        mValue = 0;
//    }
//
//    explicit Test(int i)//对于只有一个参数的构造函数而言，如果不指明是explicit显式转换的话，那么下面得t1=10，t1=10.5都能通过编译，因为默认隐式转换
//    {
//        mValue = i;
//    }
//
//    Test operator + (const Test& p)
//    {
//        Test ret(mValue + p.mValue);
//
//        return ret;
//    }
//
//    int value()
//    {
//        return mValue;
//    }
//};
//
//int main()
//{
//    Test t;
//    Test t1;
//    //t1 = 10;  //Error
//    //t1 = 10.5;  //Error
//    t = static_cast<Test>(5);    // t = Test(5);强制转换，把常量 5 强制转成 Test 对象
//    Test r;
//    r = t + static_cast<Test>(10);   // r = t + Test(10);
//    cout << r.value() << endl;
//    return 0;
//}

///////////////////////////////////////////函数指针和指针函数的区别于联系////////////////////////////////////////////////////

//https://blog.csdn.net/qq_35866736/article/details/101105096
//typedef int (*FP_CALC)(int, int);
////注意这里不是函数声明而是函数定义，它是一个地址，你可以直接输出add看看   
//int add(int a, int b)
//{
//    return a + b;
//}
//int sub(int a, int b)
//{
//    return a - b;
//}
//int mul(int a, int b)
//{
//    return a * b;
//}
//int div1(int a, int b)
//{
//    return b ? a / b : -1;
//}
////定义一个函数，参数为op，返回一个指针。该指针类型为 拥有两个int参数、   
////返回类型为int 的函数指针。它的作用是根据操作符返回相应函数的地址   
//FP_CALC calc_func(char op)
//{
//    switch (op)
//    {
//    case '+': return &add;//返回函数的地址,这里写不写&都是一样的
//    case '-': return &sub;
//    case '*': return &mul;
//    case '/': return &div1;
//    default:
//        return NULL;
//    }
//    return NULL;
//}
////s_calc_func为指针函数，返回值是指针，它的参数是 op，   
////返回值为一个拥有 两个int参数、返回类型为int 的函数指针   
//int (*s_calc_func(char op)) (int, int)//s_calc_func先与右边的（）结合，表明他是一个函数，再与左边的*结合，表明返回值是指针，再与
//                                     //右边的（）结合，表明这个指针指的是一个函数，这个函数拥有两个int参数，返回值是int，
//{                                    //也就是s_calc_func是一个函数，参数是（char op），返回值是函数指针，这个指针指向的函数名字不确定，有两个int参数，返回值是int
//    return calc_func(op);
//}
//FP_CALC s_calc_func1(char op)//这里用FP_CALC代替了函数指针，非常简单明了，实现的功能是一样的
//{
//    return calc_func(op);
//}
////最终用户直接调用的函数，该函数接收两个int整数，和一个算术运算符，返回两数的运算结果   
//int calc(int a, int b, char op)
//{
//    //其实这三个指针都是指向同一个地址，只不过写的形式不同，fp是直接返回函数地址；s_fp和fp1是通过指针函数间接返回地址
//    FP_CALC fp = calc_func(op); //fp是一个函数指针，它指向根据预算符得到各种运算的函数的地址   
//    int (*s_fp)(int, int) = s_calc_func(op);//s_fp也是一个函数指针，它指向返回值为（拥有两个int参数、返回类型为int的函数）和上面的fp是一样的，只不过写法很复杂
//    FP_CALC fp1 = s_calc_func1(op);//fp1也是一个函数指针，
//    //assert(fp != s_fp);    // assert(条件)，如果条件成立，程序就继续进行，如果不成立，程序终止，防止出现更大的错误  
//    cout << fp <<' '<< s_fp <<' '<< fp1 << endl;
//    cout <<(*s_fp)(a, b) << endl;
//    cout << (*fp)(a, b) << endl;
//    cout << (*fp1)(a, b) << endl;
//    if (fp) 
//        return (*fp)(a, b);//根据上一步得到的函数的地址调用相应函数，并返回结果   
//    else 
//        return -1;
//}
//
//void main()
//{
//    int a = 100, b = 20;
//    printf("calc(%d, %d, %c) = %d\n", a, b, '+', calc(a, b, '+'));
//    printf("calc(%d, %d, %c) = %d\n", a, b, '-', calc(a, b, '-'));
//    printf("calc(%d, %d, %c) = %d\n", a, b, '*', calc(a, b, '*'));
//    printf("calc(%d, %d, %c) = %d\n", a, b, '/', calc(a, b, '/'));
//}

///////////////////////////////////////////在A树中寻找B树////////////////////////////////////////////////////

//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//    TreeNode(int x, TreeNode* p, TreeNode* q) : val(x), left(p), right(q) {}
//};
//class Solution {
//public:
//    bool backtrack(TreeNode* a, TreeNode* b)
//    {
//        if ((!a && !b) || (a && !b))
//        {
//            return true;
//        }
//        else if ((!a && b))
//        {
//            return false;
//        }
//        if (a->val == b->val)
//        {
//            if (backtrack(a->left, b->left) && backtrack(a->right, b->right))
//            {
//                return true;
//            }
//        }
//        return false;
//    }
//    bool isSubStructure(TreeNode* A, TreeNode* B) {
//        if (!A || !B)
//        {
//            return false;
//        }
//        return backtrack(A, B) || isSubStructure(A->left,B) || isSubStructure(A->right,B);
//    }
//};
//void main()
//{
//    TreeNode* one = new TreeNode(-4);
//    TreeNode* two = new TreeNode(-3);
//    TreeNode* fiv = new TreeNode(1);
//    TreeNode* fou = new TreeNode(0,one,two);
//    TreeNode* thr = new TreeNode(1,fou,fiv);
//    TreeNode* one1 = new TreeNode(-4);
//    TreeNode* fou1 = new TreeNode(1, one1,nullptr);
//    Solution so;
//    cout<<so.isSubStructure(thr, fou1);
//}

//到这里


///////////////////////////////////////////用 Rand7() 实现 Rand10()////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/implement-rand10-using-rand7/solution/cong-zui-ji-chu-de-jiang-qi-ru-he-zuo-dao-jun-yun-/
//int rand7()
//{
//    return rand() % 7 + 1;
//}
//void main()
//{
//    while (true) {
//        int a = rand7();
//        int b = rand7();//产生1-7均匀分布的随机数
//        int num = (a - 1) * 7 + b; // rand 49,产生1-49均匀分布的随机数，相当于把二维变成一维
//        if (num <= 40)
//        {//抛弃41-49这9个数,在1-40这40个数里面，模10余0的有4个（10,20,30,40），模10余1的有4个（1，11,21,31）...，所以最后出现0,1,2,3,4,5,6,7,8,9的概率是相等的，就实现了rand10
//            cout<< num % 10 + 1<<endl;
//            return;  // 拒绝采样
//        }
//
//        a = num - 40; // rand 9，因为num在41-49内均匀分布，所以num-40在1-9内均匀分布，相当于rand9()
//        b = rand7();
//        num = (a - 1) * 7 + b; // rand 63
//        if (num <= 60)
//        {
//            cout << num % 10 + 1 << endl;
//            return;
//        }
//
//        a = num - 60; // rand 3
//        b = rand7();
//        num = (a - 1) * 7 + b; // rand 21
//        if (num <= 20)
//        {
//            cout << num % 10 + 1 << endl;
//            return;
//        }
//
//    }
//}

///////////////////////////////////////////有限状态机的转移函数////////////////////////////////////////////////////

//https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/solution/mian-shi-ti-20-biao-shi-shu-zhi-de-zi-fu-chuan-y-2/
//enum State {//enum表示枚举数据类型，state是自定义的数据类型，里面的每个标志表示一个整数，从0开始
//    STATE_INITIAL,//0，表示起始的空格
//    STATE_INT_SIGN,//1，表示符号位
//    STATE_INTEGER,//2，表示整数部分
//    STATE_POINT,//3，表示左邻是整数的小数点
//    STATE_POINT_WITHOUT_INT,//4，表示左邻不是整数的小数点
//    STATE_FRACTION,//5，表示小数部分
//    STATE_EXP,//6，表示字符e
//    STATE_EXP_SIGN,//7，表示指数部分的符号位
//    STATE_EXP_NUMBER,//8，表示指数部分的整数部分
//    STATE_END//9，表示末尾的空格
//};
//enum CharType {//状态机输入的字符类型
//    CHAR_NUMBER,//0,表示数字
//    CHAR_EXP,//1,表示e
//    CHAR_POINT,//2,表示小数点
//    CHAR_SIGN,//3,表示符号+-
//    CHAR_SPACE,//4,表示空格
//    CHAR_ILLEGAL//5,表示非法字符
//};
//CharType toCharType(char ch) {//类型转换，就是把s中的字符转换成状态机的输入
//    if (ch >= '0' && ch <= '9') {
//        return CHAR_NUMBER;
//    }
//    else if (ch == 'e' || ch == 'E') {
//        return CHAR_EXP;
//    }
//    else if (ch == '.') {
//        return CHAR_POINT;
//    }
//    else if (ch == '+' || ch == '-') {
//        return CHAR_SIGN;
//    }
//    else if (ch == ' ') {
//        return CHAR_SPACE;
//    }
//    else {
//        return CHAR_ILLEGAL;
//    }
//}
//
//bool isNumber(string s) {
//    unordered_map<State, unordered_map<CharType, State>> transfer{
//        {//空格状态下可以接受的输入包括：1，空格，转到空格状态，2，数字，转到整数状态，
//            //3，小数点，转到左邻不是整数的小数点状态（这一位是空格），4，符号，转到符号状态
//            STATE_INITIAL, {
//                {CHAR_SPACE, STATE_INITIAL},
//                {CHAR_NUMBER, STATE_INTEGER},
//                {CHAR_POINT, STATE_POINT_WITHOUT_INT},
//                {CHAR_SIGN, STATE_INT_SIGN}
//            }
//        }, {//符号状态下可以接受的输入包括：1，数字，转到整数状态，2，小数点，转到左邻不是整数的小数点（因为这一位是符号）
//            STATE_INT_SIGN, {
//                {CHAR_NUMBER, STATE_INTEGER},
//                {CHAR_POINT, STATE_POINT_WITHOUT_INT}
//            }
//        }, {//整数状态下可以接受的输入包括：1，数字，转到整数状态，2，e，转到e状态，3，小数点，转到左邻是整数的小数点（因为这一位是数字）
//            //空格，转到末尾空格状态
//            STATE_INTEGER, {
//                {CHAR_NUMBER, STATE_INTEGER},
//                {CHAR_EXP, STATE_EXP},
//                {CHAR_POINT, STATE_POINT},
//                {CHAR_SPACE, STATE_END}
//            }
//        }, {//左邻是整数的小数点状态下可以接受的输入包括：1，数字，转到小数状态，2，e，转到e状态，3，空格，转到末尾空格状态
//            STATE_POINT, {
//                {CHAR_NUMBER, STATE_FRACTION},
//                {CHAR_EXP, STATE_EXP},
//                {CHAR_SPACE, STATE_END}
//            }
//        }, {//左邻不是整数的小数点状态下可以接受的输入包括：1，数字，转到小数状态
//            STATE_POINT_WITHOUT_INT, {
//                {CHAR_NUMBER, STATE_FRACTION}
//            }
//        }, {//小数状态下可以接受的输入包括：1，数字，转到小数状态，2，e，转到e状态，3，空格，转到末尾空格状态
//            STATE_FRACTION,
//            {
//                {CHAR_NUMBER, STATE_FRACTION},
//                {CHAR_EXP, STATE_EXP},
//                {CHAR_SPACE, STATE_END}
//            }
//        }, {//e状态下可以接受的输入包括：1，数字，转到指数部分的整数状态，2，符号，转到指数部分符号状态
//            STATE_EXP,
//            {
//                {CHAR_NUMBER, STATE_EXP_NUMBER},
//                {CHAR_SIGN, STATE_EXP_SIGN}
//            }
//        }, {//指数部分符号状态下可以接受的输入包括：1，数字，转到指数部分的整数状态
//            STATE_EXP_SIGN, {
//                {CHAR_NUMBER, STATE_EXP_NUMBER}
//            }
//        }, {//指数部分整数状态下可以接受的输入包括：1，数字，转到指数部分的整数状态，2，空格，转到末尾空格状态
//            STATE_EXP_NUMBER, {
//                {CHAR_NUMBER, STATE_EXP_NUMBER},
//                {CHAR_SPACE, STATE_END}
//            }
//        }, {//末尾空格状态下可以接受的输入包括：1，空格，转到末尾空格状态
//            STATE_END, {
//                {CHAR_SPACE, STATE_END}
//            }
//        }
//    };
//
//    int len = s.length();
//    State st = STATE_INITIAL;//初始状态是起始空格状态
//
//    for (int i = 0; i < len; i++) {
//        CharType typ = toCharType(s[i]);//转换成状态机的输入
//        if (transfer[st].find(typ) == transfer[st].end()) {//如果输入是当前状态无法接受的，就直接返回false
//            return false;
//        }
//        else {//否则就跳转到下一个状态
//            st = transfer[st][typ];
//        }
//    }//退出时状态是整数、小数点、小数、指数整数、末尾空格则返回true
//    return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER || st == STATE_END;
//}
//void main()
//{
//    cout<<isNumber("12e+5.4");
//}

///////////////////////////////////////////文本空格填充以及左右对齐////////////////////////////////////////////////////

////如果某一行单词总长度不够 maxWidth，但是又无法均分到单词间隔时，多余的空格就优先从这一行的左往右分布。要求均匀。
////·按照这个规则，如果我们想知道一行中有多少个单词间隔（坑位）和他们各自需要补充多少个空格，就得计算每一行已经有多少个单词eWordsCount ，
////eWordsCount-1就是坑位数（单词间隔），maxWidth - 每一行的单词总长 eLineLen 就等于总共需要补充的空格数eBlankCount 。
////然后我们就可以计算每个坑位最少需要填补的空格个数 eAvg，即 eAvg = eBlankCount / (eWordsCount - 1); 
////但是可能会不够均分，按照题意就从左往右补，总共补 extraBlank = eBlankCount % (eWordsCount - 1);
//
//vector<string> fullJustify(vector<string>& words, int maxWidth) {
//    // 结果
//    vector<string> res;
//    int size = words.size();
//    // 每一行开始和结束的单词在words里面的索引
//    int eLeft = 0, eRight = 0;
//    // 记录每一行单词长度和
//    int eLineLen = 0;
//    // 当前行单词个数
//    int eWordsCount = 0;
//    // 当前行需要补缺的长度
//    int eBlankCount = 0;
//    // 当前行需要补空格的最少个数
//    int eAvg = 0;
//    // 当前行补完两个单词简的坑位后还多余的 空格个数
//    int extraBlank = 0;
//    while (1) {
//        eLeft = eRight;//eRight是上一行没有填入的单词，作为下一行的开头单词
//        eLineLen = 0;
//
//        // 判断：当前行已有长度 + 下一个单词的长度 + 每个单词后需要加多的空格数 <= 20
//        while (eRight < size && eLineLen + words[eRight].length() + eRight - eLeft <= maxWidth) {
//            //eLineLen是已有长度（只包括字母，不包括空格），words[eRight].length()是我们希望填入的单词长度，eRight - eLeft是默认的每个单词之间的空格（默认1个空格）
//            //·比如我们想填入第一个单词的时候，eLineLen=0，eRight=0，eLeft=0，只需要看第一个单词的长度是否小于maxWidth
//            //·再比如我们想填入第二个单词的时候，eLineLen=4，eRight=1，eLeft=0，说明假设我们已填入第二个单词，那么第一个和第二个单词之间的一个空格的长度必须要考虑
//            //·再比如我们已填入了三个单词，想填example，此时eLineLen=8，eRight=3，eLeft=0，那么此时8+7+3>16，那就不能填入了，这里的3就是假设填入四个单词后必须考虑的3个空格
//            //如果把example改成examp，此时8+5+3<=16，说明可以填入
//            eLineLen += words[eRight++].length();
//        }
//
//        // 情况1：当前行是最后一行
//        if (eRight == size) {
//            // 单词左对齐，且单词之间应只有一个空格
//            string s = "";
//            for (int i = eLeft; i < size; i++) {
//                if (i == size - 1)
//                {
//                    s += words[i];
//                }
//                else
//                {
//                    s += words[i] + ' ';
//                }
//            }
//            //在行尾补充剩余空格
//            res.push_back(s + string(maxWidth - s.length(), ' '));
//            return res;
//        }
//
//        // 当前行单词个数
//        eWordsCount = eRight - eLeft;
//
//        // 当前行需要补缺的长度
//        eBlankCount = maxWidth - eLineLen;
//
//        // 情况2：当前行只有一个单词
//        if (eWordsCount == 1) {
//            // 单词左对齐，在行尾补充剩余空格
//            res.push_back(words[eLeft] + string(eBlankCount, ' '));
//            continue;
//        }
//
//        /* 情况3：当前行不只一个单词
//         首先计算每一行两个单词之间 缺失的最少空格数，因为可能会多余出来，比如一行一共缺8个空格，但是有3个单词间隔，就不能平均分，按照题意要尽量均匀，左边优先。
//         此处 我是把每个单词后应该有的空格和 补缺空格一并处理，没有做区分。
//         */
//        eAvg = eBlankCount / (eWordsCount - 1);
//        extraBlank = eBlankCount % (eWordsCount - 1);
//
//        string s1 = "";
//        for (int i = eLeft; i < eRight; i++) {
//            if (i == eRight - 1) {
//                s1 += words[i];
//            }
//            else {
//                if (i - eLeft < extraBlank) {
//                    s1 += words[i] + string(eAvg + 1, ' ');
//                }
//                else {
//                    s1 += words[i] + string(eAvg, ' ');
//                }
//            }
//        }
//        res.push_back(s1);
//    }
//    return res;
//}
//void main()
//{
//    vector<string> words = { "ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country" };
//    vector<string> res=fullJustify(words,16);
//    for (auto str : res)
//    {
//        cout << str << endl;
//    }
//}

///////////////////////////////////////////打印从1到最大的n位数（n是大数，可以是100，1000,甚至10000）////////////////////////

//https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/solution/jian-zhi-offer-17-da-yin-cong-1dao-zui-d-ngm4/1079742
//class Solution {
//public:
//    vector<string> res;
//    void backTrack(const int& digits, int numIndex, string& num) {
//        if (numIndex == digits) {
//            res.push_back(num);
//            return;
//        }
//
//        for (int i = 0; i <= 9; ++i) {
//            num.push_back(i + '0');
//            backTrack(digits, numIndex + 1, num);
//            num.pop_back();
//        }
//    }
//public:
//    vector<string> printNumbers(int n) {
//        // 考虑大数的全排列 回溯生成
//        res.clear();
//        for (int i = 1; i <= n; ++i) {  // 数据位数遍历
//            for (int j = 1; j <= 9; ++j) {  // 首位选择 1-9
//                string number(1, j + '0');
//                backTrack(i, 1, number);
//            }
//        }
//        return res;
//    }
//};
//void main()
//{
//    Solution so;
//    vector<string> res = so.printNumbers(3);
//    for (auto i : res)
//    {
//        cout << i << ' ';
//    }
//}

///////////////////////////////////////////二进制下不含连续1的非负整数////////////////////////

//https://leetcode-cn.com/problems/non-negative-integers-without-consecutive-ones/solution/tong-ge-lai-shua-ti-la-dong-tai-gui-hua-a1b20/
//如上图，我们从低位往高位填写，填写到第 4 位的时候，我们有两种选择，要么填 1，要么填 0：
//·如果填 1 的话，那么，第 3 位肯定不能填 1 ，所以，第 4 位填 1 时有多少种不包含连续1的组合，取决于第 2 位填 0 或 1 时的不包含连续1的组合数；
//·如果填 0 的话，那么，第 3 位可以填 0 ，也可以填1，所以，第 4 位填 0 时有多少种不包含 连续1 的组合，取决于第 3 位填 0 或 1 时的不包含连续1的组合数；
//综上所述，第 4 位填 0 或 1 两种情况下，最终的组合数取决于第 3 位的组合数 加上 第 2 位的组合数，如果用函数表示，则为 f(4) = f(3) + f(2)。
//·同理，填写其他位时也是一样的道理，因此，我们不难得出 f(n) = f(n - 1) + f(n - 2)
//void main()
//{
//    int n = 8;
//    // 预处理32位整数
//    // dp[i]表示长度为i时有多少个不包含连续1的数
//    // dp[i] = dp[i - 1] + dp[i - 2]
//    vector<int> dp(32);
//    //初始化，长度为0那肯定不包含连续的1，所以为1；长度为1包含0 和 1 两种情况，所以为2。
//    dp[0] = 1;
//    dp[1] = 2;
//    for (int i = 2; i < 32; i++) {
//        dp[i] = dp[i - 1] + dp[i - 2];
//    }
//    //我们要求小于等于n的方案数，那么考虑把n变成二进制，从最高位开始遍历（也就是二进制的从左到右）如果某一位是1，那就可以直接把这一位右边一位的
//    //的方案数加起来（因为右边低位能表示的数一定小于n），同时如果存在两个连续的1，就直接退出；如果某一位是0，那么就要继续考察更低的位数，也就是继续右移。
//    //注意这里的i表示右移的步数，i=31表示从右往左第32位，就是最高位，i=0表示从右往左第1位，就是最低位
//    //·比如n=8=“1000”，遍历到第4位（统一从右往左）的时候，i=3，ans=ans（0）+dp[3]（5）=5，不管这三位怎么变，他最大能表示的数是7，必定
//    //·小于8，所以可以直接加进去
//    //·再比如n=12=“1100”，遍历到第4位的时候，i=3，ans=ans（0）+dp[3]（5）=5；遍历到第3位的时候，i=2，ans=ans（5）+dp[2]（3）=8；有两个
//    //·连续的1，退出。
//    //两个疑问：一、n=“1100”的时候，i=3，ans+=dp[3]，这里dp[3]的方案为“000,001,010,100,101”，i=2，ans+=dp[2]，这里dp[2]的方案为
//    //“00,01,10”，和前面的dp[3]里面的方案不重复吗？
//    //答：i=3的时候，为了保证计算小于n的所有方案，需要在dp[3]的方案前补上0（保证小于n），得到“0000,0001,0010,0100,0101”
//    //    而i=2的时候，同样为了保证计算小于n的所有方案，需要在dp[2]的方案前补上10（保证小于n，补00和01不能计算出所有方案，补11可能
//    //    大于n）得到“1000,1001,1010”补00最大表示3（0011），补01最大表示7（0111），补10最大表示11（1011）补11最大表示15（1111）
//    //    因此，这样计算不会重复且能计算出所有结果
//    //二、连续的1提前结束会对答案有影响吗？
//    //答：不会，因为我们是从高位开始遍历，只要有连续的1，不管低位如何变化，他最终的方案数都和低位全0的数是一样的，比如n=13（1101）
//    //    有连续的1，那么它的方案数就是dp[3]+dp[2]=8，和n=12（1100）是一样的，同样的，n=14（1110），n=15（1111）的方案数都是8，
//    //    和n=12（1100）一样。
//    int ans = 0;
//    int pre = 0;//pre表示当前位左边的高位是不是1，如果高位是1，当前位也是1，那就要提前结束
//    for (int i = 31; i >= 0; i--) {
//        if (((n >> i) & 1) == 1) {
//            ans += dp[i];
//            if (pre == 1) {
//                cout<<ans<<endl;
//                return;
//            }
//            pre = 1;
//        }
//        else {
//            pre = 0;
//        }
//    }
//
//    // 当前数也是符合条件的，如果不符合在上面的return已经返回了
//    cout<<ans + 1<<endl;
//}

///////////////////////////////////////////有效的括号字符串（包括任意字符*，可以抵消任意括号）////////////////////////

//https://leetcode-cn.com/problems/valid-parenthesis-string/comments/72887
//两个栈分别将"("和"*"的序号压入栈中，每次遇到右括号，首先检测左括号栈中是否为空，不为空则弹出元素，否则弹出star栈，
//最后考虑left和star栈可能存在元素，判断此时栈中元素的序号大小，如果left栈中的序号大于star中的则表明 存在"*("此种情况，直接false
//bool checkValidString(string s) {
//    stack<int> left, star;
//    for (int i = 0;i < s.size();i++) {
//        if (s[i] == '(') left.push(i);
//        else if (s[i] == '*') star.push(i);
//        else {
//            if (left.empty() && star.empty()) return false;
//            if (!left.empty()) left.pop();
//            else
//                star.pop();
//        }
//    }
//    while (!left.empty() && !star.empty()) {
//        if (left.top() > star.top()) return false;
//        left.pop();
//        star.pop();
//    }
//    return left.empty();//如果left非空，说明（的个数大于*的个数，无法抵消，返回false
//}
//void main()
//{
//    cout<<checkValidString("(()*)(***)");
//}

///////////////////////////////////////////哈希表计算回旋镖的数量////////////////////////

//https://leetcode-cn.com/problems/number-of-boomerangs/solution/hui-xuan-biao-de-shu-liang-by-leetcode-s-lft5/
//int distance(vector<vector<int>>& points, int i, int j)
//{
//    return (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
//}
//int numberOfBoomerangs(vector<vector<int>>& points) {
//    if (points.size() < 3)
//    {
//        return 0;
//    }
//    int n = points.size();
//    int res = 0;
//    unordered_map<int, int> umap;//记录所有点与当前点的距离以及它们的个数
//    for (int i = 0;i < n;i++)
//    {
//        umap.clear();
//        for (int j = 0;j < n;j++)
//        {
//            if (j == i)
//            {
//                continue;
//            }
//            int dis = distance(points, i, j);//计算每个点与当前点的距离
//            umap[dis]++;//记录距离为dis的点的个数
//        }
//        for (auto p : umap) {
//            res += p.second * (p.second - 1);//如果有n个点与当前点的距离为dis，那么他们能与当前点组成回旋镖的个数就是An2（n个里面选2个，排列数）=n*（n-1）
//        }//累加即可
//    }
//    return res;
//}
//void main()
//{
//    vector<vector<int>> points = { {-1,0}, {0,0},{1,0},{0,1},{0,-1} };
//    cout<<numberOfBoomerangs(points);
//}

///////////////////////////////////////////辅助栈实现最小值栈，O(1)的复杂度////////////////////////////////////////

//https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/solution/mian-shi-ti-30-bao-han-minhan-shu-de-zhan-fu-zhu-z/
//class MinStack {
//public:
//    /** initialize your data structure here. */
//    stack<int> st;
//    stack<int> assi;
//    MinStack() {
//    }
//
//    void push(int x) {
//        if (assi.empty() || x <= assi.top())//辅助栈为空直接入栈保证了两个栈同时为空，不会出现辅助栈先空的情况
//        {//x<=assi.top()的=保证了重复的最小值也会入栈，否则最小值返回错误并且辅助栈会先空，参考0-1-0-1，pop，pop，top，min的情况
//            assi.push(x);
//        }
//        st.push(x);
//    }
//
//    void pop() {
//        if (st.top() == assi.top())
//        {
//            assi.pop();
//        }
//        st.pop();
//    }
//
//    int top() {
//        return st.top();
//
//    }
//
//    int min() {
//        return assi.top();
//    }
//};
//void main()
//{
//    MinStack minst;
//    minst.push(1);
//    minst.push(0);
//    minst.push(1);
//    minst.push(0);
//    cout << minst.min() << endl;
//    minst.pop();
//    minst.pop();
//    cout << minst.top() << endl;
//    cout << minst.min() << endl;
//}

///////////////////////////////////////////具备最长递增子序列长度的子序列个数////////////////////////////////////////

//https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/solution/dai-ma-sui-xiang-lu-dai-ni-xue-tou-dp673-9txt/
//void main()
//{
//    //vector<int> nums = { 1,2,4,3,5,4,7,2 };
//    vector<int> nums = { 1,1,2,3 };
//    if (nums.size() <= 1) 
//      cout<< nums.size();
//    vector<int> dp(nums.size(), 1);//记录以 nums[i] 为结尾的最长递增子序列的长度
//    vector<int> count(nums.size(), 1);//记录以 nums[i] 为结尾并且具有最长长度的子序列个数
//    int maxCount = 0;//记录整个序列中最长子序列的长度
//    for (int i = 1; i < nums.size(); i++) {//i从1到n-1
//        for (int j = 0; j < i; j++) {//j从0到i-1
//            if (nums[i] > nums[j]) {//如果找到j满足nums[i] > nums[j]，说明nums[i]可以接在nums[j]后面形成更长的子序列
//                if (dp[j] + 1 > dp[i]) {//这时候要看dp[j] + 1和dp[i]的大小，因为每个i都对应好几个j，我们只需要更新最大长度或更大长度，如果此时有更大长度
//                    dp[i] = dp[j] + 1;//更新最大长度
//                    count[i] = count[j];//count[j]记录以 nums[j] 为结尾并且具有最大长度（暂时的最大长度）的子序列个数，既然我们已经找到了一个更大长度
//                    //并且nums[j]是一个前驱，那么count[i]就等于count[j],比如1,1,2,3，当i=2时，以nums[2]结尾的最长子序列为{1（第一个1）,2}和{1（第二个1）,2}
//                    //最大长度为2，则dp[2]=2,count[2]=2（因为具备最大长度2的子序列有2个），那么当i=3时，j=0，dp[0]+1=2>1，更新dp[3]=2,count[3]=1(count[0]=1)
//                    //j=1，dp[1]+1=2==2，不更新dp[3]，count[3]+=count[1]=1+1=2(以nums[3]结尾并且具有当前最大长度2的子序列有两个，分别是{1（第一个1）,3}和{1（第二个1）,3})
//                    //j=2，dp[2]+1=3>2,更新dp[3]=3,count[3]=count[2]=2((以nums[3]结尾并且具有当前最大长度3的子序列有两个，分别是{1（第一个1）,2,3}和{1（第二个1）,2,3}
//                }
//                else if (dp[j] + 1 == dp[i]) {
//                    count[i] += count[j];
//                }
//            }
//            if (dp[i] > maxCount) maxCount = dp[i];//dp[i]每更新一次，就要记录最大长度，为了最后做统计
//        }
//    }
//    int result = 0;
//    for (int i = 0; i < nums.size(); i++) {//此时已经知道了最长子序列的长度maxCount，现在就对每个dp[i]检查是否等于maxCount，
//        if (maxCount == dp[i]) result += count[i];//等于的话就把以nums[i]结尾的，具备最大长度maxCount的子序列个数count[i]加入结果
//    }
//    cout<< result;
//}

///////////////////////////////////////////将二叉搜索树转换成一个排序的循环双向链表////////////////////////////////////////

//https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/solution/mian-shi-ti-36-er-cha-sou-suo-shu-yu-shuang-xian-5/
//class Solution {
//public:
//    TreeNode* treeToDoublyList(TreeNode* root) {
//        if (root == nullptr) return nullptr;
//        dfs(root);//遍历完最后一个非空结点结束，pre指向尾结点
//        head->left = pre;//处理完所有结点还需要把首尾连起来，head表示首，pre表示尾
//        pre->right = head;
//        return head;
//    }
//private:
//    TreeNode* pre, * head;//pre指向前一个访问过的结点，head指向双向链表的头结点
//    void dfs(TreeNode* cur) {//中序遍历二叉搜索树
//        if (cur == nullptr) return;
//        dfs(cur->left);//先访问左孩子
//        if (pre != nullptr) pre->right = cur;//当pre是空的时候，说明此时访问的是头结点，不是空的时候，就把pre的右孩子指向现在访问的结点cur
//        else head = cur;
//        cur->left = pre;//不管pre是不是空，当前访问的左孩子指向的始终是前一个访问过的结点，也就是pre
//        pre = cur;//当前结点处理完毕，该遍历下一个结点了，pre改变为当前结点
//        dfs(cur->right);//遍历下一个结点
//    }
//};
//void main()
//{
//    TreeNode* one = new TreeNode(1);
//    TreeNode* thr = new TreeNode(3);
//    TreeNode* fiv = new TreeNode(5);
//    TreeNode* two = new TreeNode(2,one,thr);
//    TreeNode* fou = new TreeNode(4,two,fiv);
//    Solution so;
//    so.treeToDoublyList(fou);
//}

///////////////////////////////////////////把链表平均分成几部分////////////////////////////////////////

//https://leetcode-cn.com/problems/split-linked-list-in-parts/
//vector<ListNode*> splitListToParts(ListNode* head, int k) {
//    int len = 0;
//    ListNode* p = head;
//    while (p)//计算总数
//    {
//        len++;
//        p = p->next;
//    }
//    int m = len % k;//有多少部分需要多分一个结点
//    int n;//每部分平均长度（不算多分一个的长度）
//    vector<ListNode*> res;
//    ListNode* tmp;
//    p = head;
//    while (m--)//处理需要多分一个结点的部分
//    {
//        res.push_back(p);//把这些部分的头结点加入结果集
//        n = len / k + 1;//每次n都要重新算，注意要加一，多分一个结点
//        while (--n)
//        {
//            p = p->next;
//        }
//        tmp = p->next;//每部分的最后一个结点都要断开
//        p->next = nullptr;
//        p = tmp;
//    }
//    while (p)//处理不用多分结点的部分
//    {
//        res.push_back(p);//把这些部分的头结点加入结果集
//        n = len / k;//每次n都要重新算，
//        while (--n)
//        {
//            p = p->next;
//        }
//        tmp = p->next;//每部分的最后一个结点都要断开
//        p->next = nullptr;
//        p = tmp;
//    }
//
//    if (res.size() < k)//如果每部分只有一个结点但是仍然不够分，说明总长度len<k，需要补空指针
//    {
//        int remain = k - res.size();
//        while (remain--)
//        {
//            res.push_back(nullptr);
//        }
//    }
//    return res;
//}
//void main()
//{
//    ListNode* ten = new ListNode(10);
//    ListNode* nin = new ListNode(9,ten);
//    ListNode* eig = new ListNode(8, nin);
//    ListNode* sev = new ListNode(7, eig);
//    ListNode* six = new ListNode(6, sev);
//    ListNode* fiv = new ListNode(5, six);
//    ListNode* fou = new ListNode(4, fiv);
//    ListNode* thr = new ListNode(3, fou);
//    ListNode* two = new ListNode(2, thr);
//    ListNode* one = new ListNode(1, two);
//    splitListToParts(one,3);
//}

///////////////////////////////////////////精准计算程序运行时间（us级别）以及str += "a"和str =str+ "a" 效率差距////////////////////////////////////////

//https://www.cnblogs.com/lidabo/archive/2013/01/08/2850413.html
//void Test()//测试程序1  
//{
//    string str = "";
//    for (int i = 0;i < 100000;i++) {  
//        str += "a";
//    }
//}
//void Test1()//测试程序2 
//{
//    string str = "";
//    for (int i = 0;i < 100000;i++) {
//        str =str + "a";
//    }
//}
//
//int main(void)
//{
//    LARGE_INTEGER BegainTime;//除了可以使用LONGLONG这个表示64位结构的数据外。还可以使用一个叫做LARGE_INTEGER的数据结构来表示64位数据
//    LARGE_INTEGER EndTime;
//    LARGE_INTEGER BegainTime1;
//    LARGE_INTEGER EndTime1;
//    LARGE_INTEGER Frequency;//调用QueryPerformanceFrequency函数取得高精度运行计数器的频率f。单位是每秒多少次（n/s），此数一般很大。
//    QueryPerformanceFrequency(&Frequency);
//    QueryPerformanceCounter(&BegainTime);//在需要定时的代码的两端分别调用QueryPerformanceCounter以取得高精度运行计数器的数值n1，n2。两次数值的差值通过f换算成时间间隔，t = (n2 - n1) / f。
//
//    //要测试的代码放在这里   
//    Test();
//
//    QueryPerformanceCounter(&EndTime);
//    QueryPerformanceCounter(&BegainTime1);
//
//    //要测试的代码放在这里   
//    Test1();
//
//    QueryPerformanceCounter(&EndTime1);
//    //输出运行时间（单位：s）   
//    cout << "Test运行时间（单位：us）：" << (double)(EndTime.QuadPart - BegainTime.QuadPart)*1000000 / Frequency.QuadPart << endl;
//    cout << "Test1运行时间（单位：us）：" << (double)(EndTime1.QuadPart - BegainTime1.QuadPart) * 1000000 / Frequency.QuadPart << endl;
//    return 0;
//}

///////////////////////////////////////////扁平化多层双向链表（DFS）////////////////////////////////////////

//https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list/solution/bian-ping-hua-duo-ji-shuang-xiang-lian-b-383h/
//class Node {
//public:
//    int val;
//    Node* prev;
//    Node* next;
//    Node* child;
//    Node(int x) :val(x) {};
//};
//class Solution {
//public:
//    Node* flatten(Node* head) {
//        dfs(head);
//        return head;
//    }
//    Node* dfs(Node * node)//dfs用来查找本层链表的最后一个节点，传入值是本层的首节点，返回值是本层的最后一个节点
//    {
//        Node* cur = node;
//        // 记录本层链表的最后一个节点，也就是返回值
//        Node* last = nullptr;
//
//        while (cur) {//如果本层是最后一层，那么cur就逐个遍历，last逐个更新，直到最后更新为最后一个节点，返回
//            Node* next = cur->next;//先把cur结点的next孩子记录下来，因为不确定是否存在下一层，如果存在的就需要拼接
//            //  如果有子节点，那么首先处理子节点，同时说明本层不是最后一层
//            if (cur->child) {
//                Node* child_last = dfs(cur->child);//找到了下一层的最后一个节点child_last
//
//                //  开始拼接，首先将 node 与 child 相连
//                cur->next = cur->child;
//                cur->child->prev = cur;
//
//                //  如果 next 不为空，就将 child_last 与 next 相连，如果next为空，只需要把child_last赋给last就行了，代表本层的最后一个节点是拼接后的下一层的最后一个节点
//                if (next) {
//                    child_last->next = next;
//                    next->prev = child_last;
//                }
//
//                // 将 child 置为空
//                cur->child = nullptr;
//                //即使next存在也没关系，因为这是一个while循环，虽然这里last指的不是本层的最后一个节点，但是下一次循环的时候会更新last指向；而如果next不存在，那么后面的循环就不再执行了
//                //这时候本层的最后一个节点就是拼接后的下一层的最后一个节点，所以为了保证返回值总是对的，这里就需要这样赋值
//                last = child_last;
//            }
//            else {//到最后一层的时候，上面的if语句不执行，last逐个更新
//                last = cur;
//            }
//            cur = next;//到最后一层的时候，cur逐个往后遍历，直到最后一个节点
//        }
//        return last;
//    }
//};
//void main()
//{
//    //1->2->4->NULL
//    //|
//    //v
//    //3->5->NULL
//    Node* two = new Node(2);
//    Node* thr = new Node(3);
//    Node* fou = new Node(4);
//    Node* fiv = new Node(5);
//    Node* one = new Node(1);
//    one->next = two;
//    two->next = fou;
//    thr->next = fiv;
//    two->prev = one;
//    fou->prev = two;
//    fiv->prev = thr;
//    one->child = thr;
//    Solution so;
//    Node* res=so.flatten(one);
//    while (res)
//    {
//        cout << res->val << " ";
//        res = res->next;
//    }
//}

///////////////////////////////////////////不用+号和-号计算加法（位运算）////////////////////////////////////////

////https://leetcode-cn.com/problems/sum-of-two-integers/solution/liang-zheng-shu-zhi-he-by-leetcode-solut-c1s3/1153738
//void main()
//{
//    int a = 7, b = 2;
//    while (b != 0) {//unsigned int防止 AddressSanitizer 对有符号左移的溢出保护处理,详见 https://leetcode-cn.com/problems/sum-of-two-integers/comments/69218 ,Vs里面不会出现这个问题
//        unsigned int carry = (unsigned int)(a & b) << 1;//所有需要进位的位为a & b，进位后的进位结果为(a & b) << 1,注意这里的a和b是上一轮的a和b，carry表示考虑进位后的有进位加法结果
//        a = a ^ b;//异或表示在不考虑进位的情况下，无进位加法结果
//        b = carry;//考虑进位后的结果要保存到下一轮，如果b=0了说明没有进位了，这时候a就是最终结果
//    }
//    cout<<a<<endl;
//}

///////////////////////////////////////////解码方法Ⅰ////////////////////////////////////////

//https://leetcode-cn.com/problems/decode-ways/solution/jie-ma-fang-fa-by-leetcode-solution-p8np/
//void main()
//{
//    string s = "11106";
//    int n = s.size();
//    vector<int> dp(n + 1, 0);
//    dp[0] = 1;
//    for (int i = 1;i <= n;i++)
//    {
//        if (s[i - 1] >= '1' && s[i - 1] <= '9')//·情况一：首先考虑s[i - 1]是一个单独的可以解码的数
//        {
//            dp[i] = dp[i - 1];//那么dp[i]就等于去掉s[i - 1]后能解码的方案数（也就是dp[i-1]，s[i - 1]只需要跟在s[i - 2]后面，作为一个单独符号（只有一个数字的单独符号）解码，比如最后一位的6）
//        }
//        if (i > 1)//·情况二：其次考虑s[i - 1]可以和s[i - 2]组合起来解码，不必考虑此时s[i - 1]是多少，因为它作为个位上的数字，是多少都可以。此时最少需要两个数字，i>1
//        {
//            if (s[i - 2] >= '1' && s[i - 2] <= '2')//s[i - 2]必须满足1~2，不然不能作为十位上的数字，比如01,05,09...这些都是非法的，无法解码
//            {
//                int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');//计算s[i - 2]和s[i - 1]能组成的数字
//                if (num <= 26)//当这个数字在26范围内时，表明这两个数可以合在一起跟在s[i - 3]后面，作为单独符号（有两个数字的单独符号）解码，比如第一个和第二个1，第二个和第三个1，第三个1和第四个0
//                    //这里就不用再考虑把两个数字分开单独计算方案了，因为s[i - 2]单独算的时候在i-1的时候就算过了，s[i - 1]单独算的时候在情况一中就计算过了
//                {
//                    dp[i] += dp[i - 2];//这里是累加，其实就是要把情况一和情况二的结果加起来，可以写成dp[i]=(s[i-1]>='1' && s[i-1]<='9'? dp[i-1]:0)+dp[i-2];
//                }
//            }
//        }
//    }
//}

///////////////////////////////////////////解码方法Ⅱ////////////////////////////////////////

//https://leetcode-cn.com/problems/decode-ways-ii/solution/jie-ma-fang-fa-ii-by-leetcode-solution-23af/
//static constexpr int mod = 1000000007;//constexpr表示编译器常量，告诉编译器在编译阶段就把mod换成1000000007
//void main()
//{
//    auto check1digit = [](char ch) -> int {//单个字符的解码方案数，Lambda 表达式，这里auto表示匿名函数指针，check1digit是函数名字（因为我们要在后面调用它，也可以直接写进程序里）
//        //[]表示不捕获任何变量,这种情况下lambda表达式内部不能访问外部的变量。ch是形参，和[]的作用其实差不多，都是用来传递参数的，->int表示返回值为int
//        if (ch == '0') {
//            return 0;
//        }
//        return ch == '*' ? 9 : 1;
//    };
//
//    auto check2digits = [](char c0, char c1) -> int {//两个字符的解码方案数
//        if (c0 == '*' && c1 == '*') {//两个字符都是*的时候
//            return 15;
//        }
//        if (c0 == '*') {//第一个字符是*，第二个字符大于6时，只有17~19这一种解码方法，小于6时，有11~16,21~26两种解码方法
//            return c1 <= '6' ? 2 : 1;
//        }
//        if (c1 == '*') {//第二个字符是*，第一个字符是数字的时候
//            if (c0 == '1') {
//                return 9;
//            }
//            if (c0 == '2') {
//                return 6;
//            }
//            return 0;
//        }
//        return c0 != '0' && (c0 - '0') * 10 + (c1 - '0') <= 26;//两个字符都是数字的时候，第一个字符不能是0，并且两个字符组成的数要小于26，满足这两个条件就返回1，不满足就返回0
//    };
//    string s = "12*";
//    int n = s.size();
//    // a = dp[i-2], b = dp[i-1], c = dp[i]
//    int a = 0, b = 1, c = 0;//这里b的初始值是dp[0]=1,也就是长度为0的字符串解码方法只有一种，那就是空，而a=dp[i-2]，当 i=1 的时候 a=0
//    for (int i = 1; i <= n; ++i) {
//        c = (long long)b * check1digit(s[i - 1]) % mod;//必须先转化成long long，不然就超出范围了，c不用定义成long long，因为mod完就一定小于int，当然，abc定义成long long也没错
//        if (i > 1) {
//            c = (c + (long long)a * check2digits(s[i - 2], s[i - 1])) % mod;
//        }
//        a = b;//逐次往后转移
//        b = c;
//    }
//}

/////////////////////////////////////////// 将所有衣服平均分配给洗衣机最少需要的步数////////////////////////////////////////

//https://leetcode-cn.com/problems/super-washing-machines/solution/gong-shui-san-xie-noxiang-xin-ke-xue-xi-mzqia/1158762
//void main()
//{
//    vector<int> machines = { 1,0,5 };
//    int n = machines.size();
//    int sum = accumulate(machines.begin(), machines.end(), 0); // 所有衣服数量和
//    if (sum % n != 0) {
//        cout<< -1<<endl;
//        return;
//    }
//    int avg = sum / n; // 最终平均每台洗衣机内衣服的数量
//    int res = 0;
//    int left = 0, right = sum; // left表示洗衣机i左边衣服总数(不包括i)，right表示右边衣服总数(不包括i)
//    for (int i = 0; i < n; ++i) {
//        right -= machines[i];//每次i右移，右边衣服总和就要相应减少
//
//        // a表示通过洗衣机i向左边匀的衣服数量，avg * i表示最后达到平衡时左边衣服的总数量，left表示当前左边衣服的总数量，相减得到通过i向左边转移的衣服数量，
//        // 为什么向左转移的衣服总数就是左边达到平衡的最小次数？
//        //·因为向左转移的衣服总数就是左边缺少的总数，可以把它理解成一个坑，需要放里面填土，但是一次只能往里面填 1 单位的土，那么我们有多大的坑就需要多少次填土的操作
//        // 一次可以操作很多台洗衣机，那么为什么一次只能填 1 单位的土？
//        //·因为我们把左边当成了一个整体，左边内部衣服的转移是不会帮助我们填土的进度，左边这个坑只能从 i 以及 i 右边往里面填土才行。
//        //·不用管i里面是否有足够多的衣服能转移，因为我们只在乎通过i的流量（通过i向左转移的数量a+通过i向右转移的数量b）如果i里面不够，那么对于i+1而言，它的左边衣服数量是不够的（avg * (i+1) - left）>0
//        //  那么只需要通过i+1向左边转移就行了
//        //·i=0的时候，a一定为0，说明我们不需要向0左边转移（因为0左边没有洗衣机了）
//        int a = max(avg * i - left, 0);
//        // b表示通过洗衣机i向右边匀的衣服数量，(n - i - 1) * avg表示最后达到平衡时右边衣服的总数量，right表示当前右边衣服的总数量，相减得到通过i向右边转移的衣服数量
//        //·不用管i里面是否有足够多的衣服能转移，因为我们只在乎通过i的流量（通过i向左转移的数量a+通过i向右转移的数量b）如果i里面不够，那么对于i-1而言，它的右边衣服数量是不够的（(n - (i-1) - 1) * avg - right）>0
//        //  那么只需要通过i-1向右边转移就行了
//        //·i=n-1的时候，b一定为0，说明我们不需要向n-1右边转移（因为n-1右边没有洗衣机了）
//        int b = max((n - i - 1) * avg - right, 0);
//        //a+b表示通过i号洗衣机达到平衡的最少转移次数，找到其中的最大值，因为每一步操作都可以操作多台不同的洗衣机，比如洗衣机2和洗衣机3可以同时向左转移或向右转移，这里不能用最小值是因为
//        //a+b只代表右边和右边平衡的操作次数，此时i不一定平衡，需要利用其他的a+b来使i平衡，所以操作次数的最大值就是最终转移步数
//        //为什么最大的操作次数就是答案？
//        //·因为对于所有洗衣机而言，小的转移次数可以被大的转移次数所包括，也就是在大的转移次数的轮数内，一定能先完成小的转移次数，
//        res = max(res, a + b);
//        //对于i计算完毕后要把它归为左边的组，然后对i+1进行计算
//        left += machines[i];
//    }
//    cout << res << endl;
//}

/////////////////////////////////////////// 数字序列0123456789101112131415…中第n位的数字////////////////////////////////////////

//https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/solution/mian-shi-ti-44-shu-zi-xu-lie-zhong-mou-yi-wei-de-6/
//void main()
//{
//    int n = 15;//找第15位的数字（这里n表示的是下标，也就是序列中从左往右第16个字符，n=0表示第一个字符，输出0，n=5表示第六个字符，输出5）
//    long start = 1;//表示不同位数的开头数字（分别是1，10，100，1000，...）注意1位数是从1开始的而不是0
//    int digit = 1;//表示位数（分别是1,2,3,4...）
//    long count = 9;//表示不同位数的所有数字总共有多少数位（1位数count=9,2位数count=90（从10到99）*2=180,3位数count=900（从100到999）*3=2700...）
//    while (n > count) {//·首先计算第n位所在数字的位数是多少以及该位数的开头数字是多少（也就是digit和start分别是多少）
//        //n表示在数字序列中的位置，所以每次减去不同位数的count，当n小于等于此时的count的时候就代表n属于digit-1的那个count里，
//        //·比如n=189,第一次循环189-9=180，start变成10，digit变成2，count变成10*2*9=180，n==count，退出循环
//        //此时start和digit就是我们需要的，退出循环
//        n -= count;
//        start *= 10;//start每次翻十倍
//        digit++;//位数每次加一
//        //·int * int 问题在于计算过程中溢出了。这个计算式完全是以int运算来执行的，并且只有在运算完成之后，其结果才被提升为long，而此时已经太迟：计算已经溢出。 
//        //  解决方法使计算表达式的第一个因子(也就是start)明确为long型，这样可以强制表达式中所有的后续计算都用long运算来完成，这样结果就不会溢出.
//        count = start * digit * 9;//count增加相应的值
//    }
//    int num = start + (n - 1) / digit;//·其次，确定第n位所在数字（从数字start开始的，start 为第 0 个数字，我们要找的是第 (n-1)/digit 个数字，而不是第 n/digit 个数字），此时 num = 99
//    string s = to_string(num);//·最后，确定第n为在这个数字的哪一位上，转换成string比较简单
//    int res = s[(n - 1) % digit] - '0';// 99 的第 1 位数字
//    cout << res << endl;
//}

/////////////////////////////////////////// 计算矩形面积Ⅰ////////////////////////////////////////

//https://leetcode-cn.com/problems/rectangle-area/solution/ju-xing-mian-ji-by-leetcode-solution-xzbl/
//void main()
//{
//    int ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2;//部分重叠
//    int ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2;//完全重叠
//    int ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = 3, by1 = 3, bx2 = 4, by2 = 4;//完全分离
//    int aera1 = abs(ax2 - ax1) * abs(ay2 - ay1);
//    int aera2 = abs(bx2 - bx1) * abs(by2 - by1);
//    int res = aera1 + aera2;
//    //·当两个矩形有重叠部分时（不管是部分还是全部），必定有ay2>=ay1,by2>=by1（题目要求）而重叠则代表着ay2>=by2>=ay1或by2>=ay2>=by1,不管是哪一个可能，都可以推出ay2>=ay1,ay2>=by1,by2>=ay1,by2>=by1
//    //  这意味着，ay2和by2中任何一个值都大于等于ay1和by1，因此当两个矩形有重叠部分时，min(ay2,by2)-max(ay1,by1)>=0。
//    int high = max(0, min(ay2, by2) - max(ay1, by1));
//    //·同理
//    int bottom = max(0, min(ax2, bx2) - max(ax1, bx1));
//    res -= bottom * high;//减去重叠部分的面积
//}

/////////////////////////////////////////// 850.计算矩形面积Ⅱ（扫描线）////////////////////////////////////////

//https://leetcode.cn/problems/rectangle-area-ii/solution/gong-shui-san-xie-by-ac_oier-9r36/
//将所有给定的矩形的左右边对应的 x 端点提取出来并排序，每个端点可看作是一条竖直的线段（红色），
//问题转换为求解「由多条竖直线段分割开」的多个矩形的面积总和（黄色）：
//相邻线段之间的宽度为单个矩形的「宽度」（通过 x 差值直接算得），问题转换为求该区间内高度的并集（即矩形的高度）。
//由于数据范围只有 200，我们可以对给定的所有矩形进行遍历，统计所有对此段区间有贡献的矩形（即有哪些矩形是“经过”该区间的）
//再对这些矩形总高度（矩形高度并集），即可计算出此区间的「高度」，从而计算出来此区间的面积。
//int main()
//{
//    vector<vector<int>> rectangles = { {0, 0, 2, 2},{1, 0, 2, 3},{1, 0, 3, 1} };
//    vector<int> x;
//    for (auto r : rectangles)
//    {//扫描线，先记录矩形的左右两边
//        x.push_back(r[0]);
//        x.push_back(r[2]);
//    }
//    sort(x.begin(), x.end());//从大到小排序
//    int res = 0;
//    for (int i = 1, n = x.size();i < n;i++)
//    {//遍历区间
//        int lo = x[i - 1], ri = x[i];//区间的左右边界
//        if (lo == ri)
//        {//左右边界相同，直接跳过
//            continue;
//        }
//        vector<vector<int>> cover;//记录有哪些矩形“经过”这一区间
//        for (auto r : rectangles)
//        {
//            if (r[0] <= lo && r[2] >= ri)
//            {//当一个矩形的左边界小于等于 lo 且右边界大于等于 ri，说明它“经过”了此区间
//                cover.push_back({ r[1],r[3] });//记录这个矩形的底和高
//            }
//        }
//        sort(cover.begin(), cover.end());//对“经过”此区间的所有矩形排序，按照底边从低到高的顺序
//        int up = -1, down = -1;//记录重合矩形的底和高
//        int high = 0;//记录高的并集，也就是总高度
//        for (auto c : cover)
//        {
//            if (c[0] > up)
//            {//如果一个新的矩形底边大于当前重合矩形的高，说明它与当前重合矩形没有交集
//                high += up - down;//这时候我们要记录一下之前重合矩形的高度，因为它不可能再和后面的矩形有交集了
//                up = c[1];//新的重合矩形的高
//                down = c[0];//新的重合矩形的底
//            }
//            else if (c[1] > up)
//            {//否则一个新的矩形底边小于等于当前重合矩形的高，并且大于当前重合矩形的底，
//                //说明他只重合一部分，有一部分新的面积没有交集，因此更新当前重合矩形的高
//                //注意不管重合多少次，我们都只计算一次重合的面积
//                up = c[1];
//            }
//        }
//        high += up - down;//最后一个重合矩形的高
//        res = (res + (((long long)ri - lo) * high) % MOD) % MOD;//加到答案里面去
//    }
//    cout << res;
//}

//////////////////////////////////////////391.判断完美矩形以及自定义排序函数的用法（扫描线）////////////////////////////////////////

//https://leetcode-cn.com/problems/perfect-rectangle/solution/gong-shui-san-xie-chang-gui-sao-miao-xia-p4q4/
//struct Line {//自定义结点Line
//public:
//    int x, y1, y2;
//    bool left;
//    bool operator< (const Line& l) const {//对这个结点排序，重载的是<，所以<左边的参数就是this，右边的参数就是传入值，true的时候this排在传入值前面，false则相反
//                                          //const代表这个此函数是静态成员函数，不会更改成员变量的值
//        if (this->x != l.x) return this->x < l.x;
//        else return this->y1 < l.y1;
//    }
//    //*********************sort排序不能重载大于号,因为默认是less模板***********************
//    //bool operator>(const Line& l) const {//由于sort用小于号<来比较大小，因此要用sort的话必须重载小于号<,重载>用sort会报错，除非规定排序模板是greater
//    //    if (this->x != l.x) return this->x < l.x;
//    //    else return this->y2 > l.y2;
//    //}
//};
//struct Point//自定义结点Point
//{
//    int x,y;
//    bool operator<(const Point& p)
//    {
//        return this->x < p.x || ((this->x == p.x) && (this->y) < p.y);
//    }
//};
////********************声明比较类来排序，这个结构体放在类内类外都可以(前提是自定义的结点不在类内，否则没办法访问)******************************
//// struct cmp
//// {
////     bool operator()(const Line& l1,const Line& l2)
////     {
////         return l1.x<l2.x || ((l1.x==l2.x)&&(l1.y1<l2.y1));
////     }
//// };
////********************结构体、类外重载<，相当于sort函数在使用<排序的时候就会使用此规则，对于排序其他的结构体就会出错******************************
////bool operator< (const Line& l1,const Line& l2){//这样重载的话对Point排序的时候会报错，所以最好的方法是在结构体内重载<，其次是申明不同的比较类或函数
////    if (l1.x != l2.x) return l1.x < l2.x;
////    else return l1.y1 < l2.y1;
////}
//
//class Solution {
//public:
//    //********************自定义比较函数排序,放在类内的话要加static，放在类外则不用******************************
//    //因为类构造的时候会自动给非静态成员函数加上this指针，而sort函数接受的比较函数只有两个参数，因此会报错
//    static bool cmp(const Line& l1, const Line& l2)
//    {
//        return l1.x < l2.x || ((l1.x == l2.x) && (l1.y1 < l2.y1));
//    }
//    //bool operator<(const Line& l1, const Line& l2)//如果在类内结构体外（如果结构体是在类内的话）重载<的话，他默认<左边的参数是本身类，也就是this，传入参数是<右边的参数，应该是另一个类（Solution），
//    //而不是我们要排序的Line，所以在类内结构体外只能对class排序
//    //{
//    //    return l1.x < l2.x || ((l1.x == l2.x) && (l1.y1 < l2.y1));
//    //}
//    bool isRectangleCover(vector<vector<int>>& rects) {
//        vector<Line> lines;
//        for (auto& rect : rects) {
//            int x = rect[0], y = rect[1], a = rect[2], b = rect[3];//（x,y）是左下角，（a,b）是右上角
//            lines.push_back({ x, y, b, true });//true代表左边,vector::push_back接受initializer_list为参数，emplace_back不行
//            lines.push_back({ a, y, b, false });//false代表右边
//        }
//        // sort lines
//        sort(lines.begin(), lines.end());//重载<排序
//        /*vector<Point> v;
//        v.push_back({ 1,2 });
//        v.push_back({ 2,3 });
//        sort(v.begin(), v.end());
//        for (const auto& vv : v)
//        {
//            cout << vv.x << ' ';
//        }
//        cout << endl;
//        for (const auto& l : lines)
//        {
//            cout << l.x << ' ';
//        }
//        cout << endl;*/
//        int n = lines.size();
//        for (int i = 0,j=0; i < n; i=j) {
//            while (j < n && lines[j].x == lines[i].x) 
//                j++;//退出循环时，lines[i].x ！= lines[j].x，j已经是右领边了
//            vector<vector<int>> seg_l, seg_r;//注意这里的seg_l和seg_r在每次i更新后都会重新定义，也就是说每一个seg_l和seg_r里面存放的竖边对应的x都是相同的
//            for (int k = i; k < j; k++) {//把x相等的竖线分成左边和右边
//                bool flag = true;
//                if (lines[k].left)
//                    merge(seg_l, lines[k], flag);//如果lines[k]是左边，就把它和原来的左边拼接起来
//                else 
//                    merge(seg_r, lines[k], flag);//如果lines[k]是右边，就把它和原来的右边拼接起来
//                if (!flag) 
//                    return false;
//            }
//            if (i > 0 && j < n) {//除了最左边和最右边，非边缘竖边必然有成对的左右两条完全相同的竖边重叠在一起；
//                if (seg_l.size() != seg_r.size()) 
//                    return false;//完美矩形某个相接的地方必定存在相同长度和方向的左边和右边，因此seg_l和seg_r的尺寸必须相同
//                for (int k = 0; k < seg_l.size(); k++) {//seg_l和seg_r能连起来的地方都连起来了，所以如果左边右边还不能完全对齐的话，就不是完美矩形
//                    if (seg_l[k][0] != seg_r[k][0] || seg_l[k][1] != seg_r[k][1]) return false;
//                }
//            }
//            else if (i == 0) {//最左边只应该有一条左边，而且左边是完全连续的，否则就不是完美矩形
//                if (!(seg_l.size() == 1 && seg_r.empty())) return false;
//            }
//            else {//最右边只应该有一条右边，而且右边是完全连续的，否则就不是完美矩形
//                if (!(seg_r.size() == 1 && seg_l.empty())) return false;
//            }
//        }
//        return true;
//    }
//    void merge(vector<vector<int>>& seg, struct Line& line, bool& flag) {//注意都是引用传递，这个seg里面存放的竖边对应的x都是相同的
//        if (seg.empty()) {//第一条左边直接加进来
//            seg.push_back({ line.y1, line.y2 });
//            return;
//        }
//        else {
//            auto last = seg.back();
//            if (line.y1 < last[1]) {//同一个x，如果新竖边的底边要小于旧竖边的顶边的话，说明有两个矩形是重叠的，那么就直接返回false
//                flag = false;
//                return;
//            }
//            else if (line.y1 == last[1]) 
//                last[1] = line.y2;//同一个x，如果新竖边的底边等于旧竖边的顶边的话，说明可以拼接起来，此时新的顶边就是y2
//            else 
//                seg.push_back({ line.y1, line.y2 });//否则的话先保存起来，这里不能返回false，因为这两个矩形之间后面可能插入一个细长的矩阵，其左边的x比这个x小，右边的x比这个x大
//        }
//    }
//};
//int main()
//{
//    Solution so;
//    vector<vector<int>> vec = { {1, 1, 3, 3},{3, 1, 4, 2},{3, 2, 4, 4},{1, 3, 2, 4},{2, 3, 3, 4} };
//    cout<<so.isRectangleCover(vec)<<endl;
//}

/////////////////////////////////////////// 将十进制数int转换为16进制的形式////////////////////////////////////////

//https://leetcode-cn.com/problems/convert-a-number-to-hexadecimal/solution/shu-zi-zhuan-huan-wei-shi-liu-jin-zhi-sh-2srt/
//void main()
//{
//    int num = 26;
//    if (num == 0) {
//        cout<< "0"<<endl;
//        return;
//    }
//    string res;
//    for (int i = 7; i >= 0; i--) {
//        int val = (num >> (4 * i)) & 0xf;
//        //·i是从7开始的，所以我们是从最高位（符号位）开始往右遍历的，当val=0并且res的长度也为0的时候说明此时是前导0，不需要加到结果里，因为题目要求不需要前导0
//        //  当val>0且res的长度为0的时候说明遍历到了第一个不为0的位，可以作为res的首位添加进去
//        //  当val=0且res的长度不为0的时候说明遍历到了数据位中间的某个0，此时仍然要加到结果里
//        //  当val>0且res的长度不为0的时候说明遍历到了数据位中间的某个值，此时要加到结果里
//        //  综上所述，当val>0或者res的长度不为0的时候我们都要加到结果里，作用是消除前导0
//        //·如果题目要求需要前导0的话，就要把这个if去掉
//        if (res.length() > 0 || val > 0) {
//            //如果是要求完整的
//            char digit = val < 10 ? (char)('0' + val) : (char)('a' + val - 10);
//            res.push_back(digit);
//        }
//    }
//    cout << res << endl;
//}

/////////////////////////////////////////// 分数转换为小数（包括有限小数和无限循环小数，模拟实现长除法）////////////////////////////////////////

//https://leetcode-cn.com/problems/fraction-to-recurring-decimal/solution/fen-shu-dao-xiao-shu-by-leetcode-solutio-tqdw/
//void main()
//{
//    int numerator = 2;
//    int denominator = 3;
//    int numeratorLong = numerator;
//    int denominatorLong = denominator;
//    if ((long)numeratorLong % denominatorLong == 0) {//如果能够整除，就直接返回
//        cout<< to_string((long)numeratorLong / denominatorLong)<<endl;
//        return;
//    }
//
//    string ans;
//    if (numeratorLong < 0 ^ denominatorLong < 0) {//分子分母符号不同,只能用异或，不能用条件或
//        ans.push_back('-');
//    }
//
//    // 整数部分
//    numeratorLong = abs(numeratorLong);//去除符号的干扰
//    denominatorLong = abs(denominatorLong);
//    int integerPart = numeratorLong / denominatorLong;//先算出整数部分
//    ans += to_string(integerPart);
//    ans.push_back('.');//加入小数点
//
//    // 小数部分
//    string fractionPart;
//    unordered_map<long, int> remainderIndexMap;//用来记录每一次长除的余数和对应的位置
//    long remainder = numeratorLong % denominatorLong;//最开始的余数
//    int index = 0;//余数对应的位置
//    while (remainder != 0 && !remainderIndexMap.count(remainder)) {//当余数不为0 并且之前从来没有出现过这个余数的时候，就需要继续计算余数，余数为0的时候就不需要再计算了，直接退出。
//        remainderIndexMap[remainder] = index;//把这个余数和对应的位置记录下来，注意这个余数是没有*10的余数
//        remainder *= 10;//补位，长除法的思想
//        fractionPart += to_string(remainder / denominatorLong);//记录每一个商作为小数部分的结果
//        remainder %= denominatorLong;//计算下一次的余数
//        index++;//余数对应的位置递增
//    }
//    if (remainder != 0) { // 如果是有限小数，那么最后一次的remainder肯定为0，参考35/20，如果是无限循环小数，那么remainder肯定不是0，上面while退出的原因一定是找到了重复的余数，参考2/3
//        int insertIndex = remainderIndexMap[remainder];//找到循环节的起始位置，此时的remainder和循环节的第一个字符是相同的，所以直接找其对应的位置，插入（即可
//        fractionPart = fractionPart.substr(0, insertIndex) + '(' + fractionPart.substr(insertIndex);//用insert也没问题，耗费的时间更多
//        fractionPart.push_back(')');
//    }
//    ans += fractionPart;
//    cout << ans << endl;
//}

///////////////////////////////////////////加油站是否可以循环行驶一圈////////////////////////////////////////

//https://leetcode-cn.com/problems/gas-station/solution/134-jia-you-zhan-tan-xin-jing-dian-ti-mu-xiang-jie/
//void main()
//{
//    vector<int> gas = { 1, 2, 3, 4, 5 };//表示到达站点i能获得的油量
//    vector<int> cost = { 3, 4, 5, 1, 2 };//表示站点i去往站点i+1消耗的油量，比如3表示站点0去往站点1需要消耗3点油量，特别的，最后一个2表示站点n-1去往站点0需要消耗2点油量
//    int left = 0;//表示从起点开始的油量的总和
//    int sum = 0;//用来判断是否有足够的油量跑完全程
//    int start = 0;//假设起点是站点0
//    for (int i = 0;i < gas.size();i++)
//    {
//        left += gas[i] - cost[i];//到达站点i加油并且离开站点i后油量的总值
//        sum += gas[i] - cost[i];
//        if (left < 0)//如果从起点开始的油量的总和小于0了，说明以[0,i]为起点都不能到达站点i+1（因为left中计算了站点i去往站点i+1消耗的油量，如果小于0，说明i不能到达i+1）
//            //·为什么以[0,i]为起点都不能到达站点i+1？
//            //  在站点i处能够用掉[0，i]累积下来的所有油，且之前累积的油必然大于等于0（如果小于0的话，油量left就重置了，起点就应该是i）。所以i之前的（包括i）都不可以。
//        {
//            start = i + 1;//此时起点应该是i+1
//            left = 0;//重新计算油量
//        }
//    }
//    if (sum < 0)//说明没有足够的油量跑完一周
//    {
//        cout << -1 << endl;
//        return;
//    }
//    cout << start << endl;
//    return;
//}

/////////////////////////////////////////// 判断数组是不是某二叉搜索树的后序遍历结果////////////////////////////////////////

//https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/solution/mian-shi-ti-33-er-cha-sou-suo-shu-de-hou-xu-bian-6/
//bool recur(vector<int>& postorder, int left, int r)
//{
//    if (left >= r)
//    {
//        return true;
//    }
//    int i = left;
//    while (i < r && postorder[i] < postorder[r]) 
//        ++i;//找到右子树序列的第一个,右子树的第一个必定比根节点大，而后序遍历的最后一个数postorder[r]就表示根节点
//    if (i == r)//没有右子树序列，对应的数是只有左子树的单支树，递归考虑左子树
//    {
//        return recur(postorder, left, r - 1);//注意这里就直接返回了
//    }
//    int tmp = i;//存储找到的右子树序列的第一个位置
//    while (i < r && postorder[i] > postorder[r]) 
//        ++i;//判断右子树序列的元素是否都比根节点大
//    if (i < r) 
//        return false;//如果i<r的话说明右子树序列的某个元素小于等于根节点，那么就一定不是二叉搜索树，返回false
//    return recur(postorder, left, tmp - 1) && recur(postorder, tmp, r - 1);//递归考虑左子树和右子树
//}
//void main()
//{
//    vector<int> nums = { 4, 8, 6, 12, 16, 14, 10 };
//    cout << recur(nums,0,nums.size()-1) << endl;
//}

/////////////////////////////////////////// 在长为m，宽为n的矩形中，最多移动maxMove步，出界的路径数////////////////////////////////////////

////https://leetcode-cn.com/problems/out-of-boundary-paths/solution/chu-jie-de-lu-jing-shu-by-leetcode-solut-l9dw/
//static constexpr int MOD = 1e9 + 7;
//void main()
//{
//    int m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0;//起始点是0,0
//    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };//四个方向
//    int outCounts = 0;
//    vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>>(m, vector<int>(n)));//dp[i][j][k]表示移动 i 次之后到达坐标 (j, k)的路径数量
//    dp[0][startRow][startColumn] = 1;//移动0次，只能到达起始点，所以到达（startRow，startColumn）的路径数为1，其他dp[0][j][k]都为0
//    for (int i = 1; i <= maxMove; i++) {
//        for (int j = 0; j < m; j++) {
//            for (int k = 0; k < n; k++) {
//                int count = dp[i-1][j][k];//count表示移动 i-1 次到达（j，k）的路径数
//                if (count > 0) {//如果可以到达（j，k），那么count>0，那么就可以到达（j-1，k），（j+1，k），（j，k-1），（j，k+1）这四个坐标
//                    for (auto& direction : directions) {//四个方向
//                        int j1 = j + direction[0], k1 = k + direction[1];//四个方向的坐标
//                        if (j1 >= 0 && j1 < m && k1 >= 0 && k1 < n) {//如果新的坐标仍然在界内，那么移动 i 次到达新坐标的路径数就要加上count
//                            dp[i][j1][k1] = (dp[i][j1][k1] + count) % MOD;
//                        }
//                        else {
//                            outCounts = (outCounts + count) % MOD;//如果新的坐标出界了，那么就出界的路径数就要加上count
//                        }
//                    }
//                }
//            }
//        }
//    }
//    cout << outCounts << endl;
//}

/////////////////////////////////////////// sort函数自定义排序函数的四种方法////////////////////////////////////////

//bool cmp1(const int& a, const int& b)
//{
//    return a > b;
//}
//struct cmp3
//{
//    bool operator()(const int& a, const int& b)
//    {
//        return a > b;
//    }
//};
//class Student {
//public:
//    int id;
//    double grade;
//    Student() {}
//    Student(int x, double y) :id(x), grade(y) {};
//    bool operator<(const Student& s) const
//    {//重载 < 号的时候最好不要出现 > 号
//        //return id > s.id;//按照id降序排列，最好写成下面的形式
//        return s.id < id;
//        //return id< s.id;//按照id升序排列
//        //return grade > s.grade;//按照成绩降序排列，最好写成下面的形式
//        //return s.grade < grade;
//        //return grade < s.grade;//按照成绩升序排列
//    }
//};
//struct Student1 {
//    int id;
//    double grade;
//    Student1(int x, double y) :id(x), grade(y) {};
//    const bool operator>(const Student1& s) const
//    {//重载 > 号的时候最好不要出现 < 号
//        //这里有三个const，作用不同
//        //第一个const表示返回值是常量，可有可无，一般不写
//        //第二个const 避免改变参数的值，并且可以接受常量参数和非常量参数，如果不加的话 p1(非const)+p2(const)就会出错，因为 p1.operator+(p2) 将p2视为了参数，即将常量视为参数，而实参是常量形参必定是常量。
//        //第三个const 保证了此函数可以被常量对象调用（常量对象不能调用非常量成员函数，因为this指针具有const属性，而成员函数不接受const指针）
//        //return id > s.id;//按照id降序排列
//        //return id < s.id;//按照id升序排列,最好写成下面的形式
//        //return s.id > id;
//        //return grade > s.grade;//按照成绩降序排列
//        //return grade < s.grade;//按照成绩升序排列,最好写成下面的形式
//        return s.grade > grade;
//    }
//};
//void main()
//{
//    vector<int> nums = { 2,5,3,6,4,1,2 };
//    //**********默认升序排列***********
//    sort(nums.begin(), nums.end());
//    cout << "**********默认升序排列***********" << endl;
//    for (auto i : nums)
//    {
//        cout << i << ' ';
//    }
//
//    cout << endl;
//    //**********声明全局比较函数,变成降序排列***********
//    nums = { 2,5,3,6,4,1,2 };
//    sort(nums.begin(), nums.end(), cmp1);
//    cout << "**********声明全局比较函数cmp1,变成降序排列***********" << endl;
//    for (auto i : nums)
//    {
//        cout << i << ' ';
//    }
//    cout << endl;
//    //**********使用标准库函数,变成降序排列***********
//    nums = { 2,5,3,6,4,1,2 };
//    sort(nums.begin(), nums.end(), greater<int>());
//    cout << "**********使用标准库函数,变成降序排列***********" << endl;
//    for (auto i : nums)
//    {
//        cout << i << ' ';
//    }
//    cout << endl;
//    //**********重载<,按照id降序排列***********
//    Student s_1(1, 80);
//    Student s_2(3, 75);
//    Student s_3(2, 90);
//    vector<Student> V = { s_1,s_2,s_3 };
//    sort(V.begin(), V.end(), less<Student>());//如果这里指定了排序规则less或greater的话，重载<和>的成员函数必须是常量函数
//    cout << "**********重载<,按照id降序排列***********" << endl;
//    for (auto i : V)
//    {
//        cout << i.id << "号同学的成绩是" << i.grade << endl;
//    }
//    cout << endl;
//    //**********重载>,按照grade升序排列***********
//    Student1 s1_1(1, 80);
//    Student1 s1_2(3, 75);
//    Student1 s1_3(2, 90);
//    vector<Student1> V1 = { s1_1,s1_2,s1_3 };
//    sort(V1.begin(), V1.end(), greater<Student1>());
//    cout << "**********重载>,按照grade升序排列***********" << endl;
//    for (auto i : V1)
//    {
//        cout << i.id << "号同学的成绩是" << i.grade << endl;
//    }
//    cout << endl;
//    //**********重载（）,变成降序排列***********
//    nums = { 2,5,3,6,4,1,2 };
//    sort(nums.begin(), nums.end(), cmp3());
//    cout << "**********重载（）,变成降序排列***********" << endl;
//    for (auto i : nums)
//    {
//        cout << i << ' ';
//    }
//    cout << endl;
//}

/////////////////////////////////////////// 模拟实现整数转换英文表示////////////////////////////////////////

//https://leetcode-cn.com/problems/integer-to-english-words/solution/zheng-shu-zhuan-huan-ying-wen-biao-shi-b-ivik/
//vector<string> singles = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };//singles[0]为空是为了把数字和索引对齐，可以去掉，recursion里面做相应的调整
//vector<string> teens = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
//vector<string> tens = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };//同样是为了把数字和索引对齐，10已经在teens里面表示过了，所以从20开始，20/10=2，索引为2
//vector<string> thousands = { "", "Thousand", "Million", "Billion" };//单位，十亿->百万->千->一
//void recursion(string& curr, int num);//必须提前声明，否则main函数无法识别
//void main()
//{
//    //int num = 1234567891;
//    int num = 1000010;
//    if (num == 0) {
//        cout<< "Zero"<<endl;
//        return;
//    }
//    string res;
//    //单位，每3位属于一个单位，比如（个十百）属于一个单位，后面什么也不加，（千万十万）属于一个单位，后面要加thousand，（百万，千万，亿）属于一个单位，后面要加Million
//    //（十亿，百亿，千亿）属于一个单位，后面要加billion...但是int的最大值就是21亿多，所以只需要从十亿这个单位开始就行了
//    int unit = 1000000000;
//    for (int i = 3; i >= 0; i--) {//从thousands里面提取单位，thousands[0]表示一，thousands[1]表示千，thousands[2]表示百万，thousands[3]表示十亿，
//        int curNum = num / unit;//计算每轮单位前的数字，比如1 234 567 891，第一轮十亿的单位前的数字是1，表示1个十亿，第二轮百万单位前面的数字是234，第三轮千前面的数字是567，第四轮一前面的数字是891
//        if (curNum != 0) {
//            num -= curNum * unit;//减去每轮已经转换完的数，比如第一轮就是1234567891-1000000000=234567891，第二轮就是234567891-234000000=567891...
//            string curr;//记录每一轮转换后的字符串
//            recursion(curr, curNum);//把每一轮的数字转换成字符串，第一轮是1，第二轮是234，第三轮是567...
//            curr = curr + thousands[i] + " ";//把转换完的数字和单位还有一个空格组合起来，单位是一的时候就不用加单位了，直接用数字表示
//            res += curr;//把每一轮的结果组合起来，就是答案
//        }
//        unit /= 1000;//单位每次缩小1000，十亿->百万->千->一
//    }
//    while (res.back() == ' ') {
//        res.pop_back();
//    }
//    cout<< res<<endl;
//}
//void recursion(string& curr, int num) {//这里传递的是引用，所以可以直接在函数里修改，不用返回
//    if (num == 0) {//这里的num可以是一位数，两位数和三位数，num==0表示这是一个十的倍数，比如20,30,120,140...
//        return;
//    }
//    else if (num < 10) {//num==0已经排除了，那么1~9就可以用singles里面的字符串表示了
//        curr = curr + singles[num] + " ";
//    }
//    else if (num < 20) {//10~19可以用teens里面的字符串表示
//        curr = curr + teens[num - 10] + " ";
//    }
//    else if (num < 100) {//20~99分为两个循环来表示，第一次先转化十位，把十位上的数字用tens里面的字符串表示，然后把余数（1~9）用singles表示，比如56，先转换成
//        curr = curr + tens[num / 10] + " ";
//        recursion(curr, num % 10);
//    }
//    else {//100~999分为三个循环来表示，第一次先转换百位，用singles和一个" Hundred "，注意" Hundred "里面Hundred前面后面都有一个空格，所以不用再加空格了
//        curr = curr + singles[num / 100] + " Hundred ";
//        recursion(curr, num % 100);
//    }
//}

/////////////////////////////////////////// 不使用乘法、除法和 mod 运算符计算除法，包含各种边界条件////////////////////////////////////////

//https://leetcode-cn.com/problems/divide-two-integers/solution/po-su-de-xiang-fa-mei-you-wei-yun-suan-mei-you-yi-/
//void main()
//{
//    //被除数和除数均为 32 位有符号整数。
//    //假设我们的环境只能存储 32 位有符号整数，其数值范围是 [INT_MIN, INT_MAX]。本题中，如果除法结果溢出，则返回INT_MAX。
//    int dividend = 11, divisor = -1;
//    if (dividend == INT_MIN && divisor == -1)//分子为INT_MIN,分母为 -1 ，那么结果就会越界返回INT_MAX
//    {
//        cout << INT_MAX << endl;
//        return;
//    }
//    if (divisor == 1)//分母为1，返回分子
//    {
//        cout << dividend << endl;
//        return;
//    }
//    bool flag = true;//符号位标志
//    if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))//分子分母异号，结果应该是负值，符号位为false
//        flag = false;
//    //把分子分母全都转换成负数，因为负数能表示的范围大一些，比如INT_MAX转换成负数不会越界，而INT_MIN转换成正数就越界了
//    // ·因为INT_MIN=-2147483648，INT_MAX=2147483647，INT_MIN转成正数就是2147483648>2147483647，就会越界了
//    if (dividend > 0) dividend = -dividend;
//    if (divisor > 0)  divisor = -divisor;
//
//    int ans = 0;//保存结果
//    while (1) {
//        int a = dividend, b = divisor, cnt = 1;
//        if (a > b) break;//因为a和b都是负数，所以当a>b的时候就代表真正的分子比分母小了，这时候就不能再除下去了
//        while (a - b <= b) {//因为a和b都是负数，所以a-b一定在 [INT_MIN+1, INT_MAX]之间，所以肯定不会越界
//            //当a-b<=b的时候，代表b还可以继续翻倍，比如a=-11,b=-3,a-b=-8<=-3，代表-11分出一个-3后还能在分出一个-3，那么商cnt就应该翻倍（注意不是加一）变成2
//            //然后让分母翻倍，此时分子为-11，分母为-6，发现a-b=-5>-6,说明a要比四倍的b要小，要比两倍的b要大，也就是2*b<=a<4*b，所以商至少是2（cnt此时就是2），先加进结果（ans += cnt=2）
//            //那么就让分子变成a-2*b，得到新的分子分母，分子a=a-2*b（也就是dividend -= b;）分母b重新变成原有的分母（divisor），因为此时的a已经无法容纳两倍的原有分母
//            //比如新的a=-5，b=-3，cnt=1；此时a<b,说明可以容纳一个-3，但是a-b=-2>-3，说明只能容纳一个-3，无法容纳两个-3（-6），那么分母b就不用翻倍了，此时结果已经很明显了，只需要退出就行了
//            //所以就不用把cnt翻倍，直接加进结果（ans += cnt=3），并且分子再次减去一个b，此时a=-2，b=-3，退出循环，ans=3；
//            //·举例1：分子=-11，分母=3，那么a=-11，b=-3，cnt=1，a-b=-8<-3，进入while循环，cnt=1+1=2，b=-3+（-3）=-6，此时a-b=-5>-6，退出while循环，ans=0+2=2，dividend=-11-(-6)=-5
//            //        继续下一轮循环，a=-5，b=-3，cnt=1，a-b=-2>-3，不进入while循环，ans=2+1=3，dividend=-5-（-3）=-2
//            //        继续下一轮循环，a=-2，b=-3，cnt=1，a>b，退出循环
//            //·举例2：分子=-13，分母=3，那么a=-13，b=-3，cnt=1，a-b=-10<-3，进入while循环，cnt=1+1=2，b=-3+（-3）=-6，此时a-b=-7<-6，继续while循环，cnt=2+2=4(这里体现倍增），b=-6+（-6）=-12
//            //         此时a-b=-1>-6，退出while循环，ans=0+4=4，dividend=-13-(-12)=-1
//            //        继续下一轮循环，a=-1，b=-3，cnt=1，a>b，退出循环
//            cnt += cnt;
//            b += b;
//        }
//        ans += cnt;
//        dividend -= b;
//    }
//    cout<< (flag ? ans : -ans)<<endl;
//}

/////////////////////////////////////////// 不使用+-*/计算加法////////////////////////////////////////

//int main()
//{
//    int a = -3, b = -1;
//    //因为不允许用+号，所以求出异或部分和进位部分依然不能用+ 号，所以只能循环到没有进位为止        
//    while (b != 0)
//    {
//        //保存进位值，下次循环用
//        int c = (a & b) << 1;
//        
//        //保存不进位值，下次循环用，
//        a ^= b;
//        cout << a << endl;
//        binary_print(a);
//        //如果还有进位，再循环，如果没有，则直接输出没有进位部分即可。
//        b = c;
//        cout << b << endl;
//        binary_print(b);
//        cout << endl;
//    }
//    cout << a << endl;
//}


/////////////////////////////////////////// 不使用+-*/计算减法（利用a-b=a+(-b)=a+(~b+1)）或者位运算////////////////////////////////////////

//int add(int a, int b)
//{
//    if (b == 0)
//    {
//        return a;
//    }
//    //保存进位值，下次循环用
//    int c = (a & b) << 1;//C++中负数不支持左移位，因为结果是不定的
//    //保存不进位值，下次循环用，
//    a ^= b;
//    //如果还有进位，再循环，如果没有，则直接输出没有进位部分即可。
//    b = c;
//    return add(a, b);
//}
//int main()
//{
//    int a = -5, b = -3;      
//    cout << add(a,add(~b,1)) << endl;//减去一个数等于加上这个数的相反数，相反数等于 原码取反加 1
//    //*********************位运算*************************
//    //1、首先，如果减数为0，则被减数即为减法的结果，运算结束。
//    //    但如果减数不为0，我们可以先把被减数和减数上同为1的位从两个数上去除。至于如何分离出值同为1的位，则可以通过求位与操作来做到；而把这些1分别中被减数和减数中去除，则可以通过按位异或来的操作来实现。
//    //2、经步骤1处理后，被减数和减数在对应的位上，将或者通为0，或者分别为0和1，却不会同为1。此时：
//    //    如果对应位被减数 = 1，而减数 = 0，则所得结果对应位也为1；
//    //    如果对应位被减数 = 0，而减数 = 1，则所得结果对应位还是1，但此时须向前一位借1；
//    //    即，通过被减数与减数作位异或的操作得到临时结果，和通过对减数左移一位得到需从临时结果中减去的借数。
//    //3、于是，经过步骤2后，原来的减法变成了要求：临时结果 - 借数
//    //    很明显，只要以临时结果为被减数，借数为减数，重复步骤1~3即可。
//    binary_print(a);
//    binary_print(b);
//    while (b != 0)
//    {
//        int p = a & b;//找出同为1的位
//        cout << p << endl;
//        binary_print(p);
//        a ^= p;//去除被减数中的1
//        cout << a << endl;
//        binary_print(a);
//        b ^= p;//去除减数中的1
//        cout << b << endl;
//        binary_print(b);
//        a ^= b;//临时结果，需要借位的话就相当于被减数凭空增大一个数（这个数需要大于减数，才能减去减数得到临时结果），但是被减数凭空增大，减数也应该增大，否则结果就不对了
//               //因此，减数也增大这个数，就是左移 1 位
//        cout << a << endl;
//        binary_print(a);
//        b <<= 1;
//        cout << b << endl;
//        binary_print(b);
//        cout << endl;
//    }
//    cout << a << endl;
//}

/////////////////////////////////////////// 不使用+-*/计算乘法////////////////////////////////////////

//int main()
//{
//    int a = -3, b = -5;
//    if (a == 0 || b == 0)
//    {
//        cout << 0 << endl;
//        return 0;
//    }
//    bool flag = true;
//    if (b < 0)
//    {
//        flag = false;
//        b = -b;//因为快速乘里面的 b 只能是正数，所以要进行翻转
//    }
//
//    int ans = 0;
//    while (b)//快速乘，和快速幂的思想一样
//    {
//        if (b & 1)
//            ans = ans + a;/*add(ans, a);*///如果题目明确说了
//        a = a << 1;
//        b = b >> 1;
//    }
//    cout<<(flag?ans:-ans)<<endl;
//}


/////////////////////////////////////////// 在数组中找到只出现过一次的两个数字，其他数字全都出现两次////////////////////////////////////////

//void main()
//{
//    vector<int> nums = { 1,2,10,4,1,4,3,3 };
//    int m = 1, n = 0, x = 0, y = 0;
//    for (auto i : nums)//相同的数异或后为0,0异或任何数不变，所以最后n就是两个只出现1次的数x和y的异或值
//    {
//        n ^= i;
//    }
//    while ((m & n) == 0)//x和y异或后是n，n的二进制从右往左找到第一位为1的位置（也可以是其他位置，随便取得），说明x和y的二进制表示在这一位置上不同（只有这一位不同，异或以后才会是1）
//    {
//        m <<= 1;
//    }
//    for (auto i : nums)//通过遍历判断 nums 中各数字和 m 做与运算的结果，可将数组拆分为两个子数组，并分别对两个子数组遍历求异或，则可得到两个只出现一次的数字
//                       //x和y分别与m相与后一定得到不同的数，而相同的两个数与m相与后一定是相同的，也就是在同一组里
//    {
//        if (m & i)
//        {
//            x ^= i;
//        }
//        else
//        {
//            y ^= i;
//        }
//    }
//    cout << x << ' ' << y << endl;
//}

/////////////////////////////////////////// 在数组中找到只出现过一次的数字，其他数字全都出现三次////////////////////////////////////////

//https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/solution/mian-shi-ti-56-ii-shu-zu-zhong-shu-zi-chu-xian-d-4/
//void main()
//{
//    vector<int> nums = { 3,4,3,3 };
//    int ones = 0, twos = 0;
//    for (int num : nums) {//状态转移
//        //最后结果每一位的余数肯定是0或1，取决于只出现一次那个数字的二进制，但是转移过程中必须有三种状态
//        //这里的状态表示截止到目前数字为止，某一个二进制位上1的总个数对3的余数，会出现0，1，2三种状态
//        //假如只用两个状态来表示，那就无法完成状态转移
//        //另外每遍历一个数，它的32位二进制状态是同时完成转移的，因为所有位数的状态转移图相同，可以同时进行
//        //为什么最后直接返回ones就行了？
//        //·因为最后每一位的余数肯定是0或1，在状态图中就是00或01，那么twos最后肯定是0，ones是每一位结果组成的整数，因此返回ones即可
//        ones = ones ^ num & ~twos;
//        twos = twos ^ num & ~ones;
//    }
//    cout << ones << endl;
//}

/////////////////////////////////////////// 归并排序，以及统计逆序对////////////////////////////////////////

//https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/solution/jian-zhi-offer-51-shu-zu-zhong-de-ni-xu-pvn2h/
//int res = 0;
//void mergeSort(int l, int r, vector<int>& nums, vector<int>& tmp) {
//    // 终止条件
//    if (l >= r) return;//划分为子数组，如果子数组长度为1就没必要排序了
//    // 递归划分
//    int m = (l + r) / 2;
//    mergeSort(l, m, nums, tmp);
//    mergeSort(m + 1, r, nums, tmp);
//    // 合并阶段
//    int i = l, j = m + 1;
//    for (int k = l; k <= r; k++)//nums本来是乱序数组，tmp是相同大小的数组，为了把已排序的子数组保存起来，需要先对乱序数组做一个备份，也就是tmp[k] = nums[k];
//        tmp[k] = nums[k];
//    for (int k = l; k <= r; k++) {//[l,r]就是需要合并的子数组长度，把[l,r]平均分成两份，分别是[l,m]和[m+1,r]，i和j分别表示其中的索引，因此如果i==m+1，说明左边子数组已经遍历完了，只需要遍历右边子数组
//        if (i == m + 1)
//            nums[k] = tmp[j++];
//        else if (j == r + 1 || tmp[i] <= tmp[j])//如果右边子数组遍历完了，或者左边子数字的数小于等于右边子数组里的数，那就添加左子数组当前元素 tmp[i]
//            nums[k] = tmp[i++];
//        else {//否则说明左边子数字的数大于右边子数组里的数，构成逆序对，而在合并阶段的两个子数组[l,m]和[m+1,r]都是排好序的，所以一旦左边子数组里的某个数大于右边子数组的某个值，那么左边子数组
//              //后面的所有数都和右边子数组中的这个数构成逆序对，因此res += m - i + 1。
//            nums[k] = tmp[j++];
//            res += m - i + 1; // 统计逆序对
//        }
//    }
//    return;
//}
//void main()
//{
//    vector<int> nums = { 7,3,2,6,0,1,5,4 };
//    vector<int> tmp(nums.size());
//    mergeSort(0, nums.size() - 1, nums, tmp);//归并排序
//    for (auto i : nums)
//    {
//        cout << i << ' ';
//    }
//    cout << endl << res << endl;
//}

/////////////////////////////////////////// 给表达式添加运算符+-*,使结果等于target////////////////////////////////////////

//https://leetcode-cn.com/problems/expression-add-operators/solution/gei-biao-da-shi-tian-jia-yun-suan-fu-by-2o1s7/
//void backtrack(string& expr, int i, long res, long mul, vector<string>& ans,int target,string& num)
//{
//    //·expr 为当前构建出的表达式；传入的是引用，所以最后一定要完全清除这一层的表达式，也可以传入值，但是效率很低
//    //·i 表示当前的枚举到了num 的第 i 个数字；
//    //·res 为当前表达式的计算结果；
//    //·mul 为表达式最后一个连乘串的计算结果。
//    if (i == num.size()) {//当所有数字都枚举完的时候
//        if (res == target) {//检查结果是否和target相同
//            ans.emplace_back(expr);
//        }
//        return;
//    }
//    int signIndex = expr.size();//当前表达式的长度，用来回溯
//    if (i > 0) {
//        // 占位，下面填充符号，也就是后面的expr[signIndex] = '+'会把这里添加的0换成+-*，注意这里不是‘0’，而是阿斯克码中的第一个转义字符‘\0’，当然这里就是用来占位置，用什么字符都行
//        //i=0的时候不用占位，因为i=0的时候不能添加符号，
//        expr.push_back(0); 
//    }
//    long val = 0;//保存由单个或多个数字符号组成的数
//    // 枚举截取的数字长度（取多少位），截取的数字是num[i:j]，注意数字可以是单个0 但不能有前导零，只要判断截取的数字首位num[i]是不是‘0’就行了，因为只要不出现第一个前导0，就一定不会出现第二个前导0
//    //·j==i就表示单个字符的时候什么数字字符（0~9）都可以，比如i=1，j=1的时候，“0”可以计算在结果内
//    //·nums[i]！=0表示截取出来的数字首位不能是0，比如当i=1，j=2的时候，“05”显然不能表示一个数，因此不能计算进结果
//    for (int j = i; j < num.size() && (j == i || num[i] != '0'); ++j) {
//        val = val * 10 + num[j] - '0';
//        expr.push_back(num[j]);
//        if (i == 0) { // 表达式开头不能添加+-*
//            backtrack(expr, j + 1, val, val,ans,target,num);
//        }
//        else { // 枚举符号
//            expr[signIndex] = '+'; //把占位符换成+号
//            backtrack(expr, j + 1, res + val, val, ans, target, num);//下一个符号可能是*，所以 传入下一层的最后一个连乘串是val
//            expr[signIndex] = '-'; 
//            backtrack(expr, j + 1, res - val, -val, ans, target, num);//下一个符号可能是*，所以 传入下一层的最后一个连乘串是-val
//            expr[signIndex] = '*'; 
//            backtrack(expr, j + 1, res - mul + mul * val, mul * val, ans, target, num);//因为我们上一轮已经计算过了mul，所以要先减去，然后再加上当前连乘的结果
//                                                                                       //上一轮是 - 也没关系，因为上一轮计算了减，传入的参数是 -val，所以这一轮先减 mul 就变成了加，不会影响结果
//        }
//    }
//    expr.resize(signIndex);//回溯，也就是把添加的符号和数字全都去掉，这种回溯方法比较方便，不必考虑在本次循环中添加了多少字符
//                           //这个回溯是为了不影响上一轮的计算结果，因为传入的expr参数是引用，会影响上一轮
//}
//void main()
//{
//    string num = "105";
//    int target = 5;
//    int n = num.length();//设字符串num 的长度为n，为构建表达式，我们可以往num 中间的n−1个空隙添加+ 号、- 号或 * 号，或者不添加符号。
//    vector<string> ans;
//    string expr;//expr 为当前构建出的表达式；
//    backtrack(expr, 0, 0, 0, ans,target,num);
//    for (auto s : ans)
//    {
//        cout << s << endl;
//    }
//}

/////////////////////////////////////////// 和为target的连续正数序列////////////////////////////////////////

//https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/solution/jian-zhi-offer-57-ii-he-wei-s-de-lian-xu-t85z/
//void main()
//{
//    int target = 15;
//    int i = 1, j = 2, s = 3;//i和j表示滑动窗口的左右端点，s表示窗口内的数字和
//    vector<vector<int>> res;
//    vector<int> ans;
//    while (i < j) {//窗口中至少要有两个数，当右端点j>=target/2之后，右端点前进的速度会远小于左端点前进的速度，因此窗口会不断缩小，直到两指针相遇
//        if (s == target) {//如果找到一种组合，就加进结果中
//            ans.clear();
//            for (int k = i; k <= j; k++)
//                ans.push_back(k);
//            res.push_back(ans);
//        }
//        if (s >= target) {//如果和太大了( > )或者以i为左端点已经找到了一种组合( = )，那么就不可能再找到以i为左端点的另一种组合了，就应当收缩左边界，以i+1为左端点
//            s -= i;
//            i++;
//        }
//        else {//否则就继续扩大右端点
//            j++;
//            s += j;
//        }
//    }
//    for (auto v : res)
//    {
//        for (auto i : v)
//        {
//            cout << i << ' ';
//        }
//        cout << endl;
//    }
//   
//}

/////////////////////////////////////////// 添加和搜索单词（前缀树Trie）////////////////////////////////////////

//https://leetcode-cn.com/problems/design-add-and-search-words-data-structure/solution/tian-jia-yu-sou-suo-dan-ci-shu-ju-jie-go-n4ud/
//class WordDictionary {
//public:
//    struct StringTree
//    {
//        //StringTree* children[26] = { nullptr };//利用数组实现
//        vector<StringTree*> children;//利用vector实现，不能在声明的时候直接定义，需要在构造函数里定义
//        bool isEnd;//表示单词是否已经结束了，防止已经add的单词比search的单词多几个单词，比如已经add了badge，要查找bad这个单词，查找到d的时候发现index已经到头，但是此节点的isEnd是false，表示字典树里
//                   //没有bad但是有比bad多几个字母的单词，这时候应该返回false，不匹配
//        StringTree() :isEnd(false) {
//            this->children = vector<StringTree*>(26, nullptr);
//        }
//    };
//    StringTree* root;//首先建立一个根节点
//    WordDictionary() {
//        root = new StringTree();
//    }
//
//    void addWord(string word) {
//        int n = word.size();
//        StringTree* node = root;//root不能动，所以要新建一个结点node
//        for (int i = 0;i < n;i++)
//        {
//            if ((node->children[word[i] - 'a']) == nullptr)//不存在就新建
//            {
//                StringTree* tmp = new StringTree();
//                node->children[word[i] - 'a'] = tmp;
//            }
//            node = node->children[word[i] - 'a'];//向下转移
//        }
//        node->isEnd = true;//所有单词添加完毕，node指向最后一个字母的节点，那么此节点的isEnd赋值为true，表示单词结尾
//    }
//
//    bool search(string word) {
//        return dfs(word, 0, root);//利用dfs查找单词，这样就不必为‘.’单独建一个指针了
//    }
//    bool dfs(const string& word, int index, StringTree* node) {
//        if (index == word.size()) {//如果search的单词遍历完了，那么就看最后一个字母节点的isEnd是不是true
//            return node->isEnd;
//        }
//        char ch = word[index];//没遍历完就继续遍历
//        if (ch >= 'a' && ch <= 'z') {//如果该字符是字母，那么就找到该字母的分支，继续递归
//            StringTree* child = node->children[ch - 'a'];
//            if (child != nullptr && dfs(word, index + 1, child)) {
//                return true;
//            }
//        }
//        else if (ch == '.') {//如果是'.'，那就要遍历所有子分支
//            for (int i = 0; i < 26; i++) {
//                StringTree* child = node->children[i];
//                if (child != nullptr && dfs(word, index + 1, child)) {//只要找到一个就返回true
//                    return true;
//                }
//            }
//        }
//        return false;//该字符的子分支不存在或者后续字符不匹配，那么就返回false
//    }
//};
//void main()
//{
//    WordDictionary w;
//    w.addWord("badge");
//    w.addWord("mad");
//    w.addWord("dad");
//    cout << w.search("bad") << endl;
//    cout << w.search("pad") << endl;
//    cout << w.search(".ad") << endl;
//    cout << w.search("b..") << endl;
//}

/////////////////////////////////////////// DFS购买大礼包（记忆化搜索）////////////////////////////////////////

//https://leetcode-cn.com/problems/shopping-offers/solution/da-li-bao-by-leetcode-solution-p1ww/
//map<vector<int>, int> memo;//存放每一种可能的needs和他们的价格，如果之前回溯中这种needs出现过，那就直接返回价格
//int dfs(vector<int> price, vector<int> curNeeds, vector<vector<int>>& filterSpecial, int n) {
//    if (!memo.count(curNeeds)) {//如果之前回溯中这种needs没出现过
//        int minPrice = 0;
//        for (int i = 0; i < n; ++i) {
//            minPrice += curNeeds[i] * price[i]; // 不购买任何大礼包，原价购买购物清单中的所有物品
//        }
//        for (auto& curSpecial : filterSpecial) {//分别计算买了符合规定的礼包之后的价格
//            int specialPrice = curSpecial[n];
//            vector<int> nxtNeeds;
//            for (int i = 0; i < n; ++i) {
//                if (curSpecial[i] > curNeeds[i]) { // 不能购买超出购物清单指定数量的物品
//                    break;
//                }
//                nxtNeeds.emplace_back(curNeeds[i] - curSpecial[i]);
//            }
//            if (nxtNeeds.size() == n) { // 当前礼包符合规定，可以购买
//                minPrice = min(minPrice, dfs(price, nxtNeeds, filterSpecial, n) + specialPrice);//买了这个礼包之后还需要一些物品，继续回溯，两个价格相加再与不购买礼包的价格对比，取最小值
//            }
//        }
//        memo[curNeeds] = minPrice;//记录一下当前needs的价格，记忆化
//    }
//    return memo[curNeeds];
//}
//int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
//    int n = price.size();
//
//    // 过滤不需要计算的大礼包，只保留需要计算的大礼包
//    vector<vector<int>> filterSpecial;
//    for (auto& sp : special) {
//        int totalCount = 0, totalPrice = 0;
//        for (int i = 0; i < n; ++i) {
//            totalCount += sp[i];//礼包中含有的物品总数
//            totalPrice += sp[i] * price[i];//原本的总价值
//        }
//        if (totalCount > 0 && totalPrice > sp[n]) {//如果礼包中不含任何物品或者原本的总价格小于礼包价格，那么就没必要买礼包
//            filterSpecial.emplace_back(sp);
//        }
//    }
//
//    return dfs(price, needs, filterSpecial, n);
//}
//// 记忆化搜索计算满足购物清单所需花费的最低价格
//void main()
//{
//    vector<int> price = {2,3,4};//每件物品的价格，A的价格是2元，B的价格是3元，C的价格是4元
//    vector<vector<int>> special = { {1,1,0,4},{2,2,1,9 } };//大礼包，礼包一包含1个A，1个B，0个C，总共4元，礼包二包含2个A，2个B，1个C，总共9元
//    vector<int> needs = {1,2,1};//需要1个A，2个B，1个C
//    cout<<shoppingOffers(price, special, needs)<<endl;
//}

///////////////////////////////////////////// DFS单词拼凑字符串（记忆化搜索）////////////////////////////////////////

//https://blog.csdn.net/qq_41855420/article/details/89475759
//搜索拼凑target需要的最少贴纸数量
//int dfs(unordered_map<string, int>& strStickerCnt, vector<vector<int>>& myStickers, string target) {
//    if (strStickerCnt.count(target)) {
//        //target表示我们目前需要的字符总状态，如果target已经搜索过，表明我们已经知道凑齐target最少需要多少贴纸，直接返回
//        return strStickerCnt[target];
//    }//除了已经搜索过直接返回以外不需要其他返回，因为我们要把所有贴纸能组成的状态都搜索一遍，才能找到最少贴纸数量，target为空时会在这里返回，因为我们已经把空字符需要0张贴纸记录在map里了
//    int minRes = INT_MAX, stickersSize = myStickers.size();
//    //统计target中各个字符出现的次数
//    vector<int> tar(26, 0);
//    for (char ch : target) {
//        tar[ch - 'a'] ++;
//    }
//    //尝试使用每一个sticker
//    for (int i = 0; i < stickersSize; ++i) {//贴纸可以随便重复使用，所以从0开始
//        //如果当前sticker中没有target[0]这个字符则剪枝
//        if (myStickers[i][target[0] - 'a'] == 0) {//myStickers记录的是每个贴纸包含的字符及其个数
//            continue;
//        }
//        //使用当前sticker，nowTarget为运用贴纸后剩余的字母
//        string nowTarget = "";
//        for (int j = 0; j < 26; j++) {
//            if (tar[j] - myStickers[i][j] > 0) {//这张贴纸上有多少能用的就都剪一下用，没有或者不够的字符凑成newTarget，继续深搜
//                nowTarget += string(tar[j] - myStickers[i][j], 'a' + j);
//            }
//        }
//        //搜索nowTarget字符串需要最少贴纸数
//        int tempRes = dfs(strStickerCnt, myStickers, nowTarget);
//        //更新target字符串需要的最少贴纸数
//        if (tempRes != -1) {//等于-1代表无法拼凑出newTarget，那么我们就不能用当前的贴纸，不更新minRes，换下一张贴纸；否则更新minRes
//            minRes = min(minRes, 1 + tempRes);
//        }
//    }
//    strStickerCnt[target] = (minRes == INT_MAX ? -1 : minRes);//标记target已经搜索过
//    return strStickerCnt[target];
//}
//int main()
//{
//    vector<string> stickers = { "with", "example", "science" };
//    string target = "thehat";
//    int stickersSize = stickers.size();
//    unordered_map<string, int> strStickerCnt;//strStickerCnt[str]表示的字符串str需要的最少贴纸数量
//    vector<vector<int>> myStickers(stickersSize, vector<int>(26, 0));//各个贴纸中各个字母出现的次数
//    //统计每一张贴纸包含的字符及个数
//    for (int i = 0; i < stickersSize; ++i) {
//        for (char ch : stickers[i]) {
//            myStickers[i][ch - 'a'] += 1;
//        }
//    }
//    strStickerCnt[""] = 0;//初始化，空字符串不需要贴纸
//    cout << dfs(strStickerCnt, myStickers, target) << endl;
//    return 0;
//}

/////////////////////////////////////////// 判断路径是否交叉（分情况讨论，归纳总结题）////////////////////////////////////////

//https://leetcode-cn.com/problems/self-crossing/solution/gong-shui-san-xie-fen-qing-kuang-tao-lun-zdrb/
//void main()
//{
//    vector<int> distance = { 2,1,1,2 };
//    int n = distance.size();
//    if (n < 4)
//    {
//        cout<<false<<endl;
//        return;
//    }
//    for (int i = 3; i < n; i++) {
//        if (distance[i] >= distance[i - 2] && distance[i - 1] <= distance[i - 3])
//        {
//            cout << true << endl;
//            return;
//        }
//        if (i >= 4 && distance[i - 1] == distance[i - 3] && distance[i] + distance[i - 4] >= distance[i - 2])
//        {
//            cout << true << endl;
//            return;
//        }
//        if (i >= 5 && distance[i - 1] <= distance[i - 3] && distance[i - 2] >= distance[i - 4] &&
//            distance[i] + distance[i - 4] >= distance[i - 2] && distance[i - 1] + distance[i - 5] >= distance[i - 3])
//        {
//            cout << true << endl;
//            return;
//        }
//    }
//    cout << false << endl;
//}

/////////////////////////////////////////// 祖玛游戏，DFS消除连续同颜色的球////////////////////////////////////////

//https://leetcode-cn.com/problems/zuma-game/solution/acmjin-pai-ti-jie-dfsmei-ju-bian-cheng-x-30qj/
//unordered_map<char, int> mp;//保存hand还剩下的各种颜色的球的个数
//unordered_map<string, bool> vis;//保存消除同颜色的球之后剩余的字符串是否被访问过了，如果被访问过了，那么不管这个字符串能否完全消除，其结果都已经被记录过了，不需要再访问下去
//                                //如果没有被访问过，那么就继续访问
//char color[5] = { 'R', 'Y', 'B', 'G', 'W' };
//int ans = 100;
//string eliminate(string s) {
//    bool flag = true;//标志符
//    while (flag) {
//        flag = false;//用来退出while循环
//        for (int i = 0, j = 0; i < s.size(); i = j) {//注意这里没有改变j的值，只是一种方法，值得学习
//            //这个循环用来消除一个字符串里面的连续的球，只能消除一种颜色的，比如s=“bwwrrrwbb”，一开始i=0，j=0，while循环用来找和s[i]相同的字符，如果字符长度大于等于3，就消除
//            //j=1，i=0，j-i=1不符合；i=j=1，j=3，j-i=2不符合；i=j=3，j=6，j-i=3符合，消除“rrr”，s变成“bwwwwbb”，break退出for循环，但是flag仍然为true，i和j继续从0开始消除
//            while (j < s.size() && s[i] == s[j])
//                ++j;
//            if (j - i >= 3) {//只有当字符串中存在连续相同的字符时，flag才等于true，表示消除了相同的球以后两端的球有可能继续消除，因此最外层的while循环要继续，只有当字符串中
//                //不存在连续的相同球以后flag才为false，退出循环
//                s = s.substr(0, i) + s.substr(j);
//                flag = true;
//                break;
//            }
//        }
//    }
//    return s;
//}
//void dfs(string s, int step) {//s是表示当前的字符串，step表示已用的球数
//    if (step >= ans)//当已用步数大于ans是就没必要继续访问了，因为我们要求最少步数
//        return;
//
//    if (s.size() == 0) {//已经消除完了
//        ans = min(ans, step);
//        return;
//    }
//    if (vis[s])//当前字符串已经访问过了，也就是说已经知道它能否消除完和消除完需要的步数，所以不需要再访问
//        return;
//    vis[s] = true;//标记为访问过
//    //不会出现相同board不同hand的情况，因为起点（原始的board）相同，终点（经过消除得到的board）相同，而且只能用hand的同颜色去消除board，那么就只能有一种策略
//    //这和格子迷宫到达同一地点不一样，格子迷宫向下向左都都能达到接近终点的目的，而祖玛只能通过同色球消除去接近终点，换句话说，祖玛是限定只能向下走的格子迷宫
//    //另外起点是不包含三个连续的同色球的，要不然的话相同board有可能会出现不同hand的情况，比如board=“wwwr”，hand=“wr”你可以选择放入一个“w”使得board=“r”
//    // 此时hand=“r”；也可以不放，使得board=“r”，此时hand=“wr”
//    for (int i = 0; i < 5; i++) {//逐个颜色考虑放球
//        if (!mp[color[i]])//如果这种颜色的球已经放完了，就要放下一个颜色的
//            continue;
//        for (int j = 0; j < s.size(); j++) {//遍历每个能放球的位置
//            string next = s.substr(0, j + 1) + color[i] + s.substr(j + 1);//插入球
//            next = eliminate(next);//同颜色连续就消除
//            mp[color[i]] -= 1;//该颜色的数量减一
//            dfs(next, step + 1);//进入下一轮，注意每一个j都有一个next字符串
//            mp[color[i]] += 1;//回溯
//        }
//
//    }
//}
//void main()
//{
//    string board = "WWRRBBWW", hand = "WRBRW";
//    for (auto& it : hand)
//        ++mp[it];
//    board = eliminate(board);//如果最开始有连续的同色球，就消除
//    dfs(board, 0);
//    cout<<(ans == 100 ? -1 : ans)<<endl;
//}

//////////////////////////////////////////猜数字，保证获胜的最少代价////////////////////////////////////////

//https://leetcode-cn.com/problems/guess-number-higher-or-lower-ii/solution/cai-shu-zi-da-xiao-ii-by-leetcode-soluti-a7vg/
//·用f(i,j) 表示在范围[i,j]内确保胜利的最少金额，目标是计算 f(1, n)。
//·假设第一次猜的数字是 x 并且猜错，则需要支付金额 x，当 x 大于所选数字时，为了确保胜利还需要支付的金额是 f(1, x - 1)，
//  当 x 小于所选数字时，为了确保胜利还需要支付的金额是f(x + 1, n)。为了在任何情况下都能确保胜利，应考虑最坏情况，计算 f(1, n)时应取上述两者的最大值：
//  f(1, n) = x + max(f(1, x - 1), f(x + 1, n))。
//·为了将确保胜利的金额最小化，需要遍历从 1 到 n 的所有可能的 x，使得 f(1, n)的值最小：
//  f(1, n) = min{x + max(f(1, x - 1), f(x + 1, n))}（x=[1:n]，包括1和n）
//·由于 f(1, x - 1) 和 f(x + 1, n)都是比原始问题 f(1, n)规模更小的问题，因此可以使用动态规划的方法求解。
//int main()
//{
//    int n = 10;
//    vector<vector<int>> dp(n + 1, vector<int>(n + 1));//dp(i,j)表示在范围 [i, j]内确保胜利的最少金额,目标是计算 dp[1][n]
//    //当 i = j时范围 [i, j]只包含 1个数字，所选数字一定是范围内的唯一的数字，不存在猜错的情况，因此 dp(i, j) = 0；当 i > j时范围 [i, j]不存在，因此 dp(i, j) = 0。
//    //综合上述两种情况可知，动态规划的边界情况是：当 i>=j 时，dp(i, j) = 0,vector如果没有初始化值的话默认全都是0。
//    //当 i < j时，在范围 [i, j]内第一次猜的数字可能是该范围内的任何一个数字。在第一次猜的数字是 k的情况下（i<=k<=j），在范围 [i, j]内确保胜利的最少金额是
//    //k+max(f(i,k−1),f(k+1,j))。需要遍历全部可能的 k 找到在范围 [i, j]内确保胜利的最少金额，因此状态转移方程如下：
//    //dp(i, j) = min{k + max(dp(i, k-1), dp(k + 1, j))}（k=[i:j]，包括i和j）
//    for (int i = n - 1; i >= 1; i--) {//注意遍历顺序，dp(i, j)由dp(i, k-1)(dp[i][j]的左边，最左到达主对角线的左邻元素）和dp(k + 1, j)(dp[i][j]的下边）推出，
//                                      //因此i要从最下边（n+1）开始，j要从最左边开始，但是当 i>=j 时，dp(i, j) = 0，所以j就从i+1开始了
//        for (int j = i + 1; j <= n; j++) {
//            int minCost = INT_MAX;//每个dp[i][j]的值都要重新猜，重新计算
//            for (int k = i; k < j; k++) {
//                //为什么k<j即可，当k=j时 cost = j + max(dp[i,j-1], dp[j+1,j]) = j + max(dp[i,j-1], 0) = j + dp[i,j-1] 
//                //               当k=j-1时 cost = j-1 + max(dp[i,j-2], dp[j,j]) = j-1 + max(dp[i,j-2], 0) = j-1 + dp[i,j-2] 
//                //               后者显然小于前者（j-1小于j，在[i,j-1]这个较大范围里猜数的花费肯定大于在[i,j-2]这个较小范围里猜数的花费），故无需考虑k=j的情况
//                //               当然写成 k<=j 也没问题
//                int cost = k + max(dp[i][k - 1], dp[k + 1][j]);
//                minCost = min(minCost, cost);
//            }
//            dp[i][j] = minCost;//记录最小值
//        }
//    }
//    cout << dp[1][n] << endl;
//}

//////////////////////////////////////////从 1 到 n 的数字，且恰好拥有 k 个逆序对的不同的数组的个数////////////////////////////////////////

//https://leetcode-cn.com/problems/k-inverse-pairs-array/solution/kge-ni-xu-dui-shu-zu-by-leetcode-solutio-0hkr/
//static constexpr int mod = 1000000007;
//int main()
//{
//    int n = 3, k = 1;//所有包含从 1 到 n 的数字，且恰好拥有 k 个逆序对的不同的数组的个数
//    vector<vector<int>> f(2, vector<int>(k + 1));
//    // f[i][j]表示我们使用数字1,2,⋯,i 的排列构成长度为 i 的数组，并且恰好包含 j 个逆序对的方案数
//    //我们可以考虑第 i个元素选取了1, 2, ⋯, i 中的哪个数字。
//    //假设我们选取了数字 k，那么数组的前 i - 1个元素由1, ⋯, k−1 以及k + 1, ⋯, i 的某个排列构成。数组中的逆序对的个数可以看成如下的两部分之和：
//    //·数字 k与前 i-1 个元素产生的逆序对的个数；
//    //·前 i - 1个元素「内部」产生的逆序对个数。
//    //对于第一部分而言，我们可以求出：数字 k 会贡献 i-k个逆序对，即k+1,⋯,i 与 k 分别产生一个逆序对,总共i-k个。
//    //对于第二部分而言，我们希望它能够有j−(i−k) 个逆序对，这样才能一共有 j个逆序对。由于我们关心的是前 i-1个元素「内部」产生的逆序对个数，
//    //而逆序对只和元素的「相对大小」有关，因此我们可以：
//    //·1,⋯,k−1 这些元素保持不变；
//    //·k+1,⋯,i 这些元素均减少 1，变成 k,⋯,i−1。
//    //使得前 i-1个元素中，任意两个元素的相对大小都不发生变化。此时，我们的目标变成了「对于1,2,⋯,i−1，希望它能够有 j-(i-k)个逆序对」，
//    //这就是动态规划中的子任务 f[i-1][j-(i-k)]。因此，我们就可以通过枚举 k 得到状态转移方程：
//    //f[i][j]= ∑f[i−1][j−(i−k)](k=[1:i])=∑f[i−1][j−k](k=[0:i-1])
//    //f[i][j-1]= ∑f[i−1][j-1−(i−k)](k=[1:i])=∑f[i−1][j-1−k](k=[0:i-1])
//    //裂项相消，就得到f[i][j]=f[i][j−1]−f[i−1][j−i]+f[i−1][j]
//    //边界条件为：
//    //·f[0][0] = 1即不用任何数字可以构成一个空数组，它包含 0个逆序对；
//    //·f[i][j < 0] = 0由于逆序对的数量一定是非负整数，因此所有 j < 0的状态的值都为 0
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 0; j <= k; ++j) {
//            int cur = i & 1, prev = cur ^ 1;//cur表示当前所在的是第一行还是第二行,prev表示另一行
//            //i是奇数的话cur=1，prev=0；i是偶数的话cur=0，prev=1；
//            f[cur][j] = (j - 1 >= 0 ? f[cur][j - 1] : 0) - (j - i >= 0 ? f[prev][j - i] : 0) + f[prev][j];
//            //在迭代的时候为了数值不溢出，取了模，所以dp[i][j]每个结果都在[0,MOD]之间，但是这个数值和实际结果大小是不一样的（因为取了模）然后用公式更新的时候，
//            //因为有减法，所以会出现负数，这个时候只需要再加上mod就可以了（等于每个dp[i][j]用之前的取模前的值去更新，然后再对它取模）...
//            //简单来说就是因为取模才会出现负数，而且结果不代表实际意义，比如原本应该是（12-9）%10=3，但是现在变成（2-9）%10=-7，所以只需要对-7加上10，就得到正确的答案
//            if (f[cur][j] < 0) {
//                f[cur][j] += mod;
//            }
//            f[cur][j] %= mod;//每个结果都应该取模
//        }
//    }
//    cout << f[n & 1][k] << endl;//不知道n是第几行，所以n & 1
//}

//////////////////////////////////////////不含相同字符的两个单词长度的最大值////////////////////////////////////////

//https://leetcode-cn.com/problems/maximum-product-of-word-lengths/solution/tong-ge-lai-shua-ti-la-zhao-dao-ti-mu-de-y37h/
//int main()
//{
//    vector<string> words = { "abcw","baz","foo","bar","xtfn","abcdef" };
//    int res = 0;
//    int n = words.size();
//    vector<int> mask(n, 0);
//    //用26位比特表示字母，如果某个单词中出现某个字母，则对应的比特位为1，比如"a"=00000000 00000000 00000000 00000001，"ab"=00000000 00000000 00000000 00000011
//    for (int i = 0;i < n;i++)
//    {
//        for (int j = 0;j < words[i].size();j++)
//        {
//            //不管这个字母出现几次，对应的比特位始终是1，因为这里用的是或，出现1次和出现多次没区别
//            mask[i] |= (1 << (words[i][j] - 'a'));
//        }
//    }
//    for (int i = 0;i < words.size();i++)
//    {
//        for (int j = i + 1;j < words.size();j++)
//        {
//            if (!(mask[i] & mask[j]))//如果两个字符对应的掩码位相与不是0，说明他们有相同字母
//            {
//                res = max(res, (int)(words[i].size() * words[j].size()));
//            }
//        }
//    }
//    cout<<res<<endl;
//}

//////////////////////////////////////////求前缀 prefix 开头的键 key 的值的总和。////////////////////////////////////////

//https://leetcode-cn.com/problems/map-sum-pairs/solution/tong-ge-lai-shua-ti-la-zi-dian-shu-qing-h4x2x/
//class MapSum {
//public:
//    struct Trie//严格来说并不是前缀树，因为前缀树需要有变量isEnd
//    {
//        int val;//存储值，如果不是单词结尾的字母，值默认是0
//        Trie* child[26];
//        Trie()
//        {
//            val = 0;
//            for (int i = 0;i < 26;i++)
//            {
//                child[i] = nullptr;
//            }
//        };
//    };
//    Trie* root;
//    MapSum() {
//        root = new Trie();
//    }
//
//    void insert(string key, int val) {
//        Trie* node = this->root;//每次插入都要从头结点开始
//        for (const auto& ch : key)//逐个字符插入
//        {
//            if (node->child[ch - 'a'] == nullptr)
//            {
//                node->child[ch - 'a'] = new Trie();
//            }
//            node = node->child[ch - 'a'];
//        }
//        node->val = val;//最后一个字母赋值
//    }
//    int dfs(Trie* node)//递归求和
//    {
//        int res = node->val;
//        for (int i = 0;i < 26;i++)
//        {
//            if (node->child[i])
//            {
//                res += dfs(node->child[i]);
//            }
//        }
//        return res;
//    }
//    int sum(string prefix) {
//        Trie* node = this->root;//每次求和都要从头结点开始
//        for (const auto& ch : prefix)
//        {
//            if (node->child[ch - 'a'] == nullptr)//如果不存在这样的前缀，就返回0
//            {
//                return 0;
//            }
//            node = node->child[ch - 'a'];
//        }
//        return dfs(node);//这里的node是前缀的最后一个字符，下个字符节点往下的所有单词都是以prefix为前缀，所以全都加起来
//    }
//};
//int main()
//{
//    MapSum mapSum;
//    mapSum.insert("apple", 3);
//    cout<<mapSum.sum("ap")<<endl;           // return 3 (apple = 3)
//    mapSum.insert("app", 2);
//    cout << mapSum.sum("ap") << endl;           // return 5 (apple + app = 3 + 2 = 5)
//}

//////////////////////////////////////////可怜的小猪////////////////////////////////////////

//有 buckets 桶液体，其中 正好 有一桶含有毒药，其余装的都是水。它们从外观看起来都一样。为了弄清楚哪只水桶含有毒药，你可以喂一些猪喝，通过观察猪是否会死进行判断。
//不幸的是，你只有 60 分钟时间来确定哪桶液体是有毒的。
//·喂猪的规则如下：
//·选择若干活猪进行喂养
//·可以允许小猪同时饮用任意数量的桶中的水，并且该过程不需要时间。
//·小猪喝完水后，必须有 15 分钟的冷却时间。在这段时间里，你只能观察，而不允许继续喂猪。
//·过了 15 分钟后，所有喝到毒药的猪都会死去，其他所有猪都会活下来。
//·重复这一过程，直到时间用完。
//给你桶的数目 buckets ，minutesToDie 和 minutesToTest ，返回在规定时间内判断哪个桶有毒所需的   最小   猪数。
//·我们以10瓶水举例讲解，十瓶水，一次喝的机会，我们用2进制表示为
//  1	   2	  3	     4	    5     6	     7	    8	   9	  10
// 0001	  0010	 0011	0100   0101	 0110	0111   1000	  1001	  1010
//我们按不同位数把他们分组（从右到左，第1位是最低位）
//  第1位为1	第2位为1	第3位为1	第4位为1
//    0001	     0010	      0100	      1000
//    0011	     0011	      0110	      1001
//    0101	     0110	      0111	      1010
//    0111	     0111	      0101
//    1001	     1010
//把每一纵列的水取出来一滴然后混合，现在我们有四瓶混合水，准备四只猪分别对应四瓶混合水，也就是分别对应四位为1的组，
//·把第一位为1的给一号猪
//·把第二位为1的给二号猪
//·把第三位为1的给三号猪
//·把第四位为1的给四号猪
//喝完
//现在假设四号猪，死了，另外3只没死
//这意味着什么？
//意味着第四位为1的瓶子中有一瓶有毒！
//嫌疑人有
//1000
//1001
//1010
//然而我们知道，另外3只没死，意味着第一位为1，第二位为1，第三位为1的都没有毒
//所以排除掉后面4个
//真相只有一个！
//1000是有毒！
//这相当于是一个在与不在的二元判断
//对于第一位为1的水，如果猪死了，证明毒水里面第一位是1
//依次类推，i号猪的存亡状态决定了毒水编号二进制的第i位是否为1
//所以1000瓶水，是2 ^ 10次方，我们需要10位去表示，十只猪去检验
//·然而这是只有一次喝的机会的情况，这种情况下，猪死了就代表这一位为1，反之就是0，因为只有两种情况（0和1）
//  但是当喝水次数变多的时候，虽然我们仍然能够用10只猪去判断1000瓶水，需要时间仅为15分钟，但是我们用了更多的猪并且浪费了剩余的喝水次数，
//  因此，我们考虑将1000瓶水按照五进制来编码，这样就需要5位，每一位上有0,1,2,3,4五种可能，每一轮仍然按照各个位上的可能分组（从右到左，第1位是最低位）
// ·第一轮：  第1位为0    第2位为0 	第3位为0	第4位为0	第5位为0
//              00000       00000        00000       00000       00000
//              00010       00001        00001       00001       00001
//               ...         ...          ...         ...         ...
//  让五只猪去喝五瓶混合水，哪只猪死了就代表哪一位上是0，没死的话就不能确定那一位是多少了（有1,2,3,4四种可能，需要继续实验），发现3号猪和5号猪死了。所以有毒的水的编号是： 0_0__. 
// ·第二轮：  第1位为1 	第2位为1	第4位为1（第3位和第5位确定了，不需要继续了）
//              00001         00010       01000
//              00011         00011       01001
//               ...           ...         ...
//  让剩下的三只猪去喝三瓶混合水，哪只猪死了就代表那一位上是1，没死的话就不能确定那一位是多少了（还有2,3,4三种可能，需要继续实验），发现2号猪死了。所以有毒的水的编号是： 0_01_.
// ·第三轮：  第1位为2 	第4位为2（第2位、第3位和第5位确定了，不需要继续了）
//              00002         02000
//              00012         02001
//               ...           ... 
//  让剩下的两只猪去喝两瓶混合水，哪只猪死了就代表那一位上是2，没死的话就不能确定那一位是多少了（还有3,4两种可能，需要继续实验），发现都没死。所以有毒的水的编号仍然是： 0_01_.
// ·第四轮：  第1位为3 	第4位为3（第2位、第3位和第5位确定了，不需要继续了）
//              00003         03000
//              00013         03001
//               ...           ... 
//  让剩下的两只猪去喝两瓶混合水，哪只猪死了就代表那一位上是3，没死的话就可以那一位是4，发现1号猪死了，4号猪还活着。。所以有毒的水的编号是： 04013.
//  对应10进制下的508,所以508有毒
//·综上所述，我们首先确定每一位有几种可能，T 次机会能确定 T+1 种可能，用 T 次喝水机会就能完全确定每一位上的值（因为我们排除了 T 种可能，就不需要再去尝试了，因为只剩下这一种可能了），
//  1次机会能确定2种可能，4次机会能确定5种可能...也就是用 T+1 进制来编码
//  然后就可以确定最少的猪的个数 x，也就是需要多少位（T+1）进制，总共的编码数为 (T+1)^x （T+1的x次方），需要满足(T+1)^x>1000,那么x>log (T+1）1000，向上取整
//int main()
//{
//    int buckets = 1000, minutesToDie = 15, minutesToTest = 60;
//    int T = minutesToTest / minutesToDie;
//    cout<<ceil(log(buckets) / log(T + 1))<<endl;
//}

//////////////////////////////////////////随机返回二维矩阵中不是1的元素坐标，访问过的元素变成1////////////////////////////////////////

//https://leetcode-cn.com/problems/random-flip-matrix/solution/sui-ji-fan-zhuan-ju-zhen-by-leetcode-sol-pfmr/1252587
//·根据需求，我们需要每次生成一个数，随机数的范围就是0到total = m * n(不包括total。total代表还没有被转化为1的元素个数，为什么不包括total，因为随机数从0开始）。
//·很明显，刚开始的total等于m * n，也就是全部元素的总数。
//·接下来我们生成第一个随机数x, 由于x在0到m * n, (不包括m * n), 我们可以先把x直接当作下标来用, 很明显由于这是第一个随机数x，x下标对应的元素必然是0，
//  我们直接把对应元素置为1（逻辑上），把x对应二维坐标返回即可。剩余的还未被操作的元素个数更新为total - 1， 即维护total == total - 1
//·接下来我们生成第二个随机数x2, 我们不妨假设x2就等于第一次生成的x，这时候x2对应元素还是0吗？明显不是，因为x == x2，第一次操作时已经将x对应元素置为1了。
//  既然x2已经被用过了，我们接下来应该怎么办呢？是重新获得一个随机数吗？回头看一下，我们发现第一次操作后，因为更新total = total - 1, 有一个数（对应旧的total - 1，即m * n - 1, 
//  也就是一维数组的最后一个下标）永远不会出现在本次的随机数里面了，但是这个数对应的下标还没有被用到，我们不妨在之前用hashmap记录这个没有被用到的数(map[x] = m * n - 1)，
//  使得当再一次随机到一个数等于x的时候，我们不是用x来当下标，而是用x记录的total - 1来当下标。（至此，我们假设的是前2次都随机到一个相同的数字）
//·接下来我们不妨再假设第3次随机得到的数字x3还是等于第一次的x，这时候下标x 和m * n - 1都被用过了怎么办？回头再看，我们发现第二次操作之后，又有一个下标total - 2不会再出现再随机数里面，
//  但是还没有被用过，于是我们可以重复第一次的操作，在hashmap里面更新随机数x对应的下标（map[x] = m * n - 2）。
//·以后就是差不多操作，当获取到一个随机数x时，给x维护一个还没有被用到过的下标，保证下次再获得同样的随机数x时，能立马得到一个还没有被用过的下标.
//其实可以理解为用过这个随机数后，把后面（比这个值大）的没用过的数填到这个数的位置上，hashmap用来记录我们把哪个数填到这里了，参考：
//https://leetcode-cn.com/problems/random-flip-matrix/solution/pythonjavajavascriptgo-jiang-wei-ha-xi-b-8ipu/
//class Solution {
//public:
//    unordered_map<int, int> umap;//用来记录已经产生过的随机数和最后一个数的映射
//    int col;//记录行和列
//    int row;
//    int total;//记录元素总数
//    Solution(int m, int n) {
//        total = m * n;
//        col = n;
//        row = m;
//    }
//
//    vector<int> flip() {
//        int a = rand() % total;//产生范围是[0,total-1]
//        int res;
//        if (umap.count(a))//如果a已经产生过了
//        {
//            res = umap[a];//结果就变成还没用过的total
//        }
//        else
//        {
//            res = a;//否则，结果就是a
//        }
//        if (umap.count(total - 1))//接下来我们要建立a的映射，因为a用过了，下次不能再用，如果此时的最后一个数也是用过的，那么map里面肯定也有一个映射，我们用最终没有被用过的数来更新
//        {//图参考 https://pic.leetcode-cn.com/1638022328-jJzIMN-file_1638022333112
//            umap[a] = umap[total - 1];
//        }
//        else {//如果此时的最后一个数没用过，就更新为最后一个数
//            umap[a] = total - 1;
//        }
//        int i = res / col;//还原成二维
//        int j = res % col;
//        total--;
//        return { i,j };
//    }
//
//    void reset() {
//        umap.clear();
//        total = row * col;
//    }
//};
//int main()
//{
//    Solution so(2, 2);
//    for (auto i : so.flip())
//    {
//        cout << i << ' ';
//    }
//    cout << endl;
//    for (auto i : so.flip())
//    {
//        cout << i << ' ';
//    }
//    cout << endl;
//    for (auto i : so.flip())
//    {
//        cout << i << ' ';
//    }
//    cout << endl;
//    for (auto i : so.flip())
//    {
//        cout << i << ' ';
//    }
//    cout << endl;
//    so.reset();
//    for (auto i : so.flip())
//    {
//        cout << i << ' ';
//    }
//    cout << endl;
//}

//////////////////////////////////////////Z字形输出字符串////////////////////////////////////////

//https://leetcode-cn.com/problems/zigzag-conversion/solution/zzi-xing-bian-huan-by-jyd/
//void main()
//{
//    string s = "PAYPALISHIRING";
//    int numRows = 3;
//    string res = "";
//    vector<string> tmp(min(numRows, (int)s.size()));
//    int row = 0;
//    bool flag = true;
//    for (int i = 0;i < s.size();i++)
//    {
//        cout << row << endl;
//        tmp[row] += s[i];
//        if (flag)
//        {
//            row++;
//        }
//        else
//        {
//            row--;
//        }
//        if (row == -1 )
//        {
//            flag = !flag;
//            row+=2;
//        }
//        else if (row == min(numRows, (int)s.size()))
//        {
//            flag = !flag;
//            row-=2;
//        }
//    }
//    for (const auto& s : tmp)
//    {
//        res += s;
//    }
//}

//////////////////////////////////////////判断不同筛子的个数////////////////////////////////////////

//https://ac.nowcoder.com/questionTerminal/27086d759f01413b94a1a30a53e4a333
//总共有N个筛子，将其中一个骰子通过若干次上下、左右或前后翻转后，其与另一个骰子对应的6面数字均相等，则为同一个筛子。
//int main() {
//	int N;
//	cin >> N;//N个筛子
//	unordered_map<int, int> um;//四个侧面组成的key，相同的key代表他们是同一个筛子旋转而成的（“1”是上面，“2”是下面）
//	for (int n = 1; n <= N; ++n) {
//		int a[6];
//		for (int i = 0; i < 6; ++i) cin >> a[i];//按照“上下左右前后”的顺序输入6个面的数
//		int val = 0;
//		for (int i = 0; i < 6; ++i) {
//			if (a[i] == 1) {//找到“1”所在的位置，把它定为上面
//				if (i % 2 == 0)//如果这个上面是在偶数位置，也就是在输入顺序的“上、左、前”三个位置，那么侧面就是“左前右后”/“前上后下”/“上左下右”（从“上面”看是逆时针）
//							   //这个顺序是因为我们从“1”所在的上面俯视，逆时针旋转记录四个侧面（这个顺序可以随意），不用管谁是第一个，因为后面还要循环旋转
//					val = a[(i + 2) % 6] * 1000 + a[(i + 4) % 6] * 100 + a[(i + 3) % 6] * 10 + a[(i + 5) % 6];
//				else//如果这个上面是在奇数位置，也就是在输入顺序的“下、右、后”三个位置，那么侧面就是“后右前左”/“下后上前”/“右下左上”
//					//这个顺序和上面的顺序是对应的，都是逆时针旋转记录（这里的逆时针就和上面相反了，因为我们定义的“1”的上面相反了）
//					val = a[(i + 4) % 6] * 1000 + a[(i + 2) % 6] * 100 + a[(i + 3) % 6] * 10 + a[(i + 1) % 6];
//				break;
//			}
//		}
//
//		for (int i = 0, tmp = val; i < 3; ++i) {//旋转四个侧面，记录最小值为key，相同的key表示同一个筛子，因为“上”“下”两面固定，侧面可以旋转得到相同的key
//			tmp = tmp / 10 + (tmp % 10 * 1000);
//			val = min(val, tmp);
//		}
//		um[val]++;
//	}
//
//	vector<int> res;
//	for (auto iter : um) res.push_back(iter.second);//保存同一个筛子的个数
//	sort(res.begin(), res.end(),greater<int>());//相同筛子的个数递减排序
//	cout << res.size() << endl;//输出不同筛子的个数
//	for (auto i:res) cout << i << " ";
//	return 0;
//}

//////////////////////////////////////////不重叠的3个子数组之和的最大值////////////////////////////////////////

//给定一个整数数组nums和一个整数k，找到三个长度为k且总和最大的不重叠子数组并返回它们。 以索引列表的形式返回结果，这些索引表示每个间隔(索引为0)的起始位置。
//如果有多个答案，返回按字典顺序最小的一个
//https://leetcode-cn.com/problems/maximum-sum-of-3-non-overlapping-subarrays/solution/gong-shui-san-xie-jie-he-qian-zhui-he-de-ancx/1272149
//正常来说：定义 f[i][j]为考虑以第i个数为结尾的数组（也就是0,1,2,...i-1一共i个数)，凑成无重叠子数组数量为 j 个时的和最大值。最终答案为 f[n][3]。
//·对于nums[i]，有两种做法：取或不取，
//·如果取了，由于这 j 个子数组无重叠，因此前面的 j - 1个子数组不能覆盖 [i - k + 1, i]（这一段长度刚好是k）。即只能在 [0, i - k]中选 j - 1个子数组。
//  此时有：f[i][j]=f[i−k][j−1]+ ∑nums[idx]，idx=[i-k+1,i],表示包含nums[i]的最后一个子数组和
//·当明确了 nums[i]对最优方案无贡献，此时问题等价于考虑前 i - 1个数，凑成 j个不重叠子数组的最大值。此时有：
//  f[i][j] = f[i - 1][j]
//·最终 f[i][j]为上述两种方案中的最大值。
//然后考虑「如何回溯出字典序最小的具体方案」，常规的回溯具体方案的做法是，从最终答案 f[n][3]开始往回追溯。
//利用 f[n][3]仅由两个可能的节点（f[n - 1][3] 和 f[n - k][2]）转移而来，通过判断 f[n][3]等于 f[n - 1][3] 还是 f[n−k][2]+ ∑nums[idx]，idx=[n-k,n-1]来决定回溯点为何值。
//但该做法只能确保回溯出字典序最大的方案是正确（当两个可能的前驱节点都能转移到 f[i][j]时优先采纳靠后的位置），而我们需要回溯出字典序最小的方案。
//在上述解法的基础上，有两种「求解字典序最小具体方案」的做法：
//·将正序 DP 调整为反序 DP。修改状态定义为 f[i][j]为考虑从第i个数到第n个数中进行选择，凑出无重叠子数组数量为 j个时的最大值（最终答案为 f[1][3]）。转移过程分析同理，
//  然后从下标 idx = 0开始进行回溯，优先采纳 idx小的方案即可；
//·仍然采取正序 DP 的做法，但对原数组进行翻转，从而将回溯「字典序最大」转换为「字典序最小」具体方案。
//·这里用的是反序DP
//int main()
//{
//    vector<int> nums = { 1,2,1,2,6,7,5,1 };
//    int k = 2;
//    const int n = nums.size();
//    // 前缀和
//    vector<long long> sum(n + 1, 0);  
//    for (int i = 1; i <= n; i++)
//    {
//        sum[i] = sum[i - 1] + nums[i - 1];//sum[1]表示第1个数相加，sum[i]表示第1个数到第i个数相加
//    }
//    // 计算最优值
//    //f[i][j]为考虑以第i个数为结尾的数组（也就是i-1，i,i+1...n-1,一共n-i+1个数)，凑成无重叠子数组数量为 j 个时的和最大值。最终答案是f[1][3]
//    //正常来说应该有n行4列，也就是i的范围是[1:n-k]（反序遍历，i就表示j个数组的末尾的数字，j必定大于0，因为等于0就代表0个子数组，其和一定是0），j的范围是[1:3]
//    //·但是，如果i=[1:n-k]的话，当i=n-k时，sum[n-k+k-1]-sum[n-k-1]=sum[n-1]-s[n-k-1]，无法包含最后一个数（正确的应该是sum[n]-s[n-k]），
//    //    而如果用sum[i+k]-sum[i]的话，当i=1时，sum[1+k]-sum[1]有无法包含第一个数（正确的应该是sum[k]-sum[0]）
//    //·因此，我们有两种做法，第一是末尾拉长，也就是i的范围变成[1:n-k+1]，这样sum[n-k+1+k-1]-sum[n-k+1-1]=sum[n]-s[n-k]正确；
//                              第二是开头拉长，也就是i的范围变成[0:n-k]，这样sum[0+k]-sum[0]=sum[k]-s[0]正确；
//    //这里用的是第一种
//    vector<vector<long long>> f(n + 2, vector<long long>(4, 0));
//    for (int i = n - k + 1; i >= 1; i--) {
//        for (int j = 1; j < 4; j++) {
//            f[i][j] = max(f[i + 1][j], sum[i + k - 1] - sum[i - 1] + f[i + k][j - 1]);
//        }
//    }
//    // 从最优值和最终状态开始回溯 (背包回溯方案)。
//    vector<int> ans;
//    int i = 1, j = 3;
//    // 在决定第几个枚举点? 
//    while (j > 0) {
//        // 最优值 f[i][j] 一定从两个状态转移过来 : f[i+1][j] 或者 sum[i...i+k-1] + f[i+k][j-1] 
//        // (1) 如果 nums[i] 无贡献，则一定有 f[i+1][j] 更大
//        if (f[i + 1][j] > f[i + k][j - 1] + sum[i + k - 1] - sum[i - 1]) { i++; }
//        // (2) 如果 nums[i] 被选择，则一定有 sum[i...i+k-1] + f[i+k][j-1] 更大。
//        else {
//            ans.push_back(i - 1);  // i表示的是第i个数，还原到索引应该-1
//            i += k; // 选取 nums[i] 后，只能继续从 nums[i+k...] 继续模拟取后面的点。
//            j--;
//        }
//    }
//}

//////////////////////////////////////////给边界涂色////////////////////////////////////////

//https://leetcode-cn.com/problems/coloring-a-border/solution/bian-kuang-zhao-se-by-leetcode-solution-0h5l/
//typedef pair<int, int> pii;
//void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited, vector<pii>& borders, int originalColor) {
//    int m = grid.size(), n = grid[0].size();
//    bool isBorder = false;
//    int direc[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
//    for (int i = 0; i < 4; i++) {
//        int nx = direc[i][0] + x, ny = direc[i][1] + y;
//        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == originalColor)//如果新的坐标块属于连通域
//        {
//            if (!visited[nx][ny])//并且没有被访问过，注意这个if不能写到上一层if里面，因为下面的else是用来判断边界的，访问过的坐标块不是边界，不能用else表示，不过可以用else if来限制
//            {
//                visited[nx][ny] = true;//说明可以往下递归
//                dfs(grid, nx, ny, visited, borders, originalColor);
//            }
//        }
//        else//既然我们能递归到这一层来，说明此时的（x,y）坐标块属于连通域，那么如果上下左右的坐标超出网格或者不是同一颜色，说明我们（x，y）就是连通域的边界
//        {
//            isBorder = true;
//        }
//    }
//    if (isBorder) {//只要上下左右某一个坐标块满足边界要求，（x，y）就是边界
//        borders.emplace_back(x, y);
//    }
//}
//int main()
//{
//    vector<vector<int>> grid = { {1,1,1},{1,1,1},{1,1,1} };
//    int row = 1, col = 1;
//    int color = 3;
//    int m = grid.size(), n = grid[0].size();
//    vector<vector<bool>> visited(m, vector<bool>(n, false));
//    vector<pii> borders;//先找到边界，再染色，这样就避免了一边查找一边染色时，如果原本的某个颜色和目标颜色相同，那么原本的这个颜色被误认为是属于同一连通域，从而边界错误
//    int originalColor = grid[row][col];//先记录一下要染色的区域颜色
//    visited[row][col] = true;
//    dfs(grid, row, col, visited, borders, originalColor);
//    for (pii& p : borders) {
//        grid[p.first][p.second] = color;
//    }
//}

//////////////////////////////////////////通过n关需要按得按键数////////////////////////////////////////

//https://www.cnblogs.com/hanlin-hl/p/14596288.html
//int main()
//{
//    vector<int> a = { 1,1,4,5,1,4 };//a[0]表示第1关...
//    long long res = 0;
//    for (int i = 1; i <= a.size(); i++) {
//        //  第i关要失败a[i-1] - 1次，每次失败都要按i次按钮（前面有i-1关，需要按i-1次才能到第i关来（因为前i-1关的正确按钮我们已经知道了，所以前i-1关只需要按1次，总共i-1次），
//        //  再加上第i关失败的这次按，所以第i关一次失败需要i次按钮）
//        //  那么a[i-1]-1次失败就需要（a[i-1]-1）* i次，另外每一关还有一次成功的，所以对于第i关来说一共需要(a[i-1] - 1) * i + 1次（注意溢出）
//        res += (long long)(a[i-1] - 1) * i + 1;
//    }
//    cout<<res<<endl;
//    return 0;
//}

//////////////////////////////////////////课程表三////////////////////////////////////////

//https://leetcode-cn.com/problems/course-schedule-iii/solution/wei-rao-li-lun-tan-xin-suan-fa-gan-duede-pa4u/
//int main()
//{
//    vector<vector<int>> courses = { {100, 200},{200, 1300},{1000, 1250},{2000, 3200} };
//    //对于所有课程，肯定是优先选择截止日期早的课程，因此，按照截止日期由小到大排序，截止日期相同的优先选择持续时间短的课程
//    sort(courses.begin(), courses.end(), [](const auto& a, const auto& b) { return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]);});
//    //优先队列保存每一门已选择课程的持续时间
//    priority_queue<int> q;
//    int day = 0;//表示我们修完选择的课程需要的总天数，也就是能够修下一门课的起始日期
//    for (auto c : courses) {
//        if (day + c[0] <= c[1]) {//如果起始日期加上下一门课的持续时间小于等于下一门课的截止日期，那么说明可以选修下一门课
//            day += c[0];//选修，起始日期增加相应时间
//            q.push(c[0]);//已修的课程添加到优先队列中，因为当时间冲突的时候我们需要改变之前已选择的课程
//        }
//        //否则的话（下一门课的时间有冲突，不能直接选修），当我们之前已经选修过课程，并且那门课程比下一门课的持续时间长的话，我们就退选那门课并选修下一门课
//        else if (!q.empty() && q.top() > c[0]) {
//            day -= q.top();//去掉那门课的持续时间，因为day保存的是所有已选课程的持续时间之和，相当于把那门课的持续时间替换成下一门课的，前后的课还是可以满足条件的
//            day += c[0];//加上下一门课的持续时间
//            q.pop();//已选课的队列中弹出那门课
//            q.push(c[0]);//加入下一门课
//        }
//
//    }
//}

//////////////////////////////////////////视角为angle，在某一坐标上能看到标记点的最大个数////////////////////////////////////////

//https://leetcode-cn.com/problems/maximum-number-of-visible-points/solution/gong-shui-san-xie-qiu-ji-jiao-ji-he-ti-b-0bid/
//int main()
//{
//    vector<vector<int>> points = { {1, 1},{2, 2},{1, 2},{2, 1} };//标记点的坐标
//    int angle = 0;//视角
//    vector<int> location = { 1, 1 };//固定位置
//    int n = points.size();
//    vector<double> ang;
//    double range = (double)angle / 180.0 * M_PI;//将视角转化成弧度
//    int res1 = 0;//用来记录和固定位置相同的点的个数
//    for (int i = 0;i < n;i++)
//    {
//        if (points[i][1] == location[1] && points[i][0] == location[0])
//        {
//            res1++;
//        }
//        else//如果不是相同位置，则记录偏转角度，atan2函数返回值是(-π,π]，而atan函数返回值是(-π/2, π/2)
//        {
//            ang.emplace_back(atan2(points[i][1] - location[1], points[i][0] - location[0]));
//        }
//    }
//    sort(ang.begin(), ang.end());//偏转角度排序，从-π到π线性排列，不符合题目要求，因此下面要把-π和π连起来
//    int m = ang.size();
//    for (int i = 0;i < m;i++)对于每一个偏转角度，都让其加上2π，这样原本-π附近的值就会变成π附近，这样不会影响能看到标记点个数的最大值
//    {
//        ang.emplace_back(ang[i] + 2 * M_PI);
//    }
//    for (auto i : ang)
//    {
//        cout << i << ' ';
//    }
//    int res2 = 0;
//    int low = 0, high = 0;
//    while (high < 2 * m)//此时ang数组里面有2m个数
//    {
//        if (low <= high && ang[high] - ang[low] <= range)//ang[low]到ang[high]之间的所有点都在视角里面（包括low和high），因此更新res2
//        {
//            res2 = max(res2, high - low + 1);
//        }
//        while (low<=high && ang[high] - ang[low]>range)//如果ang[low]到ang[high]之间有一部分点不在视角里面，则收缩low，相当于滑动窗口
//        {//注意是while循环，不在视角里时会一直收缩，直到下一个满足条件的low
//            low++;
//        }
//
//        high++;
//    }
//    cout << res1 + res2 << endl;//最后结果是res1+res2
//    return 0;
//}

//////////////////////////////////////////隔离人口密度h以上的城市形成的连通块小于等于m时的最小h值////////////////////////////////////////

//https://ac.nowcoder.com/questionTerminal/5ad3f49d4fdb45679f8c5280101cdecd?f=discussion
//输入：
//5 3
//1 2 3 4 5
//1 2
//1 4
//2 3
//2 5
//输出：4，解释：
//当h = 4时，城市4和城市5会被封城：城市4和城市1的边被切断，城市5与城市2的边被切断。
//此时形成了3个连通块：
//城市1, 2, 3可以相互达到构成了一个连通块。
//城市4单独构成了一个连通块。
//城市5单独构成了一个连通块。
//此时h满足条件且最小。
//struct node {
//    int idx, val, cnt;
//}pnode;//定义每个城市的序号，人口密度，人口密度小于此城的城市个数（也就是连通图里的入度或出度）
//vector<node> s;
//bool cmp(node a, node b) {
//    return a.val > b.val;
//}
////·由于n个城市连了n-1条边，说明任意一个结点只有唯一一条路径可以达到另一个结点，不会存在多条路径，也就是整个图中不会有环存在
////·这样的话，如果是无向图，任意隔离一座城市（也就是把他和邻居两个城市的路径切断），都会形成3个连通块（本身单独的一块、左边的连通块、右边的连通块）
////·如果是有向图，则每个结点都存在入度和出度，任意隔离一个入度为x，出度为y的城市，都会出现x+y+1个连通块（本身单独的一块，指向此结点的x块，此结点指出的y块）
////  因为这x块之间只有通过此结点中转，没有其他路径互达，我们隔离了中转结点，因此就形成了x个连通块
////·我们想找连通块小于等于m的最小人口密度值，那么就应该从密度最大的城市开始考虑，如果隔离了此城市之后形成的连通块大于m了，说明我们不能隔离此城市，
////  则h应该设为比此城市的人口密度大1，这样此城市就没有隔离，并且此时形成的连通块个数小于等于m
////  如果隔离了此城市之后形成的连通块小于等于m，说明我们的h还可以设的更小一点，以形成更多的连通块
////·要注意，必须是从人口密度大的城市开始寻找h，因为题目要求是人口密度大于等于h的城市都要隔离，如果从小密度的城市开始查找的话，就不知道以此城市的密度为h隔离之后会形成
////  多少个连通块了，因为其他的城市密度都比此城市大，隔离了此城市其他城市都要隔离，那么联通块数目无法计算；当然如果是小于等于h的城市都要隔离的话，应该从小密度城市开始查找
////·要注意，当我们隔离了一座城市后发现连通块的数量小于等于m，那么继续隔离下一城市的时候，连通块的数量是累加的，相当于我们把上一轮形成的小连通块分割成更小的连通块
////  所以最后cur要累加
////·要注意，这样做的前提是n个城市只形成n-1条边，只有一个中转城市，否则的话，隔离了中转城市也不一定会形成固定数量的连通块
//int main() {
//    ios::sync_with_stdio(false);//提高输入输出速度
//    int n, m;//n座城市，最后剩下的连通块的数量应当小于等于m
//    cin >> n >> m;
//    for (int i = 1;i <= n;i++) {//记录每座城市的编号，从1开始，到n结束，分别记录人口密度
//        cin >> pnode.val;
//        pnode.idx = i;
//        s.push_back(pnode);
//    }
//    for (int i = 1;i < n;i++) {
//        int a, b;
//        cin >> a >> b;//记录哪两座城市之间可以联通
//        a--, b--;//题目中输入的城市序号是从1开始的，而在s中，序号1城市的下标是0，所以a和b都要--
//        if (s[a].val > s[b].val)s[a].cnt++;//a和b联通且a的人口密度大于b，那么城市a的入度或出度++，后面需要根据这个值来计算形成的连通块数量
//        else s[b].cnt++;//否则城市b的入度或出度++
//    }
//    sort(s.begin(), s.end(), cmp);//按照人口密度由高到低排序
//    int h = -1, cur = 1;//cur表示隔离当前城市以后形成的连通块数量，最开始所有城市组成一个连通块
//    for (int i = 0;i < n;i++) {
//        cur += s[i].cnt;//隔离当前城市以后形成的连通块数量，为什么有向图的连通块数量不是x+y+1？
//                        //·因为我们已经规定了密度大的指向密度小的，并且我们遍历是从密度最大的开始的，密度最大的城市不存在入度（即x=0）
//                        //  隔离它以后，cur变成y+1，也就是cur += s[i].cnt（cur初始值为1），然后遍历第二大的城市，如果它和最大的城市有边相连，那么一定是最大指向第二大的
//                        //  而这条有向边我们在遍历最大的城市计算过了，它属于最大城市的出度之一（大城市的出度边同时也是小城市的入度边），所以我们在遍历密度小的城市的时候不能再计算
//                        //  它们的入度了，因为他们的入度都已经在计算大城市的出度的时候计算过了，比如:
//                        //    1 <----- 2(序号同时表示密度）
//                        //   ↑
//                        //    |
//                        //    3 <----- 4 <----- 5
//                        //            ↑
//                        //             |
//                        //             6
//                        //  如果我们直接隔离 4 号城市，那么肯定会形成 2（入度）+1（出度）+1（本身）= 4个连通块，但是如果我们规定必须从最大密度开始，则直接消除了 4 号城市的 2 个入度，所以在隔离
//                        //  4 号城市之后，只能新增1（出度）+1（本身）个连通块
//        if (cur > m) {//如果cur大于m了，说明不能隔离此城市，h就应该比此城市的密度大，为了求最小值的h，那就只能是此城市的密度+1
//            h = s[i].val + 1;
//            break;//找到h以后就不用再找了，因为接下来cur肯定会变得更大，更不会小于等于m了，此时的h一定是最小值
//        }
//    }
//    cout << h;
//    return 0;
//}

//////////////////////////////////////////固定供暖器位置，给所有房子供暖的最小半径////////////////////////////////////////

//https://leetcode-cn.com/problems/heaters/solution/gong-nuan-qi-by-leetcode-solution-rwui/
//int main()
//{
//    vector<int> houses = { 1,2,3,5,15 };//房间位置
//    vector<int> heaters = { 2,30 };//供暖期位置
//    int ans = 0;
//    sort(heaters.begin(), heaters.end());
//    for (int house : houses) {//对于每一所房子
//        int j = upper_bound(heaters.begin(), heaters.end(), house) - heaters.begin();//找到比它的位置大的第一个供暖器j，则j-1就是比它的位置小或等于的最后一个供暖器
//        int i = j - 1;//那么只有选择这两个供暖器中的一个才能使供暖半径最小
//        int rightDistance = j >= heaters.size() ? INT_MAX : heaters[j] - house;//计算右边距离，如果最后一个供暖器的位置超过了数组边界，那么右边距离就是无穷大，只能选择左边的供暖器
//        int leftDistance = i < 0 ? INT_MAX : house - heaters[i];//计算左边距离，如果第一个供暖器的位置超过了数组边界，那么左边距离就是无穷大，只能选择右边的供暖器
//        int curDistance = min(leftDistance, rightDistance);//在左边距离和右边距离中选择较小者，说明此房子是由那个供暖器来供暖的
//        ans = max(ans, curDistance);//为了保证所有的房子都能被覆盖，我们现在已经知道了每所房子属于哪一个供暖器以及它们的距离，只需要找到这些距离的最大值就能保证供暖半径最小的同时覆盖所有房子
//    }
//    cout << ans << endl;
//}

//////////////////////////////////////////最佳营地选择方案////////////////////////////////////////

//https://www.nowcoder.com/questionTerminal/b079b68130a54dc8841c8311e53c3120
//对于其中一个候选地 i 而言，如果将该地以及其直接相连的道路全都删除，就可以得到若干个连通块，用 w_i记录下其中的最大连通块中的候选地数量。
//对于所有的满足 w_ k = min{w_1,w_2 ...w_n}的候选地 k 而言，都是最佳军营建造地。
//int n, w[100005], minnode;//设为全局变量，这样在dfs函数里就不用传参数了
//const int N = 1e5 + 5, M = 1e5 + 5;
//int head[N], e[M], ne[M], weight[M],idx=0;
////vector<int>e[100005];//注意这是100005个vector，这是一个vector数组，用来保存邻居节点
//int dfs(int root, int f)
//{ //dfs返回的是root能够到达的结点数，f表示访问root之前访问的结点，也就是从哪个结点达到root的，也就是f是root的来源结点
//    int sum = 1, maxv = 0;//sum记录root能到达的结点个数，包括本身，因此初始值为1，maxv记录访问邻居节点的过程中返回的最大值，也就是root邻居节点能到达节点个数的最大值，不包括root
//                          //当删除了root以后，形成的最大连通块包含结点个数就是由 n-sum 和 maxv 决定的
//    for (int i = head[root];i !=-1;i=ne[i])
//    {
//        int y = e[i];//访问root结点的第i个邻居节点
//        if (y == f) continue;//如果要访问的结点就是我们的来源结点，那么就要继续访问下一个，否则就会构成循环
//        int temp = dfs(y, root);//temp记录root结点的第i个邻居节点y能到达的结点个数（包括y本身但是不包括root）
//        sum += temp;//每访问一个邻居节点，就把它能到达的结点个数加在sum里，成为root能到达的结点的一部分
//        maxv = max(maxv, temp);//记录访问邻居节点的过程中返回的最大值，也就是root的邻居节点能到达节点个数的最大值
//    }
//    //·为什么这里是n-sum和maxv的最大值？
//    //·因为root可能是一个边缘节点，它能到达的结点很少（甚至只能到达本身），这时我们应该计算包含来源结点f的那部分连通块，而那部分的数量是n-sum（sum表示root能到达的结点数量，
//    //  包含本身但是不包含来源结点的那一部分，同理，maxv只包含root向下能寻找到的节点个数，不包括向上的）
//    //·同时，root可能是一个中心结点，他能到达非常多的结点，那么删除root后形成的最大连通块就应该在root邻居结点的连通块中选择，这一步我们已经在遍历的过程中做过了，
//    //  maxv就是最大连通块的节点个数，
//    //·因此我们应该在 n-sum 和 maxv 中选择最大值
//    w[root] = max(n - sum, maxv);//记录下删除root后的最大连通块包含的节点个数w[i]
//    minnode = min(minnode, w[root]);// 记录最小w[i]的值
//    return sum;
//}
//void add(int a, int b, int c)
//{
//    weight[idx] = c;
//    e[idx] = b;
//    ne[idx] = head[a];
//    head[a] = idx++;
//}
//int main()
//{
//    ios::sync_with_stdio(0), cin.tie(0);//加速输入输出
//    int i, j, x, y;
//    int t;
//    cin >> t;
//    while (t--)//t组数据
//    {
//        minnode = 1e9;
//        cin >> n;//n个候选营地
//        memset(head, -1, sizeof(head));
//        memset(e, 0, sizeof(e));
//        memset(ne, -1, sizeof(ne));
//        memset(weight, 0, sizeof(weight));
//        memset(w, 0, sizeof(w));
//        //for (i = 1;i <= n;i++)
//        //{
//        //    e[i].clear();//每个营地的邻居节点全都清空
//        //    w[i] = 0;//此营地的权重设为0
//        //}
//        for (i = 1;i < n;i++)
//        {
//            cin >> x >> y;
//            add(x, y, 1);
//            add(y, x, 1);
//        }
//        dfs(1, 0);
//        int s1 = 0, s2 = 0;
//        for (i = 1;i <= n;i++)
//            if (w[i] == minnode)
//            {//找到两个最佳地点
//                if (s1 == 0)
//                    s1 = i;
//                else
//                    s2 = i;
//            }
//        if (s2 == 0)//如果最佳地点只有一个（s1），那么就随便找一条道路封闭再重建就行了，这里选择的是营地1到它的第一个邻居结点的道路
//            cout << s1 << ' ' << e[head[s1]] << endl,
//            cout << s1 << ' ' << e[head[s1]] << endl;
//        else//否则最佳地点有两个，也就是删除s1和s2后，形成的最大连通块包含的结点数最少，参考
//            //https://www.nowcoder.com/questionTerminal/b079b68130a54dc8841c8311e53c3120 的示例一说明，只需要把s1或者s2的某个邻居结点重建到彼此上去，就可以保证最佳地点唯一
//            //这里选择的是把s2的第一个不是s1的邻居结点重建到s1上去
//        {  
//            for (i = head[s2];i !=-1;i=ne[i])
//                if (e[i] != s1)//前提是这个结点不是s1或者s2
//                    break;
//            cout << s2 << ' ' << e[i] << endl,//删除
//            cout << s1 << ' ' << e[i] << endl;//重建
//        }
//    }
//    return 0;
//}

//////////////////////////////////////////数组中任意两数之和等于第三个数的三元组的数量////////////////////////////////////////

//int main()
//{
//    vector<int> arr = { 1, 8, 9, 10 };
//    if (arr.size() == 0)
//    {
//        return 0;
//    }
//    sort(arr.begin(), arr.end());
//    int res = 0;
//    unordered_set<int> uset;
//    for (int i = 0;i < arr.size();i++)
//    {
//        for (int j = 0;arr[i] - arr[j] > arr[j];j++)//arr[i] - arr[j] 是第三个数，那么要保证第三个数比第二个数大，否则就会出现重复的三元组，比如 9-1=8，,9-8=1
//        {
//            if (uset.count(arr[i] - arr[j]))
//            {
//                cout << arr[i] - arr[j] << ' ' << arr[j] << ' ' << arr[i] << endl;
//                res++;
//            }
//        }
//        uset.insert(arr[i]);
//    }
//    
//    return 0;
//}

//////////////////////////////////////////字符串哈希来查找最长的重复串////////////////////////////////////////

//https://leetcode-cn.com/problems/longest-duplicate-substring/solution/wei-rao-li-lun-rabin-karp-er-fen-sou-suo-3c22/
//·记 s 的长度为 n。这个问题可以分为两步：从 n - 1 到 1 由大至小遍历选取长度 L，判断 s 中是否有长度为 L 的重复子串。
//  从大至小遍历的时候，第一次遇到的符合条件的 L，即为最大的符合条件的 L，记为 L1,重复的子串为 s1，
//  并且对于任意满足 L0<=L1也均符合条件，因为 s1的所有子串也是 s 的重复子串。
//  而对于任意满足 L2>L1，则均不符合条件。因此，我们可以用二分查找的方法，来查找 L1
//·剩下的任务便是如何高效判断 s 中是否有长度为 L 的重复子串。我们可以使用 Rabin-Karp 算法对固定长度的字符串进行编码。
//  当两个字符串的编码相同时，则这两个字符串也相同。在 s 中 n−L+1 个长度为 L 的子串中，有两个子串的编码相同时，则说明存在长度为 L 的重复子串。
//  具体步骤如下：
//·首先，我们需要对 s 的每个字符进行编码，得到一个数组 arr。因为本题中 s 仅包含小写字母，我们可按照 arr[i] = s[i] - 'a'，将所有字母编码为 0 - 25 之间的数字。
//  比如字符串 “abcde" 可以编码为数组 [0, 1, 2, 3, 4]。
//·第二步：我们将子串看成一个 26 进制的数，它对应的 10 进制数就是它的编码。假设此时我们需要求长度为 3 的子串的编码。那么第一个子串 “abc” 的编码就是
//  h0=​= 0×26^2+ 1×26^1+ 2×26^0=28。更一般地，设 c[i]为 s 的第 i 个字符编码后的数字，a(a>=26) 为编码的进制，那么有 
//  h0=c[0]*a^(L-1)+c[1]*a^(L-2)+...+c[L]*a^0=∑c[i]*a^(L-1-i)(i=[0:L-1])
//·第三步：上一步我们只求了第一个子串“abc” 的编码。当我们要求第二个子串“bcd” 的编码时，也可以按照上一步的方法求：
//  h1=​= 1×26^2+ 2×26^1+ 3×26^0=731，但是这样时间复杂度是 O(L)。我们可以在 h0 的基础上，更快地求出它的编码：h1=(h0-0*26^2)*26+3*26^0(相当于去掉a，左移变大，再加上d)
//  ​更一般的表达式是：h1=(h0-c[0]*a^(L-1))*a+c[L] = (h[0]*a-c[0]*a^L)+c[L]。这样，我们只需要在常数时间内就可以根据上一个子串的编码求出下一个子串的编码。
//  我们用一个哈希表来存储子串的编码。在求子串的编码时，如果某个子串的编码出现过，则表示存在长度为 L 的重复子串，否则，我们将当前的编码放入哈希表中。
//  如果所有编码都不重复，则说明不存在长度为 L 的重复子串。
//int main()
//{
//    string s = "banana";
//    int n = s.size();
//    unsigned long long prime = 31;//为什么a选用31？因为要比26大，并且哈希碰撞最小，参考 https://www.cnblogs.com/liudblog/p/11611904.html
//    int left = 1;//最短的重复字串长度是1
//    int right = n - 1;//最长的重复字串长度是n-1
//    int pos = -1;//记录最终结果的起始位置
//    int len = 0;//记录最终结果的长度
//
//    auto find = [&](int len) {//Lambda函数，匿名函数，以引用的形式传入所有外部变量
//        unsigned long long hash = 0;//哈希值，初始为0
//        unsigned long long power = 1;//记录最左边我们要抛弃的字母的权重，也就是解释里面的 a^L（a在这里选的是prime=31）
//        for (int i = 0; i < len; i++) {//初始窗口，从最左边开始，长度为len
//            hash = hash * prime + (s[i] - 'a');//每往后算一位，就相当于前面的哈希值左移1位，变大prime倍，再加上新加入的这一位，
//                                               //比如“ab”的哈希值是0*31^1+1*31^0=1，那么“abc”的哈希值就是 1*31+2=32（0*31^2+1*31^1+2*31^0=32)
//            power *= prime;//a^L就是prime^len,连乘len个prime
//        }
//        unordered_set<unsigned long long> exist{ hash };//哈希表，首先把第一个窗口的哈希值存进去
//        for (int i = len; i < n; i++) {//枚举右边界，抛弃左边界的数，新加入右边界
//            hash = hash * prime - power * (s[i - len] - 'a') + (s[i] - 'a');//这里就是解释里面的 h1 = (h0 * a - c[0] * a ^ L) + c[L]，s[i-len]是我们要抛弃的左边界，s[i]是右边界
//            if (exist.count(hash)) return (i - len + 1);//i-len+1是新的左边界，也就是重复字串的起点，返回
//            exist.insert(hash);//每个窗口的哈希值都要保存
//        }
//        return -1;//否则就不是重复字串，返回-1
//    };
//
//    while (left <= right) {//二分法，
//        int mid = (left + right) / 2;//长度二分
//        int start = find(mid);//返回值是重复串的起始位置
//        if (start != -1) {//如果找到了一个重复串，则起始位置不是-1
//            len = mid;//记录此重复字串的长度
//            pos = start;//记录起始位置
//            left = mid + 1;//这个字串长度不一定是最大的，所以我们继续寻找更大长度的重复字串，在[mid+1,right]的范围里查找
//        }
//        else {//否则这个长度的字串不存在重复字串，长度减小，继续查找，在[left,mid-1]的范围里查找
//            right = mid - 1;
//        }
//    }
//    if (pos == -1) cout << "" << endl;
//    else cout<< s.substr(pos, len)<<endl;
//    return 0;
//}

//////////////////////////////////////////利用双指针来求满足条件的元素个数////////////////////////////////////////

//https://leetcode-cn.com/problems/friends-of-appropriate-ages/solution/gua-ling-de-peng-you-by-leetcode-solutio-v7yk/
//·观察题目中给定的三个条件：
//  ages[y]<=0.5×ages[x] + 7
//  ages[y] > ages[x]
//  ages[y]>100 && ages[x] < 100
//  可以发现，条件 3 是蕴含在条件 2 中的，即如果满足条件 3 那么一定满足条件 2。因此，我们当条件 1 和 2 均不满足时，用户 x 就会向用户 y 发送好友请求，也就是用户 y 需要满足：
//   0.5×ages[x] + 7 < ages[y]<=ages[x]
//·当 ages[x]<=14 时，不存在满足要求的 ages[y]。因此我们只需要考虑 ages[x]>=15 的情况，此时满足要求的ages[y] 的范围为 
//  (0.5×ages[x] + 7, ages[x]](左开右闭）。
//·当 ages[x] 增加时，上述区间的左右边界均单调递增，因此如果我们将数组ages 进行升序排序，那么就可以在遍历 ages[x] 的同时，使用两个指针left 和 right 维护满足要求的左右边界。
//  当 x 向后移动一个位置时：
//  如果左边界指针 left 指向的元素不满足 ages[left] > 0.5×ages[x] + 7，那么就将左边界向后移动一个位置；
//  如果右边界指针 right 指向的下一个元素满足 ages[right + 1]<=ages[x]，那么就将右边界向后移动一个位置。
//  这样一来，[left, right] 就是满足年龄要求的 y 的下标。需要注意的是，x 本身一定在[left, right] 区间内，因此 x 发送的好友请求数，即为[left, right] 区间的长度减去 1。
//int main()
//{
//    vector<int> ages = { 20,30,100,110,120 };
//    int n = ages.size();
//    sort(ages.begin(), ages.end());
//    int left = 0, right = 0, ans = 0;
//    for (int age : ages) {
//        if (age < 15) {
//            continue;
//        }
//        while (ages[left] <= 0.5 * age + 7) {
//            ++left;
//        }
//        while (right + 1 < n && ages[right + 1] <= age) {
//            ++right;
//        }
//        ans += right - left;//原本[left,right]的长度应该是right-left+1，但是要去除x，所以是right-left
//    }
//    cout << ans << endl;
//    return 0;
//}

//////////////////////////////////////////利用整数n各个数位之和来代替n之后能组成递增子序列的最大长度////////////////////////////////////////

//对于n来说，长度越长，拥有的9越多，那么代替之后的数越大，递增子序列的长度越长，比如“9”，能组成的最大长度就是9（[1:9]），“99”能组成的最大长度是18（[1:18]）
//“999”能组成的最大长度是27（[1:27]）
//·当n恰好全是有9组成时（比如“9”，“99”，“999”，“9999”）最大长度就是n的长度*9
//·当n包含其他数字时，首先我们肯定能找到比n短一位并且全是9的数，比如例子中n=“110328219”，长度len为9，那么“99999999”是肯定可以取到的，也就是最大长度最少应该是(len-1)*9
//  其次，我们还可以考虑首位是多大，并且假设一个数字，首位和n相同，后面len-1位全是9，当然这个数可能比n大，没办法取到，因此最后一步
//  我们应该遍历n的除首位之外的所有位，如果发现有比9小的数字，说明我们设想的数无法取到，那只能将首位减一，这样就比n小，并且能取到最大长度，
//  比如例子中我们比如例子中设想的是“199999999”，当然这个数比“110328219”大，没办法取到，那就只能退而求其次，取到“99999999”
//  再比如n=“410328219”，我们设想的是“499999999”，比n大，因此我们应该取“399999999”，最大长度为75
//  再比如n=“599999999”，我们设想的是“599999999”，和n一样大，因此我们就应该取“599999999”，而不是“499999999”，最大长度为77（实际上我们这样设想的目的就是为了这种情况）
//int main()
//{
//    string n = "110328219";
//    int len = n.size();
//    int flag = 1;
//    for (char c : n) {
//        if (c != '9') {
//            flag = false;
//            break;
//        }
//    }
//    if (flag)//全是9，返回len*9
//        return len * 9;
//    int ans = (len - 1) * 9 + n[0] - '0';//设想一个数，当然并不需要实际表示出来，不用怕设想出来的数首位是1的情况，因为这里并不是直接表示出来这个数，而是求和，如果无法取到，直接 ans-1
//                                         //就相当于把首位的1删掉，只剩下后面的 len-1 位9，也就是我们最先找到的比n短一位并且全是9的数。所以不管首位是多少都可以这么做
//    for (int i = 1; i < len; i++) {
//        if (n[i] != '9') {//发现设想的数取不到
//            ans -= 1;
//            break;
//        }
//    }
//    cout << ans << endl;
//}

//////////////////////////////////////////轮流从左右删除某些元素，最后剩下的元素////////////////////////////////////////

//https://leetcode-cn.com/problems/elimination-game/solution/wo-hua-yi-bian-jiu-kan-dong-de-ti-jie-ni-k2uj/
//int main()
//{
//    int n = 10;//[1:n-1]中所有数递增排列
//    int head = 1;//表示从左到右第一个数是多少
//    int step = 1;//表示每隔几个数就删除一个数，注意是每隔几个数，最开始是1，表示第一个数、第三个数、第五个数要被删除
//    bool left = true;//表示是否是从左边开始删除，true表示从左边，false表示从右边
//
//    while (n > 1) {//n表示当前队列中还剩下多少数
//        //从左边开始移除 or（从右边开始移除，数列总数为奇数），从左到右第一个数会发生变化
//        //比如2 4 6 8 10，我们从10开始移除，我们将会移除10，6，2，head被移除并且变为 4
//        //比如 2 4 6 8 10 12，我们从12开始移除，我们将会移除12，8，4，head仍然是 2
//        if (left || n % 2 != 0) {
//            head += step;
//        }
//        step <<= 1; //步长 * 2
//        n >>= 1;  //总数 / 2
//        left = !left; //取反移除方向
//    }
//    cout << head << endl;
//    return 0;
//}

//////////////////////////////////////////约瑟夫环问题////////////////////////////////////////

//int yuesefu(int n, int m) 
//{//从 a 到 1递归
//    if (n == 1) 
//    {
//        return 0; //这里返回下标,从0开始，只有一个元素就是剩余的元素0
//    }
//    else 
//    {//这里的n是本轮中总共多少人，yuesefu(n - 1, m)返回的是最后存活的人在下一轮的编号，这一轮编号=（下一轮编号+ m ）% n
//        //比如当 n = 9，m = 4 时，0 1 2 3 4 5 6 7 8    消去3-->    0 1 2 4 5 6 7 8( 0 1 2)
//        //                对应的下一轮：	                               0 1 2 3 4  5 6 7  
//        //也就是这一轮的 4 =（下一轮的 0 + 4）% 9 = 4，这一轮的 2 =（下一轮的 7+4）% 9 = 2。注意这里的 n一定是这一轮的总人数而不是下一轮的
//        return (yuesefu(n - 1, m) + m) % n; 
//    }
//}
//int main(void) {
//    int a, b;//a个人，编号从0 到 a-1，从 1 喊到 b，喊 b 的人死
//    cin >> a >> b;
//    cout << yuesefu(a, b) << endl;
//
//    //或者，直接循环迭代，求出来的result如上
//    int result = 0;//最后存活的人编号一定是0，所以从0开始
//    for (int i = 2;i <= a;i++) 
//    {//从 1 到 a 迭代，i表示这一轮的总人数，i=1时一定是0，不用管，所以从 2 开始
//        result = (result + b) % i;
//    }
//    cout << "result = " << result << endl;
//    return 0;
//}

//////////////////////////////////////////最大价值的n-k次物品////////////////////////////////////////

//https://www.nowcoder.com/questionTerminal/9a17bac597244027b853a63a25b7b6b7
//·共有n件物品，每件物品价值为w[i]。你共有n次机会，每次可以拿一件物品，但如果你第i次拿的物品价值
//  超过（严格大于）m，则后续的k次机会(即[i+1，i+k])将作废，从第i+k+1次开始才可以继续拿物品。
//  你每次可以拿任意一件物品，现在想知道在此规则下，你能拿到的物品总价值最大是多少？
//·主要思路是贪心，先对物品价值数组排序，记价值小于等于阈值的物品为L，大于阈值的物品为H。
//  把base case规定为把所有L物品都拿了，然后再从高价值到低价值的顺序去拿H物品，看可以拿多少次。
//  接下来弹出一个价值最小的L物品，再去拿H物品，看能否通过弹出一个L物品增加一次拿H物品的机会。
//  遍历完所有的可能性，求出价值总和的最大值就可以了。
//  最终选取的结果一定是类似 AAAAAAAABKBKBKB这样的排列 （A代表小于m的物品，B代表大于m的物品，K代表K次间隔）
//typedef long long ll;
//int main()
//{
//    int n=5, k=2, m=10;
//    vector<ll> p, q;
//    vector<int> w={5,8,10,15,33};
//    for (int i = 0; i < n; ++i)
//    {
//        if (w[i] <= m) 
//            p.emplace_back(w[i]);//小于m的物品放在p里面
//        else 
//            q.emplace_back(w[i]);//大于m的物品放在q里面
//    }
//    sort(p.begin(), p.end(), greater<int>());//从大到小排序
//    sort(q.begin(), q.end(), greater<int>());//从大到小排序
//    int n1 = p.size(), n2 = q.size();
//    for (int i = 1; i < n1; ++i) 
//        p[i] += p[i - 1];//之前已经排序了，所以前缀和就代表着拿价值最大的几件物品
//    for (int i = 1; i < n2; ++i)
//        q[i] += q[i - 1];
//    ll res = 0;
//    if (!p.empty()) //小于m的物品全拿，p已经是前缀和数组了，所以p.back()表示全部的物品价值，如果全是大于m的，那么就相当于没有A，只有B和K
//        res = p.back();
//    for (int i = 0; i < n2; ++i)
//    {//从大于m的里面价值最大的开始拿
//        int left = n - i * (k + 1) - 1;//left表示拿完[0:i]这几件价值最大的B物品后，除开需要的间隔K，还剩下多少次机会去拿A，比如当i=0时， left=4，
//                                       //因为总共五次机会，我们可以在最后一次（第五次）才去拿q[0]这件物品（反正是最后一次了，不用在乎需不需要间隔了）
//                                       //然后前 4 次机会我们可以用来拿A（当然A的数量可能没有left多，所以下面我们有一个min保证拿最少的）
//                                       //再比如 i=1时，left=1，表示我们可以在第 2 次的时候拿q[0]或q[1]，然后第3、4次机会浪费，第 5 次拿q[0]或q[1]（反正有两次机会，任意顺序都可以）
//                                       //那么我们就只剩下第 1 次机会去拿A了，所以left=1。
//        if (left <= 0) 
//            break;//如果left小于等于0，说明我们没有机会拿A了，直接退出
//        ll d = q[i];//注意q已经是前缀和数组了，所以这里就相当于把q的[0:i]件物品全都拿了，总价值为d
//        left = min(left, n1);//要保证拿A的机会不多于A的数量
//        d += p[left - 1];//拿A的前 i 件物品，也就是p的[0:left-1]，这里的left>=1，p是前缀和数组
//        res = max(res, d);//记录总价值最大值
//    }
//    cout << res << endl;
//    return 0;
//}

//////////////////////////////////////////基类和子类指针的转换和虚函数、普通函数调用////////////////////////////////////////

//class base
//{
//public:
//    virtual void virtual_fun()
//    {
//        cout << "base" << endl;
//    }
//
//    void normal__base_fun()
//    {
//        cout << "base" << endl;
//    }
//};
//class derived :public base
//{
//public:
//    virtual void virtual_fun()
//    {
//        cout << "derived" << endl;
//    }
//
//    void normal_derived_fun()
//    {
//        cout << "derived" << endl;
//    }
//
//};
//
//
//int main()
//{
//    base* cp = (base*)new derived;
//    cp->virtual_fun();
//    cp->normal__base_fun();
//    //cp->normal_derived_fun();//ERROR，基类指针不能直接调用 子类有但是基类没有 的函数（除了虚函数）
//    cout << "-------------------" << endl;
//    derived* dp = (derived*)new base;
//    dp->virtual_fun();
//    dp->normal_derived_fun();
//    dp->normal__base_fun();//正确，子类继承基类，可以调用函数（除了private成员）
//    cout << "-------------------" << endl;
//    base* ep = new base;
//    ep->virtual_fun();
//    ep->normal__base_fun();
//    //ep->normal_derived_fun();//ERROR，ep是base类型的指针，基类指针不能直接调用 子类有但是基类没有 的函数（除了虚函数）
//    cout << "-------------------" << endl;
//    derived* fp = new derived;
//    fp->virtual_fun();
//    fp->normal_derived_fun();
//    fp->normal__base_fun();//正确，fp是子类指针，子类继承基类，可以调用函数（除了private成员）
//    return 0;
//}

//////////////////////////////////////////基类和子类指针的转换和成员变量访问////////////////////////////////////////

//总结一下：编译器通过 指针 来访问 成员变量，指针指向哪个对象就使用哪个对象的数据；编译器通过指针的类型来访问成员函数，指针属于哪个类的类型就使用哪个类的函数。（针对非虚函数！）
//通过基类的对象、指针、引用只能访问从基类继承过去的成员(包括成员变量和成员函数)，不能访问派生类新增的成员。
//通过基类的引用或指针，调用基类 / 派生类的虚函数，要根据运行时根据指针或引用实际指向或引用的类型确定，调用非虚函数时，则无论基类指向的是何种类型，都调用基类的函数
//基类A
//class A {
//public:
//    A(int a);
//public:
//    void display();
//protected:
//    int m_a;
//};
//A::A(int a) : m_a(a) { }
//void A::display() {
//    cout << "Class A: m_a=" << m_a << endl;
//}
////中间派生类B，继承A
//class B : public A {
//public:
//    B(int a, int b);
//public:
//    void display();
//protected:
//    int m_b;
//};
//B::B(int a, int b) : A(a), m_b(b) { }
//void B::display() {
//    cout << "Class B: m_a=" << m_a << ", m_b=" << m_b << endl;
//}
////基类C
//class C {
//public:
//    C(int c);
//public:
//    void display();
//protected:
//    int m_c;
//};
//C::C(int c) : m_c(c) { }
//void C::display() {
//    cout << "Class C: m_c=" << m_c << endl;
//}
////最终派生类D，继承B,C
//class D : public B, public C {
//public:
//    D(int a, int b, int c, int d);
//public:
//    void display();
//private:
//    int m_d;
//};
//D::D(int a, int b, int c, int d) : B(a, b), C(c), m_d(d) { }
//void D::display() {
//    cout << "Class D: m_a=" << m_a << ", m_b=" << m_b << ", m_c=" << m_c << ", m_d=" << m_d << endl;
//}
//int main() {
//    A* pa = new A(1);
//    B* pb = new B(2, 20);
//    C* pc = new C(3);
//    D* pd = new D(4, 40, 400, 4000);
//
//    cout << "-------更改前-----" << endl;
//    pa->display();//尽管在D构造的时候更新了m_a的值，但其实只是把D内存空间里的m_a赋值为4，A内存空间里的m_a任然是 1
//    pb->display();//同理
//    pc->display();
//    pd->display();
//    cout << "-----------------------" << endl;
//
//    cout << "--------更改后-----------" << endl;
//
//    pa = pd;//向上类型转换，只能访问基类已有的成员变量和函数，如果是同名的非虚函数，必定是访问基类里的函数，因为基类不包含子类里的变量，因此调用子类函数的话无法确定子类变量的值
//    pa->display();
//
//    pa = pb;
//    pb->display();//调用子类中的函数
//    pa->display();//调用基类中的函数，实际指向的是B的内存空间，所以读取的变量值是B内存空间里的m_a=2，和原始的A内存空间里的m_a=1值不相同
//
//    pb = pd;
//    pb->display();
//
//    pc = pd;
//    pc->display();
//
//    pd->display();
//    cout << "-----------------------" << endl;
//    return 0;
//}

//////////////////////////////////////////虚函数指针和虚函数表中的函数地址////////////////////////////////////////

//https://zhuanlan.zhihu.com/p/98776075
//class A {
//public:
//    virtual void vfunc1() {};
//    virtual void vfunc2() {};
//    void func1() {};
//    void func2() {};
//private:
//    int m_data1, m_data2;
//};
//
//class B : public A {
//public:
//    virtual void vfunc1() {};
//    void func2() {};
//private:
//    int m_data3;
//};
//
//class C : public B {
//public:
//    virtual void vfunc1() {};
//    void func2() {};
//private:
//    int m_data1, m_data4;
//};
//template<typename dst_type, typename src_type>
//dst_type pointer_cast(src_type src)
//{
//    return *static_cast<dst_type*>(static_cast<void*>(&src));
//}
//int main()
//{
//    A a;
//    B b;
//    C c;
//    void* p1 = pointer_cast<void*>(&A::vfunc1);
//    void* p2 = pointer_cast<void*>(&A::vfunc2);
//    void* p3 = pointer_cast<void*>(&B::vfunc1);
//    void* p4 = pointer_cast<void*>(&B::vfunc2);
//    void* p5 = pointer_cast<void*>(&C::vfunc1);
//    void* p6 = pointer_cast<void*>(&C::vfunc2);
//    cout << "A中虚函数vfunc1的地址：" << p1 << endl;
//    cout << "A中虚函数vfunc2的地址：" << p2 << endl;
//    cout << "B中虚函数vfunc1的地址：" << p3 << endl;
//    cout << "B中虚函数vfunc2的地址：" << p4 << endl;
//    cout << "C中虚函数vfunc1的地址：" << p5 << endl;
//    cout << "C中虚函数vfunc2的地址：" << p6 << endl;
//}

//////////////////////////////////////////在超大迷宫里是否能到达目的地////////////////////////////////////////

//https://leetcode-cn.com/problems/escape-a-large-maze/solution/gong-shui-san-xie-bfs-gei-ding-zhang-ai-8w63o/
//从 s 跑一遍 BFS，然后从 t 跑一遍 BFS，同时设定一个最大访问点数量 MAX，若从两者出发能够访问的点数量都能超过 MAX，说明两点均没有被围住，最终必然会联通
//现在我们用在当障碍的块数量是确定的（block.size()），如果障碍块能围成封闭区域，那么这块区域的面积最大值 就是 blocked.size() * (blocked.size() - 1) / 2;
//证明参考 https://leetcode-cn.com/problems/escape-a-large-maze/solution/gong-shui-san-xie-bfs-gei-ding-zhang-ai-8w63o/
//就是当障碍块的数量是确定的时候，只有利用两条边界才能得到最大的封闭区域面积，
//class Solution {
//public:
//    vector<pair<int, int>> dic = { {1,0},{-1,0},{0,1},{0,-1} };
//    unordered_set<long long> uset;//存放阻塞坐标
//
//    int limit;//存放搜索上界
//    int n = 1e6;
//    bool isValid(const vector<int>& source, const vector<int>& target)
//    {
//        unordered_set<long long> vis;//存放已访问过的坐标
//        queue<pair<int, int>> q;
//        int cnt = 0;//记录已经访问过了多少个坐标
//        q.push(make_pair(source[0], source[1]));
//        vis.insert((long long)source[0] * n + source[1]);
//        while (!q.empty() && cnt <= limit)
//        {//BFS遍历
//            auto t = q.front();
//            q.pop();
//            for (int i = 0;i < dic.size();i++)
//            {
//                int new_x = t.first + dic[i].first;
//                int new_y = t.second + dic[i].second;
//                if (new_x == target[0] && new_y == target[1])
//                {//已经到达目的坐标，返回true
//                    return true;
//                }
//                else if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && uset.count((long long)new_x * n + new_y) == 0 && vis.count((long long)new_x * n + new_y) == 0)
//                {
//                    cnt++;
//                    q.push(make_pair(new_x, new_y));
//                    vis.insert((long long)new_x * n + new_y);
//                }
//            }
//        }
//        if (q.empty() && cnt <= limit)
//        {//limit表示最多能访问多少坐标，q先为空的时候说明blocks围成的区域没有达到最大，但仍然是个封闭区域，返回false
//            return false;
//        }
//        return true;//能访问的坐标cnt大于了limit，说明block没有围成封闭区域（因为最大封闭区域的面积是limit）返回true
//    }
//    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
//        for (auto i : blocked)
//        {
//            uset.insert((long long)i[0] * n + i[1]);
//        }
//        limit = blocked.size() * (blocked.size() - 1) / 2;
//        return isValid(source, target) && isValid(target, source);//从s跑一遍DFS，再从t跑一遍DFS，如果都返回true，说明s和t都没有被包围，则它们是联通的
//    }
//};
//int main()
//{
//    Solution so;
//    vector<vector<int>> blocked = { {0, 1},{1, 0} };
//    vector<int> source = { 0, 0 }, target = { 0, 2 };
//    cout<<so.isEscapePossible(blocked,source,target);
//}

//////////////////////////////////////////字符串中的数是否等于它之前两个数相加的和////////////////////////////////////////

//https://leetcode-cn.com/problems/additive-number/solution/gong-shui-san-xie-hui-su-gao-jing-du-jia-6o6b/1324548
//高精度加法，倒序储存如：
//315（三百一十五）->[5,1,3]
//bool check(vector<int>& a, vector<int>& b, vector<int>& c) {
//    vector<int> sum;
//    int m = a.size(), n = b.size(), carry = 0;
//    //模拟进位加法
//    for (int i = 0; i < m || i < n || carry != 0; i++) {
//        if (i < m) carry += a[i];
//        if (i < n) carry += b[i];
//        sum.push_back(carry % 10);
//        carry /= 10;
//    }
//    bool ok = c.size() == sum.size();
//    for (int i = 0; i < c.size() && ok; i++) {
//        if (c[i] != sum[i]) return false;
//    }
//    return ok;
//}
//bool dfs(string num,int n,vector<vector<int>>& list,int u) {//dfs回溯函数，u是表示从第几个字符开始分割数字数
//    int m = list.size();//m表示现在已经确定的数字数量
//    //递归出口，当u已经遍历到字符串末尾n，判断是不是至少有3个数，少于3个数一定不是等式
//    if (u == n) return m >= 3;
//    //max为这次递归遍历的最大范围，若当前u不为0，一直爆搜到结尾n，不然就只能单个0
//    int max = num[u] == '0' ? u + 1 : n;
//    //用于储存一个整数，便于之后高精度加法
//    vector<int> cur;
//    //开始从u到max进行遍历
//    for (int i = u; i < max; i++) {
//        //倒序插入每一位，因为num从左到右遍历是从高位到低位，而模拟加法的时候高位要放在cur的右边，所以右边的低位要插入，其实用deque更方便一点
//        cur.insert(cur.begin(), num[i] - '0');
//        //list不足2个或符合累加则进入递归
//        if (m < 2 || check(list[m - 2], list[m - 1], cur)) {
//            //回溯
//            list.push_back(cur);
//            if (dfs(num,n,list,i + 1)) return true;
//            list.pop_back();
//        }
//    }
//    //全都不符合返回false
//    return false;
//}
//int main()
//{
//    string num = "112358";
//    vector<vector<int>> list;
//    cout << dfs(num, num.size(),list,0);
//}

//////////////////////////////////////////根据指令建二叉树并查找“樱桃串”////////////////////////////////////////

//bool buildtree(TreeNode* node, int tmp, string s, int ch)
//{
//    if (node->val == tmp)
//    {
//        if (s == "left")
//        {
//            node->left = new TreeNode(ch);
//            return true;
//        }
//        else
//        {
//            node->right = new TreeNode(ch);
//            return true;
//        }
//    }
//    else
//    {
//        if (node->left)
//        {
//            if (buildtree(node->left, tmp, s, ch))
//            {
//                return true;
//            }
//        }
//        if (node->right)
//        {
//            if (buildtree(node->right, tmp, s, ch))
//            {
//                return true;
//            }
//        }
//    }
//    return false;
//}
//int cnt(TreeNode* node)
//{
//    if (node->left && node->right && !node->left->left && !node->left->right && !node->right->left && !node->right->right)
//    {
//        return 1;
//    }
//    else if (!node->left && !node->right)
//    {
//        return 0;
//    }
//    int le = 0, ri = 0;
//    if (node->left)
//    {
//        le = cnt(node->left);
//    }
//    if (node->right)
//    {
//        ri = cnt(node->right);
//    }
//    return le + ri;
//}
//int main()
//{
//    ios::sync_with_stdio(0);
//    int m, n;//m是结点个数，n是边的个数
//    cin >> m >> n;
//    TreeNode* root = new TreeNode(1);
//    while (n--)
//    {
//        int tmp, ch = 0;
//        string s;
//        cin >> tmp >> s >> ch;
//        buildtree(root, tmp, s, ch);
//    }
//    int res = cnt(root);
//    cout << res << endl;
//    return 0;
//}

//////////////////////////////////////////多路归并排序(找到二维矩阵第k小的数）////////////////////////////////////////

//https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/solution/shi-yong-dui-heapde-si-lu-xiang-jie-ling-fu-python/
//·在整个矩阵中，每次弹出矩阵中最小的值，第k个被弹出的就是我们需要的数字。
//·现在我们的目的很明确：每次弹出矩阵中最小的值。
//  当我们看到下面这个有序矩阵时，我们知道左上角的数字是整个矩阵最小的，
//  但弹出它后我们如何保证接下来每一次都还能找到全矩阵最小的值呢？
//·其实解决这个问题的关键，在于维护一组“最小值候选人”：
//  你需要保证最小值必然从这组候选人中产生，于是每次只要从候选人中弹出最小的一个即可。
//  我们来选择第一组候选人，在这里可以选择第一列，因为每一个数字都是其对应行的最小值，全局最小值也必然在其中。
//  我们每次弹出候选人当中的最小值，然后把上次弹出候选人的右边一个补进来，就能一直保证全局最小值在候选人列表中产生，
//typedef pair<int, int> pii;
//int main()
//{
//    vector<vector<int>> matrix = { {1, 5, 9},{10, 11, 13},{12, 13, 15} };
//    int k = 8;
//    auto cmp = [&](const pii& a, const pii& b)//利用匿名函数自定义排序比较方便，因为在优先队列中存的是
//                                              //坐标，后面操作也是坐标，如果是自定义函数或重载与运算符
//                                              //的话，就需要存坐标对应的值，但是在后续操作的过程中
//                                              //无法把值还原成坐标并右移，这在多路归并一类题中非常重要
//    {
//        return matrix[a.first][a.second] > matrix[b.first][b.second];
//    };
//    priority_queue<pii, vector<pii>, decltype(cmp)> q(cmp);
//    //优先队列第三个参数是类（class），而匿名函数不是类，lambda表达式实际上是一个未命名对象，而不是类,decltype(cmp)可以认为是
//    //确定lambda表达式的返回值类型
//    int m = matrix.size(), n = matrix[0].size();
//    for (int i = 0;i < m;i++)
//    {
//        q.push(make_pair(i, 0));//第一列存入，第一组候选值
//    }
//    while (--k)//弹出k-1个最小值
//    {
//        auto t = q.top();
//        q.pop();
//        if (t.second < n - 1)
//        {
//            q.push(make_pair(t.first, t.second + 1));
//        }
//    }
//    cout << matrix[q.top().first][q.top().second] << endl;//此时最前端就是第k个最小值
//    return 0;
//}

//////////////////////////////////////////二分查找（找到二维矩阵第k小的数）////////////////////////////////////////

//https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/solution/you-xu-ju-zhen-zhong-di-kxiao-de-yuan-su-by-leetco/
//核心思想是以mid为界限，把matrix分成左边和右边两部分，左边都是小于等于mid的元素，右边都是大于mid的元素，初始上下界分别是
//左上角（最小）和右下角（最大），不断调整mid的大小来找到一个mid成为第k小的元素。
//那么如何调整mid呢？
//·每确定一个mid都可以确定小于等于mid的元素有多少个（也就是左边部分的元素个数），假设为 n，如果n<k,也就是小于等于mid的元素
//  个数不足k个，那么mid一定不可能是第k小的元素（此时的mid最多只可能是第k-1小的元素，比如在mid=2，在1,2,3,4中找第3小的元素
//  此时小于等于mid的元素个数为2,n=2<k=3，mid只是第2小的元素），因此mid应该更大点，所以left=mid+1；如果n>=k，也就是
//  小于等于mid的元素个数多于k，那么mid至少是第k小的元素（有可能是第k+1，k+2...），为了缩小范围，mid应该小一点，所以right=mid（
//  需要保留mid，因为此时的mid有可能是第k小的值）。如此这般，最后我们找到了一个mid，保证小于等于mid的n=k，而小于等于mid-1的n<k
//  而小于等于mid+1的n>=k（因为mid+1不一定在矩阵中，所以小于等于它的元素个数是>=k）。这样就找到了第k小的元素。
//如何保证最后找到的left或者说right存在于矩阵中？
//·首先，矩阵中肯定存在第k小的元素，也就是说肯定存在a，保证小于等于a的n=k，而小于等于a-1的n<k。而小于等于a+1的n>=k、
//  如果我们找到了一个b满足上述条件，那么b肯定大于等于a（小于a不可能满足上述条件），而大于a的话肯定会进入下一循环，最终找到的
//  b=a。参考 https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/solution/ci-ti-er-fen-cha-zhao-guo-cheng-de-dong-tu-yan-shi/
//bool check(vector<vector<int>>& matrix, int mid, int k, int n) {//用来计算小于等于mid的元素个数n
//    int i = n - 1;
//    int j = 0;
//    int num = 0;
//    while (i >= 0 && j < n) {
//        if (matrix[i][j] <= mid) {
//            num += i + 1;
//            j++;
//        }
//        else {
//            i--;
//        }
//    }
//    return num >= k;
//}
//int main()
//{
//    vector<vector<int>> matrix= { {1, 5, 9},{10, 11, 13},{12, 13, 15} };
//    int k = 8;
//    int n = matrix.size();
//    int left = matrix[0][0];
//    int right = matrix[n - 1][n - 1];
//    int ans;
//    while (left <= right) {
//        int mid = left + ((right - left) >> 1);
//        if (check(matrix, mid, k, n)) {
//            ans=mid;
//            right = mid - 1;
//        }
//        else {
//            left = mid + 1;
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}

//////////////////////////////////////////输入多组特征值并输出特征值的任意组合////////////////////////////////////////

//void dfs(int index, int n, const vector<vector<string>>& v, vector<string> path)
//{
//    if (index == -1)
//    {
//        for (int i = n - 1;i > 0;i--)
//        {
//            cout << path[i] << '-';
//        }
//        cout << path.front() << endl;
//        return;
//    }
//    for (int j = 0;j < (int)v[index].size();j++)
//    {
//        path.emplace_back(v[index][j]);
//        dfs(index - 1, n, v, path);
//        path.pop_back();
//    }
//}
//int main()
//{
//    ios::sync_with_stdio(0);
//    int n;
//    cin >> n;
//    cin.ignore();//很重要，这是因为输入数字之后，敲回车，产生的换行符仍然滞留在输入流了，接着就被getline(cin,s)给读进去了，
                   //下面的s就是一个换行符，造成输入错误，所以需要删除这个换行符
//    vector<vector<string>> v;
//    string s;
//    for (int i = 0;i < n;i++)
//    {
//        getline(cin, s);
//        stringstream ss(s);
//        string stmp;
//        vector<string> vtmp;
//        while (ss >> stmp)
//        {
//            vtmp.emplace_back(stmp);
//        }
//        v.emplace_back(vtmp);
//    }
//    vector<string> path;
//    dfs(n-1, n, v, path);
//    return 0;
//}

//////////////////////////////////////////可被三整除的子序列最大和////////////////////////////////////////

//https://leetcode-cn.com/problems/greatest-sum-divisible-by-three/solution/dong-tai-gui-hua-yu-zhuang-tai-zhuan-yi-by-christm/
//int main()
//{
//    vector<int> nums = { 3,6,5,1,8 };
//    int n = nums.size();
//    //dp[i][j]表示到nums的第i个数为止，子序列之和 mod 3 余j的最大值（是和的最大值，并且这个和要 mod 3 余 j）
//    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
//    //dp[0][0]表示没有子序列之和时（也就是和为0） 和 mod 3 余0，最大值是0，因此初始化为0
//    //dp[0][1]表示没有子序列之和时（也就是和为0） 和 mod 3 余1，此时不成立，为了不影响后续的值，要初始化为INT_MIN,，如果初始化为0，则会出现错误
//    //参考 https://leetcode-cn.com/problems/greatest-sum-divisible-by-three/solution/dong-tai-gui-hua-yu-zhuang-tai-zhuan-yi-by-christm/560980
//    //比如当i=1时，nums[i-1]= 3 % 3 =0，此时应当只有dp[1][0]=3,但是错误的更新为dp[1][0]=dp[1][1]=dp[1][2]=3,后两者不符合定义，会影响后续计算
//    //·当i=2时，nums[i-1]= 6 % 3 =0，此时应当只有dp[2][0]=9,但是错误的更新为dp[2][0]=dp[2][1]=dp[2][2]=9,后两者不符合定义，会影响后续计算
//    //·当i=3时，nums[i-1]= 5 % 3 =2，此时dp[3][0]=9,dp[3][2]=14，但是错误的更新为dp[3][0]=dp[3][1]=dp[3][2]=14，因为上一轮的dp[2][1]=9,导致dp[3][0]=14，上一轮的dp[2][2]=9，导致dp[3][1]=14，错误结果
//    dp[0][1] = INT_MIN;
//    dp[0][2] = INT_MIN;
//    for (int i = 1;i <= n;i++)
//    {
//        //如果这个数mod 3 余 0，那么三个和都可以直接加上这个数
//        if (nums[i - 1] % 3 == 0)
//        {
//            dp[i][0] = dp[i - 1][0] + nums[i - 1];
//            dp[i][1] = dp[i - 1][1] + nums[i - 1];
//            dp[i][2] = dp[i - 1][2] + nums[i - 1];
//        }
//        //如果这个数mod 3 余 1，那么此时余0的和就应该是上一层余0的和与上一层余2的和加上这个数的最大值
//        //（上一层余2 加上 这一层余1 就成了 余0）其他的同理
//        else if (nums[i - 1] % 3 == 1)
//        {
//            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] + nums[i - 1]);
//            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + nums[i - 1]);
//            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + nums[i - 1]);
//        }
//        else if (nums[i - 1] % 3 == 2)
//        {
//            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + nums[i - 1]);
//            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2] + nums[i - 1]);
//            dp[i][2] = max(dp[i - 1][2], dp[i - 1][0] + nums[i - 1]);
//        }
//    }
//    return dp[n][0];
//}

//////////////////////////////////////////替换数组中的0构成递增数组的方案个数////////////////////////////////////////

//https://www.nowcoder.com/questionTerminal/3e34d9ed0bbc4db68b6fbca20a62926d?answerType=1&f=discussion
//int main()
//{
//    vector<int> a = { 0,0,0,0,0,67,0,0 };//替换其中的0构成递增数组（不是严格递增）
//    int k = 100;//数组中的数不能大于k
//    int n = a.size();
//    //dp[i][j]表示用j个数去填充i个位置，构成递增数组的方案个数（j个数是指1,2,3,4,...j，也就是最大值为j）
//    vector<vector<int> > dp(n + 1, vector<int>(k + 1));
//    for (int j = 0; j <= k; ++j)//用j个数去填充0个位置，自然只有0种方案
//        dp[0][j] = 0;
//    for (int i = 0; i <= n; ++i)//用0个数去填充i个位置，自然只有0种方案
//        dp[i][0] = 0;
//    for (int j = 1; j <= k; ++j)//用j个数去填充1个位置，自然只有j种方案
//        dp[1][j] = j;
//    //用j个数去填充i个位置，就等于在第i个位置上放1,2,3，...j，那么前i-1个位置上只能放小于等于这个数（假设为k）的值，才能构成
//    //递增数组，比如k=1，那么前i-1个位置上只能放1，也就是dp[i-1][1]，k=2，那么前i-1个位置上只能放1和2，也就是dp[i-1][2]
//    //以此类推，dp[i][j]=∑dp[i-1][k]（k=[1:j]），展开后就等于dp[i][j-1]+dp[i-1][j]
//    //比如，用5个数（1,2,3,4,5）去填充4个位置，就等于用1个数去填充前3个位置（第四个位置填 1 ），加上用 2 个数去填充前3个位置（第四个位置填 2 ），加上用 3 个数去填充前3个位置（第四个位置填 3 ）
//    // 加上用 4 个数去填充前3个位置（第四个位置填 4 ），加上用 5 个数去填充前3个位置（第四个位置填 5 ）
//    for (int i = 2; i <= n; ++i)
//        for (int j = 1; j <= k; ++j)
//            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
//    int i = 0;
//    int ans = 1;
//    while (i < n) {//接下来计算需要填充的长度end-start和能用的数high-low
//        while (i < n && a[i] != 0)//首先找到连续0的开端，也就是start
//            ++i;
//        if (i == n)//i=n表示所有数都填充完毕了，退出程序
//            break;
//        int start = i;
//        int low = (i > 0 ? a[i - 1] : 1);//如果第一个数就是0，那么low就是1，反之应该是下界a[i-1]，因为此时a[i]=0，a[i-1]不为0
//        while (i < n && a[i] == 0)//找到连续0的末尾，也就是end
//            ++i;
//        int end = i;
//        int high = (i < n ? a[i] : k);//如果最后一个数是0，那么high就是k，反之应该是上界a[i]，因为此时a[i]！=0
//        ans = ((long long)ans * dp[end - start][high - low + 1]) % MOD;
//    }
//}

//////////////////////////////////////////挑石子游戏（博弈论）////////////////////////////////////////

//https://leetcode-cn.com/problems/stone-game-ix/solution/nick-mei-tian-jin-lai-li-jie-juan-yi-dia-0f2k/
//Alice 和 Bob 轮流进行自己的回合，Alice 先手。每一回合，玩家需要从 stones 中移除任一石子。
//·如果玩家移除石子后，导致 所有已移除石子 的价值 总和 可以被 3 整除，那么该玩家就 输掉游戏 。
//·如果不满足上一条，且移除后没有任何剩余的石子，那么 Bob 将会直接获胜（即便是在 Alice 的回合）
//我们穷举出Alice能赢的情况~因为Alice先手，两人都是最优选择！
//·先考虑0是偶数，说明两者可以互相选择0，不改变原结果~
//  ① 先选 1（因为最优选择，肯定不会先选0，除非只有0则Bob直接获胜），Bob只能跟选1（2 肯定是不能选的，如果选 0 的话Alice也可以跟选 0 ，由于 0 是偶数，那么最终 0 取完了还是会回到Alice只选了 1 这个场景下）
//  ===> 那么情形就是 1 (1 2 1 2 ... 1 2) 2 2 2 2 如果最后只要剩下 2（剩下 1 个都可以），Bob只能选 2，那么Alice赢
//  ② 先选 2 ，Bob只能也跟选 2
//  ===> 那么情形就是 2 (2 1 2 1 ... 2 1) 1 1 1 1 如果最后只要剩下 1（剩下 1 个都可以），Bob只能选 1，那么Alice赢
//  通过①和②，0为偶数的情况下，总的来说 1 和 2 哪个数较少就Alice先选择哪个数能保证一定能赢！（相等的话也一定能赢，开始随便选一个就行），也就是说，只要 1 和 2 同时存在，不管数量关系是多少，Alice都会赢
//·③ 在①和②的基础上 如果加上一个0（因为奇数个0完全等于只有一个0）
//  == = > 1 (1 2 1 2 ... 1 2) 只要后面有(0, 1, 1, 1...)供选择，那么Bob有两种选择（0或1）
//    ·B选 0 A选 1 B只能选 1 所以A赢
//    ·B选 1 A选 0 B也只能再选 1 A还是会赢
//      == = > 2 (2 1 2 1 ... 2 1) 只要后面有(0, 2, 2, 2...)供选择，同理A也会赢！
//  通过③，0为奇数的情况，总的来说，只要存在1 2 两类数量差至少为3，Alcie选择多的那么数就一定会赢！
//·为什么需要大3，以 1 ( 1 2 1 2 1 2 ...)0 1 1 1 为例，首先最开始多了一个1。然后最后不能只有 0 1 两个数，此时会出现石子被取完的情况，无论怎样都是 Bob 赢，
//  所以至少应该是 0 1 1 以上，这样就至少多了3个1。对于2的情况同理。
//int main()
//{
//    vector<int> stones = { 5,1,2,4,3 };
//    int temp[3] = { 0 };
//    for (int stone : stones) {
//        temp[stone % 3] ++;
//    }
//    if (temp[0] % 2 == 0) {
//    //0为偶数，只要 1 2两类数都同时存在那么Alice一定会赢，只要选择较少的那个，如果两类一样后选的人一定会输
//        if (temp[1] > 0 && temp[2] > 0)
//        {
//            cout << "Alice Win" << endl;
//            return 0;
//        }
//    }
//    else
//    // 0为奇数 只要存在1 2 两类数量差至少为3，Alcie选择多的那类数就一定会赢！
//    {
//        if (abs(temp[1] - temp[2]) > 2)
//        {
//            cout << "Alice Win" << endl;
//            return 0;
//        }
//        else
//        //除了以上几种情况，Bob就会赢！
//        {
//            cout << "Bob Win" << endl;
//            return 0;
//        }
//    }
//}

//////////////////////////////////////////Dijkstra最短路径算法（朴素算法-邻接矩阵）////////////////////////////////////////

//https://leetcode-cn.com/problems/network-delay-time/solution/gtalgorithm-dan-yuan-zui-duan-lu-chi-tou-w3zc/
//用于求解从任意点出发遍历完所有节点所耗费的最短/最长路程（或时间）
//const int inf = 0x3f3f3f3f;//表示两个节点之间没有直连的边
//int main()
//{
//    vector<vector<int>> times = { {0,1,5},{0,2,2},{0,3,6},{1,4,1},{2,4,5},{2,3,3},{2,1,1}, {3,4,2} };//直连的节点（有向图）
//    int n = 5;//节点总数
//    int k = 0;//起点
//    vector<vector<int>> edges(n, vector<int>(n, inf));//保存各个边，这里是有向的，也可以是无向的
//    vector<int> disc(n, inf);//记录起点到其他节点的距离
//    vector<int> vis(n, 0);//记录该节点是否访问过，一般来说只需要访问一次，已访问过就代表初始节点到这个节点的最短距离已经找到了
//    for (int i = 0;i < times.size();i++)
//    {
//        edges[times[i][0]][times[i][1]] = times[i][2];
//    }
//    disc[k] = 0;//初始节点到初始节点的距离为0
//    for (int i = 0;i < n;i++)//每次循环都要找到当前的disc中最短的距离，以他为中转点来计算
//    {
//        int x = -1;
//        for (int j = 0;j < n;j++)
//        {
//            if (vis[j] == 0 && (x == -1 || disc[j] < disc[x]))//该节点必须没有访问过，且距离最短
//            {
//                x = j;
//            }
//        }
//        vis[x] = 1;//访问该节点
//        for (int j = 0;j < n;j++)
//        {
//            disc[j] = min(disc[j], disc[x] + edges[x][j]);//以x为中转点来计算其他节点的最短路径
//        }
//    }
//    cout << (*max_element(disc.begin(), disc.end()) == inf ? -1 : *max_element(disc.begin(), disc.end()))<< endl;
//}

//////////////////////////////////////////Dijkstra最短路径算法（堆优化算法-邻接表）////////////////////////////////////////

//typedef pair<int, int> PII;
//const int N = 1e5 + 10, M=1e6;//N至少是结点总数，M至少是边总数
//int n, m;//图中的节点总数和边总数，N>=n+1,M>=m
////·h代表head，描述节点，存储是某个节点所对应的边的集合的头结点，所以它跟N有关；
////·e,ne,w都是描述边的，分别代表end，next，weight，e存储某一条边指向的节点；ne存储同一起始节点上的下一条边；w存储边的权值
////·对每一条边编号，idx从0开始，
//int h[N], w[M], e[M], ne[M], idx;
//int dist[N];//节点之间的距离
//bool vis[N];//是否访问过该节点
//void add(int a, int b, int c)
//{//存入边和节点
//    e[idx] = b;//编号为idx的边指向b节点
//    w[idx] = c;//编号为idx的边权重为c
//    ne[idx] = h[a];//编号为idx的边，与它同一起始节点a的下一条边是h[a]，h[a]首先要初始化为-1，然后逆向建立链表，也就是首先建立尾部，有新的边就放到尾部的前面
//    h[a] = idx++;//现在编号为idx的边是新的头结点了，同时idx这条边的所有信息记录完毕，记录下一条边idx++
//}
//int dijkstra(int start,int end)
//{
//    memset(dist, 0x3f, sizeof(dist));//初始化,memset按字节操作，0x3f是8位bit，正好一个字节，把dist的所有字节全都填充为0x3f
//    dist[start] = 0;//start到自己的距离为0
//    priority_queue<PII, vector<PII>, greater<PII>> heap;//小根堆
//    heap.push({ 0, start });//第一个参数是距离，第二个参数是编号
//    //　注意这里vis[start]不能置成true，这样在下面的循环内，start点就不能拓展，所以我们总是在拿出的时候将vis置成true
//    while (heap.size())
//    {
//        PII t = heap.top();
//        heap.pop();
//        int ver = t.second, distance = t.first;//ver是当前距离start最近的点，distance是距离
//        if (ver == end)
//        {//如果已经找到目标节点，直接返回距离
//            return distance;
//        }
//        if (vis[ver]) 
//            continue;//如果已经访问过就跳过
//        vis[ver] = true;//访问此节点
//        for (int i = h[ver]; i != -1; i = ne[i])
//        {//访问ver节点的每条边，i代表与ver节点相连的边，从第一条边h[ver]开始，到-1结束（边序号是从0到m，所以-1就代表边已经遍历完了），每次更新为下一条边
//            int j = e[i];//编号为i指向的节点为j
//            if (dist[j] > distance + w[i])
//            {//如果start到ver节点的距离distance加上ver到j节点的距离小于原本start到j节点的距离的话
//                dist[j] = distance + w[i];//更新距离表
//                heap.push({ dist[j], j });//j可能是下一个最近的节点，加入优先队列排序
//            }
//        }
//    }
//
//    if (dist[end] == 0x3f3f3f3f) return -1;//不可达，返回-1
//    return dist[end];//返回距离
//}
//int main()
//{
//    int s, t;
//    cin >> n >> m >> s >>t;
//    memset(h, -1, sizeof h);//必须对每个结点的头条边初始化，-1的二进制是 11111111，memset按字节操作，赋值完后所有节点的头条边是-1
//    while (m--)
//    {
//        int a, b, c;
//        cin >> a >> b >> c;
//        add(a, b, c);//构建邻接表，有向图
//    }
//    cout << dijkstra(s,t) << endl;//输出s到t的最短距离
//    return 0;
//}

//////////////////////////////////////////从1号节点到n号节点的次短路径距离（BFS）////////////////////////////////////////

//https://leetcode-cn.com/problems/second-minimum-time-to-reach-destination/solution/gong-shui-san-xie-yi-ti-shuang-jie-dui-y-88np/1349047
//int main()
//{
//    int n = 5;//节点个数
//    vector<vector<int>> edges = { {1, 2},{1, 3},{1, 4},{3, 4},{4, 5} };//直连的节点（无向图）
//    int time = 3;//穿过任意一条边的时间是 time 分钟
//    int change = 5;//红绿灯每change分钟改变一次
//    const int INF = 0x3f3f3f3f;
//    vector<vector<int>> G(n + 1);//建图
//    vector<int> dist1(n + 1, INF);//最短路径数组
//    vector<int> dist2(n + 1, INF);//次短路径数组
//    for (auto& edge : edges) {//无向图两个节点都要加入邻居节点
//        G[edge[0]].push_back(edge[1]);
//        G[edge[1]].push_back(edge[0]);
//    }
//    //优先队列，first是从起始节点出发，到访问当前节点的距离（时间），second是当前访问的节点序号，按照距离递增排序
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//    pq.emplace(0, 1);//当前在1号节点，距离为0
//    dist1[1] = 0;//从1出发，访问1的最短路径距离是0
//    while (!pq.empty()) {
//        auto [distance, u] = pq.top();
//        pq.pop();
//        //如果此时访问u的距离既不是最短路径也不是次短路径，就直接跳过（因此这相当于第三次访问u，肯定不是次短路径，这不是必要的，因为重复访问肯定时间长，不可能出现在优先队列的头部）
//        if (distance != dist1[u] && distance != dist2[u]) continue;
//        for (int v : G[u]) {//访问u的全部邻居节点
//            //当distance是change的偶倍数时，是绿灯，不需要等待，反之需要等待change-b分钟，比如distance=6，change=5时，需要等待
//            //4分钟，而distance=11，change=5时，不需要等待
//            int a = distance / change, b = distance % change;
//            int wait = a % 2 == 0 ? 0 : change - b;
//            //distance是访问u已经花费的时间，wait是在u需要等待的时间，time是从u到任一邻居节点花费的时间
//            int w = distance + wait + time;
//            if (dist1[v] > w) {//如果这个距离w最短，则更新最短路径数组和次短路径数组
//                dist2[v] = dist1[v];//最短变成次短
//                dist1[v] = w;//新的最短
//                pq.emplace(dist1[v], v);//暂存进优先队列，等所有邻居遍历完后在考虑它是不是下一轮的中转点
//            }
//            else if (dist1[v] < w && w < dist2[v]) {//如果这个距离w在最短和次短之间，则更新次短路径数组
//                dist2[v] = w;//更新次短
//                pq.emplace(dist2[v], v);//尽管这个距离w不是访问v最短的，但它可能是下一轮中转的唯一选择，需要加入考察
//            }
//        }
//    }
//    cout << dist2[n] << endl;//从1号节点到n号节点的次短路径距离（时间）
//}

//////////////////////////////////////////统计轴对齐正方形的个数（平行于x，y轴） ////////////////////////////////////////

//https://leetcode.cn/problems/detect-squares/solution/jian-ce-zheng-fang-xing-by-leetcode-solu-vwzs/
//class DetectSquares {
//public:
//    unordered_map<int, unordered_map<int, int>> cnt;//y坐标相同的在一张map里
//    DetectSquares() {
//
//    }
//
//    void add(vector<int> point) {//添加 一个新点。可以添加 重复 的点，并会视作不同的点进行处理。
//        int x = point[0], y = point[1];
//        cnt[y][x]++;//插入坐标
//    }
//
//    int count(vector<int> point) {//给你一个查询点，请你从数据结构中选出三个点，使这三个点和查询点一同构成一个 面积为正 的 轴对齐正方形 ，统计 满足该要求的方案数目
//        int res = 0;
//        int x = point[0], y = point[1];
//        if (!cnt.count(y)) {//如果没有和y相同的点，则必然没有正方形
//            return 0;
//        }
//        unordered_map<int, int>& yCnt = cnt[y];//y相同的点先单独拿出来，注意是引用，速度更快
//        for (auto& [col, colCnt] : cnt) {//对于每一个y和其中的点
//            if (col != y) {//如果y坐标不相同
//                // 根据对称性，这里可以不用取绝对值
//                int d = col - y;
//                //第一项是查询点上边或下边的点个数，第二项是右边或左边的点个数，第三个是对角线的点个数
//                //d>0时，第一个res+=计算的是(x,y)右上的正方形，第二个res+=计算的是(x,y)左上的正方形
//                //d<0时，第一个res+=计算的是(x,y)左下的正方形，第二个res+=计算的是(x,y)右下的正方形
//                //注意最好不要直接用colCnt[x]，因为当x不存在时，哈希表会自动创建(x,0）这样的键值对，降低访问速度
//                res += (colCnt.count(x) ? colCnt[x] : 0) * (yCnt.count(x + d) ? yCnt[x + d] : 0) *
//                    (colCnt.count(x + d) ? colCnt[x + d] : 0);
//                res += (colCnt.count(x) ? colCnt[x] : 0) * (yCnt.count(x - d) ? yCnt[x - d] : 0) *
//                    (colCnt.count(x - d) ? colCnt[x - d] : 0);
//            }
//        }
//        return res;
//    }
//};
//int main()
//{
//    DetectSquares de;
//    de.add({ 3,10 });
//    de.add({ 11,2 });
//    de.add({ 3,2 });
//    de.count({ 11,10 });
//    de.count({ 14,8 });
//    de.add({ 11,2 });
//    de.count({ 11,10 });
//}

//////////////////////////////////////////组建最长的快乐字符串 ////////////////////////////////////////

//https://leetcode-cn.com/problems/longest-happy-string/solution/gong-shui-san-xie-jie-he-you-xian-dui-li-q6fd/
//int main()
//{
//    int a = 1,b = 1, c = 7;
//    priority_queue<pair<int, int>> q;//（剩余字母个数，字母），按照字母个数排序
//    if (a)
//    {
//        q.push(make_pair(a, 0));//0代表字母'a'
//    }
//    if (b)
//    {
//        q.push(make_pair(b, 1));
//    }
//    if (c)
//    {
//        q.push(make_pair(c, 2));
//    }
//    string res;
//    while (!q.empty())
//    {
//        auto t = q.top();
//        q.pop();
//        if (res.size() >= 2 && res[res.size() - 1] == t.second + 'a' && res[res.size() - 2] == t.second + 'a')
//        {//如果前面已经放了两个相同字符
//            if (q.empty())
//            {//如果此时没有其他字符可以放
//                break;//那么此时就是最长快乐字符串
//            }
//            auto t_s = q.top();//否则把剩余个数第二多的另一个字符放进去
//            q.pop();
//            res += t_s.second + 'a';//注意此时插入的是剩余数量第二多的那个字符
//            if (--t_s.first > 0)//放进去的那个字符如果还剩下，那就继续加到优先队列中，继续下一轮
//            {
//                q.push(make_pair(t_s.first, t_s.second));
//            }
//            q.push(make_pair(t.first, t.second));//最多的那个字符应该重新放进去，否则下一轮就没有它了
//        }
//        else
//        {//否则的话，就可以继续放数量最多的这个字符了
//            res += t.second + 'a';//注意此时插入的是剩余数量最多的那个字符
//            if (--t.first > 0)//放进去的那个字符如果还剩下，那就继续加到优先队列中，继续下一轮
//            {
//                q.push(make_pair(t.first, t.second));
//            }
//
//        }
//    }
//    cout << res << endl;
//    return 0;
//}

//////////////////////////////////////////网格照明，某个位置上的是否被照亮 ////////////////////////////////////////

//https://leetcode-cn.com/problems/grid-illumination/solution/gong-shui-san-xie-ha-xi-biao-xian-ying-s-s48d/1368883
//typedef long long LL;
//int main()
//{
//    int dir[9][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1} };
//    vector<vector<int>> lamps = { {2,5},{4,2},{0,3},{0,5},{1,4},{4,2},{3,3},{1,0} };
//    vector<vector<int>> queries = { {4,3},{3,1},{5,3},{0,5},{4,4},{3,3}};
//    unordered_map<int, int> row, col, left, right;
//    // 用来存储灯的坐标点的，便于在询问的时候，删除光的八个方向包括该光本身是否存在灯，然后将存在的灯熄灭
//    set<LL> point;
//    LL N = 6;//N*N的方格
//    //为啥 int a = x + y, b = x - y; 可以表示对角线?
//    /*这里的 截距 a 和 b 其实是单元格(x, y) 所在的两条对角线的编号！x+y表示向左的那条对角线，x-y表示向右的那条
//    打开单元格(x, y) 处的灯后，会照亮对应行 / 列 / 对角线上所有的单元格。我们对行 / 列 / 对角线进行编号以后，
//    当打开单元格(x, y) 处的灯后，照亮对应行 / 列 / 对角线上所有单元格的操作，
//    我们只需要记录对应行 / 列 / 对角线被照亮的次数即可。*/
//    auto change = [&](int x, int y, int c) {
//        row[x] += c, col[y] += c, right[x - y] += c, left[x + y] += c;
//    };
//    // 遍历灯：存储以上数据结构
//    for (vector<int>& l : lamps) {
//        int x = l[0], y = l[1];
//        // 重复点直接跳过
//        if (point.count(x * N + y))continue;
//        point.insert(x * N + y);
//        change(x, y, 1);
//    }
//    vector<int> res;
//    for (vector<int>& q : queries) {
//        int x = q[0], y = q[1];
//        // 判断(x,y)所在行、列、对角线是否存在光
//        if (row[x] || col[y] || right[x - y] || left[x + y])
//            res.push_back(1);
//        else { 
//            res.push_back(0);
//            continue; 
//        }
//        // 然后将光所在点的8个方向包括该点本身的所有灯进行关闭
//        for (int i = 0;i < 9;++i) {
//            int nx = x + dir[i][0], ny = y + dir[i][1];
//            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
//                continue;
//            // 灯存在，则进行删除灯，并关闭行列对角线上的光
//            if (point.count(nx * N + ny)) {
//                point.erase(nx * N + ny);
//                change(nx, ny, -1);
//            }
//        }
//    }
//}

//////////////////////////////////////////不能跳出棋盘的1元素个数 ////////////////////////////////////////

//https://leetcode-cn.com/problems/number-of-enclaves/solution/fei-di-de-shu-liang-by-leetcode-solution-nzs3/
//typedef pair<int, int> pii;
//int main()
//{
//    vector<vector<int>> grid = { {0, 0, 0, 0},{1, 0, 1, 0},{0, 1, 1, 0},{0, 0, 0, 0} };
//    int m = grid.size(), n = grid[0].size();
//    queue<pii> q;
//    vector<vector<int>> vis(m, vector<int>(n, 0));
//    int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
//    for (int i = 0;i < m;i++)//从边缘元素出发，找到四条边上是1的位置
//    {
//        if (grid[i][0] == 1)//这是左边
//        {
//            vis[i][0] = 1;
//            q.push(make_pair(i, 0));
//        }
//        if (grid[i][n - 1] == 1)//这是右边
//        {
//            vis[i][n - 1] = 1;
//            q.push(make_pair(i, n - 1));
//        }
//    }
//    for (int j = 0;j < n;j++)
//    {
//        if (grid[0][j] == 1)//这是上边
//        {
//            vis[0][j] = 1;
//            q.push(make_pair(0, j));
//        }
//        if (grid[m - 1][j] == 1)//这是下边
//        {
//            vis[m - 1][j] = 1;
//            q.push(make_pair(m - 1, j));
//        }
//    }
//    while (!q.empty())//从四个边界的1元素出发，找到和他们相邻的所有1元素，这些元素全部都可以跳出“棋盘”，因此排除这些元素
//    {
//        pii t = q.front();
//        q.pop();
//        for (int i = 0;i < 4;i++)
//        {
//            int new_x = t.first + dir[i][0];
//            int new_y = t.second + dir[i][1];
//            if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && vis[new_x][new_y] == 0 && grid[new_x][new_y] == 1)
//            {
//                vis[new_x][new_y] = 1;
//                q.push(make_pair(new_x, new_y));
//            }
//        }
//    }
//    int res = 0;
//    for (int i = 0;i < m;i++)
//    {
//        for (int j = 0;j < n;j++)
//        {
//            if (grid[i][j] == 1 && vis[i][j] == 0)//剩下没有被访问过的1元素就是无法跳出“棋盘”的元素，统计个数
//            {
//                res++;
//            }
//        }
//    }
//    cout << res << endl;
//}

//////////////////////////////////////////找到有序数组中的单一元素（二分） ////////////////////////////////////////

//https://leetcode-cn.com/problems/single-element-in-a-sorted-array/solution/you-xu-shu-zu-zhong-de-dan-yi-yuan-su-by-y8gh/
//考虑数组中任意偶数下标x的元素；如果x之前，没有出现过 target； 显然 x和x + 1 对应的元素应该是一样的，
//因为没有出现target则意味着所有元素都是成对出现。(0, 1) (2, 3) (4, 5) 括号内的元素应该都是一样的。
//直至某个位置有了第一个落单的元素 target； 则之后的所有偶数下标 x 的元素应该和 x - 1 是一样的。target一定是偶数下标
//(0, 1) (2, 3) (4, 5) target(7, 8) (9, 10)
//int main()
//{
//    vector<int> nums = { 1,1,2,3,3,4,4,8,8 };
//    //vector<int> nums = { 1};
//    int l = 0;
//    int r = nums.size()-1;
//    int res = 0;
//    if (nums.size() == 1)
//    {//这是为了防止只有一个元素时数组越界，因为我们要计较nums[mid]和nums[mid+1]，则数组至少有两个元素
//        cout << nums[0] << endl;
//        return 0;
//    }
//    while (l <= r) {//搜索区间[left,right]
//        int mid = (l + r) / 2;
//        if (mid % 2 == 0) {//偶数坐标
//            if (nums[mid] == nums[mid + 1]) {//相等说明还没有出现target，向右查找，此时mid和mid+1都可以排除
//                l = mid + 2;
//            }
//            else 
//            {//不相等说明出现了target，判断此时mid是否等于0或者mid和mid-1是否相等（必须要先判断0，否则会越界）
//             //如果等于0说明mid就是target，mid不等于mid-1也说明mid就是target（因为前一个判断已经确定mid不等于mid+1了）
//             
//                if (mid == 0 || nums[mid - 1] != nums[mid]) 
//                    return nums[mid];
//                res = mid;//mid有可能是答案，记录一下，其实没必要写这句，如果mid是答案的话上面的if就会直接返回了
//                r = mid-1;//否则缩小右边界，此时搜索范围是[left,mid-1],符合while的条件定义“左闭右闭”
//            }
//        }
//        else {//奇数坐标
//            if (nums[mid] == nums[mid - 1]) {//相等说明还没有出现target，向右查找，此时mid可以排除
//                l = mid + 1;
//            }
//            else 
//            {//不相等说明出现了target，判断此时mid和mid+1是否相等
//             //如果mid不等于mid+1也说明mid就是target（因为前一个判断已经确定mid不等于mid-1了）
//             //这里不需要判断mid是否等于nums.size()-1，因为nums里面有奇数个数，最后一个坐标肯定是偶数，
//             //mid是奇数坐标的话肯定不会是最后一个坐标，因此不必担心越界
//             //其实没必要写这个if，直接缩小边界就行了，因为target出现的下标一定是偶数，所以mid是奇数的话不可能是target
//                /*if (nums[mid] != nums[mid + 1]) 
//                    return nums[mid];*/
//                res = mid;//其实没必要写这句，因为mid是奇数的话不可能是target
//                r = mid-1;//否则缩小右边界，此时搜索范围是[left,mid),符合while的条件定义“左闭右开”
//            }
//        }
//    }
//    cout << nums[res] << endl;//这里随便返回一个值就行了，因为上面的while循环一定能找到答案，不需要这里的返回
//    return 0;
//}

//////////////////////////////////////////骑士走k步仍然在棋盘上的概率 ////////////////////////////////////////

//https://leetcode-cn.com/problems/knight-probability-in-chessboard/solution/qi-shi-zai-qi-pan-shang-de-gai-lu-by-lee-2qhk/
//int main()
//{
//    int k = 2, n = 3, row = 0, column = 0;//k表示还能移动多少次，n表示边界，row，column表示初始点
//    int dir[8][2] = { {-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2} };//8个方向
//    vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, vector<double>(n, 1.0)));
//    //dp[s][i][j]表示从（i，j）开始走了s步之后仍然留在棋盘上的概率,s=0时，无法移动，则dp[0][i][j]=1.0（初始必定在棋盘上，概率为1）
//    //dp[s][i][j]=0.125*∑dp[s-1][new_i][new_j]，其中0.125为「从(i, j)走到(new_i, new_j)」的概率（八个方向移动等概率发生）
//    //最终答案是dp[k][row][column]，从（row，column）出发走k步仍然留在棋盘上的概率
//    for (int s = 1;s <= k;s++)
//    {
//        for (int i = 0;i < n;i++)//从棋盘的左上角开始
//        {
//            for (int j = 0;j < n;j++)
//            {
//                double sum = 0;//下一步仍然留在棋盘上的概率求和
//                for (int k = 0;k < 8;k++)//8个方向
//                {
//                    int new_i = i + dir[k][0];
//                    int new_j = j + dir[k][1];
//                    if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n)
//                    {//只需要计算下一步仍然留在棋盘上的概率，如果离开了棋盘，那么sum就应该加0，即不加任何概率
//                        sum += dp[s - 1][new_i][new_j];
//                    }
//
//                }
//                dp[s][i][j] = 0.125 * sum;
//            }
//        }
//    }
//    cout << dp[k][row][column] << endl;
//    return 0;
//}

//////////////////////////////////////////利用煎饼法对数组排序 ////////////////////////////////////////

//https://leetcode-cn.com/problems/pancake-sorting/solution/gong-shui-san-xie-mou-pao-pai-xu-yun-yon-c0mn/1388332
//数组 arr 元素由 1 到 n（n 为数组长度）内的所有自然数组成，对数组 arr 进行排序后，数组中每个元素 i 的位置是确定的，即 i - 1。
//于是，我们可以从大(n) 到小(1)，将元素 i(i = n, n - 1, ……, 1) 放置到最终的排序位置 i - 1。
//对每个元素 i，我们最多可由两次翻转实现：
//·当元素 i 的索引为 i - 1，即元素 i 位于最终的排序位置时，此时不做翻转，continue 进入下次循环，对元素 i - 1 进行排序。
//·当元素 i 的索引不是 i - 1 时，此时我们需要两次翻转，将元素 i 放置到最终的排序位置 i - 1。
//  具体地：第一次翻转，将元素 i 及其之前的所有元素进行翻转，此时，元素 i 位于数组的开始位置 0，
//  然后进行第二次翻转，将前 i 个元素进行翻转，此时元素 i 位于索引 i - 1 处，即元素 i 的最终排序位置~
//int main()
//{
//    vector<int> arr = { 3,2,4,1 };
//    vector<int> res;
//    for (int n = arr.size();n > 0;n--)//下一个数应该放在第n个位置上（元素n应该放在下标n-1处）
//    {
//        int index = max_element(arr.begin(), arr.begin() + n) - arr.begin();//注意搜索最大值的范围
//        if (index == n-1)//index是下标，n是次序（第几个）
//        {
//            continue;
//        }
//        reverse(arr.begin(), arr.begin() + index + 1);//reverse(begin,end)翻转[begin,end-1]范围内的元素。begin和end都是迭代器
//        reverse(arr.begin(), arr.begin() + n);
//        res.emplace_back(index + 1);//题目要求翻转的是次序，index是下标，所以要加1
//        res.emplace_back(n);
//    }
//    for (auto i : res)
//    {
//        cout << i << ' ';
//    }
//    return 0;
//}

//////////////////////////////////////////n行m列的矩形，找到至少包含k个不同字符的最小正方形边长 ///////////////

//https://www.nowcoder.com/questionTerminal/0f82611d55dd4c88b6e5367c418d075d?answerType=1&f=discussion
//int n, m, k;//n行m列的矩形，找到至少包含k个不同字符的最小正方形边长
//char s[501][501];//字母矩阵
//int f[501][501][26];//记录以第i行第j列元素为右下角的矩形中第k个字符（从‘a’开始算起）的个数（k表示‘a’-‘z’）
//void update(int x, int y, char ch)//每输入一个字母，就更新一次
//{
//    for (int i = 0;i < 26;i++)
//    {//以第x行第y列元素为右下角的矩形中所有字母个数都要更新，即以第x行第y列元素为右下角的矩形中包含第i个字母个数等于
//     // 以第x-1行第y列元素为右下角的矩形中包含第i个字母个数 加上 以第x行第y-1列元素为右下角的矩形中包含第i个字母个数
//        // 减去以第x-1行第y-1列元素为右下角的矩形中包含第i个字母个数(因为这块面积加了两遍）
//        f[x][y][i] = f[x - 1][y][i] + f[x][y - 1][i] - f[x - 1][y - 1][i];
//    }
//    f[x][y][ch - 'a']++;//更新本次输入的字符个数
//    return;
//}
//bool check(int edge)
//{
//    for (int i = 1;i+edge-1 <= n;i++)
//    {//最好从1开始，因为更新的时候要用i-1和j-1，如果i和j是0的话就要单独判断，比较麻烦，可以理解为次序而不是下标
//        for (int j = 1;j + edge -1<= m;j++)
//        {//第i行第j列是正方形左上角（包含），第i + edge - 1 行第j + edge - 1是正方形右下角（包含）
//            if (i + edge - 1 > n || j + edge - 1 > m)
//            {//右下角超出边界，注意i + edge - 1表示次序，所以它可以等于n，但不能大于n
//                continue;
//            }
//            int cnt = 0;//记录此正方形中有多少个不同字母
//            for (int k = 0;k < 26;k++)
//            {
//                if (f[i + edge - 1][j + edge - 1][k] - f[i - 1][j + edge - 1][k] 
//                    - f[i + edge - 1][j - 1][k] + f[i - 1][j - 1][k] > 0)
//                {//右下角-正方形左边-正方形上边+左上角（因为减了两遍），大于0表示这个正方形中含有第k个字母，那么字母种类自增1
//                    cnt++;
//                }
//            }
//            if (cnt >= k)
//            {//只要有一个正方形中字母种类大于等于k，返回true，表示此边长满足条件
//                return true;
//            }
//        }
//    }
//    return false;//否则此边长不满足条件
//}
//int main()
//{
//    cin >> n >> m >> k;
//    for (int i = 1;i <= n;i++)
//    {//最好从1开始，因为更新的时候要用i-1和j-1，如果i和j是0的话就要单独判断，比较麻烦，可以理解为次序而不是下标
//        for (int j = 1;j <= m;j++)
//        {
//            cin >> s[i][j];
//            update(i, j, s[i][j]);
//        }
//    }
//    int ans = -1;//如果不存在这样的正方形，就输出-1
//    int L = 1, R = min(n, m);//二分法上下界[1,min(m,n)],边长最小为1，最大为m，n的较小值
//    while (L <= R) {
//        int mid = L + R >> 1;
//        if (check(mid)) 
//        {//返回true表示以mid为边长的正方形中存在至少k个不同字符，那么就记录一下这个边长，然后把边长变小继续查找
//            ans = mid;
//            R = mid - 1;
//        }
//        else 
//        {//否则边长变大继续查找
//            L = mid + 1;
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}

//////////////////////////////////////////推倒多米诺骨牌的方向 ////////////////////////////////////////

//https://leetcode-cn.com/problems/push-dominoes/solution/fu-xue-ming-zhu-miao-dong-xi-lie-xiang-x-xkts/
//int main()
//{
//    string dominoes = "RR.L";
//    int n = dominoes.size(), i = 0;//i是左边界下标
//    char left = 'L';//左边界，左边界初始为'L'的话不影响后续骨牌的方向
//    while (i < n) {
//        int j = i;//j是右边界下标
//        while (j < n && dominoes[j] == '.') 
//        { // 找到一段连续的没有被推倒的骨牌
//            j++;
//        }
//        char right = j < n ? dominoes[j] : 'R';//j等于n表示右边没有边界，所以默认是'R'，也不会对其他骨牌有影响
//        if (left == right) { // 方向相同，那么[i,j]之间的竖立骨牌也会倒向同一方向
//            while (i < j) {
//                dominoes[i++] = right;
//            }
//        }
//        else if (left == 'R' && right == 'L') { // 方向相对，那么就从两侧向中间倒
//            int k = j-1;//不能移动j，因为后面要用右边界去给左边界重新赋值，注意这里不是k=j，因为i是竖直骨牌的第一个，需要处理，而j是竖直骨牌最后一个右边的骨牌，它不是竖直的，因此不需要处理
//            while (i < k) {//i=k时不做处理，保持竖直状态
//                dominoes[i++] = 'R';
//                dominoes[k--] = 'L';
//            }
//        }
//        left = right;//左边界重新赋值
//        i = j + 1;//i变成没有处理过的第一个，也可以是i=j，那么i就表示已处理过的最后一个，需要调整其他下标
//    }
//    cout << dominoes << endl;
//    return 0;
//}

//////////////////////////////////////////好子集的数量（状态压缩DP） ////////////////////////////////////////

//https://leetcode.cn/problems/the-number-of-good-subsets/solution/gong-shui-san-xie-zhuang-ya-dp-yun-yong-gz4w5/
//一个整数数组 nums 。如果 nums 的一个子集中，所有元素的乘积可以表示为一个或多个 互不相同的质数 的乘积，那么我们称它为 好子集 。
//int main()
//{
//    vector<int> nums = { 1,2,3,4 };//1 <= nums[i] <= 30，所以nums子集的乘积最多只需要分解成不超过30的质数之积
//    const static int mod = 1e9 + 7;
//    vector<int> p = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };// 30 以内的质数，总共10个
//    vector<int> cnts(35);//记录每个数出现的次数
//    int n = nums.size();
//    for (auto i : nums) cnts[i]++;//统计次数
//    int mask = 1 << 10;//用来表示每个质数是否出现
//    vector<long long> f(mask);
//    //f(state)为当前子集乘积拆解结果的用到的质数为 state 时的方案数
//    //dp[5]  5 二进制位 0000000101, 表示子集所有元素乘积为 p[0] * p[2] = 2 * 5 =10的方案个数
//    // 动态转移方式为在已有的情况下再增加其他质数  (p[0] * p[2]) * p[1] = (2 * 5) * 3
//    // 注意这里 dp 用 int 会溢出
//    f[0] = 1;//拆解结果用到的质数个数为 0 时的方案数只有1个，那就是空集，乘积为 0 
//    for (int i = 2; i <= 30; i++) 
//    {//讨论[2,30]中的某个数值t能否添加到好子集中，1 添加与否不对好子集产生影响，最后讨论
//     //一个数值 i 能够添加到子集中的充要条件为题目给定的条件：该数不会被相同的质数相乘表示（比如4,8,9,12,16,18,20,24,25,27,28)。
//        if (!cnts[i]) continue;//如果 nums 里面没有这个数，不必考虑是否可以加入好子集
//        //如果一个数值 i 能够添加到好子集中，我们通过「试除法」将其分解为 p 中的多个质数，
//        //并使用二进制数 cur 来表示用到了 p 中的哪些质数
//        int cur = 0, x = i;//这里 x 就是 i
//        bool ok = true;//true表示t能够加入好子集中
//        for (int j = 0; j < 10; j++) 
//        {//判断 x 会不会被相同的质数相乘表示
//            int t = p[j], c = 0;//这里的 t 表示 p 中某一个质数，c 用来计数，统计 x 的因子里面有多少个 t 
//            while (x % t == 0) 
//            {//这里是while循环，如果一个数的因子里面有多个相同的数，比如 4 = 2*2，8=2*2*2,18=2*3*3，那么此时 c>1 ,代表 4 不能加入好子集中
//                //其实可以直接判断x是不是在上面那堆数（4,8,9...）里面，如果不在的话，再去计算cur
//                cur |= (1 << j);//用来记录哪一个质数是 x 的因子，c>1保证了不可能出现相同的因子
//                x /= t;
//                c++;
//            }
//            if (c > 1) {
//                ok = false;
//                break;//已经不能加入好子集中了，不需要继续去判断了
//            }
//        }
//        if (!ok) continue;//不能加入好子集，下一个数
//        //至此我们判断出了 x 不包含重复的因子，因此 x 可以添加到已有的集合中，只要保证它和集合中已有的数没有重复的质因子就行了
//        for (int prev = 0; prev < mask; prev++) 
//        {//否则t可以加入好子集，下一步判断 t 能够添加到哪些子集中，其实就是枚举与 cur 无交集的状态 prev
//            //无交集代表cur用到的质数位和prev用到的质数位完全不同
//            if ((prev & cur) != 0) //按位与不等于0代表cur和prev有交集，则t不能加入到这个好子集中
//                continue;
//            //prev|cur表示把cur和prev用到的质数合并到一起，也就是在已有的好子集中加入t，则新的好子集乘积可以用prev|cur表示
//            //为什么要乘以次数？
//            //·因为好子集只需要下标不同，值可以相同。也就是说如果nums里面有相同的数，那么可以在同一个好子集中加入下标不同但值相同的 i，这样的方案数就是之前的方案数乘以次数
//            //为什么是f[prev | cur]的累加？
//            //·因为这里的累加并不是在prev这层循环起作用（这层循环里prev都不相同，cur都相同，那么prev | cur都不相同，想累加也不行）
//            //  而是在i=[2:30]这层循环起作用，也就是cur也是变化的，这样对于不同的prev，不同的cur有可能prev | cur相同，所以要累加
//            //  比如prev1={2,3}，cur1={5}，那么prev1 | cur1={2,3,5}；prev2={2}，cur2={3,5}，prev2 | cur2={2,3,5}，组成相同的好子集
//            //  再比如prev1={2,15}，cur1={29}，那么prev1 | cur1={2,15,29}；prev2={29}，cur2={2,15}，prev2 | cur2={2,15,29}，
//            //  也组成相同的好子集
//            f[prev | cur] = (f[prev | cur] + f[prev] * cnts[i]) % mod;
//        }
//    }
//    int ans = 0;
//    for (int i = 1; i < mask; i++)//状态不能是空集（空集包含质数为0，也就是i=0）所以i从1开始
//        ans = (ans + f[i]) % mod;
//    for (int i = 0; i < cnts[1]; i++) 
//        //对于一个非空集而言，添加一个1可以构建一个新的好子集，添加2个1也可以...
//        //所以假设最开始的非空集为ans，添加一个1得到2*ans，
//        //添加两个1得到4*ans（原本的ans，一个1都没有；添加下标为m的1；添加下标为n(n!=m)）的1；添加两个下标为m，n的1）
//        //后续同理...
//        ans = ans * 2 % mod;
//    cout<<ans<<endl;
//    return 0;
//}

//////////////////////////////////////////二分法查找所有车完成旅途的最少时间 ////////////////////////////////////////

//https://leetcode-cn.com/problems/minimum-time-to-complete-trips/solution/er-fen-fa-zhu-yi-yi-chu-by-newhar-zjs1/
//bool isValid(long long mid, vector<int>& time, int totalTrips)
//{
//    long long res = 0;
//    for (int i = 0;i < time.size();i++)
//    {
//        res += (mid / time[i]);//对于每辆车，计算在mid天内能完成的旅程数，累加
//    }
//    if (res >= totalTrips)//如果能完成totalTrips，返回true
//    {
//        return true;
//    }
//    return false;
//}
//int main()
//{
//    vector<int> time = { 1,2,3 };//time未必是排好序的，所以可能还需要排序
//    int totalTrips = 5;//需要完成的旅程总数
//    long long left = 1, right = (long long)totalTrips * time[0];//通过二分法搜索至少需要多少天，下界是一天，上界是旅程总数乘以一次旅程需要的最少天数（time[0]）
//    long long res;
//    while (left <= right)
//    {
//        long long mid = left + (right - left) / 2;
//        if (isValid(mid, time, totalTrips))//返回true表示mid天完成的旅程数大于等于totalTrips，那么就可以继续往小搜索
//        {
//            res = mid;
//            right = mid - 1;
//        }
//        else//否则就要往大搜索
//        {
//            left = mid + 1;
//        }
//    }
//    cout << res << endl;
//}

//////////////////////////////////////////DP计算完成n圈比赛的最少时间（更换轮胎） ////////////////////////////////////////

//https://leetcode-cn.com/problems/minimum-time-to-finish-the-race/solution/jie-he-xing-zhi-qiao-miao-dp-by-endlessc-b963/
//二维整数数组 tires ，其中 tires[i] = [fi, ri] 表示第 i 种轮胎如果连续使用，第 x 圈需要耗时 fi * ri^(x - 1) 秒，也就是耗时会指数增长。
//比方说，如果 fi = 3 且 ri = 2 ，且一直使用这种类型的同一条轮胎，那么该轮胎完成第 1 圈赛道耗时 3 秒，完成第 2 圈耗时 3 * 2 = 6 秒，完成第 3 圈耗时 3 * 2^2 = 12 秒，依次类推。
//比赛总共包含 numLaps 圈，你可以选择 任意 一种轮胎开始比赛。每一种轮胎都有 无数条 。每一圈后，你可以选择耗费 changeTime 秒 换成 任意一种轮胎（也可以换成当前种类的新轮胎）
//int main()
//{
//    vector<vector<int>> tires = { {99, 7} };
//    int changeTime = 85, numLaps = 95;
//    vector<int> min_s(18, 0x3f3f3f3f);//记录使用同一个(不是同一类，是只用一个）轮胎跑完x圈使用的最少时间，也就是说在所有种类的轮胎中，找到一种轮胎，只用这种轮胎的一个跑完x圈，耗时最少
//                                      //为什么是18，证明参考链接，也就是说同一个轮胎（不管哪个种类的轮胎），用它跑17圈以后跑一圈耗费的时间一定多于换一个新轮胎
//    for (auto i : tires)
//    {
//        long long tmp = i[0], sum = 0;//注意sum才真正表示跑完第x圈的耗时，初始为fi，也就是第 1 圈的耗时，第 x 圈需要耗时 fi * ri^(x - 1) 秒，它可以分解成 fi*ri^0+fi*ri^1+fi*ri^2+fi*ri^3...+fi*ri^(x-1)
//        for (int x = 1;tmp <= changeTime + i[0];x++)
//        {//x表示第几圈，所以从1开始，当跑到某一圈时，始终使用这一个轮胎在这一圈的耗时大于换一个新的这种轮胎在这一圈的耗时，就该停止了
//            //因为在继续下去的话，始终使用的耗时是指数增长的，一定耗时更长。
//            sum += tmp;//跑完第x圈的耗时
//            min_s[x] = min((long long)min_s[x], sum);//在所有种类的轮胎中，找到一种轮胎，只用这种轮胎的一个跑完第 x 圈，耗时最少,相当于我们用每种轮胎不断刷新跑完第 x 圈用的最短时间（注意不是前 x 圈的总时间） 
//            tmp *= i[1];//指数增长
//        }
//    }
//    vector<long long> dp(numLaps + 1, INT_MAX);//dp[i]表示在 必然更换轮胎 的情况下跑完i圈需要的最短时间
//    dp[0] = -changeTime;//跑完0圈不需要耗时，但是0圈不需要更换轮胎，为了方便计算，dp[0] = -changeTime，默认更换了一次轮胎
//    for (int i = 1;i <= numLaps;i++)
//    {//从第1圈开始
//        for (int j = 1;j <= min(i, 17);j++)
//        {//跑完i-j圈后换胎，然后用min_s[j]的时间，跑了j圈（用同一个轮胎），也就是最后一个轮胎连续跑了 j 圈，注意i-j可以为0，相当于在开始跑之前更换一次轮胎，实际上并不需要这次更换
//            //下面加的时候加上了这个更换的时候，所以dp[0] = -changeTime，要减去这个额外的时间
//            dp[i] = min(dp[i], dp[i - j] + min_s[j]);
//        }
//        dp[i] += changeTime;//默认更换一次轮胎，如果前面计算min_s的时候计算上最开始换轮胎的时间的话（就是tmp初始化为 i[0]+changeTime），dp[0]就可以初始化为0了
//    }
//    cout << dp[numLaps] << endl;
//    return 0;
//}

//////////////////////////////////////////最多可达成的换楼请求数目 ////////////////////////////////////////

//https://leetcode-cn.com/problems/maximum-number-of-achievable-transfer-requests/solution/zui-duo-ke-da-cheng-de-huan-lou-qing-qiu-ae0e/
//class Solution {
//public:
//    int status[21] = { 0 };//记录各个楼的状态，人数多了还是少了，人数正好饱和为0，正代表入度多于出度，人多了，负代表出度多于入度，人少了
//    int ret = 0;//记录返回结果
//    int nn;//等于n,n栋楼，编号0：n-1
//    bool balance = true;//当前所有楼是否都饱和，平衡状态
//    void dfs(vector<vector<int>>& requests, int size, int pos, int nums)
//    {//pos是当前搜索到的请求下标，nums是已选择的请求数量
//        if (pos == size) {//搜索完毕进入判断
//            balance = true;
//            for (int i = 0;i < nn;i++)
//            {
//                if (status[i] != 0)
//                {
//                    balance = false; //当前状态是否平衡，只要有1个楼不平衡，选择的请求就不满足要求
//                    break;
//                }
//            }
//            if (balance == true && nums > ret)
//            {//如果满足的请求数大于当前答案，则更新答案
//                ret = nums;
//            }
//            return;
//        }
//        // 接下来是pos不等于size的操作:回溯
//        // 不选择当前请求
//        dfs(requests, size, pos + 1, nums);
//        // 选择当前请求
//        status[requests[pos][0]]--;//requests[pos][0]代表某一号楼，选择当前请求后，这号楼的出度减少1，也就是从起始状态0变成了-1，需要增加入度才能恢复0
//        status[requests[pos][1]]++;
//        dfs(requests, size, pos + 1, nums + 1);
//        status[requests[pos][0]]++;
//        status[requests[pos][1]]--;
//
//    }
//    int maximumRequests(int n, vector<vector<int>>& requests) {
//        nn = n;
//        int size = requests.size();
//        dfs(requests, size, 0, 0);
//        return ret;
//    }
//};
//int main()
//{
//    int n = 5;
//    vector<vector<int>> requests = { { 0,1},{1,0},{0,1},{1,2},{2,0},{3,4} };
//    //************回溯**************
//    //Solution so;
//    //cout<<so.maximumRequests(n, requests)<<endl;
//    //************二进制枚举**************
//    vector<int> delta(n);
//    int ans = 0, m = requests.size();
//    for (int mask = 0; mask < (1 << m); ++mask) 
//    {//长度为 m 的二进制数 mask 表示所有的请求，其中 mask 从低到高的第 i 位为 1 表示选择第 i 个请求，为 0 表示不选第 i 个请求
//        int cnt = 0;
//        for (int i = 0;i < m;i++)
//        {
//            if (mask & (1 << i))
//            {//统计一共接收了多少请求
//                cnt++;
//            }
//        }
//        if (cnt <= ans) 
//        {//要求最多能接受多少请求，所以接受请求少的方案不用考虑
//            continue;
//        }
//        //fill(delta.begin(), delta.end(), 0);//对于每种方案，都要从0开始统计
//        delta = vector<int>(n, 0);
//        for (int i = 0; i < m; ++i) {
//            if (mask & (1 << i)) {//如果mask这种方案中选择了第i个请求，则重新计算出度入度
//                --delta[requests[i][0]];
//                ++delta[requests[i][1]];
//            }
//        }
//        if (all_of(delta.begin(), delta.end(), [](int x) { return x == 0; })) 
//        {//如果此方案中所有楼都是平衡的，也就是delta全都是0
//            ans = cnt;//更新答案
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}

//////////////////////////////////////////距离n最近的回文数字（n非常大） ////////////////////////////////////////

//https://leetcode.cn/problems/find-the-closest-palindrome/solution/gong-shui-san-xie-tan-xin-fen-xi-shang-x-vtr6/
//string getnum(string i, bool isEven)
//{
//    string res;
//    res += i;
//    if (isEven)
//    {
//        for (int k = i.length() - 1;k >= 0;k--)
//        {
//            res.push_back(i[k]);
//        }
//    }
//    else
//    {
//        for (int k = i.length() - 2;k >= 0;k--)
//        {
//            res.push_back(i[k]);
//        }
//    }
//    return res;
//}
//int main()
//{
//    string n = "99800";
//    unordered_set<long long> uset;//存放可能的结果集合
//    bool isEven = false;
//    int len = n.length();
//    if (len % 2 == 0)
//    {
//        isEven = true;
//    }
//    string left = n.substr(0, len + 1 / 2);//“998”，根据左边的值去构建右边的值
//    long long left_num = stoi(left);
//    //将与长度相关的边界值也纳入考虑，即将「长度为 len - 1 的回文串最大值 len-1个 9」和「长度为 len + 1 的回文串最小值（10...01）」也纳入考虑
//    //比如本例中 len=9，则有可能的答案就是 10^5+1=100001 和 10^4-1= 9999，因为 10001 就离 9999 最近，99999就离 100001最近，他们都是 5 位数，所以这两个值也是可能的答案
//    uset.insert(pow(10, len) + 1);
//    uset.insert(pow(10, len - 1) - 1);
//    for (long long i = left_num - 1;i <= left_num + 1;i++)
//    {//必须是[left_num - 1:left_num + 1]这个范围去构建，因为 n 可能更靠小的数或者大的数，比如 99800 就更靠近 99799
//        string new_num = getnum(to_string(i), isEven);
//        long long tmp = stoll(new_num);
//        if (tmp != stoll(n))
//        {
//            uset.insert(tmp);
//        }
//    }
//    long long res = -1;
//    for (auto it : uset)
//    {
//        if (res == -1)
//        {
//            res = it;
//        }
//        else if (abs(res - stoll(n)) > abs(it - stoll(n)))
//        {
//            res = it;
//        }
//        else if (abs(res - stoll(n)) == abs(it - stoll(n)))//如果不止一个，返回较小的那个
//        {
//            res = min(res, it);
//        }
//    }
//    cout<<to_string(res)<<endl;
//    return 0;
//}

//////////////////////////////////////////3n个人分成n组，中位数之和最大 ////////////////////////////////////////

//int main()
//{
//    int n = 2;
//    vector<long long> v = {1, 2, 5, 5, 6, 8};//将3*n个人分成n组，即每组3个人，取中值为代表，计算所有组中值之和的最大值
//    sort(v.begin(), v.end());//首先排序
//    long long sum = 0;
//    for (int i = 3 * n - 2;i >= n;i -= 2)
//    {//从倒数第二个值（也就是6）开始，每隔一个数取出一个值，最后保证最小的数有n个（也就是i>=n）
//        //这样分成的每个组就是{n个最小值中的一个，取出来的这个值，取出来的这个值右边的值}，这样保证了每组的中值就是我们取出来的值，同时他们的和最大
//        sum += v[i];
//    }
//    cout << sum << endl;
//    return 0;
//}

//////////////////////////////////////////如何培养出潜力和战力之和最大的士兵 ////////////////////////////////////////

//https://www.nowcoder.com/questionTerminal/79190c8e6202414bad33d6e287b61f3d
//输入：2
//      1 2
//      2 1
//输出：4，解释：士兵2打败了士兵1，战斗力变成 2+（2-1）=3，加上自己的潜力值 就是 4
//我们要选出的兵，肯定要打败所有其他的y > x的兵来给自己加经验，对吧！我们就先把所有的y > x的兵的经验和，也就是潜力值 - 战力值的和记为一个数，就叫sum吧。
//然后我们的任务就是去找那个合适的兵，然后让他的经验值堆高，假定这个兵的两值是x和y，这里就有两种情况：
//1.这个兵的x < y，也就是在我们的sum里面已经加了它了，那我们最终的结果就是sum - (y - x) + x + y = sum + 2x;也就是他不能打败自己获得增强，而我们的sum里面已经加了，所以要先减去（y-x）
//2.这个兵的x >= y，那就很简单，结果是sum + x + y
//所以我们就去找到底是x<y情况下的2x大呢还是x >= y下的x + y大呢，其实这里就可以解决题目中的问题了
//最终我们找到了这个最合适的兵，也得出了题目要求的最值
//·但是你可能疑虑，选是选出来了，这个兵能打得过其他兵嘛
//  如果这个兵是x1 < y1，其他要打的兵属性值是x2，y2, 由于这个兵是 x1<y1 ，所以答案一定是通过 add+ 2*x1得到的，就是说x1是所有士兵里面的最大值，那么一定有 2x1 > 2x2 = > x1 > x2，妥妥的打得过
//  如果这个兵是x1 >= y1, 其他要打的兵是x2，y2，由于这个兵是 x1>=y1 ，所以答案一定是通过 add+ x1+ y1得到的，那么一定有 x1 + y1 >= 2 * x_max = x_max+ x_max(x_max是只有那些 x<y 的士兵的最大攻击力）
//  x1不可能小于x_max，x1小于x_max的话，y1比x1更小，而x_max要小于y_max，那么一定会得到 x_max +y_max >x1+y1,和我们的假设 x1+y1 最大不符，所以 x1 > x_max, 那么还是打得过！！
//int main() {
//    int n,j,k;
//    long long maxZhan = 0, add = 0, maxSum = 0, tZhan, tQian;
//    cin >> n;
//    for (int i = 0; i < n; i++) 
//    {
//        cin >> tZhan >> tQian;
//        //潜力比战斗力大，记录潜力与战力差的总和和其中最高的战斗力
//        if (tZhan < tQian)
//        {
//            if (tZhan > maxZhan)
//            {
//                j = i;
//                maxZhan = max(maxZhan, tZhan);
//            }
//            add += tQian - tZhan;
//        }
//        //否则，记录最大的潜力、战力和
//        else
//        {
//            if (tZhan + tQian > maxSum)
//            {
//                k = i;
//                maxSum = max(maxSum, tZhan + tQian);
//            } 
//        }
//    }
//    cout << add + max(2 * maxZhan, maxSum) << endl;
//    return 0;
//}

//////////////////////////////////////////printf 输出格式 ////////////////////////////////////////

//http://c.biancheng.net/view/1793.html
//int main()
//{
//    double a = 12.32325263;
//    int b = 31;
//    long long d = 251255433211552452;
//    char* c = "abcabcabc";
//    //+表示输出符号（正负号）。如果没有，那么只有负数才会输出符号。
//    //10表示输出a时占用的空格总数，如果小于我们需要输出的总长度，则不起作用；大于就默认在左边补空格
//    //.9对于浮点数来说是小数点后有几位，对于整数来说是总位数（前面补0），小于本身长度不起作用，对于字符串来说是截取前几个字符，大于本身长度不起作用
//    //#表示输出8进制（%o）和16进制（%x / %X）的前缀‘0’和‘0x/0X’
//    //-表示左对齐，也就是右补空格
//    printf("%+10.9lf,%-#6.3X,%-10.11s,%lld", a,b,c,d);
//}

//////////////////////////////////////////所有子数组中最大元素和最小元素的差值之和 ////////////////////////////////////////

//https://leetcode-cn.com/problems/sum-of-subarray-ranges/solution/gong-shui-san-xie-yi-ti-san-jie-qu-jian-wn84z/
//假设有 m 个子数组，最终的表达式为 m 个等式 max−min 之和。
//若某个 nums[i]，如果在这 k1个子数组中充当最大值，则在最终等式中以 max 的形式出现 k1次，如果在 k2个子数组中充当最小值，则在最终等式中以 min 形式出现 k2次。
//因此我们可以统计每个 nums[i]成为区间最大值的次数 k1和成为区间最小值的次数 k2，(k1 - k2) * nums[i]为 nums[i] 对于最终答案的贡献。
//int main()
//{
//    vector<int> nums = { 1,3,3,1 };
//    int n = nums.size();
//    vector<int> lsmall(n, -1);//记录索引i左边第一个小于当前元素的位置
//    vector<int> rsmall(n, n);//记录索引i右边第一个小于当前元素的位置
//    vector<int> llarge(n, -1);//记录索引i左边第一个大于当前元素的位置
//    vector<int> rlarge(n, n);//记录索引i右边第一个大于当前元素的位置
//    stack<int> s;
//    // 从左往右单调增栈 不能出栈的时候栈顶就是当前元素左侧最近的小于当前元素的节点
//    for (int i = 0; i < n; i++) {
//        while (!s.empty() && nums[s.top()] >= nums[i]) {
//            rsmall[s.top()] = i;
//            s.pop();
//        }
//        if (!s.empty())
//        {
//            lsmall[i] = s.top();
//        }
//        s.push(i);
//    }
//    // 从右往左单调增栈 不能出栈的时候栈顶就是当前元素右侧最近的小于等于当前元素的节点
//    // ·注意这里是小于等于当前元素，因为数组有重复元素。
//    //例如对数组nums = { 1,3,3*,1* }，如果都取等号的话对第一个3有lsmall[1] = 0, rsmall[1] = 3;
//    //此时以第一个3为最小值的区间有1 * 2 = 2个分别是{(3), (3, 3*)}。对第二个3*有lsmall[2] = 0, rsmall[2] = 3；
//    //此时以第二个3*为最小值的区间有2 * 1 = 2分别是{(3, 3*), (3*)}。这里(3, 3*)就被重复计算了。 
//    //假如求rsmall时不取等号的话，rsmall[1]就等于2，此时以第一个3为最小值的区间就只有1个了即{（3）}
//    //再比如对第一个1，如果都取等号的话，有lsmall[0] = -1, rsmall[0] = n = 4 ;
//    //此时以第一个1为最小值的区间有1 * 4 = 4个，分别是{(1), (1, 3),(1, 3，3*),(1, 3，3*，1*)}。
//    //对第二个1*有lsmall[3] = -1, rsmall[3] = n =4 ；
//    //此时以第二个1*为最小值的区间有4 * 1 = 4个分别是{(1, 3，3*，1*),(3，3*，1*),(3*, 1*),(1*)}。这样(1, 3，3*，1*)就被重复计算了
//    //假如求rsmall时不取等号的话，rsmall[1]就等于3，此时以第一个1为最小值的区间就只有1 * 3 = 3个了，分别是{(1), (1, 3),(1, 3，3*)}。这样就保证了不重复
//    /*s = stack<int>();//这里合并到上面去了，所以不用这样写了
//    s.push(n);
//    for (int i = n - 1; i >= 0; i--) {
//        while (s.top() != n && nums[s.top()] > nums[i]) {
//            s.pop();
//        }
//        rsmall[i] = s.top();
//        s.push(i);
//    }*/
//
//    // 从左往右单调减栈 不能出栈的时候栈顶就是当前元素左侧最近的大于当前元素的节点
//    s = stack<int>();
//    for (int i = 0; i < n; i++) {
//        while (!s.empty() && nums[s.top()] <= nums[i]) {//同理
//            rlarge[s.top()] = i;
//            s.pop();
//        }
//        if (!s.empty())
//        {
//            llarge[i] = s.top();
//        }
//        s.push(i);
//    }
//
//    // 从右往左单调增栈 不能出栈的时候栈顶就是当前元素右侧最近的大于等于当前元素的节点
//    /*s = stack<int>();//合并到上面去了
//    s.push(n);
//    for (int i = n - 1; i >= 0; i--) {
//        while (s.top() != n && nums[s.top()] < nums[i]) {
//            s.pop();
//        }
//        rlarge[i] = s.top();
//        s.push(i);
//    }*/
//    long long ans = 0;
//    for (int i = 0; i < n; i++) {
//        ans += nums[i] * 1L * (i - llarge[i]) * (rlarge[i] - i);//nums[i]作为最大值的区间
//        ans -= nums[i] * 1L * (i - lsmall[i]) * (rsmall[i] - i);//nums[i]作为最小值的区间
//    }
//    cout << ans << endl;
//    return 0;
//}

//////////////////////////////////////////十进制转十六进制 ////////////////////////////////////////

//int main()
//{
//    string hex = "0123456789abcdef";
//    int num = -4;
//    binary_print(num);//打印32位二进制
//    if (num == 0)
//        cout<< "0";
//    binary_print((long long)num);//打印64位二进制
//    unsigned int n1 = (unsigned int) num;
//    //这里是因为进制转换都需要用辗转相除法，但是此法需要保证n始终大于0，所以当小于0的时候，我们需要将n转换成大于0的数，并且还要保证最后输出的十六进制相同
//    //由于n是负数，那么它的二进制高位就是1，也就是说我们如果直接把n转化成long long类型的话，其二进制高位补1，最后仍然表示一个负数，不能用辗转相除法
//    //方法一是将n转化成无符号数,直接转化成正数并且二进制形式不变
//    //方法二是将n转化成long long，但是不是强制类型转化，而是加上2^32，其实就相当于把int的负半轴搬到正半轴的右边，跨越的长度是INT_MIN+INT_MAX=2^32，然后用long long表示
//    long long n = num < 0 ? (long long)num + (1LL << 32) : num;
//    binary_print(1LL << 32);//打印64位二进制
//    binary_print(n);//打印64位二进制
//    binary_print(n1);//打印32位无符号二进制
//    string s;
//    while (n) {//辗转相除法
//        int mod = n % 16;
//        n /= 16;
//        s += hex[mod];
//    }
//    reverse(s.begin(), s.end());
//    cout << s << endl;
//}

//////////////////////////////////////////十进制转R进制模板 ////////////////////////////////////////

//int main()
//{
//    const int R = 7;
//    int num = -7;
//    const string words = "0123456789abcdef";
//    // 特判0
//    if (num == 0) {
//        cout << "0" << endl;;
//    }
//    // 处理负数
//    long long n = num;
//    string flag;
//    if (n < 0) {
//        flag = "-";
//        n = -n;
//    }
//    string s;
//    while (n) {
//        int idx = n % R;
//        n /= R;
//        s += words[idx];
//    }
//    reverse(s.begin(), s.end());
//    cout << flag + s << endl;
//    return 0;
//}

//////////////////////////////////////////得分最高的最小轮调次数 ////////////////////////////////////////

//https://leetcode-cn.com/problems/smallest-rotation-with-highest-score/solution/de-fen-zui-gao-de-zui-xiao-lun-diao-by-l-hbtd/1426046
//任何值小于或等于其索引的项都可以记作一分。在所有可能的轮调中，返回我们所能得到的最高分数对应的轮调下标 k 。如果有多个答案，返回满足条件的最小的下标 k ，0 <= nums[i] < nums.length
//每次移动的时候，值对应下标-1，首位到末位； 本来比下标小的依旧得分，本来等于下标的失分，本来大于下标的依旧不得分，本来在下标0的移到n-1处得分； 
//状态转移为f[k] = f[k-1] - (k-1步时值与下标相等的元素个数) + 1; 
//·要得到每个步数时值与下标相等的元素个数，可由每个元素移到与值相等的下标的步数O(N)得到；
//  step数组记录轮调到第i次时，有多少个nums[i]=i，这样下一次轮调就要减去这些，因为是向左轮调，i变小，下一轮不能得分
//int main()
//{
//    vector<int> nums = { 2, 3, 1, 4, 0 };
//    int res = 0, tmp = 0, k = 0, n = nums.size();//res记录遍历过程中的得分最大值，tmp记录每次的得分，k记录当前轮调的次数
//    vector<int> step(n, 0);//记录轮调到第i次时，有多少个nums[k]=k，这样下一次轮调就要减去这些，因为是向左轮调，k变小，下一轮不能得分
//    for (int i = 0;i < n;i++)
//    {
//        if (nums[i] <= i)
//        {
//            tmp++;//轮调0次时，得分初始值，相当于dp[0]
//            step[i - nums[i]]++;//如果nums[i] <= i，那么要想把nums[i]轮调到i位置，就需要从初始状态向左轮调(i-nums[i])轮，也就是轮调到i-nums[i]次时，初始的nums[i]就正好等于i
//                                //比如nums[2]=1，此时的 i=2，nums[i]=1,nums[i] <= i，那么想把nums[i]轮调到和它相等的位置上，就需要 i（2）-nums[i]（1）=1次
//                                //注意这里是累加，也就是说有另外一个j，使得 j-nums[j]=i-nums[i]，也就是轮调到i-nums[i]（j-nums[j]）次时，有两个数（nums[i],nums[j]）等于下标（i,j）
//        }
//        else
//        {
//            step[i + n - nums[i]]++;//如果nums[i] > i，那么就需要先把nums[i]轮调到下标0出，需要 i 次，然后把nums[i]从头（0）轮调到尾（n-1），需要 1 次；
//                                    //最后从尾（n-1）轮调到下标 nums[i] 处，需要 n-1-nums[i] 次，所以总共需要 i+1+n-1+nums[i]=i+n-nums[i] 次
//        }
//    }
//    res = tmp;//一定记住要记录下初始得分，这是dp[0]，不能遗漏
//    for (int i = 1;i < n;i++)
//    {//轮调 1 次到 n-1 次
//        tmp = tmp - step[i - 1] + 1;//step[i - 1]记录轮调 i-1 次时，有多少数与下标相等，则轮调 i 次后，这些数都大于下标了，不能算在本次得分里
//        if (tmp > res)
//        {//记录得分最大值和轮调次数
//            res = tmp;
//            k = i;
//        }
//    }
//}

//////////////////////////////////////////围成一圈的最大身高差的最小值 ////////////////////////////////////////

//https://www.nowcoder.com/test/question/done?tid=52841300&qid=104799#summary
//输入一组数作为孩子的身高，围成一个圆，找到所有相邻孩子最大身高差的最小值（不同排列会有不同的最大身高差，找到最小值）
//贪心，排序以后，序号间隔越小差值也越小，大的放中间小的放两边，如排序之后[2 3 4 5 6 7 8 9]就应该排列成[2 4 6 8 9 7 5 3],然后 2 和 3 再拉手就可以了
//int main() {
//    vector<int> h = { 8,9,7,6,5,4,3,2 };
//    int n = h.size();
//    sort(h.begin(), h.end());
//    int a = h[1] - h[0];//此时的h[1]和h[0]就是站在两边的高度差值，因为围成一圈以后他们相邻，比如例子里的 2 和 3
//    int b = h[n - 1] - h[n - 2];//此时的h[n-1]和h[n-2]就是站在中间的高度差值，因为围成一圈以后他们相邻，比如例子里的 8 和 9
//    int maxVal = max(a, b);
//    for (int i = 0; i < n - 2; i++) {
//        int c = h[i + 2] - h[i];//然后计算相邻的高度差，在排序数组里是相间的，比如 2 和 4、4 和 6...
//        maxVal = max(maxVal, c);//此时排列的最大身高差就是最大身高差的最小值
//    }
//    cout << maxVal<< endl;
//    return 0;
//}

//////////////////////////////////////////从两个数组中选出 k 个数，组成最大的数，数之间的相对位置不能变 ////////////////////////////////////////

//https://leetcode-cn.com/problems/create-maximum-number/solution/pin-jie-zui-da-shu-by-leetcode-solution/
//vector<int> picknum(vector<int>& num, int n)
//{//从num中选出 n 个数字，组成最大的数
//    if (n == 0)
//    {
//        return {};
//    }
//    vector<int> v;//用vector来代替栈，方便直接返回
//    int k = num.size() - n;//选出n个，也就是我们要删除 size-n 个
//    for (int i = 0;i < num.size();i++)
//    {
//        int ch = num[i];
//        while (v.size() > 0 && k > 0 && v.back() < ch)
//        {//要求组成最大的数，所以是递减队列
//            v.pop_back();
//            k--;
//        }
//        v.push_back(ch);
//    }
//    while (k > 0 && v.size() > 0)
//    {//如果删除的数还不够 k 个，就从末尾开始删，因为是递减数列
//        v.pop_back();
//        k--;
//    }
//    return v;
//}
//int compare(vector<int>& subsequence1, int index1, vector<int>& subsequence2, int index2) 
//{//比较两个数组，返回字典序更大或者长度更大的，index1和index2是比较的起始位置
//    int x = subsequence1.size(), y = subsequence2.size();
//    while (index1 < x && index2 < y) {
//        int difference = subsequence1[index1] - subsequence2[index2];
//        if (difference != 0) 
//        {//大于0表示subsequence1的字典序更大，小于0表示subsequence2的字典序更大
//            return difference;
//        }
//        index1++;
//        index2++;
//    }
//    return (x - index1) - (y - index2);//都相同就返回长度更大的，如果序列1更长，那么上面的循环结束时 index2 = y 而 index1 < x，那么此时返回大于0的数，代表序列1更长
//                                       //如果序列2更长，上面的循环结束时 index1 = x 而 index2 < y，那么此时返回小于0的数，代表序列2更长
//                                       //如果序列1和序列2完全相同，那么返回0，代表序列2更长（此时先选哪个都无所谓）
//}
//vector<int> addvec(vector<int>& a, vector<int>& b)
//{//融合两个数组，得到最大数
//    if (a.size() == 0)
//    {
//        return b;
//    }
//    if (b.size() == 0)
//    {
//        return a;
//    }
//    int i = 0, j = 0;
//    vector<int> res;
//    for (int k = 0; k < (a.size()+b.size()); k++) {
//        if (compare(a, i, b, j) > 0) //这里不能简单比较两个数，而应该把后续数字考虑进来，因为如果a[i]和b[j]是相同的，那么此时应该选后续数字更大的那个，比如【6,5】和【6,7,4】，第一个6相同
//                                     //我们不能直接选择某个6，如果选择第一个最后就是【6,6,7,5,4】，而正确的是【6,7,6,5,4】，应该先选第二个6，再比如【6,8】和【6,7,4】，如果先选第二个最后就是
//                                     //【6,7,6,8,4】，而正确的是【6,8,6,7,4】，所以要结合后续数字整体判断
//        {//数组a的数更大
//            res.push_back(a[i++]);
//        }
//        else {//数组b的数更大
//            res.push_back(b[j++]);
//        }
//    }
//    return res;
//}
//bool isValid(vector<int>& res, vector<int>& tmp)
//{//更新答案，字典序更大的作为答案，可以和compare合在一起
//    for (int i = 0;i < res.size();i++)
//    {
//        if (tmp[i] > res[i])
//        {
//            return true;
//        }
//        else if (tmp[i] < res[i])
//        {
//            return false;
//        }
//    }
//    return false;
//}
//int main()
//{
//    vector<int> nums1 ={ 6,7 };
//    vector<int> nums2 = { 6,7,4 };
//    int k = 5;
//    int m = nums1.size(), n = nums2.size();
//    vector<int> res;
//    for (int i = 0;i <= k;i++)
//    {//从nums1中选出 i 个数字，从nums2中选出 k-i 个数字
//        if (i > nums1.size() || (k - i) > nums2.size())
//        {
//            continue;
//        }
//        vector<int> a = picknum(nums1, i);
//        vector<int> b = picknum(nums2, k - i);
//        vector<int> tmp = addvec(a, b);//融合
//        if (res.size() == 0 || isValid(res, tmp))//更新答案
//        {
//            res = tmp;
//        }
//    }
//    for (auto& i : res)
//    {
//        cout << i << ' ';
//    }
//}

//////////////////////////////////////////重载、重写和覆盖的区别 ////////////////////////////////////////

//class Parent
//{
//public:
//    Parent()
//    {
//        cout << "Parent () " << endl;
//    }
//
//    ~Parent()
//    {
//        cout << "~Parent()" << endl;
//    }
//    virtual void vDis()
//    {
//        cout << "Parent::virtual void vDis()" << endl;
//    }
//    void Dis1()
//    {
//        cout << "Parent::void Dis1()" << endl;
//    }
//    void Dis2()
//    {
//        cout << "Parent::void Dis2()" << endl;
//    }
//    void Dis3(int a)
//    {
//        cout << "Parent::void Dis3(int a)" << endl;
//    }
//    virtual void Dis4(int a)
//    {
//        cout << "Parent::void Dis4(int a)" << endl;
//    }
//};
//
//class Child :public Parent
//{
//public:
//    Child()
//    {
//        cout << "Child" << endl;
//
//    }
//    ~Child()
//    {
//        cout << "~Child" << endl;
//    }
//    void vDis()
//    {
//        cout << "Child::void vDis()" << endl;
//    }
//    void Dis1(string s)
//    {
//        cout << "Child::void Dis1(string s)" << s << endl;
//    }
//    int Dis2()
//    {
//        cout << "Child::int Dis2()" << endl;
//        return 0;
//    }
//    int Dis3()
//    {
//        cout << "Child::int Dis3()" << endl;
//        return 0;
//    }
//    void Dis4(int a)
//    {
//        cout << "Child::void Dis4(int a)" << endl;
//    }
//};
//void Max(int a, int b)
//{
//    cout << "Max 1" << endl;
//}
//int Max(double a, double b)
//{
//    cout << "Max 2" << endl;
//    return 0;
//}
//int main()
//{
//    Child c;
//    c.vDis();//不同作用域，参数、返回值完全相同，构成 重写（虚函数多态）
//
//    c.Dis1("TEST");//不同作用域，参数不同，返回值相同，构成覆盖
//    c.Dis2();//不同作用域，参数相同，返回值不同，构成覆盖
//    c.Dis3();//不同作用域，参数不同，返回值不同，构成覆盖
//    c.Dis4(1);//不同作用域，参数相同，返回值相同，没有virtual关键字，构成覆盖
//
//    Max(1, 1);//同一作用域，不同参数，无论返回值是否相同，都构成重载
//    return 0;
//}

//////////////////////////////////////////从二叉树上去掉一个节点后，剩下各部分数量乘积最大值的次数 ////////////////////////////////////////

//https://leetcode-cn.com/problems/count-nodes-with-the-highest-score/solution/tong-ge-lai-shua-ti-la-liang-chong-xie-f-xu45/
//long help(int x) {
//    return x == 0 ? 1 : x;
//}
//int dfs(int node, vector<int>& left, vector<int>& right) {//返回以node为根节点的节点总数
//    if (node == -1) return 0;//-1表示NULL
//    int l = dfs(left[node], left, right);//以node左孩子为根节点的节点总数
//    int r = dfs(right[node], left, right);//以node右孩子为根节点的节点总数
//    int p = n - l - r - 1;//除了左孩子分支、右孩子分支和node以外的节点数目
//    long score = help(l) * help(r) * help(p);//任意分支如果是0，就要变成1，因为是乘法
//    if (score == maxscore) {//乘积最大值的次数
//        ++ans;
//    }
//    else if (score > maxscore) 
//    {//更新最大值，次数刷新
//        maxscore = score;
//        ans = 1;
//    }
//    return l + r + 1;//以node节点根节点的节点总数，用来当其他节点的孩子节点
//}
//long maxscore = 0;
//int ans = 0;
//int n;
//int main()
//{
//    vector<int> parents = { -1,2,0,2,0 };//i节点的父节点是parents[i]
//    n = parents.size();
//    vector<int> left(n, -1), right(n, -1);//i节点的左孩子和右孩子
//    for (int i = 1; i < n; ++i) {
//        int parent = parents[i];
//        if (left[parent] == -1) left[parent] = i;//先填充左孩子（其实左右都可以，不影响最终答案）
//        else right[parent] = i;
//    }
//    dfs(0, left, right);
//    cout << ans << endl;
//}

//////////////////////////////////////////从数组中遍历二叉树（前、中、后序） ////////////////////////////////////////

//// 前序 根,左,右
//void vis_pre(int* input, int inputLen, int root, vector<int>& ans) {
//    if (root >= inputLen) return;
//    if (input[root] == -1) return;
//    ans.push_back(input[root]);
//    vis_pre(input, inputLen, (root + 1) * 2 - 1, ans);
//    vis_pre(input, inputLen, (root + 1) * 2, ans);
//}
//// 中 左,根,右
//void vis_mid(int* input, int inputLen, int root, vector<int>& ans) {
//    if (root >= inputLen) return;
//    if (input[root] == -1) return;
//    vis_mid(input, inputLen, (root + 1) * 2 - 1, ans);
//    ans.push_back(input[root]);
//    vis_mid(input, inputLen, (root + 1) * 2, ans);
//}
//// 后 左,右，根
//void vis_pos(int* input, int inputLen, int root, vector<int>& ans) {
//    if (root >= inputLen) return;
//    if (input[root] == -1) return;
//    vis_pos(input, inputLen, (root + 1) * 2 - 1, ans);
//    vis_pos(input, inputLen, (root + 1) * 2, ans);
//    ans.push_back(input[root]);
//}
//int main()
//{
//    int array[] = { 1,7,2,6,-1,4,8 };//层次遍历结果
//    int len = 7;
//    vector<vector<int> > ans(3, vector<int>());
//    vis_pre(array, len, 0, ans[0]);
//    vis_mid(array, len, 0, ans[1]);
//    vis_pos(array, len, 0, ans[2]);
//}

//////////////////////////////////////////右值和转移构造函数 ////////////////////////////////////////

//class MetaData
//{
//public:
//    MetaData(int size, const std::string& name)
//        : _name(name)
//        , _size(size)
//    {}
//
//    // copy constructor  
//    MetaData(const MetaData& other)
//        : _name(other._name)
//        , _size(other._size)
//    {}
//
//    // move constructor  
//    MetaData(MetaData&& other)
//        : _name(other._name)
//        , _size(other._size)
//    {}
//
//    std::string getName() const { return _name; }
//    int getSize() const { return _size; }
//private:
//    std::string _name;
//    int _size;
//};
//class ArrayWrapper
//{
//public:
//    // default constructor produces a moderately sized array  
//    ArrayWrapper()
//        : _p_vals(new int[64])
//        , _metadata(64, "ArrayWrapper")
//    {}
//
//    ArrayWrapper(int n)
//        : _p_vals(new int[n])
//        , _metadata(n, "ArrayWrapper")
//    {}
//
//    // move constructor  
//    ArrayWrapper(ArrayWrapper&& other)
//        : _p_vals(other._p_vals)
//        , _metadata(other._metadata)//other是一个右值引用，右值引用是一个左值，也就是说它有固定内存，如果想用MetaData的转移构造函数的话，传入的参数应该是右值，这里就不符合
//                                    //实际上这里就会触发复制构造函数（传入参数为左值）
//    {
//        other._p_vals = NULL;
//    }
//
//    // copy constructor  
//    ArrayWrapper(const ArrayWrapper& other)
//        : _p_vals(new int[other._metadata.getSize()])
//        , _metadata(other._metadata)
//    {
//        for (int i = 0; i < _metadata.getSize(); ++i)
//        {
//            _p_vals[i] = other._p_vals[i];
//        }
//    }
//    ~ArrayWrapper()
//    {
//        delete[] _p_vals;
//    }
//private:
//    int* _p_vals;
//    MetaData _metadata;
//};

//////////////////////////////////////////加减二叉树的值正好等于 n ////////////////////////////////////////

//https://www.nowcoder.com/test/question/done?tid=53582087&qid=502455#summary
//输入:
//n=6  k=3
//输出
//1 -
//2 +
//5 +
//备注:1 <= n <= 10000000000,1 <= n <= 2 ^ k <= 2 ^ 60
//拿着数字0从根节点开始往下走，每次选择一条边移动，到达一个节点时选择加上这个节点的编号或者减去这个节点的编号。在走到第k个节点时，所得到的数字刚好为n，根节点编号为1。
//求经过的节点的 编号和 最小的路径
//int main() 
//{
//    long long n, k;//
//    vector<long long>ans;
//    //从最后一步开始往上走，最后一步的取值范围是[pow(2,k-1),pow(2,k))，也就是走k步一定到达二叉树的第k层，范围是[pow(2,k-1),pow(2,k))（k>=1）
//    //因为要求编号和 最小的路径，所以从最左边开始尝试
//    for (long long i = pow(2, k - 1);i < pow(2, k);i++) {
//        long long distance = n;    //记录当前的距离（也就是我们还需要多少才能填满n），每次换一个起点 i ，就刷新距离为 n 
//        long long level = i;    //记录当前的编号值
//        for (long long j = k;j > 0;j--) {    //记录步数（层数），从第k层往上走
//            if (distance > 0) 
//            {//如果之前填的不足以填满 n，也就是前一个 distance<n，那么就用此时的编号值再去填
//                distance -= level;
//                ans.push_back(level);//加上 这个编号值
//            }
//            else 
//            {//否则，前一个 distance>=n，那么就不能再去填了，只能减去此时的编号值，即使等于 n 也得减，因为此时还没有到达根节点
//                distance += level;
//                ans.push_back(-level);//减去 这个编号值
//            }
//            level = level / 2;    //往上走，父节点是孩子节点的二分之一
//        }
//        if (distance == 0)    //走到根节点，如果正好填满 n，那么说明找到了编号和 最小的路径，退出循环
//            break;
//        else
//            ans.clear();//否则，清空路径，从下一个 i 为起点开始查找
//    }
//    //打印结果
//    for (long long i = ans.size() - 1;i >= 0;i--) {
//        if (ans[i] > 0)
//            cout << ans[i] << " +" << endl;
//        else
//            cout << -ans[i] << " -" << endl;//注意输出 -ans[i]，因为ans里面减去的编号值是以负数的形式存在的，而输出要求是正数
//    }
//    return 0;
//}

//////////////////////////////////////////从原点走k步到达目标点所经过的斜线数量 ////////////////////////////////////////

//https://www.nowcoder.com/test/question/done?tid=53582087&qid=502456#summary
//从(0,0)恰好k步走到点(x,y)，中途可以经过任何点包括（x,y），但是第k步一定要到达（x,y），可以走8个方向，统计走过的斜线最多的数量。不能到达输出-1
//int main() {
//    int T;//T是测试次数
//    long long x, y, k, ans;//x，y是终点坐标，k是剩余步数，ans是经过的斜线数量
//    scanf("%d", &T);
//    while (T--) {
//        scanf("%lld%lld%lld", &x, &y, &k);
//        if (x > y) 
//        {//统一把 y 变成最大值，因为是对称的，走到(x,y)的路径和走到(y,x)的路径一模一样
//            swap(x, y);
//        }
//        if (y > k) 
//        { //要到达目的地花费的最小步数是 y ，如果 k 小于 y 就一定到不了
//            cout<<"-1"<<endl;
//            continue;
//        }
//        //k-x 代表走到(x,x)还剩下的步数，(y-x)代表(x,y)与(x,x)的直线距离，当（y-x）是偶数且（k-x）是偶数时，一定能从(x,x)走斜线到达(x,y)，所以答案最大值是 k 
//        ans = k;
//        if ((y - x) % 2) 
//            ans--; // 当（y-x）是奇数且无论（k-x）是多少时，一定能从(x,x)走斜线到达(x,y)上下左右的一点，然后走一条直线到达(x,y)，所以答案是 k-1 
//        else if ((k - x) % 2) 
//            ans -= 2;// // 当（y-x）是偶数且（k-x）是奇数时，全走斜线的话要么提前到达(x,y)，要么永远到不了(x,y)，所以要用两条直线去走一条斜线的路程，答案是 k-2 
//        printf("%lld\n", ans);
//    }
//    return 0;
//}

//////////////////////////////////////////一个很大的整数经过奇数加一偶数折半最后变成1的操作次数 ////////////////////////////////////////

//https://www.nowcoder.com/questionTerminal/442cbe24e08447729543510c2eb47082?source=relative
//int main()
//{
//    int N[128] = { 0 };//用来存放一个很大的数，每一位代表10进制数的每一位，N(1<=N<=10^100)
//    char temp;
//    int begin = 0, end = 0, res = 0;
//    while (scanf("%c", &temp))
//    {
//        if (temp == '\n')
//            break;
//        N[end] = temp - '0';
//        end++;
//    }
//    while (!(begin == end - 1 && N[end - 1] == 1))
//    {//end-1代表个位，end始终指向比个位还要低的位置（相当于end()）。begin代表最左边的非零元素的位置
//        //这个判断条件代表 除了个位以外其他位都是0，也就是这个数就是 1
//        if (N[end - 1] & 1)
//        {//个位是奇数，所以要+1，变成偶数，打响指次数加1
//            N[end - 1]++;//不用管这里需不需要向前进位，因为进位高位加1和不进位低位是10所表示的数是一样大的，并且数学原则保持一致，加减乘除全都正常运算
//                         //比如 8 7 9 9，末尾加一变成8 7 9 10，除以 2 以后变成4 3 9 10 ，再除以 2 变成2 1 9 10，再除以 2 变成1 0 9 10，再除以 2 变成0 5 4 10，再除以 2 变成2 7 5，经过 5 次变换，
//                         //而8 8 0 0 ，除以 2 以后变成4 4 0 0，再除以 2 变成2 2 0 0，再除以 2 变成1 1 0 0，再除以 2 变成0 5 5 0，再除以 2 变成2 7 5，经过 5 次变换
//                         //从理论上看，8 7 9 10 换算成10进制就是： 10*1+9*10+7*100+8*1000=8800，而8 8 0 0同样是8800
//            res++;
//        }
//        int flag = 0, tempV = 0;
//        res++;//此时这个数变成了一个偶数，下面的for循环就是把这个偶数折半，打响指次数+1
//        for (int i = begin; i < end; i++)
//        {//从非0的最高位开始，如果这一位是偶数，则直接除以2，并且不会出现除不尽而需要和后面低位的数值合起来判断的情况
//            //但如果这一位是奇数，那么除以2肯定除不尽，需要加上低位的数值再次判断，flag就是用来判断前面的高位是否能够除尽
//            //能除尽flag就是 0，除不尽就是 1，然后乘以10，代表它是高位除以2的“余数”
//            //比如 8 7 9 4，第一位是8，偶数能除尽，flag=0，这一位变成 4，
//            // 第二位是 7 ，奇数除不尽，flag变成 1，这一位变成 3
//            // 第三位是 9，此时的flag=1，表示高位除不尽，则temp变成 9+10=19，仍然是奇数，除不尽，flag还是1，这一位变成 9
//            // 第四位是 4，此时的flag=1，表示高位除不尽，则temp变成 4+10=14，是偶数，flag变成0，这一位变成 7 
//            // 整体来看8 7 9 4 变成了 4 3 9 7，符合预期。
//            tempV = N[i] + flag * 10;
//            flag = tempV & 1;
//            N[i] = tempV / 2;
//        }
//        if (N[begin] == 0)//最高位如果是0了，就不需要在考虑它了，向低位递进，直到最后一位变成 1 ，其他位全是 0
//            begin++;
//    }
//    cout << res;
//    return 0;
//}

//////////////////////////////////////////用一支、两支、三支雪糕支撑n天，每天吃6根雪糕////////////////////////////////////////

//https://www.nowcoder.com/questionTerminal/5d314ef72996433da302d46df12ceb9f?f=discussion
//int main()
//{
//    int n= 3, x=0, y=2, z=5;//n是总天数，x是单支雪糕的个数，y是双支雪糕的个数，z是三支雪糕的个数
//    if (x + 2 * y + z * 3 < 6 * n)
//    {//每天需要吃6支雪糕，多了少了都不行，如果雪糕总数不够 6*n，输出No
//        cout << "No" << endl;
//        return 0;
//    }
//    n -= y / 3;//先吃双支雪糕，3个双支雪糕能吃一天，所以就减去 y 里面有几个 3
//    y %= 3;//双支雪糕还剩下多少个
//    n -= z / 2;//再吃三支雪糕，2个三支雪糕能吃一天，所以就减去 z 里面有几个 2
//    z %= 2;//三支雪糕还剩下多少个
//    if (n <= 0)
//    {//减完之后看n是否已经结束了，没结束就继续
//        cout << "Yes" << endl;
//        return 0;
//    }
//    // 此时的n是还剩下的天数（n≥1），总共还需要 6*n 支雪糕，y是还剩下的双支雪糕的个数（0≤y≤2），z是还剩下的三支雪糕的个数（0≤z≤1），n * 6 - y * 2 - z * 3 就是缺的雪糕数
//    // 如果 n * 6 - y * 2 - z * 3＜0，表示虽然需要的雪糕总数小于双支、三支雪糕的总数，但是 y 和 z都无法凑出完整的 6 来，因为 y取值0 1 2，z 取值0 1，可以凑出的雪糕数为 0，2，4，3，5, 7
//    // 而要使得 n * 6 - y * 2 - z * 3＜0 成立，只有n=1，y=2，z=1，此时能凑出7支雪糕，不满足每天6支的要求
//    // 当 n * 6 - y * 2 - z * 3＞0 时，剩下的就可以用一支雪糕的数量来弥补，所以就看一支雪糕的数量x是否足够
//    if (n * 6 - y * 2 - z * 3 > 0 && n * 6 - y * 2 - z * 3 <= x)
//    {
//        cout << "Yes" << endl;
//        return 0;
//    }
//    else
//    {
//        cout << "No" << endl;
//    }
//    return 0;
//}

//////////////////////////////////////////左值、右值和引用的绑定关系///////////////////////////////////////

//int main()
//{
//    //const int& a = 1;//常量左值引用绑定右值
//    //int&& b = 1;//右值引用绑定右值
//    //cout << b << endl;//输出 1 
//    ////a = 2;//ERROR，表达式必须是可修改的左值
//    //b = 2; //正确，右值引用是左值，并且可修改
//    //cout << b << endl;//输出 2，成功改变右值 
//    int x = 1;
//    const int* p = &x;
//    x++;
//    cout << x << endl;
//}

//////////////////////////////////////////完美转发（例一）///////////////////////////////////////

//template<typename T>
//void print(T& t) {
//    std::cout << "Lvalue ref" << std::endl;
//}
//
//template<typename T>
//void print(T&& t) {
//    std::cout << "Rvalue ref" << std::endl;
//}
//
//template<typename T>
//void testForward(T&& v) {
//    print(v);//v此时已经是个左值了,永远调用左值版本的print
//    print(std::forward<T>(v)); //本文的重点,v是左值引用就转发左值引用，v是右值引用就转发右值引用
//    print(std::move(v)); //永远调用右值版本的print
//
//    std::cout << "======================" << std::endl;
//}
//
//int main(int argc, char* argv[])
//{
//    int x = 1;
//    testForward(x); //实参为左值，T推导为
//    testForward(std::move(x)); //实参为右值
//}

//////////////////////////////////////////完美转发（例二）///////////////////////////////////////

//void rvalue_call(int& v) {
//    cout << "& call" << endl;
//}
//void rvalue_call(int&& v) {
//    cout << "&& call" << endl;
//}
//void rvalue_call(const int& v) {
//    cout << "const & call" << endl;
//}
//void rvalue_call(const int&& v) {
//    cout << "const && call" << endl;
//}
//
//template<typename T>
//void func(T&& a) {
//    rvalue_call(std::forward<T>(a));
//}
//
//int main(void) {
//    int x = 1;
//    func(x);//实参为左值，推导 T 为 int&，折叠后 a 为 int&                                         
//    int& y = x;
//    func(y);//实参为左值引用，推导 T 为 int&，折叠后 a 为 int&                                       
//    func(std::move(y));//实参为右值引用，推导 T 为 int&&，折叠后 a 为 int&&                            
//    func(100);//实参为右值，推导 T 为 int&&，折叠后 a 为 int&&
//
//    const int a = 11;
//    func(a);//实参为const左值，推导 T 为 const int&，折叠后 a 为  const int&             
//    func(std::move(a));//实参为const右值，推导 T 为 const int&&，折叠后 a 为  const int&&
//}

//////////////////////////////////////////有序矩阵中的第 k 个最小数组和(二分）///////////////////////////////////////

//https://leetcode-cn.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/solution/er-fen-by-newbie-19-3/
//void dfs(vector<vector<int>>& mat, int mid, int index, int sum, int& num, int k, int m, int n) 
//{//mid是预设的数组和，index是当前遍历到的行号，从0开始，sum是当前的数组和，num表示小于等于mid的数量，从1开始，因为init是最小的，一定小于mid
//    // 注意·num是引用传递，每一层指针改变都会增大num的值
//    if (index == m || num > k) 
//        return;//我们不断挪动每一层的指针，从最底层开始挪动，并且计算小于等于mid的数组和数量，如果数量已经够了(num>k)，那么就不用再挪任何层的指针了，直接返回
//    //我们想从最后一行开始往右查找，所以先到达最下一层，让它往右递增，此时上面的所有层都还在0的位置；然后挪动倒数第二层的指针，向右递增
//    //比如 0  0  0  0  0  0  0  0  0  1  1  1  1  1  1  1  1  1  2  2  2  2  2  2  2  2  2 按照这个顺序去计算sum的，注意第一列已经算过了（init一定小于mid，所以num从1开始）
//    //     0  0  0  1  1  1  2  2  2  0  0  0  1  1  1  2  2  2  0  0  0  1  1  1  2  2  2
//    //     0  1  2  0  1  2  0  1  2  0  1  2  0  1  2  0  1  2  0  1  2  0  1  2  0  1  2
//    dfs(mat, mid, index + 1, sum, num, k, m, n);
//    for (int i = 1;i < n;i++) 
//    {//这里i从1开始，如果从0开始的话，第一列的init就被重复计算了,导致的结果是：mid尽管小于sum(ans)，但是由于init的重复计算，小于等于mid的数组和个数仍然大于等于 k，向左缩小范围，导致错误
//        if (sum + mat[index][i] - mat[index][0] <= mid) 
//        {//这里算的是增量，起始是init
//            num++;
//            dfs(mat, mid, index + 1, sum + mat[index][i] - mat[index][0], num, k, m, n);
//        }
//        else 
//        {//当前层的指针已经不能再往右移了，退出循环
//            break;
//        }
//    }
//}
//int main()
//{
//    vector<vector<int>> mat = { {1, 10, 10},{1, 4, 5},{2, 3, 6} };
//    int k = 7;
//    int m = mat.size(), n = mat[0].size();
//    int left = 0, right = 0;
//    for (int i = 0;i < m;i++) 
//        left += mat[i][0], right += mat[i].back();//左边界是第一列之和，右边界是最后一列之和
//    int init = left;//这个值是用来帮助我们找到数组和小于等于 k 的个数
//    int ans=0;    
//    while(left<=right) 
//    {//假设的一个数组和，计算小于等于mid的个数，如果小于k，说明mid应该更大（mid也排除了），所以left=mid+1，如果大于等于k，说明mid正好或者太大了（mid有可能是答案），所以right=mid
//        //mid是有可能不存在与数组中的，但是我们通过right=mid-1不断收缩空间，最后的答案一定在数组中，因为题目保证了答案一定存在，所以一定有一个sum是第k小的数组和
//        //因此，sum一定满足：小于等于sum的数组和有 k-1 个，如果我们最后假设的 mid 不存在并且 mid> sum(ans)，那么二分循环一定没有结束，一定可以 right=mid -1再次缩小范围
//        int mid = (left + right) >> 1;
//        int num = 1;//表示mid是第num小的数组和，也就是说比mid小或等的数组和有 num-1 个，从1开始，因为init是最小的，一定小于mid
//        dfs(mat, mid, 0, init, num, k, m, n);
//        if (num >= k) 
//        {
//            ans=mid;
//            right = mid - 1;
//        }
//        else 
//            left = mid + 1;
//    }
//    cout << ans << endl;
//    return 0;
//}

//////////////////////////////////////////shared_ptr 的用法///////////////////////////////////////

//int main()
//{
//    string* s1 = new string("s1");
//
//    shared_ptr<string> ps1(s1);
//    shared_ptr<string> ps2;
//    ps2 = ps1;
//
//    cout << ps1.use_count() << endl;	//2
//    cout << ps2.use_count() << endl;	//2
//    cout << ps1.unique() << endl;	    //0
//
//    string* s3 = new string("s3");
//    shared_ptr<string> ps3(s3);
//
//    cout << (ps1.get()) << endl;	//033AEB48
//    cout << ps3.get() << endl;	//033B2C50
//    swap(ps1, ps3);	//交换所拥有的对象
//    cout << (ps1.get()) << endl;	//033B2C50
//    cout << ps3.get() << endl;	//033AEB48
//
//    cout << ps1.use_count() << endl;	//1
//    cout << ps2.use_count() << endl;	//2
//    cout << ps3.use_count() << endl;	//2
//    weak_ptr<string> pw1(ps1);
//    cout << pw1.use_count() << endl;	//1
//    cout << ps1.use_count() << endl;	//1，weak_ptr不会影响对应的 ps1 内部对象的计数
//    ps2 = ps1;	//ps1对象的引用计数加1，ps2对象的引用计数减1，此时ps1和ps2指向的对象相同，所以ps1.use_count()=2，ps2.use_count()=2，原本ps2指向对象的引用计数减1，也就是 ps3.use_count()=1
//    cout << ps1.use_count() << endl;	//2
//    cout << ps2.use_count() << endl;	//2
//    cout << ps3.use_count() << endl;	//1
//    ps1.reset();	//放弃ps1的拥有权，引用计数的减少
//    cout << ps1.use_count() << endl;	//0
//    cout << ps2.use_count() << endl;	//1
//    cout << ps3.use_count() << endl;	//1
//}

//////////////////////////////////////////weak_ptr 的用法///////////////////////////////////////

//class B;	//声明
//class A
//{
//public:
//    weak_ptr<B> pb_;
//    ~A()
//    {
//        cout << "A delete\n";
//    }
//};
//
//class B
//{
//public:
//    shared_ptr<A> pa_;
//    ~B()
//    {
//        cout << "B delete\n";
//    }
//};
//
//void fun()
//{
//    shared_ptr<B> pb(new B());
//    shared_ptr<A> pa(new A());
//    cout << pb.use_count() << endl;	//1
//    cout << pa.use_count() << endl;	//1
//    pb->pa_ = pa;
//    pa->pb_ = pb;
//    cout << pb.use_count() << endl;	//1,因为pa->pb_ 是一个weak_ptr，不会影响引用计数
//    cout << pa.use_count() << endl;	//2
//    shared_ptr<B> p = pa->pb_.lock();
//    cout << pb.use_count() << endl;	//2,因为p是由weak_ptr pb_创建的shared_ptr，会影响 B 的引用计数
//}
//
//int main()
//{
//    fun();//能正确析构，因为p是由weak_ptr pb_创建的shared_ptr，所以当 pb_ 释放时，p也会释放，再加上 pb 也释放了，所以 B 的引用计数为0，析构 
//    return 0;
//}

//////////////////////////////////////////密码生成器//////////////////////////////////////

//https://www.nowcoder.com/questionTerminal/96bf0c548a094de7a05919e0b32b1a5a?orderByHotValue=1&mutiTagIds=659&page=1&onlyReference=false
//密码生成器由 N 个槽位组成，槽位的下标为 0~N - 1 ，每个槽位存储一个数。起初每个槽位都是 0 。
//密码生成器会进行 M 轮计算，每轮计算，小汪会输入两个数 L, R(L <= R), 密码生成器会将这两个数作为下标，将两个下标之间（包含）的所有槽位赋值为 i（ i 为当前的轮次， i ∈[1, M]）。
//M轮计算完成后，密码生成器会根据槽位的最终值生成一条密码，密码的生成规则为：
//（0* a[0] + 1 * a[1] + 2 * a[2] + ... + (N - 1) * a[N - 1]) mod 100000009
//其中a[i]表示第i个槽位的最终值。
//struct node
//{
//    int L, r, v;
//    bool operator <(const node& b) const 
//    {//这里重载小于号是为了优先队列排序
//        return this->v < b.v;
//    }
//};
//int main()
//{
//    int n, m;//长度为n，总计m轮
//    while (cin >> n >> m)//正确输入n，m才会进入程序
//    {
//        vector<int> v = vector<int>(n);//记录最终每个位置的数
//        vector<node> tmp;//node表示从[node->L:node->r]这些位置的值都是node->val,tmp用来记录这些node
//        for (int i = 1; i <= m;i++)
//        {
//            int a, b;
//            cin >> a >> b;
//            node now;
//            now.L = a;
//            now.r = b;
//            now.v = i;
//            tmp.push_back(now);
//        }
//        sort(tmp.begin(), tmp.end(), [](const node& a, const node& b)
//            {
//                return a.L < b.L;
//            });//按照起点位置从小到大排序
//        priority_queue<node> q;//记录每个位置上有哪些node，然后从大到小排序
//        int pos = 0;
//        for (int i = 0; i < n; i++)
//        {//对于每个位置 i，找到最终的值
//            while (i >= tmp[pos].L && i <= tmp[pos].r && pos < m)
//            {//对于位置 i 来说，如果 tmp[pos] 这个 node 包含 i ，也就是 L<=i<=r 那么就把它加入优先队列，
//              //然后考察下一个 node，当某个 node 起点大于 i 或者终点小于 i，说明node不能覆盖i，结束循环，
//              //开始找 i 这个位置的最大值
//                q.push(tmp[pos]);
//                pos++;
//            }
//            while (!q.empty())
//            {//找最大值
//                node now = q.top();
//                if (now.r < i)
//                {//这里还要判断一次，终点是否小于 i，因为尽管上面的循环我们只加入了覆盖 i 的 node 结点，保证了i一定在 node 的范围内，但是这个优先队列并不一定是只用来计算 i 这个位置的
//                    //还用来计算 i+1，i+2...这些位置，如果在这些位置没有新的 node 加入优先队列，而优先队列只保证了起点小于 i+1（加入优先队列的 node起点小于等于 i，则一定小于 i+1），
//                    //不能保证终点一定大于等于 i+1，这就需要判断，如果终点小于 i（这个 i 是新一轮的 i了，也就是我们说的 i+1），那么队首元素不能要。
//                    q.pop();
//                }
//                else
//                {//反之，node 可以覆盖 i ，取出最大值即可，因为值越大代表轮数越靠后，最大值代表最后一次转动 i 位置
//                  //就代表了 i 位置的最终值，直接break
//                    v[i] = now.v;
//                    break;
//                }
//            }
//        }
//        long long ans = 0;
//        for (int i = 0;i < n; i++)
//        {//计算最终值
//            ans += i * v[i];
//            ans %= 100000009;
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

////////////////////////////////////////////function包装各种可调用对象///////////////////////////////////////

////********************普通函数*******************
//int fun1(int a) {
//    return a;
//}
////********************函数指针*******************
//int (*fun_ptr)(int);
////********************模板函数*******************
//template<typename T>
//T fun2(T a) {
//    return a;
//}
////********************lamda表达式*******************
//auto fun3 = [](int a) {return a;}; //lamda表达式
////********************对象函数*******************
//struct fun4 {
//    int operator()(int x) {
//        return x;
//    }
//};
////********************模板对象函数*******************
//template <typename T>
//struct fun5 {
//    T operator()(T a) {
//        return a;
//    }
//};
////********************对象静态函数*******************
//struct fun6 {
//    static int foo(int a) {
//        return a;
//    }
//};
////********************模板对象静态函数*******************
//template <typename T>
//struct fun7 {
//    static T foo(T a) {
//        return a;
//    }
//};
////********************对象成员函数*******************
//struct fun8 {
//    int foo(int a) {
//        return a;
//    }
//};
////********************模板对象成员函数*******************
//template <typename T>
//struct fun9 {
//    T foo(T a) {
//        return a;
//    }
//};
//int main(int argc, char* argv[]) {
//    cout << "Hello world" << endl;
//    function<int(int)> callback;//可调用对象的输入是一个int参数，返回值也是一个int
//
//    callback = fun1; //std::function包装普通函数
//    cout << callback(1) << endl; //std::function对象实例调用包装的调用实体
//    //输出 1
//
//    fun_ptr = fun1; //函数指针fun_ptr指向fun1函数
//    callback = fun_ptr; //std::function对象包装函数指针
//    std::cout << callback(1) << std::endl; //std::function对象实例调用包装的实体
//    //输出 1
//
//    callback = fun2<int>; //std::function包装模板函数
//    cout << callback(2) << endl; //std::function对象实例调用包装的调用实体
//    //输出 2
//
//    callback = fun3; //std::function包装lamda表达式
//    cout << callback(3) << endl; //std::function对象实例调用包装的调用实体
//    //输出 3
//
//    callback = fun4(); //std::function包装对象函数
//    cout << callback(4) << endl; //std::function对象实例调用包装的调用实体
//    //输出 4
//
//    callback = fun5<int>();//std::function包装模板对象函数
//    cout << callback(5) << endl;//std::function对象实例调用包装的调用实体
//    //输出 5
//
//    callback = fun6::foo;//std::function包装对象静态函数
//    cout << callback((double)6.3) << endl; //std::function对象实例调用包装的调用实体,强制类型转换也只能输出整数 6，因为callback只接受以int为参数，会强制转换成int
//    //输出 6
//
//    callback = fun7<int>::foo;//std::function包装模板对象静态函数
//    cout << callback(7) << endl;//std::function对象实例调用包装的调用实体
//    //输出 7
//
//    fun8 test_fun;
//    callback = bind(&fun8::foo, test_fun, placeholders::_1);//std::function包装类成员函数
//    cout << callback(8) << endl;//std::function对象实例调用包装的调用实体
//    //输出 8
//
//    fun9<double> test_fun1;//尽管模板类声明了是一个double，并且传入参数也是double，但是callback只接受以int为参数，会强制转换成int
//    callback = bind(&fun9<double>::foo, test_fun1, placeholders::_1);//std::function包装模板类成员函数
//    cout << callback(9.2) << endl;//std::function对象实例调用包装的调用实体
//    //输出 9
//
//    function<int(int)> callback2 = callback; //拷贝赋值运算符
//    cout << callback2(10) << endl;
//    //输出 10
//
//    function<int(int)>&& callback3 = move(callback); //移动赋值运算符
//    cout << callback3(10) << endl;
//    //输出 10
//
//    function<int(int)> callback4(callback); //拷贝
//    cout << callback4(10) << endl;
//    //输出 10
//
//    return 0;
//}

////////////////////////////////////////////小于等于n 的字典序排列///////////////////////////////////////

//https://leetcode-cn.com/problems/lexicographical-numbers/solution/by-ac_oier-ktn7/
//vector<int> res;
//void getprefix(int cur, int n)
//{
//    if (cur > n)
//    {
//        return;
//    }
//    res.push_back(cur);
//    for (int i = 0;i <= 9;i++)
//    {
//        getprefix(cur * 10 + i, n);
//    }
//}
//int main()
//{
//    int n = 253;
//    vector<int> res;
//    int curr = 1;//curr表示当前的数是多少
//    //for (int i = 1;i <= 9;i++)
//    //{
//    //    getprefix(i,n);//递归做法，要求空间复杂度O（1），所以不能用递归
//    //}
//    for (int i = 0;i < n;i++)
//    {//小于等于n的数一共有n个，每次添加一个
//        res.push_back(curr);
//        if (curr * 10 <= n)
//        {//以curr为前缀的下一层数的最左边的数（也就是以curr为前缀的下一层数的最小值）小于等于n，说明可以进去下一层，则 curr*10
//            //比如curr=1，curr*10=10<253,进入下一层，curr=10，curr*10=100<253，进入下一层，curr=100,curr*10=1000>253,不能进入下一层
//            curr *= 10;
//        }
//        else
//        {//如果无法进入下一层，那么就遍历本层小于等于n的所有值，直到 本层遍历完成 或者 遇到 n
//            while (curr % 10 == 9 || curr + 1 > n)
//            {//curr % 10 == 9说明前缀需要加1（因为是字典序），curr + 1 > n 说明遇到了上界n，那么就不能继续在本层遍历了。
//                //这里不能是if，因为if只能往上走一层，而有的时候我们需要往上走多层，比如 curr=199 的时候，如果用if，那么下一个遍历的数是 20，而在字典序中，199 后面的数应该是 2，2 后面才应该是20
//                //也就是说，每次一个前缀遍历到了终点，就应该从最上层的前缀开始加 1 重新遍历,199就是以 1 为前缀的终点，所以要回到 1 这一层加 1 而不是在 19 这一层加 1
//                curr /= 10;//回到上一层，比如199/10=19,19/10=1
//            }
//            curr++;//最上层的前缀加 1
//        }
//    }
//    for (auto& i : res)
//    {
//        cout << i << ' ';
//    }
//    return 0;
//}

////////////////////////////////////////////字典序的第k个最小值///////////////////////////////////////

//https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/solution/ben-ti-shi-shang-zui-wan-zheng-ju-ti-de-shou-mo-sh/
//int getSteps(int prefix, long n) {
//    int cnt = 0;//记录以当前curr为前缀的小于等于n的数有几个
//    long cur = prefix;//当前的前缀
//    long next = prefix + 1;//下一个前缀，以当前的前缀为前缀的数在字典序中一定小于下一个前缀，那么next就是上界，取不到
//    while (cur <= n) 
//    {//当前的前缀小于等于n，说明可以往下一层搜索
//        cnt += min(next, n + 1) - cur;//当 next 的值大于上界的时候，那以这个前缀为根节点的十叉树就不是满十叉树了，应该只到上界那里，后面都不再有节点了。因此只取上界和n+1的较小值
//                                      //为什么是 n+1？因为 13-11=2，但实际上小于等于n的数有 11 12 13 三个，所以要 n+1
//        cur *= 10;//逐层增加
//        next *= 10;
//        // 如果说刚刚cur是1，next是2，那么现在分别变成10和20
//       // 1为前缀的子节点增加10个，十叉树增加一层, 变成了两层
//
//       // 如果说现在cur是10，next是20，那么现在分别变成100和200，
//       // 1为前缀的子节点增加100个，十叉树又增加了一层，变成了三层
//    }
//    return cnt;
//}
////将小于等于n的数按照字典序从小到大排列，找到第k个最小值，比如n=13，字典序的排列是 [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]
//int main() 
//{
//    int n = 13, k = 5;
//    int curr = 1;//curr表示当前的前缀，初始化为 1
//    int p = 1;//p表示当前找的是第 p 个最小值
//    while (p < k) 
//    {//当 p=k-1 时，循环里最开始（没有乘10或自加的）的curr就是第 p （此时的 p 也没有自加，也就是p=k-1）个最小值，而循环里最终的 curr 就是第 p（这里也是最终自加后的p，也就是p=k） 个最小值。
//        //比如 p=1，最开始的curr=1，他是第 1 个最小值，然后最终的curr*10=10，最终的 p = 2 ，也就是 10 是 第 2 个最小值
//        int steps = getSteps(curr, n);//以当前curr为前缀的小于等于n的数有几个
//        if (p + steps > k) 
//        {//如果当前找到的 最小值数量大于 k 了，说明第 k 个最小值就在以 curr 为前缀某一层中，则 curr*=10，进入下一层，
//            //比如1*10=10，判断以 10 为前缀的数量，10就是第 p 个最小值（这里的 p 是自增后的 p，此时已经是 2 了）
//            //为什么不是大于等于？因为 steps里面重复计算了一个前缀，真正找到的小于等于 n 的数其实只有 p + steps -1 个，因此
//            //必须保证 p + steps>k 或者p + steps -1>=k才能在下一层中寻找，比如 p=1 时，找到的steps=5,包括（1,10,11,12,13）
//            //p+steps=6，说明我们找到了6个最小值，但其实只找到了5个，这时如果我们要找地6个最小值，那么一定不能往下一层寻找
//            //因为往下一层最多只能找到前 5 个最小值，不可能找到第6个
//            curr *= 10;
//            p++;//此时我们判断出第 k 个最小值就在以 curr 为前缀某一层中，只能保证当前的 curr （还没有进入下一层）是满足条件的，p 加 1
//                //也就是下一次循环找的是第 p+1 个最小值（其实可以理解为 验证此时增加后的 curr 是不是第 p+1 个最小值）
//        }
//        else
//        {//否则，以 curr 为前缀的最小值数量仍然小于等于 k ，那么就要把以 curr 为前缀的所有数加入 p，然后换一个更大的前缀。比如1+1=2，判断以 2 为前缀的数量，2 就是第 p+steps+1 个最小值
//            curr++;
//            p += steps;
//        }
//    }
//    cout<<curr;//当 p=k 的时候退出了循环，此时的curr就是第 k 个最小值 
//}

////////////////////////////////////////////数组指针和指针数组///////////////////////////////////////

//int main()
//{
//    int* p[3];//指针数组，有三个指针的数组
//    int(*q)[4];//数组指针，指向一个长度为4的数组的指针
//    int a[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };//二维数组
//    for (int i = 0;i < 3;i++)//指针数组需要单独赋值，不然不可用
//        p[i] = a[i];
//    q = a;//数组指针直接赋值，这里a是整个二维数组的地址，也是首元素a[0][0]的地址
//
//    cout << sizeof(p) << endl;//p是一个数组，64位机器上占用 3×8 =24 字节空间
//    cout << sizeof(q) << endl;//q是一个指针，64位机器上占用 8 字节空间
//
//    cout << a << endl;//数组名a可以直接代表它的地址  000000BED98FF848
//    cout << &a << endl;//数组地址  000000BED98FF848
//    cout << &a[0][0] << endl;//首元素a[0][0]的地址  000000BED98FF848，三个完全相同
//
//    cout << p << endl;//一维数组同理 000000BED98FF7F8
//    cout << &p << endl;// 000000BED98FF7F8
//    cout << &p[0] << endl;// 000000BED98FF7F8，三个完全相同
//
//    cout << p[0] << endl;//p[0]指向a数组的第0行，所以p[0]的值和 a 数组第0行的地址相同，也就是 p[0] = a = &a = a[0][0] =000000BED98FF848
//
//    cout << *(p[0]+1) << endl;//第0行第1个元素
//    cout << *(*q+1) << endl;//第0行第1个元素
//    cout << *(*(p+1) + 1) << endl;//第1行第1个元素
//    cout << *(*(q+1) + 1) << endl;//第1行第1个元素
//    
//}

////////////////////////////////////////////n！中尾0的个数///////////////////////////////////////

//https://leetcode-cn.com/problems/factorial-trailing-zeroes/solution/xiang-xi-tong-su-de-si-lu-fen-xi-by-windliang-3/
// n! 尾零的数量即为 n! 中因子 10 的个数，而 10 = 2×5，因此转换成求 n! 中质因子 2  的个数和质因子 5 的个数的较小值（用一个 2 和一个 5 凑出一个10，看看最多凑出多少个）。
//由于质因子 5 的个数不会大于质因子 2 的个数（比如 n=5 出现了 2,2*2=4 三个质因子2，而只出现了 5 一个质因子5），我们可以仅考虑质因子 5 的个数
//实际上就是计算1 - n之中有多少个 包含不同个数的因数5 的数（5,10,15这些是只包含 1 个因数5的数；25,50,75这些是包含 2 个因数5的数，因为25 =5*5,50=2*5*5...以此类推）。以130为例：
//第一次除以5时得到26，表明存在26个包含[一] 个因数5的数；
//第二次除以5得到5，表明存在5个包含[二] 个因数5的数(本来是出现了 2*5 个质因子 5 。但是这些数字的一个因数 5 已经在第一次运算的时候统计了，所以只需要加一次)；
//第三次除以5得到1，表明存在1个包含[三] 个因数5的数(本来是出现了 3*5 个质因子 5。但是这些数字的两个因数 5 已经在前两次运算的时候统计了)；
//得到从1 - n中所有5的因数的个数
//int main()
//{
//    int n = 130;
//    int count = 0;
//    while (n > 0) {
//        count += n / 5;
//        n = n / 5;
//    }
//    return count;
//}

////////////////////////////////////////////变成回文串的最小代价///////////////////////////////////////

//https://www.nowcoder.com/profile/535762530/codeBookDetail?submissionId=141948542
//int main()
//{
//    ios::sync_with_stdio(0), cin.tie(0);
//    int add[5] = { 0,100,200,360,220 }, del[5] = { 0,120,350,200,320 };
//    string s;
//    cin >> s;
//    int n = s.size();
//    vector<vector<int>> dp(n, vector<int>(n, 0x3f3f3f3f));//dp[i][j]表示把 s[i:j] 变成回文串需要的最小代价
//    for (int i = 0; i < n; i++) /**< 长度为1肯定代价0 */
//        dp[i][i] = 0;
//    for (int i = 2; i <= n; i++) //长度
//    {
//        for (int j = 0; j <= n - i; j++)
//        {//起点
//            int k = j + i - 1;//终点
//            if (s[j] == s[k])
//            {
//                if (i == 2) /**< 长度为2特判，因为不能使用下面dp[j+1][k-1]*/
//                    dp[j][k] = 0;
//                else
//                    dp[j][k] = dp[j + 1][k - 1];
//            }
//            else
//            {//否则的话就考虑删除起点s[j]或终点s[k]，或者考虑添加新起点或新终点让他们组成回文
//                dp[j][k] = min(dp[j][k], dp[j][k - 1] + min(add[s[k] - '0'], del[s[k] - '0']));//dp[j][k - 1]表示把 s[j:k-1] 变成回文串需要的最小代价，那么我们只需要在左边添加一个 s[k]，或者删除右边的 s[k]，都能把s[j][k]变成回文
//                dp[j][k] = min(dp[j][k], dp[j + 1][k] + min(add[s[j] - '0'], del[s[j] - '0']));//或者，在右边添加一个s[j]，或者删除左边的s[j]，也能把s[j][k]变成回文，取最小值即可
//            }
//        }
//    }
//    cout << dp[0][n - 1];
//    return 0;
//}

////////////////////////////////////////////单例模式（饿汉、懒汉、多线程安全）///////////////////////////////////////

//mutex mu;//线程互斥对象
//class Singleton_Hungry
//{
//private:
//    Singleton_Hungry()
//    {
//        cout << "我是饿汉式，在程序加载时，我就已经存在了。" << endl;
//    }
//    static Singleton_Hungry* singleton;
//public:
//    static Singleton_Hungry* getInstace()
//    {
//        return singleton;
//    }
//
//};
////静态属性类外初始化
//Singleton_Hungry* Singleton_Hungry::singleton = new Singleton_Hungry;
//
//class Singleton_Lazy
//{
//private:
//    Singleton_Lazy()
//    {
//        cout << "我是懒汉式,在别人需要我的时候，我才现身。" << endl;
//    }
//    static Singleton_Lazy* singleton;
//public:
//    static Singleton_Lazy* getInstance()
//    {
//
//        if (NULL == singleton)
//        {
//
//            mu.lock();//关闭锁
//            if (NULL == singleton)
//            {
//                singleton = new Singleton_Lazy;
//            }
//            mu.unlock();//打开锁
//        }
//        return singleton;
//    }
//};
//Singleton_Lazy* Singleton_Lazy::singleton = NULL;
//void thread01()
//{
//    for (int i = 0; i < 5; i++)
//    {
//        cout << "thread01 working...." << endl;
//        Singleton_Lazy* lazy1 = Singleton_Lazy::getInstance();
//        cout << "thread01创建单例lazy1地址:" << lazy1 << endl;
//    }
//}
//void thread02()
//{
//    for (int i = 0; i < 5; i++)
//    {
//        cout << "thread02 working...." << endl;
//        Singleton_Lazy* lazy2 = Singleton_Lazy::getInstance();
//        cout << "thread02创建单例lazy2地址:" << lazy2 << endl;
//    }
//}
//
//int main()
//{
//    thread thread1(thread01);
//    thread thread2(thread02);
//    thread1.join();
//    thread2.join();
//    /*thread1.detach();
//    thread2.detach();*/
//    for (int i = 0; i < 5; i++)
//    {
//        cout << "Main thread working..." << endl;
//        Singleton_Lazy* main = Singleton_Lazy::getInstance();
//        cout << "Main 创建单例lazy地址:" << main << endl;
//    }
//    //system("pause");//如果上面两个线程用的是detach的方法，那么主线程结束以后子线程仍然可以在后台执行，但是我们在输出窗口内看不到子线程的输出，因为主线程的资源已经释放了，所以我们需要暂停主线程，等待子线程的输出
//    return 0;
//}

////////////////////////////////////////////停留 K 次能够获得的最大金币数///////////////////////////////////////

//*************************************动态规划***************************************
//dp[i][j]表示到达i宝库时使用j次启动所带来的最大收益,在启动次数固定为times的情况下，dp[i][times]可以由dp[j][times-1]转移而来，状态转移方程为：
//  dp[i][times] = dp[j][times - 1] + gold[i], 其中j表示离i宝库不超过m公里的宝库，到达i宝库时启动次数为times次，那么到达j宝库时启动次数应该已经使用了times-1次。
//  但是它也可以不从j宝库转移过来，因为从j宝库过来并不一定能使得金币数增加最多，因此j应该是所有能到i宝库的宝库中，能使得金币数增加最多的那个宝库。
//  dp矩阵中的最大值即为X星人最多可以收集到的金币数量。
//int main()
//{
//    int n=5, m=10, p=2;//n个宝库，飞行器每次启动可以飞行m距离，总共只能启动2次
//    vector<vector<int>> dp(n + 1, vector<int>(p + 1, INT_MIN));//注意初始值是INT_MIN，因为题目没有明确每个宝库的金币是正数，也有可能是负数，所以不能初始化为 0 
//    vector<int> a{ 0,0,8,10,18,22 };//从第 1 个宝库到第 i 个宝库的距离（注意第 0 个位置是填充数组用的）
//    vector<int> b{ 0,5,6,8,12,15 };// 第 i 个宝库的金币（注意第 0 个位置是填充数组用的）
//    dp[1][0] = b[1];//起点就是第 1 个宝库，所以不需要启动飞行器即可获得金币
//    int ans = 0;
//    for (int k = 1;k <= p;k++)//到达第 i 个宝库用了 k 次启动，k 最少也是 1 次。

//    {
//        for (int i = 2;i <= n;i++)
//        {//到达第 i 个宝库
//            for (int j = 1;j < i;j++)
//            {// 前一个宝库是 第 j 个宝库
//                if (a[i] - a[j] <= m)
//                {//这两个宝库之间距离小于 m ，才能够获得最多金币，显然用两段启动去到达下一个宝库，比不上一段启动
//                    dp[i][k] = max(dp[i][k], dp[j][k - 1] + b[i]);//记录获得的最多金币
//                    ans = max(ans, dp[i][k]);//记录最大值
//               
//                }
//            }
//
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}
//*************************************回溯***************************************
//int maxscore = 0;
//void traverse(int step, int temp, int i, vector<vector<int>>& nums) {//step表示现在已经用了多少次机会，temp表示现在用于的金币，i是当前宝库的序号，从0开始，nums第一列表示宝库之间距离，第二列表示每个宝库的金币
//    if (i >= nums.size()) {
//        return;
//    }
//    if (step == K) {//机会用完了，统计最多金币数
//        maxscore = max(maxscore, temp);
//        return;
//    }
//    maxscore = max(maxscore, temp);//中途也应该统计最大值，因为宝库的金币数有负值，用完所有机会获得的金币有可能小于中途获得的金币
//    int j = i + 1;
//    while (j < nums.size() && (nums[i][0] + M >= nums[j][0])) {//当前宝库为 i ，下一个宝库 j 距离应该小于 i+M
//        traverse(step + 1, temp + nums[j][1], j, nums);//拿到宝库 j 的金币，用掉一次机会，
//        j++;//回溯，也可能不在上一个 j 停靠，而到 j+1 停靠
//    }
//}
//int main() {
//    int N, M, K;
//    vector<vector<int>> nums;
//    cin >> N;
//    cin >> M;
//    cin >> K;
//    for (int i = 0;i < N;i++) {
//        int a, b;
//        cin >> a;
//        cin >> b;
//        vector<int> temp{ a,b };
//        nums.push_back(temp);
//    }
//    if (nums.size() == 0) 
//        cout << 0;
//    else {
//        traverse(0, nums[0][1], 0, nums);
//        cout << maxscore;
//    }
//    return 0;
//}
//

////////////////////////////////////////////最大连续1的个数 III///////////////////////////////////////

//https://leetcode-cn.com/problems/max-consecutive-ones-iii/solution/fen-xiang-hua-dong-chuang-kou-mo-ban-mia-f76z/
//用滑动窗口来做，窗口内保证是连续的 1 ，并且反转的 0 的个数不超过 k 个，也就是加入一个 0 ，窗口容忍度减一，拿走一个 0 ，窗口容忍度加一
//int main()
//{
//    vector<int> nums = { 1,1,1,0,0,0,1,1,1,1,0 };
//    int k = 2;//可以翻转最多 k 个 0 ，则返回 数组中连续 1 的最大个数 。
//    int left = 0, right = 0, sum = 0;
//    int res = 0;
//    for (;right < nums.size();right++)
//    {
//        sum += nums[right] != 1;//如果是 0 ，容忍度减一，也就是sum加1，如果是1，则不加
//        while (sum > k)
//        {//拿走左端的 0 ，容忍度加一
//            sum -= nums[left] != 1;//只有拿走 0 ，容忍度才加1，否则不加
//            left++;//不管拿走的是1还是0，窗口都要缩小
//        }
//        res = max(res, right - left + 1);//每移动一次窗口，都要计算最大长度
//    }
//    cout << res << endl;
//    return 0;
//}

////////////////////////////////////////////找到处理最多请求的服务器///////////////////////////////////////

//https://leetcode-cn.com/problems/find-servers-that-handled-most-number-of-requests/solution/zhao-dao-chu-li-zui-duo-qing-qiu-de-fu-w-e0a5/
//typedef pair<int, int> pii;
//int main()
//{
//    int k = 3;//k 台服务器，编号为 0 1 2 .. k-1
//    vector<int> arrival = { 1,2,3,4,8,9,10 };//第 i 个任务的到达时间
//    vector<int> load = { 5,2,10,3,1,2,2 };//第 i 个任务的处理时间
//    vector<int> request(k, 0);//每台服务器需要处理的任务数
//    vector<int> res;//处理任务最多的服务器序号
//    int res_max = 0;//最多的任务数
//    auto cmp = [](const pii& a, const pii& b)
//    {
//        return a.first > b.first;
//    };
//    priority_queue < pii, vector<pii>, decltype(cmp)> busy(cmp);// < 处理结束时间，服务器序号 >，处理结束时间小的排在更前面
//    set<int> aviliable;//记录第 i 个任务到来时，有哪些服务器是空闲的，序号从小到大排序
//    int i = 0;
//    for (;i < min(k, (int)arrival.size());i++)//任务数可能小于服务器的数量，这样第一轮就可以自由分配
//    {
//        request[i]++;
//        res_max = max(res_max, request[i]);
//        busy.push(make_pair(arrival[i] + load[i], i));//到达时间+处理时间=处理结束时间
//    }
//    for (;i < arrival.size();i++)
//    {
//        while (!busy.empty() && busy.top().first <= arrival[i])
//        {//当优先队列中的服务器结束时间小于等于第 i 个任务到达时间时，那么这台服务器有可能处理第 i 个任务
//            aviliable.insert(busy.top().second);//加入候选队列
//            busy.pop();
//        }
//        if (aviliable.empty())
//        {//当候选队列为空时，表示第 i 个任务到来时，所有服务器都处于忙碌状态，则丢弃此任务
//            continue;
//        }
//        else
//        {
//
//            auto p = aviliable.lower_bound(i % k);//第 i 个任务应该交给第 （i%k） 号服务器，如果他忙碌的话，就找比他序号大的空闲服务器，如果没找到就直接取出空闲的序号最小的服务器
//            if (p == aviliable.end()) {//lower_bound找的是比 i%k 序号大的服务器，如果没找到，就直接取出空闲的序号最小的服务器
//                p = aviliable.begin();
//            }
//            int tmp = *p;
//            aviliable.erase(p);//这台服务器已经接收任务了，从空闲队列中排除
//            request[tmp]++;//处理任务数加 1
//            res_max = max(res_max, request[tmp]);//记录最多的任务数
//            busy.push(make_pair(arrival[i] + load[i], tmp));//重新计算处理结束时间
//        }
//    }
//    for (int j = 0;j < k;j++)
//    {//找出处理任务最多的服务器
//        if (request[j] == res_max)
//        {
//            res.emplace_back(j);
//        }
//    }
//    for (auto& i : res)
//    {
//        cout << i << ' ';
//    }
//    return 0;
//}

////////////////////////////////////////////从二叉树中选出 3 个不同的节点，使得其两两之间的最短距离之和最大///////////////////////////////////////

//https://www.nowcoder.com/test/question/done?tid=54456794&qid=1701885#summary
//例子：输出 8 
//5
//4 1 1 4
//总体思路是先从根节点往下寻找，找到深度最深的一个节点，记为 NodeA，然后从 NodeA 开始，找到距离 NodeA 最远的节点（把树转化成图），记为 NodeB
//然后从NodeB开始，记录各个节点距离 NodeB 的距离，最后遍历每个节点，结果为 NodeA 到 NodeB 的距离加上某个节点到 NodeA 和 NodeB距离之和的最大值
//int n, fa[100005];//n是节点个数，最大是1e5，第 i 个节点的父节点是 fa[i] 节点
//int vis[2][100005];//vis[0]记录 NodeA到各个节点的距离，其中距离最大的是 NodeB，vis[1]记录 NodeB到各个节点的距离
//vector<int> e[100005];//这是 100005 个vector，记录每个节点的邻居节点（包括父节点和子节点，把树转换成图）
//pair<int, int> bfs(int st, int type) {//type用来区分第一次遍历还是第二次遍历
//    queue<int> q;
//    q.push(st);
//    memset(vis[type], -1, sizeof vis[type]);//-1表示还没有访问这个节点
//    vis[type][st] = 0;
//    while (!q.empty()) {
//        int x = q.front();
//        q.pop();
//        for (int i = 0; i < e[x].size(); i++) {
//            if (vis[type][e[x][i]] == -1) {
//                vis[type][e[x][i]] = vis[type][x] + 1;
//                q.push(e[x][i]);
//            }
//        }
//    }
//    int longest = 0, index = 0;
//    for (int i = 1; i <= n; i++) {
//        if (longest < vis[type][i]) {
//            longest = vis[type][i];
//            index = i;
//        }
//    }
//
//    return make_pair(index, longest);
//}
//
//int main() {
//    cin>>n;//n个节点
//    for (int i = 2; i <= n; i++) 
//    {//1 号节点是根节点，没有父节点，所以从 2 号节点开始
//        cin>>fa[i];//第 i 个节点的父节点是 fa[i] 节点
//        e[fa[i]].push_back(i);// fa[i] 节点的邻居节点包含 i 节点
//        e[i].push_back(fa[i]);// i 节点的邻居节点包含 fa[i] 节点
//    }
//    int nodeA = bfs(1, 0).first;//找到深度最深的结点作为NodeA
//    pair<int, int> p = bfs(nodeA, 0);//从NodeA开始，计算 NodeA到其他节点的距离，其中最大的节点为 NodeB，同时距离信息保存在 vis[0] 里面 
//    int nodeB = p.first;
//    int longest = p.second;//NodeA 到 NodeB的距离
//    bfs(nodeB, 1);//从NodeB开始，计算 NodeB到其他节点的距离，其中最大的节点为 NodeA，同时距离信息保存在 vis[1] 里面 
//    int ans = 0;
//    for (int i = 1; i <= n; i++) 
//    {//遍历其他节点，找到它与 NodeA和 NodeB距离之和的最大值
//        if (i != nodeA && i != nodeB) 
//        {//注意这个节点不能是 NodeA 和 NodeB
//            ans = max(ans, longest + vis[0][i] + vis[1][i]);
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}

////////////////////////////////////////////每个数各不相同的最小代价///////////////////////////////////////

//https://www.nowcoder.com/test/question/done?tid=54456794&qid=1701886#summary
//例子：输出 7
//3
//1 1 2
//4 5 3
//typedef pair<long long, long long> pll;
//int main() {
//    vector<pair<long long, long long>> arr;//<当前的数，加 1的代价>
//    priority_queue<long long, vector<long long>, less<long long>> q;// 当前层次（所有相同的数属于同一层次）的的代价大根堆
//    long long n;
//    long long ans = 0;
//    cin >> n;
//    arr.resize(n);
//    for (long long i = 0; i < n; ++i) {
//        cin >> arr[i].first;
//    }
//    for (long long i = 0; i < n; ++i) {
//        cin >> arr[i].second;
//    }
//    sort(arr.begin(), arr.end(), [](const pll& a, const pll& b)
//        {//按照从小到大的顺序排列，因为每个数都是要递增的，我们选择相同的数里代价最大的那几个，让他们增加到比下一个层次的数小的空隙里（就是出队的循环）
//            //剩下的就先增加到下一层次，然后和下一层次的数一起来考虑增加的高度（就是统一提升层次）
//            return a.first < b.first || (a.first == b.first && a.second < b.second);
//        });
//    // 当前层次总和，就是把当前层次全都加1需要的代价，然后减去那些代价比较大的（因为他们已经确定了增加多少，并且已经算在答案里了，ans += q.top() * j;）
//    long long weight = 0;
//    arr.emplace_back(pair<long long, long long>{INT32_MAX, 0});//防止越界
//    for (long long i = 0; i < n; ++i) 
//    {
//        if (arr[i].first == arr[i + 1].first) 
//        {
//            weight += arr[i].second;//同一层次的先把他们加一的代价加起来
//            q.push(arr[i].second);
//        }
//        else 
//        {
//            weight += arr[i].second;//此刻的 i 是同一层次的最后一个数，所以仍然要有这一句
//            q.push(arr[i].second);
//            // 以上步骤将同一层次入队
//
//            // 计算出队数量
//            long long num = arr[i + 1].first - arr[i].first;//计算下一层次和这一层次之间有多少“空隙”，比如下一层次是 3，这一层次是 1 ，那么这一层次（ 1 ） 可以增加到 1 或者 2
//                                                            //考虑让代价最大的那两个 1 去增加，因为这是他们增加付出代价最小的唯一方法（相当于有几个“坑”填几个萝卜），
//                                                            //否则的话这两个 1 增加到更大的层级付出的代价更大
//            long long n0 = min((long long)q.size(), num);//“空隙”的数量有可能大于当前层级的数量，比如下一层次是 6 ，这一层次是 1 ，而相同的 1 只有两个，那么只需要增加到 1 或 2 即可
//                                                         // 如果小于当前层级的数量，比如下一层次是 3，这一层次是 1 ，而相同的 1 有四个，那么只能让min（3-1,4)= 2 个代价最大的 1 去增加
//            for (long long j = 0; j < n0; ++j) {
//                // 出队
//                ans += q.top() * j;//j=0相当于不增加，当然是让代价最大的保持不变，代价小的去增加
//                weight -= q.top();//此时一部分同一层级的数已经确定了增大的代价，而剩下的还没有确定，需要和下一层次的数放在一起考虑
//                                  //如果是“空隙”的数量有可能大于当前层级的数量，那么weight就会变成 0 ，也就是所有数都确定了增大的代价，不需要和下一层次一起考虑了，队列大小为 0
//                q.pop();
//            }
//
//            // 剩下的统一提升层次
//            ans += weight * (long long)num;//weight是让剩下的数加一的代价总数，那么要让这一层次的数增加到下一层次，就需要 num 次增加，付出的代价就是 weight * num
//                              //比如下一层次是 3，这一层次是 1，weight= 6，那么要让 1 变成 3 就需要6 * 2=12 的代价，因为 6 只是让 1 增加到 2 
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}

////////////////////////////////////////////轮流拿n堆石子中的某一个，最后出现两堆相同石子的输///////////////////////////////////////

//https://www.nowcoder.com/questionTerminal/fe03f011e6c44a8ca76ca15a5e1c6d87?orderByHotValue=1&page=1
//如果一个玩家在轮到他之前所有的石碓都是空的，或者如果在移动石头之后，存在两个堆包含相同数量的石头（可能为都为0），那么他就会输,man先手
//例子：输出woman\n man\n（\n代表回车）
//2
//1
//0
//2
//2 2
//首先把先手必败的情况给判掉：0的数目大于等于2时，相同数字对数大于1，总和为0，这几种情况先手必败。
//可以想到游戏结束的上一个状态一定是0, 1, 2, 3...n - 1这种，谁到了这个状态谁必败，而且因为判掉了先手必败的几个情况（保证了相同数字不大于2且总和不为0），
//所以一定能出现这种状态。那么只要将数目总和减去最后形成的这个等差数列，就可以知道谁可以领到这个等差数列状态，就可以知道谁必胜了
//typedef long long ll;
//int main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int>vec(n);
//        unordered_map<int, int>mp;//记录相同数字的对数
//        int cnt = 0, zero = 0;
//        ll sum = 0;
//        for (int i = 0;i < n;i++) {
//            cin >> vec[i];
//            if (vec[i] == 0) zero++;
//            if (mp[vec[i]]) cnt++;//相同数字对数大于1
//            mp[vec[i]] = 1;
//            sum += vec[i];
//        }
//        sort(vec.begin(), vec.end());
//        if (cnt > 1 || sum == 0 || zero >= 2) {
//            cout << "woman" << endl;
//            continue;
//        }
//        sum = 0;
//        for (int i = 0;i < n;i++) {
//            sum += vec[i] - i;
//        }
//        if (sum % 2 == 0) 
//        {//sum是偶数，说明当woman拿完最后一块石头时，形成了等差数组，那么man就不能拿了，woman必赢
//            cout << "woman" << endl;
//        }
//        else 
//        {//sum是奇数，说明当man拿完最后一块石头时，形成了等差数组，那么woman就不能拿了，man必赢
//            cout << "man" << endl;
//        }
//    }
//    return 0;
//}

////////////////////////////////////////////穿过银河的最小距离的最大值（并查集+二分）///////////////////////////////////////

//https://www.nowcoder.com/questionTerminal/f7a9f3af845c4cbb9d948e78d16689b4?orderByHotValue=1&mutiTagIds=139&page=3
//假定银河是一个n×m的区域，顶点在(0, 0)和(n, m)，度度熊从最左边任意一点进入，打算穿越这片区域并从右边任意一点离开。
//在银河中分布着k个星球，每个星球以及银河的上下两个边缘都有引力，处于安全考虑，度度熊要离他们越远越好。
//试求度度熊穿越银河的路径上，距离所有星球以及上下边界的最小距离的最大值可以为多少？
//例子：输出1.1180，保留4位小数
//10 5 2
//1 1
//2 3
//const int maxn = 6005;
//struct Point {
//    int x, y;
//};
//Point p[maxn];//用来记录每颗星球
//int n, m, k;//m行n列，横坐标是 x，对应 n ，纵坐标是 y，对应 m，k个星球
//int fa[maxn];//记录每个星球的“帮主”，也就是每个集合里面的代表元素
//double dis[maxn][maxn], ans;//记录每个星球之间的距离
//
//double get_dis(Point a, Point b) 
//{//计算星球之间距离
//    return sqrt(1.0 * (a.x - b.x) * (a.x - b.x) + 1.0 * (a.y - b.y) * (a.y - b.y));
//}
//int findset(int x) 
//{//找到每个星球属于哪个“帮派”，返回它的“帮主”
//    if (fa[x] == x) 
//        return x;
//    return fa[x] = findset(fa[x]);//x可能只知道它的“上级”是谁，不知道“帮主”是谁，因此找到帮主之后要告诉每一个成员，就必须赋值
//}
//void merge(int x, int y) 
//{//合并两个“帮派”，fx是一号帮派的帮主，fy是二号帮派的帮主，现在统一为一个帮派，fy为帮主
//    int fx = findset(x), fy = findset(y);
//    if (fx != fy) {
//        fa[fx] = fy;
//    }
//}
//void init() 
//{//并查集初始化，最开始，所有大侠各自为战。他们各自的帮主自然就是自己。
//    for (int i = 1;i <= k;i++) {
//        fa[i] = i;
//    }
//}
//bool check(double distance) 
//{//distance是我们预想的最小距离，先看点之间能否满足这个最小值，也就是点间距离一般大于等于这个最小值，如果不满足，那么不能从这两点之间穿过，所以用并查集合在一起。
// //被并查集合在一起的点，只能从这些点上面走或者下面走。再看从点下面和上面走是否可行，如果点集不能从上面和下面走，那么这个最小值不成立。
//    init();//先初始化，不同距离会造成“帮派”不一样，所以每次都要重新初始化，同样的两个星球距离，distance大的时候，这两个星球需要看成一个“帮派”，distance小的时候就看成两个“帮派”
//    map<int, int> mp;
//    for (int i = 1;i <= k;i++) {
//        for (int j = i + 1;j <= k;j++) {
//            if (dis[i][j] / 2.0 < distance) 
//            {//两个星球距离小于distance则合并它们所属的“帮派”，因为同一”帮派“意味着不能从他们中间穿过，而不同帮派的任意两个星球如果距离不满足条件的话
//             //则不能从这两个帮派之间穿过，这样就变成了同一“帮派”，因为如果穿过去的话就必然要收到两个星球的吸引
//                merge(i, j);
//            }
//        }
//    }
//    for (int i = 1;i <= k;i++) 
//    {//对于每个星球，如果它到上边界的距离（p[i].y）小于两倍的distance的话（因为飞船需要同时满足 到星球和到上边界的距离大于等于distance），说明飞船不能从 这个“帮派”的上面飞过去
//        //那么就把这个“帮派”的上边界标志位 1 ，说明飞船不能从 这个“帮派”的上面飞过去
//        if (p[i].y / 2.0 < distance) 
//        {
//            mp[findset(i)] = 1;//“帮主”就是“帮派”的标志，所以只需要记录“帮主”就行了
//        }
//    }
//    for (int i = 1;i <= k;i++) 
//    {//对于每个星球，如果它到下边界的距离（m - p[i].y）小于两倍的distance的话（因为飞船需要同时满足 到星球和到下边界的距离大于等于distance），说明飞船不能从 这个“帮派”的下面飞过去
//        //并且 已经记录了飞船不能从 这个“帮派”的上面飞过去，那么在distance这个距离下，飞船肯定无法穿过这片银河，返回false，因为从上面、中间、下面都无法避免被吸引
//        if ((m - p[i].y) * 1.0 / 2.0 < distance) 
//        {
//            if (mp.count(findset(i))) 
//            {
//                return false;
//            }
//        }
//    }
//    return true;//以上对所有星球都遍历了一遍，如果还没有返回的话，说明在这个distance下，一定有某种方法可以避开所有的星球，穿过银河，返回true
//}
//void solve() {
//    double l = 0, r = m / 2.0;//最小距离为0，最大距离为 上下边界距离（m）/2
//    double mid = 0;
//    while (r - l > 1e-7) {//这里不能是 l<r 因为对于double来说，l<r 意味着精度要小于10^-18，肯定会超时
//        mid = (l + r) / 2;
//        if (check(mid)) 
//        {//返回true说明 这个distance满足条件，可以试一下更大的distance，这里不用担心会陷入死循环，因为double的精度很高，退出的条件很容易满足
//            l = mid;
//        }
//        else 
//        {//返回false说明 这个distance不满足条件，需要减小distance
//            r = mid;
//        }
//    }
//    ans = mid;//最终找到了合适的 mid ，记录下来
//}
//int main() {
//    cin >> n >> m >> k;
//    for (int i = 1; i <= k;i++) {
//        cin >> p[i].x >> p[i].y;
//    }
//    for (int i = 1;i <= k;i++) {
//        for (int j = i + 1;j <= k;j++) {
//            dis[i][j] = get_dis(p[i], p[j]);//先计算星球之间距离，这是固定的
//        }
//    }
//    solve();
//    printf("%.4f\n", ans);
//    return 0;
//}

////////////////////////////////////////////单点修改，区间查询（树状数组（最合适）、线段树）///////////////////////////////////////

//***********************************************线段树**********************************************
//https://leetcode-cn.com/problems/range-sum-query-mutable/solution/guan-yu-ge-lei-qu-jian-he-wen-ti-ru-he-x-41hv/
//class NumArray {
//private:
//    void bulid(int start, int end, int node, vector<int>& nums)//这里的start和end代表的是当前节点 node 储存的是区间 [start,end] 的总和
//    {//在结点 node 保存数组 nums 在区间[start, end]的总和。
//     // ·start = end 时，结点 node 是叶子结点，它保存的值等于 nums[start]。
//     // ·start < end 时，结点 node 的左子结点保存区间 [start,mid]    mid=(start+mid)/2 的总和    ​
//     //    右子结点保存区间 [mid+1,end]  的总和，那么结点 node 保存的值等于它的两个子结点保存的值之和。
//     //    假设 nums 的大小为 n，我们规定根结点 node = 0 保存区间[0, n−1] 的总和，然后自下而上递归地建树。
//     //    也就是 0 的左孩子节点 node = 1 保存区间 [0,(n-1)/2] 的总和，左孩子节点 node = 2 保存区间 [(n-1)/2+1，n-1] 的总和，依次递归
//        if (start == end)
//        {//到达叶子结点，直接赋值
//            segmentTree[node] = nums[start];
//            return;
//        }
//        int mid = start + (end - start) / 2;
//        bulid(start, mid, 2 * node + 1, nums);//左孩子节点索引是 2*node+1
//        bulid(mid + 1, end, 2 * node + 2, nums);//右孩子节点索引是 2*node+2
//        segmentTree[node] = segmentTree[2 * node + 1] + segmentTree[2 * node + 2];//左右孩子总和相加
//    }
//    void setvalue(int start, int end, int node, int index, int val)//这里的start和end代表的是当前节点 node 储存的是区间 [start,end] 的总和，index是我们想找的位置
//    {//当我们要修改 nums[index] 的值时，我们找到对应区间 [index, index] 的叶子结点，
//     // 直接修改叶子结点的值为 val，并自下而上递归地更新父结点的值。
//        if (start == end)
//        {//找到了索引为 index 的节点，直接更新
//            segmentTree[node] = val;
//            return;
//        }
//        int mid = start + (end - start) / 2;
//        if (index <= mid)
//        {//index在左边区间里
//            setvalue(start, mid, 2 * node + 1, index, val);
//        }
//        else
//        {//index在右边区间里
//            setvalue(mid + 1, end, 2 * node + 2, index, val);
//        }
//        segmentTree[node] = segmentTree[2 * node + 1] + segmentTree[2 * node + 2];//一定要更新上层的值，因为我们是从叶子节点向上累加计算的，所以叶子节点更新一定会影响到上层的值
//        return;
//    }
//    int range(int start, int end, int node, int left, int right)
//    {//给定区间 [left, right] 时，我们将区间[left, right] 拆成多个结点对应的区间。
//     //·如果结点 node 对应的区间完全被 [left, right] 包含，可以直接返回该结点的值，即当前区间和。
//     //·如果结点 node 对应的区间不完全被 [left, right] 包含，设左子结点对应的区间的右端点为 mid，那么将区间 [left, right] 沿点 mid 拆成两个区间，分别计算左子结点和右子结点。
//     //·我们从根结点开始递归地拆分区间 [left, right]。
//
//        if (left <= start && right >= end)
//        {//如果想要查询的区间和当前节点储存的区间相同，直接返回
//            return segmentTree[node];
//        }
//        int mid = start + (end - start) / 2;
//        if (right <= mid)
//        {//当想要查询的区间完全在左孩子节点的区间内时，只递归左孩子
//            return range(start, mid, 2 * node + 1, left, right);
//        }
//        else if (left >= mid + 1)
//        {//当想要查询的区间完全在右孩子节点的区间内时，只递归右孩子
//            return range(mid + 1, end, 2 * node + 2, left, right);
//        }
//        else
//        {//否则就是左右区间各有一部分，那么分别递归左右孩子
//            return range(start, mid, 2 * node + 1, left, right) + range(mid + 1, end, 2 * node + 2, left, right);
//        }
//        return 0;
//    }
//public:
//    vector<int> segmentTree;//线段树 segmentTree 是一个二叉树，每个结点保存数组 nums 在区间 [start, end]的最小值、最大值或者总和等信息
//    int n;
//    NumArray(vector<int>& nums) :n(nums.size()), segmentTree(4 * nums.size(), 0) {//最多需要四倍的空间,线段树空间复杂度是O（4N）
//        bulid(0, n - 1, 0, nums);
//    }
//    void update(int index, int val) {
//        setvalue(0, n - 1, 0, index, val);
//    }
//
//    int sumRange(int left, int right) {
//        return range(0, n - 1, 0, left, right);
//
//    }
//};
//***********************************************线段树的另一种写法**********************************************
//class NumArray {
//private:
//    void bulid(int node,int left,int right, vector<int>& nums)//这里的left和right代表的是当前节点 node 储存的是区间 [left,right] 的总和
//    {//left=right时，到达了叶子节点，建新节点，记录区间和区间和
//        if (left == right)
//        {//到达叶子结点，直接赋值
//            segmentTree[node] = Node(left, right, nums[left]);
//            return;
//        }
//        else
//        {
//            segmentTree[node] = Node(left, right, 0);//否则先建新节点，记录区间，区间和暂时更新为0
//            int mid = left + (right - left) / 2;
//            bulid(2 * node + 1,left,mid,nums);//左孩子节点索引是 2*node+1（如果根节点序号是0的话，而如果根节点序号是1，那么左孩子节点就是 2*node
//            bulid(2 * node + 2, mid+1, right, nums);//右孩子节点索引是 2*node+2
//            segmentTree[node].val = segmentTree[2 * node + 1].val + segmentTree[2 * node + 2].val;//左右孩子总和相加
//        }
//    }
//    void setvalue(int node, int index, int val)//这里的start和end代表的是当前节点 node 储存的是区间 [start,end] 的总和，index是我们想找的位置
//    {//当我们要修改 nums[index] 的值时，我们找到对应区间 [index, index] 的叶子结点，
//     // 直接修改叶子结点的值为 val，并自下而上递归地更新父结点的值。
//        if (segmentTree[node].start==index && segmentTree[node].end == index)
//        {//找到了索引为 index 的节点，直接更新
//            segmentTree[node].val = val;
//            return;
//        }
//        else
//        {
//            int mid = segmentTree[node].start + (segmentTree[node].end - segmentTree[node].start) / 2;
//            if (index <= mid)
//            {//index在左边区间里
//                setvalue(2 * node + 1, index, val);
//            }
//            else
//            {//index在右边区间里
//                setvalue(2 * node + 2, index, val);
//            }
//            segmentTree[node].val = segmentTree[2 * node + 1].val + segmentTree[2 * node + 2].val;//一定要更新上层的值，因为我们是从叶子节点向上累加计算的，所以叶子节点更新一定会影响到上层的值
//        }
//        return;
//    }
//    int query(int node, int left, int right)
//    {//给定区间 [left, right] 时，我们将区间[left, right] 拆成多个结点对应的区间。
//     //·如果结点 node 对应的区间被 [left, right] 完全包含，可以直接返回该结点的值，即当前区间和。
//     //·如果结点 node 对应的区间被 [left, right] 不完全包含，设左子结点对应的区间的右端点为 mid，那么将区间 [left, right] 沿点 mid 拆成两个区间，分别计算左子结点和右子结点。
//     //·我们从根结点开始递归地拆分区间 [left, right]。
//
//        if (left <= segmentTree[node].start && right >= segmentTree[node].end)
//        {//如果想要查询的区间和当前节点储存的区间相同，直接返回
//            return segmentTree[node].val;
//        }
//        int mid = segmentTree[node].start + (segmentTree[node].end - segmentTree[node].start) / 2;
//        if (right <= mid)
//        {//当想要查询的区间完全在左孩子节点的区间内时，只递归左孩子
//            return query(2 * node + 1, left, right);
//        }
//        else if (left >= mid + 1)
//        {//当想要查询的区间完全在右孩子节点的区间内时，只递归右孩子
//            return query(2 * node + 2, left, right);
//        }
//        else
//        {//否则就是左右区间各有一部分，那么分别递归左右孩子
//            return query(2 * node + 1, left, right) + query(2 * node + 2, left, right);
//        }
//        return 0;
//    }
//public:
//    struct Node
//    {//用node来记录线段树每个节点对应的区间以及区间和
//        int start, end, val;
//        Node() :start(0), end(0), val(0) {};//必须要提供无参构造函数，因为构造vector的时候会运行构造函数，如果不提供无参构造就会报错
//        Node(int _start, int _end, int _val) :start(_start), end(_end), val(_val) {};
//    };
//    vector<Node> segmentTree;//线段树 segmentTree 是一个二叉树，每个结点保存数组 nums 在区间 [start, end]的最小值、最大值或者总和等信息
//    int n;
//    NumArray(vector<int>& nums) :n(nums.size()), segmentTree(4 * nums.size()) {//最多需要四倍的空间,线段树空间复杂度是O（4N）
//        bulid(0,0,n-1,nums);//建树，第一个0是线段树的节点编号，第二个0和n-1是用nums[0]到nums[n-1]来建树
//    }
//    void update(int index, int val) {
//        setvalue(0, index, val);
//    }
//
//    int sumRange(int left, int right) {
//        return query(0, left, right);
//
//    }
//};
//***********************************************树状数组**********************************************
//https://blog.csdn.net/qq_40941722/article/details/104406126
//对于一个长度为n的数组，A数组存放的是数组的初始值，引入一个辅助数组C（就是我们说的累加和数组）
//令：  C1 = A1
//      C2 = C1 + A2 = A1 + A2
//      C3 = A3
//      C4 = C2 + C3 + A4 = A1 + A2 + A3 + A4
//      C5 = A5
//      C6 = C5 + A6 = A5 + A6
//      C7 = A7
//      C8 = C4 + C6 + C7 + A8 = A1 + A2 + A3 + A4 + A5 + A6 + A7 + A8
//称C[i]的值为下标为i的数所管辖的数的和，下标为i的数所管辖的元素的个数为 2^k 个（k为i的二进制的末尾0的个数），例如：
//·i = 8 = 1000，末尾3个0，故k = 3，所管辖的个数为 2 ^ 3 = 8个，C8是8个数的和，就是A1 + A2 + A3 + A4 + A5 + A6 + A7 + A8；
//·i = 5 = 0101，末尾没有0，故k = 0，所管辖的个数为 2 ^ 0 = 1个，C5是一个数的和，就是A5；
//·i = 6 = 0110，末尾1个0，故k = 1，所管辖的个数为 2 ^ 1 = 2个，C6是2个数的和，就是A5+A6；
//对于输入的数 m，我们要求编号为 [1:m] 的数的前缀和 SUM = A1 + A2 + ...+Am​，只需要对特定的 C[i] 求和就行了，
//这里 m 和 C[i] 的对应关系是这样的，对于查询的 m ，将它转换成二进制后，不断对末尾的1的位置进行 -1 （不是数学意义上的-1，而是去掉末尾的1）的操作，直到全部为 0 停止，中间得到的值就是 C[i]，例如：
//·m = 7，SUM = C7 + C6 + C4​，7 的二进制为0111（得到C7​），对0111的末尾1的位置 -1，得到0110 = 6（得到C6），再对0110末尾1位置 -1，得到0100 = 4（得到C4），
//最后对0100末尾1位置 -1后得到0000（结束），计算停止，至此C7​，C6​，C4全部得到，求和后就是m = 7时它的前缀和，可以理解为 C7管的是A7，C6管的是A6+A5，C4管的是A1+A2+A3+A4，这样求和以后就是前缀和
//·m = 6，SUM = C6​+ C4​，6的2进制等于0110，经过两次变换后为0100（C4）和0000（结束信号），那么求和后同样也得到了预计的结果；
//class NumArray {
//private:
//    vector<int> tree;//累加和数组，注意不是前缀和，因为不是存储从0开始的区间和，想要得到前缀和需要将不同的 累加和 相加，也就是tree里面不同位置的数相加
//    vector<int> num;//原数组
//    int lowbit(int x)
//    {//找到x的二进制数的最后一个1所表示的二进制，比如 x=2（10），返回 2，x=3（11），返回 1 ，x=7（111），返回 1
//        //注意: x不能等于0, 否则会进入死循环, 所以树状数组通常使用的索引会执行 +1 操作
//        return x & (-x);//x和x的相反数相与，https://blog.csdn.net/qq_40941722/article/details/104406126
//    }
//    void add(int index, int val)
//    {//更新过程是每次加 二进制最低位的 1 所代表的数 比如更新5，index=5（101），那么它会影响到5+1=6（110）,6+2=8（1000）,8+8=16（10000）...这些值(101+1 ->110, 110 + 10 -> 1000, 1000 + 1000 -> 10000)
//        while (index <= num.size())
//        {//这里index可以等于 n，因为tree的索引全部加 1 
//            tree[index] += val;
//            index += lowbit(index);
//        }
//    }
//    int sum(int range)
//    {//前缀和是多个 累加和 相加，查询的是[0:range]的前缀和
//     //查询过程每次就是每次减 二进制最低位的 1 所代表的数，比如查询[0,15]的前缀和(1111 - 1 -> 1110, 1110 - 10 -> 1100, 1100 - 100 -> 1000)
//        int sum = 0;
//        while (range > 0)
//        {
//            sum += tree[range];
//            range -= lowbit(range);
//        }
//        return sum;
//    }
//public:
//    NumArray(vector<int>& nums) :num(nums), tree(nums.size() + 1) {树状数组空间复杂度是O（N）
//        for (int i = 0;i < nums.size();i++)
//        {//建树相当于插入，注意索引要加 1
//            add(i + 1, nums[i]);
//        }
//    }
//    void update(int index, int val) {
//        add(index + 1, val - num[index]);//更新的时候只需要增加改动的部分（val-num[index]）
//        num[index] = val;//num里面的值也要更新，下次可能还需要更改
//    }
//
//    int sumRange(int left, int right) {//left和right都是索引，而C里面C[0]并没有存值，C[1]存的才是A[0]的累加和，所以要求[left,right]的前缀和应该是 sum(right+1)-sum(left)
//                                       //比如求[0,0]的前缀和就是 sum（1）-sum（0）=C[1]-C[0]=A[0]-0=A[0]，这样才正确
//        return sum(right + 1) - sum(left);
//
//    }
//};
//int main()
//{
//    vector<int> m = { 0, 9, 5, 7, 3 };
//    NumArray a(m);
//    cout << a.sumRange(4, 4) << endl;
//    cout << a.sumRange(2, 4) << endl;
//    cout << a.sumRange(3, 3) << endl;
//    a.update(4, 5);
//    a.update(1, 7);
//    a.update(0, 8);
//    cout << a.sumRange(1, 2) << endl;
//    a.update(1, 9);
//    cout << a.sumRange(4, 4) << endl;
//    a.update(3, 4);
//}

////////////////////////////////////////////区间更新、单点查询（差分数组+前缀和（最合适），树状数组）///////////////////////////////////////

//int n;
//int c[10]; //差分数组的树状数组，这里差分数组没有直接表示出来，这里直接声明大小为10 ，一般是n+1
//int lowbit(int x) {
//    return x & (-x);
//}
//
//void updata(int i, int k) 
//{//在差分数组的 i 位置加上 k ，那么就影响一些区间和，所以要更新它们
//    while (i <= n) {
//        c[i] += k;
//        i += lowbit(i);
//    }
//}
//
//int getsum(int i) 
//{//求前缀和，前缀和等于一些区间和相加
//    int res = 0;
//    while (i > 0) {
//        res += c[i];
//        i -= lowbit(i);
//    }
//    return res;
//}
//int main() {
//    int a[] = { 1,2,3,5,6,9 };//真正的原始数组
//    int tmp[] = {0,1,2,3,5,6,9 };//第一个0是填充值，1 的真正索引是 0。为了方便计算差分数组，差分数组长度比原数组长度少 1，即此差分数组为[1,1,1,2,1,3]
//    n = 6;//数组最大的索引号，并非数组长度
//    for (int i = 1; i <= n; i++) 
//    {
//        updata(i, tmp[i] - tmp[i - 1]);   //对差分数组建立树状数组，此时树状数组的第一个值c[0]=0，没有真正存值
//    }
//    int x = 1, y = 4, k = 2;//[x,y]区间内加上k,x 和 y 是真正的索引号，去除了填充的0，x=1表示 a[1]=2,y=4表示 a[4]=6，也就是将[2,3,5,6]都加 2 ，a 就变成了[1,4,5,7,8,9],差分数组变成[1,3,1,2,1,1]
//    //D[x]增加k（例子中就是D[1]从 1 变到 3），又因为树状数组的索引号要加 1 ，所以最后是树状数组的 x+1 加了 k（虽然说我们修改的是差分数组D，但是真实存储的是树状数组，所以要按树状数组的索引来更新）
//    updata(x + 1, k);    
//    updata(y + 2, -k);   //D[y+1]减少k（例子中就是D[5]从 3 变到 1），又因为树状数组的索引号要加 1 ，所以最后是树状数组的 y+2 减了 k
//    int i = 2;//想要查询原始数组里第 3 个值（索引为 2） 也就是 a[2]=3=tmp[3]最终的值
//    int sum = getsum(i+1);//对差分数组求 前缀和 即为原数组的值，因为是单点查询
//    cout << sum << endl;
//    return 0;
//}

////////////////////////////////////////////区间更新、区间查询（差分数组+树状数组，带懒标记的线段树（最合适））///////////////////////////////////////

//***********************************************树状数组**********************************************
//https://blog.csdn.net/bestsort/article/details/80796531
//int n;
//int sum1[10]; //差分数组的树状数组，这里差分数组没有直接表示出来，记录的是差分数组的区间和
//int sum2[10]; //
//int lowbit(int x) {
//    return x & (-x);
//}
//void updata(int i, int k) {
//    int x = i;    //因为x不变，所以得先保存i值
//    while (i <= n)
//    {
//        sum1[i] += k;
//        sum2[i] += k * x;
//        i += lowbit(i);
//    }
//}
//int getsum(int i) {
//    int res = 0, x = i;
//    while (i > 0) 
//    {//这个循环用来求前缀和，sum1[i]不断循环求和就是 公式中的∑（i=[1:p]）d[i]，因为这个就是求前缀和，而树状数组求前缀和就是自下而上循环
//        // sum2[i]不断循环求和就是 公式中的∑（i=[1:p]）(d[i] * i)，
//        res += (x+1) * sum1[i] - sum2[i];//推导参考 https://blog.csdn.net/bestsort/article/details/80796531
//        i -= lowbit(i);
//    }
//    return res;
//}
//int main() {
//    int a[] = { 1,2,3,5,6,9 };//真正的原始数组
//    int tmp[] = {0,1,2,3,5,6,9 };//第一个0是填充值，1 的真正索引是 0。为了方便计算差分数组，差分数组长度比原数组长度少 1，即此差分数组为[1,1,1,2,1,3]
//    n = 6;//数组最大的索引号，并非数组长度
//    for (int i = 0; i < n; i++) 
//    {
//        updata(i+1, tmp[i+1] - tmp[i]);   //对差分数组建立树状数组,索引号要加 1
//    }
//    int x = 1, y = 4, k = 2;//[x,y]区间内加上k,x 和 y 是真正的索引号，去除了填充的0，x=1表示 a[2]=2,y=4表示 a[5]=6，也就是将[2,3,5,6]都加 2 ，a 就变成了[1,4,5,7,8,9],差分数组变成[1,3,1,2,1,1]
//    updata(x + 1, k);    //D[x]增加k（例子中就是D[1]从 1 变到 3），又因为树状数组的索引号要加 1 ，所以最后是树状数组的 x+1 加了 k
//    updata(y + 2, -k);   //D[y+1]减少k（例子中就是D[5]从 3 变到 1），又因为树状数组的索引号要加 1 ，所以最后是树状数组的 y+2 减了 k
//    int left = 2,right=4;//想要查询原始数组里第 3 个值（索引为 2） 到第5个值（索引为 4）的区间和
//    int sum = getsum(right+1)-getsum(left);//树状数组索引需要加 1
//    cout << sum << endl;
//    return 0;
//}
//***********************************************线段树（带懒标记）**********************************************
//https://www.pianshen.com/article/9064544677/
//https://blog.csdn.net/Tong_zhi/article/details/82683219
//http://t.csdn.cn/T0JFE
//http://t.csdn.cn/oAA0l
//class NumArray {
//private:
//    void bulid(int node,int left,int right, vector<int>& nums)//这里的start和end代表的是当前节点 node 储存的是区间 [start,end] 的总和
//    {//left=right时，到达了叶子节点，建新节点，记录区间和区间和
//        if (left == right)
//        {//到达叶子结点，直接赋值，这里可以不用给lazymark赋值，也可以直接赋值 0
//            segmentTree[node] = Node(left, right, nums[left]);
//            return;
//        }
//        else
//        {
//            segmentTree[node] = Node(left, right, 0);//否则先建新节点，记录区间，区间和暂时更新为0
//            int mid = left + (right - left) / 2;
//            bulid(2 * node + 1,left,mid,nums);//左孩子节点索引是 2*node+1（如果根节点序号是0的话，而如果根节点序号是1，那么左孩子节点就是 2*node
//            bulid(2 * node + 2, mid+1, right, nums);//右孩子节点索引是 2*node+2
//            segmentTree[node].val = segmentTree[2 * node + 1].val + segmentTree[2 * node + 2].val;//左右孩子总和相加
//        }
//    }
//    void pushdown(int node, int start, int end) {
//        //下推上一次懒标记
//        segmentTree[2 * node + 1].lazymark += segmentTree[node].lazymark;
//        segmentTree[2 * node + 2].lazymark += segmentTree[node].lazymark;
//        //更新子区间总和
//        int mid = (start + end) / 2;
//        segmentTree[2 * node + 1].val += segmentTree[node].lazymark * (mid - start + 1);
//        segmentTree[2 * node + 2].val += segmentTree[node].lazymark * (end - mid);
//        //下推后当前节点懒标记置零
//        segmentTree[node].lazymark = 0;
//    }
//    void setvalue(int node, int left,int right, int val)//这里的start和end代表的是当前节点 node 储存的是区间 [start,end] 的总和，[left,right]是我们想更新的区间
//    {//当我们要修改 [left,right]区间 的值时，我们找到完全在区间 [left,right]里面的区间节点，然后更新这个节点的lazymark和val，然后直接返回，不用更新到叶子节点
//        //比如我们要更新 [2,10]这个区间的值，让他们都 +3，那么如果此时的节点区间为[5,7]，完全包含在[2,10]内，那么只需要让[5,7]这个节点的 lazymark+3
//        //然后把这个节点的 val增加 区间长度*增加量，因为我们要把这个区间内的所有数都 +3，所以这个节点记录的区间总和 就会增加 （7-5+1）*3=9，即 node.val += 9；
//        //http://t.csdn.cn/oAA0l
//        if (left <= segmentTree[node].start && segmentTree[node].end <= right) {
//            segmentTree[node].lazymark += val;
//            segmentTree[node].val += (segmentTree[node].end - segmentTree[node].start + 1) * val;
//            return;
//        }
//        if (segmentTree[node].lazymark)//否则的话，此节点区间不完全包含在[left,right]内，那么就需要往下探索合适的区间（完全包含在[left,right]的区间）
//        { //首先要检查此节点是否有上一次的懒标记，如果有的话就要把上一次的懒标记往更小的区间推，以保证和本次的懒标记不冲突，比如[5,7]有上一次的懒标记为 +3，这一次又要更新 [5,6]的值 +2
//            //那么如果我们不把[5,7]这个节点的懒标记下推而直接更新[5,6]节点的懒标记的话，就会造成 [5,7]这个区间是全部 +3，而 [5,6]这个区间却是全部 +2，这就是冲突的，最后答案也是错误的
//            //而如果我们把 [5,7]这个节点的懒标记下推到子区间 [5,6] 和 [7,7] 的话，就能保证 [5,6]区间全部 +3，[7,7]区间全部 +3，然后再更新 [5,6]区间全部 +2，这样最终就是
//            // [5,6]区间全部 +5，[7,7]区间全部 +3，符合我们的要求
//            pushdown(node, segmentTree[node].start, segmentTree[node].end);
//        }
//        //然后开始更新本次的懒标记
//        int mid = segmentTree[node].start + (segmentTree[node].end - segmentTree[node].start) / 2;
//        if (right <= mid)
//        {//[left,right]在 左边子区间节点 里
//            setvalue(2 * node + 1, left, right, val);//保证完全包含就行了
//        }
//        else if(left>mid)
//        {//[left,right]在 右边子区间节点 里
//            setvalue(2 * node + 2, left, right, val);
//        }
//        else
//        {
//            setvalue(2 * node + 1, left, right, val);//保证完全包含就行了
//            setvalue(2 * node + 2, left, right, val);
//        }
//        segmentTree[node].val = segmentTree[2 * node + 1].val + segmentTree[2 * node + 2].val;//一定要更新上层的值，因为下层节点更新一定会影响到上层的值
//        return;
//    }
//    int query(int node, int left, int right)
//    {//给定区间 [left, right] 时，我们将区间[left, right] 拆成多个结点对应的区间。
//     //·如果结点 node 对应的区间被 [left, right] 完全包含，可以直接返回该结点的值，即当前区间和。
//     //·如果结点 node 对应的区间被 [left, right] 不完全包含，设左子结点对应的区间的右端点为 mid，那么将区间 [left, right] 沿点 mid 拆成两个区间，分别计算左子结点和右子结点。
//     //·我们从根结点开始递归地拆分区间 [left, right]。
//
//        if (left <= segmentTree[node].start && right >= segmentTree[node].end)
//        {//如果想要查询的区间和当前节点储存的区间相同，直接返回
//            return segmentTree[node].val;
//        }
//        if (segmentTree[node].lazymark)
//        {//否则的话，此节点区间不完全包含在[left,right]内，那么就需要往下探索合适的区间（完全包含在[left,right]的区间）
//            //首先检测此节点是否有懒标记，如果有的话就要懒标记往更小的区间推，因为本节点有懒标记代表着下层子区间的值是没有更新的，直接查询肯定出错
//            pushdown(node, segmentTree[node].start, segmentTree[node].end);
//        }
//        int mid = segmentTree[node].start + (segmentTree[node].end - segmentTree[node].start) / 2;
//        if (right <= mid)
//        {//当想要查询的区间完全在左孩子节点的区间内时，只递归左孩子
//            return query(2 * node + 1, left, right);
//        }
//        else if (left > mid)
//        {//当想要查询的区间完全在右孩子节点的区间内时，只递归右孩子
//            return query(2 * node + 2, left, right);
//        }
//        else
//        {//否则就是左右区间各有一部分，那么分别递归左右孩子
//            return query(2 * node + 1, left, right) + query(2 * node + 2, left, right);//注意此时我们想要查询的区间需要做出修改，因为left和right不在同一区间内
//        }
//        return 0;
//    }
//public:
//    struct Node
//    {//用node来记录线段树每个节点对应的区间以及区间和,lazymark表示“之前有一次更新操作需要将此节点所代表的区间的值都进行修改，
//        //但是因为还没有查询这个区间里面的值所以我暂时不去修改叶子节点的值，而是做一个简单记录，等到真正需要查询的时候再去修改”
//        //也就是当我们要做[0, 6]所有数加3这种更新时, 我们并没有更新树中对应结点的value, 而是去更新[0, 3] + [4, 5] + [6, 6]这三个结点的lazymark, 使之 + 3便可, 
//        //这样我们就用logn完成了区间更新, 相对的因为我们只是更新了lazymark, 故而做查询时需要将上面的lazymark向下面传导, 不过我们这样做就只用传导需要用到的那部分区间的lazymark, 大大节约了时间
//        // https://blog.csdn.net/qq_31964727/article/details/80798109
//        int start, end, val,lazymark;
//        Node() :start(0), end(0), val(0),lazymark(0) {};//必须要提供无参构造函数，因为构造vector的时候会运行构造函数，如果不提供无参构造就会报错
//        Node(int _start, int _end, int _val,int _lazymark = 0) :start(_start), end(_end), val(_val),lazymark(_lazymark) {};
//    };
//    vector<Node> segmentTree;//线段树 segmentTree 是一个二叉树，每个结点保存数组 nums 在区间 [start, end]的最小值、最大值或者总和等信息
//    int n;
//    NumArray(vector<int>& nums) :n(nums.size()), segmentTree(4 * nums.size()) {//最多需要四倍的空间,线段树空间复杂度是O（4N）
//        bulid(0,0,n-1,nums);//建树，第一个0是线段树的节点编号，第二个0和n-1是用nums[0]到nums[n-1]来建树
//    }
//    void update(int left,int right, int val) {//区间更新，[left,right]区间内的数全都加上 val
//        setvalue(0, left, right,val);
//    }
//    int sumRange(int left, int right) {//区间查询，查询[left,right]区间内的总和
//        return query(0, left, right);
//
//    }
//};

////////////////////////////////////////////掉落的方块高度最大值（区间更新、区间查询--动态开点，带懒标记的线段树）///////////////////////////////////////

//本题为「非强制在线」问题，因此可以先对数组进行离散化，将值域映射到较小的空间，然后套用固定占用 4×n 空间的线段树求解。
//但更为灵活（能够同时应对强制在线问题）的求解方式是「线段树（动态开点）」。
//同时实现动态开点的方式有两种：
//·根据操作次数对使用到的最大点数进行预估，并采用数组方式进行实现线段树（解法一）；
//·使用动态指针（解法二）；
//这里用动态指针，利用「动态指针」实现的「动态开点」可以有效避免数组估点问题，更重要的是可以有效避免 new 大数组的初始化开销，
//https://leetcode.cn/problems/falling-squares/solution/by-ac_oier-zpf0/
//class Solution {
//public:
//    int N = (int)1e9;//最大范围
//    struct Node {
//        Node* ls, * rs;// ls 和 rs 分别代表当前区间的左右子节点
//        int val, add;// val 代表当前区间的最大高度，add 为懒标记
//    };
//    Node* root = new Node();//root节点保存的是区间[0:N]上的最大值
//    void pushdown(Node* node) {
//        if (node->ls == nullptr) 
//            node->ls = new Node();//动态指针开点，需要子区间的时候才去创建子区间，对于那种强制在线的问题很实用
//        if (node->rs == nullptr) 
//            node->rs = new Node();
//        if (node->add == 0) //如果本节点区间的懒标记为0，说明下面的子区间的最大值就是0，创建节点的默认值就已经是0了，不需要下面的赋值操作，直接返回，当然再赋值一遍也没啥问题
//            return;
//        node->ls->add = node->add;//更新子区间的子区间的最大值
//        node->rs->add = node->add;
//        node->ls->val = node->add;//更新子区间的最大值 
//        node->rs->val = node->add;
//        node->add = 0;//更新完子区间的最大值后如果不把本节点区间的最大值归0，就会造成和子区间的最大值冲突问题，比如想要更新[2,10]区间的最大值为6，遍历到[5,7]区间时，发现完全包含在[2,10]内，直接更新
//        //[5,7]区间最大值val和子区间最大值add，返回；下一次想要更新[3,6]区间的最大值为7，遍历到[5,7]区间时，发现不完全包含，那么此时需要动态开点，划分子区间[5,6]和[7,7]，然后根据上一次更新的懒标记
//        //[5,7]子区间内最大值为6，则[5,6]区间最大值val=6，其子区间最大值 add=6，[7,7]区间最大值val=6，其子区间最大值 add=6,如果此时不归0，那么后面更新[5,6]区间最大值为7的时候，就会出现
//        //[5,7]子区间最大值为6，但是[5,6]区间最大值为7，这是矛盾的
//    }
//    void update(Node* node, int lc, int rc, int l, int r, int v) {//v就代表更新[l,r]区间的最大值是v，直接更新，而不用像计算区间和那样只更新增加的那部分
//        if (l <= lc && rc <= r) 
//        {//lc，rc是节点node的区间范围，也可以写到结构体里面去，如果更新区间[l,r]完全包含[lc,rc]，那么直接更新最大值
//            node->val = v;//更新[lc,rc]这段区间的最大值是v
//            node->add = v;//懒标记也更新，表示下面的子区间最大值也是v，但是实际上不继续往下更新了，实现了logn的更新时间复杂度
//            return;
//        }
//        pushdown(node);
//        int mid = (lc + rc) >> 1;
//        if (l <= mid) //更新子区间最大值，如果包含左边子区间，就更新左边子区间
//            update(node->ls, lc, mid, l, r, v);
//        if (r > mid) 
//            update(node->rs, mid + 1, rc, l, r, v);//如果包含右边子区间，就更新右边子区间，如果两边都包含，就各自更新，和上面那种写法没啥区别
//        node->val = max(node->ls->val, node->rs->val);//最后还要更新本节点区间的最大值
//    }
//    int query(Node* node, int lc, int rc, int l, int r) {
//        if (l <= lc && rc <= r) //如果查询区间[l,r]完全包含[lc,rc]，那么直接返回最大值
//            return node->val;
//        pushdown(node);//查询的时候也要更新最大值，因为如果当前节点的懒标记不为0，说明上次没有更新子区间最大值的，也就是现在的子区间最大值为0，如果直接查询，就肯定会出错
//        int mid = (lc + rc) >> 1, ans = 0;
//        if (l <= mid) //如果包含左边子区间，先记录左边子区间的最大值
//            ans = query(node->ls, lc, mid, l, r);
//        if (r > mid) //再和右边子区间的最大值相比较
//            ans = max(ans, query(node->rs, mid + 1, rc, l, r));
//        return ans;//返回当前节点区间的最大值
//    }
//    vector<int> fallingSquares(vector<vector<int>>& positions) {
//        int n = positions.size();
//        vector<int>ans;
//        for (auto& info : positions) 
//        {//x表示左边界，h是边长，x+h-1表示右边界，这是因为不同方块之间的边缘可以重合，但不会导致方块叠加，此时高度是不累加的
//            int x = info[0], h = info[1], cur = query(root, 0, N, x, x + h - 1);//root节点保存的是区间[0:N]上的最大值，先查询[x,x+h-1]的最大高度，因为当前方块就要落在这块区间
//            update(root, 0, N, x, x + h - 1, cur + h);//直接更新区间[x,x+h-1]的最大高度为cur + h，而不是像更新区间和那样只更新增加的部分
//            ans.push_back(root->val);//每落下一个方块，都要记录一下总区间内的最大值
//        }
//        return ans;
//    }
//};

////////////////////////////////////////////以图中任意节点为根节点建立树 的最小高度///////////////////////////////////////

//https://leetcode-cn.com/problems/minimum-height-trees/solution/zui-rong-yi-li-jie-de-bfsfen-xi-jian-dan-zhu-shi-x/1488539
// 越是靠里面的节点越有可能是最小高度树。
// 从边缘开始，先找到所有出度为1的节点(相连结点数为1)，然后把所有出度为1的节点进队列，然后不断地bfs，最后找到的就是两边同时向中间靠近的节点，也就是到其他叶子节点最近的节点。
// 从外向内，一层一层剥离，得到的"最里层结点"就是目标结果
//const int N = 2e4 + 10, M = 4e4 + 10;
//int h[N], e[M], ne[M], idx = 0;//用邻接表来保存邻居节点
//void add(int a, int b)
//{
//    e[idx] = b;
//    ne[idx] = h[a];
//    h[a] = idx++;
//}
//int main()
//{
//    int n = 10;//n个节点，n-1条边，说明每两个节点之间只有一条路径，那么越靠近中心的节点建成的树高度最小，所以任务就是找到最中心的那些节点，这些节点到达距离它最远的叶子节点的距离相同
//               //所以最终只有一个（n为奇数）或两个节点（n为偶数）满足条件，也就是如果以此节点为根，那么左子树的高度和右子树的高度差 1 ，这样的树具有最小的高度
//    vector<vector<int>> edges = { {0,1},{1,2}, {2,3}, {3,4}, {4,5}, {5,6}, {6,7}, {7,8}, {8,9} };
//    if (n == 1) {
//        return { 0 };
//    }
//    int degree[N];// 建立每个结点对应的度 (相连结点的个数)
//    memset(h, -1, sizeof(h));
//    memset(degree, 0, sizeof(degree));
//    vector<int> res;
//    for (int i = 0; i < edges.size(); ++i) {
//        // 每个结点对应的度+1
//        ++degree[edges[i][0]];
//        ++degree[edges[i][1]];
//        // 建立"每个结点相连的结点"组成的表
//        add(edges[i][0], edges[i][1]);
//        add(edges[i][1], edges[i][0]);
//    }
//
//    queue<int> que;
//    // 队列中存放外层叶子结点
//    for (int i = 0; i < n; ++i) {
//        if (degree[i] == 1) {  // 叶子结点（度为 1 的节点）
//            que.push(i);
//        }
//    }
//    while (!que.empty()) {
//        res.clear();  // 更新result (如果不是最里层结点，就会被抛弃)
//        int size = que.size();
//        // 让外层叶子结点出队 (相当于剪去最外层叶子结点，从而露出新的叶子结点，即里层一点的结点)
//        while (size--) {//同一层次的要一起更新，因为有清空result数组的操作，同一层次的全部加入数组或者全部清空
//            int leaft = que.front();
//            que.pop();                 // 剪去该层叶子结点
//            res.push_back(leaft);   // 将该层叶子结点加入结果，如果不是最里层，还是会清空的。直到找到最里层叶子结点，即结果
//            // 更新与 "被剪去的叶子结点" 相连的结点，如果因为该叶子结点被剪去，而使得其相连结点为"叶子结点"，则将其相连结点入队 (一圈一圈剪，最终得到最里层，即结果)
//            for (int i = h[leaft];i != -1;i = ne[i])
//            {
//                --degree[e[i]];
//                if (degree[e[i]] == 1)
//                {
//                    que.push(e[i]);
//                }
//            }
//        }
//    }
//    for (auto& i : res)
//    {
//        cout << i << ' ';
//    }
//    return 0;
//}

////////////////////////////////////////////用完所有火柴棍能够摆出的最大数字///////////////////////////////////////

//https://www.nowcoder.com/questionTerminal/f9c54db77d44469080b0e6e9c361db88?answerType=1&f=discussion
//输入：
//20 4
//3 7 8 4
//输出:777773(字符串）
//bool backtrack(map<int, int>& mt, vector<pair<int, int>> v, string& ret, int n) {
//    //base case
//    if (n == 0) 
//    {//火柴棍用完了，返回true，表示已经找到合适的方案
//        return true;
//    }
//    for (int i = 0; i < v.size();i++) {
//        if (v[i].second <= n) {//当前得满足剩余的火柴棍得数目
//            ret.push_back(v[i].first + '0');//摆出这个数字，消耗掉相应的火柴
//            if (backtrack(mt, v, ret, n - v[i].second))//当前字符以及对应得剩余火柴棍数
//            {
//                return true;//找到合适的方案就直接返回
//            }
//            ret.pop_back();//回溯
//        }
//    }
//    return false;//无法用光所有的火柴棍，需要重新规划前面的摆放数字，题目保证所一定有一种方案可以用完所有火柴棍
//}
//int main() 
//{
//    map<int, int> nums = { {1,2}, {2,5}, {3,5}, {4,4}, {5,5}, {6,6}, {7,3}, {8,7}, {9,6}};
//    int n, m, x;
//    while (cin >> n >> m) {//n根火柴，只能摆 m 种数字
//        vector<pair<int, int>> v;//数字以及对应的火柴棍的数量
//        for (int i = 0; i < m;i++) {
//            cin >> x;// x 是允许摆的数字
//            v.push_back({ x,nums[x] });
//        }
//
//        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
//            if (a.second != b.second) {
//                return a.second < b.second;//需要火柴棍少的数放在前面，因为需要的火柴少，就能摆出更多的数字，位数更多这个数就越大
//            }
//            else {
//                return a.first > b.first; //需要火柴棍相同时，大的数字在前面，比如 3 和 5 都需要5根火柴，那么 5 在 3 的前面
//            }
//            });
//        string res = "";
//        //回溯，来找在满足排序条件下最终能组成得字符串
//        backtrack(nums, v, res, n);//当前字符以及对应得剩余火柴棍数
//        sort(res.begin(), res.end(), [](char a, char b) {
//            return a > b;//确保数字从大到小排序，这样得到的就是最大的数字
//            });
//        cout << res << endl;
//    }
//    return 0;
//}

////////////////////////////////////////////n 种面额的纸币每个月发 m 的工资，最多能发几个月的///////////////////////////////////////

//https://www.nowcoder.com/questionTerminal/e47cffeef25d43e3b16c11c9b28ac7e8?answerType=1&f=discussion
//输入：
//3 51
//100 1
//50 4
//1 2
//输出：4
//注意钱不能找零, 所以:
//100能支付一个月工资
//50 + 1，50 + 1能支付两个月工资
//50 + 50能支付一个月工资
//即最多能支付四个月的工资。
//const int N = 100;
//struct Money 
//{
//    int x, y;//面额是x，总共有 y 张
//    bool operator < (const Money e) const
//    {
//        return this->x < e.x;
//    }
//} money[N];
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    int n, m;//n种不同的面额，每个月至少发放 m 元工资
//    cin >> n >> m;
//    for (int i = 0;i < n;++i)
//        cin >> money[i].x >> money[i].y;//每种纸币的面额和张数
//    sort(money, money + n,less<Money>());//金额小的放前面
//    int ans = 0;
//    while (1) 
//    {//一次循环是凑 m 的过程，凑不够（rest>0）就退出while循环
//        int need, rest = m;//支付了need张纸币，还需要rest的钱
//        for (int i = n - 1;i >= 0;--i) {
//            if (money[i].y == 0) //此面额的纸币没有了
//                continue;
//            need = rest / money[i].x;//需要多少张此面额的纸币，如果此面额大于所需的钱，那么need=0，说明我们暂时不需要此金额的钱，优先支付 等于m 的工资，到最后迫不得已才去支付 大于m 的工资
//            if (need > money[i].y) //如果需要的太多了，就只能提供 y 张
//                need = money[i].y;
//            money[i].y -= need;
//            rest -= need * money[i].x;//还需要支付多少钱
//            if (rest == 0) break;//如果刚好凑够 m 块钱，那么就不在继续这个for循环，开始凑下一个 m（下面两个 if 都不会在这一次循环里执行）
//        }
//        //不能凑齐m，优先用小额的钱去补
//        if (rest != 0) //到这里rest一定大于0
//        {
//            for (int i = 0;i < n;++i) {
//                if (money[i].y == 0) 
//                    continue;
//                need = rest / money[i].x + 1;//注意这里need要加 1 ，因为我们已经找不到正好等于 m 的纸币组合方案了，只能支付 大于 m的工资
//                if (need > money[i].y) //如果需要的太多了，就只能提供 y 张
//                    need = money[i].y;
//                money[i].y -= need;
//                rest -= need * money[i].x;
//                if (rest < 0) //rest 小于0 说明我们已经支付了 大于 m的工资，结束这个for循环，开始凑下一个 m 
//                    break;  //这里不用考虑等于0，因为如果这里等于0的话说明有一种方案能刚好凑够 m，那么就根本不可能进入这个for循环
//            }
//        }
//        if (rest > 0) //如果我们用完所有的纸币，都无法凑齐 m 块钱，那么最多就只能支付 ans 个月的工资，注意这里break以后不在执行 ans++
//            break;
//        ans++;//注意ans++不能放在前面，因为不知道剩下的钱能否凑齐 m， 当 rest <= 0 时，说明我们还能凑齐 m 发一个月工资，这时才执行 ans++
//    }
//    cout << ans << endl;
//    return 0;
//}

////////////////////////////////////////////union 以及指针和整数之间的转换问题///////////////////////////////////////

//union myun
//{
//    struct 
//    { 
//        int x; 
//        int y; 
//        int z; 
//    }u;
//    long long k;
//}a;
//int main()
//{
//    //int* b1 = (int*)(0);//0x00000000
//    //int* c1 = b1 + 4;//0x00000010，注意b1是int型指针，每次加 1 相当于往后移动 4 字节，总共移动16字节，用16进制表示就是0x00000010
//    //cout << int(c1) << endl;//输出16，把16进制数转化成10进制
//    //double* b2 = (double*)(0);//0x00000000
//    //double* c2 = b2+4;//0x00000020，注意b2是double型指针，每次加 1 相当于往后移动 8 字节，总共移动32字节，用16进制表示就是0x00000020
//    //cout << int(c2) << endl;//输出32
//    
//    a.u.x = 4;
//    a.u.y = 5;
//    a.u.z = 6;
//    a.k = 0x0000000200000001;
//    printf("%d %d %d\n", a.u.x, a.u.y, a.u.z);//输出1 2 6，因为 k 和结构体u共享内存，所以给 k 赋值的时候会覆盖低地址的 8 个字节，
//                                              //然后用 long long 的8个字节去填充，低字节的 0x00000001 赋给 x，高字节的0x00000002赋给y 
//    printf("%d\n", sizeof(a));//输出 16
//    return 0;
//}

////////////////////////////////////////////n个人选择m个食堂，最长队伍的期望///////////////////////////////////////

//int n, m;//n个人，m个食堂
//int a[56];//每个食堂有多少个窗口
//double dp[56][56][56];
//double C[56][56];//用来计算组合数，就是C(i,j)，从i个里面拿j个有多少方案
//int main()
//{
//    n = 5, m = 5;//n个人，m个食堂
//    C[0][0] = 1.0;//0个里面拿0个只有1种方案
//    for (int i = 1;i <= 55;i++)
//    {// i 个里面拿0个只有1种方案，那就是不拿
//        C[i][0] = 1.0;
//        for (int j = 1;j <= i;j++)
//        {//这个式子有多种表达式 ，比如C[i][j] = (i-j+1)*C[i][j-1]/j 也是对的
//            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
//        }
//    }
//    for (int i = 1;i <= m;i++)
//        a[i] = 5;//每个食堂有多少个窗口
//    for (int i = 0;i <= n;i++) 
//        dp[0][0][i] = i;//k应该表示第 i 个食堂内 最长队伍 的长度，这个是一个假设的数，
//
//    for (int i = 1;i <= m;i++)
//    {//i 表示在[0:i]个食堂内选择一个去吃饭
//        for (int j = 0;j <= n;j++)
//        {//j表示总共吃饭的人数
//            for (int k = 0;k <= n;k++)
//            {//k应该表示第 i 个食堂内 最长队伍 的长度（猜测）
//                for (int c = 0;c <= j;c++)
//                {//c是选择在第 i 个食堂吃饭的人数 [0;j]
//                    //在第 i 个食堂内有不同的人来吃饭，不同的人数对所有食堂内 最长队伍 的长度有影响，所以 Max 代表排除第 i 个食堂后，[0,i-1]这些食堂内的最长队伍长度（猜测）
//                    //tmp=(c + a[i] - 1) / a[i]表示第 i 个食堂内最长队伍的长度，当c=0时，tmp=0，此时长度为0，所有窗口都没有人，当c=1时，tmp=1，此时最长长度为1...
//                    //总共有 j 个人，在第 i 个食堂里吃饭的有 c 个人，这个概率就是 pow(i - 1, j - c) / pow(i, j) * C[j][c]，j个人选择在 i 个食堂，每个人都有 i 种选择，总个数为 i^j,也就是 pow(i, j)
//                    //j - c 个人选择其他食堂，则他们每个人只有 i-1种选择（因为不能选第 i 个食堂），个数为(i-1)^(j-c)，也就是 pow(i - 1, j - c) ，还要随便选 c 个人来第 i 个食堂吃饭，就是C[j][c]
//                    //
//                    int tmp = (c + a[i] - 1) / a[i];
//                    int Max = max(k, tmp);
//                    dp[i][j][k] += dp[i - 1][j - c][Max] * pow(i - 1, j - c) / pow(i, j) * C[j][c];
//                }
//            }
//        }
//    }
//    printf("%.10f\n", dp[m][n][0]);
//    return 0;
//}
//

////////////////////////////////////////////二叉平衡搜索数的建立和重平衡///////////////////////////////////////

//template <typename T>
//struct AVLTreeNode
//{
//    T m_key;                  // 关键字
//    int m_height;             // 高度
//    AVLTreeNode* m_leftChild; // 左孩子
//    AVLTreeNode* m_rightChild; // 右孩子
//    AVLTreeNode(T value, AVLTreeNode* l, AVLTreeNode* r) : m_key(value), m_height(0), m_leftChild(l), m_rightChild(r) {}
//};
//
//template <typename T>
//class AVLTree
//{
//public:
//    AVLTree() : m_root(NULL) {}
//    ~AVLTree() { destroy(m_root); }
//
//public:
//    // 中序遍历
//    void inOrder() { inOrder(m_root); }
//
//    // 先序遍历
//    void preOrder() { preOrder(m_root); }
//
//    // 树的高度
//    int height() { return height(m_root); }
//
//    // 查找AVL树种值为key的结点（递归）
//    AVLTreeNode<T>* search(T key) { return search(m_root, key); }
//
//    // 查找AVL树种值为key的结点（非递归）
//    AVLTreeNode<T>* iterativeSearch(T key) { return iterativeSearch(m_root, key); }
//
//    // 查找最小结点，返回最小结点的键值
//    T minimum()
//    {
//        AVLTreeNode<T>* p = minimum(m_root);
//        if (p != NULL)
//            return p->m_key;
//        return (T)NULL;
//    }
//
//    // 查找最大结点，返回最大结点的键值
//    T maximum()
//    {
//        AVLTreeNode<T>* p = maximum(m_root);
//        if (p != NULL)
//            return p->m_key;
//        return (T)NULL;
//    }
//
//    // 将键值为key的结点插入到AVL中
//    void insert(T key) { insert(m_root, key); }
//
//    // 删除键值为key的结点
//    void remove(T key)
//    {
//        AVLTreeNode<T>* z = search(m_root, key);
//        if (z != NULL)
//            m_root = remove(m_root, z);
//    }
//
//    // 销毁AVL树
//    void destroy() { destroy(m_root); }
//
//private:
//    void inOrder(AVLTreeNode<T>* node)
//    {
//        if (node == NULL)
//            return;
//        inOrder(node->m_leftChild);
//        cout << node->m_key << " ";
//        inOrder(node->m_rightChild);
//    }
//
//    void preOrder(AVLTreeNode<T>* node)
//    {
//        if (node == NULL)
//            return;
//        cout << node->m_key << " ";
//        preOrder(node->m_leftChild);
//        preOrder(node->m_rightChild);
//    }
//
//    int height(AVLTreeNode<T>* node)
//    {
//        return node != NULL ? node->m_height : 0;
//    }
//
//    void destroy(AVLTreeNode<T>*& tree)
//    {
//        if (tree == NULL)
//            return;
//        if (tree->m_leftChild != NULL)
//            destroy(tree->m_leftChild);
//        if (tree->m_rightChild != NULL)
//            destroy(tree->m_rightChild);
//        delete tree;
//    }
//
//    AVLTreeNode<T>* search(AVLTreeNode<T>* node, T key)
//    {
//        if (node == NULL || node->m_key == key)
//            return node;
//        if (key < node->m_key)
//            return search(node->m_leftChild, key);
//        else
//            return search(node->m_rightChild, key);
//    }
//
//    AVLTreeNode<T>* iterativeSearch(AVLTreeNode<T>* node, T key)
//    {
//        while ((node != NULL) && (node->m_key != key))
//        {
//            if (key < node->m_key)
//                node = node->m_leftChild;
//            else
//                node = node->m_rightChild;
//        }
//        return node;
//    }
//
//    AVLTreeNode<T>* minimum(AVLTreeNode<T>* node)
//    {
//        if (node == NULL)
//            return NULL;
//        while (node->m_leftChild != NULL)
//        {
//            node = node->m_leftChild;
//        }
//        return node;
//    }
//
//    AVLTreeNode<T>* maximum(AVLTreeNode<T>* node)
//    {
//        if (node == NULL)
//            return NULL;
//        while (node->m_rightChild != NULL)
//        {
//            node = node->m_rightChild;
//        }
//        return node;
//    }
//
//    AVLTreeNode<T>* insert(AVLTreeNode<T>*& node, T key)
//    {
//        if (node == NULL)
//        {
//            node = new AVLTreeNode<T>(key, NULL, NULL);//新节点默认高度是0，但是一旦创建出来立马更新高度为 1
//        }
//        else if (key < node->m_key) // key插入node的左子树的情况
//        {
//            node->m_leftChild = insert(node->m_leftChild, key);
//            // 插入节点后，如果AVL树失衡，需要进行相应调节
//            if (height(node->m_leftChild) - height(node->m_rightChild) == 2)
//            {
//                if (key < node->m_leftChild->m_key)//LL失衡,需要LL旋转
//                    node = RightRotation(node);
//                else
//                    node = leftRightRotation(node);//LR失衡,需要LR旋转
//            }
//        }
//        else if (key > node->m_key) // key插入node的右子树的情况
//        {
//            node->m_rightChild = insert(node->m_rightChild, key);
//            // 插入节点后，如果AVL树失衡，需要进行相应调节
//            if (height(node->m_rightChild) - height(node->m_leftChild) == 2)
//            {
//                if (key > node->m_rightChild->m_key)
//                    node = LeftRotation(node);
//                else
//                    node = rightLeftRotation(node);
//            }
//        }
//        else
//        {
//            cout << "添加失败，不能添加相同的结点" << endl;
//        }
//        node->m_height = max(height(node->m_leftChild), height(node->m_rightChild)) + 1;//递归子树完毕后要更新上层高度，这里叶子节点
//                                                                                        //高度为1，往上依次加1
//        return node;
//    }
//
//    AVLTreeNode<T>* remove(AVLTreeNode<T>*& node, AVLTreeNode<T>* z)
//    {
//        if (node == NULL || z == NULL)
//            return NULL;
//
//        if (z->m_key < node->m_key) // 待删除的节点在tree的左子树中
//        {
//            node->m_leftChild = remove(node->m_leftChild, z);
//            // 删除节点后，如果AVL树失衡，需要进行相应调节
//            if (height(node->m_rightChild) - height(node->m_leftChild) == 2)
//            {
//                AVLTreeNode<T>* r = node->m_rightChild;
//                if (height(r->m_leftChild) > height(r->m_rightChild))
//                    node = rightLeftRotation(node);
//                else
//                    node = LeftRotation(node);
//            }
//        }
//        else if (z->m_key > node->m_key) //待删除的节点在node的右子树中
//        {
//            // 删除节点后，如果AVL树失衡，需要进行相应调节
//            node->m_rightChild = remove(node->m_rightChild, z);
//            if (height(node->m_leftChild) - height(node->m_rightChild) == 2)
//            {
//                AVLTreeNode<T>* l = node->m_leftChild;
//                if (height(l->m_rightChild) > height(l->m_leftChild))
//                    node = leftRightRotation(node);
//                else
//                    node = RightRotation(node);
//            }
//        }
//        else //当前node就是要删除的节点
//        {
//            if ((node->m_leftChild != NULL) && (node->m_rightChild != NULL))
//            {
//                if (height(node->m_leftChild) > height(node->m_rightChild))
//                {
//                    /* 如果node节点的左子树比右子树高，则:
//                        * (01)找出node的左子树中最大节点
//                        * (02)将该最大节点的值赋值给node
//                        * (03)删除该最大节点
//                        * 相当于用node的左子树中最大节点作为node的替身
//                        * 这种方式删除node左子树中最大节点之后，AVL树任然是平衡的
//                        */
//                    AVLTreeNode<T>* max = maximum(node->m_leftChild);
//                    node->m_key = max->m_key;
//                    node->m_leftChild = remove(node->m_leftChild, max);
//                }
//                else
//                {
//                    /* 如果node节点的右子树比左子树高，则:
//                        * (01)找出node的右子树中最小节点
//                        * (02)将该最小节点的值赋值给node
//                        * (03)删除该最小节点
//                        * 相当于用node的右子树中最小节点作为node的替身
//                        * 这种方式删除node右子树中最小节点之后，AVL树任然是平衡的
//                        */
//                    AVLTreeNode<T>* min = minimum(node->m_rightChild);
//                    node->m_key = min->m_key;
//                    node->m_rightChild = remove(node->m_rightChild, min);
//                }
//            }
//            else
//            {
//                // 被删除的节点等于node，并且node有一个孩子
//                // 将当前节点指向该孩子节点并删除当前节点
//                AVLTreeNode<T>* tmp = node;
//                node = node->m_leftChild != NULL ? node->m_leftChild : node->m_rightChild;
//                delete tmp;
//            }
//        }
//        return node;
//    }
//
//private:
//    /* LL：插入到左子树的左边导致 k2 节点失去平衡，此时是LL失衡，所以需要 右旋一次（以k1为轴）
//     *          k2              k1
//     *         /  \            /  \
//     *        k1   z   ===>   x    k2
//     *       /  \            /    /  \
//     *      x    y         new   y    z
//     *     /
//     *   new
//     */
//
//    AVLTreeNode<T>* RightRotation(AVLTreeNode<T>*& k2)//传入节点是失衡的结点，并不是作为旋转轴的那个节点，旋转轴节点是失衡节点的孩子节点
//    {
//        AVLTreeNode<T>* k1 = k2->m_leftChild;
//        k2->m_leftChild = k1->m_rightChild;
//        k1->m_rightChild = k2;
//        //只需要更新k1和k2两个节点的高度，因为他们的子节点尽管位置可能发生变化，但是高度是不变的，因为并没有给子节点下面添加节点
//        //或者删除节点，那么高度自然不会变化
//        k2->m_height = max(height(k2->m_leftChild), height(k2->m_rightChild)) + 1;
//        k1->m_height = max(height(k1->m_leftChild), k2->m_height) + 1;
//        return k1;//新的根节点
//    }
//
//    /* RR：插入到右子树的右边导致 k1 节点失去平衡，此时是RR失衡，所以需要 左旋一次（以k2为轴）
//     *       k1              k2
//     *      /  \            /  \
//     *     x   k2   ===>   k1   z
//     *        /  \        /  \   \
//     *       y    z      x    y  new
//     *             \
//     *             new
//     */
//    AVLTreeNode<T>* LeftRotation(AVLTreeNode<T>*& k1)
//    {
//        AVLTreeNode<T>* k2 = k1->m_rightChild;
//        k1->m_rightChild = k2->m_leftChild;
//        k2->m_leftChild = k1;
//
//        k1->m_height = max(height(k1->m_leftChild), height(k1->m_rightChild)) + 1;
//        k2->m_height = max(height(k2->m_rightChild), k1->m_height) + 1;
//        return k2;
//    }
//
//    /* LR：插入到左子树的右边导致 k3 节点失去平衡，此时是LR失衡，所以需要 左旋一次（以k2为轴）+右旋一次（以k2为轴）
//     *       k3               k3               k2           或者      k3               k3               k2 
//     *      /  \     LL      /  \     RR      /  \                   /  \     LL      /  \     RR      /  \
//     *     k1   D   ===>   k2    D   ===>   k1    k3                k1   D   ===>   k2    D   ===>   k1    k3
//     *    /  \            /                /  \     \              /  \            /  \             /     /  \
//     *   A    K2         k1               A   new    D            A    K2         k1  new          A    new   D
//     *       /          /  \                                             \       /  
//     *     new         A   new                                           new    A    
//     */
//    AVLTreeNode<T>* leftRightRotation(AVLTreeNode<T>*& k3)
//    {
//        k3->m_leftChild = LeftRotation(k3->m_leftChild);
//        return RightRotation(k3);
//    }
//
//    /* RL：插入到右子树的左边导致 k3 节点失去平衡，此时是RL失衡，所以需要 右旋一次（以k2为轴）+左旋一次（以k2为轴）
//     *     k1               k1                K2               或者             k1               k1                K2 
//     *    /  \      LL     /  \      RR      /  \                              /  \      LL     /  \      RR      /  \
//     *   A    k3   ===>   A    k2   ===>   k1    K3                           A    k3   ===>   A    k2   ===>   k1    K3
//     *       /  \             /  \        /  \     \                              /  \                \        /     /  \
//     *      k2   D          new   k3     A   new    D                            k2   D                k3     A    new   D
//     *     /                        \                                             \                   /  \
//     *   new                         D                                            new                new  D
//     */
//    AVLTreeNode<T>* rightLeftRotation(AVLTreeNode<T>*& k1)
//    {
//        k1->m_rightChild = RightRotation(k1->m_rightChild);
//        return LeftRotation(k1);
//    }
//
//private:
//    AVLTreeNode<T>* m_root; // AVL树的根节点
//};
//
//int main()
//{
//    AVLTree<int> tree;
//    tree.insert(3);
//    tree.insert(2);
//    tree.insert(1);
//    tree.insert(4);
//    tree.insert(5);
//    tree.insert(6);
//    tree.insert(7);
//
//    tree.insert(16);
//    tree.insert(15);
//    tree.insert(14);
//    tree.insert(13);
//    tree.insert(12);
//    tree.insert(11);
//    tree.insert(10);
//    tree.insert(8);
//    tree.insert(9);
//
//    tree.preOrder();
//    cout << endl;
//    tree.inOrder();
//    cout << endl;
//
//    tree.remove(8);
//    tree.preOrder();
//    cout << endl;
//    tree.preOrder();
//    cout << endl;
//
//    return 0;
//}

////////////////////////////////////////////通过DFS构建一个整数列表///////////////////////////////////////

//https://leetcode-cn.com/problems/mini-parser/solution/mi-ni-yu-fa-fen-xi-qi-by-leetcode-soluti-l2ma/
//输入：s = "[123,[456,[789]]]",
//输出：[123, [456, [789]]]
//解释：返回一个 NestedInteger 对象包含一个有两个元素的嵌套列表：
//      1. 一个 integer 包含值 123
//      2. 一个包含两个元素的嵌套列表：
//          i.一个 integer 包含值 456
//          ii.一个包含一个元素的嵌套列表
//              a.一个 integer 包含值 789
//class NestedInteger {
//public:
//         // Constructor initializes an empty nested list.
//        NestedInteger();
//    
//            // Constructor initializes a single integer.
//        NestedInteger(int value);
//    
//             // Return true if this NestedInteger holds a single integer, rather than a nested list.
//        bool isInteger() const;
//    
//             // Return the single integer that this NestedInteger holds, if it holds a single integer
//             // The result is undefined if this NestedInteger holds a nested list
//        int getInteger() const;
//    
//             // Set this NestedInteger to hold a single integer.
//        void setInteger(int value);
//    
//             // Set this NestedInteger to hold a nested list and adds a nested integer to it.
//        void add(const NestedInteger& ni);
//    
//             // Return the nested list that this NestedInteger holds, if it holds a nested list
//             // The result is undefined if this NestedInteger holds a single integer
//        const vector<NestedInteger>& getList() const;
//};
//int index = 0;
//NestedInteger deserialize(string s) {//s = "[123,[456,[789]]]"
//    if (s[index] == '[') 
//    {//遇到[，说明后面是一个整数列表
//        index++;//index是全局变量，每层递归都能改变
//        NestedInteger ni;//首先创建一个空的列表
//        while (s[index] != ']') 
//        {//不等于]的时候说明：上面那个[还没有找到对应的]，因此要一直循环
//            ni.add(deserialize(s));//注意此时的index已经往后移了
//            if (s[index] == ',') 
//            {//添加完一个整数列表（可能是整数，也可能是整数列表），如果后面是 ，号，说明后面还有整数列表需要参加，index右移
//                index++;
//            }
//        }
//        index++;//退出循环的时候说明对应的 [ 和 ] 已经找齐了，也就是已经构造了一个完整的整数列表，此时s[index]=']'，为了不影响上一层递归，index要右移
//        return ni;//返回构造好的整数列表
//    }
//    else 
//    {//否则的话把这个数字取出来，
//        bool negative = false;
//        if (s[index] == '-') {
//            negative = true;
//            index++;
//        }
//        int num = 0;
//        while (index < s.size() && isdigit(s[index])) {
//            num = num * 10 + s[index] - '0';
//            index++;
//        }
//        if (negative) {
//            num *= -1;
//        }
//        return NestedInteger(num);//一个整数也可以作为整数列表返回
//    }
//}

////////////////////////////////////////////北邮计算GPA///////////////////////////////////

//int main()
//{
//    vector<double> Grade_point;
//    vector<int> credit;
//    int credit_sum = 0;
//    double sum = 0;
//    for (int i = 0;i < 13;i++)
//    {
//        int a,b;
//        cin >> a >> b;
//        credit.push_back(a);
//        credit_sum += a;
//        double c = 4 - 3 * pow(100 - b, 2) / 1600;
//        cout << c << endl;
//        Grade_point.push_back(c);
//        sum += a * c;
//    }
//    double GPA = sum / credit_sum;
//    cout << GPA << endl;
//    return 0;
//}

////////////////////////////////////////////文件的最长绝对路径的长度///////////////////////////////////////

//https://leetcode-cn.com/problems/longest-absolute-file-path/solution/wen-jian-de-zui-chang-jue-dui-lu-jing-by-fi0r/1517112
//int main()
//{
//    string input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
//    //'\n' 和 '\t' 分别是换行符和制表符。
//    //·\n 代表换行，后面可能是子文件、子文件夹、同级文件、同级文件夹
//    //·\n\t 代表换行并且进入子目录，后面可能是子文件、子文件夹
//    //·总之，\t的个数代表目录深度
//    stringstream ss(input);
//    string buf;
//    int res = 0;
//    int d[1000];//d[i]表示深度为 i 的文件/文件夹具有的绝对路径的长度，就是字符串的长度 (不包括每个目录之间插入的‘ / ’
//    d[0] = 0;//深度为0，代表没有任何目录，长度为0
//    vector<string> lines;//记录每一级目录
//    while (getline(ss, buf, '\n'))
//    {//按照换行符分开每个目录，注意此时的目录带有\t，是深度信息
//        lines.push_back(buf);
//    }
//    for (string line : lines) 
//    {
//        int depth = count(line.begin(), line.end(), '\t');//有几个\t就代表当前目录深度是 depth+1，比如“dir”有0个/t，表示深度为 1
//                                                          //“\tsubdir1”有 1 个/t，表示深度为 2，它的 父目录 为dir，深度为 1
//        d[depth + 1] = d[depth] + line.size() - depth;//d[depth]表示 当前文件/文件夹（lines）的 父目录 的长度
//                                                      //比如“dir”深度为 1 ，它的父目录深度就是 0
//        //lines.size()-depth表示去掉 \t 后当前文件/文件夹的长度，则d[depth + 1]表示 当前文件/文件夹绝对路径的长度（父目录绝对路径的长度 +当前文件长度）
//        if (string::npos != line.find('.')) 
//        {//如果当前的是一个文件，则刷新最长绝对路径的长度，因为不可能在进入下一级目录了
//            res = max(res, d[depth + 1] + depth);//d[depth + 1]表示字符串具有的长度，depth表示每个目录之间插入的 '/ ' 的个数，深度为 depth+1  就要插入 depth 个 ' / ',因为最上层目录不需要 ' / '
//        }
//    }
//    return res;
//}

////////////////////////////////////////////能被七整除的子序列的最大和///////////////////////////////////////

//https://www.nowcoder.com/questionTerminal/fa6e601b639e43948ea9f45ea2543ae5?answerType=1&f=discussion
//输入：7 3 1 4
//输出：14（7+3+4）
//int main()
//{
//    vector<int> data;
//    int num;
//    while (cin >> num)//当不知道有多少个数要输入时，就用这种方法
//        data.push_back(num);
//    vector<int> dp(7, 0); //dp[i]表示除以7余i的累加和的最大值，也就是dp[i] % 7 = i
//    for (int& a : data)
//    {//遍历每一个数
//        vector<int> tmp = dp;
//        for (int& i : tmp)
//        {//新建一个tmp，他记录的是上一层的dp里的值，i 表示上一层dp里的每个值，不是下标
//            //如果用下标来表示的话，就要考虑用二维数组来存储了，因为要用到上一层的值，参考下面的dp1
//            //每遇到一个数a，考虑选择它或者不选它对 每一个累加和的影响
//            //如果选择了它，那么总和为 i 的情况下，会对模7余 (i + a) % 7的最大和有影响，也就是等号左边的dp[(i + a) % 7]，它要么保持原样dp[(i + a) % 7]，要么变成 i + a，取最大
//            //如果不选它，那么所有累加和都不会有影响，所以全都保持原样，即什么都不用做
//            //·其实这里是站在 j 的角度上去考虑对其他的影响，即考虑当前状态能变成其他的哪个状态，再去计算那个状态的值。
//            //  而一般的dp是站在当前状态的角度上去考虑 哪一个状态能变成当前状态，再去更新当前状态的值
//            //  这道题也可以这么做，对于每一个 j ，先求出 a % 7的值，然后用 j 减去 a % 7，就知道了哪个状态能变成 j 这个状态，当前这样要考虑 j 和 a%7 的大小关系
//            //  并且初始化是一个很麻烦的事，不能简单初始化为0，否则会计算出错
//            dp[(i + a) % 7] = max(dp[(i + a) % 7], i + a);
//        }
//
//    }
//    //vector<vector<int>> dp1(data.size()+1,vector<int>(7, 0)); //用二维数组表示
//    //for (int i=1;i<data.size()+1;i++)
//    //{//遍历每一个数
//    //    for (int j=0;j<7;j++)
//    //    {//(dp1[i-1][j] + data[i-1]) % 7表示上一层模 7 余 j 的最大和加上 a 以后的模 7 的余数，记为 x ，则dp1[i][x]表示这一层模 7 余 x 的最大和
//    //        //它等于 不取 a 的情况下的最大值 dp1[i-1][x]，取 a 的情况下的最大值 dp[i-1][j]+ a ，以及本层已经更新过的 dp[i][x]
//    //        //·为什么还要考虑本层已经更新过的dp[i][x]？
//    //        //  因为上一层不同的值（值指的是最大和而不是余数）加上 a 有可能得到相同的余数 x，比如上一层有 7 和 0 两个最大和，a=3,（7+3）%7=3，（0+3）%3=3，
//    //        //  正确的最大和是 7+3=10，但如果先更新了10，然后没有考虑dp[i][x]的话就会重新更新为3，答案就错了
//    //        int x = (dp1[i - 1][j] + data[i - 1]) % 7;
//    //        dp1[i][x] = max(dp1[i][x], max(dp1[i-1][x],dp1[i-1][j] + data[i-1]));
//    //    }
//
//    //}
//    cout << dp[0];
//    //cout << dp1.back()[0];
//    return 0;
//}

////////////////////////////////////////////含有重复元素的整数数组 nums ，随机输出给定的目标数字 target 的索引（蓄水池抽样法）///////////////////////////////////////

//https://leetcode.cn/problems/random-pick-index/solution/by-ac_oier-zhml/
//https://mp.weixin.qq.com/s?__biz=MzU4NDE3MTEyMA==&mid=2247490892&idx=1&sn=c1fe373edc88142cbabd383ef3c0669b
//https://blog.csdn.net/weixin_40418080/article/details/124417080
//整理题意：总的样本数量未知，从所有样本中抽取若干个，要求每个样本被抽到的概率相等。
//具体做法为：从前往后处理每个样本，每个样本成为答案的概率为 1/i，其中 i 为样本编号（编号从 1 开始），
//最终可以确保每个样本成为答案的概率均为 1/n（其中 n 为样本总数）。
//容易证明该做法的正确性，假设最终成为答案的样本编号为 k ，那么 k 成为答案的充要条件为「在遍历到 k 时被选中」
//并且「遍历大于 k 的所有元素时，均没有被选择（没有覆盖）」。参考链接 2
//int main()
//{
//    vector<int> arr = { 1, 2, 3, 3, 3 };
//    int target = 3;
//    int cnt = 0;
//    int ans = -1;
//    for (int i = 0;i < arr.size();i++)
//    {
//        if (arr[i] == target)//必须保证元素等于target，否则不能加入池塘
//        {//池塘抽样
//            cnt++;//cnt表示池塘中元素的个数，代表上面的 i
//            if (rand() % cnt == 0)
//            {//若随机到结果为 0（发生概率为  1/i），其实也称其他形式也可以，比如 (rand() % cnt)==cnt-1，本质上是一样的
//                ans = i;
//            }
//        }
//    }
//}

////////////////////////////////////////////统计包含每个点的矩形数目///////////////////////////////////////

//https://leetcode-cn.com/problems/count-number-of-rectangles-containing-each-point/solution/dui-kuan-du-er-fen-by-baoya_uncle-eakf/
//rectangles[i] = [li, hi] 表示第 i 个矩形长为 li 高为 hi 。第 i 个矩形的 左下角 在 (0, 0) 处，右上角 在 (li, hi) 。
//int main()
//{
//    vector<vector<int>> rectangles = { {1, 1},{2, 2},{3, 3} }, points = { {1, 3},{1, 1} };
//    int n = points.size();
//    vector<int> res(n, 0);
//    unordered_map<int, vector<int>> umap;
//    int max_h = 0;
//    for (auto rectangle : rectangles)
//    {//矩形高度范围只有[0:100]，所以对高度统计
//        umap[rectangle[1]].push_back(rectangle[0]);
//        max_h = max(max_h, rectangle[1]);//纪录最大高度，后面减少计算量
//    }
//    for (auto it = umap.begin();it != umap.end();it++)
//    {//高度相同时，宽度从小到大排序，方便二分查找
//        sort(it->second.begin(), it->second.end());
//    }
//    int ans;//二分查找的最终位置，二分的目的是找到高度大于等于点纵坐标，宽度大于等于点横坐标的最小位置，所以下面ans初始化为最大的m，也就是默认所有矩形的宽度都小于点横坐标
//    for (int i = 0;i < n;i++)
//    {//对于每一个点
//        for (int j = points[i][1];j <= max_h;j++)
//        {//从高度大于等于这个点纵坐标的高度开始，一直到最大高度位置，遍历
//            int m = umap[j].size();//相同高度的矩形数量
//            ans = m;//一开始认为这一高度下所有矩形的宽度都小于点横坐标，则 m-ans=0，这个点不在任何矩形内
//            if (umap.count(j))
//            {//只有存在高度为 j 的矩形时才去二分查找
//                int left = 0, right = m - 1;
//                while (left <= right)
//                {
//                    int mid = left + (right - left) / 2;
//                    if (points[i][0] <= umap[j][mid])
//                    {//点横坐标小于矩形宽度时，记录此时的矩形位置，此位置往后的矩形宽度都符合条件，找到最小的位置
//                        ans = mid;
//                        right = mid - 1;
//                    }
//                    else
//                    {
//                        left = mid + 1;
//                    }
//                }
//
//            }
//            res[i] += (m - ans);//从 ans 到 m 这些矩形都满足条件
//        }
//    }
//}

////////////////////////////////////////////纪录最长递增子序列的长度（变体）///////////////////////////////////////

//https://blog.csdn.net/xyjy11/article/details/118032689
//尽可能多的物品满足以下条件:对于任意两个物品 i 和 j , 满足x[i]<x[j] && y[i]<y[j]或者 x[i]>x[j] && y[i]>y[j].问最多能挑出多少物品.
//思路：最长上升子序列的变种，需要保证xy的同升同降，即先将所有物品按x升序排列，随后在无序的y中取一个最长上升子序列即可
//需要注意的是，在排序过程中，对于相同大小的x，需要将大的y排在前边，因为排在后边，因为x不递增，会导致错误的结果。
//例如(1, 2) (1, 3) (1, 4)，这一组中最长子序列长度正确应为1(因为x相同），但将小y排在前边，y序列会算出3的错误结果。
//int find(vector<int>& arr, int n, int val)
//{
//    int left = 0, right = n;//n=maxlen，maxlen是下标，是可以取到的
//    int ans = 0;
//    while (left <= right)
//    {
//        int mid = left + (right - left) / 2;
//        if (arr[mid] >= val)
//        {//要找的是大于等于val的最小下标
//            ans = mid;
//            right = mid - 1;
//        }
//        else
//        {
//            left = mid + 1;
//        }
//    }
//    return ans;
//}
//void binary_search(vector<vector<int>>& v)
//{
//    vector<int> s(v.size());//用来保存已经找到的递增子序列，保证是严格递增序列
//    int maxlen = 0;
//    s[maxlen] = v[0][1];//s[maxlen]表示 maxlen+1 长度的子序列最后一位的值，也就是已找到的严格递增序列的最大值
//    for (int i = 1;i < v.size();i++)
//    {
//        if (v[i][1] > s[maxlen])
//        {//如果当前的y值严格大于已找到的最大值
//            maxlen++;//接到后面去
//            s[maxlen] = v[i][1];
//        }
//        else 
//        { // 否则的话，查找前边部分第一个大于等于自身的位置，并且更新它，因为此时以v[i][1]为结尾的子序列比以原s[t]结尾的子序列更有“潜力”，因为更小所以有更多的可能得到成更长的子序列
//            //注意这里没有更新maxlen，因为这样的更新会把后面的值放到前面，不符合子序列的定义，只是代表找到了一个更有“潜力”的“子序列”，它不会改变当前递增序列的最大值
//            //所以后续遍历中还是以原本的最大值s[maxlen]去进行比较的。
//            int t = find(s, maxlen, v[i][1]);//在当前递增序列中，找到大于等于v[i][1]的第一个值
//            s[t] = v[i][1];//替换他
//        }
//    }
//    cout << maxlen + 1 << endl;//输出最大递增子序列长度
//}
//int main()
//{
//    int n=5;//n件物品
//    vector<vector<int>> v = { {1,10},{5,32},{4,19},{2,21},{2,17} };//每件物品有x，y两种属性
//    /*for (int i = 0;i < n;i++)
//    {
//        cin >> v[i][0];
//    }
//    for (int i = 0;i < n;i++)
//    {
//        cin >> v[i][1];
//    }*/
//    sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b)
//        {//按照x升序，x相同时y降序，保证严格递增（即x相同时只算一个）
//            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
//        });
//    binary_search(v);
//    return 0;
//}

////////////////////////////////////////////纪录最长严格递增子序列（不是长度）///////////////////////////////////////

//https://www.cnblogs.com/0patrick/p/14638622.html
////判断两个数组那个字典序排列在前
//bool dictOrder(vector<int> cur, vector<int> competitor) {
//    for (int i = 0; i < competitor.size(); i++) 
//    {//cur 的长度比competitor的长度多 1 ，因为cur是拼接后的
//        if (cur[i] <= competitor[i]) 
//        {
//            continue;
//        }
//        else {
//            return false;//返回false表示新的数组字典序比原来的要小，那么需要替换原有数组
//        }
//    }
//    return true;
//}
//
////动态规划，记录i每向前移一位时，搜索以input[i]结尾的最长递增子序列，并将这个子序列存储在“store”数组中。
//vector<int> fun(vector<int>& input) {
//    vector<vector<int>> store(input.size());
//    store[0] = { input[0] };
//    for (int i = 1; i < input.size(); i++) {
//        int longest = 0;//记录拼接后的长度（longest = store[i].size()）或者拼接前的长度（longest = store[j].size()）
//        for (int j = 0; j < i; j++) {
//            if (store[j].back()< input[i]) //严格递增
//            {//如果input[i]可以拼接到store[j]的后面，
//                if (store[j].size() + 1 > longest) 
//                {//如果拼接后的长度大于目前的最大长度，则更新
//                    store[i] = store[j];
//                    store[i].emplace_back(input[i]);//拼接
//                    //longest = store[j].size();//如果longest记录的是拼接前的长度，那么就不需要下面的else if语句了，因为store[j].size() + 1 == longest说明拼接此时的 j2 之后的长度等于拼接之前的 j1 的长度
//                                                //那么拼接 j1 之后的长度肯定大，所以不需要更新
//                                                //store[j].size() + 1 < longest说明拼接此时的 j2 之后的长度小于拼接之前的 j1 的长度，那么肯定不需要更新了
//                                                //还有一个问题是store[j].size() + 1 > longest时，如果 store[j].size()==longest 时，为什么不需要比较字典序,比如1,4,3,5，当前i=5，j1={1,4}，longest=2
                                                  //j2={1,3}，此时的store[j2].size()=longest=2，直接更新
//                                                //因为当store[j2].size()=longest=store[j1].size()时，因为j1<j2<i，那么store[j2].back()一定小于store[j1].back()，否则的话之前遍历 i=j2 的时候
//                                                //j2就可以拼接在store[j1]的后面了，那么store[j2].size()长度一定大于store[j1].size()，不可能出现相等的情况，所以store[j2].back()一定小于store[j1].back()
//                                                //这样的话我们就直接更新store[i] = store[j2]，因为store[j2]字典序更小
//                    longest = store[i].size();//最好还是比较拼接后的长度
//                }
//                else if (store[j].size() + 1 == longest) 
//                {
//                    if (dictOrder(store[i], store[j]) == false) //此时这两个子序列结尾的数都是input[i]，需要比较前面的数
//                    {//这里比较的是原有的拼接后的和现在的拼接前的，所以长度不一样，store[i]的长度比store[j]的长度多 1 ，所以dictOrder函数里只需要比较store[j]这么长的就行了
//                        store[i] = store[j];
//                        store[i].emplace_back(input[i]);
//                        longest = store[i].size();
//                    }
//                }
//            }
//        }
//        if (store[i].size() == 0) {//如果当前的数input[i]不能拼接在任何数组后面（也就是它比前面任何数都要小）
//            store[i].emplace_back(input[i]);//那么就把它当成新的子序列的起始点，这个子序列可能更具有“潜力”
//        }
//    }
//
//    //找出所有以input[i]结尾的递增子序列中最长的
//    vector<int> ans;
//    for (auto& vec : store) {
//        if (ans.size() < vec.size()) {
//            ans = vec;
//        }
//        else if (ans.size() == vec.size() && vec.size() && ans.size()) {
//            if (dictOrder(ans, vec) == false) {//返回false表示现在的ans字典序比新的要大，所以要更新
//                ans = vec;
//            }
//        }
//    }
//    return ans;
//}
//
//int main() {
//    vector<int> input = { 1,4,7,3,6,4,8,9,7};
//    //vector<int> input = { 1,2,9,8,7,6,5 };
//    //输入：1,2,8,6,4，输出:1 2 4，说明：其最长递增子序列有3个，（1，2，8）、（1，2，6）、（1，2，4）其中第三个字典序最小，故答案为（1，2，4）
//    int n = input.size();
//    vector<int> ans = fun(input);
//    for (int num : ans) {
//        cout << num << ' ';
//    }
//
//    return 0;
//}

////////////////////////////////////////////n个节点最大深度不超过m的二叉树的方案数///////////////////////////////////////

//https://www.nowcoder.com/test/question/done?tid=55578572&qid=1664955#summary
//有多少种不同的二叉树满足节点个数为 n 且树的高度不超过 m 的方案
//int main()
//{
//    int n=3, m=3;
//    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));//动态规划，dp[i][j]表示节点个数为 i 的二叉树高度不超过 j 的方案数
//    dp[0] = vector<long long>(m+1, 1);//节点为0，高度不超过 j 的方案数永远为 1 （空树）
//    for (int i = 1;i <= n;i++)
//    {
//        for (int j = 1;j <= m;j++)
//        {
//            for (int k = 0;k < i;k++)
//            {// 左子树节点数为k，右子树节点数为i-k-1，且左右子树都要求小于等于j-1
//                dp[i][j] = (dp[i][j] + dp[k][j - 1] * dp[i - k - 1][j - 1] % MOD) % MOD;
//            }
//        }
//    }
//    cout << dp[n][m] << endl;
//    return 0;
//}

////////////////////////////////////////////飞行器从地图中的起点到终点的最短路径长度，可以飞行///////////////////////////////////////

//https://www.nowcoder.com/question/next?pid=30440638&qid=1664953&tid=55891831
//迷宫有 n 行 m 列，如果当前小强操控的人物位于点(x,y) ，那么关于点(x,y)中心对称的格子(x',y')  满足x+x'=n+1 且 y+y'=m+1 。
//需要注意的是，对称飞行器最多使用 5 次。
//输入：4 4
//      #S..
//      E#..
//      #...
//      ....
//输出：4，一种可行的路径是用对称飞行器到达(4,3) 再向上走一步，再向右走一步，然后使用一次对称飞行器到达终点。
//int n, m, sx, sy, ex, ey;//sx,sy,ex,ey表示起始和终点的坐标
//char a[505][505];//记录每个坐标
//int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
//struct node {
//    int x, y, c, s; //c代表剩余飞行次数,s代表step
//};
//int bfs()
//{
//    queue<node> q;
//    q.push({ sx, sy, 5, 0 });
//    a[sx][sy] = '#';//访问过的点变成 '#'，代表已访问
//    while (!q.empty())
//    {
//        auto [x, y, c, s] = q.front();//c++17才能这样用，注意是方括号，还可以在前面加一个引用符号&
//        q.pop();
//        if (x == ex && y == ey)
//            return s;//找到终点就直接返回step
//        for (int i = 0; i < 4; i++) 
//        {//标准BFS遍历，用来找最短路径
//            int nx = x + dx[i], ny = y + dy[i];
//            if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == '.')
//                q.push({ nx, ny, c, s + 1 }), a[nx][ny] = '#';//这里没有飞行，所以 c 还是原值
//        }
//        int nx = n - 1 - x, ny = m - 1 - y;
//        if (c > 0 && a[nx][ny] == '.')//c>0表示还能飞，且目的坐标是 .
//            q.push({ nx, ny, c - 1, s + 1 }), a[nx][ny] = '#';
//    }
//    return -1;//-1表示不可达
//}
//int main()
//{
//    cin >> n >> m;
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < m; j++) {
//            cin >> a[i][j];
//            if (a[i][j] == 'S')
//                sx = i, sy = j;//起始点
//            if (a[i][j] == 'E')
//                ex = i, ey = j, a[i][j] = '.';//终点，这里把终点变成 . 是为了后面遍历的时候方便，不需要另外判断
//        }
//    cout << bfs() << endl;
//    return 0;
//}

///////////////////////////////////////n个人任选 2 个人，使得他们较小的属性之和最大////////////////////////////////////////////

//https://www.nowcoder.com/questionTerminal/2a9089ea7e5b474fa8f688eae76bc050?answerType=1&f=discussion
//n个(A,B)，找出两个人，使得 X=(Ai+Aj)/2, Y=(Bi+Bj)/2，求min(X,Y)的最大值
//当 Ai + Aj < Bi + Bj时，X < Y，结果就是X值；当 Ai + Aj > Bi + Bj时，X > Y，结果就是Y值；
//为了让 X 与 Y 的大小关系只与 j 的值有关，我们直接按照abs(A - B)从小到大的顺序对n个人排序：
//这样，在先选定 i 时，由于后面的 j 的abs(A - B)一定大于（或等于） i 的abs(A - B)；
//所以，当Ai < Bi时，若Aj < Bj，则 X < Y，若Aj > Bj，则 X > Y；(因为Aj - Bj > Bi - Ai，所以 Ai + Aj > Bi + Bj）
//当Ai > Bi时，若Aj < Bj，则 X < Y，若Aj > Bj，则 X > Y；(因为Bj - Aj > Ai - Bi，所以 Ai + Aj < Bi + Bj）
//即，最终到底是 X 更小还是 Y 更小，只与 j 的 A 值更小还是 B 值更小有关。
//结论就是：
//·若 j 的 A 值更小，最终结果就是 X ，那么在选定 j 时只需要找前面 A 值最大的 i， 即可实现：ans = X = (Ai + Aj) / 2 最大；
//·同样的，若 j 的 B 值更小，最终结果就是Y，那么在选定 j 时只需要找前面 B 值最大的 i，即可实现：ans = Y = (Bi + Bj) / 2 最大。
//·遍历 j，刷新res，并维护最大的 Ai 和最大的 Bi，为后面的 j 做条件
//输入：   3
//         2 2
//         3 1
//         1 3
//输出：2.0（一位小数），选择第一个和第二个员工或第一个和第三个时，较差方面的能力都是 1.5，选择第二个和第三个时较差方面能力是 2，所以输出 2.0。
//int main()
//{
//    int n;
//    cin >> n;
//    vector<vector<int>> v(n, vector<int>(2));
//    int res = 0;
//    for (int i = 0;i < n;i++)
//    {
//        cin >> v[i][0] >> v[i][1];
//    }
//    sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b)
//        {//按差的绝对值从小到大排序
//            return abs(a[0] - a[1]) < abs(b[0] - b[1]);
//        });
//    int max_a = v[0][0], max_b = v[0][1];//记录之前遍历到的最大的 A 和 B
//    for (int j = 1;j < n;j++)
//    {
//        if (v[j][0] < v[j][1])
//        {//X更小，更新res
//            res = max(res, max_a + v[j][0]);
//        }
//        else
//        {//Y更小，更新res
//            res = max(res, max_b + v[j][1]);
//        }
//        max_a = max(max_a, v[j][0]);//更新 A 和 B ，这两条语句不能放到前面去，不然提前刷新了 A 和 B ，可能造成选出的 i 和 j 相同，即只选出了一个人
//        max_b = max(max_b, v[j][1]);
//    }
//    printf("%.1f", (double)res / 2.0);
//    return 0;
//}

///////////////////////////////////////找出 含最多 K 个可整除元素的不同子数组的个数////////////////////////////////////////////

//https://leetcode-cn.com/problems/k-divisible-elements-subarrays/solution/by-nehzil-eq1s/
//对于 [2, 3, 3, 2, 2]
//位于下标 0、3 和 4 的元素都可以被 p = 2 整除。
//共计 11 个不同子数组都满足最多含 k = 2 个可以被 2 整除的元素：
//[2]、[2, 3]、[2, 3, 3]、[2, 3, 3, 2]、[3]、[3, 3]、[3, 3, 2]、[3, 3, 2, 2]、[3, 2]、[3, 2, 2] 和[2, 2] 。
//注意，尽管子数组[2] 和[3] 在 nums 中出现不止一次，但统计时只计数一次。
//子数组[2, 3, 3, 2, 2] 不满足条件，因为其中有 3 个元素可以被 2 整除。
//int main()
//{
//    vector<int> nums = { 2, 3, 3, 2, 2 };
//    int k = 2, p = 2;//最多含有 k 个能被 p 整除的元素的子数组的个数
//    unordered_map<string, int> umap;//去重，unordered_map和unordered_set的 key 只能是int，char，string这些内置数据类型，不能是容器或者自定义类型，所以要把子数组转换成 string 保存
//    for (int i = 0; i < nums.size(); i++) {
//        int count = 0;//模拟不同字串，i作为子串的起始位置
//        string tmp = "";//记录
//        for (int j = i; j < nums.size(); j++) 
//        {//以 nums[i] 开头的，最多包含 k 个能被 p 整除的子数组
//            if (nums[j] % p == 0) 
//                count += 1;//能被 p 整除
//            if (count > k) 
//                break;//比 k 多了，说明后面的子数组都不符合条件了，跳出循环，开始以 nums[i+1] 为开头来找子数组
//            tmp += nums[j] + '0';//子数组转化成字串保存
//            umap[tmp] = 1;//只要出现过一次就可以了
//        }
//    }
//    cout << umap.size() << endl;//不同子数组的个数
//    return 0;
//}

////////////////////////////////////////////前缀树的模板表示法，以及利用前缀树找出 含最多 K 个可整除元素的不同子数组的个数///////////////////////////////////////

//namespace OY {
//    struct TrieLowerMapping {
//        static constexpr int range() { return 26; }
//        int operator()(char __c) const { return __c - 'a'; }
//    };
//    struct TrieDefaultInfo {
//        bool m_isEnd = false;
//    };
//    template <typename _Mapping = TrieLowerMapping, typename _Info = TrieDefaultInfo, uint32_t _PoolSize = 1000000>
//    struct Trie {
//        struct TrieNode;
//        static inline _Mapping s_map = _Mapping();
//        static inline TrieNode s_parent[_PoolSize];
//        static inline TrieNode s_child[_PoolSize][_Mapping::range()];
//        static inline _Info s_info[_PoolSize];
//        static inline uint32_t s_cursor = 1;
//        struct TrieNode {
//            uint32_t index;
//            TrieNode() = default;
//            TrieNode(uint32_t index) : index(index) {}
//            static constexpr TrieNode newNode(TrieNode parent) {
//                s_parent[s_cursor] = parent;
//                return s_cursor++;
//            }
//            static constexpr TrieNode newNode(TrieNode parent, uint32_t i) {
//                s_parent[s_cursor] = parent;
//                s_child[parent.index][i] = s_cursor;
//                return s_cursor++;
//            }
//            constexpr TrieNode& parent() { return s_parent[index]; }
//            constexpr TrieNode& child(uint32_t i) { return s_child[index][i]; }
//            constexpr TrieNode& child(uint32_t i) const { return s_child[index][i]; }
//            constexpr TrieNode& childGet(uint32_t i) {
//                if (!s_child[index][i]) s_child[index][i] = newNode(*this, i);
//                return s_child[index][i];
//            }
//            template <typename _Iterator>
//            constexpr TrieNode insert(_Iterator first, _Iterator last) {
//                if (first == last)
//                    return *this;
//                else
//                    return childGet(s_map(*first)).insert(first + 1, last);
//            }
//            template <typename _Sequence>
//            constexpr TrieNode insert(_Sequence& sequence) { return insert(sequence.begin(), sequence.end()); }
//            template <typename _Iterator>
//            constexpr TrieNode find(_Iterator first, _Iterator last) const {
//                if (first == last)
//                    return *this;
//                else if (child(s_map(*first)))
//                    return child(s_map(*first)).find(first + 1, last);
//                else
//                    return 0;
//            }
//            template <typename _Sequence>
//            constexpr TrieNode find(_Sequence& sequence) const { return find(sequence.begin(), sequence.end()); }
//            constexpr _Info* operator->() const { return s_info + index; }
//            constexpr _Info& operator*() { return s_info[index]; }
//            constexpr explicit operator bool() const { return index; }
//            constexpr operator uint32_t() const { return index; }
//        };
//        TrieNode m_root;
//        Trie() : m_root(s_cursor++) {}
//        template <typename _Iterator>
//        TrieNode insert(_Iterator __first, _Iterator __last) { return m_root.insert(__first, __last); }
//        template <typename _Sequence>
//        TrieNode insert(const _Sequence& __sequence) { return m_root.insert(__sequence.begin(), __sequence.end()); }
//        template <typename _Iterator>
//        TrieNode find(_Iterator __first, _Iterator __last) const { return m_root.find(__first, __last); }
//        template <typename _Sequence>
//        TrieNode find(const _Sequence& __sequence) const { return m_root.find(__sequence.begin(), __sequence.end()); }
//    };
//    template <typename _Mapping = TrieLowerMapping, typename _Info = TrieDefaultInfo, uint32_t _PoolSize = 1000000>
//    Trie()->Trie<_Mapping, _Info, _PoolSize>;
//}
//class Solution {
//public:
//    int countDistinct(vector<int>& nums, int k, int p) {
//        //这个结构体用来指明字典树的分叉数量，以及序列元素到孩子下标的映射关系
//        struct mapping {
//            static constexpr uint32_t range() { return 201; }
//            uint32_t operator()(int x) const { return x; }
//        };
//        OY::Trie<mapping> T;
//        int ans = 0;
//        vector<bool> isgood(nums.size(), false);
//        for (int i = 0; i < nums.size(); i++) 
//            isgood[i] = nums[i] % p == 0;
//        //固定左端移动右端
//        for (int i = 0; i < nums.size(); i++) {
//            int count = 0;
//            auto it = T.m_root;
//            for (int j = i; j < nums.size(); j++) {
//                if (isgood[j]) 
//                    count++;
//                if (count > k) 
//                    break;
//                it = it.childGet(nums[j]);
//                if (!it->m_isEnd) {
//                    ans++;
//                    it->m_isEnd = true;
//                }
//            }
//        }
//        return ans;
//    }
//};
//int main()
//{
//    Solution so;
//    vector<int> nums = { 2, 3, 3, 2, 2 };
//    int k = 2, p = 2;
//    cout << so.countDistinct(nums, k, p) << endl;
//    return 0;
//}

////////////////////////////////////////////计算一个字符串的所有子串的引力总和///////////////////////////////////////

//https://leetcode-cn.com/problems/total-appeal-of-a-string/solution/by-endlesscheng-g405/
//字符串的 引力 定义为：字符串中 不同 字符的数量。例如，"abbca" 的引力为 3 ，因为其中有 3 个不同字符 'a'、'b' 和 'c' 。给你一个字符串 s ，返回 其所有 子字符串 的总引力 。
//·将所有子串按照其末尾字符的下标分组。
//·考虑两组相邻的子串：以 s[i - 1] 结尾的子串、以 s[i]结尾的子串。
//·以 s[i]结尾的子串，可以看成是以 s[i - 1] 结尾的子串，在末尾添加上 s[i] 组成。
//  上面这一串提示是思考子串统计类问题的通用技巧之一。
//·从左往右遍历 s，考虑将 s[i]添加到以 s[i - 1] 结尾的子串的末尾。添加后，这些子串的引力值会增加多少？
//  分类讨论：
//·如果 s[i] 之前没有遇到过，那么这些子串的引力值都会增加 1，这些子串的引力值之和会增加 i，再加上 1，即 s[i]单独组成的子串的引力值，即以 s[i] 结尾的字串引力总和会相比于以 s[i-1] 结尾的字串引力总和多 i+1；
//·如果 s[i] 之前遇到过，设其上次出现的下标为 j，那么向子串 s[0..i−1], s[1..i−1], s[2..i−1], ⋯, s[j..i−1] 的末尾添加 s[i] 后，这些子串的引力值是不会变化的，因为 s[i] 已经在 s[j] 处出现过了；
//  而子串 s[j + 1..i−1], s[j + 2..i−1], ⋯, s[i−1..i−1] 由于不包含字符 s[i]，这些子串的引力值都会增加 1，因此有 i-1-(j+1)+1 = i−j−1 个子串的引力值会增加 1，
//  这些子串的引力值之和会增加 i−j−1，再加上 1，即 s[i] 单独组成的子串的引力值，即以 s[i] 结尾的字串引力总和会相比于以 s[i-1] 结尾的字串引力总和多 i-j；。
//总结：以 s[i] 结尾的字串引力总和会相比于以 s[i-1] 结尾的字串引力总和多 i-j，对于第一次出现的 s[i]，其 j=-1，则增加的部分为 i+1。
//int main()
//{
//    string s = "abbca";
//    int n = s.length();
//    int str_sum = 0;//记录以不同字符结尾的字串引力总和
//    long long ans = 0;//记录所有字串的引力总和
//    int pos[26];//记录不同字符上一次出现的位置
//    memset(pos, -1, sizeof(pos));//初始化为-1，这样对于第一次出现的字符而言，其字串的引力总和会增加 i-(-1)=i+1，符合上面的分析
//    for (int i = 0;i < n;i++)
//    {
//        char ch = s[i];
//        str_sum += i - pos[ch - 'a'];//这里用的是累加，因为 i-pos[ch - 'a'] 表示的是以 s[i] 结尾的字串引力总和相比于以 s[i-1] 结尾的字串引力总和多的那部分，
//                                     //而原来的 str_num 记录的才是以 s[i-1] 结尾的字串引力总和，所以新的 str_num 记录的才是以 s[i] 结尾的字串引力总和
//                                     //pos[ch - 'a'] 就是分析中的 j，相当于动态规划里的 dp[i]和 dp[i-1]
//        ans += str_sum;//所有子串的引力总和，每遍历一个 i ，都会有一个新的 str_num，这些都是 s 的字串，所以都要加到 ans 里
//        pos[ch - 'a'] = i;//记录新的位置，如果有下一个 s[i]，那么此时的 i 就相当于那个时候的 j
//    }
//    cout << ans << endl;
//    return 0;
//}

////////////////////////////////////////////等级相同的节点之间的最小距离///////////////////////////////////////

//https://www.nowcoder.com/questionTerminal/4b0fd3cd06dc4a899abf74996796f5c0?answerType=1&f=discussion
//输入：3
//      1 2 1
//      1 2
//      2 3
//输出：2，解释：1号节点和3号节点等级相同，距离为 2
//int res = INT_MAX;
//void bfs(int start,int n, vector<vector<int>>& arr, unordered_map<int, int>& mp) {
//    vector<bool> st(n + 1);//记忆化搜索
//    vector<int> dist(n + 1);
//    if (res == 1) //res已经是最小了，不用继续找了
//        return;
//    queue<int> q;
//    q.push(start);
//    dist[start] = 0;
//    st[start] = true;
//    while (!q.empty()) 
//    {
//        auto t = q.front();
//        q.pop();
//        if (t != start && mp[t] == mp[start]) 
//        {//已经找到了离起点最近的等级相同的终点，距离为dist[t]，返回
//            res = min(res, dist[t]);
//            break;
//        }
//        for (auto& x : arr[t]) 
//        {//遍历t的邻居节点
//            if (!st[x]) 
//            {//未访问过
//                st[x] = true;
//                dist[x] = dist[t] + 1;
//                q.push(x);
//            }
//        }
//    }
//}
//int main() {
//    int n;
//    cin >> n;//n个节点，n-1条边
//    vector<vector<int>> arr(n + 1);//记录相连的节点
//    unordered_map<int, int> mp;//记录每个节点的等级
//    for (int i = 1;i <= n;i++) {
//        int c;
//        cin >> c;
//        mp[i] = c;
//    }
//    for (int i = 0;i < n - 1;i++) {//n个节点，n-1条边
//        int a, b;
//        cin >> a >> b;
//        arr[a].push_back(b);
//        arr[b].push_back(a);
//    }
//    for (int i = 1;i <= n;i++) {
//        bfs(i,n,arr,mp);//枚举每一个起点 i ，找出离它最近的第一个相同等级的终点
//    }
//    if (res == INT_MAX) 
//        res = -1;
//    cout << res << endl;
//    return 0;
//}

////////////////////////////////////////////有约定的情况下分糖果，最多满足几个人，01背包///////////////////////////////////////

//https://www.nowcoder.com/questionTerminal/e7a006abf5ec412a939f0d33725f06ed?answerType=1&f=discussion
//输入：3 10
//      5 1 5
//      1
//      1 3
//输出：2，解释：1 和 3有约定，且两个人最多吃10个糖果，所以最多满足 2 个人
//int main()
//{
//    int n, m, k;//n个人，m个糖果，背包容量为 m
//    cin >> n >> m;
//    vector<int> a(n), b(n, 1), dp(m + 1, 0);//a代表重量，b代表价值，01背包，dp[i]表示 i 个糖果最多能够满足 dp[i] 个人
//    for (int i = 0;i < n;i++)
//    {
//        cin >> a[i];
//    }
//    cin >> k;//k个约定，每一个约定为编号对(i, j)，表示第i个和第j个人是好朋友，他俩要么一起都吃到糖果，要么一起都不吃，每个人最多只出现在一个编号对中。
//    for (int i = 0;i < k;i++)
//    {
//        int x, y;//x，y有约定
//        cin >> x >> y;
//        a[x - 1] += a[y - 1];//若第x和y个人有约定, 则将x和y绑定成一个物品: 重量为a[x] + a[y], 价值为2; 否则 x 是重量为a[x], 价值为1的物品
//        b[x - 1] = 2;//价值为2表示，这两个人都能装到背包里
//        b[y - 1] = 0;//另一个人已经被打包了，则价值为0
//    }
//    for (int i = 0;i < n;i++)
//    {//物品
//        if (b[i] == 0)
//        {
//            continue;
//        }
//        for (int j = m;j >= a[i];j--)
//        {//01背包，倒序
//            dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
//        }
//
//    }
//    cout << dp[m] << endl;
//    return 0;
//}

////////////////////////////////////////////从左上角走到右下角的方案总和，每一步都有能量限制，反向DP///////////////////////////////////////

//https://www.nowcoder.com/questionTerminal/85e7e341dc764ae1866b9525c1937225?answerType=1&f=discussion
//输入：3 3
//      2 1 1
//      1 1 1
//      1 1 1
//输出：10，解释如下：
//  (1, 1)−>(1, 2)−>(1, 3)−>(2, 3)−>(3, 3)
//  (1, 1)->(1, 3)->(2, 3)->(3, 3)
//  (1, 1)->(1, 2)->(2, 2)->(2, 3)->(3, 3)
//  (1, 1)->(1, 2)->(2, 2)->(3, 2)->(3, 3)
//  (1, 1)->(2, 2)->(2, 3)->(3, 3))
//  (1, 1)->(2, 2)->(3, 2)->(3, 3))
//  (1, 1)->(2, 1)->(3, 1)->(3, 2)->(3, 3)
//  (1, 1)->(2, 1)->(2, 2)->(3, 2)->(3, 3)
//  (1, 1)->(2, 1)->(2, 2)->(2, 3)->(3, 3)
//  (1, 1)->(3, 1)->(3, 2)->(3, 3)
//int main() 
//{
//    int n, m;
//    cin >> n >> m;
//    vector<vector<int>> nums(n, vector<int>(m, 0));
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cin >> nums[i][j];
//        }
//    }
//    vector<vector<int>> dp(n, vector<int>(m, 0));// dp[i][j]表示从(0,0)到达(i,j)的方案数
//    dp[0][0] = 1;  //从 [0, 0]走到 [0, 0]的方案数为 1 
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0;j < m; j++)
//        {
//            int e = nums[i][j];//e表示从当前的(i,j)出发最多走 e 步，这条路径中的任一点都可以到达（可以选择在中间某一坐标停留，也可以选择不停留）
//            for (int dx = 0;dx <= e; dx++)
//            {//dx表示能向下走 dx 步，最多能走 e 步（一直向下走）
//                for (int dy = 0; dy <= e - dx; dy++)
//                {//dy表示能向右走 dy 步，最多能走 e-dx 步（先往下走再往右走，往下走了 dx 步，往右只能走 e-dx 步）
//                    if (dx == 0 && dy == 0)
//                        continue;//不能原地踏步
//                    int nx = i + dx, ny = dy + j;//nx，ny表示从(i,j)出发走 dx+dy 步后到达的坐标
//                    if (nx < n && ny < m)
//                    {//新坐标必须在方格内
//                        dp[nx][ny] = (dp[nx][ny] + dp[i][j]) % 10000;// 能从(i,j)走到的点（nx，ny），其方案数dp[nx][ny]就 累加 上到达(i,j)的方案
//                    }
//                }
//            }
//        }
//    }
//    cout << dp[n-1][m-1] << endl;
//}

////////////////////////////////////////////存在某个元素出现的次数不小于m次的子数组总数//////////////////////////////////////

//https://www.nowcoder.com/questionTerminal/778ae1581eb54959bce91afe0b51c3ff?answerType=1&f=discussion
//输入：5 2
//      1 2 1 2 3
//输出：5，满足条件的区间为[0,2],[0,3],[0,4],[1,3],[1,4].
//int main() {
//    int n, m;
//    cin >> n >> m;
//    vector<int>a(n);
//    for (int i = 0;i < n;i++)
//        cin >> a[i];
//    long long ans = 0;
//    int i = 0;
//    unordered_map<int, int> num;
//    for (int j = 0; j < n; j++) {   // [i,j]窗口长度为 j-i+1
//        if (++num[a[j]] != m)//注意这里是先累加，然后再去和 m 比较，不满足就直接跳过
//            continue;  // 元素 a[j] 进入滑动窗口，只有当 a[j] 的次数等于 m 时，此时的窗口里才满足 某个元素出现的次数不小于 m 次的条件，开始统计，注意此时窗口内一定只有 一个元素出现的次数等于 m，那就是 a[j]
//        ans += n - j;   //以i为起点，以 j 后面为终点的区间都满足条件，则ans += n-j。也就是[i,j],[i,j+1],[i,j+2],...[i,n-1]这些子数组都满足条件
//        while (a[i] != a[j]) 
//        {  //此时的窗口内 只有 a[j] 出现的次数等于 m，那么从 i+1 开始一直到窗口内第一个 a[j] 的下标（假设为 k），
//           //以这些下标为数组首位，j 和 j后面元素为数组末尾，这些子数组都包含 m 次 a[j] 元素，都满足条件，则ans+=n-j
//           // 也就是[i+1,j],[i+1,j+1],[i+1,j+2],...[i+1,n-1]这些子数组都满足条件,ans += n-j，这是在 while循环中的 i 没递增的情况下
//           //       [i+2,j],[i+2,j+1],[i+2,j+2],...[i+2,n-1]这些子数组都满足条件,ans += n-j
//           //       ...
//           //       [k,j],[k,j+1],[k,j+2],...[k,n-1]这些子数组都满足条件,ans += n-j，这是在 while循环中的 i=k-1 的情况下
//           // 总共需要执行 k-(i+1)+1= k-i 次 ans += n-j，注意以 i 为首位的已经统计过了
//            num[a[i]]--;//剔除左窗口的值
//            i++;
//            ans += n - j;//先缩小左边界再计算贡献
//        }
//        //此时删去头元素（a[k]）就不满足条件了，但以头元素（a[k]）为起点的区间已经加到ans中了（就是上一个while循环里最后一次循环）
//        // 仍然删去头元素，使此时的区间不满足条件，同时使以 i = k+1 为起点的区间没被累加过
//        num[a[i]]--;//这里的 i 就是上面说的 k，只不过没有明确的表示出来
//        i++;
//    }
//    cout << ans << endl;
//    return 0;
//}

////////////////////////////////////////////把序列 A 变成序列 B 最少需要的移动次数，只能移动首尾两个数///////////////////////////////////////

//https://www.nowcoder.com/questionTerminal/b65b8b1376d94d4b8d4718ba2f4c0022?answerType=1&f=discussion
//输入：4
//      4 2 3 1
//      1 2 3 4
//输出：2，解释：先把 1 放到 4 的后面，再把 4 放到 3 的后面
//int main() {
//    int n;
//    cin >> n;
//    vector<int> a(n, 0);//a 和 b里面的值相同，且没有重复值，但是位置不同
//    vector<int> b(n, 0);
//    unordered_map<int, int> mp;
//    for (int i = 0; i < n; i++) 
//        cin >> a[i];// 4 5 3 2 1 6
//    for (int i = 0; i < n; i++)
//    {
//        cin >> b[i];// 6 4 3 2 1 5
//        mp[b[i]] = i;//因为要把 a 变成 b ，所以对 b 做映射，b中的值[6 4 3 2 1 5] 映射为B： [0 1 2 3 4 5]，这里的 mp[b[i]] 就是 b 的映射关系
//    }
//    //把a中的值[4 5 3 2 1 6] 也映射（按照 b 的映射关系）成坐标就是A： [ 1 5 2 3 4 0]，因为在 b 的映射关系中 6->0，4->1，3->2，2->3，1->5，5->5，
//    //如果把 A 变成 B，那么就相当于把 a 变成了 b，并且 B 是一个严格递增的序列，问题就变成了把 A 转换成一个严格递增的数组需要移动几次，也就是只要求出 A 的最长递增子数组就行了
//    int len = 0, cur = 0, curi = -1;//len表示最长递增子数组的长度，cur当前子数组的长度，curi表示上一个遍历到值，相当于 A[i-1]
//    for (int i = 0; i < n; i++) 
//    {//mp[a[i]] 相当于 A[i],curi相当于 A[i-1]
//        if (mp[a[i]] > curi) 
//            cur++;//如果A[i] > A[i-1]，那么递增子数组长度加 1
//        else 
//        {//否则 A[i] 不能放到之前的递增子数组里，更新最长递增子数组长度，并且当前子数组长度刷新为 1
//            len = max(len, cur);
//            cur = 1;
//        }
//        curi = mp[a[i]];//记录 A[i-1]
//    }
//    len = max(len, cur);//最后一个值有可能是最长递增子数组的一部分，所以最后还要在更新一次
//    //若 ai, ai+1, ..., aj是最长上升子数组
//    //则一定有 ai-1 > ai，aj+1 < aj，
//    //那么从a0到ai-1的i个值都需要依次移动 1 次，从aj+1到an-1的 n-j-1 个值都需要依次移动 1 次，那么总共需要 n+i-j-1 = n-(j-i+1) 次，j-i+1 就是最长递增子数组的长度 
//    //因为我们只能每次移动首元素或者尾元素，哪怕 a0 到 ai - 2 都不需要移动，我们为了移动 ai - 1，也只能把它们全都移动到ai - 1后面，使ai - 1变为首元素，从而移动ai - 1到正确位置；
//    //同理，为了移动aj + 1，aj + 2到an的元素无论如何都需要被移动。例如：[1, 2, 4, 3, 5, 6, 8, 7, 9, 10]的最长上升子数组为 [3 5 6 8]，那么我们必须把 [1 2 4] 和 [7 9 10]移到正确位置上
//    //则最少需要 6 次移动：
//    //第一次：把 1 移到 4 的后面，序列变成[2, 4, 1, 3, 5, 6, 8, 7, 9, 10]
//    //第二次：把 2 移到 1 的后面，序列变成[4, 1, 2, 3, 5, 6, 8, 7, 9, 10]
//    //第三次：把 4 移到 3 的后面，序列变成[1, 2, 3, 4, 5, 6, 8, 7, 9, 10]
//    //第四次：把 10 移到 7 的前面，序列变成[1, 2, 3, 4, 5, 6, 8, 10, 7, 9]
//    //第五次：把 9 移到 10 的前面，序列变成[1, 2, 3, 4, 5, 6, 8, 9, 10, 7]
//    //第六次：把 7 移到 8 的前面，序列变成[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]，完成排序
//    cout<< n - len << endl; //所以答案为 n-len
//    return 0;
//}

////////////////////////////////////////////乘积小于 K 的子数组个数///////////////////////////////////////

//https://leetcode-cn.com/problems/subarray-product-less-than-k/solution/jian-dan-yi-dong-xiang-xi-zhu-jie-shuang-jvy3/
//int main()
//{
//    vector<int> nums = { 10,5,2,6 };
//    int k = 100;
//    int res = 0;
//    int n = nums.size();
//    int left = 0, right = 0, tmp = 1;//窗口的左右边界和窗口内所有数的乘积
//    while (right < n)
//    {
//        tmp *= nums[right];//乘积扩大
//        while (tmp >= k && left <= right)
//        {//当窗口内的乘积大于 k 时，就要弹出左边界的值，同时还要保证左边界小于等于右边界
//            tmp /= nums[left];
//            left++;
//        }
//        res += right - left + 1;//此时窗口的乘积小于 k ，满足条件，那么以 nums[right] 结尾满足条件的子数组个数就是 right-left+1，就相当于固定右边界，然后只要左边界在当前窗口内，那么这个子数组都满足条件
//                                //比如此时的 right = 3，left = 1，窗口为 [5,2,6]，乘积为 60 < 100，满足条件，那么以 6 结尾的子数组个数就有 3 个，分别是 [5,2,6]，[2,6]，[6]
//        right++;//移动右边界
//    }
//    cout << res << endl;
//    return 0;
//}

////////////////////////////////////////////输出内存中的每个字节的值以及注意事项///////////////////////////////////////

//http://blog.chinaunix.net/uid-25094731-id-225841.html
//https://bbs.csdn.net/topics/390514117
//https://blog.csdn.net/wyll19980812/article/details/120551413
//int print_all_byte(void* addr, int size)
//{//一定要用 unsigned char，因为后面输出的时候是按照整形输出的，有符号char会被拓展，也就是signed char 最多只能表示 7 bits，而一个字节里面有 8 bits，所以会造成输出错误
//    unsigned char* ptr = (unsigned char* )addr;
//    int print_bytes = 0;
//
//    if (NULL == ptr) {
//        return -1;
//    }
//    printf("%x", ptr);
//    while (print_bytes < size) {
//        printf("%#6x", *ptr);
//        ptr++;
//        print_bytes++;
//    }
//    printf("\n");
//    return print_bytes;
//}
//int main()
//{
//    int d1 = 0x12345678;
//    long d2 = 0x87654321;
//    double d3 = -0.12345678;
//    int arr1[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 1234 };
//
//    if (sizeof(d1) == print_all_byte((void*)&d1, sizeof(d1))) {
//        printf("print int success!\n");
//    }
//
//    if (sizeof(d2) == print_all_byte((void*)&d2, sizeof(d2))) {
//        printf("print long success!\n");
//    }
//
//    if (sizeof(d3) == print_all_byte((void*)&d3, sizeof(d3))) {
//        printf("printf double success!\n");
//    }
//
//    if (sizeof(arr1) == print_all_byte((void*)arr1, sizeof(arr1))) {
//        printf("printf array success!\n");
//    }
//    char c1 = 126;
//    char c2 = 128;
//    char c3 = 130;
//    char c4 = 256;
//    char c5 = 259;
//    char c6 = 387;
//
//    unsigned char c7 = 126;
//    unsigned  char c8 = 128;
//    unsigned char c9 = 130;
//    unsigned char c10 = 256;
//    unsigned char c11 = 259;
//    unsigned char c12 = 387;
//
//    printf("int 126=01111110 assign to char c1,---> %d\n", c1);//126 = 01111110，符号位为 0，c1 是有符号char，整形输出（或转化为int）会对符号位进行拓展，结果为 0x0000007e(126)
//    printf("int 126=01111110 assign to unsigned char c7,---> %d\n", c7);//126 = 01111110，符号位为 0，c7 是无符号char，整形输出（或转化为int）不会对符号位进行拓展，而是直接在前面补0，结果为 0x0000007e(126)
//
//    printf("int 128=10000000 assign to char c2,---> %d\n", c2);//128 = 10000000，符号位为 1，c2 是有符号char，整形输出（或转化为int）会对符号位进行拓展，结果为 0xffffff80(-128)
//    printf("int 128=10000000 assign to unsigned char c8,---> %d\n", c8);//128 = 10000000，符号位为 1，c8 是无符号char，整形输出（或转化为int）不会对符号位进行拓展，而是直接在前面补0，结果为 0x00000080(128)
//
//    printf("int 130=10000010 assign to char c3,---> %d\n", c3);//130 = 10000010，符号位为 1，c3 是有符号char，整形输出（或转化为int）会对符号位进行拓展，结果为 0xffffff82(-126)
//    printf("int 130=10000010 assign to unsigned char c9,---> %d\n", c9);//130 = 10000010，符号位为 1，c9 是无符号char，整形输出（或转化为int）不会对符号位进行拓展，而是直接在前面补0，结果为 0x00000082(130)
//
//    printf("int 256=1 00000000 assign to char c4,---> %d\n", c4);//256 = 1 00000000，大于 8 位，截断，剩下 00000000 ，符号位为 0，有符号char，拓展，结果为 0x00000000（0）
//    printf("int 256=1 00000000 assign to unsigned char c10,---> %d\n", c10);//256 = 1 00000000，大于 8 位，截断，剩下 00000000 ，符号位为 0，无符号char，不拓展，结果为 0x00000000（0）
//
//    printf("int 259=1 00000011 assign to char c5,---> %d\n", c5);//259 = 1 00000011，大于 8 位，截断，剩下 00000011 ，符号位为 0，有符号char，拓展，结果为 0x00000003（3）
//    printf("int 259=1 00000011 assign to unsigned char c11,---> %d\n", c11);//259 = 1 00000011，大于 8 位，截断，剩下 00000011 ，符号位为 0，无符号char，不拓展，结果为 0x00000003（3）
//
//    printf("int 387=1 10000011 assign to char c6,---> %d\n", c6);//387 = 1 10000011，大于 8 位，截断，剩下 10000011 ，符号位为 1，有符号char，拓展，结果为 0xffffff83（-125）
//    printf("int 387=1 10000011 assign to unsigned char c12,---> %d\n", c12);//387 = 1 10000011，大于 8 位，截断，剩下 10000011 ，符号位为 1，无符号char，不拓展，结果为 0x00000083（131）
//    return 0;
//}

////////////////////////////////////////////三分法求出最佳服务器的位置（凸函数求解）///////////////////////////////////////

//https://leetcode-cn.com/problems/best-position-for-a-service-centre/solution/san-fen-tao-san-fen-by-lyhshang/
//三分法使用与求一元凸函数的最值（凸函数的极值等于最值，也就是只有一个最值，https://blog.csdn.net/li15006474642/article/details/104581298）
//本题是二元凸函数，但是对于每个 x 和每个 y 都是一元凸函数
//class Solution {
//public:
//    vector<vector<int>> positions;
//    double eps = 1e-6;//设置精度
//    double minx, miny;//极值点对应的x,y坐标
//    double f(double x, double y)
//    {//计算(x,y)到其他点的距离总和
//        double sum_dist = 0;
//        for (auto& c : positions)
//            sum_dist += sqrt(pow(c[0] - x, 2) + pow(c[1] - y, 2));
//        return sum_dist;
//    }
//    double get_y_MinDist(double l, double r, double mx)
//    {//该函数在[l,r]区间内寻找 在满足x=mx条件下 满足 (r-l)<eps 的y坐标
//        double m1, m2, k1, k2;
//        while ((r - l) > eps)
//        {
//            m1 = l + (r - l) / 3.0;//三分之一点
//            m2 = l + (r - l) * 2.0 / 3.0;//三分之二点
//            k1 = f(mx, m1);//这里的mx和m1千万不能搞反了，前面是横坐标后面是纵坐标
//            k2 = f(mx, m2);
//            if (k1 < k2) r = m2;
//            else l = m1;
//        }
//        return (l + r) / 2;//注意这里是l,即y坐标
//
//    }
//    double get_xy_MinDist(double l, double r)
//    {//该函数在[l,r]区间内不断寻找满足(r-l)<eps的子区间左端点作为x坐标，并调用get_y_MinDist进行迭代
//        double m1, m2, k1, k2, my1, my2, L = l, R = r;
//        //m1, m2 是三分点, my1,my2是计算y的函数,k1,k2是计算f函数,L,R表示总的区间
//        while ((r - l) > eps)
//        {
//            m1 = l + (r - l) / 3.0;//三分之一点
//            m2 = l + (r - l) * 2.0 / 3.0;//三分之二点 注意double类型除法，除数和被除数至少有一个是double型！！！！
//            my1 = get_y_MinDist(L, R, m1);//这里的LR范围还是[0,100]而不是因为x迭代的[l,r]，因为这一步是固定x去迭代y，y的范围不受x的范围限制
//            my2 = get_y_MinDist(L, R, m2);//固定x为m2，去迭代y，找到的 my2 是当 x=m2 时 y=my2到其他点的距离最小
//            k1 = f(m1, my1);//(m1,my1)是一个可能的点，计算它到其他点的距离
//            k2 = f(m2, my2);//(m2,my2)也是一个可能的点，计算它到其他点的距离
//            minx = m1;//极值点可能是m1，也可能是m2，但是到最后的时候m1和m2足够接近，所以minx=m1和minx=m2都满足精度要求
//            if (k1 < k2) 
//            {// (m1,my1)到其他点的距离小，则 x 的最小值可能在 [L,m2] 之间，my1是临时的 y 的最小值
//                miny = my1;
//                r = m2; 
//            }
//            else 
//            { 
//                miny = my2;
//                l = m1; 
//            }
//        }
//        return k2;//注意这里是k1或k2，因为当 l 和 r足够接近时，k1和k2非常接近，任意一个都满足精度要求
//    }
//    double getMinDistSum(vector<vector<int>>& positions) {
//        //因为是单谷函数，很适合采用采用三分法
//        this->positions = positions;
//        int lhs = 0, rhs = 100;
//        return get_xy_MinDist(lhs, rhs);
//    }
//};
//int main()
//{
//    vector<vector<int>> positions = { {1, 1},{0, 0},{2, 0} };
//    Solution so;
//    cout << so.getMinDistSum(positions) << endl;
//    return 0;
//}

////////////////////////////////////////////凸包问题求解，包含所有点的最短周长///////////////////////////////////////

//https://leetcode-cn.com/problems/erect-the-fence/solution/by-ac_oier-4xuu/
//class Solution {
//private:
//    //相减
//    vector<int> subtract(const vector<int>& a, const vector<int>& b) {
//        return { a[0] - b[0], a[1] - b[1] };
//    }
//    //叉乘的长度
//    double cross(const vector<int>& a, const vector<int>& b) {
//        return a[0] * b[1] - a[1] * b[0];
//    }
//    //从ab到ac扫过的面积。我们根据这个即可判断ac是更接近ab的顺时针方向还是逆时针方向
//    double getArea(const vector<int>& a, const vector<int>& b, const vector<int>& c) 
//    {//定义向量ab,ac，当cross(ab,ac)< 0时，ac对应的线段在ab的顺时针方向（下面）；当cross(ab,ac)> 0时，ac对应的线段在ab的逆时针方向（上面）；当cross(ab,ac)=0时，ab,ac共线
//        return cross(subtract(b, a), subtract(c, a));
//    }
//public:
//    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
//        //二维凸包（Andrew 算法），在二维空间中，凸包可想象为一条刚好围着所有点的橡皮圈。Andrew 算法用于求解凸包上的所有点（围成所有点的最小周长），其算法逻辑将凸包分为「上凸壳」和「下凸壳」，并分别画出
//        sort(trees.begin(), trees.end(), [](const vector<int>& a, const vector<int>& b) 
//            {//根据 x 排升序的目的，是为了我们能够往一个方向画出凸包边缘（从左往后画出一半凸壳，从右往左画出另外一半），
//                //而将 y 升序目的是可以确保一旦我们现在从 a 到 b 进行连线，那么 a 到 b 之间的所有点能够确保被围住；
//            return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1];    //先按照x排序，若x相同则按照y排序
//            });
//
//        const int len = trees.size();//所有点的个数
//        int pointNum = 0;//画出凸包的点的顺序，从 1 开始，表示第 pointNum 个点 
//        vector<int> stk(len + 10);//记录我们选取了哪些点，索引表示画出凸包的顺序，值表示凸包上的每个点在trees里面的索引，
//        vector<bool> vis(len + 10);//记录哪些点我们已经用过了，在画第二部分的凸包时，只需要确保第一部分使用的点不参与即可
//        stk[++pointNum] = 0;    //不标记起点，因为第一部分和第二部分都会用到这个起点，起点就是所有点里面最左下的点，在trees里面索引为 0
//        for (int i = 1; i < len; ++i) 
//        {//索引为 0 的点已经是起点了，所以从 1 开始遍历，这是第一部分的凸包，是从x轴左边往x轴右边画的
//            auto& c = trees[i];
//            while (pointNum >= 2) 
//            {//若栈内元素不少于 2 个，考虑是否要将栈顶的边删掉（由栈顶前两个元素组成的边）假设栈顶元素为 b，栈顶元素的下一位为 a，即栈顶存在一条 a 到 b 的边，
//                //当前处理到的点为 c，此时我们根据 ac 边是否在 ab 边的某一时针方向来决定是否要将 ab 边去掉
//                //如果是顺时针画第一部分的凸包，那么当 ac 边在 ab 边的上面（逆时针方向）时，删除 ab 边，也就是cross(ab,ac)>0 时，删除 ab
//                //如果是逆时针画第一部分的凸包，那么当 ac 边在 ab 边的下面（顺时针方向）时，删除 ab 边，也就是cross(ab,ac)<0 时，删除 ab，这里是逆时针画凸包
//                auto& a = trees[stk[pointNum - 1]], b = trees[stk[pointNum]];//a，b是已有的两个点，连成 ab 边
//                if (getArea(a, b, c) < 0) //现在已经画了pointNum个点，其中 b 是第pointNum个
//                    vis[stk[pointNum--]] = false; //如果 ab 在 ac 的逆时针方向，则我们将 b 从上半部分的边中踢出去，连成 ac 边就行了
//                else 
//                    break; //否则，我们认为ab比ac更在上面
//            }
//            stk[++pointNum] = i;    //我们新画的第 pointNum+1 个在trees里的索引是 i
//            vis[i] = true;  //表明我们用了第i个点
//        }
//        const int usedPointNum = pointNum;//第一部分凸包画了 pointNum 个点
//        for (int i = len - 1; i >= 0; --i) 
//        {//这是第二部分的凸包，是从x轴右边往x轴左边画的
//            if (vis[i]) 
//                continue;   //我们不能使用已经作为第一部分的点
//            auto& c = trees[i];
//            while (pointNum > usedPointNum) 
//            {//假定处理完第一部分凸包，我们栈内有 m 个元素，我们需要将上述「栈顶元素不少于 2 个」的逻辑替换为「栈顶元素大于 m 个」保证第一部分的凸包边我们不能删去
//                auto& a = trees[stk[pointNum - 1]], b = trees[stk[pointNum]];
//                if (getArea(a, b, c) < 0) 
//                    //如果是顺时针画第二部分的凸包，那么当 ac 边在 ab 边的下面（逆时针方向）时，删除 ab 边，也就是cross(ab,ac)>0 时，删除 ab
//                    //如果是逆时针画第二部分的凸包，那么当 ac 边在 ab 边的上面（顺时针方向）时，删除 ab 边，也就是cross(ab,ac)<0 时，删除 ab，这里是逆时针画凸包
//                    --pointNum;   //同样的，如果ab在ac的逆时针方向，我们不使用点b
//                else 
//                    break;
//            }
//            stk[++pointNum] = i;
//        }
//
//        //因为我们一开始的时候就重复画了一个起点，因此我们最后的结果中需要移除该节点
//        vector<vector<int>> res;
//        for (int i = 1; i < pointNum; ++i) //i=1表示第一个点（起点），i=pointNum表示最后一个点（也是起点），所以要除掉
//            res.push_back(trees[stk[i]]);
//        return res;
//    }
//};
//int main()
//{
//    vector<vector<int>> trees = { {1, 1},{2, 2},{2, 0},{2, 4},{3, 3},{4, 2} };
//    Solution so;
//    so.outerTrees(trees);
//}

////////////////////////////////////////////检查在二维棋盘内是否有合法括号字符串路径从左上到右下///////////////////////////////////////

//https://leetcode.cn/problems/check-if-there-is-a-valid-parentheses-string-path/solution/tian-jia-zhuang-tai-hou-dfscpythonjavago-f287/1551464
//https://leetcode.cn/problems/check-if-there-is-a-valid-parentheses-string-path/solution/by-tsreaper-wbub/
//class Solution {
//public:
//    bool vis[105][105][205];
//    bool hasValidPath(vector<vector<char>>& grid) {
//        int m = grid.size(), n = grid[0].size();
//        //首先对于第一个和最后一个的判断，剪枝判断
//        if ((m + n) & 1 && grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
//            return false;//如果总行数+总列数=奇数，那么肯定不匹配
//        return dfs(grid, 0, 0, 0);
//    }
//
//    bool dfs(vector<vector<char>>& grid, int x, int y, int c) {
//        int m = grid.size(), n = grid[0].size();
//        //对于'('采取+1操作，对于')'采取-1操作，那么对于同一坐标下的状态就有至多m+n种
//        //(因为只有右和下，序列s最长也就m+n)
//
//        //走到最后了，发现c == 1，那这个时候就是满足条件的，
//        //因为已经排除了最后是'('的情况，因此算上最后的')'，就是0
//        if (x == m - 1 && y == n - 1)
//            return c == 1;
//        //这种情况是，前面累积还有c个'('没消除，就算当前这个加上后面全都是')'来抵消，也消不完，false
//        //m-x+n-y-2+1 = (m-1-x) + (n-1-y) + 1     
//        //前面两项就是正常的算后面还有几个，+1是因为我当前过来的x y对应的那个括号还没算，因此还要算上这个
//        if (c > m - x + n - y - 2 + 1)
//            return false;
//
//        //第二个情况是当前坐标的状态c被访问过了，那就代表之前走过从当前开始的这条路，并且没有true，那就没必要走了
//        if (vis[x][y][c])
//            return false;
//        //当前状态还没走过，那就标志位置为true
//        vis[x][y][c] = true;
//        //算上本次加上括号的状态
//        c += grid[x][y] == '(' ? 1 : -1;
//
//        //说明抵消完还有')',没必要往下走了
//        if (c < 0)
//            return false;
//        //向下，向右，只要一个存在路径就行
//        return (x < m - 1 && dfs(grid, x + 1, y, c)) || (y < n - 1 && dfs(grid, x, y + 1, c));
//    }
//};
//int main()
//{
//    Solution so;
//    vector<vector<char>> grid = { {'(', '(', '('},{')', '(', ')'},{'(', ')', ')'},{'(', '(', ')'} };
//    so.hasValidPath(grid);
//    //**************************三维DP************************
//        /*
//        前置知识:括号匹配问题可以在遍历过程维护一个变量k:当遇到'(',k++;当遇到')',k--
//        只要遍历过程中k始终>=0且最后k=0说明括号可以匹配
//        dp五部曲:
//        1.状态定义:dp[i][j][k]表示格子grid[i][j]是否存在括号状态为k的情形,有则为true,无则为false
//        2.状态转移:由于只能向右走或者向下走,因此只有两种转移途径
//            2.1 从上边转移:dp[i][j][k] = dp[i-1][j][k-c]
//            2.2 从左边转移:dp[i][j][k] = dp[i][j-1][k-c]
//            其中c为grid[i][j]的括号状态:c=grid[i][j]=='('?1:-1,也就是当前坐标(i,j)是'（'的时候，要使(i,j)的括号状态为 k ，那么从上方或者左边转移过来的状态就必须是 k-1，否则就必须是 k+1
//        3.初始化:初始化dp[0][0][1]=true,因为grid[0][0]必须为左括号
//        4.遍历顺序:i与j正均为序遍历,而k也是正序遍历(都可)
//        5.返回形式:只需要返回dp[m-1][n-1][0]即可
//        */
//    int m = grid.size(), n = grid[0].size();
//    if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
//    {//初始点是'）'或者终点是'（'，一定不满足条件
//        return false;
//    }
//    //每个坐标（i-1，j-1）最多有 i+j-1 中括号状态，最小是0（小于0就不用考虑了，肯定不能匹配），最大是 i+j-1，到达它的路径全是'（'，总共有 i-1+j 个'（'，注意这里的i和j是第几行第几列，不是下标
//    vector<vector<vector<int>>> dp(m, vector(n, vector(m + n, 0)));
//    dp[0][0][1] = 1;
//    for (int i = 0;i < m;i++)
//    {
//        for (int j = 0;j < n;j++)
//        {
//            for (int k = 0;k < m + n;k++)
//            {//其实只需要遍历到 i+1+j+1-1=i+j+1，也就是 k<i+j+2就行了，注意这里的 i和 j是下标，不要和上面的定义搞错了
//                int tmp = grid[i][j] == '(' ? 1 : -1;
//                if (k - tmp < 0 || k - tmp >= m + n)
//                {//太小或太大都不用考虑，肯定不能匹配
//                    continue;
//                }
//                if (i > 0)
//                {//只要上方或左边有一个满足条件就行
//                    dp[i][j][k] = dp[i][j][k] || dp[i - 1][j][k - tmp];
//                }
//                if (j > 0)
//                {
//                    dp[i][j][k] = dp[i][j][k] || dp[i][j - 1][k - tmp];
//                }
//            }
//        }
//    }
//    cout << dp[m - 1][n - 1][0] << endl;
//}

////////////////////////////////////////////原地哈希///////////////////////////////////////

//https://leetcode.cn/problems/find-all-duplicates-in-an-array/solution/by-fuxuemingzhu-dko5/
//注意题目给出的条件：数组长度是 n，每个数据的取值范围是[1, n]，且不重复
//我们知道一个数组有 下标 和 值 两个概念，根据下标获取到值。
//本题中，数组中数字的取值范围[1, n]，正好与下标的范围 [0, n - 1] 对应。
//因此，就有一个思路，对于 nums[i]，我们将下标 = nums[i] - 1 的位置的数字进行映射（还要能映射回去）。
//·映射方法通常有两种：
//  取反
//  增加偏移量
//方法一：取反
//  ·从起始位置进行遍历，每次将下标为 nums[i] - 1 的数字取反；
//  ·当遍历到值 nums[i] 为负数，需要忽略其负号。
//  ·若发现下标为 nums[i] - 1 的数字已经是负数，说明之前出现过同样的数字 nums[i]，即找到了重复数字；
//方法二：增加偏移量
//  除了取反之外，我们还可以增加一个偏移量，只要映射后与原数组的范围区分开就行。思路和取反一样，只是为了映射后与映射前的数组不混淆。
//  比如，本题中数字的范围是[1, 10^5]，我们可以增加一个偏移量 10^5，即映射到了一个新的数组空间。
//  做法：
//  ·从起始位置进行遍历，每次将下标为 nums[i] - 1 的数字 + 100000；
//  ·遍历到值 nums[i] 超过 100000，需要将其 - 100000 恢复原值；
//  ·若发现下标为 nums[i] - 1 的数字已经超过 100000，说明之前出现过同样的数字 nums[i]，即找到了重复数字；
//这里用取反
//int main()
//{
//    vector<int> nums = { 4,3,2,7,8,2,3,1 };
//    vector<int> res;
//    for (int i = 0;i < nums.size();i++)
//    {
//        int k = abs(nums[i]);
//        if (nums[k - 1] > 0)
//        {//如果下标为 nums[i-1] 的值为正，说明nums[i]之前没有出现过，标记为出现过
//            nums[k - 1] = -nums[k - 1];
//        }
//        else
//        {//否则就找到了一个重复数字
//            res.push_back(k);
//        }
//    }
//    for (auto& i : res)
//    {
//        cout << i << ' ';
//    }
//    return 0;
//}

////////////////////////////////////////////乘法表中的第k个最小值///////////////////////////////////////

//https://leetcode.cn/problems/kth-smallest-number-in-multiplication-table/solution/by-fuxuemingzhu-8eq4/
//bool isValid(int val, int m, int n, int k)
//{//第 i 行的数字分别是 i, 2∗i, 3∗i, ...，因此这一行小于等于 val 的数字个数为 min(val/i, n)。
//    int res = 0;
//    for (int i = 1;i <= min(val, m);i++)//i 不可能大于val，因为 val/i需要大于0，另外还要考虑乘法表总共 m 行
//    {
//        res += min(n, val / i);//val 整除以 i 得到了 val 是 i 的多少倍，表示在第 i 行有多少数字小于等于 val。同时矩阵最多有 n 列，因此需要取个 min。
//    }
//    if (res >= k)
//    {
//        return true;
//    }
//    return false;
//}
////乘法表：
////  1     2     3
////  2     4     6
////  3     6     9
//int main() 
//{
//    int m = 3, n = 3, k = 5;//3行3列乘法表，找到第5个最小值（1,2,2,3,3,4,6,6,9）
//    int left = 1, right = m * n;//二分法
//    int ans = 0;
//    while (left <= right)
//    {
//        int mid = left + (right - left) / 2;
//        if (isValid(mid, m, n, k))//如果小于等于mid的数大于等于k个，返回true，mid有可能是答案，记录一下，缩小范围
//        {
//            ans = mid;
//            right = mid - 1;
//        }
//        else
//        {
//            left = mid + 1;//否则直接缩小范围
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}

////////////////////////////////////////////异或矩阵中的第k个最大值///////////////////////////////////////

//给你一个二维矩阵 matrix 和一个整数 k ，矩阵大小为 m x n 由非负整数组成。
//新矩阵中坐标(a, b) 的 值 可由对所有满足 0 <= i <= a < m 且 0 <= j <= b < n 的元素 matrix[i][j]（下标从 0 开始计数）执行异或运算得到。
//请你找出新矩阵中第 k 大的值（k 的值从 1 开始计数）。
//https://leetcode.cn/problems/find-kth-largest-xor-coordinate-value/solution/xin-shou-pian-qian-ru-shen-chu-xi-lie-er-uwny/
//int main()
//{
//    vector<vector<int>> matrix = { {5, 2}, { 1, 6} };
//    int k = 2;
//    int m = matrix.size(), n = matrix[0].size();
//    vector<vector<int>> dp(m + 1, vector<int>(n + 1));//dp就是新矩阵
//    vector<int> results;
//    for (int i = 1; i <= m; ++i) {
//        for (int j = 1; j <= n; ++j) {
//            dp[i][j] = dp[i - 1][j] ^ dp[i][j - 1] ^ dp[i - 1][j - 1] ^ matrix[i - 1][j - 1];//推导参考链接
//            results.push_back(dp[i][j]);
//        }
//    }
//
//    nth_element(results.begin(), results.begin() + k - 1, results.end(), greater<int>());//第k个最大值库函数，nth_element（）默认是升序，也就是求第k个最小值，注意这个函数没有返回值，他只是把第k个值
//                                                                                         //放在应该在的位置，不会主动返回这个值
//    cout << results[k - 1] << endl;//因此需要用下标去访问
//    return 0;
//}

////////////////////////////////////////////猫和老鼠（博弈论）///////////////////////////////////////

//***************************************************动态规划***************************************************
//https://leetcode.cn/problems/cat-and-mouse/solution/gong-shui-san-xie-dong-tai-gui-hua-yun-y-0bx1/
//无向图，两人轮流行动。
//老鼠从节点 1 开始，第一个出发；猫从节点 2 开始，第二个出发。在节点 0 处有一个洞。
//此外，猫无法移动到洞中（节点 0）。
//由于老鼠可能的位置有 n 个，猫可能的位置有 n - 1 个，游戏轮数最大为 2n(n - 1)，因此动态规划的状态数是 O(n^4)
//对于每个状态需要 O(n) 的时间计算状态值，因此总时间复杂度是 O(n^5)
//class Solution {
//    const static  int N = 55;//棋盘最大为50
//    最多有 n 个位置，因此 (i, j) 位置对组合数最多为 n*(n-1)种，然后 k 其实代表的是老鼠先手还是猫先手，共有 2 种可能，因此状态数量数据有明确上界为 2*n^2
//    int f[2 * N * N][N][N];//f[k][i][j] 为当前进行了 k 步，老鼠所在位置为 i，猫所在的位置为 j 时，最终的获胜情况（0 为平局，1 和 2 分别代表老鼠和猫获胜）
//    vector<vector<int>> g;
//    int n;
//public:
//    int catMouseGame(vector<vector<int>>& graph) {
//        g = graph;
//        n = g.size();
//        memset(f, -1, sizeof(f));//初始化
//        /*for (int k = 0; k < 2 * n * n; k++) {
//            for (int i = 0; i < n; i++) {
//                for (int j = 0; j < n; j++) {
//                    f[k][i][j] = -1;
//                }
//            }
//        }*/
//        return dfs(0, 1, 2);
//    }
//private:
//    int dfs(int k, int a, int b) 
//    {//老鼠先走，k是偶数代表该老鼠走了，奇数代表该猫走了，当前老鼠位于a，猫位于b
//        int ans = f[k][a][b];
//        if (a == 0) //出口就是0 ，老鼠位于 0 就赢了（即使猫也在0也没事）
//            ans = 1;
//        else if (a == b) //否则猫就逮到老鼠了
//            ans = 2;
//        else if (k >= 2 * n * n)//步数超过2n^2，所有状态都走过一遍了，所以一定平局，参考 https://leetcode.cn/problems/cat-and-mouse/solution/guan-yu-2n2die-dai-bu-shu-de-zheng-ming-2x2il/
//            ans = 0;
//        else if (ans == -1) 
//        {//只有未访问过此状态才往下访问
//            if (k % 2 == 0) 
//            {//该老鼠走了
//                bool win = false;//老鼠能赢
//                bool draw = false;//平局
//                for (int ne : g[a]) 
//                {
//                    int t = dfs(k + 1, ne, b);//随便走一步
//                    if (t == 1) 
//                        win = true;//如果返回 1 ，代表这样走老鼠能赢，
//                    else if (t == 0) //如果返回 0 ，代表这样走平局，
//                        draw = true;
//                    if (win) //如果老鼠能赢，不需要再往下搜索了
//                        break;
//                }
//                if (win) 
//                    ans = 1;//老鼠赢
//                else if (draw)  
//                    ans = 0;//平局
//                else 
//                    ans = 2;//猫赢
//            }
//            else {//该猫走了
//                bool win = false;//猫能赢
//                bool draw = false;//平局
//                for (int ne : g[b]) {
//                    if (ne == 0) //猫无法移动到洞中（节点 0）
//                        continue;
//                    int t = dfs(k + 1, a, ne);
//                    if (t == 2) 
//                        win = true;//如果返回 2 ，代表这样走猫能赢，
//                    else if (t == 0) 
//                        draw = true;//如果返回 0 ，代表这样走平局，
//                    if (win) 
//                        break;//如果猫能赢，不需要再往下搜索了
//                }
//
//                if (win)
//                    ans = 2;
//                else if (draw)
//                    ans = 0;
//                else 
//                    ans = 1;
//
//            }
//        }
//        f[k][a][b] = ans;//记忆化搜索
//        return ans;
//    }
//};
//***************************************************拓扑排序(博弈论的正确解法）***************************************************
//https://leetcode.cn/problems/cat-and-mouse/solution/guan-fang-jie-da-shen-ru-jie-du-you-xian-rj57/
//class Solution {
//public:
//    const int MOUSE_TURN = 0, CAT_TURN = 1;
//    const int DRAW = 0, MOUSE_WIN = 1, CAT_WIN = 2;
//    vector<vector<int>> graph;
//    vector<vector<vector<int>>> degrees;
//    vector<vector<vector<int>>> results;
//
//    int catMouseGame(vector<vector<int>>& graph) {
//        int n = graph.size();
//        this->graph = graph;
//        this->degrees = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(2)));
//        //定义results[i][j][k],k=0或1，k=0表示该老鼠行动，k=1表示该猫行动，i表示老鼠所在的位置，j表示猫所在的位置，而results[i][j][k]表示在状态i, j，k下所有的后继状态。
//        //例如，根据题意，初始状态为[1][2][0]，此时i = 1表示老鼠在位置1，j = 2表示猫在位置2，k = 0表示该老鼠行动，老鼠现在只能前往位置 3，同时下一步该猫行动，
//        //因此results[1][2][0] = { [3][2][1]（表示状态）}，再下一步猫可以前往位置4或位置5，因此results[3][2][1] = { [3][4][0] 、[3][5][0] }
//        //这样我们就能根据给出的节点图以及规则将状态转移图构建出来。
//        this->results = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(2)));
//        queue<tuple<int, int, int>> qu;
//
//        for (int i = 0; i < n; i++) {
//            for (int j = 1; j < n; j++) {
//                degrees[i][j][MOUSE_TURN] = graph[i].size();//状态[i][j][0]的邻居状态，也就是results[i][j][0]最多有几个后续状态，此时该老鼠走，它只能走向节点 i 的相邻结点，总共有 graph[i].size() 个
//                degrees[i][j][CAT_TURN] = graph[j].size();//状态[i][j][1]的邻居状态，也就是results[i][j][1]最多有几个后续状态，此时该猫走，它只能走向节点 j 的相邻结点，总共有 graph[j].size() 个
//            }
//        }
//        for (int node : graph[0]) 
//        {
//            for (int i = 0; i < n; i++) 
//            {//不管老鼠位于什么节点（i=[0:n]），该猫走的时候（k=CAT_TURN），如果它位于 节点0 的邻居节点（node : graph[0]），那么猫不能去节点 0，也就是[i][node][CAT_TURN]这些状态的后续状态要减 1
//                degrees[i][node][CAT_TURN]--;
//            }
//        }
//        for (int j = 1; j < n; j++) 
//        {//初始化
//            results[0][j][MOUSE_TURN] = MOUSE_WIN;//老鼠位于节点 0（i=0），猫位于任意节点（j=[1:n]），不管该老鼠走还是猫走，都是老鼠赢
//            results[0][j][CAT_TURN] = MOUSE_WIN;
//            qu.emplace(0, j, MOUSE_TURN);//这两个状态的比赛结果已知，加入队列，用于推断他们的邻居状态
//            qu.emplace(0, j, CAT_TURN);
//        }
//        for (int i = 1; i < n; i++) 
//        {
//            results[i][i][MOUSE_TURN] = CAT_WIN;//猫和老鼠位于相同节点 i（i！=0），不管该老鼠走还是猫走，都是猫赢
//            results[i][i][CAT_TURN] = CAT_WIN;
//            qu.emplace(i, i, MOUSE_TURN);//这些状态的比赛结果已知，加入队列，用于推断他们的邻居状态
//            qu.emplace(i, i, CAT_TURN);
//        }
//        while (!qu.empty()) {
//            auto [mouse, cat, turn] = qu.front();
//            qu.pop();
//            int result = results[mouse][cat][turn];//记录当前状态的比赛结果
//            vector<tuple<int, int, int>> prevStates = GetPrevStates(mouse, cat, turn);//通过当前状态推断出了前一状态有哪些
//            for (auto& [prevMouse, prevCat, prevTurn] : prevStates) 
//            {
//                if (results[prevMouse][prevCat][prevTurn] == DRAW) 
//                {//如果前一状态的比赛结果是平局，说明这一状态还没更新比赛结果（因为初始化就是平局，并且我们是自底向顶更新的）
//                    //当前状态的比赛结果是老鼠赢，并且前一回合该老鼠走，那么它走向当前这个必胜状态，就一定赢，那么前一状态的比赛结果一定不会是平局（这里暂时不管是老鼠赢还是猫赢）
//                    //当前状态的比赛结果是猫赢，并且前一回合该猫走，那么它走向当前这个必胜状态，就一定赢，那么前一状态的比赛结果一定不会是平局（这里暂时不管是老鼠赢还是猫赢）
//                    bool canWin = (result == MOUSE_WIN && prevTurn == MOUSE_TURN) || (result == CAT_WIN && prevTurn == CAT_TURN);
//                    if (canWin) 
//                    {//一定能分出胜负
//                        results[prevMouse][prevCat][prevTurn] = result;//能分出胜负就只有上面两种情况，那么更新比赛结果
//                        qu.emplace(prevMouse, prevCat, prevTurn);
//                    }
//                    else if (--degrees[prevMouse][prevCat][prevTurn] == 0) 
//                    {//否则前一状态无法确定谁一定赢，那么如果前一回合该老鼠走，由于前一状态的后续状态全都得不到老鼠赢的结果，那么前一状态的比赛结果一定是猫赢
//                        //因为老鼠尝试了所有路线都无法取得胜利（degrees记录的是前一状态能转移的所有路径），那么老鼠肯定就输了（如果有一条路径能赢的话就会执行if语句而不是这条语句）
//                        //如果前一回合该猫走，由于前一状态的后续状态全都得不到猫赢的结果，那么前一状态的比赛结果一定是老鼠
//                        //因为猫尝试了所有路线都无法取得胜利（degrees记录的是前一状态能转移的所有路径），那么猫肯定就输了（如果有一条路径能赢的话就会执行if语句而不是这条语句）
//                        //而且我们是从必胜/必败状态出发去推断前一状态是必胜还是必败的，在队列中的前一状态不可能出现平局（因为在队列中就意味着状态可以转化，这些状态的结果是相同的）
//                        int loseResult = prevTurn == MOUSE_TURN ? CAT_WIN : MOUSE_WIN;
//                        results[prevMouse][prevCat][prevTurn] = loseResult;
//                        qu.emplace(prevMouse, prevCat, prevTurn);
//                    }
//                }
//            }
//        }
//        return results[1][2][MOUSE_TURN];//自底向上推断比赛结果，返回
//    }
//
//    vector<tuple<int, int, int>> GetPrevStates(int mouse, int cat, int turn) 
//    {//找到哪些状态能变成当前状态，也就是当前状态是哪些状态的后续状态
//        vector<tuple<int, int, int>> prevStates;//用来保存这些状态
//        int prevTurn = turn == MOUSE_TURN ? CAT_TURN : MOUSE_TURN;//turn是当前状态该谁走，该老鼠的话上一状态就该猫，该猫的话上一状态就该老鼠
//        if (prevTurn == MOUSE_TURN) 
//        {//上一状态该老鼠走
//            for (int& prev : graph[mouse]) 
//            {//老鼠当前位于mouse，则上一状态就位于 mouse的邻居节点 prev
//                prevStates.emplace_back(prev, cat, prevTurn);//那么上一状态就是[prev][cat][prevTurn],因为上一状态猫不能走
//            }
//        }
//        else {//上一状态该猫走
//            for (int& prev : graph[cat]) 
//            {//猫当前位于cat，则上一状态就位于 cat 的邻居节点 prev
//                if (prev != 0) 
//                {//猫不能位于节点 0
//                    prevStates.emplace_back(mouse, prev, prevTurn);
//                }
//            }
//        }
//        return prevStates;
//    }
//};
//int main()
//{
//    Solution so;
//    vector<vector<int>> graph = { {2, 5}, {3}, {0, 4, 5}, {1, 4, 5}, {2, 3}, {0, 2, 3} };
//    int res=so.catMouseGame(graph);
//    if (res == 1)
//    {
//        cout << "老鼠赢" << endl;
//    }
//    else if (res == 2)
//    {
//        cout << "猫赢" << endl;
//    }
//    else
//    {
//        cout << "平局" << endl;
//    }
//    return 0;
//}

////////////////////////////////////////////猫和老鼠②（博弈论，拓扑排序）///////////////////////////////////////

//https://leetcode.cn/problems/cat-and-mouse-ii/solution/mao-he-lao-shu-ii-by-leetcode-solution-e5io/
//static const int MOUSE_TURN = 0, CAT_TURN = 1;
//static const int UNKNOWN = 0, MOUSE_WIN = 1, CAT_WIN = 2;
//static const int MAX_MOVES = 1000;
//class Solution {
//public:
//    vector<vector<int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
//    int rows, cols;
//    vector<string> grid;
//    int catJump, mouseJump;
//    int food;
//    int degrees[64][64][2];//degrees记录的是[mouse][cat][turn]状态能转移的后续状态的总数，[mouse][cat]是这一轮还没走之前的状态，而不是这一轮走完以后的状态
//    int results[64][64][2][2];//results[mouse][cat][turn][0]记录的是[mouse][cat][turn]状态的比赛结果,results[mouse][cat][turn][1]记录的是[mouse][cat][turn]状态的比赛次数，因为轮数>1000，老鼠获胜
//                              //所以老鼠有两种获胜方法，这区别于 上一个 猫鼠游戏
//
//    bool canMouseWin(vector<string> grid, int catJump, int mouseJump) {
//        this->rows = grid.size();
//        this->cols = grid[0].size();
//        this->grid = grid;
//        this->catJump = catJump;
//        this->mouseJump = mouseJump;
//        int startMouse = -1, startCat = -1;
//        for (int i = 0; i < rows; i++) {
//            for (int j = 0; j < cols; j++) {
//                char c = grid[i][j];
//                if (c == 'M') {
//                    startMouse = getPos(i, j);
//                }
//                else if (c == 'C') {
//                    startCat = getPos(i, j);
//                }
//                else if (c == 'F') {
//                    food = getPos(i, j);
//                }
//            }
//        }
//        int total = rows * cols;
//        memset(degrees, 0, sizeof(degrees));
//        memset(results, 0, sizeof(results));
//        queue<tuple<int, int, int>> qu;
//        // 计算每个状态的度
//        for (int mouse = 0; mouse < total; mouse++) {
//            int mouseRow = mouse / cols, mouseCol = mouse % cols;
//            if (grid[mouseRow][mouseCol] == '#') {//遇到墙的话，它不能作为任何状态的后续状态，它也不会有后续状态，直接跳过
//                continue;
//            }
//            for (int cat = 0; cat < total; cat++) {
//                int catRow = cat / cols, catCol = cat % cols;
//                if (grid[catRow][catCol] == '#') {
//                    continue;
//                }
//                degrees[mouse][cat][MOUSE_TURN]++;//可以停留在原地，所以[mouse][cat][MOUSE_TURN]的后续状态可以是[mouse][cat][MOUSE_TURN]，原本的状态
//                degrees[mouse][cat][CAT_TURN]++;//可以停留在原地，所以[mouse][cat][CAT_TURN]的后续状态可以是[mouse][cat][CAT_TURN]，原本的状态
//                for (auto& dir : dirs) 
//                {
//                    for (int row = mouseRow + dir[0], col = mouseCol + dir[1], jump = 1; row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] != '#' && jump <= mouseJump; row += dir[0], col += dir[1], jump++) 
//                    {//[mouse][cat][MOUSE_TURN]这个状态在[nextMouse][nextCat][MOUSE_TURN]这个状态的跳转范围内，所以[nextMouse][nextCat][MOUSE_TURN]的后续状态里面包含[mouse][cat][MOUSE_TURN]状态，所以
//                        //[nextMouse][nextCat][MOUSE_TURN]的度要加一，换句话说，对于状态A，他能跳转到B,C,D...，那么B,C,D...也能跳转到A，所以A也是B,C,D的后续状态，则B,C,D的度加1
//                        //遍历所有状态（两个for循环）就能找到所有状态的度
//                        int nextMouse = getPos(row, col), nextCat = getPos(catRow, catCol);
//                        degrees[nextMouse][nextCat][MOUSE_TURN]++;
//                    }
//                    for (int row = catRow + dir[0], col = catCol + dir[1], jump = 1; row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] != '#' && jump <= catJump; row += dir[0], col += dir[1], jump++) 
//                    {//同理
//                        int nextMouse = getPos(mouseRow, mouseCol), nextCat = getPos(row, col);
//                        degrees[nextMouse][nextCat][CAT_TURN]++;
//                    }
//                }
//            }
//        }
//        // 猫和老鼠在同一个单元格，猫获胜，这些状态的比赛结果已知，我们要用这些已知的结果去推断未知的结果
//        for (int pos = 0; pos < total; pos++) {
//            int row = pos / cols, col = pos % cols;
//            if (grid[row][col] == '#') {
//                continue;
//            }
//            results[pos][pos][MOUSE_TURN][0] = CAT_WIN;
//            results[pos][pos][MOUSE_TURN][1] = 0;//此状态操作次数为0
//            results[pos][pos][CAT_TURN][0] = CAT_WIN;
//            results[pos][pos][CAT_TURN][1] = 0;
//            qu.emplace(pos, pos, MOUSE_TURN);
//            qu.emplace(pos, pos, CAT_TURN);
//        }
//        // 猫和食物在同一个单元格，猫获胜
//        for (int mouse = 0; mouse < total; mouse++) {
//            int mouseRow = mouse / cols, mouseCol = mouse % cols;
//            if (grid[mouseRow][mouseCol] == '#' || mouse == food) 
//            {//老鼠位于墙的状态不存在，直接跳过，老鼠已经在food的状态，猫不可能获胜，跳过
//                continue;
//            }
//            results[mouse][food][MOUSE_TURN][0] = CAT_WIN;
//            results[mouse][food][MOUSE_TURN][1] = 0;//此状态操作次数为0
//            results[mouse][food][CAT_TURN][0] = CAT_WIN;
//            results[mouse][food][CAT_TURN][1] = 0;
//            qu.emplace(mouse, food, MOUSE_TURN);
//            qu.emplace(mouse, food, CAT_TURN);
//        }
//        // 老鼠和食物在同一个单元格且猫和食物不在同一个单元格，老鼠获胜
//        for (int cat = 0; cat < total; cat++) {
//            int catRow = cat / cols, catCol = cat % cols;
//            if (grid[catRow][catCol] == '#' || cat == food) 
//            {//猫位于墙的状态不存在，直接跳过，猫已经在food的状态，老鼠不可能获胜，跳过
//                continue;
//            }
//            results[food][cat][MOUSE_TURN][0] = MOUSE_WIN;
//            results[food][cat][MOUSE_TURN][1] = 0;
//            results[food][cat][CAT_TURN][0] = MOUSE_WIN;
//            results[food][cat][CAT_TURN][1] = 0;
//            qu.emplace(food, cat, MOUSE_TURN);
//            qu.emplace(food, cat, CAT_TURN);
//        }
//        // 拓扑排序
//        while (!qu.empty()) {
//            auto [mouse, cat, turn] = qu.front();//已知比赛结果的状态
//            qu.pop();
//            int result = results[mouse][cat][turn][0];//比赛结果
//            int moves = results[mouse][cat][turn][1];//移动了多少次
//            vector<tuple<int, int, int>> prevStates = getPrevStates(mouse, cat, turn);
//            for (auto [prevMouse, prevCat, prevTurn] : prevStates) {
//                if (results[prevMouse][prevCat][prevTurn][0] == UNKNOWN) 
//                {//前一状态的结果未知，如果已知的话就不用推断了
//                    bool canWin = (result == MOUSE_WIN && prevTurn == MOUSE_TURN) || (result == CAT_WIN && prevTurn == CAT_TURN);
//                    if (canWin) 
//                    {//一定能分出胜负
//                        results[prevMouse][prevCat][prevTurn][0] = result;
//                        results[prevMouse][prevCat][prevTurn][1] = moves + 1;
//                        qu.emplace(prevMouse, prevCat, prevTurn);//前一状态的结果和当前结果相同
//                    }
//                    else 
//                    {//无法分出胜负
//                        //如果前一状态的度减少到 0，则从前一状态出发到达的所有后续状态都是上一轮的移动方的必败状态，因此前一状态也是上一轮的移动方的必败状态。
//                        degrees[prevMouse][prevCat][prevTurn]--;//前一状态的后续状态减去 1
//                        if (degrees[prevMouse][prevCat][prevTurn] == 0) 
//                        {//前一状态的后续状态没有了，那么上一轮该谁走，谁就是必输的
//                            int loseResult = prevTurn == MOUSE_TURN ? CAT_WIN : MOUSE_WIN;
//                            results[prevMouse][prevCat][prevTurn][0] = loseResult;
//                            results[prevMouse][prevCat][prevTurn][1] = moves + 1;
//                            qu.emplace(prevMouse, prevCat, prevTurn);
//                        }
//                    }
//                }
//            }
//        }
//        return results[startMouse][startCat][MOUSE_TURN][0] == MOUSE_WIN && results[startMouse][startCat][MOUSE_TURN][1] <= MAX_MOVES;//老鼠赢必须在1000回合以内
//    }
//
//    vector<tuple<int, int, int>> getPrevStates(int mouse, int cat, int turn) 
//    {//当前状态去推断前一状态
//        vector<tuple<int, int, int>> prevStates;
//        int mouseRow = mouse / cols, mouseCol = mouse % cols;//当前老鼠的位置
//        int catRow = cat / cols, catCol = cat % cols;//当前猫的位置
//        int prevTurn = turn == MOUSE_TURN ? CAT_TURN : MOUSE_TURN;//上一轮该谁走
//        int maxJump = prevTurn == MOUSE_TURN ? mouseJump : catJump;//不同的角色能移动的范围不同
//        int startRow = prevTurn == MOUSE_TURN ? mouseRow : catRow;//上一轮该老鼠走，那么就从当前老鼠的位置出发，找前一状态
//        int startCol = prevTurn == MOUSE_TURN ? mouseCol : catCol;
//        prevStates.emplace_back(mouse, cat, prevTurn);//可以停留在原地，所以当前状态也可以是前一状态
//        for (auto& dir : dirs) 
//        {
//            for (int i = startRow + dir[0], j = startCol + dir[1], jump = 1; i >= 0 && i < rows && j >= 0 && j < cols && grid[i][j] != '#' && jump <= maxJump; i += dir[0], j += dir[1], jump++) {
//                int prevMouseRow = prevTurn == MOUSE_TURN ? i : mouseRow;//上一轮该老鼠走，老鼠就能在最大移动范围内任意移动，否则应该停在原地
//                int prevMouseCol = prevTurn == MOUSE_TURN ? j : mouseCol;
//                int prevCatRow = prevTurn == MOUSE_TURN ? catRow : i;//上一轮该猫走，猫就能在最大移动范围内任意移动，否则应该停在原地
//                int prevCatCol = prevTurn == MOUSE_TURN ? catCol : j;
//                int prevMouse = getPos(prevMouseRow, prevMouseCol);//上一轮老鼠的位置
//                int prevCat = getPos(prevCatRow, prevCatCol);//上一轮猫的位置
//                prevStates.emplace_back(prevMouse, prevCat, prevTurn);//上一轮的状态
//            }
//        }
//        return prevStates;
//    }
//
//    int getPos(int row, int col) 
//    {//二维转一维
//        return row * cols + col;
//    }
//};
//int main()
//{
//    Solution so;
//    vector<string> grid = { "####F", "#C...", "M...." };
//    int catJump = 1, mouseJump = 2;
//    bool res=so.canMouseWin(grid,catJump,mouseJump);
//    if (res)
//    {
//        cout << "老鼠赢" << endl;
//    }
//    else
//    {
//        cout << "猫赢" << endl;
//    }
//    return 0;
//}

////////////////////////////////////////////相邻元素差的绝对值之和的最小值///////////////////////////////////////

//https://www.nowcoder.com/questionTerminal/a132e8338b9e4545a154b1407cd41fd2
//每列的三个数字中取出一个按顺序组成一个长度为 n 的数组 b，计算b相邻元素差的绝对值之和的最小值是多少
//输入：5
//      5 9 5 4 4
//      4 7 4 10 3
//      2 10 9 2 3
//输出：5，解释：数组 b 可以为[5,7,5,4,4]，答案为 5。
//int main()
//{
//    int n;
//    cin >> n;//n列数字，每列有3个数
//    vector<vector<int>> nums(3, vector<int>(n,0));
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < n; j++) {
//            cin >> nums[i][j];
//        }
//    }
//    vector<vector<long long>> dp(3, vector<long long>(n));//dp[i][j]:到第j列为止，选择nums[i][j]为结尾的绝对值之和的最小值
//    for (int j = 1; j < n; j++) {
//        for (int i = 0; i < 3; i++) 
//        {//每一列分别计算选择nums[0][j]、nums[1][j]、nums[2][j]时的绝对值之和最小值
//            long long path1 = dp[0][j - 1] + abs(nums[0][j - 1] - nums[i][j]);
//            long long path2 = dp[1][j - 1] + abs(nums[1][j - 1] - nums[i][j]);
//            long long path3 = dp[2][j - 1] + abs(nums[2][j - 1] - nums[i][j]);
//            dp[i][j] = min(min(path1, path2), path3);//选择最小的一个作为以nums[i][j]结尾的绝对值之和
//        }
//    }
//    cout << min(dp[0][n - 1], min(dp[1][n - 1], dp[2][n - 1])) << endl;//最后有三个最小值，选择最小的那个
//    return 0;
//}

////////////////////////////////////////////统计区间中的整数数目///////////////////////////////////////

//https://leetcode.cn/problems/count-integers-in-intervals/solution/by-tsreaper-fc7p/
//用一个 set 有序地维护所有不相交的区间，当加入区间[left, right] 时，通过 lower_bound 快速找到第一个 右端点 大于等于 left - 1 的区间，
//然后不断用接下来的区间和[left, right] 合并，直到当前区间的左端点大于 right + 1。由于每个区间只会加入以及离开 set 一次，复杂度 O(nlogn)。
//·为什么用 left - 1 和 right + 1 比较，直接 left 和 right 不行吗？
//  为了把虽然不相交但是连续的区间也合并，比如[1, 3], [4, 6] 可以合并成[1, 6]。当然对于本题而言这样的合并不需要。直接用 left 和 right 判断也可以，但作为模板的角度合并可能更合适一点。
//typedef pair<int, int> pii;
//class CountIntervals {
//    int ans = 0;
//    set<pii> st;//记录不同区间<right,left>，按照右边界大小升序排列，
//public:
//    CountIntervals() {
//    }
//    void add(int left, int right) 
//    {
//        int L = left, R = right;
//        /*{c, d) = lower_bound({ a, b))是要(c > a) || (c == a && d >= b)， 
//        {c, d) = upper_bound({a, b))是要(c > a) || (c == a && d > b)。可以理解为把pair看作连续的数，first在高位，second在低位*/
//        //目标是找到第一个 右端点 大于等于 left - 1 的区间，这样就能和 [left,right] 合并为一个区间，所以如果有 一个区间右端点等于 left - 1 ，那么不管它的左端点是多少，都大于 -2e9，，保证它都满足条件
//        //能够合并，其实写成0也没问题，因为题目保证了所有区间左端点都大于0，写成upper_bound也没问题
//        auto it = st.lower_bound(pii(left - 1, -2e9));
//        while (it != st.end()) 
//        {//因为it是第一个能够和 [left,right] 合并的区间，我们不清楚后面还有多少区间能够合并，所以用了while
//            if (it->second > right + 1) 
//                break;//如果某个区间的左端点大于 right + 1，说明这个区间不能再和 [left,right] 合并了，退出循环
//            L = min(L, it->second);//能合并的时候计算最左和最右端点
//            R = max(R, it->first);
//            ans -= it->first - it->second + 1;//为了避免重复计算原有区间包含的整数个数，所以要减去，原有区间已经合并到新区间了，后面会再加上
//            st.erase(it++);//原有区间已经不需要了，删除区间，it++ 会返回旧值，本身会++，这个时候erase的是旧值，it已经到下一个节点了。另一种写法是 it = st.erase(it) ，erase会返回it的下一个位置，都可以
//        }
//        ans += R - L + 1;//已经没有区间能够合并了，所有区间包含的整数个数重新计算
//        st.insert(pii(R, L));//插入这个新区间，此时所有区间都不能再合并了
//    }
//
//    int count() {
//        return ans;
//    }
//};
//int main()
//{
//    CountIntervals countIntervals; // 用一个区间空集初始化对象
//    countIntervals.add(2, 3);  // 将 [2, 3] 添加到区间集合中
//    countIntervals.add(7, 10); // 将 [7, 10] 添加到区间集合中
//    countIntervals.count();    // 返回 6
//                               // 整数 2 和 3 出现在区间 [2, 3] 中
//                               // 整数 7、8、9、10 出现在区间 [7, 10] 中
//    countIntervals.add(5, 8);  // 将 [5, 8] 添加到区间集合中
//    countIntervals.count();    // 返回 8
//                               // 整数 2 和 3 出现在区间 [2, 3] 中
//                               // 整数 5 和 6 出现在区间 [5, 8] 中
//                               // 整数 7 和 8 出现在区间 [5, 8] 和区间 [7, 10] 中
//                               // 整数 9 和 10 出现在区间 [7, 10] 中
//}

////////////////////////////////////////////每个子数组内最小值的总和///////////////////////////////////////

//https://leetcode.cn/problems/sum-of-subarray-minimums/solution/xiao-bai-lang-dong-hua-xiang-jie-bao-zhe-489q/
//给定一个整数数组 arr，找到 min(b) 的总和，其中 b 的范围为 arr 的每个（连续）子数组。
//思路就是找到每个数字的 ‘管辖范围’，也就是每个数字能被作为最小值的子数组左右边界[left,right]，也就是在[left,right]这段范围内包含nums[i]的子数组，最小值都是 nums[i]
//int main()
//{
//    vector<int> arr = { 3,1,2,4 };
//    stack<int> st;//通过单调栈来求
//    int n = arr.size();
//    vector<int> lsmall(n, -1), rsmall(n, n);//每个数字左边界和右边界，默认是-1和n
//    for (int i = 0;i < n;++i)
//    {
//        while (!st.empty() && arr[st.top()] >= arr[i])
//        {//如果这里是>=，说明我们找的左边界是严格小于arr[i]的，因为对于nums[i]来说，栈里面存放的是它左边的值，只有当栈顶的值严格小于arr[i]的时候才退出循环
//            //而我们找的右边界是小于等于arr[i]的，因为对于栈里面的值来说，arr[i]是它右边的值，当右边的值小于等于栈顶的时候，我们就认为找到了右边界，并记录下来
//            //如果这里是>，说明我们找的左边界是小于等于arr[i]的，因为对于nums[i]来说，栈里面存放的是它左边的值，只有当栈顶的值小于等于arr[i]的时候才退出循环
//            //而我们找的右边界是严格小于arr[i]的，因为对于栈里面的值来说，arr[i]是它右边的值，当右边的值严格小于栈顶的时候，我们就认为找到了右边界，并记录下来
//            //这么做的目的是为了防止某些子数组被重复计算，注意不管是严格小于还是小于等于，lsmall[i]和rsmall[i]都是左右边界，都无法取到，所以left=lsmall[i]，right=small[i]。
//            //比如[3,1,2,4,1*]中有两个1，，如果两边都是严格小于，那么对于第一个 1 而言，求出来的范围是整个数组[-1:5]
//            //对于第二个 1* 而言，求出来的范围也是整个数组[-1:5]，这样就是重复计算了
//            //而如果右边闭左边开的话，对于第一个 1 求出来的范围是[-1:4],第二个1*求出来范围是[-1:5],不会重复计算子数组
//            //因为对于第一个1，它充当最小值的区间为{3,1}，{3,1,2}，{3,1,2,4}，{1}，{1,2}，{1,2,4}
//            //而对于第二个1*，它充当最小值的区间为{3,1,2,4,1*},{1,2,4,1*},{2,4,1*},{4,1*},{1*}。这样就不会重复
//            rsmall[st.top()] = i;
//            st.pop();
//        }
//        if (!st.empty())
//        {
//            lsmall[i] = st.top();
//        }
//        st.push(i);
//    }
//    int res = 0;
//    for (int i = 0;i < n;i++)
//    {//我们要确定的是对于每一个nums[i]，它能在多少个子数组里充当最小值，注意这个子数组必须包含 nums[i]，
//        //所以我们从 (lsmall[i],i] 或者说 [left,i] 这个范围内选择一个来当子数组的左边界，从 [i，rsmall[i]) 或者说 [i，right]这个范围内选择一个来当子数组的右边界，
//        //这样构建出来的子数组就一定包含 nums[i]，并且最小值就是 nums[i]，这样的子数组一共有  (i - lsmall[i]) * (rsmall[i] - i) 个，
//        //那么nums[i]对最终结果的贡献值就是 arr[i] * (i - lsmall[i]) * (rsmall[i] - i)，注意溢出
//        //注意lsmall[i]和rsmall[i]是边界，无法取到，所以左边区间个数为 i-(lsmall[i]+1)+1=i - lsmall[i]
//        //右边区间个数为 rsmall[i]-1-i+1=rsmall[i] - i
//        res = (res + 1LL * arr[i] * (i - lsmall[i]) * (rsmall[i] - i)) % MOD;
//    }
//    cout << res << endl;
//    return 0;
//}

////////////////////////////////////////////巫师的能力值总和（单调栈）///////////////////////////////////////

//https://leetcode.cn/problems/sum-of-total-strength-of-wizards/solution/ji-suan-mei-ge-shu-zi-zuo-wei-zui-xiao-z-3jvr/
//给你一个整数数组 strength ，其中 strength[i] 表示第 i 位巫师的力量值。对于连续的一组巫师（也就是这些巫师的力量值是 strength 的 子数组），总力量 定义为以下两个值的 乘积 ：
//·子数组中 最小 的能力值。
//·子数组中所有巫师的个人力量值 之和 。
//请你返回 所有 巫师组的 总 力量之和
//和上面那题一样，先找到每个数字的 ‘管辖范围’，再来计算最终结果
//int main()
//{
//    vector<int> strength = { 1,3,1,2 };
//    int n = strength.size();
//    // 步骤1. 求左侧第一个 严格小于nums[i] 的坐标，和右侧第一个 小于等于nums[i] 的坐标，这是为了防止重复计算子数组
//    stack<int> st;
//    vector<int> left(n, -1), right(n, n);
//    for (int i = 0; i < n; ++i) {
//        while (!st.empty() && strength[st.top()] >= strength[i]) {
//            right[st.top()] = i;
//            st.pop();
//        }
//        if (!st.empty()) {
//            left[i] = st.top();
//        }
//        st.push(i);
//    }
//    //现在我们已经求出了最小值的‘管辖范围’，下一步计算这些子数组前缀和并与最小值相乘，直接想法是在‘管辖范围’内枚举子数组，然后计算，但是这样时间复杂度是O（n2）
//    //所以利用 前缀和 以及 前缀和的前缀和 来计算，参考 https://leetcode.cn/problems/sum-of-total-strength-of-wizards/solution/ji-suan-mei-ge-shu-zi-zuo-wei-zui-xiao-z-3jvr/ 的第二步
//    // 步骤2. 准备前缀和 psum 和 前缀和的前缀和 ppsum
//    vector<int> psum = strength;//注意这里的处理，直接赋值初始化，大小是相同的
//    for (int i = 1; i < n; ++i) {
//        psum[i] = (psum[i] + psum[i - 1]) % MOD;
//    }
//    vector<int> ppsum = psum;
//    for (int i = 1; i < n; ++i) {
//        ppsum[i] = (ppsum[i] + ppsum[i - 1]) % MOD;
//    }
//    auto f = [&](int l, int r) 
//    {//匿名函数用来求 前缀和
//        if (r < 0) 
//            return 0;//注意右边界是可能小于0的，所以直接返回0，代表无效区间前缀和为0
//        if (l < 0) //左边界也可能小于0，，此时只有[0,r]这部分区间有效，所以只计算这部分前缀和 ppsum[r]
//            return ppsum[r];
//        return (ppsum[r] - ppsum[l] + MOD) % MOD;//注意ppsum[r]是取余后的值，所以ppsum[r] - ppsum[l]可能小于0，加上MOD就还原为原本的值，但是当ppsum[r] - ppsum[l]大于0时，加上MOD就可能溢出，所以最终还要取余
//    };
//    // 步骤3. 针对每个 min 值计算结果
//    // 对于 a[i], 其管辖区间为 [left[i] + 1, right[i] - 1]
//    // 问题归结, 将 l = left[i] + 1, r = right[i] - 1 代入上面的式子求解即可
//    int res = 0;
//    for (int i = 0; i < n; ++i) {
//        int l = left[i] + 1, r = right[i] - 1;//这里的l和r都能取到
//        int sleft = 1LL * f(l - 2, i - 1) * (r - i + 1) % MOD;//计算前缀和
//        int sright = 1LL * f(i - 1, r) * (i - l + 1) % MOD;
//        res = (res + 1LL * strength[i] * (((sright - sleft) + MOD) % MOD)) % MOD;//还是刚才那个问题sright和sleft是取余后的，所以要这样处理一下
//    }
//}

////////////////////////////////////////////按顺序砍树的最短路径///////////////////////////////////////

//https://leetcode.cn/problems/cut-off-trees-for-golf-event/solution/by-fuxuemingzhu-dtet/
//typedef pair<int, int> pii;
//class Solution {
//public:
//    int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
//    int m, n;
//    int bfs(int start, int end, vector<vector<int>>& forest)
//    {
//        queue<pii> q;
//        vector<vector<int>> vis(m, vector(n, 0));
//        q.push({ start,0 });
//        vis[start / n][start % n] = 1;
//        while (!q.empty())
//        {
//            auto [pos, dis] = q.front();
//            q.pop();
//            if (pos == end)
//            {
//                return dis;
//            }
//            for (int i = 0;i < 4;i++)
//            {
//                int nx = pos / n + dir[i][0];
//                int ny = pos % n + dir[i][1];
//                if (nx >= 0 && nx < m && ny >= 0 && ny < n && forest[nx][ny] != 0 && vis[nx][ny] == 0)
//                {
//                    q.push({ nx * n + ny,dis + 1 });
//                    vis[nx][ny] = 1;
//                }
//            }
//        }
//        return -1;
//    }
//    int cutOffTree(vector<vector<int>>& forest) {
//        m = forest.size(), n = forest[0].size();
//        if (forest[0][0] == 0)//起始坐标在（0,0）
//        {
//            return -1;
//        }
//        vector<vector<int>> grid;
//        for (int i = 0;i < m;i++)
//        {
//            for (int j = 0;j < n;j++)
//            {
//                if (forest[i][j] > 1)
//                {//必须要从低到高砍树，所以把大于1的树按照从小到大的顺序排列
//                 //1 表示地面，可以行走但不是树
//                    grid.push_back({ forest[i][j],i * n + j });
//                }
//            }
//        }
//        sort(grid.begin(), grid.end());//排序
//        int s = 0;//起始点是（0,0）
//        int sum = 0;//总路径长度
//        for (int i = 0;i < grid.size();i++)
//        {
//            int next = bfs(s, grid[i][1], forest);//用bfs计算从上一棵树到下一课树的最短距离
//            if (next == -1)//-1表示不可达
//            {
//                return -1;//返回-1表示无法砍完所有的树
//            }
//            sum += next;
//            s = grid[i][1];//记录上一棵树
//        }
//        return sum;
//    }
//};
//int main()
//{
//    Solution so;//0表示障碍，不能走，1表示平地，不需要砍树，大于1的全是树的高度
//    vector<vector<int>> forest = { {54, 64, 24, 69}, {86, 61, 68, 79}, { 6, 92, 89, 94}, {83, 22, 46, 47}, {89, 18, 25, 60} };
//    cout << so.cutOffTree(forest) << endl;
//}

////////////////////////////////////////////掉落方块的最大高度///////////////////////////////////////

//https://leetcode.cn/problems/falling-squares/solution/diao-luo-de-fang-kuai-by-leetcode-soluti-2dmw/
//int main()
//{
//    vector<vector<int>> positions = { {2,1},{2,9},{1,8} };//每个方块的左边界和边长
//    int n = positions.size();
//    //*******************************暴力枚举**********************************
//    vector<int> heights(n);
//    for (int i = 0; i < n; i++) 
//    {//对于第 i 个掉落的方块，如果它的底部区间与第 j 个掉落的方块有重叠，那么它掉落后的高度至少为 heights[j] + size_i(第 i 个掉落的方块的边长)
//        int left1 = positions[i][0], right1 = positions[i][0] + positions[i][1] - 1;//第 i 个掉落的方块的左边界和右边界
//        heights[i] = positions[i][1];//对于第 i 个掉落的方块，heights[i] 的初始值为 size_i
//        for (int j = 0; j < i; j++) 
//        {
//            int left2 = positions[j][0], right2 = positions[j][0] + positions[j][1] - 1;//第 j 个掉落的方块的左边界和右边界
//            if (right1 >= left2 && right2 >= left1) 
//            {//如果有重合的部分
//                heights[i] = max(heights[i], heights[j] + positions[i][1]);//注意这里不能用heights[i]代替，因为不同的 j 会更新heights[i]，导致不重合的方块高度仍然累加，就是错误答案
//            }
//        }
//    }
//    for (int i = 1; i < n; i++) 
//    {//因为题目要求返回一个所有已经落稳的方块的最大堆叠高度列表，我们从 i = 1 开始，更新 heights[i] = max(heights[i], heights[i−1])，要么刷新最大高度，要么保持原来的高度
//        heights[i] = max(heights[i], heights[i - 1]);
//    }
//}

////////////////////////////////////////////判断p的子字符串中有多少是环绕字符串“abc...xyzabc...xyz”的字串///////////////////////////////////////

//https://leetcode.cn/problems/unique-substrings-in-wraparound-string/solution/huan-rao-zi-fu-chuan-zhong-wei-yi-de-zi-ndvea/
//对于两个以同一个字符结尾的“连续字符”子串，长的那个子串必然包含短的那个。例如 “abcd” 和 “bcd” 均以‘d’ 结尾，“bcd” 是 “abcd” 的子串。
//据此，我们可以定义 dp[α] 表示 p 中以字符 α 结尾且在 s 中的子串的最长长度，知道了最长长度和结尾字符，也就知道了不同的子串的个数。比如知道了 dp['d']=4，也就知道了p中有子字符串“abcd”，那么
//字串个数就是 4= （‘d’，‘cd’，‘bcd’，‘abcd’），注意是以‘d’结尾的。
//如何计算 dp[α] 呢？我们可以在遍历 p 时，维护连续递增的子串长度 k。具体来说，遍历到 p[i] 时，如果 p[i] 是 p[i - 1] 在字母表中的下一个字母，则将 k 加一，否则将 k 置为 1，
//表示重新开始计算连续递增的子串长度。然后，用 k 更新 dp[p[i]] 的最大值，最后把所有字符结尾的最大长度加起来，就是dp['a']+dp['b']+...+dp['z']。
//int main()
//{
//    string p = "zab";//判断p的子字符串中有多少是环绕字符串“abc...xyzabc...xyz”的字串
//    int res = 0;
//    int cnt[26] = { 0 };//dp数组
//    int n = p.length(), j = 1;//用来纪录长度
//    cnt[p[0] - 'a']++;
//    for (int i = 1; i < n; i++)
//    {
//        int cur = p[i] - 'a', pre = p[i - 1] - 'a';//当前字符和上一个字符
//        if ((cur - pre == -25) || (cur - pre == 1))//能够拼接在一起，注意是循环字符串，所以a可以跟在z后面
//        {
//            j++;
//        }
//        else
//        {
//            j = 1;
//        }
//        cnt[cur] = max(cnt[cur], j);//每个字符都要更新最大长度
//    }
//    for (int i = 0;i < 26; i++)
//    {//计算总和
//        res += cnt[i];
//    }
//    cout << res << endl;
//    return 0;
//}

////////////////////////////////////////////判断是IPv4还是IPv6还是其他///////////////////////////////////////

//string validIPAddress(string queryIP) {
//    int n = queryIP.length();
//    int cnt1 = 0, cnt2 = 0;
//    for (auto ch : queryIP)
//    {
//        if (ch == '.')
//        {
//            cnt1++;
//        }
//        else if (ch == ':')
//        {
//            cnt2++;
//        }
//    }
//    stringstream ss(queryIP);
//    string tmp;
//    vector<string> v;
//    if (cnt1 == 3 && cnt2 == 0)
//    {
//        while (getline(ss, tmp, '.'))
//        {
//            if (tmp[0] == '0' && tmp.length() > 1 || tmp.length() > 3)//IPv4不能包含前导0，并且单个数字长度不能超过3
//            {
//                return "Neither";
//            }
//            int num = 0;
//            for (int i = 0;i < tmp.length();i++)
//            {
//                num = num * 10 + tmp[i] - '0';
//            }
//            if (num < 0 || num>255)
//            {//不能超过255
//                return "Neither";
//            }
//        }
//        if (tmp.length() == 0)
//        {//不能是空数字
//            return "Neither";
//        }
//        return "IPv4";
//    }
//    else if (cnt1 == 0 && cnt2 == 7)
//    {
//        while (getline(ss, tmp, ':'))
//        {
//            if (tmp.length() == 0 || tmp.length() > 4)//IPv6单个字符串长度不能超过4
//            {
//                return "Neither";
//            }
//            for (int i = 0;i < tmp.length();i++)
//            {
//                if (!(tmp[i] >= 'a' && tmp[i] <= 'f' || tmp[i] >= '0' && tmp[i] <= '9' || tmp[i] >= 'A' && tmp[i] <= 'F')) {
//                    return "Neither";
//                }
//            }
//        }
//        return "IPv6";
//    }
//    return "Neither";
//}
//int main()
//{
//    string s = "1.0.1.";
//    cout<< validIPAddress(s);
//}

////////////////////////////////////////////格雷码解码方法///////////////////////////////////////

//https://leetcode.cn/problems/minimum-one-bit-operations-to-make-integers-zero/comments/673644
//一开始不知道格雷码，然后看了以下评论区才知道的。
//这里总结一下这道题怎么解的，代码为什么可以这么写。
//首先要知道什么是格雷码：（https://baike.baidu.com/item/%E6%A0%BC%E9%9B%B7%E7%A0%81/6510858?fr=aladdin）
//在一组数的编码中，若任意两个相邻的代码只有一位二进制数不同，则称这种编码为格雷码（Gray Code），另外由于最大
//数与最小数之间也仅一位数不同，即“首尾相连”，因此又称循环码或反射码。
//这里举个例子就明白了：格雷码相邻两个之间只有一个位不同
//-----------------------------------------------------------------------------------------------------------------------------------
//    十进制数    ：  0   |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  10  |  11  |  12  |  13  |  14  |  15  |
//- ---------------------------------------------------------------------------------------------------------------------------------
//四位自然二进制码： 0000 | 0001 | 0010 | 0011 | 0100 | 0101 | 0110 | 0111 | 1000 | 1001 | 1010 | 1011 | 1100 | 1101 | 1110 | 1111 |
//-----------------------------------------------------------------------------------------------------------------------------------
//  四位典型格雷码： 0000 | 0001 | 0011 | 0010 | 0110 | 0111 | 0101 | 0100 | 1100 | 1101 | 1111 | 1110 | 1010 | 1011 | 1001 | 1000 |
//-----------------------------------------------------------------------------------------------------------------------------------
//格雷码表示方法中：第1个数执行op1得到第二个数，第二个数执行op2得到第三个数，第三个数执行op1得到第四个数，。。。。。。。。（类推）
//更多的关于格雷码的知识，可以看上面的链接，讲的要详细一些。
//这里我们认为输入的 n 的二进制表示是典型格雷码（用 x 表示），
//那么将 n 解码为自然二进制码（用 y 表示），可以明显的观察到，y 对应的十进制数就是 x 变为 0 需要的执行操作的次数。
//例如：
//格雷码：0111 ----> 二进制码：0101 ------>十进制数：5 ----->5 就是格雷码 0111 变为格雷码 0000 需要的操作次数。
//所以我们就需要求格雷码对应的二进制码就可以了，对吧。
//
//格雷码解码：从左边第二位起，将每位与左边一位解码后的值异或，作为该位解码后的值（最左边一位依然不变）。
//这里开始说一下，为什么下面的代码可以表示解码过程。
//例如：设abcd表示四位典型格雷码
//解码结果设为nmxy
//那么根据格雷码解码：
//n = a
//m = b^n = a^b
//x = c^m = c^(a^b) = a^b^c
//y = d^x = d^(c^(a^b)) = a^b^c^d
//所以才有 n>>=1 这个步骤。
//例如：格雷码1110的结果
//n = 1
//m = 1^1 = 0
//x = 1^m = 1^0 = 1
//y = 0^x = 0^1 = 1
//所以解码为二进制数1011------对应十进制数11
//int main()
//{
//    int n = 14;//把当前的n的二进制理解为 格雷码 而不是 自然二进制码，目的是把这个格雷码解码成 自然二进制码
//    int res = 0;//0的格雷码表示为 0000...
//    while (n != 0)
//    {//目的是把格雷码 1110 变成对应的自然二进制码 1011，最后输出 11
//        //和上面提到的一样，从左往右解码，首先最左边保持不变，做法就是 用 res=0 异或 n，这样得到 res = 1110
//        //然后将 n 右移 1 位，n变成 0111，原本的第一位 1 变成第二位，第二位 1 变成第三位，第三位 1 变成第四位
//        //这样它再和 res 异或，此时对于最左边的位来说，它保持不变（因为它和0异或不变），急就是上面提到的 a，对于第二位来说，就是原本的第一位 异或 原本的第二位，就是上面提到的 a^b
//        //对于第三位来说，就是原本的第二位 异或 原本的第三位，就是上面提到的 b^c；对于第四位来说，就是原本的第三位 异或 原本的第四位，就是上面提到的 c^d
//        //然后将 n 右移 1 位，n变成 0011，原本的第一位 1 变成第三位，第二位 1 变成第四位
//        //这样它再和 res 异或，此时对于最左边的两位来说，它们保持不变（因为它们和0异或不变），这就是上面提到的 a 和 a^b 
//        //对于第三位来说，就是原本的第一位 异或 原本的第二位 异或 原本的第三位，就是上面提到的 a^b^c；对于第四位来说，就是原本的第二位 异或 原本的第三位 异或 原本的第四位，就是上面提到的 b^c^d
//        //然后将 n 右移 1 位，n变成 0001，原本的第一位 1 变成第四位
//        //这样它再和 res 异或，此时对于最左边的三位来说，它们保持不变（因为它们和0异或不变），这就是上面提到的 a 和 a^b 和 a^b^c 
//        //对于第四位来说，就是原本的第一位 异或 原本的第二位 异或 原本的第三位 异或 原本的第四位，就是上面提到的 a^b^c^d
//        //然后将 n 右移 1 位，n变成 0000，退出循环，得到最终答案 1011=11；
//        res ^= n;
//        n >>= 1;
//    }
//    cout << res << endl;
//    return 0;
//}

////////////////////////////////////////////外星字典序（拓扑排序）///////////////////////////////////////

//https://leetcode.cn/problems/Jf1JuT/solution/by-ac_oier-4xmv/
//constexpr int N = 26, M = 26 * 26;//有向图最多有26个节点（26个字母），最多可能有26*26条边
//int cnt = 0, idx = 0;//cnt用来记录实际上有多少个字母
//int he[N], ne[M], e[M], vis[26], in[26];//建有向图，vis用来排除重复的字母，in记录每个字母节点的入度
//void add(int a, int b)
//{
//    e[idx] = b;
//    ne[idx] = he[a];
//    he[a] = idx++;
//    in[b]++;//入度加1
//}
//bool build(string& a, string& b)
//{
//    int n = a.length(), m = b.length(), len = min(n, m);//先比较长度相同的部分
//    for (int i = 0;i < len;i++)
//    {
//        if (a[i] != b[i])//如果两个字符不一样，由于a的字典序排在b的字典序之前（题目规定），那么就加一条从a[i]节点到b[i]节点的有向边，返回true，表示这两个字符串已经用过了，开始下一循环
//        {
//            add(a[i] - 'a', b[i] - 'a');
//            return true;
//        }
//    }
//    return n <= m;//否则的话看a的长度是否小于等于b的长度，如果不是，返回false，表示不符合字典序，无法建图，直接返回“”，虽然题目规定符合字典序，但是还是有测试用例是{“abc”，“ab”}。
//}
//string alienOrder(vector<string>& words) {
//    memset(he, -1, sizeof(he));
//    int n = words.size();
//    for (int i = 0;i < n;i++)
//    {
//        for (auto& ch : words[i])
//        {
//            if (vis[ch - 'a'] == 0)
//            {//排除重复节点，计算总节点数
//                cnt++;
//                vis[ch - 'a'] = 1;
//            }
//        }
//        for (int j = 0;j < i;j++)
//        {//比较字典序，如果不符合外星字典序，直接返回“”，符合字典序就在有向图里面加一条新边
//            if (!build(words[j], words[i]))
//            {
//                return "";
//            }
//        }
//    }
//    queue<int> q;
//    for (int i = 0;i < 26;i++)
//    {
//        if (in[i] == 0 && vis[i])
//        {//入度为0并且出现过的字母节点加入队列，因为字典序更小的字母不会有字母指向它
//            q.push(i);
//        }
//    }
//    string res;
//    while (!q.empty())
//    {//BFS拓扑排序标准流程
//        int t = q.front();
//        q.pop();
//        res += t + 'a';
//        for (int i = he[t];i != -1;i = ne[i])
//        {
//            int en = e[i];
//            if (--in[en] == 0)
//            {
//                q.push(en);
//            }
//        }
//    }
//    // cout<<res;
//    return res.length() == cnt ? res : "";//如果结果字符串的长度等于出现过的字符个数，返回res，否则说明存在相互冲突或成环的字典序，返回“”，比如{ "z","x","z" }
//}
//int main()
//{//words里面的字符串已经符合外星字典序了
//    vector<string> words = { "wrt", "wrf", "er", "ett", "rftt" };//返回"wertf"
//    //vector<string> words = { "z","x" };//返回"zx"
//    //vector<string> words = { "z","x","z" };//不存在合法顺序
//    //vector<string> words = { "z","z" };//返回"z"
//    cout << alienOrder(words) << endl;
//}

////////////////////////////////////////////划分为k个相等的子集///////////////////////////////////////

//https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/solution/by-lfool-d9o7/
//以数组为[10,10,10,7,7,7,7,7,7,6,6,6]，分成3部分为例，
//即分成3个桶，每个桶的和为30
//排序后数组为[6,6,6,7,7,7,7,7,7,10,10,10]，需要放在3个桶中，每个桶的和为30
//第一层递归，末尾的10放在第一个桶中
//|   |   |   |   |   |
//|   |	  |   |   |   |
//|   |	  |   |   |   |
//|10 |	  |   |   |   |
// ---	   ---	   ---
//桶1      桶2      桶3
//
//第二层和第三层递归，倒数第二个和倒数第三个10都放在桶1中
//|   |   |   |   |   |
//|10 |	  |   |   |   |
//|10 |	  |   |   |   |
//|10 |	  |   |   |   |
// ---	   ---	   ---
// 桶1     桶2     桶3
//
//第四层递归，倒数第一个7就不能放在桶1中了，因为30+7>30
//所以放在桶2中
//|   |   |   |   |   |
//|10 |	  |   |   |   |
//|10 |	  |   |   |   |
//|10 |	  |7  |   |   |
// ---	   ---	   ---
// 桶1     桶2     桶3
//
//后续直到桶2中放了4个7，
//
//|   |   |7  |   |   |
//|10 |	  |7  |   |   |
//|10 |	  |7  |   |   |
//|10 |	  |7  |   |   |
// ---	   ---	   ---
// 桶1     桶2     桶3
//
//再有7就不能放到桶2中了，因为5*7>30
//后续的2个7和2个6放到了桶3中
//
//|   |   |7  |   |6  |
//|10 |	  |7  |   |6  |
//|10 |	  |7  |   |7  |
//|10 |	  |7  |   |7  |
// ---	   ---	   ---
// 桶1     桶2     桶3
//
//正数第一个6这时没地方放了，因为放到任何一个桶中，都大于30
//这时遍历3个桶，都没法放进去之后，返回false
//
//然后递归返回，
//
//递归返回到正数第二个6，正数第二个6从桶3中出栈，但是没有桶4可以让正数第二个6放进去了，
//for循环直接结束了，同时返回false
//同理，桶3中的元素会依次从桶3中出栈
//
//然后桶2中的栈顶的7，会尝试放到桶3中，再递归下去，（剩余的数组元素为[6,6,6,7,7])
//当然我们知道这种情况也是无解的，
//
//|   |   |   |   |   |
//|10 |	  |7  |   |   |
//|10 |	  |7  |   |   |
//|10 |	  |7  |   |7  |
// ---	   ---	  ---
// 桶1     桶2     桶3
//
//最终桶2中的元素，会全部依次出栈，此时数组中剩余的元素为[6,6,6,7,7,7,7,7,7]
//
//|   |   |   |   |   |
//|10 |	  |   |   |   |
//|10 |	  |   |   |   |
//|10 |	  |   |   |   |
// ---	   ---	   ---
// 桶1     桶2     桶3
//
//如果没有 if (i > 0 && edges[i] == edges[i - 1]) 这行代码,这句剪枝的意思是，如果前一个桶和当前桶中已经放进的数的和相同，
//那么就跳过（当然，第一个桶不跳过）。为啥要跳过，因为不就相当于桶换了顺序装嘛，本质是一样的，都行不通。
//
//我们知道了桶2已经是空了，但是仍然会运行for循环，把倒数第一个位置的7，放到桶3中再次尝试，并继续递归下去
//但是这样其实没有意义，因为桶2和桶3的地位是一样的，他们两个当前的大小是相同的，所以无需放到桶3再去尝试
//这种情况也是无解的，所以可以剪枝
//
//同样，桶1中的栈顶的2个10都会出栈，最终会平均分配到3个桶中，剩余的元素，也都会平均分配到每个桶中
//
//|6  |   |6  |   |6  |
//|7  |	  |7  |   |7  |
//|7  |	  |7  |   |7  |
//|10 |	  |10 |   |10 |
// ---	   ---	   ---
// 桶1     桶2     桶3
//bool dfs(int index, vector<int>& edges, vector<int>& matchsticks, int edgeLength, int k)
//{//回溯+剪枝，时间复杂度k^n(k是子集个数，n是数字个数，相当于n个数，每个数都要选择 k 次，总共选择k^n次）
//    if (index == matchsticks.size())
//        return true;//边界条件，所有数都放完了
//    for (int i = 0;i < k; ++i)//做选择，相当于k个桶
//    {
//        if (edges[i] + matchsticks[index] > edgeLength)
//            continue; //第 i 个子集不能放
//        if (i > 0 && edges[i] == edges[i - 1])
//            continue;//第 i 个子集大小和 第 i-1 个子集大小相等，第 i-1 个子集不可以放则第 i 个子集也不可以放
//        edges[i] += matchsticks[index]; //放在第 i 个子集
//        if (dfs(index + 1, edges, matchsticks, edgeLength, k))
//            return true; //找到了一种合适的方案，直接返回
//        edges[i] -= matchsticks[index]; //否则，不能放在第 i 个子集里，回溯
//    }
//    return false;
//}
//int main()
//{
//    vector<int> nums = { 5,5,5,5,4,4,4,4,3,3,3,3 };
//    int k = 4;
//    int totalLength = accumulate(nums.begin(), nums.end(), 0);
//    if (totalLength % k != 0)
//        return false;
//    int edgeLength = totalLength / k;
//    vector<int> edges(k, 0);
//    sort(nums.begin(), nums.end(), greater<int>());//先放大的数
//    return dfs(0, edges, nums, edgeLength, k);
//}

////////////////////////////////////////////设计文本编辑器///////////////////////////////////////

//https://leetcode.cn/problems/design-a-text-editor/solution/lian-biao-mo-ni-pythonjavacgo-by-endless-egw4/
//class TextEditor {
//    vector<char> left, right;//光标左边和光标右边的字符串
//
//public:
//    TextEditor() {}
//
//    void addText(string text) {
//        left.insert(left.end(), text.begin(), text.end());//在光标处插入和删除都是在left数组中操作
//    }
//
//    int deleteText(int k) {//删除光标左边 k 个字符。返回实际删除的字符数目。
//        int k0 = k;
//        for (; k && !left.empty(); --k)//要删除的字符个数 k大于光标左边的字符个数的话，就只删除左边的所有字符
//            left.pop_back();
//        return k0 - k;//正常的话会删除k个字符，也就是 k-0 个字符
//    }
//
//    string cursorLeft(int k) {//将光标向左移动 k 次。返回移动后光标左边 min(10, len) 个字符，其中 len 是光标左边的字符数目。
//        for (; k && !left.empty(); --k) {//把左边的k个或所有字符移到右边去，注意在这里right的尾部保存的是靠前的字符
//            right.push_back(left.back());
//            left.pop_back();
//        }
//        return string(left.begin() + max((int)left.size() - 10, 0), left.end());//相当于是min（10-10，len-10）
//    }
//
//    string cursorRight(int k) {//将光标向右移动 k 次。返回移动后光标左边 min(10, len) 个字符，其中 len 是光标左边的字符数目。
//        for (; k && !right.empty(); --k) {
//            left.push_back(right.back());
//            right.pop_back();
//        }
//        return string(left.begin() + max((int)left.size() - 10, 0), left.end());
//    }
//};
//int main()
//{
//    TextEditor textEditor;
//    textEditor.addText("leetcode"); // 当前文本为 "leetcode|" 。
//    textEditor.deleteText(4); // 返回 4
//                              // 当前文本为 "leet|" 。
//                              // 删除了 4 个字符。
//    textEditor.addText("practice"); // 当前文本为 "leetpractice|" 。
//    textEditor.cursorRight(3); // 返回 "etpractice"
//                               // 当前文本为 "leetpractice|". 
//                               // 光标无法移动到文本以外，所以无法移动。
//                               // "etpractice" 是光标左边的 10 个字符。
//    textEditor.cursorLeft(8); // 返回 "leet"
//                              // 当前文本为 "leet|practice" 。
//                              // "leet" 是光标左边的 min(10, 4) = 4 个字符。
//    textEditor.deleteText(10); // 返回 4
//                               // 当前文本为 "|practice" 。
//                               // 只有 4 个字符被删除了。
//    textEditor.cursorLeft(2); // 返回 ""
//                              // 当前文本为 "|practice" 。
//                              // 光标无法移动到文本以外，所以无法移动。
//                              // "" 是光标左边的 min(10, 0) = 0 个字符。
//    textEditor.cursorRight(6); // 返回 "practi"
//                               // 当前文本为 "practi|ce" 。
//                               // "practi" 是光标左边的 min(10, 6) = 6 个字符。
//}

////////////////////////////////////////////在多个非重叠矩形中的等概率返回整数点///////////////////////////////////////

//https://leetcode.cn/problems/random-point-in-non-overlapping-rectangles/solution/shui-tang-chou-yang-by-xiaohu9527-7b3d/
//如果分别有三个长方形其包含的点数为[9,12,16], 那么其选中的概率分别应该对应为[9/37, 12/37, 16/37]，其中37为三个长方形所包含点数之和。
//因为总共有37个坐标点，所以我们希望每个坐标点被选中的概率为1/37。因此必须根据每个长方形内所包含的点数来分配概率。
//我们简单的看一下如果以9/37的概率选中第一个长方形会怎么样，第一个长方形中有9个点，因此每个点被选中的概率为1/9, 
//乘以其正方行被选中的概率及1/9 * 9/37刚好为1/37。对于第二个与第三个长方形则是一样的道理
//方法一：水塘抽样
//步骤：
//变量解释：
//index：记录当前被选中的长方形的下标
//cur：记录当前长方形中有多少点
//curSum：记录加上当前的长方形中的点，总共有多少点
//·我们每遍历一个长方形，计算其长方形中有多少点即cur，然后计算总共有多少点及curSum。我们随机的在所有的点中取一个随机数，
//  及rand() % curSum。如果想要公平的选中一个长方形，那么是不是我们选中当前长方形的概率应该为当前点数除以总点数，
//  因此当前长方形被选中的概率应该为cur / curSum.
//·根据以上逻辑，当rand() % curSum < cur的时候，那么说明我们选中了当前的长方形，此时我们及需要更新其被选中的长方形为当前长方形，
//  反正我们不做变动，保留之前被选中的长方形。
//·当以上过程完成后已经有一个长方形被公平的选中，我们随后根据之前步骤拆解中的方法随机返回其长方形中的一个点。
//class Solution {
//public:
//    vector<vector<int>> rect;
//    Solution(vector<vector<int>>& rects) {
//        this->rect = rects;//rects[i] = [ai, bi, xi, yi] 表示 (ai, bi) 是第 i 个矩形的左下角点，(xi, yi) 是第 i 个矩形的右上角点
//    }
//
//    vector<int> pick()
//    {
//        int idx = -1, cur = 0, cursum = 0;//对应上面的变量解释
//        for (int i = 0;i < rect.size();i++)
//        {
//            int x1 = rect[i][0], y1 = rect[i][1], x2 = rect[i][2], y2 = rect[i][3];
//            cur = (x2 - x1 + 1) * (y2 - y1 + 1);//计算当前长方形中的整数点
//            cursum += cur;//计算总共点数
//            if (rand() % cursum < cur)
//            {//选中当前长方形
//                idx = i;
//            }
//        }
//        //返回当前长方形中的任意一点
//        return { rect[idx][0] + rand() % (rect[idx][2] - rect[idx][0] + 1),rect[idx][1] + rand() % (rect[idx][3] - rect[idx][1] + 1) };
//    }
//};
//int main()
//{
//    vector<vector<int>> rects = { {-2, -2, 1, 1},{2, 2, 4, 6} };
//    Solution so(rects);
//    vector<int> res = so.pick();
//    cout << res[0] << ' ' << res[1] << endl;
//    res = so.pick();
//    cout << res[0] << ' ' << res[1] << endl;
//    res = so.pick();
//    cout << res[0] << ' ' << res[1] << endl;
//    res = so.pick();
//    cout << res[0] << ' ' << res[1] << endl;
//    res = so.pick();
//    cout << res[0] << ' ' << res[1] << endl;
//    return 0;
//}

////////////////////////////////////////////730. 统计不同回文子序列///////////////////////////////////////

//https://leetcode.cn/problems/count-different-palindromic-subsequences/solution/tong-ji-bu-tong-hui-wen-zi-xu-lie-by-lee-7slg/
//给定一个字符串 s，返回 s 中不同的非空「回文子序列」个数 。
//通过从 s 中删除 0 个或多个字符来获得子序列。
//int main()
//{
//    string s = "bccb";
//    int n = s.length();
//    //状态 dp(x, i, j) 表示在字符串区间 s[i:j] 中以字符 x 为开头和结尾的不同「回文序列」总数
//    //s[i] 仅包含 'a', 'b', 'c' 或 'd'，所以 x 只有4种可能
//    vector<vector<vector<int>>> dp(4, vector(n, vector(n, 0)));
//    for (int i = 0;i < n;i++)
//    {
//        dp[s[i] - 'a'][i][i] = 1;//任何单个字符都是回文序列
//    }
//    for (int len = 2;len <= n;len++)
//    {//枚举长度
//        for (int i = 0, j = len - 1;j < n;i++, j++)
//        {
//            //枚举子序列起点 i，终点 j
//            for (char c = 'a', k = 0;k < 4;c++, k++)
//            {//枚举子序列开头和结尾的字符 x
//                if (s[j] == c && s[i] == c)
//                {//当s[i] = x 且 s[j] = x 时，那么对于 s[i + 1:j - 1] 中的任意一个「回文序列」在头尾
//                 //加上字符 x 都会生成一个新的以字符 x 为开头结尾的「回文序列」，并加上 xx（去掉中间所有的字符）
//                 //和 x (只保留首部或尾部，注意这里i和j是不相等的，所以和前面单个字符是不一样的状态）
//                 //两个单独的「回文序列」。下式中，由于首尾字符不同的「回文序列」一定互不相同，
//                 //因此可以直接累加，无需考虑去重。
//                    dp[k][i][j] = (2LL + dp[0][i + 1][j - 1] + dp[1][i + 1][j - 1] + dp[2][i + 1][j - 1] + dp[3][i + 1][j - 1]) % MOD;
//                }
//                else if (s[j] == c && s[i] != c)
//                {//当 s[j]=x 且 s[i]!= x 时，那么 dp(x, i, j) 等价于 dp(x,i+1,j)
//                    dp[k][i][j] = dp[k][i + 1][j];
//                }
//                else if (s[j] != c && s[i] == c)
//                {//当 s[j]!=x 且 s[i]= x 时，那么 dp(x, i, j) 等价于 dp(x,i,j-1)
//                    dp[k][i][j] = dp[k][i][j - 1];
//                }
//                else
//                {//当 s[j]!=x 且 s[i]!= x 时，那么 dp(x, i, j) 等价于 dp(x,i+1,j-1)
//                    dp[k][i][j] = dp[k][i + 1][j - 1];
//                }
//            }
//        }
//    }
//    int res = 0;
//    for (int i = 0;i < 4;i++)
//    {//统计最大区间的总方案数即可
//        res = (res + dp[i][0][n - 1]) % MOD;
//    }
//    return res;
//}

////////////////////////////////////////////子数组得分大于k的数组个数///////////////////////////////////////

//https://leetcode.cn/problems/count-subarrays-with-score-less-than-k/solution/by-endlesscheng-b120/1606007
//int main()
//{
//    vector<int> nums({ 2,1,4,3,5 });
//    int k = 10;
//    long long res = 0LL, sum = 0LL;
//    int left = 0, right = 0, n = nums.size();
//    while (right < n)
//    {
//        sum += nums[right];//计算窗口内的数组和
//        while (sum * (right - left + 1) >= k)//如果数组得分大于等于k，弹出左边界，数组和相应减少
//        {
//            sum -= nums[left];
//            left++;
//        }
//        res += right - left + 1;//此时[left,right]这个子数组满足条件，那么这个子数组的所有子数组都满足条件，总共有right-left+1个子数组
//                                //相当于固定子数组右边界为right，不断缩小左边界left得到不同的子数组
//        right++;
//    }
//    cout << res << endl;
//}

////////////////////////////////////////////替换字符后能否得到s的字串///////////////////////////////////////

//https://leetcode.cn/problems/match-substring-after-replacement/
//给你两个字符串 s 和 sub 。同时给你一个二维字符数组 mappings ，其中 mappings[i] = [oldi, newi] 表示你
//可以替换 sub 中任意数目的 oldi 个字符，替换成 newi 。sub 中每个字符 不能 被替换超过一次(不能连续替换同义字符）。
//如果使用 mappings 替换 0 个或者若干个字符，可以将 sub 变成 s 的一个子字符串，请你返回 true，否则返回 false 。
//int main()
//{
//    string s = "fool3e7bar",sub= "leet";
//    vector<vector<char>> mappings = { {'e','3'},{'t','7'},{'t','8'}};
//    unordered_map<char, set<char>> mp;
//    for (int i = 0;i < mappings.size();i++) {
//        char a = mappings[i][0], b = mappings[i][1];
//        mp[a].insert(b);//sub中的旧字符能替换成哪些新字符
//    }
//    int n = s.size(), m = sub.size();
//    for (int i = 0;i + m <= n;i++) 
//    {//遍历s的字串
//        bool ok = true;
//        for (int j = 0;j < m;j++) 
//        {
//            if (s[i + j] != sub[j] && !mp[sub[j]].count(s[i + j]))//如果sub原本没有当前字符并且也无法替换,那么肯定不是我们要找的 
//            {
//                ok = false;
//                break;
//            }
//        }
//        if (ok)//找到了这样的字串，返回true 
//            return true;
//    }
//    return false;
//}

////////////////////////////////////////////从网格最上层到达最下层所花费的最小代价///////////////////////////////////////

//https://leetcode.cn/problems/minimum-path-cost-in-a-grid/solution/by-endlesscheng-lnwn/
//给你一个下标从 0 开始的整数矩阵 grid ，矩阵大小为 m x n ，由从 0 到 m * n - 1 的不同整数组成。
//你可以在此矩阵中，从一个单元格移动到 下一行 的任何其他单元格。如果你位于单元格(x, y) ，
//且满足 x < m - 1 (不是最后一行），你可以移动到(x + 1, 0), (x + 1, 1), ..., (x + 1, n - 1) 中的任何一个单元格。
//注意： 在最后一行中的单元格不能触发移动。
//每次可能的移动都需要付出对应的代价，代价用一个下标从 0 开始的二维数组 moveCost 表示，该数组大小为(m * n) x n ，
//其中 moveCost[i][j] 是从值为 i （注意是值为 i ）的单元格移动到下一行第 j 列单元格的代价。
//从 grid 最后一行的单元格移动的代价可以忽略。
//grid 一条路径的代价是：所有路径经过的单元格的 值之和 加上 所有移动的 代价之和 。从 第一行 任意单元格出发，
//返回到达 最后一行 任意单元格的最小路径代价。
//int main()
//{
//    vector<vector<int>> grid = { {5, 3},{4, 0},{2, 1} }, moveCost = { {9, 8},{1, 5},{10, 12},{18, 6},{2, 4},{14, 3} };
//    int m = grid.size(), n = grid[0].size();
//    vector<int> dp = grid[0];//dp[j]表示到达某一层第 j 列的单元格所花费的最小代价，到达第一层（i=0）只需要花费 单元格 的值
//    for (int i = 1;i < m;i++)
//    {//从第二层开始
//        vector<int> ndp(n, 0x3f3f3f3f);//记录到达这一层各个单元格花费的最小代价
//        for (int j = 0;j < n;j++)
//        {//j表示从上一层的第j列出发
//            for (int k = 0;k < n;k++)
//            {//到达这一层的第 k 列所花费的代价
//                //dp[j]表示到达上一层的第 j 列所花费的最小代价，grid[i][k]代表 单元格 的值，moveCost[grid[i - 1][j]][k]代表上一层第j列到这一层第 k 列移动的代价
//                ndp[k] = min(ndp[k], dp[j] + grid[i][k] + moveCost[grid[i - 1][j]][k]);//计算最小值
//            }
//        }
//        dp = ndp;//这一层统计完毕，赋值给dp，用来统计下一层
//    }
//    return *min_element(dp.begin(), dp.end());//到达最后一层，找出最小值
//}

////////////////////////////////////////////交换首字母后拼接的新字符串有多少个///////////////////////////////////////

//https://leetcode.cn/problems/naming-a-company/solution/by-endlesscheng-ruz8/
//int main()
//{
//    vector<string> ideas = { "coffee","donuts","time","toffee" };
//    unordered_map<string, int> umap;
//    for (auto& idea : ideas)
//    {//按照除去首字母的子串 ideas[i][1:] 分组，记录每组的首字母有哪些，用状态压缩来表示。
//        umap[idea.substr(1)] |= 1 << (idea[0] - 'a');
//    }
//    int cnt[26][26];//定义 cnt[i][j] 表示组中首字母包含 i 但不包含 j 的组的个数，如果遍历后面的组时 遇到一个组不包含 i 但是包含 j
//                    //那么前面组的首字母 i 和后面组的首字母 j 交换以后，就能得到两个新字符串 都 不在 ideas 中，这样算两组答案，因为
//                    //两个新字符串拼接的时候前后顺序可以交换
//    memset(cnt, 0, sizeof(cnt));
//    long long res = 0LL;
//    for (auto& t : umap)
//    {//遍历每一个组
//        for (int i = 0;i < 26;i++)
//        {
//            if ((t.second & (1 << i)) == 0)//当前组的首字母没有 i
//            {
//                for (int j = 0;j < 26;j++)
//                {
//                    if (t.second & (1 << j))//当前组的首字母有 j
//                    {
//                        res += cnt[i][j];//当前组不包含 i 但是包含 j，那么如果前面组包含 i 但不包含 j ，则加到结果中，如果没有就加0
//                                         //前面的组可能有多个组满足 包含 i 但不包含 j ，那么cnt[i][j]大于等于1
//                    }
//                }
//            }
//            else
//            {//当前组的首字母有 i
//                for (int j = 0;j < 26;j++)
//                {
//                    if ((t.second & (1 << j)) == 0)//当前组的首字母没有 j
//                    {
//                        ++cnt[i][j];//记录一下当前组的包含 i 但不包含 j的情况，留给后续组来考虑
//                                    //为什么不会漏掉之后的互补项？后面枚举到那个互补项的时候，自然就加上去了。
//                    }
//                }
//            }
//        }
//    }
//    cout << res * 2 << endl;//前后顺序可以交换
//    return 0;
//}

////////////////////////////////////////////719. 找出第 K 小的数对距离///////////////////////////////////////

//https://leetcode.cn/problems/find-k-th-smallest-pair-distance/solution/zhao-chu-di-k-xiao-de-shu-dui-ju-chi-by-xwfgf/
//int main()
//{
//    vector<int> nums = { 9,10,7,10,6,1,5,4,9,8 };
//    int k = 18;
//    sort(nums.begin(), nums.end());
//    int n = nums.size();
//    int left = 0, right = nums.back() - nums.front();//最小差值是0，最大差值为 尾-首
//    int ans = 0;
//    while (left <= right)
//    {//二分
//        int mid = (right + left) / 2;//设想一个差值
//        int cnt = 0;//记录比这个差值小的差值有多少个，如果大于等于k，说明真正的差值小于或等于设想的差值，否则应当大于
//                    //因为设想的差值越大，比这个差值小的差值就越多。
//        for (int j = 0;j < n;j++)
//        {//计算比设想差值小的差值有多少个，nums是排好序的，如果固定右边界 nums[j]，就能找到一个左边界 nums[i]
//            //使得 nums[j]-nums[i]小于等于设想差值，这样，nums[j]-nums[i]，nums[j]-nums[i+1]，nums[j]-nums[i+2]...
//            //nums[j]-nums[j-1]都小于等于设想差值，总共有 j-1-i+1=j-i个，因此对每一个 nums[j] 累加 j-i，就是比设想差值小的差值个数
//            int i = lower_bound(nums.begin(), nums.begin() + j, nums[j] - mid) - nums.begin();
//            cnt += j - i;
//        }
//        //这里也可以用双指针
//        /*for (int i = 0, j = 0; j < n; j++) 
//        {//初始左端点 i = 0，我们从小到大枚举所有数对的右端点 j，移动左端点直到 nums[j]−nums[i]≤mid，
//            //那么右端点为 j 且距离小于等于 mid 的数对数目为 j - i，计算这些数目之和。
//            while (nums[j] - nums[i] > mid) 
//            {
//                i++;
//            }
//            cnt += j - i;
//        }*/
//        if (cnt >= k)
//        {//如果大于等于k，说明真正的差值小于或等于设想的差值，mid有可能是答案，先记录一下在缩小范围继续查找
//            //这样也能保证 ans 一定存在于 nums 中
//            ans = mid;
//            right = mid - 1;
//        }
//        else
//        {//否则，设想差值应该更大一点
//            left = mid + 1;
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}

////////////////////////////////////////////剑指 Offer II 029. 排序的循环链表///////////////////////////////////////

//https://leetcode.cn/problems/4ueAj6/solution/by-ac_oier-kqv3/
//class Node {
//public:
//    int val;
//    Node* next;
//
//    Node() {}
//
//    Node(int _val) {
//        val = _val;
//        next = NULL;
//    }
//
//    Node(int _val, Node* _next) {
//        val = _val;
//        next = _next;
//    }
//};
//class Solution {
//public:
//    Node* insert(Node* head, int insertVal) {
//        Node* res = head;//记录原本的头结点
//        if (head == NULL)
//        {
//            Node* node = new Node(insertVal);
//            node->next = node;//循环链表，只有一个元素也要循环
//            return node;
//        }
//        int axm = head->val, inm = head->val;//记录循环链表中的最大值和最小值
//        while (head->next != res)
//        {
//            head = head->next;
//            axm = max(axm, head->val);
//            inm = min(inm, head->val);
//        }
//        if (inm == axm)
//        {//最大值和最小值相等，说明只有一个元素（有很多节点，但这些节点值都相同，视为只有一个元素），那么随便在哪插入都可以
//            //这里插入到头节点的下一个位置,这样方便返回
//            Node* node = new Node(insertVal);
//            node->next = res->next;
//            res->next = node;
//        }
//        else
//        {//否则说明有多个元素
//            while (head->val <= head->next->val)
//            {//找到有序列表的结束点（结束点的定义为：当前节点值为最大值，下一节点值为最小值。即为有序链表分割位置的左端点)
//                head = head->next;
//            }
//            cout << head->val;//此时的head是最大值节点
//            if (insertVal >= axm || insertVal <= inm)
//            {//大于最大值或小于最小值，都应该插入到最大值节点的下一位置
//                Node* node = new Node(insertVal);
//                node->next = head->next;
//                head->next = node;
//            }
//            else
//            {
//                while (!(head->val <= insertVal && head->next->val > insertVal))
//                {//否则找到他应该插入的位置，该位置前一节点小于等于它，后一位置大于它
//                    head = head->next;
//                }
//                Node* node = new Node(insertVal);
//                node->next = head->next;
//                head->next = node;
//            }
//        }
//        return res;//res是原本的头结点
//    }
//};
//int main()
//{
//    Node* one = new Node(1);
//    Node* two = new Node(4,one);
//    Node* thr= new Node(3, two);
//    one->next = thr;
//    Solution so;
//    so.insert(thr, 0);
//}

//////////////////////////////////////////// 构造range模块（有序集合、线段树）///////////////////////////////////////

//https://leetcode.cn/problems/range-module/solution/by-ac_oier-i4sw/
//*****************************************线段树（超时，因为new内存很耗时）*****************************************
//class RangeModule {
//public:
//    const int N = 1e9;
//    struct secTree
//    {
//        int sum, add;
//        secTree* left, * right;
//    };
//    secTree* root = new secTree();
//    void pushdown(secTree* node, int start, int end)
//    {
//        if (node->left == nullptr)
//        {
//            node->left = new secTree();
//        }
//        if (node->right == nullptr)
//        {
//            node->right = new secTree();
//        }
//        if (node->add == 0)
//        {
//            return;
//        }
//        int mid = (end + start) / 2;
//        if (node->add == 1)
//        {
//            node->left->sum = (mid - start + 1);
//            node->right->sum = (end - mid);
//        }
//        else
//        {
//            node->left->sum = 0;
//            node->right->sum = 0;
//        }
//        node->left->add = node->add;
//        node->right->add = node->add;
//        node->add = 0;
//    }
//    void setvalue(secTree* node, int start, int end, int left, int right, int val)
//    {
//        if (left <= start && right >= end)
//        {
//            if (val == 1)
//            {
//                node->sum = (end-start + 1);
//            }
//            else
//            {
//                node->sum = 0;
//            }
//            node->add = val;
//            return;
//        }
//        pushdown(node, start, end);
//        int mid = (end + start) / 2;
//        if (left <= mid)
//        {
//            setvalue(node->left, start, mid, left, right, val);
//        }
//        if (right > mid)
//        {
//            setvalue(node->right, mid + 1, end, left, right, val);
//        }
//        node->sum = node->left->sum + node->right->sum;
//        return;
//    }
//    int query(secTree* node, int start, int end, int left, int right)
//    {
//        if (left <= start && right >= end)
//        {
//            return node->sum;
//        }
//        pushdown(node, start, end);
//        int ans = 0;
//        int mid = (end + start) / 2;
//        if (left <= mid)
//        {
//            ans += query(node->left, start, mid, left, right);
//        }
//        if (right > mid)
//        {
//            ans += query(node->right, mid+1, end, left, right);
//        }
//        return ans;
//    }
//    RangeModule() {
//
//    }
//
//    void addRange(int left, int right) {
//        setvalue(root, 0, N, left, right-1, 1);
//    }
//
//    bool queryRange(int left, int right) {
//        int cnt = query(root, 0, N, left, right-1);
//        if (cnt == right - left)
//        {
//            return true;
//        }
//        return false;
//    }
//
//    void removeRange(int left, int right) {
//        setvalue(root, 0, N, left, right-1, -1);
//    }
//};
//*****************************************有序集合*****************************************
//https://leetcode.cn/problems/range-module/solution/range-mo-kuai-by-leetcode-solution-4utf/
//class RangeModule {
//public:
//    RangeModule() {}
//
//    void addRange(int left, int right) {
//        auto it = intervals.upper_bound(left);//找到左端点大于left的区间 it
//        if (it != intervals.begin()) {
//            auto start = prev(it);//看it前一个区间能不能和[left,right]合并
//            if (start->second >= right) {//前一个区间完全包含[left,right]，那么不需要再更新，直接返回
//                return;//因为start.first<=left,start->second >= right
//            }
//            if (start->second >= left) {//否则当前一区间右端点>=left的时候，说明可以合并
//                left = start->first;//此时左端点已经确定了，就是前一区间的 左端点
//                intervals.erase(start);//此时还不能直接插入，因为还不确定右端点，先擦除前一区间
//            }
//        }
//        while (it != intervals.end() && it->first <= right) {//如果 right 大于等于 区间的左端点，说明可以合并
//            right = max(right, it->second);//取最大的right
//            it = intervals.erase(it);//erase擦除当前迭代器，并返回被擦除迭代器的下一个迭代器
//        }
//        intervals[left] = right;//插入区间
//    }
//
//    bool queryRange(int left, int right) {
//        auto it = intervals.upper_bound(left);//找到左端点大于left的区间 it
//        if (it == intervals.begin()) {//最小的区间左端点大于left，那么[left,right)肯定无法全部包含，至少left这个端点不包含
//            return false;
//        }
//        it = prev(it);//否则找到前一个区间，其左端点小于等于 left
//        return right <= it->second;//如果 right小于等于前一个区间的右端点，那么[left,right)全部被包含了，返回true
//    }
//
//    void removeRange(int left, int right) {
//        auto it = intervals.upper_bound(left);//找到左端点大于left的区间 it
//        if (it != intervals.begin()) {
//            auto start = prev(it);//看it前一个区间能不能和[left,right]合并
//            if (start->second >= right) {//前一个区间完全包含[left,right)
//                int ri = start->second;//记录一下前一个区间的右端点
//                if (start->first == left) {//如果前一个区间的左端点与left相等，说明这两个区间左端点重合，注意此时前一个区间的右端点 ri>=right
//                                            //因此，如果right != ri，那么我们删除前一个区间，并且保留一下剩余的区间 [right,ri)，就是下面的if
//                    intervals.erase(start);
//                }
//                else {//否则的话 [start->first,left) 也是保留的区间
//                    start->second = left;
//                }
//                if (right != ri) {//然后在考察右边是不是也有保留区间，如果right != ri，那么 [right,ri) 也是保留的区间
//                    intervals[right] = ri;
//                }
//                return;//此时已经删除完成了，直接返回
//            }
//            else if (start->second > left) {//否则当前一个区间的右端点大于 left 的时候，那么有一段保留区间为 [start->first,left)
//                start->second = left;
//            }
//        }
//        while (it != intervals.end() && it->first < right) {//考察右端点与其他区间的保留关系
//            if (it->second <= right) {//这个条件说明遍历到的区间完全包含在[left,right)里面，直接删除，往后查找
//                it = intervals.erase(it);
//            }
//            else {
//                intervals[right] = it->second;//否则保留区间 [right,ri)
//                intervals.erase(it);//删除原区间
//                break;//后面的区间没有重叠范围了，不需要遍历
//            }
//        }
//    }
//
//private:
//    map<int, int> intervals;//<区间左端点，区间右端点>
//};
//int main()
//{
//    RangeModule rangeModule;
//    rangeModule.addRange(10, 20);
//    rangeModule.removeRange(14, 16);
//    rangeModule.queryRange(10, 14); //返回 true （区间[10, 14) 中的每个数都正在被跟踪）
//    rangeModule.queryRange(13, 15); //返回 false（未跟踪区间[13, 15) 中像 14, 14.03, 14.17 这样的数字）
//    rangeModule.queryRange(16, 17); //返回 true （尽管执行了删除操作，区间[16, 17) 中的数字 16 仍然会被跟踪）
//}

//////////////////////////////////////////// 个位数字为 K ，和为num的整数集合最少的元素个数///////////////////////////////////////

//https://leetcode.cn/problems/sum-of-numbers-with-units-digit-k/solution/mei-ju-da-an-by-endlesscheng-zh75/
//假设最终的集合有 n 个数，都是以 k 结尾的，那么这些数 个位数 之和为 n*k，如果这些数之和为 num
//那么 num-n*k 就表示这些数除开个位以外的和，那么一定是 10 的倍数，也就是 (num - n * k) % 10=0
//int main()
//{
//    int num = 58, k = 9;
//    if (num == 0)
//    {//num=10需要特判
//        return 0;
//    }
//    for (int n = 1; n <= num && num - n * k >= 0; n++)
//    {//n最大值是num，并且num - n * k 需要大于等于0
//        if ((num - n * k) % 10 == 0)
//        {
//            return n;
//        }
//    }
//    return -1;
//}

//////////////////////////////////////////// 高 m 宽 n 的木块切割后最多能卖多少钱 ///////////////////////////////////////

//https://leetcode.cn/problems/selling-pieces-of-wood/solution/by-endlesscheng-mrmd/
//int main()
//{
//    int m = 3, n = 5;
//    vector<vector<int>> prices = { {1, 4, 2},{2, 2, 7},{2, 1, 3} };
//    vector<vector<long long>> dp(m + 1, vector<long long>(n + 1,0LL));//定义 dp[i][j] 表示对一块高 i 宽 j 的木块，切割后能得到的最多钱数。
//    for (auto& v : prices)
//    {//初始化，高v[0]宽v[1]的木块能卖v[2] 块钱，其他的都是 0
//        dp[v[0]][v[1]] = v[2];
//    }
//    for (int i = 1;i <= m;i++)
//    {
//        for (int j = 1;j <= n;j++)
//        {//最开始的dp[i][j]记录的是高 i 宽 j 的木块整块（不切割）卖多少钱
//            for (int k = 1;k <= i;k++)
//            {//横着切成 高 k 宽 j 的小木块 和高 i-k 宽 j 的小木块，更新最大钱数
//                dp[i][j] = max(dp[i][j], dp[k][j] + dp[i - k][j]);
//            }
//            for (int k = 1;k <= j;k++)
//            {//竖着切成 高 i 宽 k 的小木块 和高 i 宽 j-k 的小木块，更新最大钱数
//                dp[i][j] = max(dp[i][j], dp[i][k] + dp[i][j - k]);
//            }
//        }
//    }
//    cout << dp[m][n] << endl;
//    return 0;
//}

//////////////////////////////////////////// 白名单里的随机数 ///////////////////////////////////////

//https://leetcode.cn/problems/random-pick-with-blacklist/solution/hei-ming-dan-zhong-de-sui-ji-shu-by-leet-cyrx/1625225
//给定一个整数 n 和一个 无重复 黑名单整数数组 blacklist 。设计一种算法，
//从[0, n - 1] 范围内的任意整数中选取一个 未加入 黑名单 blacklist 的整数。
//任何在上述范围内且不在黑名单 blacklist 中的整数都应该有 同等的可能性 被返回。
 //按官方给的思路，逻辑上构思一个[0,n)的整型数组，而我们把随机边界 bound 就设为 n - m, m是黑名单的长度
 //也就是我们逻辑上认为 [0,n) 的所有整数中，所有的黑名单数都在 [bound,n)这个区间里
 //这样我们只需要在 [0,bound) 上随机一次，就能得到一个可取随机白名单数
 //那实际上不可能刚好黑名单数就全出现在最后
 //所以我们要是可以把在 bound 前边出现的黑名单数，都一一映射到后边的非黑名单数的话，那就相当于实现了这样的效果了
//class Solution {
//public:
//    unordered_map<int, int> umap;//存放 bound 前面的黑名单数到 bound 后面的黑名单数的映射
//    unordered_set<int> black;//存放所有的黑名单数
//    int bound;//随机边界，即构思的 [0,n) 整型数组，前边全是白名单，后边全是黑名单数，它是分界线
//    Solution(int n, vector<int>& blacklist) {
//        int m = blacklist.size();
//        bound = n - m;//设置边界为 n-m
//        for (auto& i : blacklist)
//        {
//            black.insert(i);
//        }
//        int tmp = bound;//用来构造映射，tmp在 bound 后面寻找可用的白名单数,bound属于黑名单列表
//        for (auto& i : blacklist)
//        {
//            if (i < bound)
//            {//如果 bound 前面存在 黑名单数
//                while (black.find(tmp) != black.end())
//                {//找到 bound 后面（包括bound）的白名单数，如果 tmp 是一个黑名单数，说明它不可用，递增
//                    ++tmp;
//                }
//                umap[i] = tmp++;//退出循环时 tmp是一个可用的白名单数，做一个映射，然后将tmp递增，表明它不可用了
//            }
//        }
//    }
//
//    int pick() {
//        int k = rand() % bound;//在 bound 里随机一个数
//        if (black.find(k) != black.end())
//        {//如果是 黑名单数，那么返回它在bound后面的白名单数映射
//            return umap[k];
//        }
//        return k;//否则直接返回
//    }
//};
//int main()
//{
//    vector<int> blacklist = { 2, 3, 5 };
//    Solution solution(7, blacklist);
//    solution.pick(); // 返回0，任何[0,1,4,6]的整数都可以。注意，对于每一个pick的调用，
//                     // 0、1、4和6的返回概率必须相等(即概率为1/4)。
//    solution.pick(); // 返回 4
//    solution.pick(); // 返回 1
//    solution.pick(); // 返回 6
//    solution.pick(); // 返回 1
//    solution.pick(); // 返回 0
//    solution.pick(); // 返回 4
//}

//////////////////////////////////////////// 所有串联所有单词的子串起始位置 ///////////////////////////////////////

//https://leetcode.cn/problems/substring-with-concatenation-of-all-words/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-6/191275
//给定一个字符串 s 和一些 长度相同 的单词 words 。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
//注意子串要与 words 中的单词完全匹配，中间不能有其他字符 ，但不需要考虑 words 中单词串联的顺序。
//int main()
//{
//    string s = "wordgoodgoodgoodbestword";
//    vector<string> words = { "word","good","best","good" };
//    unordered_map<string, int> wordmap, smap;
//    for (auto& word : words)
//    {
//        wordmap[word]++;
//    }
//    int wordlen = words[0].size();
//    int wordnum = words.size();
//    vector<int> ans;
//    for (int k = 0;k < wordlen;k++) {
//        int i = k, j = k;
//        while (i +  wordnum * wordlen <= s.size()) {//左边界
//            while (j < i + wordnum * wordlen) {//右边界
//                string temp = s.substr(j, wordlen);
//                smap[temp]++;
//                j += wordlen;
//                if (wordmap[temp] == 0) {//情况二，有words中不存在的单词
//                    i = j;//对i加速，直接跳到 j 开头的单词
//                    smap.clear();
//                    break;
//                }
//                else if (smap[temp] > wordmap[temp]) 
//                {//情况三，子串中temp数量超了
//                    while (smap[temp] > wordmap[temp]) 
//                    {//窗口内某个单词的数量超了，不断缩小左边界，直到多的那个单词被排除
//                        smap[s.substr(i, wordlen)]--;
//                        i += wordlen;//对i加速
//                    }
//                }
//            }
//            //正确匹配，由于情况二和三都对i加速了，不可能满足此条件
//            if (j == i + wordlen * wordnum) {//此时窗口内拥有的单词和个数都满足要求，缩小左边界，开始下一循环
//                ans.push_back(i);
//                smap[s.substr(i, wordlen)]--;
//                i += wordlen;//i正常前进
//            }
//        }
//        smap.clear();//下一个循环的哈希表要清空
//    }
//    for (auto i : ans)
//    {
//        cout << i << endl;
//    }
//}

//////////////////////////////////////////// 6106. 统计无向图中无法互相到达点对数 ///////////////////////////////////////

//https://leetcode.cn/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/solution/wei-yun-suan-tong-ji-ge-wei-shang-1shi-f-qc1h/
//int N;
//int fa[100005];//记录每个星球的“帮主”，也就是每个集合里面的代表元素
//unordered_map<int, int> umap;//记录每个帮派里有多少人
//int findset(int x)
//{//找到每个星球属于哪个“帮派”，返回它的“帮主”
//    if (fa[x] == x)
//        return x;
//    return fa[x] = findset(fa[x]);//x可能只知道它的“上级”是谁，不知道“帮主”是谁，因此找到帮主之后要告诉每一个成员，就必须赋值
//}
//void merge(int x, int y)
//{//合并两个“帮派”，fx是一号帮派的帮主，fy是二号帮派的帮主，现在统一为一个帮派，fy为帮主
//    int fx = findset(x), fy = findset(y);
//    if (fx != fy) {
//        fa[fx] = fy;
//        umap[fy] += umap[fx];
//        umap[fx] = 0;
//    }
//}
//void init()
//{//并查集初始化，最开始，所有大侠各自为战。他们各自的帮主自然就是自己。
//    for (int i = 0;i < N;i++) {
//        fa[i] = i;
//        umap[i] = 1;
//    }
//}
//int main()
//{
//    vector<vector<int>> edges = { {0, 2},{0, 5},{2, 4},{1, 6},{5, 4} };
//    int n = 7;//一共有n个点
//    long long res = 0LL;
//    N = n;
//    init();
//    for (auto& v : edges)
//    {
//        merge(v[0], v[1]);//并查集
//    }
//    vector<int> tmp;
//    for (auto it : umap)
//    {
//        if (it.second > 0)
//        {
//            tmp.push_back(it.second);
//        }
//    }
//    int k = tmp.size();//tmp里面的元素记录的是每个独立的帮派里有多少人，他们之间相互都到达不了
//    vector<long long> presum(k);
//    presum[0] = tmp[0];
//    for (int i = 1;i < k;++i)
//    {
//        res += presum[i - 1] * tmp[i];//利用前缀和计算不可到达点对的数量
//        presum[i] = presum[i - 1] + tmp[i];//计算前缀和
//    }
//    cout << res << endl;
//}

//////////////////////////////////////////// 2318. 不同骰子序列的个数 ///////////////////////////////////////

//https://leetcode.cn/problems/number-of-distinct-roll-sequences/solution/by-endlesscheng-tgkn/
////vector<vector<vector<int>>> dp(10005, vector<vector<int>>(6, vector<int>(6, 0)));
// int dp[10005][6][6];//这里最好用数组，因为初始化很快，而vector初始化很慢
//void init()
//{
//    for (int i = 0;i < 6;++i)
//    {
//        for (int j = 0;j < 6;++j)
//        {
//            dp[2][i][j] = i != j && gcd(i + 1, j + 1) == 1;
//        }
//    }
//    for (int i = 2;i < 10004;++i)
//    {
//        for (int cur = 0;cur < 6;++cur)
//        {
//            for (int j = 0;j < 6;++j)
//            {
//                if (cur != j && gcd(cur + 1, j + 1) == 1)
//                {
//                    for (int pre = 0;pre < 6;++pre)
//                    {
//                        if (pre != j)
//                        {
//                            dp[i + 1][j][cur] = (dp[i + 1][j][cur] + dp[i][cur][pre]) % MOD;
//                        }
//                    }
//                }
//            }
//        }
//    }
//}
//int main()
//{
//    int n = 2;
//    int res = 0;
//    if (n == 1)
//    {
//        return 6;
//    }
//    init();//每次都要初始化重新计算dp（虽然每次计算都一样），因为LeetCode只会创建一个对象然后不断调用成员去测试，如果能够在创建对象之前就计算出dp
//           //那么就不需要这里初始化，参考 https://leetcode.cn/problems/number-of-distinct-roll-sequences/solution/by-endlesscheng-tgkn/
//           //正是因为这里每次初始化，所以上面要用数组而不是vector。
//    for (int i = 0;i < 6;++i)
//    {
//        for (int j = 0;j < 6;++j)
//        {
//            res = (res + dp[n][i][j]) % MOD;
//        }
//    }
//    cout<<res;
//}

//////////////////////////////////////////// 2320. 统计放置房子的方案数///////////////////////////////////////

//https://leetcode.cn/problems/count-number-of-ways-to-place-houses/solution/d-by-endlesscheng-gybx/
//一条街道上共有 n * 2 个 地块 ，街道的两侧各有 n 个地块。每一边的地块都按从 1 到 n 编号。每个地块上都可以放置一所房子。
//现要求街道同一侧不能存在两所房子相邻的情况，请你计算并返回放置房屋的方式数目
//如果一所房子放置在这条街某一侧上的第 i 个地块，不影响在另一侧的第 i 个地块放置房子。
//int main()
//{
//    int n = 5;
//    vector<vector<long long>> dp(n + 1, vector(2, 0LL));//dp[i][0]表示第 i 个位置不放房子的方案数，dp[i][1]表示第 i 个位置放房子的方案数
//    dp[1][0] = 1;//第一个位置 放不放 房子的方案数都是 1
//    dp[1][1] = 1;
//    for (int i = 2;i <= n;i++)
//    {
//        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;//第 i 个位置不放房子，那么第 i-1 个位置可以放也可以不放，求和
//        dp[i][1] = dp[i - 1][0];//第 i 个位置放房子，那么第 i-1 个位置 不能 放房子，
//    }
//    //街道两侧放多少房子的方案互不影响，相乘，因为某一侧任何一种方案，另一侧有 dp[n][0]+dp[n][1] 种方案
//    return ((dp[n][0] + dp[n][1]) % MOD * (dp[n][0] + dp[n][1]) % MOD) % MOD;
//}

//////////////////////////////////////////// 2321. 交换子数组后的最大分数///////////////////////////////////////

//https://leetcode.cn/problems/maximum-score-of-spliced-array/solution/by-endlesscheng-fm8l/
//给你两个下标从 0 开始的整数数组 nums1 和 nums2 ，长度都是 n 。
//你可以选择两个整数 left 和 right ，其中 0 <= left <= right < n ，接着 交换 两个子数组 nums1[left...right] 和 nums2[left...right] 。
//例如，设 nums1 = [1, 2, 3, 4, 5] 和 nums2 = [11, 12, 13, 14, 15] ，整数选择 left = 1 和 right = 2，
//那么 nums1 会变为[1, 12, 13, 4, 5] 而 nums2 会变为[11, 2, 3, 14, 15] 。
//你可以选择执行上述操作 一次 或不执行任何操作。
//数组的 分数 取 sum(nums1) 和 sum(nums2) 中的最大值，其中 sum(arr) 是数组 arr 中所有元素之和。返回 可能的最大分数 。
//
//求子数组和的最大值
//int solve(vector<int>& nums1, vector<int>& nums2) {
//    int s1 = 0, s = 0, maxSum = 0;//s1表示nums1的总和，s表示遍历过程中的子数组和，maxsum表示子数组和的最大值
//    for (int i = 0; i < nums1.size(); ++i) {
//        s1 += nums1[i];
//        s = max(s + nums2[i] - nums1[i], nums2[i] - nums1[i]);//这里的数组其实是 nums1和 nums2的差数组，只不过没有显式表达出来
//                                                              //对于 diff[i]=nums2[i] - nums1[i]而言 选不选他取决于是否能增大子数组和
//        maxSum = max(maxSum, s);//记录最大值
//    }
//    return s1 + maxSum;//返回总和加上差值数组的子数组和最大值
//}
//int main()
//{
//    vector<int> nums1 = { 60,60,60 }, vector<int> nums2 = { 10,90,10 };
//    cout << max(solve(nums1, nums2), solve(nums2, nums1)) << endl;//记录两个数组交换能取得的最大值
//}

//////////////////////////////////////////// 2322. 从树中删除两条边的最小分数///////////////////////////////////////

//https://leetcode.cn/problems/minimum-score-after-removals-on-a-tree/solution/dfs-shi-jian-chuo-chu-li-shu-shang-wen-t-x1kk/
//删除树中两条 不同 的边以形成三个连通组件。对于一种删除边方案，定义如下步骤以计算其分数：
//·分别获取三个联通块 每个 组件中所有节点值的异或值。
//·最大 异或值和 最小 异或值的 差值 就是这一种删除边方案的分数。
//例如，三个组件的节点值分别是：[4, 5, 7]、[1, 9] 和[3, 3, 3] 。三个异或值分别是 4 ^ 5 ^ 7 = 6、1 ^ 9 = 8 和 3 ^ 3 ^ 3 = 3 。
//最大异或值是 8 ，最小异或值是 3 ，分数是 8 - 3 = 5 。
//返回在给定树上执行任意删除边方案可能的 最小 分数。
//int main()
//{
//    vector<int> nums = { 1,5,5,4,11 };//n个节点
//    vector <vector<int>> edges = { {0,1},{1,2},{1,3},{3,4 } };//n-1条边
//    int n = nums.size();
//    vector<vector<int>> g(n);
//    for (auto& e : edges) {
//        int x = e[0], y = e[1];
//        g[x].push_back(y);//无向图
//        g[y].push_back(x);
//    }
//    vector<int> xr(n), in(n), out(n);//xr[x]记录以 x 为根节点的树的异或值，in[x]记录进入节点 x 时的时间戳，
//                                    //out[x]记录离开节点 x 时（x的邻居节点全都访问完成）的时间戳
//    int clock = 0;//时间戳
//    function<void(int, int)> dfs = [&](int x, int fa) //function 是标准库提供的函数指针，这里的意思是dfs这个函数指针指向一个匿名函数
//    {//要记录一下从哪个节点进入 x 节点的，避免重复访问
//        in[x] = ++clock;//进入该节点 x 的时间
//        xr[x] = nums[x];//以 x 为根的树的异或值，此时还没有访问子树，所以初始化为本身
//        for (int y : g[x])
//        {//访问每个邻居节点
//            if (y != fa) 
//            {
//                dfs(y, x);//dfs
//                xr[x] ^= xr[y];//执行到这一步时，以 y 为根节点的树异或值已经算出来了，因为 x 是 y的父节点，所以要更新 xr[x]，每访问一个 x 的邻居节点都要更新
//            }
//        }
//        out[x] = clock;//x的邻居节点访问完毕，离开 x 节点
//    };
//    dfs(0, -1);//以 0 为根节点开始访问
//
//    int ans = INT_MAX;//要记录砍掉两条边之后形成的三个联通块的异或值，其中的最大值和最小值的差的最小值，只能遍历所有边，选两条砍掉，暴力计算
//    for (int i = 2, x, y, z; i < n; ++i)
//    {//枚举不是根的两个点，删除这两个点及其父节点形成的边，就相当于我们枚举的是 y1 和 y2，而删除的 y1和父节点x1 的边和 y2父节点x2 的边
//        for (int j = 1; j < i; ++j) 
//        {
//            if (in[i] < in[j] && in[j] <= out[i])
//            {// 如果 i 是 j 的祖先节点，那么一定先进入 i 在进入 j，则 in[i] < in[j]，而离开 i 和 j的时间可能相同，如果 j 是 i 的最后一个邻居节点
//                //那么 退出 j的时间和退出 i 的时间是相同的，因为 退出j 后没有访问新的节点，clock没有改变，而 i 的邻居节点也访问完了，直接退出
//                //这时候他们两个 退出的时间就相同
//                x = xr[j], y = xr[i] ^ xr[j], z = xr[0] ^ xr[i];
//            }
//            else if (in[j] < in[i] && in[i] <= out[j])
//            {// j 是 i 的祖先节点，同理
//                x = xr[i], y = xr[j] ^ xr[i], z = xr[0] ^ xr[j];
//            }
//            else 
//                x = xr[i], y = xr[j], z = xr[0] ^ x ^ y; // 删除的两条边分别属于两颗不相交的子树
//            ans = min(ans, max(max(x, y), z) - min(min(x, y), z));//记录差的最小值
//            if (ans == 0) return 0; // 提前退出，0一定是最小的
//        }
//    }
//        
//    cout << ans << endl;
//}

//////////////////////////////////////////// 535. TinyURL 的加密与解密///////////////////////////////////////

//https://leetcode.cn/problems/encode-and-decode-tinyurl/solution/by-ac_oier-ca6o/
//class Solution
//{
//public:
//    Solution() {}
//    // Encodes a URL to a shortened URL.
//    string encode(string longUrl)
//    {
//        while (!origin2Tiny.count(longUrl)) {//如果传入两个相同的 长URL，将会返回相同的短 URL
//            string cs;
//            for (int i = 0; i < k; i++)
//            {//k为随机码
//                cs += str[rand() % str.size()];
//            }
//            string cur = prefix + cs;//组合成 短URL
//            if (tiny2Origin.count(cur))
//            {//如果这个短 URL 已经存在了，那么重新生成
//                continue;
//            }
//            tiny2Origin[cur] = longUrl;//记录一下
//            origin2Tiny[longUrl] = cur;
//        }
//        return origin2Tiny[longUrl];
//    }
//
//    // Decodes a shortened URL to its original URL.
//    string decode(string shortUrl)
//    {
//        return tiny2Origin[shortUrl];
//    }
//
//private:
//    unordered_map<string, string> origin2Tiny, tiny2Origin;
//    string str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
//    string prefix = "https://acoier.com/tags/";//前缀
//    int k = 6;
//};
//int main()
//{
//    Solution so;
//    so.encode("https://leetcode.com/problems/design-tinyurl");
//}

//////////////////////////////////////////// 522. 最长特殊序列 II///////////////////////////////////////

//https://leetcode.cn/problems/longest-uncommon-subsequence-ii/solution/zui-chang-te-shu-xu-lie-ii-by-leetcode-s-bo2e/
//特殊序列 定义如下：该序列为某字符串 独有 的子序列（即不能是其他字符串的子序列）。
//对于给定的某个字符串 str[i]，如果它的一个子序列 sub 是「特殊序列」，那么 str[i] 本身也是一个「特殊序列」。
//这是因为如果 sub 如果没有在除了 str[i] 之外的字符串中以子序列的形式出现过，那么给 sub 不断地添加字符，它也不会出现。
//而 str[i] 就是 sub 添加若干个（可以为零个）字符得到的结果。
//因此我们只需要使用一个双重循环，外层枚举每一个字符串 str[i] 作为特殊序列，内层枚举每一个字符串 str[j](i ！= j)，
//判断 str[i] 是否不为 str[j] 的子序列即可。
//int main()
//{
//    vector<string> strs = { "aba","cdc","eae" };
//    auto is_subseq = [](const string& s, const string& t)
//    {//双指针来判断s是否是t的子序列
//        int pt_s = 0, pt_t = 0;
//        while (pt_s < s.size() && pt_t < t.size()) {
//            if (s[pt_s] == t[pt_t]) {
//                ++pt_s;
//            }
//            ++pt_t;
//        }
//        return pt_s == s.size();//返回true表示 s 是 t 的子序列
//    };
//
//    int n = strs.size();
//    int ans = -1;
//    for (int i = 0; i < n; ++i) {
//        if ((int)strs[i].length() <= ans)
//        {
//            continue;
//        }
//        bool check = true;
//        for (int j = 0; j < n; ++j) {
//            if (i != j && is_subseq(strs[i], strs[j])) {//如果发现了 strs[j] 包含 strs[i]子序列，说明 strs[i] 不是特殊序列，判断下一个 str[i]
//                check = false;
//                break;
//            }
//        }
//        if (check) {
//            ans = max(ans, (int)strs[i].size());
//        }
//    }
//    cout << ans << endl;
//}

//////////////////////////////////////////// 324. 摆动排序 II///////////////////////////////////////

//https://leetcode.cn/problems/wiggle-sort-ii/solution/yi-bu-yi-bu-jiang-shi-jian-fu-za-du-cong-onlognjia/
//int main()
//{
//    vector<int> nums = { 1,5,1,1,6,4 };
//    auto midptr = nums.begin() + nums.size() / 2;//中位数的位置
//    nth_element(nums.begin(), midptr, nums.end());//把正确的中位数放在正确的位置上，左边都是不大于中位数的数，右边都是不小于中位数的数
//    int mid = *midptr;//中位数
//
//    // 3-way-partition，三分法，把数组分为 小于target，等于target，大于target三个部分
//    int i = 0, j = 0, k = nums.size() - 1;//[0,i）表示小于target的部分，[i,j)表示等于target的部分，[k,n - 1)表示大于target的部分
//    while (j < k) //i表示的是小于target的数应该放的位置，k表示的是大于target的数应该放的位置
//    {
//        if (nums[j] > mid) {//大于target，应该放在 k 的位置
//            swap(nums[j], nums[k]);//交换 j和 k，原来nums[k]的数现在保存在 nums[j]里
//            --k;//k的位置已经放置了正确的数，递减 k，注意这里没有对 j 操作，因为不知道现在的 nums[j]（也就是原来的nums[k]）的大小关系
//        }
//        else if (nums[j] < mid) {//小于target，应该放在 i 的位置
//            swap(nums[j], nums[i]);//交换 i和 j，原来nums[i]的数现在保存在 nums[j]里
//            ++i;//i的位置已经放置了正确的数，递增 i
//            ++j;//注意未递增的 nums[i]一定是小于等于target的，那么下一轮不需要判断 现在的 nums[j]（也就是原来的nums[i]）的大小关系
//                //直接递增
//        }
//        else {//等于target，不需要更改位置，直接遍历下一个数
//            ++j;
//        }
//    }
//
//    if (nums.size() % 2) ++midptr;//如果总共有 奇数个数，中位数的位置往后移一位
//    vector<int> tmp1(nums.begin(), midptr);//记录前半部分数组和后半部分数组
//    vector<int> tmp2(midptr, nums.end());
//    for (int i = 0; i < tmp1.size(); ++i) {//插入值，小的这部分要反向插入，即先插入序列末尾的
//        nums[2 * i] = tmp1[tmp1.size() - 1 - i];
//    }
//    for (int i = 0; i < tmp2.size(); ++i) {//大的这部分也要反向插入，即先插入序列末尾的
//        nums[2 * i + 1] = tmp2[tmp2.size() - 1 - i];
//    }
//    for (const auto& i : nums)
//    {
//        cout << i << ' ';
//    }
//}

//////////////////////////////////////////// 241. 为运算表达式设计优先级///////////////////////////////////////

//https://leetcode.cn/problems/different-ways-to-add-parentheses/solution/pythongolang-fen-zhi-suan-fa-by-jalan/
//vector<int> diffWaysToCompute(string input) {
//    vector<int> vec1, vec2, res;
//    int n = input.size();
//    int flag = 0;
//    for (int i = 0; i < n; i++) 
//    {//对于每个运算符进行枚举，以它为分界线分隔左右两部分，分别得到左边的结果集和右边的结果集
//        //结果集的每个元素代表在不同位置加上括号（优先算某个算式）的结果
//        //比如2*3-4*5，对于第一个 * 而言，左边结果集只有{ 2 }，右边结果集有{-5，-17}，其中-5表示（3-4）*5的结果，-17表示3-（4*5）的结果
//        //这样，用2*-5表示（2*（（3-4）*5）的结果，用2*-17表示（2*（3-（4*5）），枚举其他两个运算符，得到不同的结果，最终得到结果集，返回上一层
//        //其实可以优化一下，以map来保存字符串到结果集的映射，下一次直接用
//        if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
//            flag = 1; // flag=1说明string是表达式，flag=0说明string是一个数字
//            vec1 = diffWaysToCompute(string(input, 0, i)); // 从第0个开始，存i个字符
//            vec2 = diffWaysToCompute(string(input, i + 1, n - i - 1));
//            for (int v1 : vec1) {
//                for (int v2 : vec2) {
//                    if (input[i] == '+') 
//                        res.push_back(v1 + v2);
//                    else if (input[i] == '-') 
//                        res.push_back(v1 - v2);
//                    else if (input[i] == '*') 
//                        res.push_back(v1 * v2);
//                }
//            }
//        }
//    }
//    if (flag == 0) //说明整个字符串没有运算符，只有数字，转变成int返回，注意要构造vector
//        return { stoi(input) };
//    return res;
//}
//int main()
//{
//    string expression = "2*3-4*5";
//    vector<int> res=diffWaysToCompute(expression);
//    ostream_iterator<int> os(cout," ");
//    copy(res.begin(), res.end(), os);
//}

////////////////////////////////////////////6110. 网格图中递增路径的数目///////////////////////////////////////

//https://leetcode.cn/problems/number-of-increasing-paths-in-a-grid/solution/ji-yi-hua-sou-suo-pythonjavacgo-by-endle-xecc/
//class Solution {
//public:
//    int n, m, ans = 0;
//    vector<vector<int>> f;//记录以grid[i][j]结尾的严格递增的路径个数
//    int dir[4][2] = { {1,0},{0,-1},{0,1},{-1,0} };
//    int dfs(int x, int y, vector<vector<int> >& g) {
//        if (f[x][y])//如果以grid[x][y]结尾的严格递增的路径个数之前已经算过了，直接返回
//            return f[x][y];
//        f[x][y] = 1;//本身可以单独作为 1 条只有一个格子的路径
//        for (auto& d : dir) 
//        {
//            int tx = x + d[0], ty = y + d[1];
//            if (tx >= 0 && tx < n && ty >= 0 && ty<m && g[tx][ty]<g[x][y])//格子存在并且比当前值严格小，说明可以构成严格递增路径
//                f[x][y] = (f[x][y] + dfs(tx, ty,g)) % MOD;//递归累加
//        }
//        return f[x][y];//返回
//    }
//    int countPaths(vector<vector<int>>& g) {
//        if (g.empty() || g[0].empty())
//            return 0;
//        n = g.size(), m = g[0].size();
//        f.resize(n, vector<int>(m));
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {//分别计算以每个格子结尾的严格递增路径的个数，累加
//                ans = (ans + dfs(i, j,g)) % MOD;
//            }
//        }
//        return ans;
//    }
//};
//int main()
//{
//    Solution so;
//    vector<vector<int>> g = { {1,1,1},{1,1,1},{1,1,1} };
//    cout << so.countPaths(g) << endl;
//}


////////////////////////////////////////////871. 最低加油次数///////////////////////////////////////

//https://leetcode.cn/problems/minimum-number-of-refueling-stops/solution/by-ac_oier-q2mk/
//-将路上的一个个加油站 视为 一桶桶的油，每次经过的时候，就把油带上放后备箱；
//- 当油不够的时候，取出后备箱所带的 最多的那桶油 加进油箱
//- 这样以来，如若油箱和后备箱的油加起来都不够，那么就到不了了
//int main()
//{
//    int target = 100, startFuel = 10;
//    vector<vector<int>> stations = { {10, 60},{20, 30},{30, 30},{60, 40} };
//    int n = stations.size();
//    int pos = 0, idx = 0, curFuel = startFuel;//pos表示当前位置，idx表示当前哪些加油站的油已经带上了，curFuel表示当前的油量
//    int res = 0;
//    priority_queue<int> priq;// 使用优先队列，承装所经过加油站的油
//    while (pos < target)
//    {//只要还没到目的地就一直循环
//        if (curFuel == 0)
//        {//油用光了，从后备箱里加油，意味着我们需要在相应的加油站停留
//            if (!priq.empty())
//            {//后备箱非空，才能加油
//                curFuel += priq.top();//先加一个最多的，不够的话再加后续的
//                priq.pop();//加过的不能再加了
//                res++;//加油意味着我们需要在相应的加油站停留，但不需要知道是哪个加油站
//            }
//            else
//            {//后备箱是空的话那就无法到达终点了
//                cout << -1 << endl;
//                return 0;
//            }
//        }
//        pos += curFuel;//用当前油量直接跑到最远的位置
//        curFuel = 0;//油用光了
//        while (idx < n && pos >= stations[idx][0])
//        {//跑到最远位置的过程中遇到哪些加油站，都把他们装到后备箱里
//            priq.push(stations[idx][1]);
//            idx++;
//        }
//    }
//    cout << res << endl;
//    return 0;
//}

////////////////////////////////////////////6109. 知道秘密的人数///////////////////////////////////////

//https://leetcode.cn/problems/number-of-people-aware-of-a-secret/solution/by-endlesscheng-2x0z/
//在第 1 天，有一个人发现了一个秘密。
//给你一个整数 delay ，表示每个人会在发现秘密后的 delay 天之后，每天 给一个新的人 分享 秘密。
//同时给你一个整数 forget ，表示每个人在发现秘密 forget 天之后会 忘记 这个秘密。一个人 不能 在忘记秘密那一天及之后的日子里分享秘密。
//有两类人：
//A 类：知道秘密，但还不能分享；
//B 类：知道秘密，且可以分享。
//int main()
//{
//    int n = 5, delay = 2, forget = 4;
//    int cnt_a = 0;//记录到第n天时的A类人
//    vector<int> dp(n,0);//表示第 i 天的 A 类人数。
//    dp[0] = 1;//第1天只有1个人知道秘密但不能分享
//    for (int i = 0; i < n; ++i) 
//    {//从第 i 天开始考虑，把天数在区间 [i+delay,i+forget-1] 的 A 类人数都加上 f[i]，因为这dp[i]个A类人会在这些天开始传播秘密，刚好传播给dp[i]个人
//        //也就是对于第 j 天来说，新增了dp[i]个A类人，但是这仅仅是对那些可以从A类人转变成B类人来说的，对于某些A类人，他们在第n天都无法传播这些秘密
//        //因为要单独记录一下这些人的人数，他们没有算在dp[n-1]里面，所以最后要加上cnt_a
//        if (i + delay >= n)//无法转变成B类人
//            cnt_a = (cnt_a + dp[i]) % MOD;
//        for (int j = i + delay; j < min(i + forget, n); ++j)
//            dp[j] = (dp[j] + dp[i]) % MOD;
//    }
//    return (cnt_a + dp[n - 1]) % MOD;
//}

/////////////////////////////////////////// 乌鸦喝水 ///////////////////////////////////////

//class Solution {
//public:
//    int drink(int* s, int sLen, int x, int y) {
//        // write code here
//        int left = 0, right = 0;
//        int sum = 0;
//        int min_l = sLen, res = 0;
//        for (;left < sLen;++left)
//        {
//            while (right < sLen && sum < x)
//            {
//                sum += min(s[right], y);
//                ++right;
//            }
//            if (right - left-1 < min_l && sum>=x)
//            {
//                res = left;
//                min_l = right - left -1;
//            }
//            sum -= min(s[left], y);
//        }
//        return res;
//    }
//};
//int main()
//{
//    Solution so;
//    int a[] = { 3, 2, 0, 3, 4 };
//    int x = 5, y = 2;
//    int s = 5;
//    so.drink(a,s,x,y);
//}

////////////////////////////////////////////2332. 坐上公交的最晚时间///////////////////////////////////////

//https://leetcode.cn/problems/the-latest-time-to-catch-a-bus/solution/pai-xu-by-endlesscheng-h9w9/
//int main()
//{
//    vector<int> buses = { 10, 20 }, passengers = { 2, 17, 18, 19 };
//    int capacity = 2;
//    sort(buses.begin(), buses.end());
//    sort(passengers.begin(), passengers.end());
//    int j = 0, c= capacity;//j表示乘客的下标，c是每辆车的容量，每次都重置为capacity
//    for (int t : buses)//对于每辆车而言
//    {
//        for (c = capacity; c && j < passengers.size() && passengers[j] <= t;)
//        {//如果车上还有位置，并且乘客到达的时间早于车到达的时间，容量减1，乘客减1
//            ++j; 
//            --c;
//        }
//    }      
//    /*模拟结束后：
//    如果最后一班公交还有空位，我们可以在发车时到达公交站，如果此刻有人，我们可以顺着他往前找到没人到达的时刻；
//    如果最后一班公交没有空位，我们可以找到上一个上车的乘客，顺着他往前找到一个没人到达的时刻。*/
//    --j;//上面循环结束时的j时晚于最后一辆车到达时间的乘客位置，而j-1是早于最后一辆车的最后一个乘客下标，我们要赶在他之前到才能坐上车
//    int ans = c ? buses.back() : passengers[j]; // 在发车时到达公交站 or 上一个上车的乘客
//    while (j >= 0 && passengers[j] == ans)
//    {
//        --ans; // 往前找没人到达的时刻
//        j--;
//    }
//    cout << ans;
//}

////////////////////////////////////////////2333. 最小差值平方和///////////////////////////////////////

//https://leetcode.cn/problems/minimum-sum-of-squared-difference/solution/javascript-6118-zui-xiao-chai-zhi-ping-f-pp7t/
//要求最终差值平方和最小，那肯定是尽可能减小最大的差值。
//先遍历一次数组，计算出所有差值的绝对值（用 arr 数组存储，arr[i] 表示差值为 i + 1 出现的次数），
//然后从大到小尝试降低。将 k 消耗完之后，计算一下平方和就是结果了。
//int main()
//{
//    vector<int> nums1 = { 1, 4, 10, 12 }, nums2 = { 5, 8, 6, 9 };
//    int k1 = 1, k2 = 1;
//    vector<int> vec(1e5 + 1, 0);// vec[i] 表示差值为 i + 1 出现的次数,用哈希表也可以，不过要用map，因为要排序
//    int n = nums1.size();
//    for (int i = 0; i < n; i++) 
//        vec[abs(nums1[i] - nums2[i])]++;//记录差值次数
//    int k = k1 + k2;//总的操作次数
//    for (int i = vec.size() - 1; k > 0 && i > 0; i--) //从最大值开始缩减
//    {
//        if (vec[i] == 0)
//        {//没有出现过这个差值，跳过
//            continue;
//        }
//        int change = min(k, vec[i]);//如果k大于vec[i]，说明可以把所有出现的 i 都减1，缩小成 i-1，那么change就是vec[i]
//                                    //则 i-1的个数vec[i-1]应当加上 vec[i]
//                                    //反之，如果vec[i]大于k，说明不能把所有出现的 i 都缩小成 i-1，那么只能对 k 个 i缩小
//                                    //则 i-1的个数vec[i-1]应当加上 k
//                                    
//        vec[i] -= change;
//        vec[i - 1] += change;
//        k -= change;//减去相应的操作次数，等于0就退出循环
//    }
//    long long ans = 0;
//    for (long long i = 0; i < vec.size(); i++) {
//        if (vec[i] != 0) {
//            ans += i * i * vec[i];//计算平方和
//        }
//    }
//    cout << ans;
//}

////////////////////////////////////////////907. 子数组的最小值之和///////////////////////////////////////

//https://leetcode.cn/problems/sum-of-subarray-minimums/solution/dan-diao-zhan-zuo-you-liang-bian-di-yi-g-ww3n/
//int main()
//{
//    vector<int> arr = { 1, 3, 4, 3, 1 };
//    int threshold = 6;
//    stack<int> st;//通过单调栈来求
//    int n = arr.size();
//    vector<int> lsmall(n, -1), rsmall(n, n);//每个数字左边界和右边界，默认是-1和n
//    for (int i = 0; i < n; ++i)
//    {
//        while (!st.empty() && arr[st.top()] >= arr[i])
//        {//如果这里是>=，说明我们找的左边界是严格小于arr[i]的，因为对于nums[i]来说，栈里面存放的是它左边的值，只有当栈顶的值严格小于arr[i]的时候才退出循环
//            //而我们找的右边界是小于等于arr[i]的，因为对于栈里面的值来说，arr[i]是它右边的值，当右边的值小于等于栈顶的时候，我们就认为找到了右边界，并记录下来
//            //如果这里是>，说明我们找的左边界是小于等于arr[i]的，因为对于nums[i]来说，栈里面存放的是它左边的值，只有当栈顶的值小于等于arr[i]的时候才退出循环
//            //而我们找的右边界是严格小于arr[i]的，因为对于栈里面的值来说，arr[i]是它右边的值，当右边的值严格小于栈顶的时候，我们就认为找到了右边界，并记录下来
//            //这么做的目的是为了防止某些子数组被重复计算，注意不管是严格小于还是小于等于，lsmall[i]和rsmall[i]都是左右边界，都无法取到，所以left=lsmall[i]，right=small[i]。
//            rsmall[st.top()] = i;
//            st.pop();
//        }
//        if (!st.empty())
//        {
//            lsmall[i] = st.top();
//        }
//        st.push(i);
//    }
//    for (int i = 0; i < n; i++)
//    {
//        int k = rsmall[i] - lsmall[i] - 1;//arr[i]充当最小值的区间元素个数
//        if (arr[i] > threshold / k)//这个区间里最小值都大于threshold / k，那么其他值一定满足，这样就找到了满足条件的区间
//        {
//            cout << k;
//            return 0;
//        }
//    }
//    cout << -1;
//    return 0;
//}

////////////////////////////////////////////729. 我的日程安排表 I///////////////////////////////////////

//https://leetcode.cn/problems/my-calendar-i/solution/wo-de-ri-cheng-an-pai-biao-i-by-leetcode-nlxr/
//日程可以用一对整数 start 和 end 表示，这里的时间是半开区间，即[start, end), 
//实数 x 的范围为，  start <= x < end
//class MyCalendar {
//    set<pair<int, int>> booked;//[start，end）
//public:
//    bool book(int start, int end) {
//        auto it = booked.lower_bound({ end, 0 });//找到左端点大于等于end的第一个区间
//        if (it == booked.begin() || (--it)->second <= start) 
//        {//最开始的区间或者是前一个区间右端点小于等于start，说明没有重叠部分
//            booked.emplace(start, end);
//            return true;
//        }
//        return false;
//    }
//};
//int main()
//{
//    MyCalendar myCalendar;
//    myCalendar.book(10, 20); // return True
//    myCalendar.book(15, 25); // return False ，这个日程安排不能添加到日历中，因为时间 15 已经被另一个日程安排预订了。
//    myCalendar.book(20, 30); // return True ，这个日程安排可以添加到日历中，因为第一个日程安排预订的每个时间都小于 20 ，且不包含时间 20 。
//}

////////////////////////////////////////////731. 我的日程安排表 II///////////////////////////////////////

//https://leetcode.cn/problems/my-calendar-ii/solution/wo-de-ri-cheng-an-pai-biao-ii-by-leetcod-wo6n/
//class MyCalendarTwo {
//public:
//    MyCalendarTwo() {
//
//    }
//
//    bool book(int start, int end) {
//        for (auto& [l, r] : overlaps) {
//            if (l < end && start < r) {//说明有重叠部分，这样就产生了三重预定
//                return false;
//            }
//        }
//        for (auto& [l, r] : booked) {
//            if (l < end && start < r) {//说明有重叠部分，这样就产生了双重预定
//                overlaps.emplace_back(max(l, start), min(r, end));//把重叠部分加入overlap
//            }
//        }
//        booked.emplace_back(start, end);//重叠部分已经记录过了，直接插入
//        return true;
//    }
//private:
//    vector<pair<int, int>> booked;
//    vector<pair<int, int>> overlaps;
//};
//int main()
//{
//    MyCalendarTwo myCalendar;
//    myCalendar.book(10, 20); // returns true,无重叠，正常添加
//    myCalendar.book(50, 60); // returns true,无重叠，正常添加
//    myCalendar.book(10, 40); // returns true，会导致[10,20)双重预订，但可以添加至日历中。
//    myCalendar.book(5, 15); // returns false,不能添加至日历中，因为它会导致[10,15)三重预订。
//    myCalendar.book(5, 10); // returns true,可以添加至日历中，因为它未使用已经双重预订的时间10。
//    myCalendar.book(25, 55); // returns true,可以添加至日历中，因为时间[25, 40] 将和第三个日程安排双重预订；
//                             // 时间[40, 50] 将单独预订，时间[50, 55）将和第二个日程安排双重预订。
//}

////////////////////////////////////////////732. 我的日程安排表 III///////////////////////////////////////

//https://leetcode.cn/problems/my-calendar-iii/solution/by-ac_oier-ioyt/
//class MyCalendarThree {
//public:
//    int N = (int)1e9;//最大范围
//    struct Node
//    {
//        Node* left, * right;//左右孩子节点
//        int val, add;//区间最大值，懒标记
//    };
//    Node* root = new Node();
//    void pushdown(Node* node)
//    {//动态开点
//        if (node->left == nullptr)
//        {
//            node->left = new Node();
//        }
//        if (node->right == nullptr)
//        {
//            node->right = new Node();
//        }
//        if (node->add == 0)
//        {//懒标记为0，没有必要下推
//            return;
//        }
//        node->left->val += node->add;
//        node->left->add += node->add;
//        node->right->val += node->add;
//        node->right->add += node->add;
//        node->add = 0;
//    }
//    void update(Node* node, int lc, int rc, int l, int r, int v)
//    {
//        if (l <= lc && r >= rc)
//        {//lc，rc是node表示的区间范围
//            node->val += v;//区间最大值+v
//            node->add += v;//懒标记+v，以后用到的时候再往下移
//            return;
//        }
//        pushdown(node);//上面没有返回的话说明区间没有完全包含，下移懒标记
//        int mid = (rc + lc) / 2;
//        if (l <= mid)
//        {//左右区间分别更新
//            update(node->left, lc, mid, l, r, v);
//        }
//        if (r > mid)
//        {
//            update(node->right, mid + 1, rc, l, r, v);
//        }
//        node->val = max(node->left->val, node->right->val);//更新父节点
//        return;
//    }
//    int query(Node* node, int lc, int rc, int l, int r)
//    {
//        if (l <= lc && r >= rc)
//        {
//            return node->val;//返回最大值
//        }
//        pushdown(node);
//        int mid = (rc + lc) / 2, ans = 0;
//        if (l <= mid)
//        {
//            ans = query(node->left, lc, mid, l, r);
//        }
//        if (r > mid)
//        {
//            ans = max(ans, query(node->right, mid + 1, rc, l, r));
//        }
//        return ans;
//    }
//    MyCalendarThree() {
//
//    }
//
//    int book(int start, int end) {
//        update(root, 0, N, start, end-1, 1);
//        return query(root, 0, N, 0, N);
//    }
//};
//int main()
//{
//    MyCalendarThree myCalendarThree;
//    myCalendarThree.book(10, 20); // 返回 1 ，第一个日程安排可以预订并且不存在相交，所以最大 k 次预订是 1 次预订。
//    myCalendarThree.book(50, 60); // 返回 1 ，第二个日程安排可以预订并且不存在相交，所以最大 k 次预订是 1 次预订。
//    myCalendarThree.book(10, 40); // 返回 2 ，第三个日程安排 [10, 40) 与第一个日程安排相交，所以最大 k 次预订是 2 次预订。
//    myCalendarThree.book(5, 15); // 返回 3 ，剩下的日程安排的最大 k 次预订是 3 次预订。
//    myCalendarThree.book(5, 10); // 返回 3
//    myCalendarThree.book(25, 55); // 返回 3
//}

////////////////////////////////////////////736. Lisp 语法解析///////////////////////////////////////

//https://leetcode.cn/problems/parse-lisp-expression/solution/lisp-yu-fa-jie-xi-by-leetcode-solution-zycb/
//class Solution {
//private:
//    unordered_map<string, vector<int>> scope;//记录变量的值
//
//public:
//    int evaluate(string expression) {
//        int start = 0;//当前遍历到了哪个字符
//        return innerEvaluate(expression, start);
//    }
//
//    int innerEvaluate(const string& expression, int& start) {
//        if (expression[start] != '(') { // 非Lisp表达式，可能为：整数或变量，因为Lisp表达式都是以（ 开头的
//            if (islower(expression[start])) {
//                string var = parseVar(expression, start); // 变量
//                return scope[var].back();//变量的最内层作用域的值
//            }
//            else { // 整数
//                return parseInt(expression, start);
//            }
//        }
//        //否则就是Lisp表达式，开始解析
//        int ret;
//        start++; // 移除左括号
//        if (expression[start] == 'l') { // "let" 表达式
//            start += 4; // 移除 "let "，注意有空格
//            vector<string> vars;//临时记录这一层作用域内所有变量的名字
//            while (true) {
//                if (!islower(expression[start])) 
//                {//let表达式最后一个expr有三种形式：变量、数字、Lisp表达式
//                    //·如果是数字并且是变量的值的话，他是直接在解析完变量之后就直接解析出来的，不会进入这里的循环
//                    //  所以这里出现数字一定是最后一个expr，可以直接在这一层解析，也可以在下一层解析
//                    //·如果是Lisp表达式的话，需要在进一步解析，所以为了统一，就直接下一层解析
//                    ret = innerEvaluate(expression, start); // let 表达式的最后一个 expr 表达式的值
//                    break;//已经解析出了最后一个expr的值，跳出循环，返回
//                }
//                string var = parseVar(expression, start);
//                // ·如果是变量的话，他后面一定是‘）’，所以找到该变量最内层作用域的值，返回
//                if (expression[start] == ')') {
//                    ret = scope[var].back(); // let 表达式的最后一个 expr 表达式的值
//                    break;
//                }
//                //否则的话，说明还不到最后一个expr，是正常的变量赋值阶段
//                vars.push_back(var);//记录变量
//                start++; // 移除空格
//                int e = innerEvaluate(expression, start);//变量的值也有可能是Lisp表达式
//                scope[var].push_back(e);//记录同一变量不同作用域的值，以此插入
//                start++; // 移除空格
//            }
//            for (auto var : vars) {
//                scope[var].pop_back(); // 清除当前作用域的变量，因为要返回上一层了，不可能再用内层作用域的值
//            }
//        }
//        else if (expression[start] == 'a') { // "add" 表达式
//            start += 4; // 移除 "add "
//            int e1 = innerEvaluate(expression, start);
//            start++; // 移除空格
//            int e2 = innerEvaluate(expression, start);
//            ret = e1 + e2;
//        }
//        else { // "mult" 表达式
//            start += 5; // 移除 "mult "
//            int e1 = innerEvaluate(expression, start);
//            start++; // 移除空格
//            int e2 = innerEvaluate(expression, start);
//            ret = e1 * e2;
//        }
//        start++; // 移除右括号
//        return ret;
//    }
//
//    int parseInt(const string& expression, int& start) { // 解析整数
//        int n = expression.size();
//        int ret = 0, sign = 1;
//        if (expression[start] == '-') {
//            sign = -1;
//            start++;
//        }
//        while (start < n && isdigit(expression[start])) {
//            ret = ret * 10 + (expression[start] - '0');
//            start++;
//        }
//        return sign * ret;
//    }
//
//    string parseVar(const string& expression, int& start) { // 解析变量
//        int n = expression.size();
//        string ret;
//        while (start < n && expression[start] != ' ' && expression[start] != ')') {
//            ret.push_back(expression[start]);
//            start++;
//        }
//        return ret;
//    }
//};
//int main()
//{
//    string expression = "(let x 2 (mult x (let x 3 y 4 (add x y))))";
//    Solution so;
//    cout<<so.evaluate(expression);
//}

////////////////////////////////////////////648. 单词替换///////////////////////////////////////

//https://leetcode.cn/problems/replace-words/solution/by-ac_oier-jecf/
//struct TrieNode
//{
//    bool end;
//    TrieNode* child[26];
//};//前缀树节点
//TrieNode* root = new TrieNode();
//void insert(string s)
//{//插入
//    TrieNode* node = root;
//    for (int i = 0; i < s.size(); ++i)
//    {
//        if (node->child[s[i] - 'a'] == nullptr)
//        {
//            node->child[s[i] - 'a'] = new TrieNode();
//        }
//        node = node->child[s[i] - 'a'];
//    }
//    node->end = true;
//}
//int search(string s)
//{
//    TrieNode* node = root;
//    for (int i = 0; i < s.size(); ++i)
//    {
//        if (node->child[s[i] - 'a'] == nullptr)
//        {//不存在直接返回-1，表示当前的单词 s 所有前缀都不在前缀树中，因此无法替换
//            return -1;
//        }
//        else if (node->child[s[i] - 'a']->end == true)
//        {//找到了一个前缀，返回前缀的长度
//            return i;
//        }
//        node = node->child[s[i] - 'a'];
//    }
//    return -1;//上面没有返回的话说明当前的单词 s 是比前缀更短的单词，因此不可能替换
//}
//int main()
//{
//    vector<string> dictionary = { "cat","bat","rat" };
//    string sentence = "the cattle was rattled by the battery";
//    stringstream ss(sentence);
//    string word, res;
//    for (auto& s : dictionary)
//    {
//        insert(s);//插入前缀
//    }
//    while (getline(ss, word, ' '))
//    {
//        int k = search(word);
//        if (k != -1)
//        {
//            word = word.substr(0, k + 1);//替换
//        }
//        res += word + ' ';
//    }
//    res.pop_back();//弹出最后一个空格
//    cout<<res;
//}

/////////////////////////////////////////873. 最长的斐波那契子序列的长度//////////////////////////////////////////

//https://leetcode.cn/problems/length-of-longest-fibonacci-subsequence/solution/zui-chang-de-fei-bo-na-qi-zi-xu-lie-de-c-8trz/
//int main()
//{
//    vector<int> arr = { 1,2,3,4,5,6,7,8 };
//    unordered_map<int, int> umap;//记录前面遍历过的数组，就像两数之和那样
//    int n = arr.size();
//    vector<vector<int>> dp(n, vector<int>(n));//dp[i][j]表示以arr[i]为最后一位数字
//                                              //arr[j]为倒数第二位的斐波那契数列的最大长度
//    int res = 0;
//    for (int i = 0; i < n; i++) 
//    {
//        //由于数组 arr 是严格单调递增的，因此在确定下标 i 的情况下可以反向遍历下标 j，计算 dp[i][j] 的值，
//        //只有当 arr[j]×2>arr[i] 时才满足 arr[k]<arr[j]，当 arr[j]×2<=arr[i] 时不需要
//        //对当前下标 i 继续遍历更小的下标 j。
//        for (int j = i - 1; j >= 0 && arr[j] * 2 > arr[i]; j--) 
//        {
//            //为了计算 dp[i][j] 的值，需要得到该斐波那契序列中位于 arr[j] 前面的数字，该数字是arr[i]−arr[j]。
//            //如果 arr[i]−arr[j] 存在于数组 arr 中，且该数字小于 arr[j]，则用 k 表示其下标，有 
//            //arr[k] + arr[j] = arr[i]。因此在以 arr[k] 和 arr[j] 作为最后两个数字的斐波那契子序列的后面添加
//            //arr[i]，即可得到以 arr[j] 和 arr[i] 作为最后两个数字的斐波那契子序列。
//            if (umap.find(arr[i] - arr[j]) == umap.end())
//            {//不存在就继续下一个 arr[j]
//                continue;
//            }
//            int k = umap[arr[i] - arr[j]];//i、j、k都是下标
//            //根据斐波那契子序列的定义可知，斐波那契子序列的长度至少为 3。当dp[k][j]>=3 时
//            //dp[j][i] = dp[k][j] + 1。当 dp[k][j] < 3 时，以 arr[k] 和 arr[j] 作为最后两个数字
//            //的斐波那契子序列并不存在，但是以 arr[j] 和 arr[i] 作为最后两个数字的斐波那契子序列存在，
//            //此时有 dp[j][i] = 3。所以要求最大值
//            dp[i][j] = max(dp[j][k] + 1, 3);
//            res = max(res, dp[i][j]);//整体的最大值
//        }
//        umap[arr[i]] = i;//每个元素的位置
//    }
//    cout<<res;
//}

/////////////////////////////////////////741. 摘樱桃//////////////////////////////////////////

//https://leetcode.cn/problems/cherry-pickup/solution/by-ac_oier-pz7i/
//class Solution {
//public:
//    static const int N = 55, INF = INT_MIN;  // N 为本题范围，因题目有负值的格子，定义INF作为dp数组初始化用
//    // 定义dp数组用于记录结果，由题意，第二次遍历等价于与第一次相同的规则再走一遍，故总共有2N次结果。
//    // 进而可以将问题转换为，两个点从左上角同时开始走，最后都走到右下角的最大得分。
//    // dp[k][i1][i2]为当前 两个点 所在行号加上所在列号等于 k 的情况下，行号、列号从 1 开始
//    // 第一个点在i1行，第二个点在i2行的最大得分，最终答案为dp[2n][n][n]，右下角是第 n 行第 n 列，所以最后是 2n。
//    // 知道了和为 k 及行号，可以算出第一个点在第 k-i1 列，第二个点在第 k-i2 列
//    int dp[2 * N][N][N];
//    int cherryPickup(vector<vector<int>>& grid) {
//        int n = grid.size();
//        // 初始化dp数组为INF
//        for (int k = 2; k <= 2 * n; k++) {
//            for (int i1 = 0; i1 <= n; i1++) {
//                for (int i2 = 0; i2 <= n; i2++) {
//                    dp[k][i1][i2] = INF;
//                }
//            }
//        }
//        // dp[2][1][1] 两个点都在左上角的初始状态，都为0，即 dp[2][1][1] = grid[0][0]
//        // k=2表示第 1 行 第 1 列
//        // 题目保证起点 grid[0][0] 和终点 grid[N-1][N-1] 的值都不会是 -1。
//        dp[2][1][1] = grid[0][0];//原点最大得分就是原有值
//        // 从k=3开始，因为 k=2 只有原点可以走
//        for (int k = 3; k <= 2 * n; k++) {
//            // 两个点都从第一行开始，i1和i2都为 1 到 n 。
//            for (int i1 = 1; i1 <= n; i1++) {
//                for (int i2 = 1; i2 <= n; i2++) {
//                    // 计算两个点当前所在的列
//                    int j1 = k - i1, j2 = k - i2;
//                    // 检查越界
//                    if (j1 <= 0 || j1 > n || j2 <= 0 || j2 > n) 
//                        continue;
//                    // 检查两个点所在位置是否有障碍，有的话跳过。
//                    int A = grid[i1 - 1][j1 - 1], B = grid[i2 - 1][j2 - 1];
//                    if (A == -1 || B == -1) //只要有一个点处于障碍位置，则这个状态是不可达的
//                        continue;
//                    // 确认两个点同时移动都可行，当前第k步可以从原来的两个点状态的最大值转移过来，由于从行走或从列走都有可能，共有四种状态。
//                    int a = dp[k - 1][i1 - 1][i2];//第一个点从列走（从上到下），第二个点从行走（从左到右）
//                    int b = dp[k - 1][i1 - 1][i2 - 1];//第一个点从列走（从上到下），第二个点从列走（从上到下）
//                    int c = dp[k - 1][i1][i2 - 1];//第一个点从行走（从左到右），第二个点从列走（从上到下）
//                    int d = dp[k - 1][i1][i2];//第一个点从行走（从左到右），第二个点从行走（从左到右）
//                    int t = max(max(a, b), max(c, d)) + A;
//                    // 两个点不重合可以同时累加。
//                    if (i1 != i2) //同一个 k，如果i1和i2相等，那么j1和j2也相等，说明是同一位置
//                        t += B;
//                    // 填入现在最佳的结果。
//                    dp[k][i1][i2] = t;
//                }
//            }
//        }
//        //如果在不存在一条可经过的路径，则没有任何一个樱桃能被摘到。答案是 0
//        //由于我们初始值是 INT_MIN，所以如果最终答案没有大于0，说明没有路径
//        return dp[2 * n][n][n] <= 0 ? 0 : dp[2 * n][n][n];
//    }
//};

/////////////////////////////////////////952. 按公因数计算最大并查集大小//////////////////////////////////////////

//https://leetcode.cn/problems/largest-component-size-by-common-factor/solution/by-ac_oier-mw04/
//const static int N = 20010;//以下标来区分不同元素
//static vector<int> p(N, 0);//p记录每个元素的“帮主”
//static vector<int> sz(N, 0);//每个元素的“帮派”大小
//int ans = 1;
//int find(int x) {
//    if (p[x] == x) 
//    {
//        return x;
//    }
//    return p[x] = find(p[x]);
//}
//void merge(int a, int b) {
//    int x = find(a),y=find(b);
//    if (x != y)
//    {//x==y说明已经在一个集合里面了，所以不需要再合并了
//        sz[x] += sz[y];     // 二者连通块得数目合一
//        p[y] = p[x];        // a的祖先作为了合并的最终祖先 
//        ans = max(ans, sz[x]);    // 更新结果
//    } 
//}
//int main()
//{
//    vector<int> nums = { 4,6,15,35 };
//    int n = nums.size();
//    unordered_map<int, vector<int>> m1;//记录哪些元素value包含因数key
//    for (int i = 0; i < n; i++) {
//        // 求取cur得所有质因数, 存取该质因数对应的所有数得坐标
//        int cur = nums[i];
//        for (int j = 2; j * j <= cur; j++) {
//            if (cur % j == 0) 
//                m1[j].push_back(i);//j是i的质因数，i是元素（以下标表示）
//            while (cur % j == 0) //这个质因数 j 已经统计过了，现在把cur的因数里面排除所有的 j
//                cur /= j;//将 i 分解成质因数，比如 24 分解为 2 和 3
//        }
//        if (cur > 1) //cur大于1说明本身就是质数，无法分解成质因数，比如 2 和 3
//            m1[cur].push_back(i);
//    }
//    for (int i = 0; i <= n; i++) {
//        p[i] = i; // 初始化并查集，每个元素的“帮主”初始化为自己
//        sz[i] = 1; // 初始化每个连通块得数量
//    }
//
//    // 联通这些点
//    for (auto& it : m1) {
//        vector<int> tmp = it.second;//有哪些元素拥有质因数 it.first
//        for (int i = 1; i < tmp.size(); i++) 
//        {//有相同质因数的元素全都合并在一起
//            merge(tmp[0], tmp[i]);
//        }
//    }
//    cout << ans;
//}

/////////////////////////////////////////622. 设计循环队列//////////////////////////////////////////

//https://leetcode.cn/problems/design-circular-queue/solution/she-ji-xun-huan-dui-lie-by-leetcode-solu-1w0a/
//class MyCircularQueue {
//private:
//    int front;// 头指针，若队列不空，指向队列头元素,相当于begin()
//    int rear;// 尾指针，若队列不空，指向队列尾元素的下一个位置,相当于end()
//    int capacity;
//    vector<int> elements;
//
//public:
//    MyCircularQueue(int k) {
//        this->capacity = k + 1;
//        this->elements = vector<int>(capacity);//最多存储capacity-1个元素，剩下一个空间用来做哨兵
//        rear = front = 0;//相当于begin()==end()，说明没有元素
//
//    }
//
//    bool enQueue(int value) {
//        if (isFull()) {//如果队列满了，返回false
//            return false;
//        }
//        elements[rear] = value;//注意rear指向队列尾元素的下一个位置,相当于end()，所以我们在尾部插入元素
//        rear = (rear + 1) % capacity;//新的尾部元素，注意是循环队列，当rear=capacity-1的时候（哨兵位置）
//                                     //加1之后变成了capacity，取余之后变为0，但这种情况不可能出现，因为
//                                     //rear=capacity-1代表队列满了，无法再加入元素了
//        return true;
//    }
//
//    bool deQueue() {
//        if (isEmpty()) {
//            return false;
//        }
//        front = (front + 1) % capacity;//从头弹出元素
//        return true;
//    }
//
//    int Front() {
//        if (isEmpty()) {
//            return -1;
//        }
//        return elements[front];
//    }
//
//    int Rear() {
//        if (isEmpty()) {
//            return -1;
//        }
//        return elements[(rear - 1 + capacity) % capacity];//rear的范围是[0:capacity-1]，-1之后有可能小于0
//                                                          //所以要加上capacity，为了防止溢出再取余
//    }
//
//    bool isEmpty() {
//        return rear == front;//相当于begin（）==end（）
//    }
//
//    bool isFull() {
//        return ((rear + 1) % capacity) == front;//注意rear指向的是末尾元素的下一个位置，所以当rear和front相邻
//                                                //的时候，说明此时一共有capacity-1个元素，说明队列满了
//    }
//};
//int main()
//{
//    MyCircularQueue circularQueue(3); // 设置长度为 3
//    circularQueue.enQueue(1); // 返回 true
//    circularQueue.enQueue(2); // 返回 true
//    circularQueue.enQueue(3); // 返回 true
//    circularQueue.enQueue(4); // 返回 false，队列已满
//    circularQueue.Rear(); // 返回 3
//    circularQueue.isFull(); // 返回 true
//    circularQueue.deQueue(); // 返回 true，删除1后我们不会把2,3往前移动
//    circularQueue.enQueue(4); // 返回 true，注意我们不会移动2和3，而是把4放在原来1的位置
//    circularQueue.Rear(); // 返回 4
//}

/////////////////////////////////////////623. 在二叉树中增加一行//////////////////////////////////////////

//https://leetcode.cn/problems/add-one-row-to-tree/solution/by-ac_oier-sc34/
//给定一个二叉树的根 root 和两个整数 val 和 depth ，在给定的深度 depth 处添加一个值为 val 的节点行。
//注意，根节点 root 位于深度 1 。
//加法规则如下 :
//给定整数 depth，对于深度为 depth - 1 的每个非空树节点 cur ，创建两个值为 val 的树节点作为 cur 的左子树根和右子树根。
//cur 原来的左子树应该是新的左子树根的左子树。
//cur 原来的右子树应该是新的右子树根的右子树。
//如果 depth == 1 意味着 depth - 1 根本没有深度，那么创建一个树节点，值 val 作为整个原始树的新根，而原始树就是新根的左子树。
//TreeNode* addOneRow(TreeNode* root, int val, int depth) {
//    int layer = 1;
//    if (depth == 1)
//    {
//        TreeNode* res = new TreeNode(val, root, nullptr);
//        return res;
//    }
//    queue<TreeNode*> q;
//    q.push(root);
//    while (!q.empty())
//    {
//        if (layer == depth - 1)
//        {//对于深度为 depth - 1 的每个非空树节点 cur
//            int sz = q.size();
//            while (sz--)
//            {
//                auto t = q.front();
//                q.pop();
//                TreeNode* oldleft = t->left;//原来的左右子树
//                TreeNode* oldright = t->right;
//                t->left = new TreeNode(val, oldleft, nullptr);//新建左右孩子
//                t->right = new TreeNode(val, nullptr, oldright);
//            }
//            break;//新建完成，退出while循环
//        }
//        else
//        {
//            int sz = q.size();
//            while (sz--)
//            {
//                auto t = q.front();
//                q.pop();
//                if (t->left)
//                {
//                    q.push(t->left);
//                }
//                if (t->right)
//                {
//                    q.push(t->right);
//                }
//            }
//            layer++;
//        }
//    }
//    return root;
//}
//int main()
//{
//    TreeNode* one = new TreeNode(1);
//    TreeNode* two = new TreeNode(3);
//    TreeNode* thr = new TreeNode(5);
//    TreeNode* fou = new TreeNode(2,one,two);
//    TreeNode* fiv = new TreeNode(6,thr,nullptr);
//    TreeNode* six = new TreeNode(4,fou,fiv);
//    addOneRow(six, 1, 2);
//}

/////////////////////////////////////////636. 函数的独占时间//////////////////////////////////////////

//https://leetcode.cn/problems/exclusive-time-of-functions/solution/by-ac_oier-z3ed/
//typedef pair<int, int> pii;
//vector<string> split(string& s, char delimiter) {
//    vector<string> ans;
//    int left = 0, right = 0;
//    while (right < s.size()) {
//        if (s[right] == delimiter) {
//            ans.push_back(s.substr(left, right - left));
//            left = right + 1;
//        }
//        right++;
//    }
//    ans.push_back(s.substr(left, right - left));
//    return ans;
//}
////输入：n = 2, logs = ["0:start:0", "1:start:2", "1:end:5", "0:end:6"]
////输出：[3, 4]
////解释：
////函数 0 在时间戳 0 的起始开始执行，执行 2 个单位时间，于时间戳 1 的末尾结束执行。
////函数 1 在时间戳 2 的起始开始执行，执行 4 个单位时间，于时间戳 5 的末尾结束执行。
////函数 0 在时间戳 6 的开始恢复执行，执行 1 个单位时间。
////所以函数 0 总共执行 2 + 1 = 3 个单位时间，函数 1 总共执行 4 个单位时间。
//int main()
//{
//    int n = 2;
//    vector<string> logs = { "0:start:0", "1:start:2", "1:end:5", "0:end:6" };
//    vector<int> ans(n, 0);
//    stack<pii> st;
//    int gain = 0;
//    for (int i = 0; i < logs.size(); i++) {
//        vector<string> items = split(logs[i], ':');
//        int id = stoi(items[0]), ct = stoi(items[2]);
//        if (items[1] == "start") {//新函数的调用开始时间
//            st.push({ id, ct });
//        }
//        else {
//            //此时栈顶元素必然是该函数的调用记录，此时 log[i] 的结束时间 ct 与栈顶记录的函数开始时间之差 ct - pt + 1，
//            //必然是该函数的执行时间，将其累加到当前函数中，并更新当前时间。
//            auto top = st.top();
//            st.pop();
//            int pt = top.second;//该函数的调用开始时间
//            ans[id] += ct - pt + 1;
//            if (!st.empty())
//                //对于下一个函数来说，因为我们只记录了此函数（记为a）开始时间和结束时间如果中间又调用了其他函数(记为b）
//                //如果直接通过log记录的start和end计算 a 的运行时间，那么有可能会多计算一些时间，所以，我们计算完
//                //栈顶函数（相当于b）的运行时间后，如果栈非空，说明此时还处在 a 的调用期间，所以 a 的运行时间应该减去
//                //b 的运行时间
//                ans[st.top().first] -= ct - pt + 1;
//        }
//    }
//    for (auto i : ans)
//    {
//        cout << i << ' ';
//    }
//}

/////////////////////////////////////////761. 特殊的二进制序列//////////////////////////////////////////

//特殊的二进制序列是具有以下两个性质的二进制序列：
//·0 的数量与 1 的数量相等。
//·二进制序列的每一个前缀码中 1 的数量要大于等于 0 的数量。
//给定一个特殊的二进制序列 S，以字符串形式表示。定义一个操作 为首先选择 S 的两个连续且非空的 特殊的子串，然后将它们交换。
//（两个子串为连续的当且仅当第一个子串的最后一个字符恰好为第二个子串的第一个字符的前一个字符。)
//在任意次数的操作之后，交换后的字符串按照字典序排列的最大的结果是什么？
//输入: S = "11011000"
//输出 : "11100100"
//解释 :
//    将子串 "10" （在S[1]出现） 和 "1100" （在S[3]出现）进行交换。
//    这是在进行若干次操作后按字典序排列最大的结果。
//把 1 看成左括号，0 看成右括号。第一个条件其实就是在说左括号数量等于右括号数量，第二个条件就是每个右括号有对应的左括号。
//string makeLargestSpecial(string_view s) {
//    const int n = s.size();
//    if (n == 0) 
//        return "";
//    int stk = 0, pos = 0;
//    vector<string> children;
//    for (int i = 0;i < n;++i) {
//        switch (s[i]) {
//        case '1':
//            // 栈中增加一个左括号
//            // 增加前栈为空说明当前是一个新的极小括号序列的开头
//            // 将新的极小括号序列的开始位置记录下来
//            if (stk++ == 0)
//                pos = i;
//            break;
//        case '0':
//            // 栈中减少一个左括号
//            // 减少后栈为空说明当前已经找到了一个完整的极小括号序列
//            // 将极小括号序列去除最外围的括号后，递归计算最大值
//            // 将递归得到的子括号序列加入列表
//            if (--stk == 0)
//                //[pos+1，i-1]是还未构造的括号序列，所以需要递归构造，字串开头的 pos+1，长度是 i-1-(pos+1)+1=i-pos-1
//                //字串构造完成后，加上这一层最外面的左右括号，就是一个完整的满足条件的括号序列，
//                //加入res数组，最后在排序还原成字符串
//                children.push_back("1" + makeLargestSpecial(s.substr(pos + 1, i - pos - 1)) + "0");
//            break;
//        }
//    }
//    // 将子括号序列按从大到小排序
//    sort(children.begin(), children.end(), greater<string>{});//字符串排序是按照字典序排列的
//    return reduce(children.begin(), children.end(), ""s);//还原成字符串，注意必须是""s或者string("")，直接""是不行的
//                                                         //因为""是字符指针const char*，没有重载+运算符，不能用reduce
//}
//int main()
//{
//    cout << makeLargestSpecial("11011000");
//}

/////////////////////////////////////////899. 转移字符能得到的字典序最小的字符串//////////////////////

//https://leetcode.cn/problems/orderly-queue/solution/nao-jin-ji-zhuan-wan-by-heren1229-gg97/
//给定一个字符串 s 和一个整数 k 。你可以从 s 的前 k 个字母中选择一个，并把它加到字符串的末尾。
//返回 在应用上述步骤的任意数量的移动后，字典上最小的字符串 。
//int main()
//{
//    string s = "baaca";
//    int k = 2;
//    int n = s.length();
//    if (k == 1) 
//    {//当 k = 1 时，每次只能取 s 的首个字符并将其移动到末尾，因此对于给定的字符串，可能的移动方法是唯一的，
//        //移动后的结果也是唯一的。对于长度为 n 的字符串 s，经过 0 次到 n - 1 次移动之后分别得到 
//        //n 个字符串，这 n 个字符串中的字典序最小的字符串即为答案。
//        //我们共有 n 种候选方案（将字符串 s 看作一个首尾相接的循环字符串，共有 n 个起点可枚举），
//        //枚举过程中需要与当前最优的方案进行比较，比较复杂度为 O(n)，因此整体复杂度为 O(n^2)
//        //这里我们用 最小表示法 来找最优的字符串，参考 https://oi-wiki.org/string/minimal-string/#_8
//        int k = 0, i = 0, j = 1;//i和j是两个字符串的起点，必定不相同
//        while (k < n && i < n && j < n) {
//            // i, j 分别代表一个长度为n的字符串的起点，它们的前 k 个字符均相同，即
//            // s[i,i+1,...i+k-1]=s[j,j+1,...j+k+1],当两字符串第一个不同的字符大小关系为 s[i + k] > s[j + k]时
//            // 可以发现在下标 i1∈[i,i+k] 作为起点的新方案 a' 必然不会是最优方案，因为必然存在下标范围 
//            // j1=idx−i+j 作为起点的新方案 b' 比其更优，因此我们可以直接从 i+k+1 位置构造新的更优方案，
//            // 并与 b 再次比较，而 s[i + k] < s[j + k]的分析同理
//            char a = s[(i + k) % n], b = s[(j + k) % n];//s[i + k] 和 s[j + k]
//            if (a == b) 
//                k++;//两者相等，则比较下一个字符，k+1
//            else {
//                (a > b ? i : j) += k + 1;//a大的话，跳过[i+1:i+k]
//                // 当 i 和 j 相等，因为不能为同一序列否则无法进行下去，所以加一
//                if (i == j) 
//                    i++;
//                // 更换序列需要重新从第一个字符开始比较
//                k = 0;
//            }
//        }
//        // 较大值进入到了下一个轮回，无意义
//        i = min(i, j);//i和j是下标
//        cout<<s.substr(i, n - i) + s.substr(0, i);
//        return 0;
//    }
//    else 
//    {/*证明起来很简单的，首先，我们可以轻易地证明出，想要让某个字符到首位是容易的，
//            然后，我们能证明出想要让两个字符分别排位到1，2号位置是容易的，譬如说....a....b....这样的序列，
//            我们可以先把所有前面的字符都移到最后，这样把a移到首位，然后把所有中间的字符移到最后，
//            这样让字符串变形为ab.......，然后，我们可以将ab这两个字符视为一个字符来处理，
//            因为每次我们想要对其进行操作时，总是可以先对a进行操作，再对b进行操作，
//            这样能永远保持这两个字符以固定的顺序绑定在一起。然后，我们可以以此推广至整个序列，
//            相当于不断地去找到下一个最小的字符，和首字符绑定起来变为一个字符，直到整个字符串合并完成*/
//        sort(s.begin(), s.end());
//    }
//    cout << s;
//}

/////////////////////////////////////////运矿石（01背包）//////////////////////////////////////////

//https://blog.csdn.net/weixin_41646851/article/details/107506504
//int main()
//{
//    vector<int> weight = {7,4,11,8,10 };
//    int n= weight.size(),s = 0;
//    for (int i = 0; i < n; ++i) {
//        s += weight[i];
//    }
//    // S 为矿石总重量的一半
//    int S = s >> 1;
//    // N 为矿石数量的一半，奇数块的话向上取整
//    int N = (n + 1) >> 1;
//    //建立（S+1）*（N+1）的动态二维数组
//    // dp[i][j] 代表容量为 i 的背包，装有 j 块石头时的最大重量
//    //每一边的背包容量最大为 S，最多装 N 块石头
//    vector<vector<int> > dp(S + 1, vector<int>(N + 1, INT_MIN));
//    // 数组第一行置为0
//    for (int i = 0; i <= S; ++i) 
//        dp[i][0] = 0;//背 0 块石头最大重量为0
//    for (int i = 0; i < n; ++i) 
//    {//i 表示现在该决定 i 号矿石应该是否应该放在背包里，这里是01背包的二维形式，所以先遍历物品或背包都可以
//        auto dp1 = dp;
//        for (int j = weight[i]; j <= S; ++j) 
//        {//j表示背包容量，01背包的二维形式可以正序
//            for (int k = 1; k <= N; ++k) 
//            {//对于 i 号矿石来说，此时容量为 j ，装有 k 块石头的最大重量有两种情况
//                //一是不把它装进去，这样背包保持原样，是 考虑 i-1 号矿石时容量为 j ，装有 k 块石头的最大重量
//                //二是把他装进去，这样最大重量等于 
//                //  考虑 i-1 号矿石时容量为 j-weight[i] ，装有 k-1 块石头的最大重量 加上 i 号矿石的重量
//                dp1[j][k] = max(dp1[j][k], dp[j - weight[i]][k - 1] + weight[i]);
//            }
//        }
//        // 用旧的dp数组来进行for循环，循环完毕更新整个dp数组，其实可以把dp申请为三维数组
//        swap(dp1, dp);
//    }
//    //求出来的最终的dp[S][N]表示一边最多能装多重的石头，那么另一边就装 s-dp[S][N] 的石头（s表示总重量）
//    //那么 两边差值就是 abs(s-dp[S][N]-dp[S][N])=abs(s-2*dp[S][N]),但是由于 dp[S][N]永远小于等于 S=s/2
//    //（S表示背包容量，装的重量不可能超过容量），则dp[S][N]<=S,2*dp[S][N]<=s,那么s-2*dp[S][N]永远大于等于0
//    //因此不需要加 abs
//    if (n & 1) 
//    {//如果有 奇数块 石头，则一边会装 N 块石头，另一边会装 N-1 块石头，每边装的越多（越接近S）
//        //两边的差值就越小，答案就越小，所以要求两边能装重量的最大值
//        return s - 2 * max(dp[S][N], dp[S][N - 1]);
//    }
//    return s - 2 * dp[S][N];//偶数块石头的话，两边装的石头数量相等，都是 N
//}

/////////////////////////////////////////糖果装盒，最多装几盒//////////////////////////////////////////

//两种糖A和B，个数分别是x和y，每个盒子装三个糖，要求一盒中A和B至少一个，求最多装几盒。
//https://www.nowcoder.com/discuss/1006463?type=post&order=recall&pos=&page=1&ncTraceId=&channel=-1&source_id=search_post_nctrack&gio_id=36F15DC043EFA17A7DFBBC684EE07A58-1659792138736
//int main()
//{
//    int T;
//    cin >> T;
//    int x;
//    int y;
//    while (T--) {
//        cin >> x >> y;
//        //假设能做x盒，那么 x<=A x<=B 且 3x<=A+B,
//        int ans = min(min((x + y) / 3, x), y );
//        cout << ans << endl;
//    }
//    return 0;
//}

/////////////////////////////////////////约瑟夫环出列顺序//////////////////////////////////////////

//https://blog.csdn.net/shizi599/article/details/101238187?spm=1001.2101.3001.6650.8&utm_medium=distribute.pc_relevant.none-task-blog-2~default~BlogCommendFromBaidu~Rate-8.pc_relevant_default&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2~default~BlogCommendFromBaidu~Rate-8.pc_relevant_default&utm_relevant_index=12
//struct node
//{
//    int num;
//    struct node* next;
//    node(int val, node* p) :num(val), next(p) {};
//};
//int main()
//{
//    int N = 6, M = 3;//总共N个人，
//    node* head = new node(1, nullptr);
//    node* cyclic = head;
//    for (int i = 2; i <= N; i++)
//    {//创建链表
//        node* body = new node(i, nullptr);
//        cyclic->next = body;
//        cyclic = cyclic->next;
//    }
//    cyclic->next = head;//收尾相连
//    node* tail = head;
//    while (tail->next != head) {//找到尾结点
//        tail = tail->next;
//    }
//    node* p = head;//p代表离队的那个人
//    while (p->next != p) //每删除一个节点，就要把链表重新组合成环，最后只剩下一个节点，退出循环
//    {
//        for (int i = 1; i < M; i++)
//        {//找到从当前头部开始的第 M 个人，注意 i=M-1仍然进行一次循环，这样p就指向第 M 个人
//            tail = p;//先记录上一个人
//            p = p->next;//再往前进
//        }
//        tail->next = p->next;//tail是第 M-1 个人，p是 第 M 个人，出列，剩下的人继续组成环
//        cout << p->num << ' ';
//        delete p;
//        p = tail->next;//上一轮的 第 M+1 个人成为这一轮的第 1 个人
//    }
//    cout << p->num;//最后一个人，出列
//    delete p;
//    return 0;
//}

/////////////////////////////////////////768. 最多能完成排序的块 II//////////////////////////////////////////

//https://leetcode.cn/problems/max-chunks-to-make-sorted-ii/solution/zui-duo-neng-wan-cheng-pai-xu-de-kuai-ii-w5c6/
//arr是一个可能包含重复元素的整数数组，我们将这个数组分割成几个“块”，并将这些块分别进行排序。
//之后再连接起来，使得连接的结果和按升序排序后的原数组相同。
//我们最多能将数组分成多少块？
// 比如arr = [4,3,2,1,0]，最多分成 1 块
// 将数组分成2块或者更多块，都无法得到所需的结果。
// 例如，分成[4, 3], [2, 1, 0] 的结果是[3, 4, 0, 1, 2]，这不是有序的数组。
//int main()
//{
//    vector<int> arr = { 2,1,1,4,3,4 };
//    stack<int> st;//构建单调递增栈
//    for (auto i : arr)
//    {
//        //对于已经分好块的数组，若在其末尾添加一个数字，如何求得新数组的分块方式？
//        //·新添加的数字可能会改变原数组的分块方式。如果新添加的数字大于或等于原数组最后一个块的最大值，
//        //则这个新添加的数字可以自己形成一个块，因为我们要求最多分为多少块。
//        //·如果新添加的数字小于原数组最后一个块的最大值，则它必须融入最后一个块。
//        //如果它大于或等于原数组倒数第二个块（如果有）的最大值，那么这个过程可以停止，
//        //新数组的分块方式已经求得。否则，它将继续融合原数组倒数第二个块，直到遇到一个块，
//        //使得该块的最大值小于或等于这个新添加的数，或者这个数字已经融合了所有块。
//        //上述分析过程中，我们只用到了块的最大值来进行比较，比较过程又是从右到左，符合栈的思想，
//        //因此可以用类似单调栈的数据结构来存储块的最大值。
//        if (!st.empty())
//        {//对于一个非空栈，
//            if (i >= st.top())
//            {//比较当前值 i 和栈顶最后一个块的最大值，如果大于或等于，则当前值可以自己形成一个块
//                //他又变成新的最后一个块的最大值（到目前为止）
//                st.push(i);
//            }
//            else
//            {//否则，往前查找，原有的最后一个块的最大值不应该变动，其他块的最大值可能会受到影响
//                //比如在[1,2,3,0]中，从左向右遍历，[1,2,3]均为最大值，但是一遇到0之后不仅0需要并入3所在分块，
//                //就连1和2都要并入3所在分块，所以这里我们还需要有一步弹出操作，表示之前的块不能单独存在了
//                //需要合并到后面更大的块中
//                int max_ = st.top();
//                while (!st.empty() && i < st.top())
//                {
//                    st.pop();
//                }
//                st.push(max_);//新的块的最大值
//            }
//        }
//        else
//        {
//            st.push(i);
//        }
//    }
//    return st.size();//st记录的是每一块的最大值，所以有多少个最大值就有多少个块
//}

/////////////////////////////////////////1422. 分割字符串的最大得分//////////////////////////////////////////

//https://leetcode.cn/problems/maximum-score-after-splitting-a-string/solution/fen-ge-zi-fu-chuan-de-zui-da-de-fen-by-l-7u5p/
//给你一个由若干 0 和 1 组成的字符串 s ，请你计算并返回将该字符串分割成
//两个 非空 子字符串（即 左 子字符串和 右 子字符串）所能获得的最大得分。
//「分割字符串的得分」为 左 子字符串中 0 的数量加上 右 子字符串中 1 的数量。
//将字符串 s = "011101" 划分为两个非空子字符串的可行方案有：
//左子字符串 = "0" 且 右子字符串 = "11101"，得分 = 1 + 4 = 5
//左子字符串 = "01" 且 右子字符串 = "1101"，得分 = 1 + 3 = 4
//左子字符串 = "011" 且 右子字符串 = "101"，得分 = 1 + 2 = 3
//左子字符串 = "0111" 且 右子字符串 = "01"，得分 = 1 + 1 = 2
//左子字符串 = "01110" 且 右子字符串 = "1"，得分 = 2 + 1 = 3
//当 1<=i < n 时，分割点 i 将字符串 s 分割成两个非空子字符串，左子字符串的下标范围是[0, i - 1]，
//右子字符串的下标范围是[i, n - 1]。对于 1 <= i < n-1，当分割点从 i 移动到 i + 1 时，位于下标 i 处的字符 s[i] 
//从右子字符串中移除并添加到左子字符串中，分割字符串的得分变化如下：
//如果 s[i] = 0，则左子字符串的得分加 1，右子字符串的得分不变，因此分割字符串的得分加 1；
//如果 s[i] = 1，则左子字符串的得分不变，右子字符串的得分减 1，因此分割字符串的得分减 1。
//由于最左侧的分割点是 i = 1，因此首先计算 i = 1 处的分割字符串的得分，然后从左到右依次遍历每个分割点，
//遍历过程中更新分割字符串的得分，遍历结束之后即可得到分割字符串的最大得分。
//int main()
//{
//    string s = "011101";
//    int score = 0;
//    int n = s.size();
//    if (s[0] == '0') {
//        score++;
//    }
//    for (int i = 1; i < n; i++) {
//        if (s[i] == '1') {
//            score++;
//        }
//    }
//    int ans = score;//分割点i=1时的得分
//    for (int i = 1; i < n - 1; i++) {
//        if (s[i] == '0') {
//            score++;
//        }
//        else {
//            score--;
//        }
//        ans = max(ans, score);
//    }
//    return ans;
//}

/////////////////////////////////////////2376. 统计特殊整数//////////////////////////////////////////

//https://leetcode.cn/problems/count-special-integers/solution/shu-wei-dp-mo-ban-by-endlesscheng-xtgx/
//如果一个正整数每一个数位都是 互不相同 的，我们称它是 特殊整数 。
//给你一个 正 整数 n ，请你返回区间[1, n] 之间特殊整数的数目。
//**************************************************数位DP（非递归）***************************************
//int main() 
//{
//    int n = 11;
//    //预处理一个数组f[i][j]代表从i连乘到j的结果,i,j在这里表示每个数位上有多少种选择
//    //f[i][j]代表 i * (i + 1) * ... * (j - 1) * j
//    //首位不可能是0，所以只有9种选择，后面由于首位用掉一个数字，最多只有 10-1=9种选择，因此最多乘到 9 就可以了
//    int f[10][10] = { 0 };
//    for (int i = 1; i < 10; i++) {
//        for (int j = i; j < 10; j++) {
//            int cur = 1;
//            for (int k = i; k <= j; k++) 
//                cur *= k;//表示累乘
//            f[i][j] = cur;
//        }
//    }
//    int ans = 0; //用于统计结果
//    int s = 0;  //用于统计数字是否被使用，s二进制的低10位用来表示那一个数是否被使用过
//    int p = 1;  //记录当前处理到的位数
//    //先把x的位数取出来
//    vector<int> num;
//    int t = n;
//    while (t != 0) {
//        num.push_back(t % 10);
//        t /= 10;
//    }
//    int sz = num.size();  //代表n一共有多少位
//    if (sz <= 1) //n=0时，sz=0，n是个位数时，sz=1，肯定不包含重复的数字，直接返回 n+1（0也算在里面了）
//        //比如 n=5，就说明有6个数字小于等于5切没有重复位数，他们是： 0,1,2,3,4,5 
//        return n + 1;
//    //先统计位数相同的情况，对应res1和res2
//    for (int i = sz - 1; i >= 0; i--) {
//        int cnt = 0; //代表这个位置的选择个数
//        int cur = num[i];//n 在这一位上的数字
//        for (int j = cur - 1; j >= 0; j--) 
//        {// j表示这一位上可以放置的数，cur-1保证了肯定小于n
//            //排除掉首位为0的情况
//            if (i == sz - 1 && j == 0) 
//                continue;
//            //如果某个数字在之前的选择还没有出现过
//            if ((s & (1 << j)) == 0) //s二进制从右往左低 j 位为0表示之前没有使用过，可以放置在当前位置
//                cnt++;//这个位置的选择个数+1
//        }
//        //确定了当前这一位有多少种选择cnt，后面的位数可以在满足「相同数字只能使用一次」的限制条件下
//        //任意选择（因为大小关系已经由当前这一位保证了）
//        //p表示当前已经放了多少位了，10-p表示后面最多还有多少种选择，处理到当前位置已经用了 p 个数
//        //接下来的那一位就只有 10-p中选择了，比如“678”，当前处理到第一位 6，有“1,2,3,4,5”5种选择
//        //则cnt=5，p=1，接下来对于‘7’这一位，有 9 种选择（因为首位已经选择了小于6的数
//        //所以这一位不用考虑大小，而首位已经选择了1,2,3,4,5其中的一个，则这一位只有另外的 9 种选择）
//        // sz-p表示还有多少位没有选择，10-p-(sz-p)表示那些目前没有选择的位选择完以后，还剩下多少数可以选择
//        //注意 10-p-(sz-p) 是所有位数都选择完以后还剩下的位数，则 它+1 表示最后一位有多少种选择
//        //也就是 a 表示下一位有多少种选择， b 表示最后一位有多少种选择
//        //注意 a有可能小于b，如果当前处理最后一位，填好以后 a 表示还剩下多少选择，b表示最后一位还剩下多少选择
//        //则有 b=a+1
//        int a = 10 - p, b = a - (sz - p) + 1;
//        //a>=b时表示下一位有 a 中选择，再下一位有 a-1种选择，最后一位有 b 种选择，总方案数为 a*(a-1)...*b=f[b][a]
//        //b>a时表示最后一位有cnt种选择，后面就结束了，因此是 cnt*1
//        ans += (b <= a ? f[b][a] * cnt : cnt);
//        //计算完了小于当前位的所有方案，也就是res1，接下来计算res2
//        //我们想在当前位上放和 n这一位相同的数，也就是cnr，所以要先判断一下之前有没有放过 cur
//        //如果放过，那么这一位就不能放，否则就是重复的，比如“676”，我们可以在第一位上放‘6’，第二位上放‘7’
//        //但是不能在第三位上也放‘6’，只能放上面选择的 0-5，这样的话就没必要继续往下循环了，因为我们循环的目的
//        //是为了计算 当前面高位上的数字相同时，低位上能放哪些数字，既然当前位不相同，那么低位能放的数都已经计算
//        //在 前面的 f[b][a] * cnt 里面了，所以退出循环
//        p++;//已放置的数加 1
//        if (s & (1 << cur))
//            break;
//        s |= (1 << cur);//否则放置一个相同的数，继续判断下一位
//        //有可能本身也是一个合理的数
//        if (i == 0) //i=0说明最后一位也相同，并且不重复，那么 n 本身是满足条件的
//            ans++;
//    }
//    //再处理位数不同的情况，也就是res3
//    ans += 10;//上面保证了 n>=2，所以比n位数小的可以是 1 位，也就是个位数，总共有 0-9 十个数
//    int cr = 9;//比n位数少的数，包括 1位数，2位数... sz-1位数，如果是 1 位数，首位（只有一位）总共9种选择
//    //如果是 2 位数，首位总共 9 种选择，次位总共 10-2+1=9 种选择（因为可以放 0）
//    for (int i = 2; i < sz; i++) 
//    {// i表示当前列举的是 i 位数，最大为 sz-1
//        cr *= (10 - i + 1);//2位数可以直接在 1 位数的基础上加上一位
//        ans += cr;//比 n 位数少的 i 位数都满足条件，所以直接加到答案里
//    }
//    return ans;
//}
//**************************************************数位DP（递归模板）***************************************
//int main()
//{//简单的说，数位DP就是爆搜+记忆化，从最低位开始计算合法方案数，然后往前回溯，同时做记忆化
//    int n = 20;
//    auto s = to_string(n);
//    int m = s.length();
//    //第一维一般是当前枚举到的位数，第二位表示状态（具体问题具体分析,这里表示 0-9 中哪些数字被用过了）
//    //dp就是记忆化的数组,用来剪枝，dp[i][j]记录枚举到 第 i 位，用过的数字包含在 j 的二进制中时符合条件的方案数
//    vector<vector<int>> dp(m, vector<int>(1 << 10, -1));
//    //定义f(i, mask, isLimit, isNum) 表示构造从左往右第 i 位及其之后数位的合法方案数
//    function<int(int, int, bool, bool)> fun = [&](int i, int mask, bool is_limit, bool is_num) -> int 
//    {//mask 表示前面选过的数字集合，换句话说，第 i 位要选的数字不能在 mask 中。
//        //isLimit 表示当前是否受到了 n 的约束。若为真，则第 i 位填入的数字至多为 s[i]，否则可以是 [0:9]。
//        //  如果在受到约束的情况下填了 s[i]，那么后续填入的数字仍会受到 n 的约束。
//        //isNum 表示 i 前面的数位是否填了数字。若为假，前面填的全都是0，则当前位
//        //  要填入的数字至少为 1（因为不能有前导0）；若为真，则要填入的数字可以从 0 开始（因为这一位不是首位）。
//        if (i == m) 
//            //所有位数枚举完时返回，is_num是TRUE，表示之前填过了非 0 的数，则返回 1，表示我们已经构造出了
//            //一个合法的数，比如我们构造出“001”，当i=3时，is_num等于TRUE，则“001”是合法的
//            //而如果我们我们构造出“000”，则它表示数字 0，在本题中是非法的，当前其他题 0 可能是合法的
//            //所以有些题可以直接返回 1
//            return is_num;
//        // !is_limit && is_num 只有遇到那些会多次访问的状态时才为 TRUE，可以参考下面的注释
//        // 那么当我们第一次访问这些状态时，dp[i][mask]=-1，我们计算这个状态的方案数，然后记忆下来
//        // 后续访问时，dp[i][mask] >= 0保证了我们不是第一次访问该状态，所以可以直接返回方案数
//        // 必须要在 没有收到限制 且 前面已经填了数字，且前面填的数和之前某一次填的数完全相同（mask相同），则可以直接返回答案
//        // 比如 n=415，当前已经填了“4”，“1”，现在要填第三位，此时的 is_limit 是 TRUE，这一位只能填[0:5]
//        // 之前某一次填了“1”，“4”，这一位填了[0:9]，这样的话虽然 i 和 mask 都相同，但是不能直接返回 dp[i][mask]
//        // 因为一个是受限制，一个没有限制
//        // 这里有没有 is_num 不影响，因为 is_num 不会和之前某一次填的mask相同
//        if (!is_limit && is_num && dp[i][mask] >= 0) 
//            return dp[i][mask];
//        //res表示访问到当前这一位（第 i 位），前面（不包括 i）用过的数字包含在 mask 的二进制中时符合条件的方案数
//        //res需要对当前这一位能放的数进行遍历，然后在 第 i 位已放的条件下去访问后续的位能放置的方案数，累加起来就是
//        //当前这一状态的总方案数，然后往前回溯，返回给前一位，作为它的总方案数
//        int res = 0;
//        if (!is_num) 
//            //前面都填的是 0，我们可以直接在这一位上也填 0，然后一直到最低位，开始下面的填数过程
//            //这里表示还没有进入到真正数字的表示范围，比如“009”，访问到第 2 位时，is_num是false
//            //只有这样我们才能进入到最低位，然后从最低位开始计算结果，返回前一位
//            //如果这里不直接进入最低位（最右边）而是从最高位（最左边）开始填数，那么首位只能从 1 开始填，就会少算答案
//            //比如，n=10，从左边开始填的话，首位填 1，次位填 0，只有 1种方案 “10”
//            //从右边开始的话，首位先填“0”，次位可以填[1:9]，首位再填“1”，次位填“0”，总共 10 种方案
//            //当然也可以选择下面填数的时候每次都从 0 开始，但是如果首位填了 0，后面的位就不能出现0，这样“001”，“002”
//            //这种都不能算正确答案，就会少算很多，也就是说，在这里其实不是真正的填了 0，而是填了一个占位符 _
//            //有的题目不需要占位符，直接从左往右填，是因为它们允许重复填数，即使前面填了0，后面依然可以填 0 ，所以不需要
//            //占位符而可以直接用 0 去占位
//            res = fun(i + 1, mask, false, false); // 可以跳过当前数位
//        int up = is_limit ? s[i] - '0' : 9;//上界，受到限制的话最大为 s[i]，否则是 9
//        for (int d = 1 - is_num; d <= up; ++d) 
//            // 枚举要填入的数字 d，is_num是TRUE，表示前面填过数了，当前位不是真正意义上的首位，所以可以填0
//            // 否则不能填0，只能填 1-9
//            if ((mask & (1 << d)) == 0) // d 不在 mask 中
//                //mask | (1 << d)表示把 d 放在当前位置
//                //如果is_limit是 TRUE，表示当前位置填的数受到 s[i]的限制，那么如果当前位填的数
//                // d小于up，则小于关系已经完全成立了（高位已经小于了），后面低位不需要再受到
//                // s[i] 的限制，则后续的is_limit=FALSE；
//                // 如果 d等于up，则小于关系不完全成立，低位仍需受到限制
//                //如果is_limit是 FALSE，表示当前位置填的数不受 s[i]的限制，则后面的数也可以不受限制
//                //当前这一位已经填了数了，所以后面低位可以在 0-9中选择
//                //for循环开始的时候，is_num是TRUE的话说明前面已经填了数，那么后面的数可以随便填
//                //is_num是FALSE的话，这一位只能填[1:9]，也填过数了，那么后面的数可以随便填，综上，传入下层的 is_num 一定是true
//                res += fun(i + 1, mask | (1 << d), is_limit && d == up, true);
//        //这里为下次重复访问本状态提供记忆化，
//        //·如果is_limit是TRUE，说明当前仍然受到 n 的约束，也就是前面
//        //所填的数全都和 n 相同，那么不可能再有第二次机会去填这一位并且前面填的数都和n相同
//        //比如 n=“123”，对于第 3 位，假设前面两位填的是“1”和“2”，那么填第 3 位的机会有且只有当前这一次
//        //所以当is_limit是TRUE的时候不需要记忆化，也就不需要记录dp
//        //·如果 is_num 是FALSE，说明前面填的数全是0，当前这一位才是真正意义上的首位，那么由于前面的数是确定的
//        //所以只可能有一次机会访问到该状态，所以不需要记忆，比如“006”这个数，它表示 6，第 3 位的 6 才是
//        //真正意义上的首位，他前面两个 0 只是我们用来凑够位数的
//        //·其实就是说，当前面填的数都是确定的时候，我们不需要对当前这个状态（i，mask）做记录，因为只可能访问
//        //  一次，当然记录也没啥问题，只不过多占一些内存。
//        if (!is_limit && is_num) 
//            dp[i][mask] = res;
//        return res;//返回，计算上一位的方案数。
//    };
//    return fun(0, 0, true, false);
//}

/////////////////////////////////////////跳跃游戏//////////////////////////////////////////

//https://leetcode.cn/problems/jump-game-ii/
//int main()
//{
//    vector<int> a = { 2,2,3,0,4 };
//    int N = a.size();
//    int curDistance = 0;    // 当前覆盖最远距离下标
//    int ans = 0;            // 记录⾛的最⼤步数
//    int nextDistance = 0;   // 下⼀步覆盖最远距离下标，下一步不一定要等到当前最远距离的时候才去跳
//    for (int i = 0; i < N; i++) {
//        nextDistance = max(a[i] + i, nextDistance);  // 更新下⼀步覆盖最远距离下标
//        if (i > curDistance)
//        {//到达了当前覆盖最远距离无法覆盖的地方，说明无论如何不能到达这里，
//            //如果可以的话，nextDistance会覆盖这里，则返回-1，表示无法到达
//            return -1;
//        }
//        if (i == curDistance)
//        {// 遇到当前覆盖最远距离下标
//            if (curDistance != N - 1)
//            {// 如果当前覆盖最远距离下标不是终点
//                ans++;// 需要⾛下⼀步
//                if (nextDistance >= N - 1)
//                    break; // 下⼀步的覆盖范围已经可以达到终点，结束循环，上面ans已经递增了
//                curDistance = nextDistance;// 否则更新当前覆盖最远距离下标
//
//            }
//            else
//                break;// 当前覆盖最远距离下标是集合终点，不⽤做ans++操作了，直接结束
//        }
//    }
//    return ans;
//}

/////////////////////////////////////////2380. 二进制字符串重新安排顺序需要的时间///////////////////////////

//https://leetcode.cn/problems/time-needed-to-rearrange-a-binary-string/solution/by-newhar-o6a1/
//int main()
//{
////    1 当s[i]==0时，则不需要移动，f[i]=f[i-1]
////    2 当s[i]==1时，如果左侧存在 cnt(cnt > 0) 个 0，则至少需要 cnt 秒来移动；
////    同时，如果这个 1 的左侧还存在 1，那么它至少需要比左侧那个 1 多一秒才能到达最终位置。
////    这是因为，当左侧的 1 刚到达最终位置的时刻，右侧的 1 一定不会移动到最终位置，
////    而是至少与前面的 1 间隔一个 0，因为 "11"这种无法同时向左移动，从而无法同时到达最终位置。
////    每个 11 向左移动的过程中，有两种情况：
////    在到达最终位置之前，未受到左侧的 1 的 “阻挡”，也就是每一秒都移动了一次，
////      此时，移动次数 = 其左侧 0 的个数；
////    在到达最终位置之前，受到了左侧 1 的 “阻挡”，也就是说，在某一时刻，
////      其与左侧的 1 相邻而组成了 11。在此之后，我们可以证明，
////      当左侧的那个 1 到达最终位置时，右侧的 1 一定与左侧的 1 间隔 1 个 0。
////      此时，移动次数 = 左侧 1 的移动次数 + 1。
//    string s = "0110101";
//    int res = 0;//res记录的是左侧的 1 移动的最少次数
//    for (int i = 0, cnt = 0; i < s.size(); ++i) {
//        if (s[i] == '0') //等于 0，不需要移动
//            ++cnt;//记录左侧 0 的个数
//        else if (cnt > 0) //否则s[i]=1,则必须保证左侧是存在0的，否则左侧不存在 0 的话，也不需要移动
//            res = max(res + 1, cnt);
//        //比如对于第一个 1，前面有1个0，没有 1 ，所以只需要移动 1 次
//        //对于第二个 1，前面有 1 个0，左侧 1 的移动次数为 1，所以要把它放到正确位置上，至少需要 2 次、
//        //第一次把前面第一个 1 转移到前面，形成“101”，第二次把它转移到前面，形成“110”
//        //对于第三个1，前面有 2个0，左侧 1 的移动次数为 2，所以要把它放到正确位置上，至少需要 3 次
//        //第一次把前面第一个 1 和第 3 个 1 转移到前面，形成“10110”，第二次把第二个 1 转移到前面，形成“11010”
//        //第三次把它转移到前面，形成“11100”...
//    }
//    return res;
//}
//int main()
//{
//    vector<int> nums = { 2,2,1,1,5,3,3,5 };
//    int n = nums.size();
//    vector<int> cnt(n + 1, 0), tmp(n + 1, 0);
//    int max_ = 0;
//    int res = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if(tmp[cnt[nums[i]]])
//            tmp[cnt[nums[i]]]--;
//        cnt[nums[i]]++;
//        tmp[cnt[nums[i]]]++;
//        max_ = max(max_, cnt[nums[i]]);
//        if (max_ == 1)
//        {
//            res = max(res, i + 1);
//        }
//        if (max_*tmp[max_] == i && tmp[1] == 1)
//        {
//            res = max(res, i + 1);
//        }
//        if (tmp[max_] == 1 && (max_-1)*tmp[max_ - 1] == i+1-max_)
//        {
//            res = max(res, i + 1);
//        }
//    }
//    return res;
//}

/////////////////////////////////////////2381. 字母移位 II///////////////////////////

//https://leetcode.cn/problems/shifting-letters-ii/solution/by-lfool-ipl4/
//int main()
//{
//    string s = "abc";
//    vector<vector<int>> shifts = { {0, 1, 0},{1, 2, 1},{0, 2, 1} };
////  shifts[i] = [starti, endi, directioni] 。对于每个 i ，将 s 中从下标 starti 到下标 endi （两者都包含）
////  所有字符都进行移位运算，如果 directioni = 1 将字符向后移位，如果 directioni = 0 将字符向前移位。
//    int n = s.size();
//    vector<int> f(n + 1);//差分数组
//    //f[i]=arr[i]-arr[i-1],f[0]=arr[0]
//    for (auto& shift : shifts) {
//        int x = shift[2] * 2 - 1;//1 映射到 1，0 映射到 -1
//        f[shift[0]] += x;//我们要增加的是从 shift[0] 到 shift[1] （都包含）的所有数，所以对于差分数组
//        //需要对 shift[0] 增加相应的数，表示 shift[0]（包含）往后的数全都增加
//        //对 shift[1]+1 减少相应的数，表示 shift[1]+1（包含）往后的数全都减少
//        //这样就实现了区间都增加 x 的目标
//        f[shift[1] + 1] -= x;
//    }
//    int sum = 0;
//    string ans;
//    for (int i = 0; i < n; i++) { /* 前缀和求出最终的字符 */
//        sum += f[i];//前缀和，presum[i]=presum[i-1]+arr[i]，presum[0]=arr[0]
//        int d = ((s[i] - 'a' + sum) % 26 + 26) % 26;//sum有可能是负数，取余之后还是负数，所以要加上 26
//        ans.push_back(d + 'a');
//    }
//    cout << ans;
//}

/////////////////////////////////////////2382. 删除操作后的最大子段和///////////////////////////

//https://leetcode.cn/problems/maximum-segment-sum-after-removals/solution/by-endlesscheng-p61j/
//对于第 i 个查询，nums 中位于下标 removeQueries[i] 处的元素被删除，将 nums 分割成更小的子段。
//输入：nums = [1, 2, 5, 6, 1], removeQueries = [0, 3, 2, 4, 1]
//输出：[14, 7, 2, 2, 0]
//解释：用 0 表示被删除的元素，答案如下所示：
//查询 1 ：删除第 0 个元素，nums 变成[0, 2, 5, 6, 1] ，最大子段和为子段[2, 5, 6, 1] 的和 14 。
//查询 2 ：删除第 3 个元素，nums 变成[0, 2, 5, 0, 1] ，最大子段和为子段[2, 5] 的和 7 。
//查询 3 ：删除第 2 个元素，nums 变成[0, 2, 0, 0, 1] ，最大子段和为子段[2] 的和 2 。
//查询 4 ：删除第 4 个元素，nums 变成[0, 2, 0, 0, 0] ，最大子段和为子段[2] 的和 2 。
//查询 5 ：删除第 1 个元素，nums 变成[0, 0, 0, 0, 0] ，最大子段和为 0 ，因为没有任何子段存在。
//所以，我们返回[14, 7, 2, 2, 0] 。
//*******************************************哈希表**********************************************
//int main()
//{
//    vector<int> nums = { 1, 2, 5, 6, 1 }, removeQueries = { 0, 3, 2, 4, 1 };
//    int n = nums.size();
//    // 求前缀和，方便我们直接求出区间的和
//    vector<long long> presum(n + 1);
//    for (int i = 1; i <= n; i++) 
//        presum[i] = presum[i - 1] + nums[i - 1];
//
//    // 记录已删除的下标
//    set<int> st;
//    // 放入下标 0 和 n + 1，这样就无需处理边界情况
//    //因为我们是对presum进行处理，presum记录前缀和的区间是[1:n]，所以先设置两个取不到的边界
//    st.insert(0); 
//    st.insert(n + 1);
//    // 记录所有子段和
//    multiset<long long> ms;
//    // 一开始只有一个子段和，也就是整个数组之和
//    ms.insert(presum[n]);
//    vector<long long> ans;
//    for (int pos : removeQueries) {
//        pos++;//加1的目的是为了把nums下标 对应到 presum下标去，后面就可以直接计算了
//        // 找出第一个比 pos 大的已删除下标 R，以及最后一个比 pos 小的已删除下标 L
//        auto it = st.upper_bound(pos);
//        int L = *prev(it), R = *it;//L和R是已经删除的位置，所以都取不到，[L + 1, R - 1]是本次要处理的区间
//        // 删除下标 pos，把它也放入 st 中
//        st.insert(pos);
//        // 删除子段 [L + 1, R - 1] 的和
//        // presum[i]的真正定义是：nums数组的前 i 个数（从下标 0 到下标 i-1）相加的和，也就是说 
//        // presum[0]= 0，presum[1]= nums[0]...
//        // 若我们想求[left：right]的区间和（这里的left和right是指nums里面的下标）
//        // 则应该是 presum[right+1]-presum[left]
//        // 而如果用presum下标来表示的话，就应该是 presum[right_p]-presum[left_p-1]
//        // 这里的 right_p 就等于 right+1，left_p就等于 left+1
//        // 如果left和right是表示nums里面第几个数的话，就可以直接用 presum[right]-presum[left-1] 了
//        // 这里用的 L 和 R 是指 presum 里面的下标，所以可以这样写
//        ms.erase(ms.find(presum[R - 1] - presum[L]));
//        // 加入新子段 [L + 1, pos - 1] 的和
//        if (pos - L - 1 > 0)//pos=L+1的时候，就不需要记录左边新增小区间的和了，因为两个0连一块了，小区间不存在 
//            ms.insert(presum[pos - 1] - presum[L]);
//        // 加入新子段 [pos + 1, R - 1] 的和
//        if (R - pos - 1 > 0) 
//            ms.insert(presum[R - 1] - presum[pos]);
//        // 求出最大的子段和
//        if (ms.empty()) 
//            ans.push_back(0);
//        else 
//            ans.push_back(*prev(ms.end()));
//    }
//    for (auto i : ans)
//    {
//        cout << i << ' ';
//    }
//}
//*******************************************并查集**********************************************
//int main()
//{
//    vector<int> nums = { 1, 2, 5, 6, 1 }, removeQueries = { 3, 0, 2, 4, 1 };
//    int n = nums.size();
//    vector<int> fa(n + 1);
//    /*int fa[n + 1];
//    iota(fa, fa + n + 1, 0);以递增的方式填充数组*/
//    for (int i = 0; i <= n; i++)
//    {
//        fa[i] = i;
//    }
//    vector<long long> sum(n + 1, 0);//sum[i]表示以元素nums[i]为“帮主”的并查集的和
//    //找“帮主”
//    function<int(int)> find = [&](int x) -> int { return fa[x] == x ? x : fa[x] = find(fa[x]); };//路径压缩
//
//    vector<long long> ans(n);//删除完所有数后或者说没有添加数前，和一定为0,
//    for (int i = n - 1; i > 0; --i) 
//    {//倒着添加数，更方便，i不用等于0，因为我们是倒叙遍历，i=1的时候就相当于添加了 n-1 个数
//        //此时的子段最大值 等于 我们删除 1 个数以后的子段最大值，i=0的时候相当于添加了 n 个数（所有数都添加了）
//        //i=n-1的时候就相当于添加了 1 个数，所以我们只需要更新ans的倒数第二个数就可以了
//        //因为 ans的最后一个数相当于 添加了 0个数，一定是0
//        int x = removeQueries[i];//要添加的那个下标 x 
//        int to = find(x + 1);
//        //我们以每个子段最后一个数作为“帮主”，现在我们要添加 x
//        //如果 x+1 已经被添加过了，则他一定有一个“帮主”，就是to
//        //我们就把 x 也添加到 to 这个“帮派”里面去
//        //如果 x+1 没有被添加过，则 x 就把 x+1 当成他的虚拟“帮主”，也就是说，此时的 to 就是 x+1
//        //等到 x+1 被添加的时候，就可以直接把 x+1 这个虚拟“帮主”添加到后面的子段帮主或者是一个新的虚拟“帮主”
//        //这样我们添加 x 以后就不需要考虑把前面的子段也合并了，因为之前的处理已经算是合并到虚拟“帮主” x 下了
//        fa[x] = to;
//        //to 这个帮派的和要加上相应的数，首先nums[x]先被加进去，没什么问题
//        //然后，假如 x 前面也有一个子段“帮派”，他们把 x 作为他们的虚拟“帮主”，因为之前 x 还没被添加
//        //所以是虚拟的，那么我们现在添加了 x，真正形成了一个“帮派”，这样就可以顺利合并到新帮主 to 下面了
//        //当前，这个新帮主也可以是一个虚拟的，等待真正的添加
//        sum[to] += nums[x] + sum[x];
//        //ans[n-1]是没有添加数之前的最大字段和，一定是0
//        //我们添加一个数以后，新的子段最大值有可能是原来的子段最大值，或者是新合并的这个帮派 to 的最大值
//        ans[i - 1] = max(ans[i], sum[to]);
//    }
//    for (auto i : ans)
//    {
//        cout << i << ' ';
//    }
//}

/////////////////////////////////////////2386. 找出数组的第 K 大和///////////////////////////

//https://leetcode.cn/problems/find-the-k-sum-of-an-array/solution/zhuan-huan-dui-by-endlesscheng-8yiq/
//所有可能获得的子序列和列出如下，按递减顺序排列：
//6、4、4、2、2、0、0、-2
//数组的第 5 大和是 2 。
//int main()
//{
//    vector<int> nums = { 2, 4, -2 };
//    int k = 5;
//    long sum = 0L;
//    //·sum记录最大和，他一定是第一大的子序列和，因为是所有正数相加的和
//    //后续的较小的和就是通过将 sum 减去一个正数（也就是从 所有正数 序列中去掉某个正数）
//    //或者是将 sum 加上一个负数（也就是向 所有正数 序列中添加某个负数），这样都能使 sum 变小一点。
//    //·那么如何找到第 k 个最大？
//    //从 sum 中减去 最小 的正数或加上 最大 的负数，就能得到第二大的子序列和
//    //·为了统一操作，将负数取反，然后排序，每次取最小的数，得到的就是 最小 的正数或 最大 的负数。
//    //sum 中减去或加上它，就可以得到下一个更小的子序列和，当然在遍历过程中都是正数，
//    //我们不知道应该减去它还是加上它，所以应该取可能得到的最大值。
//    for (int& x : nums)
//        if (x >= 0) 
//            sum += x;//最大和
//        else x = -x;//全部变成正数
//    sort(nums.begin(), nums.end());//从小到大排序，优先处理 绝对值小 的数，这样保证得到的子序列和是从大到小递减的
//    priority_queue<pair<long, int>> pq;
//    //记录当前的最大值和，以及 当前要减去的数的下标/下一步要加上的数的下标
//    //·当前减去是因为我们先假设 当前这个正数 原本就是正数，那么它就是最小的正数，
//    //  从sum里面减去它，可能得到下一个最大和
//    //·下一步加上是因为我们再假设 当前这个正数 原本是负数，那么他就是最大的负数
//    //  从sum里面加上它，可能得到下一个最大和
//    pq.emplace(sum, 0);//0表示我们现在要先减去 nums[0]
//    while (--k) 
//    {//只需要找出 k-1 个次大的和，每个k末尾时的堆顶就是 第（K+1-k）个最大值，所以当 k=1这个循环结束时
//        //堆顶就是第 K 个最大值，然后 --k = 0，退出循环
//        sum = pq.top().first;
//        int i = pq.top().second;
//        pq.pop();
//        //在第 m 次循环中，我们首先认为 nums[i] 是正数，考虑从sum里面减去它，可能得到下一个最大和
//        //这时对于 nums[i-1]有两种考虑，1是仍然认为它是正数，则不需要去管它，因为上一步已经减过了
//        //2是认为它是负数，则需要在 减去nums[i]的情况下 加上nums[i-1]
//        //也就是说，对于一个数，第一循环先减去它，第二次循环再去考虑是否要加上它，这样就能得到所有数的可能组合
//        //比如，对于 i=0，第一次先减去nums[0]，用二进制序列可表示为“0111...”（状态压缩）
//        //对于 i=1，第一次先减去nums[1]，然后考虑是否加上 nums[0]，如果不加，那么可表示为“0011...”
//        //如果加上，那么可表示为 “1011...”
//        //对于 i=2，第一次先减去nums[2]，让考虑是否加上 nums[1]，如果不加，那么可表示为“0001”或者是“1001”
//        //如果加上，那么可表示为“0101”或者“1101”
//        //可以发现，每一个二进制表示其实就是一种可能性，通过优先队列来决定谁最大，然后在这个最大值的基础上进行
//        //下一次判断
//        if (i < nums.size()) 
//        {//i 必须是合理的
//            pq.emplace(sum - nums[i], i + 1);
//            //当前我们要先减去 nums[i]（认为它原本是正数），然后下一步应该把 nums[i+1] 试着减去
//            if (i > 0)
//            {//i > 0是因为上面我们只是把nums[i-1]假设原本是正数
//                pq.emplace(sum - nums[i] + nums[i - 1], i + 1); // 不保留 nums[i-1]，把之前减去的加回来
//            }
//        }
//    }
//    cout << pq.top().first;
//    return 0;
//}

/////////////////////////////////////////1470. 重新排列数组///////////////////////////

//https://leetcode.cn/problems/shuffle-the-array/solution/by-muse-77-eh8g/
//int main()
//{
//    vector<int> nums = { 2,5,1,3,4,7 };
//    int n = 3;
//    for (int i = 0; i < 2 * n; i++) 
//    {//i是原本的下标，j是最后应该在的下标，处于数组前半段时，最后应该在 2*i的位置上
//        //比如，i=0对应 j=0，i=1对应 j=2，i=2,对应j=4
//        //后半段的话，相当于先往左移动 n 个数，然后在按上面的规则那样放进去
//        int j = i < n ? 2 * i : 2 * (i - n) + 1;
//        nums[j] |= (nums[i] & 1023) << 10;//nums[i] & 1023 记录的是原有的值
//    }
//    for (int& e : nums) 
//        e >>= 10;
//    for (auto i : nums)
//    {
//        cout << i << ' ';
//    }
//}

/////////////////////////////////////////2389. 和有限的最长子序列///////////////////////////

//https://leetcode.cn/problems/longest-subsequence-with-limited-sum/solution/fei-bao-li-zuo-fa-qian-zhui-he-er-fen-by-ny4m/
//给你一个长度为 n 的整数数组 nums ，和一个长度为 m 的整数数组 queries 。
//返回一个长度为 m 的数组 answer ，其中 answer[i] 是 nums 中 元素之和小于等于 queries[i] 的 子序列 的 最大 长度  。
//queries 对应的 answer 如下：
//- 子序列[2, 1] 的和小于或等于 3 。可以证明满足题目要求的子序列的最大长度是 2 ，所以 answer[0] = 2 。
//- 子序列[4, 5, 1] 的和小于或等于 10 。可以证明满足题目要求的子序列的最大长度是 3 ，所以 answer[1] = 3 。
//- 子序列[4, 5, 2, 1] 的和小于或等于 21 。可以证明满足题目要求的子序列的最大长度是 4 ，所以 answer[2] = 4 。
//int main()
//{
//    vector<int> nums = { 4, 5, 2, 1 }, queries = { 3, 10, 21 };
//    sort(nums.begin(), nums.end());//由于想找的是子序列之和，所以需要保证顺序
//    int n = nums.size();
//    for (int i = 1;i < n;++i)
//        nums[i] += nums[i - 1];//原地计算前缀和
//    vector<int> res;
//    for (int x : queries) 
//    {//找到第一个大于 queries[i] 的前缀和，它的前面的前缀和一定小于等于 queries[i]
//        res.push_back(upper_bound(nums.begin(), nums.end(), x) - nums.begin());
//    }
//    for (auto i : res)
//    {
//        cout << i << ' ';
//    }
//}

/////////////////////////////////////////2397. 被列覆盖的最多行数///////////////////////////

//https://leetcode.cn/problems/maximum-rows-covered-by-columns/solution/c-by-liu-xiang-3-htvj/
//给你一个下标从 0 开始的 m x n 二进制矩阵 mat 和一个整数 cols ，表示你需要选出的列数。
//如果一行中，所有的 1 都被你选中的列所覆盖，那么我们称这一行 被覆盖 了。
//请你返回在选择 cols 列的情况下，被覆盖 的行数 最大 为多少。
//int main()
//{
//    vector<vector<int>> mat = { {0, 0, 0},{1, 0, 1},{0, 1, 1},{0, 0, 1} };
//    int cols = 2;
//    int n = mat.size(), m = mat[0].size();//总共n行m列
//    int ans = 0;
//    for (int i = 0; i < (1 << m); i++) 
//    {//从m列中随便选择，总共有 2^m 种选择方案，分别枚举
//        //因为m最大是12，所以不会超时
//        int cnt = 0;// 统计是否恰好选择 cols 列
//        for (int j = 0; j < m; j++)
//            cnt += i & (1 << j);
//        if (cnt != cols) 
//            continue;//必须选中cols列才行
//        // 统计被覆盖的行
//        cnt = 0;
//        for (int j = 0; j < n; j++) 
//        {//统计每一行
//            bool flag = true;
//            for (int k = 0; k < m; k++)
//                //对于这一行的所有列
//                // 该列为 1 但没有被覆盖，因此该行没有被覆盖
//                if (mat[j][k] == 1 && (i & (1<<k)) == 0)
//                {
//                    flag = false;
//                    break;
//                }
//            if (flag)
//                cnt++;
//        }
//        ans = max(ans, cnt);//最大行数
//    }
//    return ans;
//}

/////////////////////////////////////////2398. 预算内的最多机器人数目///////////////////////////

//https://leetcode.cn/problems/maximum-number-of-robots-within-budget/solution/by-endlesscheng-7ukp/
//运行 k 个机器人 总开销 是 max(chargeTimes) + k * sum(runningCosts) ，
//其中 max(chargeTimes) 是这 k 个机器人中最大充电时间，sum(runningCosts) 是这 k 个机器人的运行时间之和。
//请你返回在 不超过 budget 的前提下，最多可以有多少个机器人可以连续运行。
//int main()
//{
//    vector<int> chargeTimes = { 8,17,5,2 }, runningCosts = { 1,14,4,1 };
//    int budget = 17;
//    int ans = 0;
//    deque<int> q;//单调递减队列，不能用优先队列是因为pq无法去除前面不属于当前区间的最大值
//                //也就是说，有可能出现以下情况：
//                // 当前区间左端点是最大的，但是他不满足条件，因此我们要将其从优先队列中去除
//                // 去除之后 由于我们不会将之前区间出现过的最大值清除出优先队列，就会造成
//                // 最大值是前面区间的，而 和 是当前区间的情况
//                // 单调队列不会出现这种情况，因为假如当前当前左端点是最大的，它在进入单调队列的时候会将
//                // 所有之前区间的的最大值全都清除，因此如果他不满足条件，队列就成空了，不会出现上面的情况
//    long sum = 0L;
//    // 枚举区间右端点 right，挪动左端点 left ，计算该区间的花费
//    for (int left = 0, right = 0; right < chargeTimes.size(); ++right) 
//    {//每次都换一个右端点重新挪动左端点，找到满足条件的最大区间，相当于变长的滑动窗口
//        // 及时清除队列中的无用数据，保证队列的单调性
//        while (!q.empty() && chargeTimes[right] >= chargeTimes[q.back()])
//            q.pop_back();
//        q.push_back(right);
//        sum += runningCosts[right];//记录区间的和
//        // 如果左端点 left 不满足要求，就不断右移 left
//        //chargeTimes[q.front()]就是max(chargeTimes)，(right - left + 1) * sum就是k * sum(runningCosts)
//        while (!q.empty() && chargeTimes[q.front()] + (right - left + 1) * sum > budget) {
//            // 及时清除队列中的无用数据，保证队列的单调性
//            if (q.front() == left) 
//                //为什么只要等于左端点而不是小于等于左端点？
//                //假如有某个最大值不在当前区间，并且不满足条件，那么之前遍历的时候，他肯定有作为左端点的时候
//                //以他为左端点的区间如果不满足条件的话，他就会被弹出，不会出现在后面的区间里，因此不需要考虑小于等于
//                //当然写成小于等于也没关系
//                q.pop_front();//我们要把左端点右移，如果左端点的值是此区间的最大值，并且区间不满足条件，就需要从单调队列中去除
//            sum -= runningCosts[left++];
//        }
//        ans = max(ans, right - left + 1);
//    }
//    return ans;
//}

/////////////////////////////////////////658. 最接近 x 的 k 个数///////////////////////////

//https://leetcode.cn/problems/find-k-closest-elements/solution/zhao-dao-k-ge-zui-jie-jin-de-yuan-su-by-ekwtd/
//给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。
//整数 a 比整数 b 更接近 x 需要满足：
//| a - x | < | b - x | 或者
//| a - x| == |b - x | 且 a < b
//假设数组长度为 n，注意到数组 arr 已经按照升序排序，我们可以将数组 arr 分成两部分，
//前一部分所有元素[0, left] 都小于 x，后一部分所有元素[right, n−1] 都大于等于 x，left 与 right 都可以通过二分查找获得。
//left 和 right 指向的元素都是各自部分最接近 x 的元素，因此我们可以通过比较 left 和 right 指向的元素获取整体最接近 x 的元素。
//如果 x-arr[left]<=arr[right]-x，那么将 left 减一，否则将 right 加一。相应地，如果 left 或 right 已经越界，那么不考虑对应部分的元素。
//最后，区间[left + 1, right−1] 的元素就是我们所要获得的结果，返回答案既可。
//int main()
//{
//    vector<int> arr = { 1,2,3,4 };
//    int k = 4, x = -1;
//    int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
//    int left = right - 1;
//    while (k--) {//每次只加入一个值
//        if (left < 0) {//左边已经越界
//            right++;
//        }
//        else if (right >= arr.size()) {//右边已经越界
//            left--;
//        }
//        else if (x - arr[left] <= arr[right] - x) {//左边的值更接近x
//            left--;
//        }
//        else {//右边的值更接近x
//            right++;
//        }
//    }
//    for (auto i : vector<int>(arr.begin() + left + 1, arr.begin() + right))//退出循环时left和right都是未经过检查的，因此不能取
//    {
//        cout << i << ' ';
//    }
//    return 0;
//}

/////////////////////////////////////////662. 二叉树最大宽度///////////////////////////

//https://leetcode.cn/problems/maximum-width-of-binary-tree/solution/er-cha-shu-zui-da-kuan-du-by-leetcode-so-9zp3/1724500
//求每一层的宽度时，因为两端点间的 null 节点也需要计入宽度，因此可以对节点进行编号。
//一个编号为 index 的左子节点的编号记为 2×index，右子节点的编号记为 2×index + 1，
//计算每层宽度时，用每层节点的最大编号减去最小编号再加 11 即为宽度。
//int main()
//{
//    TreeNode* one = new TreeNode(5);
//    TreeNode* two = new TreeNode(3);
//    TreeNode* thr = new TreeNode(9);
//    TreeNode* fou = new TreeNode(3,one,two);
//    TreeNode* fiv = new TreeNode(2,nullptr,thr);
//    TreeNode* root = new TreeNode(1,fou,fiv);
//    unsigned long long res = 1;
//    vector<pair<TreeNode*, unsigned long long>> arr;//节点与其对应的编号 ，如果树高度很高，就会造成某一层节点的编号非常大，所以要用unsigned long long
//    arr.emplace_back(root, 1L);
//    while (!arr.empty()) {
//        vector<pair<TreeNode*, unsigned long long>> tmp;//用来记录下一层的所有节点编号
//        for (auto& [node, index] : arr) {
//            if (node->left) 
//            {//只有下一层节点存在才能记录，这样保证了tmp中全部都是有效编号
//                tmp.emplace_back(node->left, index * 2);
//            }
//            if (node->right) 
//            {
//                tmp.emplace_back(node->right, index * 2 + 1);
//            }
//        }
//        res = max(res, arr.back().second - arr[0].second + 1);//每一层都重新计算最大宽度
//        arr.swap(tmp);//为下一层做准备
//    }
//    return res;
//}
//因题目保证了答案在int范围内，所以不会出现某一层超过int个节点的情况，如果我们能把每一层都从 0 开始标下标，就可以用int来ac
//① 找到本层第一个有子节点的节点的index，记为first
//② 向下一层传坐标index时，以first为起点，先减去first再执行 * 2 或 * 2 + 1 操作
//  这样每一层的节点编号就代表它是 本层 的第几个节点，而不是整棵树的第几个节点，就不会出现非常大的编号了
//int widthOfBinaryTree(TreeNode* root) {
//    int ans = -1;
//    queue<pair<TreeNode*, int>> Queue;
//    Queue.emplace(root, 1);
//    while (!Queue.empty()) {
//        int size = Queue.size();
//        int left = Queue.front().second;//本层的最左边节点编号
//        int right;
//        int first = -1; //找第一个有孩子节点的下标
//        while (size--) {
//            TreeNode* curr = Queue.front().first;
//            right = Queue.front().second;//每次都刷新最右边节点编号，其实只需要记录本层最后一个节点编号就行了
//            ans = max(ans, right - left + 1);
//            Queue.pop();
//            if (first == -1 && (curr->left || curr->right)) 
//            {//记录本层第一个有子节点的结点编号
//                first = right;
//            }
//            if (curr->left) {// 以first为起点，保证下一层第一个节点下标为0,最后节点下标也不会超int
//                Queue.emplace(curr->left, (right - first) * 2); //right是当前节点编号
//            }
//            if (curr->right) {
//                Queue.emplace(curr->right, (right - first) * 2 + 1);
//            }
//        }
//    }
//    return ans;
//}

/////////////////////////////////////////25. K 个一组翻转链表///////////////////////////

//https://leetcode.cn/problems/reverse-nodes-in-k-group/solution/k-ge-yi-zu-fan-zhuan-lian-biao-by-leetcode-solutio/
//void reverse(ListNode* head, ListNode* tail)
//{
//    ListNode* pre = nullptr;
//    ListNode* nex = tail->next;
//    ListNode* p = head;
//    while (p!=nex)
//    {
//        ListNode* next = p->next;
//        p->next = pre;
//        pre = p;
//        p = next;
//    }
//}
//ListNode* reverseKGroup(ListNode* head, int k) {
//    ListNode* dummyhead = new ListNode(0, head);
//    ListNode* tail = dummyhead, * pre = dummyhead;
//    while (head)
//    {
//        for (int i = 0; i < k; i++)
//        {//先找到 k 个链表
//            tail = tail->next;
//            if (!tail)
//            {
//                return dummyhead->next;
//            }
//        }
//        ListNode* next = tail->next;//先记录一下下一组的开头节点
//        reverse(head, tail);//翻转这一组
//        pre->next = tail;//pre代表上一组的最后一个节点
//        head->next = next;
//        pre = tail = head;//pre变成这一组的最后一个节点
//        head = next;//下一组的头结点
//    }
//    return dummyhead->next;
//}
//int main()
//{
//    ListNode* one = new ListNode(5);
//    ListNode* two = new ListNode(4,one);
//    ListNode* thr = new ListNode(3,two);
//    ListNode* fou = new ListNode(2,thr);
//    ListNode* fiv = new ListNode(1,fou);
//    reverseKGroup(fiv, 2);
//}

/////////////////////////////////////////646. 最长数对链///////////////////////////

//要挑选最长数对链的第一个数对时，最优的选择是挑选第二个数字最小的，这样能给挑选后续的数对留下更多的空间。
//挑完第一个数对后，要挑第二个数对时，也是按照相同的思路，
//是在剩下的数对中，第一个数字满足题意的条件下，挑选第二个数字最小的
//按照这样的思路，可以先将输入按照第二个数字排序，
//然后不停地判断第一个数字是否能满足大于前一个数对的第二个数字即可。
//https://leetcode.cn/problems/maximum-length-of-pair-chain/solution/zui-chang-shu-dui-lian-by-leetcode-solut-ifpn/
//int main()
//{
//    vector<vector<int>> pairs = { { 7,9},{4,5},{7,9},{-7,-1},{0,10},{3,10},{3,6},{2,3 }};
//    int curr = INT_MIN, res = 0;
//    sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
//        return a[1] < b[1];
//        });
//    for (auto& p : pairs) {
//        if (curr < p[0]) {
//            curr = p[1];
//            res++;
//        }
//    }
//    return res;
//}

/////////////////////////////////////////2400. 恰好移动 k 步到达某一位置的方法数目///////////////////////////

//https://leetcode.cn/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/solution/by-tsreaper-qzp3/
//int dp[3000][1005] = {}, mod = 1e9 + 7;// dp[i][j]: 从i出发再走j步到达endpos的方法数
//int dfs(int x, int step, int endPos) {
//    if (step == 0) 
//        return endPos == x;
//    if (dp[x + 1000][step] != -1) 
//        return dp[x + 1000][step];    // 已经计算过，不再重复计算
//    dp[x + 1000][step] = 0;     // 未计算，初始化为0
//    // 枚举下一步往左或者往右，累加即为答案
//    // 因为负数的原因，将坐标整体向右移动1000
//    dp[x + 1000][step] = (dfs(x + 1, step - 1, endPos) + dfs(x - 1, step - 1, endPos)) % mod;
//    return dp[x + 1000][step];
//}
////存在 3 种从 1 到 2 且恰好移动 3 步的方法：
//// 1 -> 2 -> 3 -> 2.
//// 1 -> 2 -> 1 -> 2.
//// 1 -> 0 -> 1 -> 2.
//int main()
//{
//    int startPos = 1, endPos = 2, K = 3;
//    memset(dp, -1, sizeof(dp));
//    cout << dfs(startPos, K, endPos); 
//    //***********************************组合数学****************************************
//    //称 startPos 指向 endPos 的方向为正方向，startPos 远离 endPos 的方向为负方向。
//    //设从 startPos 出发，往正方向走了 a 步，往负方向走了(k - a) 步后到达 endPos，根据组合数的定义可知答案为C(k,a) 
//    //（k 步里选 aa 步走正方向）。
//    //记 d = abs(endPos - startPos)，有方程 a - (k - a) = d，得 a = （d + k）/2。
//    //因此首先判断是否(d + k)是偶数（这样才能求出整数的 a），以及 d<=k（否则走不到），然后求组合数即可。
//    //可以用的递推式C(i,j)=C(i-1,j-1)+C(i-1,j)求组合数，复杂度O（k^2)。
//    //int d = abs(startPos - endPos);//起点终点之间的距离
//    //if ((d + K) % 2 == 1 || d > K) 
//    //  return 0;
//    //// 递推求组合数
//    //vector<vector<long long>> f(K + 1, vector<long long>(K + 1));
//    //for (int i = 0; i <= K; i++) {
//    //    f[i][0] = 1;
//    //    for (int j = 1; j <= i; j++) 
//    //      f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % MOD;
//    //}
//    //cout<< f[K][(d + K) / 2];
//    //
//    //也可以通过C(k,i)=((k-i+1)/i)*C(k,i-1) 的递推式 O(k) 求组合数，需要用到乘法逆元。
//    //int d = abs(startPos - endPos);
//    //if ((d + K) % 2 == 1 || d > K) return 0;
//    //// 线性求逆元
//    //vector<long long> inv(K + 1);
//    //inv[1] = 1;
//    //for (int i = 2; i <= K; i++) 
//    //  inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
//    //// 递推求组合数，初值 C(k, 0) = 1
//    //long long ans = 1;
//    //for (int i = 1; i <= (d + K) / 2; i++) 
//    //  ans = ans * (K - i + 1) % MOD * inv[i] % MOD;
//    //return ans;
//}


//int main()
//{
//    vector<int> nums = { 1, 3, 8, 48, 10 };
//    int j = 0;//左端点
//    int ans = 1;
//    int mask = 0;//窗口内所有数的 二进制 记录
//    for (int i = 0; i < nums.size(); i++) //右端点
//    {
//        while (mask & nums[i]) { /* 不满足条件, 窗口收缩, 更新状态 */
//            mask ^= nums[j++];
//        }
//        ans = max(ans, i - j + 1);
//        mask |= nums[i]; /* 窗口变大 */
//    }
//    cout<< ans;
//}

//int main()
//{
//    vector<vector<int>> intervals = { {5, 10},{6, 8}, {1, 5},{2, 3},{1, 10} };
//    sort(intervals.begin(), intervals.end());
//    priority_queue<int, vector<int>, greater<int>> pq;
//    for (auto& vec : intervals) {
//        // 判断是否存在一组（结束时间最小的组）使得它的结束时间小于当前区间的开始时间
//        if (!pq.empty() && pq.top() < vec[0]) //这里是if，也就是最多只需要找到一组就可以了，不是while
//            pq.pop();
//        pq.push(vec[1]);
//    }
//    return pq.size();
//}

/////////////////////////////////////////986. 两个区间列表的交集///////////////////////////

//https://leetcode.cn/problems/interval-list-intersections/solution/qu-jian-lie-biao-de-jiao-ji-by-leetcode/1360013
//int main()
//{
//    vector<vector<int>> firstList = { {0, 2},{5, 10},{13, 23},{24, 25} }, secondList = { {1, 5},{8, 12},{15, 24},{25, 26} };
//    int i = 0, j = 0;
//    int n = firstList.size(), m = secondList.size();
//    vector<vector<int>> res;
//    /*
//       双指针:
//       指针i表示A集合中区间的索引,那么A[i][0]和A[i][1]分别表示区间A[i]的左右边界
//       指针j表示B集合中区间的索引,那么B[j][0]和B[j][1]分别表示区间B[j]的左右边界
//       左边界start取两个区间左边界较大值,右边界end取两个区间右界较小值
//       若start<=end则可以形成区间,将[start,end]加入结果
//       指针移动:看谁的右边界较小,较小的右边界后面不可能有交集了,因此根据右边界大小移动i与j指针
//       相同的话就同时移动
//       具体地:A[i][1]>B[j][1],j++;A[i][1]<B[j][1],i++
//       循环至两个区间组都到达末尾就结束
//    */
//    while (i < n && j < m)
//    {
//        int max_left = max(firstList[i][0], secondList[j][0]);
//        int min_right = min(firstList[i][1], secondList[j][1]);
//        if (max_left <= min_right)
//        {
//            res.push_back({ max_left,min_right });
//        }
//        if (firstList[i][1] >= secondList[j][1])
//        {
//            j++;
//        }
//        if (firstList[i][1] <= secondList[j][1])
//        {
//            i++;
//        }
//    }
//}

/////////////////////////////////////////857. 雇佣 K 名工人的最低成本///////////////////////////

//https://leetcode.cn/problems/minimum-cost-to-hire-k-workers/solution/yi-bu-bu-ti-shi-ru-he-si-kao-ci-ti-by-en-1p00/
//有 n 名工人。 给定两个数组 quality 和 wage ，其中，quality[i] 表示第 i 名工人的工作质量，其最低期望工资为 wage[i] 。
//现在我们想雇佣 k 名工人组成一个工资组。在雇佣 一组 k 名工人时，我们必须按照下述规则向他们支付工资：
//对工资组中的每名工人，应当按其工作质量与同组其他工人的工作质量的比例来支付工资。
//工资组中的每名工人至少应当得到他们的最低期望工资。
//给定整数 k ，返回 组成满足上述条件的付费群体所需的最小金额 
//输入： quality = [3, 1, 10, 10, 1], wage = [4, 8, 2, 2, 7], k = 3
//输出： 30.66667
//解释： 我们向 0 号工人支付 4，向 2 号和 3 号分别支付 13.33333。
//·在最优发工资方案下，至少有一名工人，发给他的工资恰好等于他的最低期望工资。
//    反证：假设不存在这样的工人，那么发给每名工人的工资都高于其最低期望工资，
//    我们可以把每人的工资都下调，从而得到更优的方案，矛盾。
//·枚举发了最低期望工资的那名工人，在满足题干中规则 1 的前提下，哪些工人可以满足规则 2？
//    如何快速地求出这些工人？
//·定义 r[i]=wage[i]/quality[i]，表示「每单位工作质量的工资」。若以 k 名工人中最高的 r[i] 为基准（记为r_max)发工资，
//    那么对于 r 值不超过 r_max的工人，发给他们的工资是不低于其最低期望工资的，
//    w[i]（实际）= r_max * q[i] >= w[i]（最低）=r[i] * q[i]，那么按照 r[i] 从小到大排序，我们便可以快速地求出这些工人。
//·设这 k 名工人的 quality 之和为 sumQ，若以 r_max ​为基准发工资，那么发的工资总额为 sumQ * r_max​
//    因为 w[i]（实际）= r_max * q[i]，因此 sumQ 越小发的工资总额就越小，因此我们需要在从小到大枚举 r[i]
//    维护当前最小的 k 个 quality 值。
//·用一个最大堆来维护。按照 r[i] ​从小到大的顺序遍历，当堆中有 k 个元素时，如果 quality[i]​比堆顶小，
//    则可以弹出堆顶，将 quality[i]​ 入堆，从而得到一个更小的 sumQ，此时有可能找到一个更优解 sumQ * r[i],更新答案。
//typedef pair<double, int> pdi;//<r[i],q[i]>记录单位工资和对应的质量
//int main()
//{
//    vector<int> quality = { 3,1,10,10,1 }, vector<int> wage = { 4,8,2,2,7 };
//    int k = 3;
//    int n = quality.size();
//    vector<pdi> ri;
//    for (int i = 0;i < n;i++)
//    {
//        ri.push_back(make_pair((double)wage[i] / quality[i], quality[i]));//计算单位质量的工作
//    }
//    sort(ri.begin(), ri.end());//从小到大排序
//    priority_queue<int> pq;
//    int i = 0, sumQ = 0;
//    for (;i < k;i++)
//    {//记录前k个工人
//        sumQ += ri[i].second;//记录总质量
//        pq.push(ri[i].second);
//    }
//    //ri是经过排序的，所以ri[k - 1].first是前 k 个工人中最大的 r_max，以他为基准发工资一定满足要求（就是给他发最低工资）
//    double res = sumQ * ri[k - 1].first;//k 个工资总工资的初始值
//    for (;i < n;i++)
//    {
//        if (ri[i].second < pq.top())
//        {//出现了一个更小的q[i]，选择这名工人可以使sumQ减小，从而可能减少最低工资
//            sumQ -= pq.top();//从当前的sumQ里面减去最大的 q[i]
//            sumQ += ri[i].second;//加上当前工人的 q[i]
//            pq.pop();//优先队列也要做相应调整
//            pq.push(ri[i].second);
//        }
//        res = min(res, sumQ * ri[i].first);//更新最低总工资
//    }
//    cout<<res;
//}

/////////////////////////////////////////程序微秒计时///////////////////////////

//int main()
//{
//    clock_t start, finish;
//    double totaltime;
//    start = clock();
//    for (int i = 0;i < 10000000;i++)
//    {
//        ;
//    }
//    finish = clock();
//    totaltime = (double)(finish - start) / CLOCKS_PER_SEC*1000000;
//    cout << totaltime << "微秒";
//}

/////////////////////////////////////////887. 鸡蛋掉落///////////////////////////

//输入：k = 1, n = 2
//输出：2
//解释：
//鸡蛋从 1 楼掉落。如果它碎了，肯定能得出 f = 0 。
//否则，鸡蛋从 2 楼掉落。如果它碎了，肯定能得出 f = 1 。
//如果它没碎，那么肯定能得出 f = 2 。
//因此，在最坏的情况下我们需要移动 2 次以确定 f 是多少。
//https://blog.csdn.net/qq_39144436/article/details/123617917
//https://leetcode.cn/problems/super-egg-drop/solution/dong-tai-gui-hua-zhi-jie-shi-guan-fang-ti-jie-fang/
//int main()
//{
//    /*
//       dp+二分:参考liweiwei的题解比较好懂(太难了了解即可)
//       dp五部曲:
//       1.状态定义:dp[i][j]表示总楼层数为i(注意是总楼层数),鸡蛋数为 j 时确定 f（鸡蛋破碎的临界楼层）的最少操作次数
//       2.状态转移:dp[i][j]=min<k∈[1,i]>(max(dp[k-1][j-1],dp[i-k][j])+1),其中外层min的k∈[1,i]
//           其中dp[k-1][j-1]为鸡蛋从 k 楼扔下碎了:那么f只可能是[1,k-1],鸡蛋数-1
//               dp[i-k][j]为鸡蛋从 k 楼扔下没碎:那么f只可能是[k+1,i],鸡蛋数不变
//               两者中取较大的值,这是鸡蛋碎与不碎的最坏情况下转移过来的dp[i][j],也就是保证能找出 f 的最少次数
//               +1当前在 k 楼扔鸡蛋的这一次
//               而最小操作次数怎么算?很显然就是在尝试所有楼层分别扔一次然后取最少的操作数来确定这个 f 出自哪里
//               因为这个k取值范围内的都是合格的范围,所以要找出最少的操作数必然要在[1,i]内进行比较
//               说白了:max比较出 k 层碎与不碎的最坏情形;min负责找出[1,i]这么多最坏情形决策行为的最小操作数
//       3.初始化:从转移方程来看的话,i=0,1与j=0,1需要初始化
//       4.遍历顺序:显然是正序遍历
//       5.返回形式:直接返回dp[n][k]就是所求
//       时间复杂度:O(nklogn),空间复杂度:O(nk)
//       */
//    int k = 1, n = 2;
//    // 初始化
//    // 要与原来的dp比较求小的值,必定要初始化为最大值才不会对第一个值大的比较产生影响
//    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
//    // 初始化i=0,1与j=0,1
//    // j=0时,鸡蛋数目为0:操作数怎样都是0(无法操作)
//    // j=1时,鸡蛋数目为1:当楼层数n>=1时候为n,因为只有一个鸡蛋，只能一层一层试
//    for (int i = 1; i <= n; i++) {
//        dp[i][0] = 0;
//        dp[i][1] = i;
//    }
//    // i=0时,楼层数目为0:操作数怎样都是0(无法上楼)
//    for (int j = 0; j <= k; j++) 
//    {
//        dp[0][j] = 0;
//    }
//    // i=1时,楼层数目为1:当鸡蛋数j>=1时候为1,只需要扔一次即可
//    for (int j = 1; j <= k; j++) {
//        dp[1][j] = 1;
//    }
//    // 之后遍历范围为i∈[2,n],j∈[2,k]
//    for (int i = 2; i <= n; i++) {
//        for (int j = 2; j <= k; j++) {
//            // 通过二分法在区间[1,i]确定一个最优值，注意这里的总楼层为 i，也就是本次我们猜测的 k 就在 [1:i]之间
//            // 当然i=1已经初始化了，所以从2直接开始
//            int left = 1, right = i;
//            int ans;
//            // 这里用二分查找k∈[1,i]中最小的那个dp(k)->一个v形函数
//            // 最低点在中间,可以通过二分在O(logn)时间复杂度内找到最小的k值
//            while (left <= right) {
//                int mid = left + (right - left) / 2;
//                // 碎了，就需要往低层继续扔：层数少 1 ，鸡蛋也少 1
//                // 不碎，就需要往高层继续扔：层数是当前层到最高层的距离差，鸡蛋数量不少
//                // 两种情况都做了一次尝试，所以加 1
//                int breakConut = dp[mid - 1][j - 1];    // 递增
//                int notBreakCount = dp[i - mid][j];     // 递减
//                //我们观察到 dp(n, k) 是一个关于 n 的单调递增函数，也就是说在鸡蛋数 k 固定的情况下，楼层数 n 越多，
//                //需要的步数一定不会变少。在上述的状态转移方程中，
//                //第一项 dp(mid−1, j−1) 是一个随 mid 的增加而单调递增的函数，
//                //第二项 dp(i−mid,j) 是一个随着 mid 的增加而单调递减的函数。
//                //这如何帮助我们来优化这个问题呢？当 x 增加时，T1(x) 单调递增而 T2(x) 单调递减，
//                //我们可以想象在一个直角坐标系中，横坐标为 x，纵坐标为 T1(x) 和T2(x) 。
//                //当一个函数单调递增而另一个函数单调递减时，我们如何找到一个位置使得它们的最大值最小呢？
//                //如上图所示，如果这两个函数都是连续函数，那么我们只需要找出这两个函数的交点，
//                //在交点处就能保证这两个函数的最大值最小
//                //breakConut=T1(x)，notBreakCount=T2(x)，所以当breakConut>notBreakCount,这时的mid一定位于交点的右边
//                //所以我们要往左边找，right = mid - 1;
//                if (breakConut > notBreakCount) {
//                    // 排除法（减治思想）写对二分见第 35 题，先想什么时候不是解
//                // 严格大于的时候一定不是解，此时 mid 一定不是解
//                // 下一轮搜索区间是 [left, mid - 1]                 
//                    right = mid - 1;
//                }
//                else {
//                    //否则的话，这时的mid一定位于交点的左边或者等于交点，所以我们先记录一下这个可能的答案，再往右边去找
//                    // 这个区间一定是上一个区间的反面，即 [mid, right]
//                    ans = mid;//此时mid有可能是答案，记录一下
//                    left = mid + 1;
//                }
//            }
//            //退出循环时，ans一定位于交点的左边或者等于交点（因为两个连续函数的交点不一定是整数）
//            //那么ans+1也是一个有可能的答案，所以要比较一下max(T1(ans),T2(ans))和max(T1(ans+1),T2(ans+1))的最小值
//            //也就是ans和ans+1谁更靠近交点，其实如果交点不是整数的话，ans和ans+1都是正确的值
//            //另外，这里我们其实只需要比较T2(ans)和T1(ans+1)的最小值就行了，因为交点左边，T2一定大于T1，交点右边T1一定大于T2
//            dp[i][j] = min(max(dp[ans - 1][j - 1], dp[i - ans][j]),
//                        max(dp[(ans + 1) - 1][j - 1], dp[i - (ans + 1)][j])) + 1;
//        }
//    }
//    return dp[n][k];
//}


//class Solution {
//public:
//    void func(vector<TreeNode*>& v)
//    {
//        for (int i = 0, j = v.size() - 1;i < j;i++, j--)
//        {
//            swap(v[i]->val, v[j]->val);
//        }
//    }
//    TreeNode* reverseOddLevels(TreeNode* root) {
//        if (!root)
//        {
//            return nullptr;
//        }
//        queue<TreeNode*> q;
//        q.push(root);
//        int depth = 0;
//        while (!q.empty())
//        {
//            int sz = q.size();
//            vector<TreeNode*> v;
//            while (sz--)
//            {
//                auto t = q.front();
//                q.pop();
//                if (depth & 1)
//                {
//                    v.push_back(t);
//                }
//                if (t->left)
//                {
//                    q.push(t->left);
//                }
//                if (t->right)
//                {
//                    q.push(t->right);
//                }
//            }
//            if (!v.empty())
//            {
//                func(v);
//            }
//        }
//        return root;
//    }
//};
//int main()
//{
//    TreeNode* one = new TreeNode(8);
//    TreeNode* two = new TreeNode(13);
//    TreeNode* thr = new TreeNode(21);
//    TreeNode* fou = new TreeNode(34);
//    TreeNode* fiv = new TreeNode(3,one,two);
//    TreeNode* six = new TreeNode(5,thr,fou);
//    TreeNode* root = new TreeNode(2,fiv,six);
//    Solution so;
//    so.reverseOddLevels(root);
//}


//class Solution {
//public:
//    struct StringTree
//    {
//        int cnt = 0;
//        vector<StringTree*> children;//利用vector实现，不能在声明的时候直接定义，需要在构造函数里定义
//        bool isEnd;//表示单词是否已经结束了，防止已经add的单词比search的单词多几个单词，比如已经add了badge，要查找bad这个单词，查找到d的时候发现index已经到头，但是此节点的isEnd是false，表示字典树里
//                  //没有bad但是有比bad多几个字母的单词，这时候应该返回false，不匹配
//        StringTree() :isEnd(false) {
//            this->children = vector<StringTree*>(26, nullptr);
//        }
//    };
//    StringTree* root = new StringTree();;//首先建立一个根节点
//    void addWord(string word)
//    {
//        int n = word.size();
//        StringTree* node = root;//root不能动，所以要新建一个结点node
//        for (int i = 0;i < n;i++)
//        {
//            if ((node->children[word[i] - 'a']) == nullptr)//不存在就新建
//            {
//                node->children[word[i] - 'a'] = new StringTree();
//            }
//            node = node->children[word[i] - 'a'];//向下转移
//            node->cnt++;
//        }
//        node->isEnd = true;//所有单词添加完毕，node指向最后一个字母的节点，那么此节点的isEnd赋值为true，表示单词结尾
//    }
//    int dfs(string s)
//    {
//        int n = s.size();
//        StringTree* node = root;//root不能动，所以要新建一个结点node
//        int ans = 0;
//        for (int i = 0;i < n;i++)
//        {
//            if ((node->children[s[i] - 'a']) == nullptr)//不存在就新建
//            {
//                return ans;
//            }
//            
//            node = node->children[s[i] - 'a'];//向下转移
//            ans += node->cnt;
//        }
//        return ans;
//    }
//    vector<int> sumPrefixScores(vector<string>& words) {
//        int n = words.size();
//        for (auto w : words)
//        {
//            addWord(w);
//        }
//        vector<int> res;
//        for (int i = 0;i < n;i++)
//        {
//            int k = dfs(words[i]);
//            res.push_back(k);
//        }
//        return res;
//    }
//};
//int main()
//{
//    vector<string> words = { "abc", "ab", "bc", "b" };
//    Solution so;
//    so.sumPrefixScores(words);
//}

/////////////////////////////////////////2409. 统计共同度过的日子数///////////////////////////

//https://leetcode.cn/problems/count-days-spent-together/solution/by-endlesscheng-3r0d/1759511
//vector<int> cnt{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//int getDay(string s) 
//{//日期统一转化为天数
//    int m = stoi(s.substr(0, 2)), d = stoi(s.substr(3));
//    return accumulate(cnt.begin(), cnt.begin() + m - 1, 0) + d;
//}
//int main()
//{
//    string arriveAlice = "04-22", leaveAlice = "12-31",arriveBob = "12-02",leaveBob = "12-14";
//    int st1 = getDay(arriveAlice), end1 = getDay(leaveAlice);
//    int st2 = getDay(arriveBob), end2 = getDay(leaveBob);
//    int res = 0;
//    res = max(min(end1, end2) - max(st1, st2) + 1, 0);//如果没有交集的话，min(end1, end2)<max(st1, st2),则
//                                                      //min(end1, end2) - max(st1, st2) + 1<=0，所以取最大值
//    cout << res;
//}

/////////////////////////////////////////2410. 运动员和训练师的最大匹配数///////////////////////////

//https://leetcode.cn/problems/maximum-matching-of-players-with-trainers/solution/pai-xu-shuang-zhi-zhen-by-endlesscheng-h54k/
//如果第 i 名运动员的能力值 小于等于 第 j 名训练师的能力值，那么第 i 名运动员可以 匹配 第 j 名训练师。
//除此以外，每名运动员至多可以匹配一位训练师，每位训练师最多可以匹配一位运动员。
//请你返回满足上述要求 players 和 trainers 的 最大 匹配数。
//输入：players = [4, 7, 9], trainers = [8, 2, 5, 8]
//输出：2
//解释：
//得到两个匹配的一种方案是：
//- players[0] 与 trainers[0] 匹配，因为 4 <= 8 。
//- players[1] 与 trainers[3] 匹配，因为 7 <= 8 。
//可以证明 2 是可以形成的最大匹配数。
//int main()
//{
//    vector<int> players = { 4, 7, 9 }, trainers = { 8, 2, 5, 8 };
//    sort(players.begin(), players.end()), sort(trainers.begin(), trainers.end());
//    int n = players.size(), m = trainers.size();
//    int i = 0, res = 0;//i表示运动员，j是教练
//    for (int j = 0;j < m;++j)
//    {
//        if (players[i] <= trainers[j])
//        {//满足条件,匹配，运动员指针后移，教练指针后移在for循环里
//            i++;
//            res++;
//        }
//        if (i >= n)//运动员已经匹配完了，退出循环
//            break;
//    }
//    cout<<res;
//}

/////////////////////////////////////////2411. 按位或最大的最小子数组长度///////////////////////////

//https://leetcode.cn/problems/smallest-subarrays-with-maximum-bitwise-or/solution/by-endlesscheng-zai1/
//我们可以把二进制数看成集合，二进制数第 i 位为 1 表示 i 在集合中。两个二进制数的或，就可以看成是两个集合的并集。
//对于两个二进制数 a 和 b，如果 a∣b = a，从集合的角度上看，b 对应的集合是 a 对应的集合的子集。
//据此我们可以提出如下改进后的算法：
//从左到右正向遍历 nums，对于 x = nums[i]，从 i - 1开始倒着遍历 nums[j]：
//相当于固定右端点，依次更新左端点的值
//·如果 nums[j]∣x != nums[j]，说明 nums[j] 可以变大（集合元素增多），更新 nums[j] = nums[j]∣x；
//  注意此时的 nums[j]是原本数组 nums从 j 到 i 所有数中能使 nums[j]变大的数的 或值
//·如果 nums[j]∣x = nums[j]，从集合的角度看，此时 x 不仅是 nums[j] 的子集，同时也是 nums[k](k < j) 的子集
//（因为 nums[j] 是 nums[k] 的子集，不可能再使nums[k]变大了，循环保证了每个集合都是其左侧相邻集合的子集，
//  每一个数都会融入到它左边的集合里面去，不可能超过左边集合），
//  那么后续的循环都无法让元素变大，退出循环；
//在循环中，如果 nums[j] 可以变大，则更新 ans[j] = i−j + 1。
//int main()
//{
//    vector<int> nums = { 1, 0, 2, 1, 3 };
//    int n = nums.size();
//    vector<int> ans(n,1);//原本长度是 1
//    for (int i = 0; i < n; ++i) {
//        for (int j = i - 1; j >= 0 && (nums[j] | nums[i]) != nums[j]; --j) 
//        {
//            nums[j] |= nums[i];//集合增大
//            ans[j] = i - j + 1;//长度变大
//        }
//    }
//    for (auto i : ans)
//    {
//        cout << i << ' ';
//    }
//}

/////////////////////////////////////////微信红包模拟///////////////////////////

//int main()
//{
//    double sum = 50.50;
//    int count = 2;
//    double max_ = 0.0;
//    
//    srand((unsigned)time(NULL));
//    while (count--)
//    {
//        double money;
//        if (count == 0)
//        {//最后一个人把钱全都拿走
//            money = sum;
//            max_ = max(money, max_);
//            printf("%.3f\n", money);
//            break;
//        }
//        double k = (double)(1 + rand() % 999) / 1000;//精度，一般是100
//        money = sum * k;
//        sum -= money;
//        max_ = max(money, max_);
//        printf("%.3f\n", money);//保留小数点后三位
//    }
//    printf("%.3f\n", max_);
//    //double a = 3.1415926;
//    //cout << setprecision(3) << a << endl;  //3.14,输出的总位数是3
//    //cout << setprecision(9) << a << endl;  //3.1415926，输出的总位数是9
//    //cout << fixed << setprecision(3) << a << endl;  //3.142，输出小数点后面位数是3
//    //cout << fixed << setprecision(9) << a << endl;  //3.141592600，输出小数点后面位数是9
//}

/////////////////////////////////////////从边界射入弹珠，哪些能落入洞里///////////////////////////

//https://leetcode.cn/contest/season/2022-fall/problems/EXvqDp/
////输入：
////num = 5
////plate = [".....", "..E..", ".WO..", "....."]
////输出： [[0, 1], [1, 0], [2, 4], [3, 2]]
////解释：
////在[0, 1] 处打入弹珠，弹珠前进 2 步，遇到转向器后前进方向逆时针旋转 90 度，再前进 1 步进入洞中。
////在[1, 0] 处打入弹珠，弹珠前进 2 步，遇到转向器后前进方向顺时针旋转 90 度，再前进 1 步进入洞中。
////在[2, 4] 处打入弹珠，弹珠前进 2 步后进入洞中。
////在[3, 2] 处打入弹珠，弹珠前进 1 步后进入洞中。
//const int N = 1005, 
//dx[] = { 1,0,-1,0 }, 
//dy[] = { 0,-1,0,1 }, //下左上右，按照顺时针顺序排列
//inf = 0x3f3f3f3f;
//int n, m, dp[N][N][4];//dp[x][y][d]表示在（x，y）坐标，方向为d的状态下，到达弹珠洞需要多少步
//bool vis[N][N][4];//表示此状态是否遇到过
//vector<string> plate;
//int dfs(int x, int y, int d) 
//{//x,y,d表示当前状态
//    if (x >= n || x < 0 || y >= m || y < 0)
//        return inf;//已经出界，则永远无法到达洞里
//    if (dp[x][y][d] != -1)//之前已经计算过该状态到洞里需要多少步，直接返回
//        return dp[x][y][d];
//    if (vis[x][y][d])//如果上面没有返回，那么就说明进入了一个环，永远无法到达洞里，因为dp[x][y][d]==-1，说明
//                    //还没有计算出该状态到洞里需要多少步，也就是dfs还没有返回上一层，而vis[x][y][d]==1说明
//                    //之前遇到过这个状态，并且还没有计算出结果，正在等待下层dfs返回结果，这样就是一个环
//                    //不加这个剪枝也可以，因为不可能出现一个环
//        return dp[x][y][d] = inf;//返回永远不可能到达洞里
//    vis[x][y][d] = 1;//此状态已访问
//    if (plate[x][y] == '.') 
//    {//当前位置是“平地”则保持原有方向，dfs(x + dx[d], y + dy[d], d)表示在（x + dx[d]，y + dy[d]）坐标，方向为 d 的状态下，
//        //到达弹珠洞需要多少步，加 1 表示向前走一步，从x --> x + dx[d]
//        dp[x][y][d] = dfs(x + dx[d], y + dy[d], d) + 1;
//    }
//    else if (plate[x][y] == 'O')//已经到洞里了
//        dp[x][y][d] = 0;
//    else if (plate[x][y] == 'W') 
//    {//W表示逆时针转向器（弹珠经过时方向将逆时针旋转 90 度），原来方向为d，d+1为顺时针旋转，d-1位逆时针旋转
//        int D = ((d-1)+4) % 4;
//        dp[x][y][d] = dfs(x + dx[D], y + dy[D], D) + 1;
//    }
//    else 
//    {//E表示顺时针转向器（弹珠经过时方向将顺时针旋转 90 度），原来方向为d，d+1为顺时针旋转，d-1位逆时针旋转
//        int D = (d + 1) % 4;
//        dp[x][y][d] = dfs(x + dx[D], y + dy[D], D) + 1;
//    }
//    vis[x][y][d] = 0;//不回溯可以，这是因为同一位置，同一方向，不管从哪个边界射入，此状态到达洞里的步数是不会变的
//                     //这里回溯的话就是说，每一次从不同边界射入，所有状态都是未知的，但是因为dp没有被重置，所以还是会剪枝
//                    //不会超时
//    return dp[x][y][d];//返回此状态到达洞里需要多少步
//}
//class Solution {
//public:
//    vector<vector<int>> ballGame(int num, vector<string>& plate) {
//        ::plate = plate;
//        n = plate.size(), m = plate[0].size();
//        memset(vis, 0, sizeof(vis));
//        memset(dp, -1, sizeof(dp));//初始化
//        vector<vector<int>> ans;
//        for (int i = 0;i < n;++i)
//            for (int j = 0;j < m;++j)
//                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && plate[i][j] == '.')
//                {//从边界的“平地”开始射入弹珠
//                    if (i == 0 && j == 0)
//                        continue;//四个角都不算
//                    if (i == 0 && j == m - 1)
//                        continue;
//                    if (i == n - 1 && j == 0)
//                        continue;
//                    if (i == n - 1 && j == m - 1)
//                        continue;
//                    if (i == 0) 
//                    {//从上边界射入，方向向下
//                        if (dfs(i, j, 0) <= num)//能到达洞里
//                            ans.push_back({ i,j });
//                    }
//                    else if (i == n - 1) 
//                    {//从下边界射入，方向向上
//                        if (dfs(i, j, 2) <= num)
//                            ans.push_back({ i,j });
//                    }
//                    else if (j == 0) 
//                    {//从左边界射入，方向向右
//                        if (dfs(i, j, 3) <= num)
//                            ans.push_back({ i,j });
//                    }
//                    else 
//                    {//从右边界射入，方向向左
//                        if (dfs(i, j, 1) <= num)
//                            ans.push_back({ i,j });
//                    }
//                }
//        return ans;
//    }
//};
//int main()
//{
//    vector<string> s = { ".....","..E..",".WO..","....." };
//    Solution so;
//    for (auto v : so.ballGame(5, s))
//    {
//        cout << v[0] << ' '<<v[1] << endl;
//    }
//}

/////////////////////////////////////////读写文件，并根据字符串长度排序///////////////////////////

//打开文件并根据文件中的字符串长度排序
//int standard(vector<string>& nums, int low, int high)
//{
//    int k = rand() % (high - low + 1) + low;//在[low,high]之间随机产生一个下标，并以这个下标的值为后面的判断依据
//    swap(nums[low], nums[k]);//必须要交换，如果不交换而直接用nums[k]去比较的话，会丢失最左端nums[left]的值，因为后面直接把nums[low] = nums[high]，而此时nums[low]没有保存
//	string temp = nums[low];//而交换的话就可以用temp去保存nums[k]的值，而nums[k]保存的就是nums[low]的值
//	while (low < high)
//	{
//		while (low < high && nums[high].length()>=temp.length()) //如果这里不加low<high的话，在升序排列的数组中high会一直减小到-1，造成数组越界
//		{
//			--high;
//		}
//		nums[low] = nums[high];
//		while (low < high && nums[low].length() <= temp.length())//同理
//		{
//			++low;
//		}
//		nums[high] = nums[low];
//	}
//	nums[low] = temp;
//	return low;
//}
//void quicksort(vector<string>& nums, int low, int high)
//{
//	if (low < high)
//	{
//		int index=standard(nums, low, high);
//		quicksort(nums, low, index - 1);
//		quicksort(nums, index+1, high);
//	}
//}
//void merge(vector<string>& array, int start, int mid, int end, vector<string>& tmp)
//{
//    int i = start;//start是左边分支的开头，mid是左边分支的结尾，则左边分支个数是 mid-left+1
//    int j = mid + 1;//mid + 1 是右边分支的开头，end是右边分支的结尾，则右边分支个数是 end - (mid + 1) + 1 = end - mid，左右分支总共有 end - left + 1 个数
//    for (int k = start;k <= end;k++)
//    {
//        tmp[k] = array[k];
//    }
//    //将左右两个分支比较合并，这是 归并 的实现
//    for (int k = start; k <= end; ++k)
//    {//要处理的数总共有 end-left+1 个，从start开始，到end结束，注意两个都是闭区间
//        //此处会发生合并，分别进行比较，总共比较k次，复杂度O(k)
//        if ((i <= mid && j <= end && tmp[i].length() >= tmp[j].length()) || j == end+1)
//        {
//            array[k] = tmp[i];
//            i = i + 1;
//        }
//        else if ((i <= mid && j <= end && tmp[i].length() < tmp[j].length()) || i==mid+1)
//        {
//            array[k] = tmp[j];
//            j = j + 1;
//        } 
//    }
//}
//void mergesort(vector<string>& array, int start, int end, vector<string>& tmp)
//{
//    if (start < end)
//    {//start，end都是闭区间，所以 start==end 的时候就只有一个数了，不需要再分了
//        int temp = (start + end) / 2;
//        //开始递归
//        mergesort(array, start, temp, tmp);//左分支
//        //关于传参temp + 1 如果start和end之间的差为1，则直接对两个数进行排序
//        mergesort(array, temp + 1, end, tmp);//右分支
//        merge(array, start, temp, end,tmp);//左右分支合并，左分支可能比右分支多一个数
//    }
//}
//int main()
//{
//    fstream infile("test.txt",ios::in), outfile("test1.txt", ios::out);//只有声明为out的时候才会新建文件并写入，其他模式不会新建也不会报错
//    vector<string> v;
//    string s;
//    while (infile>>s)
//    {
//        v.push_back(s);
//    }
//    /*sort(v.begin(), v.end(), [](const string& a, const string& b)
//        {
//            return a.length() > b.length();
//        });*/
//    int n = v.size();
//    //quicksort(v, 0, n - 1);//快排
//    vector<string> tmp(n);
//    mergesort(v, 0, n - 1, tmp);//归并
//    for (auto s : v)
//    {
//        cout << s << endl;
//        outfile << s <<'\n';
//    }
//    infile.close(); //关闭文件
//    outfile.close();//必须关闭以后才能打开另一个文件
//    outfile.open("test2.txt", ios::out);//写入另一个文件
//    for (auto s : v)
//    {
//        outfile << s <<'\n';
//    }
//    outfile.close();
//}


//int main()
//{
//    int n = 20;
//    string s = to_string(n);
//    int m = s.length();
//    vector<vector<int>> dp(m, vector<int>(m,-1));
//    function<int(int, bool, int)> fun = [&](int i, bool is_limit, int hasone)->int
//    {
//        if (i == m)
//        {
//            return hasone;
//        }
//        if (!is_limit && dp[i][hasone] != -1)
//        {
//            return dp[i][hasone];
//        }
//        int up = is_limit ? s[i] - '0' : 9;
//        int res = 0;
//        for (int d = 0;d <= up;++d)
//        {
//            res += fun(i + 1, is_limit && d == up, hasone + (d == 1));
//        }
//        if (!is_limit)
//        {
//            dp[i][hasone] = res;
//        }
//        return res;
//    };
//    cout << fun(0, true, 0) << endl;
//}

/////////////////////////////////////////777. 在LR字符串中交换相邻字符///////////////////////////

//https://leetcode.cn/problems/swap-adjacent-in-lr-string/solution/by-ac_oier-ye71/
//输入: start = "RXXLRXRXL", end = "XRLXXRRLX"
//输出 : True
//解释 :
//我们可以通过以下几步将start转换成end:
//RXXLRXRXL ->
//XRXLRXRXL ->
//XRLXRXRXL ->
//XRLXXRRXL ->
//XRLXXRRLX
//int main()
//{
//    string start = "RXXLRXRXL", end = "XRLXXRRLX";
//    int left = 0, right = 0, n = start.size();
//    while (left < n || right < n)
//    {
//        while (left < n && start[left] == 'X')
//        {//在start字符串中，从左往右找到一个不是X的值
//            left++;
//        }
//        while (right < n && end[right] == 'X')
//        {//在end字符串中，从左往右找到一个不是X的值
//            right++;
//        }
//        //判断是否有一个串遍历完成，而另一个串遍历没有完成的情况,
//        // 如果出现了就只有两种结果：
//        //      1.两个串都只有 X 但是长度不相同(题目保证了长度相同，所以这种情况不可能）
//        //      2.其中一个串都是X，另一个串有一个其他字符，这样就会出现一个串遍历完了，但另一个还没有
//        //可以用 i==j 这个判断式来直接判断结果
//        if (left == n || right == n)
//        {
//            return left == right;
//        }
//        if (start[left] != end[right])
//        {//两个串中'L'和'R'出现的顺序必须相同，也就是去掉所有的 X 后，两个串是相同的
//            //此时start[left] 和 end[right] 都不是 X,则他们必须相同，否则顺序不相同
//            return false;
//        }
//        //此时start[left] 和 end[right] 都是 L 或都是 R 
//        if (start[left] == 'L' && left < right)
//        {//start串的找到的 L 必须大于等于 end串的 L 的索引，否则返回false，因为start的 L 不能右移 
//            return false;
//        }
//        if (start[left] == 'R' && left > right)
//        {//start串的找到的 R 必须小于等于 end串的 R 的索引，否则返回false，因为start的 R 不能左移 
//            return false;
//        }
//        ++right;
//        ++left;
//    }
//    return true;//这里返回什么都行，因为上面的循环里一定会返回
//
//}

/////////////////////////////////////////C语言中字符数组和字符串指针的区别///////////////////////////

//https://blog.csdn.net/dahuang1016/article/details/108519382
//https://blog.csdn.net/qq_43353179/article/details/109353528
//int main()
//{
//    char str1[] = "abcd";//字符数组，两份内存，一份在栈里面，一份在静态变量区，栈中的允许修改
//    char str2[] = "abcd";
//
//    const char str3[] = "abcd";
//    const char str4[] = "abcd";
//
//    str1[0] = 'A';//正确，str1是字符数组，且不是const
//    //str3[0] = 'A';//错误，str3是字符数组，但它是const
//
//    const char* str5 = "abcd";//字符串指针，一份内存，在静态变量区，不允许修改
//    const char* str6 = "abcd";
//
//    char* str7 = "abcd";
//    char* str8 = "abcd";
//
//    //str5[0] = 'A';//错误，str5是字符串指针，但它声明为指向常量的指针，所以不能修改
//    //str7[0] = 'A';//错误，str7是字符串指针，且不是const，所以可以通过指针去修改对象，但是对象存在静态变量区，不允许修改
//                  //所以这条语句可以通过编译，不能运行
//
//    cout << (str1 == str2) << endl;
//    cout << (str3 == str4) << endl;
//    cout << (str5 == str7) << endl;
//    cout << (str7 == str8) << endl;
//
//    cout << str1 << endl << str2 << endl << str3 << endl << str4 << endl << str5 << endl << str6 << endl << str7 << endl << str8 << endl;
//}

