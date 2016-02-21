#include <stdlib.h>
#include <stdio.h>
#define size0 100
#define no -1
class cstack
{
	private:
		int count;
		int allocatedMemory;
		double *arr;
	public:
		cstack();
		cstack(int size);
		~cstack();
		bool push(double x);
		double pop();
		bool is_Empty();
};
 
