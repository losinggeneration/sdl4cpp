#include <iostream>
#include "score.h"

Score::Score()
{
	m_One = m_Two = 0;

	// Sets up 10 blank Rects in the vector which are filled in via LoadNumbers
	SDL::Rect empty;
	for(int x = 0; x < 10; x++)
		m_Images.push_back(empty);

	m_ScoreOneLoc.y = 10;
	m_ScoreOneLoc.x = 250;

	m_ScoreTwoLoc.y = 10;
	m_ScoreTwoLoc.x = 350;

	LoadNumbers();
}

Score::~Score()
{
}

void Score::Draw(SDL::Screen &screen, SDL::Rect &one, SDL::Rect &two)
{
	/*
	 * Basically the idea here is that we blit the protion of the m_Numbers
	 * bitmap to the screen and set tho location of one/two to ScoreOneLocation
	 */
	switch(m_One)
	{
		case 0:
			screen.Blit(m_Images.at(0), m_Numbers, m_ScoreOneLoc);
			one = m_ScoreOneLoc;
			break;
		case 1:
			screen.Blit(m_Images.at(1), m_Numbers, m_ScoreOneLoc);
			one = m_ScoreOneLoc;
			break;
		case 2:
			screen.Blit(m_Images.at(2), m_Numbers, m_ScoreOneLoc);
			one = m_ScoreOneLoc;
			break;
		case 3:
			screen.Blit(m_Images.at(3), m_Numbers, m_ScoreOneLoc);
			one = m_ScoreOneLoc;
			break;
		case 4:
			screen.Blit(m_Images.at(4), m_Numbers, m_ScoreOneLoc);
			one = m_ScoreOneLoc;
			break;
		case 5:
			screen.Blit(m_Images.at(5), m_Numbers, m_ScoreOneLoc);
			one = m_ScoreOneLoc;
			break;
		case 6:
			screen.Blit(m_Images.at(6), m_Numbers, m_ScoreOneLoc);
			one = m_ScoreOneLoc;
			break;
		case 7:
			screen.Blit(m_Images.at(7), m_Numbers, m_ScoreOneLoc);
			one = m_ScoreOneLoc;
			break;
		case 8:
			screen.Blit(m_Images.at(8), m_Numbers, m_ScoreOneLoc);
			one = m_ScoreOneLoc;
			break;
		case 9:
			screen.Blit(m_Images.at(9), m_Numbers, m_ScoreOneLoc);
			one = m_ScoreOneLoc;
			break;
	}

	switch(m_Two)
	{
		case 0:
			screen.Blit(m_Images.at(0), m_Numbers, m_ScoreTwoLoc);
			two = m_ScoreTwoLoc;
			break;
		case 1:
			screen.Blit(m_Images.at(1), m_Numbers, m_ScoreTwoLoc);
			two = m_ScoreTwoLoc;
			break;
		case 2:
			screen.Blit(m_Images.at(2), m_Numbers, m_ScoreTwoLoc);
			two = m_ScoreTwoLoc;
			break;
		case 3:
			screen.Blit(m_Images.at(3), m_Numbers, m_ScoreTwoLoc);
			two = m_ScoreTwoLoc;
			break;
		case 4:
			screen.Blit(m_Images.at(4), m_Numbers, m_ScoreTwoLoc);
			two = m_ScoreTwoLoc;
			break;
		case 5:
			screen.Blit(m_Images.at(5), m_Numbers, m_ScoreTwoLoc);
			two = m_ScoreTwoLoc;
			break;
		case 6:
			screen.Blit(m_Images.at(6), m_Numbers, m_ScoreTwoLoc);
			two = m_ScoreTwoLoc;
			break;
		case 7:
			screen.Blit(m_Images.at(7), m_Numbers, m_ScoreTwoLoc);
			two = m_ScoreTwoLoc;
			break;
		case 8:
			screen.Blit(m_Images.at(8), m_Numbers, m_ScoreTwoLoc);
			two = m_ScoreTwoLoc;
			break;
		case 9:
			screen.Blit(m_Images.at(9), m_Numbers, m_ScoreTwoLoc);
			two = m_ScoreTwoLoc;
			break;
	}
}

void Score::LoadNumbers()
{
	// load the bitmap or exit on error
	if(!m_Numbers.LoadBMP("numbers.bmp"))
	{
		std::cerr << "Encountered the following error: " << SDL::GetError() << std::endl;
		exit(1);
	}

	// initial possition of the tile
	int posx = 0;
	int posy = 1;
	int sizex = 8;
	int sizey = 11;

	// Perhaps this should be
	// if(m_Images.empty())
	// 		exit(1);
	// since an empty m_Images idicates an allocation error
	if(!m_Images.empty())
	{
		for(int x = 0; x < 10; x++)
		{
			posx += 1;
			m_Images.at(x).w = sizex;
			m_Images.at(x).x = posx;
			m_Images.at(x).h = sizey;
			m_Images.at(x).y = posy;

			posx += sizex;
		}
	}
}
