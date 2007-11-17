#ifndef SCORE_H
#define SCORE_H

#include <SDL4Cpp.h>
#include <vector>

class Score
{
	public:
		Score();
		~Score();

		void Draw(SDL::Screen &screen, SDL::Rect &one, SDL::Rect &two);
		int m_One, m_Two;
	private:
		void LoadNumbers();
		// Where to draw the score
		SDL::Rect m_ScoreOneLoc, m_ScoreTwoLoc;
		SDL::Surface m_Numbers;
		std::vector<SDL::Rect> m_Images;
};

#endif

