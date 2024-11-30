# 🏦 ATM System 💼

> **A console-based C++ application for secure and intuitive ATM banking operations.🛠️**

---

## 🌟 Project Overview

This C++ project simulates a **Bank Management System** 🏦 that allows users to manage client data. The system provides functionalities like logging in, performing transactions (quick withdrawals, normal withdrawals, deposits), and checking account balances. Additionally, it ensures secure data persistence by storing all client details in a text file.

---

## ✨ Features

### 📋 Client Management
- 🔑 **Login**: Authenticate users with account number and PIN code.
- 💸 **Transactions**:
  - **Quick Withdraw**: Withdraw predefined amounts (20, 50, 100, 200, 400, 600, 800, 1000).
  - **Normal Withdraw**: Withdraw any amount in multiples of 5.
  - **Deposit**: Add money to client accounts.
- 💰 **Check Balance**: View the current balance of the client.
- 🔒 **Data Security**: Client data is securely stored in `Client.txt` for future use.

### 🔒 Data Security
- **Persistent Storage**: Client data is securely stored in `Client.txt` for future use.
- **Validation**: Ensure accurate data entry and sufficient balance for withdrawals.
- **Simple File-Based Database**: Efficiently manage all client data.

---

## 🏗️ Code Structure

### 📊 Data Structures
- **stClient**: Structure to hold client information.

### 🔢 Enumerations
- **enATMMainMenueOptions**: Defines options for the ATM main menu.

### 🛠️ Functions
- Comprehensive functions for managing client data, transactions, and menu navigation (refer to the code comments for details).

---

## ⚙️ How It Works

### Core Components
1. **User Input**:
   - Users interact with a console-based menu to select operations like login, withdraw, deposit, and check balance.
   - All user inputs are validated before being processed.

2. **Operations**:
   - **Login**: Authenticate users with account number and PIN code.
   - **Quick Withdraw**: Withdraw predefined amounts.
   - **Normal Withdraw**: Withdraw any amount in multiples of 5.
   - **Deposit**: Add money to client accounts.
   - **Check Balance**: View the current balance of the client.

3. **File Management**:
   - Client data is stored in `Client.txt`, using delimiters for easy parsing.
   - Efficient file handling ensures data is accurately read, written, and updated in the text file.

4. **Menu Navigation**:
   - The menu offers easy navigation between operations, including options to perform transactions, check balances, and logout.
   - Users can also return to previous menus at any point.

---

## 📚 Further Improvements

- 🔒 **Encryption**: Implement encryption for sensitive data like PIN codes.
- 🗄️ **Database Integration**: Replace text files with a relational database for more robust data management.
- 🖥️ **GUI**: Develop a graphical user interface for a more user-friendly and intuitive experience.
- 📜 **Logging**: Add a logging system to track all transactions and user activities for better monitoring and auditing.

---

## ⚙️ Technologies Used

- **Language**: C++ 🖥️
- **Programming Paradigm**: Procedural 💻
- **File Handling**: File I/O for data persistence 📂
- **Data Structures**: Vectors for dynamic client management 📊

---

## 🎯 Learning Outcomes

This project demonstrates several key C++ programming concepts:
- ✅ **File Handling**: Learn to store and retrieve data using file I/O operations, ensuring persistence.
- ✅ **Modular Design**: Functions are used for each operation, making the code organized and reusable.
- ✅ **Error Handling**: Input validation and error checking ensure the integrity of data and smooth user experience.
- ✅ **Control Structures**: Utilize loops, conditionals, and switch statements for handling complex logic.
- ✅ **Transaction Management**: Efficiently manage both deposit and withdrawal transactions.

---

## 📜 License

This project is open-source. Use it, modify it, share it! 🎉

Feel free to fork, modify, and use this project as a starting point for your own C++ applications! 🚀

---

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request. 🙌

---

## 🏁 Ready to Explore?

### 🚀 How to Run
1. **Download** the repository to your local machine. 📥
2. **Compile** the C++ code using your favorite IDE or compiler (e.g., `g++` in terminal). 💻
3. **Run** the compiled program and begin managing client data and transactions with ease! 🎮

---
