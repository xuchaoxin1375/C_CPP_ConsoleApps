#include <stdio.h>
#include <string.h>

int main()
{
	char str_7[10];
	int num_7[10];
	int n = strlen(str_7);
	while (scanf("%s", str_7) != EOF)
	{
		/*字符数组->整型数组*/
		for (int i = 0; i < n; i++)
		{
			if (str_7[i] == '.')
			{
				continue;
			}
				num_7[i] -= 48;
			
		}

		//for (int i = n; i > 0; i--)
		//{
		//	if (num_7[i] > 4)
		//	{
		//		num_7[i - 1]++;
		//	}
		//	else
		//	{
		//		break;
		//	}
		//}
	}
}