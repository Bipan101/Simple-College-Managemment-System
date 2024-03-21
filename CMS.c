//Simple College Management System

#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    char fname[30];
    char lname[30];
};

struct Course {
    int id;
    char name[60];
};

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

void addCourse(struct Course *courses, int *numCourses) {
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

void deleteStudent(struct Student *students, int *numStudents) {
    if (*numStudents > 0) {
        int studentId;
        printf("Enter student ID to delete: ");
        scanf("%d", &studentId);

        int found = 0;
        for (int i = 0; i < *numStudents; i++) {
            if (students[i].id == studentId) {
                // Shift the remaining elements to fill the gap
                for (int j = i; j < *numStudents - 1; j++) {
                    students[j] = students[j + 1];
                }
                (*numStudents)--;
                found = 1;
                break;
            }
        }

        if (found) {
            printf("Student record deleted successfully.\n");
        } else {
            printf("Student record not found.\n");
        }
    } else {
        printf("No students found.\n");
    }
}

void deleteCourse(struct Course *courses, int *numCourses) {
    if (*numCourses > 0) {
        int courseId;
        printf("Enter course ID to delete: ");
        scanf("%d", &courseId);

        int found = 0;
        for (int i = 0; i < *numCourses; i++) {
            if (courses[i].id == courseId) {
                // Shift the remaining elements to fill the gap
                for (int j = i; j < *numCourses - 1; j++) {
                    courses[j] = courses[j + 1];
                }
                (*numCourses)--;
                found = 1;
                break;
            }
        }

        if (found) {
            printf("Course record deleted successfully.\n");
        } else {
            printf("Course record not found.\n");
        }
    } else {
        printf("No courses found.\n");
    }
}

void displayStudents(struct Student *students, int numStudents) {
    printf("\nStudent List:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student ID: %d \n", students[i].id);
        printf("Name: %s %s\n", students[i].fname, students[i].lname);
        printf("\n");
    }
}

void displayCourses(struct Course *courses, int numCourses) {
    printf("\nCourse List:\n");
    for (int i = 0; i < numCourses; i++) {
        printf("Course ID: %d\n", courses[i].id);
        printf("Name of Course is: %s\n", courses[i].name);
        printf("\n");
    }
}

void saveData(struct Student *students, int numStudents, struct Course *courses, int numCourses) {
    FILE *file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "Students:\n");
    for (int i = 0; i < numStudents; i++) {
        fprintf(file, "ID: %d\n", students[i].id);
        fprintf(file, "Name: %s %s\n", students[i].fname, students[i].lname);
        fprintf(file, "\n");
    }

    fprintf(file, "Courses:\n");
    for (int i = 0; i < numCourses; i++) {
        fprintf(file, "ID: %d\n", courses[i].id);
        fprintf(file, "Name: %s\n", courses[i].name);
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Data saved to file successfully.\n");
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
        printf("3. Delete Student\n");
        printf("4. Delete Courses Record\n");
        printf("5. Display Students Record\n");
        printf("6. Display Courses\n");
        printf("7. Save Data to File\n");
        printf("8. Exit\n");
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
                deleteStudent(students, &numStudents);
                break;
            case 4:
                deleteCourse(courses, &numCourses);
                break;
            case 5:
                displayStudents(students, numStudents);
                break;
            case 6:
                displayCourses(courses, numCourses);
                break;
            case 7:
                saveData(students, numStudents, courses, numCourses);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}
