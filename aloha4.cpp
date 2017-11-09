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
	char ch[] = "absd";
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
		int delay = rand()%5, i;
		for(i = slot; i < (slot+delay); i++)
		{
			cout << "slot " << i << ", machine 3 empty" << endl;
			_sleep(1000);
		}
		slot = i;
		ofstream file("m3.txt", ios :: trunc);
		file << ch[ctr];
		file.close();
		
		bool m1,m2,m0;
		
		FILE *f1;
		f1 = fopen("m1.txt", "r");
		if (f1 == NULL)
		{
			m1 = false;
		}
		else
		{
			m1 = true;
		}
		fclose(f1);
		
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
		
		if(m1 || m2 || m0)
		{
			block++;
			cout << "slot " << slot << " m3 collision\n";
		}
		else
		{
			cout << "slot " << slot << " m3 success\n";
			ofstream res("bus.txt", ios :: app);
			res << "3" << ch[ctr] << slot << endl;
			if(ctr == (strlen(ch)-1))
			{
				cout << "m3 complete in slot " << slot << endl;
				ofstream checker("checker.txt", ios::app);
				checker << "a";
				checker.close();
				res.close();
			}
			ctr++;
		}
		_sleep(1000);
		remove("m3.txt");
		slot++;
	}
	cout << "probability collision: " << (float)block/slot << endl;
	cout << "delay: " << slot << endl;
	int ccc = std::cin.get();
	return 0;
}
