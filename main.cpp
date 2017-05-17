#include <string>
#include <getopt.h>

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
	unsigned char r8 = data[pixelOffset + 0];
	unsigned char g8 = data[pixelOffset + 1];
	unsigned char b8 = data[pixelOffset + 2];
	if (flagInvert)
	{
		r8 = 255 - r8;
		g8 = 255 - g8;
		b8 = 255 - b8;
	}
	float r = powf(r8 / 255.f, 2.2f);
	float g = powf(g8 / 255.f, 2.2f);
	float b = powf(b8 / 255.f, 2.2f);
	float val = (0.2126 * r) + (0.7152 * g) + (0.0722 * b);

	if (!flagDither)
	{
		return val;
	}

	float d = ditherTable[(y % ditherHeight) * ditherWidth + (x % ditherWidth)] * ditherScale;
	return val + (d - .5f);
}

void parseCommandLine(int argc, char** argv)
{
	while (1)
	{
		static struct option long_options[] = {
			{ "nodither", no_argument, 0, 'n' },
			{ "invert",   no_argument, 0, 'i' },
			{ 0, 0, 0, 0 }
		};

		int option_index = 0;
		int c = getopt_long(argc, argv, "ni", long_options, &option_index);

		if (c == -1)
			break;

		switch (c)
		{
			case 'n': {
				flagDither = false;
				break;
			}
			case 'i': {
				flagInvert = true;
				break;
			}
		}
	}
}

void processFile(const char* filepath)
{
	int w, h, n;
	unsigned char *data = stbi_load(filepath, &w, &h, &n, 3);

	if (!data)
	{
		printf("Failed to load image %s.\n", filepath);
		return;
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
}

int main(int argc, char** argv)
{
	parseCommandLine(argc, argv);

	if (optind >= argc)
	{
		printf("No filepath provided.\n");
		return 1;
	}

	for (int i = optind; i < argc; ++i)
	{
		processFile(argv[i]);
	}

	return 0;
}
