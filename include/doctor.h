#ifndef DOCTOR_H
#define DOCTOR_H

#include <stdio.h>
#include <stdlib.h>
#include "../include/patient.h"
#include "../include/doctor.h"
#include "../include/operations.h"

struct Doctor
{
    int id;
    char name[50];
    char specialty[30];
    char timings[30];
    int fee;
    char keywords[200]; // diseases/organs treated
};

// Core Function Prototypes
void addDoctor();
void searchDoctor();
void listAllDoctors();
void showDoctorDetails(int id);
void listDoctorsBySpecialty();
void searchDoctorByKeyword();

#endif