#include<stdio.h>
#include<string.h>

 struct Flight{
    int flight_No;
    char dep_City[20];
    char des_City[20]; 
    char date[20];
    int av_seats ;
} ;
void DisplayFlights(struct Flight flights[], int size);
void BookSeats(struct Flight flights[], int size);
int main(){
    struct Flight flights[5] = {
        {100, "Lahore", "Multan", "2024-11-01", 50},
        {110, "Paris", "Tokyo", "2024-11-05", 75},
        {120, "Dubai", "Sydney", "2024-11-10", 100},
        {130, "Mumbai", "Toronto", "2024-11-15", 60},
        {140, "Karachi", "Islamabad", "2024-11-20", 40}
    };
    int choice;

    do {
    printf("\n****Flight Management System****\n");
    printf("1.Dispaly flight details\n");
    printf("2.Book a seat\n");
    printf("3.Exit\n");
    
    printf("Enter your choice: ");
    scanf("%d",&choice);
    
  
    switch(choice){
        case 1: DisplayFlights(flights,5);
        break;
        case 2: BookSeats(flights, 5);
        break;
        case 3: printf("Exiting...");
                return 0;
        
        default: printf("Invalid choice! Please try again.");
        break;
    } 
   
    } while(choice != 3);

    return 0;
}
void DisplayFlights(struct Flight flights[], int size){
       printf("\nFlight Details\n");
       printf("---------------------------------------------------------------------------\n");
       printf("Flight Number | Departure City | Destination City | Date        | Seats\n");
       printf("---------------------------------------------------------------------------\n");

       for(int i=0; i<size; i++){
        printf("%-10d  | %-15s  | %-15s  | %-10s  | %-5d \n",flights[i].flight_No, flights[i].dep_City, flights[i].des_City, flights[i].date, flights[i].av_seats);
       printf("---------------------------------------------------------------------------\n");
       }
}
void BookSeats(struct Flight flights[], int size){
    int flightno, found = 0;
    printf("\nEnter flight number to book a seat: ");
    scanf("%d",&flightno);
    for(int i=0; i<size; i++){
    if(flights[i].flight_No == flightno){
         found = 1;
        if(flights[i].av_seats > 0){
            flights[i].av_seats --;
        printf("Seat booked successfully! Remaining seats: %d\n",flights[i].av_seats);
    }
        else {
        printf("Sorry! No seats available on this flight.\n");
    }
    break;
}
    }
    if(!found)
    printf("Flight not found!. Please check the flight number and try again.\n");
    
}
