#include<string.h>
#include <stdlib.h>
#include <time.h>
#include<stdio.h>
#include<unistd.h>
int main();
int CID;
struct User
{
	int ID;
	char username[20];
	char useremail[200];
	char password[20];
	char bookingmode[20];
	char time[200];
	char preference[200];
	int amountpaid;
	int cancel;
	int CID;
};
struct co_info{
    int flag;
 	int ID;
	char carname[100];
	char cname[100];
	char add[100];
	char purpose[200];
	int mnum;
	char pnum[11];
	int d;
	int m;
	int y; 
	int de;
	int me;
	int ye;
	int seats;
	int price;
	int rcount;
	float review;
    int CID;
};

void sortlowtohigh(int  data[],int size){
	int i,j,temp;
	 for (i =0; i < size; ++i) 
        {
 
            for (j = i + 1; j < size; ++j)
            {
 
                if (data[i] > data[j]) 
                {
 
                    temp =  data[i];
                    data[i] = data[j];
                    data[j] = temp;
 
                }
 
            }
 
}
}
void sorthightolow(int data[],int size){

	int i,j,temp;
	 for (i =0; i < size; ++i) 
        {
 
            for (j = i + 1; j < size; ++j)
            {
 
                if (data[i] < data[j]) 
                {
 
                    temp =  data[i];
                    data[i] = data[j];
                    data[j] = temp;
 
                }
 
            }
 
}
}
void reviewhightolow(float data[],int size){

	int i,j;
	float temp;
	 for (i =0; i < size; ++i) 
        {
 
            for (j = i + 1; j < size; ++j)
            {
 
                if (data[i] < data[j]) 
                {
 
                    temp =  data[i];
                    data[i] = data[j];
                    data[j] = temp;
 
                }
 
            }
 
}
}
void removeduplicate(int arr[],int size){
	int i,j,k;
	for(i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++)
        {
            /* If any duplicate found */
            if(arr[i] == arr[j])
            {
                /* Delete the current duplicate element */
                for(k=j; k<size; k++)
                {
                    arr[k] = arr[k + 1];
                }

                /* Decrement size after removing duplicate element */
                size--;

                /* If shifting of elements occur then don't increment j */
                j--;
            }
        }
    }
}
void reviewremoveduplicate(float arr[],int size){
	int i,j,k;
	for(i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++)
        {
            /* If any duplicate found */
            if(arr[i] == arr[j])
            {
                /* Delete the current duplicate element */
                for(k=j; k<size; k++)
                {
                    arr[k] = arr[k + 1];
                }

                /* Decrement size after removing duplicate element */
                size--;

                /* If shifting of elements occur then don't increment j */
                j--;
            }
        }
    }
}
int printstation(struct co_info car)
{
int flag=0;	
printf("CarID: %d ",car.CID);
printf("CarName: %s\t ",car.carname);
printf("Car Type:%s\t",car.purpose);
printf("Model Year: %d\t ",car.mnum);
printf("Seating Capacity: %d\t ",car.seats);
printf("PricePerDay: %d\t ",car.price);
printf("Reviews: %f\n",car.review);
flag++;
return flag;
}
NameQuery(char choice[])
{
  FILE *fp;
    fp=fopen("owner.bin","rb");
    int x=0;
    struct co_info car;
	char pref[100];
	int i,flag;
	printf("Write car name you prefer: ");
	fflush(stdin);
	gets(pref);
	system("cls");
	char input[10];
	strcpy(input,"Wedding");
	while(fread(&car,sizeof(struct co_info),1,fp))
	{
		if(strcmp(pref,car.carname)==0&&strcmp(choice,car.purpose)==0&&car.flag==0)
		{
	     x=printstation(car);	
	     }
	
	}

fclose(fp);
if(x==0)
	{
	 printf("No cars found,Returning to mainscreen.......");
	 sleep(2);
	 main();
	}
}
ModelQuery(char choice[])
{
 struct co_info car;
      FILE *fp;
      fp=fopen("owner.bin","rb");
	  int i,x=0,mod;
      printf("Enter desired model year? ");
      scanf("%d",&mod);
      system("cls");
      while(fread(&car,sizeof(struct co_info),1,fp))
      {
		  
       if(mod==car.mnum&&strcmp(choice,car.purpose)==0&&car.flag==0)
       {   
        x=printstation(car);
        }    
	  }
	if(x==0)
	{
	 printf("No cars found,Returning to mainscreen.......");
	 sleep(2);
	 main();
	}
	  
}
SeatingQuery(char choice[])
{
	int mod;
    FILE *fp;
	struct co_info car;
    fp=fopen("owner.bin","rb");
	printf("Write number of seats  you prefer: ");
   	  scanf("%d",&mod);
   	  system("cls");
   	  int x=0;
   	  while(fread(&car,sizeof(struct co_info),1,fp))
   	  {
   	  	if(mod==car.seats&&strcmp(choice,car.purpose)==0&&car.flag==0)
   	  	{
   	  	x=printstation(car);
		 }
	
}
if(x==0)
	{
	 printf("No cars found,Returning to mainscreen.......");
	 sleep(2);
	 main();
	}
}
void NameBrowse(char choice[])
{
    int x=0;
    FILE *fp;
	struct co_info car;
    fp=fopen("owner.bin","rb");
   	system("cls");
   	while(fread(&car,sizeof(struct co_info),1,fp))
   	  {
   	  	if(strcmp(car.purpose,choice)==0&&car.flag==0)
   	  	{
   	  	x=printstation(car);
		 }
	

}
if(x==0)
	{
	 printf("No cars found,Returning to mainscreen.......");
	 sleep(2);
	}
}
void Modelbrowseearliesttorecent(char choice[])
{
 FILE* ptr;
ptr=fopen("owner.bin","rb");
   struct co_info read;
	int count=0;
	while(fread(&read,sizeof(struct co_info),1,ptr)){
		if(strcmp(choice,read.purpose)==0&&read.flag==0)
			count++;
	}
	int sorted[count];
	 int i=0;
	 while(fread(&read,sizeof(struct co_info),1,ptr)){
		if(strcmp(choice,read.purpose)==0&&read.flag==0)
			{
			 sorted[i]=read.mnum;
			 i++;
			}
	
	}
	 i=0;
	 sortlowtohigh(sorted,count);
	 removeduplicate(sorted,count);
	 fseek(ptr,0,SEEK_SET);
	 int x=0;
	for (int j=0;j<count;j++)
	{
	while(fread(&read,sizeof(struct co_info),1,ptr)){
			if(sorted[i]==read.mnum&&strcmp(choice,read.purpose)==0&&read.flag==0){
			x=printstation(read);
			}

			
	}
	fseek(ptr,0,SEEK_SET);
	i++;
	}
	if(x==0)
	{
	 printf("No cars found,Returning to mainscreen.......");
	 sleep(2);
	 main();
	}
}
void Modelbrowserecenttoearliest(char choice[])
{
 FILE* ptr;
	ptr=fopen("owner.bin","rb");
	struct co_info read;
	int count=0;
	while(fread(&read,sizeof(struct co_info),1,ptr)){
		if(strcmp(choice,read.purpose)==0&&read.flag==0)
			count++;
	}
	fseek(ptr,0,SEEK_SET);
	int c=0;
	int sorted[count];
		while(fread(&read,sizeof(struct co_info),1,ptr))
		{
		  
		  if(strcmp(choice,read.purpose)==0&&read.flag==0)
		   {
			sorted[c]=read.mnum;
			c++;
		    }
	  }
	  int x;
	int i=0;
	 sorthightolow(sorted,count);
	 removeduplicate(sorted,count);
	 fseek(ptr,0,SEEK_SET);
	for (int j=0;j<count;j++){
	while(fread(&read,sizeof(struct co_info),1,ptr)){
			if(sorted[i]==read.mnum&&strcmp(choice,read.purpose)==0&&read.flag==0){
			x=printstation(read);
			}

			
	}
	fseek(ptr,0,SEEK_SET);
	i++;
	}
	if(x==0){
		printf("No car Found\nreturning to main menu");
		sleep(2);
		main();
	}
	  
}
void SeatingcapacityLowesttoHighest(char choice[])
{
 	FILE* ptr;
	ptr=fopen("owner.bin","rb");
	struct co_info read;
	int count=0;
	while(fread(&read,sizeof(struct co_info),1,ptr)){
		if(strcmp(read.purpose,choice)==0&&read.flag==0)
			count++;
	}
	int sorted[count];
	fseek(ptr,0,SEEK_SET);
	int c=0;
	while(fread(&read,sizeof(struct co_info),1,ptr)){
	  if(strcmp(read.purpose,choice)==0&&read.flag==0)
	   {
	   sorted[c]=read.seats;
	   c++;
       }
	}
	
	int i=0,x=0;
	 sortlowtohigh(sorted,count);
	 removeduplicate(sorted,count);
	 fseek(ptr,0,SEEK_SET);
	for (int j=0;j<count;j++){
	while(fread(&read,sizeof(struct co_info),1,ptr)){
			if(sorted[i]==read.seats&&strcmp(read.purpose,choice)==0&&read.flag==0)
			{
			printf("CarID: %d\t ",read.CID);
            printf("CarName: %s\t ",read.carname);
            printf("Model Year: %d\t ",read.mnum);
            printf("Seating Capacity: %d\t ",read.seats);
            printf("PricePerDay: %d\t ",read.price);
            printf("Reviews: %f\n",read.review);
			x++;	
			}

			
	}
	fseek(ptr,0,SEEK_SET);
	i++;
	}
	if(x==0)
	{
	 printf("No cars found,Returning to mainscreen.......");
	 sleep(2);
	 main();
	}
}
void Seatingcapacityhighesttolowest(char choice[])
{
 FILE* ptr;
	ptr=fopen("owner.bin","rb");
	struct co_info read;
	int count=0;
	while(fread(&read,sizeof(struct co_info),1,ptr)){
		if(strcmp(choice,read.purpose)==0&&read.flag==0)
			count++;
	}
	fseek(ptr,0,SEEK_SET);
	int c=0;
	int sorted[count];
		while(fread(&read,sizeof(struct co_info),1,ptr))
		{
		  
		  if(strcmp(choice,read.purpose)==0&&read.flag==0)
		   {
			sorted[c]=read.seats;
			c++;
		    }
	  }
	int i=0,x=0;
	 sorthightolow(sorted,count);
	 removeduplicate(sorted,count);
	 fseek(ptr,0,SEEK_SET);
	for (int j=0;j<count;j++){
	while(fread(&read,sizeof(struct co_info),1,ptr)){
			if(sorted[i]==read.seats&&strcmp(choice,read.purpose)==0&&read.flag==0){
				x=printstation(read);
			}

			
	}
	fseek(ptr,0,SEEK_SET);
	i++;
	}
	if(x==0)
	{
	 printf("No cars found,Returning to mainscreen.......");
	 sleep(2);
	 main();
	}
}
void pricehightolow(char choice[])
{
FILE* ptr;
	ptr=fopen("owner.bin","rb");
	struct co_info read;
	int count=0;
	while(fread(&read,sizeof(struct co_info),1,ptr)){
		if(strcmp(choice,read.purpose)==0&&read.flag==0)
			count++;
	}
	fseek(ptr,0,SEEK_SET);
	int c=0;
	int sorted[count];
		while(fread(&read,sizeof(struct co_info),1,ptr))
		{
		  
		  if(strcmp(choice,read.purpose)==0&&read.flag==0)
		   {
			sorted[c]=read.price;
			c++;
		    }
	  }
	int i=0,x=0;
	 sortlowtohigh(sorted,count);
	 removeduplicate(sorted,count);
	 fseek(ptr,0,SEEK_SET);
	for (int j=0;j<count;j++){
	while(fread(&read,sizeof(struct co_info),1,ptr)){
			if(sorted[i]==read.price&&strcmp(choice,read.purpose)==0&&read.flag==0){
			printf("CarID: %d\t ",read.CID);
            printf("CarName: %s\t ",read.carname);
            printf("Model Year: %d\t ",read.mnum);
            printf("Seating Capacity: %d\t ",read.seats);
            printf("PricePerDay: %d\t ",read.price);
            printf("Reviews: %f\n",read.review);	
            x++;
			}

			
	}
	fseek(ptr,0,SEEK_SET);
	i++;
	}
	if(x==0)
	{
	 printf("No cars found,Returning to mainscreen.......");
	 sleep(2);
	 main();
	}
 
}
void pricelowtohigh(char choice[])
{
	FILE* ptr;
	ptr=fopen("owner.bin","rb");
	struct co_info read;
	int count=0;
	while(fread(&read,sizeof(struct co_info),1,ptr)){
		if(strcmp(read.purpose,choice)==0&&read.flag==0)
			count++;
	}
	int sorted[count];
	fseek(ptr,0,SEEK_SET);
	int c=0;
	while(fread(&read,sizeof(struct co_info),1,ptr)){
	  if(strcmp(read.purpose,choice)==0&&read.flag==0)
	   {
	   sorted[c]=read.price;
	   c=c+1;;
       }
	}
	
	int i=0,x=0;
	 sortlowtohigh(sorted,count);
	 removeduplicate(sorted,count);
	 fseek(ptr,0,SEEK_SET);
	for (int j=0;j<count;j++){
	while(fread(&read,sizeof(struct co_info),1,ptr)){
		
			if(sorted[i]==read.price&&strcmp(read.purpose,choice)==0&&read.flag==0)
			{
			printf("CarID: %d\t ",read.CID);
            printf("CarName: %s\t ",read.carname);
            printf("Model Year: %d\t ",read.mnum);
            printf("Seating Capacity: %d\t ",read.seats);
            printf("PricePerDay: %d\t ",read.price);
            printf("Reviews: %f\n",read.review);
            x++;
			}

			
	}
	fseek(ptr,0,SEEK_SET);
	i++;
	}
	if(x==0)
	{
	 printf("No cars found,Returning to mainscreen.......");
	 sleep(2);
	 main();
	}			
}
void Reviews(char choice[])
{
    FILE *ptr;
	ptr=fopen("owner.bin","rb");
	struct co_info read;
	int count=0;
	while(fread(&read,sizeof(struct co_info),1,ptr)){
		if(strcmp(choice,read.purpose)==0&&read.flag==0)
			count++;
	}
	fseek(ptr,0,SEEK_SET);
	int c=0;
	float sorted[count];
		while(fread(&read,sizeof(struct co_info),1,ptr))
		{
		  
		  if(strcmp(choice,read.purpose)==0&&read.flag==0)
		   {
			sorted[c]=read.review;
			c++;
		    }
	  }
	int i=0,x=0;
	 reviewhightolow(sorted,count);
	 reviewremoveduplicate(sorted,count);
	 fseek(ptr,0,SEEK_SET);
	for (int j=0;j<count;j++){
	while(fread(&read,sizeof(struct co_info),1,ptr)){
			if(sorted[i]==read.review&&strcmp(choice,read.purpose)==0&&read.flag==0){
			x=printstation(read);
			}

			
	}
	fseek(ptr,0,SEEK_SET);
	i++;
	}
	
	if(x==0)
	{
	 printf("\nNo cars found,Returning to mainscreen.......");
	 sleep(2);
	 main();
	}
}
char* getlocaltime(){
	time_t ttime = time(0);
    
    char* dt = ctime(&ttime);
    return dt;
}
int card(int price)
{
  char cardno[100];
  int i=0,c=0;
  printf("Enter your card no");
  fflush(stdin);
  gets(cardno);
  for(i=0;i<strlen(cardno);i++)
  {
   if(cardno[i]>47&&cardno[i]<58)
   {
   	c++;
   }
  }
  if(c!=strlen(cardno))
  {
   printf("Invalid characters entered ");
   return 0;
  }
  if(strlen(cardno)<6||strlen(cardno)>19)
  {
   printf("Invalid card no");
   return 0;
  }
  i=0;
  printf("Your credit card no is: ");
  while(i<strlen(cardno))
  {
   if(i%4==0)
   {
   	printf(" ");
   }
   printf("%c",cardno[i]);
   i++;
  }
  printf("\nAmount to be withdrawed from your account is %d",price);
}
int payment (int price){
	int mode,cash;
	
  printf("\t\t\t\t Checkout");
  printf("\nPress 1 if you want to pay card\n");
	printf("\nPress 2 if you want to pay cash\n");
	scanf("%d",&mode);
	switch(mode)
	{
	  case 1:
	  	{
	  	 card(price);
	  	 break;
		  }
	  case 2:
	  	{
	  	 printf("Enter amount of cash ");
	  	 scanf("%d",&cash);
	  	 if(cash>=price)
	  	 {
	  	  printf("change returned is %d\n",cash-price);
		   }
		else 
		printf("Insufficient money entered");
		return 0;
		break;
		  }
	}
}
int Buy(struct User pass,int days,int price,char choice[])
{
 fflush(stdin);
 int ID;
 printf("\nEnter ID of the car you want to rent from the above list:    ");
 scanf("%d",&CID);
 system("cls");
 printf("Finding your car....\n");
 sleep(2);
 FILE *p;
 struct co_info car;
 p=fopen("owner.bin","rb");
 int i,flag=0,flag2=0;
 for(i=0;i<3;i++)
 {
 fseek(p,0,SEEK_SET);
 while(fread(&car,sizeof(struct co_info),1,p))
 {
 	if(flag>0&&flag<3)
 	{
 	  printf("Enter ID of the car you want to rent from the above list");
      scanf("%d",&CID);
	 }
 	if(car.CID==CID)
 	{
 	 if(strcmp(car.purpose,choice)==0)
 	 {
 	  printf("\t\t\t________________________________________________\n");
 	  printf("\t\t\t The car you have picked is %s\n",car.carname);
 	  price=price+days*car.price;
 	  printf("Your total price is %d\n",price);
 	  printf("\n_______________________________________________________\n");
 	  printf("\n\n");
 	  printf("Enter Y to confirm your order\nPress any  other character to go back to main page\n");
 	  char m[10];
 	  fflush(stdin);
	   gets(m);
 	  switch(strcmp(m,"Y")==0||strcmp(m,"y")==0)
 	  {
 	   case 1:
 	   	{
 	   	 system("cls");
 	   	 printf("Booking your Order........\n");
 	   	 sleep(2);
 	   	 printf("Congratulations your order has been confirmed!\n");
 	   	 printf("You will now be guided towards our Invoice and Payment Details Area");
		FILE *fr;
		fr=fopen("owner.bin","rb+");
		struct co_info read;
		while(fread(&read,sizeof(struct co_info),1,fr)){
				if (read.CID==CID){
					read.rcount++;
                    pass.CID=read.CID;
					fseek(fr,-sizeof(struct co_info),SEEK_CUR);
					fwrite (&read, sizeof(struct co_info), 1, fr);
					break;
				}
	
		}

		
 	   	

 	   	 return price;
 	   	 break;
		}
 	    default:
 	    {
	    main();
		break;
 	    }
	   }
	  }
	  else
	 {
	  printf("Your car is not listed in %s category and is not available for your uses please enter again\n");
	  flag++;
      }
      flag2++;
      continue;
	 }
	if(flag>3||flag2>3)
	{
	printf("We apologize for the inconvience\nNo cars found\n Exiting program......");
	char c=getchar(); 
	sleep(2);
	exit(0);
	}
	
 }
}
}
void filter(int choice,char pref[] )
{
  switch(choice)
  {
    case 1:
        { 
		  sleep(2);
	  	  system("cls");
	  	  NameQuery(pref);
	  	  break;
		  }
     case 2:
{
           
	  	  sleep(2);
	  	  system("cls");
	  	  ModelQuery(pref);
	  	  break;
		  
  }
  case 3:
  {
  	sleep(2);
	system("cls");
	SeatingQuery(pref);
	break;
  }
  case 4:
  {
  	sleep(2);
	system("cls");
	NameBrowse(pref);
	break;
  }
  case 5:
  {
  	sleep(2);
    system("cls");
	Modelbrowserecenttoearliest(pref);
	break;
  }
  case 6:
  {
  	sleep(2);
	system("cls");
    Modelbrowseearliesttorecent(pref);
    break;
  }
  case 7:
  {
  	sleep(2);
	system("cls");
	SeatingcapacityLowesttoHighest(pref); 
	break;
  }
  case 8:
  {
   sleep(2);
   system("cls");
   Seatingcapacityhighesttolowest(pref);
   break;
  }
  case 9:
  {
   sleep(2);
   system("cls");
   pricehightolow(pref);
   break;
  }
  case 10:
  {
  	sleep(2);
	system("cls");
	pricelowtohigh(pref);
	break;
  }
  case 11:
  {
  	 sleep(2);
	 system("cls");
	 Reviews(pref);
	 break;
  }
  default:
  {
  	printf("Invalid character");
  	break;
  }
}
}
int wedding(struct User pass,int price,char choice [])
{
struct co_info W;
printf("Loading Packages....");
int i;
 sleep(2);
 
 int Budget=3000,Normal=5000,Luxury=8000,Custom;
 printf("\nPlease specify what kind of package would you like\n1)Budget\n2)Normal\n3)Luxury\n4)Custom\n");
 scanf("%d",&i);
 switch (i)
 {
 	case 1:
 		{
 		 printf("You have selected the Budget package\nYour bill for decorations is %d Rs",Budget);
 		 price= price+Budget;

 		 break;
		 }
	case 2:
		{
		 printf("You have selected the Normal package\nYour bill for decorations is %d Rs",Normal);
		 price= price+Normal;
		 break;
		}
	case 3:
		{
		 printf("You have selected the Luxury package\nYour bill for decorations is %d Rs",Luxury);
		 price = price+Luxury;
		 break;
		}
	case 4:
		{
		 int flowers=3000,ribbons=2500,j;
		 printf("If you would like flowers only press 1\nIf you would like ribbons only press 2\n If you would like both press 3");
		 scanf("%d",&j);
		 switch(j)
		 { 
		 case 1:
		 	{
		 	 printf("You have selected the flowers only custom package\nYour bill for decorations is %d Rs\n",flowers);
		 	 price = price+flowers;
		 	 break;
			 }
		case 2:
			{
			 printf("You have selected the ribbons only custom package\nYour bill for decorations is %d Rs\n",ribbons);
			 price = price+ribbons;
			 break;
			}
		case 3:
			{
			 printf("You have selected the flowers and ribbons only custom package\nYour bill is %d Rs",flowers+ribbons);
			 price = price+(flowers+ribbons);
			 break;
			}
		default:
			{
			 char k;
			 printf("Invalid character entered\nIf you would like to exit press 0 or any other character\nIf you would like to go back to main wedding page press 1\n");
			 scanf("%c",&k);
			 switch(k)
			  {
				case '1':
					{
					wedding(pass,price,choice);
					}
				default:
					{
					 return 0;
					}
			  }
			}
		}
		break;
	 	}
	  default:
	    {    int k;
			 printf("Invalid character entered\nIf you would like to exit press 0 or any other character\nIf you would like to go back to main wedding page press 1\n");
			 scanf("%d",&k);
			 switch(k)
			  {
				case 1:
					{
					wedding(pass,price,choice);
					}
				default:
					{
					 return 0;
					}
		}
 }
 
}
fflush(stdin);
sleep(3);
system("cls");
 printf("\t\t\t\t Welcome to The Wedding Section of Wheels for Wheels");
 	
	printf("\nPress the following keys for your desired method of filtering ");
    printf("\n1,For searching for cars with a particular Model name.\n");
	printf("2,For searching for cars with a particular Model year.\n");
	printf("3,For searching for cars with a particular Seating capacity.\n");
	printf("4,For browsing all cars randomly by Model Name.\n");
	printf("5,For browsing all cars by Model year recent to earliest.\n");
	printf("6,For browsing all cars by Model year earliest to recent.\n");
	printf("7,For browsing all cars by Seating Capacity Lowest to Highest.\n");
	printf("8,For browsing all cars by Seating Capacity Highest to Lowest.\n");
	printf("9,For browsing all cars by Pricing Highest to Lowest.\n");
	printf("10,For browsing all cars by Pricing Lowest to Highest.\n");
	printf("11,For browsing all cars by their Owner's reviews\n");
	scanf("%d",&i);
	
filter(i,choice);
fflush(stdin);
	char ch;
	printf("\n__________________________________________________________________ \n");
	printf("If you want to rent a car Press 1\n");
	printf("If you want to go back to main menu any other character\n");
	scanf("%c",&ch);
	switch(ch)
	{
	  case '1':
	  	{
	  	 int day=1;
	  	 price= price+ Buy(pass,day,price,choice);
	  	 break;
		  }
	   default:
	    {
	      main();
	      break;
		}
	}
 return price;
}

