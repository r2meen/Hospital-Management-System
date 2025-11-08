#include <stdio.h>
void addPatient();
void searchPatient();
void deletePatient();
void updatePatient();
void deletePatient();
void displayPatientByID(int);
int checkDuplicateID(int inputID)
{
    FILE *fp = fopen("patients.txt", "r");
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

    fcloser(fp);
    return 0;
}
struct Patient
{
    int id;
    char firstName[30];
    char lastName[30];
    char fullName[60];
    int age;
    char gender[10];
    char disease[50];
    char doctorAssigned[50];
};
struct Doctor
{
    int id;
    char firstName[30];
    char lastName[30];
    char fullName[60];
    char specialization[50];
    char timings[30];
};
struct Appointment
{
    int patientID;
    int doctorID;
    char date[15];
    char time[10];
};

int main()
{
    return 0;
}

void addPatient()
{
    int inputID;
    struct Patient p;
    FILE *fp = fopen("patients.txt", "a");
    if (!fp)
    {
        printf("Error opening file!\n");
        return;
    }
    do
    {
        printf("Enter Patient's ID: ");
        scanf("%d", &inputID);
        if (checkDuplicateID(inputID))
        {
            printf("Patient ID %d already exists!\nENter a different ID.\n ", inputID);
        }
        else
        {
            p.id = inputID;
            break;
        }
    } while (1);

    printf("Enter Patient's Name:\n");
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
        printf("Enter valid age!\n");
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

    printf("\nNew Patient's Data\n");
    printf("Patient's ID: %d\n", p.id);
    printf("First Name: %s\n", p.firstName);
    printf("Last Name: %s\n", p.lastName);
    printf("Full Name: %s\n", p.fullName);
    printf("Age: %d\n", p.age);
    printf("Gender: %s\n", p.gender);
    printf("Disease: %s\n", p.disease);
    printf("Doctor Assigned: %s\n", p.doctorAssigned);

    char confirm;
    printf("CONFIRM ADD (Y/N): ");
    scanf(" %c", &confirm);
    if (confirm == 'Y' || confirm == 'y')
    {
        fprintf(fp, "%d,%s,%s,%s,%d,%s,%s,%s\n",
                p.id, p.firstName, p.lastName, p.fullName,
                p.age, p.gender, p.disease, p.doctorAssigned);
        printf("Patient added successfully!\n");
    }
    else
        printf("Add cancelled!\n");

    fclose(fp);
}
void searchPatient()
{
    int choice, found = 0, inputId;
    struct Patient p;
    char name[60];
    printf("\n====== SEARCH PATIENT ======\n");
    printf("1. Search by ID\n");
    printf("2. Search by Name\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    FILE *fp = fopen("patients.txt", "r");
    if (!fp)
    {
        printf("Error opening file!\n");
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
                printf("\nPatient Found!\n");
                printf("-----------------------------\n");
                printf("ID              : %d\n", p.id);
                printf("Full Name       : %s\n", p.fullName);
                printf("Age             : %d\n", p.age);
                printf("Gender          : %s\n", p.gender);
                printf("Disease         : %s\n", p.disease);
                printf("Doctor Assigned : %s\n", p.doctorAssigned);
                printf("-----------------------------\n");
                found = 1;
            }
        }
        if (!found)
            printf("No patient found with this name %s\n", name);
    }
    else
        printf("Invalid choice! Please enter 1 or 2.\n");
    fclose(fp);
}

