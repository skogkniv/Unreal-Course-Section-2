#pragma once
// My 'contract' - a high level look at what we want our program to do
// Definied in another source file
#include <string>

using FString = std::string;
using int32 = int;

// all values initialized to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus 
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase,
	Not_Letters
};

class FBullCowGame 
{
public:

	FBullCowGame(); // constructor - made this method of the class

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;	
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const; 
	
	void Reset(); 
	FBullCowCount SubmitValidGuess(FString);

// Please try and ignore this and focus on the interface above
private:	
	// see constructor for initilization compile time values
	int32 MyCurrentTry;
	// int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;

	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};