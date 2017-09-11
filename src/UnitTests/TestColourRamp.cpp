#include <assert.h>
#include "TestColourRamp.h"
#include "MocDisplay.h"
#include "../ramp/ColourRamp.h"

void TestColourRamp::TestCouldNotConnectToDisplay()
{
	MocDisplay fakeDisplay(4,4,false);
	ColourRamp colourRamp(fakeDisplay, m_fakeDisplayName);
	ColourRGB565 tl(0), tr(0), bl(0), br(0);
	assert(colourRamp.Create4ColourRam(tl, tr, bl, br) == Error(displayConnect));
}

void TestColourRamp::TestToSmallDisplay()
{
	// To small
	MocDisplay fakeDisplay(1, 2, true);
	ColourRamp colourRamp(fakeDisplay, m_fakeDisplayName);
	ColourRGB565 tl(0), tr(0), bl(0), br(0);
	assert(colourRamp.Create4ColourRam(tl, tr, bl, br) == Error(displaySize));

	// Negative value
	MocDisplay fakeDisplay2(2, -1, true);
	ColourRamp colourRamp2(fakeDisplay2, m_fakeDisplayName);
	assert(colourRamp2.Create4ColourRam(tl, tr, bl, br) == Error(displaySize));

	// Correct size
	MocDisplay fakeDisplay3(2, 2, true);
	ColourRamp colourRamp3(fakeDisplay3, m_fakeDisplayName);
	assert(colourRamp3.Create4ColourRam(tl, tr, bl, br) == Error(ok));
}

void TestColourRamp::TestBasicRamps()
{
	MocDisplay fakeDisplay(2, 2, true);
	ColourRamp colourRamp(fakeDisplay, m_fakeDisplayName);
	ColourRGB565 tl(1), tr(2), bl(3), br(4);
	vector<unsigned short> expectedResult =	{1,2,
											 3,4};
	assert(colourRamp.Create4ColourRam(tl, tr, bl, br) == Error(ok));
	assert(expectedResult == fakeDisplay.m_frameBuffer);


	MocDisplay fakeDisplay2(16, 2, true);
	ColourRamp colourRamp2(fakeDisplay2, m_fakeDisplayName);
	ColourRGB565 tl_1(0), tr_1(0xf), bl_1(0), br_1(0xf);
	vector<unsigned short> expectedResult2 = { 
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	assert(colourRamp2.Create4ColourRam(tl_1, tr_1, bl_1, br_1) == Error(ok));
	assert(expectedResult2 == fakeDisplay2.m_frameBuffer);

}

const char* TestColourRamp::m_fakeDisplayName = "FakeDisplayName";