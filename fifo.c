#include <stdio.h>
int main()
{
    int i, j, n;

    int arry[50], frm[10], num_frm, k, avail;

    printf("\n ENTER THE NUMBER OF PAGES >>>> \n");
    scanf("%d", &n);

    int ctr_faults = 0;

    printf("\n ENTER THE PAGE TRACE >>>> \n");
    for (i = 1; i <= n; i++)
        scanf("%d", &arry[i]);

    printf("\n ENTER THE NUMBER OF FRAMES >>>> ");
    scanf("%d", &num_frm);

    for (i = 0; i < num_frm; i++)
        frm[i] = -1;
    j = 0;
    printf("\tREF STRING \t PAGE FRAMES\n");

    for (i = 1; i <= n; i++)
    {
        printf("%d\t\t", arry[i]);
        avail = 0;
        for (k = 0; k < num_frm; k++)

            if (frm[k] == arry[i])
                avail = 1;
        if (avail == 0)
        {
            frm[j] = arry[i];
            j = (j + 1) % num_frm;
            ctr_faults++;
            for (k = 0; k < num_frm; k++)

                printf("%d\t", frm[k]);
        }

        printf("\n");
    }
    printf("PAGE FAULTS >>>> %d \n", ctr_faults);
    printf("PAGE HITS >>>>  %d \n", n - ctr_faults);
    return 0;
}
