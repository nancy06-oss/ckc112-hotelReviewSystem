#include "HotelSystem.h"

// Constructor - initializes system with zero hotels and travelers
HotelSystem::HotelSystem() {
    hotelCount = 0;
    travelerCount = 0;
}

// Load users from file (ONE-TIME READ at startup)
// File format: UserID | Name | State | Email | Membership | Points
void HotelSystem::loadUsersFromFile(const char* filename) {
    ifstream inputFile(filename);
    
    if (!inputFile.is_open()) {
        cout << "Error: Could not open " << filename << " for reading.\n";
        return;
    }
    
    char userID[10], name[100], state[50], email[100];
    char membership[20];
    int points;
    
    // Read users exactly once at startup
    // Processing logic: No file-reading loops with logic - all logic in class methods
    while (inputFile >> userID >> name >> state >> email >> membership >> points) {
        if (travelerCount < 100) {
            travelers[travelerCount].setTravelerData(userID, name, state, email, membership, points);
            travelerCount++;
        }
    }
    
    inputFile.close();
    cout << "[SYSTEM] Loaded " << travelerCount << " travelers from " << filename << "\n";
}

// Load reviews from file (ONE-TIME READ at startup)
// File format: UserID | Rating | Comment | HotelName
void HotelSystem::loadReviewsFromFile(const char* filename) {
    ifstream inputFile(filename);
    
    if (!inputFile.is_open()) {
        cout << "Error: Could not open " << filename << " for reading.\n";
        return;
    }
    
    char userID[10], hotelName[100];
    char comment[500];
    int rating;
    
    // Read reviews exactly once at startup
    while (inputFile >> userID >> rating) {
        inputFile.ignore();  // Ignore tab character
        inputFile.getline(comment, 500, '\t');  // Read until tab
        inputFile.getline(hotelName, 100);      // Read until newline
        
        // Create hotel if not exists
        int hotelIndex = findHotelIndex(hotelName);
        if (hotelIndex == -1 && hotelCount < 20) {
            hotelIndex = hotelCount;
            hotels[hotelCount].setHotelData(hotelName);
            hotelCount++;
        }
        
        // Add review to hotel
        if (hotelIndex != -1) {
            Review review;
            review.setReviewData(rating, comment, hotelName);
            hotels[hotelIndex].addReview(review);
            
            // Add review to traveler
            int travelerIndex = findTravelerIndex(userID);
            if (travelerIndex != -1) {
                travelers[travelerIndex].addReview(review);
            }
        }
    }
    
    inputFile.close();
    cout << "[SYSTEM] Loaded reviews and processed " << hotelCount << " unique hotels from " << filename << "\n";
}

// Save reports to file (ONE-TIME WRITE before termination)
void HotelSystem::saveReportsToFile(const char* filename) {
    ofstream outputFile(filename);
    
    if (!outputFile.is_open()) {
        cout << "Error: Could not open " << filename << " for writing.\n";
        return;
    }
    
    outputFile << "\n=========== HOTEL REVIEW SYSTEM - FINAL REPORT ==========\n\n";
    
    outputFile << "--- HOTEL RANKINGS BY AVERAGE RATING ---\n";
    for (int i = 0; i < hotelCount; i++) {
        outputFile << hotels[i];
    }
    
    outputFile << "\n--- TOP REVIEWERS (By Loyalty Points) ---\n";
    for (int i = 0; i < travelerCount; i++) {
        if (travelers[i].getReviewCount() > 0) {
            outputFile << "Traveler: " << travelers[i].getUserName() 
                      << " (" << travelers[i].getUserID() << ")"
                      << " | Loyalty Points: " << travelers[i].getLoyaltyPoints()
                      << " | Reviews Written: " << travelers[i].getReviewCount() 
                      << " | Avg Rating Given: " << travelers[i].getAverageRating() << "/5\n";
        }
    }
    
    outputFile << "\n========== END OF REPORT ==========\n";
    outputFile.close();
    cout << "[SYSTEM] Report saved to " << filename << "\n";
}

// Find hotel by name and display its information
void HotelSystem::findHotelByName(const char* hotelName) {
    int index = findHotelIndex(hotelName);
    if (index != -1) {
        hotels[index].displayHotelInfo();
        hotels[index].displayAllReviews();
    } else {
        cout << "Hotel '" << hotelName << "' not found in system.\n";
    }
}

