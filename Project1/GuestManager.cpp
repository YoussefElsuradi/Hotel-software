

#include <iostream>
#include "GuestManager.h"
#include <vector>






GuestType Guest::GetGuestType()const{

	return 	typeOfGuest;
}

RoomType Guest::GetRoomType()const{

	return OcRoomType;
}

int Guest::GetBookedDays()const{

	return bookedDays;
}

Guest::Guest(GuestType GuestT, RoomType RoomT, int StayDuration){
	typeOfGuest = GuestT;
	OcRoomType = RoomT;
	int bookedDays = StayDuration;

}

int Rockstar::GetRoomBusyDays()const{

	return bookedDays + 10 ;
}
int Guest::GetRoomBusyDays()const{
	return bookedDays;
}


int Businessman::GetRoomBusyDays()const{

	return bookedDays;
}
int Family::GetRoomBusyDays()const{
	return bookedDays;
}
int Businessman::GetAdditionalIncome()const{

	return income;
}
int Family::GetAdditionalIncome()const{

	return 0;
}
int Rockstar::GetAdditionalIncome()const{

	return 0;
}



GuestManager::GuestManager(const int NumOfStandardRooms,const int DayPriceStandard,const int NumOfComfortRooms,const int DayPriceComfort){
	int NumOfStandardRooms = StanRooms;
	int DayPriceStandard = DayPriceS;
	int NumOfComfortRooms = ComfRooms;
	int DayPriceComfort = DayPriceC;




}

bool GuestManager::AddGuest(GuestType GuestT, RoomType RoomT, int stayDays, int additionalIncome = 0){
	if(IsAvailable(RoomT)){
		if (GuestT == GuestType::Businessman){
			Guest* Bp = new Businessman(GuestT, RoomT, stayDays, additionalIncome);
			GVect.push_back(Bp);
			return true;
		}
		if (GuestT == GuestType::Family){
			Guest* p = new Family(GuestT, RoomT, stayDays);
			GVect.push_back(p);
			return true;
		}
		if (GuestT == GuestType::Rockstar){
			Guest* p = new Rockstar(GuestT, RoomT, stayDays);
			GVect.push_back(p);
			return true;
		}
	}
	return false;



}
//g++  -std=c++17 GuestManager.cpp
bool GuestManager::IsAvailable(RoomType RoomT, int inDays = 0){

	
	if(inDays == 0){
		if((RoomT == RoomType::Comfort)&& (NumOfComfortRooms - ComfRoomsUsed > 0))
			return true;
		else if((RoomT == RoomType::Standard )&&(NumOfStandardRooms - StanRoomsUsed > 0))
			return true;
	} 
	if

	

}

int GuestManager::IncomingProfit(){

}

float GuestManager::EarningEfficiency(){

}
GuestManager::~GuestManager(){

	for(int i{ 0 }; i < GVect.size(); i++){
		delete GVect[i];
		GVect[i] = nullptr;
	}

}



