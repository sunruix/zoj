#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
	int score;
	char name[16], id[16];
} record;

bool comp(const record &a, const record &b)
{
	return a.score < b.score;
}

int main()
{
	int n;
	char c;
	vector<record> male;
	vector<record> female;
	record temp;

	scanf("%d", &n);
	while (n--) {
		scanf("%s %c %s %d", &temp.name, &c, &temp.id, &temp.score);
		c == 'M' ? male.push_back(temp) : female.push_back(temp);
	}
	sort(male.begin(), male.end(), comp);
	sort(female.begin(), female.end(), comp);
	female.size() ? printf("%s %s\n", (female.end() - 1)->name, (female.end() - 1)->id) : printf("Absent\n");
	male.size() ? printf("%s %s\n", (male.begin())->name, (male.begin())->id) : printf("Absent\n");
	male.size() && female.size() ? printf("%d", (female.end() - 1)->score - (male.begin())->score) : printf("NA");
	return 0;
}


