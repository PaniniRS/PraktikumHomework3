#include <stdio.h> //standard 
#include <stdbool.h> //boolean
// #include <conio.h> //clearing screen
#include <windows.h> //time sleep for win
#include <unistd.h> //time sleep for linux

void PrintBuilding();
void MoveElevator();
int FindIndex();
int ElementExists();

int main(){
    int arrayLength = 9;
    char floors[9] = {'D', 'C', 'B', 'G', '1', '2', '3', '4', '5'};
    char* pElevatorPosition = &floors[0];
    char userDesiredFloor;
    char userWantsToExit;

    PrintBuilding(pElevatorPosition, floors, arrayLength);
    while (true){
        printf("\n\t[?] Which floor would you like to go to? -Floor ");
        scanf(" %c", &userDesiredFloor);
        char* pUserDesiredFloor = &userDesiredFloor;


        // If the floor doesnt exist in floors ask the user to input another floor
        int elementExists = 1;
        for (int i = 0; i < arrayLength; i++){
        if (*pUserDesiredFloor == floors[i]){
            elementExists = 0;
        }
    }
        if (elementExists){
            printf("\n\t[!!!]\tPlease enter a valid floor letter\t[!!!]");
            continue;
        }

        MoveElevator(pElevatorPosition, pUserDesiredFloor, floors, 9);
        printf("\n\t[!] Do you want to exit the lift? (Y or N): ");
        scanf(" %c", &userWantsToExit);
        if (userWantsToExit == 'Y' || userWantsToExit == 'y'){
            break;
        }else if (userWantsToExit == 'N' || userWantsToExit == 'n'){
            continue;
        }
        
        fflush(stdin);
    }

    return 0;
}

//=----------------------------------------------------------------------------=
//                          Functions
//=----------------------------------------------------------------------------=

void PrintBuilding(char* pElevatorPosition, char floors[], int floorCount){
        printf("\n+-------+\n");
    for (int i = floorCount-1; i > -1; i--){
        printf("|-     -|\n");
        //Finds and prints the elevator on the correct floor
        if (*pElevatorPosition == floors[i]){
        printf("+- [ ] -+\n");
        }else{
        printf("+-  %c  -+\n", floors[i]);
        }
    }
        printf("+-------+");
}

void MoveElevator(char* pElevatorPosition, char* pFloorToMoveTo, char array[], int arrayLength){
    int elevatorIndex = FindIndex(pElevatorPosition, array, arrayLength);
    int floorToMoveToIndex = FindIndex(pFloorToMoveTo, array, arrayLength);

    while (!(floorToMoveToIndex == elevatorIndex)){
        elevatorIndex = FindIndex(pElevatorPosition, array, arrayLength);
        //if the floor is above the elevator => move the elevator up
        //else if the floor is below the elevator => move the elevator down
        if (floorToMoveToIndex > elevatorIndex){
            pElevatorPosition = &array[elevatorIndex+1];
        }else if (floorToMoveToIndex < elevatorIndex){
            pElevatorPosition = &array[elevatorIndex-1];
        }
    }
            PrintBuilding(pElevatorPosition, array, arrayLength);
}

int FindIndex(char* elementToFind, char array[9], int arrayLength){
    int elementIndex;
    for (int i = 0; i < arrayLength; i++){
        char elementOfArray = array[i];
        if (*elementToFind == elementOfArray){ // error vamu nemoze da otvori memorija za adresata na pointerot
            elementIndex = i;
        }
    }
    return elementIndex;
}

int ElementExists(char* elementToFind, char array[9], int arrayLength){
    int elementExists = 1;
    for (int i = 0; i < arrayLength; i++){
        if (*elementToFind == array[i]){
            elementExists = 0;
        }
        return elementExists;
    }
    
}