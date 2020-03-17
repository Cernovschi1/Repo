#include <iostream>
#include "complex.h"
#include "complex_test.h"

//functie de sortare a unui vector de numere complexe
void sorteaza(complexz arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[i])
                std::swap ( arr[j], arr[i] );
}

//suma elementelor unui vector de numere complexe
complexz suma(complexz arr[],int n)
{
    complexz sum(0,0);
    for(int i = 0; i <n; i++)
        {sum=sum.add(arr[i]);
        }
    return sum;
}


//afisarea vectorului de numere complexe
void afis(complexz arr[],int n)
{
    for(int i=0;i<n;i++)
    {   arr[i].show_comp1();
        std::cout<<'\n';
    }

}
int main()
{
    complexz c1(1,1),c2(2,2),c3(4,4),c4(2,3),c5(4,3),c6(1,2);
    complexz arr[]={c1,c2,c3,c4,c5,c6};
    int n=sizeof(arr) / sizeof(arr[0]);
    sorteaza(arr,n);
    afis(arr,n);
    suma(arr,n).show_comp1();
    run_all_tests();

    return 0;
}
