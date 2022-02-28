

#include <iostream>
#include "GuestManager.h"



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



class Guest
{
	Guest();
	Guest(GuestType, RoomType, StayDuration);

	virtual ~Guest();

protected:
	



};

class GuestManager
{
	int GuestManager(int OfStandardRooms, int dayPriceStandard, int OfComfortRooms, int dayPriceComfort);

};