#include <stdio.h>
#include <conio.h>
#include <math.h>

int associative();
int direct();
int mn_sz ,  cch_sz ,  blck_sz ,  ln_sz ;
int bit ,  cache_bit ,  block_bit ,  lines ,  line_bit ,  word_bit ;
int pages ,  page_bit ,  set_sz ;

int main()
{
 printf("Size of main memory>>>>  ");
      scanf("%d", &mn_sz);

      printf("Size of cache memory>>>> ");
      scanf("%d", &cch_sz) ;

      printf("Enter the size of Block >>>> ");
      scanf("%d", &blck_sz) ;

       int x = 1;
       printf("\n");
      printf("Enter 1 for Direct Mapping and 2 for set associative mapping(two way)>>>>");
      scanf("%d", &x);

      switch (x)
      {
      case 1:
          direct();
          break ;

      case 2:
            associative();
            break;

      default:
            printf("INVALID ENTRY !");
      }

}
int direct()
{
      ln_sz = blck_sz ;
      bit = log2(mn_sz) ;
      block_bit = log2(blck_sz);

      lines = cch_sz/ln_sz ;

      line_bit = log2(lines) ;

      printf("size of line: %d \n",ln_sz) ;
      printf("No of line bits>>>> %d \n",line_bit) ;

      word_bit = block_bit ;
      printf("No of word bits>>>> %d \n",block_bit) ;

      pages = mn_sz/cch_sz ;
      page_bit = log2(pages) ;

      printf("No of tag bits>>>> %d \n",page_bit) ;
}

int associative()
{
      int no_of_sets = 2 ;

      bit = log2(mn_sz) ;

      set_sz = cch_sz/2 ;

      lines = set_sz/blck_sz ;
      line_bit = log2(lines) ;

      printf("size of line>>>> %d \n",blck_sz) ;
      printf("No of line bits>>>> %d \n",line_bit) ;

       block_bit = log2(blck_sz);
       printf("No of word bits>>>> %d \n",block_bit) ;

      pages = mn_sz/set_sz ;
      page_bit = log2(pages) ;

       printf("No of tag bits>>>> %d \n",page_bit) ;
}
