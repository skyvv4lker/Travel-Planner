# 🗺️ Smart Travel Planner

A graph-based travel planner application that calculates **optimal travel routes** between cities.  
It uses advanced shortest-path algorithms like **Dijkstra, BFS, and DFS**, and handles constraints such as **cost, distance, and travel time**.

This project combines a **C++ backend** for computation and a **Python Flask frontend** for visualization and interaction.

---

## 🌟 Features

- ✅ Find the **fastest, cheapest, or shortest routes** between cities
- ✅ Handles multiple constraints: **time, cost, and distance**
- ✅ Outputs a **clear route summary and visual map**
- ✅ **Open-source** and easy to extend or customize
- ✅ Ideal for **students, travelers, and logistics enthusiasts**

---

## ⚡ Setup & Run

### 1️⃣ Build Backend
```bash
cd cpp
make build
```

### 2️⃣ (Optional) Test Backend CLI
```bash
make run-backend
```
This generates output.html in web/static/.

### 3️⃣ Run Frontend (Flask)
```bash
make run-frontend
```
Then open your browser at: http://127.0.0.1:5000

### 4️⃣ Clean Compiled Files
```bash
make clean
```

---

🛠️ **Tech Stack**

- **C++**: backend computations and graph algorithms  
- **Python Flask**: frontend web interface  
- **HTML/CSS**: web templates & output visualization  
- **CSV**: input data for cities and routes  

---

🔗 **Contributing**

Contributions are welcome!  

- Improve algorithms  
- Add new features (like map visualization or user login)  
- Optimize frontend design  

Please open an issue or a pull request to contribute.

---

📄 **License**

This project is open-source. Feel free to use, modify, and distribute under the **MIT License**.

---

👏 **Acknowledgements**

- Inspired by real-world GPS and logistics systems  
- Built as a **C++ + Flask hybrid project** for learning and practical application
