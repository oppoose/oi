#include <stdio.h>
int main()
{
    int hour1,minute1;
    int hour2,minute2;
    scanf("%d:%d", &hour1, &minute1);
    scanf("%d:%d", &hour2, &minute2);
    
    int total_minutes1 = hour1 * 60 + minute1;
    int total_minutes2 = hour2 * 60 + minute2;


     
    int difference = total_minutes2 - total_minutes1;
    if (difference < 0) {
        difference += 24 * 60; // Adjust for next day
    }

    int result_hour = difference / 60;
    int result_minute = difference % 60;
    printf("%02d:%02d\n", result_hour, result_minute);
    return 0;
}