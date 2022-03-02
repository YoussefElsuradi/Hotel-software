#pragma once



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
public: 


    GuestType GetGuestType;
    RoomType GetRoomType;
    int GetBookedDays;
    virtual int RoomBusyDays() = 0;
    virtual int GetAdditionalIncome() = 0;
    Guest();
    


protected:

	RoomType OcRoomType;
    GuestType typeOfGuest;
    int bookedDays;


};

class GuestManager
{
	

};

class Family : public Guest {

};