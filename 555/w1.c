#include <stdio.h>

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_of_month(int year, int month) {
    int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (month == 2 && isLeapYear(year)) return 29;
    return days[month - 1];
}

int calc_total_days(int year, int month, int day) {
    int days = 0;
    for (int y = 1; y < year; y++) {
        days += isLeapYear(y) ? 366 : 365;
    }
    for (int m = 1; m < month; m++) {
        days += days_of_month(year, m);
    }
    days += day;
    return days;
}

int main() {
    int year, month, day;
    printf("请输入年份：");
    scanf("%d", &year);
    printf("请输入月份：");
    scanf("%d", &month);
    printf("请输入日期：");
    scanf("%d", &day);

    int base_year = 2025, base_month = 11, base_day = 12;
    int diff_days = calc_total_days(year, month, day) - calc_total_days(base_year, base_month, base_day);
    
    int week = (3 + (diff_days % 7 + 7) % 7) % 7; 
    char *week_str[] = {"日", "一", "二", "三", "四", "五", "六"};
    
    printf("%d年%d月%d日是星期%s\n", year, month, day, week_str[week]);
    return 0;
}
