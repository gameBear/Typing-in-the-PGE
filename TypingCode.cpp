//Functions and variables:

//Add in the start of teh olc::PixelGameEngine in the PGE header file.

//Right under teh Key Enum

//This char arrayholds capital and non capital letters along with the numbers 0 to 9

	const char localChar[62] = { 'A','a','B','a','C','c','D','d','E','e','F','f','G','g','H','h','I','i','J','j','K','k','L','l','M','m','N','n','O','o','P','p','Q','q','R','r','S','s','T','t','u','U','V','v','W','w','X','x','Y','y','Z','z','0','1','2','3','4','5','6','7','8','9' };

//and rith under the win32
//IsFocused bool function

////////////////////////////////////// KeyGetter ///////////////////////
	char  PixelGameEngine::GetLetterPressed() {
		if (pKeyboardState[Key(52)].bPressed) return ' ';
		for (int i = 0; i < 36; i++) {
			if (pKeyboardState[Key(i)].bPressed) {

				//////////////////////////////// determines if its a letter, and if it is, sees if shift is pressed, then returns the appropiate letter
				if (i < 26) {
					if (pKeyboardState[Key::SHIFT].bHeld) {
						return localChar[i * 2];
					}
					else return localChar[i * 2 + 1];
				}
				///////////// if its not a letter, return the appropiate number
				else return localChar[i +26];
			}
		}
		return NULL;
	}

	//////////////////////////////////////////////
	std::string PixelGameEngine::getString(bool isTyping) {
		static std::string returnString = "";
		char newLetter = GetLetterPressed();
		if (isTyping && newLetter != NULL) returnString += newLetter;
		else if (!isTyping) returnString = "";
		return returnString;
	}
	//////////////////////////////////////////////


	//This one is mainly used to avoid the release of enter to reactivate the writing function.
	void PixelGameEngine::SetKeyStage(Key k /*all the keys will be set to this stage*/, bool stage)
	{
		pKeyboardState[k].bPressed = stage;
		pKeyboardState[k].bHeld = stage;
		pKeyboardState[k].bReleased = stage;
	}
	//////////////////////////////////////////////

//this here goes in the file where you use the PGE (usueally the Main.cpp or source.cpp file) 

//add in the  onUserUpdate()
		

		//activate type mode
		// isTyping 0 = no typing, 1 = startedTyping, 2 = isCurrentlyTyping
		if (isTyping == 0 && GetKey(olc::Key::ENTER).bReleased) {
			isTyping = 1;
		}

		//draws to teh screen and actuealy gets teh input as well as erasing when done.
		if (isTyping) {
			FillRect(screenW * 0.5 - 140, screenH * 0.5, 280, 20, olc::BLACK);
			std::string myFileName = getString(true);
			DrawString(screenW * 0.5 -136, screenH * 0.5 + 4, myFileName, olc::GREY);
			if (GetKey(olc::Key::ENTER).bPressed) {
				getString(false);
				SetKeyStage(olc::Key::ENTER, false);
				isTyping = false;
			}
		}
