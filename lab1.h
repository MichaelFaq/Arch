#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> indexParts;
vector<string> res;
string s = "ccccdaaaacbbbbaccccaaa", subs = "aaa*bbb*ccc";
int lenLast = 0;

vector<int> SearchIndexVect(string ss, string subss);
bool SearchElement(string ss, string subss);
void FindMatchIndexes();
void DelSimEl();
