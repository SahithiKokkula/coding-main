#include <stdio.h>

#define MAX_NAME_LENGTH 50
#define NUM_SUBJECTS 3
#define MAX_STUDENTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    float marks[NUM_SUBJECTS];
    float average;
} Student;

int main() {
    // Open the file
    FILE *file = fopen("student.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read data from the file
    int num_students;
    fscanf(file, "%d", &num_students);
    if (num_students > MAX_STUDENTS) {
        printf("Error: Too many students\n");
        fclose(file);
        return 1;
    }

    // Read student information from the file
    Student students[MAX_STUDENTS];
    for (int i = 0; i < num_students; i++) {
        fscanf(file, "%s", students[i].name);
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            fscanf(file, "%f", &students[i].marks[j]);
        }
    }

    // Calculate average marks for each student
    for (int i = 0; i < num_students; i++) {
        float sum = 0.0;
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            sum += students[i].marks[j];
        }
        students[i].average = sum / NUM_SUBJECTS;
    }

    // Display student information with average marks
    printf("Student Information with Average Marks:\n");
    for (int i = 0; i < num_students; i++) {
        printf("Name: %s, Average Marks: %.2f\n", students[i].name, students[i].average);
    }

    // Close the file
    fclose(file);

    return 0;
}