// Display summary of all hotels
void HotelSystem::displayAllHotels() const {
    cout << "\n=== ALL HOTELS IN SYSTEM ===\n";
    if (hotelCount == 0) {
        cout << "No hotels loaded.\n";
        return;
    }
    for (int i = 0; i < hotelCount; i++) {
        cout << (i + 1) << ". ";
        hotels[i].displayHotelInfo();
    }
}

// Find traveler by ID and display their information
void HotelSystem::findTravelerByID(const char* travelerID) {
    int index = findTravelerIndex(travelerID);
    if (index != -1) {
        travelers[index].displayUser();
    } else {
        cout << "Traveler '" << travelerID << "' not found in system.\n";
    }
}

// Display summary of all travelers
void HotelSystem::displayAllTravelers() const {
    cout << "\n=== ALL TRAVELERS IN SYSTEM ===\n";
    if (travelerCount == 0) {
        cout << "No travelers loaded.\n";
        return;
    }
    for (int i = 0; i < travelerCount; i++) {
        cout << (i + 1) << ". ";
        travelers[i].displayUser();
    }
}

// Display detailed traveler profile with all their reviews
void HotelSystem::displayTravelerProfile(const char* travelerID) {
    int index = findTravelerIndex(travelerID);
    if (index != -1) {
        travelers[index].displayUser();
        travelers[index].displayAllReviews();
    } else {
        cout << "Traveler '" << travelerID << "' not found in system.\n";
    }
}

// Property deep dive operation - search hotel by name
void HotelSystem::displayPropertyDeepDive() {
    cout << "\n=== PROPERTY DEEP-DIVE ===\n";
    cout << "Available Hotels:\n";
    displayAllHotels();
    cout << "\nEnter Hotel Name: ";
    char hotelName[100];
    cin.ignore();
    cin.getline(hotelName, 100);
    
    findHotelByName(hotelName);
}

// Traveler profile menu operation
void HotelSystem::displayTravelerProfileMenu() {
    cout << "\n=== TRAVELER PROFILE ===\n";
    cout << "Available Travelers:\n";
    displayAllTravelers();
    cout << "\nEnter Traveler ID (e.g., U001): ";
    char travelerID[10];
    cin.ignore();
    cin.getline(travelerID, 10);
    
    displayTravelerProfile(travelerID);
}

