
class RasterGrid
{
	
	const unsigned int xlen = 0;
	const unsigned int ylen = 0;
	


public:

	unsigned int x = 0;
	unsigned int y = 0;

	constexpr RasterGrid(unsigned int xlen, unsigned int ylen) : xlen(xlen), ylen(ylen)
	{}


	unsigned int* next()
	{
		static unsigned int state[2];
		
		if(x >= xlen-1)
		{
			x = 0;
			y = (y+1) * (y+1 < ylen) + 0 * !(y+1 < ylen);
		}

		else
		{
			x++;
		}
				
		state[0] = x;
		state[1] = y;
		
		return state;
		

	}

};


class SpiralGrid
{
	
	const unsigned int xlen;
	const unsigned int ylen;


public:
	
	int x = 0;
	int y = 0;


	constexpr SpiralGrid(unsigned int xlen, unsigned int ylen) : xlen(xlen), ylen(ylen)
	{}


	unsigned int* next()
	{
		static int delx = 1;
		static unsigned int state[2];


		if(x >= xlen || x < 0)
		{
			delx = delx * -1;
			y = (y+1) * (y+1 < ylen) + 0 * !(y+1 < ylen);
			x+=delx;

			// Grid scanning has finished - repeat
			if(y == 0 && ylen>0)
			{
				x = 0;
				delx = +1;
			}

			// For 1D case, avoid taking two consequitive images.
			if(y==0 && ylen==0)
			{
				x += delx;
			}
		}
		

		// Implicit casting
		state[0] = x;
		state[1] = y;


		x+=delx;
	
		return state;
	}

};