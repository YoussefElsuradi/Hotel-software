

#include <iostream>



enum RoomType 
{
	Standard,
	Comfort

};


enum GuestType
{
	Family,
	Businessman, // Businessman generates additional income (by actively using the items from the room refrigerator)
	Rockstar // Rockstar keeps room occupied for additional 10 days, but pays only for the days that were booked

};

/*
Create an abstract Guest class. It has the following mandatory parts in it

Protected fields for
-Type of the occupied room
-Type of the guest
-booked number of days
-there should be no additional income field
GetGuestType – a getter (a.k.a accessor) for a type of the guest
GetRoomType – a getter for a type of the room.
GetBookedDays – a getter for a number of the booked days
GetRoomBusyDays – purely virtual function that returns number of days that the room will be in use. This method will behave differently for different types of guests. Remember, that rockstar books and pays for a certain number of days, but the room stays busy for 10 days longer.
 int GetAdditionalIncome – purely virtual function that returns an amount of money generated each day in addition to the room cost. Remember, that businessmen generate additional income. Everybody else will return a default 0.
Guest( GuestType, RoomType, StayDuration ) – parametrized constructor that creates a new guest of specified type that occupies a room of a specified type for a specified number of days.
~Guest – virtual destructor. It does nothing in this class, but since we plan to inherit from this class, it is necessary.
There should be no setter (a.k.a mutator) methods for Guest fields.
From the Guest class inherit three classes

-class Family. The most regular Guess sub-class with nothing special in it. For a family, days booked equal to room busy day, and there is no additional income.
-class Rockstar. As discussed before, the number of days the room is busy is 10 days longer than the days booked for a rockstar. There is no additional income.
-class Businessman. Objects of Businessman class has an additional income int field and the following parametrized constructor
Businessman( GuestType, RoomType, stayDuration, additionalIncome )
Pay attention, there are no setters (a.k.a mutators) for fields of the base class Guest. You’ll have to activate the parametrized constructor of Guest from the constructor of Businessman. The modern C++ constructor syntax allows you to do it.
*/

class Guest
{

protected:
	



};