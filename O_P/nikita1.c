
#include <stdio.h>
#define MAXLINE 1000 // maximalnaya dlina stroki
#define YES 1
#define NO 0

int delete(char buffer[]); // funkciya ydaleniya slov s dvumy podryad glasnimi

int main(void)
{
    char line[MAXLINE];
    gets(line);
    delete(line);
    puts(line);
    return 0;
}

int delete(char buffer[])
{
    char sim; // tekyhiy simvol
    int flag = YES, // flag na probel
        find = NO,// flag na uslovie
        in_pred_sim;
      
    char *in_sim, // ykazatel na tekyhiy simvol
        *in_start_sim, // ykazatel na simvol nachala slova
        *in_new_line; // ykazatel na simvol novoy stroki
    in_sim = buffer;
    in_pred_sim = ' ';
    in_start_sim = buffer;
    in_new_line = buffer;

    do
    {
        sim = *in_sim;
        if(sim == ' ' || sim == ',' || sim =='.' || sim =='\n' || sim =='\0')
        {
            if(flag)
            {
                if(find == NO)
                {
                    while (in_start_sim < in_sim)
                    {
                        *in_new_line++ = *in_start_sim++;
                    }
                    
                }
            }
            flag = NO;
            find = NO;

            *in_new_line++=sim;
        }
        else
        {
            if (flag==NO) in_start_sim = in_sim;
            if (flag == YES && (in_pred_sim ==  'e' || in_pred_sim == 'y' || in_pred_sim == 'u' || in_pred_sim == 'i' || in_pred_sim == 'o' ||
            in_pred_sim == 'a') && (*in_sim == 'e' || *in_sim == 'y' || *in_sim == 'u' || *in_sim == 'i' || *in_sim == 'o' || *in_sim == 'a'))
            {
                find = YES;
            }
             flag = YES;
             in_pred_sim=*in_sim;
        }
        in_sim++;
    } while (sim!='\0');
    return 0;
}