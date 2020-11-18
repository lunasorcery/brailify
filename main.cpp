#include <string>
#include <getopt.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb/stb_image_resize.h"

struct rgba8888_t {
	uint8_t r,g,b,a;
};

static char const ditherTable[64] = {
	 0,48,12,60, 3,51,15,63,
	32,16,44,28,35,19,47,31,
	 8,56, 4,52,11,59, 7,55,
	40,24,36,20,43,27,39,23,
	 2,50,14,62, 1,49,13,61,
	34,18,46,30,33,17,45,29,
	10,58, 6,54, 9,57, 5,53,
	42,26,38,22,41,25,37,21
};
int const ditherWidth  = 8;
int const ditherHeight = 8;
float const ditherScale = 1.f / 64.f;

float const kgamma = 2.2f;

bool flagInvert = false;
bool useThreshold = false;
int threshold = 128;
int resizeWidth = 0;

float getPixel(rgba8888_t* data, int w, int h, int x, int y)
{
	if (x < 0 || y < 0 || x >= w || y >= h) {
		return -1;
	}

	rgba8888_t const pixel = data[(y*w)+x];

	uint8_t const r8 = flagInvert ? (255-pixel.r) : pixel.r;
	uint8_t const g8 = flagInvert ? (255-pixel.g) : pixel.g;
	uint8_t const b8 = flagInvert ? (255-pixel.b) : pixel.b;

	float const a = pixel.a / 255.f;

	if (useThreshold) {
		float const luma = ((0.2126 * r8) + (0.7152 * g8) + (0.0722 * b8)) * a;
		return luma - threshold;
	} else {
		float const r = powf(r8 / 255.f, kgamma);
		float const g = powf(g8 / 255.f, kgamma);
		float const b = powf(b8 / 255.f, kgamma);
		float const luma = ((0.2126 * r) + (0.7152 * g) + (0.0722 * b)) * a;
		float const ditherThreshold = (ditherTable[(y % ditherHeight) * ditherWidth + (x % ditherWidth)] + .5f) * ditherScale;
		return luma - ditherThreshold;
	}
}

void parseCommandLine(int argc, char** argv)
{
	while (1) {
		static struct option long_options[] = {
			{ "invert",          no_argument, 0, 'i' },
			{ "width",     required_argument, 0, 'w' },
			{ "threshold", required_argument, 0, 't' },
			{ 0, 0, 0, 0 }
		};

		int option_index = 0;
		int c = getopt_long(argc, argv, "iw:t:", long_options, &option_index);

		if (c == -1)
			break;

		switch (c) {
			case 'i': {
				flagInvert = true;
				break;
			}
			case 'w': {
				resizeWidth = strtol(optarg, nullptr, 10);
				if (resizeWidth <= 0) {
					printf("Width must be greater than zero.\n");
					exit(1);
				}
				break;
			}
			case 't': {
				useThreshold = true;
				threshold = strtol(optarg, nullptr, 10);
				break;
			}
		}
	}
}

void processFile(const char* filepath)
{
	int srcWidth, srcHeight, srcComp;
	rgba8888_t* srcData = (rgba8888_t*)stbi_load(filepath, &srcWidth, &srcHeight, &srcComp, 4);
	rgba8888_t* dstData = srcData;

	if (!srcData) {
		printf("Failed to load image %s.\n", filepath);
		return;
	}

	int dstWidth  = srcWidth;
	int dstHeight = srcHeight;

	if (resizeWidth != 0) {
		dstWidth = resizeWidth * 2;
		dstHeight = (srcHeight * dstWidth) / srcWidth;
		dstData = new rgba8888_t[dstWidth * dstHeight * 3];
		stbir_resize_uint8((uint8_t const*)srcData, srcWidth, srcHeight, 0, (uint8_t*)dstData, dstWidth, dstHeight, 0, 4);
	}

	char buffer[4];
	buffer[0] = 0xe2;
	buffer[3] = 0;
	for (int y = 0; y < dstHeight; y += 4) {
		for (int x = 0; x < dstWidth; x += 2) {
			const unsigned char masks[8] = { 0x01, 0x02, 0x04, 0x40, 0x08, 0x10, 0x20, 0x80 };
			
			uint8_t bits = 0;
			for (int i = 0; i < 8; ++i) {
				if (getPixel(dstData, dstWidth, dstHeight, x + i / 4, y + i % 4) >= .0f) {
					bits |= masks[i];
				}
			}

			buffer[1] = 0xa0 | (bits >> 6);
			buffer[2] = 0x80 | (bits & 0x3f);
			fputs(buffer, stdout);
		}
		fputs("\n", stdout);
	}

	if (dstData != srcData) {
		delete[] dstData;
	}
	stbi_image_free(srcData);
}

int main(int argc, char** argv)
{
	parseCommandLine(argc, argv);

	if (optind >= argc) {
		printf("No filepath provided.\n");
		return 1;
	}

	for (int i = optind; i < argc; ++i) {
		processFile(argv[i]);
	}

	return 0;
}
