#include <stdlib.h>
#include <iostream>
/*
 Include directly the different
 headers from cppconn/ and mysql_driver.h + mysql_util.h
 (and mysql_connection.h). This will reduce your build time!
*/
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
using namespace std;

// This program retrieves all of the musicians

// Compile:
// g++ -I/usr/include eventplanning.cpp -o eventplanning -I /usr/local/lib -lmysqlcppconn
// 
// Execute:
// ./eventplanning
// 
 sql::Driver *driver;
 sql::Connection *con;
 sql::Statement *stmt;
 sql::ResultSet *res;
 sql::PreparedStatement  *prep_stmt;


void findalltables();
void manageinserts();
void managedeletes();
void findbycoor();
void findbyid();
void joinacrew();
void altercontracts();
void countweddingphotographers();

int main(void)
{

try {

   
 /* Create a connection */
 driver = get_driver_instance();

  
con = driver->connect("tcp://127.0.0.1:3306", "root", "");

/* Connect to the MySQL music database */
    
 con->setSchema("eventplanning");
 //stmt = con->createStatement();
    
 int option = 10;

 while (option != 9) {
     
     cout << endl;
     cout << "1. Insert to a Table" << endl;
     cout << "2. Find by id" << endl;
     cout << "3. Find a Event by coordinators" << endl;
     cout << "4. Show Tables" << endl;
     cout << "5. Delete from a Table" << endl;
     cout << "6. Perform a Join" << endl;
     cout << "7. Alter the contracts" << endl;
     cout << "8. Count the photograpghers that photograph weddings" << endl;
     cout << "9. Exit" << endl;
    
     
     cout << "Choice : ";
     cin >> option;
     
     switch(option) {
        
         case 1: manageinserts();
                 break;

         case 2: findbyid();
                 break;

         case 3: findbycoor();
                 break;

         case 4: findalltables();
                 break;
            
         case 5: managedeletes();
                 break;

        case 6: joinacrew();
                break;
        
        case 7: altercontracts();
                break;
        
        case 8: countweddingphotographers();
                break;
             
     }
 }
 

 delete res;
 delete stmt;
 delete con;
} catch (sql::SQLException &e) {
 cout << "# ERR: SQLException in " << __FILE__;
 cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
 cout << "# ERR: " << e.what();
 cout << " (MySQL error code: " << e.getErrorCode();
 cout << ", SQLState: " << e.getSQLState() << " )" << endl;
}
cout << endl;
return EXIT_SUCCESS;

}

void findallevents() {
     
 stmt = con->createStatement();
 res = stmt->executeQuery("SELECT * from events");
    
 while (res->next()) {
 
 /* Access column data by alias or column name */ 
     cout << res->getString("event_id") << " ";
     cout << res->getString("event_name") << " ";
     cout << res->getString("event_date") << " ";
     cout << res->getString("event_type") << " ";
     cout << res->getString("venue_id") << " ";
     cout << res->getString("coordinator_id") << endl;
 
 }
     
}

void findallbakeries() {
     
 stmt = con->createStatement();
 res = stmt->executeQuery("SELECT * from bakeries");
    
 while (res->next()) {
 
 /* Access column data by alias or column name */ 
     cout << res->getString("store_id") << " ";
     cout << res->getString("bakery_name") << " ";
     cout << res->getString("service_offered") << " ";
     cout << res->getString("contact_info") << endl;
 
 }
}
 
void findallvenues() {
     
 stmt = con->createStatement();
 res = stmt->executeQuery("SELECT * from venues");
    
 while (res->next()) {
 
 /* Access column data by alias or column name */ 
     cout << res->getString("venue_id") << " ";
     cout << res->getString("venue_name") << " ";
     cout << res->getString("venue_location") << " ";
     cout << res->getString("capacity") << " ";
     cout << res->getString("contact_info") << endl;
 
 }
}

void findallcoor() {
     
 stmt = con->createStatement();
 res = stmt->executeQuery("SELECT * from coordinators");
    
 while (res->next()) {
 
 /* Access column data by alias or column name */ 
     cout << res->getString("coordinator_id") << " ";
     cout << res->getString("coordinator_name") << " ";
     cout << res->getString("service_offered") << " ";
     cout << res->getString("contact_info") << endl;
 
 }
}

