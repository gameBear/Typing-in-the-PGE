//Functions and variables:

//Add in the start of teh olc::PixelGameEngine class.

	//Variables
	std::string l_input;
	int isTyping = 0;
	

	//Getting key strokes, add teh rest of the keys you need... could use a swithc case.
	char getABC() {
		char returnVal = NULL;
		bool isShift = false;
		if (GetKey(olc::Key::SHIFT).bHeld) isShift = true;
		if (GetKey(olc::Key::A).bPressed) {
			if (isShift) return 'A';
			else return 'a';
		}
		else if (GetKey(olc::Key::B).bPressed) {
			if (isShift) return 'B';
			else return 'b';
		}
		else if (GetKey(olc::Key::C).bPressed) {
			if (isShift) return 'C';
			else return 'c';
		}
		else if (GetKey(olc::Key::D).bPressed) {
			if (isShift) return 'D';
			else return 'd';
		}
		else if (GetKey(olc::Key::E).bPressed) {
			if (isShift) return 'E';
			else return 'e';
		}
		return returnVal;
	}

	//putting together the string
	bool GetInputString(int &typing, std::string &m_input) {
		char newChar = NULL;
		if (typing == 2 && GetKey(olc::Key::ENTER).bReleased) {
			typing = 0;
			return true;
		}
		else if (typing == 1 || typing == 2) {
			if (typing == 2 && GetKey(olc::Key::ENTER).bReleased) {
				typing = 0;
				return true;
			}
			else if(typing == 1) typing = 2;
			else newChar += getABC();
			if (newChar != NULL) m_input += newChar;
			return false;
		}
		return true;
	}



//calls and updates

//add in the  onUserUpdate()
		

		//activate type mode
		// isTyping 0 = no typing, 1 = startedTyping, 2 = isCurrentlyTyping
		if (isTyping == 0 && GetKey(olc::Key::ENTER).bReleased) {
			isTyping = 1;
		}

		//draws to teh screen and actuealy gets teh input as well as erasing when done.
		if (isTyping == 1 || isTyping == 2) {
			if (!GetInputString(isTyping, l_input)) {
				FillRect(50, 50, 300, 20, olc::WHITE);
				DrawString(54, 54, l_input, olc::BLACK);
			}
			else l_input = "";
		}
