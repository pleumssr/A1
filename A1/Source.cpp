#include<iostream>
#include<string.h>
using namespace std;
struct ch
{
	char name[31];
	int vote = 0;
	int rank;
};
void reRank(int& chvote, int& chrank, int& rank, int num)
{

	if (chvote == num)
	{
		chrank = rank;
		rank++;
	}

}

int main()
{
	struct ch ch[10];
	int num = 0, vote, rank = 1;
	for (int i = 1; i <= 8; i++)
	{
		cin >> ch[i].name;
	}
	scanf_s("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf_s("%d", &vote);
		ch[vote].vote++;
	}
	for (num; num >= 0; num--)
	{
		for (int i = 1; i <= 8; i++)
		{
			reRank(ch[i].vote, ch[i].rank, rank, num);
		}
	}
	for (int i = 1; i <= 8; i++)
	{
		if (ch[i].rank == 8)
		{
			for (int j = 1; j <= 8; j++)
			{
				if (ch[i].vote == ch[j].vote)
				{
					ch[j].rank = 8;
				}
			}
		}
	}
	for (int i = 1; i <= 8; i++)
	{

		if (ch[i].rank < 8)
		{
			printf("%s\n", ch[i].name);
		}

	}
	return 0;
}