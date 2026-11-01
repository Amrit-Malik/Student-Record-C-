/* Name - Amrit Malik
SAP ID - 590032657
Batch No. 20 */
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
void searchStudent();
void deleteStudent();
float calculateCGPA(struct Student s);
void displayCGPA();
void displayYearWiseAverage();
void sortBySapId();
void sortByName();

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
                searchStudent();
                break;

            case 3:
                displayAllStudents();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                displayCGPA();
                break;

            case 6:
                displayYearWiseAverage();
                break;

            case 7:
                sortBySapId();
                break;

            case 8:
                sortByName();
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
void searchStudent()
{
    long long searchSapId;
    int i, j;
    int found = 0;

    if (studentCount == 0)
    {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n========== SEARCH STUDENT ==========\n");
    printf("Enter SAP ID to search: ");
    scanf("%lld", &searchSapId);

    for (i = 0; i < studentCount; i++)
    {
        if (students[i].sapId == searchSapId)
        {
            printf("\nStudent Found!\n");
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

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent with SAP ID %lld not found.\n", searchSapId);
    }
}
void deleteStudent()
{
    long long deleteSapId;
    int i, j;
    int found = 0;

    if (studentCount == 0)
    {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n========== DELETE STUDENT ==========\n");
    printf("Enter SAP ID to delete: ");
    scanf("%lld", &deleteSapId);

    for (i = 0; i < studentCount; i++)
    {
        if (students[i].sapId == deleteSapId)
        {
            for (j = i; j < studentCount - 1; j++)
            {
                students[j] = students[j + 1];
            }

            studentCount--;

            printf("\nStudent record deleted successfully!\n");

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent with SAP ID %lld not found.\n", deleteSapId);
    }
}
float calculateCGPA(struct Student s)
{
    float sum = 0.0;
    int count = 0;
    int i;

    for (i = 0; i < s.semester; i++)
    {
        if (s.sgpa[i] > 0)
        {
            sum = sum + s.sgpa[i];
            count++;
        }
    }

    if (count == 0)
    {
        return 0.0;
    }

    return sum / count;
}
void displayCGPA()
{
    long long searchSapId;
    int i;
    int found = 0;
    float cgpa;

    if (studentCount == 0)
    {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n========== CALCULATE CGPA ==========\n");
    printf("Enter SAP ID: ");
    scanf("%lld", &searchSapId);

    for (i = 0; i < studentCount; i++)
    {
        if (students[i].sapId == searchSapId)
        {
            cgpa = calculateCGPA(students[i]);

            printf("\nStudent Name : %s\n", students[i].name);
            printf("SAP ID       : %lld\n", students[i].sapId);
            printf("CGPA         : %.2f\n", cgpa);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent with SAP ID %lld not found.\n", searchSapId);
    }
}
void displayYearWiseAverage()
{
    int year, i;
    int count;
    float totalCGPA;
    float averageCGPA;

    if (studentCount == 0)
    {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n========== YEAR-WISE AVERAGE CGPA ==========\n");

    for (year = 1; year <= 4; year++)
    {
        totalCGPA = 0.0;
        count = 0;

        for (i = 0; i < studentCount; i++)
        {
            if (students[i].year == year)
            {
                totalCGPA = totalCGPA + calculateCGPA(students[i]);
                count++;
            }
        }

        if (count > 0)
        {
            averageCGPA = totalCGPA / count;

            printf("Year %d Average CGPA: %.2f\n",
                   year, averageCGPA);
        }
        else
        {
            printf("Year %d: No student records available.\n", year);
        }
    }
}
void sortBySapId()
{
    struct Student temp[MAX_STUDENTS];
    struct Student swap;
    int i, j;

    if (studentCount == 0)
    {
        printf("\nNo student records available.\n");
        return;
    }

    /* Copy records so original order is not changed */
    for (i = 0; i < studentCount; i++)
    {
        temp[i] = students[i];
    }

    /* Bubble sort by SAP ID */
    for (i = 0; i < studentCount - 1; i++)
    {
        for (j = 0; j < studentCount - i - 1; j++)
        {
            if (temp[j].sapId > temp[j + 1].sapId)
            {
                swap = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = swap;
            }
        }
    }

    printf("\n========== STUDENTS SORTED BY SAP ID ==========\n");

    for (i = 0; i < studentCount; i++)
    {
        printf("\nSAP ID   : %lld\n", temp[i].sapId);
        printf("Roll No  : %s\n", temp[i].rollNo);
        printf("Name     : %s\n", temp[i].name);
        printf("Year     : %d\n", temp[i].year);
        printf("Semester : %d\n", temp[i].semester);
        printf("CGPA     : %.2f\n", calculateCGPA(temp[i]));
    }
}
void sortByName()
{
    struct Student temp[MAX_STUDENTS];
    struct Student swap;
    int i, j;

    if (studentCount == 0)
    {
        printf("\nNo student records available.\n");
        return;
    }

    /* Copy records so original order is not changed */
    for (i = 0; i < studentCount; i++)
    {
        temp[i] = students[i];
    }

    /* Bubble sort alphabetically by name */
    for (i = 0; i < studentCount - 1; i++)
    {
        for (j = 0; j < studentCount - i - 1; j++)
        {
            if (strcmp(temp[j].name, temp[j + 1].name) > 0)
            {
                swap = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = swap;
            }
        }
    }

    printf("\n========== STUDENTS SORTED BY NAME ==========\n");

    for (i = 0; i < studentCount; i++)
    {
        printf("\nName     : %s\n", temp[i].name);
        printf("SAP ID   : %lld\n", temp[i].sapId);
        printf("Roll No  : %s\n", temp[i].rollNo);
        printf("Year     : %d\n", temp[i].year);
        printf("Semester : %d\n", temp[i].semester);
        printf("CGPA     : %.2f\n", calculateCGPA(temp[i]));
    }
}