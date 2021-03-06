/* CSC111 Computer Science II
   Parts Database - inventory.c
   Programmers: Adam Haertter & Thomas Wolf
   Professor: Dr. Lee
   Date Created: Oct 16, 2019
   Date Updated: Oct 16, 2019
*/

#include <stdio.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {					//Defines structure for parts
   int number;
   char name[NAME_LEN+1];
   int on_hand;
}  inventory[MAX_PARTS];

int num_parts = 0;				//Number of parts currently stored

int find_part(int number);
void insert();
void search();
void update();
void print();

/*
 * main:	Prompts the user to enter an operation code,
 *		then calls a function to perform the requested
 *		action. Repeats until the user enters the
 *		command 'q'. Prints an error message if the user
 *		enters an illegal code.
 */
int main()
{
   char code;
   for(;;) {
	printf("Enter operation code: ");	//Prompts for code input
	scanf(" %c", &code);
	while(getchar() != '\n')		//Skips to the end of the line
	   ;
	switch(code) {
	   case 'i': insert();			//Runs insert() if i was inputted
		     break;
	   case 's': search();			//Runs search() if s was inputted
		     break;
	   case 'u': update();			//Runs update() if u was inputted
		     break;
	   case 'p': print();			//Runs print() if p was inputted
		     break;
	   case 'q': return 0;			//Quits program if q was inputted
	   default:  printf("Illegal code\n");	//Prints error message on invalid input
	}
	printf("\n");
   }
}

/* find_part:	Looks up a part number in the inventory
 *		array. Returns the array index if the part
 *		number is found; otherwise, returns -1.
 */
int find_part(int number)
{
   int i;

   for(i=0; i<num_parts; i++)
	if(inventory[i].number == number)	//Checks parameter against values in array
	   return i;				//Returns matching index
   return -1;					//Returns -1 if there is no match
}

/* insert:	Prompts the user for information about a new
 *		part and then inserts the part into the
 *		database. Prints an error message and returns
 *		prematurely if the part already exists or the
 *		database is full.
 */
void insert()
{
   int part_number;

   if(num_parts == MAX_PARTS) {
	printf("Database is full; can't add more parts.\n");
	return;
   }

   printf("Enter part number: ");			//Prompts user to input part number
   scanf("%d, &part_number);				//Assigns scanned value to part_number

   if(find_part(part_number) >= 0) {			//Sends part_number to find_part and sees if it exists
	printf("Part already exists.\n");
	return;
   }

   inventory{num_parts].number = part_number;
   printf("Enter part name: ");				//Prompts user to enter part name
   read_line(inventory[num_parts].name, NAME_LEN);	//Reads the product name from the line with limit NAME_LEN
   printf("Enter quantity on hand: ");			//Prompts user to enter quantity
   scanf("%d", &inventory[num_parts].on_hand);  	//Scans for input of quantity and updates database
   num_parts++;						//Increments num_parts
}

/* search:	Prompts the user to enter a part number, then
 *		looks up the part in the database. If the part
 *		exists, prints the name and quantity on hand;
 *		if not, prints an error message.
 */
void search()
{
   int i, number;

   printf("Enter part number: ");				//Prompts user to enter a part number
   scanf("%d", &number);					//Scans input and assigns to number
   i = find_part(number);					//Finds number id and stores it to i
   if(i>=0) {
	printf("Part name: %s\n", inventory[i].name);		//Prints part name, if found
	printf("Quantity on hand: %d\n", inventory[i].on_hand);	//Prints quantity, if found
   } else
	printf("Part not found.\n");
}

/* update:	Prompts the user to enter a part number.
		Prints an error message if the part doesn't
		exist; otherwise, prompts the suer to enter
		change in quantity on hand and updates the
		database.
 */
void update()
{
   int i, number, change;

   printf("Enter part number: ");				//Prompts user to enter part number
   scanf("%d", &number);					//Scans input and assigns to number
   i - find_part(number);					//Assigns index to int i using find_part
   if(i >= 0) {							//If the part exists,
	printf("Enter change in quantity on hand: ");		//Propts user to enter change in quantity
	scanf("%d", &change);					//Scans input and assigns to change variable
	inventory[i].on_hand += change;				//Adds change to the quantity variable
   } else
	printf("Part not found.\n");				//Prints error message if part doesn't exist
}

/* print:	Prints a listing of all parts in the database,
		showing the part number, part name, and
		quantity on hand. Parts are printed in the
		order in which they were entered into the
		database.
 */
void print()
{
   int i;

   pintf("Part Number	Part Name			"	//Prints organizer headings
	"Quantity on Hand\n");
   for(i=0; i<num_parts; i++)
	printf("%7d	%-25s%11d\n", inventory[i].number,	//Prints contents of each part in inventory
		inventory[i].name, inventory[i].on_hand);
}
