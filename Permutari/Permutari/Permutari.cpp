#include <fstream>
using namespace std;

ifstream f("input.txt");
ofstream g("output.txt");

int v[10],n;  //maxim 9 elemente

void afis() {
	for (int i = 1; i <= n; i++)
		g << v[i] << " ";
	g << '\n';
}

int OK(int k)
{
	for (int i = 1; i < k; i++)
		if (v[i] == v[k])
			return false;
	return true;
}

int solutie(int k)
{
	return k == n;
}

void back(int k) {
	for (int i = 1; i <= n; i++)
	{
		v[k] = i;
		if (OK(k))
			if (solutie(k))
				afis();
			else
				back(k + 1);
	}
}

int main()
{
	f >> n;
	back(1);
}