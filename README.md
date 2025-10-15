# 🏫 School Management System

## 🎯 Introduction
The **School Management System** is an object-oriented C++ project designed to simulate a school environment.  
It demonstrates strong understanding of **inheritance, polymorphism, encapsulation, and abstraction** in C++.

This project manages **students, teachers, tutors, managers, and administrative staff**, while maintaining a structured hierarchy between them.  
The system also showcases the use of **vectors, templates, static members**, and **Singleton design pattern**.

---

## 🧩 Project Overview

The system allows the school administration to:
- Add and manage **students (pupils)**, **teachers**, **tutors**, **managers**, **secretaries**, and **administrative staff**.
- Organize the school into **classes** and **layers**.
- Display and analyze **outstanding people** and **top-performing employees**.
- Maintain **salary calculations** and **academic statistics**.
- Use a **menu-driven interface** to perform all operations.

---

## 🏗️ Object-Oriented Design

### 🧍 1. `Person`
**Base class** representing any person in the school.  
Includes personal details such as first name and surname.

**Key methods:**
- `printDetails()`
- `isOutstanding()`

---

### 🎓 2. `Pupil`
Derived from `Person`. Represents a student.

**Data:**
- Grades for all subjects  
- Grade level (`'a'`–`'f'`)  
- Class number (`1–3`)

**Logic:**
- `averageGrade()` returns the mean of all grades.  
- `isOutstanding()` returns `true` if GPA > 85 and all grades ≥ 65.

---

### 🧑‍🏫 3. `Worker`
Abstract class derived from `Person`. Represents any paid employee.

**Data:**
- Years of seniority  
- Static base pay (25)

**Logic:**
- `monthlySalary()` (virtual)  
- `printDetails()`

---

### 📘 4. `Teacher`
Derived from `Worker`.

**Data:**
- List of subjects taught  
- Number of subjects

**Logic:**
- `monthlySalary()` computed per given formula.  
- `isOutstanding()` if teaching 5+ subjects.  
- `printSubjects()` lists all subjects.

---

### 🧑‍🏫 5. `Tutor`
Derived from `Teacher`.

**Description:**
Represents a teacher who also educates a class.

**Logic:**
- `monthlySalary()` = teacher salary + 1000 NIS  
- `isOutstanding()` if at least 50% of class pupils are outstanding.

---

### 🗂️ 6. `AdministrationPersonal`
Derived from `Worker`.

**Data:**
- Office location

**Logic:**
- `monthlySalary()` calculated differently from a teacher.  
- `isOutstanding()` based on performance.  

---

### 👔 7. `Manager`
Derived from `Teacher`. Implements **Singleton Pattern**.

**Logic:**
- Private constructor and static pointer to itself.  
- `getInstance()` returns the single instance.  
- `monthlySalary()` includes managerial bonus.  
- `isOutstanding()` if seniority > 3 years.

---

### 👩‍💼 8. `Secretary`
Derived from `Worker`.

**Data:**
- Number of children attending the school.

**Logic:**
- Salary depends on number of children.  
- `isOutstanding()` if seniority > 10 years.

---

### 🏫 9. `Class`
Represents a single class of pupils.

**Data:**
- Grade level and number  
- Array of pupil pointers  
- Tutor pointer

**Methods:**
- `addStudent(Pupil*)`  
- `getStudent(int index)`

---

### 📚 10. `Layer`
Represents a full grade (e.g., Grade A, Grade B).

**Data:**
- Grade level (`'a'`–`'f'`)  
- Up to 3 class pointers

---

### 🏛️ 11. `School`
Implements the **Singleton** pattern. Central management of all layers, students, and employees.

**Data:**
- Vector of pupils  
- Vector of employees  
- Array of layer pointers  

**Method:**
- `menu()` provides all management operations:
  - Add/Print Pupils  
  - Add/Print Teachers  
  - Add/Print Tutors  
  - Add/Print Manager  
  - Add/Print Secretary  
  - Display Outstanding People  
  - Display Class Details  
  - Display Worker with Highest Salary  
  - Exit and clean memory  

---

### 🔢 12. Template Class `<T> VecAnalyser`
Generic class for analyzing vectors of pointers to pupils or employees.

**Methods:**
- `getElement(int index)`  
- `swap(int index1, int index2)`  
- `printElement(int index)`  
- `printAll()`  
- `printMax()` → prints element with highest salary or GPA  
- `isManager(int index)`

---

## 🖥️ Program Flow

1. The program starts from **`assignment3.cpp`**.  
2. The **School** singleton instance is created.  
3. The **menu** allows the user to perform actions (add, display, calculate, etc.).  
4. Input is validated and objects are dynamically allocated.  
5. Memory is released properly on exit.

---

## ⚙️ Compilation and Execution

### 🧱 Using Makefile
```bash
make
```

### ▶️ Run
```bash
./assignment3
```

### 🧹 Clean
```bash
make clean
```

---

## 🧠 Object-Oriented Concepts Used
- **Inheritance**
- **Polymorphism**
- **Encapsulation**
- **Templates**
- **Static members**
- **Singleton design pattern**
- **Dynamic allocation & pointers**
- **Vectors over arrays**

---

## 📁 Project Structure

```
School-Management-System-main/
├── AdministrationPersonal.cpp / .h
├── Class.cpp / .h
├── Layer.cpp / .h
├── Manager.cpp / .h
├── Person.cpp / .h
├── Pupil.cpp / .h
├── School.cpp / .h
├── Secretary.cpp / .h
├── Teacher.cpp / .h
├── Tutor.cpp / .h
├── VecAnalyser.cpp / .h
├── Worker.cpp / .h
├── main.cpp  ← Main program
└── makefile
```


