#include<stdio.h>
#include<math.h>

int main()
{
	int a[10], i, j, ct;

	for (i = 0; i < 10; i++)
		scanf("%d", &a[i]);

	ct = 0;
	for (i = 0; i < 10; i++)
	{
		for (j = i + 1; j < 10; j++)
			if (a[i] == a[j])
				break;
		if (j >= 10)
			ct++;
	}

	printf("%d", ct);

	return 0;
}

