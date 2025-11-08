#include <stdio.h>
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
void addPatient();
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

    fclose(fp);
    return 0;
}


int main() {
    addPatient(); 
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
    do{
    printf("Enter Patient's ID: ");
    scanf("%d", &inputID);
    if(checkDuplicateID(inputID)){
        printf("Patient ID %d already exists!\nEnter a different ID.\n",inputID);
    }
    else{
        p.id=inputID;
        break;
    }
    }while(1);
   

    printf("Enter Patient's Name\n");
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
    if(p.age<0)
    {
    printf("Enter valid age!\n");
    scanf("%d",&p.age);
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
    if (confirm == 'Y' || confirm=='y'){
        fprintf(fp, "%d,%s,%s,%s,%d,%s,%s,%s\n",
                p.id, p.firstName, p.lastName, p.fullName,
                p.age, p.gender, p.disease, p.doctorAssigned);
        printf("Patient added successfully!\n");
    }
    else
        printf("Add cancelled!\n");
    
    fclose(fp);
}
