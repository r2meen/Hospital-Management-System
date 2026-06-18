#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>
#include "../include/doctor.h"
#include "../include/colors.h"

/* ===========================
   UTILITY FUNCTIONS
   =========================== */
int containsIgnoreCase(char *str, char *word)
{
    char tempStr[200], tempWord[50];

    for (int i = 0; str[i]; i++)
        tempStr[i] = tolower(str[i]);
    tempStr[strlen(str)] = '\0';

    for (int i = 0; word[i]; i++)
        tempWord[i] = tolower(word[i]);
    tempWord[strlen(word)] = '\0';

    return strstr(tempStr, tempWord) != NULL;
}

// Automatically calculates the next available ID based on the file
int getNewDoctorID()
{
    FILE *fp = fopen("data/doctors.txt", "r");
    if (!fp)
        return 1; // If file doesn't exist, start at ID 1

    int maxID = 0;
    struct Doctor d;

    // Scan through all records to find the highest ID
    while (fscanf(fp, "%d,%[^,],%[^,],%[^,],%d,%[^\n]\n",
                  &d.id, d.name, d.specialty, d.timings, &d.fee, d.keywords) != EOF)
    {
        if (d.id > maxID)
        {
            maxID = d.id;
        }
    }
    fclose(fp);
    return maxID + 1;
}

/* ===========================
   CORE FUNCTIONS
   =========================== */
void addDoctor()
{
    struct Doctor d;
    d.id = getNewDoctorID(); // Auto-assign ID

    // FIXED PATH
    FILE *fp = fopen("data/doctors.txt", "a");
    if (!fp)
    {
        printf(RED "Error opening doctors database!\n" RESET);
        return;
    }

    printf(BLUE "\n--- Adding New Doctor ---\n" RESET);
    printf(YELLOW "Assigned Doctor ID: " RESET "%d\n", d.id);

    printf(YELLOW "Enter Doctor Name: " RESET);
    scanf(" %[^\n]", d.name);

    printf(YELLOW "Enter Specialty: " RESET);
    scanf(" %[^\n]", d.specialty);

    printf(YELLOW "Enter Timings (e.g. 9AM-2PM): " RESET);
    scanf(" %[^\n]", d.timings);

    printf(YELLOW "Enter Fee: " RESET);
    scanf("%d", &d.fee);

    printf(YELLOW "Enter keywords (heart, chest pain, etc): " RESET);
    scanf(" %[^\n]", d.keywords);

    // Write to file separated by commas
    fprintf(fp, "%d,%s,%s,%s,%d,%s\n",
            d.id, d.name, d.specialty, d.timings, d.fee, d.keywords);

    fclose(fp);
    printf(GREEN "\nDoctor added successfully to database!\n" RESET);
}

void listAllDoctors()
{
    // FIXED PATH
    FILE *fp = fopen("data/doctors.txt", "r");
    if (!fp)
    {
        printf(RED "\nNo doctors found or database missing.\n" RESET);
        return;
    }

    struct Doctor d;
    int found = 0;

    printf(BLUE "\n--- List of Doctors ---\n" RESET);
    while (fscanf(fp, "%d,%[^,],%[^,],%[^,],%d,%[^\n]\n",
                  &d.id, d.name, d.specialty, d.timings, &d.fee, d.keywords) != EOF)
    {
        printf(CYAN "%d. " RESET "%s (" YELLOW "%s" RESET ")\n", d.id, d.name, d.specialty);
        found = 1;
    }
    fclose(fp);

    if (!found)
    {
        printf(RED "No doctors are currently registered.\n" RESET);
    }
}

