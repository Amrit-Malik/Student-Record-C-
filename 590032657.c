#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_SEMESTERS 8

struct Student
{
    long long sapId;
    char rollNo[20];
    char name[50];
    char phone[15];
    char email[60];
    int year;
    int semester;
    float sgpa[MAX_SEMESTERS];
};

struct Student students[MAX_STUDENTS];
int studentCount = 0;

/* Function declarations */
void displayMenu();
void addStudent();
void displayAllStudents();

int main()
{
    int choice;

    do
    {
        displayMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                printf("\nSearch Student feature will be added next.\n");
                break;

            case 3:
                displayAllStudents();
                break;

            case 4:
                printf("\nDelete Student feature will be added next.\n");
                break;

            case 5:
                printf("\nCGPA calculation feature will be added next.\n");
                break;

            case 6:
                printf("\nYear-wise average CGPA feature will be added next.\n");
                break;

            case 7:
                printf("\nSorting by SAP ID will be added next.\n");
                break;

            case 8:
                printf("\nSorting by Name will be added next.\n");
                break;

            case 9:
                printf("\nAI-Assisted Academic Advisor will be added next.\n");
                break;

            case 0:
                printf("\nProgram closed successfully.\n");
                break;

            default:
                printf("\nInvalid choice! Please enter a number from 0 to 9.\n");
        }

    } while (choice != 0);

    return 0;
}


/* Displays the main menu */
void displayMenu()
{
    printf("\n=============================================\n");
    printf(" STUDENT RECORD AND RESULT MANAGEMENT SYSTEM\n");
    printf("=============================================\n");
    printf("1. Add Student\n");
    printf("2. Search Student\n");
    printf("3. Display All Students\n");
    printf("4. Delete Student\n");
    printf("5. Calculate and Display CGPA\n");
    printf("6. Display Year-wise Average CGPA\n");
    printf("7. Display Students Sorted by SAP ID\n");
    printf("8. Display Students Sorted by Name\n");
    printf("9. AI-Assisted Academic Advisor\n");
    printf("0. Exit\n");
    printf("=============================================\n");
}


/* Adds a new student record */
void addStudent()
{
    int i;

    if (studentCount >= MAX_STUDENTS)
    {
        printf("\nStudent storage is full!\n");
        return;
    }

    printf("\n========== ADD STUDENT ==========\n");

    printf("Enter SAP ID: ");
    scanf("%lld", &students[studentCount].sapId);

    printf("Enter Roll No: ");
    scanf(" %19s", students[studentCount].rollNo);

    printf("Enter Name: ");
    scanf(" %49[^\n]", students[studentCount].name);

    printf("Enter Phone No: ");
    scanf(" %14s", students[studentCount].phone);

    printf("Enter Email ID: ");
    scanf(" %59s", students[studentCount].email);

    printf("Enter Year (1-4): ");
    scanf("%d", &students[studentCount].year);

    printf("Enter Current Semester (1-8): ");
    scanf("%d", &students[studentCount].semester);

    for (i = 0; i < MAX_SEMESTERS; i++)
    {
        students[studentCount].sgpa[i] = 0.0;
    }

    printf("\nEnter SGPA for completed semesters:\n");

    for (i = 0; i < students[studentCount].semester; i++)
    {
        printf("Semester %d SGPA: ", i + 1);
        scanf("%f", &students[studentCount].sgpa[i]);
    }

    studentCount++;

    printf("\nStudent added successfully!\n");
}


/* Displays all stored students */
void displayAllStudents()
{
    int i, j;

    if (studentCount == 0)
    {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n========== ALL STUDENT RECORDS ==========\n");

    for (i = 0; i < studentCount; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("-----------------------------------------\n");

        printf("SAP ID       : %lld\n", students[i].sapId);
        printf("Roll No      : %s\n", students[i].rollNo);
        printf("Name         : %s\n", students[i].name);
        printf("Phone No     : %s\n", students[i].phone);
        printf("Email ID     : %s\n", students[i].email);
        printf("Year         : %d\n", students[i].year);
        printf("Semester     : %d\n", students[i].semester);

        printf("SGPA         : ");

        for (j = 0; j < students[i].semester; j++)
        {
            printf("Sem %d = %.2f", j + 1, students[i].sgpa[j]);

            if (j < students[i].semester - 1)
            {
                printf(", ");
            }
        }

        printf("\n");
    }
}