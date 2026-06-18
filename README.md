<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Hospital Management System | Engineering Documentation</title>
    <style>
        body { font-family: 'Segoe UI', Arial, sans-serif; line-height: 1.6; color: #2d3436; max-width: 900px; margin: auto; padding: 30px; background-color: #f8f9fa; }
        header { text-align: center; border-bottom: 3px solid #0984e3; padding-bottom: 20px; margin-bottom: 30px; }
        h1 { color: #2d3436; }
        h2 { color: #0984e3; border-bottom: 1px solid #dfe6e9; padding-bottom: 5px; margin-top: 40px; }
        .diagram-box { background: #2d3436; color: #00ff9f; padding: 20px; border-radius: 8px; font-family: 'Courier New', monospace; overflow-x: auto; margin: 20px 0; border: 1px solid #636e72; }
        table { width: 100%; border-collapse: collapse; margin-top: 15px; }
        th, td { border: 1px solid #dfe6e9; padding: 12px; text-align: left; }
        th { background-color: #f1f2f6; }
        code { background: #e2e8f0; padding: 2px 6px; border-radius: 4px; }
        .feature-grid { display: grid; grid-template-columns: 1fr 1fr; gap: 20px; }
    </style>
</head>
<body>

    <header>
        <h1>🏥 Hospital Management System (HMS)</h1>
        <p><strong>Course:</strong> CS-115 Computer Programming | <strong>Status:</strong> Semester Capstone Project</p>
        <p><em>Enterprise-grade modular console application engineered for efficient hospital data management.</em></p>
    </header>

    <h2>📖 Project Overview</h2>
    <p>The <strong>Hospital Management System</strong> is a professional-grade C application developed to digitize and automate critical hospital operations. The system utilizes a <strong>Modular Design Pattern</strong>, partitioned into functional domains to ensure scalability, data integrity, and clear separation of concerns.</p>

    <h2>🏗️ System Architecture & Workflow</h2>
    
    <h3>1. Architectural Decomposition</h3>
    
    <div class="diagram-box">
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
    </div>

    <h3>2. Operational Workflow</h3>
    
    <div class="diagram-box">
  [USER] ──► [MAIN MENU] ──► [MODULE SELECTION]
                │
                ├─────────► [PATIENT MODULE] ──► [VALIDATION] ──► [DISK STORAGE]
                │
                ├─────────► [DOCTOR MODULE]  ──► [SEARCHING]  ──► [DISK STORAGE]
                │
                └─────────► [OPERATIONS] ──┬──► [APPOINTMENTS] ──► [DISK STORAGE]
                                           └──► [BILLING ENGINE] ──► [REPORT GENERATOR]
    </div>

    <h2>✨ Key Features</h2>
    <div class="feature-grid">
        <div>
            <h3>👤 Records Management</h3>
            <ul>
                <li><strong>CRUD Implementation:</strong> Full support for Patient and Doctor records.</li>
                <li><strong>Search Engine:</strong> Advanced retrieval by ID, Name, Specialty, or Keyword.</li>
                <li><strong>Data Integrity:</strong> Automated ID sequencing and strict input validation.</li>
            </ul>
        </div>
        <div>
            <h3>📅 Operations & Analytics</h3>
            <ul>
                <li><strong>Appointments:</strong> Dynamic scheduling linking patients to doctor profiles.</li>
                <li><strong>Billing:</strong> Automated calculation engine supporting room fees and taxes.</li>
                <li><strong>Reporting:</strong> On-demand summary reports for administrative oversight.</li>
            </ul>
        </div>
    </div>

    <h2>🛠️ Technical Stack</h2>
    <ul>
        <li><strong>Core Language:</strong> C (Standard C99/C11)</li>
        <li><strong>Design Principle:</strong> Modular Functional Decomposition</li>
        <li><strong>Persistence:</strong> CSV-formatted Flat-file Database</li>
        <li><strong>Build System:</strong> GCC Compiler</li>
    </ul>

    <h2>🚀 Getting Started</h2>
    <p>This system is cross-platform and supports Linux, Windows, and macOS.</p>
    <pre style="background:#dfe6e9; padding:15px;"><code>gcc src/main.c src/patient.c src/doctor.c src/operations.c -Iinclude -o hospital_system
./hospital_system</code></pre>

    <h2>👥 Team & Responsibilities</h2>
    <table>
        <tr><th>Member</th><th>Core Responsibilities</th></tr>
        <tr><td>Rameen Zulfi</td><td>Main Menu Orchestration, UI Architecture, Reporting, Chapter 1</td></tr>
        <tr><td>Eifa Siddiqui</td><td>Data Engine, CRUD Logic, Struct Definitions, File I/O, Chapters 2 & 3</td></tr>
        <tr><td>Yusra Batool</td><td>Billing Module, Test Case Implementation, QA/Debugging, Chapters 4 & 5</td></tr>
    </table>

    <h2>🚧 Future Improvements</h2>
    <ul>
        <li><strong>GUI Transition:</strong> Migrating from CLI to a graphical interface.</li>
        <li><strong>Database Migration:</strong> Moving to an ACID-compliant RDBMS (e.g., SQLite).</li>
        <li><strong>Security:</strong> Implementing role-based access control (RBAC).</li>
    </ul>

</body>
</html>