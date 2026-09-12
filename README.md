# BattDesign ⚡

A lightweight, C-based sizing engine designed to calculate series ($S$) and parallel ($P$) cell configurations for custom battery packs based on target energy and nominal system voltage.

---

## 📌 Features

* **Series Stacking ($S$) Calculation:** Computes required series cell count to hit target pack voltage.
* **Parallel Stacking ($P$) Calculation:** Converts energy requirements ($\text{kWh} \to \text{Wh}$) to determine parallel string capacity.
* **Pass-by-Pointer Architecture:** Uses struct pointers (`BatteryCell*`, `BatteryPack*`) to optimize memory usage for low-level embedded environments.
* **Zero External Dependencies:** Built using standard C (`C99`/`C11`) and standard math libraries.

---

## 📂 Source Code Structure

The core engine relies on two foundational data structures and calculation routines:

```c
// Cell Configuration Model
typedef struct {
    float nominalVoltage;  // Individual cell nominal voltage (V)
    int   cellCapacity;    // Individual cell capacity (Ah)
} BatteryCell;

// Target Pack Requirements
typedef struct {
    int packEnergy;          // Desired total pack energy (kWh)
    int packNominalVoltage;  // Desired pack nominal voltage (V)
} BatteryPack;

```

---

## ⚙️ Mathematical Model


1. **Series Connections ($S$):**

$$
S = \frac{V_{\text{pack\_nominal}}}{V_{\text{cell\_nominal}}}
$$

2. **Parallel Connections ($P$):**

$$
E_{\text{Wh}} = E_{\text{kWh}} \times 1000
$$

$$
P = \frac{\left(\frac{E_{\text{Wh}}}{V_{\text{pack\_nominal}}}\right)}{C_{\text{cell\_capacity}}}
$$



---

## 🛠️ Build & Run

### Prerequisites

* GCC, Clang, or any standard C compiler.

### Compilation

```bash
# Clone repository
git clone https://github.com/YOUR_USERNAME/BattDesign.git
cd BattDesign

# Compile using GCC
gcc -Wall -Wextra main.c -o BattDesign -lm

# Run the program
./BattDesign

```

---

## 🖥️ Example Terminal Output

```text
--- Battery Cell Configuration ---
Cell Nominal Voltage(V): 3.6
Cell Capacity(Ah): 10

--- Battery Pack Configuration ---
Battery Pack Energy(kWh): 10
Pack Nominal Voltage(V): 350

packEnergy: 10000.00 Wh
(packEnergy / packNominal) is 28.57

seriesConnections: 97.22
parallelConnections: 2.86

```

---
