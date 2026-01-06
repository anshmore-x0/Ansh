#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<stdlib.h>
#include<time.h>

int get_stop_index(const char *stop_name, const char *stops[],int num_stops);
int calculate_fare(int source_index, int destination_index);
void print_ticket(const char *source, const char *destination, int fare);

int main() 
{
    const char *stops[] = {"NAGASANDRA", "YESHWANTHPUR","MAJESTIC", "CHICKPET", "JAYANAGAR", "INDIRANAGAR", "WHITEFIELD", "TRINITY", "LALBAGH", "MADAVARA"};
    const int num_stops = 10;
    char source_input[50];
    char destination_input[50];
    int source_index = -1;
    int destination_index = -1;
    int fare = 0;

    printf("---  Namma Metro (Green Line) Ticket Kiosk ---\n");
    printf("Available Stops (Enter exactly as shown):\n");
    for (int i = 0; i < num_stops; i++) 
    {
        printf("%d. %s\n", i + 1, stops[i]);  
    }
    printf("------------------------------------------------\n");
    
    while (source_index == -1) 
    { 
        printf("Enter Source Station: ");
        if (scanf("%49s", source_input) != 1) 
        {
            return 1;
        }
        source_index = get_stop_index(source_input, stops,num_stops);
        if (source_index == -1) 
        printf("Invalid Source Station. Please check the spelling and try                          again.\n"); 
        }
    }
    while (destination_index == -1) 
    { 
        printf("Enter Destination Station: "); 
        if (scanf("%49s", destination_input) != 1) 
        {
            return 1; 
        } 
       destination_index = get_stop_index(destination_input,stops,num_stops); 
        if (destination_index == -1) 
        {
            printf("Invalid Destination Station. Please check the spelling and try again.\n"); 
        } 
        else if (destination_index == source_index) 
        {
            printf("Source and Destination cannot be the same. Please choose a  different destination.\n"); 
            destination_index = -1; 
        }
    }    
    fare = calculate_fare(source_index, destination_index);
    print_ticket(stops[source_index], stops[destination_index], fare);
    return 0;
}
int get_stop_index(const char *stop_name, const char *stops[] , int num_stops) 
{
    char temp_input[50];
    strncpy(temp_input, stop_name, 49);
    temp_input[49] = '\0';
    for (char *p = temp_input; *p; p++) 
    {
        *p = toupper(*p);
    }
    for (int i = 0; i < num_stops; i++) 
    { 
        if (strcmp(temp_input, stops[i]) == 0) 
        {
            return i; 
        }
    }
    return -1;
}
int calculate_fare(int source_index, int destination_index);
{
 int num_stops_traveled = destination_index - source_index;
    if (num_stops_traveled < 0) 
    {
        num_stops_traveled = -num_stops_traveled;
    }
    int base_fare = 10;
    int incremental_rate = 5;
    int calculated_fare = base_fare;
    if (num_stops_traveled == 0)
    {
        return 0;
    }
    return base_fare + (num_stops_traveled * incremental_rate)
}

void print_ticket(const char *source, const char *destination, int fare) 
{
    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);
    char date_buffer[11];
    char time_buffer[9];
    strftime(date_buffer, sizeof(date_buffer), "%d/%m/%Y", local_time);
    strftime(time_buffer, sizeof(time_buffer), "%H:%M:%S",local_time);
    srand(time(NULL)) ;   
    int id = rand()%1000;
    printf("\n=====================================);
    printf("| Namma Metro Ticket |\n");
    printf("==========================================\n");
    printf("| Date: %-10s | Time: %s |\n", date_buffer,time_buffer);
    printf("------------------------------------------\n");
    printf("| SOURCE: %-26s |\n", source);
    printf("| DESTINATION: %-26s |\n", destination);
    printf("------------------------------------------\n");
    printf("| TICKET ID: BMT-G123-A%03d |\n",id);
    printf("------------------------------------------\n");
    printf("| FARE PAID: INR %d |\n", fare);
    printf("==========================================\n");
    printf("| Thank you for choosing Namma Metro. |\n");
    printf("| Please keep the token until exit. |\n");
    printf("==========================================\n");
}
