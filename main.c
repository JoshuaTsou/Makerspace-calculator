//
//  main.c
//  Makerspace project
//
//  Created by air on 11/14/17.
//  Copyright © 2017 air. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int cal(int a,int b,int cha)
{
    if(cha==4)
        return a+b;
    else if (cha==3)  // 16~22    exp 2+3 cpu see 2 3 4. 4 is+
        return b-a;
    else if (cha==2)
        return a*b;
    else if (cha==1)
        return b/a;
    return 0;
}

int main() {  // every main.c need int main
    // insert code here...
    char exp[90];  // char= character exp= expression [90]= 90 string
    int explength,i,calcha[30],calnum[60],numnow,chanow,numsup,numflag,calflag;
    // explength= expression length, i= a character which help cpu calculate, calcha[30]= 30 calculator character(+-*/), calnum [60]= 60 calculator number, numnow= how much number there is now, chanow= how much calcha, numsup= number support, numflag= check if it is number if yes set it to 1 if it is not then set to 0.
    while(1)
    {
        printf("Please input the expression:\n");
        gets(exp);  // get the expression
        explength=strlen(exp);  // let the cpu tell me how long is the expression(表达式)
        if(explength<=1)  // if explength is smaller then 1 quit
            break;
        for(i=0,chanow=0,numnow=0;i<explength;i++)  // keep reading all the number or sign until it end
        {
            calflag=0;  // when start all the number equals 0
            numflag=0;
            numsup=0;
            while(exp[i]<='9'&&exp[i]>='0')  // if it is 0~9 then save the number
            {
                numflag=1;  // I read a number
                numsup*=10; // multiply 10 until the last number
                numsup+=exp[i]-48;  // plus the number after you multiply
                i++; // keep reading the next number
            }
            if(numflag==1)
            {
                calnum[numnow]=numsup;
                numflag=0;
                numnow++;
            }
            if(i>=explength-1)
                break;
            if(exp[i]=='+')
            {
                calcha[chanow]=4;
            }
            else if(exp[i]=='-')
            {
                calcha[chanow]=3;
            }
            else if(exp[i]=='*')
            {
                calcha[chanow]=2;
            }
            else if(exp[i]=='/')
            {
                calcha[chanow]=1;
            }
            else
            {
                printf("ERROR!\n");
                calflag=1;
                break;
            }
            while((calcha[chanow]>calcha[chanow-1])&&(chanow!=0))
            {
                calnum[numnow-2]=cal(calnum[numnow-1],calnum[numnow-2],calcha[chanow-1]);
                calcha[chanow-1]=calcha[chanow];
                calcha[chanow]=0;
                chanow--;
                calnum[numnow-1]=0;
                numnow--;
            }
            if((calcha[chanow]<=calcha[chanow-1])||(chanow==0))
            {
                chanow++;
            }
        }
        if(calflag==1)
            continue;
        while(chanow>=1)
        {
            calnum[numnow-2]=cal(calnum[numnow-1],calnum[numnow-2],calcha[chanow-1]);
            calnum[numnow-1]=0;
            numnow--;
            calcha[chanow-1]=0;
            chanow--;
        }
        printf("=%d\n",calnum[0]);
    }
    return 0;
}