int everyday(struct User pass,int price,char choice[])
{
 printf("Loading Everyday Section.....\n");
 sleep(2);
 system("cls");
 printf("\t\t\t\t Welcome to The Everyday Section of Wheels for Wheels\n");
 int day;
 printf("\t\t\t\tHow many days will you be needing the car: ");
 scanf("%d",&day);
 if(day>15)
 {
  price=price-2000;
  }
 if(day>30)
 {
  price=price-4000;
 }
    struct co_info E;
	int i;
	printf("\nPress the following keys for your desired method of filtering\n ");
    printf("1,For searching for cars with a particular Model name.\n");
	printf("2,For searching for cars with a particular Model year.\n");
	printf("3,For searching for cars with a particular Seating capacity.\n");
	printf("4,For browsing all cars randomly by Model Name.\n");
	printf("5,For browsing all cars by Model year recent to earliest.\n");
	printf("6,For browsing all cars by Model year earliest to recent.\n");
	printf("7,For browsing all cars by Seating Capacity Lowest to Highest.\n");
	printf("8,For browsing all cars by Seating Capacity Highest to Lowest.\n");
	printf("9,For browsing all cars by Pricing Highest to Lowest.\n");
	printf("10,For browsing all cars by Pricing Lowest to Highest.\n");
	printf("11,For browsing all cars by their Owner's reviews\n");
	scanf("%d",&i);
	fflush(stdin);
	FILE *p;
	int count=0;
	filter(i,choice);
	char ch;
		printf("\n__________________________________________________________________\n ");
	printf("If you want to rent a car Press 1\n");
	printf("If you want to go back to main menu any other character\n");
	scanf("%c",&ch);
	switch(ch)
	{
	  case '1':
	  	{
	  	 price= price+ Buy(pass,day,price,choice);
	  	 break;
		  }
	   default:
	    {
	      main();
	      break;
		}
	}


 return price;
}

