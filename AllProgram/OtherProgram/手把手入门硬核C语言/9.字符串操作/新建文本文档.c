


int i, j, la, lb, num = 0;
char c, a[120], b[4500];
while ((c = getchar()) != '\n')
{
	a[num++] = c;
	a[num] = '\0';
}

num = 0;
while ((c = getchar()) != '\n')
{
	b[num++] = c;
	b[num] = '\0';
}

la = strlen(a);
lb = strlen(b);
for (i = 0; (lb - i) >= la; i++)
{
	if (b[i] == a[0])
	{
		for (j = 0; j < la; j++)
		{
			if (b[i + j] != a[j])
			{
				break;
			}
		}

		if (j == la)
		{
			printf("%d\n", i + 1);
			break;
		}
	}
}
//
char str[20] = "jsdlaadf", substr[10] = "sdf";
char *p = str, *q = substr;
int flag = 0;

for (; *(p + strlen(substr) - 1); p++)
{
	for (q = substr; *p == *q && *q; p++, q++);

	if (!*q)
	{
		flag = 1;
		break;
	}
}

if (flag == 1)
{
	puts("accord");
}
else
{
	puts("not accord");
}
