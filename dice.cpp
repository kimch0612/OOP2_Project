#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;
int main(void)
{
    int i;
    srand(time(NULL));
    i = (random() % 6) + 1;
    cout << i << endl;
}