#include <cs50.h>
#include <stdio.h>
#include <math.h>
int main() 
{
    int counter; 
    float change;
    counter = 0;
    do //doWhile loop to get positive float
    {
    change = get_float("Change owed: ");
    change = round(change * 100); // change set to a 2dp value
    change = change / 100;
    }
    while(change < 0);

    while(change >= 0.25) // while loop to decrement by 25c
        {
            counter ++;
            change -= 0.25;
        }
    
    change = round(change * 100); // change set to a 2dp value
    change = change / 100;
    
    while(change >= 0.1)
        {
            counter ++;
            change -= 0.1;
        } 
    
    change = round(change * 100); // change set to a 2dp value
    change = change / 100;
    
    while(change >= 0.05)
        {
            counter ++;
            change -= 0.05;#include <cs50.h>
#include <stdio.h>
#include <math.h>
int main() 
{
    int counter; 
    float change;
    counter = 0;
    do //doWhile loop to get positive float
    {
    change = get_float("Change owed: ");
    change = round(change * 100); // change set to a 2dp value
    change = change / 100;
    }
    while(change < 0);

    while(change >= 0.25) // while loop to decrement by 25c
    {
        counter ++;
        change -= 0.25;
    }
    
    change = round(change * 100); // change set to a 2dp value
    change = change / 100;
    
    while(change >= 0.1)
    {
        counter ++;
        change -= 0.1;
    } 
    
    change = round(change * 100); // change set to a 2dp value
    change = change / 100;
    
    while(change >= 0.05)
    {
        counter ++;
        change -= 0.05;
    }   
    
    change = round(change * 100); // change set to a 2dp value
    change = change / 100;
    
    while(change > 0.0)
    {
        counter ++;
        change -= 0.01;
        change = round(change * 100); // change set to a 2dp value
        change = change / 100;
    }
    printf("%d\n", counter);
    return 0;
}

        }   
    
    change = round(change * 100); // change set to a 2dp value
    change = change / 100;
    
    while(change > 0.0)
        {
            counter ++;
            change -= 0.01;
            change = round(change * 100); // change set to a 2dp value
            change = change / 100;
        }
    printf("%d\n", counter);
    return 0;
}