void findallvendors() {
     
 stmt = con->createStatement();
 res = stmt->executeQuery("SELECT * from vendors");
    
 while (res->next()) {
 
 /* Access column data by alias or column name */ 
     cout << res->getString("vendor_id") << " ";
     cout << res->getString("vendor_name") << " ";
     cout << res->getString("contact_info") << endl;
 
 }
}

void findalldec() {
     
 stmt = con->createStatement();
 res = stmt->executeQuery("SELECT * from decorators");
    
 while (res->next()) {
 
 /* Access column data by alias or column name */ 
     cout << res->getString("decorator_id") << " ";
     cout << res->getString("decorator_name") << " ";
     cout << res->getString("service_offered") << " ";
     cout << res->getString("contact_information") << endl;
 
 }
}

void findallphotographers() {
     
 stmt = con->createStatement();
 res = stmt->executeQuery("SELECT * from photographers");
    
 while (res->next()) {
 
 /* Access column data by alias or column name */ 
     cout << res->getString("photographer_id") << " ";
     cout << res->getString("photographer_name") << " ";
     cout << res->getString("service_offered") << " ";
     cout << res->getString("availab") << " ";
     cout << res->getString("contact_info") << endl;
 
 }
}

void findalldressmakers() {
     
 stmt = con->createStatement();
 res = stmt->executeQuery("SELECT * from dressmaker");
    
 while (res->next()) {
 
 /* Access column data by alias or column name */ 
     cout << res->getString("dress_id") << " ";
     cout << res->getString("dressmaker_name") << " ";
     cout << res->getString("service_offered") << " ";
     cout << res->getString("availab") << " ";
     cout << res->getString("contact_info") << " ";
     cout << res->getString("dressmaker_address") << endl;
 
 }
}

void findallcontracts() {
     
 stmt = con->createStatement();
 res = stmt->executeQuery("SELECT * from contracts");
    
 while (res->next()) {
 
 /* Access column data by alias or column name */ 
     cout << res->getString("contractNum") << " ";
     cout << res->getString("event_id") << " ";
     cout << res->getString("vendor_id") << " ";
     cout << res->getString("contract_date") << " ";
     cout << res->getString("terms_conditions") << " ";
     cout << res->getString("payment_schedule") << endl;
 
 }
}

void findbyeventid() {
     
 
 int id;
    
 cout << "Enter the event ID : ";
 cin >> id;
    
 
prep_stmt = con->prepareStatement("SELECT * FROM events WHERE event_id = ?");
prep_stmt->setInt(1, id);
res = prep_stmt->executeQuery();


 while (res->next()) {

 /* Access column data by alias or column name */
     
  /* Access column data by alias or column name */ 
      cout << res->getString("event_id") << " ";
      cout << res->getString("event_name") << " ";
      cout << res->getString("event_date") << " ";
      cout << res->getString("event_type") << " ";
      cout << res->getString("venue_id") << " ";
      cout << res->getString("coordinator_id") << endl;
 
 
 }
     
}

void findbydressmaker() {
     
 
 int id;
    
 cout << "Enter the Dressmaker ID : ";
 cin >> id;
    
 
prep_stmt = con->prepareStatement("SELECT * FROM dressmaker WHERE dress_id = ?");
prep_stmt->setInt(1, id);
res = prep_stmt->executeQuery();


 while (res->next()) {

 /* Access column data by alias or column name */
     
  /* Access column data by alias or column name */ 
      cout << res->getString("dress_id") << " ";
      cout << res->getString("dressmaker_name") << " ";
      cout << res->getString("service_offered") << " ";
      cout << res->getString("availab") << " ";
      cout << res->getString("contact_info") << " ";
      cout << res->getString("dressmaker_address") << endl;
 
 
 }
     
}

void findbyvenue() {
     
 
 int id;
    
 cout << "Enter the Venue ID : ";
 cin >> id;
    
 
prep_stmt = con->prepareStatement("SELECT * FROM venues WHERE venue_id = ?");
prep_stmt->setInt(1, id);
res = prep_stmt->executeQuery();


 while (res->next()) {

 /* Access column data by alias or column name */
     
  /* Access column data by alias or column name */ 
      cout << res->getString("venue_id") << " ";
      cout << res->getString("venue_name") << " ";
      cout << res->getString("venue_location") << " ";
      cout << res->getString("capacity") << " ";
      cout << res->getString("contact_info") << endl;
 
 
 }
     
}

