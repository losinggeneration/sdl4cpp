#include "SDL4Cpp.h"
#include "SDL4Cpp_image.h"
#include "SDL_image.h"

namespace SDL
{
	Image::Image()
	{
	}

	Image::~Image()
	{
	}
	
	const SDL_version *Image::Linked_Version()
	{
		return IMG_Linked_Version();
	}

	bool Image::Load(SDL_RWops *src, int freesrc, char *type)
	{
		SDL_Surface *temp = IMG_LoadTyped_RW(src, freesrc, type);

		if(temp == NULL)
			return false;
		else
			m_Surface = temp;

		return true;

	}

	bool Image::Load(std::string file)
	{
		SDL_Surface *temp = IMG_Load(file.c_str());

		if(temp == NULL)
			return false;
		else
			m_Surface = temp;

		return true;
	}

	bool Image::Load(SDL_RWops *src, int freesrc)
	{
		SDL_Surface *temp = IMG_Load_RW(src, freesrc);

		if(temp == NULL)
			return false;
		else
			m_Surface = temp;

		return true;

	}

	int Image::InvertAlpha(int on)
	{
		return IMG_InvertAlpha(on);
	}

	bool Image::isBMP(SDL_RWops *src)
	{
		return IMG_isBMP(src);
	}

	bool Image::isPNM(SDL_RWops *src)
	{
		return IMG_isPNM(src);
	}

	bool Image::isXPM(SDL_RWops *src)
	{
		return IMG_isXPM(src);
	}

	bool Image::isXCF(SDL_RWops *src)
	{
		return IMG_isXCF(src);
	}

	bool Image::isPCX(SDL_RWops *src)
	{
		return IMG_isPCX(src);
	}

	bool Image::isGIF(SDL_RWops *src)
	{
		return IMG_isGIF(src);
	}

	bool Image::isJPG(SDL_RWops *src)
	{
		return IMG_isJPG(src);
	}

	bool Image::isTIF(SDL_RWops *src)
	{
		return IMG_isTIF(src);
	}

	bool Image::isPNG(SDL_RWops *src)
	{
		return IMG_isPNG(src);
	}

	bool Image::isLBM(SDL_RWops *src)
	{
		return IMG_isLBM(src);
	}

	bool Image::LoadBMP_RW(SDL_RWops *src)
	{
		SDL_Surface *temp = IMG_LoadBMP_RW(src);

		if(temp == NULL)
			return false;
		else
			m_Surface = temp;

		return true;

	}

	bool Image::LoadPNM_RW(SDL_RWops *src)
	{
		SDL_Surface *temp = IMG_LoadPNM_RW(src);

		if(temp == NULL)
			return false;
		else
			m_Surface = temp;

		return true;

	}

	bool Image::LoadXPM_RW(SDL_RWops *src)
	{
		SDL_Surface *temp = IMG_LoadXPM_RW(src);

		if(temp == NULL)
			return false;
		else
			m_Surface = temp;

		return true;

	}

	bool Image::LoadXCF_RW(SDL_RWops *src)
	{
		SDL_Surface *temp = IMG_LoadXCF_RW(src);

		if(temp == NULL)
			return false;
		else
			m_Surface = temp;

		return true;
	}

	bool Image::LoadPCX_RW(SDL_RWops *src)
	{
		SDL_Surface *temp = IMG_LoadPCX_RW(src);

		if(temp == NULL)
			return false;
		else
			m_Surface = temp;

		return true;
	}

	bool Image::LoadGIF_RW(SDL_RWops *src)
	{
		SDL_Surface *temp = IMG_LoadGIF_RW(src);

		if(temp == NULL)
			return false;
		else
			m_Surface = temp;

		return true;
	}

	bool Image::LoadJPG_RW(SDL_RWops *src)
	{
		SDL_Surface *temp = IMG_LoadJPG_RW(src);

		if(temp == NULL)
			return false;
		else
			m_Surface = temp;

		return true;
	}

	bool Image::LoadTIF_RW(SDL_RWops *src)
	{
		SDL_Surface *temp = IMG_LoadTIF_RW(src);

		if(temp == NULL)
			return false;
		else
			m_Surface = temp;

		return true;
	}

	bool Image::LoadPNG_RW(SDL_RWops *src)
	{
		SDL_Surface *temp = IMG_LoadPNG_RW(src);

		if(temp == NULL)
			return false;
		else
			m_Surface = temp;

		return true;
	}

	bool Image::LoadTGA_RW(SDL_RWops *src)
	{
		SDL_Surface *temp = IMG_LoadTGA_RW(src);

		if(temp == NULL)
			return false;
		else
			m_Surface = temp;

		return true;
	}

	bool Image::LoadLBM_RW(SDL_RWops *src)
	{
		SDL_Surface *temp = IMG_LoadLBM_RW(src);

		if(temp == NULL)
			return false;
		else
			m_Surface = temp;

		return true;
	}
	
	bool Image::ReadXPMFromArray(char **xpm)
	{
		SDL_Surface *temp = IMG_ReadXPMFromArray(xpm);

		if(temp == NULL)
			return false;
		else
			m_Surface = temp;

		return true;
	}
}

