

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


GuestType Guest::GetGuestType(){


}

RoomType Guest::GetRoomType(){

}

int Guest::GetBookedDays(){

}

int Guest::RoomBusyDays(){

}

RoomType  Guest::OcRoomType(){

}
int Guest::RoomBusyDays(){

}

Guest::Guest(GuestType, RoomType, int bookedDays){

};

int Rockstar::RoomBusyDays(){
	int RBookedDays = GetBookedDays() + 10;
	return RBookedDays;
}