void findbycoor() {
     
 
 int id;
    
 cout << "Enter the coordinator ID : ";
 cin >> id;
    
 
prep_stmt = con->prepareStatement("SELECT event_id, event_name, event_date, event_type, venue_id, coordinator_id FROM events WHERE coordinator_id = ?");
prep_stmt->setInt(1, id);
res = prep_stmt->executeQuery();


 while (res->next()) {

 /* Access column data by alias or column name */
     
  /*Access column data by alias or column name */
      cout << res->getString("event_id") << " ";
      cout << res->getString("event_name") << " ";
      cout << res->getString("event_date") << " ";
      cout << res->getString("event_type") << " ";
      cout << res->getString("venue_id") << " ";
      cout << res->getString("coordinator_id") << endl;
 
 
 }


 }


 void insertevent() {

 string  event_name, event_date, event_type;  
 int event_id,venue_id,coordinator_id;

    
 cout << "Event ID : ";
 cin >> event_id;
 
 cout << "Event Name : ";
 cin.ignore(); 
 getline(cin, event_name);

 cout << "Event Date YYYY-MM-DD : ";
 cin >> event_date;

 cout << "Event Type : ";
 cin >> event_type;

 cout << "Venue ID : ";
 cin >> venue_id;
 
 cout << "Coordinator ID : ";
 cin >> coordinator_id;
 
prep_stmt = con->prepareStatement("INSERT INTO events (event_id, event_name, event_date, event_type, venue_id, coordinator_id) " \
                                   "VALUES(?,?,?,?,?,?) ");
                                                                 
                                   
prep_stmt->setInt(1, event_id);
prep_stmt->setString(2, event_name);
prep_stmt->setString(3, event_date);
prep_stmt->setString(4, event_type);
prep_stmt->setInt(5, venue_id);
prep_stmt->setInt(6, coordinator_id);

prep_stmt->execute();

 }

 void insertbakery() {

 string bakery_name, service_offered, contact_info;  
 int store_id;

    
 cout << "Store ID : ";
 cin >> store_id;
 
 cout << "Bakery Name : ";
 cin.ignore(); 
 getline(cin, bakery_name);

 cout << "Services Offered : ";
 cin >> service_offered;

 cout << "Contact XXX-XXX-XXXX: ";
 cin >> contact_info;

 
prep_stmt = con->prepareStatement("INSERT INTO bakeries (store_id, bakery_name, service_offered, contact_info) " \
                                   "VALUES(?,?,?,?) ");
                                                                 
                                   
prep_stmt->setInt(1, store_id);
prep_stmt->setString(2, bakery_name);
prep_stmt->setString(3, service_offered);
prep_stmt->setString(4, contact_info);

prep_stmt->execute();

 }

 void insertvenue() {

 string venue_name, venue_location, contact_info;  
 int venue_id, capacity;

    
 cout << "Venue ID : ";
 cin >> venue_id;
 
 cout << "Venue Name : ";
 cin.ignore(); 
 getline(cin, venue_name);

 cout << "Capacity : ";
 cin >> capacity;

 cout << "Venue's Location : ";
 cin >> venue_location;

 cout << "Contact XXX-XXX-XXXX: ";
 cin >> contact_info;

 
prep_stmt = con->prepareStatement("INSERT INTO venues (venue_id, venue_name, venue_location,capacity, contact_info) " \
                                   "VALUES(?,?,?,?,?) ");
                                                                 
                                   
prep_stmt->setInt(1, venue_id);
prep_stmt->setString(2, venue_name);
prep_stmt->setString(3, venue_location);
prep_stmt->setInt(4, capacity);
prep_stmt->setString(5, contact_info);

prep_stmt->execute();

 }

void deleteevent() {
    int id;
    cout << "Enter the event ID to delete: ";
    cin >> id;

    prep_stmt = con->prepareStatement("DELETE FROM events WHERE event_id = ?");
    prep_stmt->setInt(1, id);
    prep_stmt->executeUpdate();

    cout << "Event with ID " << id << " has been deleted." << endl;
}

void deletebakery() {
    int id;
    cout << "Enter the bakery ID to delete: ";
    cin >> id;

    prep_stmt = con->prepareStatement("DELETE FROM bakeries WHERE store_id = ?");
    prep_stmt->setInt(1, id);
    prep_stmt->executeUpdate();

    cout << "Bakery with ID " << id << " has been deleted." << endl;
}

void deletevenue() {
    int id;
    cout << "Enter the Venue ID to delete: ";
    cin >> id;

    prep_stmt = con->prepareStatement("DELETE FROM venues WHERE venue_id = ?");
    prep_stmt->setInt(1, id);
    prep_stmt->executeUpdate();

    cout << "Venue with ID " << id << " has been deleted." << endl;
}


