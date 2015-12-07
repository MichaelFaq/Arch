#include "lab1.h"

using namespace std;

vector<int> SearchIndexVect(string ss, string subss)
{
	vector<int> promV;
	if (subss.empty())
	{
		for (int i = 0; i < ss.size(); i++) promV.insert(promV.end(), i);
	}
	else
	{
		int k = 0;
		while (ss.find(subss) != -1)
		{
			promV.insert(promV.end(), ss.find(subss) + k);
			k = k + ss.find(subss) + 1;
			ss.erase(0, ss.find(subss) + 1);
		}
	}
	return promV;
}

bool SearchElement(string ss, string subss)
{
	bool flag = true;
	while (subss.find("*") != -1)
	{
		indexParts.insert(indexParts.end(), SearchIndexVect(ss, subss.substr(0, subss.find("*"))));
		if (indexParts[indexParts.size() - 1].size() == 0) flag = false;
		lenLast = subss.substr(0, subss.find("*")).length();
		subss.erase(0, subss.find("*") + 1);
	}
	lenLast = subss.length();
	indexParts.insert(indexParts.end(), SearchIndexVect(ss, subss));
	if (indexParts[indexParts.size() - 1].size() == 0) flag = false;

	return flag;
}

void FindMatchIndexes()
{
	vector<int> numbI, clock(indexParts.size(), 0), promSort, prom;
	for (int i = 0; i < indexParts.size(); i++) numbI.insert(numbI.end(), indexParts[i].size()-1);
	while (clock[0] <= numbI[0])
	{
		for (int j = 0; j < clock.size(); j++) prom.insert(prom.end(), indexParts[j][clock[j]]);
		promSort = prom;
		sort(promSort.begin(), promSort.end());
		if (prom == promSort)	res.insert(res.end(), "Pos: " +to_string(prom[0]) +" "+s.substr(prom[0], prom[prom.size() - 1] - prom[0] + lenLast));
		prom.clear();

		clock[clock.size() - 1]++;
		for (int i = clock.size() - 1; i > 0; i--)
		if (clock[i] > numbI[i])
		{
			clock[i] = 0;
			clock[i - 1]++;
		}
	}
}

void DelSimEl()
{
	int i = 0;
	while (i < res.size() - 1)
	{
		int j = i + 1;
		while (j < res.size())
			if (res[i] == res[j]) res.erase(res.begin() + j);
			else j++;
		i++;
	}
//	for (i = 0; i < res.size(); i++) cout << res[i] << "\n";
}

int main()
{
	for (int i = 0; i< 5; i++) s+=s;
	if (SearchElement(s, subs))
	{
		if (!indexParts.empty())
		{
			res.clear();
			FindMatchIndexes();
			DelSimEl();
		}
	//	else cout << "Any string \n"; // subs == "*"
	}
	//else cout << "No match \n";

	//system("pause");
	return 0;
}
