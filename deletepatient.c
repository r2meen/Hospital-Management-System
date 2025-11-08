#include<stdio.h>
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
int main(){
    deletePatient();
    return 0;
}