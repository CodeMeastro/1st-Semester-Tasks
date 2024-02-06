#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
double total , company_pay , excess_amount , saved_amount ;   //Global Variables
//int number_of_days();
int get_time(string);            //Function to get time
string get_part(string);         //Function to get part
//void roundTrip_airFare();        //Function to get airfare
//void car_rentals();              //Function to get car rentals
//void miles_driven();           //Function to get miles driven in personal car
//void parking_fees(int);        //Function to get parking fees for all days spent in hotel
//void taxi_fees();              //Function to get taxi fees 
//void conference_registrtion_fee();    //Function to get conference or semonar registration fees
//void hotel_expenses(int);             //Function to get hotel expense
void get_meal_amount1(int,string);    //Function to get meal amount
void get_meal_amount2(int,string);    //Function to get meal amount
void get_meal_alldays(int);              //Function to get meal of all days

//Main function starts from here
int main()
{
    string prompt,day_part1,day_part2;
    int time_departure,time_arrival,days = 20;
    //days = number_of_days();
    prompt = "Enter the time of departure on the first day of the trip (HH:MM): ";
    time_departure =  get_time(prompt);
    prompt = "Enter the time of arrival on the last day of the trip (HH:MM): ";
    time_arrival =  get_time(prompt);
    prompt = "Enter the part of the day for departure on the first day of the trip(am:pm): ";
    day_part1 = get_part(prompt);
    prompt = "Enter the part of the day for departure on the first day of the trip(am:pm): ";
    day_part2 = get_part(prompt);
    //roundTrip_airFare();
    //car_rentals();
    //miles_driven();
    //parking_fees(days);
    //taxi_fees();
    //conference_registrtion_fee();
    //hotel_expenses(days);
    get_meal_amount1(time_departure , day_part1);
    get_meal_amount2(time_arrival, day_part2);
    get_meal_alldays(days);
    cout<<"______________________________________"<<endl;
    cout<<"Total is: "<<total<<"$"<<endl;
    cout<<"The amount company will pay: "<<company_pay<<"$"<<endl;
    cout<<"The excess amount which the person will pay: "<<excess_amount<<"$"<<endl;
    cout<<"The amount saved by the person will pay: "<<saved_amount<<"$"<<endl;
    return 0;
}

//Function to take input of am/pm
string get_part(string p)
{
    string choice;
    cout<<p<<endl;
    cin>>choice;
    while(choice!="am" && choice!="AM" && choice!="PM" && choice!="pm")
    {
        cout<<"Please can you enter the part correctly"<<endl;
        cout<<"Enter the input in limit of (am/AM/pm/PM): "<<endl;
        cin>>choice;
    }
    return choice;
}

//Function to get time as an input from the user
int get_time(string p)
{
    //To input time from user
    string tim,substring = ":", extract_hour;
    cout<<p<<endl;
    getline(cin,tim);
    size_t found = tim.find(substring);
    extract_hour = tim.substr(0,found);
    int hour = stoi(extract_hour);
    while(hour<=0 || hour>12)
    {
      cout<<"The time you entered is not the correct time"<<endl;
      cout<<"Enter the correct time in range of (1:00 - 12:00): "<<endl;
      getline(cin,tim);
      found = tim.find(substring);
      extract_hour = tim.substr(0,found);
      hour = stoi(extract_hour);
    }
    return hour;
}

//Function to get meal of departure day
void get_meal_amount1(int timing,string parting)
{
    double amount1;
    if(parting == "am" || parting == "AM")
    {
        if(timing<=7)
        {
            cout<<"Enter the amount of the breakFast you have eaten: "<<endl;
            cin>>amount1;
            total = total + amount1;
            // the amount company will pay
            if(amount1>=9)
            {
              excess_amount =excess_amount + (amount1 - 9);
              company_pay = company_pay + 9;  
            }
            else if(amount1<9)
            {
                 saved_amount = saved_amount + (9 - amount1);
                 company_pay =  company_pay + amount1;
            }
            
        }
        else if(timing>7 || timing<=12)
        {
            cout<<"Enter the amount of the lunch you have eaten: "<<endl;
            cin>>amount1;
            total = total + amount1;
            if(amount1>=12)
            {
              excess_amount =excess_amount + (amount1 - 12);
              company_pay = company_pay + 12;  
            }
            else if(amount1<12)
            {
                 saved_amount = saved_amount + (12 - amount1);
                 company_pay =  company_pay + amount1;
            }
        }
    }
    else if(parting == "pm" || parting == "PM")
    {
        if(timing >=1 || timing <=6)
        cout<<"Enter the amount of the dinner you have eaten: "<<endl;
        cin>>amount1;
        total = total + amount1;
        if(amount1>=16)
            {
              excess_amount =excess_amount + (amount1 - 16);
              company_pay = company_pay + 16;  
            }
            else if(amount1<16)
            {
                saved_amount = saved_amount + (16 - amount1);
                 company_pay =  company_pay + amount1;
            }
    }
    
}

//Function for arrival day meal
void get_meal_amount2(int timing,string parting)
{
    double amount2;
    if(parting == "am" || parting == "AM")
    {
        if(timing<=7)
        {
            cout<<"Enter the amount of the breakFast you have eaten: "<<endl;
            cin>>amount2;
            total = total + amount2;
            // the amount company will pay
            if(amount2>=9)
            {
              excess_amount =excess_amount + (amount2 - 9);
              company_pay = company_pay + 9;  
            }
            else if(amount2<9)
            {
                 saved_amount = saved_amount + (9 - amount2);
                 company_pay =  company_pay + amount2;
            }
            
        }
        else if(timing>7 || timing<=12)
        {
            cout<<"Enter the amount of the lunch you have eaten: "<<endl;
            cin>>amount2;
            total = total + amount2;
            if(amount2>=12)
            {
              excess_amount =excess_amount + (amount2 - 12);
              company_pay = company_pay + 12;  
            }
            else if(amount2<12)
            {
                 saved_amount = saved_amount + (12 - amount2);
                 company_pay =  company_pay + amount2;
            }
        }
    }
    else if(parting == "pm" || parting == "PM")
    {
        if(timing >=1 || timing <=6)
        cout<<"Enter the amount of the dinner you have eaten: "<<endl;
        cin>>amount2;
        total = total + amount2;
        if(amount2>=16)
            {
              excess_amount =excess_amount + (amount2 - 16);
              company_pay = company_pay + 16;  
            }
            else if(amount2<16)
            {
                 saved_amount = saved_amount + (16 - amount2);
                 company_pay =  company_pay + amount2;
            }
    }
}
void  get_meal_alldays(int a) //Function to get meal for all days in hotel
{
    double amount,all;
    cout<<"For all days except first and last day"<<endl;
    cout<<"Enter for any one day I will calculate for all days"<<endl;
    cout<<"Enter the amount of the eatings you have payed for: "<<endl;
    cin>>amount;
    all = amount * a;
    total = total + all;
    company_pay = company_pay + all;
}