// Top pick matcher operation - find highest rated hotel or rank all
void HotelSystem::displayTopPickMatcher() {
    cout << "\n=== TOP-PICK MATCHER ===\n";
    cout << "1. Find Highest-Rated Hotel\n";
    cout << "2. Rank All Hotels by Rating\n";
    cout << "Enter choice (1 or 2): ";
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

// Top reviewers operation - display travelers sorted by loyalty points
void HotelSystem::displayTopReviewers() {
    cout << "\n=== TOP REVIEWERS (By Loyalty Points) ===\n";
    
    if (travelerCount == 0) {
        cout << "No travelers in system.\n";
        return;
    }
    
    // Create a copy array for sorting (to preserve original order)
    Traveler tempTravelers[100];
    for (int i = 0; i < travelerCount; i++) {
        tempTravelers[i] = travelers[i];
    }
    
    // Bubble sort to find top reviewers by loyalty points (descending)
    Traveler temp;
    for (int i = 0; i < travelerCount - 1; i++) {
        for (int j = 0; j < travelerCount - i - 1; j++) {
            // Using operator overloading to compare
            if (tempTravelers[j] < tempTravelers[j + 1]) {
                temp = tempTravelers[j];
                tempTravelers[j] = tempTravelers[j + 1];
                tempTravelers[j + 1] = temp;
            }
        }
    }
    
    cout << "Top Reviewers:\n";
    int limit = (travelerCount < 10) ? travelerCount : 10;
    for (int i = 0; i < limit; i++) {
        cout << (i + 1) << ". " << tempTravelers[i].getUserName() 
             << " (" << tempTravelers[i].getUserID() << ")"
             << " - Loyalty Points: " << tempTravelers[i].getLoyaltyPoints() 
             << " | Reviews: " << tempTravelers[i].getReviewCount() << "\n";
    }
}

// Find and display the highest rated hotel
void HotelSystem::findHighestRatedHotel() const {
    if (hotelCount == 0) {
        cout << "No hotels found in system.\n";
        return;
    }
    
    int maxIndex = 0;
    for (int i = 1; i < hotelCount; i++) {
        // Using operator overloading to compare hotels
        if (hotels[i] > hotels[maxIndex]) {
            maxIndex = i;
        }
    }
    
    cout << "\n*** HIGHEST-RATED HOTEL ***\n";
    cout << hotels[maxIndex];
    hotels[maxIndex].displayAllReviews();
}

// Rank all hotels by average rating (descending)
void HotelSystem::rankAllHotels() const {
    cout << "\n=== HOTEL RANKING BY AVERAGE RATING ===\n";
    
    if (hotelCount == 0) {
        cout << "No hotels found.\n";
        return;
    }
    
    // Create a copy array for sorting
    Hotel tempHotels[20];
    for (int i = 0; i < hotelCount; i++) {
        tempHotels[i] = hotels[i];
    }
    
    // Bubble sort by average rating (descending)
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

// Utility: Find hotel index by name
int HotelSystem::findHotelIndex(const char* hotelName) const {
    for (int i = 0; i < hotelCount; i++) {
        if (strcmp(hotels[i].getHotelName(), hotelName) == 0) {
            return i;
        }
    }
    return -1;
}

// Utility: Find traveler index by ID
int HotelSystem::findTravelerIndex(const char* travelerID) const {
    for (int i = 0; i < travelerCount; i++) {
        if (strcmp(travelers[i].getUserID(), travelerID) == 0) {
            return i;
        }
    }
    return -1;
}

// Add manual review from user input
void HotelSystem::addManualReview() {
    cout << "\n=== ADD MANUAL REVIEW ===\n";
    cout << "Available Travelers:\n";
    displayAllTravelers();
    
    char userID[10];
    cout << "\nEnter Traveler ID: ";
    cin.ignore();
    cin.getline(userID, 10);
    
    int travelerIndex = findTravelerIndex(userID);
    if (travelerIndex == -1) {
        cout << "Traveler not found.\n";
        return;
    }
    
    cout << "\nAvailable Hotels:\n";
    displayAllHotels();
    
    char hotelName[100];
    int rating;
    char comment[500];
    
    cout << "\nEnter Hotel Name: ";
    cin.getline(hotelName, 100);
    
    cout << "Enter Rating (1-5): ";
    cin >> rating;
    cin.ignore();
    
    cout << "Enter Comment: ";
    cin.getline(comment, 500);
    
    if (rating < 1 || rating > 5) {
        cout << "Invalid rating. Please enter a value between 1 and 5.\n";
        return;
    }
    
    Review review;
    review.setReviewData(rating, comment, hotelName);
    
    int hotelIndex = findHotelIndex(hotelName);
    if (hotelIndex == -1 && hotelCount < 20) {
        hotelIndex = hotelCount;
        hotels[hotelCount].setHotelData(hotelName);
        hotelCount++;
    }
    
    if (hotelIndex != -1) {
        hotels[hotelIndex].addReview(review);
        travelers[travelerIndex].addReview(review);
        cout << "Review added successfully!\n";
    } else {
        cout << "Hotel not found and cannot add new hotel (limit reached).\n";
    }
}

// Display main menu
void HotelSystem::displayMainMenu() {
    cout << "\n\n========================================================\n";
    cout << "      HOTEL REVIEW SYSTEM - MAIN MENU\n";
    cout << "========================================================\n";
    cout << "1. Property Deep-Dive (Find & Summarize Hotel Reviews)\n";
    cout << "2. Traveler Profile (View Traveler Info & Reviews)\n";
    cout << "3. Top-Pick Matcher (Find Highest-Rated Hotel)\n";
    cout << "4. Top Reviewers (View Top Travelers by Loyalty Points)\n";
    cout << "5. Display All Hotels\n";
    cout << "6. Display All Travelers\n";
    cout << "7. Add Manual Review\n";
    cout << "8. Save Reports & Exit System\n";
    cout << "========================================================\n";
    cout << "Enter your choice (1-8): ";
}

// Main system run method - orchestrates entire application
void HotelSystem::run() {
    cout << "\n=== INITIALIZING HOTEL REVIEW SYSTEM ===\n";
    
    // ONE-TIME READ: Load all data from files at startup
    loadUsersFromFile("Users.txt");
    loadReviewsFromFile("Reviews.txt");
    
    cout << "[SYSTEM] Initialization complete. System ready for operations.\n";
    
    int choice;
    bool running = true;
    
    while (running) {
        displayMainMenu();
        cin >> choice;
        
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
                // ONE-TIME WRITE: Save reports before exit
                saveReportsToFile("HotelReview_Report.txt");
                running = false;
                cout << "\n[SYSTEM] System shutting down. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 8.\n";
        }
    }
}
