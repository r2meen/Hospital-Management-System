#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../include/patient.h"
#include "../include/colors.h"

/* ===========================
   UTILITY FUNCTIONS
   =========================== */
int checkDuplicateID(int inputID)
{
    FILE *fp = fopen("data/patients.txt", "r");
    if (!fp)
        return 0;
    struct Patient p;
    while (fscanf(fp, "%d,%29[^,],%29[^,],%59[^,],%d,%9[^,],%49[^,],%49[^\n]\n",
                  &p.id, p.firstName, p.lastName, p.fullName, &p.age,
                  p.gender, p.disease, p.doctorAssigned) == 8)
    {
        if (p.id == inputID)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

void displayPatientByID(int id)
{
    struct Patient p;
    FILE *fp = fopen("data/patients.txt", "r");
    int found = 0;

    if (!fp)
    {
        printf(RED "Error opening file!\n" RESET);
        return;
    }

    while (fscanf(fp, "%d,%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^\n]\n",
                  &p.id, p.firstName, p.lastName, p.fullName,
                  &p.age, p.gender, p.disease, p.doctorAssigned) != EOF)
    {
        if (p.id == id)
        {
            printf(GREEN "\nPatient Found!\n" RESET);
            printf(CYAN "-----------------------------\n" RESET);
            printf(YELLOW "ID              : " RESET "%d\n", p.id);
            printf(YELLOW "Full Name       : " RESET "%s\n", p.fullName);
            printf(YELLOW "Age             : " RESET "%d\n", p.age);
            printf(YELLOW "Gender          : " RESET "%s\n", p.gender);
            printf(YELLOW "Disease         : " RESET "%s\n", p.disease);
            printf(YELLOW "Doctor Assigned : " RESET "%s\n", p.doctorAssigned);
            printf(CYAN "-----------------------------\n" RESET);
            found = 1;
            break;
        }
    }

    if (!found)
        printf(RED "No patient found with ID %d\n" RESET, id);

    fclose(fp);
}

/* ===========================
   CORE FUNCTIONS
   =========================== */
void addPatient()
{
    int inputID;
    struct Patient p;
    FILE *fp = fopen("data/patients.txt", "a");
    if (!fp)
    {
        printf(RED "Error opening file!\n" RESET);
        return;
    }
    
    printf(CYAN "\n====== ADD NEW PATIENT ======\n" RESET);
    do
    {
        printf("Enter Patient's ID: ");
        scanf("%d", &inputID);
        if (checkDuplicateID(inputID))
        {
            printf(RED "Patient ID %d already exists!\nEnter a different ID.\n" RESET, inputID);
        }
        else
        {
            p.id = inputID;
            break;
        }
    } while (1);

    printf(YELLOW "\nEnter Patient's Name\n" RESET);
    printf("First name: ");
    scanf("%s", p.firstName);
    printf("Last name: ");
    scanf("%s", p.lastName);

    int i = 0;
    while (p.firstName[i] != '\0')
    {
        p.fullName[i] = p.firstName[i];
        i++;
    }
    p.fullName[i] = ' ';
    i++;
    int j = 0;
    while (p.lastName[j] != '\0')
    {
        p.fullName[i++] = p.lastName[j];
        j++;
    }
    p.fullName[i] = '\0';
    getchar();

    printf("Enter Patient's Age: ");
    scanf("%d", &p.age);
    if (p.age < 0)
    {
        printf(RED "Enter valid age!\n" RESET);
        scanf("%d", &p.age);
    }
    getchar();
    printf("Enter Patient's Gender: ");
    scanf("%s", p.gender);
    getchar();
    printf("Enter Patient's Disease: ");
    scanf("%[^\n]%*c", p.disease);
    printf("Enter doctor assigned: ");
    scanf("%[^\n]%*c", p.doctorAssigned);

    printf(CYAN "\n--- Review Patient Data ---\n" RESET);
    printf("ID: %d | Name: %s | Age: %d | Disease: %s | Doctor: %s\n", 
            p.id, p.fullName, p.age, p.disease, p.doctorAssigned);

    char confirm;
    printf(YELLOW "\nCONFIRM ADD (Y/N): " RESET);
    scanf(" %c", &confirm);
    if (confirm == 'Y' || confirm == 'y')
    {
        fprintf(fp, "%d,%s,%s,%s,%d,%s,%s,%s\n",
                p.id, p.firstName, p.lastName, p.fullName,
                p.age, p.gender, p.disease, p.doctorAssigned);
        printf(GREEN "\nSuccess: Patient added to database!\n" RESET);
    }
    else
        printf(RED "\nAdd cancelled!\n" RESET);

    fclose(fp);
}

void searchPatient()
{
    int choice, found = 0, inputId;
    struct Patient p;
    char name[60];
    
    printf(CYAN "\n====== SEARCH PATIENT ======\n" RESET);
    printf("1. Search by ID\n");
    printf("2. Search by Name\n");
    printf(YELLOW "Enter your choice: " RESET);
    scanf("%d", &choice);
    
    FILE *fp = fopen("data/patients.txt", "r");
    if (!fp)
    {
        printf(RED "Error opening file!\n" RESET);
        return;
    }
    
    if (choice == 1)
    {
        printf("Enter the patient ID to search: ");
        scanf("%d", &inputId);
        getchar();
        displayPatientByID(inputId);
    }
    else if (choice == 2)
    {
        getchar();
        printf("Enter the patient's name to search: ");
        scanf("%[^\n]%*c", name);
        while (fscanf(fp, "%d,%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^\n]\n",
                      &p.id, p.firstName, p.lastName, p.fullName,
                      &p.age, p.gender, p.disease, p.doctorAssigned) != EOF)
        {
            if (strstr(p.fullName, name) != NULL ||
                strstr(p.firstName, name) != NULL ||
                strstr(p.lastName, name) != NULL)
            {
                printf(GREEN "\nPatient Found!\n" RESET);
                printf(CYAN "-----------------------------\n" RESET);
                printf(YELLOW "ID              : " RESET "%d\n", p.id);
                printf(YELLOW "Full Name       : " RESET "%s\n", p.fullName);
                printf(YELLOW "Age             : " RESET "%d\n", p.age);
                printf(YELLOW "Gender          : " RESET "%s\n", p.gender);
                printf(YELLOW "Disease         : " RESET "%s\n", p.disease);
                printf(YELLOW "Doctor Assigned : " RESET "%s\n", p.doctorAssigned);
                printf(CYAN "-----------------------------\n" RESET);
                found = 1;
            }
        }
        if (!found)
            printf(RED "No patient found with this name %s\n" RESET, name);
    }
    else
        printf(RED "Invalid choice! Please enter 1 or 2.\n" RESET);
        
    fclose(fp);
}

void updatePatient()
{
    int updateID, found = 0, choice;
    struct Patient p;

    FILE *fp = fopen("data/patients.txt", "r");
    FILE *temp = fopen("data/temp.txt", "w");

    if (!fp || !temp)
    {
        printf(RED "Error opening file!\n" RESET);
        return;
    }

    printf(CYAN "\n====== UPDATE PATIENT ======\n" RESET);
    printf("Enter Patient ID to update: ");
    scanf("%d", &updateID);

    displayPatientByID(updateID);

    while (fscanf(fp, "%d,%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^\n]\n",
                  &p.id, p.firstName, p.lastName, p.fullName,
                  &p.age, p.gender, p.disease, p.doctorAssigned) != EOF)
    {
        if (p.id == updateID)
        {
            found = 1;

            struct Patient original = p;

            printf(YELLOW "\nWhich field do you want to update?\n" RESET);
            printf("1. Name\n");
            printf("2. Age\n");
            printf("3. Gender\n");
            printf("4. Disease\n");
            printf("5. Doctor Assigned\n");
            printf(RED "6. Cancel\n" RESET);
            printf("Enter choice: ");
            scanf("%d", &choice);
            getchar();

            switch (choice)
            {
            case 1:
                printf("Enter new First Name: ");
                scanf("%s", p.firstName);
                printf("Enter new Last Name: ");
                scanf("%s", p.lastName);
                sprintf(p.fullName, "%s %s", p.firstName, p.lastName);
                break;
            case 2:
                printf("Enter new Age: ");
                scanf("%d", &p.age);
                break;
            case 3:
                printf("Enter new Gender: ");
                scanf("%s", p.gender);
                break;
            case 4:
                printf("Enter new Disease: ");
                scanf(" %[^\n]", p.disease);
                break;
            case 5:
                printf("Enter new Doctor Assigned: ");
                scanf(" %[^\n]", p.doctorAssigned);
                break;
            case 6:
                printf(RED "Update cancelled.\n" RESET);
                p = original;
                break;
            default:
                printf(RED "Invalid choice! Keeping old data.\n" RESET);
                p = original;
            }

            char confirm;
            printf(YELLOW "\nSave changes? (Y/N): " RESET);
            scanf(" %c", &confirm);

            if (!(confirm == 'Y' || confirm == 'y'))
            {
                p = original; 
                printf(RED "Update cancelled.\n" RESET);
            }
            else
            {
                printf(GREEN "\nRecord Updated Successfully!\n" RESET);
            }
        }

        fprintf(temp, "%d,%s,%s,%s,%d,%s,%s,%s\n",
                p.id, p.firstName, p.lastName, p.fullName,
                p.age, p.gender, p.disease, p.doctorAssigned);
    }

    fclose(fp);
    fclose(temp);

    remove("data/patients.txt");
    rename("data/temp.txt", "data/patients.txt");

    if (!found)
        printf(RED "\nNo patient found with ID %d\n" RESET, updateID);
}

void deletePatient()
{
    int deleteID, found = 0;
    struct Patient p, toDelete;

    FILE *fp = fopen("data/patients.txt", "r");
    FILE *temp = fopen("data/temp.txt", "w");

    if (!fp || !temp)
    {
        printf(RED "Error opening file!\n" RESET);
        return;
    }

    printf(MAGENTA "\n====== DELETE PATIENT ======\n" RESET);
    printf("Enter Patient ID to delete: ");
    scanf("%d", &deleteID);

    while (fscanf(fp, "%d,%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^\n]\n",
                  &p.id, p.firstName, p.lastName, p.fullName,
                  &p.age, p.gender, p.disease, p.doctorAssigned) != EOF)
    {
        if (p.id == deleteID)
        {
            found = 1;
            toDelete = p;

            printf(GREEN "\nPatient Found!\n" RESET);
            printf(CYAN "-----------------------------\n" RESET);
            printf("ID              : %d\n", toDelete.id);
            printf("Full Name       : %s\n", toDelete.fullName);
            printf("Age             : %d\n", toDelete.age);
            printf("Gender          : %s\n", toDelete.gender);
            printf("Disease         : %s\n", toDelete.disease);
            printf("Doctor Assigned : %s\n", toDelete.doctorAssigned);
            printf(CYAN "-----------------------------\n" RESET);
            break;
        }
    }

    if (!found)
    {
        printf(RED "\nNo patient found with ID %d\n" RESET, deleteID);
        fclose(fp);
        fclose(temp);
        remove("data/temp.txt");
        return;
    }

    char confirm;
    printf(RED "\nAre you sure you want to PERMANENTLY DELETE this patient? (Y/N): " RESET);
    scanf(" %c", &confirm);

    if (!(confirm == 'Y' || confirm == 'y'))
    {
        printf(YELLOW "\nDeletion Cancelled.\n" RESET);
        fclose(fp);
        fclose(temp);
        remove("data/temp.txt");
        return;
    }

    rewind(fp); 

    while (fscanf(fp, "%d,%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^\n]\n",
                  &p.id, p.firstName, p.lastName, p.fullName,
                  &p.age, p.gender, p.disease, p.doctorAssigned) != EOF)
    {
        if (p.id == deleteID)
            continue; 

        fprintf(temp, "%d,%s,%s,%s,%d,%s,%s,%s\n",
                p.id, p.firstName, p.lastName, p.fullName,
                p.age, p.gender, p.disease, p.doctorAssigned);
    }

    fclose(fp);
    fclose(temp);

    remove("data/patients.txt");
    rename("data/temp.txt", "data/patients.txt");

    printf(GREEN "\nRecord Deleted Successfully!\n" RESET);
}