int longdrive(struct User pass,int price,char choice[])
{
	struct co_info LD;
	printf("Loading Long-Drive Section.....\n");
 	sleep(2);
 	system("cls");
	int dist,days;
	printf("\t\t\t\t Welcome to The Long Drive Section of Wheels for Wheels\n");
	printf("\t\t\t\tRoughly for how many kilometers will you be needing the car: ");
	scanf("%d",&dist);
	printf("\t\t\t\tFor how many days will you be needing the car:  ");
	scanf("%d",&days);
	fflush(stdin);
	if(dist>300)
	{
	 price=price-3000;
	}
	if(dist>500)
	{
	 price=price-5000;
	}
	price=price+dist*50;
	int i;
	sleep(1);
	printf("Press the following keys for your desired method of filtering\n");
    printf("1,For searching for cars with a particular Model name.\n");
	printf("2,For searching for cars with a particular Model year.\n");
	printf("3,For searching for cars with a particular Seating capacity.\n");
	printf("4,For browsing all cars randomly by Model Name.\n");
	printf("5,For browsing all cars by Model year recent to earliest.\n");
	printf("6,For browsing all cars by Model year earliest to recent.\n");
	printf("7,For browsing all cars by Seating Capacity Lowest to Highest.\n");
	printf("8,For browsing all cars by Seating Capacity Highest to Lowest.\n");
	printf("9,For browsing all cars by Pricing Highest to Lowest.\n");
	printf("10,For browsing all cars by Pricing Lowest to Highest.\n");
	printf("11,For browsing all cars by their Owner's reviews\n");
	scanf("%d",&i);
	filter(i,choice);
	
	char ch;
		printf("\n_______________________________________________________________\n ");
	printf("If you want to rent a car Press 1\n");
	printf("If you want to go back to main menu any other character\n");
	scanf(" %c",&ch);
	switch(ch)
	{
	  case '1':
	  	{
	  	 price= price+ Buy(pass,days,price,choice);
	  	 break;
		  }
	   default:
	    {
	      main();
	      break;
		}
	}

	return price;
	
	
	
}
 
