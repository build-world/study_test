//Copyright 2016 buildworld.net. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void erstop(void)
{
	printf("error!");
	system("pause");
}

int main(int argc, char *argv[])
{
	FILE *fpIn, *fpOut;
	char InPath[_MAX_PATH], OutPath[_MAX_PATH];
	char temp;
	int i, rtn;
	size_t szDump;
	if (!argv[1])
	{
		printf("Input,please.\n");
		scanf("%s%s", InPath, OutPath);
	}
	else
	{
		strcpy(InPath, argv[1]);
		strcpy(OutPath, argv[2]);
	}
	fpIn = fopen(InPath, "rb+");
	if (!fpIn)
	{
		printf("Openfile error!\n");
		erstop();
		return 0;
	}
	//seek data chunk
	temp = NULL;
	while (temp != 'd')
	{
		fread(&temp, 1, 1, fpIn);
	}
	for (i = 0; i < 3; i++)
	{
		fread(&temp, 1, 1, fpIn);
		switch (i)
		{
		case 0:
			if (temp != 'a')
			{
				erstop();
				return 0;
			}
			break;
		case 1:
			if (temp != 't')
			{
				erstop();
				return 0;
			}
			break;
		case 2:
			if (temp != 'a')
			{
				erstop();
				return 0;
			}
			break;
		}
	}
	//get size
	rtn = fread(&szDump, sizeof(size_t), 1, fpIn);
	if (rtn == EOF) erstop();
	//
	printf("File verifly complete, %d Sample, Dump start!\n", szDump / 2);
	//dump data
	char *DumpData = (char *)malloc(szDump);
	rtn = fread(DumpData, szDump, 1, fpIn);
	if (rtn == 1)
	{
		printf("Read succeed!\n");
	}
	else
	{
		printf("Read error!\n");
		erstop();
		return 0;
	}
	fpOut = fopen(OutPath, "wb");
	rtn = fwrite(DumpData, szDump, 1, fpOut);
	if (rtn == 1)
	{
		printf("Write succeed!\n");
	}
	else
	{
		printf("Write error!\n");
		erstop();
		return 0;
	}
	printf("all complete!");
	fclose(fpIn);
	fclose(fpOut);
	free(DumpData);
	return 0;
}

