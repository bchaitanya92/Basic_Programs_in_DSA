#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to represent a day in the calendar
struct Day{
    char *dayName, *activity;
    int date,month,year;
};  // <- Add semicolon here

// Function to create a day in the calendar
struct Day create() {
    struct Day day;
    day.dayName = (char *)malloc(20 * sizeof(char));
    day.activity = (char *)malloc(100 * sizeof(char));
    printf("Enter the day name: ");
    scanf("%s", day.dayName);
    printf("Enter the date (DD/MM/YY): ");
    scanf("%d/%d/%d", &day.date, &day.month, &day.year);
    printf("Enter the activity: ");
    scanf(" %[^\n]", day.activity);  //[^\n]: it is used for giving white spaces between the words in a sentance.
    return day;
}

// Function to read data for all seven days
void read(struct Day calendar[7]) {
    for (int i = 0; i < 7; i++) {
        printf("\nDay %d:\n", i + 1);
        calendar[i] = create();
    }
}

// Function to display the calendar
void display(struct Day calendar[7]) {
    printf("\n Weekly Calendar\n");
    for (int i = 0; i < 7; i++) {
        printf("\nDay %d:\n", i + 1);
        printf("Name: %s\n", calendar[i].dayName);
        printf("Date: %02d/%02d/%02d\n", calendar[i].date, calendar[i].month, calendar[i].year % 100);
        printf("Activity: %s\n", calendar[i].activity);
    }
}

void main() {
    struct Day calendar[7];
    printf("Please enter data for each day of the week:\n");
    read(calendar);
    display(calendar);
    
    // Free dynamically allocated memory
    for (int i = 0; i < 7; i++) {
        free(calendar[i].dayName);
        free(calendar[i].activity);
    }
}