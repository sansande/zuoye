#include <stdio.h>

int isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int year, int month) {
    if (month == 2) {
        return isLeap(year) ? 29 : 28;
    }
    return (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31;
}

int calcDaysDiff(int targetYear, int targetMonth) {
    const int baseYear = 2025, baseMonth = 11, baseDay = 12;
    int days = 0;

    int targetYear1 = targetYear;
    int targetMonth1 = targetMonth;
    int targetDay1 = 1;

    if (targetYear1 > baseYear) {
        for (int year = baseYear; year < targetYear1; year++) {
            days += isLeap(year) ? 366 : 365;
        }
        int baseDays = 0;
        for (int m = 1; m < baseMonth; m++) {
            baseDays += daysInMonth(baseYear, m);
        }
        baseDays += baseDay;
        days -= baseDays;

        int targetDays = 0;
        for (int m = 1; m < targetMonth1; m++) {
            targetDays += daysInMonth(targetYear1, m);
        }
        targetDays += targetDay1;
        days += targetDays;
    } else if (targetYear1 < baseYear) {
        for (int year = targetYear1; year < baseYear; year++) {
            days -= isLeap(year) ? 366 : 365;
        }
        int baseDays = 0;
        for (int m = 1; m < baseMonth; m++) {
            baseDays += daysInMonth(baseYear, m);
        }
        baseDays += baseDay;
        days += baseDays;

        int targetDays = 0;
        for (int m = 1; m < targetMonth1; m++) {
            targetDays += daysInMonth(targetYear1, m);
        }
        targetDays += targetDay1;
        days -= targetDays;
    } else {
        int baseDays = 0, targetDays = 0;
        for (int m = 1; m < baseMonth; m++) {
            baseDays += daysInMonth(baseYear, m);
        }
        baseDays += baseDay;

        for (int m = 1; m < targetMonth1; m++) {
            targetDays += daysInMonth(targetYear1, m);
        }
        targetDays += targetDay1;

        days = targetDays - baseDays;
    }

    return days;
}

void printMonthCalendar(int year, int month) {
    int diff = calcDaysDiff(year, month);
    int firstDayWeek = (diff + 3) % 7;
    if (firstDayWeek < 0) firstDayWeek += 7;

    int days = daysInMonth(year, month);
    printf("=== %d月 ===\n", month);
    printf("日 一 二 三 四 五 六\n");

    for (int i = 0; i < firstDayWeek; i++) {
        printf("   ");
    }

    for (int day = 1; day <= days; day++) {
        printf("%2d ", day);
        if ((firstDayWeek + day) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n\n");
}

void printFullYearCalendar(int year) {
    printf("\n=== %d年完整日历 ===\n\n", year);
    for (int month = 1; month <= 12; month++) {
        printMonthCalendar(year, month);
    }
}

int main() {
    int year;
    printf("请输入年份：");
    scanf("%d", &year);

    printFullYearCalendar(year);

    return 0;
}
