#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<chrono>
#include <fcntl.h>
#include <errno.h>
using namespace std;

int main()
{
	char ch[] = "abc";
	int ctr = 0;
	_sleep(1000);
	cout << "3\n";
	_sleep(1000);
	cout << "2\n";
	_sleep(1000);
	cout << "1\n";
	_sleep(1000);
	cout << "time slot begins\ndata: " << ch << endl;
	_sleep(1000);
	int slot = 0, block = 0;
	while(ctr < strlen(ch))
	{
		int delay = rand()%3, i;
		for(i = slot; i < (slot+delay); i++)
		{
			cout << "slot " << i << ", machine 1 empty" << endl;
			_sleep(1000);
		}
		slot = i;
		ofstream file("m1.txt", ios :: trunc);
		file << ch[ctr];
		file.close();
		
		bool m3,m2,m0;
		
		FILE *f3;
		f3 = fopen("m3.txt", "r");
		if (f3 == NULL)
		{
			m3 = false;
		}
		else
		{
			m3 = true;
		}
		fclose(f3);
		
		FILE *f2;
		f2 = fopen("m2.txt", "r");
		if (f2 == NULL)
		{
			m2 = false;
		}
		else
		{
			m2 = true;
		}
		fclose(f2);

		FILE *f0;
		f0 = fopen("m0.txt", "r");
		if (f0 == NULL)
		{
			m0 = false;
		}
		else
		{
			m0 = true;
		}
		fclose(f0);
		
		if(m3 || m2 || m0)
		{
			block++;
			cout << "slot " << slot << " m1 collision\n";
		}
		else
		{
			cout << "slot " << slot << " m1 success\n";
			ofstream res("bus.txt", ios :: app);
			res << "1" << ch[ctr] << slot << endl;
			if(ctr == (strlen(ch)-1))
			{
				cout << "m1 complete in slot " << slot << endl;
				ofstream checker("checker.txt", ios::app);
				checker << "a";
				checker.close();
				res.close();
			}
			ctr++;
		}
		_sleep(1000);
		remove("m1.txt");
		slot++;
	}
	cout << "probability collision: " << (float)block/slot << endl;
	cout << "delay: " << slot << endl;
	int ccc = std::cin.get();
	return 0;
}
