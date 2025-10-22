#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle {
public:
    virtual ~Vehicle() {}
    virtual Vehicle* Clone() const = 0;
    virtual void show() const = 0;
};

#endif // VEHICLE_H