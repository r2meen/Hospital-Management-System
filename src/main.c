#include <stdio.h>
#include <stdlib.h>
#include "../include/patient.h"
#include "../include/doctor.h"
#include "../include/operations.h"
#include "../include/colors.h"

/* ===========================
   SUB-MENUS
   =========================== */

void patientMenu()
{
    int choice;
    do
    {
        printf(GREEN "\n===========================================\n" RESET);
        printf(GREEN "             PATIENTS MODULE \n" RESET);
        printf(GREEN "===========================================\n" RESET);
        printf("1 - Add Patient\n");
        printf("2 - Search Patient\n");
        printf("3 - Update Patient\n");
        printf("4 - Delete Patient\n");
        printf(YELLOW "5 - Back to Main Menu\n" RESET);
        printf(GREEN "===========================================\n" RESET);
        printf(YELLOW "Enter your choice (1-5): " RESET);

        if (scanf("%d", &choice) != 1)
        {
            printf(RED "Invalid input! Please enter a number.\n" RESET);
            while (getchar() != '\n')
                ; // clear buffer
            continue;
        }

        switch (choice)
        {
        case 1:
            addPatient();
            break;
        case 2:
            searchPatient();
            break;
        case 3:
            updatePatient();
            break;
        case 4:
            deletePatient();
            break;
        case 5:
            printf(YELLOW "\nReturning to Main Menu...\n" RESET);
            break;
        default:
            printf(RED "\nInvalid choice! Please select 1-5.\n" RESET);
        }
    } while (choice != 5);
}

void doctorMenu()
{
    int choice;
    do
    {
        printf(BLUE "\n===========================================\n" RESET);
        printf(BLUE "              DOCTORS MODULE \n" RESET);
        printf(BLUE "===========================================\n" RESET);
        printf("1 - Add New Doctor\n");
        printf("2 - Search & View Doctors Database\n");
        printf(YELLOW "3 - Back to Main Menu\n" RESET);
        printf(BLUE "===========================================\n" RESET);
        printf(YELLOW "Enter your choice (1-3): " RESET);

        if (scanf("%d", &choice) != 1)
        {
            printf(RED "Invalid input! Please enter a number.\n" RESET);
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (choice)
        {
        case 1:
            addDoctor();
            break;
        case 2:
            searchDoctor();
            break;
        case 3:
            printf(YELLOW "\nReturning to Main Menu...\n" RESET);
            break;
        default:
            printf(RED "\nInvalid choice! Please select 1-3.\n" RESET);
        }
    } while (choice != 3);
}

void operationsMenu()
{
    int choice;
    do
    {
        printf(MAGENTA "\n===========================================\n" RESET);
        printf(MAGENTA "            OPERATIONS MODULE \n" RESET);
        printf(MAGENTA "===========================================\n" RESET);
        printf("1 - Create Appointment\n");
        printf("2 - Generate Bill\n");
        printf("3 - Display Reports\n");
        printf(YELLOW "4 - Back to Main Menu\n" RESET);
        printf(MAGENTA "===========================================\n" RESET);
        printf(YELLOW "Enter your choice (1-4): " RESET);

        if (scanf("%d", &choice) != 1)
        {
            printf(RED "Invalid input! Please enter a number.\n" RESET);
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (choice)
        {
        case 1:
            createAppointment();
            break;
        case 2:
            generateBill();
            break;
        case 3:
            displayReports();
            break;
        case 4:
            printf(YELLOW "\nReturning to Main Menu...\n" RESET);
            break;
        default:
            printf(RED "\nInvalid choice! Please select 1-4.\n" RESET);
        }
    } while (choice != 4);
}

/* ===========================
   MAIN MENU
   =========================== */

void displayMainMenu()
{
    printf(CYAN "\n===========================================\n" RESET);
    printf(YELLOW "         HOSPITAL MANAGEMENT SYSTEM \n" RESET);
    printf(CYAN "===========================================\n" RESET);
    printf("1 - Patients Module\n");
    printf("2 - Doctors Module\n");
    printf("3 - Operations Module\n");
    printf(RED "4 - Exit Program\n" RESET);
    printf(CYAN "===========================================\n" RESET);
}

int main()
{
    int choice;

    do
    {
        displayMainMenu();
        printf(YELLOW "Enter your choice (1-4): " RESET);

        if (scanf("%d", &choice) != 1)
        {
            printf(RED "Invalid input! Please enter a number.\n" RESET);
            while (getchar() != '\n')
                ; // clear buffer
            continue;
        }

        switch (choice)
        {
        case 1:
            patientMenu();
            break;
        case 2:
            doctorMenu();
            break;
        case 3:
            operationsMenu();
            break;
        case 4:
            printf(GREEN "\nExiting program... Thank you!\n" RESET);
            break;
        default:
            printf(RED "\nInvalid choice! Please select 1-4.\n" RESET);
        }

    } while (choice != 4);

    return 0;
}