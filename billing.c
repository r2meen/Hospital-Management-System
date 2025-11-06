#include <stdio.h>
#include <string.h>

void generateBill();

int main() {
    printf("       Billing Section\n\n");
    generateBill();
    return 0;
}

void generateBill() {
    char patientName[50], doctorName[50], staffName[50], paymentMethod[10];
    int patientID, days;
    float roomCharge, docFee, testFee, medicineFee;
    float subtotal, tax, discount, total;
    float amountReceived = 0, amountReturned = 0;

    printf("Enter Patient ID: ");
    scanf("%d", &patientID);

    printf("Enter Patient Name: ");
    scanf(" %[^\n]", patientName);

    printf("Enter Doctor Name: ");
    scanf(" %[^\n]", doctorName);

    printf("Enter Billing Staff Name: ");
    scanf(" %[^\n]", staffName);

    printf("Enter Room Charges per day: ");
    scanf("%f", &roomCharge);

    printf("Enter Number of days stayed: ");
    scanf("%d", &days);

    printf("Enter Doctor Consultation Fee: ");
    scanf("%f", &docFee);

    printf("Enter Lab Test Charges: ");
    scanf("%f", &testFee);

    printf("Enter Medicine Charges: ");
    scanf("%f", &medicineFee);
    if (roomCharge < 0 || days < 0 || docFee < 0 || testFee < 0 || medicineFee < 0) {
        printf("\nError: Negative values are not allowed!\n");
        return;}
    subtotal = (roomCharge * days) + docFee + testFee + medicineFee;
    tax = subtotal * 0.05;  
    discount = 500;          
    if (discount > subtotal)
        discount = subtotal;

    total = subtotal + tax - discount;
    printf("Enter Payment Method (C FOR CASH)/(K FOR CARD):");
    scanf(" %[^\n]", paymentMethod);

    if (paymentMethod[0] == 'C' || paymentMethod[0] == 'c') {
        printf("Enter Amount Received: ");
        scanf("%f", &amountReceived);

        if (amountReceived < 0) {
            printf("\nError: Negative amount received not allowed!\n");
            return;
        }

        if (amountReceived >= total) {
            amountReturned = amountReceived - total;
        } else {
            printf("\nWarning: Amount received is less than total bill!\n");
            amountReturned = 0;
        }
    }
    printf("\n-----------------------------------------\n");
    printf("             HOSPITAL BILL\n");
    printf("-----------------------------------------\n");
    printf("Patient ID: %d\n", patientID);
    printf("Patient Name: %s\n", patientName);
    printf("Doctor: %s\n", doctorName);
    printf("Billing Staff: %s\n", staffName);
    printf("-----------------------------------------\n");
    printf("Room Charges (%d days):     %.2f\n", days, roomCharge * days);
    printf("Consultation Fee:           %.2f\n", docFee);
    printf("Lab Tests:                  %.2f\n", testFee);
    printf("Medicines:                  %.2f\n", medicineFee);
    printf("-----------------------------------------\n");
    printf("Subtotal:                   %.2f\n", subtotal);
    printf("Tax (5%%):                   %.2f\n", tax);
    printf("Discount:                   %.2f\n", discount);
    printf("-----------------------------------------\n");
    printf("Total Bill:                 %.2f\n", total);
    printf("-----------------------------------------\n");
    printf("Payment Method: %s\n", paymentMethod);

    if (paymentMethod[0] == 'C' || paymentMethod[0] == 'c') {
        printf("Amount Received:            %.2f\n", amountReceived);
        printf("Amount Returned:            %.2f\n", amountReturned);
        printf("Payment Status: Paid in Cash\n");
    } 

    else if (paymentMethod[0] == 'K' || paymentMethod[0] == 'k') {
        printf("Payment Status: Paid by Card\n");
    } 

    else {
        printf("Payment Status: Invalid Method Entered\n");
    }

    printf("-----------------------------------------\n");
    printf("Thank you for choosing our hospital!\n");
    printf("-----------------------------------------\n");
}



