#include "HotelSystem.h"

// Constructor
HotelSystem::HotelSystem() {
    hotelCount = 0;
    travelerCount = 0;
}

// Load users from file (ONE-TIME READ)
void HotelSystem::loadUsersFromFile(const char* filename) {
    ifstream inputFile(filename);
    
    if (!inputFile.is_open()) {
        cout << "Error: Could not open " << filename << "\n";
        return;
    }
    
    int userID;
    char name[100], email[100], city[50];
    int points;
    char membership[20];
    
    // Read users exactly once at startup
    while (inputFile >> userID >> name >> email >> city >> points >> membership) {
        if (travelerCount < 100) {
            travelers[travelerCount].setTravelerData(userID, name, email, city, points, membership);
            travelerCount++;
        }
    }
    
    inputFile.close();
    cout << "Loaded " << travelerCount << " travelers from file.\n";
}

// Load reviews from file (ONE-TIME READ)
void HotelSystem::loadReviewsFromFile(const char* filename) {
    ifstream inputFile(filename);
    
    if (!inputFile.is_open()) {
        cout << "Error: Could not open " << filename << "\n";
        return;
    }
    
    int reviewID, hotelID, userID, rating;
    char comment[500];
    
    // Read reviews exactly once at startup
    while (inputFile >> reviewID >> hotelID >> userID >> rating) {
        inputFile.ignore();
        inputFile.getline(comment, 500);
        
        // Create hotel if not exists
        int hotelIndex = findHotelIndex(hotelID);
        if (hotelIndex == -1 && hotelCount < 50) {
            char defaultName[100] = "Hotel ";
            char defaultLoc[100] = "Location ";
            hotelIndex = hotelCount;
            hotels[hotelCount].setHotelData(hotelID, defaultName, defaultLoc, 5);
            hotelCount++;
        }
        
        // Add review to hotel
        if (hotelIndex != -1) {
            Review review;
            review.setReviewData(reviewID, hotelID, userID, rating, comment);
            hotels[hotelIndex].addReview(review);
            
            // Add review to traveler
            int travelerIndex = findTravelerIndex(userID);
            if (travelerIndex != -1) {
                travelers[travelerIndex].addReview(review);
            }
        }
    }
    
    inputFile.close();
    cout << "Loaded reviews and associated with " << hotelCount << " hotels.\n";
}

// Save reports to file (ONE-TIME WRITE)
void HotelSystem::saveReportsToFile(const char* filename) {
    ofstream outputFile(filename);
    
    if (!outputFile.is_open()) {
        cout << "Error: Could not open " << filename << " for writing.\n";
        return;
    }
    
    outputFile << "=== HOTEL REVIEW SYSTEM REPORT ===\n\n";
    
    outputFile << "HOTELS RANKING:\n";
    for (int i = 0; i < hotelCount; i++) {
        outputFile << hotels[i];
    }
    
    outputFile << "\n\nTOP REVIEWERS:\n";
    for (int i = 0; i < travelerCount; i++) {
        if (travelers[i].getReviewCount() > 0) {
            outputFile << "Traveler: " << travelers[i].getUserName() 
                      << " | Reviews: " << travelers[i].getReviewCount() 
                      << " | Avg Rating: " << travelers[i].getAverageRating() << "\n";
        }
    }
    
    outputFile.close();
    cout << "Report saved to " << filename << "\n";
}

// Find hotel by ID
void HotelSystem::findHotelByID(int hotelID) {
    int index = findHotelIndex(hotelID);
    if (index != -1) {
        hotels[index].displayHotelInfo();
        hotels[index].displayAllReviews();
    } else {
        cout << "Hotel not found.\n";
    }
}

// Display all hotels
void HotelSystem::displayAllHotels() const {
    cout << "\n=== ALL HOTELS ===\n";
    for (int i = 0; i < hotelCount; i++) {
        hotels[i].displayHotelInfo();
    }
}

// Find traveler by ID
void HotelSystem::findTravelerByID(int travelerID) {
    int index = findTravelerIndex(travelerID);
    if (index != -1) {
        travelers[index].displayUser();
    } else {
        cout << "Traveler not found.\n";
    }
}

// Display all travelers
void HotelSystem::displayAllTravelers() const {
    cout << "\n=== ALL TRAVELERS ===\n";
    for (int i = 0; i < travelerCount; i++) {
        travelers[i].displayUser();
    }
}

// Display traveler profile
void HotelSystem::displayTravelerProfile(int travelerID) {
    int index = findTravelerIndex(travelerID);
    if (index != -1) {
        travelers[index].displayUser();
        travelers[index].displayAllReviews();
    } else {
        cout << "Traveler not found.\n";
    }
}

// Property deep dive operation
void HotelSystem::displayPropertyDeepDive() {
    cout << "\n=== PROPERTY DEEP-DIVE ===\n";
    cout << "Enter Hotel ID: ";
    int hotelID;
    cin >> hotelID;
    
    findHotelByID(hotelID);
}

// Traveler profile menu operation
void HotelSystem::displayTravelerProfileMenu() {
    cout << "\n=== TRAVELER PROFILE ===\n";
    cout << "Enter Traveler ID: ";
    int travelerID;
    cin >> travelerID;
    
    displayTravelerProfile(travelerID);
}

// Top pick matcher operation
void HotelSystem::displayTopPickMatcher() {
    cout << "\n=== TOP PICK MATCHER ===\n";
    cout << "1. Find Highest Rated Hotel\n";
    cout << "2. Rank All Hotels\n";
    cout << "Enter choice: ";
    int choice;
    cin >> choice;
    
    if (choice == 1) {
        findHighestRatedHotel();
    } else if (choice == 2) {
        rankAllHotels();
    } else {
        cout << "Invalid choice.\n";
    }
}

