#include <stdio.h>
#include <string.h>
#include "../include/operations.h"
#include "../include/patient.h"
#include "../include/doctor.h"
#include "../include/colors.h"

/* ===========================
   BILLING MODULE
   =========================== */
void generateBill()
{
    char patientName[50], doctorName[50], staffName[50], paymentMethod[10];
    int patientID, days, roomChoice, doctorChoice, testChoice;
    float roomCharge = 0, docFee = 0, testFee = 0;
    float subtotal, tax, discount, total;
    float amountReceived = 0, amountReturned = 0;

    const char *rooms[] = {"General Ward", "Semi-Private Room", "Private Room", "ICU"};
    float roomPrices[] = {2000, 3500, 5000, 10000};

    const char *doctors[] = {"Dr. Smith", "Dr. Johnson", "Dr. Williams", "Dr. Brown"};
    float doctorFees[] = {1500, 2000, 1800, 2200};

    const char *tests[] = {"No Lab Test", "Blood Test", "X-Ray", "MRI", "CT Scan"};
    float testPrices[] = {0, 500, 1000, 5000, 7000};

    printf(MAGENTA "\n====== GENERATE BILL ======\n" RESET);
    printf(YELLOW "Enter Patient ID: " RESET);
    scanf("%d", &patientID);

    printf(YELLOW "Enter Patient Name: " RESET);
    scanf(" %[^\n]", patientName);

    printf(YELLOW "Enter Billing Staff Name: " RESET);
    scanf(" %[^\n]", staffName);

    printf(CYAN "\nSelect Room Type:\n" RESET);
    for (int i = 0; i < 4; i++)
    {
        printf("  %d. %s (%.2f per day)\n", i + 1, rooms[i], roomPrices[i]);
    }
    printf(YELLOW "Enter choice (1-4): " RESET);
    scanf("%d", &roomChoice);
    if (roomChoice < 1 || roomChoice > 4)
    {
        printf(RED "Invalid room choice. Exiting...\n" RESET);
        return;
    }
    roomCharge = roomPrices[roomChoice - 1];

    printf(YELLOW "Enter Number of days stayed: " RESET);
    scanf("%d", &days);
    if (days < 0)
    {
        printf(RED "Invalid number of days. Exiting...\n" RESET);
        return;
    }

    printf(CYAN "\nSelect Doctor:\n" RESET);
    for (int i = 0; i < 4; i++)
    {
        printf("  %d. %s (Fee: %.2f)\n", i + 1, doctors[i], doctorFees[i]);
    }
    printf(YELLOW "Enter choice (1-4): " RESET);
    scanf("%d", &doctorChoice);
    if (doctorChoice < 1 || doctorChoice > 4)
    {
        printf(RED "Invalid doctor choice. Exiting...\n" RESET);
        return;
    }
    docFee = doctorFees[doctorChoice - 1];
    strcpy(doctorName, doctors[doctorChoice - 1]);

    printf(CYAN "\nSelect Lab Test:\n" RESET);
    for (int i = 0; i < 5; i++)
    {
        printf("  %d. %s (Charges: %.2f)\n", i + 1, tests[i], testPrices[i]);
    }
    printf(YELLOW "Enter choice (1-5): " RESET);
    scanf("%d", &testChoice);
    if (testChoice < 1 || testChoice > 5)
    {
        printf(RED "Invalid test choice. Exiting...\n" RESET);
        return;
    }
    testFee = testPrices[testChoice - 1];

    subtotal = (roomCharge * days) + docFee + testFee;
    printf(GREEN "\nSubtotal (before tax and discount): %.2f\n" RESET, subtotal);

    tax = subtotal * 0.05;
    discount = 500;
    if (discount > subtotal)
        discount = subtotal;

    total = subtotal + tax - discount;

    printf(YELLOW "\nEnter Payment Method (C for Cash / K for Card): " RESET);
    scanf(" %[^\n]", paymentMethod);

    if (paymentMethod[0] == 'C' || paymentMethod[0] == 'c')
    {
        printf(YELLOW "Enter Amount Received: " RESET);
        scanf("%f", &amountReceived);

        if (amountReceived < 0)
        {
            printf(RED "\nError: Negative amount received not allowed!\n" RESET);
            return;
        }

        if (amountReceived >= total)
        {
            amountReturned = amountReceived - total;
        }
        else
        {
            printf(RED "\nWarning: Amount received is less than total bill!\n" RESET);
            amountReturned = 0;
        }
    }

    // THE PRINTED BILL
    printf(CYAN "\n-----------------------------------------\n" RESET);
    printf(GREEN "             HOSPITAL BILL\n" RESET);
    printf(CYAN "-----------------------------------------\n" RESET);
    printf(YELLOW "Patient ID: " RESET "%d\n", patientID);
    printf(YELLOW "Patient Name: " RESET "%s\n", patientName);
    printf(YELLOW "Doctor: " RESET "%s\n", doctorName);
    printf(YELLOW "Billing Staff: " RESET "%s\n", staffName);
    printf(CYAN "-----------------------------------------\n" RESET);
    printf("Room Charges (%d days - %s):     %.2f\n", days, rooms[roomChoice - 1], roomCharge * days);
    printf("Consultation Fee:                 %.2f\n", docFee);
    printf("Lab Tests (%s):                  %.2f\n", tests[testChoice - 1], testFee);
    printf(CYAN "-----------------------------------------\n" RESET);
    printf("Subtotal:                       %.2f\n", subtotal);
    printf("Tax (5%%):                       %.2f\n", tax);
    printf("Discount:                       %.2f\n", discount);
    printf(CYAN "-----------------------------------------\n" RESET);
    printf(GREEN "Total Bill:                     %.2f\n" RESET, total);
    printf(CYAN "-----------------------------------------\n" RESET);
    printf("Payment Method: %s\n", paymentMethod);

    if (paymentMethod[0] == 'C' || paymentMethod[0] == 'c')
    {
        printf("Amount Received:                %.2f\n", amountReceived);
        printf("Amount Returned:                %.2f\n", amountReturned);
        printf(GREEN "Payment Status: Paid in Cash\n" RESET);
    }
    else if (paymentMethod[0] == 'K' || paymentMethod[0] == 'k')
    {
        printf(GREEN "Payment Status: Paid by Card\n" RESET);
    }
    else
    {
        printf(RED "Payment Status: Invalid Method Entered\n" RESET);
    }
    printf(CYAN "-----------------------------------------\n" RESET);
}