void showDoctorDetails(int id)
{
    // FIXED PATH
    FILE *fp = fopen("data/doctors.txt", "r");
    if (!fp)
    {
        printf(RED "\nDatabase error!\n" RESET);
        return;
    }

    struct Doctor d;
    int found = 0;

    while (fscanf(fp, "%d,%[^,],%[^,],%[^,],%d,%[^\n]\n",
                  &d.id, d.name, d.specialty, d.timings, &d.fee, d.keywords) != EOF)
    {
        if (d.id == id)
        {
            printf(BLUE "\n--- Doctor Details ---\n" RESET);
            printf(YELLOW "ID: " RESET "%d\n", d.id);
            printf(YELLOW "Name: " RESET "%s\n", d.name);
            printf(YELLOW "Specialty: " RESET "%s\n", d.specialty);
            printf(YELLOW "Timings: " RESET "%s\n", d.timings);
            printf(YELLOW "Fee: " RESET "Rs. %d\n", d.fee);
            printf(YELLOW "Keywords: " RESET "%s\n", d.keywords);
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found)
        printf(RED "Invalid Doctor ID. No doctor found.\n" RESET);
}

void listDoctorsBySpecialty()
{
    // FIXED PATH
    FILE *fp = fopen("data/doctors.txt", "r");
    if (!fp)
    {
        printf(RED "\nDatabase error!\n" RESET);
        return;
    }

    struct Doctor d;
    char spec[30];
    int found = 0;

    printf(YELLOW "\nEnter Specialty to Search: " RESET);
    scanf(" %[^\n]", spec);

    printf(BLUE "\nDoctors in %s:\n" RESET, spec);

    while (fscanf(fp, "%d,%[^,],%[^,],%[^,],%d,%[^\n]\n",
                  &d.id, d.name, d.specialty, d.timings, &d.fee, d.keywords) != EOF)
    {
        if (strcasecmp(d.specialty, spec) == 0)
        {
            printf(GREEN "%d. %s\n" RESET, d.id, d.name);
            found = 1;
        }
    }
    fclose(fp);

    if (!found)
        printf(RED "No doctors found for this specialty.\n" RESET);
}

void searchDoctorByKeyword()
{
    // FIXED PATH
    FILE *fp = fopen("data/doctors.txt", "r");
    if (!fp)
    {
        printf(RED "\nDatabase error!\n" RESET);
        return;
    }

    struct Doctor d;
    char key[50];
    int found = 0;

    printf(YELLOW "\nEnter disease/organ keyword: " RESET);
    scanf(" %[^\n]", key);

    printf(BLUE "\nDoctors matching '%s':\n" RESET, key);

    while (fscanf(fp, "%d,%[^,],%[^,],%[^,],%d,%[^\n]\n",
                  &d.id, d.name, d.specialty, d.timings, &d.fee, d.keywords) != EOF)
    {
        if (containsIgnoreCase(d.keywords, key))
        {
            printf(GREEN "%d. %s " RESET "(" YELLOW "%s" RESET ")\n", d.id, d.name, d.specialty);
            found = 1;
        }
    }
    fclose(fp);

    if (!found)
        printf(RED "No matching doctors found.\n" RESET);
}

/* ===========================
   DOCTOR SUB-MENU
   =========================== */
void searchDoctor()
{
    int choice;

    printf(BLUE "\n====== SEARCH DOCTOR ======\n" RESET);
    printf("1. List All Doctors\n");
    printf("2. Show Doctor Details by ID\n");
    printf("3. List Doctors by Specialty\n");
    printf("4. Search Doctor by Keyword\n");
    printf(YELLOW "5. Back to Main Menu\n" RESET);
    printf(YELLOW "Enter choice: " RESET);
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        listAllDoctors();
        break;
    case 2:
    {
        int id;
        printf(YELLOW "Enter Doctor ID: " RESET);
        scanf("%d", &id);
        showDoctorDetails(id);
        break;
    }
    case 3:
        listDoctorsBySpecialty();
        break;
    case 4:
        searchDoctorByKeyword();
        break;
    case 5:
        return;
    default:
        printf(RED "Invalid choice!\n" RESET);
    }
}