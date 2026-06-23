#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook) 
{
    // Sort contacts based on the chosen criteria
    printf("1. Sort by Name\n2. Sort my Phone\n3. Sort by Email\n4. Exit\n");
    int sortchoice;
    printf("Enter your choice for sorting: ");
    scanf("%d", &sortchoice);
    switch(sortchoice)
    {
        case 1:
            for(int i = 0 ; i < addressBook->contactCount-1; i++)
            {
                for(int j = 0 ; j < addressBook->contactCount-i-1 ; j++)
                {
                    if(strcmp(addressBook->contacts[j].name, addressBook->contacts[j+1].name) > 0)
                    {
                        Contact temp = addressBook->contacts[j];
                        addressBook->contacts[j] = addressBook->contacts[j + 1];
                        addressBook->contacts[j + 1] = temp;
                    }
                }
            }
            break;
        case 2:
            for(int i = 0 ; i < addressBook->contactCount-1; i++)
            {
                for(int j = 0 ; j < addressBook->contactCount-i-1 ; j++)
                {
                    if(strcmp(addressBook->contacts[j].phone, addressBook->contacts[j+1].phone) > 0)
                    {
                        Contact temp = addressBook->contacts[j];
                        addressBook->contacts[j] = addressBook->contacts[j + 1];
                        addressBook->contacts[j + 1] = temp;
                    }
                }
            }
            break;
        case 3:
            for(int i = 0 ; i < addressBook->contactCount-1; i++)
            {
                for(int j = 0 ; j < addressBook->contactCount-i-1 ; j++)
                {
                    if(strcmp(addressBook->contacts[j].email, addressBook->contacts[j+1].email) > 0)
                    {
                        Contact temp = addressBook->contacts[j];
                        addressBook->contacts[j] = addressBook->contacts[j + 1];
                        addressBook->contacts[j + 1] = temp;
                    }
                }
            }
            break;
        case 4:
            return;
    }
    printf("\nContacts List:\n");
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        printf("Name: %s, Phone: %s, Email: %s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    printf("Enter the Name: ");
    scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].name);
    printf("Enter the Phone number: ");
    scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].phone);
    printf("Enter the Email Id: ");
    scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].email);
    addressBook->contactCount++;
}

int searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    printf("1. Search by Name\n2. Search by Phone\n3. Search by Email\n4. Exit\n");
    int choice;
    printf("Enter your choice for Searching: ");
    scanf("%d", &choice);
    char name[50], phone[15], email[50];
    switch(choice)
    {
        case 1:
            printf("Enter the name: ");
            scanf(" %[^\n]", name);

            for(size_t i = 0 ; i < addressBook -> contactCount; i++)
            {
                if(strcasecmp(addressBook->contacts[i].name, name) == 0)
                {
                    printf("Name: %s, Phone: %s, Email: %s\n",
                    addressBook->contacts[i].name,
                    addressBook->contacts[i].phone,
                    addressBook->contacts[i].email);   
                    return i;
                }
            }
            return -2;
            break;
        case 2: 
            printf("Enter the Phone number: ");
            scanf(" %[^\n]", phone);

            for(size_t i = 0 ; i < addressBook -> contactCount; i++)
            {
                if(strcasecmp(addressBook->contacts[i].phone, phone) == 0)
                {
                    printf("Name: %s, Phone: %s, Email: %s\n",
                    addressBook->contacts[i].name,
                    addressBook->contacts[i].phone,
                    addressBook->contacts[i].email);   
                    return i;
                }
            }
            return -2;
            break;
        case 3:
            printf("Enter the Email ID: ");
            scanf(" %[^\n]", email);

            for(size_t i = 0 ; i < addressBook -> contactCount; i++)
            {
                if(strcasecmp(addressBook->contacts[i].email, email) == 0)
                {
                    printf("Name: %s, Phone: %s, Email: %s\n",
                    addressBook->contacts[i].name,
                    addressBook->contacts[i].phone,
                    addressBook->contacts[i].email);   
                    return i;
                }
            }
            return -2;
            break;
        case 4:
            return -1;
    }
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    printf("1. Edit Name\n2. Edit Phone\n3. Edit Email\n4. Exit\n");
    int choice;
    printf("Enter your choice for Editing: ");
    scanf("%d", &choice);

    int index = searchContact(addressBook);

    if(index == -1)
        printf("Exit from Search contact\n");
    else if(index == -2)
        printf("Contact not found\n");
    else
    {
        switch(choice)
        {
            case 1:
                printf("Enter the edit name: ");
                scanf(" %[^\n]", addressBook->contacts[index].name);
            break;
            case 2:
                printf("Enter the edit phone number: ");
                scanf(" %[^\n]", addressBook->contacts[index].phone);
            break;
            case 3:
                printf("Enter the edit email: ");
                scanf(" %[^\n]", addressBook->contacts[index].email);
            break;
            case 4:
                return;
        }
    }
}
void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */

    int index = searchContact(addressBook);

    if(index == -1)
        printf("Exit from Search contact\n");
    else if(index == -2)
        printf("Contact not found\n");
    else
    {
        for(int i = index ; i < addressBook->contactCount ; i++)
           addressBook->contacts[i] = addressBook->contacts[i+1];
        addressBook->contactCount--;
    }
}
