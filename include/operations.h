#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include "../include/patient.h"
#include "../include/doctor.h"
#include "../include/operations.h"

struct Appointment
{
    int patientID;
    int doctorID;
    char date[15];
    char time[10];
};

void createAppointment();
void generateBill();
void displayReports();

#endif