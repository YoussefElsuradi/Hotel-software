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


    GuestType GetGuestType();
    RoomType GetRoomType();
    int GetBookedDays();
    virtual int RoomBusyDays() = 0;
    virtual int GetAdditionalIncome() = 0;
    Guest(GuestType, RoomType, int bookedDays);
    virtual ~Guest();
    


protected:

	RoomType OcRoomType();
    GuestType typeOfGuest();
    int bookedDays();


};

class GuestManager
{
	

};

class Family : public Guest {

};

class Rockstar : public Guest {
    virtual int RoomBusyDays() = 0;
//number of days the room is busy is 10 days longer than the days booked for a rockstar. There is no additional income.
};

class Businessman : public Guest {
    int additionalIncome;
    public: 
    Businessman(GuestType, RoomType, int bookedDays);
    

};

class GuestManager
{
    GuestManager(int NumOfStandardRooms, int dayPriceStandard, int NumOfComfortRooms, int dayPriceComfort);

    bool AddGuest(GuestType, RoomType, int stayDays, int additionalIncome);

    bool IsAvailable(RoomType, int inDays);

    int IncomingProfit();

    float EarningEfficiency(); 


};