void joineventsandvenues() {
    // Prepare the SQL query to join events and venues based on venue_id
    prep_stmt = con->prepareStatement("SELECT events.event_id, events.event_name, events.event_date, events.event_type, events.venue_id, events.coordinator_id, venues.venue_name, venues.venue_location, venues.capacity, venues.contact_info FROM events JOIN venues ON events.venue_id = venues.venue_id");
    res = prep_stmt->executeQuery();

    // Display the joined data
    while (res->next()) {
      cout << res->getString("event_id") << " ";
      cout << res->getString("event_name") << " ";
      cout << res->getString("event_date") << " ";
      cout << res->getString("event_type") << " ";
      cout << res->getString("venue_id") << " ";
      cout << res->getString("coordinator_id") << " ";

      cout << res->getString("venue_name") << " ";
      cout << res->getString("venue_location") << " ";
      cout << res->getInt("capacity") << " ";
      cout << res->getString("contact_info") << endl;

      cout << endl;
    }
}

void joineventsandcoor() {
    // Prepare the SQL query to join events and venues based on venue_id
    prep_stmt = con->prepareStatement("SELECT events.event_id, events.event_name, events.event_date, events.event_type, events.venue_id, events.coordinator_id, coordinators.coordinator_name, coordinators.service_offered, coordinators.contact_info FROM events JOIN coordinators ON events.coordinator_id = coordinators.coordinator_id");
    res = prep_stmt->executeQuery();

    // Display the joined data
    while (res->next()) {
        cout << res->getInt("event_id") << " ";
        cout << res->getString("event_name") << " ";
        cout << res->getString("event_date") << " ";
        cout << res->getString("event_type") << " ";
        cout << res->getInt("venue_id") << " ";
        cout << res->getInt("coordinator_id") << " ";
        cout << res->getString("coordinator_name") << " ";
        cout << res->getString("service_offered") << " ";
        cout << res->getString("contact_info") << endl;

        cout << endl;
    }
}

void joincontractandvendor() {
    // Prepare the SQL query to join events and venues based on venue_id
    prep_stmt = con->prepareStatement("SELECT contracts.contractNum, contracts.event_id, contracts.vendor_id, contracts.contract_date, contracts.terms_conditions, contracts.payment_schedule, vendors.vendor_name, vendors.contact_info FROM contracts JOIN vendors ON contracts.vendor_id = vendors.vendor_id");
    res = prep_stmt->executeQuery();

    // Display the joined data
    while (res->next()) {
        cout << res->getInt("contractNum") << " ";
        cout << res->getInt("event_id") << " ";
        cout << res->getInt("vendor_id") << " ";
        cout << res->getString("contract_date") << " ";
        cout << res->getString("terms_conditions") << " ";
        cout << res->getString("payment_schedule") << " ";

        cout << res->getString("vendor_name") << " ";
        cout << res->getString("contact_info") << endl;

        cout << endl;
    }
}

void joincontractandevents() {
    // Prepare the SQL query to join events and venues based on venue_id
    prep_stmt = con->prepareStatement("SELECT contracts.contractNum, contracts.event_id, contracts.vendor_id, contracts.contract_date, contracts.terms_conditions, contracts.payment_schedule, events.event_name, events.event_date, events.event_type, events.venue_id, events.coordinator_id FROM contracts JOIN events ON contracts.event_id = events.event_id");
    res = prep_stmt->executeQuery();

    // Display the joined data
    while (res->next()) {
        cout << res->getInt("contractNum") << " ";
        cout << res->getInt("event_id") << " ";
        cout << res->getInt("vendor_id") << " ";
        cout << res->getString("contract_date") << " ";
        cout << res->getString("terms_conditions") << " ";
        cout << res->getString("payment_schedule") << " ";

        cout << res->getString("event_name") << " ";
        cout << res->getString("event_date") << " ";
        cout << res->getString("event_type") << " ";
        cout << res->getInt("venue_id") << " ";
        cout << res->getInt("coordinator_id") << endl;

        cout << endl;
    }
}