/* ===========================
   APPOINTMENTS MODULE
   =========================== */
void createAppointment()
{
    struct Appointment app;
    struct Patient p;
    int found = 0;

    printf(MAGENTA "\n====== CREATE APPOINTMENT ======\n" RESET);

    printf(YELLOW "Enter Patient ID: " RESET);
    scanf("%d", &app.patientID);

    FILE *fp = fopen("data/patients.txt", "r");
    if (fp)
    {
        while (fscanf(fp, "%d,%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^\n]\n",
                      &p.id, p.firstName, p.lastName, p.fullName,
                      &p.age, p.gender, p.disease, p.doctorAssigned) != EOF)
        {
            if (p.id == app.patientID)
            {
                found = 1;
                printf(GREEN "Patient Found: %s\n" RESET, p.fullName);
                break;
            }
        }
        fclose(fp);
    }

    if (!found)
    {
        printf(RED "Patient ID not found! Cannot create appointment.\n" RESET);
        return;
    }

    // Read doctors from file
    FILE *dfp = fopen("data/doctors.txt", "r");
    if (!dfp)
    {
        printf(RED "No doctors available in database!\n" RESET);
        return;
    }

    struct Doctor d;
    printf(CYAN "\nAvailable Doctors:\n" RESET);
    while (fscanf(dfp, "%d,%[^,],%[^,],%[^,],%d,%[^\n]\n",
                  &d.id, d.name, d.specialty, d.timings, &d.fee, d.keywords) != EOF)
    {
        printf("%d. %s (%s) - %s\n", d.id, d.name, d.specialty, d.timings);
    }
    rewind(dfp); 

    printf(YELLOW "\nEnter Doctor ID: " RESET);
    scanf("%d", &app.doctorID);

    int doctorFound = 0;
    while (fscanf(dfp, "%d,%[^,],%[^,],%[^,],%d,%[^\n]\n",
                  &d.id, d.name, d.specialty, d.timings, &d.fee, d.keywords) != EOF)
    {
        if (d.id == app.doctorID)
        {
            doctorFound = 1;
            break;
        }
    }
    fclose(dfp);

    if (!doctorFound)
    {
        printf(RED "Invalid Doctor ID!\n" RESET);
        return;
    }

    printf(YELLOW "Enter Appointment Date (DD-MM-YYYY): " RESET);
    scanf(" %[^\n]", app.date);

    printf(YELLOW "Enter Appointment Time (e.g., 10:00 AM): " RESET);
    scanf(" %[^\n]", app.time);

    FILE *appFile = fopen("data/appointments.txt", "a");
    if (!appFile)
    {
        printf(RED "Error opening appointments file!\n" RESET);
        return;
    }

    fprintf(appFile, "%d,%d,%s,%s\n", app.patientID, app.doctorID, app.date, app.time);
    fclose(appFile);

    printf(GREEN "\n--- Appointment Created Successfully! ---\n" RESET);
    printf(YELLOW "Patient: " RESET "%s\n", p.fullName);
    printf(YELLOW "Doctor: " RESET "%s\n", d.name);
    printf(YELLOW "Date: " RESET "%s\n", app.date);
    printf(YELLOW "Time: " RESET "%s\n", app.time);
    printf(YELLOW "Fee: " RESET "Rs. %d\n", d.fee);
}

/* ===========================
   REPORTS MODULE
   =========================== */