void updatePatient()
{
    int updateID, found = 0, choice;
    struct Patient p;
    FILE *fp = fopen("patients.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!fp || !temp)
    {
        printf("Error opening file!\n");
        return;
    }
    printf("\n====== UPDATE PATIENT ======\n");
    printf("Enter the patient's ID to update: ");
    scanf("%d", &updateID);
    displayPatientByID(updateID);
    while (fscanf(fp, "%d,%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^\n]\n",
                  &p.id, p.firstName, p.lastName, p.fullName,
                  &p.age, p.gender, p.disease, p.doctorAssigned))
    {
        if (p.id == updateID)
        {
            found = 1;
            printf("\nWhich field(s) do you want to update?\n");
            printf("1. Name\n");
            printf("2. Age\n");
            printf("3. Gender\n");
            printf("4. Disease\n");
            printf("5. Doctor Assigned\n");
            printf("6. Cancel\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            getchar();

            switch (choice)
            {
            case 1:
                printf("Enter new First Name: ");
                scanf("%s", p.firstName);
                printf("Enter new Last Name: ");
                scanf("%s", p.lastName);
                int i = 0, j = 0;
                while (p.firstName[i] != '\0')
                    p.fullName[i++] = p.firstName[i];
                p.fullName[i++] = ' ';
                while (p.lastName[j] != '\0')
                    p.fullName[i++] = p.lastName[j++];
                p.fullName[i] = '\0';
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
                scanf("%[^\n]%*c", p.disease);
                break;

            case 5:
                printf("Enter new Doctor Assigned: ");
                scanf("%[^\n]%*c", p.doctorAssigned);
                break;

            case 6:
                printf("Update cancelled for ID %d.\n", p.id);
                break;

            default:
                printf("Invalid choice! No changes made.\n");
                break;
            }

            printf("\n Record Updated Successfully!\n");
        }
        fprintf(temp, "%d,%s,%s,%s,%d,%s,%s,%s\n",
                p.id, p.firstName, p.lastName, p.fullName,
                p.age, p.gender, p.disease, p.doctorAssigned);
    }
    fclose(fp);
    fclose(temp);

    remove("patients.txt");
    rename("temp.txt", "patients.txt");

    if (!found)
        printf("No Patient found with ID %d\n", updateID);
}

void deletePatient()
{
    int id, found = 0;
    struct Patient p;
    FILE *fp, *temp;
    printf("\n====== DELETE PATIENT ======\n");
    printf("Enter the patient ID to delete: ");
    scanf("%d", &id);

    printf("\nDetails of the patient you want to delete:\n");
    displayPatientByID(id);

    char confirm;
    printf("\nAre you sure you want to delete this patient? (y/n): ");
    scanf(" %c", &confirm);

    if (confirm == 'y' && confirm == 'Y')
    {
        printf("Patient record successfully deleted!.\n");
        return;
    }
    else
        printf("Deletion Cancelled!\n");

    fp = fopen("patients.txt", "r");
    if (!fp)
    {
        printf("Error opening file.\n");
        return;
    }
    temp = fopen("temp.txt", "w");
    if (!temp)
    {
        printf("Error creating temporary file!\n");
        fclose(fp);
        return;
    }
    while (fscanf(fp, "%d,%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^\n]\n",
                  &p.id, p.firstName, p.lastName, p.fullName,
                  &p.age, p.gender, p.disease, p.doctorAssigned) != EOF)
    {
        if (p.id == id)
        {
            found = 1;
        }
        else
        {
            fprintf(temp, "%d,%s,%s,%s,%d,%s,%s,%s\n",
                    p.id, p.firstName, p.lastName, p.fullName,
                    p.age, p.gender, p.disease, p.doctorAssigned);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("patients.txt");
    rename("temp.txt", "patients.txt");

    if (!found)
        printf("No patient found with ID %d.\n", id);
}

void displayPatientByID(int id)
{
    struct Patient p;
    FILE *fp = fopen("patients.txt", "r");
    int found = 0;

    if (!fp)
    {
        printf("Error opening file!\n");
        return;
    }

    while (fscanf(fp, "%d,%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^\n]\n",
                  &p.id, p.firstName, p.lastName, p.fullName,
                  &p.age, p.gender, p.disease, p.doctorAssigned) != EOF)
    {
        if (p.id == id)
        {
            printf("\nPatient Found!\n");
            printf("-----------------------------\n");
            printf("ID              : %d\n", p.id);
            printf("Full Name       : %s\n", p.fullName);
            printf("Age             : %d\n", p.age);
            printf("Gender          : %s\n", p.gender);
            printf("Disease         : %s\n", p.disease);
            printf("Doctor Assigned : %s\n", p.doctorAssigned);
            printf("-----------------------------\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("No patient found with ID %d\n", id);

    fclose(fp);
}
