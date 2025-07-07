
# stack-n-spin

---

##  Getting Started

### 1. **Clone the Repository**
```sh
git clone https://github.com/loak20/stack-n-spin.git
cd stack-n-spin
cd game
```

### 2. **Build the Project (with CMake)**
```sh
cmake -S . -B build
cmake --build build
```

### 3. **Run the Tests**
```sh
./build/tests
```

### 4. **Run the Casino**
```sh
./build/casino
```
---

## 🧩 How to Add a New Game

1. **Create New Game Files**
   - Add `YourGame.hpp` and `YourGame.cpp` in the project directory.
   - Inherit from the `Game` base class:
     ```cpp
     #include "Game.hpp"
     class YourGame : public Game {
     public:
         YourGame(const std::string& playerName, double initialBalance);
         void play(double& playerBalance) override;
         std::string getName() const override;
         // ... your game logic ...
     };
     ```

2. **Implement Your Game Logic**
   - Define the constructor, `play()`, and `getName()` in `YourGame.cpp`.

3. **Register the Game in CasinoManager**
   - In `CasinoManager.cpp`, add your game in the constructor:
     ```cpp
     addGame(std::make_shared<YourGame>(playerName, playerBalance));
     ```
   - Include your game’s header at the top:
     ```cpp
     #include "YourGame.hpp"
     ```

4. **Update CMakeLists.txt**
   - Add your new `.cpp` file to the `add_executable` list:
     ```
     add_executable(casino
         main.cpp
         CasinoManager.cpp
         Blackjack.cpp
         Roulette.cpp
         YourGame.cpp   # <--- Add this line
     )
     ```

5. **(Optional) Add Tests**
   - Create a test file in `tests/` and add test cases for your game logic.

6. **Rebuild and Run**
   - Rebuild the project and your new game will appear in the casino menu!

---
