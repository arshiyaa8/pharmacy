# Pharmacy Management System 💊

A simple **C-based Pharmacy Management System** that acts as a smart healthcare assistant — helping users identify a disease by symptom, get medicine recommendations, and find shop and dosage details, all backed by a flat-file database.

> ⚠️ **Note:** This is an educational project. It is not a substitute for professional medical advice — always consult a doctor for real treatment.

---

## ✨ Features

- 🔍 **Symptom Search** — Enter a symptom and get the matching medicine, recommended dosage, pharmacy shop, and address
- 📋 **View All Records** — Display every disease/medicine record currently stored
- ➕ **Add New Record** — Add new symptom-medicine entries directly from the menu
- 🕓 **Search History** — Automatically logs each user's searches to `user_history.txt`
- 🔡 **Case-Insensitive Matching** — Symptom search works regardless of letter casing

---

## 🛠️ Built With

- **Language:** C
- **Concepts used:** Structures, File Handling, Functions, String Manipulation

---

## 📂 Project Structure

| File | Purpose |
|---|---|
| `pharmacy.c` | Main source code — menu system, search, add, and display logic |
| `pharmacy_data.txt` | Flat-file database storing disease/medicine records |

Each record is stored as: `symptom medicine shop dosage address`

---

## 🚀 Getting Started

### Prerequisites
- A C compiler (e.g. GCC)

### Compile & Run
```bash
git clone https://github.com/arshiyaa8/pharmacy.git
cd pharmacy

# Compile
gcc pharmacy.c -o pharmacy

# Run
./pharmacy
```

On first run, make sure `pharmacy_data.txt` exists in the same folder (the program will prompt you if it's missing).

### Usage
1. Enter your name when prompted.
2. Choose an option from the menu:
   - `1` — Show all records
   - `2` — Search by symptom
   - `3` — Add a new record
   - `4` — Exit

---

## 📄 Sample Data Format (`pharmacy_data.txt`)

```
fever paracetamol MedPlus 500mg TwiceDaily MainStreet
cold cetirizine Apollo 10mg OnceDaily ParkRoad
```

*(Fields must be single words — no spaces — since entries are space-separated.)*

---

## 👤 Author

**arshiyaa8**
