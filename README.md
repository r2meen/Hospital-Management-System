<div align="center">

<!-- Animated header banner -->
<img src="https://capsule-render.vercel.app/api?type=waving&color=0:0a0f1e,50:0d3b6e,100:00c9a7&height=200&section=header&text=Hospital%20Management%20System&fontSize=38&fontColor=ffffff&fontAlignY=38&desc=CS-115%20%C2%B7%20NED%20University%20%C2%B7%20CISE%20Department&descAlignY=58&descSize=16&animation=fadeIn" width="100%"/>

<!-- Typing animation -->
<a href="https://github.com/RameenZulfi">
  <img src="https://readme-typing-svg.demolab.com?font=Space+Mono&size=15&duration=3000&pause=800&color=00C9A7&center=true&vCenter=true&multiline=true&repeat=true&width=600&height=60&lines=Modular+C+Application+for+Healthcare+Operations;Patient+%7C+Doctor+%7C+Appointments+%7C+Billing" alt="Typing animation"/>
</a>

<br/>

<!-- Status badges -->
![Language](https://img.shields.io/badge/Language-C%20%28C99%2FC11%29-00c9a7?style=for-the-badge&logo=c&logoColor=white)
![Build](https://img.shields.io/badge/Build-GCC%20Compiler-3d7fff?style=for-the-badge&logo=gnu&logoColor=white)
![Storage](https://img.shields.io/badge/Storage-Flat--file%20%28.txt%29-ff6b6b?style=for-the-badge&logo=files&logoColor=white)
![Course](https://img.shields.io/badge/Course-CS--115-ffc53d?style=for-the-badge&logo=academia&logoColor=black)
![Status](https://img.shields.io/badge/Status-Completed-27c93f?style=for-the-badge)

</div>

---

## 📖 Overview

The **Hospital Management System (HMS)** is a modular console application written in C, built to digitize and automate critical hospital operations. Designed for small and medium healthcare facilities, it replaces error-prone manual record-keeping with fast, reliable, file-persisted data management.

> Built entirely from scratch for the **CS-115 Computer Programming** course at **NED University of Engineering & Technology (CISE)** under the guidance of **Ms. Hameeza** and **Ms. Mahnoor**.

---

## 🏗️ Architecture

```text
┌─────────────────────────────────────────────────────────────┐
│                    MAIN MENU  (main.c)                      │
│          Orchestrates system flow & UI navigation           │
└────────────────────┬────────────────────────┬───────────────┘
                     │                        │
      ┌──────────────▼───────────┐  ┌─────────▼──────────────┐
      │      DOMAIN MODULES      │  │   UTILITY / DATA LAYER │
      ├──────────────────────────┤  ├────────────────────────┤
      │  👤  Patient Module      │  │  📁  File I/O Engine   │
      │  (CRUD, Search, Validate)│  │  (read/write/update)   │
      ├──────────────────────────┤  ├────────────────────────┤
      │  🩺  Doctor Module       │  │  🛠️  Helper Functions  │
      │  (List, Search, Schedule)│  │  (Validation / Search) │
      ├──────────────────────────┤  └────────────────────────┘
      │  ⚙️  Operations Module   │
      │  (Appointments, Billing) │
      └──────────────────────────┘
```

**Operational flow:**
```
[USER] ──► [MAIN MENU] ──► [MODULE SELECTION]
               │
               ├── [PATIENT MODULE]  ──► [VALIDATION]      ──► [patients.txt]
               ├── [DOCTOR MODULE]   ──► [KEYWORD SEARCH]  ──► [doctors.txt]
               └── [OPERATIONS]  ──┬──► [APPOINTMENTS]     ──► [appointments.txt]
                                   └──► [BILLING ENGINE]   ──► [Bill Report]
```

---

## ✨ Features

### 👤 Patient Management
| Operation | Description |
|-----------|-------------|
| **Add** | Register new patients with auto doctor-assignment based on disease |
| **Update** | Modify any field — name, age, gender, disease, or assigned doctor |
| **Search** | Look up records by ID or partial name match |
| **Delete** | Safe deletion using atomic temp-file replacement |
| **Display** | Tabular view of all patients with full details |

### 🩺 Doctor Management
| Operation | Description |
|-----------|-------------|
| **Add** | Register doctors with specialty, timings, fee, and disease keywords |
| **List by Specialty** | Filter doctors by medical specialty (case-insensitive) |
| **Search by Keyword** | Find doctors matching a disease/organ keyword |
| **Update / Delete** | Modify or remove doctor records with file-safe operations |

### 📅 Appointments
- Book appointments by matching patient disease to available doctors
- List all scheduled appointments
- Cancel by appointment number with instant file update

### 💰 Billing Engine

```
Subtotal  =  (Room Rate × Days)  +  Doctor Fee  +  Lab Test Fee
Tax       =  Subtotal × 5%
Discount  =  500 (fixed)
─────────────────────────────────────────────
Total     =  Subtotal + Tax − Discount
```

Room options: General Ward · Semi-Private · Private · ICU  
Lab tests: Blood Test · X-Ray · MRI · CT Scan  
Payment: Cash (with change calculation) · Card

---

## 🚀 Getting Started

**Requirements:** GCC compiler · Any terminal · Windows / Linux / macOS

```bash
# Clone the repository
git clone https://github.com/RameenZulfi/hospital-management-system.git
cd hospital-management-system

# Compile all source files
gcc src/main.c src/patient.c src/doctor.c src/operations.c -Iinclude -o hospital_system

# Run
./hospital_system          # Linux / macOS
hospital_system.exe        # Windows
```

**Expected output on launch:**
```
========================================
   HOSPITAL MANAGEMENT SYSTEM MAIN MENU
========================================
1. Patients Module
2. Doctors Module
3. Operations Module
4. Exit
========================================
Enter your choice:
```

---

## 🛠️ Tech Stack

<div align="center">

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![GCC](https://img.shields.io/badge/GCC-A42E2B?style=for-the-badge&logo=gnu&logoColor=white)
![VS Code](https://img.shields.io/badge/VS%20Code-007ACC?style=for-the-badge&logo=visual-studio-code&logoColor=white)
![Windows](https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)

</div>

| Layer | Choice | Reason |
|-------|--------|--------|
| Language | C (C99/C11) | Course requirement; teaches fundamentals |
| Build | GCC | Cross-platform, industry-standard |
| Storage | `.txt` flat files | No external dependencies; persistent across sessions |
| IDE | VS Code + Dev-C++ | Familiar toolchain for the team |
| Libraries | `stdio.h` · `string.h` · `ctype.h` | Standard C — no third-party dependencies |

---

## 📁 Project Structure

```
hospital-management-system/
│
├── src/
│   ├── main.c            # Entry point & menu orchestration
│   ├── patient.c         # Patient CRUD & search logic
│   ├── doctor.c          # Doctor management & keyword search
│   └── operations.c      # Appointments + billing engine
│
├── include/
│   ├── patient.h
│   ├── doctor.h
│   └── operations.h
│
├── data/
│   ├── patients.txt      # Persistent patient records
│   ├── doctors.txt       # Persistent doctor records
│   └── appointments.txt  # Persistent appointment log
│
└── README.md
```

---

## 👥 Team

<div align="center">

| <img src="https://img.shields.io/badge/CS--25112-Rameen%20Zulfi-00c9a7?style=for-the-badge"/> | <img src="https://img.shields.io/badge/CS--25111-Eifa%20Siddiqui-3d7fff?style=for-the-badge"/> | <img src="https://img.shields.io/badge/CS--25110-Yusra%20Batool-ff6b6b?style=for-the-badge"/> |
|:---:|:---:|:---:|
| Main Menu · UI Architecture · Module Integration · Chapter 1 | Data Engine · CRUD Logic · Struct Definitions · File I/O · Chapters 2 & 3 | Billing Module · QA & Testing · Debugging · Chapters 4 & 5 |

</div>

---

## 🔭 Roadmap

- [x] Patient CRUD with file persistence
- [x] Doctor management with keyword-based matching
- [x] Appointment scheduling and cancellation
- [x] Automated billing with tax, discount, and payment handling
- [ ] Graphical User Interface (Java / Python Tkinter)
- [ ] SQLite database migration
- [ ] Role-based login system (Admin · Doctor · Billing Staff)
- [ ] Appointment conflict detection
- [ ] Dynamic linked-list record management

---

## 📄 References

1. **Aga Khan University Hospital** — Doctor search UX inspired the keyword-based specialty matching system
2. **Deitel & Deitel** — *C How to Program* — Core reference for structures, file handling, and modular design

---

<div align="center">

*Developed for CS-115 Computer Programming · NED University of Engineering & Technology · Fall 2025*

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:00c9a7,50:0d3b6e,100:0a0f1e&height=120&section=footer" width="100%"/>

</div>
