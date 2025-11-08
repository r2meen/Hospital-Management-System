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

void updatePatient()
{
    int updateID,found=0,choice;
    struct Patient p;
    FILE *fp = fopen("patients.txt", "r");
    FILE *temp=fopen("temp.txt","w");

    if (!fp || !temp)
    {
        printf("Error opening file!\n");
        return;
    }
    printf("\n====== UPDATE PATIENT ======\n");
    printf("Enter the patient's ID to update: ");
    scanf("%d",&updateID);
    displayPatientByID(updateID);
    while(fscanf(fp, "%d,%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^\n]\n",
        &p.id, p.firstName, p.lastName, p.fullName,
        &p.age, p.gender, p.disease, p.doctorAssigned)!=EOF)
{
    if(p.id==updateID){
        found=1;
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

            switch(choice){
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
int confirm;
            printf("\nAre you sure you want to save changes? (Y/N): ");
            scanf(" %c", &confirm);

            if (confirm == 'Y' || confirm == 'y')
            {
                printf("\nRecord Updated Successfully!\n");
            }
            else
            {
                printf("\nUpdate Cancelled. Keeping old data.\n");
            }
        }
       

        fprintf(temp, "%d,%s,%s,%s,%d,%s,%s,%s\n",
                p.id, p.firstName, p.lastName, p.fullName,
                p.age, p.gender, p.disease, p.doctorAssigned);
}
fclose(fp);
fclose(temp);

remove("patients.txt");
rename("temp.txt","patients.txt");

if(!found)
printf("No Patient found with ID %d\n",updateID);
}

int main(){
    updatePatient();
    return 0;
}