// Top reviewers operation (creative implementation)
void HotelSystem::displayTopReviewers() {
    cout << "\n=== TOP REVIEWERS ===\n";
    
    // Bubble sort to find top reviewers by loyalty points
    Traveler temp;
    for (int i = 0; i < travelerCount - 1; i++) {
        for (int j = 0; j < travelerCount - i - 1; j++) {
            // Using operator overloading to compare
            if (travelers[j] < travelers[j + 1]) {
                temp = travelers[j];
                travelers[j] = travelers[j + 1];
                travelers[j + 1] = temp;
            }
        }
    }
    
    cout << "Top 5 Reviewers by Loyalty Points:\n";
    int limit = (travelerCount < 5) ? travelerCount : 5;
    for (int i = 0; i < limit; i++) {
        cout << (i + 1) << ". " << travelers[i].getUserName() 
             << " - Points: " << travelers[i].getLoyaltyPoints() 
             << " | Reviews: " << travelers[i].getReviewCount() << "\n";
    }
}

// Find highest rated hotel
void HotelSystem::findHighestRatedHotel() const {
    if (hotelCount == 0) {
        cout << "No hotels found.\n";
        return;
    }
    
    int maxIndex = 0;
    for (int i = 1; i < hotelCount; i++) {
        // Using operator overloading to compare
        if (hotels[i] > hotels[maxIndex]) {
            maxIndex = i;
        }
    }
    
    cout << "\n*** HIGHEST RATED HOTEL ***\n";
    cout << hotels[maxIndex];
    hotels[maxIndex].displayAllReviews();
}

// Rank all hotels
void HotelSystem::rankAllHotels() const {
    cout << "\n=== HOTEL RANKING ===\n";
    
    // Create a copy array for sorting
    Hotel tempHotels[50];
    for (int i = 0; i < hotelCount; i++) {
        tempHotels[i] = hotels[i];
    }
    
    // Bubble sort by average rating
    Hotel temp;
    for (int i = 0; i < hotelCount - 1; i++) {
        for (int j = 0; j < hotelCount - i - 1; j++) {
            if (tempHotels[j + 1] > tempHotels[j]) {
                temp = tempHotels[j];
                tempHotels[j] = tempHotels[j + 1];
                tempHotels[j + 1] = temp;
            }
        }
    }
    
    for (int i = 0; i < hotelCount; i++) {
        cout << (i + 1) << ". ";
        cout << tempHotels[i];
    }
}

// Utility: Find hotel index
int HotelSystem::findHotelIndex(int hotelID) const {
    for (int i = 0; i < hotelCount; i++) {
        if (hotels[i].getHotelID() == hotelID) {
            return i;
        }
    }
    return -1;
}

// Utility: Find traveler index
int HotelSystem::findTravelerIndex(int travelerID) const {
    for (int i = 0; i < travelerCount; i++) {
        if (travelers[i].getUserID() == travelerID) {
            return i;
        }
    }
    return -1;
}

// Add manual review
void HotelSystem::addManualReview() {
    cout << "\n=== ADD MANUAL REVIEW ===\n";
    int reviewID, hotelID, userID, rating;
    char comment[500];
    
    cout << "Enter Review ID: ";
    cin >> reviewID;
    cout << "Enter Hotel ID: ";
    cin >> hotelID;
    cout << "Enter User ID: ";
    cin >> userID;
    cout << "Enter Rating (1-5): ";
    cin >> rating;
    cin.ignore();
    cout << "Enter Comment: ";
    cin.getline(comment, 500);
    
    Review review;
    review.setReviewData(reviewID, hotelID, userID, rating, comment);
    
    int hotelIndex = findHotelIndex(hotelID);
    if (hotelIndex != -1) {
        hotels[hotelIndex].addReview(review);
        cout << "Review added successfully!\n";
    } else {
        cout << "Hotel not found.\n";
    }
}

// Display main menu
void HotelSystem::displayMainMenu() {
    cout << "\n========== HOTEL REVIEW SYSTEM ==========\n";
    cout << "1. Property Deep-Dive (Find & Summarize Reviews)\n";
    cout << "2. Traveler Profile (View Traveler Info & Reviews)\n";
    cout << "3. Top-Pick Matcher (Find Highest-Rated Hotel)\n";
    cout << "4. Top Reviewers (View Top Travelers by Loyalty)\n";
    cout << "5. Display All Hotels\n";
    cout << "6. Display All Travelers\n";
    cout << "7. Add Manual Review\n";
    cout << "8. Save Reports & Exit\n";
    cout << "=========================================\n";
    cout << "Enter your choice: ";
}

// Main system run method
void HotelSystem::run() {
    loadUsersFromFile("Users.txt");
    loadReviewsFromFile("Reviews.txt");
    
    int choice;
    bool running = true;
    
    while (running) {
        displayMainMenu();
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1:
                displayPropertyDeepDive();
                break;
            case 2:
                displayTravelerProfileMenu();
                break;
            case 3:
                displayTopPickMatcher();
                break;
            case 4:
                displayTopReviewers();
                break;
            case 5:
                displayAllHotels();
                break;
            case 6:
                displayAllTravelers();
                break;
            case 7:
                addManualReview();
                break;
            case 8:
                saveReportsToFile("HotelReview_Report.txt");
                running = false;
                cout << "System shut down. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}