/*从键盘输入20个数整数，分别用气泡法和选择法对他们进行从小到大进行排队*/
/*选择排序：比如在一个长度为N的无序数组中，在第一趟遍历N个数据，找出其中最小的数值与第一个元素交换，第二趟遍历剩下的N-1个数据，
找出其中最小的数值与第二个元素交换......第N-1趟遍历剩下的2个数据，找出其中最小的数值与第N-1个元素交换，至此选择排序完成。*/

#include <stdio.h>
int main()
{
    int a[20];
    int minmum=0;
    int temp=0;
    for(int i=0;i<20;i++)
    {
       scanf("%d",&a[i]);
    }
    for(int i=0;i<20;i++)
    {
        minmum=a[i];
        for(int j=i;j<20;j++)
        {
            if(a[j]<minmum)
            {
             temp=minmum;
             minmum=a[j];
             a[j]=temp;
            }
        }
    }
    int count=0;
    for(int i=0;i<20;i++)
    {
        printf("%-3d",a[i]);
        count++;
        if(count%5==0){
            printf("\n");
        }
    }
    return 0;
}