void displayReports()
{
    int choice;
    printf(MAGENTA "\n====== DISPLAY REPORTS ======\n" RESET);
    printf("1. All Patients Report\n");
    printf("2. All Doctors Report\n");
    printf("3. All Appointments Report\n");
    printf("4. Patient Count by Disease\n");
    printf(YELLOW "5. Back to Main Menu\n" RESET);
    printf(YELLOW "Enter choice: " RESET);
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
    {
        struct Patient p;
        FILE *fp = fopen("data/patients.txt", "r");
        if (!fp)
        {
            printf(RED "No patient records found!\n" RESET);
            return;
        }

        printf(CYAN "\n========== ALL PATIENTS REPORT ==========\n" RESET);
        printf(YELLOW "%-5s %-25s %-5s %-10s %-20s %-20s\n" RESET, "ID", "Name", "Age", "Gender", "Disease", "Doctor");
        printf(CYAN "------------------------------------------------------------------------\n" RESET);

        int count = 0;
        while (fscanf(fp, "%d,%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^\n]\n",
                      &p.id, p.firstName, p.lastName, p.fullName,
                      &p.age, p.gender, p.disease, p.doctorAssigned) != EOF)
        {
            printf("%-5d %-25s %-5d %-10s %-20s %-20s\n", p.id, p.fullName, p.age, p.gender, p.disease, p.doctorAssigned);
            count++;
        }
        printf(CYAN "------------------------------------------------------------------------\n" RESET);
        printf(GREEN "Total Patients: %d\n" RESET, count);
        fclose(fp);
        break;
    }

    case 2:
    {
        struct Doctor d;
        FILE *dfp = fopen("data/doctors.txt", "r");
        if (!dfp)
        {
            printf(RED "No doctor records found!\n" RESET);
            return;
        }

        printf(CYAN "\n========== ALL DOCTORS REPORT ==========\n" RESET);
        printf(YELLOW "%-5s %-25s %-20s %-15s %-10s\n" RESET, "ID", "Name", "Specialty", "Timings", "Fee");
        printf(CYAN "------------------------------------------------------------------------\n" RESET);

        int docCount = 0;
        while (fscanf(dfp, "%d,%[^,],%[^,],%[^,],%d,%[^\n]\n",
                      &d.id, d.name, d.specialty, d.timings, &d.fee, d.keywords) != EOF)
        {
            printf("%-5d %-25s %-20s %-15s %-10d\n", d.id, d.name, d.specialty, d.timings, d.fee);
            docCount++;
        }
        printf(CYAN "------------------------------------------------------------------------\n" RESET);
        printf(GREEN "Total Doctors: %d\n" RESET, docCount);
        fclose(dfp);
        break;
    }

    case 3:
    {
        struct Appointment app;
        FILE *fp = fopen("data/appointments.txt", "r");
        if (!fp)
        {
            printf(RED "No appointment records found!\n" RESET);
            return;
        }

        printf(CYAN "\n========== ALL APPOINTMENTS REPORT ==========\n" RESET);
        printf(YELLOW "%-12s %-12s %-15s %-15s\n" RESET, "Patient ID", "Doctor ID", "Date", "Time");
        printf(CYAN "--------------------------------------------------------\n" RESET);

        int count = 0;
        while (fscanf(fp, "%d,%d,%[^,],%[^\n]\n",
                      &app.patientID, &app.doctorID, app.date, app.time) != EOF)
        {
            printf("%-12d %-12d %-15s %-15s\n", app.patientID, app.doctorID, app.date, app.time);
            count++;
        }
        printf(CYAN "--------------------------------------------------------\n" RESET);
        printf(GREEN "Total Appointments: %d\n" RESET, count);
        fclose(fp);
        break;
    }

    case 4:
    {
        struct Patient p;
        FILE *fp = fopen("data/patients.txt", "r");
        if (!fp)
        {
            printf(RED "No patient records found!\n" RESET);
            return;
        }

        char diseases[100][50];
        int counts[100] = {0};
        int diseaseCount = 0;

        while (fscanf(fp, "%d,%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^\n]\n",
                      &p.id, p.firstName, p.lastName, p.fullName,
                      &p.age, p.gender, p.disease, p.doctorAssigned) != EOF)
        {
            int found = 0;
            for (int i = 0; i < diseaseCount; i++)
            {
                if (strcmp(diseases[i], p.disease) == 0)
                {
                    counts[i]++;
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                strcpy(diseases[diseaseCount], p.disease);
                counts[diseaseCount] = 1;
                diseaseCount++;
            }
        }

        printf(CYAN "\n========== PATIENT COUNT BY DISEASE ==========\n" RESET);
        printf(YELLOW "%-30s %s\n" RESET, "Disease", "Count");
        printf(CYAN "-------------------------------------------\n" RESET);
        for (int i = 0; i < diseaseCount; i++)
        {
            printf("%-30s %d\n", diseases[i], counts[i]);
        }
        printf(CYAN "-------------------------------------------\n" RESET);
        fclose(fp);
        break;
    }
    case 5:
        return;
    default:
        printf(RED "Invalid choice!\n" RESET);
    }
}