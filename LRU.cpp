#include<stdio.h>
#include<conio.h>
 
int LRU(int time[], int n){
    int i, minimo = time[0], pos = 0;
 
    for(i = 1; i < n; ++i)
    {
        if(time[i] < minimo)
        {
            minimo = time[i];
            pos = i;
        }
    }
    
    return pos;
}
 
int main(void)
{
    int n_pos_memoria, n_paginas, frames[10], string[30], counter = 0, time[10], flag1, flag2, i, j, pos, trocas = 0;
    
    printf("Entre com o numero de posicoes da memoria: ");
    scanf("%d", &n_pos_memoria);
    printf("Entre com aquantidade de paginas: ");
    scanf("%d", &n_paginas);
    printf("String de referencia: ");
    
    for(i = 0; i < n_paginas; ++i)
    {
        scanf("%d", &string[i]);
    }
    
    for(i = 0; i < n_pos_memoria; ++i)
    {
        frames[i] = -1;
    }
    
    for(i = 0; i < n_paginas; ++i)
    {
        flag1 = flag2 = 0;
        
        for(j = 0; j < n_pos_memoria; ++j)
        {
            if(frames[j] == string[i])
            {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }
        
        if(flag1 == 0)
        {
            for(j = 0; j < n_pos_memoria; ++j)
            {
                if(frames[j] == -1)
                {
                    counter++;
                    trocas++;
                    frames[j] = string[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }    
        }
        
        if(flag2 == 0)
        {
            pos = LRU(time, n_pos_memoria);
            counter++;
            trocas++;
            frames[pos] = string[i];
            time[pos] = counter;
        }
        
        printf("\n");
        
        for(j = 0; j < n_pos_memoria; ++j)
        {
            printf("%d\t", frames[j]);
        }
    }
    
    printf("\n\nTotal de reposicao de paginas = %d", trocas);
    
    getch();
    return 0;
}
