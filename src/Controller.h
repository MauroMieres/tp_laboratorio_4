#include "Passenger.h"
#include "LinkedList.h"

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
int controller_addPassenger(LinkedList* pArrayListPassenger,char* path);
int controller_editPassenger(LinkedList* pArrayListPassenger);
int controller_removePassenger(LinkedList* pArrayListPassenger);
int controller_ListPassenger(LinkedList* pArrayListPassenger);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);
int controller_showPassenger(Passenger* pPassenger);
int controller_IdSiguiente(LinkedList* pArrayListPassenger);
Passenger* controller_searchPassengerID(LinkedList* pArrayListPassenger,int id, int* index);
int controller_comparePrices(void* a, void* b );
int controller_compareLastNames(void* a, void* b );
int controller_compareNames(void* a, void* b );
int controller_compareId(void* a, void* b );
int controller_compareStatusFlight(void* a, void* b );
int controller_comparePassengerType(void* a, void* b );
int controller_compareFlyCodes(void* a, void* b );
