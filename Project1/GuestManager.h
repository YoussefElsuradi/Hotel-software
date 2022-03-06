#pragma once
#include<vector>
#include<iostream>



enum class GuestType{
    Rockstar,Businessman,Family
};

enum class RoomType{
    Standard,Comfort
};



class Guest
{
public: 


    GuestType GetGuestType()const;
    RoomType GetRoomType()const;
    int GetBookedDays()const;
    virtual int GetRoomBusyDays()const = 0;
    virtual int GetAdditionalIncome()const = 0;
    Guest(GuestType GuestT, RoomType RoomT, int StayDuration);
    virtual ~Guest();
   


protected:

	RoomType OcRoomType;
    GuestType typeOfGuest;
    int addIncome = 0;
    int bookedDays = 0;
    int RoomBusyDays = 0;



};


class Family : public Guest {
public:
    Family(GuestType GuestT, RoomType RoomT, int StayDuration);
    int GetRoomBusyDays()const override;
    int GetAdditionalIncome()const override;
};

class Rockstar : public Guest {
    public:
    int GetAdditionalIncome()const override;
    Rockstar(GuestType GuestT, RoomType RoomT, int StayDuration);
    int GetRoomBusyDays()const override;
   
//number of days the room is busy is 10 days longer than the days booked for a rockstar. There is no additional income.
};

class Businessman : public Guest {

    public: 
    int GetAdditionalIncome()const;
    Businessman(GuestType GuestT, RoomType RoomT, int StayDuration, int additionalIncome);
    int GetRoomBusyDays()const;

    private:
    int income = 0;
};

class GuestManager
{
    public:

    GuestManager(const int NumOfStandardRooms,const int DayPriceStandard,const int NumOfComfortRooms,const int DayPriceComfort);

    bool AddGuest(const GuestType GuestT,const RoomType Roomt, int stayDays, int additionalIncome = 0);

    bool IsAvailable(const RoomType RoomT, int inDays = 0);

    int IncomingProfit();

    float EarningEfficiency(); 


    int StanRooms = 0;
    int DayPriceS = 0; 
    int ComfRooms = 0;
        
    int DayPriceC = 0;
    int StanRoomsUsed = 0;
    int ComfRoomsUsed =0;
    float DayProfits = 0;
    float DayMaxProfits = 0;
    float earnEF = 0;
    bool operator <(GuestManager b);
    ~GuestManager();

    
    private: 

    std::vector<Guest*> GVect; //vector of pointers
    


};