void altercontracts() {
    int contractNum;
    string new_payment_schedule;

    // Get the contract number and the new payment schedule information from the user
    cout << "Enter the contract number you want to alter: ";
    cin >> contractNum;
    cout << "Enter the new payment schedule information: ";
    cin.ignore(); // Ignore the newline character left in the input buffer
    getline(cin, new_payment_schedule);

    // Prepare the SQL statement to update the contract
    prep_stmt = con->prepareStatement("UPDATE contracts SET payment_schedule = ? WHERE contractNum = ?");
    prep_stmt->setString(1, new_payment_schedule);
    prep_stmt->setInt(2, contractNum);

    // Execute the update statement
    int rowsAffected = prep_stmt->executeUpdate();

    if (rowsAffected > 0) {
        cout << "Contract with number " << contractNum << " has been successfully altered." << endl;
    } else {
        cout << "No contract found with number " << contractNum << "." << endl;
    }

}

void countweddingphotographers() {
    prep_stmt = con->prepareStatement("SELECT COUNT(*) AS num_photographers FROM photographers");
    res = prep_stmt->executeQuery();

    while (res->next()) 
    {
      int numPhotographers = res->getInt("num_photographers");
      cout << endl << "Number of photographers: " << numPhotographers << endl;
    }
}

void manageinserts() {
    int option1 = 5;
    while (option1 !=4) 
  {
      cout << endl;
      cout << "1. Add an Event" << endl;
      cout << "2. Add an Bakery" << endl;
      cout << "3. Add an Venue" << endl;
      cout << "4. Back" << endl << endl;
      
      cout << "Choice: ";
      cin >> option1;

      switch (option1) 
      {
            case 1:
                insertevent();
                break;
            case 2:
                insertbakery();
                break;
            case 3:
                insertvenue();
                break;
      }
  }
}

void managedeletes() {
    int option1 = 5;
    while (option1 !=4) 
  {
      cout << endl;
      cout << "1. Delete an Event" << endl;
      cout << "2. Delete a Bakery Store" << endl;
      cout << "3. Delete a Venue" << endl;
      cout << "4. Back" << endl << endl;
      
      cout << "Choice: ";
      cin >> option1;

      switch (option1) 
      {
            case 1:
                deleteevent();
                break;
            case 2:
                deletebakery();
                break;
            case 3:
                deletevenue();
                break;
      }
  }
}

void findbyid() {
      int option1 = 5;
    while (option1 !=4) 
  {
      cout << endl;
      cout << "1. Find an Event" << endl;
      cout << "2. Find Dressmaker" << endl;
      cout << "3. Find a Venue" << endl;
      cout << "4. Back" << endl << endl;
      
      cout << "Choice: ";
      cin >> option1;

      switch (option1) 
      {
            case 1:
                findbyeventid();
                break;
            case 2:
                findbydressmaker();
                break;
            case 3:
                findbyvenue();
                break;
      }
  }
}

void joinacrew() {
      int option1 = 6;
    while (option1 !=5) 
  {
      cout << endl;
      cout << "Which tables do you want joined?" << endl;
      cout << "1. Events and Venues " << endl;
      cout << "2. Events and Coordinators" << endl;
      cout << "3. Contracts and Vendors" << endl;
      cout << "4. Contracts and Events" << endl;
      cout << "5. Back" << endl << endl;

      cout << "Choice: ";
      cin >> option1;

      switch (option1) 
      {
            case 1:
                joineventsandvenues();
                break;
            case 2:
                joineventsandcoor();
                break;
            case 3:
                joincontractandvendor();
                break;
            case 4:
                joincontractandevents();
                break;
      }
  }
}

void findalltables() {
    int option1 = 11;
    while (option1 !=10) 
  {
      cout << endl;
      cout << "Choose which table to view?" << endl;
      cout << "1. Events " << endl;
      cout << "2. Coordinators" << endl;
      cout << "3. Vendors" << endl;
      cout << "4. Venues" << endl;
      cout << "5. Decorators" << endl;
      cout << "6. Photograpghers" << endl;
      cout << "7. Dressmaker" << endl;
      cout << "8. Bakeries" << endl;
      cout << "9. Contracts" << endl;
      cout << "10. Back" << endl << endl;

      cout << "Choice: ";
      cin >> option1;

      switch (option1) 
      {
            case 1:
                findallevents();
                break;
            case 2:
                findallcoor();
                break;
            case 3:
                findallvendors();
                break;
            case 4:
                findallvenues();
                break;
            case 5:
                findalldec();
                break;
            case 6:
                findallphotographers();
                break;
            case 7:
                findalldressmakers();
                break;
            case 8:
                findallbakeries();
                break;
            case 9:
                findallcontracts();
                break;
      }
  }
}
