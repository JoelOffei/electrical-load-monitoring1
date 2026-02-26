# Electrical Load Monitoring System

## Overview

The Electrical Load Monitoring System is a simple C++ console application that helps users track the electricity usage of household appliances.  

It allows users to:

- Register appliances
- View all registered appliances
- Search for an appliance
- Remove an appliance
- Calculate total monthly energy consumption
- Generate a billing summary based on a given tariff

The system also saves data to a file so that appliances remain stored even after the program is closed.

---

## Features

- Input validation for appliance details
- Automatic monthly energy calculation (in kWh)
- File storage using `appliances.txt`
- Billing summary saved to `billing_summary.txt`
- Search and remove functionality
- Menu-driven console interface

---

## How It Works

Each appliance stores:

- Name
- Power rating (Watts)
- Daily usage hours

Monthly energy is calculated using:

```
Monthly Energy (kWh) = (Power × Hours × 30) / 1000
```

The total cost is calculated as:

```
Total Cost = Total Monthly Energy × Tariff
```

---

## Files Used

- `appliances.txt` – stores appliance data
- `billing_summary.txt` – stores the latest billing result

---

## How to Compile and Run

Make sure you have a C++ compiler installed (e.g., g++).

### Compile:
```
g++ main.cpp -o load_monitor
```

### Run:
```
./load_monitor
```

(On Windows, use `load_monitor.exe`)

---

## Menu Options

1. Register Appliance  
2. View All Appliances  
3. Search Appliance  
4. Remove Appliance  
5. Billing Summary  
0. Exit  

---

## Limitations

- Maximum of 50 appliances
- Console-based (no graphical interface)
- Data stored in simple text format

---

## Author

Joel Offei

---

## Notes

This project was developed as a basic demonstration of:
- Object-Oriented Programming (OOP)
- File handling in C++
- Input validation
- Menu-driven program structure