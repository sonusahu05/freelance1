#include <stdio.h>
int main()
{
    int arr_2[20], arr_1[50], ctr_flt = 0, ctr, d, f, i, j, k = 0, n, num, temp_var, arr_3[20], ctrr[20];

    printf("ENTER NUMBER OF PAGES >>>> ");
    scanf("%d", &n);
    printf("ENTER THE PAGE TRACE >>>> ");

    for (i = 0; i < n; i++)
        scanf("%d", &arr_1[i]);
    printf("ENTER NUMBER OF FRAMES >>>> ");
    scanf("%d", &f);
    arr_2[k] = arr_1[k];
    printf("\n\t%d\n", arr_2[k]);
    ctr_flt++;
    k++;
    for (i = 1; i < n; i++)
    {
        ctr = 0;
        for (j = 0; j < f; j++)
        {
            if (arr_1[i] != arr_2[j])
                ctr++;
        }

        if (ctr == f)
        {
            ctr_flt++;
            if (k < f)
            {
                arr_2[k] = arr_1[i];
                k++;
                for (j = 0; j < k; j++)
                    printf("\t%d", arr_2[j]);
                printf("\n");
            }
            else
            {
                for (num = 0; num < f; num++)
                {
                    ctrr[num] = 0;
                    for (j = i - 1; j < n; j--)
                    {
                        if (arr_2[num] != arr_1[j])
                            ctrr[num]++;
                        else
                            break;
                    }
                }
                for (num = 0; num < f; num++)
                    arr_3[num] = ctrr[num];

                for (num = 0; num < f; num++)
                {
                    for (j = num; j < f; j++)
                    {
                        if (arr_3[num] < arr_3[j])
                        {
                            temp_var = arr_3[num];
                            arr_3[num] = arr_3[j];
                            arr_3[j] = temp_var;
                        }
                    }
                }
                for (num = 0; num < f; num++)
                {
                    if (ctrr[num] == arr_3[0])
                        arr_2[num] = arr_1[i];
                    printf("\t%d", arr_2[num]);
                }
                printf("\n");
            }
        }
    }
    printf("\nPAGE FAULTS =  %d", ctr_flt);
    printf("\nPAGE HITS = %d \n", n - ctr_flt);
}
