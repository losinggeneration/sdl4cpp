#ifndef SCORE_H
#define SCORE_H

#include <SDL4Cpp.h>
#include <vector>

class Score
{
	public:
		Score();
		~Score();

		/* "screen" to draw  to and the rect which describe one and two */
		void Draw(SDL::Screen &screen, SDL::Rect &one, SDL::Rect &two);

		/* this is the actual scores for player one and two. Yes, this is
		 * typically considered bad practice with the whole information hidding
		 * but this is simple enough that I don't care
		 */
		int m_One, m_Two;
	private:
		/* this will load the rect for numbers from a single bitmap into the
		 * vector m_Images
		 */
		void LoadNumbers();
		// Where to draw the score
		SDL::Rect m_ScoreOneLoc, m_ScoreTwoLoc;
		// This surface contains the scores of player one and two
		SDL::Surface m_Numbers;
		// The rect position of numbers
		std::vector<SDL::Rect> m_Images;
};

#endif

