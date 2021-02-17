#ifndef PRE_H
#define PRE_H
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <iterator>
#define REP(i,n)       for(int i = 0; i < (n); i++)
#define REP_1(i,n)     for(int i = 1; i < (n); i++)
#define REP_N(i,n)     for(int i = 0; i <= (n); i++)
#define REP_1_N(i,n)   for(int i = 1; i <= (n); i++)
#define DWN(i,n)       for(int i = (n); i > 0; i--)
#define DWN_1(i,n)     for(int i = (n); i > 1; i--)
#define DWN_N(i,n)     for(int i = (n); i >= 0; i--)
#define DWN_1_N(i,n)   for(int i = (n); i >= 1; i--)
#define FOR(i,A,B)     for(int i = (A); i < (B); i++)
#define FOR_N(i,A,B)   for(int i = A; i <= (B); i++)
#define FOR_D(i,A,B)   for(int i = (A); i > (B); i--)
#define FOR_D_N(i,A,B) for(int i = (A); i >= (B); i--)
#define FILEIN(file)   freopen((file),"r",stdin)
#define FILEOUT(file)  freopen((file),"w",stdout)
#define DEBUGB(block,message) cout << std::setw((block) * 4) << "" << "DEBUG Block " << (block) << ": BEGIN " << (message)<<endl
#define DEBUGE(block,message) cout << std::setw((block) * 4) << "" << "DEBUG Block " << (block) << ": END " << (message)<<endl
#define MEM0(OBJ) memset((OBJ),0,sizeof((OBJ)))
#define MEMINIT(OBJ,VALUE) memset((OBJ),(VALUE),sizeof((OBJ)))

using namespace std;

/// leetcode defined data types ///
struct ListNode;

struct TreeNode;

struct ListNode* make_listnode(const vector<int> &v);

struct 
TreeNode* make_treenode(const vector<long long> &v);

template<class T>
ostream& operator<<(ostream &os, const vector<T> &v);
ostream& operator<<(ostream &os, const ListNode *p);

ostream& operator<<(ostream &os, const TreeNode *t);

#endif //PRE_H