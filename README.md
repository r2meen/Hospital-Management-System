# 🏥 Hospital Management System (HMS)

> **Enterprise-grade modular console application** engineered for efficient hospital data management.

---

## 📖 Project Overview

The **Hospital Management System** is a professional-grade C application developed to digitize and automate critical hospital operations. The system utilizes a **Modular Design Pattern**, partitioned into functional domains to ensure scalability, data integrity, and clear separation of concerns.

---

## 🏗️ System Architecture & Workflow

### 1. Architectural Decomposition

```text
       ┌────────────────────────────────────────────────────────┐
       │                MAIN MENU (main.c)                      │
       │     (Orchestrates system flow & UI navigation)         │
       └──────────────┬────────────────────────────┬────────────┘
                      │                            │
      ┌───────────────┴────────────┐    ┌──────────┴─────────────┐
      │     DOMAIN MODULES         │    │  UTILITY / DATA LAYER  │
      ├────────────────────────────┤    ├────────────────────────┤
      │ 👤 Patient Module          │    │ 📁 File I/O Engine     │
      │ (CRUD, Search, Validate)   │    │ (read, write, update)  │
      ├────────────────────────────┤    ├────────────────────────┤
      │ 👨‍⚕️ Doctor Module         │    │ 🎨 UI Color Themes     │
      │ (List, Search, Schedule)   │    │ (ANSI Escape Codes)    │
      ├────────────────────────────┤    ├────────────────────────┤
      │ ⚙️ Operations Module       │    │ 🛠️ Helper Functions    │
      │ (Appointments, Billing)    │    │ (Validation/Search)    │
      └────────────────────────────┘    └────────────────────────┘

```

### 2. Operational Workflow

```text
  [USER] ──► [MAIN MENU] ──► [MODULE SELECTION]
                │
                ├─────────► [PATIENT MODULE] ──► [VALIDATION] ──► [DISK STORAGE]
                │
                ├─────────► [DOCTOR MODULE]  ──► [SEARCHING]  ──► [DISK STORAGE]
                │
                └─────────► [OPERATIONS] ──┬──► [APPOINTMENTS] ──► [DISK STORAGE]
                                           └──► [BILLING ENGINE] ──► [REPORT GENERATOR]

```

---

## ✨ Key Features

### 👤 Records Management

* **CRUD Implementation:** Full support for Patient and Doctor records.
* **Search Engine:** Advanced retrieval by ID, Name, Specialty, or Keyword.
* **Data Integrity:** Automated ID sequencing and strict input validation.

### 📅 Operations & Analytics

* **Appointments:** Dynamic scheduling linking patients to doctor profiles.
* **Billing:** Automated calculation engine supporting room fees and taxes.
* **Reporting:** On-demand summary reports for administrative oversight.

---

## 🛠️ Technical Stack

* **Core Language:** C (Standard C99/C11)
* **Design Principle:** Modular Functional Decomposition
* **Persistence:** CSV-formatted Flat-file Database
* **Build System:** GCC Compiler

---

## 🚀 Getting Started

This system is cross-platform and supports Linux, Windows, and macOS.

```bash
# Compile using GCC
gcc src/main.c src/patient.c src/doctor.c src/operations.c -Iinclude -o hospital_system

# Launch the application
./hospital_system

```

---

## 👥 Team & Responsibilities

| Member | Core Responsibilities |
| --- | --- |
| **Rameen Zulfi** | Main Menu Orchestration, UI Architecture, Reporting, Chapter 1 |
| **Eifa Siddiqui** | Data Engine, CRUD Logic, Struct Definitions, File I/O, Chapters 2 & 3 |
| **Yusra Batool** | Billing Module, Test Case Implementation, QA/Debugging, Chapters 4 & 5 |

---

## 🚧 Future Improvements

* **GUI Transition:** Migrating from CLI to a graphical interface.
* **Database Migration:** Moving to an ACID-compliant RDBMS (e.g., SQLite).
* **Security:** Implementing role-based access control (RBAC).

---

## 📄 License

This project was developed for academic purposes under the **CS-115 Computer Programming** course. All rights reserved by the development team.
