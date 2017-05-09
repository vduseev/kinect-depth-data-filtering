#include "gradientfilter.h"

const int space = 1;

void GradientFilter(unsigned char *preproc, int width, int height)
{
	// градиент
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (preproc[i * width + j] == 0)
			{
				unsigned int summ = 0;
				unsigned int pixel_count = 0;

				// top
				int k = i;
				while (k > space)
				{
					k -= 1 + space;
					if (preproc[k * width + j] > 0)
					{
						summ += preproc[k * width + j];
						pixel_count++;
						break;
					}
				}
				// bottom
				k = i;
				while (k < height - space)
				{
					k += 1 + space;
					if (preproc[k * width + j] > 0)
					{
						summ += preproc[k * width + j];
						pixel_count++;
						break;
					}
				}
				// left
				k = j;
				while (k > space)
				{
					k -= 1 + space;
					if (preproc[i * width + k] > 0)
					{
						summ += preproc[i * width + k];
						pixel_count++;
						break;
					}
				}
				// right
				k = j;
				while (k < width - space)
				{
					k += 1 + space;
					if (preproc[i * width + k] > 0)
					{
						summ += preproc[i * width + k];
						pixel_count++;
						break;
					}
				}

				if (pixel_count > 0)
					preproc[i * width + j] = summ / pixel_count;
			}
		}
	}
}