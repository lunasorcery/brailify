#include <string>

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

static char ditherTable[64] = {
	 0,48,12,60, 3,51,15,63,
	32,16,44,28,35,19,47,31,
	 8,56, 4,52,11,59, 7,55,
	40,24,36,20,43,27,39,23,
	 2,50,14,62, 1,49,13,61,
	34,18,46,30,33,17,45,29,
	10,58, 6,54, 9,57, 5,53,
	42,26,38,22,41,25,37,21
};
const int ditherWidth  = 8;
const int ditherHeight = 8;
const float ditherScale = 1.f / 64.f;

bool flagInvert = false;
bool flagDither = true;

float getPixel(unsigned char* data, int w, int h, int x, int y)
{
	if (x < 0 || y < 0 || x >= w || y >= h)
	{
		return 0;
	}

	int pixelOffset = ((y * w) + x) * 3;
	float r = powf(data[pixelOffset + 0] / 255.f, 2.2f);
	float g = powf(data[pixelOffset + 1] / 255.f, 2.2f);
	float b = powf(data[pixelOffset + 2] / 255.f, 2.2f);
	float val = (0.2126 * r) + (0.7152 * g) + (0.0722 * b);

	if (flagInvert)
	{
		val = 1.f - val;
	}

	if (!flagDither)
	{
		return val;
	}

	float d = ditherTable[(y % ditherHeight) * ditherWidth + (x % ditherWidth)] * ditherScale;
	return val + (d - .5f);
}

int main(int argc, const char** argv)
{
	if (argc <= 1)
	{
		printf("No filepath provided.\n");
		return 1;
	}

	int w, h, n;
	unsigned char *data = stbi_load(argv[argc-1], &w, &h, &n, 3);

	for (int i = 1; i < argc - 1; ++i)
	{
		if (strcmp(argv[i], "--invert")==0)
		{
			flagInvert = true;
		}
		else if (strcmp(argv[i], "--nodither")==0)
		{
			flagDither = false;
		}
	}

	if (!data)
	{
		printf("Failed to load image.\n");
		return 1;
	}

	for (int y = 0; y < h; y += 4)
	{
		for (int x = 0; x < w; x += 2)
		{
			const int indices[8] = { 2, 2, 2, 1, 2, 2, 2, 1 };
			const unsigned char masks[8] = { 0x01, 0x02, 0x04, 0x01, 0x08, 0x10, 0x20, 0x02 };
			
			unsigned char buffer[4] = { 0xe2, 0xa0, 0x80, 0x00 };
			for (int i = 0; i < 8; ++i)
			{
				if (getPixel(data, w, h, x + i / 4, y + i % 4) >= .5f)
				{
					buffer[indices[i]] |= masks[i];
				}
			}

			printf("%s", buffer);
		}
		printf("\n");
	}

	stbi_image_free(data);
	return 0;
}
