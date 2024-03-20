
//  This is a simple college management system that allows you to add students and courses, and display them.

#include <stdio.h>
#include <stdlib.h>

// Define structures for student and course
struct Student {
    int id;
    char fname[30];
    char lname[30];
};

struct Course {
    int id;
    char name[60];
};

// Function to add a new student
void addStudent(struct Student *students, int *numStudents) {
    if (*numStudents < 100) {
        printf("Enter student ID Number: ");
        scanf("%d", &students[*numStudents].id);
        printf("Enter student's First Name: ");
        scanf("%s", students[*numStudents].fname);
        printf("Enter student's Last Name: ");
        scanf("%s", students[*numStudents].lname);
        (*numStudents)++;
        printf("\nStudent added successfully.\n\n");
    } else {
        printf("Maximum number of students reached.\n");
    }
}

// Function to add a new course
void addCourse(struct Course *courses, int *numCourses) {
    // TODO: Implement the logic to add a new course
    if (*numCourses < 100) {
        printf("\nEnter course Code:");
        scanf("%d", &courses[*numCourses].id);
        printf("Enter course Name:\n ");
        scanf("%s", courses[*numCourses].name);
        (*numCourses)++;
        printf("Course added successfully.\n");
    } else {
        printf("Maximum number of courses reached.\n");
    }
}

// Function to display all students
void displayStudents(struct Student *students, int numStudents) {
    printf("\nStudent List:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student ID: %d \n", students[i].id);
        printf("Name: %s %s\n", students[i].fname, students[i].lname);
        printf("\n");
    }
}

// Function to display all courses
void displayCourses(struct Course *courses, int numCourses) {
    printf("\nCourse List:\n");
    for (int i = 0; i < numCourses; i++) {
        printf("Coure ID: %d\n", courses[i].id);
        printf("Name of Course is: %s\n", courses[i].name);
        printf("\n");
    }
}

int main() {
    struct Student students[100];
    struct Course courses[100];
    int numStudents = 0;
    int numCourses = 0;
    int choice;

    do {
        printf("\nCollege Management System\n\n");
        printf("1. Add Student\n");
        printf("2. Add Course\n");
        printf("3. Display Students\n");
        printf("4. Display Courses\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &numStudents);
                break;
            case 2:
                addCourse(courses, &numCourses);
                break;
            case 3:
                displayStudents(students, numStudents);
                break;
            case 4:
                displayCourses(courses, numCourses);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}