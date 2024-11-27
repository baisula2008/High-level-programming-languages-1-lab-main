#include "std_lib_facilities.h"

template<typename T>
void print(const T& t, const string& s = " ")           /* A constant reference to a string variable (chang yin yong) chuan kong zhi */
{
	cout << s << "\t";                              /* \t:means (tab) character */
	for (auto& i : t)                               /* through the reference i value,we got the address of i,bec i is belong to templ t.*/
	{
		cout << i << ' ';
	}
	cout << endl;
}

template <typename C>
void inc(C& c, int n) {                                     /* through reference value o,we got the address of the value i, and i belong to the tem c */
	for (auto& i : c)                                   /* auto means i would be automatically identified the data type of the i value */
	{
		i += n;
	}
}

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2) {                   /* means copies [f1,e1) to [f2,f2+(e1–f1))*/
	for (Iter1 p = f1; p != e1; ++p)                        /* p!= e1 means identify if the pointer reads to the end of value , and increament by 1 each of element */
	
	{
		*f2++ = *p;                                     /* assign the pointer p value to f2 pointer and increament by 1,each of element */
	}
	return f2;
}

int main() {

	constexpr int size = 10;					/* initialize the array  with 10 element */
	int numbers[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	array<int, size> ai;						/* alias is ai*/	
	copy(numbers, numbers + size, ai.begin());                	/* Number of elements */
	print(ai, "array:");

	vector<int> vi(size);
	copy(numbers, numbers + size, vi.begin());
	print(vi, "vector:");

	list<int> li(size);
	copy(numbers, numbers + size, li.begin());
	print(li, "list:");
	cout << endl;

	array<int, size> ai2 = ai;
	print(ai2, "Copy of array:");
	vector<int> vi2 = vi;
	print(vi2, "Copy of vector:");
	list<int> li2 = li;
	print(li2, "Copy of list:");
	cout << endl;

	inc(ai2, 2);
	inc(vi2, 3);
	inc(li2, 5);
	print(ai2, "increased by 2:");
	print(vi2, "increased by 3:");
	print(li2, "increased by 5:");
	cout << endl;

	my_copy(ai2.begin(), ai2.end(), vi2.begin());
	my_copy(li2.begin(), li2.end(), ai2.begin());
	my_copy(vi2.begin(), vi2.end(), li2.begin());
	print(ai2, "copied array: ");
	print(vi2, "copied vector: ");
	print(li2, "copied list: ");
	cout << endl;

	vector<int>::iterator vit;
	vit = find(vi2.begin(), vi2.end(), 3);			    /*find() to see if the vector contains the value 3,and find the value */
	if (vit != vi2.end())
	{
		cout << "Found at: " << distance(vi2.begin(), vit) << endl;
	}
	else {
		cout << "Not found" << endl;
	}

	list<int>::iterator lit;
	lit = find(li2.begin(), li2.end(), 27);
	if (lit != li2.end())
	{
		cout << "Found at: " << distance(li2.begin(), lit) << endl;             /* find out the distance and position from the starting point*/
	}
	else {
		cout << "Not found" << endl;
	}
}
