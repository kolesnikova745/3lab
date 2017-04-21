#include <iostream>
#include <ctime>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <cstdlib>
#include <vector>
using namespace std;

double c2 =0, c =0;
double c21 =0, c1 =0;
double c211 =0, c11 =0;
double t11 = 0, t21 = 0;
double t12 = 0, t22 = 0;
double t13 = 0, t23 = 0;

class AbstrSort {

public:
virtual void Sort(int t);
void Sort1(int t);
void Sort2(int t);
void Sort3(int t);
void in(int s);
void Out(int t);
void Outdo(int t);
void rands(int t);
int x,a[1000],b,y[1000];
int digit(int t, int p)
{
    return (t>>(8 * p) & 255);
}
    void doSwap( unsigned& p, unsigned& it )
    {
	while( sq[p] == it ) p++;
	swap( it, sq[p] );
	wr++;
    }

vector<unsigned> sq;
    unsigned wr;
};
class Shell : public AbstrSort
{
    public:
void Sort(int t)
{
    t11 = t11 + clock();
  int j;
  for (int gap = t / 2; gap > 0; gap /= 2)
  {
    for (int i = gap; i < t; ++i)
    {
      int temp = a[i];
      for (j = i; j >= gap && temp < a[j - gap]; j -= gap)
      {
        a[j] = a[j - gap];
        c++;
      }
      a[j] = temp;
      c++;
    }
  }
    t21 = t21 + clock();
}
};
class Gnome : public AbstrSort
{
    public:
void Sort(int t)
{
    t12 = t12 + clock();
    int i=0;
    while (i < t)
        if (i == 0 || a[i - 1] <= a[i])
            {++i; c21++;}
        else { swap(a[i], a[i - 1]); --i; c1++; }
        t22 = t22 + clock();
}
};
class Cycle : public AbstrSort
{
    public:
void Sort(int t)
{
    t13 = t13 + clock();
  int writes = 0;


  for (int cycleStart = 0; cycleStart < t - 1; ++cycleStart)
  {
    int item = a[cycleStart];
    int swap_tmp;


    int pos = cycleStart;
    for (int i = cycleStart + 1; i < t; ++i)
    {
      if (a[i] < item)
      {
          c211++;
        ++pos;
      }
    }


    if (pos == cycleStart)
    {
        c211++;
      continue;
    }


    while (item == a[pos])
    {
      ++pos;
    }
    c11++;
    swap_tmp = a[pos];
    a[pos] = item;
    c11++;
    item = swap_tmp;
    ++writes;


    while (pos != cycleStart)
    {

      pos = cycleStart;
      for (int i = cycleStart + 1; i < t; ++i)
      {
        if (a[i] < item)
        {
            c211++;
          ++pos;
        }
      }

      while (item == a[pos])
      {
        ++pos;
      }
      c11++;
      swap_tmp = a[pos];
      a[pos] = item;
      c11++;
      item = swap_tmp;
      ++writes;
    }
  }
    t23 = t23 + clock();

}
};

void AbstrSort::rands(int t)
{
    for (int i = 0; i < t; i++)
{
    a[i] = rand()%10+1;
}
}
void AbstrSort::Outdo(int t)
{
    for (int i=0; i<t; i++)
    cout << a[i] <<" ";
    cout << endl;
}
void AbstrSort::Out(int t)
{
    for (int i=0; i<t; i++)
    cout << a[i] <<" ";
    cout << endl;
    delete a;
}
void AbstrSort::Sort(int t)
{

}
void AbstrSort ::Sort2(int t)
{

}
void AbstrSort::Sort3(int t)
{

}



int main()
{
    setlocale(LC_ALL, "rus");
    int b;
    Shell v1;
    Gnome v2;
    Cycle v3;
    cout << " ¬ведите длину массива : "<< endl;
    cin >> b;
    srand ( time(NULL) );
    for (int i = 1; i<=100; i++)
    {
        v1.rands(b);
        v1.Sort(b);
    };
         srand ( time(NULL) );
    for (int i = 1; i<=100; i++)
    {
        v2.rands(b);
        v2.Sort(b);
    };
         srand ( time(NULL) );
    for (int i = 1; i<=100; i++)
    {
        v3.rands(b);
        v3.Sort(b);
    }

cout <<"перестановки/сравнени€: "<< endl;
cout << c/100<<" "<< c2/100<<" "<< (t21-t11)/100000<< endl;
cout << c1/100<<" "<< c21/100<<" "<< (t22-t12)/100000<< endl;
cout << c11/100<<" "<< c211/100<<" "<< (t23-t13)/100000<< endl;
    return main();
}
