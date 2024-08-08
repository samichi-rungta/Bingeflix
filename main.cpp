#include <iostream>
#include <string>
#include <map>
using namespace std;

// Define a User class to store user information
class User {
public:
    string username;
    string password;
    string selectedGenre;
};

// Define a Restaurant class to store restaurant information
class Restaurant {
public:
    string name;
    string genre;
};

// Function to create a new account
User createUser() {
    User newUser;
    cout << "Enter a username: ";
    cin >> newUser.username;
    cout << "Enter a password: ";
    cin >> newUser.password;
    return newUser;
}

// Function to authenticate a user
bool authenticateUser(const User& user) {
    string enteredPassword;
    cout << "Enter your password to log in: ";
    cin >> enteredPassword;
    return (enteredPassword == user.password);
}

// Function to display genres and get user choice
string chooseGenre() {
    map<int, string> genres = {
        {1, "Comedy"},
        {2, "Action"},
        {3, "Horror"},
        {4, "Sci-Fi"},
        {5, "Romance"}
    };

    cout << "\nChoose a genre:\n";
    for (const auto& genre : genres) {
        cout << genre.first << ". " << genre.second << "\n";
    }

    int genreChoice;
    cin >> genreChoice;

    auto it = genres.find(genreChoice);
    if (it != genres.end()) {
        return it->second;
    } else {
        return "";  // Invalid choice
    }
}

// Function to recommend a restaurant based on genre
Restaurant recommendRestaurant(const string& genre) {
    Restaurant recommendedRestaurant;

    // In a real application, you would have a database of restaurants
    // Here, I'm providing simple recommendations for demonstration purposes

    if (genre == "Comedy") {
        recommendedRestaurant = {"Funny Foodie", "Comedy"};
    } else if (genre == "Action") {
        recommendedRestaurant = {"Adrenaline Eats", "Action"};
    } else if (genre == "Horror") {
        recommendedRestaurant = {"Spooky Bites", "Horror"};
    } else if (genre == "Sci-Fi") {
        recommendedRestaurant = {"Galactic Grub", "Sci-Fi"};
    } else if (genre == "Romance") {
        recommendedRestaurant = {"Candlelit Cafe", "Romance"};
    }

    return recommendedRestaurant;
}

int main() {
    User currentUser = createUser();

    // Log in to verify the password
    while (!authenticateUser(currentUser)) {
        cout << "Invalid password. Try again.\n";
    }

    cout << "Login successful!\n";

    currentUser.selectedGenre = chooseGenre();
    if (!currentUser.selectedGenre.empty()) {
        Restaurant recommendedRestaurant = recommendRestaurant(currentUser.selectedGenre);
        cout << "\nRecommended restaurant for " << currentUser.selectedGenre << ": "
                  << recommendedRestaurant.name << "\n";
    } else {
        cout << "Invalid genre choice. Exiting...\n";
    }

    return 0;
}



