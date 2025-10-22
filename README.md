# Prototype Design Pattern Demonstration in C++

This project demonstrates the implementation of the Prototype design pattern in C++, showing how to efficiently clone complex objects with shared resources. 

# Authors

- Lucie Desnoyers
- Sadok Lajmi
- Aloïs Vincent
- Mélina Wang
- Zhang Boyang

# Description

The project simulates a vehicle management system with three types:
- Cars (Car)
- Buses (Bus)
- Vans (Van)

The goal of the project is to demonstrate the benefits of prototype-based cloning compared to classical object construction:

- **Classical construction:** Each new object independently initializes its own HeavyData instance.
- **Prototype cloning:** All cloned objects share the same HeavyData, copying only the lightweight fields.

### Class Diagram

![Class Diagram](ClassDiagram.jpg)

### Sequence Diagram

![Sequence Diagram](SequenceDiagram.png)

# Core Files
- `vehicle.h` - Abstract base class with Clone() method
- `carproto.h/cpp`, `busproto.h/cpp`, `vanproto.h/cpp` - Vehicle implementations
- `HeavyData.h/cpp` - Simulated expensive resource
- `bench.h` - Benchmarking system to compare performance
- `main.cpp` - Demonstration program
