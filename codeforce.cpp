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
#include<bitset>
#include<regex>
#include<random>
#include<cmath>
#include <iomanip> // 包含头文件
using namespace std;

//void solve()
//{
//    int n; cin >> n;
//    vector<int> a(n);
//    map<int, int> leftOcc, rightOcc;
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//        rightOcc[a[i]] = i;
//        if (!leftOcc.count(a[i])) leftOcc[a[i]] = i;
//    }
//    int mex = calcMex(a);
//    if (leftOcc.count(mex + 1)) {
//        int L = leftOcc[mex + 1], R = rightOcc[mex + 1];
//        for (int i = L; i <= R; ++i) {
//            a[i] = mex;
//        }
//        int mx = calcMex(a);
//        assert(mx <= mex + 1);
//        return mx == mex + 1;
//    }
//    for (int i = 0; i < n; ++i) {
//        assert(a[i] != mex);
//        if (a[i] > mex || (leftOcc[a[i]] != rightOcc[a[i]])) {
//            return true;
//        }
//    }
//    return false;
//}
//int main()
//{
//    int t;
//    cin >> t;
//    while (t--)
//    {
//        cout << (solve() ? "Yes" : "No") << '\n';
//    }
//}