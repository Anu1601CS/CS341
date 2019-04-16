// Name: Anurag
// Roll n0 : 1601CS05

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fileMap[100000];
int mapIdx[100000];
int mapEndIdx[100000];

int main()
{
	int numBlock;
	printf("The Sequential file\n");
	printf("Enter the number of block in disk\n");
	scanf("%d", &numBlock);
	int *disk = malloc(sizeof(int) * numBlock);

	for (int i = 0; i < numBlock; i++)
		disk[i] = -1;
	int totFile = 0;

	while (1)
	{
		printf("Enter : \n");
		printf("1. To add file\n");
		printf("2. To print directory\n");
		printf("3. TO exit\n");

		int choice;
		scanf("%d", &choice);

		if (choice == 1)
		{
			char *fName = malloc(sizeof(char) * 1000);
			int sBlock, tBlock;

			printf("Enter File name,starting block and total number of block in file\n");
			scanf("%s%d%d", fName, &sBlock, &tBlock);
			int flag = 0;

			for (int i = sBlock; i < numBlock; i++)
			{
				if (disk[i] != -1)
					break;

				if (sBlock + tBlock - 1 == i)
				{
					flag = 1;
					break;
				}
			}

			if (tBlock == 0)
				flag = 0;

			if (flag == 1)
			{
				for (int i = sBlock; i < sBlock + tBlock; i++)
					disk[i] = totFile;
				fileMap[totFile] = fName;
				mapIdx[totFile] = sBlock;
				mapEndIdx[totFile] = sBlock + tBlock - 1;
				totFile++;
			}
			else
				printf("Something Went Wrong either someone has occupied that space or out of bound\n");
		}
		else if (choice == 2)
		{
			printf("File name 	Start Block 	EndBlock\n");

			for (int i = 0; i < totFile; i++)
				printf("%s 		%d 		%d\n", fileMap[i], mapIdx[i], mapEndIdx[i]);
		}
		else if (choice == 3)
			break;
		else
			printf("Invalid Input\n");
	}
}
