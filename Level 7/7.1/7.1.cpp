#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <iterator>
using namespace std;
//this is a programme for practicing using STL Containers
void main()
{
	list<double> dbl;//create a list of doubles
	
	//add data to the list
	dbl.push_back(1.5);
	dbl.push_back(2.5);
	dbl.push_back(3.5);
	dbl.push_front(4.5);
	
	//print the list, using front() and back() to access first and last element
	cout<<dbl.front()<<endl;//access and print the first element
	cout<<dbl.back()<<endl;//access and print the last element
	cout<<endl;//print a new line
	copy(dbl.begin(),dbl.end(),std::ostream_iterator<double>(cout,"\n"));//print the list
	dbl.clear();//clear list
	cout<<endl;//print a new line

	vector<double> dbv;//create a vector of doubles
	dbv.reserve(15);//reserve space for 15 elements

	//add data to the vector
	dbv.push_back(1.1);
	dbv.push_back(2.2);
	dbv.push_back(3.3);
	dbv.push_back(4.4);

	//access element with index operator
	cout<<"Element 0: "<<dbv[0]<<endl;//access and print the first element
	cout<<"Element 3: "<<dbv[3]<<endl;//access and print the last element
	cout<<"Size: "<<dbv.size()<<endl;//see size of the current vector
	cout<<"Capacity: "<<dbv.capacity()<<endl;//see capacity of the current vector
	dbv.clear();//clear vector
	cout<<endl;//print a new line

	map<const char*,double> Info;//create a map that maps strings to doubles

	//add data
	Info["CountryNumber"]=86;
	Info["ZipCode"]=510000;
	Info["DistrictNumber"]=0755;

	//access element with []
	cout<<Info["CountryNumber"]<<endl;
}