#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_DOCTORS 50

struct Doctor {
    int id;
    char name[50];
    char specialty[30];
    char timings[30];
    int fee;
    char keywords[200];     // diseases/organs treated
};

struct Doctor doctors[MAX_DOCTORS];
int doctorCount = 0;

// ---------------------- ADD DOCTOR -------------------------
void addDoctor() {
    if (doctorCount >= MAX_DOCTORS) {
        printf("Doctor limit reached!\n");
        return;
    }

    struct Doctor d;
    d.id = doctorCount + 1;

    printf("\nEnter Doctor Name: ");
    scanf(" %[^\n]", d.name);

    printf("Enter Specialty: ");
    scanf(" %[^\n]", d.specialty);

    printf("Enter Timings (e.g. 9AM-2PM): ");
    scanf(" %[^\n]", d.timings);

    printf("Enter Fee: ");
    scanf("%d", &d.fee);

    printf("Enter keywords (heart, chest pain, etc): ");
    scanf(" %[^\n]", d.keywords);

    doctors[doctorCount] = d;
    doctorCount++;

    printf("\nDoctor added successfully!\n");
}

// ---------------------- LIST ALL DOCTORS -------------------------
void listAllDoctors() {
    if (doctorCount == 0) {
        printf("No doctors found.\n");
        return;
    }

    printf("\n--- List of Doctors ---\n");
    for (int i = 0; i < doctorCount; i++) {
        printf("%d. %s (%s)\n", doctors[i].id, doctors[i].name, doctors[i].specialty);
    }
}

// ---------------------- SHOW DOCTOR DETAILS -------------------------
void showDoctorDetails(int id) {
    if (id < 1 || id > doctorCount) {
        printf("Invalid Doctor ID.\n");
        return;
    }

    struct Doctor d = doctors[id - 1];

    printf("\n--- Doctor Details ---\n");
    printf("ID: %d\n", d.id);
    printf("Name: %s\n", d.name);
    printf("Specialty: %s\n", d.specialty);
    printf("Timings: %s\n", d.timings);
    printf("Fee: %d\n", d.fee);
    printf("Keywords: %s\n", d.keywords);
}

// ---------------------- LIST DOCTORS BY SPECIALTY -------------------------
void listDoctorsBySpecialty() {
    char spec[30];
    int found = 0;

    printf("\nEnter Specialty to Search: ");
    scanf(" %[^\n]", spec);

    printf("\nDoctors in %s:\n", spec);

    for (int i = 0; i < doctorCount; i++) {
        if (strcasecmp(doctors[i].specialty, spec) == 0) {
            printf("%d. %s\n", doctors[i].id, doctors[i].name);
            found = 1;
        }
    }

    if (!found) {
        printf("No doctors found for this specialty.\n");
    }
}

// ---------------------- SEARCH BY KEYWORD -------------------------
int containsIgnoreCase(char *str, char *word) {
    char tempStr[200], tempWord[50];

    // Convert both strings to lowercase
    for (int i = 0; str[i]; i++) tempStr[i] = tolower(str[i]);
    tempStr[strlen(str)] = '\0';

    for (int i = 0; word[i]; i++) tempWord[i] = tolower(word[i]);
    tempWord[strlen(word)] = '\0';

    return strstr(tempStr, tempWord) != NULL;
}

void searchDoctorByKeyword() {
    char key[50];
    int found = 0;

    printf("\nEnter disease/organ keyword: ");
    scanf(" %[^\n]", key);

    printf("\nDoctors matching '%s':\n", key);

    for (int i = 0; i < doctorCount; i++) {
        if (containsIgnoreCase(doctors[i].keywords, key)) {
            printf("%d. %s (%s)\n", doctors[i].id, doctors[i].name, doctors[i].specialty);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching doctors found.\n");
    }
}

// ---------------------- MAIN MENU -------------------------
int main() {
    int choice, id;

    while (1) {
        printf("\n--- Doctor Management Menu ---\n");
        printf("1. Add Doctor\n");
        printf("2. List All Doctors\n");
        printf("3. Show Doctor Details\n");
        printf("4. List Doctors by Specialty\n");
        printf("5. Search Doctor by Keyword\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addDoctor(); break;
            case 2: listAllDoctors(); break;
            case 3:
                printf("Enter Doctor ID: ");
                scanf("%d", &id);
                showDoctorDetails(id);
                break;
            case 4: listDoctorsBySpecialty(); break;
            case 5: searchDoctorByKeyword(); break;
            case 6: return 0;
            default: printf("\nInvalid choice!\n");
        }
    }

    return 0;
}
