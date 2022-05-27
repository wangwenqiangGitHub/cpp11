#include <iostream>
#include <functional>

int sum(int a, int b){return a+b;}


int main()
{
	auto fun = [](int* array, int n, int num){
		for(int i=0; i< n; i++){
			if(array[i] > num){
				std::cout << array[i] << std::endl;
			}
		}
	};
	int array[] = {1,3,5,7,9};
	auto fun1 = std::bind(fun, std::placeholders::_1, std::placeholders::_2,5);
	fun1(array,sizeof(array)/sizeof(*array));
	return 0;
}
