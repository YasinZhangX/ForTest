// ForTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "cert.h"
#include <iostream>
#include "time.h"

long long GetTick(char *str_time)
{
	struct tm stm;
	int iY, iM, iD, iH, iMin, iS, offset, offsetSec;
	int sign;
	char signChar;

	memset(&stm, 0, sizeof(stm));

	str_time = str_time + 8;

	iY = atoi(str_time);
	iM = atoi(str_time + 3);
	iD = atoi(str_time + 6);
	iH = atoi(str_time + 9);
	iMin = atoi(str_time + 12);
	iS = atoi(str_time + 15);
	offset = atoi(str_time + 18);
	signChar = str_time[17];

	stm.tm_year = (iY+2000) - 1900;
	stm.tm_mon = iM - 1;
	stm.tm_mday = iD;
	stm.tm_hour = iH;
	stm.tm_min = iMin;
	stm.tm_sec = iS;
	offsetSec = offset * (15 * 60);

	if (signChar == '+')
	{
		sign = 1;
	}
	else {
		sign = -1;
	}

	printf_s("%d-%0d-%0d %0d:%0d:%0d%c%0d\n", iY, iM, iD, iH, iMin, iS, signChar, offset);

	long long tmp = mktime(&stm);

	return (mktime(&stm) + sign * offsetSec);
}

int main()
{
    std::cout << "Hello World!\n"; 
	const char *rsp = "+CCLK: \"13/08/19,11:10:57+32\"";
	long long ltime;
	ltime = GetTick((char *)rsp);

	printf_s("timeStamp: %lld\r\n", ltime);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
