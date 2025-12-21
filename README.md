# C++ Module 04 – Subtype Polymorphism, Abstract Classes & Interfaces 🐾🧠🧊

✅ **Status**: Completed – all exercises  
🏫 **School**: 42 – C++ Modules (Module 04)

> *Subtype polymorphism, virtual functions, deep copies, abstract classes, and “interfaces” via pure abstract classes (C++98).*

---

## 📚 Table of Contents

- [Description](#-description)
- [Goals of the Module](#-goals-of-the-module)
- [Exercises Overview](#-exercises-overview)
  - [ex00 – Polymorphism](#ex00--polymorphism)
  - [ex01 – I don’t want to set the world on fire](#ex01--i-dont-want-to-set-the-world-on-fire)
  - [ex02 – Abstract class](#ex02--abstract-class)
  - [ex03 – Interface & recap](#ex03--interface--recap)
- [Requirements](#-requirements)
- [Build & Run](#-build--run)
- [Repository Layout](#-repository-layout)
- [Testing Tips](#-testing-tips)
- [42 Notes](#-42-notes)

---

## 📝 Description

This repository contains my solutions to **42’s C++ Module 04 (C++98)**.
The module focuses on **runtime polymorphism** (virtual functions), **proper destruction through base pointers**, **deep-copy ownership** (Rule of Three), plus **abstract classes and interface-like design** using pure virtual methods.

---

## 🎯 Goals of the Module

Concepts covered (depending on the exercise):

- Subtype polymorphism: **virtual functions**, virtual dispatch, overriding
- Correct destruction: **virtual destructors** when deleting through base pointers
- Composition + ownership: `Brain*` inside `Dog` / `Cat` + proper `new/delete`
- **Deep copy** vs shallow copy (copy constructor + assignment operator)
- Abstract classes (non-instantiable base)
- “Interfaces” via **pure abstract classes** (`= 0`)

---

## 📦 Exercises Overview

### ex00 – Polymorphism

**Goal:**  
Implement a base class `Animal` with a `type` and a `makeSound()` method.
Create derived classes `Dog` and `Cat` that override `makeSound()` so calls through `Animal*` produce the *derived* sound.

Also implement `WrongAnimal` / `WrongCat` to demonstrate what happens when polymorphism is done “wrong” (e.g., missing `virtual`).

**Concepts practiced:**
- `virtual` functions and overriding
- Polymorphic behavior via base pointers/references
- Why forgetting `virtual` breaks dynamic dispatch

---

### ex01 – I don’t want to set the world on fire

**Goal:**  
Add a `Brain` class with `std::string ideas[100]`.
`Dog` and `Cat` must own a `Brain*` and manage it with `new` / `delete`.

In `main`, create an array of `Animal*` (half dogs / half cats), then `delete` them via `Animal*` and ensure destructors are called correctly and there are **no leaks**.

Copies of `Dog` and `Cat` must be **deep copies** (no shared Brain).

**Concepts practiced:**
- Rule of Three (copy ctor, assignment, destructor)
- Deep copy ownership & avoiding double free / leaks
- Polymorphic deletion order

---

### ex02 – Abstract class

**Goal:**  
Make the base `Animal` **non-instantiable** (because an “Animal” doesn’t make sense by itself). Everything should still work as before with `Dog` / `Cat`.

> Optional: rename it to `AAnimal` (depending on your preference / implementation).

**Concepts practiced:**
- Pure virtual functions
- Abstract base classes and intent in API design

---

### ex03 – Interface & recap

**Goal:**  
Implement a small Materia system:

- `AMateria` (abstract base): has `type`, `clone()` (pure virtual), and `use()`
- Concrete materias: `Ice` and `Cure`
  - `type`: `"ice"` / `"cure"`
  - `clone()` returns a new instance of the same type
- `ICharacter` interface + concrete `Character` with an inventory of **4 slots**
  - `equip()` puts materia into the first empty slot
  - `unequip()` must **not delete** materia
  - copies of `Character` must be **deep** (inventory cloned, old deleted)
- `IMateriaSource` interface + `MateriaSource`
  - can learn up to **4** materia “templates” (store copies)
  - can `createMateria(type)` by cloning learned template, or return `0` if unknown

**Important note:**  
Unequipped materias must still be managed somehow (save addresses, “floor” storage, etc.) to avoid leaks.

**Concepts practiced:**
- Interface design in C++98 (pure abstract classes)
- Cloning pattern / prototype pattern
- Ownership rules and memory safety

---

## 🛠 Requirements

From the subject:

- **Compiler**: `c++`
- **Flags**: `-Wall -Wextra -Werror` (and it must compile with `-std=c++98`)
- **No external libraries**
- Forbidden: `printf`, `malloc`, `free` (and family)
- Until later modules: **no STL containers / algorithms** (no `<vector>`, no `<algorithm>`, etc.)
- “Goodbye Norminette!” (no enforced C norm), but code must stay readable

---

## ▶️ Build & Run

```bash
git clone <this-repo-url>
cd cpp-module-04
````

### ex00

```bash
cd ex00
make
./animal
```

### ex01

```bash
cd ex01
make
./animal
```

### ex02

```bash
cd ex02
make
./animal
```

### ex03

```bash
cd ex03
make
./interface
```

> Executable names may vary depending on your Makefiles.

---

## 📂 Repository Layout

```text
cpp-module-04/
├── ex00/
│   ├── Makefile
│   ├── main.cpp
│   ├── Animal.hpp / Animal.cpp
│   ├── Dog.hpp / Dog.cpp
│   ├── Cat.hpp / Cat.cpp
│   ├── WrongAnimal.hpp / WrongAnimal.cpp
│   └── WrongCat.hpp / WrongCat.cpp
│
├── ex01/
│   ├── Makefile
│   ├── main.cpp
│   ├── Animal.*  Dog.*  Cat.*
│   └── Brain.hpp / Brain.cpp
│
├── ex02/
│   ├── Makefile
│   ├── main.cpp
│   ├── AAnimal/Animal.*  Dog.*  Cat.*  Brain.*
│   └── (same structure as ex01, but base is abstract)
│
└── ex03/
    ├── Makefile
    ├── main.cpp
    ├── AMateria.*   Ice.*   Cure.*
    ├── ICharacter.hpp   Character.*
    ├── IMateriaSource.hpp  MateriaSource.*
    └── (optional) Floor/Trash manager files
```

---

## 🔍 Testing Tips

* **ex00**

  * Call `makeSound()` through `Animal*` and verify the derived sound is used
  * Verify `WrongCat` behaves like `WrongAnimal` when polymorphism is broken

* **ex01 / ex02**

  * Copy a `Dog`/`Cat`, modify ideas in one Brain → the other must not change (deep copy)
  * Run leak checks (example):

    ```bash
    valgrind --leak-check=full ./animal
    ```
  * Ensure destructors are called in correct order when deleting through `Animal*`

* **ex03**

  * Test inventory boundaries (equip 5th materia → nothing happens)
  * Test `unequip()` does not delete; ensure you still free unequipped materias later
  * Copy a `Character` and confirm deep copy (materias cloned; originals independent)
  * `MateriaSource` creates only known types; unknown → returns `0`

---

## 🧾 42 Notes

* Outputs from constructors/destructors should be **distinct per class** to make tests readable.
* This module is heavily about **ownership rules** — if you `new`, you must `delete` exactly once.
* You can pass the module without ex03, but doing it is excellent practice for interfaces + memory management.

---

If you’re a 42 student working on the same module: get inspired, but **write your own implementation** — that’s where the learning happens. 🚀

