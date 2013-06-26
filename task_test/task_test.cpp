// task_test.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

//#include "stdafx.h"
#include <ppl.h>
#include <iostream>

using namespace concurrency;
using namespace std;

//int _tmain(int argc, _TCHAR* argv[])
int wmain()
{
	auto task1 = make_task([]{ wcout<<L"Task 1"<<endl; });
	auto task2 = make_task([]{ wcout<<L"Task 2"<<endl; });
	auto task3 = make_task([]{ wcout<<L"Task 3"<<endl; });

	structured_task_group tasks;

	tasks.run(task1);
	tasks.run(task2);
	tasks.run(task3);
	tasks.wait();

	wcout<<"end"<<endl;

	return 0;
}

