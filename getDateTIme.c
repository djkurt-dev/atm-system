#include <stdio.h>
#include<conio.h>
#include<time.h>

int main() {
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    //printf("Current Date: %d-%d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    char current_date[] = "%d-%d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900;
    printf("%s", current_date);
    return 0;
}