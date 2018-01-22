import random
import os
import sys


class Vehicle:
    __wheels = 0
    __color = ""
    __weight = 0
    __license = ""

    def __init__(self,wheels,color,weight):
        self.__wheels = wheels
        self.__color = color
        self.__weight = weight

    def get_wheels(self):
        return self.__wheels
    def set_wheels(self,wheels):
        self.__wheels = wheels
    def get_color(self):
        return self.__color
    def set_color(self,color):
        self.__color = color
    def get_weight(self):
        return self.__weight
    def set_weight(self,weight):
        self.__weight = weight
    def license_type(self):
        return self.__license
    def set_license(self,lic):
        self.__license = lic

    def get_type(self):
        print("Vehicle")


class Car(Vehicle):
    __model = None
    def __init__(self, wheels, color, weight,model):
        self.__model = model
        return super().__init__(wheels, color, weight)

    def get_type(self):
        print("Car")

class Truck(Vehicle):
    __delivery = None
    def __init__(self, wheels, color, weight,deliver):
        self.__delivery = deliver
        return super().__init__(wheels, color, weight)

    def get_type(self):
        print("Truck")

class VehicleTesting:
    def get_type(self,vehicle):
        vehicle.get_type()


def main():
    print("Welcome to Cars")

    myCar = Car(4,"Black",1000,"sedan")
    myTruck = Truck(18,"Red",5000,"local")

    vehicle_testing = VehicleTesting()

    vehicle_testing.get_type(myCar)
    vehicle_testing.get_type(myTruck)



if __name__ == "__main__":
    sys.exit(int(main() or 0))