int preference(int i)
{
  switch(i)
  {
  	case 1:
  		{
  	     system("cls");
  		 return 1;
		  }
	case 2:
		{
		 system("cls");
		 return 2;
		}
	case 3:
		{
		 system("cls");
		 return 3;
		}
	default:
		{
		 system("cls");
		 printf("\t\t\tInvalid Character Entered");
		 int y;
		 printf("\nEnter 1 if you want to enter another number\nEnter any other number if you want to exit. ");
		 scanf("%d",&y);
		 switch(y)
		 {
		 case 1:
		  {
		   return 4;
		  }
		 default:
		 	{
		 	return 0;
			 }
		}
		}
  }
}

void invoice(int mode,int preference,int price,struct User *ptr){
	struct co_info car;
	system("cls");
	printf("Displaying Invoice. Please wait....\n");
	char* localtime=getlocaltime();
	strcpy(ptr->time,localtime);
	ptr->CID=CID;
	sleep(2);
	system("cls");
	printf("\n\t\t\t\tInvoice:\n");
	printf("\t\t---------------------------------------------\n");
	if (mode==1){	
		strcpy(ptr->bookingmode,"Normal");
		printf("\t\t| Mode of Booking :------------- Normal\n");}
	if (mode==2){
		strcpy(ptr->bookingmode,"Emergency");
		printf("\t\t| Mode of Booking :------------- Emergency\n");}
	if (preference==1){
		strcpy(ptr->preference,"Everyday Use");
		printf("\t\t| Preference:--------- Everyday Use\n");}
	if (preference==2){
		strcpy(ptr->preference,"Wedding");
		printf("\t\t| Preference:------------------- Wedding\n");}
	if (preference==3){
		strcpy(ptr->preference,"Long Drive");
		printf("\t\t| Preference:--------- Long Drive\n");}
	printf("\t\t| Date of Issuance:----- %s",localtime);
	FILE* fptr;
	fptr=fopen("owner.bin","rb");
	while(fread(&car,sizeof(struct co_info),1,fptr)){
		if (ptr->CID==car.CID){
			printf("\t\t| Car Name:----- %s\n",car.carname);
			printf("\t\t| CarID:------- %d\n",car.CID);
		}
	}
	
	printf("\t\t---------------------------------------------\n");
	printf("\t\t| Amount to be paid: %d PKR\n",price);
	ptr->amountpaid=price;
	printf("\t\t---------------------------------------------\n");
	ptr->cancel=0;
	sleep(2);
}



