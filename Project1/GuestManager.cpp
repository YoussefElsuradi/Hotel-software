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
	bookedDays = StayDuration;

}
Guest::~Guest() {

}
Family::Family(GuestType GuestT, RoomType RoomT, int StayDuration):Guest(GuestT, RoomT, StayDuration)
{
	typeOfGuest = GuestT;
	OcRoomType = RoomT;
	bookedDays = StayDuration;

}
Businessman::Businessman(GuestType GuestT, RoomType RoomT, int StayDuration, int additionalincome):Guest(GuestT, RoomT, StayDuration)
{
	typeOfGuest = GuestT;
	OcRoomType = RoomT;
	bookedDays = StayDuration;

	addIncome = additionalincome;


}
Rockstar::Rockstar(GuestType GuestT, RoomType RoomT, int StayDuration):Guest(GuestT, RoomT, StayDuration)
{
	typeOfGuest = GuestT;
	OcRoomType = RoomT;
	bookedDays = StayDuration;

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

	return addIncome;
}
int Family::GetAdditionalIncome()const{

	return 0;
}
int Rockstar::GetAdditionalIncome()const{

	return 0;
}



GuestManager::GuestManager(const int NumOfStandardRooms,const int DayPriceStandard,const int NumOfComfortRooms,const int DayPriceComfort){
	StanRooms = NumOfStandardRooms;
	DayPriceS = DayPriceStandard;
	ComfRooms = NumOfComfortRooms;
	DayPriceC = DayPriceComfort;




}

bool GuestManager::AddGuest(const GuestType GuestT,const RoomType RoomT, int stayDays, int additionalIncome)
{
	if(IsAvailable(RoomT)){
		if (GuestT == GuestType::Businessman){
			Guest* Bp = new Businessman(GuestT, RoomT, stayDays, additionalIncome); // new poiner for guest
			GVect.push_back(Bp);// adds to the end of the GVect 
			
		}
		if (GuestT == GuestType::Family){
			Guest* Fp = new Family(GuestT, RoomT, stayDays);
			GVect.push_back(Fp);
			
		}
		if (GuestT == GuestType::Rockstar){
			Guest* Rp = new Rockstar(GuestT, RoomT, stayDays);
			GVect.push_back(Rp);
			
		}
		if (RoomT == RoomType::Standard){
			StanRoomsUsed++;
		}

			
			
		if (RoomT == RoomType::Comfort)
			ComfRoomsUsed++;

		//std::cout << "SRU = " << StanRoomsUsed << std::endl;
		return true;
	}

	return false;
	


}
//g++  -std=c++17  -Wall  GuestsTest.cpp  GuestManager.cpp  -o test
bool GuestManager::IsAvailable(const RoomType RoomT, int inDays){
	if (inDays == 0) {
		if (RoomT == RoomType::Comfort) {
			if (ComfRooms <= ComfRoomsUsed) {
				return false;
			}

		}else if (RoomT == RoomType::Standard) {
			if (StanRooms <= StanRoomsUsed) {
				return false;
			}
		}
		
		return true;

	}else{
		for (long unsigned int i{ 0 }; i < GVect.size(); i++) {
			if (GVect[i]->GetRoomBusyDays() <= inDays) {
				return true;
			}
		}
		return false;
	}
	
}

// g++ GuestsTest.cpp GuestManager.cpp -o txt

int GuestManager::IncomingProfit(){
	int profits = 0;

	for (long unsigned int i{ 0 }; i < GVect.size(); i++) {
		if (GVect[i]->GetRoomType() == RoomType::Standard) {

			if (GVect[i]->GetGuestType() == GuestType::Businessman) {
				profits += ((GVect[i]->GetAdditionalIncome() * GVect[i]->GetRoomBusyDays()) + (GVect[i]->GetRoomBusyDays() * DayPriceS));
			}
			if (GVect[i]->GetGuestType() == GuestType::Rockstar) {
				profits += ((GVect[i]->GetRoomBusyDays() - 10) * DayPriceS);
			}
			if (GVect[i]->GetGuestType() == GuestType::Family) {
				profits += ((GVect[i]->GetRoomBusyDays() * DayPriceS));
			}
		}
		if (GVect[i]->GetRoomType() == RoomType::Comfort) {

			if (GVect[i]->GetGuestType() == GuestType::Businessman) {
				profits += ((GVect[i]->GetAdditionalIncome() * GVect[i]->GetRoomBusyDays()) + (GVect[i]->GetRoomBusyDays() * DayPriceC));
			}
			if (GVect[i]->GetGuestType() == GuestType::Rockstar) {
				profits += ((GVect[i]->GetRoomBusyDays() - 10) * DayPriceC);
			}
			if (GVect[i]->GetGuestType() == GuestType::Family) {
				profits += ((GVect[i]->GetRoomBusyDays() * DayPriceC));
			}
		}
	}

	
		return profits;
}

float GuestManager::EarningEfficiency(){

	for (long unsigned int i{ 0 }; i < GVect.size(); i++) {
		if (GVect[i]->GetRoomType() == RoomType::Standard) {

			if (GVect[i]->GetGuestType() == GuestType::Businessman) {
				DayProfits += ((GVect[i]->GetAdditionalIncome() + DayPriceS));
			}
			if (GVect[i]->GetGuestType() == GuestType::Rockstar) {
				DayProfits += (DayPriceS);
			}
			if (GVect[i]->GetGuestType() == GuestType::Family) {
				DayProfits += (DayPriceS);
			}
		}
		if (GVect[i]->GetRoomType() == RoomType::Comfort) {

			if (GVect[i]->GetGuestType() == GuestType::Businessman) {
				DayProfits += ((GVect[i]->GetAdditionalIncome() + DayPriceC));
			}
			if (GVect[i]->GetGuestType() == GuestType::Rockstar) {
				DayProfits += (DayPriceC);
			}
			if (GVect[i]->GetGuestType() == GuestType::Family) {
				DayProfits += (DayPriceC);
			}
		}
	}

	DayMaxProfits = float(StanRooms * DayPriceS) + float(ComfRooms * DayPriceS);

	earnEF = DayProfits / DayMaxProfits;
	return earnEF;
}
GuestManager::~GuestManager(){

	for(long unsigned int i{ 0 }; i < GVect.size(); i++){ // iterrates thru the vector deleting guessts from old to new 
		delete GVect[i];

		GVect[i] = nullptr; // replaces the deleted ones null pointers

	}

}

bool GuestManager:: operator <(GuestManager& b){
	
	return (IncomingProfit() < b.IncomingProfit());
}



