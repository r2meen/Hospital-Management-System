#ifndef PATIENT_H
#define PATIENT_H

#include <stdio.h>
#include <stdlib.h>
#include "../include/patient.h"
#include "../include/doctor.h"
#include "../include/operations.h"

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

// Function Prototypes
int checkDuplicateID(int inputID);
void displayPatientByID(int id);
void addPatient();
void searchPatient();
void updatePatient();
void deletePatient();

#endif