//-x-x-x-x--x-x-x-xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx-x-x-x-x-x-x-//


int main()
{
	struct User user;
	struct User comp;
	
	system("cls");
	printf("\t\t\t\t\tCar Rental System\n");
	printf("\t\t\t\t\t----------------\n");
	printf("\t\t\t\t\t      Signup\n");
	printf("\t\t\t\t\t-----------------");

	printf("\n");
	int num,i,flag=0;
	char a[100],b[100];
	printf("\t\t\t\tPress 1 For Signup\n");
	printf("\t\t\t\tPress 2 For Login\n");
	printf("\t\t\t\t1- Signup\n");
	printf("\t\t\t\t2- Login\n");	
	printf("Enter: ");
	scanf("%d",&num);
	fflush(stdin);
	switch(num)
	{
	
	case 1:
		
		{
		FILE *p;
		p=fopen("user.bin","rb");
		printf("Please fill in the information to get registered\n");
		printf("Enter your name: ");
		fflush(stdin);
		gets(user.username);
		printf("Enter email address:");
		fflush(stdin);
		gets(user.useremail);
		while(fread(&comp,sizeof(struct User),1,p))
		{
		 if(strcmp(comp.useremail,user.useremail)==0)
		 {
		   printf("This email is already registered to another account\n");
		   printf("You are being redirected to main page......");
		   sleep(2);
		   main();
		   
		 }
		}
		fclose(p);
		printf("Enter password:");
		fflush(stdin);
		gets(user.password);
		printf("Successfully signed up\n");
		p=fopen("user.bin","rb");
		int high=-1;
		struct User read;
		while(fread(&read,sizeof(struct User),1,p)){
			if (read.ID>high) high=read.ID;
		}
		high++;
		user.ID=high;
		sleep(2);
		break;
	}

		
	case 2:
	{
		FILE *str;
	str=fopen("user.bin","rb");
	if(str==NULL)
	{
	 printf("Error");
	 exit(1);
	}
	int x=0,z=0;
	for(i=0;i<3;i++)
	{
		printf("Enter the email:");
		fflush(stdin);
		gets(a);
		printf("Enter the password:");
		fflush(stdin);
		gets(b);
		fseek(str,0,SEEK_SET);
		 while(fread(&comp,sizeof(struct User),1,str))
			{
			if(strcmp(a,comp.useremail)==0)
			{
				if(strcmp(b,comp.password)==0)
				{
					user.ID=comp.ID;
					strcpy(user.username,comp.username);
					strcpy(user.useremail,comp.useremail);
					strcpy(user.password,comp.password);
					printf("Welcome %s\n",user.username);
					
					printf("Loading Menu...\n");
					sleep(2);
					
					x++;
				}
				
			}
			if(x>0)
			{
			break;}
			else
			{ 
			z++;
		   }
		}
		if(x>0)
		break;
		flag++;
		printf("Incorrect password\n");
		}
		break;
		
}
	}
	if (flag>=3)
	{
		printf("\nEntered incorrect password too many times");
        sleep(2);
		system("cls");
		printf("\nProgram Ending....");
		sleep(2);
		exit(1);
	}
	system("cls");
	int j,price=0,mode,cash;
	printf("Welcome %s\n",user.username);
	char key;
	if(num==2)
	{
	printf("\nEnter 1 for View any of your past bookings\n\n");
	printf("Enter any other key to continue towards your booking section\n\n");
	
	int count=0;
	fflush(stdin);
	scanf("%c",&key);
	if(key=='1'){
			FILE*fpptr;
			fpptr=fopen("user.bin","rb");
			struct User past;
			
			while(fread(&past,sizeof(struct User),1,fpptr)){
				
				if(strcmp(user.useremail,past.useremail)==0){
				printf("Displaying Past record #%d . Please wait....\n",++count);
				sleep(2);
			printf("\n\t\t\t\tInvoice:\n");
			printf("\t\t---------------------------------------------\n");
			printf("\t\t| Mode of Booking :------------- %s\n",past.bookingmode);
			printf("\t\t| Preference:-------------------%s\n",past.preference);
			printf("\t\t| Date of Issuance:----- %s",past.time);
			FILE* f;
			f=fopen("owner.bin","rb");
			struct co_info car;
			while(fread(&car,sizeof(struct co_info),1,f)){
			if (past.CID==car.CID){
			printf("\t\t| Car Name:----- %s\n",car.carname);
			printf("\t\t| CarID:------- %d\n",car.CID);
		}}
			printf("\t\t---------------------------------------------\n");
			printf("\t\t| Amount paid-----: %d PKR\n",past.amountpaid);
			printf("\t\t---------------------------------------------\n");
			sleep(2);	
				}
			}
		}
			
	
	if(count>0)
	printf("Thankyou for viewing past history\n");
	if (count==0&&key=='1') 
	printf("No past records as of now\nArranging Booking for you in just a moment.....\n");
	if(key=='1')
	{
	printf("Press L to Logout\n");
	printf("Press any other key to continue booking\n");
	fflush(stdin);
	scanf("%c",&key);
}
	if (key=='L'){
		printf("\n\n%s We are logging you out.....\n",user.username);
		printf("Have a nice day!");
		sleep(2);
		printf("\nLogged Out!");
		sleep(1);
		main();
	}		
	sleep(2);
	}

	system("cls");
	printf("\nPress 1 for normal booking\n");
	printf("Press 2 for emergency booking\n");
	scanf("%d",&j);
	switch (j)
	{
	  case 1:
	  	{
		 printf("Normal Booking Confirmed\n");
		 sleep(1);
		 printf("Loading Booking Menu....\n");
		 sleep(3);
	  	 break;
		  }
	  case 2:
	  	{
		printf("Emergency Booking Confirmed\n");
		 sleep(1);
		 printf("Loading Booking Menu....\n");
		 sleep(3);
	  	 price= 4000+price;
	  	 break;
		  }
	  default:
	  	{
	  	 printf("Invalid character entered");
	  	 return 0;
		  }
	}
  system("cls");
  int k,x,p1=0,p2=0,p3=0;
  printf("Please specify the purpose of renting a car,that is :\n1)For every day use\n2)for wedding purpose\n3)for long drive\nKindly enter enter the purpose from above mentioned options only :\n");
  scanf("%d",&k);
  char choice[200];
  x=preference(k);
  if(x==1)
  {
  strcpy(choice,"Everyday");
  p1=everyday(user,price,choice);
  }
  if(x==2)
  {
  strcpy(choice,"Wedding");
  p2=wedding(user,price,choice);
  }
  if(x==3)
  {
  strcpy(choice,"Long Drive");
  p3=longdrive(user,price,choice);
  }
  if(x==4)
  {
   main();
  } 
  
  sleep(2);
  price=price+p1+p2+p3;
  
     
	struct User *ptr=&user;
	struct User de;
	invoice(j,x,price,ptr);
	payment(price);
	
    FILE* fptr;
	FILE* fp;
	fptr=fopen("user.bin","ab");
	fwrite (&user, sizeof(struct User), 1, fptr);
	fclose(fptr);
	}
