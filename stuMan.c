#include <stdio.h>

struct Student
{
    int id;
    char name[50];
    int age;
    float marks;
};

int main()
{
    struct Student students[100];
    int numberOfStudents = 0;
    int choice;
    int i;
    int id;
    int found;

    while (1)
    {
        printf("\n====================================\n");
        printf("       STUDENT MANAGEMENT SYSTEM\n");
        printf("====================================\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("====================================\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("\nInvalid input! Nothing was saved.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice)
        {
            /* ADD STUDENT */
            case 1:
            {
                if (numberOfStudents >= 100)
                {
                    printf("\nStudent limit reached!\n");
                    break;
                }

                struct Student temp;

                printf("\nEnter Student ID: ");
                if (scanf("%d", &temp.id) != 1)
                {
                    printf("\nInvalid ID! Student was NOT saved.\n");
                    while (getchar() != '\n');
                    break;
                }

                printf("Enter Student Name: ");
                if (scanf(" %49[^\n]", temp.name) != 1)
                {
                    printf("\nInvalid name! Student was NOT saved.\n");
                    while (getchar() != '\n');
                    break;
                }

                printf("Enter Age: ");
                if (scanf("%d", &temp.age) != 1)
                {
                    printf("\nInvalid age! Student was NOT saved.\n");
                    while (getchar() != '\n');
                    break;
                }

                printf("Enter Marks: ");
                if (scanf("%f", &temp.marks) != 1)
                {
                    printf("\nInvalid marks! Student was NOT saved.\n");
                    while (getchar() != '\n');
                    break;
                }

                students[numberOfStudents] = temp;
                numberOfStudents++;
                printf("\nStudent added successfully!\n");
                break;
            }

            /* DISPLAY STUDENTS */
            case 2:
            {
                if (numberOfStudents == 0)
                {
                    printf("\nNo students available.\n");
                }
                else
                {
                    printf("\n========== STUDENT LIST ==========\n");
                    for (i = 0; i < numberOfStudents; i++)
                    {
                        printf("\nStudent %d\n", i + 1);
                        printf("ID     : %d\n", students[i].id);
                        printf("Name   : %s\n", students[i].name);
                        printf("Age    : %d\n", students[i].age);
                        printf("Marks  : %.2f\n", students[i].marks);

                        /* KEPT: else-if is still required here for range evaluations */
                        if (students[i].marks >= 90)
                            printf("Grade  : A+\n");
                        else if (students[i].marks >= 80)
                            printf("Grade  : A\n");
                        else if (students[i].marks >= 70)
                            printf("Grade  : B\n");
                        else if (students[i].marks >= 60)
                            printf("Grade  : C\n");
                        else if (students[i].marks >= 50)
                            printf("Grade  : D\n");
                        else
                            printf("Grade  : F\n");
                    }
                }
                break;
            }

            /* SEARCH STUDENT */
            case 3:
            {
                printf("\nEnter Student ID to search: ");
                if (scanf("%d", &id) != 1)
                {
                    printf("\nInvalid ID!\n");
                    while (getchar() != '\n');
                    break;
                }

                found = 0;
                for (i = 0; i < numberOfStudents; i++)
                {
                    if (students[i].id == id)
                    {
                        printf("\nStudent Found!\n");
                        printf("ID     : %d\n", students[i].id);
                        printf("Name   : %s\n", students[i].name);
                        printf("Age    : %d\n", students[i].age);
                        printf("Marks  : %.2f\n", students[i].marks);
                        found = 1;
                        break;
                    }
                }

                if (!found)
                    printf("\nStudent not found.\n");
                break;
            }

            /* UPDATE STUDENT */
            case 4:
            {
                printf("\nEnter Student ID to update: ");
                if (scanf("%d", &id) != 1)
                {
                    printf("\nInvalid ID!\n");
                    while (getchar() != '\n');
                    break;
                }

                found = 0;
                for (i = 0; i < numberOfStudents; i++)
                {
                    if (students[i].id == id)
                    {
                        struct Student temp = students[i];

                        printf("Enter new name: ");
                        scanf(" %49[^\n]", temp.name);

                        printf("Enter new age: ");
                        scanf("%d", &temp.age);

                        printf("Enter new marks: ");
                        scanf("%f", &temp.marks);

                        students[i] = temp;
                        printf("\nStudent updated successfully!\n");
                        found = 1;
                        break;
                    }
                }

                if (!found)
                    printf("\nStudent not found.\n");
                break;
            }

            /* DELETE STUDENT */
            case 5:
            {
                printf("\nEnter Student ID to delete: ");
                if (scanf("%d", &id) != 1)
                {
                    printf("\nInvalid ID!\n");
                    while (getchar() != '\n');
                    break;
                }

                found = 0;
                for (i = 0; i < numberOfStudents; i++)
                {
                    if (students[i].id == id)
                    {
                        for (int j = i; j < numberOfStudents - 1; j++)
                        {
                            students[j] = students[j + 1];
                        }
                        numberOfStudents--;
                        printf("\nStudent deleted successfully!\n");
                        found = 1;
                        break;
                    }
                }

                if (!found)
                    printf("\nStudent not found.\n");
                break;
            }

            /* EXIT */
            case 6:
                printf("\nThank you for using the system!\n");
                return 0;

            /* INVALID CHOICE */
            default:
                printf("\nInvalid choice! Nothing was saved.\n");
                break;
        }
    }

    return 0;
}